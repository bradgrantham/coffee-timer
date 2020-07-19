#include <cstdio>
#include "timer_platform.h"

int HandleEvent(const Event& e)
{
    switch(e.type) {
        case SHORT_PRESS: {
            printf("SHORT_PRESS %d\n", e.data);
            break;
        }
        case LONG_PRESS: {
            printf("LONG_PRESS %d\n", e.data);
            break;
        }
        case TIMER_FINISH: {
            printf("TIMER_FINISH %d\n", e.data);
            break;
        }
        case TIMER_TICK: {
            printf("TIMER_TICK %d\n", e.data);
            break;
        }
        case PLAY_FINISH: {
            printf("PLAY_FINISH %d\n", e.data);
            break;
        }
    }
    return 0;
}
