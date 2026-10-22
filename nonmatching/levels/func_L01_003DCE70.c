/* func_L01_003DCE70 (204 bytes, 1 place, level 01, profile -O2 -G8, needs a -g8.c unit)
   -- measured 0 of 1: SIZE IS 196, retail is 204; first difference at +0x6c.

   Picks the nearest of three candidates and measures it against the hero:

     s0 = arg1;                              [ the result block ]
     s1 = *(u32 **)(arg0 + 0x68) + 0x3C4;    [ three candidate indices ]
     *(s32 *)(s0 + 0xC) = 0;                 [ the best distance so far ]
     for (i = 2; i >= 0; i--) {
         idx = *s1;
         if (idx != -1) {
             addr = D_L01_001B264C + (idx << 7) + 0x30;
             vec = *(TI128 *)addr;
             d = func_2E3650(&vec, D_00189EA0);
             if (*(f32 *)(s0 + 0xC) < d) {
                 *(TI128 *)s0 = vec;
                 *(f32 *)(s0 + 0xC) = d;
             }
         }
         s1++;
     }
     *(f32 *)(s0 + 8) = func_311A00(s0, 0, 10.0f);

   Measured: the table address must be $gp-relative (D_L01_001B264C, sda) and its
   value used in arithmetic, so this needs -G8; under -G0 the load comes out as
   lui+lw.  The prologue, the loop's shape (three rounds, the counter from 2 down),
   the hero position at D_00189EA0 and the two calls match instruction for
   instruction.  Two things are left:

   1. the candidate's address: retail computes `addu $v1,$v1,$v0` and then
      `addiu $v1,$v1,0x30` and loads `lq $v0,0x0($v1)`, i.e. it keeps the +0x30
      in the address register; this cc1 folds the +0x30 into the load's offset
      (`lq $v0,0x30($v1)`).  Writing the +0x30 as a separate statement, or
      through a pointer variable, does not change that: this cc1 always folds a
      constant offset into a TImode load.  The same difference shows in
      func_L08_0040F9D0 (see there), so the two spellings share one cause.

   2. the comparison: retail branches with a LIKELY `bc1fl` and decrements the
      loop counter in its delay slot, so the counter falls by two on the rounds
      that update the best and by none on the rounds that do not; this cc1 emits
      a plain `bc1f` and one decrement.  A likely branch needs the flow
      analysis to predict the branch as taken, which here it does not.  */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern u32 D_L01_001B264C __attribute__((sda));
extern char D_00189EA0[];
extern f32 func_2E3650(void *a0, void *a1);
extern f32 func_311A00(void *a0, s32 a1, f32 a2);

/* 128-bit copies reach lq/sq only through TImode. */
typedef int TI128 __attribute__((mode(TI)));

void func_L01_003DCE70(u8 *a0, void *a1)
{
    u32 *q;
    u32 addr;
    f32 v[4] __attribute__((aligned(16)));
    f32 d;
    s32 i;
    s32 idx;

    *(s32 *)((u8 *)a1 + 0xC) = 0;
    q = (u32 *)((u8 *)*(u32 **)(a0 + 0x68) + 0x3C4);
    for (i = 2; i >= 0; i--) {
        idx = *q;
        if (idx != -1) {
            addr = D_L01_001B264C + (idx << 7) + 0x30;
            *(TI128 *)v = *(TI128 *)addr;
            d = func_2E3650(v, D_00189EA0);
            if (*(f32 *)((u8 *)a1 + 0xC) < d) {
                *(TI128 *)a1 = *(TI128 *)v;
                *(f32 *)((u8 *)a1 + 0xC) = d;
            }
        }
        q++;
    }
    *(f32 *)((u8 *)a1 + 8) = func_311A00(a1, 0, 10.0f);
}
