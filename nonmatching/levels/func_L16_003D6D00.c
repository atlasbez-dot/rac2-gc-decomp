/* func_L16_003D6D00 (364 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 368 bytes against retail's 364; the prologue, the frame layout and every
   branch target from +0x44 on are retail's. Two differences remain.

   check.py (16_snivelak), with the source below:
     003D6D18  bnel   $v0, $zero, ...   |  bnez   $v0, ...
     003D6D1C  lw     $s0, 0x68($a0)    |  lw     $s2, 0x68($a0)
     003D6D30  lw     $s0, 0x68($a0)    |  lui     $v0, 0x19
   The byte test comes out as the annulling `bnel`, so the pointer load in the delay
   slot is annulled on the fall-through and the load has to be repeated; retail uses
   a plain `bnez` and loads it once. The second difference is the register the
   pointer and the base land in: retail keeps the pointer in $s2 and the base in
   $s1, this build keeps the pointer in $s0 and the base in $s2.

   What is measured and right:
   - the level data is reached with %hi/%lo: the base is D_00189EA0 (the `lui $v0,0x19
     ; addiu $s1,$v0,-0x6160` pair), the table is D_L16_001B2C0C (an int holding an
     address) and the flag is D_L16_001BFF58. None of them is $gp-relative, so this
     unit needs no -G8.
   - the frame is 0x30 with the saved registers at 0x10/0x18/0x20/0x28 and the
     16-byte outgoing-argument area at 0x00; the four-float local that
     func_00282CC0 writes is that area, so the call's first argument is the local.
   - the call shapes are recovered: func_002ACBC8(s1, *(int *)s2),
     func_00282CF0(s1+0x270, table + index*128 + 0x30, s1),
     func_0027C878(s1+0x270, s1+0x270, 1.0f), func_00282CC0(local, s1, s1+0x270),
     func_002761F8(s1+0x60, local, 0, *(int *)(s0+0x2290), 0),
     func_00278E78(), func_L00_0030D478(s1+0x244C, 0, (int)(f * 0.3329932689666748f))
     and func_L16_002C0BC8(0x38, 1).
   - the float factor is the constant 0x3EAA7EFA (0.3329932689666748f), which the
     compiler materialises as `lui $at,0x3EAA ; ori $at,$at,0x7EFA`, and the
     truncation `cvt.w.s` comes from the C cast to int.
   - the source order matters for the prologue: the `&D_00189EA0` must be taken
     after the byte test, or the `lui` is hoisted into the prologue and the save
     block comes out as s2/s0/s1/ra instead of retail's s0/s1/s2/ra.

   What is left:
   - the annulling branch. This cc1 only sets INSN_ANNULLED_BRANCH_P (and so only
     emits the `l` form) when the delay-slot candidate conflicts with what the
     opposite thread needs; the pointer load in the slot conflicts here, so the
     slot is annulled and the fall-through reloads. Retail keeps the plain branch
     and the single load, so its slot did not conflict - the difference is in which
     thread the slot is filled from, which reorg.c decides from the branch
     prediction (reorg.c: fill_eager_delay_slots uses mostly_true_jump).
*/

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern int func_002ACBC8(void *, int);
extern void func_00282CF0(f32 *, f32 *, f32 *);
extern s32 func_0027C878(s32, s32, f32);
extern void func_00282CC0(f32 *, f32 *, f32 *);
extern s32 func_002761F8(char *, char *, s32, s32, s32);
extern int func_00278E78(void);
extern int func_L00_0030D478(void *, int, int);
extern void func_L16_002C0BC8(s32, s32);
extern int D_001A7A00;
extern char D_00189EA0;
extern int D_L16_001B2C0C;
extern int D_L16_001BFF58;

void func_L16_003D6D00(void *a0)
{
    char *s2;
    char *s1;
    char *s0;
    f32 tmp[4];
    int idx;

    if (*(u8 *)(a0 + 0x20) == 0) {
        *(u8 *)(a0 + 0x20) = 1;
        *(u8 *)(a0 + 0x30) = 0xFF;
    }
    s2 = *(char **)(a0 + 0x68);
    s1 = (char *)&D_00189EA0;
    if (func_002ACBC8(s1, *(int *)s2) == 0) {
        return;
    }
    s0 = s1 - 0x80;
    if (*(int *)(s0 + 0x229C) == 0xF) {
        return;
    }
    idx = *(int *)s2;
    func_00282CF0((f32 *)(s1 + 0x270), (f32 *)((char *)D_L16_001B2C0C + idx * 128 + 0x30), (f32 *)s1);
    func_0027C878((s32)(s1 + 0x270), (s32)(s1 + 0x270), 1.0f);
    *(f32 *)(s0 + 0x2FC) = 2.0f;
    *(u16 *)(s0 + 0x218) = 5;
    if (*(int *)(s0 + 0x340) == 0) {
        return;
    }
    *(int *)(s0 + 0x2F8) = 0;
    if (*(int *)(s0 + 0x2294) == 0x38) {
        return;
    }
    func_00282CC0(tmp, (f32 *)s1, (f32 *)(s1 + 0x270));
    if (func_002761F8((char *)(s1 + 0x60), (char *)tmp, 0, *(int *)(s0 + 0x2290), 0) == 0) {
        return;
    }
    if (func_00278E78() == 2) {
        return;
    }
    if (D_L16_001BFF58 != 0) {
        return;
    }
    func_L00_0030D478(s1 + 0x244C, 0, (int)((f32)D_001A7A00 * 0.33299326896667480469f));
    if (*(int *)(s0 + 0x24CC) == 0) {
        return;
    }
    func_L16_002C0BC8(0x38, 1);
}
