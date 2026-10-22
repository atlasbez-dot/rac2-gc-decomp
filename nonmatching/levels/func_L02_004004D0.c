/* func_L02_004004D0 (catalogue row: 384 bytes, 1 place: 02:004004D0) -- NEAR MISS, not integrated,
   and the row itself is not placeable.

   1. The row opens with `addiu $sp,$sp,0x10 ; nop` (0x004004D0, 0x004004D4), straight after the
      previous body's `jr $ra ; addiu $sp,$sp,0x50` (which ends at 0x004004CF): a dead-stripped
      epilogue pair, not C (a C body allocates its frame with a negative `addiu`).  The real entry
      is 0x004004D8, and the level itself says so:
      func_L02_003FAF28 passes D_L02_004004D8 to func_L00_002E6EF8 as a callback.  The body is 376
      bytes.  No C body can start with that pair, so check.py can only say `376 bytes, expected 384`.
      The catalogue needs `(2, 0x004004D0): 8` in tools/levels.py's LEVEL_ENTRY_OFFSETS (the same
      kind of entry as the three level-0 ones) and a regeneration; the row then becomes
      func_L02_004004D8 at 0x004004D8, and the body below is its definition (the extern
      D_L02_004004D8 in L02_003F5430.c would become that function).

   2. The body, compared with retail from 0x004004D8 (the first 8 bytes of the row dropped):
      376 of 376 bytes, every word equal but one adjacent pair in the loop.  The unit would be
      src/levels/02_maktar_nebula/L02_004004D0-g8.c with `-O2 -G8 -ffunction-sections -frac2-qcopy`
      ($gp for the table pointer, the count and the vector at gp+0x2520; the copy is a register
      address `lq`/`sq`).  The pair: retail keeps the first call's two argument moves after the copy,
      `lhu ; lui/lw $s0 ; andi ; sll ; addu ; addiu $v1 ; lq ; sq ; daddu $a0,$s4 ;
      addiu $a1,$gp,0x2520 ; jal`; here both moves are scheduled in the two free issue slots next to
      the `lhu` and the `lw`, ahead of the whole address chain (`daddu $a0,$s4` right after the
      `lhu`, `addiu $a1,$gp` after the `lw`).  Same cause as func_L02_00401BF8: retail's copy is an
      opaque barrier (a volatile asm), the qcopy pattern is not, and the first call's argument
      moves are register-only insns that are ready from the start of the loop block (sched2:
      `$4=$20` at cycle 1, `$5=sym` at cycle 2).
      Diagnostic (NOT a candidate, never in src/): the same body with the copy written as a
      volatile `lq $2,0(%1) ; sq $2,0(%0)` asm with a memory clobber and no -frac2-qcopy compiles to
      retail's bytes from 0x004004D8 exactly (checked with Placement.derive at the row address + 8:
      OK).  -fno-schedule-insns, -fno-schedule-insns2 and both on this unit make it worse (the
      prologue and the compare/branch layout change).

   What does match (all measured, for whoever lands the barrier): the guard chain (index word at
   +0x104, -1, count D_L02_001A9018 and table D_L02_001A9014 as plain externs in the -G8 unit: their
   loads sit in branch delay slots, which the assembler turns into the $gp form), `q = table[idx];
   if (q == 0) return; p = q;` as two names (the `daddu $s2,$v0,$zero`), D_L02_001B3C1C as a plain
   extern pointer (absolute `lui/lw`), D_L02_001B1510 as `char[8]` with sda (`addiu $a1,$gp,0x2520`;
   a 16-byte array comes out absolute), D_L02_001BA500 as an unknown-size array (its `lui` is
   hoisted into $s5 and the `addiu` is -0x5B00), the four vectors in declaration order v0..v3 at
   sp+0, 0x10, 0x20, 0x30, and `d = d - 0.5f; d = d + d; ... d * d` reusing the one float so the
   subtraction stays in $f0 (a separate `t` lands in $f12). */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef short s16;

extern s32 D_L02_001A9018;
extern u16 **D_L02_001A9014;
extern char *D_L02_001B3C1C;
extern char D_L02_001B1510[8] __attribute__((sda));
extern char D_L02_001BA500[];

extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282D30(void *, void *, float);
extern float func_00282DB0(void *, void *);
extern int func_L00_0031C998(int, int, float);
extern void func_L00_00325AE8(void *, int, float, float);

/* Walks the id list the state's group word (+0x104) names.  For each record (64 bytes, base
   D_L02_001B3C1C) it copies the record's quadword at +0x30, moves it with D_L02_001B1510
   (func_00283098, func_00282CC0), takes the vector from there to D_L02_001BA500 (func_00282CF0),
   normalises it and dots it with the record's vector at +0x20 reversed; above 0.5 it asks
   func_L00_0031C998 for a value (colours 0xFF8020 and 0x88FF8020, the square of twice the excess)
   and hands it with the moved point to func_L00_00325AE8. */
void func_L02_004004D0(char *a0) {
    char *state = *(char **)(a0 + 0x68);
    s32 idx = *(s32 *)(state + 0x104);
    u16 *q;
    u16 *p;
    char *e;
    float v0[4];
    float v1[4];
    float v2[4];
    float v3[4];
    float d;

    if (idx == -1)
        return;
    if (idx >= D_L02_001A9018)
        return;
    q = D_L02_001A9014[idx];
    if (q == 0)
        return;
    p = q;
    do {
        e = D_L02_001B3C1C + ((*p & 0x7FFF) << 6);
        *(TI128 *)v0 = *(TI128 *)(e + 0x30);
        func_00283098(v1, D_L02_001B1510, e);
        func_00282CC0(v0, v0, v1);
        func_00282CF0(v2, D_L02_001BA500, v0);
        func_00282F20(v2, v2, 1.0f);
        func_00282D30(v3, e + 0x20, -1.0f);
        d = func_00282DB0(v2, v3);
        if (d > 0.5f) {
            d = d - 0.5f;
            d = d + d;
            func_L00_00325AE8(v0, func_L00_0031C998(0xFF8020, 0x88FF8020, d * d), 3.0f, 1.0f);
        }
    } while ((s16)*p++ >= 0);
}
