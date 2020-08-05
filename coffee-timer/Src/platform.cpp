#include <deque>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include "main.h"
#include "../../platform.h"

// XXX nota bene - if allocation of this fails, failure will be
// before main() and therefore cause a silent hang.
std::deque<Event> EventQueue;


bool button_pressed[2] = {false, false};
uint32_t button_pressed_ticks[2];

constexpr int LONG_PRESS_DURATION_MILLIS = 500;

extern "C" {

void ButtonPress(int button, uint32_t pressStartTicks);
void ButtonRelease(int button, uint32_t releaseStartTicks);
int ProcessEvents(uint32_t now_ticks);
void InitPlatform();

};

void ButtonPress(int button, uint32_t pressStartTicks)
{
    int buttonIndex = button - 1;
    button_pressed[buttonIndex] = true;
    button_pressed_ticks[buttonIndex] = pressStartTicks;
}

void ButtonRelease(int button, uint32_t releaseStartTicks)
{
    int buttonIndex = button - 1;
    int otherButtonIndex = (buttonIndex + 1) % 2;
    uint32_t duration = releaseStartTicks - button_pressed_ticks[buttonIndex];
    bool pressWasLong = (duration > LONG_PRESS_DURATION_MILLIS);
        
    if(button_pressed[buttonIndex]) {
        if(button_pressed[otherButtonIndex]) {
            EventQueue.push_back({pressWasLong ? LONG_PRESS : SHORT_PRESS, BUTTON_1 | BUTTON_2 });
            button_pressed[otherButtonIndex] = false;
        } else {
            EventQueue.push_back({pressWasLong ? LONG_PRESS : SHORT_PRESS, (button == 1) ? BUTTON_1 : BUTTON_2});
        }
        button_pressed[buttonIndex] = false;
    }
}

uint32_t thenTicks;
uint64_t currentTimeMillis;
constexpr uint32_t oneTenthSecond = 100;

struct Timer {
    bool running;
    int remaining;
    uint64_t nextTick;
    Timer() :
        running(false)
    { }
};

constexpr int MAX_TIMERS = 16;
Timer timers[MAX_TIMERS];

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
    t.nextTick = currentTimeMillis + oneTenthSecond;
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

bool clipPlaying = false;
uint64_t clipFinishes;

int PlayClip(const uint8_t *samples, size_t size)
{
    // XXX ao_play(audioDevice, (char*)samples, size);
    DACPlay(samples, size);
    printf("PlayClip\n");

    clipPlaying = true;
    clipFinishes = currentTimeMillis + size * 1000 / 8000;

    return NO_ERROR;
}

int CancelClip(int tune)
{
    // XXX cancel playing of audio here
    printf("CancelClip\n");

    if(tune < 0) {
        return INVALID_CLIP_NUMBER;
    }
    assert(tune == 0);
    return NO_ERROR;
}

int SetScreen(bool powerOn)
{
    printf("set screen %d\n", powerOn);
    return NO_ERROR;
}

uint16_t ColorToU16R5G6B5(const Color& c)
{
    return
        ((c.r >> 3) << 11) | 
        ((c.g >> 2) <<  5) | 
        ((c.b >> 3) <<  0);
}

int DrawRect(int x, int y, int w, int h, const Color& c)
{
    SysDrawRect(x, y, w, h, ColorToU16R5G6B5(c));
#if 0
    for(int row = y; row < y + h; row++) {
        for(int col = x; col < x + w; col++) {
            ScreenImage[(col + row * ScreenWidth) * 3 + 0] = c.r;
            ScreenImage[(col + row * ScreenWidth) * 3 + 1] = c.g;
            ScreenImage[(col + row * ScreenWidth) * 3 + 2] = c.b;
        }
    }
#endif
    printf("DrawRect\n");
    return NO_ERROR;
}

int DrawBitmap(int left, int top, int w, int h, const uint8_t *bits, size_t rowBytes, const Color& fg, const Color& bg)
{
    SysDrawBitmap(left, top, bits, w, h, rowBytes, ColorToU16R5G6B5(fg), ColorToU16R5G6B5(bg));
#if 0
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
            if(bits[whichByte] & (1 << whichBit)) {
                int v = (fg.r + fg.g + fg.b) / 3;
                putchar(" .-o*O@#"[(int)(floorf(v / 32))]);
            } else {
                int v = (bg.r + bg.g + bg.b) / 3;
                putchar(" .-o*O@#"[(int)(floorf(v / 32))]);
            }
        }
        printf("\n");
    }
#endif
    return NO_ERROR;
}

void InitPlatform()
{
    EventQueue.push_back({INIT, 0});
}

int ProcessEvents(uint32_t now_ticks)
{
    uint32_t duration = now_ticks - thenTicks;
    thenTicks = now_ticks;
    uint64_t prevTimeMillis = currentTimeMillis;
    uint64_t now = prevTimeMillis + duration;
    currentTimeMillis = now;

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

    while(EventQueue.size() > 0) {
        Event e = EventQueue.front();
        EventQueue.pop_front();
        printf("Event %d with data %d\n", e.type, e.data);
        HandleEvent(e);
    }
    return 0;
}
