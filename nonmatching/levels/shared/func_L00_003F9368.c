/* from src/levels/shared/L00_003F8E08.c: the body's C; not matched yet.
   The body: when the object's state byte is 0 the object is told to switch to state 1 and
   the state setter is run; when the byte is not 1 the function returns. Otherwise the
   object's scale is divided by the scale of the object it points at, its own scale is
   damped, and two four-float vectors (built from fixed pairs) are interpolated with that
   scale and handed to the level's own copy of func_L00_0033E220. */

#ifndef RAC2_T_QUAD_3F9368
#define RAC2_T_QUAD_3F9368
typedef int Quad_3f9368 __attribute__((mode(TI)));
#endif

extern void func_002A7750(void *, int, int);
extern float func_00283B98(float, float);

/* The bodies the retail calls reach, at 0x2D5940 and 0x33E220 in level 00. */
extern void ref_L00_003F9368_00(void *, void *, float);
extern void ref_L00_003F9368_01(void *, void *, int, int, int, int, int, int, float, float);

void func_L00_003F9368(char *self)
{
    Quad_3f9368 v1;
    Quad_3f9368 v2;
    char *p;
    float f20;
    float f21;
    float f22;
    float f;

    if (*(unsigned char *)(self + 0x20) == 0) {
        *(int *)(self + 0x78) = 0x1500FF;
        func_002A7750(self, 1, -1);
    }
    if (*(unsigned char *)(self + 0x20) != 1) {
        return;
    }
    p = *(char **)(self + 0x24);
    f20 = *(float *)(self + 0x2C) / *(float *)(p + 0x24);
    f21 = 0.10000190883874893f;
    f22 = 243600.0f;
    f = func_00283B98(*(float *)(self + 0xF4), 0.05235988646745682f);
    *(float *)(self + 0xF4) = f;

    v1 = 0;
    *(float *)((char *)&v1 + 4) = 0.5378739833831787f;
    *(float *)((char *)&v1 + 8) = -0.3785569965839386f;
    ref_L00_003F9368_00(&v1, &v1, f20);
    ref_L00_003F9368_01(&v1, self, 0x1500FF, -1, 1, 2, 1, -1, f22, f21);

    v2 = 0;
    *(float *)((char *)&v2 + 4) = 0.5123069882392883f;
    *(float *)((char *)&v2 + 8) = 0.37711501121520996f;
    ref_L00_003F9368_00(&v2, &v2, f20);
    ref_L00_003F9368_01(&v2, self, 0x1500FF, -1, 1, 2, 1, -1, f22, f21);
}
