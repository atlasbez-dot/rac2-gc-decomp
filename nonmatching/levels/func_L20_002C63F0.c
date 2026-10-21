/* Near miss from src/levels/20_yeedil/L20_002B7A48.c (level-20 wave 5, worker 12).
   Kept as a starting point; not linked, not counted.

   The retail body at 0x002C63F0 (704 bytes, 176 instructions).

   MEASURED (tools/check.py func_L20_002C63F0 --diff): 688 bytes against the
   retail's 704, and the shape matches: the frame (0x30, two saved registers
   and the $f20 spill), the state byte, the switch on the state with the two
   float blocks out of line, the "0x229C == 4" test, the "0x2294" chain with
   its three float constants and the zero stores, and the D_0018A070 block
   with the two float comparisons and the three calls.

   What is left:

     1. the registers.  The retail keeps the hero block in $a3 (a CALLER-SAVED
        register - it is dead after the float stores) and the %hi copy in $a0,
        and it rebuilds the address from the %hi at every use after the calls
        ("addiu $s0,$a0,%lo(D_189E20)").  This build keeps the hero block in
        $s0 and the %hi in $s1, so it saves a register the retail does not and
        every access has a different base register.  The re-assignment of the
        hero block before the last block (the one this attempt has) is what
        makes the compiler use the split form, but it still keeps the address
        in a saved register;
     2. the float stores' order: the retail stores the first constant in the
        delay slot of the jump to the common block, this build stores it
        before the block;
     3. the state switch: the retail tests the state byte against 1, then
        does a range test ("slti" + "beql") and the tests against 4 and 0; the
        switch below gives the same tests, but the retail's "state == 0" test
        comes after the "state == 4" one.

   THE FLOAT CONSTANTS (the map's decimals were wrong in several places; these
   are the values the retail's hex holds, and the literals are the ones this
   compiler turns into that exact hex):

     0x3F199999 = 0.599999964  ->  0.59999996f
     0x3EE66667 = 0.450000018  ->  0.45000002f
     0x3E99999A = 0.300000012  ->  0.3f
     0x3F4CCCCD = 0.800000012  ->  0.8f
     0x3F333333 = 0.699999988  ->  0.7f
     0x3EE66666 = 0.449999988  ->  0.45f
     0x3F000000 = 0.5          ->  0.5f      (the map called it 1.0f!)
     0x3EB33334 = 0.350000024  ->  0.35000002f
     0x3F07AE14 = 0.529999971  ->  0.53f
     0x3CA3D70A = 0.02         ->  0.02f
     0x3D888889 = 0.06666667   ->  0.06666667f
     0x3F666666 = 0.9          ->  0.9f

   The full retail listing is in the wave's own dump; the map at the top of
   this file has the head of it. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef long long s64;
typedef float f32;
typedef int TI128 __attribute__((mode(TI)));

extern void func_00282E80(void *, void *);
extern void func_002AA2E8(f32 *, f32, f32);
extern void func_002AA3A8(f32 *, f32 *, f32, f32, f32, f32);
extern char D_0018A070[];

void func_L20_002C63F0(void)
{
    char *D = D_00189E20;
    char *E = D_0018A070;
    u8 state = *(u8 *)(D + 0x22B4);
    s32 x;

    switch (state) {
    case 1:
        *(f32 *)(D + 0x258) = 0.59999996f;
        *(f32 *)(D + 0x260) = 0.3f;
        *(f32 *)(D + 0x25C) = 0.45000002f;
        break;
    case 0:
    case 4:
        *(f32 *)(D + 0x258) = 0.8f;
        *(f32 *)(D + 0x260) = 0.45f;
        *(f32 *)(D + 0x25C) = 0.7f;
        break;
    }
    if (*(s32 *)(D + 0x229C) == 4) {
        if (*(s16 *)(D + 0x4AC) < *(s32 *)(D + 0x1B8)) {
            if (*(u8 *)(D + 0x49E) == 0)
                *(f32 *)(D + 0x25C) = *(f32 *)(D + 0x4B8);
        }
    } else if (*(s32 *)(D + 0x2294) == 6) {
        *(f32 *)(D + 0x25C) = 0.5f;
    } else if (*(s32 *)(D + 0x2294) == 4) {
        *(f32 *)(D + 0x258) = 0.35f;
    } else {
        x = *(s32 *)(D + 0x229C) - 0x11;
        if ((u32)x < 2) {
            *(s32 *)(D + 0x25C) = 0;
            *(s32 *)(D + 0x258) = 0;
        } else if (*(u8 *)(D + 0x1492) != 0 && *(s32 *)(D + 0x340) != 0) {
            *(f32 *)(D + 0x258) = 0.8f;
            *(f32 *)(D + 0x25C) = 0.9f;
        } else if (*(s32 *)(D + 0x2294) == 0x7C) {
            *(f32 *)(D + 0x260) = 0.8f;
        }
    }
    D = D_00189E20;
    if (*(u8 *)(D + 0x287) != 0) {
        if (*(s32 *)(D + 0x22A4) != 0x12 && *(s32 *)(D + 0x22B0) != 0x12) {
            if (*(u8 *)(D + 0x22B4) != 0) {
                if (!(*(f32 *)(D + 0x254) < 0.53f) && *(s32 *)(D + 0x229C) != 0x11
                    && *(u8 *)(D + 0x1494) == 0) {
                    func_00282E80(E + 0x240, E + 0x80);
                    if (!(*(f32 *)(D + 0x264) * 0.5f < 0.53f)) {
                        func_002AA2E8((f32 *)E, *(f32 *)(E + 0x8), 0.02f);
                        func_002AA2E8((f32 *)(E + 0x4), *(f32 *)(E + 0xC), 0.02f);
                        func_002AA3A8((f32 *)(E + 0x14), (f32 *)(E + 0x18),
                                      *(f32 *)(E + 0x10), 0.02f, 0.3f, 0.06666667f);
                    }
                }
            }
        }
    }
}
