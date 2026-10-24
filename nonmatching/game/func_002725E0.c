/* Retained manual reconstruction, 2026-10-24.
 * Profile: -O2 -G0 -ffunction-sections.
 * Final measurements: us: 0/28 placements, exit1, 980 compiled bytes; us2:
 * 0/28 placements, exit1, 980 compiled bytes; pal: 0/28 placements, exit1,
 * 980 compiled bytes.
 * Remaining: The 0x100 frame and complete sixteen-marker algorithm are
 * reconstructed; GPR/FPR allocation and scheduling differ, and 24 extra
 * bytes remain. Both ninth/tenth stack arguments retain 64-bit colour and
 * texture packet values.
 * Reopen with: Independent local-vector/state-layout and live-range
 * evidence explaining the seven saved FPRs and stack colour-offset counter.
 * No byte-match or linked-build credit is claimed.
 */
/* Draw sixteen projected markers with distance and screen-edge fades. */
typedef struct { float x, y, z, w; } MarkerVector;
typedef struct {
    unsigned char *target;
    int active;
    float timer;
    int reserved;
    short alpha[16];
    short texture[16];
    unsigned int colour[16];
    float interpolation[16];
    float scale[16];
} MarkerStateView;
extern MarkerStateView D_001B5640;
extern MarkerVector D_001B5340;
extern int D_001A7348, D_001A734C, D_001A7350, D_001A7354;
extern float func_00282E48(MarkerVector *, MarkerVector *);
extern float func_00283CE0(int);
extern void func_00279BD8(MarkerVector *, MarkerVector *);
extern long func_0027C878(int);
extern float func_00282C48(float);
extern int func_00283CF0(float);
extern void func_0027E018(int x, int y, int width, int height,
                        int u, int v, int uw, int vh, long colour, long texture);

void func_002725E0(void)
{
    MarkerVector projected;
    float centre[2], delta[2], scaled[2], point[2];
    float distance;
    MarkerStateView *state = &D_001B5640;
    int i;
    if (state->active != 1 || (state->target[0x20] & 0x80)) {
        state->active = 0;
        return;
    }
    if (state->timer <= 0.0f) return;
    distance = func_00282E48(&D_001B5340, (MarkerVector *)(state->target + 0x10));
    centre[0] = func_00283CE0(D_001A7348);
    centre[1] = func_00283CE0(D_001A734C);
    func_00279BD8(&projected, (MarkerVector *)(state->target + 0x10));
    projected.x = (projected.x - func_00283CE0(D_001A7350)) * 0.0625f;
    projected.y = (projected.y - func_00283CE0(D_001A7354)) * 0.0625f;
    delta[0] = centre[0] - projected.x;
    delta[1] = centre[1] - projected.y;
    for (i = 0; i < 16; ++i) {
        long texture = func_0027C878(state->texture[i] + 6);
        int width = i ? 32 : 64;
        int size, x, y;
        float fade = distance - 5.0f;
        float fade_x, fade_y, radius;
        unsigned int colour;
        scaled[0] = delta[0] * state->interpolation[i];
        scaled[1] = delta[1] * state->interpolation[i];
        point[0] = centre[0] + scaled[0];
        point[1] = centre[1] + scaled[1];
        if (fade > 1.0f) fade = 1.0f;
        else if (fade < 0.0f) fade = 0.0f;
        fade_x = func_00282C48(delta[0]) / centre[0] * -5.0f + 5.5f;
        if (fade_x > 1.0f) fade_x = 1.0f;
        else if (fade_x < 0.0f) fade_x = 0.0f;
        fade_y = func_00282C48(delta[1]) / centre[1] * -5.0f + 5.5f;
        if (fade_y > 1.0f) fade_y = 1.0f;
        else if (fade_y < 0.0f) fade_y = 0.0f;
        fade *= fade_x * fade_y;
        colour = (func_00283CF0(fade * (float)state->alpha[i]) << 24) |
                 (state->colour[i] & 0xFFFFFF);
        size = func_00283CF0((float)width * state->scale[i]);
        radius = (float)(size >> 1);
        x = func_00283CF0(point[0] - radius);
        y = func_00283CF0(point[1] - radius);
        func_0027E018(x, y, size, size, 0, 0, width, width, (int)colour, texture);
    }
    state->timer = 0.0f;
}
