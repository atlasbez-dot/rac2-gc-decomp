/* func_L22_003C9D48 (328 bytes, 2 places: 22_dobbo_orbit, 26_jamming_array) -- NEAR MISS.
   State: exactly 328 bytes and every instruction present; the whole body is a permutation of
   retail's. It needs a -G8 unit of its own (three $gp words at 0x001AFF58/60/64 and the
   absolute neighbour 0x001AFF5C) and never the -frac2-qcopy profile: retail's three 16-byte
   copies are displacement `lq`/`sq`, which qcopy turns into register addresses.
   What is measured and right: the four-child walk, the `por $v0` register-form zero store into
   the cleared tail quad, the w[2] product, the two blend calls on the sp+0x00 buffer, the
   `t < 0.1f` weight (t*10 above, 1.0f - t below) and the 0.08f placement call.
   Left, all scheduling: retail saves s1/s2 before the `daddu $s1,$a0` copy and saves s0 last,
   issues func_002820A0 with the controller load in its delay slot (this cc1 hoists the call and
   loads through $v0 first), and reorg duplicates the `por` into the `bgez` delay slot where this
   cc1 emits `bgezl` and duplicates the loop's first `lwc1` instead. Eight shapes measured
   (declaration order, named controller, counter initialiser, pointer formed outside the loop,
   -g profile): all give the same permutation.
   Compile with -O2 -G8 -ffunction-sections.
*/

typedef unsigned char u8;
typedef int s32;
typedef int TI128 __attribute__((mode(TI)));
typedef float f32;

/* the level's two blend words and the scale the placement call takes, all through $gp,
 * and the absolute factor the blend call takes. */
extern f32 D_L22_001AFF58 __attribute__((sda));

extern s32 D_L22_001AFF60 __attribute__((sda));

extern f32 D_L22_001AFF64 __attribute__((sda));

extern f32 D_001AFF5C[3] __attribute__((sda));

extern void func_002820A0(u8 *);

extern s32 func_002820D0(f32 *, s32, s32, f32, f32, f32);

extern void func_00283098(f32 *, f32 *, u8 *);

extern void func_00282CC0(u8 *, u8 *, u8 *);

extern f32 func_002AA140(f32, f32, f32);

extern s32 func_00283CF0(f32);

/* Walks the four children of the object: each gets a cleared tail quad, a blend of the two
 * floats around it, and a placement whose weight rises below 0.1 and fades above it. */
void func_L22_003C9D48(u8 *a0) {
    u8 *obj = a0;
    s32 i = 3;
    u8 *p;
    u8 *ctl;
    f32 v[4];
    f32 w[4];
    f32 f;
    f32 t;
    s32 n;

    func_002820A0(obj);
    ctl = *(u8 **)(obj + 0x68);
    p = ctl + 0x20;
    for (; i >= 0; i--) {
        *(TI128 *)(p + 0x10) = 0;
        w[2] = *(f32 *)(p) * *(f32 *)(p - 0x10);
        *(TI128 *)(p) = *(TI128 *)w;
        func_00283098(v, v, obj + 0xC0);
        func_00282CC0(v, v, obj + 0x10);
        f = func_002AA140(D_L22_001AFF58, D_001AFF5C[0], *(f32 *)(p));
        t = *(f32 *)(p);
        if (t < 0.1f)
            n = func_00283CF0((f32)D_L22_001AFF60 * t * 10.0f);
        else
            n = func_00283CF0((f32)D_L22_001AFF60 * (1.0f - t));
        func_002820D0(v, n, 0, f, D_L22_001AFF64, 0.08f);
        p += 4;
    }
}
