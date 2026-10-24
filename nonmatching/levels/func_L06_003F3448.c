/* Signature/interface follow-up, 23 October 2026.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * USA v1.01: 576/584 bytes, 0/1 carrying placements.
 * USA v2.00: 576/584 bytes, 0/1 carrying placements.
 * PAL: 576/584 bytes, 0/1 carrying placements.
 * func_0026FEB8 follows the canonical const-char-pointer variadic logger interface; both
 * existing diagnostic integer arguments remain.
 * This follows the current linked C contract; it does not independently prove the original
 * source declaration.
 * The retained C remains nonmatching. Earlier sizes and residual offsets below are
 * historical and superseded by this measurement; their reopening hypotheses remain
 * unqualified. No linked build was run for this follow-up.
 */

/* Historical measurements, superseded where inconsistent with the follow-up above. */
/* Nonmatching reconstruction, 23 October 2026.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * Final check.py coverage: us 0/1, us2 0/1, pal 0/1; no linked build run.
 * Scalar TI local versus stack vector; qcopy/barrier, initialization placement and -g: 572/576 versus 584.
 * Remaining: Local point address lifetime and handle-table register/branch scheduling differ.
 * Reopen with a matching stack-vector lifetime witness.
 */
#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern int func_002A8600(char **, int, int, int);
extern char *func_L00_00345AF0(char *);
extern void func_002AB650(char *);
extern void func_002A0F48(char *);
extern char *func_002AB1F0(char *);
extern void func_0026FEB8(const char *, ...);
extern char D_L06_001AF990[];
extern int D_L06_001B2348;

/* Allocate a child and initialize its rendering, health and parent linkage. */
char *func_L06_003F3448(char *parent, VectorBits *position)
{
    float point[4];
    char *state, *child, *result, *component;
    *(VectorBits *)point = *position;
    if (!parent)
        return 0;
    state = *(char **)(parent + 0x68);
    result = 0;
    child = 0;
    if (func_002A8600(&child, *(int *)(state + 0x84), 1, 1) == 0) {
        (*(unsigned char *)(state + 0x81))++;
        *(VectorBits *)(child + 0x10) = *(VectorBits *)point;
        *(int *)(child + 0x1C) = 0;
        *(unsigned char *)(child + 0x20) = 0;
        *(unsigned char *)(child + 0xBC) = 0;
        *(unsigned short *)(child + 0x34) = *(unsigned short *)(*(char **)(child + 0x24) + 0x44);
        *(float *)(child + 0x2C) = *(float *)(*(char **)(child + 0x24) + 0x24);
        *(unsigned char *)(child + 0x30) = 0xFF;
        *(unsigned short *)(child + 0x32) = 0xFF;
        *(unsigned char *)(child + 0x31) = 1;
        if (*(int *)(*(char **)(child + 0x24) + 0x40))
            *(unsigned short *)(child + 0x34) |= 0x10;
        if (*(unsigned char *)(*(char **)(child + 0x24) + 0xF))
            *(unsigned short *)(child + 0x34) |= 0x400;
        *(unsigned short *)(child + 0x36) = 0x7F80;
        *(unsigned char *)(child + 0x61) = 0xFF;
        *(unsigned char *)(child + 0x62) = 0xFF;
        *(unsigned char *)(child + 0xA8) = 0xFF;
        if (*(unsigned char *)(state + 0x83))
            *(float *)(child + 0x2C) = *(float *)(*(char **)(child + 0x24) + 0x24) * 0.1f;
        component = func_L00_00345AF0(child);
        if (component) {
            *(int *)(component + 0x6C) = 0;
            *(int *)(component + 0x94) = 0;
            *(short *)(component + 0x68) = 0;
        }
        if (*(short *)(parent + 0xB4) < *(short *)(child + 0xB4))
            *(short *)(child + 0xB4) = *(short *)(parent + 0xB4);
        *(short *)(parent + 0xB4) -= *(short *)(child + 0xB4);
        if (*(short *)(parent + 0xB4) < 0)
            *(short *)(parent + 0xB4) = 0;
        *(char **)(child + 0xB8) = parent;
        *(int *)(child + 0x98) = *(int *)(*(char **)(child + 0x24) + 0x10);
        func_002AB650(child);
        func_002A0F48(child);
        result = child;
        component = func_002AB1F0(result);
        if (component) {
            *(int *)(component + 0x24) = 0;
            *(int *)(component + 0x20) = 0;
            *(float *)component = (float)*(short *)(component + 4);
        }
    } else {
        func_0026FEB8(D_L06_001AF990, *(short *)(parent + 0xB2), D_L06_001B2348);
    }
    return result;
}
