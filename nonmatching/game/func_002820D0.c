/* Complete manual reconstruction; NOT MATCHING and never linked.
   Tested profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   Actual final-source coverage: us: 0/28 placements, 972 compiled bytes; us2: 0/28 placements, 972 compiled bytes; pal: 0/28 placements, 972 compiled bytes.
   972/976 bytes. With the qcopy profiles, the frame and almost the whole instruction sequence agree. The y-coordinate destination copy (retail daddu v1,s1) is coalesced away; adding a separate pointer created an extra induction variable instead. Color-store order was repaired without a barrier.
   Reopen only with: A measured source alias/lifetime or qualified compiler coalescing mechanism that preserves the real y-destination copy without artificial dependencies.
*/

#include "include_asm.h"
typedef unsigned char u8;
typedef unsigned long u64;
typedef int TI128 __attribute__((mode(TI)));
typedef struct { u8 pad[0x70]; long f70, f78, f80, f88; } QuadPacket;
extern void func_00281DE8(QuadPacket *, int, int, int);
typedef union { TI128 bits; float f[4]; } UiVector;
typedef struct {
    UiVector vertices[4];
    unsigned int colors[4];
    float uv[4][2];
    u64 primitive, texture, state, flags;
} UiDrawPacket;
extern float D_001B5340[];
extern float D_0018A0E0[];
extern UiVector D_001A9FD0[];
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_002830C0(void *, void *, void *);
extern void func_00280B90(void *, int, int);
extern void func_0027C768(int, float *, float *);

void func_002820D0(UiVector *position, int alpha, float **uv,
                   float size, float inset, float distance)
{
    UiDrawPacket packet;
    UiVector matrix[4], offset;
    int i;
    unsigned int color;
    matrix[3].bits = position->bits;
    func_00282CF0(&matrix[0], D_001B5340, &matrix[3]);
    func_00282F20(&matrix[0], &matrix[0], 1.0f);
    func_00282DD8(&matrix[1], &matrix[0], D_0018A0E0);
    func_00282F20(&matrix[1], &matrix[1], 1.0f);
    func_00282DD8(&matrix[2], &matrix[1], &matrix[0]);
    func_00282D30(&offset, &matrix[0], distance);
    func_00282CC0(&matrix[3], &matrix[3], &offset);
    for (i = 3; i >= 0; i--) {
        int index = 3 - i;
        func_00282D30(&packet.vertices[index], D_001A9FD0 + index, size);
        func_002830C0(&packet.vertices[index], &packet.vertices[index], matrix);
    }
    func_00281DE8((QuadPacket *)&packet, 59, 5, 128);
    color = (alpha << 24) | 0x808080;
    packet.uv[0][0] = 0.0f;
    packet.colors[1] = packet.colors[2] = packet.colors[3] = packet.colors[0] = color;
    packet.uv[0][1] = 0.0f;
    packet.uv[1][0] = 0.0f;
    packet.uv[1][1] = 1.0f;
    packet.uv[2][0] = 1.0f;
    packet.uv[2][1] = 0.0f;
    packet.uv[3][0] = 1.0f;
    packet.uv[3][1] = 1.0f;
    func_00280B90(&packet, 0, 0);
    func_00281DE8((QuadPacket *)&packet, -1, 6, 128);
    func_00282D30(&offset, &matrix[0], distance + 0.01f);
    if (uv != 0) {
        for (i = 3; i >= 0; i--) {
            int index = 3 - i;
            packet.uv[index][0] = uv[index][0];
            packet.uv[index][1] = uv[index][1];
            if (packet.uv[index][0] > 1.0f)
                packet.uv[index][0] = 1.0f;
            else if (packet.uv[index][0] < 0.0f)
                packet.uv[index][0] = 0.0f;
            if (packet.uv[index][1] > 1.0f)
                packet.uv[index][1] = 1.0f;
            else if (packet.uv[index][1] < 0.0f)
                packet.uv[index][1] = 0.0f;
        }
    } else {
        for (i = 0; i < 4; i++) {
            float *vertical = &packet.uv[i][1];
            func_0027C768((int)&packet.vertices[i], &packet.uv[i][0], vertical);
            if (i >> 1)
                packet.uv[i][0] -= inset;
            else
                packet.uv[i][0] += inset;
            {
                float value = packet.uv[i][1];
                if (i & 1)
                    value -= inset;
                else
                    value += inset;
                *vertical = value;
            }
            if (packet.uv[i][0] > 1.0f)
                packet.uv[i][0] = 1.0f;
            else if (packet.uv[i][0] < 0.0f)
                packet.uv[i][0] = 0.0f;
            if (packet.uv[i][1] > 1.0f)
                packet.uv[i][1] = 1.0f;
            else if (packet.uv[i][1] < 0.0f)
                packet.uv[i][1] = 0.0f;
        }
    }
    func_00280B90(&packet, 0, 0);
}
