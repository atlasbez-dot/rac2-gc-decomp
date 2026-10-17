#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

/* func_L23_004277E8 -- 196 bytes, level 23.  Candidate is the exact size and 40 of 49
 * words match; the nine left are the first block: this cc1 keeps the sub-object pointer
 * in `$t0` where retail keeps it in `$a2`, and the scheduler swaps the two 0xFF stores.
 *
 * retail (0x004277E8):
 *   addiu sp,sp,-0x10 ; sd s0,0x0(sp) ; sd ra,0x8(sp) ; s0 = a0
 *   lbu v1,0x20(s0) ; bnez v1,+0x6C ; lw a2,0x68(s0) [delay]
 *   state 0: lhu v0,0x34(s0) ; v1 = 0xFF ; f0 = 2000.0f ; a1 = 0x7D0 ; v0 |= 0x100
 *            sb v1,0x30(s0) ; sh v0,0x34(s0) ; a3 = 0x3FF ; sh v1,0x32(s0)
 *            sh a1,0x24(a2) ; swc1 f0,0x20(a2) ; jal func_002A7750(s0,1,0)
 *            sh a3,0x7C(s0) [delay slot] ; lhu v0,0x34(s0) ; v0 |= 0x4000 ; sh v0,0x34(s0)
 *   state 1: lwc1 f1,0x470C($gp) (= 0x001B36FC) ; if (f1 != 0.0f) { swc1 f1,0x20(a2) ;
 *            sh (s16)f1,0x24(a2) } ; jal func_002A7750(s0,2,0)
 *   tail:    jal func_L23_004278D8(s0)
 *
 * measured: 3 spellings measured (pointer local first/last, guard loaded before the
 * pointer, the two 0xFF stores in retail's order and reversed).  Store order and the
 * `$t0`-against-`$a2` choice are the scheduler's and the allocator's, not the source's.
 * The `$gp` float is fixed by the `sda` declaration below; the rest of the body is
 * understood end to end.
 * $gp recipe (lead, 2026-10-16, re-measured here): both `extern f32 X __attribute__((sda));` and
 * `extern f32 X __asm__("X_asm") __attribute__((section(".sdata")));` leave the reference BARE in
 * the .s (`l.s $f0,D_L02_001B1234`), i.e. GPREL16, which is retail's form.  The `lui $at`+absolute
 * pair seen in this candidate is the ASSEMBLER expanding the reference at that use site, not the
 * declaration spelling; the alias form is worth retrying here first for the next worker.
 */

extern void func_002A7750(void *, s32, s32);
extern void func_L23_004278D8(u8 *);
extern f32 D_L23_001B36FC __attribute__((sda));

void func_L23_004277E8(u8 *a0) {
    u8 *s0 = a0;
    u8 *o = *(u8 **)(s0 + 0x68);
    u8 st = *(u8 *)(s0 + 0x20);

    if (st == 0) {
        *(u8 *)(s0 + 0x30) = 0xFF;
        *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) | 0x100;
        *(u8 *)(s0 + 0x32) = 0xFF;
        *(u16 *)(o + 0x24) = 0x7D0;
        *(f32 *)(o + 0x20) = 2000.0f;
        func_002A7750(s0, 1, 0);
        *(u16 *)(s0 + 0x7C) = 0x3FF;
        *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) | 0x4000;
    } else if (st == 1) {
        f32 f = D_L23_001B36FC;

        if (f != 0.0f) {
            *(f32 *)(o + 0x20) = f;
            *(s16 *)(o + 0x24) = (s16)f;
        }
        func_002A7750(s0, 2, 0);
    }
    func_L23_004278D8(s0);
}
