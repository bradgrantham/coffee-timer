#include "utility.h"

#include "8x16.h"

void DrawText( int x, int y, const char *str, Justification horizontaljust, Justification verticaljust, const Color& fg, const Color& bg)
{
    unsigned char    *glyph;
    int    fx, fy, sx, sy;
    const char    *e, *s;

    e = s = str;
    int lineCount = 0;
    while(*s != 0) {
        lineCount++;
        e = s;
        while((*e != '\0') && (*e != '\n')) {
            e++;
        }
	if(*e == '\n') {
	    e++;
        }
        s = e;
    }

    e = s = str;
    if(verticaljust == JUSTIFY_BOTTOM) {
        sy = y - lineCount * fontheight;
    } else if(verticaljust == JUSTIFY_CENTER) {
        sy = y - lineCount * fontheight / 2;
    } else { 
        sy = y;
    }
    while(*s != 0) {
        e = s;
        while((*e != '\0') && (*e != '\n')) {
            e++;
        }

        if(horizontaljust == JUSTIFY_RIGHT) sx = x - (e - s) * fontwidth;
        else if(horizontaljust == JUSTIFY_CENTER) sx = x - (e - s) * fontwidth / 2;
        else sx = x;

        fx = sx;
        fy = sy;
        while(s != e){
            glyph = fontbits + fontheight * *s;
            DrawBitmap(fx, fy, fontwidth, fontheight, glyph, 1, fg, bg);
            s++;
            fx += fontwidth;
        }

	if(*e == '\n')
	    e++;
        s = e;
        sy = sy + fontheight;
    }
}
