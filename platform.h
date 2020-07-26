#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include <stdint.h>
#include <stdlib.h>

typedef enum EventType {
    INIT,
    SHORT_PRESS,
    LONG_PRESS,
    TIMER_TICK,
    TIMER_FINISHED,
    CLIP_FINISHED,
} EventType;

typedef enum ButtonPressMask {
    BUTTON_1 = 0x01,
    BUTTON_2 = 0x02,
    BUTTON_3 = 0x04,
    BUTTON_4 = 0x08,
} ButtonPressMask;

typedef struct Event
{
    EventType type;
    int data;
} Event;

#if 0
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
#else
typedef uint32_t Color;
#endif

enum {
    NO_ERROR = 0,
    OUT_OF_TIMERS = -1,
    INVALID_TIMER_NUMBER = -2,
    INVALID_CLIP_NUMBER = -2,
};

// Provided by the platform:

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

    int StartTimer(int tenths); // Tenths of seconds
    int CancelTimer(int timer);
    int GetTimerRemaining(int timer);
    int DrawRect(int x, int y, int w, int h, Color c);
    int DrawBitmap(int x, int y, int w, int h, uint8_t *bits, size_t rowBytes, Color fg, Color bg);
    int SetScreen(int power);
    int PlayClip(const uint8_t *samples8KMono, size_t size);
    int CancelClip(int clip);

#ifdef __cplusplus
};
#endif /* __cplusplus */

// Provided by the app:

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

    int HandleEvent(const Event* e);

#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* _PLATFORM_H_ */
