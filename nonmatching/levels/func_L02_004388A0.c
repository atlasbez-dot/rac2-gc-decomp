/* NEAR MISS (measured 22 October 2026): 644 bytes, retail's 644, in a unit of its own,
 * src/levels/02_maktar_nebula/L02_004388A0.c, built with
 *     -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * 0 of 1 places match, first difference at +0xB4.  With the barrier both vector blocks are
 * retail's word for word (the constant loads, the stores, the `lq $v0,0($fp) ; sq $v0,0($sp)`
 * copy and the `addiu $s5` index after it).  5 words differ, all the sentinel -1 of the
 * `idx != -1` test: retail has it in $v0, this cc1 in $v1 (+0xB4 the bne slot, +0xC8/+0xCC
 * `bnel $v0,... ; addiu $v1,-1` where retail has `bnez $v0,... ; addiu $v0,-1`, +0x114/+0x118 the
 * load and the `beq $s5`).  The bestid test's -1 is $v0 in both.
 *
 * Cause, measured with -dL and -dg (a compiler property, not a source shape):
 *   - loop.c moves the -1 of the idx test out of the outer loop (its movable is matched with the
 *     bestid test's -1: savings 2, life 3); global-alloc leaves it unallocated with a REG_EQUIV
 *     of -1, so reload rematerialises it in front of each test;
 *   - reload hands out reload registers round-robin over the function's spill registers
 *     (allocate_reload_reg, last_spill_reg).  Here they are {$v0, $v1} only because the
 *     TImode zero `*(TI128 *)tmp = 0` is reloaded as a GROUP of two registers ("Spilling reg 2.
 *     Spilling reg 3." for both clears in the .greg dump): CLASS_MAX_NREGS (GR_REGS, TImode) is 2
 *     while HARD_REGNO_NREGS (GPR, TImode) is 1 on the R5900.  The idx test's -1 is the next
 *     reload after the second clear's group (which always starts at $v0), so it gets $v1;
 *   - measured: with the clear replaced by `tmp[3] = 0.0f` (diagnostic only) the spill set is
 *     {$v0} and every -1, both tests included, is retail's $v0.
 *   What would unblock it: CLASS_MAX_NREGS consistent with HARD_REGNO_NREGS for TImode in the
 *   GPRs (an opt-in compiler switch; the matched bodies with a reloaded TImode zero would need a
 *   re-screen).  Tried on the source side: `long long bestid` (the two -1 movables no longer
 *   match and the first loop pass declines the move, but the rerun of loop moves it; 652 bytes),
 *   the outer loop as a `goto` loop (no loop motion at all: the -1 is $v0, but &tmp is no longer
 *   hoisted into $fp: 624 bytes).  Earlier: a `continue` for the `if`, a do-while, an unsigned
 *   index, moving `bestid = -1`.
 *
 * Spellings that matter, each measured earlier:
 *   - the level block is a struct: `D_L02_001BE200.timer` gives `lui ; addiu ; lw 0x34($v0)`, a
 *     char array gives `lui ; lw %lo(D+0x34)`;
 *   - the two range tests of each block are nested `if`s (`&&` is folded into one `sltiu` range
 *     test);
 *   - the table symbols are `sda`, which keeps the address of the corner table one `la` macro
 *     (`lui $s3 ; addiu $s3,$s3,0x2640` into the same register);
 *   - the draw loop counts up (`k < 4`), which loop.c turns into retail's `bgez $s2` count-down
 *     with both pointers walking up. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;

typedef int TI128 __attribute__((mode(TI)));

typedef struct { u8 pad[0x34]; int timer; } L02_State;
extern L02_State D_L02_001BE200;
extern void func_00282CC0(void *, void *, void *);

extern unsigned short **D_L02_001A9014 __attribute__((sda));
extern u8 *D_L02_001B3C1C __attribute__((sda));
extern float D_L02_001B2640[] __attribute__((sda));
extern float func_00282E80(void *, void *);
extern void func_00283098(void *, void *, void *);
extern void func_L01_002E2608(void *, int, int, int, int);

void func_L02_004388A0(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    float pt[4];
    float tmp[4];
    float m[16];
    unsigned short *q;
    u8 *e;
    u8 *rec;
    float best;
    float d;
    int idx;
    int bestid;
    int i;
    int k;

    for (i = 0; i < 2; i++) {
        idx = -1;
        if (i == 0) {
            if (D_L02_001BE200.timer >= 0x3B6) {
                if (D_L02_001BE200.timer < 0x547) {
                    *(TI128 *)tmp = 0;
                    tmp[0] = 495.0f;
                    tmp[1] = 587.0f;
                    tmp[2] = 513.0f;
                    *(TI128 *)pt = *(TI128 *)tmp;
                    idx = 0x3F;
                }
            }
        }
        if (i == 1) {
            if (D_L02_001BE200.timer >= 0x4E2) {
                if (D_L02_001BE200.timer < 0x5DD) {
                    *(TI128 *)tmp = 0;
                    tmp[0] = 515.0f;
                    tmp[1] = 596.0f;
                    tmp[2] = 512.0f;
                    *(TI128 *)pt = *(TI128 *)tmp;
                    idx = 0x40;
                }
            }
        }
        if (idx != -1) {
            bestid = -1;
            best = 99999.0f;
            for (q = D_L02_001A9014[*(int *)st];
                 q != 0 && ((short)q[-1] >= 0 || q == D_L02_001A9014[*(int *)st]) &&
                 (e = D_L02_001B3C1C + ((*q & 0x7FFF) << 6)) != 0;
                 q++) {
                d = func_00282E80(e + 0x30, pt);
                if (d < best) {
                    best = d;
                    bestid = *q & 0x7FFF;
                }
            }
            if (bestid != -1) {
                rec = D_L02_001B3C1C + (bestid << 6);
                for (k = 0; k < 4; k++) {
                    func_00283098(m + k * 4, D_L02_001B2640 + k * 4, rec);
                    func_00282CC0(m + k * 4, m + k * 4, rec + 0x30);
                }
                func_L01_002E2608(m, idx, 2, 0xFF808080, 0);
            }
        }
    }
}
