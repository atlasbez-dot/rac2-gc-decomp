/* Nonmatching reconstruction, checked 2026-10-23.
   Profile: game -O2 -G0 -ffunction-sections -frac2-qcopy.
   USA v1.01 and USA v2.00: 0/1 carrying placements each.
   PAL: this canonical function is absent from both catalogues.
   712/708 bytes; an extra saved source-position register and global float load/scheduling differ. Vector versus float-array storage, declaration order, copy profiles and literal-versus-global diagnostics were tried. The measured global at D_L02_001B01B8 remains an external object. Reopen with a source shape or qualified profile that reproduces the copy and float-load lifetimes.
   No linked build was run for this draft.
*/

extern float D_L02_001B01B8;
typedef int Vector __attribute__((mode(TI)));
extern float func_00282E48(void *, void *);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_00283248(float, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_002AA548(void *, void *, float, float, float, float);
extern void func_002AAA00(void *, void *, float, float, float, float, int);


int func_L02_003D52A8(char *self) {
    float position[4];
    float delta[4];
    float *p = position;
    char *state = *(char **)(self + 0x68);
    float angle = 1.15f;
    float distance;
    float height;
    float sine;
    float cosine;
    *(Vector *)position = *(Vector *)(self + 0x10);
    distance = func_00282E48(position, *(char **)(state + 0x30C) + 0x10);
    sine = func_00283180(angle);
    cosine = func_00283198(angle);
    height = D_L02_001B01B8 + distance * sine / cosine;
    p[2] = height - 4.2f;
    if (D_L02_001B01B8 + 5.0f < p[2])
        return 0;
    if (p[2] < D_L02_001B01B8 + 0.5f) {
        float scale = 4.7f / (p[2] - D_L02_001B01B8 + 4.2f);
        func_00282CF0(delta, self + 0x10, *(char **)(state + 0x30C) + 0x10);
        delta[2] = 0.0f;
        func_00282D30(delta, delta, scale);
        func_00282CC0(&position, &position, delta);
        func_002AA548(self + 0x10, state + 0x1B0, p[0], 0.025f, 0.025f, 2.5000002f);
        func_002AA548(self + 0x14, state + 0x1B4, p[1], 0.025f, 0.025f, 2.5000002f);
        func_002AAA00(self + 0xF8, state + 0x1C4,
            func_00283248(*(float *)(*(char **)(state + 0x30C) + 0x10) - *(float *)(self + 0x10),
                         *(float *)(*(char **)(state + 0x30C) + 0x14) - *(float *)(self + 0x14)),
            0.003490659f, 0.003490659f, 0.22107507f, 0);
    } else {
        func_002AA548(self + 0x18, state + 0x1B8, p[2], 0.025f, 0.025f, 2.5000002f);
        func_002AAA00(self + 0xF8, state + 0x1C4,
            func_00283248(*(float *)(*(char **)(state + 0x30C) + 0x10) - *(float *)(self + 0x10),
                         *(float *)(*(char **)(state + 0x30C) + 0x14) - *(float *)(self + 0x14)),
            0.003490659f, 0.003490659f, 0.22107507f, 0);
    }
    if (func_00282E48(self + 0x10, &position) < 0.0001f) {
        *(int *)(state + 0x1B8) = 0;
        return 2;
    }
    return 1;
}
