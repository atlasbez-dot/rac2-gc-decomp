/* func_L10_00423500 (level 10, 156 bytes) -- NEAR MISS, not integrated.
   state: 156 bytes against retail's 156; check.py: 0 of 1 places match.
   matches: the frame, the two call sequences with their delay-slot stores, the `mult` and the
   address arithmetic, the 8.0f constant, the three globals reached through $gp, and the order of
   the five stores before the first call.
   what still differs: (a) the position of the `addiu $v1,$zero,0x64` (the materialisation of the
   0x64) and of the `addiu $a0,$zero,0x6` (the argument of the call) - this cc1 hoists both one
   slot earlier than retail does; (b) the store of 0 to the $gp global 0x23B4 lands in the call's
   delay slot here, retail keeps it before the call; (c) in the second half retail computes the
   record's address into $a0 and copies it to $v1 (`addu $a0,$v1,$v0` / `daddu $v1,$a0,$zero` /
   `sw $v0,0x14($v1)`), this cc1 computes it into $v0 and copies it to $a0 for the call
   (`addu $v0,$v0,$v1` / `lw $a1,0x10($v0)` / `daddu $a0,$v0,$zero` / `sw $a1,0x14($v0)`).
   tried: the six orders of the five stores around the first call, the results of the first call
   through a variable and directly, and a temporary for the loaded word - the register allocation
   of the second half does not move.
   the $gp data (0x23B0, 0x23B4, 0x2448) needs the -G8 profile: in the -G0 unit the compiler
   emits the lui/addiu form for them, so this body belongs in L10_003170D0-g8.c with the three
   globals marked `sda`.
   check.py func_L10_00423500 (in a -G8 unit): "10_hrugis_cloud: 156 bytes, expected 156" -
   the size is right and the first four instructions (the frame, the -2, the constant 1) are
   retail's, but eight words differ in the two halves described above. */

#include "include_asm.h"

typedef unsigned char u8;
typedef signed int s32;

extern s32 D_L10_00213B0 __attribute__((sda));
extern s32 D_L10_00213B4 __attribute__((sda));
extern s32 D_L10_0021448 __attribute__((sda));
extern u8 D_L10_00221CD0[];
extern u8 D_L10_002A3C70[];

extern s32 func_0037C8B0(s32 a0);
extern void func_0037CFD8(u8 *a0);
extern void func_0037BD10(u8 *a0);
extern void func_0037F490(void);
extern void func_0037BD50(void);

void func_L10_00423500(void) {
    u8 *s0 = D_L10_00221CD0;
    u8 *p;
    s32 r;

    D_L10_00213B0 = -2;
    D_L10_0021448 = 1;
    D_L10_00213B4 = 0;
    *(s32 *)(s0 + 0x2C) = 1;
    *(s32 *)(s0 + 0x28) = 0x64;
    r = func_0037C8B0(6);
    *(s32 *)(s0 + 0x14) = 0;
    p = D_L10_002A3C70 + r * 0x28;
    *(s32 *)(p + 0x14) = *(s32 *)(p + 0x10);
    func_0037CFD8(p);
    *(f32 *)(s0 + 0x30) = 8.0f;
    *(s32 *)(s0 + 0x10) = 0;
    func_0037BD10(0);
    func_0037F490();
    func_0037BD50();
}
