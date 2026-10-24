/* Manual C near miss retained on 2026-10-24; no exact-C credit.
 * Measured unit: src/levels/shared/L00_00310D30.c
 * Game compiler profile: -O2 -G0 -ffunction-sections -g
 * Compiled/US retail bytes: 820/844.
 * Actual release checks: US: 0/27 (exit 1); US2: 0/27 (exit 1); PAL: 0/27 (exit 1).
 * Residual: The 0x10 frame and initial animation checks agree. Field reload/CSE decisions and table-index algebra differ. Debug labels add 8 bytes of division padding.
 * Reopen only for: A concrete alias/view explanation for retail next-frame/model reloads and separate table offsets.
 * The ASM marker and trial-only flags were restored after measurement.
 */

/* Animation frame advancement and decoding. Partial views retain only fields read here. */
typedef struct AnimationState310D30 {
    short index, count;
    unsigned char active, events, currentPacked, nextPacked;
    char pad08[8];
    char *output;
    unsigned char *model;
    unsigned char *nextModel;
    void *next;
    unsigned char currentFrame, nextFrame, currentTrack, nextTrack;
    float phase, rate, frameScale;
    char pad30[8];
    unsigned char *currentData, *nextData;
} AnimationState310D30;
extern void func_L00_003110E8(AnimationState310D30 *, int, int, unsigned char *);
extern void func_002A1130(unsigned char *, unsigned int, unsigned char *, int);
extern int func_0011AEA0(int);
extern void func_L00_00314D40(AnimationState310D30 *);
void func_L00_00310D30(void *unused, AnimationState310D30 *state)
{
    unsigned char *track;
    unsigned int data;
    short duration;
    state->events = 0;
    if (state->rate != 0.0f && state->frameScale != 0.0f) {
        state->phase += state->rate * state->frameScale;
        if (state->rate > 0.0f) {
            if (state->phase > 0.99f && state->phase < 1.01f)
                state->phase = 1.0f;
            while (state->phase >= 1.0f) {
                state->events |= 1;
                state->currentPacked = state->nextPacked;
                state->currentFrame = state->nextFrame;
                if (state->nextPacked)
                    state->currentData = state->nextData;
                state->nextFrame++;
                state->currentTrack = state->nextTrack;
                track = *(unsigned char **)(state->model + 0x48 + state->nextTrack * 4);
                if (state->nextFrame >= track[0x10]) {
                    state->nextFrame = 0;
                    state->events |= 2;
                }
                state->phase = (state->phase - 1.0f) / state->frameScale;
                track = *(unsigned char **)(state->model + 0x48 + state->currentTrack * 4);
                if (track[0x13] == 0xff) {
                    state->frameScale = **(float **)(track + 0x1c + state->currentFrame * 4);
                } else {
                    data = *(unsigned int *)(track + 0x1c + state->currentFrame * 4);
                    duration = *(short *)(data & 0x0fffffff);
                    if (duration == 0)
                        state->frameScale = 0.0f;
                    else
                        state->frameScale = 1.0f / duration;
                }
                state->phase *= state->frameScale;
            }
        }
    }
    if (state->currentPacked) {
        func_L00_003110E8(state, state->currentTrack, state->currentFrame, state->currentData);
    } else {
        track = *(unsigned char **)(state->model + 0x48 + state->currentTrack * 4);
        if (track[0x13] == 0xff) {
            state->currentData = *(unsigned char **)(track + 0x1c + state->currentFrame * 4);
        } else {
            func_002A1130(track + 0x1c + (track[0x10] + track[0x13]) * 4,
                *(unsigned int *)(track + 0x1c + state->currentFrame * 4),
                state->currentData, state->model[8]);
            func_0011AEA0(0);
        }
    }
    if (state->nextPacked) {
        func_L00_003110E8(state, state->nextTrack, state->nextFrame, state->nextData);
    } else {
        track = *(unsigned char **)(state->model + 0x48 + state->nextTrack * 4);
        if (track[0x13] == 0xff) {
            state->nextData = *(unsigned char **)(track + 0x1c + state->nextFrame * 4);
        } else {
            func_002A1130(track + 0x1c + (track[0x10] + track[0x13]) * 4,
                *(unsigned int *)(track + 0x1c + state->nextFrame * 4),
                state->nextData, state->model[8]);
            func_0011AEA0(0);
        }
    }
    func_L00_00314D40(state);
}
