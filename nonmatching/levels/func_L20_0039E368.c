/* Near miss from src/levels/20_yeedil/L20_0039C448-g8.c (the -G8 unit).

   No C was written for this body in this wave; what is recorded here is
   the structure that was mapped out of the retail and the walls it runs
   into, so the next attempt starts from the structure and not from the
   disassembly.

   func_L20_0039E368 is 648 bytes.  Its shape:

     - the prologue interleaves the body with the register saves (the
       retail's `daddu $s2,$a0` sits between `sd $s1` and `sd $ra`, the
       `lui $v1,%hi(D_001A8F00)` before the saves), which is the
       prologue-interleaving wall;
     - it calls f_0039E5F0 (the function that sits in the same unit)
       first and then dispatches on the byte at +0x20 of its argument
       through a JUMP TABLE, `jtbl_002B4CA0` (level address 0x002B4CA0,
       five entries, the `sltiu $v1,$a0,0x5` guard), so the C needs a
       `switch` whose table lands in .rodata at that address.  A C
       switch puts its table in the unit's own .rodata, which the build
       cannot place at the retail's address - the wall that keeps
       func_00118CC8 and func_00123C28 in nonmatching/ on the boot
       side.  That has to be solved before the body can land;
     - the switch's arms call f_0033E788, f_0032F2D0, f_00326528,
       f_00326488 and f_00302548, and the last one is called with the
       constant 0x3C888889 (1/60 as a float, one ulp above the natural
       0.016666666f - the known float-constant wall);
     - it reaches D_001A8F00, D_1BDCF0, D_1B2AC8 and D_1B2BE8 through
       $at/$lo and D_L20_001B2BE8's neighbours through $gp.

   The branch-likely form that the retail uses for its early exits
   (see the note on func_L20_0039D680) is the second wall after the
   jump table: the check block has to end in an unconditional jump to
   the body for this cc1 to invert the last condition.
*/
#include "include_asm.h"

/* ------------------------------------------------------------------
   Wave 21, worker 08.  THE JUMP TABLE ESCAPE WORKS.

   The wall that kept this body out of src/ is gone: the level's own
   jump table can be named and used with a computed goto, and the
   compiler emits exactly the retail's dispatch:

     extern void *D_L20_002B4CA0[5];
     ...
     goto *D_L20_002B4CA0[sel - 1];

   compiles to

     lui   $v0,%hi(D_L20_002B4CA0)
     sll   $a0,$a0,2
     addiu $v0,$v0,%lo(D_L20_002B4CA0)
     addu  $a0,$a0,$v0
     lw    $v1,0($a0)
     jr    $v1
     nop

   which is the retail's 0x39E3C4..0x39E3DC instruction for
   instruction (the retail keeps the index in $a0 and jumps through
   $a0; the attempt above keeps it in $v1).  The object gets
   R_MIPS_HI16/LO16 against the symbol and the build resolves the
   value from the retail's `lui %hi`/`addiu %lo` pair, so
   `D_L20_002B4CA0` is placed at 0x002B4CA0 and the table's CONTENTS
   (the retail's case addresses) come from the level's own data
   section.  The declaration has to have a size (5 here): an
   `extern void *D_L20_002B4CA0[];` never takes the absolute form in
   a -G8 file.

   The table, as the level's data has it:

     jtbl_002B4CA0 (0x002B4CA0), five entries:
       [0] 0x0039E5D4   (the epilogue: `ld $s0,0x60($sp)`)
       [1] 0x0039E3E0
       [2] 0x0039E430
       [3] 0x0039E51C
       [4] 0x0039E56C

   The dispatch's index is `sel - 1` where sel is the byte at 0x20 of
   the argument, so sel = 1 goes to the epilogue, sel = 2 to 0x39E3E0,
   sel = 3 to 0x39E430, sel = 4 to 0x39E51C and sel = 5 to 0x39E56C;
   the range check is `sltiu $v1,$a0,0x5` and the default is
   0x39E5CC (`jal f_0039E770`).

   So the source's shape is

     if (D_001A8F00 == 2) {
         if (D_1BDCF0 >= 5) { func_003253A8(arg0); goto out; }
         sel = *(u8 *)(arg0 + 0x20);
     } else {
         sel = *(u8 *)(arg0 + 0x20);
     }
     if ((u32)(sel - 1) >= 5) { goto default; }
     goto *D_L20_002B4CA0[sel - 1];

   with the five case bodies laid out in the source order case 2, case
   3, case 4, case 5, default, case 1 (the epilogue), because the
   retail's layout is 0x39E3E0, 0x39E430, 0x39E51C, 0x39E56C,
   0x39E5BC, 0x39E5CC, 0x39E5D4.

   What is left to do for this body: the five case bodies have to be
   written so that the compiled layout lands on the retail's
   addresses, and the branch-likely forms of the retail's early exits
   (`beql $v0,$zero` at 0x39E3E8, `bnel` at 0x39E470) have to be
   reproduced (the check block has to end in an unconditional jump to
   the body, see the note on func_L20_0039D680).

   The attempt below is unchanged: no C was written for this body in
   this wave, the structure above is what the next attempt should
   start from.
*/

/* ------------------------------------------------------------------
   Wave 22, worker 09.  The NAME of the table: `jtbl_002B4CA0`, not
   `D_L20_002B4CA0`.

   The wave 21 note above uses `D_L20_002B4CA0[5]`; that name does NOT
   resolve in the build.  The level's data carries the table under the
   name `jtbl_002B4CA0` (config/undefined_syms_auto.txt has
   `jtbl_002B4CA0 = 0x2B4CA0;`), and with that name the dispatch comes
   out of the compiler instruction for instruction as the retail's:

     extern void *jtbl_002B4CA0[5];
     ...
     if ((u32)(sel - 1) >= 5) { goto default; }
     goto *jtbl_002B4CA0[sel - 1];

   gives

     addiu  $a0,$v0,-0x1        <- the index, sel - 1
     sltiu  $v1,$a0,0x5
     beqz   $v1,.Ldefault
     lui    $v0,%hi(jtbl_002B4CA0)
     sll    $v1,$a0,2
     addiu  $v0,$v0,%lo(jtbl_002B4CA0)
     addu   $v1,$v1,$v0
     lw     $a0,0x0($v1)
     jr     $a0
     nop

   which is the retail's 0x39E3B8..0x39E3DC exactly (the retail keeps
   the index in $a0 for the `sll` and the target in $a0 for the `jr`,
   the attempt the same; the table's address comes out as the
   relocation against `jtbl_002B4CA0`, which the build resolves to
   0x002B4CA0 and whose contents come from the level's own data).

   The declaration NEEDS a size (`jtbl_002B4CA0[5]`): an
   `extern void *jtbl_002B4CA0[];` never takes the absolute form in a
   -G8 file.

   The case bodies are kept alive by a `static void * volatile` array
   of `&&label`s, which lands in the discarded .data and produces no
   code:

     static void *volatile tab[] = { &&c0, &&c1, &&c2, &&c3, &&c4 };

   The table's order is [0] = the epilogue (0x39E5D4), [1] = 0x39E3E0,
   [2] = 0x39E430, [3] = 0x39E51C, [4] = 0x39E56C, so the array is
   { &&c0, &&c1, &&c2, &&c3, &&c4 } with c0 the epilogue's label.

   MEASURED: with the dispatch written as above and the five case
   bodies left empty, the compiler produces the retail's dispatch
   instruction for instruction, and the prologue's first three
   instructions (`jal f_0039E5F0` with `lw $s3,0x68($s2)` in the delay
   slot, then `lui $v1,%hi(D_001A8F00)` / `lw $v1,%lo(D_001A8F00)($v1)`
   / `addiu $v0,$zero,0x2` / `bnel $v1,$v0` with `lbu $v0,0x20($s2)` in
   the delay slot) also comes out as the retail's.  So the wall that
   kept this body out of src/ is gone; what is left is the five case
   bodies (about 120 instructions) and the layout of the blocks.

   The stub below is the measured dispatch; it is NOT an attempt at
   the body (the case bodies are empty).
*/
#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_L20_0039E5F0(char *);
extern int D_001A8F00;
extern int D_L20_001BDCF0;
extern void *jtbl_002B4CA0[5];

void func_L20_0039E368(char *arg0) {
    static void *volatile tab[] = { &&c0, &&c1, &&c2, &&c3, &&c4 };
    u8 v;

    func_L20_0039E5F0(arg0);
    if (D_001A8F00 != 2) {
        v = *(u8 *)(arg0 + 0x20);
        goto dispatch;
    }
    if (D_L20_001BDCF0 >= 5) {
        goto c0;
    }
    v = *(u8 *)(arg0 + 0x20);
dispatch:
    if ((u32)(v - 1) >= 5) {
        goto c0;
    }
    goto *jtbl_002B4CA0[v - 1];
c0:
    return;
c1:
    return;
c2:
    return;
c3:
    return;
c4:
    return;
}

/* ------------------------------------------------------------------
   Wave 22, worker 09.  THE ATTEMPT IS NOW A NEAR MISS: 648 bytes,
   the retail's size, and 43 of the 162 instructions differ.

   What this wave measured (all of it new):

   - The jump table's NAME is `jtbl_002B4CA0` (the wave 21 note above
     used `D_L20_002B4CA0`, which does not resolve).  With the right
     name the dispatch comes out instruction for instruction as the
     retail's 0x39E3B8..0x39E3DC.

   - The state's load has to come BEFORE the call f_0039E5F0 in the
     source (`state = *(char **)(arg0 + 0x68);` before the call), so
     that the load lands in the CALL's delay slot, as the retail has
     it (`jal f_0039E5F0` + `lw $s3,0x68($s2)`).  With the load after
     the call the copy of arg0 into $s2 lands in the call's delay
     slot instead and the prologue differs.

   - THE BRANCH-LIKELY FORM: the read has to be INSIDE the `if` that
     the branch tests, and not after it:

         if (func_002B3868(arg0) == 0) {
             w = *(u8 *)(arg0 + 0x31);
             goto L410;
         }

     gives the retail's `beql $v0,$zero` with `lbu $v0,0x31($s2)` in
     the delay slot (the read is annulled on the fall-through path);
     written as

         if (func_002B3868(arg0) == 0) {
             goto L410;
         }
         ...
         w = *(u8 *)(arg0 + 0x31);

     the branch comes out plain (`beqz`) with a nop in the delay slot
     and the read after it.  This is the same rule as the note on
     func_L20_0039D680: the instruction in the delay slot has to be
     one that must NOT run on the fall-through path, which means it
     has to be inside the `if`.  With this, the case-1 body
     (0x39E3E0..0x39E414) matches the retail exactly.

   - The two tests of the halfword at +0x96 are INVERTED with respect
     to what the names suggest: the retail leaves the function when
     the value is SMALLER than 0xB5 (`sltiu $v0,$v0,0xB5` +
     `bnez $v0,.L0039E5CC`).

   - The case-2 call to f_0032F2D0 has $a1 = 1 (the case-1 call has
     $a1 = 0), and the case-3 call has $a1 = 2 and $a2 = 0.

   - The two floats that are reached through $gp are at 0x1AED04 and
     0x1AED08 (they are $gp - 0x2EC and $gp - 0x2E8), so they are the
     level's D_L20_001AED04 and D_L20_001AED08, and they need the
     `sda` attribute in this -G8 unit.

   - The frame is 0x90 and holds three buffers: 0x10 bytes at sp+0,
     0x40 bytes at sp+0x10 and 0x10 bytes at sp+0x50 (the saved
     registers start at sp+0x60).  `char bufA[0x10]; char bufB[0x40];
     char bufC[0x10];` in that order reproduces the frame exactly.

   What still differs (43 instructions):

   - the dispatch keeps the index in $v1, the retail in $a0
     (`addiu $a0,$v0,-0x1` + `sltiu $v1,$a0,0x5`); everything else of
     the dispatch is identical;
   - the setup of the mode (2 or 3) and of $a0 = arg0 lands in the
     other delay slot: the retail puts `daddu $a0,$s2,$zero` in the
     delay slot of the FIRST branch of the case and
     `addiu $a1,$zero,0x3` (the mode) in the delay slot of the LAST
     one, the attempt has them the other way round.  The three mode
     setups (3 in the case-1 body, 2 in the case-2 body and 2 in the
     block the case-3 body falls into) are in the attempt already,
     as in the retail, but the scheduler puts them in the other
     slots;
   - the argument setup of the call to f_0032DA58 in the case-4 body
     is in the order a2, a1, a0 in the retail and a1, a0, a2 in the
     attempt.

   The attempt below is the closest one.  With it in src/:
     20_yeedil: instruction at +0x50 differs
     func_L20_0039E368: 0 of 1 places match
*/

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_L20_0039E5F0(char *);
extern void func_L20_0039E770(char *);
extern s32 func_002B3868(char *);
extern void func_002A7470(char *, s32, s32, s32);
extern void func_0029F338(char *);
extern void func_0029FCC0(char *, s32, char *);
extern void func_0029FC20(char *, s32, char *);
extern void func_00282F20(char *, char *, float);
extern void func_L09_003AE8C8(char *, char *, char *, s32, s32, float, float, float, float);
extern void func_002A7750(char *, s32, s32);
extern void func_00282CF0(char *, void *, char *);
extern void func_0032DA58(char *, char *, char *, float);
extern void func_002A6C58(char *, s32, s32);

extern int D_L20_001A8F00;
extern int D_L20_001BDCF0;
extern int D_L20_001B2AC8;
extern void *D_L20_001B9FC0[];
extern float D_L20_001AED04 __attribute__((sda));
extern float D_L20_001AED08 __attribute__((sda));

extern void *jtbl_002B4CA0[5];

void func_L20_0039E368(char *arg0) {
    static void *volatile tab[] = { &&c0, &&c1, &&c2, &&c3, &&c4 };
    char bufA[0x10];
    char bufB[0x40];
    char bufC[0x10];
    char *state;
    u8 v;
    u8 w;
    s32 mode;
    s32 idx;

    state = *(char **)(arg0 + 0x68);
    func_L20_0039E5F0(arg0);
    if (D_L20_001A8F00 != 2) {
        v = *(u8 *)(arg0 + 0x20);
        goto dispatch;
    }
    if (D_L20_001BDCF0 >= 5) {
        goto c4b;
    }
    v = *(u8 *)(arg0 + 0x20);
dispatch:
    idx = v - 1;
    if ((u32)idx >= 5) {
        goto Ldef;
    }
    goto *jtbl_002B4CA0[idx];
c1:
    if (func_002B3868(arg0) == 0) {
        w = *(u8 *)(arg0 + 0x31);
        goto L410;
    }
    if (*(u8 *)(arg0 + 0x43) != 0) {
        func_002A7470(arg0, 0, 0, 0xA);
    }
    w = *(u8 *)(arg0 + 0x31);
L410:
    if (w == 0) {
        goto Ldef;
    }
    if (*(u16 *)(arg0 + 0x96) < 0xB5) {
        goto Ldef;
    }
    mode = 3;
    goto L55C;
c2:
    if (func_002B3868(arg0) != 0) {
        if (*(u8 *)(arg0 + 0x43) != 1) {
            func_002A7470(arg0, 1, 0, 0xF);
        }
    }
    if ((D_L20_001B2AC8 & 0xF) != (((int)arg0 >> 8) & 0xF)) {
        w = *(u8 *)(arg0 + 0x31);
        goto L4FC;
    }
    func_0029FCC0(arg0, 2, bufA);
    func_0029FC20(arg0, 2, bufB);
    func_00282F20(bufC, bufB, D_L20_001AED04 * 0.016666668f);
    func_L09_003AE8C8(bufA, arg0, bufC, 1, 1, (float)*(u8 *)(state + 0x34),
                      D_L20_001AED08, 1.0f, 1.0f);
    w = *(u8 *)(arg0 + 0x31);
L4FC:
    if (w == 0) {
        goto L558;
    }
    if (*(u16 *)(arg0 + 0x96) < 0xB5) {
        goto Ldef;
    }
    mode = 2;
    goto L55C;
c3:
    if (func_002B3868(arg0) != 0) {
        if (*(u8 *)(arg0 + 0x43) != 2) {
            func_002A7470(arg0, 2, 0, 0xA);
        }
    }
    if ((*(u8 *)(arg0 + 0x60) & 0x2) == 0) {
        goto Ldef;
    }
L558:
    mode = 2;
L55C:
    func_002A7750(arg0, mode, -1);
    goto Ldef;
c4:
    {
        char *s0 = arg0 + 0x10;

        func_00282CF0(bufA, D_L20_001B9FC0, s0);
        func_00282F20(bufA, bufA, 1.0f);
        func_0032DA58(arg0, s0, bufA, 0.0f);
        func_002A6C58(arg0, 0, 3);
    }
c4b:
    func_0029F338(arg0);
    goto out;
Ldef:
    func_L20_0039E770(arg0);
out:
c0:
    return;
}

/* ------------------------------------------------------------------
   Wave 5, worker 08.  The attempt below is 648 bytes, the retail's
   size, and only THREE instructions differ: the setup of the
   arguments of the call to f_00420850 in the case-5 body.

   What this wave measured, and it is a lot:

   - THE CALLEES MUST BE NAMED BY THEIR LEVEL-20 ADDRESS.  The wave-22
     attempt called the boot functions by their boot names
     (func_002B3868, func_002A7470, ...), but a boot function sits at a
     different address in every program: the call to what the boot
     calls func_002A7750 is at 0x0032F5B0 in level 20, and the build
     checks the value a symbol gets against the address in its name.
     The names that resolve are the level-20 addresses:

        f_0039E5F0  func_L20_0039E5F0      f_0033E788  func_002B3868
        f_0032F2D0  func_002A7470           f_00326528  func_0029FCC0
        f_00326488  func_0029FC20           f_00302548  func_00282F20
        f_003CC258  func_L09_003AE8C8      f_0032F5B0  func_002A7750
        f_00302290  func_00282CF0          f_00420850  func_0032DA58
        f_0032EAB8  func_002A6C58           f_003253A8  func_0029F338
        f_0039E770  func_L20_0039E770

     (func_L09_003AE8C8 and the two level functions keep their names:
     a name of the form func_LNN_XXXXXXXX may take any value.)

   - THE THREE CALLS TO func_002A7750 ARE THREE CALLS IN THE SOURCE,
     NOT ONE CALL WITH A MODE VARIABLE.  The retail's case-1 body
     ends with

        bnez $v0,.L0039E5CC
          daddu $a0,$s2,$zero      <- the call's first argument
        b .L0039E55C
          addiu $a1,$zero,0x3      <- the mode

     and the case-2 and case-3 bodies branch to the same place with
     the mode 2.  With one shared call site and a `mode' variable the
     two setups land in the other delay slots and the whole body
     differs.  With the call written out in each of the three cases
     (and the mode a variable, so that the three calls are identical
     and the cross-jumping merges them) the retail's delay slots come
     out exactly: the argument setup goes into the delay slot of the
     branch before it and the mode into the delay slot of the branch
     that reaches the shared call.  This is the same mechanism as the
     branch-likely recipe of the common file: the cross-jumping
     merges the three identical call blocks and the reorg then moves
     the argument setup into the delay slot of the branch in the
     predecessor.

   - D_L20_001BDCF0 CARRIES `nosda'.  The retail reads it with the
     address in a register of its own (`lui $v1,%hi(D) /
     lw $v0,%lo(D)($v1)'), while D_L20_001A8F00 and D_L20_001B2AC8 are
     read with the same register for the address and the value
     (`lui $v1,%hi(D) / lw $v1,%lo(D)($v1)').

   - THE DISPATCH'S INDEX IS IN $a0 ONLY WHEN THE BYTE IS READ TWICE
     FROM MEMORY.  With the byte in a variable (`v = *(u8 *)(arg0 +
     0x20)' and `v - 1' used twice) the index comes out in $v1 and
     three instructions differ; with the byte read inline twice (the
     retail does read it twice: at 0x39E39C and 0x39E3B4) the index
     is in $a0 and the dispatch matches instruction for instruction.

   What is left (the attempt is otherwise the retail, instruction for
   instruction):

     0039E59C  daddu $a1,$s0,$zero  | daddu $a2,$sp,$zero
     0039E5A0  daddu $a0,$s2,$zero  | daddu $a1,$s0,$zero
     0039E5A8  daddu $a2,$sp,$zero  | daddu $a0,$s2,$zero

     the three argument setups of the call to f_00420850 (the case-5
     body) come out in the order a1, a0, a2 here and in the order
     a2, a1, a0 in the retail.  The values are the same (the retail's
     a0 is arg0, a1 is arg0+0x10 and a2 is the first buffer), only
     the order of the three independent setups differs, so it is the
     scheduler's choice and not the source's.  Tried: the arguments
     in every order the values allow, the float argument first, in the
     middle and last, &bufA[0], bufA + 0 and (char *)bufA for the
     third argument, the call in a block of its own and the s0 pointer
     declared at the top of the function.  Nothing moves the order.

   The attempt belongs in the -G8 unit (the two floats of the case-2
   body are read through $gp).
*/


extern void func_L20_0039E5F0(char *);
extern void func_L20_0039E770(char *);
extern s32 func_0033E788(char *);
extern void func_0032F2D0(char *, s32, s32, s32);
extern void func_0029F338(char *);
extern void func_00326528(char *, s32, char *);
extern void func_00326488(char *, s32, char *);
extern void func_00302548(char *, char *, float);
extern void func_L09_003AE8C8(char *, char *, char *, s32, s32, float, float, float, float);
extern void func_0032F5B0(char *, s32, s32);
extern void func_00302290(char *, void *, char *);
extern void func_00420850(char *, char *, char *, float);
extern void func_0032EAB8(char *, s32, s32);

extern int D_L20_001A8F00;
extern int D_L20_001BDCF0 __attribute__((nosda));
extern int D_L20_001B2AC8;
extern void *D_L20_001B9FC0[];
extern float D_L20_001AED04 __attribute__((sda));
extern float D_L20_001AED08 __attribute__((sda));

extern void *jtbl_002B4CA0[5];

void func_L20_0039E368(char *arg0) {
    static void *volatile tab[] = { &&c0, &&c1, &&c2, &&c3, &&c4 };
    char bufA[0x10];
    char bufB[0x40];
    char bufC[0x10];
    char *state;
    u8 w;
    s32 mode;

    state = *(char **)(arg0 + 0x68);
    func_L20_0039E5F0(arg0);
    if (D_L20_001A8F00 != 2) {
        goto dispatch;
    }
    if (D_L20_001BDCF0 >= 5) {
        goto c4b;
    }
dispatch:
    if ((u32)(*(u8 *)(arg0 + 0x20) - 1) >= 5) {
        goto Ldef;
    }
    goto *jtbl_002B4CA0[*(u8 *)(arg0 + 0x20) - 1];
c1:
    if (func_0033E788(arg0) == 0) {
        w = *(u8 *)(arg0 + 0x31);
        goto L410;
    }
    if (*(u8 *)(arg0 + 0x43) != 0) {
        func_0032F2D0(arg0, 0, 0, 0xA);
    }
    w = *(u8 *)(arg0 + 0x31);
L410:
    if (w == 0) {
        goto Ldef;
    }
    if (*(u16 *)(arg0 + 0x96) < 0xB5) {
        goto Ldef;
    }
    mode = 3;
    func_0032F5B0(arg0, mode, -1);
    goto Ldef;
c2:
    if (func_0033E788(arg0) != 0) {
        if (*(u8 *)(arg0 + 0x43) != 1) {
            func_0032F2D0(arg0, 1, 0, 0xF);
        }
    }
    if ((D_L20_001B2AC8 & 0xF) != (((int)arg0 >> 8) & 0xF)) {
        w = *(u8 *)(arg0 + 0x31);
        goto L4FC;
    }
    func_00326528(arg0, 2, bufA);
    func_00326488(arg0, 2, bufB);
    func_00302548(bufC, bufB, D_L20_001AED04 * 0.016666668f);
    func_L09_003AE8C8(bufA, arg0, bufC, 1, 1, (float)*(u8 *)(state + 0x34),
                      D_L20_001AED08, 1.0f, 1.0f);
    w = *(u8 *)(arg0 + 0x31);
L4FC:
    if (w == 0) {
        goto L558;
    }
    if (*(u16 *)(arg0 + 0x96) < 0xB5) {
        goto Ldef;
    }
    mode = 2;
    func_0032F5B0(arg0, mode, -1);
    goto Ldef;
c3:
    if (func_0033E788(arg0) != 0) {
        if (*(u8 *)(arg0 + 0x43) != 2) {
            func_0032F2D0(arg0, 2, 0, 0xA);
        }
    }
    if ((*(u8 *)(arg0 + 0x60) & 0x2) == 0) {
        goto Ldef;
    }
L558:
    mode = 2;
    func_0032F5B0(arg0, mode, -1);
    goto Ldef;
c4:
    {
        char *s0 = arg0 + 0x10;

        func_00302290(bufA, D_L20_001B9FC0, s0);
        func_00302548(bufA, bufA, 1.0f);
        func_00420850(arg0, s0, bufA, 0.0f);
        func_0032EAB8(arg0, 0, 3);
    }
c4b:
    func_003253A8(arg0);
    goto out;
Ldef:
    func_L20_0039E770(arg0);
out:
c0:
    return;
}
