/* Complete nonmatching reconstruction: 1256/1256 bytes.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Placement checks: US: 0/27; US2: 0/27; PAL: 0/27.
 * Both complete144-byte batches, all80 records and both submissions for each of four sides remain. Shape and UV cursors are captured separately before math calls; this reaches1256/1256 bytes with the retail0x270 frame, without a match. Each112-byte record position and the real zero-vector source use clobbering16-byte transfers. Color alpha is converted to unsigned32 before shifting. The radius sum is captured before the vector calls. The first mismatch is+0x10: the candidate saves f26 where retail saves f27; the remaining FP constant live ranges, pointer spills and nested-loop scheduling differ.
 * Reopen with independently justified FP zero/one/radius lifetimes and actual record/packet cursor allocation. Keep both full batches and all submissions; equal size does not establish matching.
 */
#include "common.h"
typedef int Quadword __attribute__((mode(TI)));
typedef float Vector[4] __attribute__((aligned(16)));
typedef struct {
    float vertex[4][4];
    unsigned int color[4];
    float uv[4][2];
    char tail[32];
} __attribute__((aligned(16))) DrawBatch;
extern int D_0018C0B4[];
extern float D_L00_001AF750 __attribute__((sda));
extern int D_L00_001AF74C __attribute__((sda));
extern int D_L00_001AF748 __attribute__((sda));
extern float D_L00_001AF720 __attribute__((sda));
extern float D_L00_001B8DC0[];
extern int D_L00_001A8FF0[];
extern float D_L00_001A8F20[];
extern short D_L00_001AF6D8[][2];
extern short D_L00_001AF6DA[];
extern float D_L00_00294A80[][4];
extern float D_L00_00294B10[][2];
extern float D_L00_00294B14[][2];
extern char *func_L00_0032A088(int, int);
extern void func_00281DE8(void *, int, int, int);
extern int func_00283CF0(float);
extern float func_002ABB18(float);
extern float func_00283198(float);
extern float func_00282C48(float);
extern int func_00283D38(int, int, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_002AFFD8(void *, void *, int);
extern void func_00282DD8(void *, void *, void *);
extern float func_00283180(float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00280B90(void *, void *, int);

/* Builds and submits the two quads for each active effect record. */
void func_L00_003A8940(char *object)
{
    DrawBatch first, second __attribute__((aligned(16)));
    Vector forward, right, up;
    Vector position, normal;
    Vector scaled, local, rotated;
    char *base;
    char *record;
    float alphaScale = 128.0f;
    int i, side, corner, index, texture;
    int alpha;
    unsigned int color;
    float age, radius, distance, sine, cosine, width;
    *(Quadword *)normal = 0;
    normal[3] = 1.0f;
    normal[2] = 1.0f;
    base = func_L00_0032A088(1483, *(short *)(*(char **)(object + 104) + 26));
    func_00281DE8(&first, 54, 0, 128);
    func_00281DE8(&second, 54, 1, 128);
    if (D_0018C0B4[0] == 29)
        alphaScale = 32.0f;
    for (i = 0; i < 80; ++i) {
        record = base + i * 112;
        if (*(short *)(record + 18)) {
            age = (float)*(short *)(record + 16) * *(float *)(record + 32);
            alpha = func_00283CF0(alphaScale * age);
            color = func_00283D38(D_L00_001AF74C, D_L00_001AF748,
                func_00282C48(func_00283198(func_002ABB18(age * 3.1415927f * D_L00_001AF750))));
            color |= (unsigned int)alpha << 24;
            first.color[0] = color;
            first.color[1] = color;
            first.color[2] = color;
            first.color[3] = color;
            second.color[0] = color;
            second.color[1] = color;
            second.color[2] = color;
            second.color[3] = color;
            radius = *(float *)(record + 28);
            distance = (D_L00_001AF720 - radius) * age;
            radius += distance;
            qcopy(position, record);
            func_00282CF0(forward, D_L00_001B8DC0, position);
            func_00282F20(forward, forward, 1.0f);
            if (D_L00_001A8FF0[0])
                func_002AFFD8(position, normal, 1);
            func_00282DD8(right, forward, normal);
            func_00282F20(right, right, 1.0f);
            func_00282DD8(up, right, forward);
            up[3] = 0.0f;
            right[3] = 0.0f;
            forward[3] = 0.0f;
            position[3] = 1.0f;
            sine = func_00283180(*(float *)(record + 20));
            cosine = func_00283198(*(float *)(record + 20));
            for (side = 0; side < 4; ++side) {
                short *shapeCursor = &D_L00_001AF6D8[side * 4][0];
                short *uvCursor = &D_L00_001AF6DA[side * 8];
                float *weights = (float *)(record + 40);
                for (corner = 0; corner < 4; ++corner) {
                    index = *shapeCursor;
                    shapeCursor += 2;
                    texture = *uvCursor;
                    uvCursor += 2;
                    if (weights[index] == 0.0f)
                        qcopy(scaled, D_L00_001A8F20);
                    else
                        func_00282F20(scaled, D_L00_00294A80[index], weights[index]);
                    func_00282CC0(local, D_L00_00294A80[index], scaled);
                    rotated[0] = local[0];
                    rotated[1] = local[1] * sine - local[2] * cosine;
                    rotated[2] = local[1] * cosine + local[2] * sine;
                    rotated[3] = 1.0f;
                    func_00282D30(first.vertex[corner], rotated, radius);
                    width = (1.0f - age) * 0.075f;
                    first.uv[corner][0] = D_L00_00294B10[texture][0];
                    first.uv[corner][1] = D_L00_00294B14[texture][0];
                    func_00282D30(scaled, right, width);
                    func_00282CC0(second.vertex[corner], first.vertex[corner], scaled);
                    func_00282D30(scaled, up, width);
                    func_00282CC0(second.vertex[corner], first.vertex[corner], scaled);
                    second.uv[corner][0] = D_L00_00294B10[texture][0];
                    second.uv[corner][1] = D_L00_00294B14[texture][0];
                }
                func_00280B90(&first, forward, 0);
                func_00280B90(&second, forward, 0);
            }
        }
    }
}
