/* func_L08_00429408 (152 bytes, 1 place) - best attempt, NOT MATCHED.
 *
 * Docker-free ruler (scratch/wslcmp.py): "08_tabora: instruction at +0x8 differs".  Body,
 * calls and order are right; the prologue's address materialisation is grouped differently:
 *   retail: lui/addiu 0x1B39E0 (v0) ; lui/addiu 0x1B39A0 (v1) ; sll $s0,$a0,2 ;
 *           addu $v1,$s0,$v1 ; addu $s2,$s0,$v0 ; lui/addiu 0x1B3A30 (v0) ; ...
 *   mine  : the three bases interleave differently and one base is kept in $a0.
 *
 * Measured, no effect: array-index spelling (`D_L08_001B39A0[a0] = 0`) and pointer-local
 * spelling (`s32 *v = &D_L08_001B39E0[a0]`).  Both give the same interleave.
 */

typedef signed int s32;

extern s32 D_L08_001B39A0[];
extern s32 D_L08_001B39E0[];
extern s32 D_L08_001B39F0[];
extern s32 D_L08_001B3A30[];
extern void func_00291450(s32 a0);

void func_L08_00429408(s32 a0) {
    s32 *v = &D_L08_001B39E0[a0];

    D_L08_001B39A0[a0] = 0;
    D_L08_001B3A30[a0] = 0;
    if (*v != -1) {
        func_00291450(*v);
        *v = -1;
    }
    v = &D_L08_001B39F0[a0];
    if (*v != -1) {
        func_00291450(*v);
        *v = -1;
    }
}

Wave 24 (worker 01): the address materialisation is still grouped differently.  With the
attempt above `tools/check.py func_L08_00429408 --diff` gives "08_tabora: instruction at
+0x8 differs" with 24 differing lines; the prologue is the only difference: retail
materialises 0x1B39E0 into $v0 and 0x1B39A0 into $v1 (each a joined lui/addiu pair)
before the `sll $s0,$a0,2`, this cc1 materialises 0x1B39E0 into $v0 but keeps 0x1B39A0 in
$a0 and 0x1B3A30 in $v1, and interleaves the pairs with the `sd` saves differently.
Measured with no effect: the four pointer locals in retail's order, the same in
1B39A0-first order, the array-index spelling, a manual `i = a0 << 2` with the bases
added by hand, and the fully inlined `D_L08_001B39A0[a0]` spelling.

Measured lever: `-mno-split-addresses` turns the split address into retail's joined
`lui`/`addiu` pair, but the body then comes out four bytes short (148 against 152) with
all six spellings tried, so it does not land this function either.
