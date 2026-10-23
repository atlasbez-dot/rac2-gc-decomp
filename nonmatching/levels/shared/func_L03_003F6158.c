/* from src/levels/03_endako/L03_003F09C0.c: C that compiles but does not match */
/* The retail's two 16-byte copies are one `lq`/`sq` each, which needs a
 * `mode(TI)` copy in a unit of its own built with `-frac2-qcopy`; an
 * aggregate copy gives `ldl`/`ldr`/`sdl`/`sdr` instead.  The `beql` at
 * 0x003F61C8 carries the child's flag word in its slot, and the branch-likely
 * profile of this compiler is not reachable from the plain source. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void *func_3113F0(u32 id);
extern void *func_32AA20(void *obj, s32 a1);
extern f32 func_2EF670(f32 a, f32 b);
extern f32 func_2F0048(f32 a, f32 b);
extern void func_324210(void *obj, void *target, s32 a, f32 f0, f32 f1);
extern void func_326730(void *obj, void *target, s32 a, s32 b, f32 scale);
extern void func_31B640(void *obj, void *a1, void *a2, s32 a3);

/* The boot's block at 0x0012E20; the retail reads its words at +0x80 and +0x84. */
extern f32 D_0012EA0;
extern f32 D_0012EA4;

typedef int TI128 __attribute__((mode(TI)));

void func_L03_003F6158(u8 *entity) {
    u8 *state = *(u8 **)(entity + 0x68);
    u8 *obj = *(u8 **)(state + 0x2C4);
    u8 *dst;
    u16 flag;
    f32 f0;
    f32 f12;
    f32 f13;

    if (obj == 0) {
        obj = (u8 *)func_3113F0(0xC49);
        if (obj == 0)
            return;
        *(u8 **)(state + 0x2C4) = obj;
        dst = (u8 *)func_32AA20(obj, 0);
    } else {
        dst = obj + 0x10;
    }
    *(TI128 *)dst = *(TI128 *)(entity + 0x10);
    *(TI128 *)(obj + 0xF0) = *(TI128 *)(entity + 0xF0);

    flag = *(u16 *)(entity + 0x34);
    if (flag & 1) {
        *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 1;
        obj[0x31] = 0;
    } else {
        *(u16 *)(obj + 0x34) = flag & 0xFFFE;
        obj[0x31] = 1;
    }

    f12 = D_0012EA0 - *(f32 *)(obj + 0x10);
    f13 = D_0012EA4 - *(f32 *)(obj + 0x14);
    f0 = func_2EF670(f12, f13);
    f12 = *(f32 *)(entity + 0xF8);
    f13 = func_2F0048(f12, f0);
    *(f32 *)(state + 0x278) = f0;
    func_324210(obj, state + 0x210, 0, 0x3CF5C28F, 0x3E99999A);
    func_326730(obj, state + 0x210, 0, 1, 2.5f);

    if ((obj[0x60] & 2) != 0 && obj[0x43] == 1)
        func_31B640(obj, 0, 0, 10);
}
