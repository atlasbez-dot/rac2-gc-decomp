/* func_L14_003C96E0 (276 bytes, 1 place: 14_aranos_prison) -- NEAR MISS, not integrated.
   state: 264 bytes against retail's 276; the frame is 0x50 against 0x60 and the
   five callee-saved float registers are not allocated the way retail allocates
   them.
   check.py (14_aranos_prison), with the source below:
     003C96E0  addiu $sp,$sp,-0x50  | addiu $sp,$sp,-0x60
     003C96F4  swc1 $f22,0x40($sp)  | sd $s3,0x18($sp)
     003C9700  mov.s $f22,$f14      | swc1 $f24,0x50($sp)
   Everything else lines up: the three float parameters ($f12, $f13, $f14), the
   call to func_002A7750 (the level's 0x321F58) with 0x16 and 7, the three square
   roots (func_00282C10, the level's 0x2F5B40) of (f12 - x) * 2 over f13 and f14,
   the vector subtraction and scaling (func_00282CF0 and func_00282D30, 0x2F5C68
   and 0x2F5CC0) on the record at +0x1B0 of the object's state, the stores at
   +0x394, +0x398, +0x1B8, +0x14C and +0x3A0, and the constant 0.333f (retail
   materialises 0x3EAA7EFA, which is what this cc1 parses 0.333f to).
   What is left is the register allocation: retail keeps the three parameters in
   $f20, $f23 and $f24 and the two computed values in $f21 and $f22, this cc1
   keeps the parameters in $f20, $f21 and $f22 and the computed values in $f23 and
   a caller-saved register, so retail saves five float registers and this one
   saves four (the frame differs by 0x10).
   The allocator gives the callee-saved float registers in the order the locals
   are created, so retail's order (the first parameter, the two computed values,
   the second and third parameters) means the two computed values must be created
   before the second and third parameters are copied.  A local that is only
   assigned later is created later, so the copies of $f13 and $f14 have to come
   from variables that are assigned after the first square root -- which the
   source cannot express, because the parameters have to be copied before the
   calls that clobber them.
   Tried and not enough: the parameters used directly and copied into locals;
     the locals declared in different orders; the computed values initialised at
     their declaration; the first square root's result kept in a variable; the
     constant written as 0.333f, 0.33309978f and 0.33333334f (the last gives
     0x3EAAABAB, retail has 0x3EAA7EFA). */

extern void func_321F58();
extern float func_2F5B40(float f);
extern void func_2F5C68(void *dst, void *src, void *src2);
extern void func_2F5CC0(void *dst, void *src, float s);

void func_L14_003C96E0(char *arg0, char *arg1, float f12, float f13, float f14) {
    char *s0 = arg0;
    char *s1;
    char *s2 = arg1;
    char *s3;
    float f20;
    float f21;
    float f22;
    float f0;
    float f1;

    func_321F58(arg0, 0x16, 7);
    s1 = *(char **)(arg0 + 0x68);
    f21 = *(float *)(arg0 + 0x18);
    f21 = (f12 - f21) * 2.0f;
    func_2F5B40(f21 / f13);
    f1 = *(float *)(arg1 + 8);
    f20 = (f12 - f1) * 2.0f;
    f22 = func_2F5B40(f20 / f14);
    f22 = f22 + f22;
    s3 = s1 + 0x1B0;
    func_2F5C68(s3, arg1, arg0 + 0x10);
    func_2F5CC0(s3, s3, 1.0f / f22);
    f0 = func_2F5B40(f21 * f13);
    *(float *)(s1 + 0x394) = f13;
    *(float *)(s1 + 0x398) = f14;
    *(float *)(s1 + 0x1B8) = f0;
    *(int *)(s1 + 0x14C) = -1;
    f0 = *(float *)(arg1 + 8) + 0.333f;
    *(float *)(s1 + 0x3A0) = f0;
}
