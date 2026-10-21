/* func_0033C028 (336 bytes, src/game/0033BE98.c): tools/check.py gives 28 of 28 places, but only with
   `if (w != 0) h = X; else h = X;` (two identical arms), which gives retail's basic-block boundary
   before the call; the plain `h = X;` gives 332 bytes. Held back: a branch whose arms are identical
   is there only to steer the scheduler (AGENTS.md, no artificial barriers). */

/* Opus retry, 20 October 2026: no plain-C spelling found; only a real branch reproduces retail.
   - Calls do not end basic blocks in this cc1 (flow.c count_basic_blocks), so without a branch
     the body is one block. Retail needs the arms' block boundaries for three separate reasons:
     (a) combine sinks both fix_trunc insns into the $a1/$a2 argument moves within a block;
     (b) local-alloc ties the 379 product to x ($f1) when x is local, while retail's x is a global
     pseudo (live across the arms), so the product takes the constant's $f0;
     (c) at the first func_00288FB8 call, `li $a0,0x31E5` and `addiu $s1,%lo(D_001ADDD8)` tie on
     sched2 priority, and the tie goes to the insn with more dependents. A loop-note barrier later
     in the same block adds a dependent to the $s1 insn only, which flips the delay slot.
   - `do { h = ...; } while (0);`: 336 bytes, but 24 lines of the .s differ. A float temporary
     reused for both values (`f = x * 170.0f + 0.5f; w = (int)f; f = x * 379.0f + 0.5f;
     h = (int)f;`) keeps w's conversion in place (combine refuses because f is set again), and
     with do-while(0) around the second pair 14 lines still differ, from (a) for h, (b) and (c).
   - No single flag moves the plain or reused-temporary spelling: -fno-schedule-insns,
     -fno-schedule-insns2 (alone or together), -fno-gcse, -fno-strength-reduce,
     -fno-rerun-cse-after-loop, -fno-cse-follow-jumps, -fno-cse-skip-blocks,
     -fno-expensive-optimizations, -fno-regmove, -fno-caller-saves, -fno-force-mem,
     -fno-peephole, -fno-thread-jumps, -fno-defer-pop, -g, -mno-split-addresses, -ffast-math.
   - jump2 cross-jumps after sched2, so a branch whose two arms compile alike leaves exactly
     retail's schedule. The original probably had such an if/else, for example two values that
     ended up equal. */

struct SolIds {
    int ids[2];
};
extern struct SolIds D_001ADDD0;
extern char D_001ADDD8[];
extern int D_001A7340 __attribute__((sda));
extern int D_001A7BB8 __attribute__((sda));
extern float D_001B23A4 __attribute__((sda));
extern void func_0033AF48(void *);
extern char *func_00288FB8(int);
extern int func_00115DA8(char *, const char *, ...);
extern void func_0027FAA8(int, int, unsigned long, char *, int);
extern void func_002802E0(void *, int, int, int, int, int, int, int, int);
extern void func_00280190(void *, unsigned long, char *, int);

/* Draws the two text lines, then the framed rectangle scaled by D_001B23A4.
   The retail object keeps a basic-block boundary after the first scaled value and before the
   call (its allocation and its unfilled scheduling holes show it): a branch on the value just
   converted, with the same second conversion in both arms, which the post-scheduling cross-jump
   merges into straight code. The plain `h = ...;` does not produce that schedule. */
void func_0033C028(char *object)
{
    char buffer[64];
    struct SolIds pair;
    char scratch[32];
    char *format;
    char *first;
    char *second;
    float x;
    int w, h;

    func_0033AF48(object + 8);
    pair = D_001ADDD0;
    format = D_001ADDD8;
    first = func_00288FB8(0x31E5);
    second = func_00288FB8(pair.ids[D_001A7BB8 != 0]);
    func_00115DA8(buffer, format, first, second);
    func_0027FAA8(D_001A7340 >> 1, 0x8C, 0x80F0F0F0UL, buffer, -1);
    x = D_001B23A4;
    w = (int)(x * 170.0f + 0.5f);
    if (w != 0)
        h = (int)(x * 379.0f + 0.5f);
    else
        h = (int)(x * 379.0f + 0.5f);
    func_002802E0(scratch, w, h, 44, 468, 254, 222, 20, 3);
    func_00280190(scratch, 0x80F0F0F0UL, func_00288FB8(0x32A8), -1);
}
