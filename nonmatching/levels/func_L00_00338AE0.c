/* 0 of 22 places match - last line: 00_aranos_tutorial: instruction at +0x4 differs.
   The record template, the two sixteen-byte copies, the tag word, the flag bytes, the
   quantised height and the two level-derived fields are understood and transcribed; the
   quadword-copy profile (-frac2-qcopy with -frac2-qcopy-barrier) reproduces the retail's
   register-addressed copies exactly, as it does for func_L00_00338D28 and
   func_L00_0033BA68.

   What is left is one register choice, and it cascades: retail keeps the first argument
   in $s0 and the allocated record in $s1 (daddu $s0,$a0 / daddu $s1,$v0), this cc1 keeps
   the record in $s0 and the first argument in $s1. The two copies then follow: retail
   computes the second destination as obj+0x20 into the now-dead $s0 (addiu $s0,$s1,0x20,
   early, in the delay slot of the func_002A77E0 call), this cc1 computes it late into
   $a2 (a caller-saved register). Every other word of the 288 bytes is identical.

   Measured without moving it: the source order of the copies, the copies written as raw
   pointer casts, the destination pointer named in a local (in the block, before the
   branch and inside it), the record pointer named in a second local, the float and the int
   parameters swapped in the signature (the ABI is the same), the constant on the left of
   the multiplication, the intermediate float declared in the block, -O1, -O3,
   -fno-schedule-insns, -fno-schedule-insns2, -fno-crossjumping and every -frac2-* switch.
   The allocation order of the saved registers is what differs: retail allocates the
   argument, the record, the second argument and the third in that order, this cc1
   allocates the record first (its live range is the longest). A lever that orders the
   record's pseudo after the argument's, or that splits the record's live range at the
   calls, would unblock it.

   The level's flag-byte pointer sits at 0x001FE9F8 in level 00 and at a different
   address in every other level, so it is a per-level symbol: ref_L00_00338AE0_00. */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;
typedef int V4 __attribute__((mode(TI)));

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u32 w4;
    u8 b8;
    u8 b9;
    u16 s_a;
    f32 f_c;
    V4 v10;
    V4 v20;
    f32 f30;
    f32 f34;
    s32 i38;
} Obj_L00_00338AE0;

extern void *func_002B9030(s32 kind);
extern s32 func_002A77E0(s32 limit);
extern s32 func_00283CF0(f32 value);
extern f32 func_002A7878(f32 a, f32 b);
extern unsigned char *ref_L00_00338AE0_00;

Obj_L00_00338AE0 *func_L00_00338AE0(char *src1, char *src2, s32 a2, f32 value, f32 value2)
{
    Obj_L00_00338AE0 *o = (Obj_L00_00338AE0 *)func_002B9030(0x2E);
    f32 r;

    if (o != 0) {
        o->v10 = *(V4 *)src1;
        o->w4 = ((func_002A77E0(10) + 0x26) << 24) | 0x00808080;
        o->b9 = func_00283CF0(1.0f) + 0x20;
        o->b3 = 0x48;
        o->b1 = 1;
        o->s_a = 5;
        o->b2 = *ref_L00_00338AE0_00;
        o->f_c = value * 210000.0f;
        o->v20 = *(V4 *)src2;
        r = func_002A7878(0.0f, 256.0f);
        o->f30 = r;
        o->b8 = func_00283CF0(r);
        o->i38 = a2;
        o->f34 = value2;
    }
    return o;
}
