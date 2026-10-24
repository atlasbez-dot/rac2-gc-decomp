/* 2026-10-23 bounded readable-C attempt.
 * Profile: -O2 -G0 -ffunction-sections.
 * US: 584 versus 588; polygon-pointer spill, successor-index allocation and threshold hoisting differ.
 * All carrying placements checked in us, us2 and pal; no candidate.
 * Tried scalar/TI versus union vectors, pointer grouping, expression/control flow
 * spelling, and applicable qualified copy profiles. Reopen with a demonstrated
 * scheduling or symbol declaration remedy; do not infer handwritten assembly.
 */

extern char *D_L02_001FF1C0[];
extern float func_00282E80(const void *, const void *);

int func_L02_00349BD8(int first, int second, int *firstIndex, int *secondIndex) {
    char *a = D_L02_001FF1C0[first];
    char *b = D_L02_001FF1C0[second];
    int i, j, previousA, previousB;
    char *nextA, *nextB, *priorA, *priorB;
    for (i = 0; i < *(int *)a - 1; ++i) {
        for (j = 0; j < *(int *)b - 1; ++j) {
            if (func_00282E80(a + ((i << 4) + 0x10), b + ((j << 4) + 0x10)) < 0.5f) {
                previousA = i - 1;
                if (i == 0) previousA = *(int *)a - 2;
                previousB = j - 1;
                if (j == 0) previousB = *(int *)b - 2;
                nextA = a + (((i + 1) << 4) + 0x10);
                nextB = b + (((j + 1) << 4) + 0x10);
                if (func_00282E80(nextA, nextB) < 0.5f) {
                    *firstIndex = i; *secondIndex = j; return 1;
                }
                priorA = a + ((previousA << 4) + 0x10);
                if (func_00282E80(priorA, nextB) < 0.5f) {
                    *firstIndex = previousA; *secondIndex = j; return 1;
                }
                priorB = b + ((previousB << 4) + 0x10);
                if (func_00282E80(nextA, priorB) < 0.5f) {
                    *firstIndex = i; *secondIndex = previousB; return 1;
                }
                if (func_00282E80(priorA, priorB) < 0.5f) {
                    *firstIndex = previousA; *secondIndex = previousB; return 1;
                }
            }
        }
    }
    return 0;
}
