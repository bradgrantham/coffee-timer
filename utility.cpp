#include "utility.h"

#include "8x16.h"

void InitFont()
{
    for(size_t i = 0; i < sizeof(fontbits); i++) {
        // UGH
        uint8_t r = 
            ((fontbits[i] & 0x80) >> 7) |
            ((fontbits[i] & 0x40) >> 5) |
            ((fontbits[i] & 0x20) >> 3) |
            ((fontbits[i] & 0x10) >> 1) |
            ((fontbits[i] & 0x08) << 1) |
            ((fontbits[i] & 0x04) << 3) |
            ((fontbits[i] & 0x02) << 5) |
            ((fontbits[i] & 0x08) << 7);
        fontbits[i] = r;
    }
}

void DrawText( int x, int y, const char *s, enum Justification just, const Color& fg, const Color& bg)
{
    unsigned char    *glyph;
    int    fx, fy, sx, sy;
    const char    *e;

    e = s;
    sy = y;
    while(*s != 0) {
        e = s;
        while((*e != '\0') && (*e != '\n'))
            e++;

        if(just == JUSTIFY_RIGHT) sx = x - (e - s) * fontwidth;
        else if(just == JUSTIFY_CENTER) sx = x - (e - s) * fontwidth / 2;
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
