#include "include_asm.h"

/* func_002CA790 - 276 bytes, 28 places (the boot and every level), retail at
   0x002CA790.

   Near miss (wave 2, worker 2).  The body is recovered: the function clears the
   mode word of the game state (D_001F2840), calls func_2FC138(1), copies the
   state's 16 bytes at +0x50 and +0x60 into D_001B5340, writes the state's float
   at +0xF8 to D_001C90F0, calls func_28B338(0) and func_279FF0, zeroes the
   fields at +0x118, +0x11C, +0x114 and +0x20, and then dispatches on the mode
   word at +0x1C: the modes 3, 4, 5 and 6 call func_27D330(0x10) and then
   func_132B28(0x5D), every other mode calls only func_132B28(0x5D).  After
   that it calls func_288D30 (and func_2B7320 when it returns 0), func_132028,
   func_2E4AC8, and, when the byte at +0xDB is set, func_2B7CE0(1) and clears
   the byte; then func_2B8518.

   The C below reproduces every call, every field offset and the branch
   structure, but three things differ:

   1. the retail materialises the address of the 16-byte copy's source
      (`addiu $a0,$s0,0x50` ; `lq $v0,0($a0)`), this cc1 folds the constant
      offset into the `lq` itself (`lq $v0,0x50($s1)`).  Measured with eight
      source shapes (a struct member, a char* plus an offset, a void* cast, an
      unsigned int cast, a 128-bit type with alignment 1, a pointer variable,
      the destination as a symbol) and with the SDK compiler 2.95.3: every one
      of them folds the offset, and no matched function in the repository uses
      `lq` at all, so this looks like a difference in the 128-bit address
      handling of the two compilers;
   2. the retail keeps the high half of D_001F2840's address in the callee-saved
      $s1 (it needs it after the calls, and the last two accesses are made
      through $s1), this cc1 keeps it in $a1 and the pointer in $s1;
   3. the retail materialises D_001C90F0's base before func_28B338 and puts the
      store in the call's delay slot, this cc1 moves the base later.

   What was tried: the struct's field layout, the copies through a TI128 pointer
   and through the struct member, the `sda` attribute on the externs (it turns
   the int store gp-relative, which the retail does not do), the branch shape
   (the retail calls func_27D330 and func_132B28 one after the other inside one
   `if`), and the order of the stores.

   What would unblock it: the 128-bit load's address handling (see 1) - with it,
   the rest of the body is within a few instructions.
*/

typedef int TI128 __attribute__((mode(TI)));

/* The game's global state at 0x1F2840: the mode word, the reset counters, the
   spawn table and the flags the reset touches. */
typedef struct {
    char reserved_000[0x1C];
    int field_01C;
    int field_020;
    char reserved_024[0x2C];
    TI128 field_050;
    TI128 field_060;
    char reserved_070[0x60];
    int field_0D0;
    char reserved_0D4[0x7];
    unsigned char field_0DB;
    char reserved_0DC[0x1C];
    float field_0F8;
    char reserved_0FC[0x18];
    int field_114;
    int field_118;
    int field_11C;
} GameState_2CA790;

extern char D_001F2840[];
extern char D_001B5340[];
extern float D_001C90F0[];

extern void func_2FC138(int);
extern void func_28B338(int);
extern void func_279FF0(void);
extern void func_27D330(int);
extern void func_132B28(int);
extern int func_288D30(void);
extern void func_2B7320(void);
extern void func_132028(void);
extern void func_2E4AC8(void);
extern void func_2B7CE0(int);
extern void func_2B8518(void);

void func_002CA790(int a0)
{
    GameState_2CA790 *s = (GameState_2CA790 *)(void *)D_001F2840;
    TI128 *dst = (TI128 *)D_001B5340;
    TI128 *src = (TI128 *)((char *)s + 0x50);
    int mode;

    s->field_0D0 = a0 ? 2 : 1;
    *(int *)(void *)D_001F2840 = 0;
    func_2FC138(1);
    dst[0] = *src;
    src = (TI128 *)((char *)s + 0x60);
    dst[1] = *src;
    *(float *)D_001C90F0 = s->field_0F8;
    func_28B338(0);
    func_279FF0();
    mode = s->field_01C;
    s->field_118 = 0;
    s->field_11C = 0;
    s->field_114 = 0;
    s->field_020 = 0;
    if (mode == 3 || mode == 4 || mode == 6 || mode == 5) {
        func_27D330(0x10);
        func_132B28(0x5D);
    }
    if (s->field_01C == 2) {
        if (func_288D30() == 0)
            func_2B7320();
    }
    func_132028();
    func_2E4AC8();
    if (s->field_0DB) {
        func_2B7CE0(1);
        s->field_0DB = 0;
    }
    func_2B8518();
}
