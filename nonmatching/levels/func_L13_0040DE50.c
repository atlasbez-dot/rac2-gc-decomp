/* func_L13_0040DE50: M3 2026-10-26: needs a -G8 unit (sda); 228/228, register allocation only ($s0-$s2 roles, $f20/$f21). In the permuter queue.
 */
extern float D_L13_001B1310 __attribute__((sda));

extern int D_L13_001B1300 __attribute__((sda));

extern int D_L13_001B1304 __attribute__((sda));

extern int D_L13_001B1308 __attribute__((sda));

extern int D_L13_001B130C __attribute__((sda));

extern float D_L13_001B1314 __attribute__((sda));

extern int func_002A7820(int, int);

extern float func_002A7940(void);

extern void func_L13_0040DFC0(char *, char *, char *, char *, int, char *, float, float,
                              float);

void func_L13_0040DE50(char *a0)
{
    char *g;
    float f;

    f = D_L13_001B1310 * *(float *)(a0 + 0x2C);
    g = func_002A7820(0x5F, 0x6F);
    func_L13_0040DFC0(a0 + 0x10, D_L13_001B1308, g, D_L13_001B1300, 2, a0, f,
                      func_002A7940(), 1.0f);

    f = D_L13_001B1310 * *(float *)(a0 + 0x2C) * D_L13_001B1314;
    g = func_002A7820(0x6F, 0x7F);
    func_L13_0040DFC0(a0 + 0x10, D_L13_001B130C, g, D_L13_001B1304, 2, a0, f,
                      func_002A7940(), 1.0f);
}
