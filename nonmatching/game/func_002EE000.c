/* func_002EE000 (564 bytes, boot 0x2EE000, 28 places)
 *
 * Draft, not compiled: the body is decoded, the float work is not reproduced yet.
 *
 * The body: it takes the owner pointer, asks func_002ED688 for the object and
 * returns when there is none.  It calls func_002EE6A8 on the owner and leaves
 * when the result is 8, calls it again and leaves when the result is 9, copies
 * the 16 bytes at the object + 0x30 into the frame (`lq`/`sq`) and calls
 * func_282E20 with the object + 0x90.  It then reads the float at +0x98 of the
 * object, calls func_283248 with it, stores the negated result at +0x34 and
 * +0x38 of the object, calls func_283248 again with the float at +0x90 and
 * +0x94, calls func_283BE0 with the result and the float at +8 of the frame,
 * compares it with zero, and calls func_283C80 with the value at +0x38 of the
 * object.  It calls func_002EE6A8 twice more (the results 2 and 0xC are
 * tested) and then does a long float expression with the constants 0x1B4F4AB,
 * 0x3F7AE148, 8.0 and a `$gp` constant, storing the result in the object.
 *
 * The unit has to be built with -G8: the body reads float constants through
 * `$gp` (-0x2DAC and the ones the clamp uses).
 *
 * What has to be reproduced: the seventeen calls in the retail's order, the
 * three `lq`/`sq` copies, the float expression tree that keeps $f20 and $f21
 * alive across the calls, and the two float branches (`bc1f` and `bc1tl`).
 *
 * What would unblock it: the float expression tree and the clamp's branch
 * shape, as in func_002EE238.
 */
typedef float f32;

extern int func_002ED688(unsigned char *);
extern int func_002EE6A8(unsigned char *);
extern void func_282E20(void *);
extern f32 func_283248(f32, f32);
extern f32 func_283BE0(f32, f32);
extern f32 func_283C80(f32, f32);

void func_002EE000(unsigned char *owner)
{
    char *obj = (char *)func_002ED688(owner);
    f32 a, b;

    if (obj == 0)
        return;
    if (func_002EE6A8(owner) == 8)
        return;
    if (func_002EE6A8(owner) == 9)
        return;
    func_282E20(obj + 0x90);
    a = func_283248(*(f32 *)(obj + 0x98), 1.0f);
    *(f32 *)(obj + 0x34) = -a;
    *(f32 *)(obj + 0x38) = -a;
    b = func_283248(*(f32 *)(obj + 0x90), *(f32 *)(obj + 0x94));
    func_283BE0(b, *(f32 *)(obj + 0x38));
    func_283C80(b, *(f32 *)(obj + 0x38));
    func_002EE6A8(owner);
    func_002EE6A8(owner);
}
