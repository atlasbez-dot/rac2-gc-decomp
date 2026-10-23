/* Near miss from src/levels/shared/L06_0035EA68-g8.c: 256 bytes, expected 256; 0 of 3 places.
   Kept as a starting point; not linked, not counted.

   The source unit needs -G8 (D_001A79F0 is reached through $gp).

   What still differs against retail (level 06 at 0x0047AC68) is the register allocation
   only; the size and the instruction sequence agree:
   - retail materialises the constant 1 of the first test before the load of the level's
     table, so the table lands in $v1, the constant 1 in $a0, the state in $a1 and the tag
     in $a2; here the table's address takes $a0 first, the constant 1 lands in $a1, the
     state in $a2 and the tag in $a1, and the sign extension of the tag copies the shifted
     value once more;
   - the two loads of the level's table therefore differ in shape (retail keeps the
     address and the value in one register: lui $v1,0x1B ; lw $v1,0x21C4($v1)).

   Two findings for the next attempt:
   - the globals D_0018C0D4, D_0018C0BC and D_00189E20 need __attribute__((nosda)): in a
     -G8 unit they land in the small data section and are reached through $gp, while
     retail reaches them with lui/addiu (and a byte load);
   - the state pointer's fields are at 0x34C and 0x24A0 of one global at 0x189EA0, which
     retail addresses with lui/addiu and then loads with the offset in the instruction, so
     the address has to be taken as a whole (a char * local) rather than folded into the
     load.

   The level's table pointer and the call to func_L06_0047A408 have a different address in
   every level that has this function, so they are refs here. */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern s32 *ref_L06_0047AC68_00 __attribute__((nosda));

extern void ref_L06_0047AC68_01(s32);

extern u8 D_0018C0D4 __attribute__((nosda));

extern s32 D_0018C0BC __attribute__((nosda));

typedef struct {
    char pad0[0x34C];
    s16 field34C;
    char pad1[0x24A0 - 0x34E];
    s32 field24A0;
} L06State;

extern L06State D_00189E20 __attribute__((nosda));

extern int D_001A79F0;

s32 func_L06_0047AC68(s32 a0)
{
    s32 *row;
    s32 *entry;
    char *state;
    u16 tag;

    row = (s32 *)((char *)ref_L06_0047AC68_00 + (*(s16 *)(a0 + 0x84) << 5));
    entry = row + 7;
    state = (char *)*entry;

    if (*(s16 *)(state + 0x48) == 1 && *(s16 *)(state + 0x4A) != 0)
        return 0;
    tag = *(u16 *)(state + 0x2C);
    if (*(s16 *)(state + 0x2C) == 11 && D_0018C0D4 != 2)
        return 0;

    if ((s16)tag == 1 || (s16)tag == 10) {
        if (*(s16 *)(state + 0x2E) != 0)
            goto clear;
        if (D_00189E20.field34C != 0) {
            if (D_001A79F0 != 14)
                return 0;
            if (D_00189E20.field24A0 != 13)
                return 0;
        }
    }
clear:
    if ((s16)tag != 2)
        goto call;
    if (D_0018C0BC == 26)
        goto call;
    *(u16 *)(state + 0x2E) = 0;
    return 0;
call:
    ref_L06_0047AC68_01(a0);
    return 0;
}
