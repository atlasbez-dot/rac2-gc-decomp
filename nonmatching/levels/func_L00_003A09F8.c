/* Near miss (M38): 516/520 bytes, us 0/17, us2 0/17, absent from PAL. Profile -O2 -G0
 * -ffunction-sections -mno-split-addresses (retail's tied lui/lw loads that never fill a call
 * slot; sda or MACRO_ADDR spellings move the first one into the jal slot as $gp).
 * Solved: frame 0xB0 and the f20-f23 saves: the two setup conversions are stored into a
 * float[2] stack array (retail's sw f0,0x10/0x14), and the row/column positions are a float[2]
 * stack array whose elements are reloaded for the subtractions.
 * Left: the phase global is read `la v0; lwc1 f21,0(v0)` in retail ($at form here; incomplete,
 * sda, MACRO_ADDR and NOT_SDA spellings tie); the colour is `sll; addu` in retail where combine
 * makes it `or`; the 0xFF7F7F and 127.5f invariants sit after the inner-loop guard in retail. */
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
    float scale[2];
    float pos[2];

    scale[0] = func_00283CE0(D_001A7348);
    scale[1] = func_00283CE0(D_001A734C);
    texture = func_0027C878(30);
    rows = D_001A7340 / 32 + 1;
    columns = D_001A7344 / 32 + 1;
    for (row = 0; row < rows; row++) {
        for (column = 0; column < columns; column++) {
            pos[0] = (float)(row << 5);
            pos[1] = (float)(column << 5);
            phase = (float)D_L00_001AF5A8;
            tick = func_00283CE0(*(int *)(state + 0x140));
            limit = func_00283CE0(90);
            color = (func_00283CF0((tick * 127.5f) / limit) << 24) + 0x00FF7F7F;
            u = func_002A77E0(32);
            v = func_002A77E0(32);
            x = func_00283CF0(pos[0] - phase);
            y = func_00283CF0(pos[1] - phase);
            func_0027E018(x, y, 32, 32, u, v, 32, 32, color, texture);
        }
    }
}
