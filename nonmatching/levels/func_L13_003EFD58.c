/* 0 of 1 places match - last line: 13_boldan: 360 bytes, expected 364
 *
 * The body is recovered: the level's jump table at 0x002AD800 dispatches five
 * states, 0 and 2 and 4 have no code of their own (the table points 2 and 4 at
 * the epilogue), 1 and 3 share the counter block.  Retail's shape:
 *
 *   003EFD74  beqz  $v0, 0x3EFEAC      ; sel >= 5 -> the shared store
 *   003EFD7C  lui   $v0, 0x2B          ; the switch dispatch
 *   003EFD80  sll   $v1, $v1, 2
 *   003EFD84  addiu $v0, $v0, -0x2800
 *   003EFD88  addu  $v1, $v1, $v0
 *   003EFD8C  lw    $a0, 0x0($v1)
 *   003EFD90  jr    $a0
 *
 * The out-of-range path and the counter's "still counting" path share one
 * store, `sh $v0,0x96($s0)`, where $v0 is the sltiu result (0) on the first
 * and v+1 on the second; that is why the source keeps the range test in a
 * variable (`val = (s32)(sel < 5)`) and stores it at one place.
 *
 * The remaining difference (4 bytes) is the copy of the first argument of
 * func_3248E0: retail materialises `daddu $a0,$s0,$zero` in BOTH case blocks
 * and shares only the call, this cc1 hoists the copy into the shared call
 * block (one instruction instead of two).  The same holds for the store:
 * retail keeps `sh $v0,0x96($s0)` in a block of its own, here it is the tail
 * of the shared call block.
 *
 * Measured, all with `tools/check.py func_L13_003EFD58 --diff` in
 * src/levels/13_boldan/L13_00306F38.c:
 *
 *   - 372 bytes: the counter logic written out twice, the call duplicated;
 *   - 360 bytes: one counter block, the call shared, `val` in a variable
 *     (this deposit);
 *   - 384 bytes: the counter logic written out twice with the shared store.
 *
 * The float arguments of func_3281B8 come out right only when the integer
 * argument is the LAST one in the call (`func_3281B8(a0+0xF0, s1+4, f12, f13,
 * f14, f15, 0)`): both orderings put the arguments in the same registers
 * (a0,a1,a2 and f12..f15), but with the integer argument last this cc1 fills
 * the jal's delay slot with `daddu $a2,$zero,$zero` and keeps `mov.s $f14,$f13`
 * before the call, as retail does.
 *
 * The constants are the retail words: 0x3F490FDC = 0.78539824f (pi/4),
 * 0x3A64C38A = 0.00087266474f (pi/3600), 0x3DD67752 = 0.10471977f (pi/30).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern f32 func_2F9748(f32, f32);
extern s32 func_332438(u8 *);
extern void func_368E50(s32, s32, u8 *);
extern void func_3281B8(f32 *, u8 *, f32, f32, f32, f32, s32);
extern void func_3248E0(u8 *, s32, s32);
extern void *D_L13_002AD800[];

void func_L13_003EFD58(u8 *a0) {
    u8 *s1;
    u32 sel;
    u16 v;
    s32 val;
    s32 arg;
    u8 *obj;
    static void *cases[5] = {&&c0, &&c1, &&done, &&c3, &&done};

    s1 = *(u8 **)(a0 + 0x68);
    sel = a0[0x20];
    val = (s32)(sel < 5);
    if (val)
        goto *D_L13_002AD800[sel];
    goto store;

c0:
    a0[0x30] = 0xFF;
    *(f32 *)(s1 + 8) = *(f32 *)(a0 + 0xF0);
    *(f32 *)s1 = func_2F9748(*(f32 *)(a0 + 0xF0), 0.78539824f);
    a0[0x20] = 1;
    *(u16 *)(a0 + 0x96) = 0;
    goto done;

c1:
    if (func_332438(a0)) {
        func_368E50(0, 0, a0);
    }
    func_3281B8((f32 *)(a0 + 0xF0), s1 + 4, *(f32 *)s1, 0.00087266474f, 0.00087266474f,
                0.10471977f, 0);
    v = *(u16 *)(a0 + 0x96);
    if (v < 0x79) {
        val = v + 1;
        goto store;
    }
    arg = 3;
    obj = a0;
    goto call;

c3:
    if (func_332438(a0)) {
        func_368E50(0, 0, a0);
    }
    func_3281B8((f32 *)(a0 + 0xF0), s1 + 4, *(f32 *)(s1 + 8), 0.00087266474f,
                0.00087266474f, 0.10471977f, 0);
    v = *(u16 *)(a0 + 0x96);
    if (v < 0x79) {
        val = v + 1;
        goto store;
    }
    arg = 1;
    obj = a0;

call:
    func_3248E0(obj, arg, -1);
    *(u16 *)(a0 + 0x96) = 0;
    goto done;

store:
    *(u16 *)(a0 + 0x96) = (u16)val;

done:
    return;
}
