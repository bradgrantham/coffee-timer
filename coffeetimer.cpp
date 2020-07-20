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

// Play beepbeepbeep
// Wait 1 seconds
// repeat until timer expires
enum {
    FINISHED_BEEP,
    FINISHED_QUIET,
} finishedStateStep;

int waitingTimer;
int runningTimer;
int finishedTimer;
int beepSilenceTimer;
int beepClip;
constexpr int waitingToDarkDuration = 10; // 5 * 60;
constexpr int button1TimerDuration = 5; // 1 * 60;
constexpr int button2TimerDuration = 10; // 4 * 60;
constexpr int finishedToWaitingDuration = 10; // 5 * 60;

void DisplayTimeRemaining(int seconds)
{
    printf("%02d:%02d\n", seconds / 60, seconds % 60);
}

void EnterRunningState(int which)
{
    int seconds = (which == 0) ? button1TimerDuration : button2TimerDuration;
    runningTimer = StartTimer(seconds);
    DisplayTimeRemaining(seconds - 1);
    appState = STATE_RUNNING;
}

void UpdateRunningScreen()
{
    DisplayTimeRemaining(GetTimerRemaining(runningTimer));
}

void EnterWaitingState()
{
    if(debugStates) printf("EnterWaitingState\n");
    SetScreen(true);
    printf("draw 1m and 4m and smiley\n");
    waitingTimer = StartTimer(waitingToDarkDuration);
    appState = STATE_WAITING;
}

uint8_t samples[8000]; // XXX fill

void EnterFinishedState()
{
    if(debugStates) printf("EnterFinishedState\n");
    appState = STATE_FINISHED;
    finishedStateStep = FINISHED_BEEP;
    beepClip = PlayClip(0, sizeof(samples));
    finishedTimer = StartTimer(finishedToWaitingDuration);
    printf("beep beep beep\n");
}

void UpdateFinishedScreen()
{
    if(finishedStateStep == FINISHED_BEEP) {
        beepClip = -1;
        beepSilenceTimer = StartTimer(1);
        finishedStateStep = FINISHED_QUIET;
        printf("...\n");
    } else if(finishedStateStep == FINISHED_QUIET) {
        beepSilenceTimer = -1;
        beepClip = PlayClip(samples, sizeof(samples));
        finishedStateStep = FINISHED_BEEP;
        printf("beep beep beep\n");
    }
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
                    CancelTimer(waitingTimer);
                    if(e.data == BUTTON_1) {
                        EnterRunningState(0);
                    } else if(e.data == BUTTON_2) {
                        EnterRunningState(1);
                    } else {
                        abort();
                    }
                    // XXX enter timer
                    break;
                case STATE_RUNNING:
                    abort(); // implement me
                    break;
                case STATE_PAUSED:
                    abort(); // implement me
                    break;
                case STATE_FINISHED:
                    CancelClip(beepClip);
                    CancelTimer(finishedTimer);
                    EnterWaitingState();
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
                    EnterFinishedState();
                    break;
                case STATE_PAUSED:
                    abort(); // implement me
                    break;
                case STATE_FINISHED:
                    if(e.data == finishedTimer) {
                        CancelTimer(beepSilenceTimer);
                        beepSilenceTimer = -1;
                        CancelClip(beepClip);
                        beepClip = -1;
                        EnterWaitingState();
                    } else if(e.data == beepSilenceTimer) {
                        beepSilenceTimer = -1;
                        UpdateFinishedScreen();
                    } else {
                        abort();
                    }
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
                    assert(e.data == runningTimer);
                    UpdateRunningScreen();
                    break;
                case STATE_PAUSED:
                    abort(); // implement me
                    break;
                case STATE_FINISHED:
                    // Nothing
                    break;
            }
            break;
        }

        case CLIP_FINISHED: {
            if(debugEvents) printf("CLIP_FINISHED %d\n", e.data);
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
                    assert(finishedStateStep == FINISHED_BEEP);
                    UpdateFinishedScreen();
                    break;
            }
            break;
        }
    }
    return 0;
}
