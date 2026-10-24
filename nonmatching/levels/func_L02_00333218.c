/* 2026-10-23 bounded readable-C attempt.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * US: 236 versus 232; union local ordering is correct, but copy/address materialization, zero scheduling and result branches differ.
 * All carrying placements checked in us, us2 and pal; no candidate.
 * Tried scalar/TI versus union vectors, pointer grouping, expression/control flow
 * spelling, and applicable qualified copy profiles. Reopen with a demonstrated
 * scheduling or symbol declaration remedy; do not infer handwritten assembly.
 */

/* from src/levels/shared/L02_002B5F50.c: not written this wave. Retail 232 bytes, 12 place(s), first word at L02:00333218.
 * Rule: MMI/LQ/SQ (op 0x1c).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x00333218  addiu       $sp, $sp, -0x60
 *   0x0033321c  .word       0x700014A9                   # INVALID     $zero, $zero, 0x14A9 # 00000000 <InstrIdType: CPU_NORMAL>
 *   0x00333220  .word       0x7FA20020                   # INVALID     $sp, $v0, 0x20 # 00000000 <InstrIdType: CPU_NORMAL>
 *   0x00333224  sd          $s0, 0x30($sp)
 *   0x00333228  sd          $s1, 0x38($sp)
 *   0x0033322c  daddu       $s0, $a0, $zero
 * Kept as data for the maintainers. */


typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } Vec4;
extern void func_00283098(float *, const float *, const float *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(float *, const float *, const float *);
extern int func_00277258(void *position, int flags, char *self, float radius);
extern char D_L02_001C0940[];
extern void func_00282CC0(void *, void *, void *);

int func_L02_00333218(char *object, char *record) {
    Vec4 position;
    Vec4 offset;
    Vec4 initial;
    char *origin = object + 0x10;
    initial.q = 0;
    initial.f[2] = *(float *)(record + 4) + *(float *)record;
    offset.q = initial.q;
    func_00283098((float *)&offset, (float *)&offset, (float *)(object + 0xC0));
    func_00282CC0(&position, origin, &offset);
    if (!func_00277258(&position, *(int *)(record + 0x38) & 2, object, *(float *)record))
        return 0;
    *(int *)(record + 0x84) = *(int *)(D_L02_001C0940 + 0x18);
    *(TI128 *)(record + 0x60) = *(TI128 *)(D_L02_001C0940 + 0x20);
    position.q = *(TI128 *)(D_L02_001C0940 + 0x30);
    func_00282CF0((float *)origin, (float *)&position, (float *)&offset);
    return 1;
}
