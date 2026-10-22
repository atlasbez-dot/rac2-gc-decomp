/* Near miss: 312 of the retail's 304 bytes; the call sequence and the body
 * match, the register choices and the delay slots do not.
 *
 * func_L01_002B35E8 (304 bytes, level 01 at 0x002B35E8; also 04:002D9018,
 * 07:002B1950, 08:002C41E0, 09:002B5580, 16:002B30B0).
 *
 * tools/check.py func_L01_002B35E8 --diff (with -frac2-qcopy on the unit):
 *   01_oozla: 312 bytes, expected 304
 *
 * The retail's 16-byte copy (lq/sq at 0x002B366C) needs the grouped R5900
 * quadword copy, so the unit has to be compiled with -frac2-qcopy (a sibling
 * file with that flag, as src/levels/20_yeedil/L20_0039E158.c does).
 *
 * What is left: the object pointer stays in $a1 here and in $a0 in the
 * retail (one extra daddu), the seven arguments of func_0028B3D0 are set up in
 * another order, and the D_0018F40 test keeps its constant and its load
 * swapped.
 */

#include "include_asm.h"

/* The game's 16-byte copy type: a whole vector or matrix moved in one quadword. */
typedef int TI128 __attribute__((mode(TI)));

extern char D_L01_00189E20[];

extern char D_L01_002FCC30[];

extern char D_L01_002FCC80[];

extern char D_L01_002FD550[];

extern char D_L01_001B4B00[];

extern char D_L01_001B5100[];

extern int D_0018F40;

extern void func_L00_002A53B8(void);

extern void func_0028B3D0(int a0, char *a1, char *a2, char *a3, char *a4, char *a5, char *a6);

extern void func_L00_002F6B90(int a0);

extern void func_L00_002A6708(void);

extern void func_L00_002D24B8(void);

extern int func_L00_002A4DB0(int *a0, int a1, int a2, char *a3);

extern void func_L01_002BEB90(int a0, int a1);

void func_L01_002B35E8(void) {
    char *p;
    int *v;
    int m;
    int r;

    func_L00_002A53B8();
    p = D_L01_00189E20;
    func_0028B3D0(0x23, 0, D_L01_002FCC30, D_L01_002FCC80, D_L01_002FD550, 0, 0);
    p[0x22B4] = 0;
    func_L00_002F6B90(3);
    v = *(int *)(p + 0xC14);
    if (v != 0)
        *(unsigned short *)((char *)v + 0x34) &= 0xFFF9;
    *(int *)(p + 0xC14) = 0;
    func_L00_002A6708();
    v = *(int *)(p + 0xC18);
    *(int *)(p + 0x2290) = v;
    *(TI128 *)((char *)v + 0x10) = *(TI128 *)(p + 0x80);
    *(int *)((char *)v + 0x9C) = 0;
    *(float *)(p + 0xC24) = 1.0f;
    func_L00_002D24B8();
    v = *(int *)(p + 0x2290);
    if (*(unsigned char *)((char *)v + 0x42) != 0xFF) {
        r = func_L00_002A4DB0(v, *(unsigned char *)((char *)v + 0x42),
                              *(unsigned char *)((char *)v + 0x40), D_L01_001B4B00);
        v = *(int *)(p + 0x2290);
        *(int *)((char *)v + 0x58) = r;
    }
    v = *(int *)(p + 0x2290);
    r = func_L00_002A4DB0(v, *(unsigned char *)((char *)v + 0x43),
                          *(unsigned char *)((char *)v + 0x41), D_L01_001B5100);
    v = *(int *)(p + 0x2290);
    *(int *)((char *)v + 0x5C) = r;
    if (*(int *)(p + 0x2294) == 0x61) {
        m = D_0018F40;
        if (m == 2 || m == 6)
            return;
    }
    func_L01_002BEB90(0, 1);
}
