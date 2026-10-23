/* Retained C reconstruction: 276/300 bytes.
   Profile: -O2 -G0 -ffunction-sections -g.
   0/20 in us and us2; this name is absent from pal. A separate boolean reproduces the mode gate, but the saved high-half resident base and the remainder/store register schedule differ.
   Reopen only with new source/type/lifetime evidence; bounded scheduling/profile variants did not close it. */

#include "include_asm.h"

typedef unsigned char u8;

extern char D_00189E20_2[];
extern unsigned char D_00139568[];
extern char D_L00_00262570[];
extern void func_002A04B8(void *owner, int *a1, int *a2, int *a3);
extern void func_002A0488(void *owner, int a1, int a2, int a3);
extern void func_L00_002A7070(void);
extern void func_L00_002A70F0(int first, void *second);

void func_L00_002A74A8(void)
{
    char *base = D_00189E20_2;

    int active = 0;
    if (*(int *)(base + 0x2294) == 125 || *(int *)(base + 0x2294) == 127)
        active = *(int *)(base + 0x1B8) < 30;
    if (active) {
        int v[3];

        func_002A04B8(*(void **)(base + 0x2290), &v[0], &v[1], &v[2]);

        if (*(int *)(base + 0x1B8) % 4 < 3) {
            v[0] = 0;
            v[1] = 0;
            v[2] = 0;
        } else {
            v[1] = 0x90;
            v[2] = 0xF0;
            v[0] = 0x90;
        }

        func_002A0488(*(void **)(base + 0x2290), v[0], v[1], v[2]);
        func_L00_002A7070();
    }

    if (*(int *)(base + 0x1248) >= 0) {
        unsigned char index = D_00139568[*(int *)(base + 0x1248)];
        char *record = D_L00_00262570 + index * 0xE0;

        if (*(u8 *)(record + 4) != 0) {
            int state = *(int *)(base + 0x1220);

            if (state != 0)
                func_L00_002A70F0(state, *(void **)(base + 0x2290));
        }
    }
}
