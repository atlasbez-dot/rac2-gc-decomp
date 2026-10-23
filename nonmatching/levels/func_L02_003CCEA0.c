/* func_L02_003CCEA0 (level 02, 328 bytes) -- NEAR MISS, not integrated.
   state: 356 bytes against retail's 328; tools/check.py: 0 of 2 places match
   (02_maktar_nebula, 15_gorn).

   the body (all of it decoded):
   - the object's own 16-byte vector is copied to the frame's +0x10 and its third float is
     raised by one;
   - the kind byte at +0x20 of the object picks the direction: on 0x0B the shared helper
     func_00282CF0 gets the kind's block at +0x360, otherwise the zero vector D_00189F00 (the
     boot's, at 0x189F00), and the helper's result is the vector at the frame's +0x00;
   - func_002AFDD8 then runs with the object, the same source vector and the result;
   - the first of the two angles is func_00283248(result.x, result.y); out of the range
     +/-pi/4 it is clamped, stored at +0x278 of the kind's block and the helper
     func_00282E20 is called with the result vector; in the range nothing is stored;
   - the second angle is -func_00283248(result.x, result.z) (the first angle is not its
     argument), clamped to +/-pi/6 and stored at +0x2F4 of the kind's block.

   what still differs:
   - the frame: the retail keeps the object in $s0 and the kind's block in $s1 and rematerialises
     the two addresses of the frame's vectors (the `daddu $a0,$sp,$zero` and the
     `addiu $a2,$sp,0x10` of its calls); this cc1 keeps the addresses in callee-saved
     registers and needs three of them;
   - the two calls of the 0x0B branch: the retail hands the second one the same pointer
     (the kind's block at +0x360) that the first one got, and it keeps it in $a1 over the call
     in between; this cc1 materialises the pointer twice;
   - the clamp of the first angle: the retail's `bc1tl` and `bc1f` are the shared tail of the
     two tests (one store, one call), this cc1 gives each test its own copy.

   open: the frame's two addresses and the shared tail of the first clamp.
*/

typedef int TI128 __attribute__((mode(TI)));

extern void func_00282CF0(float *, const float *, const float *);

extern void func_002AFDD8(unsigned char *, unsigned char *, unsigned char *, int);

extern float func_00283248(float, float);

extern float func_00282E20(char *);

/* The zero vector the boot keeps for the shared helper. */
extern float D_00189F00[];

void func_L02_003CCEA0(char *a0) {
    char *s0 = a0;
    char *s1 = *(char **)(s0 + 0x68);
    TI128 v[2];
    float f;

    v[1] = *(TI128 *)(s0 + 0x10);
    *(float *)((char *)&v[1] + 8) += 1.0f;
    if (*(unsigned char *)(s0 + 0x20) == 0xB) {
        func_00282CF0((float *)&v[0], (float *)(s1 + 0x360), (float *)&v[1]);
        func_002AFDD8((unsigned char *)s0, (unsigned char *)(s1 + 0x360),
                      (unsigned char *)&v[0], 0);
    } else {
        func_00282CF0((float *)&v[0], (float *)D_00189F00, (float *)&v[1]);
        func_002AFDD8((unsigned char *)s0, (unsigned char *)&v[0],
                      (unsigned char *)&v[0], 0);
    }
    f = func_00283248(*(float *)&v[0], *(float *)((char *)&v[0] + 4));
    if (f > 0.7853982448577881f) {
        f = 0.7853982448577881f;
        goto over;
    }
    if (f < -0.7853982448577881f) {
        f = -0.7853982448577881f;
        goto over;
    }
    goto after;
over:
    *(float *)(s1 + 0x278) = f;
    func_00282E20((char *)&v[0]);
after:
    f = -func_00283248(*(float *)&v[0], *(float *)((char *)&v[0] + 8));
    if (f > 0.523598849773407f)
        f = 0.523598849773407f;
    else if (f < -0.523598849773407f)
        f = -0.523598849773407f;
    *(float *)(s1 + 0x2F4) = f;
}
