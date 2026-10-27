/* Retained near miss, 2026-10-26 (M11); not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections -mno-split-addresses.
 * 800/792 bytes; us: 0/27 placements.
 * Retail evidence used here: every address is its own lui/addiu pair (la) and the trail row
 * base is formed with mtlo + madd, which is what -mno-split-addresses gives; the odd
 * D_L00_0023D9E0-0x10 bases mean the inner loops run j = 1..4 over [j - 1] and [j].
 * Left: retail hoists nothing out of the i loop (no spilled &D_L00_0023D9E0 / i + 1, i + 1
 * lives in $fp), and D_L00_001B28B8[i] is la + addu, not a %hi($at) store. A goto i loop
 * stops the hoist but loses the madd (744 B).
 */
#include "common.h"
typedef unsigned int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float v[4]; } Vector;
extern short D_L00_001B28B0[];
extern unsigned short D_L00_001B28B8[];
extern Vector D_L00_0023D9E0[][5];
extern Vector D_L00_001B8DC0;
extern float D_L00_001AFA14 __attribute__((sda));
extern void func_002A7988(void *, float, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern float func_002A7878(float, float);
extern float func_002A78D8(float, float);
extern void func_002ACEC0(void *, void *, void *, float);

/* Four five-point lightning trails: a trail whose timer runs out is re-aimed from the
   object's position with random bends, a live one jitters each segment. */
void func_L00_003B4EF8(unsigned char *object)
{
    Vector position, direction, axis, displacements[4];
    int i, j;
    float sign, angle;

    qcopy(&position, object + 0x10);
    for (i = 0; i < 4; i++) {
        if (D_L00_001B28B0[i] == 0) continue;
        D_L00_001B28B0[i]--;
        if (D_L00_001B28B0[i] < 0) D_L00_001B28B0[i] = 0;
        if (D_L00_001B28B0[i] == 0) {
            D_L00_001B28B0[i] = 4;
            D_L00_001B28B8[i] = 64;
            func_002A7988(&direction, D_L00_001AFA14, D_L00_001AFA14);
            qcopy(&D_L00_0023D9E0[i][0], &position);
            sign = 1.0f;
            for (j = 1; j < 5; j++) {
                func_00282CF0(&axis, &D_L00_0023D9E0[i][j - 1], &D_L00_001B8DC0);
                angle = func_002A7878(0.17453295f, 0.78539824f) * sign;
                sign = -sign;
                func_002ACEC0(&direction, &direction, &axis, angle);
                func_00282CC0(&D_L00_0023D9E0[i][j], &D_L00_0023D9E0[i][j - 1], &direction);
            }
        } else {
            for (j = 1; j < 5; j++) {
                func_00282CF0(&displacements[j - 1], &D_L00_0023D9E0[i][j], &D_L00_0023D9E0[i][j - 1]);
                displacements[j - 1].v[0] += func_002A78D8(0.0f, 0.1f);
                displacements[j - 1].v[1] += func_002A78D8(0.0f, 0.1f);
                displacements[j - 1].v[2] += func_002A78D8(0.0f, 0.1f);
            }
            qcopy(&D_L00_0023D9E0[i][0], &position);
            for (j = 1; j < 5; j++)
                func_00282CC0(&D_L00_0023D9E0[i][j], &D_L00_0023D9E0[i][j - 1], &displacements[j - 1]);
            if (D_L00_001B28B0[i] > 0) D_L00_001B28B8[i] = 32;
            else D_L00_001B28B8[i] = 0;
        }
    }
}
