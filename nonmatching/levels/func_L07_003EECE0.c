/* func_L07_003EECE0 (292 bytes, level 07_siberius) -- NEAR MISS, not integrated.
   state: 296 bytes against the retail's 292; the body, the branches, the two
   calls with their float arguments, the table lookup and the three 16-byte
   copies are the retail's, but the frame is 0x40 against the retail's 0x30
   (two callee-saved registers too many) and the level global is addressed
   differently.

   The file must build with the grouped-quadword copy, i.e.
     src/levels/07_siberius/L07_003EECE0-rc2.c  -O2 -G0 -ffunction-sections -frac2-qcopy
   The retail's three 16-byte copies are the grouped `lq $v0,0($a1) ;
   sq $v0,0($a0)` pair with the address in a register; without -frac2-qcopy
   this cc1 folds the destination offset into the `sq`.

   check.py (07_siberius), with the source below:
     003EED00  lui $s3, 0x0            |  lw $a3, 0x24($s0)
     003EED78  lw $s2, 0x0($s3)        |  lw $v0, 0x23CC($v0)
   Retail reads the level global D_L07_001B23CC as `lui $v0,0x1B ;
   lw $v0,0x23CC($v0)` - the %hi in a register and the %lo as the
   displacement - and does it three times; this cc1 materialises the address
   as a split 64-bit pair instead (the "la" form docs/COMPILER-NOTES.md
   records as a wall) and needs two more callee-saved registers for it.

   What is measured and right:
   - the branches: `if (*(int *)(s1 + 0x98) != 0)` and, inside it,
     `if (func_00283DB8(&tmp, 128.0f) != -1)`; both skip the first copy, so
     the retail's two branches land on the same word (+0x58);
   - the frame holds one 16-byte scratch (the argument of func_00282D60 and
     func_00283DB8) at +0, the three saved registers at +0x10..+0x20;
   - the table is indexed by a byte offset: `index * 128 + base + 0x30`, with
     the global's value loaded as a 32-bit word;
   - the float part reads the same table at index *(int *)(s1 + 0x94) and
     calls func_00283248 with (f12 - f1, f13 - f0), the result going to
     s1+0xE8.

   Tried and not enough: the two index reads through a local and through the
   expression; the global as an `unsigned int` and as a `char *`; the copies
   in both orders; -fno-schedule-insns and -mastra-keep-frame-order (neither
   changes the global's addressing). */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_002A7750(int, int, int);

extern void func_00282D60(TI128 *, char *, float);

extern int func_00283DB8(TI128 *, float);

extern float func_00283248(float, float);

extern unsigned int D_L07_001B23CC;

void func_L07_003EECE0(char *arg)
{
    TI128 tmp;
    char *s0 = arg;
    char *s1;
    unsigned int base;
    unsigned short v;
    int r;
    float f0, f1;

    v = *(unsigned short *)(arg + 0x34);
    *(int *)(arg + 0x98) = *(int *)(*(int *)(arg + 0x24) + 0x10);
    *(unsigned short *)(arg + 0x34) = (v & 0xFFBE) | 0x1000;
    func_002A7750(arg, 3, -1);
    *(unsigned char *)(arg + 0x30) = 0xFF;
    *(unsigned short *)(arg + 0x32) = 0xFF;

    s1 = *(char **)(arg + 0x68);
    if (*(int *)(s1 + 0x98) != 0) {
        func_00282D60(&tmp, s0, 0.0009765625f);
        r = func_00283DB8(&tmp, 128.0f);
        if (r != -1) {
            base = D_L07_001B23CC;
            *(TI128 *)(arg + 0x10) = *(TI128 *)(base + *(int *)(s1 + 0x98) * 128 + 0x30);
        }
    }

    base = D_L07_001B23CC;
    f1 = *(float *)(arg + 0x10);
    f0 = *(float *)(arg + 0x14);
    r = *(int *)(s1 + 0x94);
    r = r * 128 + base;
    *(float *)(s1 + 0xE8) = func_00283248(*(float *)(r + 0x30) - f1, *(float *)(r + 0x34) - f0);

    *(TI128 *)(s1 + 0xF0) = *(TI128 *)(arg + 0x10);

    r = *(int *)(s1 + 0x94);
    r = r * 128 + base;
    *(TI128 *)(s1 + 0xD0) = *(TI128 *)(r + 0x30);
}
