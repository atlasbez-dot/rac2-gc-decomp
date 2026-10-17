#include "include_asm.h"

/* The gate's word at $gp-0x2B14 is a small index into a table of live sub-objects. */
extern int D_L05_001AC4DC __attribute__((sda));

extern char D_L05_00221D10[];
extern char D_L05_00225DD0[];

extern char *func_379CA0(char *object);
extern int func_37CDB0(char *object);

/* Decides whether the object may take its next step: the gate must be open, the looked-up
 * sub-object must exist, its handle must match the one the gate's table names, it must not be
 * already counting, its two counters must be ordered, and its state must be neither 3 nor 0xD.
 * The last test writes 0 rather than branching. */
int func_L05_0037B888(char *a0)
{
    char *object = a0;
    char *sub = func_379CA0(a0);
    char *gate = D_L05_00221D10;
    int ready = 1;

    if (*(int *)(gate + 0x2C) == 1)
        return 0;
    if (sub == 0)
        return 0;
    if (*(short *)(object + 0xAA) != *(short *)(((char **)D_L05_00225DD0)[D_L05_001AC4DC] + 0xAA))
        return 0;
    if (*(int *)(sub + 0x118) == 1)
        return 0;
    if (*(int *)(gate + 0xC) >= *(int *)(gate + 0x20))
        return 0;
    if (func_37CDB0(object) == 3)
        return 0;
    if (func_37CDB0(object) == 0xD)
        ready = 0;
    return ready;
}
