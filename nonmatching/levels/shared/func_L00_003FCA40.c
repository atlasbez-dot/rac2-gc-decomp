/* from src/levels/shared/L00_003F8E08-g8.c: C that compiles close to the retail's bytes
   but does not match; needs a -G8 unit (the body reads level data through $gp). */

/* The body: the allocator hands out a 0xD9C-byte object; the object is set up (the flag
   halfword, three header bytes), the second argument's vector is copied into it, the
   object is normalised twice and added to the first argument, three random floats are
   written to it and the level's own copy of func_L00_003FD178 is run on it. */

#ifndef RAC2_T_QUAD_3FCA40
#define RAC2_T_QUAD_3FCA40
typedef int Quad_3fca40 __attribute__((mode(TI)));
#endif

/* The allocator, the two vector helpers and the int-to-float helper the retail calls;
   each sits at another address in the other levels, so the level's own copies are named
   here with the address they have in level 00. */
extern void *func_0029EFD0(int);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern float func_00283CE0(int);

extern int D_L00_001B0BB4 __attribute__((sda));

/* The bodies the retail calls reach, at 0x3FD178, 0x2E6EF8 and 0x3FCDB0 in level 00. */
extern void ref_L00_003FCA40_00(void *);
extern void ref_L00_003FCA40_01(void *, void *);
extern void ref_L00_003FCA40_02(void);

char *func_L00_003FCA40(char *a0, char *a1, Quad_3fca40 *a2, int a3)
{
    Quad_3fca40 local;
    char *obj;
    char *obj10;
    int *p;
    char *q;
    int g;
    float f;

    obj = (char *)func_0029EFD0(0xD9C);
    if (obj != 0) {
        *(unsigned short *)(obj + 0x34) |= 0x41;
        p = *(int **)(obj + 0x68);
        *(unsigned char *)(obj + 0x20) = 0;
        *(unsigned char *)(obj + 0x31) = 1;
        *(unsigned char *)(obj + 0x30) = 0xFF;
        *(unsigned short *)(obj + 0x32) = 0xFF;
        q = (char *)p + 0x20;
        obj10 = obj + 0x10;
        func_00282F20(q, a1, 0.33333334f);
        *(Quad_3fca40 *)obj10 = *a2;
        func_00282F20(&local, q, -0.25f);
        func_00282CC0((char *)p + 0x50, a0, &local);
        g = (int)D_L00_001B0BB4;
        *(int *)((char *)p + 0x38) = g;
        f = func_00283CE0(g);
        *(int *)((char *)p + 0x34) = a3;
        *(float *)((char *)p + 0x3C) = 1.0f / f;
        ref_L00_003FCA40_00(obj10);
        ref_L00_003FCA40_01(ref_L00_003FCA40_02, obj);
    }
    return obj;
}
