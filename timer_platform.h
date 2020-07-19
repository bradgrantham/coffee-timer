#include <stdint.h>

enum EventType {
    SHORT_PRESS,
    LONG_PRESS,
    TIMER_TICK,
    TIMER_FINISH,
    PLAY_FINISH,
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

// Provided by the platform:

extern "C" {

    int StartTimer(float seconds, float ticks);
    int CancelTimer(int timer);
    int DrawRect(int x, int y, int w, int h, Color c);
    int DrawBitmap(int x, int y, int w, int h, uint8_t *bits, Color fg, Color bg);
    int SetScreen(bool power);

};

// Provided by the app:

extern "C" {
    int HandleEvent(const Event& e);
};
