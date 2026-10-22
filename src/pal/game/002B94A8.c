#include "include_asm.h"

INCLUDE_ASM("asm/pal/game", func_PAL_002B94A8);

typedef struct {
    char reserved[0x18E];
    short active;
    int value;
} State_2B8518;
extern State_2B8518 D_00138180;

void func_PAL_002B9BB8(void) {
    extern void func_002B85F8(void *);
    extern State_2B8518 D_00138500;
    func_002B85F8(&D_00138180);
    func_002B85F8(&D_00138500);
}

