/* Retained manual C reconstruction; not linked and not credited as matching.
 * Checked source: src/game/0028A670.c
 * Profile: -O2 -G0 -ffunction-sections
 * Retail US extent: 1192 bytes.
 * us: 0/28 (exit 1, 1208 compiled bytes); us2: 0/28 (exit 1, 1208 compiled bytes); pal: catalogue absent (exit 1).
 * Residual: 1208/1192 bytes. The frame is 0xB0, but GPR allocation, table-copy setup and color/draw scheduling differ. The first positive-color transition deliberately uses 0x60290000, as retail does.
 * Reopen only with: A measured source/storage model for the local widths and separately stored draw colors, or a qualified compiler change affecting this exact allocation pattern.
 * No complete linked build was run for this candidate.
 */
#include "include_asm.h"
typedef unsigned long u64;
typedef struct { int value, timer, age; short reserved, state; } CounterTransition;
typedef struct { float value[7]; } CounterWidths;
extern CounterTransition D_001B1928[2];
extern float D_001A8DE0[];
extern char D_001A8E00[];
extern unsigned char *D_001A8CFC;
extern float D_001B23A4;
extern u64 func_00283D38(unsigned int, unsigned int, float);
extern int func_00115DA8(char *, char *, ...);
extern int func_001157AC(char *);
extern int func_00336D50(unsigned char *, int);
extern void func_00300A00(char *, int, float, float, float, float, float);
extern void func_0027F980(int, int, u64, unsigned char *, int);
void func_0028A670(void)
{
    char text[16];
    CounterWidths widths = *(CounterWidths *)D_001A8DE0;
    int count = 1;
    unsigned int first = 0, second = 0;
    CounterTransition *row = D_001B1928;
    u64 color = 0;
    int x = 0, y = 0, firstX = 0, firstY = 0, secondX = 0, secondY = 0;
    float fade, scale = 0.0f, width;
    int len, yy;
    do {
        firstX = 0;
        switch (row->state) {
        case 1:
            fade = (float)row->age * 0.0714285746f;
            first = func_00283D38(0x00f0c070, 0x55f0c070, fade);
            second = func_00283D38(0x00442d00, 0x60442d00, fade);
            if (row->value < 0)
                color = func_00283D38(0x001010f0, 0x801010f0, fade);
            else
                color = func_00283D38(0x0029a1ff, 0x60290000, fade);
            x = 442; y = 36; firstX = 499; firstY = 2; secondX = 499; secondY = 2; scale = 1.0f;
            break;
        case 2:
            if (row->timer < 14) fade = (float)row->timer * 0.0714285746f;
            else fade = 1.0f;
            first = 0x55f0c070; second = 0x60442d00;
            if (row->value < 0)
                color = func_00283D38(0x001010f0, 0x801010f0, fade);
            else
                color = func_00283D38(0x8000ffff, 0x6029a1ff, fade);
            x = 442; y = 36; firstX = 499; firstY = 2; secondX = 499; secondY = 2; scale = 1.0f;
            break;
        case 3:
            if (row->timer < 7) fade = 1.0f;
            else fade = 1.0f - ((float)row->timer - 7.0f) * 0.142857149f;
            first = func_00283D38(0x00f0c070, 0x55f0c070, fade);
            second = func_00283D38(0x00442d00, 0x60442d00, fade);
            if (row->value < 0)
                color = func_00283D38(0x001010f0, 0x801010f0, fade);
            else
                color = func_00283D38(0x0029a1ff, 0x6029a1ff, fade);
            x = 442; y = 36; firstX = 499; firstY = 2; secondX = 499; secondY = 2; scale = 1.0f;
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
