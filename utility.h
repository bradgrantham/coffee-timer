#include "platform.h"

void InitFont();

enum Justification {JUSTIFY_LEFT, JUSTIFY_CENTER, JUSTIFY_RIGHT, JUSTIFY_TOP, JUSTIFY_BOTTOM};
void DrawText( int x, int y, const char *s, Justification horizJust, Justification vertJust, const Color& fg, const Color& bg);
