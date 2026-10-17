/* 0 of 1 places match - last line: 17_smolg: instruction at +0x34 differs
   The 0x929 sub-state activation: bail unless the object's 0xAA half is 0x929
   and its 0x20 byte is 0, then run the 0x931 setup through an eight-argument
   call (func_327FF8(object, 0x931, 0, 0x931, 4, 6, 0, D_L17_001A8F20)),
   func_3629B8(0, 0, object), raise 0x34 bit 0x41, clear 0x98 and finally set the
   0x20 byte to 1 unless it is already 0xFE or 0xFD (`if (object != 0)` guard from
   the same tail as func_L12_00412DE0, which matches).
   Measured: the if/else spelling below is 164 bytes; the `||` spelling gets every
   instruction right at 160 bytes except one - this cc1 materialises the eighth
   argument's `lui/addiu` pair FIRST, retail keeps it last (after the 4 and 6
   constants). Two more spellings (eighth argument typed s32, or in a local) give
   156 and 164. Blocker: the argument-setup order of the last argument. */
typedef char *ptr;
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern s32 func_L03_003268C0(void *, s32, s32, s32, s32, s32, s32, void *);
extern s32 func_002E5CF8(s32, s32, void *);
extern char D_L17_001A8F20[];

void func_L17_003C71B0(char *a0)
{
    char *s0 = a0;

    if (*(s16 *)(s0 + 0xAA) == 0x929 && *(u8 *)(s0 + 0x20) == 0) {
        func_L03_003268C0(s0, 0x931, 0, 0x931, 4, 6, 0, D_L17_001A8F20);
        func_002E5CF8(0, 0, s0);
        *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) | 0x41;
        *(s32 *)(s0 + 0x98) = 0;
        if (s0 != 0) {
            if (*(u8 *)(s0 + 0x20) != 0xFE) {
                if (*(u8 *)(s0 + 0x20) != 0xFD)
                    *(u8 *)(s0 + 0x20) = 1;
            }
        }
    }
}
