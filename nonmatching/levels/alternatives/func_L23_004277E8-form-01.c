/* Alternative source form for func_L23_004277E8.
   Retained from v11-b2.c, entry e1; declarations preserved.
   Naming/extraction only: this form has not been recompiled or validated
   by the cleanup. See the primary near-miss file for the recorded blocker;
   do not apply another form's verdict to this one. Recheck its file-level
   flags with tools/check.py, then tools/build.py before promotion. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

extern void func_002A7750(void *, s32, s32);
extern void func_L23_004278D8(u8 *);
extern f32 D_L23_001B36FC __attribute__((sda));

extern void *func_L00_002D70A0(s32);
extern void func_L00_002D7140(void *);
extern f32 D_L02_001B1234 __attribute__((sda));
extern f32 D_L02_001B1238 __attribute__((sda));
extern f32 D_L02_001B123C __attribute__((sda));
extern f32 D_L02_001B1240 __attribute__((sda));
extern f32 D_L02_001B1244 __attribute__((sda));
extern f32 D_L02_001B1248 __attribute__((sda));
extern f32 D_L02_001B124C __attribute__((sda));
extern f32 D_L02_001B1250 __attribute__((sda));
extern f32 D_L02_001B1254 __attribute__((sda));

void func_L23_004277E8(u8 *a0) {
    u8 *s0 = a0;
    u8 *o = *(u8 **)(s0 + 0x68);
    u8 st = *(u8 *)(s0 + 0x20);

    if (st == 0) {
        *(u8 *)(s0 + 0x30) = 0xFF;
        *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) | 0x100;
        *(u8 *)(s0 + 0x32) = 0xFF;
        *(u16 *)(o + 0x24) = 0x7D0;
        *(f32 *)(o + 0x20) = 2000.0f;
        func_002A7750(s0, 1, 0);
        *(u16 *)(s0 + 0x7C) = 0x3FF;
        *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) | 0x4000;
    } else if (st == 1) {
        f32 f = D_L23_001B36FC;

        if (f != 0.0f) {
            *(f32 *)(o + 0x20) = f;
            *(s16 *)(o + 0x24) = (s16)f;
        }
        func_002A7750(s0, 2, 0);
    }
    func_L23_004278D8(s0);
}
