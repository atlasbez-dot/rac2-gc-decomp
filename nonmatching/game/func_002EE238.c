/* func_002EE238 (372 bytes, boot 0x2EE238, 28 places)
 *
 * Draft, not compiled: the body is decoded, the float work is not reproduced yet.
 *
 * The body: it takes the owner pointer, asks func_002ED688 for the object and
 * returns when there is none.  It then
 *   - calls func_002EE3B0 on the owner,
 *   - calls func_282C88 on the object + 0xC0 and func_282CF0 on the object + 0x80
 *     with the owner + 0x10,
 *   - calls func_282F20 with the frame and the object + 0x80, and func_282CC0 with
 *     the object + 0xC0, the frame and the frame,
 *   - copies the 16 bytes at the object + 0x90 into the frame (an `lq`/`sq` pair),
 *   - computes (object[0x124] - 0.5 * 0.5) / 0.5 in $f20, calls func_282C48 with
 *     it and clamps the result between two $gp constants and against 0 with
 *     `bc1tl` (a branch-likely float branch),
 *   - calls func_282F20 and func_282CC0 again with the clamped value,
 *   - calls func_282DF0, compares the result with a $gp constant and, when it is
 *     smaller, calls func_282F20 with the object + 0xC0,
 *   - copies the 16 bytes at the object + 0x90 to the object + 0xA0 and calls
 *     func_282CC0 with the object + 0x90 and the object + 0xC0.
 *
 * The unit has to be built with -G8: the body reads six float constants through
 * `$gp` (-0x2DB0, -0x2DA8, -0x2DAC and the ones the clamp uses).
 *
 * What has to be reproduced: the order of the twelve calls, the three `lq`/`sq`
 * copies, the float expression tree that keeps $f20 alive across the calls, and
 * the two `bc1tl` clamps (the level 20 wave found the `bc1tl` shape to be a
 * wall: a ternary or a conditional assignment emits `c.olt.s` and a branch
 * instead).
 *
 * What would unblock it: the float expression tree, and a spelling of the clamp
 * that this cc1 turns into `bc1tl` with the value in the delay slot.
 */
typedef float f32;

extern int func_002ED688(unsigned char *);
extern int func_002EE3B0(unsigned char *);
extern f32 func_282C48(f32);
extern void func_282C88(void *);
extern void func_282CF0(void *, void *);
extern void func_282F20(void *, void *);
extern void func_282CC0(void *, void *, void *);
extern f32 func_282DF0(void *);

void func_002EE238(unsigned char *owner)
{
    char *obj = (char *)func_002ED688(owner);
    f32 scale;
    f32 value;

    if (obj == 0)
        return;
    func_002EE3B0(owner);
    func_282C88(obj + 0xC0);
    func_282CF0(obj + 0x80, owner + 0x10);
    func_282F20(obj + 0x80, obj + 0x80);
    func_282CC0(obj + 0xC0, obj + 0xC0, obj + 0xC0);
    scale = (*(f32 *)(obj + 0x124) - 0.5f * 0.5f) / 0.5f;
    value = func_282C48(scale);
    func_282F20(obj + 0x80, obj + 0x80);
    func_282CC0(obj + 0xC0, obj + 0xC0, obj + 0xC0);
    func_282DF0(obj + 0xC0);
    func_282CC0(obj + 0x90, obj + 0xC0, obj + 0xC0);
}
