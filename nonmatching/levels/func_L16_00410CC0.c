/* Retained complete C reconstruction; not linked or counted.
 * Profile: -O2 -G64 -ffunction-sections -Wa,-G64
 * 376/380 bytes; 0/1 placements in us, us2 and pal.
 * Residual: The 0x90 frame and full vector transfers agree, but row/next-index liveness and inner-loop allocation/order differ. The threshold is 2001, and a sentinel skips only its row.
 * Reopen: Independent row-index and endpoint-offset lifetime evidence, preserving the measured 64-byte accessed table prefix.
 * Trial-only markers and profiles are restored after checking.
 */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));

/* Partial table view: retail visits up to eight four-short rows. GP access
 * is independently evidenced; this is not a complete global extent claim. */
typedef struct { s16 row[8][4]; } RowTablePrefix;
extern RowTablePrefix D_L16_001B1710 __attribute__((sda));

extern u32 D_L16_001FE7C0[];

extern float func_L01_00311C18(void *, void *, void *, void *);

extern float func_00282E80(void *, void *);

/* Walks the level's table of short rows, keeping the closest match of the handle's
   measured pair in the handle and the winning row in the handle's second half. */
void func_L16_00410CC0(u8 *arg0, u8 *arg1)
{
    TI128 state;
    TI128 work;
    u32 *s4;
    u8 *fp;
    u8 *dest;
    f32 best;
    f32 f;
    f32 g;
    s32 row;
    s32 count;
    s16 v;
    s16 *r;

    s4 = *(u32 **)(arg0 + 0x68);
    best = 2001.0f;
    fp = *(u8 **)(D_L16_001FE7C0 + s4[92]);
    qcopy(&state, arg1);
    dest = (u8 *)s4 + 0x200;
    for (row = 0; row < 8; row++) {
        r = D_L16_001B1710.row[row];
        v = r[0];
        if (v == -1)
            continue;
        count = 0;
        for (;;) {
            if (v < row) {
                count++;
            } else {
                f = func_L01_00311C18(&work, fp + row * 16 + 0x10, fp + v * 16 + 0x10, arg1);
                g = func_00282E80(arg1, &work);
                if (g < best) {
                    best = g;
                    s4[0x7E] = v;
                    *(f32 *)((u8 *)s4 + 0x1FC) = f;
                    s4[0x7D] = row;
                    qcopy(&state, &work);
                }
                count++;
            }
            if (count >= 4)
                break;
            v = *++r;
            if (v == -1)
                break;
        }
    }
    qcopy(dest, &state);
}
