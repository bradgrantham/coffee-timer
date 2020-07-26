#include <cstdio>
#include "platform.h"

int HandleEvent(const Event& e)
{
    static int myTimer;
    static bool cancelThisTimer = false;
    static int timerTickCount = 0;
    switch(e.type) {
        case INIT: {
            myTimer = StartTimer(10);
            timerTickCount = 0;
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
            myTimer = StartTimer(100);
            timerTickCount = 0;
            break;
        }
        case TIMER_TICK: {
            printf("TIMER_TICK %d\n", e.data);
            printf("this tick makes %d timer ticks so far\n", ++timerTickCount);
            if(cancelThisTimer) {
                int remaining = GetTimerRemaining(myTimer);
                if(remaining < 50) {
                    CancelTimer(myTimer);
                }
            }
            break;
        }
        case CLIP_FINISHED: {
            printf("CLIP_FINISHED %d\n", e.data);
            break;
        }
    }
    return 0;
}
