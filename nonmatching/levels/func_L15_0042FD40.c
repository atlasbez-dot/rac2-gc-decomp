/* Near miss from src/levels/15_gorn/L15_00315428-g8.c: the build refuses this body at its
   place — instruction at +0xc differs. Kept as a starting point;
   not linked, not counted. */

/* Standalone declarations recovered from src/levels/15_gorn/L15_00315428-g8.c. */
extern int D_L15_001B1530 __attribute__((sda));

extern int D_L15_001B1534 __attribute__((sda));

extern int D_L15_001B15C4 __attribute__((sda));

extern unsigned char D_L15_00221E10[];

extern unsigned char D_L15_0029FD80[];

extern int func_80381310(int a0);

extern void func_80380770(int a0, void *a1);

extern void func_80383FB8(void);

extern void func_803807B0(void);

void func_L15_0042FD40(void)
{
    char *stage = D_L15_00221E10;
    char *p;
    int n;

    D_L15_001B1530 = -2;
    *(int *)(stage + 0x2C) = 1;
    *(int *)(stage + 0x28) = 100;
    D_L15_001B15C4 = 1;
    D_L15_001B1534 = 0;
    n = func_80381310(6);
    *(int *)(stage + 0x14) = 0;
    *(float *)(stage + 0x30) = 8.0f;
    p = (char *)(D_L15_0029FD80 + n * 40);
    *(int *)(p + 0x14) = *(int *)(p + 0x10);
    func_80380770(0, p);
    func_80383FB8();
    func_803807B0();
}

/* ---------------------------------------------------------------------------
 * wave 24, worker 14: the frame, the saves, the call to func_80381310 with its
 * ten arguments, the 0.002f-style float store and the three stage hooks all
 * match; the body is 148 bytes, the retail's size, but the order of the
 * constant materialisations and of the two stores into the stage record differ
 * (this cc1 emits `addiu $v1,$zero,0x64` and the store to +0x28 before the
 * constant 1 and the store to +0x2C, retail the other way round), and the
 * record address is computed with the operands the other way round
 * (`addu $v0,$v0,$v1` here, retail's `addu $a1,$v1,$v0`) and lands in $v0
 * instead of the argument register $a1.
 * The address form of the stage record itself matches only when the global is
 * taken into a pointer (`u8 *st = D_L15_00221E10;`): with the global used
 * directly this cc1 splits the address (the %hi in a register, the %lo added
 * at every use) and the frame grows.
 * Tried: the record address as `D + n*40`, as `&D[n*40]`, as `p = D; p += n*40`
 * and through a pointer variable; the callback's address inline and in a local.
 */

extern int D_L15_001B1530 __attribute__((sda));
extern int D_L15_001B1534 __attribute__((sda));
extern int D_L15_001B15C4 __attribute__((sda));
extern unsigned char D_L15_00221E10[];
extern unsigned char D_L15_0029FD80[];
extern int func_80381310(int a0);
extern void func_80380770(int a0, void *a1);
extern void func_80383FB8(void);
extern void func_803807B0(void);

void func_L15_0042FD40_w24(void)
{
    unsigned char *st = D_L15_00221E10;
    int n;
    unsigned char *p;

    D_L15_001B1530 = -2;
    *(int *)(st + 0x2C) = 1;
    *(int *)(st + 0x28) = 100;
    D_L15_001B15C4 = 1;
    D_L15_001B1534 = 0;
    *(int *)(st + 0x14) = 0;
    n = func_80381310(6);
    *(float *)(st + 0x30) = 8.0f;
    p = D_L15_0029FD80 + n * 40;
    *(int *)(p + 0x14) = *(int *)(p + 0x10);
    func_80380770(0, p);
    func_80383FB8();
    func_803807B0();
}
