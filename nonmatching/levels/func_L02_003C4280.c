/* from src/levels/shared/L02_002B5F50.c: not matched. Retail 368 bytes, 8 place(s), first word
 * at L02:003C4280.
 *
 * The body advances the actor along its path: it copies the next point of the path into the
 * actor, scales it by the actor's own size, and counts the step when the actor has come close
 * enough to the point.
 *
 * The C below compiles to 324 bytes against retail's 368. The float constants are the retail
 * ones (0.03333f, 0.00016666666f, 0.4166667f, 0.88f, 480.0f) and the arithmetic and the call
 * sequence agree with retail, but three things differ:
 *
 *   - the 16-byte copy folds its offsets into the lq/sq here (lq $v0,0x10($a2) and
 *     sq $v0,0x10($a0)) where retail computes both addresses into registers first
 *     (addiu $a0,$a0,0x10 and addiu $v1,$s0,0x10) and uses a zero offset;
 *   - the two float tests come out as branch-likely here (bc1fl) and as plain branches in
 *     retail (bc1f);
 *   - the first argument stays in a caller-saved register here and in $s0 in retail, and the
 *     order of the two register saves differs with it.
 *
 * What would unblock it: the source shape that keeps the copy's two addresses in registers
 * and that keeps the first argument in a callee-saved register, as retail has them. */
typedef int TI128 __attribute__((mode(TI)));

extern void func_00282CF0(float *out, const float *a, const float *b);
extern void func_00282F20(float *out, const float *in, float s);
extern void func_00282CC0(void *a0, void *a1, void *a2);
extern float func_00282E80(void *a, void *b);

typedef struct {
    char pad00[4];
    float value;
    int index;
    float limit;
    char *points;
} Path_003C4280;

void func_L02_003C4280(void *a0, int a1) {
    Path_003C4280 *state = *(Path_003C4280 **)((char *)a0 + 0x68);
    float buf[4];
    float f0;
    float f1;

    if (state->index == *(int *)state->points - 1) {
        state->index = 0;
        *(TI128 *)((char *)a0 + 0x10) = *(TI128 *)(state->points + 0x10);
    }
    if (a1 == 0) {
        if (state->limit < 480.0f) {
            f0 = state->value;
            f1 = 0.03333f / f0;
            f1 = f1 * 0.00016666666f;
            state->value = f0 + f1;
        }
    } else {
        state->value = 0.4166667f;
    }
    func_00282CF0(buf, (float *)(state->points + state->index * 4 + 0x20), (float *)((char *)a0 + 0x10));
    func_00282F20(buf, buf, state->value);
    func_00282CC0((char *)a0 + 0x10, (char *)a0 + 0x10, buf);
    if (func_00282E80((char *)a0 + 0x10, state->points + state->index * 4 + 0x20) <= state->value * 0.88f)
        state->index += 1;
}
