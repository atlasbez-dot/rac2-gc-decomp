/* func_00335370 - near miss (4 bytes short).
 *
 * The body is recovered: the object pointer (word at +0x70, halfword at +0x86),
 * the call to func_00270280(5) when the halfword is not 5, and the 128-bit copy
 * of the argument to the field at +0x80 (the `lq`/`sq` pair).
 *
 * What is left is the `addiu $v1,$v1,0x80` that retail materialises in front of
 * the `sq`: this cc1 folds the constant 0x80 into the `sq`'s own displacement
 * (0x7C620080 instead of retail's 0x7C620000), so the candidate is four bytes
 * shorter than the 88 the catalogue expects.  The brief's measurement for this
 * cc1 says the offset only comes out materialised when the pointer is used
 * twice or the offset is a variable, and that no source spelling changes it.
 *
 * The same shape is func_003353C8 (the same function with 0x90 instead of 0x80).
 */

typedef struct {
    unsigned char pad_35370[0x70];
    void *f70_35370;
    unsigned char pad2_35370[0x12];
    short f86_35370;
} Obj_35370;

extern Obj_35370 *ref_L00_00335370_00;
extern Obj_35370 *func_00270280(s32 a0);

void func_00335370(void *a0)
{
    Obj_35370 *obj;
    void *dst;
    char *p;

    obj = ref_L00_00335370_00;
    if (obj->f86_35370 == 5)
        dst = obj->f70_35370;
    else {
        obj = func_00270280(5);
        dst = obj->f70_35370;
    }
    p = (char *)dst + 0x80;
    *(TI128 *)p = *(TI128 *)a0;
}
