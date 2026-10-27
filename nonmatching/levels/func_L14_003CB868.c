/*
 * Retained manual C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections
 * Retail: 960 bytes; compiled: 956 bytes.
 * Final coverage: us: 0/1; us2: 0/1; pal: catalogue absent.
 * Residual: 956/960 bytes with the complete 64-byte inverse matrix and three full
 * vectors. The final reviewed qcopy preserves its subsequent memory effects; canonical
 * pointer inputs and resident field accesses are explicit. Owner/id/entity allocation,
 * projection pointer lifetime and one saved GPR differ.
 * Reopen: An independently measured owner/group/projection lifetime witness. The held
 * hero pointer and actual owner prefix views tie at 956 bytes; retain their semantic
 * repairs rather than repeat renaming, loop or prototype permutations.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_00283698(void *dst, void *src);
extern void func_00282CF0(void *dst, void *a, void *b);
extern void func_002AFDD8(char *a, char *b, char *c, char *d);
extern float func_00282C48(float a);
extern void func_002830C0(void *dst, void *a, void *b);
extern float func_002A7878(float a, float b);
extern float func_00282C10(float a);
extern void func_00282D30(void *dst, void *src, float s);
extern void func_L14_003C96E0(char *e, void *v, float a, float b, float c);
extern void func_L00_002C42E0(int a0, int a1);
extern unsigned short *D_L14_001FB060[];
extern unsigned char *D_L14_001B259C NOT_SDA;
extern int D_L14_001B25B8 MACRO_ADDR;
extern char *D_L14_001B268C NOT_SDA;
extern char D_00189E20[];

/* Only the observed table/group fields are described. */
struct OwnerPrefix { char reserved00[0x60]; int tableIndex, groupIndex; };

void func_L14_003CB868(char *self) {
    float mtx[16] __attribute__((aligned(16)));
    float off[4] __attribute__((aligned(16)));
    float tmp[4] __attribute__((aligned(16)));
    float vec[4] __attribute__((aligned(16)));
    struct OwnerPrefix *state = *(struct OwnerPrefix **)(self + 0x68);
    unsigned short *p;
    unsigned char *e;
    char *hero;
    char *hero2;
    int inside;
    float a;
    float b;
    float c;

    func_00283698(mtx, self + 0xC0);
    for (p = D_L14_001FB060[state->groupIndex];
         (state->groupIndex & 0xFF) != 0xFF && state->groupIndex <= D_L14_001B25B8 &&
         p != 0 && ((p != 0 && (short)p[-1] >= 0) || p == D_L14_001FB060[state->groupIndex]);
         p++) {
        e = D_L14_001B259C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (e[0x20] != 0xFE) {
            if (e[0x20] != 0xFD) {
                func_00282CF0(off, e + 0x10, self + 0x10);
                func_002AFDD8(self, (char *)off, (char *)off, (char *)mtx);
                off[3] = 1.0f;
                off[0] = off[0] + 2.0f;
                inside = func_00282C48(off[0]) < 1.0f && func_00282C48(off[1]) < 1.0f;
                if (inside) {
                    func_002830C0(tmp, off, D_L14_001B268C + (state->tableIndex << 7));
                    func_L14_003C96E0((char *)e, tmp,
                                      *(float *)(D_L14_001B268C + (state->tableIndex << 7) + 0x38) +
                                          func_002A7878(1.0f, 2.0f),
                                      0.0055555557f, 0.0055555557f);
                }
            }
        }
    }
    hero = D_00189E20;
    if ((*(char **)(hero + 0x33C) == self && *(int *)(hero + 0x340) != 0) ||
        *(float *)(hero + 0x31C) < 0.5f) {
        func_00282CF0(off, D_00189E20 + 0x80, self + 0x10);
        func_002AFDD8(self, (char *)off, (char *)off, (char *)mtx);
        off[3] = 1.0f;
        off[0] = off[0] + 2.0f;
        inside = func_00282C48(off[0]) < 1.0f && func_00282C48(off[1]) < 1.0f;
        if (inside) {
            func_002830C0(tmp, off, D_L14_001B268C + (state->tableIndex << 7));
            hero2 = D_00189E20;
            a = *(float *)(D_L14_001B268C + (state->tableIndex << 7) + 0x38) + 1.5f;
            b = (a - *(float *)(hero2 + 0x88)) * 2.0f;
            c = (a - tmp[2]) * 2.0f;
            func_00282CF0(vec, tmp, hero2 + 0x80);
            func_00282D30(vec, vec, 1.0f / (func_00282C10(b / 0.0055555557f) + func_00282C10(c / 0.0055555557f)));
            vec[2] = func_00282C10(b * 0.0055555557f);
            func_L00_002C42E0(0x44, 1);
            qcopy(hero2 + 0xF0, vec);
        }
    }
}
