/* func_L08_0040F9D0 (280 bytes, 1 place, level 08, default profile -O2 -G0)
   -- measured 0 of 1: SIZE IS RIGHT (280), first difference at +0x6c.

   Creates the measured primitive of the object, with the given bounds and
   orientation:

     m = func_31D1D8(0xE78);                 [ the new object ]
     if (m == 0) return 0;
     st = *(u8 **)(m + 0x68);               [ its state ]
     m->f30 = 0x40; m->fBC = 0; m->f95 = 0; m->f20 = 0;
     st->f18 = arg0;
     *(TI128 *)(m + 0x10) = *(TI128 *)arg1;
     *(TI128 *)st = *(TI128 *)arg2;
     st->f14 = p1 * 0.0002908882452175021f;
     st->f10 = p2 * 0.00027777778450399637f;
     v = func_3279B8(); m->fF0 = v;
     v = func_3279B8(); m->fF4 = v;
     v = func_3279B8(); m->fF8 = v;
     r = func_3AE870(m + 0x10, 0);
     st->f1C = r;
     if (r == 0) { func_2B71F0(&D_L08_001B14F0); func_31D540(m); m = 0; }
     return (s32)m;

   Measured: the size is right and everything from the third call on matches
   instruction for instruction - the three calls without an argument, the three
   stores, the failure path, the return of the object pointer.  What is left is
   the two 16-byte copies at the top and the order of the float constants:

   1. retail keeps the destination of the first copy in a register of its own
      (`addiu $s1,$s2,0x10` and then `sq $v0,0x0($s1)`), this cc1 folds the
      +0x10 into the store's offset (`sq $v0,0x10($s2)`).  The second copy, to
      the state pointer, matches (`sq $v0,0x0($s0)`), so the difference is only
      there where the address is computed from another pointer.  A pointer
      variable, a typed pointer and an inline expression all fold the same way;
      see func_L01_003DCE70, which fails the same way.

   2. the scheduler: retail keeps the four lq/sq together and materialises the
      two float constants after them; this cc1 interleaves the constants with
      the copies (the lui/ori/mtc1 of the first constant lands between the two
      lq's).  Writing the products into locals first does not change it.  */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern s32 func_31D1D8(s32 size);
extern f32 func_3279B8(void);
extern s32 func_3AE870(void *a0, s32 a1);
extern void func_2B71F0(void *a0);
extern void func_31D540(void *a0);
extern u8 D_L08_001B14F0[];

/* 128-bit copies reach lq/sq only through TImode. */
typedef int V4 __attribute__((mode(TI)));

s32 func_L08_0040F9D0(void *a0, void *a1, void *a2, f32 p1, f32 p2)
{
    u8 *m;
    u8 *p;
    u8 *st;
    f32 v;
    s32 r;

    m = (u8 *)func_31D1D8(0xE78);
    if (m != 0) {
        st = *(u8 **)(m + 0x68);
        p = m + 0x10;
        *(u8 *)(m + 0x30) = 0x40;
        *(u8 *)(m + 0xBC) = 0;
        *(u8 *)(m + 0x95) = 0;
        *(u8 *)(m + 0x20) = 0;
        *(u32 *)(st + 0x18) = (u32)a0;
        *(V4 *)p = *(V4 *)a1;
        *(V4 *)st = *(V4 *)a2;
        *(f32 *)(st + 0x14) = p1 * 0.0002908882452175021f;
        *(f32 *)(st + 0x10) = p2 * 0.00027777778450399637f;
        v = func_3279B8();
        *(f32 *)(m + 0xF0) = v;
        v = func_3279B8();
        *(f32 *)(m + 0xF4) = v;
        v = func_3279B8();
        *(f32 *)(m + 0xF8) = v;
        r = func_3AE870(p, 0);
        *(u32 *)(st + 0x1C) = r;
        if (r == 0) {
            func_2B71F0(D_L08_001B14F0);
            func_31D540(m);
            m = 0;
        }
    }
    return (s32)m;
}
