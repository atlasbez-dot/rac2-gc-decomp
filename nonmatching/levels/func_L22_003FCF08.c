/* Retained complete C repair, 2026-10-25; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy.
 * Private placement checks: us: 0/2, us2: 0/2, pal: absent.
 * The random heading returned in f0 is retained independently from random
 * elevation. AF000 receives radius, heading and elevation in order, preserving
 * RNG call order. All four local quadword vectors have 16-byte alignment.
 * Historical screening lost the heading result.
 * Current code is 572/568 bytes, with frame 0xA0 versus 0xB0. GPR/FP
 * allocation and loop-invariant constant lifetimes still differ. No extra W
 * initialization was introduced.
 */

typedef unsigned char u8;
typedef float f32;
typedef int TI128 __attribute__((mode(TI)));

extern int func_002A77E0(int);

extern f32 func_002A7878(f32, f32);

extern f32 func_002A7940(void);

extern f32 func_002A78D8(f32, f32);

extern void func_002AF000(f32 *, f32, f32, f32);

extern void func_00282D30(char *, char *, f32);

extern void func_00282CD8(char *, char *, char *);

extern void func_002C2210(char *, int, int, int, int, char *, int, f32, f32, f32);

extern f32 D_L22_001B0D1C __attribute__((sda));

extern f32 D_L22_001B0D20 __attribute__((sda));

extern f32 D_L22_001B0D0C __attribute__((sda));

extern f32 D_L22_001B0D10 __attribute__((sda));

extern int D_L22_001B0D34 __attribute__((sda));

extern int D_L22_001B0D2C __attribute__((sda));

extern int D_L22_001B0D30 __attribute__((sda));

extern f32 D_L22_001B0D08 __attribute__((sda));

void func_L22_003FCF08(u8 *a0, u8 *a1, int count)
{
    f32 dir[4] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));
    f32 q[4] __attribute__((aligned(16)));
    f32 scale = 0.016666668f;
    f32 zero = 0.0f;
    f32 step = 0.0375f;
    f32 ang;
    f32 a;
    f32 heading;
    int side;

    if (count > 0) {
        int left = count;
        for (; left != 0; left--) {
            f32 out[4] __attribute__((aligned(16)));
            ang = func_002A7878(D_L22_001B0D1C, D_L22_001B0D20);
            side = func_002A77E0(2);
            side = side ? side : -1;
            heading = func_002A7940();
            a = func_002A7878(0.698131799697876f, 1.5358898639678955f);
            func_002AF000(dir, func_002A7878(D_L22_001B0D0C * scale, D_L22_001B0D10 * scale), heading, a);
            *(TI128 *)q = *(TI128 *)a1;
            func_00282D30((char *)q, (char *)a1, func_002A7878(0.75f, 0.95f));
            func_00282CD8((char *)out, (char *)dir, (char *)q);
            *(TI128 *)v = *(TI128 *)a0;
            v[0] += func_002A78D8(zero, step);
            v[1] += func_002A78D8(zero, step);
            v[2] += func_002A78D8(zero, step);
            func_002C2210((char *)v, D_L22_001B0D34, D_L22_001B0D2C, 0, side,
                          (char *)dir, 0, ang * 0.1f, ang, D_L22_001B0D08);
            func_002C2210((char *)v, D_L22_001B0D34, D_L22_001B0D30, 1, -side,
                          (char *)dir, 0, ang * 0.07f, ang * 0.7f, D_L22_001B0D08);
        }
    }
}
