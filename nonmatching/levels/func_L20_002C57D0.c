/* Near miss from src/levels/20_yeedil/L20_002B7A48.c (level-20 wave 5, worker 12).
   Kept as a starting point; not linked, not counted.

   The retail body at 0x002C57D0 (504 bytes, 126 instructions).

   MEASURED (tools/check.py func_L20_002C57D0 --diff): 480 bytes against the
   retail's 504, and the first 40 instructions match the retail one for one
   (the prologue with its five saved registers, the %hi copy in the delay slot
   of the first call, the two stores in the delay slots of the calls, the
   "p0 != 4" test with the "0x9C = -1" store in its delay slot and the state
   byte test).  What is left:

     1. the retail re-materialises the hero block from the %hi copy
        ("addiu $v0,$s4,%lo(D)") AFTER the two calls that follow the first
        block; this build hoists the same instruction into the delay slot of
        the first of them (one instruction, in the wrong place);
     2. the retail's masked state byte ("andi $a0,$s1,0xFF") is a separate
        value from the byte it stores ("sb $s1,0x22B4($v0)", unmasked); this
        build shares one masked value between the store and the test, so it
        needs two "andi"s.  The common file's rule applies: separate C
        variables for values that must stay in different registers;
     3. the retail's "p0 == 1" and "p0 == 4" tests are forward branches to
        two out-of-line blocks and the merge point follows them
        ("b .L5980" + "nop"); this build puts the first body in the
        fall-through.  That is the block layout of an if/else-if chain, and it
        is the last difference in the body;
     4. the 128-bit copies DO NOT fold here: both are in the retail's
         "plain register address" shape ("addiu $a0,$s0,0x80" + "lq $v0,0($v1)"
         + "sq $v0,0($a0)"), and this build produces the same shape.

   The three arguments are 32-bit and are copied into $s1/$s2/$s3 with
   "daddu $sN,$aN,$zero" in the order a0, a2, a1 - the order in which the
   source sets them decides the registers, and this attempt sets them in that
   order, so the whole prologue matches. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef long long s64;
typedef float f32;
typedef int TI128 __attribute__((mode(TI)));

extern char D_00189E20[];
extern void func_0028CC98(void);
extern void func_0028CCE0(void);
extern void func_0028D1E8(void);
extern void func_0028B3D0(s32, s32, void *, void *, void *, s32, s32);
extern void func_L00_002AF7D0(void);
extern void func_L00_002B1F90(void);
extern void func_L00_00322EC8(char *);
extern void func_L00_002D2E68(void);
extern void func_L00_002A6708(void);
extern void func_L00_002A53B8(void);
extern void func_L00_002F6B90(s32);
extern void func_L00_002D24B8(void);
extern void func_002A677C(s32);
extern void func_L20_002D7730(s32, s32);
extern void func_L00_002D2168(s32, s32, f32);
extern s32 D_00138320[];

void func_L20_002C57D0(s32 a0, s32 a1, char *a2)
{
    char *D = D_00189E20;
    s32 p0 = a0;
    char *p2 = a2;
    s32 p1 = a1;

    func_L00_002AF7D0();
    *(u8 *)(D + 0x22B6) = 1;
    func_L00_002B1F90();
    *(s32 *)(D + 0x2290) = *(s32 *)(D + 0xC18);
    func_L00_00322EC8(D + 0x18E0);
    func_L00_00322EC8(D + 0x1A30);
    *(s32 *)(*(s32 *)(D + 0x2290) + 0x9C) = -1;
    if (p0 != 4 || *(u8 *)(D + 0x22B4) != p0)
        func_L00_002D2E68();
    func_L00_002A6708();
    func_L00_002A53B8();
    D = D_00189E20;
    *(s32 *)(D + 0x2290) = (s32)p2;
    *(u8 *)(D + 0x22B4) = p0;
    *(s32 *)(D + 0xC14) = (s32)p2;
    if ((p0 & 0xFF) == 1) {
        if (D_00138320[0] & 0x10) {
            func_0028B3D0(0x23, 0, (void *)func_0028CC98, (void *)func_0028CCE0,
                          (void *)func_0028D1E8, 0, 0);
            func_L00_002F6B90(3);
        }
    }
    func_L20_002C63F0();
    D = D_00189E20;
    *(f32 *)(D + 0x250) = *(f32 *)(D + 0x258);
    *(f32 *)(D + 0x254) = *(f32 *)(D + 0x25C);
    *(u16 *)(*(s32 *)(D + 0x2290) + 0x34) |= 6;
    *(f32 *)(D + 0xC24) = 1.0f;
    *(f32 *)(D + 0xC20) = 1.0f;
    func_L00_002D24B8();
    func_002A677C(*(s32 *)(D + 0x2290));
    *(u16 *)(D + 0x24F2) = p1;
    if (p0 == 1) {
        *(u16 *)(D + 0x24D4) = *(u16 *)(D + 0x24CC);
        if (*(s32 *)(D + 0x24D0) < 5)
            *(s32 *)(D + 0x24CC) = *(s32 *)(D + 0x24D0);
        else
            *(s32 *)(D + 0x24CC) = 4;
    } else if (p0 == 4) {
        *(TI128 *)(D + 0x80) = *(TI128 *)(p2 + 0x10);
        *(TI128 *)(D + 0x90) = *(TI128 *)(p2 + 0xF0);
        *(u16 *)(D + 0x24D4) = *(u16 *)(D + 0x24CC);
        *(s32 *)(D + 0x24CC) = 3;
    }
    func_L20_002D7730(p1, 2);
    if (p0 == 4)
        func_L00_002D2168(0xF, 0, 5.0f);
}
