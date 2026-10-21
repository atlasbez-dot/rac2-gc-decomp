/* Near miss, rechecked 2026-10-21 in src/levels/02_maktar_nebula/L02_003D26B0-g8.c
 * with the qualified compiler on master 8b23616 plus PR249,
 * -O2 -G8 -ffunction-sections: 552 bytes, retail 556; 0 of 1 places match.
 * The candidate has no second saved-register copy of e + 0x10.
 * The empty do/while previously used to force a CSE boundary was removed: it is
 * an artificial source barrier, prohibited by AGENTS.md. Preserve the natural C
 * here until the compiler difference or a supported source form is understood.
 */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

extern u16 *D_L02_001FC060[];
extern u8 *D_L02_001B359C_1[] __attribute__((sda));
extern int D_L02_001B35B8 __attribute__((sda));
extern float D_L02_001B016C __attribute__((sda));
extern float D_L02_001B0170 __attribute__((sda));
extern float D_L02_001B0174 __attribute__((sda));

extern void func_00282CF0(float *, float *, float *);
extern int func_L02_003D7300(u8 *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern float func_00283BE0(float, float);
extern void func_002ACEC0(float *, float *, char *, float);
extern void func_00282CC0(float *, float *, u8 *);
extern void func_L01_00321178(char *, float *);

extern float func_00282E80(char *, void *);

int func_L02_003D26B0(char *self) {
    char *state = *(char **)(self + 0x68);
    float buf[4];
    u16 *p;
    char *e;
    float saved;
    float r;
    char *ax;

#define GROUP (*(int *)(state + 0x2EC))
/* The heading of the target, from the object's position. */
#define ANGLE()                                                                       \
    func_00283248(*(float *)(e + 0x10) - *(float *)(self + 0x10),                    \
                  *(float *)(e + 0x14) - *(float *)(self + 0x14))
    if (GROUP == -1)
        return 0;
    for (p = D_L02_001FC060[GROUP];
         (GROUP & 0xFF) != 0xFF && GROUP <= D_L02_001B35B8 && p != 0 &&
         ((p != 0 && (s16)p[-1] >= 0) || p == D_L02_001FC060[GROUP]);
         p++) {
        e = (char *)D_L02_001B359C_1[0] + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return 0;
        if (func_L02_003D7300(e) == 0)
            continue;
        if (!(func_00282E80(self + 0x10, e + 0x10) < D_L02_001B016C))
            continue;
        if (!(func_00283C80(*(float *)(self + 0xF8), ANGLE()) < D_L02_001B0170 * 0.017453294f))
            continue;

        func_00282CF0(buf, (float *)(self + 0x10), (float *)(e + 0x10));
        ax = self + 0xE0;
        r = D_L02_001B0174 * 0.017453294f;
        func_002ACEC0(buf, buf, ax,
                      0.0f <= func_00283BE0(*(float *)(self + 0xF8), ANGLE()) ? -r : r);
        func_00282CC0(buf, buf, e + 0x10);
        saved = *(float *)(state + 0x134);
        *(float *)(state + 0x134) = 0.0001f;
        func_L01_00321178(self, buf);
        *(float *)(state + 0x134) = saved;
        return 1;
    }
#undef ANGLE
#undef GROUP
    return 0;
}
