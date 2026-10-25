/* Near miss: the straight-line tuning-block filler is 512 bytes against retail's 520 in the
   plain -O2 -G0 profile, and 520/520 with the body's field reads split as here. What differs:
   retail materialises both 16-byte-copy addresses (`addiu $a0,$s1,0x10`, `addiu $v1,$s0,0x300`)
   before the lq/sq where this cc1 folds the offsets into the lq/sq; the small integer constants
   land in different argument registers ($a2/$a0/$a1 against $a3/$a1/$a2); and the scheduler puts
   the two constant loads for func_002A7878 ahead of the register saves here. The two calibrated
   literals are 1.333f (0x3FAA9FBE) and 0.17453295f (0x3E32B8C4); 1.3332518f and
   0.17453297972679138f are the usual wrong spellings. The -0x344 field is re-read from memory
   after the call, so the source stores it and reads the field back. */

extern float func_002A7878(float, float);
extern int func_00283CF0(float);
extern void func_002A78D8(float, float);
extern float func_002A7940(void);
extern void func_002A7750(char *, int, int);
extern void func_002A7470(char *, int, int, int);
extern float D_L09_001B13F4 __attribute__((sda));

typedef int TI128 __attribute__((mode(TI)));

/* Fills the kind's tuning block at +0x300 and the actor's angles from the stored one. */
void func_L09_00404C50(char *a0)
{
    char *s1 = a0;
    char *s0 = *(char **)(a0 + 0x68);
    float f1;

    *(TI128 *)(s0 + 0x300) = *(TI128 *)(s1 + 0x10);
    *(float *)(s0 + 0x344) = func_002A7878(1.0f, 1.333f);
    *(float *)(s1 + 0x2C) =
        *(float *)(*(char **)(s1 + 0x24) + 0x24) * *(float *)(s0 + 0x344);
    *(unsigned char *)(s0 + 0x48) = func_00283CF0(15.0f);
    *(unsigned char *)(s0 + 0x4A) = func_00283CF0(4.0f);
    f1 = *(float *)(s0 + 0x344) * 0.1f;
    *(float *)(s0 + 0x84) = 0.2f;
    *(unsigned char *)(s0 + 0x28) = 3;
    *(float *)(s0 + 0x134) = 0.05f;
    *(float *)(s0 + 0x104) = f1;
    *(float *)(s0 + 0x110) = 0.17453295f;
    *(float *)(s0 + 0x130) = 0.5260310173034668f;
    *(int *)(s0 + 0x98) = 3;
    *(float *)(s0 + 0x80) = 0.2f;
    *(unsigned char *)(s0 + 0x60) = 11;
    *(float *)(s0 + 0x30) = 0.333000004291534f;
    *(unsigned char *)(s0 + 0x2A) = 2;
    *(float *)(s0 + 0x100) = *(float *)(s0 + 0x344) * 0.3f;
    *(float *)(s0 + 0x10C) = 0.1f;
    *(int *)(s0 + 0x138) = *(int *)(s0 + 0x138) | 0x80;
    *(float *)(s0 + 0x108) = 0.1f;
    *(float *)(s0 + 0x8C) = 0.4f;
    func_002A78D8(18.0f, 22.0f);
    *(unsigned char *)(s0 + 0x1E8) = 7;
    *(unsigned char *)(s0 + 0x1E9) = 6;
    *(unsigned short *)(s0 + 0x1E2) = 0x78;
    *(int *)(s0 + 0x13C) = *(int *)(s0 + 0x234);
    *(unsigned short *)(s0 + 0x1E4) = 0xB4;
    *(float *)(s0 + 0x1D4) = 0.875f;
    *(float *)(s0 + 0x1D0) = D_L09_001B13F4 * 0.01666666753590107f;
    *(float *)(s0 + 0x1DC) = 0.4f * 0.01745329238474369f;
    *(float *)(s0 + 0x348) = func_002A7940();
    func_002A7750(s1, 1, 0);
    if (*(unsigned char *)(s1 + 0x43))
        func_002A7470(s1, 0, 0, 0);
    *(int *)(s1 + 0x9C) = 12;
    *(unsigned short *)(s1 + 0x34) = *(unsigned short *)(s1 + 0x34) | 0x1000;
}
