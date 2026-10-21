#include "include_asm.h"

extern void func_0033AB50(char *p);

/* Calls a helper with a pointer to the second 16-byte field of the record and returns the record pointer. */
char *func_US2_L00_00432D98(char *object)
{
    func_0033AB50(object + 8);
    return object;
}

/* Calls a helper with a pointer to the second 16-byte field of the record and returns the record pointer. */
char *func_US2_L00_004331D8(char *object)
{
    func_0033AB50(object + 8);
    return object;
}

/* Calls a helper with a pointer to the second 16-byte field of the record and returns the record pointer. */
char *func_US2_L00_00433490(char *object)
{
    func_0033AB50(object + 8);
    return object;
}

/* Calls a helper with a pointer to the second 16-byte field of the record and returns the record pointer. */
char *func_US2_L00_00433A18(char *object)
{
    func_0033AB50(object + 8);
    return object;
}

extern void func_0033AE28_2(char *p);
extern void func_L00_00430948_3(char *p, float a, float b);
extern void func_002E5E58_3(int a, int b, int c);
extern volatile unsigned char D_001A7B95 __attribute__((sda));
extern volatile unsigned char D_001A7B94 __attribute__((sda));

/* makes two float-binding calls, then toggles one of two global flag bytes selected by an object field and returns bit 6 of the flag word */
int func_US2_L00_00433B78(char *a0, int a1)
{
    char *p = a0 + 8;
    float *q;
    int v;

    func_0033AE28_2(p);
    q = *(float **)(a0 + 732);
    func_L00_00430948_3(p, q[0], q[1]);
    if (a1 & 0x1000) {
        func_002E5E58_3(3, 0, 0);
        v = *(int *)(a0 + 728);
        *(int *)(a0 + 728) = (v + 1) % 2;
    } else if (a1 & 0x4000) {
        func_002E5E58_3(3, 0, 0);
        v = *(int *)(a0 + 728);
        *(int *)(a0 + 728) = (v + 1) % 2;
    } else if (a1 & 0x40) {
        func_002E5E58_3(4, 0, 0);
        switch (*(int *)(a0 + 728)) {
        case 0:
            D_001A7B95 = D_001A7B95 == 0;
            break;
        case 1:
            D_001A7B94 = D_001A7B94 == 0;
            break;
        }
    }
    return (a1 >> 6) & 1;
}

/* Calls a helper with a pointer to the second 16-byte field of the record and returns the record pointer. */
char *func_US2_L00_004344A0(char *object)
{
    func_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/us2/levels", func_US2_L00_00434600);

/* Calls a helper with a pointer to the second 16-byte field of the record and returns the record pointer. */
char *func_US2_L00_00434768(char *object)
{
    func_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/us2/levels", func_US2_L00_004347A0);

INCLUDE_ASM("asm/us2/levels", func_US2_L00_004348C8);

INCLUDE_ASM("asm/us2/levels", func_US2_L00_00434B38);

INCLUDE_ASM("asm/us2/levels", func_US2_L00_00434C98);

INCLUDE_ASM("asm/us2/levels", func_US2_L00_00434DE8);

INCLUDE_ASM("asm/us2/levels", func_US2_L00_00434E20);

INCLUDE_ASM("asm/us2/levels", func_US2_L00_00434F48);

INCLUDE_ASM("asm/us2/levels", func_US2_L00_00434FE0);

INCLUDE_ASM("asm/us2/levels", func_US2_L00_00435018);

INCLUDE_ASM("asm/us2/levels", func_US2_L00_00435140);

INCLUDE_ASM("asm/us2/levels", func_US2_L00_004351D8);

INCLUDE_ASM("asm/us2/levels", func_US2_L00_004354E8);

extern int func_0033AF48(char *p);

int func_US2_L00_00435688(char *p)
{
    return func_0033AF48(p + 8);
}

