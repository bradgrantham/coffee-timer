#include <deque>
#include <chrono>
#include <cmath>
#include <ao/ao.h>
#include <thread>

#include <platform.h>

// c++ -DHOSTED -Wall -I. -I/opt/local/include/ -L/opt/local/lib -std=c++17 -lglfw -framework OpenGL -framework Cocoa -framework IOkit platform_macos.cpp testapp1.cpp gl_utility.cpp -o testapp1

#define GL_SILENCE_DEPRECATION

#if defined(__linux__)
#include <GL/glew.h>
#endif // defined(__linux__)

#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

#include "gl_utility.h"

typedef std::chrono::steady_clock::time_point Timepoint;

std::deque<Event> EventQueue;

constexpr int ScreenWidth = 128;
constexpr int ScreenHeight = 128;
constexpr int ScreenScale = 2;
unsigned char ScreenImage[ScreenWidth * ScreenHeight * 3];
bool ScreenEnabled = false;

static GLFWwindow* my_window;

static GLuint image_program;
static GLuint image_texture_location;
static GLuint image_texture_coord_scale_location;
static GLuint image_to_screen_location;
static GLuint image_x_offset_location;
static GLuint image_y_offset_location;

constexpr int raster_coords_attrib = 0;

static int gWindowWidth, gWindowHeight;

// to handle https://github.com/glfw/glfw/issues/161
static double gMotionReported = false;

static double gOldMouseX, gOldMouseY;
static int gButtonPressed = -1;

static bool quitMyApp = false;

static float pixel_to_ui_scale;
static float to_screen_transform[9];

void make_to_screen_transform()
{
    to_screen_transform[0 * 3 + 0] = 2.0 / gWindowWidth * pixel_to_ui_scale;
    to_screen_transform[0 * 3 + 1] = 0;
    to_screen_transform[0 * 3 + 2] = 0;
    to_screen_transform[1 * 3 + 0] = 0;
    to_screen_transform[1 * 3 + 1] = -2.0 / gWindowHeight * pixel_to_ui_scale;
    to_screen_transform[1 * 3 + 2] = 0;
    to_screen_transform[2 * 3 + 0] = -1;
    to_screen_transform[2 * 3 + 1] = 1;
    to_screen_transform[2 * 3 + 2] = 1;
}

opengl_texture screen_image_texture;
vertex_array screen_image_rectangle;

static const char *image_vertex_shader = R"(
    uniform mat3 to_screen;
    in vec2 vertex_coords;
    out vec2 raster_coords;
    uniform float x_offset;
    uniform float y_offset;
    
    void main()
    {
        raster_coords = vertex_coords;
        vec3 screen_coords = to_screen * vec3(vertex_coords + vec2(x_offset, y_offset), 1);
        gl_Position = vec4(screen_coords.x, screen_coords.y, .5, 1);
    }
)";

static const char *image_fragment_shader = R"(
    in vec2 raster_coords;
    uniform vec2 image_coord_scale;
    uniform sampler2D image;
    
    out vec4 color;
    
    void main()
    {
        ivec2 tc = ivec2(raster_coords.x, raster_coords.y);
        color = texture(image, raster_coords * image_coord_scale);
    }
)";


void initialize_gl(void)
{
#if defined(__linux__)
    glewInit();
#endif // defined(__linux__)

    glClearColor(0, 0, 0, 1);
    CheckOpenGL(__FILE__, __LINE__);

    GLuint va;
    glGenVertexArrays(1, &va);
    CheckOpenGL(__FILE__, __LINE__);
    glBindVertexArray(va);
    CheckOpenGL(__FILE__, __LINE__);

    image_program = GenerateProgram("image", image_vertex_shader, image_fragment_shader);
    assert(image_program != 0);
    glBindAttribLocation(image_program, raster_coords_attrib, "vertex_coords");
    CheckOpenGL(__FILE__, __LINE__);

    image_texture_location = glGetUniformLocation(image_program, "image");
    image_texture_coord_scale_location = glGetUniformLocation(image_program, "image_coord_scale");
    image_to_screen_location = glGetUniformLocation(image_program, "to_screen");
    image_x_offset_location = glGetUniformLocation(image_program, "x_offset");
    image_y_offset_location = glGetUniformLocation(image_program, "y_offset");

    CheckOpenGL(__FILE__, __LINE__);

    screen_image_texture = initialize_texture(ScreenWidth, ScreenHeight, NULL);
    screen_image_rectangle.push_back({make_rectangle_array_buffer(0, 0, ScreenWidth, ScreenHeight), raster_coords_attrib, 2, GL_FLOAT, GL_FALSE, 0});
}

void set_image_shader(float to_screen[9], const opengl_texture& texture, float x, float y)
{
    glUseProgram(image_program);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glUniform2f(image_texture_coord_scale_location, 1.0 / texture.w, 1.0 / texture.h);
    glUniform1i(image_texture_location, 0);
    glUniformMatrix3fv(image_to_screen_location, 1, GL_FALSE, to_screen);
    glUniform1f(image_x_offset_location, x);
    glUniform1f(image_y_offset_location, y);
}

static void redraw(GLFWwindow *window)
{
    int fbw, fbh;
    glfwGetFramebufferSize(window, &fbw, &fbh);
    glViewport(0, 0, fbw, fbh);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(ScreenEnabled) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, screen_image_texture);
        set_image_shader(to_screen_transform, screen_image_texture, 0, 0);

        screen_image_rectangle.bind();
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }

    CheckOpenGL(__FILE__, __LINE__);
}

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW: %s\n", description);
}

Timepoint keyPressedTime[2];

constexpr float LONG_PRESS_DURATION_MICROS = 500000;

static void key(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS) {
        if(key == GLFW_KEY_1) {
            keyPressedTime[0] = std::chrono::steady_clock::now();
        } else if(key == GLFW_KEY_2) {
            keyPressedTime[1] = std::chrono::steady_clock::now();
        } else {
        }
    } else if(action == GLFW_RELEASE) {
        if(key == GLFW_KEY_1) {
            auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - keyPressedTime[0]);
            bool pressWasLong = (elapsed.count() >= LONG_PRESS_DURATION_MICROS);
            EventQueue.push_back({pressWasLong ? LONG_PRESS : SHORT_PRESS, BUTTON_1});
        } else if(key == GLFW_KEY_2) {
            auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - keyPressedTime[1]);
            bool pressWasLong = (elapsed.count() >= LONG_PRESS_DURATION_MICROS);
            EventQueue.push_back({pressWasLong ? LONG_PRESS : SHORT_PRESS, BUTTON_2});
        } else {
        }
    }
#if 0
    static bool super_down = false;
    static bool control_down = false;
    static bool shift_down = false;
    static bool caps_lock_down = false;

    if((action == GLFW_PRESS) || (action == GLFW_REPEAT)) {
        if(key == GLFW_KEY_RIGHT_SUPER || key == GLFW_KEY_LEFT_SUPER) {
            super_down = true;
        } else if(key == GLFW_KEY_RIGHT_CONTROL || key == GLFW_KEY_LEFT_CONTROL) {
            control_down = true;
        } else if(key == GLFW_KEY_RIGHT_SHIFT || key == GLFW_KEY_LEFT_SHIFT) {
            shift_down = true;
        } else if(key == GLFW_KEY_CAPS_LOCK) {
            caps_lock_down = true;
        } else if(super_down && key == GLFW_KEY_V) {
            const char* text = glfwGetClipboardString(window);
            if (text) {
                while(*text) {
                    PushChar(*text++);
                }
            }
        } else if(super_down && key == GLFW_KEY_B) {
            if (action == GLFW_PRESS) {
                // XXX act as if blue button were pressed, should go back to text mode
            }
        } else {
            if(shift_down) {
                if((key >= GLFW_KEY_A) && (key <= GLFW_KEY_Z)) {
                    PushChar(key);
                } else {
                    if((ScancodeToASCII.count(key) != 0) && (ScancodeToASCII[key].shift >= 0)) {
                        PushChar(ScancodeToASCII[key].shift);
                    }
                }
            } else if(control_down) {
                if((key >= GLFW_KEY_A) && (key <= GLFW_KEY_Z)) {
                    PushChar(key - GLFW_KEY_A + 0x01);
                } else {
                    switch(key) {
                        case GLFW_KEY_LEFT_BRACKET: PushChar(''); break;
                        case GLFW_KEY_RIGHT_BRACKET: PushChar(''); break;
                        case GLFW_KEY_BACKSLASH: PushChar(''); break;
                        case GLFW_KEY_SLASH: PushChar(''); break;
                        case GLFW_KEY_MINUS: PushChar(''); break;
                        default: /* notreached */ break; 
                    }
                }
            } else {
                if((key >= GLFW_KEY_A) && (key <= GLFW_KEY_Z)) {
                    if(caps_lock_down) {
                        PushChar(key - GLFW_KEY_A + 'A');
                    } else {
                        PushChar(key - GLFW_KEY_A + 'a');
                    }
                } else  {
                    if((ScancodeToASCII.count(key) != 0) && (ScancodeToASCII[key].bare >= 0)) {
                        PushChar(ScancodeToASCII[key].bare);
                    }
                }
            }
        }
    } else if(action == GLFW_RELEASE) {
        if(key == GLFW_KEY_RIGHT_SUPER || key == GLFW_KEY_LEFT_SUPER) {
            super_down = false;
        } else if(key == GLFW_KEY_RIGHT_SHIFT || key == GLFW_KEY_LEFT_SHIFT) {
            shift_down = false;
        } else if(key == GLFW_KEY_RIGHT_CONTROL || key == GLFW_KEY_LEFT_CONTROL) {
            control_down = false;
        } else if(key == GLFW_KEY_CAPS_LOCK) {
            caps_lock_down = false;
        }
    }
#endif
}


static void resize_based_on_window(GLFWwindow *window)
{
    glfwGetWindowSize(window, &gWindowWidth, &gWindowHeight);
    if(float(gWindowHeight) / gWindowWidth < ScreenHeight / ScreenWidth) {
        pixel_to_ui_scale = gWindowHeight / ScreenHeight;
    } else {
        pixel_to_ui_scale = gWindowWidth / ScreenWidth;
    }
    make_to_screen_transform();
}

static void resize(GLFWwindow *window, int x, int y)
{
    resize_based_on_window(window);
    int fbw, fbh;
    glfwGetFramebufferSize(window, &fbw, &fbh);
    glViewport(0, 0, fbw, fbh);
}

static void button(GLFWwindow *window, int b, int action, int mods)
{
    double x, y;
    glfwGetCursorPos(window, &x, &y);

    if(b == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS) {
        gButtonPressed = 1;
	gOldMouseX = x;
	gOldMouseY = y;

        // TODO: button press
    } else {
        gButtonPressed = -1;
        // TODO: button release
    }
    redraw(window);
}

static void motion(GLFWwindow *window, double x, double y)
{
    // to handle https://github.com/glfw/glfw/issues/161
    // If no motion has been reported yet, we catch the first motion
    // reported and store the current location
    if(!gMotionReported) {
        gMotionReported = true;
        gOldMouseX = x;
        gOldMouseY = y;
    }

    gOldMouseX = x;
    gOldMouseY = y;

    if(gButtonPressed == 1) {
        // TODO motion while dragging
    } else {
        // TODO motion while not dragging
    }
    redraw(window);
}

void iterate_ui()
{
    CheckOpenGL(__FILE__, __LINE__);
    if(glfwWindowShouldClose(my_window)) {
        quitMyApp = true;
        return;
    }

    CheckOpenGL(__FILE__, __LINE__);
    redraw(my_window);
    CheckOpenGL(__FILE__, __LINE__);
    glfwSwapBuffers(my_window);
    CheckOpenGL(__FILE__, __LINE__);

    glfwPollEvents();
}

void shutdown_ui()
{
    glfwTerminate();
}

ao_device* audioDevice;

ao_device *open_ao()
{
    ao_device *device;
    ao_sample_format format;
    int default_driver;

    ao_initialize();

    default_driver = ao_default_driver_id();

    memset(&format, 0, sizeof(format));
    format.bits = 8;
    format.channels = 1;
    format.rate = 8000; // 44100;
    format.byte_format = AO_FMT_LITTLE;

    ao_option opt = {(char*)"buffer_time", (char*)"500", nullptr};

    /* -- Open driver -- */
    device = ao_open_live(default_driver, &format, &opt);
    if (device == NULL) {
        fprintf(stderr, "Error opening libao audio device.\n");
        return nullptr;
    }
    return device;
}


void initialize_ui(const char *appName)
{
    audioDevice = open_ao();
    if(!audioDevice) {
        exit(EXIT_FAILURE);
    }
    glfwSetErrorCallback(error_callback);

    if(!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

    // glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_DOUBLEBUFFER, 1);
    my_window = glfwCreateWindow(ScreenWidth * ScreenScale, ScreenHeight * ScreenScale, appName, NULL, NULL);
    if (!my_window) {
        glfwTerminate();
        fprintf(stdout, "Couldn't open main window\n");
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(my_window);
    // printf("GL_RENDERER: %s\n", glGetString(GL_RENDERER));
    // printf("GL_VERSION: %s\n", glGetString(GL_VERSION));

    glfwGetWindowSize(my_window, &gWindowWidth, &gWindowHeight);
    make_to_screen_transform();
    initialize_gl();
    resize_based_on_window(my_window);
    CheckOpenGL(__FILE__, __LINE__);

    glfwSetKeyCallback(my_window, key);
    glfwSetMouseButtonCallback(my_window, button);
    glfwSetCursorPosCallback(my_window, motion);
    glfwSetFramebufferSizeCallback(my_window, resize);
    glfwSetWindowRefreshCallback(my_window, redraw);
    CheckOpenGL(__FILE__, __LINE__);
}

struct Timer {
    bool running;
    int remaining;
    Timepoint nextTick;
    Timer() :
        running(false)
    { }
};

constexpr auto oneTenthSecond = std::chrono::microseconds(100000);
constexpr int MAX_TIMERS = 16;
Timer timers[MAX_TIMERS];

bool clipPlaying = false;
Timepoint clipFinishes;

int PlayClip(const uint8_t *samples, size_t size)
{
    // auto playThread = std::thread{[&] {
        ao_play(audioDevice, (char*)samples, size);
    // }};
    // playThread.detach();

    clipPlaying = true;
    clipFinishes = std::chrono::steady_clock::now() + std::chrono::microseconds(size * 1000000 / 8000);

    return NO_ERROR;
}

int CancelClip(int tune)
{
    if(tune < 0) {
        return INVALID_CLIP_NUMBER;
    }
    assert(tune == 0);
    return NO_ERROR;
}

int StartTimer(int tenths)
{
    int timer = 0;

    while((timer < MAX_TIMERS) && (timers[timer].running)) {
        timer++;
    }

    if(timer >= MAX_TIMERS) {
        return OUT_OF_TIMERS;
    }

    Timer& t = timers[timer];
    t.running = true;
    t.nextTick = std::chrono::steady_clock::now() + oneTenthSecond;
    t.remaining = tenths - 1;

    return timer;
}

int CancelTimer(int timer)
{
    if(timer < 0) {
        return INVALID_TIMER_NUMBER;
    }
    timers[timer].running = false;
    for (auto it = EventQueue.begin(); it != EventQueue.end(); ) {
        const Event& e = *it;
        bool isTimerEvent = (e.type == TIMER_TICK) || (e.type == TIMER_FINISHED);
        bool isThisTimer = (e.data == timer);
        if (isTimerEvent && isThisTimer) {
            it = EventQueue.erase(it);
        } else {
            ++it;
        }
    }
    return NO_ERROR;
}

int GetTimerRemaining(int timer)
{
    if(timer < 0) {
        return INVALID_TIMER_NUMBER;
    }
    return timers[timer].remaining;
}

int SetScreen(bool powerOn)
{
    ScreenEnabled = powerOn;
    return NO_ERROR;
}

int DrawRect(int x, int y, int w, int h, const Color& c)
{
    for(int row = y; row < y + h; row++) {
        for(int col = x; col < x + w; col++) {
            ScreenImage[(col + row * ScreenWidth) * 3 + 0] = c.r;
            ScreenImage[(col + row * ScreenWidth) * 3 + 1] = c.g;
            ScreenImage[(col + row * ScreenWidth) * 3 + 2] = c.b;
        }
    }
    return NO_ERROR;
}

int DrawBitmap(int left, int top, int w, int h, uint8_t *bits, size_t rowBytes, const Color& fg, const Color& bg)
{
    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            int whichByte = col / 8 + row * rowBytes;
            int whichBit = col % 8;
            uint8_t *pixel = ScreenImage + ((col + left) + (row + top) * ScreenWidth) * 3;
            if(bits[whichByte] & (1 << whichBit)) {
                pixel[0] = fg.r;
                pixel[1] = fg.g;
                pixel[2] = fg.b;
            } else {
                pixel[0] = bg.r;
                pixel[1] = bg.g;
                pixel[2] = bg.b;
            }
        }
    }
    return NO_ERROR;
}

int main(int argc, char **argv)
{
    initialize_ui("coffee timer simulator");

    EventQueue.push_back({INIT, 0});
    do {

        iterate_ui();

        Timepoint now = std::chrono::steady_clock::now();

        for(int i = 0; i < MAX_TIMERS; i++) {
            Timer& t = timers[i];
            if(t.running) {
                if(now > t.nextTick) {
                    t.remaining --;
                    if(t.remaining > 0) {
                        EventQueue.push_back({TIMER_TICK, i});
                        t.nextTick = t.nextTick + oneTenthSecond;
                    } else {
                        EventQueue.push_back({TIMER_FINISHED, i});
                        t.running = false;
                    }
                }
            }
        }

        if(clipPlaying) {
            if(now > clipFinishes) {
                EventQueue.push_back({CLIP_FINISHED, 0});
                clipPlaying = false;
            }
        }

        bool eventsHandled = false;
        while(EventQueue.size() > 0) {
            eventsHandled = true;
            Event e = EventQueue.front();
            EventQueue.pop_front();

            HandleEvent(e);
        }

        if(eventsHandled) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ScreenWidth, ScreenHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, ScreenImage);
            redraw(my_window);
        }

    } while (!quitMyApp);

}
