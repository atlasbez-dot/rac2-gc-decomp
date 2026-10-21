/* func_L12_0041A5F8 (160 B) — best attempt, NOT matching.
 *
 * tools/check.py func_L12_0041A5F8 --diff -> "12_todano: 156 bytes, expected 160"
 * Residual: (a) the node pointer lives in $v1 where retail has $a3;
 *           (b) the 128-bit copy comes out as `lq $v1,0x210($v1)` / `sq $v0,0x10($s0)`
 *               where retail pre-computes both bases: `addiu $v1,$a3,0x210; lq $v0,0($v1)`
 *               and `addiu $a1,$s0,0x10; sq $v0,0($a1)`;
 *           (c) 4 bytes short (one instruction).
 * The lq/sq spelling itself is right (typedef int TI128 __attribute__((mode(TI)))).
 */

typedef int TI128 __attribute__((mode(TI)));

void func_L12_0041A5F8(u8 *self)
{
    u8 *dst = self + 0x10;
    u8 *n = *(u8 **)(self + 0x68);
    u8 *m = *(u8 **)(self + 0x24);

    *(TI128 *)dst = *(TI128 *)(n + 0x210);
    *(f32 *)(self + 0xF8) = *(f32 *)(n + 0x21C);
    *(u32 *)(n + 0x224) = 0;
    *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) & 0xFFBE) | 0x1000;
    *(u32 *)(self + 0x98) = *(u32 *)(m + 0x10);
    func_L02_002EF388(self, dst, self + 0xF0, 0, 0, m);
    func_002A7750(self, 2, -1);
    if (*(u8 *)(self + 0x43) != 8)
        func_002A7470(self, 8, 0, 1);
}

/* Wave 24 (worker 05): the same wall, measured again from the retail body.
   The retail keeps the address of the transfer in a register and uses a zero
   displacement:

     addiu $a1, $s0, 0x10
     lw   $a3, 0x68($s0)
     addiu $v1, $a3, 0x210
     lq    $v0, 0x0($v1)        <- the source is base + 0x210
     sq    $v0, 0x0($a1)        <- the destination is base + 0x10

   while this cc1 folds the offsets into the instructions
   (`lq $v0,0x210($v1)` / `sq $v0,0x10($s0)`), which also moves the moby
   pointer out of $a3 - the same residual (a) the note above records.  With
   the attempt below check.py (12_todano) reports "152 bytes, expected 160"
   (the earlier attempt in this file reached 156).

   What is measured and right: the copy is a mode(TI) object; the moby
   pointer comes from the object's 0x68 and is used after the call, so it has
   to be in $a3 (retail) - a callee-saved register would change the frame;
   the 64-bit result of the first call is stored at the object's 0x98 (retail
   `sw $v1,0x98($s0)` in the jal's delay slot).  */
typedef int TI128_w24 __attribute__((mode(TI)));

extern void func_L02_002EF388(void *, void *, void *, int, int, void *);
extern void func_002A7750(void *, int, int);
extern void func_002A7470(void *, int, void *, int);

void func_L12_0041A5F8_w24(u8 *a0) {
    u8 *s0 = a0;
    u8 *moby = *(u8 **)(s0 + 0x68);
    void *t1;

    *(TI128_w24 *)(s0 + 0x10) = *(TI128_w24 *)(moby + 0x210);
    *(f32 *)(s0 + 0xF8) = *(f32 *)(moby + 0x21C);
    *(u32 *)(moby + 0x224) = 0;
    *(u16 *)(s0 + 0x34) = (*(u16 *)(s0 + 0x34) & 0xFFBE) | 0x1000;
    t1 = *(void **)(s0 + 0x24);
    *(u32 *)(s0 + 0x98) = *(u32 *)((u8 *)t1 + 0x10);
    func_L02_002EF388(s0, s0 + 0x10, s0 + 0xF0, 0, 0, t1);
    func_002A7750(s0, 2, -1);
    if (s0[0x43] != 8) {
        func_002A7470(s0, 8, 0, 1);
    }
}
