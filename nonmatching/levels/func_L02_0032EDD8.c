/* from src/levels/shared/L02_002B5F50.c: not matched. Retail 308 bytes, 9 place(s), first word
 * at L02:0032EDD8.
 *
 * The body is a lookup of the record of a pool that holds the path of an actor: the record's
 * first word names a path in the table D_L02_001FF1C0, the record's float at +0x1C is a
 * radius, and the record's position at +0x10 is compared with the point handed in. The
 * index argument names the record to start from (-1 when there is none) and receives the
 * record that matched.
 *
 * The C below compiles to 284 bytes against retail's 308, and every instruction it emits has
 * retail's counterpart in the same order. The six instructions it lacks are retail's second
 * induction variable: retail keeps the record base in $s0 and the record's position in $s2,
 * a second pointer 0x10 above it with its own 0x20 step, and loads the record's word and
 * radius from $s0. This cc1 always folds the two pointers into one induction variable,
 * whichever way the source spells them:
 *
 *   - the position as a separate walked pointer: the two are related by the constant 0x10,
 *     so the record's word and radius become negative offsets from the position pointer;
 *   - the record base computed from the loop counter: the same fold, with the position
 *     pointer as the induction variable and the record's word at -0x10 from it;
 *   - the position assigned inside the loop: the assignment has a single use, so it is
 *     removed before the loop's induction variables are recognised.
 *
 * What would unblock it: a source form in which the two pointers are not related by a
 * constant, or a compiler profile that keeps both induction variables. The candidate is
 * retained for the next attempt. */
extern unsigned int D_L02_001FC060[];
extern char *D_L02_001B359C;
extern char *D_L02_001FF1C0[];
extern int func_002A8AF0(float *p, float *v, int n);
extern float func_00282E80(void *a, void *b);

int func_L02_0032EDD8(float *point, char *records, int count, int *index) {
    char *rec;
    char *pos;
    char *entry;
    int i;

    if (*index != -1) {
        entry = D_L02_001FF1C0[*(int *)(records + *index * 32)];
        if (func_002A8AF0(point, (float *)(entry + 0x10), *(int *)entry) != 0)
            return 1;
    }
    rec = records;
    for (i = 0; i < count; i++) {
        pos = rec + 0x10;
        if (i != *index && func_00282E80(point, pos) <= *(float *)(rec + 0x1C)) {
            entry = D_L02_001FF1C0[*(int *)rec];
            if (func_002A8AF0(point, (float *)(entry + 0x10), *(int *)entry) != 0) {
                *index = i;
                return 1;
            }
        }
        rec += 0x20;
    }
    *index = -1;
    return 0;
}
