/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 552 / 560 bytes; size equality is not a match.
 * us: 0/1 placements; 552/560 bytes.
 * us2: not run / not reported.
 * pal: not run / not reported.
 * Residual: Retained readable C: -O2 -G0 -ffunction-sections, US 0/1, 556/560 bytes. Direct globals reached 552 bytes; whole-function local base reached 516. A measured partial field layout did not improve the result. Remaining differences are base rematerialisation, allocation and scheduling. Reopen with independent evidence for the original player-camera access layout.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained readable C: -O2 -G0 -ffunction-sections, US 0/1, 556/560 bytes.
 * Direct globals reached 552 bytes; whole-function local base reached 516.
 * A measured partial field layout did not improve the result. Remaining differences
 * are base rematerialisation, allocation and scheduling. Reopen with independent
 * evidence for the original player-camera access layout.
 */
extern unsigned char D_00189E20[];
extern float func_00282E80(void *, void *);
extern float func_002AA2E8(float *, float, float);
extern float func_002AA3A8(float *, float *, float, float, float, float);

void func_L19_002B6278(void) {
    if (D_00189E20[0x22B4] == 0 || D_00189E20[0x22B4] == 4) {
        *(float *)(D_00189E20 + 0x258) = 0.8f;
        *(float *)(D_00189E20 + 0x260) = 0.45f;
        *(float *)(D_00189E20 + 0x25C) = 0.7f;
    }
    if (*(int *)(D_00189E20 + 0x229C) == 4) {
        if (*(short *)(D_00189E20 + 0x4AC) < *(int *)(D_00189E20 + 0x1B8) && D_00189E20[0x49E] == 0)
            *(float *)(D_00189E20 + 0x25C) = *(float *)(D_00189E20 + 0x4B8);
    } else if (*(int *)(D_00189E20 + 0x2294) == 6) {
        *(float *)(D_00189E20 + 0x25C) = 0.5f;
    } else if (*(int *)(D_00189E20 + 0x2294) == 4) {
        *(float *)(D_00189E20 + 0x258) = 0.350000024f;
    } else if ((unsigned)(*(int *)(D_00189E20 + 0x229C) - 17) < 2) {
        *(float *)(D_00189E20 + 0x25C) = 0;
        *(float *)(D_00189E20 + 0x258) = 0;
    } else if (*(int *)(D_00189E20 + 0x2294) == 0x7C) {
        *(float *)(D_00189E20 + 0x260) = 0.8f;
    }
    if (D_00189E20[0x287] == 0 || *(int *)(D_00189E20 + 0x22A4) == 18 || *(int *)(D_00189E20 + 0x22B0) == 18 ||
        (D_00189E20[0x22B4] == 0 && *(float *)(D_00189E20 + 0x254) < 0.53f) ||
        *(int *)(D_00189E20 + 0x229C) == 17 || D_00189E20[0x1494] != 0 ||
        func_00282E80(D_00189E20 + 0x240, D_00189E20 + 0x80) > *(float *)(D_00189E20 + 0x264) * 0.5f) {
        unsigned char *player = D_00189E20;
        float *current = (float *)(D_00189E20 + 0x250);
        func_002AA2E8(current, *(float *)(player + 0x258), 0.02f);
        func_002AA2E8(current + 1, *(float *)(player + 0x25C), 0.02f);
        func_002AA3A8(current + 5, current + 6, *(float *)(player + 0x260), 0.02f, 0.3f, 0.06666667f);
    }
}
