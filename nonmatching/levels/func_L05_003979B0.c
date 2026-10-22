/* func_L05_003979B0 (380 bytes, 4 places) -- NEAR MISS, not integrated.
   state: 388 bytes, the body is recovered: the lookup, the header stores, the 128-bit copy,
   the three vector calls and the two colour calls are all in retail's order; what is left is
   the register allocation and the schedule around the float constants.
   check.py (05_feltzin_system), with the source below:
     003979A8  lw    $v0, 0x68($s3)       |  lw    $v0, 0x68($s3)
     003979AC  sw    $s1, 0x24($s0)       |  sw    $s4, 0x20($s0)   <- arg3 and arg0 swapped
     003979B0  lui   $at, 0x3C88          |  lui   $at, 0x3C88
     003979B4  ori   $at, $at, 0x8889     |  ori   $at, $at, 0x8889
     003979B8  mtc1  $at, $f1            |  mtc1  $at, $f0        <- the constant lands in $f0
   What is measured and right:
   - the file must build at -O2 -G8 -ffunction-sections -frac2-qcopy
     (src/levels/shared/L05_0037BC08-g8.c): the 128-bit copy needs the grouped quadword
     copy, and -G8 is what keeps the three $gp constants at $gp-0x42C, $gp-0x420 and
     $gp-0x424 (0x1AEBC4, 0x1AEBD0, 0x1AEBDC) in the small data area.
   - the lookup's argument is selected by a branch, not by a select: retail has
     `beqz $s1,L1 ; addiu $a0,0x1173 ; addiu $a0,0x12D8 ; jal`, so the two ids must be
     the arguments of two calls that the tail merge joins; a ternary or an if/else on the
     id itself comes out as the branchless `movn`.
   - the header stores keep retail's order only when they are volatile; without volatile
     the compiler emits them in the reverse order.
   Tried and not enough: the multiply by 1/60 before and after the conversion call (before
     it the frame grows to 0x60 and a seventh saved register appears); the 1/60 constant as
     a separate temporary; the stores volatile and not.
   Next idea: a lever that keeps the frame at 0x50 while the multiply sits in the call's
   delay slot, and one that pins the argument registers ($s5 = arg0, $s4 = arg3). */

typedef int TI128 __attribute__((mode(TI)));

extern float D_L05_001AEBC4 __attribute__((sda));
extern float D_L05_001AEBD0 __attribute__((sda));
extern int D_L05_001AEBDC __attribute__((sda));

extern int func_0029EFD0(int);
extern int func_00283CF0(float);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern void func_L00_003F26C8(char *, char *);

/* Fills the object the game hands out: it takes the caller's sixteen bytes, sets the
   header, and lays the two vector calls and the two colour calls over the result. */
char *func_L05_003979B0(char *arg0, char *arg1, char *arg2, char *arg3, char *arg4)
{
    char *s0;
    char *s3;
    float f20;
    float f21;
    float f0;

    if (arg4 != 0)
        s3 = (char *)func_0029EFD0(0x12D8);
    else
        s3 = (char *)func_0029EFD0(0x1173);
    if (s3 != 0) {
        *(volatile unsigned char *)(s3 + 0x20) = 1;
        *(volatile unsigned char *)(s3 + 0x31) = 1;
        *(volatile unsigned char *)(s3 + 0x30) = 0xFF;
        s0 = *(char **)(s3 + 0x68);
        *(volatile unsigned short *)(s3 + 0x32) = 0x1FF;
        f20 = D_L05_001AEBC4;
        *(int *)(s0 + 0x24) = (int)arg4;
        f21 = 1.0f;
        *(int *)(s0 + 0x18) = func_00283CF0(D_L05_001AEBD0);
        f20 = f20 * 0.016666667f;
        f0 = 1.0f / D_L05_001AEBD0;
        *(int *)(s0 + 0x28) = D_L05_001AEBDC;
        *(int *)(s0 + 0x10) = (int)arg2;
        *(int *)(s0 + 0x20) = (int)arg3;
        *(int *)(s0 + 0x14) = 0;
        *(float *)(s0 + 0x1C) = f0;
        func_L00_003F26C8(arg0, s3);
        s3 += 0xB0;
        *(TI128 *)(s3 + 0x10) = *(TI128 *)arg0;
        *(float *)(s3 + 0x2C) = *(float *)(s3 + 0x2C) * 0.5f;
        func_00282F20(s0, arg1, f20);
        func_00282F20(s3 + 0xC0, s0, f21);
        func_00282DD8(s3 + 0xD0, s3 + 0xC0, arg3 + 0xE0);
        func_00282F20(s3 + 0xD0, s3 + 0xD0, f21);
        func_00282DD8(s3 + 0xE0, s3 + 0xD0, s3 + 0xC0);
    }
    return s3;
}
