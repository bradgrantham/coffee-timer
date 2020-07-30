#include <algorithm>
#include <cstdio>
#include "platform.h"
#include "utility.h"

int HandleEvent(const Event& e)
{
    static int value;

    static int myTimer;

    switch(e.type) {
        case INIT: {
            myTimer = StartTimer(3600 * 10);
            SetScreen(true);
            value = 120;
            break;
        }
        case SHORT_PRESS: {
            printf("SHORT_PRESS %d\n", e.data);
            if(e.data == BUTTON_1) {
                value = std::max(0, value - 15);
            } else if(e.data == BUTTON_2) {
                value = std::min(255, value + 15);
            }
            switch((GetTimerRemaining(myTimer) / 10) % 3) {
                case 0:
                    DrawRect(0, 0, 128, 128, Color(value, 0, 0));
                    DrawText(32, 32, "hey there", JUSTIFY_LEFT, JUSTIFY_TOP, Color(255, 255, 255), Color(value, 0, 0));
                    break;
                case 1:
                    DrawRect(0, 0, 128, 128, Color(0, value, 0));
                    DrawText(32, 32, "hey there", JUSTIFY_LEFT, JUSTIFY_TOP, Color(255, 255, 255), Color(0, value, 0));
                    break;
                case 2:
                    DrawRect(0, 0, 128, 128, Color(0, 0, value));
                    DrawText(32, 32, "hey there", JUSTIFY_LEFT, JUSTIFY_TOP, Color(255, 255, 255), Color(0, 0, value));
                    break;
            }
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
            printf("TIMER_TICK %d %u\n", e.data, (GetTimerRemaining(myTimer) / 10) % 3);
            switch((GetTimerRemaining(myTimer) / 10) % 3) {
                case 0:
                    DrawRect(0, 0, 128, 128, Color(value, 0, 0));
                    DrawText(32, 32, "hey there", JUSTIFY_LEFT, JUSTIFY_TOP, Color(255, 255, 255), Color(value, 0, 0));
                    break;
                case 1:
                    DrawRect(0, 0, 128, 128, Color(0, value, 0));
                    DrawText(32, 32, "hey there", JUSTIFY_LEFT, JUSTIFY_TOP, Color(255, 255, 255), Color(0, value, 0));
                    break;
                case 2:
                    DrawRect(0, 0, 128, 128, Color(0, 0, value));
                    DrawText(32, 32, "hey there", JUSTIFY_LEFT, JUSTIFY_TOP, Color(255, 255, 255), Color(0, 0, value));
                    break;
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
