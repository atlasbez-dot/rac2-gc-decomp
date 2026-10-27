/* M21 2026-10-26: 1188 of 1192 bytes with -O2 -G8 -ffunction-sections (us, level 00),
   ~92 lines off (was ~164). Fixed: func_00283D38 returns a 32-bit value (no dsll32/dsra32),
   case 1's second colour pair is 0x0029A1FF/0x6029A1FF (cross-jumped with case 2), the -G8
   profile gives retail's macro loads of D_001B23A4/D_001A8CFC, case 3 assigns its constants
   in its own order. Left: global allocation; retail keeps row in $s2, colour in $s3, yy in
   $s1 and spills count/first/second to the stack; here second takes $fp. */

#include "common.h"

typedef struct { int value, timer, age; short reserved, state; } CounterTransition;
typedef struct { float value[7]; } CounterWidths;
extern CounterTransition D_001B1928[2];
extern float D_001A8DE0[];
extern char D_001A8E00[];
extern unsigned char *D_001A8CFC;
extern float D_001B23A4;
extern unsigned int func_00283D38(unsigned int, unsigned int, float);
extern int func_00115DA8(char *, char *, ...);
extern int func_001157AC(char *);
extern int func_00336D50(unsigned char *, int);
extern void func_00300A00(char *, int, float, float, float, float, float);
extern void func_0027F980(int, int, unsigned int, unsigned char *, int);

void func_0028A670(void)
{
    char text[16];
    CounterWidths widths;
    int firstX, secondX, firstY, x, secondY, y;
    unsigned int color;
    CounterTransition *row;
    int count;
    unsigned int first, second;
    float fade, scale, width;
    int len, yy;

    row = D_001B1928;
    color = 0;
    y = 0;
    secondY = 0;
    x = 0;
    firstY = 0;
    secondX = 0;
    widths = *(CounterWidths *)D_001A8DE0;
    count = 1;
    scale = 0.0f;
    first = 0;
    second = 0;
    do {
        firstX = 0;
        switch (row->state) {
        case 1:
            fade = (float)row->age * 0.0714285746f;
            first = func_00283D38(0x00F0C070, 0x55F0C070, fade);
            second = func_00283D38(0x00442D00, 0x60442D00, fade);
            if (row->value < 0)
                color = func_00283D38(0x001010F0, 0x801010F0, fade);
            else
                color = func_00283D38(0x0029A1FF, 0x6029A1FF, fade);
            firstX = 499;
            firstY = 2;
            secondX = 499;
            secondY = 2;
            x = 442;
            scale = 1.0f;
            y = 36;
            break;
        case 2:
            if (row->timer < 14)
                fade = (float)row->timer * 0.0714285746f;
            else
                fade = 1.0f;
            first = 0x55F0C070;
            second = 0x60442D00;
            if (row->value < 0)
                color = func_00283D38(0x001010F0, 0x801010F0, fade);
            else
                color = func_00283D38(0x8000FFFF, 0x6029A1FF, fade);
            firstX = 499;
            firstY = 2;
            secondX = 499;
            secondY = 2;
            x = 442;
            scale = 1.0f;
            y = 36;
            break;
        case 3:
            if (row->timer < 7)
                fade = 1.0f;
            else
                fade = 1.0f - ((float)row->timer - 7.0f) * 0.142857149f;
            first = func_00283D38(0x00F0C070, 0x55F0C070, fade);
            second = func_00283D38(0x00442D00, 0x60442D00, fade);
            if (row->value < 0)
                color = func_00283D38(0x001010F0, 0x801010F0, fade);
            else
                color = func_00283D38(0x0029A1FF, 0x6029A1FF, fade);
            x = 442;
            scale = 1.0f;
            y = 36;
            firstX = 499;
            firstY = 2;
            secondX = 499;
            secondY = 2;
            break;
        }
        if (firstX) {
            func_00115DA8(text, D_001A8E00, row->value);
            len = func_001157AC(text);
            if (len > 0) {
                width = widths.value[len - 1];
                func_00300A00((char *)func_00336D50(D_001A8CFC + 0x8710, 178), first,
                    (float)firstX, (float)(int)((float)firstY * D_001B23A4 + 0.5f), scale, scale, width);
                func_00300A00((char *)func_00336D50(D_001A8CFC + 0x8710, 179), second,
                    (float)secondX, (float)(int)((float)secondY * D_001B23A4 + 0.5f), scale, scale, width);
                yy = (int)((float)y * D_001B23A4 + 0.5f);
                func_0027F980(x, yy, color, (unsigned char *)text, func_001157AC(text));
            }
        }
        row++;
    } while (--count >= 0);
}
