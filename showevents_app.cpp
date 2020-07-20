#include <cstdio>
#include "platform.h"

int HandleEvent(const Event& e)
{
    switch(e.type) {
        case INIT: {
            printf("INIT %d\n", e.data);
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
            break;
        }
        case TIMER_TICK: {
            printf("TIMER_TICK %d\n", e.data);
            break;
        }
        case CLIP_FINISHED: {
            printf("CLIP_FINISHED %d\n", e.data);
            break;
        }
    }
    return 0;
}
