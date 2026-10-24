#include "include_asm.h"

typedef int TI128_00325C50 __attribute__((mode(TI)));

extern void func_002833F0(float, void *, void *);
extern void func_002AF1D0(void *, void *, int, int);
extern void func_00283738(void *, void *, void *);
extern int func_002A77E0(int);
extern void func_003258C0(void *, int, void *);

void func_00325C50(float angle, char *parent, char **children, int randomize, void *effect)
{
    char rotation[0x30];
    TI128_00325C50 zero = 0;
    TI128_00325C50 position;
    int i;

    func_002833F0(angle, rotation, &zero);
    for (i = 1; i >= 0; i--) {
        char *child = *children++;
        func_002AF1D0(parent, child, (unsigned char)child[0xBC], 0);
        func_00283738(child + 0xC0, child + 0xC0, rotation);
        if (randomize == 0)
            continue;
        if (func_002A77E0(6) != 0)
            continue;
        position = *(TI128_00325C50 *)(child + 0x10);
        func_003258C0(&position, 1, effect);
    }
}
