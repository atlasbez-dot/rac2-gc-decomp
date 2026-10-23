/* 0 of 27 places match - last line: 00_aranos_tutorial: instruction at +0x4 differs.
   Exact size (68 bytes), 15 of 17 words identical, and the source is understood: the field at
   +0x190 is lowered to the argument when the argument is below it, the difference against the
   +0x18E short is wrapped modulo 30 and indexes the float table at +0x258.
   The two words left are the order of the first two instructions: retail emits
   `addiu $a3,$zero,0x1E` (the wrap constant, which the modulo needs in a register) BEFORE the
   `lui $a2,hi` half of the base address; this cc1 always emits it between the lui and the
   matching addiu. Five source shapes (wrap local, pointer local, operand order, decimal
   literals, named difference) all give the same pair of words.
   `if (value <= limit)` is what reproduces retail's `slt+movz` lowering of the clamp (a plain
   `if (limit > value)` gives `slt+movn` with the operands swapped).

   Measured again on 22 October 2026 with the compiler rebuilt from the current sources
   (every -frac2-* switch available): the wall is unchanged. The constant is materialised
   in $a3 for the division and the modulo's numerator uses the immediate, exactly as
   retail does; only the slot of the `addiu $a3,$zero,0x1E` differs (retail: before the
   `lui $a2`; here: between the `lui $a2` and its `addiu`). The base address is the boot
   symbol D_00138180 at the same address in every level, so no per-level symbol is needed
   here. Tried and measured: the wrap constant in a local declared first, the index in a
   local, the decimal literal 30 in both places, -fno-schedule-insns, -fno-schedule-insns2,
   -O1, -frac2-gcse-unsplit-edges, -frac2-keep-block-order and -frac2-hazard-labels.
   Without scheduling the constant is materialised twice (once for the numerator, once for
   the divisor) and the body is further off, so the scheduled form is the right one.
   What would unblock it: a lever that moves the divisor's materialisation before the
   %hi/%lo pair of the base address. */

typedef struct {
    char gap_L00_0032F038[0x18E];
    short field_18E;
    int field_190;
    char gap2_L00_0032F038[0xC4];
    float table_258[0x1E];
} Table_L00_0032F038;

extern Table_L00_0032F038 D_00138180;

float func_L00_0032F038(int value)
{
    int limit = D_00138180.field_190;

    if (value <= limit)
        limit = value;
    return D_00138180.table_258[(D_00138180.field_18E - limit + 0x1E) % 0x1E];
}
