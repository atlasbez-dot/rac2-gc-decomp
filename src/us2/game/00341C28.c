#include "include_asm.h"

typedef unsigned char u8;
extern void *func_003361A8(void *);
extern char *func_00336968(char *);
extern void *func_003363D0(void *);
extern void *func_003366D0(void *);
extern void *func_003361A8(void *);
extern char *func_00336968(char *);
extern void *func_003363D0(void *);
extern void *func_003366D0(void *);

u8 *func_US2_00341C28(u8 *self)
{
    func_003361A8(self);
    func_003361A8(self + 76);
    func_00336968((char *)self + 152);
    func_003361A8(self + 240);
    func_003363D0(self + 316);
    func_003366D0(self + 388);
    return self;
}

INCLUDE_ASM("asm/us2/game", func_US2_00341C78);

INCLUDE_ASM("asm/us2/game", func_US2_00341F40);

INCLUDE_ASM("asm/us2/game", func_US2_003420C0);

extern void func_L00_0042BAD0_6(u8 *);
extern void func_L00_0042BFF8_5(u8 *);
extern void func_L00_0042C290_6(u8 *);
extern void func_00347EA0_1(u8 *);

/* initialises eight in-place sub-records of one object by four routines, then returns the object pointer */
u8 *func_US2_003420D0(u8 *a0) {
    func_L00_0042BAD0_6(a0);
    func_L00_0042BAD0_6(a0 + 76);
    func_L00_0042BAD0_6(a0 + 152);
    func_L00_0042BAD0_6(a0 + 228);
    func_L00_0042BAD0_6(a0 + 304);
    func_L00_0042BFF8_5(a0 + 380);
    func_L00_0042C290_6(a0 + 464);
    func_00347EA0_1(a0 + 568);
    return a0;
}

typedef int s32;

/* stores three consecutive words; byte-identical across all 27 levels. */
void func_US2_00342450(u8 *a0, s32 a1, s32 a2, s32 a3) { *(s32 *)(a0 + 0x310) = a1; *(s32 *)(a0 + 0x314) = a2; *(s32 *)(a0 + 0x318) = a3; }

/* Measured target: byte-identical across all 27 levels. */
void func_US2_00342460(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x230) = a1; }

