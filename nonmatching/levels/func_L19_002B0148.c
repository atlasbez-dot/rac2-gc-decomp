/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 804 / 816 bytes; size equality is not a match.
 * us: 0/1 placements; 804/816 bytes.
 * us2: not run / not reported.
 * pal: not run / not reported.
 * Residual: Retained readable C. Default -O2 -G0 -ffunction-sections. Retail uses the same table and fields; reconstruction remains nonmatching.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained readable C. Default -O2 -G0 -ffunction-sections.
 * Retail uses the same table and fields; reconstruction remains nonmatching.
 */
extern unsigned char D_00189E20[];
/* Latest trial: 804/816 bytes, US 0/1. Earlier forms produced 832, 820,
 * 824 and 812 bytes. Remaining differences include address rematerialisation,
 * branch layout and register allocation; equal/nearly equal size is not a match.
 * Reopen with an independently justified player field/layout or control-flow form.
 */
extern void func_00282A88(void *, int);
extern float func_00282C48(float);
extern void func_L19_002C44F8(int, int);
extern unsigned char D_001A7B0B;
extern int D_001A79F0;
extern int D_L19_001A9010;

void func_L19_002B0148(void) {
    unsigned char *player = D_00189E20;
    short state = *(short *)(player + 0x1490);
    unsigned char saved = player[0x149D];
    int active;
    float delta;
    int mode;
    func_00282A88(player + 0x1490, 16);
    *(short *)(player + 0x1490) = state;
    player[0x149D] = saved;
    player[0x22B9] = 0;
    *(short *)(player + 0x348) = 0;
    if (player[0x22BD] != 0) return;
    active = 0;
    if (*(int *)(D_00189E20 + 0x340) != 0 ||
        (*(int *)(D_00189E20 + 0x2294) == 0x7B && *(float *)(D_00189E20 + 0x31C) < 0.4f)) active = 1;
    if (state == -1) return;
    if (state == 2) {
        unsigned char *q = D_00189E20;
        if ( *(short *)(q + 0x1DE) == 0 &&
        (*(short *)(q + 0x34C) == 0 || *(float *)(q + 0x31C) < 2.5f)) {
        q[0x1497] = 1;
        if (q[0x22B4] == 0 && D_001A7B0B != 0)
            *(short *)(q + 0x348) = 1;
    }
    }
    if (state == 14) {
        unsigned char *q = D_00189E20;
        q[0x1494] = 1;
        *(float *)(q + 0x330) = *(float *)(q + 0x318) + 0.2f;
        *(float *)(q + 0x24C4) = 0.2f;
    }
    if (state == 0) {
        unsigned char *q = D_00189E20;
        delta = *(float *)(q + 0x330) - *(float *)(q + 0x318);
        *(float *)(q + 0x24C4) = delta;
        if (delta < 0.85f && delta > 0.25f) q[0x22B9] = 1;
        q[0x1494] = 1;
    }
    if (state == 13) D_00189E20[0x149C] = 1;
    if (state == 1) D_00189E20[0x1495] = 1;
    if (state == 8) D_00189E20[0x149A] = 1;
    if (state == 12) D_00189E20[0x149A] = 1;
    {
    unsigned char *q = D_00189E20;
    if (q[0x1495] && active &&
        (*(int *)(q + 0x2294) != 0x38 || q[0x49E])) {
        if (*(int *)(q + 0x24CC) != 0)
            func_L19_002C44F8(0x38, 1);
        else if (D_001A79F0 == 2 && D_L19_001A9010 != 0)
            func_L19_002C44F8(0x7D, 1);
        else if (*(int *)(*(char **)(*(char **)(q + 0x2290) + 0x24) + 0x1F0))
            func_L19_002C44F8(0x79, 1);
        else
            func_L19_002C44F8(0x39, 1);
    } else if (D_00189E20[0x149C] && *(int *)(D_00189E20 + 0x2294) != 0x7C &&
        func_00282C48(*(float *)(D_00189E20 + 0x330) - (*(float *)(D_00189E20 + 0x88) + 0.25f)) < 1.0f &&
        *(float *)(D_00189E20 + 0x330) - *(float *)(D_00189E20 + 0x88) > 0 &&
        (*(float *)(D_00189E20 + 0x118) < 0 || *(int *)(D_00189E20 + 0x2294) == 0x7B)) {
        func_L19_002C44F8(0x7C, 1);
    }
    }
}
