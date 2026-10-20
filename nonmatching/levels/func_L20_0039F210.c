#include "include_asm.h"

typedef unsigned int u32;
typedef int TI128 __attribute__((mode(TI)));

/* Near miss from src/levels/20_yeedil/L20_0039C448.c: 32 bytes; 28-byte candidate; 0/1.
    (Replaces an earlier draft from commit adcbd51, which used the inline-assembly `qcopy`
    helper that AGENTS.md's "Plain C" rule forbids; that draft is in that commit.)
    The only difference left is the 128-bit copy: retail materialises the destination
    pointer first (`addiu $v1,$a0,0x10; lq $v0,0($a1); sq $v0,0($v1)`) while this cc1 folds
    the constant offset into the store (`sq $v0,0x10($a0)`).  Measured again in this wave with
    about twenty further spellings, all of which fold the offset: a TI128 pointer variable, an
    array index, a struct member, a union, `volatile`, `aligned(1)`/`aligned(4)` TI types, an
    integer cast (signed and unsigned), a `short` truncation (which does keep the address in a
    register, but adds `sll`/`sra` and costs three instructions), a `unsigned long long` address
    (which keeps the address in a register, but adds `daddu` plus `dsll`/`dsra`), a pointer
    loaded from memory, a pointer used twice, two C names for the same pointer, and a pointer
    kept across a call.  The rule that holds: this cc1 folds a constant offset into the
    `lq`/`sq` whenever the address is a `plus` of a register; the address only stays in a
    register when it comes from something that is not a `plus` (a load, a call result) or when a
    mode conversion forces it (which then costs extra instructions).
    Same wall as the other TI copies in this level. */
void func_L20_0039F210(char *arg0, char *arg1, int arg2) {
    char *dst = arg0 + 0x10;
    char *state;

    *(TI128 *)dst = *(TI128 *)arg1;
    state = *(char **)(arg0 + 0x68);
    *(int *)state = 5;
    *(int *)(state + 0xC) = arg2;
}
