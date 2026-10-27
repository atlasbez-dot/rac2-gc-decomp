/* from src/levels/10_hrugis_cloud/L10_003170D0.c: spawns the object's 0x230000 form and
 * settles it on the ground. Best of 3 compiles: 528 bytes against retail's 536, 0/1
 * (this file compiles standalone: `python scratch\\wslcmp.py
 * nonmatching/levels/func_L10_00423788.c func_L10_00423788` prints
 * `10_hrugis_cloud: 528 bytes, expected 536`). A `goto out` spelling for the early
 * outs measured worse (524 bytes): the exits merged and the frame grew an $s6 save.
 * Retail's body is reproduced instruction for instruction except that
 *  (a) this cc1 merges the two early returns (`spawned == 0` and the 0xF93 kind test)
 *      into one in-line `daddu $v0,$zero; b` block (2 instructions before the node
 *      store) where retail branches straight to the epilogue (`beqz`/`bne`);
 *  (b) the live D_L10_001B354C address is reused from the func_00282948 argument
 *      register (`lui $s1` + `sw 0($s1)`) where retail re-materialises it with
 *      `lui $at; sw 0x354C($at)` (one instruction more);
 *  (c) the return local and the a1 parameter take $s5/$s4 here and $s4/$s5 in retail;
 *  (d) the two arguments of func_002A7878(10.0f, 20.0f) are loaded f12-then-f13
 *      here, f13-then-f12 in retail.
 * The first call's second argument is the fixed address 0x230000 (`lui $a1,0x23` with
 * no %lo), so it is written as a literal: this body is level-10 only.
 * Next hypothesis: spell the 0xCBE test so the two zero returns keep separate exits
 * (e.g. return a plain 0 rather than the live local in the first), and read the timer
 * through a fresh `*(u8 **)(a0 + 0x68)` so $s1 stays node and D_L10_001B354C takes $at. */
typedef signed int s32;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

extern s32 func_002A9640(u8 *a0, s32 a1, s32 a2);
extern void func_002AB8C0(u8 *a0, u8 *a1);
extern void func_002AB800(u8 *a0, u8 *a1);
extern s32 func_00282948(u16 *a0);
extern f32 func_002A7878(f32 a0, f32 a1);
extern s32 func_00283CF0(f32 a0);
extern void func_L05_00424990(void *a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5,
                              s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, f32 f12);
extern void func_L10_00425508(u8 *a0, s32 a1, s32 a2);
extern s32 func_L05_0037BBB8(u8 *a0);
extern void func_L05_0037BE98(u8 *a0);
extern void func_L05_0037AE40(u8 *a0);
extern s32 func_002E5DA0(s32 index, s32 value, u8 *object, s32 kind);

extern s32 D_L10_001B354C;

s32 func_L10_00423788(u8 *a0, s32 a1) {
    u8 *node;
    u8 *timer;
    u8 *spawned;
    s32 r = 0;

    spawned = func_002A9640(a0, 0x230000, 0);
    a0[0xA8] = 0xFF;
    node = *(u8 **)(*(u8 **)(a0 + 0x68) + 0x10);
    timer = *(u8 **)(*(u8 **)(a0 + 0x68));
    if (node != 0)
        func_002AB8C0(a0, node);
    if (*(f32 *)timer <= 0.0f)
        return 0;
    if (spawned == 0)
        return r;
    if (*(s16 *)(a0 + 0xAA) == 0xCBE &&
        (*(u8 **)(spawned + 0x20) == 0 ||
         *(s16 *)(*(u8 **)(spawned + 0x20) + 0xAA) != 0xF93))
        return r;
    if (node != 0) {
        node[7] = 0xFF;
        func_002AB800(a0, node);
    }
    *(f32 *)timer = *(f32 *)timer - *(f32 *)(spawned + 0x2C);
    if (*(s16 *)(a0 + 0xAA) != 0xB73 && *(s16 *)(a0 + 0xAA) != 0xF8E)
        func_002E5DA0(0xD, 0, a0, 0xFBF);
    if (func_00282948((u16 *)&D_L10_001B354C) != 0) {
        if (*(s16 *)(a0 + 0xAA) == 0xF8E)
            func_002E5DA0(3, 0, a0, 0xF8E);
        D_L10_001B354C = func_00283CF0(func_002A7878(10.0f, 20.0f));
    }
    if (*(f32 *)timer <= 0.0f) {
        *(f32 *)timer = 0.0f;
        func_L05_00424990(a0 + 0x10, 0, 0x32, 0x1E, 0x1E, 0x1E, 0x28, 1, 1, 0, 0, 0.5f);
        func_L10_00425508(a0, 0, 0xA);
        if (func_L05_0037BBB8(a0) != 0)
            func_L05_0037BE98(a0);
        r = 1;
        if (a1 == 0)
            func_L05_0037AE40(a0);
    }
    return r;
}
