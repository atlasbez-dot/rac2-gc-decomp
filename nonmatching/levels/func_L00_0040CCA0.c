/* func_L00_0040CCA0 (952 bytes, 27 places) -- NEAR MISS, not integrated.
   state: the exact size (238 instructions); aligned similarity 81.6% with 33 differing
   blocks, register allocation and scheduling. Belongs in src/levels/shared/L00_004096B0.c.
   check.py: 00_aranos_tutorial ... 30_insomniac_museum (27 places): instruction at +0x140 differs
*/

extern void func_00282CF0(void *out, void *a, void *b);
extern void func_00282D30(unsigned char *, unsigned char *, float);
extern float func_00283248(float, float);
extern float func_00283B98(float, float);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
float func_002A7878(float a0, float a1);
float func_002A78D8(float a0, float a1);
void func_002AF000(float *p, float a, float b, float c);
extern char *func_002BDCE8(float, float, float, float, float *, int, float *, int, int);
extern char *func_002C16C0(float, float, float, float, float, float *, float *, int, int, int, int);
extern void func_L00_0040DC08(float *, float, int, int, int, int, int, int, int, int, int);
extern unsigned char D_L00_001B8DC0[];
extern unsigned char D_0018A0E0[];
extern char D_L00_001FE940[];

void func_L00_0040CCA0(float *pos, int unused, int flag)
{
    float dir[4];
    float rot[4];
    float at[4];
    float *r2;
    float ang;
    int colour;
    int i;

    if (flag) {
        colour = 0x7F2020FF;
        func_L00_0040DC08(pos, 0.25f, 0, 15, 10, 0, 20, 0, 0, 1, 0);
    } else {
        colour = 0x7F20FF20;
    }
    func_00282CF0(dir, D_L00_001B8DC0, pos);
    i = 19;
    ang = func_00283248(dir[0], dir[1]);
    r2 = rot;
    do {
        int tex;
        float size;
        char *p;
        float a, b, c;

        func_00282D30((unsigned char *)r2, D_0018A0E0,
                      -(func_002A7878(0.2f, 3.0f) * 0.016666668f));
        tex = func_00283CF0(func_002A78D8(1.0f, 2.0f));
        size = func_002A7878(0.3f, 0.75f) * 210000.0f;
        at[0] = pos[0] + func_002A78D8(0.0f, 0.2f);
        at[1] = pos[1] + func_002A78D8(0.0f, 0.2f);
        at[2] = pos[2] + func_002A78D8(0.0f, 0.2f);
        p = func_002BDCE8(0.0f, 1.0f, 1.01f, size, at, tex, r2, 0x7F202020, 0);
        if (p != 0) {
            char *q;
            *(short *)(p + 0xA) = 0x5A;
            p[3] = 0x44;
            q = p + 0x20;
            p[9] = func_00283CF0(4.0f) + 0x40;
            *(float *)(q + 0x1C) = func_00283CE0(5);
            *(int *)(q + 4) = 3;
            q[0xA] = 0x30;
            q[0xB] = *(unsigned char *)(p + 0xA);
        }
        a = func_002A7878(1.0f, 2.0f);
        b = func_002A7878(0.0f, 1.3962636f);
        c = func_00283B98(ang, func_002A78D8(0.0f, 1.3962636f));
        func_002AF000(rot, a * 0.016666668f, c, b);
        at[0] = pos[0] + func_002A78D8(0.0f, 0.1f);
        at[1] = pos[1] + func_002A78D8(0.0f, 0.1f);
        at[2] = pos[2] + func_002A78D8(0.0f, 0.1f);
        p = func_002C16C0(func_002A7878(0.25f, 0.7f) * 210000.0f, 500.0f, 1.0f, 0.0f, 0.0f,
                          at, rot, 30, 127, colour, tex);
        if (p != 0) {
            char *base = D_L00_001FE940;
            p[2] = (*(unsigned char **)(base + 0x184))[6];
        }
    } while (--i >= 0);
}
