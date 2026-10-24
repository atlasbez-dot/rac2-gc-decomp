/* Signature/interface follow-up, 23 October 2026.
 * Profile: -O2 -G0 -ffunction-sections.
 * USA v1.01: 612/608 bytes, 0/9 carrying placements.
 * USA v2.00: 612/608 bytes, 0/9 carrying placements.
 * PAL: 612/608 bytes, 0/9 carrying placements.
 * func_002AFF38 has its canonical float return and three unsigned-long inputs; func_002A90C8
 * has its canonical four integer inputs and integer result. The unused fifth float
 * expression was a constant.
 * This follows the current linked C contract; it does not independently prove the original
 * source declaration.
 * The retained C remains nonmatching. Earlier sizes and residual offsets below are
 * historical and superseded by this measurement; their reopening hypotheses remain
 * unqualified. No linked build was run for this follow-up.
 */

/* Historical measurements, superseded where inconsistent with the follow-up above. */
/* 2026-10-23 bounded readable-C attempt.
 * Profile: -O2 -G0 -ffunction-sections.
 * US: 620 versus 608; the common vector address is hoisted into extra saved registers; XOR predicate spelling reproduces the retail operation.
 * All carrying placements checked in us, us2 and pal; no candidate.
 * Tried scalar/TI versus union vectors, pointer grouping, expression/control flow
 * spelling, and applicable qualified copy profiles. Reopen with a demonstrated
 * scheduling or symbol declaration remedy; do not infer handwritten assembly.
 */

/* from src/levels/shared/L02_002B5F50.c: not written this wave. Retail 608 bytes, 9 place(s), first word at L02:00332ef0.
 * Rule: MMI/LQ/SQ (op 0x1e).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x00332ef0  addiu       $sp, $sp, -0x50
 *   0x00332ef4  sd          $s0, 0x0($sp)
 *   0x00332ef8  sd          $s1, 0x8($sp)
 *   0x00332efc  daddu       $s0, $a1, $zero
 *   0x00332f00  sd          $s4, 0x20($sp)
 *   0x00332f04  daddu       $s1, $a0, $zero
 * Kept as data for the maintainers. */


typedef int TI128 __attribute__((mode(TI)));
extern void func_L02_00333300(char *, char *);
extern float func_00282E48(void *, void *);
extern TI128 D_L02_001B3210;
extern float func_L02_00329410(void *, void *, int);
extern float func_002AFF38(unsigned long, unsigned long, unsigned long);
extern void func_002AFD88(void *, void *, float, float, float);
extern int func_002B63C0(void *, void *);
extern int func_002A90C8(int, int, int, int);


void func_L02_00332EF0(char *object, char *record, void *target, TI128 *oldPosition, int adjust) {
    int blocked = 0;
    float distance;
    char *position;
    func_L02_00333300(object, record);
    distance = func_00282E48(object + 0x10, &D_L02_001B3210);
    if (distance < *(float *)(record + 0x90) - *(float *)(record + 8)) {
        *(int *)(record + 0x94) |= 2;
        blocked = 1;
    }
    if (((*(int *)(record + 0x38) ^ 1) & 1) && *(short *)(record + 0xC2) < 5 && *(float *)(record + 0x90) + *(float *)(record + 0xC) < distance) {
        *(int *)(record + 0x94) |= 1;
        blocked = 1;
    }
    if (*(short *)(record + 0xC0)) {
        if (*(float *)(record + 0x10) < func_L02_00329410(object, record + 0x50, 0)) {
            *(int *)(record + 0x94) |= 4;
            blocked = 1;
        }
    }
    position = object + 0x10;
    if (blocked) {
        *(TI128 *)position = *oldPosition;
        func_L02_00333300(object, record);
        distance = func_00282E48(position, &D_L02_001B3210);
    }
    if (distance <= *(float *)(record + 0x90) + 0.005f) {
        func_002AFF38((unsigned long)object, (unsigned long)(record + 0xA0), 0);
        if (adjust) func_002AFD88(object, position, 0.0f, 0.0f, *(float *)(record + 0x90) - distance);
        *(short *)(record + 0xC2) = 0;
        ++*(short *)(record + 0xC0);
    } else if (*(float *)(record + 0x90) + *(float *)(record + 0xC) <= distance) {
        *(short *)(record + 0xC0) = 0;
        ++*(short *)(record + 0xC2);
    }
    distance = func_00282E48(position, target);
    *(float *)(record + 0xCC) = distance;
    if (distance <= *(float *)(record + 0x34)) *(int *)(record + 0x94) |= 0x80;
    if ((*(int *)(record + 0x38) & 0x200) && func_002B63C0(object, record))
        func_002A90C8((int)object, 0, 0x10000, (int)position);
}
