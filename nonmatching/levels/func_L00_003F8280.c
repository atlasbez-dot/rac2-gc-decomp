/* Nonmatching C: Build the facing quad, optionally rotate its basis and project its second draw pass.
 * Tested profile: -O2 -G0 -ffunction-sections.
 * Measured US size: 1304 bytes; retail: 1324 bytes.
 * Placement checks: US, US2 and PAL: 0/27 each.
 * Remaining: An extra saved register and the projection UV cursor lifetimes still differ.
 * Reopen with independent projection cursor lifetimes; preserve the complete 144-byte packet, 64-byte basis and disjoint 48-byte rotation scratch.
 */
#include "common.h"

typedef unsigned int QuadWord __attribute__((mode(TI)));
typedef union { QuadWord word; float v[4]; } Vector;
typedef struct { Vector row[3]; Vector position; } Frame;
typedef struct { unsigned char pad[0x70]; long f70, f78, f80, f88; } QuadPacket;
typedef struct {
    Vector vertex[4];
    unsigned int color[4];
    float uv[4][2];
    long f70, f78, f80, flags;
} RenderPacket;

extern Vector D_L00_001B8DC0;
extern Vector D_0018A0E0;
extern Vector D_L00_001AA310[4];
extern void func_00281DE8(QuadPacket *, int, int, int);
extern void func_00282CF0(Vector *, const Vector *, const Vector *);
extern void func_00282CC0(Vector *, const Vector *, const Vector *);
extern void func_00282DD8(Vector *, const Vector *, const Vector *);
extern void func_00282F20(Vector *, const Vector *, float);
extern void func_00282D30(Vector *, const Vector *, float);
extern void func_002833F0(Vector *, const Vector *);
extern void func_00283738(Vector *, const Vector *, const Vector *);
extern void func_002830C0(Vector *, const Vector *, const Frame *);
extern void func_002FC560(unsigned int, unsigned long long);
extern void func_00280B90(RenderPacket *, void *, int);
extern void func_0027C768(int, float *, float *);
extern int func_002A77E0(int);
extern float func_002A7878(float, float);

void func_L00_003F8280(Vector *position, float size, float offset, float roll,
                       float unused, float jitter, int texture, int mode)
{
    RenderPacket packet;
    Frame frame;
    Vector angles;
    union {
        Vector rotation[3];
        struct { Vector center, point; } projection;
    } scratch;
    Vector *vertex;
    Vector *corner;
    float *u, *v, *out_u, *out_v;
    int count;

    func_00281DE8((QuadPacket *)&packet, texture, 1, 0x80);
    packet.flags = 0x800000004aULL;
    packet.color[0] = 0x80808080;
    packet.color[3] = 0x80808080;
    packet.color[2] = 0x80808080;
    packet.color[1] = 0x80808080;
    packet.uv[0][0] = 0.0f;
    packet.uv[0][1] = 0.0f;
    packet.uv[1][0] = 0.0f;
    packet.uv[1][1] = 1.0f;
    packet.uv[2][0] = 1.0f;
    packet.uv[2][1] = 0.0f;
    packet.uv[3][0] = 1.0f;
    packet.uv[3][1] = 1.0f;
    qcopy(&frame.position, position);
    func_00282CF0(&frame.row[0], &D_L00_001B8DC0, &frame.position);
    func_00282F20(&frame.row[0], &frame.row[0], 1.0f);
    func_00282DD8(&frame.row[1], &frame.row[0], &D_0018A0E0);
    func_00282F20(&frame.row[1], &frame.row[1], 1.0f);
    func_00282DD8(&frame.row[2], &frame.row[1], &frame.row[0]);
    if (roll != 0.0f) {
        angles.word = 0;
        angles.v[0] = roll;
        func_002833F0(scratch.rotation, &angles);
        func_00283738(frame.row, frame.row, scratch.rotation);
    }
    func_00282D30(&angles, &frame.row[0], offset);
    func_00282CC0(&frame.position, &frame.position, &angles);
    u = &packet.uv[0][0];
    v = &packet.uv[0][1];
    vertex = packet.vertex;
    corner = D_L00_001AA310;
    count = 3;
    do {
        func_00282D30(vertex, corner, size);
        ++corner;
        --count;
        func_002830C0(vertex, vertex, &frame);
        ++vertex;
    } while (count >= 0);
    func_002FC560(0x47, 0x31001ULL);
    func_00280B90(&packet, 0, 0);
    if (mode != 0) {
        qcopy(&scratch.projection.center, &packet.vertex[0]);
        vertex = &packet.vertex[1];
        count = 2;
        do {
            func_00282CC0(&scratch.projection.center, &scratch.projection.center, vertex);
            ++vertex;
            --count;
        } while (count >= 0);
        func_00282D30(&scratch.projection.center, &scratch.projection.center, 0.25f);
        out_v = &packet.uv[0][1];
        out_u = &packet.uv[0][0];
        vertex = packet.vertex;
        count = 3;
        do {
            func_00282CF0(&scratch.projection.point, vertex, &scratch.projection.center);
            func_00282D30(&scratch.projection.point, &scratch.projection.point, 0.8f);
            func_00282CC0(&scratch.projection.point, &scratch.projection.center, &scratch.projection.point);
            func_0027C768((int)&scratch.projection.point, out_u, out_v);
            if (func_002A77E0(1) == 0) {
                *u += func_002A7878(-jitter, jitter);
                *v += func_002A7878(-jitter, jitter);
            }
            if (*u > 1.0f) *u = 1.0f;
            else if (*u < 0.0f) *u = 0.0f;
            if (*v > 1.0f) *v = 1.0f;
            else if (*v < 0.0f) *v = 0.0f;
            v += 2;
            u += 2;
            out_v += 2;
            out_u += 2;
            --count;
            ++vertex;
        } while (count >= 0);
    } else {
        out_v = &packet.uv[0][1];
        out_u = &packet.uv[0][0];
        vertex = packet.vertex;
        count = 3;
        do {
            func_0027C768((int)vertex, out_u, out_v);
            if (func_002A77E0(1) == 0) {
                *u += func_002A7878(-jitter, jitter);
                *v += func_002A7878(-jitter, jitter);
            }
            if (*u > 1.0f) *u = 1.0f;
            else if (*u < 0.0f) *u = 0.0f;
            if (*v > 1.0f) *v = 1.0f;
            else if (*v < 0.0f) *v = 0.0f;
            v += 2;
            u += 2;
            out_v += 2;
            out_u += 2;
            --count;
            ++vertex;
        } while (count >= 0);
    }
    func_00281DE8((QuadPacket *)&packet, -1, 1, 0x80);
    packet.flags = 0x8000000054ULL;
    func_002FC560(0x47, 0x33001ULL);
    func_00280B90(&packet, 0, 0);
    func_002FC560(0x47, 0x5360bULL);
}
