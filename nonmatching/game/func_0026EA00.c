/* func_0026EA00 - 196 bytes, 1 place (the boot), retail at 0x0026EA00: the
   engine's start-up loop: two calls, then a loop of 65 iterations that
   rebuilds the resident object's matrix, with the counter in $s0.

   Measured near miss: 45 of the 49 instructions are the retail's, in the
   retail's order, with the retail's argument setups for all thirteen calls
   and the retail's loop (the counter in $s0, the decrement in the delay slot
   of the call to func_00284FC0, the back edge with `ld $ra` in its delay
   slot).  Two differences remain:

   1. The resident object's address.  The retail computes it once, in $v0
      (`lui $v0,0x1C ; addiu $v0,$v0,-0x5140`), copies it into the
      callee-saved $s1 (`daddu $s1,$v0,$zero`) and reads the first call's
      argument from $v0 (`lw $a1,0x14($v0)`), while the loop reads it from
      $s1 (`lw $v0,0x14($s1)`).  This attempt computes the address straight
      into $s1 (`lui $v0,0x1B ; addiu $s1,$v0,-0x5140`, the split form) and
      reads both places from $s1.  The two uses are the same address, so the
      common-subexpression pass folds them into one value; the retail's
      compiler kept the early use on the original register and copied the
      value into the callee-saved register for the loop.

   2. The order of two zero arguments of the call to func_0027DDC0: the
      retail sets $a3 (the counter), then $a2, then $a1, and puts $a0 in the
      delay slot; this attempt sets $a3, then $a1, then $a2, and puts $a0 in
      the delay slot.  The two arguments are the same constant, so only their
      order differs.

   What was tried: the first call's argument through the local pointer and
   through the global (`*(void **)(D_001BAEC0 + 20)`), the local pointer
   copied into a second variable before and after the calls (the copy
   disappears), the address written as `&D_001BAEC0[0]` and read as
   `&D_001BAEC0[20]`, the declarations of func_0027DDC0 as (int,int,int,int),
   (void*,void*,void*,int), (int,int,void*,int), (void*,int,int,int) and
   (int,void*,int,int), the third argument cast to (void *), and the flags
   `-O1`, `-mno-split-addresses`, `-fno-schedule-insns`, `-fno-schedule-insns2`,
   `-fno-expensive-optimizations` and their pairs.

   What is still open: the copy of the address into the callee-saved register
   (the "two names for the same pointer" shape of docs/COMPILER-NOTES.md:
   the copy survives there when the walk modifies the copy) and the order of
   two equal constant arguments.  */

#include "include_asm.h"

extern char D_001BAEC0[];
extern int D_001A72DC[] __attribute__((sda));
extern void func_0029D4D0(int, void *);
extern int func_0011AEA0(int);
extern void func_002FC1D8(void);
extern void func_002FCB00(void *, int, int, int);
extern void func_0027B858(void);
extern void func_0027DDC0(int, int, int, int);
extern void func_00284FC0(void);
extern void func_00285338(void);
extern void func_002FC280(void);
extern void func_002FC3C0(int);
extern int func_001244B8(int, int);
extern int func_001261F0(int);

/* The engine's start-up: one pass of the resident object's rebuild, then the
   same pass 65 times with the counter. */
void func_0026EA00(int arg)
{
    char *state = D_001BAEC0;
    int *data;
    int count = 0x80;

    func_0029D4D0(arg, *(void **)(state + 20));
    func_0011AEA0(0);
    do {
        func_002FC1D8();
        data = *(int **)(state + 20);
        func_002FCB00(data + 4, D_001A72DC[0], data[0], data[1]);
        func_0027B858();
        func_0027DDC0(0, 0, 0, count);
        func_00284FC0();
        count -= 2;
        func_00285338();
        func_0011AEA0(0);
        func_002FC280();
        func_002FC3C0(1);
        func_001244B8(0, 0);
        func_001261F0(0);
    } while (count >= 0);
}
