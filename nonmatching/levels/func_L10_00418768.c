/* Near miss; game compiler, -O2 -G0 -ffunction-sections (src/levels/10_hrugis_cloud/L10_003170D0.c).
   us: 10_hrugis_cloud: 500 bytes, expected 508; func_L10_00418768: 0 of 1 places match.
   The body reconstructs the object's whole update. Everything matches up to +0x128
   (prologue, the wake-up half, the effect teardown and the func_0037D7A0 call). The
   residual is the tail: retail materialises -1 a third time (addiu $v0,$zero,-1 at
   +0x134) and reaches the record lookup with `bnel ... ; lw $v0,0x26C($s2)` in the
   delay slot, where this C gets `bne ... ; addiu $v0,$zero,-1` plus `beq` and is two
   instructions (8 bytes) short. Tried: literal `!= -1`, `-1 !=`, and a local `one = 1`
   that reproduces retail's `addiu $s0,$zero,1` register (needed for the whole
   prologue to line up); moving the -1 store and func_003737B8 inside the
   `func_0037D390(...) == 1` block (also required). 176.0f is the float at +0x90
   (lui $at,0x4330). Reopen with the original statement order that makes the
   scheduler put the 0x26C load in the likely-branch delay slot. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_001B251C;
extern u8 D_L10_00188660[];
extern u8 D_L10_00418968[];

extern s32 func_0037B670(u8 *arg0);
extern void func_L10_004189D8(u8 *arg0);
extern void func_00308AF8(u8 *a0);
extern void func_0037BC48(u8 *arg0, s32 a1, s32 a2, s32 a3);
extern u8 *func_0037BA88(u8 *arg0);
extern void func_0037DFB8(u8 *a0);
extern s32 func_0037D390(u8 *arg0, s32 a1, s32 a2, s32 a3);
extern void func_00373410(s32 a0);
extern s32 func_003737B8(s32 a0, s32 a1, u8 *a2, s32 a3);
extern void func_0037D7A0(u8 *a0, s32 a1, f32 f12);
extern void func_L10_00418AD8(u8 *arg0);
extern s32 func_0037D6E0(u8 *a0);
extern void func_0037D528(u8 *a0);
extern void func_003087A0(u8 *a0);
extern void func_L10_00418BA0(u8 *arg0);

void func_L10_00418768(u8 *arg0) {
    u8 *s2 = *(u8 **)(arg0 + 0x68);
    u8 *s3;
    u8 *p;
    s32 id;
    s32 tmp[4];
    s32 one;

    if (arg0[0x20] == 0) {
        arg0[0x30] = 0xFF;
        if (func_0037B670(arg0) == 0)
            return;
        func_L10_004189D8(arg0);
        func_00308AF8((u8 *)tmp);
        if (*(u32 *)(s2 + 0x264) == 0)
            return;
        func_0037BC48(arg0, (s32)D_L10_00418968, 0, 0);
        return;
    }
    s3 = (u8 *)func_0037BA88(arg0);
    if (*(u32 *)(s3 + 0x110) == 0)
        return;
    func_0037DFB8(arg0);
    one = 1;
    if (func_0037D390(arg0, 0, 0, 0) == one) {
        id = *(s32 *)(s2 + 0x26C);
        if (id != -1) {
            p = D_L10_00188660 + id * 0x70;
            if (*(u8 **)(p + 0x88) == arg0 && *(u8 *)(p + 0x74) != 0)
                func_00373410(id);
        }
        *(s32 *)(s2 + 0x26C) = -1;
        func_003737B8(2, 0, arg0, 0xF8E);
    }
    func_0037D7A0(arg0, 0, 176.0f);
    if (*(u32 *)(s3 + 0x110) == 1) {
        if (*(s32 *)(s2 + 0x260) != -1) {
            *(u32 *)(s3 + 0x11C) = *(u32 *)(s3 + 0x110);
            *(u32 *)(s3 + 0x120) = (u32)D_001B251C + (*(u32 *)(s2 + 0x260) << 8);
        }
        if (*(u32 *)(s3 + 0x104) != 0)
            func_L10_00418AD8(arg0);
    }
    if (func_0037D6E0(arg0) != 0)
        func_0037D528(arg0);
    func_003087A0(s2 + 0x268);
    func_L10_00418BA0(arg0);
    p = D_L10_00188660 + *(s32 *)(s2 + 0x26C) * 0x70;
    if (*(u8 **)(p + 0x88) != arg0 || *(u8 *)(p + 0x74) == 0)
        *(s32 *)(s2 + 0x26C) = func_003737B8(0, 6, arg0, 0xF8E);
}
