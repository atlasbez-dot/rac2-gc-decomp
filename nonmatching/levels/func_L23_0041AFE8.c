/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * Compiled 404 bytes; retail 416 bytes.
 * us: 0/1 placements match (exit 1).
 * us2: 0/1 placements match (exit 1).
 * pal: 0/1 placements match (exit 1).
 * Remaining: Five shared qcopy transfers reach 404 bytes, up from 396. The 0xD0 frame and
 * complete sixteen-argument effect call remain; loop pointer allocation and the annulled handle-
 * increment slot still differ. The effect allocator now has its current pointer return and
 * qualified byte/halfword argument widths; the retained integer handle stores its pointer
 * representation explicitly.
 * Reopen: A verified loop-local vector/handle lifetime witness preserving the complete effect-
 * call banks and stack tail.
 */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));

extern float D_L23_001B157C __attribute__((sda));
extern float D_L23_001B378C;
extern char D_L23_001B37A0[];
extern int D_L23_001B1534 __attribute__((sda));
extern unsigned char D_L23_001B1510 __attribute__((sda));
extern unsigned char D_L23_001B1514 __attribute__((sda));
extern float D_L23_001B1518 __attribute__((sda));
extern float D_L23_001B151C __attribute__((sda));
extern float D_L23_001B1520 __attribute__((sda));
extern float D_L23_001B1524 __attribute__((sda));
extern short D_L23_001B1528 __attribute__((sda));
extern short D_L23_001B152C __attribute__((sda));
extern int D_L23_001B1530 __attribute__((sda));

extern void func_L23_00418650(char *, float);
extern void func_00282CC0(float *, float *, float *);
extern void func_00282CF0(float *, float *, float *);
extern void func_00282F20(float *, float *, float);
extern void *func_L23_004256F0(u8 *,u8 *,u8 *,u8,u8,short,short,int,float,float,float,float,int,int,int,int);

void func_L23_0041AFE8(char *obj, TI128 *p1, TI128 *p2, TI128 *out, int *handles) {
    TI128 loc[5];
    TI128 *v20 = &loc[0];
    TI128 *v30 = &loc[1];
    TI128 *v40 = &loc[2];
    TI128 *v50 = &loc[3];
    TI128 *v60 = &loc[4];
    TI128 *q;
    char *prev;
    int k;

    qcopy(v20,p2);
    func_L23_00418650((char *)v20, D_L23_001B157C);
    func_00282CF0((float *)v30, (float *)v20, (float *)p1);
    func_00282F20((float *)v30, (float *)v30, D_L23_001B378C);
    qcopy(v60,p1);
    qcopy(v40,p1);
    func_L23_00418650((char *)v40, D_L23_001B157C);
    prev = D_L23_001B37A0;
    q = v50;
    for (k = 2; k >= 0; k--) {
        func_00282CC0((float *)q, (float *)v60, (float *)v30);
        func_L23_00418650((char *)q, D_L23_001B157C);
        qcopy(out,q);
        if (*handles == 0) {
            *handles = (int)func_L23_004256F0(prev, obj, (char *)out, D_L23_001B1510, D_L23_001B1514, D_L23_001B1528, D_L23_001B152C, D_L23_001B1530, D_L23_001B1518, D_L23_001B151C, D_L23_001B1520, D_L23_001B1524, D_L23_001B1534, 1, -1, 1);
        }
        handles++;
        qcopy(v40,v50);
        prev = (char *)out;
        func_00282CC0((float *)v60, (float *)v60, (float *)v30);
        out++;
    }
}
