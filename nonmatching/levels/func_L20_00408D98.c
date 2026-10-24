/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-gcse-unsplit-edges.
 * Reported final C / retail: 1752 / 1760 bytes; size equality is not a match.
 * us: 0/1 placements; 1752/1760 bytes.
 * us2: 0/1 placements; 1752/1760 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Complete eight-state controller:1776 then1752 bytes against1760. Honest scalar SDA attributes are based on real GP accesses. Mixed absolute/GP choices and persistent high-address allocation differ, along with state-machine scheduling. This reconstruction uses a normal compiler-owned switch; historical computed-goto/ghost-table suggestions above were not used. Reopen with a grounded profile/allocation hypothesis; do not introduce table aliases, fake extents or keepalive barriers.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Near miss from src/levels/20_yeedil/L20_0039C448-g8.c (the -G8 unit).

   No C was written for this body in this wave; what is recorded here is
   the structure that was mapped out of the retail and the walls it runs
   into, so the next attempt starts from the structure and not from the
   disassembly.

   func_L20_00408D98 is 1760 bytes, the biggest body of this unit.  Its
   shape:

     - it dispatches on the byte at +0x20 of its argument through a JUMP
       TABLE, `jtbl_002B5340` (level address 0x002B5340, eight entries,
       the `sltiu $v0,$v1,0x8` guard), so the C needs a `switch` whose
       table lands in .rodata at that address.  A C switch puts its table
       in the unit's own .rodata, which the build cannot place at the
       retail's address - the wall that keeps func_00118CC8 and
       func_00123C28 in nonmatching/ on the boot side.  That has to be
       solved before the body can land, and it is the reason this body
       was not attempted further in this wave;
     - the prologue interleaves the body with the saves (the `lui
       $v1,%hi(D_1CA540)` and the `daddu $s4,$v1` sit between the
       `sd $s2` and the `sd $s0`), the prologue-interleaving wall;
     - the first arm writes the constant 0x42AA0000 (85.0f) through
       D_1B2BE8 with `lui $at` + `mtc1` + `swc1 %lo(D_1B2BE8)($at)` -
       an absolutely addressed float, so the declaration wants
       `nosda` (or a plain `extern float`, which the assembler expands
       into that form);
     - the arms use D_001A79F0 (the $gp base at 0x1AEFF0 - 0x7600) and
       D_0019B2E8 as table bases, with the same `sll ...,4` / `addu`
       shape as func_L20_003BFEB8.

   With 1760 bytes the body has to be worked in blocks against the
   --diff, one arm of the switch at a time; the jump table's placement
   is the first thing to solve.
*/
#include "include_asm.h"

/* ------------------------------------------------------------------
   Wave 21, worker 08.  THE JUMP TABLE ESCAPE WORKS HERE TOO.

   The wall that kept this body out of src/ is gone: the level's own
   jump table can be named and used with a computed goto, and the
   compiler emits exactly the retail's dispatch:

     extern void *D_L20_002B5340[8];
     ...
     goto *D_L20_002B5340[sel];

   compiles to

     lui   $v0,%hi(D_L20_002B5340)
     sll   $a0,$a0,2
     addiu $v0,$v0,%lo(D_L20_002B5340)
     addu  $a0,$a0,$v0
     lw    $v1,0($a0)
     jr    $v1
     nop

   The object gets R_MIPS_HI16/LO16 against the symbol, the build
   resolves the value from the retail's `lui %hi`/`addiu %lo` pair
   (0x002B5340), and the table's CONTENTS come from the level's own
   data section.  The declaration needs a size (8 here): an
   `extern void *D_L20_002B5340[];` never takes the absolute form in
   a -G8 file.

   The table, as the level's data has it:

     jtbl_002B5340 (0x002B5340), eight entries:
       [0] 0x00408E08
       [1] 0x00408EA8
       [2] 0x004090AC
       [3] 0x004090AC
       [4] 0x00409154
       [5] 0x004091E8
       [6] 0x0040925C
       [7] 0x004093BC

   The dispatch's guard is `sltiu $v0,$v1,0x8`, so the index is the
   byte itself (not shifted by one as in func_L20_0039E368).

   With 1760 bytes the body has to be worked arm by arm against the
   --diff; the jump table's placement is no longer the blocker, the
   layout of the eight arms is.

   The attempt below is unchanged: no C was written for this body in
   this wave.
*/

/* ------------------------------------------------------------------
   Wave 23, worker 09.  No C was written for this body in this wave
   (1760 bytes, eight arms); what is measured here is that the jump
   table's escape works with the right NAME and a SIZE, so that the
   next attempt can start from the arms.

   MEASURED: `extern void *jtbl_002B5340[8];` with
   `goto *jtbl_002B5340[sel];` and a
   `static void *volatile tab[8] = { &&c0, ... };` compiles to exactly
   the retail's dispatch:
       lui   $v0,%hi(jtbl_002B5340)
       sll   $a0,$a0,2
       addiu $v0,$v0,%lo(jtbl_002B5340)
       addu  $a0,$a0,$v0
       lw    $v1,0($a0)
       jr    $v1
       nop
   The table of &&labels lands in .data, which the build discards, and
   the eight case bodies stay alive.  The name has to be
   `jtbl_002B5340` (the level's config/undefined_syms_auto.txt has
   `jtbl_002B5340 = 0x2B5340;`); a `D_L20_002B5340` spelling does not
   resolve.  The declaration needs the size: an
   `extern void *jtbl_002B5340[];` never takes the absolute form in a
   -G8 file.

   The table's entries (the level's own data):
     [0] 0x00408E08   [1] 0x00408EA8   [2] 0x004090AC   [3] 0x004090AC
     [4] 0x00409154   [5] 0x004091E8   [6] 0x0040925C   [7] 0x004093BC
   and the dispatch's guard is `sltiu $v0,$v1,0x8`, so the index is the
   byte itself.

   The wall that remains is the arm by arm work: the retail's prologue
   interleaves the body with the saves (the `lui $v1,%hi(D_1CA540)` and
   the `daddu $s4,$v1` sit between the `sd $s2` and the `sd $s0`), the
   first arm writes the constant 0x42AA0000 (85.0f) through D_1B2BE8
   with `lui $at` + `mtc1` + `swc1 %lo(D_1B2BE8)($at)` (an absolutely
   addressed float), and the arms use D_001A79F0 (the $gp base at
   0x1AEFF0 - 0x7600) and D_0019B2E8 as table bases.
*/

/* Manual retained reconstruction; not an exact match.
 * Profile: -O2 -G8 -ffunction-sections -frac2-gcse-unsplit-edges.
 * Complete eight-state controller:1776 then1752 bytes against1760. Honest scalar SDA attributes are based on real GP accesses. Mixed absolute/GP choices and persistent high-address allocation differ, along with state-machine scheduling. This reconstruction uses a normal compiler-owned switch; historical computed-goto/ghost-table suggestions above were not used. Reopen with a grounded profile/allocation hypothesis; do not introduce table aliases, fake extents or keepalive barriers.
 * All carrying releases fail the final complete check; absent catalogue entries are not matches.
 */
#include "common.h"
extern char *D_L20_001B2F9C;
extern char *D_L20_001B308C __attribute__((sda));
extern float D_L20_001B29E0 __attribute__((sda));
extern void func_L20_004095D0(char *);
extern u32 D_L20_001CA540;
extern float D_L20_001B2BE8;
extern int D_001A79F0 __attribute__((sda));
extern u8 D_0019B2E8[];
extern float D_00189EA0[];
extern int D_L20_001A8F08;
extern int D_L20_001A8F00 __attribute__((sda));
extern int func_0029B3E0(int, int);
extern void func_L01_00323310(int, int);
extern void func_L00_00303530(int, int);
extern void func_L00_002B9D60(void *, void *, int, int);
extern int func_002ACBC8(void *, int);
extern void func_002A0430(unsigned int);
extern void func_L00_003294F0(unsigned char *, int);
extern void func_L20_00409480(s32);
extern void func_002A7750(u8 *, u8, s32);
extern s32 func_002B3868(u8 *);
extern int func_00282948(int *);
extern void func_L00_002E6EF8(void (*)(void *), void *);
extern void func_L20_002DC390(int);

/* The platform controller records switch edges and raises its linked platform. */
void func_L20_00408D98(u8 *object) {
    s32 *state = *(s32 **)(object + 0x68);
    char *record;
    int frame_offset;
    int next_state;

    if (D_L20_001CA540 < 2) D_L20_001B2BE8 = 85.0f;
    switch (object[0x20]) {
    case 0:
        frame_offset = D_001A79F0 * 16;
        state[8] = D_L20_001CA540;
        state[5] = 0;
        state[4] = 0;
        state[0x23] = D_0019B2E8[state[2] + frame_offset] >> 7;
        if ((D_0019B2E8[state[1] + frame_offset] & 0x80) == 0) {
            state[0x1F] = 0;
            record = D_L20_001B2F9C + state[0x1C] * 0x100;
            *(float *)(state + 0x1D) = *(float *)(record + 0x18);
            *(float *)(record + 0x18) += 20.0f;
        } else state[0x1F] = 1;
        next_state = 1;
        goto change_state;
    case 1:
        if (state[0x23] == 0 &&
            (D_0019B2E8[state[2] + D_001A79F0 * 16] & 0x80) != 0 &&
            func_002ACBC8(D_00189EA0, state[10]) != 0) {
            state[0x23] = 1;
            func_0029B3E0(0, -1);
        }
        if (D_L20_001CA540 == 2) {
            if (state[4] == 0) {
                if (func_002ACBC8(D_00189EA0, state[0x18])) {
                    state[4] = 1;
                    func_L01_00323310(state[0x20], -1);
                }
            }
        }
        if (func_002ACBC8(D_00189EA0, state[11]) != 0) {
            if (D_0019B2E8[state[1] + D_001A79F0 * 16] & 0x80) return;
            func_002A0430(state[1]);
            if (state[0x13] >= 0)
                func_L00_003294F0((u8 *)D_L20_001B2F9C + state[0x13] * 0x100, 1);
            func_L20_00409480(state[0x14]);
            func_L20_00409480(state[0x15]);
            state[8] = 2;
            state[15] = 3;
            func_002A7750(object, 5, -1);
        }
        if (D_0019B2E8[state[1] + D_001A79F0 * 16] & 0x80) return;
        if (*(s8 *)(D_L20_001B2F9C + state[0x1B] * 0x100 + 0xBC) == 1) return;
        if (state[0x1F] != 0) return;
        record = D_L20_001B2F9C + state[0x19] * 0x100;
        if (record != 0 && *(s16 *)(record + 0xAA) == 0xCBC &&
            *(s8 *)(record + 0x20) != -2 && *(s8 *)(record + 0x20) != -3) return;
        record = D_L20_001B2F9C + state[0x1A] * 0x100;
        if (record != 0 && *(s16 *)(record + 0xAA) == 0xCBC &&
            *(s8 *)(record + 0x20) != -2 && *(s8 *)(record + 0x20) != -3) return;
        next_state = 7;
        goto change_state;
    case 2:
    case 3:
        if (func_002B3868(object)) state[5] = 125;
        if (func_00282948(state + 5)) func_002A7750(object, state[7], -1);
        else if (object[0x20] == 2) *(float *)(state + 3) = 1.0f - (float)state[5] * 0.008f;
        else *(float *)(state + 3) = (float)state[5] * 0.008f;
        func_L00_002E6EF8((void (*)(void *))func_L20_004095D0, object);
        break;
    case 4:
        record = D_L20_001B308C + state[state[15] + 9] * 0x80;
        func_L00_00303530(state[8], state[0x21]);
        func_002A0430(state[0]);
        func_L00_002B9D60(record + 0x30, record + 0x70, 0x6F, 1);
        func_L20_002DC390(0);
        state[7] = 1;
        D_L20_001B29E0 = 1.0f;
        *(float *)(state + 3) = 1.0f;
        func_L00_002E6EF8((void (*)(void *))func_L20_004095D0, object);
        next_state = 6;
change_state:
        func_002A7750(object, next_state, -1);
        break;
    case 5:
        if (D_L20_001A8F08 == -2 && D_L20_001A8F00 != 2) {
            *(float *)(state + 3) = 1.0f;
            func_L00_002E6EF8((void (*)(void *))func_L20_004095D0, object);
            if (*(u8 *)(D_L20_001B2F9C + state[0x13] * 0x100 + 0x20) > 0x80)
                func_002A7750(object, 4, -1);
        }
        state[6]++;
        break;
    case 6:
        if (D_L20_001A8F00 == 2) D_L20_001B29E0 = 0.0f;
        else {
            D_L20_001B29E0 = 1.0f;
            *(float *)(state + 3) = 1.0f;
            func_L00_002E6EF8((void (*)(void *))func_L20_004095D0, object);
            if (D_L20_001A8F00 != 2 &&
                *(u8 *)(D_L20_001B2F9C + state[0x12] * 0x100 + 0x20) > 0x80) {
                *(u16 *)(D_L20_001B2F9C + state[0x17] * 0x100 + 0x34) &= 0xFFFD;
                *(u16 *)(D_L20_001B2F9C + state[0x16] * 0x100 + 0x34) &= 0xFFFD;
                *(u16 *)(D_L20_001B2F9C + state[0x17] * 0x100 + 0x34) &= 0xFFBE;
                *(u16 *)(D_L20_001B2F9C + state[0x17] * 0x100 + 0x34) |= 0x1000;
                record = D_L20_001B2F9C + state[0x17] * 0x100;
                *(int *)(record + 0x98) = *(int *)(*(char **)(record + 0x24) + 0x10);
                *(u16 *)(D_L20_001B2F9C + state[0x16] * 0x100 + 0x34) &= 0xFFBE;
                *(u16 *)(D_L20_001B2F9C + state[0x16] * 0x100 + 0x34) |= 0x1000;
                record = D_L20_001B2F9C + state[0x16] * 0x100;
                *(int *)(record + 0x98) = *(int *)(*(char **)(record + 0x24) + 0x10);
                D_L20_001B29E0 = 0.0f;
                func_002A7750(object, 3, -1);
            }
        }
        state[6]++;
        break;
    case 7:
        if (func_002B3868(object)) {
            record = D_L20_001B2F9C + state[0x1B] * 0x100;
            record[0xBC] = 1;
            state[0x1F] = 1;
            state[0x1E] = *(int *)(*(char **)(record + 0x68) + 0x2C);
            state[6] = state[0x1E];
        }
        *(float *)(D_L20_001B2F9C + state[0x1C] * 0x100 + 0x18) =
            *(float *)(state + 0x1D) + ((float)state[6] * 20.0f) / (float)state[0x1E];
        if (func_00282948(state + 6)) func_002A7750(object, 1, -1);
        break;
    }
}
