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
            value = 120;
            InitFont();
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
                    DrawRect(0, 0, 127, 127, Color(value, 0, 0));
                    DrawText(32, 32, "hey there", JUSTIFY_LEFT, Color(255, 255, 255), Color(value, 0, 0));
                    break;
                case 1:
                    DrawRect(0, 0, 127, 127, Color(0, value, 0));
                    DrawText(32, 32, "hey there", JUSTIFY_LEFT, Color(255, 255, 255), Color(0, value, 0));
                    break;
                case 2:
                    DrawRect(0, 0, 127, 127, Color(0, 0, value));
                    DrawText(32, 32, "hey there", JUSTIFY_LEFT, Color(255, 255, 255), Color(0, 0, value));
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
            printf("TIMER_TICK %d\n", e.data);
            switch((GetTimerRemaining(myTimer) / 10) % 3) {
                case 0:
                    DrawRect(0, 0, 127, 127, Color(value, 0, 0));
                    DrawText(32, 32, "hey there", JUSTIFY_LEFT, Color(255, 255, 255), Color(value, 0, 0));
                    break;
                case 1:
                    DrawRect(0, 0, 127, 127, Color(0, value, 0));
                    DrawText(32, 32, "hey there", JUSTIFY_LEFT, Color(255, 255, 255), Color(0, value, 0));
                    break;
                case 2:
                    DrawRect(0, 0, 127, 127, Color(0, 0, value));
                    DrawText(32, 32, "hey there", JUSTIFY_LEFT, Color(255, 255, 255), Color(0, 0, value));
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
