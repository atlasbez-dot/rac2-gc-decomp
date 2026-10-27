/* OF2 (2026-10-26): 176/176 bytes, default profile, own unit. D_001A63A8 is a plain extern
   struct reached through a local pointer (compiler-split lui/addiu, base in $a1), and the
   state load hoisted above the first test gives the bnez/bnel layout. Left (4 lines):
   retail holds the table word in $v1 and stores `elapsed = 0` before the andi; ours uses
   $v0 and puts that store in the jal delay slot. Store order, u32, a separate v
   assignment, an int callee and MACRO_ADDR on D_L16_001B1888 changed nothing. */
#include "common.h"

typedef struct {
    u8 pad[0x24];
    s32 timer;
    s32 elapsed;
    u8 pad2[0x3C];
    s32 busy;
} Music;

extern Music D_001A63A8;
extern int D_L16_001B1888[];
extern void func_002A6170(void *);

void func_L16_00412BA8(u8 *arg, s32 idx)
{
    Music *m = &D_001A63A8;
    u8 *s;
    s32 v;

    s = *(u8 **)(arg + 0x68);
    if (m->busy == 0) {
        if (m->timer == -1 && idx != *(s32 *)(s + 0x354)) {
            if (idx < 20)
                v = *(s32 *)(s + (idx << 2) + 0x280);
            else
                v = *(s32 *)(s + ((idx - 20) << 2) + 0x2D0);
            m->elapsed = 0;
            m->timer = (v & 0x3FFF) + 0x7D0;
            func_002A6170(D_L16_001B1888);
            *(u8 *)(s + idx + 0x310) = 1;
            *(s32 *)(s + 0x350) = 0x384;
            *(s32 *)(s + 0x354) = idx;
        }
    }
}

#if 0
/* Selects one of two measured value tables by index and arms the resident channel. */
void func_L16_00412BA8(u8 *arg, s32 idx)
{
    u8 *base = D_001A63A8;
    u8 *s0;
    s32 v;

    if (*(s32 *)(base + 0x68) != 0)
        return;
    s0 = *(u8 **)(arg + 0x68);
    if (*(s32 *)(base + 0x24) != -1)
        return;
    if (idx == *(s32 *)(s0 + 0x354))
        return;
    if (idx < 20)
        v = *(s32 *)(s0 + (idx << 2) + 0x280);
    else
        v = *(s32 *)(s0 + ((idx - 20) << 2) + 0x2D0);
    *(s32 *)(base + 0x28) = 0;
    *(s32 *)(base + 0x24) = (v & 0x3FFF) + 0x7D0;
    func_2A6170(D_L16_001B1888);
    *(u8 *)(s0 + idx + 0x310) = 1;
    *(s32 *)(s0 + 0x350) = 0x384;
    *(s32 *)(s0 + 0x354) = idx;
}

/* ---------------------------------------------------------------------------
 * wave 24, worker 14: the body above is 172 bytes against retail's 176; the
 * structure is right (the two early exits, the index test, the two value
 * tables, the callback call and the three stores) but the register
 * allocation and the schedule differ: retail keeps the shared state in $a1
 * and this cc1 in $a2, retail copies the index into $s1 before the saves and
 * this cc1 in the first branch's delay slot, retail puts the load of the
 * state pointer in the first branch's delay slot and this cc1 in the second
 * one, and retail's second exit is the branch-LIKELY `bnel` (with the restore
 * of $s0 in its delay slot) where this cc1 emits a plain `bne`.
 * The address form of the shared state matches only when the global is taken
 * into a pointer (`u8 *base = D_001A63A8;`): used directly, this cc1 splits
 * the address.
 */

extern int D_001A63A8[];
extern int D_L16_001B1888[];
extern void func_002A6170(void *);

void func_L16_00412BA8_w24(u8 *arg, s32 idx)
{
    u8 *base = (u8 *)D_001A63A8;
    u8 *s0;
    s32 v;

    if (*(s32 *)(base + 0x68) != 0)
        return;
    s0 = *(u8 **)(arg + 0x68);
    if (*(s32 *)(base + 0x24) != -1)
        return;
    if (idx == *(s32 *)(s0 + 0x354))
        return;
    if (idx < 20)
        v = *(s32 *)(s0 + (idx << 2) + 0x280);
    else
        v = *(s32 *)(s0 + ((idx - 20) << 2) + 0x2D0);
    *(s32 *)(base + 0x28) = 0;
    *(s32 *)(base + 0x24) = (v & 0x3FFF) + 0x7D0;
    func_002A6170(D_L16_001B1888);
    *(u8 *)(s0 + idx + 0x310) = 1;
    *(s32 *)(s0 + 0x350) = 0x384;
    *(s32 *)(s0 + 0x354) = idx;
}

#endif
