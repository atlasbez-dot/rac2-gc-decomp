#include "include_asm.h"

extern float D_L02_001B1030 __attribute__((sda));

extern int D_L02_001AD410;

extern char D_L02_001B11D0[8] __attribute__((sda));

extern char D_L02_001B11E0[8] __attribute__((sda));

extern char D_L02_001B11F0[8] __attribute__((sda));

extern char D_L02_001B1200[8] __attribute__((sda));

extern int D_L02_001B1210 __attribute__((sda));

extern void func_00282C88(void *);

extern void func_00335438(char *, char *, int, int, int);

INCLUDE_ASM("asm/levels", func_L01_0042A6F0);

void func_L02_003F56C0(void) {
    int v0 = D_L02_001AD410;
    float *p = (float *)((char *)v0 + 0x74);
    float f;

    f = p[0] + D_L02_001B1030 * 1.6666667535901069641113281250e-02f;
    p[0] = f;
    if (f > 1.0f)
        p[0] = f - 1.0f;
}

void func_L02_003FD770(char *a0) {
    char buf[16];
    func_00282C88(buf);
    func_00335438(D_L02_001B11F0, D_L02_001B1200, 1, 0, 0);
    func_L01_0042A6F0(2, D_L02_001B1210);
    func_00335370(D_L02_001B11D0);
    func_003353C8(D_L02_001B11E0);
}

extern char D_L02_001BA500[];
extern int D_L02_001B32E8;
extern float func_00282E48(void *, void *);
extern void func_002A7750(char *, int, int);

/* Raises the flag at 0x1B32E8. When the point at D_L02_001BA500 is within 0.0001 of the one at
   D_L02_001B11D0 the actor changes state by its kind (4 to 7, 5 to 6) and the two widgets are
   updated; otherwise func_L02_003FD770 runs unless the object's state half-word is 5. */
void func_L02_003FD7C8(char *a0) {
    D_L02_001B32E8 = 1;
    if (func_00282E48(D_L02_001BA500, D_L02_001B11D0) < 0.0001f) {
        if (*(unsigned char *)(a0 + 0x20) == 4)
            func_002A7750(a0, 7, -1);
        else if (*(unsigned char *)(a0 + 0x20) == 5)
            func_002A7750(a0, 6, -1);
        func_L01_0042A6F0(1, 0);
        func_00335370(D_L02_001B11D0);
        func_003353C8(D_L02_001B11E0);
    } else if (*(short *)(*(char **)(D_L02_001BA500 + 0x50) + 0x86) != 5) {
        func_L02_003FD770(a0);
    }
}

extern char *D_L02_001B1190[] __attribute__((sda));

/* Whether the pair of table entries the object names still agree with its own four words. */
INCLUDE_ASM("asm/levels", func_L02_003FCBF0);

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef float f32;

extern char *D_L02_001B1190[2] __attribute__((sda));
extern unsigned char *D_L02_001B359C[3] __attribute__((sda));
extern s32 D_L02_001B35B8[] __attribute__((sda));
extern u32 D_L02_001FC060[];
extern f32 D_L02_001B1258 __attribute__((sda));
extern f32 D_L02_001B125C __attribute__((sda));
extern s32 func_00312B58(char *);
extern s32 func_L02_00416800(char *);
extern s32 func_002A77E0(s32);
extern void func_L02_00416720(char *, char *, f32, f32);

#define GROUP(off) (*(s32 *)(state + (off)))
/* Leaves the function when the group is 0xFF or empty; the braces it opens close in END_IDS. */
#define FOR_EACH_ID(p, off) \
    if (GROUP(off) == 0xFF) \
        return; \
    { u16 *q = (u16 *)D_L02_001FC060[GROUP(off)]; \
    if (q == 0) \
        return; \
    for (p = q; (GROUP(off) & 0xFF) != 0xFF && GROUP(off) <= D_L02_001B35B8[0] && p != 0 && \
         ((p != 0 && (s16)p[-1] >= 0) || p == (u16 *)D_L02_001FC060[GROUP(off)]); \
         p++)
#define END_IDS }
/* One half: collect the entities of group OFF for which func_00312B58 holds (counting the
   others in m), then, up to 1000 passes over group 0xCC while m is below the record's limit,
   hand one collected entity at a time to func_L02_00416720 with an entity of 0xCC. */
#define HALF(limit, off) \
    { \
        s32 n, m, i, k; \
        if (*(s16 *)(rec + (limit)) != 0) { \
            m = 0; \
            n = 0; \
            for (k = 15; k >= 0; k--) \
                buf[k] = 0; \
            FOR_EACH_ID(p, off) { \
                e = (char *)D_L02_001B359C[0] + ((*p & 0x7FFF) << 8); \
                if (e == 0) \
                    break; \
                if (func_00312B58(e) == 0) { \
                    m++; \
                } else { \
                    buf[n] = e; \
                    n++; \
                } \
            } END_IDS \
            if (n != 0) { \
                for (i = 0; i < 1000 && m < *(s16 *)(rec + (limit)); i++) { \
                    FOR_EACH_ID(p, 0xCC) { \
                        e = (char *)D_L02_001B359C[0] + ((*p & 0x7FFF) << 8); \
                        if (e == 0) \
                            break; \
                        if (n <= 0) \
                            break; \
                        if (func_L02_00416800(e) != 0 && func_002A77E0(6) == 0) { \
                            n--; \
                            func_L02_00416720(e, buf[n], D_L02_001B1258 * 0.016666668f, \
                                              D_L02_001B125C * 2.908882452175021e-4f); \
                            m++; \
                            break; \
                        } \
                    } END_IDS \
                } \
            } \
        } \
    }

void func_L02_003FD228(char *a0) {
    char *state = *(char **)(a0 + 0x68);
    char *rec = *(char **)(D_L02_001B1190[*(s16 *)(state + 0x120)] + 4)
                + *(s16 *)(state + 0x122) * 0x14;
    char *buf[16];
    u16 *p;
    char *e;

    HALF(0xC, 0xC8)
    HALF(0xE, 0xC4)
}
