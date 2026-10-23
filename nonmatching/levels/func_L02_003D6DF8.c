/* func_L02_003D6DF8 (level 02, 228 bytes) -- NEAR MISS, not integrated.
   state: 252 bytes against retail's 228; tools/check.py: 0 of 2 places match
   (02_maktar_nebula, 11_joba).

   the body (all of it decoded):
   - the kind byte at +0x20 of the object decides: a non-zero byte jumps to the end, where the
     word at +0xBC of the kind's block is cleared and the halfword at +0xC0 set to -1;
   - otherwise the byte at +0x09 of the kind's block is cleared, the byte at +0x08 set to 3 and
     the word at +0x10 cleared, the halfword at +0x34 of the object has its 0x1000 bit cleared
     (the store in the delay slot of the call), and func_002A7750(object, 2, -1) runs;
   - a 16-byte vector is built: the float at D_L02_001B0380 (the level's own rate, read
     $gp-relative) times the constant 0.0002908882452175021f (0x3998825C, that is (pi/180)/60)
     goes into its first word, and the vector is handed to func_002833F0 with the destination at
     +0x80 of the kind's block;
   - then 180.0f (0x43340000) divided by the same rate, times 60.0f (0x42700000), truncated to
     a whole number, is written to D_L02_001B03D8 (the level's own counter, at 0x1B03D8 in
     level 02 and 0x1B4038 in level 11, so it needs a name of its own);
   - the halfword at +0x34 of the object gets its 0x100 bit set, then func_L02_003D6EE0(object)
     and func_L00_00323958(object, block + 0x30) run.

   what still differs:
   - the store of the truncated number: the retail writes the word the FPU holds after its
     `cvt.w.s` with a `swc1`, that is the integer's bits stored as a float, and this cc1
     expands `(float)(int)x` into `cvt.w.s` plus the round trip through a general register
     (`mfc1`, `mtc1`, `cvt.s.w`), four words against the retail's two. No plain C spelling of
     that store was found;
   - the 16-byte vector is built in the retail as a zero vector (`por $v0,$zero,$zero` and a
     `sq` to +0x10 of the frame), the float goes into it and the vector is copied to the
     frame's +0x00 before the call; this cc1 folds the copy's offset into the `sq` and keeps
     one address register across the call where the retail rematerialises it;
   - the general registers of the two calls differ (the retail keeps the object's pointer in
     $s0 and the kind's block in $s1, this cc1 gives the block $s1 and the object $s2) and the
     branch over the body takes a different offset.

   open: the store of the truncated number, and the frame's two addresses.
*/

typedef int TI128 __attribute__((mode(TI)));

extern void func_002A7750(char *, int, int);

extern void func_002833F0_2(char *, char *);

extern void func_L02_003D6EE0(char *);

extern void func_L00_00323958(void *, void *);

/* The level's own rate, read $gp-relative. */
extern float D_L02_001B0380 __attribute__((sda));

/* The level's own counter, written through its address. */
extern float D_L02_001B03D8;

void func_L02_003D6DF8(char *a0) {
    char *s0 = a0;
    char *s1 = *(char **)(s0 + 0x68);
    TI128 v[2];
    float f;

    if (*(unsigned char *)(s0 + 0x20) != 0)
        goto end;
    *(unsigned char *)(s1 + 0x9) = 0;
    *(unsigned char *)(s1 + 0x8) = 3;
    *(int *)(s1 + 0x10) = 0;
    *(unsigned short *)(s0 + 0x34) &= 0xEFFF;
    func_002A7750(s0, 2, -1);
    v[1] = 0;
    *(float *)&v[1] = D_L02_001B0380 * 0.0002908882452175021f;
    v[0] = v[1];
    func_002833F0_2((char *)(s1 + 0x80), (char *)&v[0]);
    f = 180.0f / D_L02_001B0380;
    *(unsigned short *)(s0 + 0x34) |= 0x100;
    f = (float)(int)(f * 60.0f);
    D_L02_001B03D8 = f;
    func_L02_003D6EE0(s0);
    func_L00_00323958(s0, s1 + 0x30);
end:
    *(int *)(s1 + 0xBC) = 0;
    *(short *)(s1 + 0xC0) = -1;
}
