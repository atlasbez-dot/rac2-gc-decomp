/* from src/levels/shared/L00_003F8E08-g8.c: C that compiles close to the retail's bytes
   but does not match; needs a -G8 unit (the body reads level data through $gp). */

/* The body: the allocator hands out a 0xE64-byte object; the two arguments' vectors are
   copied into it and into the record at +0x68, three random floats are written to the
   object, a matrix is built from them and the object's own halfword is scaled by one of
   two small-data floats. */

#ifndef RAC2_T_QUAD_3FED60
#define RAC2_T_QUAD_3FED60
typedef int Quad_3fed60 __attribute__((mode(TI)));
#endif

/* The allocator, the random helpers and the level routines the retail calls; each sits at
   another address in the other levels, so the level's own copies are named here with the
   address they have in level 00. */
extern void *func_0029EFD0(int);
extern float func_002A7940(void);
extern float func_002A7878(float, float);
extern void func_002833F0(void *, void *);
extern void func_002AB668(void *, void *, float);
extern int func_002FED90(void *, void *, float, float, float);
extern void func_002A0F48(void *);

extern float D_L00_001B0C2C __attribute__((sda));
extern float D_L00_001B0C38 __attribute__((sda));

char *func_L00_003FED60(char *a0, char *a1, int a2)
{
    char *obj;
    int *p;
    float f;

    obj = (char *)func_0029EFD0(0xE64);
    if (obj != 0) {
        *(unsigned short *)(obj + 0x34) |= 0x100;
        *(unsigned char *)(obj + 0x30) = 0xFF;
        *(unsigned short *)(obj + 0x32) = 0xFF;
        *(unsigned char *)(obj + 0x20) = 0;
        p = *(int **)(obj + 0x68);
        *(Quad_3fed60 *)(obj + 0x10) = *(Quad_3fed60 *)a0;
        *(Quad_3fed60 *)p = *(Quad_3fed60 *)a1;
        *(int *)((char *)p + 0x2C) = a2;
        *(int *)((char *)p + 0x24) = 0;
        *(int *)((char *)p + 0x28) = 0xF;
        f = func_002A7940();
        *(float *)((char *)obj + 0xF0) = f;
        f = func_002A7940();
        *(float *)((char *)obj + 0xF4) = f;
        f = func_002A7940();
        *(float *)((char *)obj + 0xF8) = f;
        func_002833F0(obj + 0xC0, obj + 0xF0);
        f = func_002A7878(0.05235988646745682f, 0.10471977293491364f);
        func_002AB668((char *)p + 0x10, obj + 0xD0, f);
        if (a2 == 0) {
            f = *(float *)((char *)obj + 0x2C) * D_L00_001B0C2C;
        } else {
            f = *(float *)((char *)obj + 0x2C) * D_L00_001B0C38;
        }
        *(float *)((char *)obj + 0x2C) = f;
        *(int *)((char *)p + 0x30) = func_002FED90(obj, 0, 1.0f, 1.0f, 1.0f);
        func_002A0F48(obj);
    }
    return obj;
}
