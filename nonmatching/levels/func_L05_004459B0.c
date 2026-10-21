/* func_L05_004459B0 (232 bytes, 4 places) - best attempt, NOT MATCHED.
 *
 * tools/check.py func_L05_004459B0 --diff:
 *   "05_feltzin_system: 240 bytes, expected 232" (the same for levels 10, 15 and 25).
 *
 * The walk over the twelve entries of the record, the two calls of func_002ACBC8, the
 * call of func_00282DB0 and the return value are right; four measured differences remain:
 *   (a) the frame: retail keeps four callee-saved registers ($s0-$s3, 0x40 bytes), this
 *       cc1 keeps six ($s0-$s5, 0x50 bytes) because the pointer into the record and the
 *       %hi of D_001B260C are live across the calls;
 *   (b) the "id" is taken from the record through $s4 (`addiu $s4,$a0,0x24` and a reload
 *       `lw $s0,0x0($s4)` per iteration) while retail keeps it in $s0 and adds 4 to it;
 *   (c) retail compares with `c.olt.s $f20,$f0` (ordered less than), this cc1 emits
 *       `c.lt.s $f20,$f0`: retail's left operand is a float variable this cc1 folds to
 *       the constant 0.0f, and the two forms differ;
 *   (d) retail's negative-id test is `bltzl` with the counter increment in the delay slot
 *       (a likely branch), this cc1 emits a plain `bltz` and jumps to the increment.
 *
 * What was measured to get here:
 *   - the source shape: `entry = *(char **)(D_001B1EC4 + (*(short *)(self + 0x84) << 5) + 0x1C)`,
 *     `p = entry + 0x24` and `tbl = D_001B251C + (*(int *)(entry + 0x20) << 8)` reproduce
 *     retail's register use (the record in $s0, the table in $s3, the counter in $s2);
 *   - the global word must be read once and directly: `char *base = D_001B1EC4;` splits the
 *     `lui`/`lw` into two registers, while the inline use keeps retail's coalesced
 *     `lui $v0,%hi ; lw $v0,%lo($v0)` shape;
 *   - in the -G8 sibling file (L05_00428350-g8.c) the frame becomes retail's 0x40 bytes,
 *     but D_001B260C then goes into small data (`lw $v0,0x0($gp)`) while retail uses
 *     `lui $v0,0x1B ; lw $v0,0x260C($v0)`, so that unit cannot be the one either.
 *
 * To retake: a float local this cc1 cannot fold to a constant 0.0f (so that the compare
 * becomes the ordered form), and a record pointer that does not need a sixth
 * callee-saved register.
 */

extern char *D_001B1EC4;

extern char *D_001B251C;

extern char *D_001B260C;

extern int func_002ACBC8(void *point, int index);

extern float func_00282DB0_2(char *a, char *src);

/* Walks the twelve entries of the record at +0x24 and reports whether the bound helper
   returned a positive value for one of them. */
int func_L05_004459B0(void *arg)
{
    char *self = arg;
    char *entry;
    char *p;
    char *tbl;
    int count;
    int id;
    int v;
    float best = 0.0f;

    entry = *(char **)(D_001B1EC4 + (*(short *)(self + 0x84) << 5) + 0x1C);
    p = entry + 0x24;
    tbl = D_001B251C + (*(int *)(entry + 0x20) << 8);

    for (count = 0; count < 12; count++) {
        v = *(int *)p;
        if (v < 0)
            continue;
        if (func_002ACBC8(self + 0x30, v) != 0) {
            id = v;
        } else {
            if (func_002ACBC8(tbl + 0x10, v) == 0)
                continue;
            id = v;
        }
        best = func_00282DB0_2(D_001B260C + (id << 7), self);
        if (best > 0.0f)
            return 1;
    }
    return 0;
}
