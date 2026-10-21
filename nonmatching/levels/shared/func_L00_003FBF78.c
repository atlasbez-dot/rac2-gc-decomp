/* from src/levels/shared/L00_003F8E08-g8.c: the body's C; not matched yet.
   The body: when the level's own counter (D_L00_001B0B64) is not positive the function
   returns. Otherwise the counter's value and the one below it are turned into floats and
   divided, and three bytes (D_L00_001B1980, D_L00_001B1981, D_L00_001B1982) are turned
   into floats, interpolated between 255 and the ratio, and the three results are written
   to the level's record; the four tail floats move that record's bounds. */

extern int D_L00_001B0B64 __attribute__((sda));
extern int D_L00_001B0B60 __attribute__((sda));
extern unsigned char D_L00_001B1980[] __attribute__((sda));
extern unsigned char D_L00_001B1981[] __attribute__((sda));
extern unsigned char D_L00_001B1982[] __attribute__((sda));
extern float D_L00_001B0BB0 __attribute__((sda));
extern float D_L00_001B2BE0 __attribute__((sda));
extern float D_L00_001B1984[] __attribute__((sda));
extern float D_L00_001B1988[] __attribute__((sda));
extern float D_L00_001B198C[] __attribute__((sda));
extern float D_L00_001B1990[] __attribute__((sda));
extern char D_L00_001BD2C0[] __attribute__((sda));

extern void func_00282948(void *);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern void func_0027AB40(void);

void func_L00_003FBF78(void)
{
    float f20;
    float f21;
    float f22;
    float f0;
    float f1;
    float f2;
    float f3;
    float f4;
    float f5;
    float f6;
    int r;

    if (D_L00_001B0B64 <= 0) {
        return;
    }
    f22 = 255.0f;
    func_00282948(&D_L00_001B0B64);
    f20 = func_00283CE0(D_L00_001B0B64) / func_00283CE0(D_L00_001B0B60);

    f21 = func_00283CE0(D_L00_001B1980[0]);
    r = func_00283CF0(f21 + (f22 - f21) * f20);
    f21 = func_00283CE0(D_L00_001B1981[0]);
    *(int *)(D_L00_001BD2C0 + 0x230) = r;
    f21 = func_00283CE0(D_L00_001B1981[0]);
    r = func_00283CF0(f21 + (f22 - f21) * f20);
    f21 = func_00283CE0(D_L00_001B1982[0]);
    *(int *)(D_L00_001BD2C0 + 0x234) = r;
    f21 = func_00283CE0(D_L00_001B1982[0]);
    r = func_00283CF0(f21 + (f22 - f21) * f20);
    *(int *)(D_L00_001BD2C0 + 0x238) = r;

    f1 = D_L00_001B0BB0 * 1024.0f;
    f0 = D_L00_001B2BE0 * f1;
    f4 = D_L00_001B1984[0];
    f5 = D_L00_001B1988[0];
    f6 = D_L00_001B198C[0];
    f3 = D_L00_001B1990[0];
    f1 = 100.0f;
    f22 = (f22 - f6) * f20;
    f2 = -f4 * f20;
    f0 = (f0 - f5) * f20;
    f1 = (f1 - f3) * f20;
    f4 = f4 + f2;
    f5 = f5 + f0;
    f6 = f6 + f22;
    f3 = f3 + f1;
    *(float *)(D_L00_001BD2C0 + 0x218) = f4;
    *(float *)(D_L00_001BD2C0 + 0x21C) = f5;
    *(float *)(D_L00_001BD2C0 + 0x228) = f6;
    *(float *)(D_L00_001BD2C0 + 0x22C) = f3;
    func_0027AB40();
}
