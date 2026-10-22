/* func_L02_003C5438 (296 bytes, 8 places) -- NEAR MISS, not integrated.
   state: the body matches retail word for word, except that cc1 keeps the matrix address
   (0x1AF8F20) in a sixth callee-saved register ($s5) instead of rematerializing it at
   both call sites, so the frame is 0x60 against retail's 0x50 and four words differ:

     003C5464  sd          $s5, 0x38($sp)   | swc1        $f21, 0x48($sp)   <- ours
     003C546C  swc1        $f21, 0x58($sp)  | swc1        $f20, 0x40($sp)   <- ours
     003C54D8  daddu       $t1, $s5, $zero  | addiu       $t1, $t1, -0x70E0 <- ours
     003C552C  daddu       $t1, $s5, $zero  | addiu       $t1, $t1, -0x70E0 <- ours

   Retail loads the address into the argument register itself at both call sites; this
   cc1 keeps one copy across the call, which costs the extra register. What is left is a
   source spelling that makes the two references two separate quantities.

   What is measured and right:
   - the 0x04 constant of the second call is 0.04f: this cc1 parses `0.04f` as
     0x3D23D70A (0.039974355), which is what retail holds, not the correctly rounded
     0x3DA3D70A. Writing the decimal 0.0399743551f gives 0x3D23BC26 and does not match.
   - the matrix address is a level symbol (0x1AF8F20 in level 02) and its `lui`/`addiu`
     pair is the assembler's %hi/%lo of the symbol, so it must not be written as a number.
   - the two calls are func_002C2210(&v, a1, a2, 0, s2, MATRIX, 0, f20 * 0.3f, f20, 0.0f)
     and func_002C2210(&v, a3, a4, 1, -s2, MATRIX, 0, f20 * 0.04f, f20 * 0.4f, 0.0f).
   - the argument list of the helper is (void *, u32, u32, u32, s32, s32, s32, f32, f32,
     f32), the sixth argument being the matrix address (as in
     src/levels/shared/L03_003C5B28.c).
   - the first call of the unit is func_002A7878(a0, a1, 2.0f, 4.0f): the unit declares
     it with four parameters (the first two unused by the callee, which reads its two
     floats from f12 and f13).

   Tried and not enough: the sixth argument as an int, as a pointer (the unit's
   declaration changed to void *) and as an unsigned int; the address in a local; the
   address read again in the second call; the copy of the 16-byte argument as a TImode
   and as a struct of four floats. */

#include "include_asm.h"
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern float func_002A7878(void *, void *, float, float);
extern int func_002A77E0(int);
extern void func_002C2210(void *, u32, u32, u32, s32, s32, s32, f32, f32, f32);
extern char D_L02_001AF8F20[];

void func_L02_003C5438(void *a0, void *a1, void *a2, void *a3, void *a4)
{
    TI128 v;
    float f20;
    float f21 = 0.0f;
    int s2;

    v = *(TI128 *)a0;
    f20 = func_002A7878(a0, a1, 2.0f, 4.0f);
    s2 = func_002A77E0(2);
    if (s2 == 0)
        s2--;
    func_002C2210(&v, (u32)a1, (u32)a2, 0, s2, (s32)D_L02_001AF8F20, 0, f20 * 0.3f, f20, f21);
    if (a3 != 0 && a4 != 0)
        func_002C2210(&v, (u32)a3, (u32)a4, 1, -s2, (s32)D_L02_001AF8F20, 0,
                      f20 * 0.04f, f20 * 0.4f, f21);
}
