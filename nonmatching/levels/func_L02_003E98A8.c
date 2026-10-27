/*
 * Updated manual-C near miss, 2026-10-25.
 * Measured unit: src/levels/02_maktar_nebula/L02_003E98A8-g8.c
 * Profile: -O2 -G8 -ffunction-sections -fno-strength-reduce
 * Actual release coverage: US 0/1 (exit1); US2 0/1 (exit1); PAL absent (exit1).
 * Current residual: 784/776 bytes. The source vector is now an incomplete view rather than
 * a one-byte object. GP versus absolute address formation, saved-register assignment and
 * nested strip loop allocation differ. The 64-byte inverse matrix and both 20-point strips
 * are retained.
 * Reopen only for: Independent global extent/storage evidence and a real actor/state/strip
 * lifetime model; no false size to enable GP addressing.
 * Older notes below are historical. Marker and trial-only profiles were restored.
 */

/* Nonmatching: USA v1.01: 0/1 carrying places; USA v2.00: 0/1 carrying places; PAL: absent. Final C 776/776 retail bytes. game -O2 -G8 -frac2-qcopy -frac2-qcopy-barrier -fno-strength-reduce. USA v1.01 and v2.00: 0/1 places, 776/776 bytes, first difference +0x14 (saved-register allocation). Absent from PAL catalogue. Seven measured trials: counted/unsigned/do loops and explicit next-side value. Ordinary strength reduction yields 752 or 792 bytes; disabling it and carrying nextSide reaches retail size. Reopen with a register-allocation/source-shape hypothesis; no linked build was run.  */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
extern char *D_L02_001B359C;
extern char D_L02_001B0BC0[] __attribute__((sda));
extern float D_L02_001B0C68 __attribute__((sda));
extern float D_L02_001B0C6C __attribute__((sda));
extern int D_L02_001B0C50 __attribute__((sda));
extern int D_L02_001B0C58 __attribute__((sda));
extern int D_L02_001B0C74 __attribute__((sda));
extern int D_L02_001B0C78 __attribute__((sda));
extern float D_L02_001B0C80 __attribute__((sda));
extern float D_L02_001B0C84 __attribute__((sda));
extern float D_L02_001B0C90 __attribute__((sda));
extern float D_L02_001B0C94 __attribute__((sda));
extern float D_L02_001B0CB4 __attribute__((sda));
extern float D_L02_001B0CB8 __attribute__((sda));
extern char D_L02_00249090[];
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00283698(void *, void *);
extern void func_L02_003E9040(void *);
extern void func_L02_003E91F0(void *);
extern void func_L02_003E9BB0(void *, int, int, int, float, float, float);

/* Updates the two strips twice, converting their points through actor space. */
void func_L02_003E98A8(char *actor) {
    char *state = *(char **)(actor + 0x68);
    char *record = D_L02_001B359C + *(int *)state * 0x100;
    float inverse[16];
    int color0, color1;
    int side, nextSide;
    int i;
    char *point;
    *(char **)(state + 0x4C) = record;
    func_00283098(state + 0x20, &D_L02_001B0BC0, actor + 0xC0);
    func_00282CC0(state + 0x20, state + 0x20, actor + 0x10);
    qcopy(state + 0x30, record + 0x10);
    D_L02_001B0C68 -= D_L02_001B0C6C;
    if (D_L02_001B0C68 <= -8.0f) D_L02_001B0C68 += 8.0f;
    color0 = (D_L02_001B0C50 << 24) | D_L02_001B0C74;
    color1 = (D_L02_001B0C58 << 24) | D_L02_001B0C78;
    func_L02_003E9040(actor);
    func_L02_003E91F0(actor);
    func_L02_003E9BB0(D_L02_00249090, color0, color1, *(int *)(state + 0x50), D_L02_001B0C80, D_L02_001B0C84, D_L02_001B0CB4);
    func_L02_003E9BB0(D_L02_00249090 + 0x140, color0, color1, *(int *)(state + 0x50), D_L02_001B0C90, D_L02_001B0C94, D_L02_001B0CB8);
    func_00283698(inverse, actor + 0xC0);
    for (side = 0; side < 2; side = nextSide) {
        nextSide = side + 1;
        i = 0;
        if (*(int *)(state + 0x50) > 0) {
          point = D_L02_00249090 + side * 0x140;
          do {
            func_00282CF0(point, point, actor + 0x10);
            func_00283098(point, point, inverse);
            *(float *)(point + 4) = -*(float *)(point + 4);
            func_00283098(point, point, actor + 0xC0);
            func_00282CC0(point, point, actor + 0x10);
            point += 0x10;
          } while (++i < *(int *)(state + 0x50));
        }
    }
    func_L02_003E9BB0(D_L02_00249090, color0, color1, *(int *)(state + 0x50), D_L02_001B0C80, D_L02_001B0C84, D_L02_001B0CB4);
    func_L02_003E9BB0(D_L02_00249090 + 0x140, color0, color1, *(int *)(state + 0x50), D_L02_001B0C90, D_L02_001B0C94, D_L02_001B0CB8);
    for (side = 0; side < 2; side = nextSide) {
        nextSide = side + 1;
        i = 0;
        if (*(int *)(state + 0x50) > 0) {
          point = D_L02_00249090 + side * 0x140;
          do {
            func_00282CF0(point, point, actor + 0x10);
            func_00283098(point, point, inverse);
            *(float *)(point + 4) = -*(float *)(point + 4);
            func_00283098(point, point, actor + 0xC0);
            func_00282CC0(point, point, actor + 0x10);
            point += 0x10;
          } while (++i < *(int *)(state + 0x50));
        }
    }
}
