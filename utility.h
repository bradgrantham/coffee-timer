#include "platform.h"

void InitFont();

enum Justification {JUSTIFY_LEFT, JUSTIFY_CENTER, JUSTIFY_RIGHT};
void DrawText( int x, int y, const char *s, enum Justification just, const Color& fg, const Color& bg);
