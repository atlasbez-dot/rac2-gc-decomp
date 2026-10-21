/* Not landable: this body reaches a 128-bit copy through `qcopy`/`qzero` or a local
   `__asm__` helper, and AGENTS.md's "Plain C" rule (no inline assembly in a function)
   forbids that as a matching route. Kept as a starting point: the shape is right, only the
   quadword copies need a plain-C spelling. Removed from src/ on 2026-10-13, from wave 7. */

/* Wave 24 (worker 07): the 128-bit copy wall, measured in the -G8 unit the body belongs to.

   The body copies one 16-byte record from the object (at +0x10) into two places of the
   state (at +0x50 and +0x60) and then updates four colour words.  Retail keeps every
   128-bit address in a register and uses a zero displacement:

     lw      $a2, 0x68($a0)      ; the state
     addiu   $a0, $a0, 0x10      ; the source
     addiu   $v1, $a2, 0x50      ; the first destination
     lq      $v0, 0x0($a0)
     sq      $v0, 0x0($v1)
     addiu   $a1, $a2, 0x60      ; the second destination
     lq      $v0, 0x0($a0)
     sq      $v0, 0x0($a1)

   This cc1 folds the constant offset of a TI access into the instruction (the reload
   accepts plus(reg, const) for TImode, and the CSE replaces the register with the plus),
   so the two destinations come out as `sq $v0, 0x50($a2)` and `sq $v0, 0x60($a2)`.

   Measured, all in the -G8 unit:
    - the source address survives when the pointer is given the same value in two
      branches (the class of the register then has more than one member and the CSE
      cannot fold it): `addu $6,$4,16 ; lq $2,0($6)`.  The body below does that.
    - the two destinations fold in every spelling tried: the plain member access, the
      pointer variable (`TI128 *dst = state + 0x50; *dst = *src;`), the pointer used
      twice (`dst[0] = *src; dst[1] = *src;`), the same pointer assigned twice, the
      destination given the same value in two branches, the integer base (`u32 base =
      *(u32 *)(obj + 0x68); *(TI128 *)(base + 0x50) = *src;`), and the 32-byte struct
      copy (`*(Pair *)(state + 0x50) = *(Pair *)(obj + 0x10);`, which this cc1 even
      copies in ld/sd).  The two-branch spelling, which works for the source, does not
      work for the destinations.
    - the rest of the body matches: the four `bltz` tests, the $gp load of the colour
      base in the delay slot (`lw $v0, 0x35AC($gp)`, which the assembler produces from
      the bare symbol reference of the sda global) and the four colour stores.

   So the two destination addresses are the whole difference; the source address and
   everything after it are as the retail has them.  The earlier note stands: the retail's
   shape is the PS2 copy macro's (an inline `lq $v0,0(%1); sq $v0,0(%0)` with register
   operands), and src/ has no plain-C spelling for it. */
typedef int TI128 __attribute__((mode(TI)));

typedef unsigned char u8;

typedef int s32;

extern int D_L14_001B259C __attribute__((sda));

void func_L14_003E5030(u8 *obj, int c) {
    char *state = *(char **)(obj + 0x68);
    TI128 *src;
    s32 v;

    if (c) {
        src = (TI128 *)((u8 *)obj + 0x10);
    } else {
        src = (TI128 *)((u8 *)obj + 0x10);
    }
    *(TI128 *)((u8 *)state + 0x50) = *src;
    *(TI128 *)((u8 *)state + 0x60) = *src;
    v = *(s32 *)((u8 *)state + 0x1C);
    if (v >= 0) {
        *(s32 *)((u8 *)state + 0x28) = D_L14_001B259C + (v << 8);
    }
    v = *(s32 *)((u8 *)state + 0x20);
    if (v >= 0) {
        *(s32 *)((u8 *)state + 0x2C) = D_L14_001B259C + (v << 8);
    }
    v = *(s32 *)((u8 *)state + 0x24);
    if (v >= 0) {
        *(s32 *)((u8 *)state + 0x30) = D_L14_001B259C + (v << 8);
    }
    v = *(s32 *)((u8 *)state + 0x38);
    if (v >= 0) {
        *(s32 *)((u8 *)state + 0x3C) = D_L14_001B259C + (v << 8);
    }
}
