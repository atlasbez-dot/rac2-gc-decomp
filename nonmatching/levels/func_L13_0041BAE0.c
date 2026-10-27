/* Nonmatching C: Build and submit the ring segments using a complete quad packet and object matrix.
 * Tested profile: -O2 -G32 -Wa,-G32 -ffunction-sections.
 * Measured US size: 756 bytes; retail: 708 bytes.
 * Placement checks: US, US2 and PAL: 0/2 each.
 * Remaining: The frame is larger than retail and the UV, packet and matrix address lifetimes differ.
 * Reopen with packet and UV lifetime evidence; preserve the complete 144-byte packet, 64-byte matrix, 32-byte UV table and 64-bit texture result.
 */
#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef struct { float vertex[4][4]; unsigned int color[4]; float uv[4][2]; unsigned long long state[4]; } RingPacket __attribute__((aligned(16)));
extern int D_L13_001B16E8[4] __attribute__((sda));
extern int D_L13_001B16F8 __attribute__((sda));
extern unsigned int D_L13_001B16FC __attribute__((sda));
extern float D_L13_001B1700[4][2] __attribute__((sda));
extern float D_L13_001B1720 __attribute__((sda));
extern unsigned char D_00189E20[];
extern void func_00283658(void *, void *);
extern unsigned long long func_0027C878(int);
extern float func_00283180(float);
extern float func_00283198(float);
extern void func_00280B90(void *, void *, int);

void func_L13_0041BAE0(void *opaque) {
    char *object = opaque;
    RingPacket packet;
    float matrix[16] __attribute__((aligned(16)));
    char *private = *(char **)(object + 0x68);
    float thickness;
    float radius;
    float fade;
    float angle;
    int i;
    int j;
    func_00283658(matrix, object + 0xC0);
    qcopy(matrix + 12, object + 0x10);
    packet.state[1] = func_0027C878(D_L13_001B16F8);
    packet.state[3] = (long long)D_L13_001B16E8[0] |
        ((long long)D_L13_001B16E8[1] << 2) | ((long long)D_L13_001B16E8[2] << 4) |
        ((long long)D_L13_001B16E8[3] << 6) | 0x8000000000ULL;
    packet.state[2] = 0xFF9000000260ULL;
    packet.state[0] = 0;
    {
        float *u = &D_L13_001B1700[0][0];
        float *v = &D_L13_001B1700[0][1];
        float *out_u = &packet.uv[0][0];
        float *out_v = &packet.uv[0][1];
        unsigned int *color = packet.color;
        unsigned int shade = D_L13_001B16FC;
        for (i = 3; i >= 0; i--) {
            *out_u = *u;
            *out_v = *v;
            *color++ = shade;
            u += 2;
            v += 2;
            out_u += 2;
            out_v += 2;
        }
    }
    radius = *(float *)(private + 0x34);
    thickness = 0.1f;
    if (radius < 1.15f) {
        fade = 1.15f - radius;
        fade += fade;
        if (fade > 1.0f) fade = 1.0f;
        else if (fade < 0.0f) fade = 0.0f;
        thickness = fade + 0.1f;
        D_00189E20[0x22B5] = radius < 0.65f ? 1 : 0;
    }
    for (i = 0; i < 32; i++) {
        for (j = 0; j < 4; j++) {
            angle = (float)(i + j / 2) * 0.19637252f - 3.14159f;
            packet.vertex[j][0] = func_00283180(angle) * *(float *)(private + 0x34);
            packet.vertex[j][1] = func_00283198(angle) * *(float *)(private + 0x34);
            packet.vertex[j][2] = 0.0f;
            packet.vertex[j][2] = (j & 1) ? D_L13_001B1720 + thickness : D_L13_001B1720 - thickness;
            packet.vertex[j][3] = 1.0f;
        }
        func_00280B90(&packet, matrix, 0);
    }
}
