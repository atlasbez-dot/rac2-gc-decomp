/* func_L22_003F8658 (348 bytes, 2 places: 22_dobbo_orbit, 23_damosel_orbit) -- NEAR MISS.
   State: exactly 348 bytes, frame 0x50 with s0-s4, prologue and the early-out block in retail's
   order; the body is decoded in full and only the scheduling of the vector setup differs.
   Profile: -O2 -G8 -ffunction-sections (no -frac2-qcopy: it changes nothing here).
   What is measured and right: the speed lerp A + (B - A) * ctl[0x18] times the slave rate into
   +0x2C; the early-out (empty controller slot, or slot kind 0xFE/0xFD) calling func_0029F338;
   the three level words loaded first into the sp+0x00 vector; the base symbol is
   D_L22_001B9C80 and the first blend call takes D_L22_001B9C80 + 0x230 (one base in $s0, the
   second as `addiu $a2,$s0,-0x230`); the 16-byte copy into +0x10; the two func_00283248 calls
   (the second negated into +0xF4) and the func_00283B98 turn of +0xF0 by the $gp scale times
   0.00029088825f - the calibrated spelling of pi/10800, 0x3998825C (0.0002908882f is two
   units low, 0x3998825A).
   Left, all scheduling/RA: retail assigns the three vector loads f2/f3/f0 and the ctl word f1
   and stores v[0],v[1] then v[2] in the jal delay slot; this cc1 assigns f2/f0/f1 and stores
   v[1] first. The 16-byte copy is also the register form in retail (`lq $v0,0($s1)` /
   `sq $v0,0($s2)`) against the folded `0x10($sp)`/`0x10($s3)` here, even though $s1/$s2 already
   hold the two addresses. Nine shapes measured (named destination, named buffer, one 8-float
   buffer, ctl store first, qcopy profile): same permutation.
*/

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef int TI128 __attribute__((mode(TI)));
typedef float f32;

/* the two ends of the speed ramp, the three words of the direction vector and the
 * two scales the turn uses, all through $gp. */
extern f32 D_L22_001B0BA4 __attribute__((sda));

extern f32 D_L22_001B0BA8 __attribute__((sda));

extern f32 D_L22_001B0BB4 __attribute__((sda));

extern f32 D_L22_001B0B90 __attribute__((sda));

extern f32 D_L22_001B0B94 __attribute__((sda));

extern f32 D_L22_001B0B98 __attribute__((sda));

extern f32 D_L22_001B0BB0 __attribute__((sda));

extern u8 D_L22_001B9C80[];

extern void func_00283098(f32 *, f32 *, u8 *);

extern void func_00282CC0(u8 *, u8 *, u8 *);

extern f32 func_00283248(f32, f32);

extern f32 func_00282E80(u8 *, u8 *);

extern f32 func_00283B98(f32, f32);

extern void func_0029F338(void *);

/* Runs the object's speed ramp, then either tears it down (no controller slot, or a
 * slot of kind 0xFE/0xFD) or points it along the level's direction vector and stores
 * the turn it must make plus the angle it turns at. */
void func_L22_003F8658(u8 *a0) {
    u8 *obj = a0;
    u8 *ctl = *(u8 **)(obj + 0x68);
    u8 *sub = *(u8 **)(obj + 0x24);
    u8 *p;
    u8 *dst;
    u8 *buf;
    f32 v[8];
    f32 t;

    *(f32 *)(obj + 0x2C) = *(f32 *)(sub + 0x24)
        * (D_L22_001B0BA4 + (D_L22_001B0BA8 - D_L22_001B0BA4) * *(f32 *)(ctl + 0x18));
    p = *(u8 **)(ctl + 0x10);
    if (p == 0 || *(u8 *)(p + 0x20) == 0xFE || *(u8 *)(p + 0x20) == 0xFD) {
        func_0029F338(obj);
        return;
    }
    dst = obj + 0x10;
    buf = (u8 *)(v + 4);
    *(f32 *)(ctl + 0xC) = D_L22_001B0BB4;
    v[0] = D_L22_001B0B90;
    v[1] = D_L22_001B0B94;
    v[2] = D_L22_001B0B98;
    func_00283098(v, v, D_L22_001B9C80 + 0x230);
    func_00282CC0(buf, (u8 *)v, D_L22_001B9C80);
    *(TI128 *)dst = *(TI128 *)buf;
    *(f32 *)(obj + 0xF8) = func_00283248(*(f32 *)(ctl + 0x0) - *(f32 *)(obj + 0x10),
                                         *(f32 *)(ctl + 0x4) - *(f32 *)(obj + 0x14));
    t = func_00282E80(dst, ctl);
    *(f32 *)(obj + 0xF4) = -func_00283248(t, *(f32 *)(ctl + 0x8) - *(f32 *)(obj + 0x18));
    *(f32 *)(obj + 0xF0) = func_00283B98(*(f32 *)(obj + 0xF0), D_L22_001B0BB0 * 0.00029088825f);
}
