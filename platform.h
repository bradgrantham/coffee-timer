#include <stdint.h>

enum EventType {
    INIT,
    SHORT_PRESS,
    LONG_PRESS,
    TIMER_TICK,
    TIMER_FINISHED,
    PLAY_FINISHED,
};

enum {
    BUTTON_1 = 0x01,
    BUTTON_2 = 0x02,
    BUTTON_3 = 0x04,
    BUTTON_4 = 0x08,
};

struct Event
{
    EventType type;
    int data;
};

struct Color
{
    uint8_t r, g, b;
    operator uint32_t() {
        return (r << 24) | (g << 16) | (b << 8);
    };
    Color(uint32_t u) :
        r((u >> 24) & 0xff), g((u >> 16) & 0xff), b((u >> 8) & 0xff)
    { }
    Color(uint8_t r, uint8_t g, uint8_t b) :
        r(r), g(g), b(b)
    {}
};

enum {
    NO_ERROR = 0,
    OUT_OF_TIMERS = -1,
};

// Provided by the platform:

extern "C" {

    int StartTimer(int seconds);
    int CancelTimer(int timer);
    int GetTimerRemaining(int timer);
    int DrawRect(int x, int y, int w, int h, Color c);
    int DrawBitmap(int x, int y, int w, int h, uint8_t *bits, Color fg, Color bg);
    int SetScreen(bool power);

};

// Provided by the app:

extern "C" {

    int HandleEvent(const Event& e);

};
