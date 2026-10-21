/* 0 of 1 places match - last line: 08_tabora: instruction at +0x8 differs
   Candidate is 184 bytes, retail's exact size, and the body is retail's: the three-slot
   walk with `i` in $a1 bumped in the `bnel` delay slot, the four pointers advanced at the
   loop bottom, the `slti $v0,$a1,3` back edge, and the found-slot arm that clears the 0x1B39A0
   word, releases each live handle through func_00291450 and answers 1 (the miss path answers
   0). THE PROLOGUE IS THE BLOCKER: retail materialises the four bases in the order
   0x1B39A0 -> $a2, 0x1B39E0 -> $s1, 0x1B39F0 -> $s2, 0x1B3A30 -> $v1, each `lui`/`addiu`
   pair interleaved with one `sd` of the save block, and keeps the walk's compare base in
   $v1. This cc1 groups them differently, keeps one base in $a0/$a3 and puts the walk's base
   elsewhere, which moves every following word.
   Three spellings measured, same interleave: pointers declared 0x1B39E0-first, pointers
   declared 0x1B39A0-first, and separate declarations with the assignments written out in
   retail's order. The sibling func_L08_00429408 (near miss, same data family) records the
   same wall with the array-index and pointer-local spellings. */
typedef signed int s32;

extern s32 D_L08_001B39A0[];
extern s32 D_L08_001B39E0[];
extern s32 D_L08_001B39F0[];
extern s32 D_L08_001B3A30[];
extern void func_00291450(s32 a0);

/* Frees the one of the three slots whose 0x1B3A30 word still names A0. */
s32 func_L08_00429350(s32 a0)
{
    s32 *pE0 = D_L08_001B39E0;
    s32 *pF0 = D_L08_001B39F0;
    s32 *pA0 = D_L08_001B39A0;
    s32 *p30 = D_L08_001B3A30;
    s32 i;
    s32 v;

    for (i = 0; i < 3; i++) {
        if (*p30 == a0) {
            v = *pE0;
            *p30 = 0;
            *pA0 = 0;
            if (v != -1) {
                func_00291450(v);
                *pE0 = -1;
            }
            v = *pF0;
            if (v != -1) {
                func_00291450(v);
                *pF0 = -1;
            }
            return 1;
        }
        pE0++;
        pF0++;
        pA0++;
        p30++;
    }
    return 0;
}

Wave 24 (worker 01): the prologue's address materialisation order is still the blocker,
but the closest spelling is now known.  `tools/check.py func_L08_00429350 --diff` with
the plain array-index form
    for (i = 0; i < 3; i++) {
        if (D_L08_001B3A30[i] == a0) { ... }
    }
gives "08_tabora: instruction at +0x10 differs" with 17 differing lines, all of them
the four base addresses: retail materialises 0x1B39A0 into $a2, 0x1B39E0 into $s1,
0x1B39F0 into $s2 and 0x1B3A30 into $v1, each as a joined `lui`/`addiu` pair, while this
cc1 splits them (`lui $a1` + `addiu $s1,$a1,0` and `lui $v0` + `addiu $s2,$v0,0`) and
keeps the two bases that are live across the call in call-clobbered registers instead of
$s1/$s2.  Measured with no effect: the four pointer locals in retail's own declaration
order, the same locals in the order 1B39E0/1B39F0/1B3A30/1B39A0, the array-index form,
and the "indexed pointer" form (`pE0 = &D_L08_001B39E0[i]` inside the loop).  All four
give the same split materialisation.

One lever measured that moves this towards retail and is worth the next worker's time:
`-mno-split-addresses`.  With the default flags this cc1 splits the address of a level
global - the `%hi` sits in one register and the `%lo` is added again at every use
(`lui $v1,%hi(D_1B39E0)` then `addiu $s1,$v1,%lo(D_1B39E0)`), while retail materialises
each base ONCE as a joined pair in one register (`lui $s1,%hi(D_1B39E0)` /
`addiu $s1,$s1,%lo(D_1B39E0)`).  Compiling the unit with
`-O2 -G0 -ffunction-sections -fno-builtin -mno-split-addresses` gives the joined form and
puts three of the four bases in retail's registers ($a2 = 0x1B39A0, $s1 = 0x1B39E0,
$s2 = 0x1B39F0); the best spelling then is 16 differing lines with the first difference
at +0x4c (the `indexed_ptr` attempt: `pE0 = &D_L08_001B39E0[i]` inside the loop).  The
flag is per file, and the unit already holds functions that match with the default
flags (they read no globals), so the flag can only be used for a unit of its own.
