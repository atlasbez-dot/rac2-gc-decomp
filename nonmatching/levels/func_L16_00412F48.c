/* func_L16_00412F48 (356 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 396 bytes against retail's 356; the body is understood but the two
   16-byte buffers, the stack-passed argument and the register allocation are not.
   check.py (16_snivelak), with the source below:
     16_snivelak: 396 bytes, expected 356
   What is measured and right:
   - the loop runs twice (`slti $v1,$s1,0x2`) and builds a 16-byte record whose
     third word is a float: the record is zeroed with `por $v0,$zero,$zero` and
     `sq $v0,0x20($sp)`, the float is written with `swc1 $f0,0x28($sp)` and the
     record is copied to the call's stack argument area with `lq`/`sq` at +0x10.
   - the call func_0029FCC0 takes the handle, the loop index and the frame pointer
     (`daddu $a2,$sp,$zero`), and its 16-byte argument travels on the stack.
   - the three func_002BAE50 calls take eight arguments (a0-a3 and t0-t3) and the
     last two are the constant -10 and 1.
   - the branch on the flag at 0x1B2648 picks between two func_002A7820 calls; the
     "flag set" path skips the middle func_002BAE50 call, so the third pair is
     outside the if/else and the flag path branches over the else body.
   Not matched: the $gp float load (`lwc1 $f12,0x28B0($gp)`) needs a -G8 unit that
   also carries -mno-split-addresses, and this source's frame keeps eight callee-
   saved registers against retail's three.
   Next idea: the two 16-byte records are a union of a `mode(TI)` value and a
   struct with a float in its third word, and the stack argument of func_0029FCC0
   is that union passed by value. */

typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int s32;

typedef float f32;

typedef int TI128 __attribute__((mode(TI)));

extern float D_L16_001B18A0 __attribute__((sda));

extern float D_L16_001B18A4[];

extern u32 D_L16_001B18A8[] __attribute__((sda));

extern u32 D_L16_001B18C0[] __attribute__((sda));

extern u32 D_L16_001B2648[];

extern u32 D_L16_001B18AC[];

extern u32 D_L16_001B18B0[];

extern u32 D_L16_001B18B4[];

extern u32 D_L16_001B18C4[];

extern u32 D_L16_001B18B8[];

extern u32 D_L16_001B18BC[];

extern u32 D_L16_001B18C8[];

extern void func_0029FCC0(void *, s32, void *, TI128);

extern float func_002A7878(float, float);

extern s32 func_002A7820(s32, s32);

extern void func_002BAE50(void *, void *, u32, s32, s32, s32, s32, s32);

/* Feeds the handle's measured pair to the level's two tables once per frame. */
void func_L16_00412F48(u8 *arg0)
{
    TI128 tmp;
    f32 f;
    s32 i;
    s32 v;

    i = 0;
    do {
        tmp = 0;
        f = func_002A7878(D_L16_001B18A0, *(f32 *)D_L16_001B18A4);
        f = f * 0.016666668f;
        *(f32 *)((u8 *)&tmp + 8) = -f;
        func_0029FCC0(arg0, i, (void *)&tmp, tmp);
        if (D_L16_001B2648[0] & 1) {
            v = func_002A7820(0x12, 0x16);
            func_002BAE50((void *)&tmp, (void *)&tmp, D_L16_001B18A8[0], D_L16_001B18AC[0], v,
                          D_L16_001B18C0[0], -0xA, 1);
        } else {
            v = func_002A7820(0x14, 0x18);
            func_002BAE50((void *)&tmp, (void *)&tmp, D_L16_001B18B0[0], D_L16_001B18B4[0], v,
                          D_L16_001B18C4[0], -0xA, 1);
        }
        v = func_002A7820(0xA, 0xF);
        func_002BAE50((void *)&tmp, (void *)&tmp, D_L16_001B18B8[0], D_L16_001B18BC[0], v,
                      D_L16_001B18C8[0], -0xA, 1);
        i++;
    } while (i < 2);
}
