/* OF2 (2026-10-26): 132/132 bytes in a qcopy unit
   ("-O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier", own file -q.c).
   Two findings: retail's `beq a0,2` skips the copy and the call (state 2 only sets the
   two words), so the shape is `if (a0 != 2) { if (a0 != 3) return; copy; call; }`;
   and a local `g = D_001B9380` keeps the base in one register (lui/addiu, +0x190 and
   +0x140 from it). Only allocation is left: retail g=$a3, copy source $a2, destination
   $v1; ours g=$a2, source $v1, destination $a0 (5 lines). Source-pointer locals and
   -g/no-barrier variants do not move it. Queued for the permuter. */
#include "common.h"

typedef int Q128 __attribute__((mode(TI)));

extern char D_001B9380[];
extern char D_00189EA0[];
extern void func_00272550(char *, char *);

void func_L01_0042A6F0(int a0, int a1)
{
    char *g = D_001B9380;
    char *p = *(char **)(g + 0x190);
    char *m = *(char **)(p + 0x70);
    int *q = (int *)(m + 0xE0);

    *(unsigned char *)(p + 0x88) = a0;

    if (a0 != 2) {
        if (a0 != 3)
            return;
        *(Q128 *)(m + 0x110) = *(Q128 *)D_00189EA0;
        func_00272550(m + 0xFC, g + 0x140);
    }
    q[1] = a1;
    q[0] = a1;
}

#if 0
/* Near miss from src/levels/shared/L01_00397110.c: the build refuses this body at its place.
   Kept as a starting point; not linked, not counted. */

/* Standalone declarations recovered from src/levels/shared/L01_00397110.c. */
extern char D_001B9380[];

extern char D_00189EA0[];

extern void func_2CF938(char *, char *);

typedef int TI128 __attribute__((mode(TI)));

void func_L01_0042A6F0(int a0, int a1)
{
    char *p = *(char **)(D_001B9380 + 0x190);
    char *m = *(char **)(p + 0x70);

    *(unsigned char *)(p + 0x88) = a0;

    if (a0 == 2 || a0 == 3) {
        *(TI128 *)(m + 0x110) = *(TI128 *)D_00189EA0;
        func_2CF938(m + 0xFC, D_001B9380 + 0x140);
        *(int *)(m + 0xE4) = a1;
        *(int *)(m + 0xE0) = a1;
    }
}

#endif
