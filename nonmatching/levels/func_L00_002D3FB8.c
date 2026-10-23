/* Default profile: 132/136 bytes in us/pal/us2, 0/27 each. The canonical 32-bit identity call and overflow behavior are reconstructed. Retail copies the loaded ceiling into a1 and retains the sum in a2; this compiler removes that transfer. A single result variable measured 124 bytes and was worse.
 * Profile: -O2 -G0 -ffunction-sections
 * us: 132 bytes, expected 136
 * pal: 132 bytes, expected 136
 * us2: 132 bytes, expected 136
 */
#include "include_asm.h"
typedef struct { unsigned char pad[142]; unsigned short f8E; unsigned char rest[80]; } Entry_262570;
extern Entry_262570 D_L00_00262570[];

extern int func_L00_002D3FB0(int);
extern unsigned char D_00139568[];
extern int D_00139688[];

int func_L00_002D3FB8(int a0, int a1)
{
    int idx = func_L00_002D3FB0(a0);
    int *slot = &D_00139688[idx];
    Entry_262570 *e;
    int v = *slot + a1;
    int ceiling;

    *slot = v;
    e = &D_L00_00262570[D_00139568[idx]];
    ceiling = e->f8E;
    if (ceiling != 0) {
        int overflow = v - ceiling;
        if (overflow <= 0) return 0;
        *slot = ceiling;
        return overflow;
    }
    return 0;
}
