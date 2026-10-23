/* 0 of 27 places match - last line: 00_aranos_tutorial: 80 bytes, expected 76
   Nineteen words, the right size, once `r` is initialised before the gate (that is
   what shares the single `mtc1 $zero,$f1` between the early return and the body).
   Three words stay permuted: this cc1 loads the gate into `$v1` with `$v0` as base
   (retail reuses `$v0` for both, `lw $v0,0x26B4($v0)`), puts the `mtc1 $zero,$f1`
   before that load (retail after it), and in the negative arm materialises the
   absolute store's address before the `neg.s` (retail after). Four spellings - gate
   as expression, gate as local, gate through an array, if/else - give the same three.
   The -G8 home of this body is src/levels/shared/L00_0037DD80-g8.c, where the two
   words carry `nosda` and `_1` names: 0x1B26B4 is read absolutely and written through
   $gp, 0x1B26B0 carries the float through $gp and is cleared absolutely.

   Wave 8 re-measured it with eight more spellings and the three differences are
   separate walls:
    - the `mtc1 $zero,$f1` has to come *after* the gate load in the RTL, so the
      gate has to be read before `r` is set; a `r = 0.0f` written first gives the
      `mtc1` first (as here) and a `return 0.0f` inside the gate arm gives two
      `mtc1`s (one in $f0 for the arm, one in $f1 for the delay slot) - retail has
      exactly one, in $f1, shared by the arm and the comparison;
    - retail reuses `$v0` for the `lui` and the `lw` of the gate (the base dies at
      the load); this cc1 keeps the `lui` in $v0 and puts the loaded word in $v1;
    - retail's `neg.s $f1,$f0` comes *before* the `lui` of the absolute store; this
      cc1 hoists the address `lui` above the `neg.s` in every spelling, whether
      the source writes `r = -x` before or after the store. */

typedef float f32;
typedef int s32;
typedef unsigned int u32;

extern u32 D_L00_001B26B4 __attribute__((nosda));
extern u32 D_L00_001B26B4_1;
extern f32 D_L00_001B26B0_1;
extern s32 D_L00_001B26B0 __attribute__((nosda));

f32 func_L00_0037E5F0(f32 value)
{
    f32 x;
    f32 r = 0.0f;

    if (D_L00_001B26B4 != 0)
        return r;
    x = D_L00_001B26B0_1 - value;
    D_L00_001B26B0_1 = x;
    if (x < 0.0f) {
        r = -x;
        D_L00_001B26B0 = 0;
    }
    D_L00_001B26B4_1 = 15;
    return r;
}
