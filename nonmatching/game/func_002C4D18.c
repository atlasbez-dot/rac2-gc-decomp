#include "common.h"

extern int D_001A8BB0;
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00283098(void *, void *, void *);
extern float func_00283CE0(int);
extern int func_002A9568(float, int, int);
extern int func_00282978(void *);
extern void func_002B9180(void *);

void func_002C4D18(char *self) {
    float v[4], w[4], m[4];
    char *p = self + 0x20;
    int *rec = *(int **)(p + 0x1C);
    float t0, t1, t2;
    char *obj;

    *(float *)(self + 0xC) =
        func_00283CE0((*(short *)((char *)rec + 8) * (rec[3] - *(short *)(self + 0xA))) / rec[3] + *(short *)((char *)rec + 0xA)) * 1000.0f;
    v[0] = *(float *)(self + 0x20);
    v[1] = *(float *)(p + 4);
    v[2] = *(float *)(p + 8);
    func_00282D30(v, v, 0.98f);
    t0 = v[0];
    t1 = v[1];
    t2 = v[2];
    *(float *)(self + 0x20) = t0;
    *(float *)(p + 4) = t1;
    *(float *)(p + 8) = t2;
    if (D_001A8BB0 == 0) {
        obj = *(char **)(p + 0xC);
        if (obj != 0 && *(unsigned char *)(obj + 0x20) != 0xFE && *(unsigned char *)(obj + 0x20) != 0xFD) {
            w[0] = *(float *)(p + 0x10);
            w[1] = *(float *)(p + 0x14);
            w[2] = *(float *)(p + 0x18);
            func_00282CC0(w, w, v);
            *(float *)(p + 0x10) = w[0];
            *(float *)(p + 0x14) = w[1];
            *(float *)(p + 0x18) = w[2];
            func_00283098(m, w, *(char **)(p + 0xC) + 0xC0);
            func_00282CC0(self + 0x10, *(char **)(p + 0xC) + 0x10, m);
        } else {
            func_002B9180(self);
            return;
        }
    } else {
        func_00282CC0(self + 0x10, self + 0x10, v);
    }
    *(unsigned char *)(self + 8) = *(unsigned char *)(self + 8) + 1;
    *(int *)(self + 4) = func_002A9568((float)*(short *)(self + 0xA) / func_00283CE0(rec[3]), rec[1], rec[0]);
    if (func_00282978(self + 0xA) != 0)
        func_002B9180(self);
}
