/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 868 / 916 bytes; size equality is not a match.
 * us: 0/27 placements; 868/916 bytes.
 * us2: 0/27 placements; 868/916 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: The 0x40 frame agrees; queued-sprite branch/loop layout, resident-base materialization and allocation differ.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Readable manual reconstruction, measured 2026-10-23.
 * Retained profile: -O2 -G0 -ffunction-sections.
 * us: 0 of 27 places match; exit 1.
 * us2: 0 of 27 places match; exit 1.
 * pal: absent from both catalogues (exit 1).
 * The 0x40 frame agrees; queued-sprite branch/loop layout, resident-base materialization and allocation differ.
 * 1 bounded source/profile trials; no exact-C credit is claimed.
 * Live helper inputs and consumed return banks were checked against retail and
 * current definitions. Original scalar-return intent remains unqualified for
 * procedural ASM callees whose results this body does not consume.
 * Reopen with independent layout/lifetime, table-extent or scheduling evidence;
 * no source barriers, register pins, invented aliases or padding were used.
 */

extern unsigned char D_00189E20[];
extern int D_L00_001A8F00;
extern char D_001A7A43;
extern void func_L00_00325AE8(void *, unsigned int, float, float);
extern float func_00283CE0(int);
extern float func_00283198(float);
extern int func_00283CF0(float);
extern void func_0027DDC0(int, int, int, int);
typedef unsigned int Rac2Native_9da4b6b15b3cf4a0_RecordWord180;
typedef unsigned long long Rac2Native_9da4b6b15b3cf4a0_RecordValue180;
extern void func_002FC560(Rac2Native_9da4b6b15b3cf4a0_RecordWord180, Rac2Native_9da4b6b15b3cf4a0_RecordValue180);
extern int func_L00_002ADEA0(int);
extern unsigned int func_00283D38(unsigned int, unsigned int, float);
extern float func_002AA2E8(float *, float, float);

/* Render queued effect sprites and the player's current auxiliary glow. */
void func_L00_002A7A50(void) {
    unsigned char *player = D_00189E20;
    unsigned int color;
    int index, alpha;
    float value, divisor, size, step;
    if (D_L00_001A8F00 == 2 || D_L00_001A8F00 == 6) {
        for (index = 0; index < *(short *)(player + 0x2160); ++index)
            func_L00_00325AE8(player + 0x2080 + index * 16, *(unsigned int *)(player + 0x2100 + index * 4),
                               *(float *)(player + 0x2120 + index * 4), *(float *)(player + 0x2140 + index * 4));
        return;
    }
    if (*(short *)(player + 0x21C)) {
        value = func_00283CE0(*(short *)(player + 0x21C));
        divisor = func_00283CE0(18);
        value = func_00283198(value * 3.1415927410125732f / divisor);
        alpha = func_00283CF0((value * 0.5f + 0.5f) * 80.0f);
        func_0027DDC0(0xAA, 0, 0, alpha);
        func_002FC560(0x47, 0x5360B);
    }
    if (player[0x22B4] == 3) {
        color = *(unsigned int *)(player + 0x2508);
        for (index = 0; index < 3; ++index)
            func_L00_00325AE8(player + 0x1FE0 + index * 16, color, 0.2f, 0.08f);
    } else if (player[0x22B4] == 0) {
        if ((func_L00_002ADEA0(3) == 3 || func_L00_002ADEA0(3) == 2) && !*(short *)(player + 0x24FC)) {
            if (*(short *)(player + 0x2500)) {
                value = 1.0f;
                if (value < *(float *)(player + 0x2020)) value = *(float *)(player + 0x2020);
                if (value < *(float *)(player + 0x2024)) value = *(float *)(player + 0x2024);
                if (value < *(float *)(player + 0x2028)) value = *(float *)(player + 0x2028);
                func_00283D38(0xC0000028U, 0x28, value);
            }
            func_L00_00325AE8(player + 0x2010, 0xC0000028U, 0.05700000002980232f, 0.08f);
        }
        for (index = 0; index < *(short *)(player + 0x2160); ++index)
            func_L00_00325AE8(player + 0x2080 + index * 16, *(unsigned int *)(player + 0x2100 + index * 4),
                               *(float *)(player + 0x2120 + index * 4), *(float *)(player + 0x2140 + index * 4));
    } else if (player[0x22B4] == 2) {
        func_L00_00325AE8(player + 0x2010, 0x300000C0U, 0.25f, 0.08f);
    } else if (player[0x22B4] == 1) {
        size = *(short *)(player + 0x2520) ? 0.101500004529953f : 0.07f;
        if (!D_001A7A43) step = 0.02f;
        else { step = 0.01f; size *= 1.7f; }
        *(float *)(player + 0x2018) -= step;
        func_002AA2E8((float *)(player + 0x186C), size, 0.003f);
        func_L00_00325AE8(player + 0x2010, *(unsigned int *)(player + 0x2524), *(float *)(player + 0x186C), 0.08f);
    }
}
