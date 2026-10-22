/* func_002E6B78 (512 bytes, boot 0x2E6B78, 28 places)
 *
 * Draft, not compiled: the body is decoded, the float work is not reproduced yet.
 *
 * The body: it takes the object pointer, calls func_282D60 with the frame and
 * the object, then calls func_283EB0 with the frame and 0xB0($sp) and the
 * constant 32.0; when the result is negative it reads a word through `$gp`
 * (-0x6440) and, when that word is not 6, it reads the halfwords at +0x20 and
 * +0x22 of the block at 0x15 2C00, subtracts a scaled value from the word at
 * 0xB0($sp) and stops when the result is not positive.  It then calls
 * func_27C878 with the constant 0.1, builds three 64-bit constants in the frame
 * and calls func_282B50 with the frame + 0x60, a `$gp` table, 0x20 and the
 * frame, calls func_282D30 with the frame + 0xA0 and the object, and reads the
 * float at +0x18 of the object.  When a word read through a global is 6 it
 * skips a call to func_002A89A8; otherwise it adds the constant 0.1 to that
 * float.  The last part is a three-iteration loop that calls func_283098 and
 * func_282CC0 per iteration with a colour built from the word at 0xB0($sp) and
 * the constant 0x808080, and stores a float at +8 of the frame's row; the loop
 * ends with func_280B90.
 *
 * The unit has to be built with -G8: the body reads a word through `$gp`
 * (-0x6440), a table through `$gp` (-0x3060 and -0x3040) and a word through a
 * global at 0x1B8BB0.
 *
 * What has to be reproduced: the order of the nine calls, the three 64-bit
 * constants built with `dsll`/`ori`, the colour table the loop fills and the
 * float in $f20.
 *
 * What would unblock it: the 64-bit constant construction (the retail builds
 * 0x800000000044 and 0xFF9000000000260 with `dsll`/`ori`) and the loop's colour
 * arithmetic.
 */
typedef float f32;

extern void func_282D60(void *, void *);
extern int func_283EB0(void *, int *);
extern void func_282B50(void *, void *, int, void *);
extern void func_282D30(void *, void *);
extern void func_283098(void *, void *, void *, int);
extern void func_282CC0(void *, void *, void *);
extern void func_280B90(void *, int, int);
extern f32 func_27C878(int);
extern void func_002A89A8(void *, int);

void func_002E6B78(void *object)
{
    int count = 0;

    func_282D60((void *)0, object);
    func_283EB0((void *)0, (int *)0);
    while (count < 3) {
        func_283098((void *)0, (void *)0, (void *)0, 0);
        func_282CC0((void *)0, (void *)0, (void *)0);
        count++;
    }
    func_280B90((void *)0, 0, 0);
}
