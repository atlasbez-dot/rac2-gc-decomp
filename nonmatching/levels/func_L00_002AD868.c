/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 672 / 728 bytes; size equality is not a match.
 * us: 0/19 placements; 672/728 bytes.
 * us2: 0/19 placements; 672/728 bytes.
 * pal: 0/19 placements; 672/728 bytes.
 * Residual: The 0xC0 frame agrees; nine GPR inputs including the ninth stack flag are retained. Base/index allocation, copied-vector scheduling and output metadata stores differ.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Readable manual reconstruction, measured 2026-10-23.
 * Retained profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0 of 19 places match; exit 1.
 * us2: 0 of 19 places match; exit 1.
 * pal: 0 of 19 places match; exit 1.
 * The 0xC0 frame agrees; nine GPR inputs including the ninth stack flag are retained. Base/index allocation, copied-vector scheduling and output metadata stores differ.
 * 2 bounded source/profile trials; no exact-C credit is claimed.
 * Live helper inputs and consumed return banks were checked against retail and
 * current definitions. Original scalar-return intent remains unqualified for
 * procedural ASM callees whose results this body does not consume.
 * Reopen with independent layout/lifetime, table-extent or scheduling evidence;
 * no source barriers, register pins, invented aliases or padding were used.
 */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
extern unsigned char D_00189E20[];
extern unsigned char *D_L00_001B16C0;
extern int D_L00_001B16C4;
extern float func_00282E48(const void *, const void *);
extern float func_00282E80(const void *, const void *);
extern float func_00282C48(float);
extern int func_002761F8(Vector *, Vector *, unsigned int, void *, void *);
extern int func_L00_00341FA8(void *, Vector *, Vector *, int *, float *, int, float, float, float);

/* Find an eligible nearby path and return its projection and owner metadata. */
int func_L00_002AD868(Vector *source, void **pathOut, Vector *destination,
                      int *segmentOut, float *offsetOut, int *modeOut,
                      void *excludePath, void *requiredPath, int ignoreObstruction) {
    Vector origin = *source;
    Vector upper, lower;
    int index, segment, clear;
    float offset, radius, height, distance, vertical;
    unsigned char *entry;
    void *path;
    for (index = 0; index < D_L00_001B16C4; ++index) {
        entry = D_L00_001B16C0 + index * 0x20;
        path = *(void **)(entry + 0x10);
        if (excludePath && path == excludePath) continue;
        if (requiredPath && path != requiredPath) continue;
        if (*(int *)path == 0) continue;
        distance = func_00282E48(entry, &origin);
        entry = D_L00_001B16C0 + index * 0x20;
        if (*(float *)(entry + 0xC) < distance) continue;
        if (!func_L00_00341FA8(*(void **)(entry + 0x10), &origin, destination,
                              &segment, &offset, *(int *)(entry + 0x14), 12.0f, 10.0f, 0.0f)) continue;
        radius = 0.9f;
        height = 1.5f;
        if (*(unsigned int *)(D_00189E20 + 0x229C) < 2) radius = 0.3f;
        if (*(short *)(D_00189E20 + 0x1F6)) { radius += 0.5f; height = 10.0f; }
        clear = 1;
        if (!ignoreObstruction) {
            upper = *destination;
            lower = *destination;
            upper.f[2] += 0.25f;
            lower.f[2] -= 1.0f;
            if (!func_002761F8(&upper, &lower, 2, 0, 0)) clear = 0;
        }
        distance = func_00282E80(&origin, destination);
        vertical = func_00282C48(origin.f[2] - destination->f[2]);
        if (distance < radius && vertical < height && clear) {
            *pathOut = *(void **)(D_L00_001B16C0 + index * 0x20 + 0x10);
            *segmentOut = segment;
            *offsetOut = offset;
            *modeOut = *(int *)(D_L00_001B16C0 + index * 0x20 + 0x14);
            return 1;
        }
    }
    return 0;
}
