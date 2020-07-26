#include <deque>
#include <cstdio>
#include <cstring>
#include "main.h"
#include "../../platform.h"

// XXX nota bene - if allocation of this fails, failure will be
// before main() and therefore cause a silent hang.
std::deque<Event> EventQueue;

extern "C" {

bool button_pressed[2] = {false, false};
uint32_t button_pressed_ticks[2];

constexpr int LONG_PRESS_DURATION_MILLIS = 500;

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

};

