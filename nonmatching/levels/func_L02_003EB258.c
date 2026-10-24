/* Nonmatching: USA v1.01: 0/1 carrying places; USA v2.00: 0/1 carrying places; PAL: 0/1 carrying places. Final C 1056/1004 retail bytes. Game -O2 -G8 -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-barrier, 1056/1004 bytes with retail 0x230 frame. Two source trials: pair of blend floats versus copied two-float struct; struct variant 1072 bytes/frame 0x240. Surface packets and transforms reconstructed. Remaining alias/register and loop differences; reopen with packet field pointer walks and natural blend-pair lifetime. No linked builds.  */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct {
    float vertex[4][4];
    unsigned int color[4];
    float uv[4][2];
    unsigned long long state[4];
} SurfacePacket;
extern int D_L02_001B0D60[2] __attribute__((sda));
extern char D_L02_001B0D68[4] __attribute__((sda));
extern unsigned int D_L02_001B0DA8 __attribute__((sda));
extern unsigned int D_L02_001B0DAC, D_L02_001B0DB0, D_L02_001B0DB4;
extern char *D_L02_001B368C;
extern void func_00281DE8(void *, int, int, int);
extern float func_00283198(float);
extern float func_00283B98(float, float);
extern float func_00282DF0(void *);
extern int func_00283CF0(float);
extern unsigned int func_00283D38(unsigned int, unsigned int, float);
extern void func_00283658(void *, void *);
extern void func_00280B90(void *, void *, int);
/* Draws two colored surfaces in strips using the selected platform transform. */
void func_L02_003EB258(char *actor) {
    SurfacePacket packet[2];
    float blend[2];
    float normal[4];
    float matrix[12];
    float position[4];
    char *state = *(char **)(actor + 0x68);
    int i, slice, count;
    float step;
    float *uv = (float *)D_L02_001B0D68;
    for (i = 0; i < 2; i++) func_00281DE8(packet + i, D_L02_001B0D60[i], 0, 0x80);
    blend[0] = func_00283198(*(float *)(state + 0x14)) * 0.5f + 0.5f;
    blend[1] = func_00283198(func_00283B98(*(float *)(state + 0x14), 3.1415927f)) * 0.5f + 0.5f;
    count = func_00283CF0(func_00282DF0(D_L02_001B368C + *(int *)(state + 8) * 0x80 + 0x10));
    *(Quad *)normal = 0;
    normal[3] = 1.0f;
    step = 2.0f / (float)count;
    for (i = 0; i < 4; i++) {
        packet[0].uv[i][0] = uv[i * 2];
        packet[0].uv[i][1] = uv[i * 2 + 1];
        packet[1].uv[i][0] = uv[i * 2 + 8] + *(float *)(state + 0x18);
        packet[1].uv[i][1] = uv[i * 2 + 9];
        packet[0].color[i] = func_00283D38(D_L02_001B0DA8, D_L02_001B0DAC, blend[0]);
        packet[1].color[i] = func_00283D38(D_L02_001B0DB0, D_L02_001B0DB4, blend[1]);
        if (*(float *)(state + 0x1C) < 1.0f) {
            packet[0].color[i] = func_00283D38(packet[0].color[i] & 0x00FFFFFF, packet[0].color[i], *(float *)(state + 0x1C));
            packet[1].color[i] = func_00283D38(packet[1].color[i] & 0x00FFFFFF, packet[1].color[i], *(float *)(state + 0x1C));
        }
        *(Quad *)packet[0].vertex[i] = *(Quad *)normal;
        packet[0].vertex[i][0] = i < 2 ? 1.0f : -1.0f;
        packet[0].vertex[i][1] = (i & 1) ? -1.0f : step - 1.0f;
        *(Quad *)packet[1].vertex[i] = *(Quad *)normal;
        packet[1].vertex[i][0] = i < 2 ? 1.0f : -1.0f;
        packet[1].vertex[i][1] = (i & 1) ? -1.0f : step - 1.0f;
    }
    func_00283658(matrix, D_L02_001B368C + *(int *)(state + 8) * 0x80);
    *(Quad *)position = *(Quad *)(D_L02_001B368C + *(int *)(state + 8) * 0x80 + 0x30);
    for (slice = 0; slice < count; slice++) {
        func_00280B90(packet, matrix, 0);
        func_00280B90(packet + 1, matrix, 0);
        for (i = 0; i < 4; i++) {
            packet[0].vertex[i][1] += step;
            packet[1].vertex[i][1] += step;
        }
    }
}
