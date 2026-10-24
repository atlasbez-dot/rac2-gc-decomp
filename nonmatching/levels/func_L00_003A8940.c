/* Retained reconstruction, 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * USA v1.01/v2.00 and PAL: 0/27 each, 1272/1256 bytes. Two source trials and a corrected
 * absolute-data declaration measured. The complete nested rendering loops are reconstructed,
 * including both submissions to the second batch. Register/spill allocation and madd-result
 * consumption differ; the compiler emits madd naturally but follows it with mflo here. Reopen
 * with record/loop lifetime and aliasing evidence. The historical MMI-only note below is
 * superseded: por/madd are compiler-emitted operations, not handwritten-assembly evidence.
 */

/* MMI (SPECIAL2) instruction: no C spelling. 1256 bytes, level
   00_aranos_tutorial. Retail at 0x003A8940 carries the SPECIAL2 words
   0x700014A9, 0x70629000 (+0x000C, +0x00E0) - opcode 0x1C, which rabbitizer
   prints as `INVALID`; it is the MMI family (pcpyld and its relatives) the
   sixth wave recorded and that no C spelling reaches. This cc1 emits
   `lq`/`sq` for a `mode(TI)` local and `ldl`/`ldr`/`sdl`/`sdr` for a struct
   assignment, never the packed copy. ASM_FUNC candidate, as for the rest of
   the family. */

#include "include_asm.h"
typedef int Quadword __attribute__((mode(TI)));
typedef struct {
    float vertex[4][4];
    unsigned int color[4];
    float uv[4][2];
    char tail[32];
} DrawBatch;
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
    DrawBatch first, second;
    float forward[4], right[4], up[4];
    float position[4], normal[4];
    float scaled[4], local[4], rotated[4];
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
            color |= alpha << 24;
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
            *(Quadword *)position = *(Quadword *)record;
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
                for (corner = 0; corner < 4; ++corner) {
                    index = D_L00_001AF6D8[side * 4 + corner][0];
                    texture = D_L00_001AF6DA[(side * 4 + corner) * 2];
                    if (*(float *)(record + 40 + index * 4) == 0.0f)
                        *(Quadword *)scaled = *(Quadword *)D_L00_001A8F20;
                    else
                        func_00282F20(scaled, D_L00_00294A80[index], *(float *)(record + 40 + index * 4));
                    func_00282CC0(local, D_L00_00294A80[index], scaled);
                    rotated[0] = local[0];
                    rotated[1] = local[1] * sine - local[2] * cosine;
                    rotated[2] = local[1] * cosine + local[2] * sine;
                    rotated[3] = 1.0f;
                    func_00282D30(first.vertex[corner], rotated, radius + distance);
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
