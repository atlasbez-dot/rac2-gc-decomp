/* from src/levels/shared/L22_0039D708-g8.c: a near miss, 344 bytes against retail's 348.
 * Needs the -G8 unit (the $gp-relative constant at 0x001AF320) to be checked again.
 *
 * tools/check.py func_L22_003A4490 --diff:
 *   22_dobbo_orbit: 344 bytes, expected 348
 *   23_damosel_orbit: 344 bytes, expected 348
 *   func_L22_003A4490: 0 of 2 places match (src/levels/shared/L22_0039D708-g8.c)
 *
 * What is left, from the diff:
 *  - the three type/state tests are plain branches where retail has the likely form
 *    (bnel at 0x003A44B8, beql at 0x003A44D0, bnel at 0x003A4534/0x003A4570);
 *    retail's likely slots carry a reload of the 0x444 pointer, C's carry a nop;
 *  - retail loads the state byte before it materialises 0xFE, C does the opposite;
 *  - in the second block C keeps the 0x448 pointer in $s0 where retail keeps it in $a1.
 * The frame, the two callee-saved registers, the call sequence and the float copy
 * already agree.
 */
extern void func_00316B30(void *, int, void *);
extern void func_003290C0(void *, void *, int, int);
extern void func_002F3F40(void *, void *, void *);
extern void func_002F3A80(void *, void *);
extern float D_L22_001AF320 __attribute__((sda));

/* Hands the orbit's own state to the three objects the object points at, each
 * of them only when it is of the kind that wants it. */
void func_L22_003A4490(char *a0) {
    char *s1 = a0;
    char *s0 = *(char **)(s1 + 0x68);
    char buf[16];

    {
        char *a1 = *(char **)(s0 + 0x440);
        if (a1 != 0 && *(short *)(a1 + 0xAA) == 0xE0A) {
            a1 = *(char **)(s0 + 0x444);
            if (*(unsigned char *)(a1 + 0x20) == 0xFE) goto L2;
            if (*(unsigned char *)(a1 + 0x20) == 0xFD) goto L2;
            if (*(unsigned char *)(a1 + 0x43) >= 1 &&
                *(unsigned char *)(a1 + 0x43) <= 3) {
                goto L316;
            }
            if (*(short *)(s0 + 0x460) == 0) {
                goto L329;
            }
        L316:
            func_00316B30(s1, 1, a1 + 0x10);
            goto Lcopy;
        L329:
            func_003290C0(s1, a1, 1, 0);
        Lcopy:
            *(float *)(*(char **)(s0 + 0x440) + 0x48) = *(float *)(s1 + 0x48);
        }
    }
L2:
    {
        char *a1 = *(char **)(s0 + 0x444);
        if (a1 != 0 && *(short *)(a1 + 0xAA) == 0xE0C) {
            a1 = *(char **)(s0 + 0x448);
            if (*(unsigned char *)(a1 + 0x20) == 0xFE) goto L4;
            if (*(unsigned char *)(a1 + 0x20) == 0xFD) goto L4;
            func_003290C0(s1, a1, 5, 0);
        }
    }
L4:
    {
        char *a1 = *(char **)(s0 + 0x448);
        if (a1 != 0 && *(short *)(a1 + 0xAA) == 0xF8F) {
            if (*(unsigned char *)(a1 + 0x20) == 0xFE) goto L_end;
            if (*(unsigned char *)(a1 + 0x20) == 0xFD) goto L_end;
            if (!(*(unsigned short *)(s1 + 0x34) & 1)) {
                func_003290C0(s1, a1, 5, 0);
                func_002F3F40(buf, &D_L22_001AF320, a1 + 0xC0);
                func_002F3A80(a1 + 0x10, buf);
            }
        }
    }
L_end:
    ;
}
