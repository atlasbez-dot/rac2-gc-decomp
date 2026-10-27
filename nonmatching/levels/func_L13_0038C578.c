/* Near miss, not linked. Level 13 function func_L13_0038C578 (416 bytes, 1 place),
   profile -O2 -G8 -ffunction-sections (sibling L13_00306F38-g8.c).

   Last verdict: `python scratch\wslcmp.py src/levels/13_boldan/L13_00306F38-g8.c
   func_L13_0038C578 full` -> 416 bytes, expected 416; "instruction at +0x12c differs".

   Every instruction matches except the order of the four loads that set f12 (the
   small-data float at 0x1AEBF0), f13 (absolute float 0x1AEBF4) and f14 (absolute float
   0x1AEBF8) for func_L01_0031A278. Retail is lui at;lwc1 f14 / addiu a1 / lwc1 f12(gp) /
   lui at;lwc1 f13 / jal / daddu a0; this C produces lui at;lwc1 f14 / addiu a1 /
   lui at;lwc1 f13 / daddu a0 / jal / lwc1 f12, i.e. the same eight instructions with the
   f12 load and the a0 setup one slot apart. The two absolute floats must be `volatile`
   (that is the only declaration form measured to give `lui at;lwc1` and `lui at;lwc1`
   rather than a base register); 0x1AEBF4/0x1AEBF8 are absolute while 0x1AEBF0 is
   $gp-relative. The switch on a0[0x20], the ten-argument func_L00_0032A258 call, the 12-argument
   func_0032C700 call with two floats, the 0x30-byte frame (0x20 outgoing + 0x10 float
   buffer + 0x20 saves) and the final func_0029F338 call all match. */

typedef unsigned char u8;
typedef int s32;
typedef float f32;

extern f32 D_L13_001AEBF0 __attribute__((sda));
extern f32 D_L13_001AEBD0 __attribute__((sda));
extern f32 D_L13_001AEBC8 __attribute__((sda));
extern f32 D_L13_001AEBC0 __attribute__((sda));
extern volatile f32 D_L13_001AEBF4;
extern volatile f32 D_L13_001AEBF8;
extern s32 func_002A9640(u8 *, s32, s32);
extern s32 func_002A7750(u8 *, s32, s32);
extern s32 func_0029F338(u8 *);
extern void func_L00_0033E220(float, float, void *, u8 *, s32, s32, s32, s32, s32, s32);
extern void func_L00_0032A258(void *, void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0031A278(u8 *, f32 *, f32, f32, f32);
extern void func_0032C700(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                        float, float);

void func_L13_0038C578(u8 *a0) {
    s32 *s1 = *(s32 **)(a0 + 0x68);

    switch (a0[0x20]) {
    case 0:
        func_L00_0033E220(210000.0f, 0.75f, &D_L13_001AEBF0, a0, 0x50204040, -1, 1, -1, 0, -1);
        func_002A7750(a0, 1, -1);
        break;
    case 1:
        if (func_002A9640(a0, 0x4010000, 0) != 0 && *s1 == 0)
            func_002A7750(a0, 2, -1);
        a0[0xA8] = 0xFF;
        break;
    case 2: {
        f32 buf[4];
        func_L00_0032A258(a0, &D_L13_001AEBD0, &D_L13_001AEBC8, &D_L13_001AEBC0,
                    0xFFFF, 0, -1, 0, 0xFFFF, 0xFF, 0);
        {
            f32 first = D_L13_001AEBF8;
            f32 x = D_L13_001AEBF0;
            f32 second = D_L13_001AEBF4;
            func_L01_0031A278(a0, buf, x, second, first);
        }
        func_0032C700(buf, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 1, 1, 0, 0, 0.3f, 20.0f);
        func_0029F338(a0);
        break;
    }
    }
}
