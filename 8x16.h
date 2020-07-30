static int fontwidth = 8, fontheight = 16;
static unsigned char fontbits[] = {
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7E,
0x81,
0xA5,
0x81,
0x81,
0xBD,
0x99,
0x81,
0x81,
0x7E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7E,
0xFF,
0xDB,
0xFF,
0xFF,
0xC3,
0xE7,
0xFF,
0xFF,
0x7E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x36,
0x7F,
0x7F,
0x7F,
0x7F,
0x3E,
0x1C,
0x08,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x08,
0x1C,
0x3E,
0x7F,
0x3E,
0x1C,
0x08,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x3C,
0x3C,
0xE7,
0xE7,
0xE7,
0x18,
0x18,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x3C,
0x7E,
0xFF,
0xFF,
0x7E,
0x18,
0x18,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x3C,
0x3C,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xE7,
0xC3,
0xC3,
0xE7,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3C,
0x66,
0x42,
0x42,
0x66,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xC3,
0x99,
0xBD,
0xBD,
0x99,
0xC3,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0x00,
0x00,
0x78,
0x70,
0x58,
0x4C,
0x1E,
0x33,
0x33,
0x33,
0x33,
0x1E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3C,
0x66,
0x66,
0x66,
0x66,
0x3C,
0x18,
0x7E,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFC,
0xCC,
0xFC,
0x0C,
0x0C,
0x0C,
0x0C,
0x0E,
0x0F,
0x07,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFE,
0xC6,
0xFE,
0xC6,
0xC6,
0xC6,
0xC6,
0xE6,
0xE7,
0x67,
0x03,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0xDB,
0x3C,
0xE7,
0x3C,
0xDB,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x01,
0x03,
0x07,
0x0F,
0x1F,
0x7F,
0x1F,
0x0F,
0x07,
0x03,
0x01,
0x00,
0x00,
0x00,
0x00,
0x00,
0x40,
0x60,
0x70,
0x78,
0x7C,
0x7F,
0x7C,
0x78,
0x70,
0x60,
0x40,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x3C,
0x7E,
0x18,
0x18,
0x18,
0x7E,
0x3C,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x66,
0x66,
0x66,
0x66,
0x66,
0x66,
0x66,
0x00,
0x66,
0x66,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFE,
0xDB,
0xDB,
0xDB,
0xDE,
0xD8,
0xD8,
0xD8,
0xD8,
0xD8,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x06,
0x1C,
0x36,
0x63,
0x63,
0x36,
0x1C,
0x30,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x7F,
0x7F,
0x7F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x3C,
0x7E,
0x18,
0x18,
0x18,
0x7E,
0x3C,
0x18,
0x7E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x3C,
0x7E,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x7E,
0x3C,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x30,
0x7F,
0x30,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x0C,
0x06,
0x7F,
0x06,
0x0C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x03,
0x03,
0x03,
0x7F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x24,
0x66,
0xFF,
0x66,
0x24,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x08,
0x1C,
0x1C,
0x3E,
0x3E,
0x7F,
0x7F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x7F,
0x3E,
0x3E,
0x1C,
0x1C,
0x08,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x3C,
0x3C,
0x3C,
0x18,
0x18,
0x18,
0x00,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x66,
0x66,
0x66,
0x24,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x36,
0x36,
0x7F,
0x36,
0x36,
0x36,
0x7F,
0x36,
0x36,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x3E,
0x63,
0x43,
0x03,
0x3E,
0x60,
0x60,
0x61,
0x63,
0x3E,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x43,
0x63,
0x30,
0x18,
0x0C,
0x06,
0x63,
0x61,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1C,
0x36,
0x36,
0x1C,
0x6E,
0x3B,
0x33,
0x33,
0x33,
0x6E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x0C,
0x0C,
0x0C,
0x06,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x30,
0x18,
0x0C,
0x0C,
0x0C,
0x0C,
0x0C,
0x0C,
0x18,
0x30,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x0C,
0x18,
0x30,
0x30,
0x30,
0x30,
0x30,
0x30,
0x18,
0x0C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x66,
0x3C,
0xFF,
0x3C,
0x66,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x7E,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x18,
0x0C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x40,
0x60,
0x30,
0x18,
0x0C,
0x06,
0x03,
0x01,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x63,
0x73,
0x7B,
0x6F,
0x67,
0x63,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x1C,
0x1E,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x7E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x60,
0x30,
0x18,
0x0C,
0x06,
0x03,
0x63,
0x7F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x60,
0x60,
0x3C,
0x60,
0x60,
0x60,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x30,
0x38,
0x3C,
0x36,
0x33,
0x7F,
0x30,
0x30,
0x30,
0x78,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x03,
0x03,
0x03,
0x3F,
0x60,
0x60,
0x60,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1C,
0x06,
0x03,
0x03,
0x3F,
0x63,
0x63,
0x63,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x63,
0x60,
0x60,
0x30,
0x18,
0x0C,
0x0C,
0x0C,
0x0C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x63,
0x63,
0x3E,
0x63,
0x63,
0x63,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x63,
0x63,
0x7E,
0x60,
0x60,
0x60,
0x30,
0x1E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x00,
0x00,
0x00,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x00,
0x00,
0x00,
0x18,
0x18,
0x0C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x60,
0x30,
0x18,
0x0C,
0x06,
0x0C,
0x18,
0x30,
0x60,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7E,
0x00,
0x00,
0x7E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x06,
0x0C,
0x18,
0x30,
0x60,
0x30,
0x18,
0x0C,
0x06,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x63,
0x30,
0x18,
0x18,
0x18,
0x00,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x63,
0x63,
0x7B,
0x7B,
0x7B,
0x3B,
0x03,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x08,
0x1C,
0x36,
0x63,
0x63,
0x7F,
0x63,
0x63,
0x63,
0x63,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3F,
0x66,
0x66,
0x66,
0x3E,
0x66,
0x66,
0x66,
0x66,
0x3F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3C,
0x66,
0x43,
0x03,
0x03,
0x03,
0x03,
0x43,
0x66,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1F,
0x36,
0x66,
0x66,
0x66,
0x66,
0x66,
0x66,
0x36,
0x1F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x66,
0x46,
0x16,
0x1E,
0x16,
0x06,
0x46,
0x66,
0x7F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x66,
0x46,
0x16,
0x1E,
0x16,
0x06,
0x06,
0x06,
0x0F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3C,
0x66,
0x43,
0x03,
0x03,
0x7B,
0x63,
0x63,
0x66,
0x5C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x63,
0x63,
0x63,
0x63,
0x7F,
0x63,
0x63,
0x63,
0x63,
0x63,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3C,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x78,
0x30,
0x30,
0x30,
0x30,
0x30,
0x33,
0x33,
0x33,
0x1E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x67,
0x66,
0x66,
0x36,
0x1E,
0x1E,
0x36,
0x66,
0x66,
0x67,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x0F,
0x06,
0x06,
0x06,
0x06,
0x06,
0x06,
0x46,
0x66,
0x7F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xC3,
0xE7,
0xFF,
0xFF,
0xDB,
0xC3,
0xC3,
0xC3,
0xC3,
0xC3,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x63,
0x67,
0x6F,
0x7F,
0x7B,
0x73,
0x63,
0x63,
0x63,
0x63,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3F,
0x66,
0x66,
0x66,
0x3E,
0x06,
0x06,
0x06,
0x06,
0x0F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x6B,
0x7B,
0x3E,
0x30,
0x70,
0x00,
0x00,
0x00,
0x00,
0x3F,
0x66,
0x66,
0x66,
0x3E,
0x36,
0x66,
0x66,
0x66,
0x67,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x63,
0x06,
0x1C,
0x30,
0x60,
0x63,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFF,
0xDB,
0x99,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xC3,
0xC3,
0xC3,
0xC3,
0xC3,
0xC3,
0xC3,
0x66,
0x3C,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xC3,
0xC3,
0xC3,
0xC3,
0xC3,
0xDB,
0xDB,
0xFF,
0x66,
0x66,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xC3,
0xC3,
0x66,
0x3C,
0x18,
0x18,
0x3C,
0x66,
0xC3,
0xC3,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xC3,
0xC3,
0xC3,
0x66,
0x3C,
0x18,
0x18,
0x18,
0x18,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFF,
0xC3,
0x61,
0x30,
0x18,
0x0C,
0x06,
0x83,
0xC3,
0xFF,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3C,
0x0C,
0x0C,
0x0C,
0x0C,
0x0C,
0x0C,
0x0C,
0x0C,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x01,
0x03,
0x07,
0x0E,
0x1C,
0x38,
0x70,
0x60,
0x40,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3C,
0x30,
0x30,
0x30,
0x30,
0x30,
0x30,
0x30,
0x30,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x08,
0x1C,
0x36,
0x63,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFF,
0x00,
0x00,
0x0C,
0x0C,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1E,
0x30,
0x3E,
0x33,
0x33,
0x33,
0x6E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x07,
0x06,
0x06,
0x1E,
0x36,
0x66,
0x66,
0x66,
0x66,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x03,
0x03,
0x03,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x38,
0x30,
0x30,
0x3C,
0x36,
0x33,
0x33,
0x33,
0x33,
0x6E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x7F,
0x03,
0x03,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1C,
0x36,
0x26,
0x06,
0x0F,
0x06,
0x06,
0x06,
0x06,
0x0F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6E,
0x33,
0x33,
0x33,
0x33,
0x33,
0x3E,
0x30,
0x33,
0x1E,
0x00,
0x00,
0x00,
0x07,
0x06,
0x06,
0x36,
0x6E,
0x66,
0x66,
0x66,
0x66,
0x67,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x00,
0x1C,
0x18,
0x18,
0x18,
0x18,
0x18,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x60,
0x60,
0x00,
0x70,
0x60,
0x60,
0x60,
0x60,
0x60,
0x60,
0x66,
0x66,
0x3C,
0x00,
0x00,
0x00,
0x07,
0x06,
0x06,
0x66,
0x36,
0x1E,
0x1E,
0x36,
0x66,
0x67,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1C,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x67,
0xFF,
0xDB,
0xDB,
0xDB,
0xDB,
0xDB,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3B,
0x66,
0x66,
0x66,
0x66,
0x66,
0x66,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x63,
0x63,
0x63,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3B,
0x66,
0x66,
0x66,
0x66,
0x66,
0x3E,
0x06,
0x06,
0x0F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6E,
0x33,
0x33,
0x33,
0x33,
0x33,
0x3E,
0x30,
0x30,
0x78,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3B,
0x6E,
0x66,
0x06,
0x06,
0x06,
0x0F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x06,
0x1C,
0x30,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x08,
0x0C,
0x0C,
0x3F,
0x0C,
0x0C,
0x0C,
0x0C,
0x6C,
0x38,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x33,
0x33,
0x33,
0x33,
0x33,
0x33,
0x6E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xC3,
0xC3,
0xC3,
0xC3,
0x66,
0x3C,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xC3,
0xC3,
0xC3,
0xDB,
0xDB,
0xFF,
0x66,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xC3,
0x66,
0x3C,
0x18,
0x3C,
0x66,
0xC3,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x7E,
0x60,
0x30,
0x1F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x33,
0x18,
0x0C,
0x06,
0x63,
0x7F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x70,
0x18,
0x18,
0x18,
0x0E,
0x18,
0x18,
0x18,
0x18,
0x70,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x18,
0x18,
0x00,
0x18,
0x18,
0x18,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x0E,
0x18,
0x18,
0x18,
0x70,
0x18,
0x18,
0x18,
0x18,
0x0E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6E,
0x3B,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x08,
0x1C,
0x36,
0x63,
0x63,
0x63,
0x7F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3C,
0x66,
0x43,
0x03,
0x03,
0x03,
0x43,
0x66,
0x3C,
0x30,
0x60,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x33,
0x00,
0x00,
0x33,
0x33,
0x33,
0x33,
0x33,
0x33,
0x6E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x30,
0x18,
0x0C,
0x00,
0x3E,
0x63,
0x7F,
0x03,
0x03,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x08,
0x1C,
0x36,
0x00,
0x1E,
0x30,
0x3E,
0x33,
0x33,
0x33,
0x6E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x33,
0x00,
0x00,
0x1E,
0x30,
0x3E,
0x33,
0x33,
0x33,
0x6E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x06,
0x0C,
0x18,
0x00,
0x1E,
0x30,
0x3E,
0x33,
0x33,
0x33,
0x6E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1C,
0x36,
0x1C,
0x00,
0x1E,
0x30,
0x3E,
0x33,
0x33,
0x33,
0x6E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3C,
0x66,
0x06,
0x06,
0x66,
0x3C,
0x30,
0x60,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x08,
0x1C,
0x36,
0x00,
0x3E,
0x63,
0x7F,
0x03,
0x03,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x63,
0x00,
0x00,
0x3E,
0x63,
0x7F,
0x03,
0x03,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x06,
0x0C,
0x18,
0x00,
0x3E,
0x63,
0x7F,
0x03,
0x03,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x66,
0x00,
0x00,
0x1C,
0x18,
0x18,
0x18,
0x18,
0x18,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x3C,
0x66,
0x00,
0x1C,
0x18,
0x18,
0x18,
0x18,
0x18,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x06,
0x0C,
0x18,
0x00,
0x1C,
0x18,
0x18,
0x18,
0x18,
0x18,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x63,
0x00,
0x08,
0x1C,
0x36,
0x63,
0x63,
0x7F,
0x63,
0x63,
0x63,
0x00,
0x00,
0x00,
0x00,
0x1C,
0x36,
0x1C,
0x00,
0x1C,
0x36,
0x63,
0x63,
0x7F,
0x63,
0x63,
0x63,
0x00,
0x00,
0x00,
0x00,
0x18,
0x0C,
0x06,
0x00,
0x7F,
0x66,
0x06,
0x3E,
0x06,
0x06,
0x66,
0x7F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x76,
0xDC,
0xD8,
0x7E,
0x1B,
0x3B,
0xEE,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7C,
0x36,
0x33,
0x33,
0x7F,
0x33,
0x33,
0x33,
0x33,
0x73,
0x00,
0x00,
0x00,
0x00,
0x00,
0x08,
0x1C,
0x36,
0x00,
0x3E,
0x63,
0x63,
0x63,
0x63,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x63,
0x00,
0x00,
0x3E,
0x63,
0x63,
0x63,
0x63,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x06,
0x0C,
0x18,
0x00,
0x3E,
0x63,
0x63,
0x63,
0x63,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x0C,
0x1E,
0x33,
0x00,
0x33,
0x33,
0x33,
0x33,
0x33,
0x33,
0x6E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x06,
0x0C,
0x18,
0x00,
0x33,
0x33,
0x33,
0x33,
0x33,
0x33,
0x6E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x63,
0x00,
0x00,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x7E,
0x60,
0x30,
0x1E,
0x00,
0x00,
0x63,
0x00,
0x3E,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x63,
0x00,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x7E,
0xC3,
0x03,
0x03,
0x03,
0xC3,
0x7E,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1C,
0x36,
0x26,
0x06,
0x0F,
0x06,
0x06,
0x06,
0x06,
0x67,
0x3F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xC3,
0x66,
0x3C,
0x18,
0xFF,
0x18,
0xFF,
0x18,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3F,
0x66,
0x66,
0x3E,
0x46,
0x66,
0xF6,
0x66,
0x66,
0x66,
0xCF,
0x00,
0x00,
0x00,
0x00,
0x00,
0x70,
0xD8,
0x18,
0x18,
0x18,
0x7E,
0x18,
0x18,
0x18,
0x18,
0x18,
0x1B,
0x0E,
0x00,
0x00,
0x00,
0x18,
0x0C,
0x06,
0x00,
0x1E,
0x30,
0x3E,
0x33,
0x33,
0x33,
0x6E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x30,
0x18,
0x0C,
0x00,
0x1C,
0x18,
0x18,
0x18,
0x18,
0x18,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x0C,
0x06,
0x00,
0x3E,
0x63,
0x63,
0x63,
0x63,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x0C,
0x06,
0x00,
0x33,
0x33,
0x33,
0x33,
0x33,
0x33,
0x6E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6E,
0x3B,
0x00,
0x3B,
0x66,
0x66,
0x66,
0x66,
0x66,
0x66,
0x00,
0x00,
0x00,
0x00,
0x6E,
0x3B,
0x00,
0x63,
0x67,
0x6F,
0x7F,
0x7B,
0x73,
0x63,
0x63,
0x63,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3C,
0x36,
0x36,
0x7C,
0x00,
0x7E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1C,
0x36,
0x36,
0x1C,
0x00,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x0C,
0x0C,
0x00,
0x0C,
0x0C,
0x06,
0x03,
0x63,
0x63,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x03,
0x03,
0x03,
0x03,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x60,
0x60,
0x60,
0x60,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x03,
0x03,
0x43,
0x63,
0x33,
0x18,
0x0C,
0x06,
0x73,
0xD9,
0x60,
0x30,
0xF8,
0x00,
0x00,
0x00,
0x03,
0x03,
0x43,
0x63,
0x33,
0x18,
0x0C,
0x66,
0x73,
0x69,
0x7C,
0x60,
0x60,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x00,
0x18,
0x18,
0x18,
0x3C,
0x3C,
0x3C,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6C,
0x36,
0x1B,
0x36,
0x6C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1B,
0x36,
0x6C,
0x36,
0x1B,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x88,
0x22,
0x88,
0x22,
0x88,
0x22,
0x88,
0x22,
0x88,
0x22,
0x88,
0x22,
0x88,
0x22,
0x88,
0x22,
0xAA,
0x55,
0xAA,
0x55,
0xAA,
0x55,
0xAA,
0x55,
0xAA,
0x55,
0xAA,
0x55,
0xAA,
0x55,
0xAA,
0x55,
0xBB,
0xEE,
0xBB,
0xEE,
0xBB,
0xEE,
0xBB,
0xEE,
0xBB,
0xEE,
0xBB,
0xEE,
0xBB,
0xEE,
0xBB,
0xEE,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x1F,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x1F,
0x18,
0x1F,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6F,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1F,
0x18,
0x1F,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6F,
0x60,
0x6F,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x60,
0x6F,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6F,
0x60,
0x7F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x7F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x18,
0x18,
0x18,
0x1F,
0x18,
0x1F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1F,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0xF8,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0xFF,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFF,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0xF8,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFF,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0xFF,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0xF8,
0x18,
0xF8,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0xEC,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0xEC,
0x0C,
0xFC,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFC,
0x0C,
0xEC,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0xEF,
0x00,
0xFF,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFF,
0x00,
0xEF,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0xEC,
0x0C,
0xEC,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFF,
0x00,
0xFF,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0xEF,
0x00,
0xEF,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x18,
0x18,
0x18,
0x18,
0x18,
0xFF,
0x00,
0xFF,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0xFF,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFF,
0x00,
0xFF,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFF,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0xFC,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x18,
0x18,
0x18,
0xF8,
0x18,
0xF8,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xF8,
0x18,
0xF8,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFC,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0xFF,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x6C,
0x18,
0x18,
0x18,
0x18,
0x18,
0xFF,
0x18,
0xFF,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x1F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xF8,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0x0F,
0x0F,
0x0F,
0x0F,
0x0F,
0x0F,
0x0F,
0x0F,
0x0F,
0x0F,
0x0F,
0x0F,
0x0F,
0x0F,
0x0F,
0x0F,
0xF0,
0xF0,
0xF0,
0xF0,
0xF0,
0xF0,
0xF0,
0xF0,
0xF0,
0xF0,
0xF0,
0xF0,
0xF0,
0xF0,
0xF0,
0xF0,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0xFF,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6E,
0x3B,
0x1B,
0x1B,
0x1B,
0x3B,
0x6E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1E,
0x33,
0x33,
0x33,
0x1B,
0x33,
0x63,
0x63,
0x63,
0x33,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x63,
0x63,
0x03,
0x03,
0x03,
0x03,
0x03,
0x03,
0x03,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x36,
0x36,
0x36,
0x36,
0x36,
0x36,
0x36,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x63,
0x06,
0x0C,
0x18,
0x0C,
0x06,
0x63,
0x7F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7E,
0x1B,
0x1B,
0x1B,
0x1B,
0x1B,
0x0E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x66,
0x66,
0x66,
0x66,
0x66,
0x3E,
0x06,
0x06,
0x03,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6E,
0x3B,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7E,
0x18,
0x3C,
0x66,
0x66,
0x66,
0x3C,
0x18,
0x7E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1C,
0x36,
0x63,
0x63,
0x7F,
0x63,
0x63,
0x36,
0x1C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1C,
0x36,
0x63,
0x63,
0x63,
0x36,
0x36,
0x36,
0x36,
0x77,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x78,
0x0C,
0x18,
0x30,
0x7C,
0x66,
0x66,
0x66,
0x66,
0x3C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7E,
0xDB,
0xDB,
0xDB,
0x7E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xC0,
0x60,
0x7E,
0xDB,
0xDB,
0xCF,
0x7E,
0x06,
0x03,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x38,
0x0C,
0x06,
0x06,
0x3E,
0x06,
0x06,
0x06,
0x0C,
0x38,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x63,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x7F,
0x00,
0x00,
0x7F,
0x00,
0x00,
0x7F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x7E,
0x18,
0x18,
0x00,
0x00,
0xFF,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x0C,
0x18,
0x30,
0x60,
0x30,
0x18,
0x0C,
0x00,
0x7E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x30,
0x18,
0x0C,
0x06,
0x0C,
0x18,
0x30,
0x00,
0x7E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x70,
0xD8,
0xD8,
0xD8,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x18,
0x1B,
0x1B,
0x1B,
0x0E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x00,
0x7E,
0x00,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6E,
0x3B,
0x00,
0x6E,
0x3B,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1C,
0x36,
0x36,
0x1C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xF0,
0x30,
0x30,
0x30,
0x30,
0x30,
0x37,
0x36,
0x36,
0x3C,
0x38,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1B,
0x36,
0x36,
0x36,
0x36,
0x36,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x0E,
0x1B,
0x0C,
0x06,
0x13,
0x1F,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x3E,
0x3E,
0x3E,
0x3E,
0x3E,
0x3E,
0x3E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
};
