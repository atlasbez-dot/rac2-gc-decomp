/* Mid worker 11 near miss (func_L11_00438F18).
   Profile: -O2 -G0 -ffunction-sections.
   Status: same 436 bytes; instruction stream equal modulo saved-register numbering (obj s0/s2, table high part s2/s0) and the index temporary v0/v1. */
#include "common.h"

#define FLD(base, T, off) (((struct { u8 pad[off]; T v; } *)(base))->v)

extern char *D_L11_001FF580[];

extern int func_002A77E0(int);
extern float func_00282E80(char *, char *);

void func_L11_00438F18(char *obj) {
    char *st = FLD(obj, char *, 0x68);
    float best;
    float d;
    int pick;
    int idx;
    char **tbl;
    int i;
    int toggled;
    int offset;

    toggled = FLD(st, u16, 0x37A) ^ 1;
    FLD(st, u16, 0x37A) = toggled;
    switch (FLD(obj, u8, 0x20)) {
    case 2:
        FLD(st, char *, 0x324) = D_L11_001FF580[FLD(st, int, 0x320)];
        break;
    case 3:
        if (toggled != 0) {
            tbl = D_L11_001FF580;
            idx = ((int *)(st + 0x2B0))[func_002A77E0(4)];
        } else {
            tbl = D_L11_001FF580;
            idx = ((int *)(st + 0x2C0))[func_002A77E0(4)];
        }
        goto assign;
    case 4:
        if (toggled != 0) {
            tbl = D_L11_001FF580;
            idx = ((int *)(st + 0x2D0))[func_002A77E0(4)];
        } else {
            tbl = D_L11_001FF580;
            idx = ((int *)(st + 0x2E0))[func_002A77E0(4)];
        }
    assign:
        FLD(st, char *, 0x324) = tbl[idx];
        break;
    }
    pick = 0;
    best = func_00282E80(obj + 0x10, FLD(st, char *, 0x324) + 0x10);
    offset = 0x10;
    for (i = 0; i < FLD(FLD(st, int *, 0x324), int, 0) - 1; i++) {
        d = func_00282E80(obj + 0x10, FLD(st, char *, 0x324) + offset);
        if (d < best) {
            best = d;
            pick = i;
        }
        offset += 0x10;
    }
    FLD(st, s16, 0x370) = pick;
}
