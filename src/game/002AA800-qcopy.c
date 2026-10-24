#include "include_asm.h"

#ifndef RAC2_T_V4_002AD6F0
#define RAC2_T_V4_002AD6F0
typedef int V4_002AD6F0 __attribute__((mode(TI)));
#endif

typedef struct { char pad[64]; } Matrix64_002AD6F0;

extern void func_00283410(char *dst, char *src);
extern void func_00283698(char *dst, char *src);
extern void func_00283788(char *a, char *b, char *c);
extern void func_002AB6D8(char *a, char *b);

void func_002AD6F0(void *obj, void *a1, void *a2, void *a3)
{
    Matrix64_002AD6F0 m0, m1, m2, m3;
    V4_002AD6F0 *p;

    func_00283410((char *)&m0, (char *)a2);
    func_00283698((char *)&m1, (char *)&m0);
    func_00283410((char *)&m2, (char *)a3);
    func_00283788((char *)&m3, (char *)&m1, (char *)&m2);
    func_002AB6D8((char *)&m3, (char *)obj);
    if (*(int *)((char *)obj + 0x3C) & 2) {
        p = (V4_002AD6F0 *)((char *)obj + 0x20);
        *p = *(V4_002AD6F0 *)a2;
    }
    p = (V4_002AD6F0 *)((char *)obj + 0x10);
    *p = *(V4_002AD6F0 *)a1;
}
