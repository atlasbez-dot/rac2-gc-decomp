/* Near miss from src/levels/20_yeedil/L20_002B7A48.c (level-20 wave 5, worker 12).
   Kept as a starting point; not linked, not counted.

   The retail body at 0x002C5A48 (584 bytes, 146 instructions).

   MEASURED (tools/check.py func_L20_002C5A48 --diff): 568 bytes against the
   retail's 584, with the same frame (0x20, three saved registers) and the
   same shape almost everywhere: the "state == 1" block with the two
   func_0029F338 calls, the "state == 4" block with the call to
   func_002AB1F0, the float store, the two 128-bit copies (which do NOT fold
   here either - both are in the retail's "plain register address" shape), the
   two func_L00_002A4DB0 calls and the last block.

   What is left:

     1. the hero block and the argument are in the wrong saved registers: the
        retail has the block in $s0 and the argument in $s1, this build has
        the argument in $s0 and the block in $s1.  The allocation follows the
        order in which the values are first set, and this attempt sets the
        block first - measured and NOT enough: a `char *` and an `s64`
        argument, the argument's copy at the top and at its use, and the
        parameter used without a local all give the same allocation.  It is
        the tie the wave-4 note calls an allocation problem, and it moves
        every access in the body;
     2. the retail reads the global D_L20_001A8F00 in the absolute form
        ("lui $v1,%hi(D)" + "lw $v1,%lo(D)($v1)"); this build takes the
        address in a register of its own ("lui $v0" + "addiu $a0,$v0,%lo(D)"
        + "lw").  The common file says an absolutely addressed INT needs
        __attribute__((nosda)) in a -G0 unit - the next attempt should try it;
     3. the retail's last test ("D[0x2294] != 0x61") is a branch-LIKELY
        ("bnel $v0,$a0") with the call's first argument in its delay slot;
        this build inverts the test and materialises the address of the
        global first;
     4. the "0x3A4" word is masked twice in the retail (with ~1 and then with
        ~2, the two "and"s separated by the store to 0x34E); this build
        produces the same two "and"s but in different registers.

   The 128-bit copies and the float conversion ("lwc1" + "cvt.s.w" + "swc1",
   the value stays in the FPR) are the retail's shape. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef long long s64;
typedef float f32;
typedef int TI128 __attribute__((mode(TI)));

extern char D_00189E20[];
extern void func_0029F338(void);
extern void *func_002AB1F0(s32);
extern void func_0029B758(s32, s32);
extern void func_L00_002B2BD0(void);
extern void func_L00_002A53B8(void);
extern void func_0028B3D0(s32, s32, void *, void *, void *, s32, s32);
extern void func_L00_002F6B90(s32);
extern void func_L00_002A6708(void);
extern void func_L00_002D24B8(void);
extern int func_L00_002A4DB0(char *, s32, s32, char *);
extern void func_L20_002D7730(s32, s32);
extern void func_L00_002D9D98(void);
extern void func_0028BDB0(void);
extern void func_0028BE00(void);
extern void func_0028C6D0(void);
extern s32 D_L20_001B5600[];
extern s32 D_L20_001B5C00[];
extern s32 D_L20_001A8F00[];

void func_L20_002C5A48(char *a0)
{
    char *s0 = D_00189E20;
    char *arg = a0;
    s32 obj;
    s32 p;
    s32 v;

    if (*(u8 *)(s0 + 0x22B4) == 1) {
        *(s32 *)(s0 + 0x24D0) = *(s32 *)(s0 + 0x24CC);
        *(s32 *)(s0 + 0x24CC) = *(s16 *)(s0 + 0x24D4);
        if (*(s32 *)(s0 + 0x1860) != 0) {
            func_0029F338();
            *(s32 *)(s0 + 0x1860) = 0;
        }
        if (*(s32 *)(s0 + 0x1864) != 0) {
            func_0029F338();
            *(s32 *)(s0 + 0x1864) = 0;
        }
    }
    s0 = D_00189E20;
    if (*(u8 *)(s0 + 0x22B4) == 4) {
        p = (s32)func_002AB1F0(*(s32 *)(s0 + 0x2290));
        if (p != 0)
            *(f32 *)p = (f32)*(s32 *)(s0 + 0x24CC);
        v = *(s32 *)(s0 + 0xC18);
        *(TI128 *)(s0 + 0x80) = *(TI128 *)(v + 0x10);
        *(TI128 *)(s0 + 0x90) = *(TI128 *)(v + 0xF0);
        *(s32 *)(s0 + 0x24CC) = *(s16 *)(s0 + 0x24D4);
        if (arg == 0) {
            func_0029B758(0, 0);
        } else {
            func_L00_002B2BD0();
        }
        v = *(s32 *)(s0 + 0x3A4);
        v &= ~1;
        *(u16 *)(s0 + 0x34E) = 1;
        v &= ~2;
        *(u8 *)(s0 + 0x22B5) = 0;
        *(s32 *)(s0 + 0x3A4) = v;
        *(s32 *)(s0 + 0x3A0) = 0;
    }
    func_L00_002A53B8();
    *(u8 *)(s0 + 0x22B4) = 0;
    func_0028B3D0(0x23, 0, (void *)func_0028BDB0, (void *)func_0028BE00,
                  (void *)func_0028C6D0, 0, 0);
    func_L00_002F6B90(3);
    if (*(s32 *)(s0 + 0xC14) != 0)
        *(u16 *)(*(s32 *)(s0 + 0xC14) + 0x34) &= 0xFFF9;
    *(s32 *)(s0 + 0xC14) = 0;
    func_L00_002A6708();
    obj = *(s32 *)(s0 + 0xC18);
    *(s32 *)(s0 + 0x2290) = obj;
    *(TI128 *)(obj + 0x10) = *(TI128 *)(s0 + 0x80);
    *(s32 *)(obj + 0x9C) = 0;
    *(f32 *)(s0 + 0xC24) = 1.0f;
    func_L00_002D24B8();
    obj = *(s32 *)(s0 + 0x2290);
    if (*(u8 *)(obj + 0x42) != 0xFF) {
        v = func_L00_002A4DB0((char *)obj, *(u8 *)(obj + 0x42),
                              *(u8 *)(obj + 0x40), (char *)D_L20_001B5600);
        *(s32 *)(*(s32 *)(s0 + 0x2290) + 0x58) = v;
    }
    v = func_L00_002A4DB0((char *)obj, *(u8 *)(obj + 0x43),
                          *(u8 *)(obj + 0x41), (char *)D_L20_001B5C00);
    *(s32 *)(*(s32 *)(s0 + 0x2290) + 0x5C) = v;
    if (*(s32 *)(s0 + 0x2294) != 0x61) {
        if (D_L20_001A8F00 != 2 && D_L20_001A8F00 != 6)
            func_L20_002D7730(0, 1);
    }
    s0 = D_00189E20;
    if (*(u8 *)(s0 + 0x22B4) == 4)
        func_L00_002D9D98();
}
