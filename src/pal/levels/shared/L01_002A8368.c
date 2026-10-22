#include "include_asm.h"

extern char D_L01_00189E20[];
extern void func_002C7CA8(void);
extern void func_002B4070(void);
extern void func_002ADDC8(void);
extern void func_002C37C8(void);
extern void func_002AEB80(void);
extern void func_002B9878(void);
extern void func_002A7740(void);
extern void func_002AB1C8(void);
extern void func_002A9520(void);
extern void func_002A9310(void);
extern void func_002FDB00(void *a0);
extern void func_002AB328(void);
extern void func_0030F444(int a0);
extern char D_L01_00189E20[];

void func_PAL_L01_002A8368(void) {
    char *p;

    func_002C7CA8();
    func_002B4070();
    func_002ADDC8();
    func_002C37C8();
    func_002AEB80();
    p = D_L01_00189E20;
    if (*(unsigned char *)(p + 0x22B4) != 0) {
        func_002B9878();
        func_002A7740();
        if (*(unsigned char *)(p + 0x22B4) != 0) {
            func_002AB1C8();
            func_002A9520();
            func_002A9310();
            func_002FDB00(p + 0x80);
            func_002AB328();
            func_0030F444(*(int *)(p + 0x2290));
        }
    }
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L01_002A8B30);
