/* func_L02_00401530 (level 02, 264 bytes) -- NEAR MISS, not integrated.
   state: 260 bytes against retail's 264 (this body, `-O2 -G0 -ffunction-sections`, the
   default profile of src/levels/shared/L02_003C43F0.c); with `-frac2-qcopy` in a unit of its
   own the body is 268 bytes, and the two profiles differ in what they get right (below).
   tools/check.py: 0 of 2 places match (02_maktar_nebula, 15_gorn).

   the body (all of it decoded):
   - the function creates the kind's object with func_0029EFD0(0xB5A) and returns it (a char *);
     a null object returns straight away, the two returns share one exit;
   - the object's own vector is copied to +0x10 of the new object, +0x30 gets the byte 0xFF,
     +0x2C the float 0.014999999664723873f (0x3C75C28F), +0x32 the halfword 0x00FF and +0x20
     the byte 0;
   - the block at +0x68 of the new object takes the two vectors (at +0x00 and +0x10), the word
     0x10E at +0x70, the three bytes a3, a4 and a5 at +0x75, +0x76 and +0x77, and the three
     floats at +0x64 (the third argument), +0x68 (the second) and +0x6C (the first);
   - the three bytes are the three integer arguments, and the zero-extension of them (the
     `andi $s4,$a3,0xFF` of the prologue) is the argument's own, so the parameters are
     `unsigned char` and not `int` with a mask: an `int` parameter's mask is dropped before the
     byte store, and a `char` parameter's extension is dropped with it;
   - the three floats arrive in $f12, $f13 and $f14 and are kept in $f22, $f21 and $f20 (the
     first, second and third); the order of the three float stores in the source decides that
     allocation, and the retail's order is: the word, the three bytes, then the floats at +0x68,
     +0x6C and +0x64 (the +0x64 store last). This cc1 hoists the last store to the front of the
     block, so the +0x64 store has to be the last statement of the source to come out right;
   - the frame is 0x60 with $s0 (the object), $s1, $s2 and $s3 (the three vectors) and $s4, $s5
     and $s6 (the three bytes) saved, and $f20, $f21 and $f22 saved.

   what still differs:
   - the three 16-byte copies. The retail takes both addresses in registers
     (`addiu $v1,$s0,0x10 ; lq $v0,0($s1) ; sq $v0,0($v1)`), this cc1 folds the frame offset
     into the store (`sq $v0,0x10($s0)`). `-frac2-qcopy` (the profile docs/COMPILER-NOTES.md
     qualifies for the grouped copy) gives the retail's shape, but it changes the allocation of
     the prologue: the three bytes then take $s2, $s3 and $s4 and the two vectors $s5 and $s6,
     where the retail has the vectors in $s1, $s2 and $s3 and the bytes in $s4, $s5 and $s6;
   - with `-frac2-qcopy` the two constants 0xFF are materialised twice (the retail keeps one
     register for the byte at +0x30 and the halfword at +0x32), because the delay slot of the
     `beqz` takes the copy's address instead of the constant.

   open: a source unit of its own with `-frac2-qcopy` (the flag changes every TImode copy of
   the unit, and the retail's frame wants the allocation of the profile without it) and the
   order of the statements that decides the float allocation.
*/

typedef int TI128 __attribute__((mode(TI)));

extern char *func_0029EFD0(int);

extern void func_002A0F48(void *);

char *func_L02_00401530(TI128 *a0, TI128 *a1, TI128 *a2, unsigned char a3,
                        unsigned char a4, unsigned char a5, float a6, float a7, float a8) {
    char *s0;
    char *v1;

    s0 = func_0029EFD0(0xB5A);
    if (s0 == 0)
        goto end;
    *(TI128 *)(s0 + 0x10) = *a0;
    *(unsigned char *)(s0 + 0x30) = 0xFF;
    *(float *)(s0 + 0x2C) = 0.014999999664723873f;
    *(unsigned short *)(s0 + 0x32) = 0xFF;
    *(unsigned char *)(s0 + 0x20) = 0;
    v1 = *(char **)(s0 + 0x68);
    *(TI128 *)v1 = *a1;
    *(TI128 *)(v1 + 0x10) = *a2;
    *(int *)(v1 + 0x70) = 0x10E;
    *(unsigned char *)(v1 + 0x75) = a3;
    *(unsigned char *)(v1 + 0x76) = a4;
    *(unsigned char *)(v1 + 0x77) = a5;
    *(float *)(v1 + 0x68) = a7;
    *(float *)(v1 + 0x6C) = a6;
    *(float *)(v1 + 0x64) = a8;
    func_002A0F48(s0);
end:
    return s0;
}
