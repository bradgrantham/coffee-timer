#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "platform.h"

bool debugEvents = true;
bool debugStates = true;

enum {
    STATE_DARK,
    STATE_WAITING,
    STATE_RUNNING,
    STATE_PAUSED,
    STATE_FINISHED,
} appState = STATE_DARK;

int waitingTimer;
constexpr int waitingToDarkSeconds = 10; // 5 * 60;

void EnterWaitingState()
{
    if(debugStates) printf("EnterWaitingState\n");
    SetScreen(true);
    printf("draw 1m and 4m and smiley\n");
    waitingTimer = StartTimer(waitingToDarkSeconds);
    appState = STATE_WAITING;
}

void UpdateWaitingScreen()
{
    printf("hey, waiting for button\n");
}

void EnterDarkState()
{
    if(debugStates) printf("EnterDarkState\n");
    printf("clear LCD to black\n");
    SetScreen(false);
    appState = STATE_DARK;
}

int HandleEvent(const Event& e)
{
    switch(e.type) {
        case INIT: {
            EnterWaitingState();
            break;
        }

        case SHORT_PRESS: {
            if(debugEvents) printf("SHORT_PRESS %d\n", e.data);
            switch(appState) {
                case STATE_DARK:
                    EnterWaitingState();
                    break;
                case STATE_WAITING:
                    // XXX enter timer
                    break;
                case STATE_RUNNING:
                    abort(); // implement me
                    break;
                case STATE_PAUSED:
                    abort(); // implement me
                    break;
                case STATE_FINISHED:
                    abort(); // implement me
                    break;
            }
            break;
        }

        case LONG_PRESS: {
            if(debugEvents) printf("LONG_PRESS %d\n", e.data);
            switch(appState) {
                case STATE_DARK:
                    EnterWaitingState();
                    break;
                case STATE_WAITING:
                    // nothing now for long press at WAITING
                    break;
                case STATE_RUNNING:
                    abort(); // implement me
                    break;
                case STATE_PAUSED:
                    abort(); // implement me
                    break;
                case STATE_FINISHED:
                    abort(); // implement me
                    break;
            }
            break;
        }

        case TIMER_FINISHED: {
            if(debugEvents) printf("TIMER_FINISHED %d\n", e.data);
            switch(appState) {
                case STATE_DARK:
                    // Won't Happen
                    break;
                case STATE_WAITING:
                    assert(e.data == waitingTimer);
                    EnterDarkState();
                    break;
                case STATE_RUNNING:
                    abort(); // implement me
                    break;
                case STATE_PAUSED:
                    abort(); // implement me
                    break;
                case STATE_FINISHED:
                    abort(); // implement me
                    break;
            }
            break;
        }

        case TIMER_TICK: {
            if(debugEvents) printf("TIMER_TICK %d\n", e.data);
            switch(appState) {
                case STATE_DARK:
                    // Won't Happen
                    break;
                case STATE_WAITING:
                    assert(e.data == waitingTimer);
                    UpdateWaitingScreen();
                    break;
                case STATE_RUNNING:
                    abort(); // implement me
                    break;
                case STATE_PAUSED:
                    abort(); // implement me
                    break;
                case STATE_FINISHED:
                    abort(); // implement me
                    break;
            }
            break;
        }

        case PLAY_FINISHED: {
            if(debugEvents) printf("PLAY_FINISHED %d\n", e.data);
            switch(appState) {
                case STATE_DARK:
                    // Won't Happen
                    break;
                case STATE_WAITING:
                    // Won't Happen
                    break;
                case STATE_RUNNING:
                    // Won't Happen
                    break;
                case STATE_PAUSED:
                    // Won't Happen
                    break;
                case STATE_FINISHED:
                    abort(); // implement me
                    break;
            }
            break;
        }
    }
    return 0;
}
