/* 0 of 27 places match - last line: 00_aranos_tutorial: instruction at +0x10 differs.
   The same body as func_L00_0032A088 (the two functions differ only in the
   payload offset, +0x20 here against +8 there): every word is retail's except
   the operand order of the entry address, where retail has
     addu $v0, $a2, $a1      base + index
   and this cc1 has
     addu $v0, $a1, $a2      index + base
   with the same registers ($a2 = the table, $a1 = the product). See
   nonmatching/levels/func_L00_0032A088.c for the ~30 spellings measured. */

typedef int s32;
typedef unsigned char u8;

extern u8 D_L00_00268E20[];

u8 *func_L00_0032A0B8(s32 key, s32 index)
{
    u8 *entry = &D_L00_00268E20[index * 0xA430];

    if (*(s32 *)(entry + 4) != key)
        return 0;
    return &D_L00_00268E20[8] + index * 0xA430;
}
