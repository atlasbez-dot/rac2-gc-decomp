#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_002C95C0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_002C97E0);

extern char D_00189E20_4[];
extern void func_L00_002C42E0(int a0, int a1);
extern int func_L00_0032EF10(int, int, int *);
extern int func_L00_002C3A40(void);
extern int func_L00_0032EFB0(int, int, int, int);
extern int D_00138320[];

/* Looks the object up in the shared table and stops when the lookup fails; otherwise the state
 * machine's offset advances the object and a second lookup asks for a transition when it
 * succeeds.  A set state word, a timer past 0.9 and a state other than the idle one ask for the
 * same transition, and a zero second argument asks for it with another code. */
int func_PAL_L00_002CA360(int arg0, int arg1)
{
    int index;
    int r;
    char *p;

    if (func_L00_0032EF10(0x40, arg0, &index) == 0)
        return 0;
    r = func_L00_002C3A40();
    if ((D_00138320[0] & 8) && r > 0) {
        if (func_L00_0032EFB0(0x40, 0x1F000, arg0 + r, r) != 0) {
            func_L00_002C42E0(0xB, 1);
            return 1;
        }
    }
    p = D_00189E20_4;
    if (*(short *)(p + 0x1454) != 0) {
        if (0.9f < *(float *)(p + 0x24B8)) {
            if (func_L00_002C3A78() != 2) {
                func_L00_002C42E0(0xB, 1);
                return 1;
            }
        }
    }
    if (arg1 != 0)
        return 0;
    func_L00_002C42E0(7, 1);
    return 1;
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_002CA448);
