/* Retained plain-C near miss; measured 23 October 2026, USA v1.01.
 * Profile: -O2 -G0 -ffunction-sections -frac2-zero-ti-por -fno-strength-reduce.
 * 348/360 bytes, 0/27 placements. Meaningful 80-entry update replaces the false MMI
 * impossibility claim: 0x700014a9 is por v0,zero,zero, reachable with TImode zero and
 * the qualified zero-ti-por profile. Two pointer expressions measured 336/360 and
 * 348/360; the latter restores the 0x80 frame. Duplicate stride lifetimes, saved
 * registers and copy/zero scheduling remain different. This is C-reachable code, not
 * handwritten evidence.
 */
#include "include_asm.h"
typedef int TI128 __attribute__((mode(TI)));
extern char *func_L00_0032A088(int, int);
extern int func_00282978(void *);
extern float func_00283B98(float, float);
extern void func_002AFFD8(void *, void *, int);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int D_L00_001A8FF0[];

int func_L00_003A87D8(char *object)
{
    char local[32];
    char *base = func_L00_0032A088(1483, *(short *)(*(char **)(object + 104) + 26));
    char *entry;
    int i, j;
    int active = 0;
    float *p;
    for (i = 0; i < 80; ++i) {
        entry = base + i * 112;
        if (*(short *)(entry + 18) != 0) {
            if (func_00282978(entry + 16) != 0) {
                *(short *)(entry + 18) = 0;
            } else {
                ++active;
                *(float *)(entry + 20) = func_00283B98(*(float *)(entry + 20), *(float *)(entry + 24));
                p = (float *)(base + 40) + i * 28;
                for (j = 8; j >= 0; --j, ++p)
                    *p += p[9];
                *(TI128 *)local = 0;
                *(float *)(local + 8) = 1.0f;
                *(float *)(local + 12) = 1.0f;
                if (D_L00_001A8FF0[0] != 0)
                    func_002AFFD8(base + i * 112, local, 1);
                entry = base + i * 112;
                func_00282D30(local + 16, local, *(float *)(entry + 36));
                func_00282CC0(entry, entry, local + 16);
            }
        }
    }
    return active;
}
