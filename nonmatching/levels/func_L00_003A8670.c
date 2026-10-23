/* Retained plain-C near miss; measured 23 October 2026, USA v1.01.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * 364/356 bytes, 0/27 placements. Meaningful 80-entry allocation and nine-element
 * initialization replace a screen. The entry forwards its second input as the real
 * index to func_L00_0032A088; func_00283CE0 takes an int. Context address lifetime,
 * float stores, branch and pointer arithmetic scheduling differ. -g restores division
 * padding; no-split-addresses worsens size to 372.
 */
#include "include_asm.h"
typedef int TI128 __attribute__((mode(TI)));
typedef struct { char pad[0x2294]; int level; } Context;
extern char D_00189E20[];
extern float D_L00_001AF718 __attribute__((sda));
extern float D_L00_001AF71C __attribute__((sda));
extern float D_L00_001AF724 __attribute__((sda));
extern float D_L00_001AF728 __attribute__((sda));
extern float D_L00_001AF72C __attribute__((sda));
extern float D_L00_001AF730 __attribute__((sda));
extern int D_L00_001AF734 __attribute__((sda));
extern int D_L00_001AF738 __attribute__((sda));
extern float D_L00_001AF73C __attribute__((sda));
extern float D_L00_001AF740 __attribute__((sda));
extern float D_L00_001AF744 __attribute__((sda));
extern char *func_L00_0032A088(int, int);
extern float func_002A7940(void);
extern float func_002A78D8(float, float);
extern float func_002A7878(float, float);
extern int func_002A7820(int, int);
extern float func_00283CE0(int);

void func_L00_003A8670(TI128 *position, int index)
{
    char *base = func_L00_0032A088(1483, index);
    char *entry = base;
    int i, j;
    int duration;
    Context *context = (Context *)D_00189E20;
    float high;
    float *p;
    for (i = 0; i < 80; ++i, entry += 112) {
        if (*(short *)(entry + 18) == 0) {
            *(short *)(entry + 18) = 1;
            *(TI128 *)entry = *position;
            *(float *)(entry + 20) = func_002A7940();
            *(float *)(entry + 24) = func_002A78D8(D_L00_001AF718, D_L00_001AF71C) * 0.017453294f;
            *(float *)(entry + 28) = func_002A7878(D_L00_001AF728, D_L00_001AF724);
            duration = func_002A7820(D_L00_001AF734, D_L00_001AF738);
            *(short *)(entry + 16) = duration;
            *(float *)(entry + 32) = 1.0f / func_00283CE0((short)duration);
            high = D_L00_001AF740;
            if (context->level == 29)
                high = D_L00_001AF744;
            *(float *)(entry + 36) = func_002A7878(D_L00_001AF73C, high) * 0.016666668f;
            p = (float *)(base + i * 112 + 76);
            for (j = 8; j >= 0; --j, ++p) {
                p[-9] = 0.0f;
                *p = func_002A7878(D_L00_001AF72C, D_L00_001AF730);
            }
            return;
        }
    }
}
