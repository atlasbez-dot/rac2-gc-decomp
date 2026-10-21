/* 0 of 1 places match - last line: 09_dobbo: instruction at +0x20 differs (212 bytes, retail 212)
   Advances the sub-object's 0x384 counter by half a step and, when it passes
   one, clears it; then it adds the step to the alpha byte of each of the
   level's colour entries.  Needs $gp (the entry count at gp+0x21E8), so it
   belongs in L09_002F8BA0-g8.c.

   Measured with -O2 -G8 -ffunction-sections: the first 0x50 bytes are retail's
   word for word - the half step, the call to func_00283CF0, the `c.le.s`
   against 1.0f and the `sw $zero` that clears the counter (this cc1 writes a
   zero float as `sw $zero`, retail's form) - and the rest differs.
   What differs: the loop.  Retail walks two tables with pointers ($t0 at
   0x2A27A0 and $t1 at 0x2A2658, each +4 per iteration) and counts the
   entries down in $a3, with the guard `blez` before the loop; this cc1 keeps
   the index in $t1 and compares it with the count at the bottom of the loop.
   The `and $a1,$a1,$t2` that masks the colour with 0xFFFFFFFF is missing as
   well: this cc1 folds every spelling of a 32-bit mask away, so the colour
   keeps its own bits.
   Tried (about four compiles): the index form and explicit pointer walks, a
   do-while with the count decremented, the mask written as 0xFFFFFFFF,
   0xFFFFFFFFL, 0xFFFFFFFFUL and through a long, and the mask in a signed, an
   unsigned and a 64-bit variable; no spelling keeps the mask, and the loop
   only changes shape with the pointer form, which then grows the body.
   Would unblock: the source's own spelling of the colour mask (a 64-bit
   constant the front end does not fold but the backend narrows) and a loop
   form that counts down over two walked tables. */
extern int D_L09_001B11D8 __attribute__((sda));
extern int D_002A2658[];
extern int D_002A27A0[];
extern int func_00283CF0(float);

void func_L09_003FE2D8(unsigned char *a0) {
    unsigned char *s0 = *(unsigned char **)(a0 + 0x68);
    float *pf = (float *)(s0 + 0x384);
    float v = *pf + 0.5f;
    int r;
    int *p0 = D_002A27A0;
    int *p1 = D_002A2658;
    int n;
    *pf = v;
    r = func_00283CF0(v);
    if (*pf >= 1.0f)
        *pf = 0.0f;
    n = D_L09_001B11D8;
    if (n > 0) {
        do {
            int a2 = *p0;
            if (a2 != 0) {
                int a1;
                a2 += r;
                a1 = *p1;
                if (a2 < 0x91)
                    a2 -= 0x80;
                a1 = a1 & 0xFFFFFFFFL;
                *p0 = a2;
                if (a2 < 0x51)
                    a2 = 0xA0 - a2;
                a1 = a1 | (a2 << 24);
                *p1 = a1;
            }
            p0++;
            p1++;
        } while (--n);
    }
}
