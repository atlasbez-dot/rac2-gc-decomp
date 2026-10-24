/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 552 / 572 bytes; size equality is not a match.
 * us: 0/27 placements; 552/572 bytes.
 * us2: 0/27 placements; 552/572 bytes.
 * pal: 0/27 placements; 552/572 bytes.
 * Residual: Complete572-byte retail lifecycle reconstructed; C is552 bytes. Two retail quadword copies into otherwise unused local snapshots are eliminated before the qualified qcopy models can retain them, reducing the frame from0x70to0x50. No artificial volatile was introduced. Reopen only with a grounded compiler model or new lifetime evidence.
 * Reopening condition: New ABI/CFG/allocator evidence or a measured compiler-model improvement; do not repeat tied forms.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained complete manual reconstruction; not an exact match.
 * Source profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Complete572-byte retail lifecycle reconstructed; C is552 bytes. Two retail quadword copies into otherwise unused local snapshots are eliminated before the qualified qcopy models can retain them, reducing the frame from0x70to0x50. No artificial volatile was introduced. Reopen only with a grounded compiler model or new lifetime evidence.
 */
#include "common.h"
typedef int EffectQuadword __attribute__((mode(TI)));
extern void func_002AFFD8(char *, char *, int);
extern void func_00300190(void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern int func_00282948(int *);
extern void func_0029F338(void *);
extern int func_002A77E0(int);
extern void *func_002C65A0(void *, void *, int, unsigned int, int, int, int, float, float, float, int);
extern void func_L00_002E6EF8(void (*)(void *), void *);
extern char D_L00_001A8F20[];
extern unsigned char *D_L00_001FEA14;
extern void func_L00_003FC468(char *);
extern void func_L00_003FCDB0(char *);

/* Advance the emitter, spawn its paired particles, and discard out-of-bounds owners. */

void func_L00_003FC228(char *object) {
    EffectQuadword before;
    EffectQuadword scratch;
    EffectQuadword after;
    char *state = *(char **)(object + 0x68);
    char *position = object + 0x10;
    unsigned char *particle;
    int phase;
    before = *(EffectQuadword *)position;
    func_002AFFD8(position, (char *)&scratch, 1);
    after = *(EffectQuadword *)position;
    func_00300190(position, position);
    func_00300190(state + 0x50, state + 0x50);
    if (*(unsigned char *)(object + 0x20) == 0) {
        func_00282CC0(state + 0x50, state + 0x50, state + 0x20);
        if (func_00282948((int *)(state + 0x38))) {
            func_0029F338(object);
            return;
        }
        phase = func_002A77E0(255);
        particle = func_002C65A0(position, D_L00_001A8F20, 2, 0x00202080,
                               phase, 64, 16, 420000.0f, 420000.0f, 0.0f, 0);
        if (particle != 0) particle[2] = *D_L00_001FEA14;
        particle = func_002C65A0(position, D_L00_001A8F20, 2, 0x00202080,
                               (phase + 128) % 255, 64, 16, 420000.0f, 420000.0f, 0.0f, 0);
        if (particle != 0) particle[2] = *D_L00_001FEA14;
        func_L00_002E6EF8((void (*)(void *))func_L00_003FC468, object);
    }
    if (*(float *)(object + 0x10) < 2.0f || *(float *)(object + 0x10) > 1021.0f ||
        *(float *)(object + 0x14) < 2.0f || *(float *)(object + 0x14) > 1021.0f ||
        *(float *)(object + 0x18) < 2.0f || *(float *)(object + 0x18) > 1021.0f)
        func_0029F338(object);
}
