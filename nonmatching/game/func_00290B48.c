/* Retained plain-C reconstruction, not a match.
 * Target: USA v1.01 func_00290B48, 280 bytes; 28 placements in each
 * of us, pal and us2. Default game profile, -O2 -G0 -ffunction-sections.
 * Nine tools/check.py invocations: four C source arrangements, then
 * a pointer-return prototype correction checked on all three releases.
 * No scratch compilations. Initial arrangement was 276 bytes; retained body is 280.
 * Retained verdict: 0 of 28 places in each release, first difference
 * at +0x3C. Prologue/epilogue agree; middle allocation, immediate
 * construction and store scheduling differ. Equal size is not a match.
 * ref_00 models the pre-alignment program-end reference; ref_01 models
 * the upper-bound reference. Those semantic identities are inferred,
 * and their per-placement values still require successful derivation.
 * Return ABI verified from the retail memset ending jr ra / move v0,a0,
 * consistent with pointer-return declarations in src/game/003399B0.c
 * and src/game/003427B0.c. Earlier void-return measurements superseded.
 * Reopen with evidence for the original state layout/store order or
 * matched equivalent source; do not repeat equivalent C reorderings.
 */

extern void *func_00115484(void *, int, int);
extern char D_001BAEC0[];
extern int D_001B22B0;
extern char ref_L00_00290B48_00[];
extern char ref_L00_00290B48_01[];

void func_00290B48(void)
{
    int *state = (int *)D_001BAEC0;
    unsigned int start, first, second, third;
    unsigned int top, block1, block2, block3, block4, block5;

    func_00115484(state, 0, 0x9C);
    top = (unsigned int)ref_L00_00290B48_01 - 0x8000;
    start = ((unsigned int)ref_L00_00290B48_00 + 0x3FFF) & ~0x3FFF;
    block1 = top - 0x40000;
    block2 = block1 - 0x64000;
    first = start + D_001B22B0;
    block3 = block2 - 0x2C000;
    second = first + D_001B22B0;
    block4 = block3 - 0x8000;
    third = second + 0x100000;
    block5 = block4 - 0x14000;
    state[0x98 / 4] = 0x07200000;
    state[0] = 0;
    state[0x10 / 4] = first;
    state[0x74 / 4] = block4;
    state[0x68 / 4] = third;
    state[0x88 / 4] = 0x01FFC000;
    state[0x6C / 4] = block5;
    state[0x8C / 4] = 0x07000000;
    state[0x90 / 4] = 0x07100000;
    state[0x94 / 4] = 0x07180000;
    state[0x04 / 4] = 0x100000;
    state[0x08 / 4] = start;
    state[0x0C / 4] = start;
    state[0x14 / 4] = second;
    state[0x18 / 4] = third;
    state[0x84 / 4] = top;
    state[0x80 / 4] = block1;
    state[0x7C / 4] = block2;
    state[0x78 / 4] = block3;
    state[0x70 / 4] = block5;
}
