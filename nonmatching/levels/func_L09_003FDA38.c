/* Near miss; game compiler, -O2 -G0 -ffunction-sections (src/levels/09_dobbo/L09_002F8BA0.c).
   us: 09_dobbo: 548 bytes, expected 544; func_L09_003FDA38: 0 of 1 places match.
   The body is right: both list sweeps, the sum guard, and the if/else on the 0x430
   float match instruction for instruction. The residual is one instruction, the
   operand order of the store address, and one delay-slot choice:
   - retail `addu $s0,$s1,$s0` (list + i*0x10); this C gets `addu $s0,$s0,$s1`
     (i*0x10 + list) once the call argument is parenthesised as
     `list + (i*0x10 + 0x10)`, which is what makes retail's
     `addiu $a0,$s0,0x10 ; addu $a0,$s1,$a0` come out. The two spellings are
     exclusive here: the left-associative form `list + i*0x10 + 0x10` gets the
     operand order right and loses the `addiu`-from-the-raw-index shape.
   - retail fills the `bc1tl` delay slot with `swc1 $f20,0x3EC($s3)` (an
     if-branch store) and lands on the else block; this C fills it with
     `swc1 $f20,0x32C($s3)`.
   Loads to keep: the list count must be re-read as `*(int *)list` at each of
   its three uses (loop test, modulo, `n - 1`); hoisting it into a local costs
   two callee-saved registers and 12 bytes. `if (...) { ... } else { zero the
   three channels }` (not an early return) gives retail's block order.
   Reopen with the exact source spelling that produces both the raw-index `addiu`
   and the base-first `addu` in one loop body. */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u32 D_L09_001FE6C0[];
extern f32 func_002EA630(u8 *a0, u8 *a1);
extern void func_0033EB48(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, f32 f12);

void func_L09_003FDA38(u8 *arg0) {
    u8 *s3 = *(u8 **)(arg0 + 0x68);
    u8 *list;
    s32 i;
    f32 f;

    list = (u8 *)D_L09_001FE6C0[*(u32 *)(s3 + 0x318)];
    *(f32 *)(s3 + 0x38C) = 0.0f;
    for (i = 0; i < *(s32 *)list; i++) {
        f = func_002EA630(list + (i * 0x10 + 0x10),
                          list + (((i + 1) % *(s32 *)list) * 0x10 + 0x10));
        *(f32 *)(list + i * 0x10 + 0x1C) = f;
        if (i != *(s32 *)list - 1)
            *(f32 *)(s3 + 0x38C) = *(f32 *)(s3 + 0x38C) + f;
    }
    list = (u8 *)D_L09_001FE6C0[*(u32 *)(s3 + 0x314)];
    *(f32 *)(s3 + 0x3B0) = 0.0f;
    for (i = 0; i < *(s32 *)list; i++) {
        f = func_002EA630(list + (i * 0x10 + 0x10),
                          list + (((i + 1) % *(s32 *)list) * 0x10 + 0x10));
        *(f32 *)(list + i * 0x10 + 0x1C) = f;
        if (i != *(s32 *)list - 1)
            *(f32 *)(s3 + 0x3B0) = *(f32 *)(s3 + 0x3B0) + f;
    }
    if (*(f32 *)(s3 + 0x430) != 0.0f) {
        *(u32 *)(s3 + 0x324) = 0;
        *(f32 *)(s3 + 0x3EC) = 0.0f;
        func_0033EB48((s32)D_L09_001FE6C0[*(u32 *)(s3 + 0x318)], (s32)(arg0 + 0x10),
                      (s32)(s3 + 0x324), (s32)(s3 + 0x3EC), *(short *)(s3 + 0x32A),
                      *(f32 *)(s3 + 0x430) * *(f32 *)(s3 + 0x38C));
        *(f32 *)(s3 + 0x32C) = 0.0f;
        *(u32 *)(s3 + 0x320) = 0;
        func_0033EB48((s32)D_L09_001FE6C0[*(u32 *)(s3 + 0x314)], (s32)(arg0 + 0x10),
                      (s32)(s3 + 0x320), (s32)(s3 + 0x32C), *(short *)(s3 + 0x32A),
                      *(f32 *)(s3 + 0x430) * *(f32 *)(s3 + 0x3B0));
    } else {
        *(u32 *)(s3 + 0x320) = 0;
        *(u32 *)(s3 + 0x324) = 0;
        *(f32 *)(s3 + 0x32C) = 0.0f;
    }
}
