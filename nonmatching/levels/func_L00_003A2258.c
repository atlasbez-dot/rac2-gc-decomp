/* Reconstruction checked 23 October 2026.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final check.py coverage: us 0/27, us2 0/27, pal 0/27.
 * Five bounded variants: tangent-pointer lifetimes, for/do loop and -g/-fno-gcse. Tangent locals reduced424 to420.
 * Remaining: Exactly420 bytes, but first vector pointer and loop index occupy s6/s5 instead of retail s5/s6.
 * Reopen with a measured ordinary-C lifetime/ABI hypothesis for that register tie.
 * Historical screening below is preserved; its blanket C/ISA claims are not acceptance evidence.
 */

/* func_L00_003A2258 - 420 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x003a2258. Screened with tools/w10_screen.py: 12 call(s)
   [func_00283CE0@003A22C8, func_00283CE0@003A22D4,
   func_L00_003A1F68@003A22EC, func_00282CC0@003A2310,
   func_00282CC0@003A2320, func_L00_003A2018@003A233C,
   func_002A7878@003A234C, func_002A7878@003A235C, func_002A7878@003A236C,
   func_00282F20@003A2388, func_00282CC0@003A239C,
   func_L00_003A2668@003A23B8]; data addresses materialised [0x3d230000];
   float constants [0xbf800000, 0x3f800000]; $gp-relative small data: no
   saves: -; callee-saved registers saved [-]; words plain C cannot emit
   [LQ/SQ 7AE20000@0x009c, LQ/SQ 7E420000@0x00a0, LQ/SQ 7BC20000@0x00a4,
   LQ/SQ 7E220000@0x00a8]. Head: addiu $sp, $sp, -0x160 ; swc1 $f22,
   0x150($sp) ; swc1 $f21, 0x148($sp) ; sd $s0, 0xF0($sp) ; sd $s1,
   0xF8($sp) ; daddu $s0, $sp, $zero. Not matched in this wave: the 128-bit
   copy needs an `lq`/`sq` pair; plain C reaches it only through a
   `mode(TI)` local, and this cc1 folds the destination offset into the `sq`
   where retail materialises the pointer first. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern float func_00283CE0(int);
extern void func_L00_003A1F68(VectorBits *, VectorBits *, VectorBits *, float);
extern void func_L00_003A2018(void *, void *, void *, void *, void *, float);
extern float func_002A7878(float, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_L00_003A2668(void *, int, void *, int);

/* Interpolate the beam's sample points and perturb them before drawing. */
void func_L00_003A2258(char *owner, void *first, void *second, char *settings)
{
    float points[11][4], left[4], right[4], noise[4];
    float (*cursor)[4] = points;
    int i = 0;
    char *leftTangent = settings + 0x50;
    char *rightTangent = settings + 0x60;
    do {
        float t = func_00283CE0(i);
        t /= func_00283CE0(9);
        func_L00_003A1F68((VectorBits *)cursor, (VectorBits *)first, (VectorBits *)second, t);
        *(VectorBits *)left = *(VectorBits *)leftTangent;
        *(VectorBits *)right = *(VectorBits *)rightTangent;
        func_00282CC0(left, left, first);
        func_00282CC0(right, right, second);
        func_L00_003A2018(cursor, first, second, left, right, t);
        noise[3] = 0.0f;
        noise[0] = func_002A7878(-1.0f, 1.0f);
        noise[1] = func_002A7878(-1.0f, 1.0f);
        noise[2] = func_002A7878(-1.0f, 1.0f);
        func_00282F20(noise, noise, 0.04f);
        func_00282CC0(cursor, cursor, noise);
        cursor++;
        i++;
    } while (i < 10);
    func_L00_003A2668(owner, 0x80, points, 11);
}
