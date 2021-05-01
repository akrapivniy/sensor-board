
#ifndef FONTS_H
#define FONTS_H


/* 8x8 Normal */
const unsigned char ssd1306_font_table[]= {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ASCII - 32
0x00,0x00,0x00,0x5F,0x5F,0x00,0x00,0x00, // ASCII - 33
0x00,0x00,0x03,0x07,0x00,0x07,0x03,0x00, // ASCII - 34
0x00,0x10,0x74,0x1C,0x77,0x1C,0x17,0x04, // ASCII - 35
0x00,0x24,0x2E,0x2A,0x7F,0x2A,0x3A,0x10, // ASCII - 36
0x00,0x4C,0x6A,0x76,0x1A,0x6A,0x56,0x33, // ASCII - 37
0x00,0x30,0x7A,0x4F,0x5D,0x37,0x7A,0x48, // ASCII - 38
0x00,0x00,0x04,0x07,0x03,0x00,0x00,0x00, // ASCII - 39
0x00,0x00,0x00,0x1C,0x3E,0x63,0x41,0x00, // ASCII - 40
0x00,0x00,0x41,0x63,0x3E,0x1C,0x00,0x00, // ASCII - 41
0x00,0x08,0x2A,0x3E,0x1C,0x3E,0x2A,0x08, // ASCII - 42
0x00,0x08,0x08,0x3E,0x3E,0x08,0x08,0x00, // ASCII - 43
0x00,0x00,0x00,0x60,0x60,0x00,0x00,0x00, // ASCII - 44
0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x00, // ASCII - 45
0x00,0x00,0x00,0x60,0x60,0x00,0x00,0x00, // ASCII - 46
0x00,0x60,0x30,0x18,0x0C,0x06,0x03,0x01, // ASCII - 47
0x00,0x1C,0x3E,0x61,0x43,0x3E,0x1C,0x00, // ASCII - 48
0x00,0x00,0x44,0x7F,0x7F,0x40,0x00,0x00, // ASCII - 49
0x00,0x46,0x67,0x71,0x59,0x4F,0x66,0x00, // ASCII - 50
0x00,0x22,0x63,0x49,0x4D,0x7F,0x32,0x00, // ASCII - 51
0x00,0x18,0x1C,0x52,0x7F,0x7F,0x50,0x00, // ASCII - 52
0x00,0x2F,0x6F,0x45,0x45,0x7D,0x39,0x00, // ASCII - 53
0x00,0x3C,0x7E,0x4B,0x49,0x79,0x30,0x00, // ASCII - 54
0x00,0x07,0x43,0x71,0x7D,0x0F,0x03,0x00, // ASCII - 55
0x00,0x36,0x7F,0x4D,0x59,0x7F,0x36,0x00, // ASCII - 56
0x00,0x06,0x4F,0x49,0x69,0x3F,0x1E,0x00, // ASCII - 57
0x00,0x00,0x00,0x66,0x66,0x00,0x00,0x00, // ASCII - 58
0x00,0x00,0x00,0x66,0x66,0x00,0x00,0x00, // ASCII - 59
0x00,0x00,0x08,0x1C,0x36,0x63,0x41,0x00, // ASCII - 60
0x00,0x14,0x14,0x14,0x14,0x14,0x14,0x00, // ASCII - 61
0x00,0x00,0x41,0x63,0x36,0x1C,0x08,0x00, // ASCII - 62
0x00,0x02,0x07,0x51,0x59,0x0F,0x06,0x00, // ASCII - 63
0x00,0x3E,0x41,0x5D,0x55,0x5D,0x51,0x1E, // ASCII - 64
0x00,0x40,0x70,0x1D,0x17,0x1F,0x78,0x60, // ASCII - 65
0x00,0x41,0x7F,0x7F,0x49,0x4F,0x7E,0x30, // ASCII - 66
0x00,0x1C,0x3E,0x63,0x41,0x41,0x42,0x27, // ASCII - 67
0x00,0x41,0x7F,0x7F,0x41,0x63,0x3E,0x1C, // ASCII - 68
0x00,0x41,0x7F,0x7F,0x49,0x5D,0x41,0x63, // ASCII - 69
0x00,0x41,0x7F,0x7F,0x49,0x1D,0x01,0x03, // ASCII - 70
0x00,0x1C,0x3E,0x63,0x41,0x51,0x72,0x77, // ASCII - 71
0x00,0x7F,0x7F,0x08,0x08,0x7F,0x7F,0x00, // ASCII - 72
0x00,0x00,0x41,0x7F,0x7F,0x41,0x00,0x00, // ASCII - 73
0x00,0x30,0x70,0x41,0x41,0x7F,0x3F,0x01, // ASCII - 74
0x00,0x7F,0x7F,0x08,0x1C,0x77,0x63,0x41, // ASCII - 75
0x00,0x41,0x7F,0x7F,0x41,0x40,0x60,0x70, // ASCII - 76
0x00,0x7F,0x7E,0x0C,0x18,0x0C,0x7E,0x7F, // ASCII - 77
0x00,0x7F,0x7E,0x0C,0x18,0x30,0x7F,0x7F, // ASCII - 78
0x00,0x1C,0x3E,0x63,0x41,0x63,0x3E,0x1C, // ASCII - 79
0x00,0x41,0x7F,0x7F,0x49,0x09,0x0F,0x06, // ASCII - 80
0x00,0x1C,0x3E,0x63,0x51,0x63,0x3E,0x1C, // ASCII - 81
0x00,0x7F,0x7F,0x09,0x19,0x7F,0x66,0x40, // ASCII - 82
0x00,0x66,0x6F,0x4D,0x59,0x7B,0x33,0x00, // ASCII - 83
0x00,0x03,0x41,0x7F,0x7F,0x41,0x03,0x00, // ASCII - 84
0x00,0x3F,0x7F,0x40,0x40,0x40,0x7F,0x3F, // ASCII - 85
0x00,0x03,0x0F,0x3D,0x70,0x1D,0x07,0x01, // ASCII - 86
0x00,0x0F,0x7F,0x30,0x1C,0x30,0x7F,0x0F, // ASCII - 87
0x00,0x63,0x77,0x1C,0x1C,0x77,0x63,0x00, // ASCII - 88
0x01,0x03,0x47,0x7C,0x78,0x47,0x03,0x01, // ASCII - 89
//0x00,0x67,0x73,0x59,0x4D,0x67,0x73,0x00, // ASCII - 90
0x00,0x06,0x09,0x09,0x06,0x00,0x00,0x00, // ASCII - 90 - degree symbol instead of Z
};


#endif /* FONTS_H */
