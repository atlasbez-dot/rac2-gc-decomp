/* Retained manual C reconstruction; not linked or counted.
 * Retail: 556 bytes, 3 places (13:0040DC20, 14:00414C60, 16:003FC758).
 * Checked trial profile: -O2 -G8 -ffunction-sections -frac2-qcopy.
 * us: 0/3 placements, 576 compiled bytes.
 * Residual: the class-0xEA7 construction, both qcopy copies, every call and both
 * func_002C2210 argument lists agree in meaning, but the candidate saves one extra GPR
 * ($s6 holds self where retail reuses $s1) and one extra FPR ($f21 holds the input
 * parameter where retail keeps it in $f20 and gives $f21 to the 0.0 argument), 20 bytes
 * over retail. Reusing one caller variable for the position then the state, and another
 * for self then entity+0xC0, did not coalesce them. With -fno-schedule-insns the float
 * assignment becomes retail's ($f20 variable, $f21 zero) and the body is 560 bytes, but
 * the GPR assignment moves further away and the frame falls to 0x40.
 * Reopen with evidence for the original local lifetimes/allocation, or a source-level
 * reason that makes the allocator coalesce the reused pointer and keep the float in $f20;
 * do not rename registers or add barriers.
 *
 * The ASM marker was restored in src/levels/shared/L13_00406F18.c after the checks.
 */

typedef int L13_TI128 __attribute__((mode(TI)));

extern void *func_0029EFD0(int);
extern float func_00283248(float, float);
extern float func_00283B98(float, float);
extern float func_00282E20(char *);
extern float func_002A7940(float);
extern void func_002ACEC0(char *, char *, char *, float);
extern void func_002833F0(char *, char *);
extern float func_002A7878(float, float);
extern void func_002C2210(void *, int, int, float, int, int, int, int, float, float);
extern void func_002E5CF8(int, int, char *);

extern float D_L13_001B1360 __attribute__((sda));
extern int D_L13_001B1308 __attribute__((sda));
extern int D_L13_001B130C __attribute__((sda));
extern char D_L13_001B8F20[];

char *func_L13_0040DC20(char *a0, char *a1, char *a2, int a3, float f12)
{
    float f20 = f12;
    char *p = a2;
    char *q = a0;
    char *vel = a1;
    char *entity = func_0029EFD0(0xEA7);

    if (entity == 0)
        return entity;
    *(unsigned char *)(entity + 0x30) = 0xFF;
    *(unsigned short *)(entity + 0x32) = 0xFF;
    *(unsigned char *)(entity + 0x31) = 1;
    *(unsigned char *)(entity + 0x20) = 0;
    *(long long *)(entity + 0x38) = *(long long *)(q + 0x38);
    *(L13_TI128 *)(entity + 0x10) = *(L13_TI128 *)p;
    p = *(char **)(entity + 0x68);
    *(L13_TI128 *)p = *(L13_TI128 *)vel;
    *(char **)(p + 0x10) = q;
    *(float *)(p + 0x14) = f20;
    *(float *)(p + 0x20) = 0.1500000059604645f;
    *(unsigned short *)(entity + 0x34) |= 0x208;

    *(float *)(entity + 0xF8) =
        func_00283B98(func_00283248(*(float *)(vel + 0), *(float *)(vel + 4)), 1.5707964906692505f);
    f20 = -func_00283248(func_00282E20(vel), *(float *)(vel + 8));
    *(float *)(entity + 0xF0) = f20;
    f20 = func_002A7940(f20);

    q = entity + 0xC0;
    func_002ACEC0(entity + 0xE0, entity + 0xE0, entity + 0xD0, f20);
    func_002ACEC0(q, q, entity + 0xD0, f20);
    func_002833F0(q, entity + 0xF0);

    *(unsigned char *)(entity + 0x23) = 0x80;
    *(unsigned short *)(entity + 0x34) |= 0x100;
    *(float *)(entity + 0x2C) = D_L13_001B1360;
    f20 = func_002A7878(8.0f, 10.0f);
    *(int *)(p + 0x24) = 0;
    func_002C2210(entity + 0x10, 0xF, D_L13_001B1308, f20 * 0.30000001192092896f, 0, 0xA,
                (int)D_L13_001B8F20, 0, f20, 0.0f);
    func_002C2210(entity + 0x10, 0xF, D_L13_001B130C, f20 * 0.03999999910593033f, 1, -0xA,
                (int)D_L13_001B8F20, 0, f20 * 0.4000000059604645f, 0.0f);
    func_002E5CF8(0, 0, entity);
    return entity;
}
