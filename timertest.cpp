#include <cstdio>
#include "platform.h"

int HandleEvent(const Event& e)
{
    static int myTimer;
    static bool cancelThisTimer = false;
    switch(e.type) {
        case INIT: {
            myTimer = StartTimer(10);
            break;
        }
        case SHORT_PRESS: {
            printf("SHORT_PRESS %d\n", e.data);
            break;
        }
        case LONG_PRESS: {
            printf("LONG_PRESS %d\n", e.data);
            break;
        }
        case TIMER_FINISHED: {
            printf("TIMER_FINISHED %d\n", e.data);
            cancelThisTimer = true;
            myTimer = StartTimer(10);
            break;
        }
        case TIMER_TICK: {
            printf("TIMER_TICK %d\n", e.data);
            if(cancelThisTimer) {
                int remaining = GetTimerRemaining(myTimer);
                if(remaining < 5) {
                    CancelTimer(myTimer);
                }
            }
            break;
        }
        case PLAY_FINISHED: {
            printf("PLAY_FINISHED %d\n", e.data);
            break;
        }
    }
    return 0;
}
