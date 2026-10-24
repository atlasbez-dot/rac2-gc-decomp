/* Reconstructed 2026-10-23; -O2 -G0 -ffunction-sections.
 * us: 0/2, us2: 0/2, pal: 0/2.
 * Same 224-byte size and 0x50 frame.
 * First remaining mismatch +0x58: first helper argument setup and induction initialization scheduling.
 * Four meaningful trials; typed table restores s5 and the expected frame, but an explicit do-loop produced 244 bytes.
 * Reopen with a natural lifetime/loop-order witness.
 */
/* Previous screening/attempt notes are preserved below as historical provenance. */
/* func_L03_0038B408, 224 bytes, 2 places.  ABANDON - frame and loop rotation.
   Read in full: for the four ints at p+0x28 (p = *(char **)(a0+0x68)) it takes
   q = D_L03_001FE700[p[0x28+i*4]] and, when q is nonzero, runs
   func_L03_0038B2E8(buf, q, p[0x38]) then walks q+0x10 by 0x10 for p[0x38] entries calling
   func_00282CF0(v, v, buf) and func_00282CC0(v, v, p+0xE0).
   Two shapes measured, 204 and 212 bytes against 224: retail keeps the table base in $s5
   and saves s0-s5 in a 0x50 frame, both candidates reach the table through $s4 with a 0x40
   frame, and the inner walk is rotated differently (`v += 0x10` at the top of the body
   against the peeled form). The first differing word is +0x0C, the frame itself.
   What would unblock it: the register set for a table base that outlives two calls. */

#include "include_asm.h"

#include "common.h"

extern void func_L03_0038B2E8(void *, void *, int);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern float (*D_L03_001FE700[])[4];

void func_L03_0038B408(unsigned char *object)
{
    float center[4];
    unsigned char *state = *(unsigned char **)(object + 0x68);
    int *groups = (int *)(state + 0x28);
    float (**table)[4] = D_L03_001FE700;
    float (*vertices)[4];
    int i, j;
    for (i = 0; i < 4; i++) {
        vertices = table[*(int *)((unsigned int)groups + (i << 2))];
        if (vertices != 0) {
            j = 0;
            func_L03_0038B2E8(center, vertices, *(int *)(state + 0x38));
            for (vertices++; j < *(int *)(state + 0x38); j++) {
                func_00282CF0(vertices, vertices, center);
                func_00282CC0(vertices, vertices, state + 0xE0);
                vertices++;
            }
        }
    }
}
