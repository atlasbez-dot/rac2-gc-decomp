/*
 * Measured plain-C near miss, 2026-10-24; default compiler profile.
 * Best candidate size was 304 bytes, equal to retail. tools/check.py reported
 * 0/28 placements in USA, PAL, and US2. All report the first difference at
 * +0x18: retail uses beql with the saved-register restore in its delay slot;
 * the candidate uses beq and starts loading the helper argument in the slot.
 * The loop also differs in pointer-register assignment and branch layout.
 */
extern char D_00189EA0[];
extern float D_00222AE0[];
extern float D_002222E0[];
extern int func_002ACBC8(void *, int);

struct Func00303AC8State {
    unsigned char pad00[4];
    float value04;
    unsigned char pad08[0x2C];
    float value34;
    unsigned char pad38[8];
    int index40;
    int key44;
    unsigned char pad48[4];
    int flags4C;
    unsigned char pad50[0x20];
    float value70;
};

void func_00303AC8(char *param)
{
    struct Func00303AC8State *state = *(struct Func00303AC8State **)(param + 0x68);
    float *destination;
    int i;

    if (state->key44 != -1) {
        if (func_002ACBC8(D_00189EA0, state->key44) != 0) {
            if (!(state->flags4C & 4)) {
                destination = (float *)((char *)D_00222AE0 + (state->index40 << 10) + 8);
                param = (char *)D_002222E0;
                *destination = state->value70 + state->value04;

                for (i = 0; i < 64; ++i, param += 0x20, destination += 4) {
                    if (((~state->flags4C) & 0x10) == 0)
                        continue;
                    if ((i % 8 == 0 || i % 8 == 7) && (((state->flags4C ^ 1) & 1) == 0))
                        continue;
                    {
                        int row = i / 8;
                        if ((row == 0 && state->flags4C == 7) || row == 7) {
                            if (state->flags4C & 2)
                                continue;
                        }
                    }
                    *destination += *(float *)param * state->value34;
                }
            }
        }
    }
}
