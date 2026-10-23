/* func_L03_003D2018 (224 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 224 bytes, 55 of 56 instructions identical; the fault is the table pointer's
   address materialisation.
   check.py (03_endako), with the source below in a unit of its own
   (src/levels/03_endako/L03_003D2018-qcopy.c, built at
   -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier):
     003D201C  lui    $v1, 0x0      |  sd    $s0, 0x10($sp)
     003D2020  sd    $s0, 0x10($sp)|  sd    $ra, 0x20($sp)
     003D2024  sd    $ra, 0x20($sp)|  sd    $s1, 0x18($sp)
     003D2028  sd    $s1, 0x18($sp)|  lw    $s1, 0x68($a0)
     003D202C  lw    $s1, 0x68($a0)|  lui   $s0, 0x1B
     003D2030  lw    $s0, 0x0($v1) |  lw    $s0, 0x2A1C($s0)
   Everything from the index load on matches, word for word, to the end of the body.
   Retail keeps the %hi of D_L03_001B2A1C in the load's own destination register and in
   place; this compiler hoists the %hi into $v1 in the entry block and loads through it.
   That one pair is the whole difference; the body is otherwise exact.

   What is measured and right:
   - the unit needs -frac2-qcopy: the retail's grouped copy `lq $v0,0($a1); sq $v0,0($sp)`
     (with $a1 holding the source address) is only produced by that profile, and the
     pattern is selected by the explicit destination form `*(TI128 *)&v2 = *(TI128 *)p;`
     (a plain `v2 = *(TI128 *)p;` keeps the folded `lq $a0,0xF0($s0)`).
   - the unit needs -frac2-qcopy-barrier as well: without it the float constant
     (-1.0471977f) is hoisted to the top of the function and the body does not match.
   - the two float constants are 1.0471977f: the retail's words are `lui $at,0x3F86;
     ori $at,$at,0xA93` (0x3F860A93) and `lui $at,0xBF86; ori $at,$at,0xA93`
     (0xBF860A93); pi/3 in a double rounds to 0x3F860A92 and does not fit.
   - the last float pair reads and writes D_00189E20_19 + 0x98 through a local pointer
     variable; writing the access out (`*(f32 *)(base + 0x98) = ...`) is what produces
     retail's `lui $s0,%hi; addiu $s0,$s0,%lo; lwc1 $f12,0x98($s0)`, while a second
     pointer variable folds the address into the displacement.
   - the table entry is `D_L03_001B2A1C + index * 0x100`, the index is the word at the
     actor's +0x68, and the record's flags are cleared with 0xFFBE and set with 0x1000.

   Tried and not enough: -G8 (the table pointer's load then comes out in retail's form,
     but the two pointer variables swap registers, the prologue's save order changes and
     the last two accesses get $at instead of a register); -frac2-gcse-unsplit-edges;
     the table pointer read as `*(char **)&D_L03_001B2A1C`, as a separate variable, and
     as `s0 = s0 + (index << 8)`; a local copy of the record's address.
   Next idea: a lever that keeps the %hi of D_L03_001B2A1C in the load's destination
   register (the -G8 reload form) without the other -G8 changes. */

#include "common.h"

extern u8  *D_L03_001B2A1C;
extern f32  func_2F0000(f32 a0, f32 a1);
extern void func_2BEE78(char *a0, char *a1, s32 a2, s32 a3);
extern void func_2B8300(s32 a0, s32 a1, char *a2);
extern void func_43B870(s32 a0);
extern void func_32F140(s32 a0, s32 a1);
extern f32  D_00189E20_19;
extern u8   D_001395BF;

typedef int TI128 __attribute__((mode(TI)));

/* The actor's per-frame update: the entry's flags are cleared, its record is copied
   and rotated by pi/3, and the resident block's float is turned the other way. */
void func_L03_003D2018(char *a0)
{
    char *s1 = *(char **)(a0 + 0x68);
    char *s0 = D_L03_001B2A1C + *(s32 *)s1 * 0x100;
    u16 v1 = *(u16 *)(s0 + 0x34);
    char *p = s0 + 0xF0;
    s32 v0 = *(s32 *)(s0 + 0x24);
    TI128 v2;
    f32 *f;
    char *base;

    v1 = (v1 & 0xFFBE) | 0x1000;
    *(u16 *)(s0 + 0x34) = v1;
    *(s32 *)(s0 + 0x98) = *(s32 *)(v0 + 0x10);
    *(TI128 *)&v2 = *(TI128 *)p;
    f = (f32 *)((char *)&v2 + 8);
    *f = func_2F0000(*f, -1.0471977f);
    func_2BEE78(s0 + 0x10, (char *)&v2, 0, 1);
    func_2B8300(1, 0x3F, s0);
    base = (char *)&D_00189E20_19;
    *(f32 *)(base + 0x98) = func_2F0000(*(f32 *)(base + 0x98), 1.0471977f);
    func_43B870(*(s32 *)(s1 + 0x28));
    func_32F140(*(s32 *)(s1 + 0x20), -1);
    D_001395BF = 1;
}
