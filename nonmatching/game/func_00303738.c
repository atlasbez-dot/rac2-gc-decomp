/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections (reported default game profile).
 * Reported final C / retail: 900 / 908 bytes; size equality is not a match.
 * us: 0/28 placements; 900/908 bytes.
 * us2: 0/28 placements; 900/908 bytes.
 * pal: 0/28 placements; 900/908 bytes.
 * Residual: Address/load reuse and scheduling; signed modulo and five-point accumulation preserved.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Nonmatching surface vertex construction, 2026-10-23. Two bounded source forms.
 * Default profile:900/908 bytes, correct 0x10 frame; US/US2/PAL each 0/28, exit 1.
 * Signed remainder coordinates and ordered five-sample sums are preserved.
 * Scalar load/address reuse, flag-test lowering and color packing still differ.
 * Explicit complemented flags/equivalent packing yielded the same bytes.
 * Reopen only with new measured source/type evidence; no artificial barrier.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { float x,y,z,w; } V4_F213135aa;
typedef struct { float position, height, reserved08[2], noise, reserved14[3]; } SurfaceSample;
typedef struct { V4_F213135aa position[4]; u32 color[4]; float uv[4][2]; } SurfacePacketView;
extern V4_F213135aa ref_00303738_00[];
extern SurfaceSample ref_00303738_01[];
#define SURFACE_NOISE(column, row) (ref_00303738_01[(column) % 8 + ((row) % 8) * 8].noise)

/* Fill one vertex, color and a pair of perturbed repeating surface coordinates. */
void func_00303738(char *object, SurfacePacketView *packet, int column, int row, int vertex)
{
    char *state = *(char **)(object + 0x68);
    int cell = row * 8 + column;
    V4_F213135aa *source = &ref_00303738_00[*(int *)(state + 0x40) * 64 + cell];
    V4_F213135aa *destination = &packet->position[vertex];
    float u, v, sum;
    u32 shade;
    destination->x = source->x;
    destination->y = source->y;
    destination->w = 1.0f;
    destination->z = source->z;
    if (~*(u32 *)(state + 0x4c) & 0x40) {
        shade = (int)(ref_00303738_01[cell].height * 48.0f + 80.0f);
        packet->color[vertex] = ((shade << 16) | ((shade << 8) | 0x80000000U)) + 0x80;
    }
    if (~*(u32 *)(state + 0x4c) & 0x20) {
        u = (float)column * *(float *)(state + 0x28);
        packet->uv[vertex][0] = u;
        sum = SURFACE_NOISE(column, row) + SURFACE_NOISE(column + 1, row)
            + SURFACE_NOISE(column - 1, row) + SURFACE_NOISE(column, row + 1)
            + SURFACE_NOISE(column, row - 1);
        packet->uv[vertex][0] = u + *(float *)(state + 0x2c) * sum;
        v = (float)row * *(float *)(state + 0x28);
        packet->uv[vertex][1] = v;
        sum = SURFACE_NOISE(column + 4, row + 4) + SURFACE_NOISE(column + 5, row + 4)
            + SURFACE_NOISE(column + 3, row + 4) + SURFACE_NOISE(column + 4, row + 5)
            + SURFACE_NOISE(column + 4, row + 3);
        packet->uv[vertex][1] = v + *(float *)(state + 0x2c) * sum;
    }
}
#undef SURFACE_NOISE
