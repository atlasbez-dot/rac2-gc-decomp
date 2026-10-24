/* Retained near miss, 24 October 2026. Game -O2 -G8 -ffunction-sections.
 * USA v1.01, PAL and USA v2.00: 176/184 bytes, 0/28 places each.
 * Six checker invocations, no scratch compiles. Raw byte-view/SDA source was
 * 168 bytes; the typed view below recovers the 0x30 frame and saved registers.
 * A nosda scalar declaration grew the body to 200 bytes with extra saves.
 * Retail constructs the scalar address and first load absolutely, then reads
 * the same word through gp. This source makes all three accesses GP-relative.
 * The size mismatch prevents relocation-qualified placement/binding checks.
 * Step/target/timer names express inferred roles, not runtime verification.
 * Reopen with evidence for the real scalar storage/declaration and its two
 * addressing forms, retaining one canonical identity and truthful interfaces.
 */
/* Advances the shared scalar towards the stored target and updates its timer. */
typedef struct {
    char prefix[0x268];
    float step;
    float target;
    int timer;
} ScalarTransitionView;
extern ScalarTransitionView D_L00_001B8C80;
extern float D_L00_001B18E0 __attribute__((sda));
extern float func_002AA2E8(float *, float, float);
extern int func_00282948(void *);

void func_002721C8(void)
{
    ScalarTransitionView *state = &D_L00_001B8C80;

    if (state->step != 0.0f) {
        func_002AA2E8(&D_L00_001B18E0,
                     state->target, state->step);
        if (D_L00_001B18E0 == state->target) {
            if (func_00282948(&state->timer) == 1)
                state->target = 0.0f;
        }
        if (D_L00_001B8C80.target <= 0.0f && D_L00_001B18E0 <= 0.0f)
            D_L00_001B8C80.step = 0.0f;
    }
}
