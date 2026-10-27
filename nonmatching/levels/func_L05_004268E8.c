/* Bounded manual reconstruction, 2026-10-25; not linked.
 * Profile: -O2 -G0 -ffunction-sections.
 * 528/540 bytes; us: 0/4 placements; us2: 0/4 placements; pal: absent from catalogue.
 * The packed color returned by 00283D38 is retained independently of the converted phase and passed
 * to the spawner, correcting the prior draft. Three full 16-byte vectors and the measured four-
 * array state prefix are preserved; no enclosing-object extent is asserted. The frame is 0x80
 * versus retail 0x90, with seven versus eight saved GPRs. The timer pointer merges with the phase
 * induction variable; address sharing and scheduling remain different.
 * Reopen with original independent timer-pointer and state-base lifetime evidence. An unmerged
 * byte-offset trial reached 540 bytes with nine saved GPRs, so equal size did not close it.
 * Prior complete variants and diagnostic dumps are preserved privately.
 * No candidate or linked-build credit is claimed.
 */
#include "common.h"

typedef int ColorWord128 __attribute__((mode(TI)));
typedef union { ColorWord128 word; float f[4]; } ColorVector;
/* The measured prefix contains four phases, rates, timers and scales.
   This view does not establish the extent of the enclosing state object. */
typedef struct {
    float phase[4], rate[4];
    int timer[4];
    float scale[4];
} ColorStatePrefix;
extern int ref_L05_004268E8_00[];
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_00282948(int *);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern float func_00282C48(float);
/* Four packed channels are returned in the integer result bank. The spawner
   consumes the low 32 bits as its color, independently of the converted phase. */
extern u32 func_00283D38(u32, u32, float);
extern char *func_002C2FD8(void *, u32, int, int, int, int, int, float);

void func_L05_004268E8(char *object)
{
    ColorVector buf[3];
    ColorStatePrefix *state;
    float *current, *end;
    int *timer;
    int index;
    float phase, blend;
    u32 color;
    int angle;
    char *particle;

    buf[2].word = *(ColorWord128 *)(object + 0x10);
    state = *(ColorStatePrefix **)(object + 0x68);
    current = state->phase;
    end = state->phase + 4;
    timer = state->timer;
    buf[2].f[2] += 0.25f;
    func_00282CF0(&buf[0], ref_L05_004268E8_00, &buf[2]);
    func_00282F20(&buf[0], &buf[0], -0.3f);
    func_00282F20(&buf[1], &buf[0], 0.1f);
    func_00282CC0(&buf[0], &buf[0], &buf[2]);
    index = 0;
    do {
        phase = *current + state->rate[index];
        *current = phase;
        if (phase >= 255.0f)
            *current = phase - 255.0f;
        else if (phase <= 0.0f)
            *current = phase + 255.0f;
        if (func_00282948(timer) != 0)
            state->timer[index] = 255;
        blend = func_00283CE0(255 - state->timer[index]);
        blend *= 1.0f / 255.0f;
        color = func_00283D38(0x50207FFF, 0x10207FFF,
                             func_00282C48(0.5f - blend));
        angle = func_00283CF0(*current);
        particle = func_002C2FD8(&buf[0], color, angle & 0xFF, 0x35, 1, 2, 0,
                                state->scale[index]);
        if (particle != 0)
            particle[9] = (char)(func_00283CF0(1.0f) + 0x60);
        func_00282CC0(&buf[0], &buf[0], &buf[1]);
        ++current;
        ++timer;
        ++index;
    } while ((int)current < (int)end);
}
