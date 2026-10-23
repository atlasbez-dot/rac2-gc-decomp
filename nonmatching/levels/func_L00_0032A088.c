/* 0 of 27 places match - last line: 00_aranos_tutorial: instruction at +0x10 differs.
   Every other word is retail's: the 48 bytes are the constant 0xA430 (`ori`),
   the table's address (`lui $v1` / `addiu $a2,$v1,-0x71E0`), the R5900
   three-operand `mult $a1,$a1,$v0` (the low product lands in $a1), the entry
   address, the `lw` of the key at +4, the `bne`, the payload address
   `addiu $v0,$a2,0x20` in the branch's delay slot, the sum `addu $v0,$a1,$v0`
   in the `jr $ra` delay slot and the `daddu $v0,$zero,$zero` of the
   "not found" path.

   The one difference is the operand order of the entry address:
     retail   addu $v0, $a2, $a1      base + index
     this     addu $v0, $a1, $a2      index + base
   The registers are the same in both ($a2 = the table, $a1 = the product), so
   this is GCC's canonicalisation of the sum, not a register allocation
   difference: this cc1 emits the *integer* operand first in a pointer+integer
   sum whenever the pointer is a symbol address or a local variable, and the
   pointer first only when the pointer is a parameter. Measured with ~30
   spellings: `&D + idx*0xA430`, a local base, an integer base, an array
   subscript (`&D[idx*0xA430]`), a struct array (`&g_table[idx]`), a struct
   member, `base + 0x20 + product` and `product + (base + 0x20)`, with the
   symbol declared as an object, as an incomplete array and as a sized array.
   The payload address comes out right in every spelling (this cc1 keeps the
   +0x20 on the base when the payload is written `&D[0x20] + product`), so only
   the entry sum is in the wrong order.

   What would unblock it: a source shape in which the table's address is a
   value (not a constant address) at the point of the sum, so that this cc1
   keeps the pointer operand first.

   Wave 8 (agent w8-08) re-measured the swap and could not move it: the
   pointer-first spelling does NOT come from a pointer PARAMETER. A static
   helper whose base is a parameter (`static u8 *entry_of(u8 *base, s32
   index) { return base + index * 0xA430; }`, inlined) still emits
   `addu $2,$6,$4` (product first) for the helper itself; casting the table
   to an integer (`(u32)D + index * 0xA430`), writing the sum in the other
   source order (`index * 0xA430 + D`) and using a sized array give the same
   `addu $2,$5,$6` (product + base). So the rule "the pointer first only when
   the pointer is a parameter" does not hold here: every spelling measured
   puts the *multiply result* first and the table second, and the retail
   puts the table first. The `mult $a1,$a1,$v0` and the payload sum
   (`addu $v0,$a1,$v0`, product first) are the retail's own, so the entry sum
   is the odd one out in retail too. */

typedef int s32;
typedef unsigned char u8;

extern u8 D_L00_00268E20[];

u8 *func_L00_0032A088(s32 key, s32 index)
{
    u8 *entry = &D_L00_00268E20[index * 0xA430];

    if (*(s32 *)(entry + 4) != key)
        return 0;
    return &D_L00_00268E20[0x20] + index * 0xA430;
}
