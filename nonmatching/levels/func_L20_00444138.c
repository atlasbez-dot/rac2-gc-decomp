/* 0 of 1 places match - last line: 20_yeedil: 152 bytes, expected 156
   The walk is recovered from the matched sibling recipe (L01_003CAFE0-g8.c, L04_00422A00-g8.c):
   a `for` over the 0x100-stride object list whose bound D_L20_001B2FA0 is re-read every
   iteration (the body stores, so this cc1 reloads it on both paths) and whose id arm is a
   `(u16)(id - 0x1233) < 2 || id == 0x1231 || id == 0x1232` chain; the loop body and tail match
   word for word, including the bnel with the 0xAA halfword in its delay slot. Three residues:
   (1) retail re-materialises the bound with a fresh `lui $v0,0x1B; lw $v0,0x2FA0($v0)` on the
   storing path where this cc1 keeps the %hi in a caller-saved register and loads `0($t0)`
   (one word short, 152 bytes); (2) retail keeps a `nop` between the loop head's
   `lhu $v1,0xAA($a0)` and the `addiu $v0,$v1,-0x1233`; (3) the bound's two reloads carry two
   different addressing forms in retail (a `$gp` word in the bne's delay slot, the absolute
   word on the storing path) - a second name (`D_L20_001B2FA0_1` as `sda`, this file's form
   uses `nosda` for both) reproduces the `$gp` form but turns the `bne` into a `bnel` and
   costs the same one word. Declaring the bound `sda` outright is worse (144 bytes, the arm
   inlines before the tail). */
#include "common.h"

extern u8 *D_L20_001B2F9C __attribute__((nosda));

extern u8 *D_L20_001B2FA0 __attribute__((nosda));

/* Flags the 0x31/0x34 pair of every live 0x1233/0x1234/0x1231/0x1232 object in the level's
   list run. */
void func_L20_00444138(void)
{
    u8 *p;

    for (p = D_L20_001B2F9C; p <= D_L20_001B2FA0 && *(u8 *)(p + 0x20) != 0xFF;
         p += 0x100) {
        u16 id = *(u16 *)(p + 0xAA);

        if ((u16)(id - 0x1233) < 2 || (s16)id == 0x1231 || (s16)id == 0x1232) {
            *(u8 *)(p + 0x31) = 0;
            *(u16 *)(p + 0x34) = *(u16 *)(p + 0x34) | 1;
        }
    }
}
