/* Near miss from src/levels/20_yeedil/L20_0039C448.c: 352 bytes; 336-byte candidate; 0/1.

    The whole body is there - the frame (0x40), the two branches, the
    float constants, the call sequence and the epilogue - and only three
    things differ:

      - the register allocation.  The retail keeps the argument in $s1
        (`daddu $s1,$a0,$zero`), the state pointer in $s2
        (`lw $s2,0x68($s1)`), the copy of the object pointer in $s3 and
        the address of the global in $s4; this cc1 gives the argument
        $s2 and the state pointer $s1, and it uses only four callee-saved
        registers where the retail uses five;
      - the retail keeps a COPY of the object pointer in $s3
        (`daddu $s3,$s0,$zero`, in both branches) where this cc1 drops
        the copy and uses $s0 itself;
      - the comparison of the float branch is `c.lt.s $f21,$f0` in the
        retail and `c.olt.s $f21,$f0` here (the same test, the other
        encoding); `if (!(a > b))` gives `c.ole.s` with the operands
        swapped, and the plain `if (a < b)` gives `c.olt.s`.

    The globals: D_00189E20 is the boot's table (the retail keeps its
    address in $s4 and reads the field at +0x2290 through it), and
    D_L20_001B9FD8 is a level float (read absolutely, `lwc1
    %lo(D_1B9FD8)($v0)`).

    The float constants: 8.0f, 12.0f, -45.0f, 45.0f and 0.017453292f
    (pi/180, 0x3C8EFA36). */

#include "common.h"

extern f32 func_002A7878(f32, f32);
extern f32 func_00283B98(f32, f32);
extern f32 func_00283180(f32);
extern f32 func_00283198(f32);
extern void func_00282CC0(char *, char *, char *);
extern void func_00282CF0(void *, void *, void *);
extern f32 func_00282DF0(f32 *);
extern void func_00282F70(char *, char *, f32);
extern f32 func_00282E80(void *, void *);
extern char D_00189E20[];
extern float D_L20_001B9FD8;

void func_L20_0039E1E8(char *arg0) {
    char *s1 = arg0;
    char *s2 = *(char **)(arg0 + 0x68);
    char *tbl = D_00189E20;
    char *s0;
    char *s3;
    f32 f20;
    f32 f21;

    f21 = func_002A7878(8.0f, 12.0f);
    if (*(char **)(s2 + 0x200) == *(int *)(tbl + 0x2290)) {
        s0 = s2 + 0x260;
        s3 = s0;
        s1 = s1 + 0x10;
        f20 = func_002A7878(-45.0f, 45.0f);
        f20 = func_00283B98(f20 * 0.017453292f, D_L20_001B9FD8);
        *(f32 *)(s2 + 0x260) = func_00283180(f20) * f21;
        *(f32 *)(s2 + 0x264) = func_00283198(f20) * f21;
        *(int *)(s2 + 0x268) = 0;
        func_00282CC0(s0, s0, tbl + 0x80);
    } else {
        s0 = s2 + 0x260;
        s1 = s1 + 0x10;
        s3 = s0;
        func_00282CF0(s0, s1, *(char **)(s2 + 0x200) + 0x10);
        if (f21 < func_00282DF0((f32 *)s0)) {
            func_00282F70(s3, s3, f21);
        }
        func_00282CC0(s3, s3, *(char **)(s2 + 0x200) + 0x10);
    }
    *(f32 *)(s2 + 0x11C) = func_00282E80(s1, s3);
}

/* ------------------------------------------------------------------
   Second attempt (worker 07, level-20 wave of 2026-10-20): two of the
   three open items of the note above are closed, and the float constant
   of that note is wrong for this compiler.

   1. THE CONSTANT.  `0.017453292f` is NOT 0x3C8EFA36 in this compiler:
   it is 0x3C8EFA35 (0.01745329238474369 is the nearest float to
   0.017453292; 0x3C8EFA36 is 0.01745329424738884, one ULP above).  The
   literal that gives the retail's bytes is `0.017453294f`.  The rest of
   the level's float constants are right (0.666f = 0x3F2A7EFA,
   0.016666668f = 0x3C888889, 0.052359886f = 0x3D567752, 0.000290888245f
   = 0x3998825C, 4.84813745e-06f = 0x36A2AD2F, 0.78539824f = 0x3F490FDC,
   1.0471977f = 0x3F860A93, 210000.0f = 0x484D1400, 1.5707964f =
   0x3FC90FDB, 3.1415927f = 0x40490FDB, 0.003f = 0x3B449BA6 and
   0.005f = 0x3BA3D70A all come out as the note says).

   2. THE REGISTER ALLOCATION.  The retail keeps the argument in $s1 and
   the state pointer in $s2.  This cc1 gives them the other way round
   when the object pointer is computed inside the two branches; computing
   it BEFORE the branch (`s0 = s2 + 0x260;`) puts the argument in $s1 and
   the state in $s2, as the retail has them, and gives the copy of the
   object pointer $s3 and the global's address $s4 - the retail's five
   callee-saved registers, with the same offsets in the frame.

   3. WHAT IS STILL OPEN - and it is the same wall as the 128-bit copy
   (see the note on func_L20_0039C448 in this directory): the retail
   keeps a COPY of the object pointer in $s3 (`daddu $s3, $s0, $zero`) in
   BOTH branches and uses $s0 in the equal branch, while this cc1 lets
   the CSE replace the copy's value by the original's and gives both the
   same register.  The copy is the reload's, not the CSE's: in the RTL
   the two are separate pseudos (`(set (reg/v:SI 90) (reg/v:SI 89))`).
   The copy survives here only when the assignment is in ONE branch (the
   candidate below does that, and it is 344 bytes against the retail's
   352, two instructions short: the else branch has neither the
   `addiu $s0, $s2, 0x260` nor the copy).  With the assignment in both
   branches the CSE merges the two pseudos and the copy disappears
   altogether.  The retail's compiler did not merge them.

   The float comparison is NOT a difference: the R5900's `c.lt.s` is the
   word the general MIPS calls `c.olt.s` (opcodes/mips-opc.c), so the two
   names are one instruction and the differ only compares the mnemonic.

   This body belongs in the `-G8` unit?  No: it reaches no global through
   `$gp`.
   ------------------------------------------------------------------ */

extern f32 func_002A7878(f32, f32);
extern f32 func_00283B98(f32, f32);
extern f32 func_00283180(f32);
extern f32 func_00283198(f32);
extern void func_00282CC0(char *, char *, char *);
extern void func_00282CF0(void *, void *, void *);
extern f32 func_00282DF0(f32 *);
extern void func_00282F70(char *, char *, f32);
extern f32 func_00282E80(void *, void *);
extern char D_00189E20[];
extern float D_L20_001B9FD8;

void func_L20_0039E1E8_w07(char *arg0) {
    char *s1 = arg0;
    char *s2 = *(char **)(arg0 + 0x68);
    char *tbl = D_00189E20;
    char *s0;
    char *s3;
    f32 f20;
    f32 f21;

    f21 = func_002A7878(8.0f, 12.0f);
    s0 = s2 + 0x260;
    if (*(char **)(s2 + 0x200) == *(int *)(tbl + 0x2290)) {
        s3 = s0;
        s1 = s1 + 0x10;
        f20 = func_002A7878(-45.0f, 45.0f);
        f20 = func_00283B98(f20 * 0.017453294f, D_L20_001B9FD8);
        *(f32 *)(s2 + 0x260) = func_00283180(f20) * f21;
        *(f32 *)(s2 + 0x264) = func_00283198(f20) * f21;
        *(int *)(s2 + 0x268) = 0;
        func_00282CC0(s0, s0, tbl + 0x80);
    } else {
        s1 = s1 + 0x10;
        func_00282CF0(s0, s1, *(char **)(s2 + 0x200) + 0x10);
        if (f21 < func_00282DF0((f32 *)s0)) {
            func_00282F70(s3, s3, f21);
        }
        func_00282CC0(s3, s3, *(char **)(s2 + 0x200) + 0x10);
    }
    *(f32 *)(s2 + 0x11C) = func_00282E80(s1, s3);
}

/* ------------------------------------------------------------------
   level-20 wave of 2026-10-21, worker 07: the copy of the object pointer
   is the wall, and the two halves of the body pull the register
   allocation in opposite directions.

   1. THE COPY.  The retail keeps a COPY of the object pointer in $s3 in
      BOTH branches (`daddu $s3,$s0,$zero` at 0x0039E254 and at
      0x0039E2D4) and the else branch recomputes the pointer
      (`addiu $s0,$s2,0x260` at 0x0039E2BC).  This cc1 lets the CSE replace
      the copy's value by the original's: with the copy in one branch only
      it survives (the attempt above, 344 bytes against the retail's 352,
      two instructions short - the else branch has neither the `addiu` nor
      the copy), and with the copy in BOTH branches the CSE merges the two
      pseudos and BOTH copies disappear (336 bytes).

      Measured this wave, all folding: two different C names for the
      object pointer in the two branches, the object pointer recomputed
      from a second load of the state (`*(char **)(arg0 + 0x68) + 0x260`),
      the pointer cast through `unsigned int`, and the pointer built as
      `s2 + 0x100 + 0x160`.  The CSE merges them all.

   2. THE REGISTER ALLOCATION.  The retail keeps the argument in $s1 and the
      state pointer in $s2; computing the object pointer BEFORE the branch
      (`s0 = s2 + 0x260;`) gives that, and gives the copy of the object
      pointer $s3 and the global's address $s4 - the retail's five
      callee-saved registers with the same offsets in the frame.  But with
      the pointer computed before the branch the else branch has no
      `addiu $s0,$s2,0x260` of its own, which is one of the two missing
      instructions: the two requirements cannot be met at once.

   3. THE GLOBAL'S ADDRESS.  The retail materialises the address of
      D_00189E20 in the SPLIT form and after the first call:

        lui $v0,%hi(D_189E20) ; lw $a2,0x200($s2) ;
        addiu $s4,$v0,%lo(D_189E20) ; lw $v1,0x2290($s4)

      With `tbl = D_00189E20;` before the call the compiler hoists the
      `lui` to the top of the function; with it after the call the `lui`
      stays where the retail has it but the register allocation changes
      (the state pointer moves to $s3 and the copy to $s2).  All six
      orders of the three statements (`tbl = ...`, `s0 = s2 + 0x260;`,
      `f21 = func_002A7878(8.0f, 12.0f);`) were measured: three of them
      give 344 bytes with the allocation right, three give 344 bytes with
      the scheduling right, none gives both.

   4. The float constant 0x017453294f and the c.lt.s/c.olt.s question of
      the note above are settled (the R5900's `c.lt.s` IS the word the
      general MIPS calls `c.olt.s`; the differ only compares the mnemonic).

   This body belongs in the `-G8` unit?  No: it reaches no global through
   `$gp`.
   ------------------------------------------------------------------ */
