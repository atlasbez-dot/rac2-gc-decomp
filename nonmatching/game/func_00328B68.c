/* func_00328B68 - 316 bytes, 28 places (the boot and every level).
   Retail at 0x00328B68: the hundred resident entries at 0x247900 are walked
   (the entry pointer steps by 0x40); for the entry whose +0x24 word is the
   argument, the +0x20 angle is turned by func_00283180, halved between 0 and
   1, scaled by 128 and drawn twice (func_L00_003E0F58 with the colours
   0x103080 and 0x7F7F7F).
   The candidate below is that body; two things differ. The retail's
   sub.s $f12,$f12,$f25 (the angle minus pi, in the delay slot of the first
   call) is dead - nothing reads $f12 afterwards - and this cc1 removes it,
   which takes pi out of the constant pool and shifts every float register
   (retail: pi in $f25, 1.0 in $f24, 0.5 in $f23, 128.0 in $f22, 0.0 in $f21
   and 0.01099406534 in $f20; this cc1 starts at $f25 with 1.0). The second
   difference is the table's address: retail materialises the symbol and adds
   0x10 to it (lui $v0,0x23 ; addiu $v0,$v0,-0x4F60 ; addiu $s1,$v0,0x10)
   where the candidate folds the +0x10 into the pointer. The angle's constant
   is 0x3C343958, that is 0.010994065341472625732421875f.
   What would unblock it: a spelling that keeps the dead subtraction (a
   volatile local adds a store and breaks the shape). */
extern float func_00283180(float);
extern int func_00283CF0(float);
extern void ref_L00_00328B68_00(void *, int, int, float, float, float, int, int);
extern char ref_L00_00328B68_01[];

void func_00328B68(char *a0)
{
    char *p = ref_L00_00328B68_01 + 0x10;
    float a;
    float s;
    float u;
    int n;
    int i;

    for (i = 0x63; i >= 0; i--) {
        if (*(int *)(p + 0x24) == (int)a0) {
            a = *(float *)(p + 0x20);
            s = func_00283180(a);
            a = a - 3.1415927f;
            s = (s + 1.0f) * 0.5f;
            n = func_00283CF0(s);
            u = s * 128.0f;
            ref_L00_00328B68_00(p, 0x103080, n, 0.0f, u, 0.01099406534147262573f, 0x2E, 2);
            ref_L00_00328B68_00(p, 0x7F7F7F, n, 0.0f, 0.0625f, 0.01099406534147262573f, 0x2E, 2);
        }
        p += 0x40;
    }
}
