#include "include_asm.h"
extern int func_002DE3A0(int);
extern int func_002DE550(int);
extern int func_002C9A60(void);
extern void func_00287E80(void);
extern void func_00339760(void *);
extern volatile int D_001A8C88;
extern char *D_001A8CFC __attribute__((sda));

int func_PAL_002DD7B0(char *object)
{
    func_002DE3A0(1);
    *(int *)(object + 0x48) = func_002DE550(0);
    *(int *)(object + 0x4C) = 0;
    func_002C9A60();
    func_00287E80();
    if (D_001A8C88 != 0 && D_001A8CFC != 0)
        func_00339760(D_001A8CFC + 0x3CF50);
    return 0;
}
