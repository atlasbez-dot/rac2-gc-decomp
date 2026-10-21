/* Near miss from src/levels/20_yeedil/L20_0039C448-g8.c (the -G8 unit).

   The body has the retail size (332 bytes) and the block order, the branches, the
   calls and the arithmetic all match the retail instruction for instruction.
   What is left is the choice of four registers:

     +0xE4  retail:  lui at,0x3F00 / mtc1 at,f12 / lui a1,%hi(D_001AED94) /
                     lw a1,%lo(D_001AED94)(a1) / mul.s f0,f0,f12
              here:   lui at,0x3F00 / mtc1 at,f1 / lui v0,%hi(D_001AED94) /
                     lw a1,%lo(D_001AED94)(v0) / mul.s f0,f0,f1
     +0xE48 retail:  add.s f12,f0,f12
              here:   add.s f12,f0,f1
     +0xE70 retail:  lui a0,0xFF / lui v1,0xFF00 / ori a0,a0,0xFFFF /
                     and v1,v0,v1 / and v0,v0,a0 / sw v1,0x10(s0)
              here:   lui v1,0xFF / lui a0,0xFF00 / ori v1,v1,0xFFFF /
                     and v1,v0,v1 / and v0,v0,a0 / sw v1,0x4(s0)

   The retail keeps the half (0.5f) in $f12 - the register the call argument
   $f12 was in - and the add of the common tail reuses it
   (`add.s f12,f0,f12`), while the attempt keeps it in $f1 and copies it for
   the add.  The retail loads the two words of the level table with the
   destination register as the base (`lui a1,%hi(D) / lw a1,%lo(D)(a1)`), the
   attempt computes the high half into a scratch register ($v0, $v1) first.
   The retail masks the two words with $a0 = 0xFFFFFF and $v1 = 0xFF000000,
   the attempt with $v1 = 0xFFFFFF and $a0 = 0xFF000000 (the values stored are
   the same).

   What did work (and is in the attempt):
   - the outer test is written the other way round (`if (func_00301ED0(state)
     != 0) { func_003253A8(arg0); } else { ... }`).  That is what puts the
     else block (the jal) right after the branch and the work at the end of the
     function, and it makes the compiler emit the branch-likely `beql` with the
     flag load in its delay slot, as the retail does.
   - the inner test is written `if (*(int *)(state + 0xC) != 0) { ... } else
     { ... }` with the flag != 0 case first, so the compiler emits
     `beqz v0` to the other case.
   - the constant 0.0002908882452f (0x3998825C) is spelled out in both
     branches instead of being a variable: the retail materialises it twice
     (lui/ori/mtc1 in each branch) and the compiler then keeps the value in
     $f0 and the constant in $f13, so the multiply comes out as the retail's
     `mul.s f13,f0,f13`.
   - the int at D_L20_001AEDA8 is converted with (f32) and the product is
     passed to func_00303270 as its second argument; the old value at
     state+8 is the first one (the retail loads it in the delay slot of the
     inner test).
   - D_L20_001AEDA8 and D_L20_001AED90 carry `sda` (the retail reaches them
     through $gp at 0x1AEFF0-0x248 and 0x1AEFF0-0x260) and the three words
     D_L20_001AED94/9C/98 carry `nosda` (the retail reaches them through
     $at: lui a1,0x1B / lw a1,-0x126C(a1)).
   - func_003033B8 returns the float that is scaled by 0.00390625f and stored
     at state+0x14, so the accumulator is dead before the calls and no
     floating point register has to be saved (the frame is 0x20).

   Tried: the half as a local variable, as a const, and as a literal in each
   branch, the order of the two mask assignments, the order of the branches,
   the data symbols as int and as char *, and the value and the constant
   inlined.  The four register choices above are what is left. */
#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_00301ED0(void *);

extern void func_003253A8(void *);

extern float func_00303270(float, float);

extern float func_00302870(float);

extern int func_00303410(float, int, int);

extern float func_003033B8(int);

extern void f_002FAC70(void (*)(void), void *);

extern void func_L20_0039F230(void);

extern int D_L20_001AEDA8 __attribute__((sda));

extern int D_L20_001AED90 __attribute__((sda));

extern int D_L20_001AED94 __attribute__((nosda));

extern int D_L20_001AED9C __attribute__((nosda));

extern int D_L20_001AED98 __attribute__((nosda));

void func_L20_0039ED78(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);

    if (func_00301ED0(state) != 0) {
        func_003253A8(arg0);
    } else {
        f32 x = *(f32 *)(state + 0x8);
        f32 r, s, f0, half;
        int v, v0, v1;
        int a0, a1;

        if (*(int *)(state + 0xC) != 0) {
            r = func_00303270(x, (f32)D_L20_001AEDA8 * 0.0002908882452f);
            *(f32 *)(state + 0x8) = r;
            s = func_00302870(r);
            half = 0.5f;
            f0 = s * half;
            a1 = D_L20_001AED94;
            a0 = D_L20_001AED90;
        } else {
            r = func_00303270(x, (f32)D_L20_001AEDA8 * 0.0002908882452f);
            *(f32 *)(state + 0x8) = r;
            s = func_00302870(r);
            half = 0.5f;
            f0 = s * s * half;
            a1 = D_L20_001AED9C;
            a0 = D_L20_001AED98;
        }
        v = func_00303410(f0 + half, a0, a1);
        v0 = *(int *)(state + 0x10);
        a0 = *(int *)(state + 0x4);
        v = func_00303410(0.15f, v0 | a0, v);
        v1 = v & 0xFF000000;
        v0 = v & 0xFFFFFF;
        *(int *)(state + 0x10) = v1;
        *(int *)(state + 0x4) = v0;
        *(f32 *)(state + 0x14) = func_003033B8(v1 >> 24) * 0.00390625f;
        f_002FAC70(func_L20_0039F230, arg0);
    }
}

/* ------------------------------------------------------------------
   Second attempt (worker 09, level-20 wave); the C in this file is that
   second attempt, the first one is described above.  It is closer: 14
   instructions differ, all of them register choices, and the block order,
   the branches, the calls and the arithmetic match.

   What is new in this attempt:
   - the second call of the tail is written as one expression
     (`func_00303410(0.15f, *(int *)(state + 0x10) | *(int *)(state + 0x4), v)`),
     which is what makes the retail's mask block come out exactly:
     lui a0,0xFF / lui v1,0xFF00 / and v1,v0,v1 / ori a0,a0,0xFFFF /
     and v0,v0,a0 / sw v1,0x10(s0) / sra a0,v1,24 / sw v0,0x4(s0).
     With the two masks in separate variables the two constants land in
     the other two registers.
   - the two masks are computed in the order 0xFFFFFF first, 0xFF000000 second.

   What is still different (the retail on the right):
     0039EDE4  mtc1 $at,$f1   | mtc1 $at,$f12
     0039EDE8  lui  $v0       | lui  $a1      (the nosda load, see below)
     0039EDEC  lw   $a1,0($v0)| lw   $a1,-0x126C($a1)
     0039EDF0  mul.s $f0,$f0,$f1 | mul.s $f0,$f0,$f12
     0039EE2C  mtc1 $at,$f1   | mtc1 $at,$f12
     0039EE30  lui  $v0       | lui  $a1
     0039EE34  lui  $v1       | lw   $a1,-0x1264($a1)
     0039EE38  lw   $a1,0($v0)| lui  $a0
     0039EE3C  mul.s $f0,$f0,$f1 | lw   $a0,-0x1268($a0)
     0039EE40  lw   $a0,0($v1)| mul.s $f0,$f0,$f12
     0039EE48  add.s $f12,$f0,$f1 | add.s $f12,$f0,$f12
     0039EE4C  lw   $v1,0x10($s0) | daddu $a1,$v0,$zero
     0039EE50  daddu $a1,$v0,$zero | lw $v0,0x10($s0)
     0039EE68  or   $a0,$v1,$a0 | or   $a0,$v0,$a0

   Three things are left, and each is a register choice:

   1. The 0.5f.  The retail keeps it in $f12, the register the call's
      float argument lives in, so the tail's add reuses it
      (`add.s f12,f0,f12`); this attempt keeps it in $f1 and copies it
      into $f12 for the add.  Measured: a value that is the argument of a
      call gets the argument register (a variable that is passed to a call
      lands in $f12), a value that is only an operand of an expression
      does not - it gets the next free $f register ($f1 here).  The
      retail has the constant in the argument register and the sum in the
      same register, so the constant has to be the argument itself, but
      then the add comes out as `add.s f12,f12,f0` (the operands swapped,
      because gcc canonicalises `x = x + y` into `y + x`), not as the
      retail's `add.s f12,f0,f12`.

   2. The nosda loads.  The retail loads D_L20_001AED94/9C/98 with the
      address's high part in the register the value goes to
      (`lui a1,%hi(D) / lw a1,%lo(D)(a1)`); this cc1 always puts the high
      part in a scratch register (`lui v0,%hi(D) / lw a1,%lo(D)(v0)`).
      Measured on this compiler with -G8: every spelling of a nosda
      global load gives the scratch form - `int x = g;`, `*(int *)&g`,
      `g[0]` with an array declaration, `*(int *)((char *)&g + 0)`, a
      32-bit cast, a volatile load, and the value passed straight to a
      call.  No function in src/ that is matched today uses the retail's
      form, so this looks like a wall of this cc1, not of the source.

   3. The word read from 0x10(state).  The retail reuses $v0 for it (the
      first call's result is moved to $a1 first, which frees $v0), this
      attempt loads it into $v1 before that move.  It is the order of
      the scheduler, not of the source.

   The attempt belongs in the -G8 unit (it reaches D_L20_001AEDA8 and
   D_L20_001AED90 through $gp). */

extern int func_00301ED0(void *);

extern void func_003253A8(void *);

extern float func_00303270(float, float);

extern float func_00302870(float);

extern int func_00303410(float, int, int);

extern float func_003033B8(int);

extern void func_L00_002E6CF0(void *, void *);

extern void func_L20_0039F230(char *);

extern int D_L20_001AEDA8 __attribute__((sda));

extern int D_L20_001AED90 __attribute__((sda));

extern int D_L20_001AED94 __attribute__((nosda));

extern int D_L20_001AED9C __attribute__((nosda));

extern int D_L20_001AED98 __attribute__((nosda));

void func_L20_0039ED78(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);

    if (func_00301ED0(state) != 0) {
        func_003253A8(arg0);
    } else {
        f32 x = *(f32 *)(state + 0x8);
        f32 r, s, f0, half;
        int v, v0, v1;
        int a0, a1;

        if (*(int *)(state + 0xC) != 0) {
            r = func_00303270(x, (f32)D_L20_001AEDA8 * 0.0002908882452f);
            *(f32 *)(state + 0x8) = r;
            s = func_00302870(r);
            half = 0.5f;
            f0 = s * half;
            a1 = D_L20_001AED94;
            a0 = D_L20_001AED90;
        } else {
            r = func_00303270(x, (f32)D_L20_001AEDA8 * 0.0002908882452f);
            *(f32 *)(state + 0x8) = r;
            s = func_00302870(r);
            half = 0.5f;
            f0 = s * s * half;
            a1 = D_L20_001AED9C;
            a0 = D_L20_001AED98;
        }
        v = func_00303410(f0 + half, a0, a1);
        v = func_00303410(0.15f, *(int *)(state + 0x10) | *(int *)(state + 0x4), v);
        v0 = v & 0xFFFFFF;
        v1 = v & 0xFF000000;
        *(int *)(state + 0x10) = v1;
        *(int *)(state + 0x4) = v0;
        *(f32 *)(state + 0x14) = func_003033B8(v1 >> 24) * 0.00390625f;
        func_L00_002E6CF0(func_L20_0039F230, arg0);
    }
}

/* ------------------------------------------------------------------
   Third attempt (worker 07, level-20 wave 3); the C in this file is that
   third attempt, the two earlier ones are described above.

   The finding of this attempt is the `nosda` attribute: it is what
   keeps this cc1 from emitting the retail's form of the load of a
   global.  With `nosda` the compiler always computes the high part of
   the address in a scratch register:

       lui  $v0,%hi(D_001AED94)
       lw   $a1,%lo(D_001AED94)($v0)

   and without the attribute it emits the retail's form, with the
   register the value goes to as the base:

       lui  $a1,%hi(D_001AED94)
       lw   $a1,%lo(D_001AED94)($a1)

   So the three words D_L20_001AED94, D_L20_001AED9C and D_L20_001AED98
   must be declared WITHOUT the attribute (the second attempt above
   declares them with `nosda`, which is the wall it ran into).  The two
   $gp values keep their `sda`: D_L20_001AEDA8 at -0x248($gp) and
   D_L20_001AED90 at -0x260($gp).

   With that, the three loads of the globals are the retail's and what
   is left is:
     - the 0.5f is in $f1 here and in $f12 in the retail (the same
       difference the second attempt found, and the same in the other
       branch: the retail keeps the half in the register the call
       argument $f12 was in, so the tail's add reuses it,
       `add.s $f12,$f0,$f12`);
     - the word read from 0x10(state) is in $v1 here and in $v0 in the
       retail (the order of the scheduler);
     - the int of D_L20_001AEDA8 is converted in $f13 here and in $f0
       in the retail, which moves the constant 0.0002908882452f to $f13
       (the retail's `mul.s $f13,$f0,$f13` against this attempt's
       `mul.s $f13,$f13,$f0`).

   The attempt belongs in the -G8 unit (it reaches D_L20_001AEDA8 and
   D_L20_001AED90 through $gp). */

extern int func_00301ED0(void *);

extern void func_003253A8(void *);

extern float func_00303270(float, float);

extern float func_00302870(float);

extern int func_00303410(float, int, int);

extern float func_003033B8(int);

extern void func_L00_002E6CF0(void *, void *);

extern void func_L20_0039F230(char *);

extern int D_L20_001AEDA8 __attribute__((sda));

extern int D_L20_001AED90 __attribute__((sda));

extern int D_L20_001AED94;

extern int D_L20_001AED9C;

extern int D_L20_001AED98;

void func_L20_0039ED78(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);

    if (func_00301ED0(state) != 0) {
        func_003253A8(arg0);
    } else {
        f32 x = *(f32 *)(state + 0x8);
        f32 r, s, f0, half;
        int v, v0, v1;
        int a0, a1;

        if (*(int *)(state + 0xC) != 0) {
            r = func_00303270(x, (f32)D_L20_001AEDA8 * 0.0002908882452f);
            *(f32 *)(state + 0x8) = r;
            s = func_00302870(r);
            half = 0.5f;
            f0 = s * half;
            a1 = D_L20_001AED94;
            a0 = D_L20_001AED90;
        } else {
            r = func_00303270(x, (f32)D_L20_001AEDA8 * 0.0002908882452f);
            *(f32 *)(state + 0x8) = r;
            s = func_00302870(r);
            half = 0.5f;
            f0 = s * s * half;
            a1 = D_L20_001AED9C;
            a0 = D_L20_001AED98;
        }
        v = func_00303410(f0 + half, a0, a1);
        v = func_00303410(0.15f, *(int *)(state + 0x10) | *(int *)(state + 0x4), v);
        v0 = v & 0xFFFFFF;
        v1 = v & 0xFF000000;
        *(int *)(state + 0x10) = v1;
        *(int *)(state + 0x4) = v0;
        *(f32 *)(state + 0x14) = func_003033B8(v1 >> 24) * 0.00390625f;
        func_L00_002E6CF0(func_L20_0039F230, arg0);
    }
}

/* ------------------------------------------------------------------
   Wave 4, worker 08.  What this wave measured on this body.

   The C in this file is the third attempt (the `nosda' attributes are
   gone from the three absolute words, which is right: without the
   attribute this cc1 emits the retail's `lui $a1,%hi(D) / lw
   $a1,%lo(D)($a1)', with it the high part goes to a scratch register).

   Three differences are left, and this wave measured two of them:

     0039EDE4  mtc1 $at,$f1   | mtc1 $at,$f12      the 0.5f
     0039EDF0  mul.s $f0,$f0,$f1 | mul.s $f0,$f0,$f12
     0039EE48  add.s $f12,$f0,$f1 | add.s $f12,$f0,$f12
     0039EE4C  lw $v1,0x10($s0) | daddu $a1,$v0,$zero
     0039EE50  daddu $a1,$v0,$zero | lw $v0,0x10($s0)
     0039EE68  or $a0,$v1,$a0 | or $a0,$v0,$a0

   1. The 0.5f is in $f12 in the retail and in $f1 here.  NEW: the
      SECOND branch is the one that is wrong in the third attempt; the
      first branch is the retail's.  Writing the half as the LITERAL
      0.5f in both branches (and in the tail) makes the second branch
      come out exactly like the retail's - the conversion of
      D_L20_001AEDA8 lands in $f0, the constant 0.0002908882452f in
      $f13, and the multiply is the retail's `mul.s $f13,$f0,$f13'.
      With the half as a variable the second branch gets $f13 for the
      conversion and $f0 for the constant instead.  So the difference
      is the register the RELOAD gives the two operands of the
      multiply, and it is decided by whether the half is a variable.

      With the literal the tail costs one instruction more than the
      retail's: the literal at the tail is a second constant, so it is
      materialised again (`mtc1 $at,$f12' before the call), while the
      retail reuses the $f12 the branches left.  The retail therefore
      has ONE half, a variable live across the branch, materialised in
      each branch - and the second branch's register allocation then
      differs from the retail's.  Measured and not understood: with the
      half as a variable the first branch is the retail's and the
      second is not; with the half as a literal the second is the
      retail's and the tail costs one instruction more.

      Tried: the half as a variable (the third attempt), as a literal
      in both branches and in the tail, as a literal in the branches
      only, the half assigned at the top of the else block (that one
      puts the constant in a saved $f20 and grows the frame), the half
      declared and assigned in each branch.

   2. The word read from 0x10(state) is in $v1 here and in $v0 in the
      retail, and the retail moves the first call's result out of $v0
      first (`daddu $a1,$v0,$zero' before `lw $v0,0x10($s0)').  That
      is the scheduler's order, not the source's: the load and the
      move are independent.  Tried: the load before and after the
      mask block, the mask block as one expression or as two
      statements, the two masks in either order - the attempt above is
      the best of them (the mask block is the retail's, instruction for
      instruction).

   The attempt belongs in the -G8 unit (D_L20_001AEDA8 and
   D_L20_001AED90 are read through $gp). */

/* ------------------------------------------------------------------
   Wave 5, worker 08.  The attempt below is 332 bytes, the retail's
   size, and seven instructions differ - all of them the register of
   one value, the 0.5f.

   What this wave measured on the floating point register allocation,
   which is the wall of this body:

   - THE 0.5f MUST BE IN $f12, and the way to get it there is to make
     it the ARGUMENT of the call.  A value that is passed to a call
     gets the argument register ($f12 for the first float argument),
     and the global allocator tries the preferred register first; a
     value that is only an operand of an expression does not get a
     preference and lands in the next free $f register ($f1 here).

       half = 0.5f;
       ...
       half = f0 + half;
       v = func_00303410(half, a0, a1);

     gives the 0.5f in $f12 in both branches (the retail's
     `mul.s $f0,$f0,$f12') and the tail's `add.s $f12,$f12,$f0'.

   - But that spelling canonicalises the add's operands: the
     destination of the add is the same value as one of its operands
     (`half = f0 + half' becomes `half = half + f0'), and the retail
     has the operands in the other order (`add.s $f12,$f0,$f12', the
     destination first).  With a different variable for the sum the
     operand order is the source's order, but then the half is only
     an operand of the expression and it loses $f12.  The two
     requirements contradict each other as far as this cc1 is
     concerned.

   - The rest of the difference is the same value in the second
     branch: with the half as a variable the conversion of
     D_L20_001AEDA8 lands in $f13 and the constant 0.0002908882452f
     in $f0; the retail has the conversion in $f0 and the constant in
     $f13, the same as the first branch.  With the half as the LITERAL
     0.5f both branches come out the retail's, and the tail then
     costs two instructions more (the constant is materialised again
     in $f12 before the call).

   - The word read from 0x10(state) is in $v1 here and in $v0 in the
     retail: the retail moves the first call's result out of $v0
     first (`daddu $a1,$v0,$zero' before `lw $v0,0x10($s0)'), this
     attempt loads it into $v1 before that move.  It is the order of
     the scheduler, not of the source.

   What else was measured: the `nosda' attribute on the three
   absolute words (D_L20_001AED94/9C/98) is WRONG - without it this
   cc1 gives the retail's form (`lui $a1,%hi(D) / lw $a1,%lo(D)($a1)'),
   with it the high part goes to a scratch register.  The two words
   read through $gp (D_L20_001AEDA8 at -0x248 and D_L20_001AED90 at
   -0x260) keep their `sda'.

   The attempt belongs in the -G8 unit.
*/

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_00301ED0(void *);

extern void func_003253A8(void *);

extern float func_00303270(float, float);

extern float func_00302870(float);

extern int func_00303410(float, int, int);

extern float func_003033B8(int);

extern void func_L00_002E6CF0(void *, void *);

extern void func_L20_0039F230(char *);

extern int D_L20_001AEDA8 __attribute__((sda));

extern int D_L20_001AED90 __attribute__((sda));

extern int D_L20_001AED94;

extern int D_L20_001AED9C;

extern int D_L20_001AED98;

void func_L20_0039ED78(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);

    if (func_00301ED0(state) != 0) {
        func_003253A8(arg0);
    } else {
        f32 x = *(f32 *)(state + 0x8);
        f32 r, s, f0, half;
        int v, v0, v1;
        int a0, a1;

        if (*(int *)(state + 0xC) != 0) {
            r = func_00303270(x, (f32)D_L20_001AEDA8 * 0.0002908882452f);
            *(f32 *)(state + 0x8) = r;
            s = func_00302870(r);
            half = 0.5f;
            f0 = s * half;
            a1 = D_L20_001AED94;
            a0 = D_L20_001AED90;
        } else {
            r = func_00303270(x, (f32)D_L20_001AEDA8 * 0.0002908882452f);
            *(f32 *)(state + 0x8) = r;
            s = func_00302870(r);
            half = 0.5f;
            f0 = s * s * half;
            a1 = D_L20_001AED9C;
            a0 = D_L20_001AED98;
        }
        half = f0 + half;
        v = func_00303410(half, a0, a1);
        v = func_00303410(0.15f, *(int *)(state + 0x10) | *(int *)(state + 0x4), v);
        v0 = v & 0xFFFFFF;
        v1 = v & 0xFF000000;
        *(int *)(state + 0x10) = v1;
        *(int *)(state + 0x4) = v0;
        *(f32 *)(state + 0x14) = func_003033B8(v1 >> 24) * 0.00390625f;
        func_L00_002E6CF0(func_L20_0039F230, arg0);
    }
}
