/* func_002D53F0: 140 bytes, 28 placements, near miss (0 of 28 with this file's flags).
 *
 * What is right: the prologue/epilogue, both void calls with their delay-slot arguments,
 * the arithmetic D_001B23A4 * 329.0f + 0.5f with its cvt.w.s/mfc1, the 0x80F0F0F0 constant
 * built with ori/dsll/ori, and the 0x1A6/0x2D4F/-1 arguments.
 *
 * What differs, measured with tools/check.py --diff --version us:
 *  1. Retail reads D_001B23A4 as one absolute `lwc1 $f0,D_001B23A4`, which the assembler
 *     expands through $at (`lui $at,0x1B; lwc1 $f0,0x23A4($at)`) and schedules after the
 *     329.0f constant. Under this file's default `-O2 -G0 -ffunction-sections` the
 *     address is split into `lui $v0` + `lwc1 0($v0)` and scheduled a word early.
 *     Repro: compiling this body with `-mno-split-addresses` added gives retail's $at
 *     form and position exactly. That is a per-file flag, so it would have to be a
 *     config/cflags.txt entry for src/game/002D3390.c (shared with its other C), not a
 *     change to this function.
 *  2. With -mno-split-addresses the two remaining differences are permutations: retail
 *     puts 329.0f in $f2 and 0.5f in $f1 (this body gives $f1/$f2), and retail moves
 *     a1 (from $s0), then a3 (from $v0), then builds a2, where this body builds a2
 *     between them and moves a1 last.
 *
 * Six wordings were measured under both flag sets and all compile identically:
 *   - y as a local vs. the conversion inline in the argument list,
 *   - `D_001B23A4 * 329.0f` vs. `329.0f * D_001B23A4` vs. `0.5f + D * 329.0f`,
 *   - a float copy of the global, a `(float)` cast, an array form (`D[0]`), volatile,
 *   - the func_00288FB8 result in its own local instead of inline.
 * `-fno-schedule-insns` (with -mno-split-addresses) makes the argument moves worse
 * (a0 first, then a2, a1, a3).
 *
 * Blocks: needs the -mno-split-addresses file profile, and the $f1/$f2 and a1/a3 order
 * are still an unexplained tie after that. No other wording is expected to break it.
 */

typedef unsigned long long u64;

extern float D_001B23A4;
extern void func_0027C540(long);
extern void func_0029C530(void);
extern int func_00288FB8(int);
extern void func_0027C660(void);
extern void func_0027FAA8(int, int, u64, int, int);

int func_002D53F0(void)
{
    int y;

    func_0027C540(0);
    func_0029C530();
    y = (int)(D_001B23A4 * 329.0f + 0.5f);
    func_0027FAA8(0x1A6, y, 0x80F0F0F0ULL, func_00288FB8(0x2D4F), -1);
    func_0027C660();
    return 0;
}
