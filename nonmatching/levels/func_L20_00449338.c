/* Retained manual C near miss; no linked or exact-C credit.
 * Profile: -O2 -G8 -ffunction-sections. US: 624/624 bytes, 0/1, exit 1.
 * Full state transitions, signed checkpoint index and ordered float tests are preserved.
 * Residual: history index/base GPR allocation and one branch-likely scheduling choice.
 * Three final index/page lifetime forms stayed at624 bytes with allocation mismatches.
 * Reopen with independent history layout or allocator evidence; no aliases or barriers. */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern s32 D_001A79F0 __attribute__((sda));

extern u8 D_0019B2E8[] __attribute__((nosda));

extern u32 D_00189EA0[] __attribute__((nosda));

extern int func_L00_00329520(void *, int);

extern int func_002B38B8(void *);

extern void func_002AD6F0(void *, void *, void *, void *);
extern void func_002A7750(char *, int, int);
extern void func_00282CF0(void *, void *, void *);

void func_L20_00449338(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    TI128 v0, v1, v2;
    int a1;
    unsigned int kind;
    u8 *historyPage;
    float f0, f1, f2, f3;

    qcopy(&v0, arg0 + 0x10);
    qcopy(&v1, arg0 + 0xF0);
    switch (*(u8 *)(arg0 + 0x20)) {
    case 0:
        *(float *)(state + 0x90) = 0.0f;
        qcopy(state + 0x60, arg0 + 0x10);
        qcopy(state + 0x70, arg0 + 0xF0);
        kind = *(u8 *)(arg0 + 0xB0);
        if (kind != 0xFF) {
            if (*(u32 *)(state + 0x8C) != 0) {
                historyPage = D_0019B2E8 + D_001A79F0 * 16;
                if (historyPage[kind] & 0x80) {
                    goto l2c;
                }
            }
        }
        a1 = *(int *)(state + 0x88);
        if (a1 != -1 && func_L00_00329520(D_00189EA0, a1) != 0) {
    l2c:
        f0 = *(float *)(state + 0x68);
        f1 = *(float *)(state + 0x80);
        *(u16 *)(arg0 + 0x34) |= 2;
        *(float *)(arg0 + 0x18) = f0 + f1;
        func_002A7750(arg0, 3, -1);
        } else {
            func_002A7750(arg0, 1, -1);
        }
        break;
    case 1:
        if (*(u8 *)(arg0 + 0xBC) != 0) {
            func_002A7750(arg0, 2, -1);
            break;
        }
        if (func_002B38B8(arg0) != 0) {
            func_002A7750(arg0, 2, -1);
            break;
        }
        kind = *(u8 *)(arg0 + 0xB0);
        if (kind != 0xFF) {
            if (*(u32 *)(state + 0x8C) != 0) {
                historyPage = D_0019B2E8 + D_001A79F0 * 16;
                if (historyPage[kind] & 0x80) {
                    func_002A7750(arg0, 2, -1);
                    break;
                }
            }
        }
        a1 = *(int *)(state + 0x88);
        if (a1 == -1) {
            break;
        }
        if (func_L00_00329520(D_00189EA0, (int)a1) != 0) {
            func_002A7750(arg0, 2, -1);
        }
        break;
    case 2: {
        float step, progress, amplitude, baseline;
        step = 1.0f / *(float *)(state + 0x84);
        *(float *)(state + 0x90) += step;
        if (*(float *)(state + 0x90) > 1.0f) *(float *)(state + 0x90) = 1.0f;
        progress = *(float *)(state + 0x90);
        amplitude = *(float *)(state + 0x80);
        baseline = *(float *)(state + 0x68);
        progress *= amplitude;
        baseline += progress;
        *(float *)(arg0 + 0x18) = baseline;
        if (*(float *)(state + 0x90) >= 1.0f)
            func_002A7750(arg0, 3, -1);
        break;
    }
    }
    if (*(u8 *)(arg0 + 0x20) < 3) {
        func_00282CF0(&v2, arg0 + 0x10, &v0);
        func_002AD6F0(state + 0x20, &v2, &v1, arg0 + 0xF0);
    }
}
