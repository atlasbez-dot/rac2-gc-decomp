/* Nonmatching: 332/332 bytes.
 * Profile: -O2 -G0 -ffunction-sections.
 * Placement checks: US: 0/1; US2: 0/1; PAL: 0/1.
 * 332/332 bytes. The fill-pointer expression folds the table+0x4c into its relocation instead of materializing the base and then adding0x4c. Prologue and table-pointer allocation therefore differ, while the walk and complete16-byte scratch remain. -mno-split-addresses changes the head without closing it and is not retained.
 * Reopen with real table/fill cursor lifetimes or independently qualified address materialization. Preserve the full vector and its later W write with clobbering qcopy.
 */
#include "common.h"

extern int D_L09_00257110[];

extern float func_00282E80(void *, void *);
extern float func_00283CE0(int);
extern int func_00283DB8(void *buf, float value);
extern void func_L09_003FD460(void *);
extern void func_L09_003FD128(void *);
extern void *func_L09_003FE3B0(int index, int *table);

typedef int TI128 __attribute__((mode(TI)));

typedef union {
    TI128 q;
    float f[4];
} Vec4_L09;


void func_L09_003FE4D0(unsigned char *a0)
{
    unsigned char *s5 = a0;
    unsigned char *s4;
    int i;
    int *p;
    int *q = &D_L09_00257110[19];
    Vec4_L09 buf;

    s4 = *(unsigned char **)(s5 + 0x68);
    i = 19;
    while (i >= 0) {
        *q = -1;
        q--;
        i--;
    }
    if (*(short *)(s4 + 0x424) <= 0)
        return;
    p = D_L09_00257110;
    i = 0;
    do {
        char *s0;
        unsigned char *s1;
        TI128 *src;
        float f;

        s0 = (char *)func_L09_003FE3B0(s5[0x21], D_L09_00257110);
        *p = *(short *)(s0 + 0xB2);
        p++;
        src = (TI128 *)(s0 + 0x10);
        qcopy(&buf, src);
        buf.f[3] = 4.0f;
        f = func_00283CE0(*(short *)(s0 + 0x32));
        if (func_00283DB8(&buf, f) != -1) {
            s1 = *(unsigned char **)(s0 + 0x68);
            if (*(int *)(s1 + 0x42C) & 8)
                func_L09_003FD460(s0);
            if (*(int *)(s1 + 0x42C) & 2)
                func_L09_003FD128(s0);
        }
        i++;
    } while (i < *(short *)(s4 + 0x424));
}
