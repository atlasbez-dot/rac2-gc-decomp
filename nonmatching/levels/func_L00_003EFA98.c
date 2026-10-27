/* Complete reconstruction of func_L00_003EFA98 and its sibling func_L00_003EFD00; not linked.
 * Profile: -O2 -G8 -ffunction-sections. 612/612 bytes, us 0/27.
 * 26 October 2026 (M10): statement-order search over the setup block took 117 to 88 differing
 * lines (colour stores high first; note the search also put matrix[1]'s init call first, which is
 * a search artifact to re-check). Left: retail allocates object to $s1 and data to $s2 (ours
 * $s6/$s1), keeps 0.25 in f20 only after the first identity call, hoists D_L00_0029AF40 into
 * $fp, and gives u/v to $s3/$s4 the other way round.
 */
#include "common.h"
typedef struct { float x, y, z, w; } Vector;
typedef struct {
    Vector vertices[4];
    unsigned int colors[4];
    float uv[8];
    long zero, texture, state, flags;
} Packet;
extern int D_L00_001B0870 __attribute__((sda));
extern int D_L00_001B0874 __attribute__((sda));
extern int D_L00_001B0878 __attribute__((sda));
extern int D_L00_001B087C __attribute__((sda));
extern int D_L00_001B0880 __attribute__((sda));
extern int D_L00_001B0884 __attribute__((sda));
extern int D_L00_001B0888 __attribute__((sda));
extern float D_L00_001B088C __attribute__((sda));
extern Vector D_L00_0029AF40[];
extern short D_L00_0029B440[][8];
extern float D_L00_0029B840[][2];
extern long func_0027C878(int);
extern void func_00282C88(void *);
extern void func_002AFFD8(char *, char *, int);
extern void func_00282D30(void *, void *, float);
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00280B90(void *, void *, int);

void func_L00_003EFA98(char *object)
{
    Packet packet;
    Vector matrix[3], offset;
    char *orientation = object + 0xC0;
    char *data = *(char **)(object + 0x68);
    char *u_base, *v_base;
    char *u, *v;
    Vector *vertex;
    short *indices;
    int face, remaining, index;
    unsigned int color;
    long flags;
    float quarter;

    packet.texture = func_0027C878(D_L00_001B0884);
    flags = (long)D_L00_001B0870;
    flags |= (long)D_L00_001B0874 << 2;
    flags |= (long)D_L00_001B0878 << 4;
    flags |= (long)D_L00_001B087C << 6;
    flags |= (long)D_L00_001B0880 << 32;
    packet.flags = flags;
    packet.state = 0xFF9000000260L;
    packet.zero = 0;
    object += 0x10;
    quarter = 0.25f;
    func_00282C88(&matrix[1]);
    func_00282C88(&matrix[0]);
    func_00282C88(&matrix[2]);
    matrix[0].x = *(float *)(data + 0x10) + *(float *)(data + 0x10);
    matrix[1].y = *(float *)(data + 0x10) + *(float *)(data + 0x10);
    matrix[2].z = *(float *)(data + 0x10) * quarter;
    color = D_L00_001B0888 + (*(unsigned int *)(data + 0x24) << 24);
    packet.colors[3] = color;
    packet.colors[2] = color;
    packet.colors[1] = color;
    packet.colors[0] = color;
    func_002AFFD8(object, (char *)&offset, 1);
    func_00282D30(&offset, &offset, quarter);
    u_base = (char *)&packet + 0x50;
    v_base = (char *)&packet + 0x54;
    for (face = 0; face < 64; face++) {
        indices = D_L00_0029B440[face];
        u = u_base;
        v = v_base;
        vertex = packet.vertices;
        for (remaining = 3; remaining >= 0; remaining--) {
            index = indices[1];
            func_00282D30(vertex, &D_L00_0029AF40[indices[0]], D_L00_001B088C);
            indices += 2;
            *(float *)u = D_L00_0029B840[index][0];
            *(float *)v = D_L00_0029B840[index][1];
            func_00283098(vertex, vertex, &matrix[0]);
            u += 8;
            func_00283098(vertex, vertex, orientation);
            v += 8;
            func_00282CC0(vertex, vertex, object);
            func_00282CC0(vertex, vertex, &offset);
            vertex++;
        }
        func_00280B90(&packet, 0, 0);
    }
}


void func_L00_003EFD00(char *object)
{
    Packet packet;
    Vector matrix[3], offset;
    char *orientation = object + 0xC0;
    char *data = *(char **)(object + 0x68);
    char *u_base, *v_base;
    char *u, *v;
    Vector *vertex;
    short *indices;
    int face, remaining, index;
    unsigned int color;
    long flags;

    packet.texture = func_0027C878(D_L00_001B0884);
    flags = (long)D_L00_001B0870;
    flags |= (long)D_L00_001B0874 << 2;
    flags |= (long)D_L00_001B0878 << 4;
    flags |= (long)D_L00_001B087C << 6;
    flags |= (long)D_L00_001B0880 << 32;
    packet.flags = flags;
    packet.state = 0xFF9000000260L;
    packet.zero = 0;
    object += 0x10;
    func_00282C88(&matrix[0]);
    func_00282C88(&matrix[1]);
    func_00282C88(&matrix[2]);
    matrix[0].x = *(float *)(data + 0x10);
    matrix[1].y = *(float *)(data + 0x10);
    matrix[2].z = *(float *)(data + 0x10) * 0.125f;
    color = D_L00_001B0888 + (*(unsigned int *)(data + 0x24) << 24);
    packet.colors[0] = color;
    packet.colors[1] = color;
    packet.colors[2] = color;
    packet.colors[3] = color;
    func_002AFFD8(object, (char *)&offset, 1);
    func_00282D30(&offset, &offset, 0.25f);
    u_base = (char *)&packet + 0x50;
    v_base = (char *)&packet + 0x54;
    for (face = 0; face < 64; face++) {
        indices = D_L00_0029B440[face];
        u = u_base;
        v = v_base;
        vertex = packet.vertices;
        for (remaining = 3; remaining >= 0; remaining--) {
            index = indices[1];
            func_00282D30(vertex, &D_L00_0029AF40[indices[0]], D_L00_001B088C);
            indices += 2;
            *(float *)u = D_L00_0029B840[index][0];
            *(float *)v = D_L00_0029B840[index][1];
            func_00283098(vertex, vertex, &matrix[0]);
            u += 8;
            func_00283098(vertex, vertex, orientation);
            v += 8;
            func_00282CC0(vertex, vertex, object);
            func_00282CC0(vertex, vertex, &offset);
            vertex++;
        }
        func_00280B90(&packet, 0, 0);
    }
}
