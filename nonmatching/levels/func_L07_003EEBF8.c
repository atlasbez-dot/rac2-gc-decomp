/* func_L07_003EEBF8 (232 bytes, level 07_siberius) -- NEAR MISS, not integrated.
   state: 224 bytes against the retail's 232; the two 16-byte copies that the
   retail groups are exact, but the two copies into the stack frame are
   grouped here and kept apart by the retail, and the prologue's save order
   differs.

   The file must build with the grouped-quadword copy, i.e.
     src/levels/07_siberius/L07_003EEBF8-rc2.c  -O2 -G0 -ffunction-sections -frac2-qcopy
   The retail's two copies out of the frame (`lq $v0,0($s2) ; sq $v0,0($a0)`
   and `lq $v0,0($s4) ; sq $v0,0($s1)`) are the grouped pair with the
   address in a register; without -frac2-qcopy this cc1 folds the offset into
   the `sq` and no 16-byte address is materialised at all.

   check.py (07_siberius), with the source below (the first difference):
     003EEBFC  sd $s0, 0x20($sp)        |  lq $v1, 0x0($a3)
     003EEC00  sd $s1, 0x28($sp)        |  sd $s0, 0x20($sp)
     003EEC04  daddu $s0, $a0, $zero     |  sd $s2, 0x30($sp)
     003EEC08  sd $s2, 0x30($sp)        |  daddu $s0, $a0, $zero
     003EEC1C  sd $ra, 0x48($sp)        |  sd $s1, 0x28($sp)
     003EEC24  addiu $a1, $zero, 0x2    |  sd $ra, 0x48($sp)
     003EEC28  lq $v0, 0x0($a2)         |  addiu $a1, $zero, 0x2
     003EEC2C  sq $v0, 0x0($sp)         |  lq $a0, 0x0($a2)
     003EEC30  lhu $v1, 0x34($s0)        |  lhu $v0, 0x34($s0)
     003EEC38  lq $v0, 0x0($a3)         |  sq $a0, 0x0($sp)
     003EEC3C  sq $v0, 0x0($s4)         |  andi $v0, $v0, 0xFFBE
   Retail keeps the two copies into the frame apart (`lq $a0,0($a2)` at
   +0x34 and `sq $a0,0($sp)` at +0x40, with the flag word and the call's
   argument in between), so its scheduler could move the loads; the grouped
   copy cannot be split, so here the two frame copies come out as one
   `lq $v0,0($a2) ; sq $v0,0($sp)` pair and the body is 8 bytes short.
   The save order differs too: the retail saves $s0, $s2, $s3, $s4, $s1, $ra
   and restores $s0..$s4, $ra; here the saves are $s0, $s1, $s2, $s3, $s4,
   $ra and the restores are in the order the scheduler picked.

   What is measured and right:
   - the retail's frame is 0x50 with two 16-byte locals (the copies of the
     two arguments) at +0 and +0x10, and the six saved registers at
     +0x20..+0x48;
   - the flags are masked and set before the call to func_002A7750(arg, 2,
     -1) and masked again after it, and the call's argument is a pointer,
     so the first argument's declaration has to be a pointer (an `int`
     declaration gives a 32-bit move where the retail has `daddu $a0,$s0,
     $zero`);
   - the state pointer (arg+0x68) is written at +0x110 with the second
     argument and read back after the calls, which is why the retail reloads
     it (`lw $a2,0x110($s1)`);
   - the two copies out of the frame are the grouped pair with $v0, exactly
     as the retail has them, and the destinations are materialised
     (`addiu $a0,$s1,0xF0`, `addiu $s1,$s1,0xD0`) - the grouped copy needs
     its addresses in registers, which is what the flag gives.

   Tried and not enough: the frame copies as an array and as two separate
   variables; the copies in both orders; the copy sources and destinations as
   pointer variables; the state pointer's load before and after the call; the
   flag update as one statement and as a read plus a store;
   -fno-schedule-insns, -mastra-keep-frame-order (the last one changes the
   prologue's order but not the frame copies). */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_002A7750(int, int, int);

extern void func_00283098(TI128 *, TI128 *, TI128 *);

extern void func_00282CC0(TI128 *, TI128 *, TI128 *);

void func_L07_003EEBF8(char *arg, char *a1, TI128 *a2, TI128 *a3)
{
    TI128 v[2];
    char *s1;
    unsigned short w;

    v[0] = *a2;
    v[1] = *a3;

    w = *(unsigned short *)(arg + 0x34);
    *(unsigned short *)(arg + 0x34) = (w & 0xFFBE) | 0x1000;

    func_002A7750(arg, 2, -1);
    *(int *)(arg + 0x98) = *(int *)(*(int *)(arg + 0x24) + 0x10);

    *(unsigned short *)(arg + 0x32) = 0xFF;
    *(unsigned char *)(arg + 0x30) = 0xFF;

    s1 = *(char **)(arg + 0x68);
    *(int *)(s1 + 0x110) = (int)a1;

    func_00283098((TI128 *)(arg + 0x10), &v[0], (TI128 *)(a1 + 0xC0));
    func_00282CC0((TI128 *)(arg + 0x10), (TI128 *)(arg + 0x10),
                  (TI128 *)(*(int *)(s1 + 0x110) + 0x10));

    w = *(unsigned short *)(arg + 0x34);
    *(unsigned short *)(arg + 0x34) = w & 0xEFFF;

    *(TI128 *)(s1 + 0xF0) = *(TI128 *)(arg + 0x10);
    *(TI128 *)(s1 + 0xD0) = v[1];
}
