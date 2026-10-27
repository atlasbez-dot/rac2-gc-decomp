/* Mid worker 19 near miss (func_L05_00415FD0).
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-zero-ti-por.
   Status: same shape; the five float constants held across the calls (0.1, 30, 40, 1/60, 0.4) get permuted registers and the prologue constant order differs. */
typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 bits; float value[4]; } Vec4;
typedef struct {
    Vec4 in;
    Vec4 scal;
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;
    Vec4 v3;
} Frame;

extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_002ACB48(void *, float);
extern float func_002A7878(float, float);
extern void *func_L00_0033C0D0(char *, void *, void *, int *, int);
extern int D_L05_001B0F18 __attribute__((sda));
extern int D_L05_001B0F28 __attribute__((sda));
extern int D_L05_001B0F38 __attribute__((sda));

void func_L05_00415FD0(char *self)
{
    Frame f;

    f.in.bits = 0;
    f.in.value[0] = -0.2409999966621399f;
    f.scal.bits = 0;
    f.in.value[3] = 1.0f;
    func_00283098(&f.v0, &f.in, self + 0xC0);
    func_00282CC0(&f.v0, &f.v0, self + 0x10);
    f.v0.value[3] = 0.0f;
    f.v1.bits = f.v0.bits;
    f.v2.bits = f.v0.bits;
    f.v3.bits = f.v0.bits;
    func_002ACB48(&f.v0, 0.10000000149011612f);
    func_002ACB48(&f.v1, 0.10000000149011612f);
    func_002ACB48(&f.v2, 0.10000000149011612f);
    func_002ACB48(&f.v3, 0.10000000149011612f);
    f.scal.value[0] = -(func_002A7878(30.0f, 40.0f) * 0.01666666753590107f) * 0.4000000059604645f;
    func_L00_0033C0D0(self, &f.v1, &f.scal, &D_L05_001B0F18, 1);
    f.scal.value[0] = -(func_002A7878(30.0f, 40.0f) * 0.01666666753590107f) * 0.4000000059604645f;
    func_L00_0033C0D0(self, &f.v2, &f.scal, &D_L05_001B0F28, 1);
    f.scal.value[0] = -(func_002A7878(30.0f, 40.0f) * 0.01666666753590107f) * 0.4000000059604645f;
    func_L00_0033C0D0(self, &f.v3, &f.scal, &D_L05_001B0F38, 1);
}
