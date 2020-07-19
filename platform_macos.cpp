#include <deque>

#include <timer_platform.h>

#define GL_SILENCE_DEPRECATION

#if defined(__linux__)
#include <GL/glew.h>
#endif // defined(__linux__)

#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

#include "gl_utility.h"

std::deque<Event> EventQueue;

constexpr int ScreenWidth = 128;
constexpr int ScreenHeight = 128;
constexpr int ScreenScale = 4;
unsigned char ScreenImage[ScreenWidth * ScreenWidth * 3];

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

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, screen_image_texture);
    set_image_shader(to_screen_transform, screen_image_texture, 0, 0);

    screen_image_rectangle.bind();
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    CheckOpenGL(__FILE__, __LINE__);
}

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW: %s\n", description);
}

static void key(GLFWwindow *window, int key, int scancode, int action, int mods)
{
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

void initialize_ui(const char *appName)
{
    glfwSetErrorCallback(error_callback);

    if(!glfwInit())
        exit(EXIT_FAILURE);

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

int main(int argc, char **argv)
{
    initialize_ui("timer_platform");

    EventQueue.push_back({SHORT_PRESS, 0});

    do {
        iterate_ui();

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
