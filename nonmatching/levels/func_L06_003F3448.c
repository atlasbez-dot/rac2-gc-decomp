/* Retained complete manual C reconstruction; nonmatching, not linked.
 * Checked source: src/levels/06_notak/L06_003F3448-helpers.c
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g
 * Retail US extent: 584 bytes.
 * Actual final coverage: us: 0/1, exit1, 576 compiled bytes; us2: 0/1, exit1, 576 compiled bytes; pal: 0/1, exit1, 576 compiled bytes.
 * Residual: 576/584 bytes; frame 0x40 versus retail 0x50. The saved-point address is not held in retail s3, and handle/branch scheduling differs. The observed pointer argument and pointer interpretation of func_L00_00345AF0 are retained; the shared zero stub family has no globally qualified unified C contract.
 * Reopen only with: A measured saved-point address lifetime witness plus a qualified shared-stub-family ABI resolution before any promotion. Do not delete the caller pointer slot to conform to the current zero-stub source index.
 * Earlier complete variants are retained privately. No native execution or
 * complete linked-program equality is claimed by these placement measurements.
 */
#include "common.h"

typedef int VectorBits __attribute__((mode(TI)));
extern int func_002A8600(char **, int, int, int);
extern char *func_L00_00345AF0(char *);
extern void func_002AB650(char *);
extern void func_002A0F48(char *);
extern s32 func_002AB1F0(u8 *);
extern void func_0026FEB8(const char *, ...);
extern char D_L06_001AF990[];
extern int D_L06_001B2348;

/* Allocate a child and initialize its rendering, health and parent linkage. */
char *func_L06_003F3448(char *parent, VectorBits *position)
{
    VectorBits point;
    char *state, *child, *result, *component;
    qcopy(&point, position);
    if (!parent)
        return 0;
    state = *(char **)(parent + 0x68);
    result = 0;
    child = 0;
    if (func_002A8600(&child, *(int *)(state + 0x84), 1, 1) == 0) {
        (*(unsigned char *)(state + 0x81))++;
        qcopy(child + 0x10, &point);
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
        component = (char *)func_002AB1F0((u8 *)result);
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
