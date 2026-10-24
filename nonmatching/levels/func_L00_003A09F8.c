/* Nonmatching: -O2 -G0 -ffunction-sections. us: func_L00_003A09F8: 0 of 17 places match (src/levels/shared/L00_003A09F8.c); us2: func_L00_003A09F8: 0 of 17 places match (src/levels/shared/L00_003A09F8.c); pal: absent. One measured reconstruction484/520 bytes, frame0xA0 versus0xB0. Raster helper directly verified:8 integer coordinates plus64-bit color and texture. Two initial conversion calls retained, but retail caller stores their otherwise unused results in stack cells whose original source aggregate is unresolved. No fabricated stack locals or helper prototype to force those stores. Reopen with original caller aggregate evidence. */
#include "common.h"
extern int D_001A7340, D_001A7344, D_001A7348, D_001A734C;
extern int D_L00_001AF5A8;
extern float func_00283CE0(s32);
extern u64 func_0027C878(s32);
extern int func_00283CF0(float);
extern s32 func_002A77E0(s32);
extern void func_0027E018(int, int, int, int, int, int, int, int, s64, u64);
/* Tiles an alpha-blended texture over the current viewport. */
void func_L00_003A09F8(void *actor) {
    char *state = *(char **)((char *)actor + 0x68);
    u64 texture;
    s64 color;
    int columns, rows, row, column, nextRow;
    int u, v, x, y;
    float tick, limit, phase;
    /* Retail performs these setup conversions even though the raster helper does not consume their results. */
    func_00283CE0(D_001A7348);
    func_00283CE0(D_001A734C);
    texture = func_0027C878(30);
    rows = D_001A7340 / 32 + 1;
    columns = D_001A7344 / 32 + 1;
    for (row = 0; row < rows; row = nextRow) {
        nextRow = row + 1;
        for (column = 0; column < columns; column++) {
            phase = (float)D_L00_001AF5A8;
            tick = func_00283CE0(*(int *)(state + 0x140));
            limit = func_00283CE0(90);
            color = (int)((u32)func_00283CF0((tick * 127.5f) / limit) << 24) + 0x00FF7F7F;
            u = func_002A77E0(32);
            v = func_002A77E0(32);
            x = func_00283CF0((float)(row << 5) - phase);
            y = func_00283CF0((float)(column << 5) - phase);
            func_0027E018(x, y, 32, 32, u, v, 32, 32, color, texture);
        }
    }
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_003A09F8 - 520 bytes, 17 place(s), level 00_aranos_tutorial,
   retail at 0x003a09f8. Screened with tools/w10_screen.py: 11 call(s)
   [func_00283CE0@003A0A44, func_00283CE0@003A0A54, func_0027C878@003A0A60,
   func_00283CE0@003A0B14, func_00283CE0@003A0B20, func_00283CF0@003A0B30,
   func_002A77E0@003A0B40, func_002A77E0@003A0B4C, func_00283CF0@003A0B5C,
   func_00283CF0@003A0B6C, func_0027E018@003A0B9C]; data addresses
   materialised [0x1a0000, 0x1a0000, 0x1b0000]; float constants [0x1a0000,
   0x1a0000, 0xff0000, 0x42ff0000]; $gp-relative small data: no   saves: -;
   callee-saved registers saved [-]; words plain C cannot emit [COP1
   4680B5A0@0x00d8, COP1 46800020@0x00fc, COP1 4680AD60@0x0110]. Head: addiu
   $sp, $sp, -0xB0 ; sd $s6, 0x70($sp) ; sd $fp, 0x80($sp) ; sd $s0,
   0x40($sp) ; sd $s1, 0x48($sp) ; sd $s2, 0x50($sp). Not matched in this
   wave: the float code has to come out of the same expression tree to keep
   the FPU registers. What would unblock it: the exact source expression
   tree, so this cc1 picks the same registers in the same order. */
