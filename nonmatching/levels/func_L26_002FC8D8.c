/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G64 -Wa,-G64 -ffunction-sections.
 * Prior worker coverage: US 0/1; US2 0/1; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Historical screening note follows; superseded by the measured manual reconstruction below. */
/* Historical analysis (summary).
 * Historical screening described the mode guard, selected group-record walk, transform scratch
 * and final state update, but did not reconstruct C. The measured manual reconstruction below
 * supersedes that screening and corrects its loop count to four iterations. Its two matrices and
 * four-vector GP input have their full accessed extents. The earlier decoded instruction
 * sequence and address map remain private.
 */

#include "include_asm.h"

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G64 -Wa,-G64 -ffunction-sections
 * Measured text: 360 bytes; retail: 384 bytes. Stack frame 0xC0; retail 0xC0.
 * Final coverage: US 0/1, US2 0/1, PAL absent. Absences are not matches.
 * 1 measured source/profile forms. Selector comparisons fold differently and register/address
 * lifetimes differ. The two matrix temporaries are 48 bytes each; the GP vertex input is a
 * complete four-vector array, so G64 is intentional. The retail countdown performs four
 * iterations, superseding the historical three-iteration note. Reopen with a new
 * selector/control-flow or register-lifetime hypothesis.
 * All carrying checks are nonmatches (exit 1); no linked-build credit.
 */

extern int D_001A79F0;
extern char D_L26_001BC880[];
extern char D_L26_0027E310[];
extern float D_L26_001A93E0[4][4] __attribute__((sda));
extern void func_00283AF0(void *, void *);
extern void func_00283958(void *, void *);
extern void func_00283098(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);

void func_L26_002FC8D8(void) {
    float matrix[12];
    float rotation[12];
    char *child = 0;
    int index = -1;
    char *hero = D_L26_001BC880;
    float *out;
    float *vertex;
    float scale;
    int count;
    if (D_001A79F0 != 26) return;
    if (*(int *)(hero + 0x30) == 0 || *(int *)(hero + 0x30) == 1) {
        index = 1;
        child = *(char **)(hero + 0x194);
    }
    if (index != -1 && child != 0 && *(int *)(hero + 0x18C + index * 4) != 0) {
        *(char **)(hero + 0x50) = D_L26_0027E310;
        out = (float *)(D_L26_0027E310 + 0x20);
        vertex = D_L26_001A93E0[0];
        func_00283AF0(*(char **)(child + 0x58) + 0x10, rotation);
        func_00283958(rotation, matrix);
        scale = *(float *)(child + 0x2C) / *(float *)(*(char **)(child + 0x24) + 0x24);
        count = 3;
        do {
            func_00283098(out, vertex, matrix);
            vertex += 4;
            func_00282D30(out, out, scale);
            func_00282CC0(out, out, child + 0x10);
            out += 4;
        } while (--count >= 0);
        *(int *)(*(char **)(hero + 0x50) + 0x68) = *(int *)(hero + 0x18C + index * 4);
    }
    if (*(int *)(hero + 0x34) >= 0x597) *(char **)(hero + 0x50) = 0;
}
