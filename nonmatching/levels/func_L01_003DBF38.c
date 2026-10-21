/* func_L01_003DBF38 (316 bytes, 1 place, level 01, default profile -O2 -G0)
   -- measured 0 of 1: SIZE IS 320, retail is 316; first difference at +0x14.

   Measures the object's primitive and scatters it around the measured block:

     p = arg0 + 0x10;                          [ the object's own transform ]
     state = *(u32 **)(arg0 + 0x68);
     func_311A00(p, 0, 0.5f);
     if (func_2D77E8() != 3) return;            [ the status, not a value ]
     for (i = 0; i >= 0; i--) {
         vec = *(TI128 *)p;
         func_316348(&vec, 0.1f);
         vec[2] = func_L01_003BAFB0();
         t = func_310580(0.2f, 2.0f);
         color = ((u32)(func_3104E8(6) + 0x14) << 24) | 0x5060;
         func_32E6D8(&vec, &D_L01_001AFE18, color, t, 10000.0f);
     }
     d = func_2E35A0(state + 0x190);
     if (0.0333333f < d) func_3DBCB8(arg0, 3, 10, 1);

   Measured: the calls, their arguments, the colour's packing, the four floats
   and the tail all match; what is left is the register plan.  Retail keeps the
   object's pointer in $s0, copies it to $s3 for the loop and reuses $s0 for the
   loop counter, and puts state+0x190 in $s1 (reusing the state register); this
   cc1 keeps the pointer in $s1, the counter in $s0, state+0x190 in $s3 and
   spends a fifth callee-saved register ($s4) on the address of D_L01_001AFE18,
   which it hoists out of the loop - retail rematerialises that address inside
   the loop (`lui $a1,0x1B; addiu $a1,$a1,-0x1E8`) because all four of its
   callee-saved registers are taken.  The one free $s4 is what changes the
   allocation, so the two have to be fixed together: no spelling of the address
   (a local pointer, a pointer variable, an inline expression) stops this cc1
   from hoisting it.  */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern s32 func_311A00(void *a0, s32 a1, f32 a2);
extern s32 func_2D77E8();
extern void func_316348(void *a0, f32 a1);
extern f32 func_L01_003BAFB0(void);
extern f32 func_310580(f32 a0, f32 a1);
extern s32 func_3104E8(s32 a0);
extern void func_32E6D8(void *a0, void *a1, u32 a2, f32 a3, f32 a4);
extern f32 func_2E35A0(void *a0);
extern void func_3DBCB8(u8 *a0, s32 a1, s32 a2, s32 a3);
extern float D_L01_001AFE18;

/* 128-bit copies reach lq/sq only through TImode. */
typedef int TI128 __attribute__((mode(TI)));

void func_L01_003DBF38(u8 *a0)
{
    u8 *p;
    u8 *state;
    u8 *q;
    f32 v[4] __attribute__((aligned(16)));
    f32 t;
    f32 d;
    s32 i;
    u32 color;

    p = a0 + 0x10;
    state = *(u8 **)(a0 + 0x68);
    func_311A00(p, 0, 0.5f);
    if (func_2D77E8() != 3)
        return;
    q = state + 0x190;
    for (i = 0; i >= 0; i--) {
        *(TI128 *)v = *(TI128 *)p;
        func_316348(v, 0.1f);
        v[2] = func_L01_003BAFB0();
        t = func_310580(0.2f, 2.0f);
        color = ((u32)(func_3104E8(6) + 0x14) << 24) | 0x5060;
        func_32E6D8(v, &D_L01_001AFE18, color, t, 10000.0f);
    }
    d = func_2E35A0(q);
    if (0.033333335f < d)
        func_3DBCB8(a0, 3, 10, 1);
}
