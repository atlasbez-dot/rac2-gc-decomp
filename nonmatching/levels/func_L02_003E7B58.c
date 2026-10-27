/* Nonmatching: 980/972 bytes.
 * Profile: -O2 -G0 -ffunction-sections.
 * Placement checks: US: 0/1; US2: 0/1; PAL: 0/1.
 * 980/972 bytes, frame0x200. Initializing UV endpoints after the texture lookup removes two saved FPRs (the helper trial was1008 bytes/frame0x210). The genuine192-byte geometry copy retains ordinary paired quadword loads/stores: two qcopy calls emit sequential transfers and do not reproduce the measured pair. The144-byte packet is16-byte aligned. Copy cursor allocation, loop alignment and phase/packet setup scheduling remain different; -mno-split-addresses did not improve them.
 * Reopen with actual paired-copy cursor and phase-field lifetimes. Keep the late endpoint initialization and complete geometry/packet instead of shrinking storage or adding alignment instructions.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { float point[3][4][4]; } StripGeometry __attribute__((aligned(16)));
typedef struct {
    float corner[4][4];
    unsigned int color[4];
    float tex0[4];
    float tex1[4];
    unsigned long long primitive, texture, mode, flags;
} StripPacket __attribute__((aligned(16)));
extern StripGeometry D_L02_002A52F0;
extern int D_L02_002A53B0[3][9];
extern int D_L02_001B0A00[];
extern unsigned long long func_0027C878(int);
extern int func_00283CF0(float);
extern void func_00282D08(void *, void *, void *, float);
extern void func_L01_0031A278(void *, void *, float, float, float);
extern void func_00280B90(void *, void *, int);

void func_L02_003E7B58(char *actor) {
    StripGeometry geometry;
    Quad *dst = (Quad *)&geometry;
    Quad *src = (Quad *)&D_L02_002A52F0;
    StripPacket packet;
    float sample[4] __attribute__((aligned(16)));
    float *phase;
    float flip;
    int band, piece;
    do {
        Quad first = src[0], second = src[1];
        dst[0] = first;
        dst[1] = second;
        src += 2;
        dst += 2;
    } while (src != (Quad *)(&D_L02_002A52F0 + 1));
    flip = 0.0f;
    if (*(unsigned short *)(actor + 0x34) & 0x8000) flip = 1.0f;
    phase = (float *)(*(char **)(actor + 0x68) + 0x60);
    packet.tex0[0] = flip;
    packet.tex0[1] = 0.0f;
    packet.tex0[2] = 1.0f - flip;
    packet.tex0[3] = 0.0f;
    packet.tex1[0] = flip;
    packet.tex1[1] = 1.0f;
    packet.tex1[2] = 1.0f - flip;
    packet.tex1[3] = 1.0f;
    packet.primitive = 5;
    packet.mode = 0xFF9000000260ULL;
    packet.flags = 0x8000000000ULL;
    packet.color[0] = packet.color[1] = packet.color[2] = packet.color[3] = 0x7F7F7F7F;
    for (band = 0; band < 3; band++) {
        float scroll = phase[band] + 0.15f;
        for (piece = 0; piece < 3; piece++) {
            float first = ((float)func_00283CF0(scroll) - scroll) * 0.43094158f + (float)piece * 0.43094158f;
            int tile = func_00283CF0((scroll + (float)piece - 1.0f) + 9.0f) % 9;
            float last = first + 0.43094158f;
            float texFirst;
            float texLast;
            packet.texture = func_0027C878(D_L02_001B0A00[D_L02_002A53B0[band][tile]]);
            texFirst = 0.0f;
            texLast = 1.0f;
            if (last < 0.1f || first > 0.9f) continue;
            if (first < 0.1f) {
                texFirst = (0.1f - first) * 2.3205001f;
                first = 0.1f;
            } else if (last > 0.9f) {
                texLast = (0.9f - last) * 2.3205001f + texLast;
                last = 0.9f;
            }
            packet.tex0[1] = packet.tex0[3] = texFirst;
            packet.tex1[1] = packet.tex1[3] = texLast;
            func_00282D08(sample, geometry.point[band][0], geometry.point[band][2], first);
            func_L01_0031A278(actor, packet.corner[0], sample[0], sample[1], sample[2]);
            func_00282D08(sample, geometry.point[band][1], geometry.point[band][3], first);
            func_L01_0031A278(actor, packet.corner[1], sample[0], sample[1], sample[2]);
            func_00282D08(sample, geometry.point[band][0], geometry.point[band][2], last);
            func_L01_0031A278(actor, packet.corner[2], sample[0], sample[1], sample[2]);
            func_00282D08(sample, geometry.point[band][1], geometry.point[band][3], last);
            func_L01_0031A278(actor, packet.corner[3], sample[0], sample[1], sample[2]);
            func_00280B90(&packet, 0, 0);
        }
    }
}
