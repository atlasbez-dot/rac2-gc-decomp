/* Nonmatching: USA v1.01: 0/1 carrying places; USA v2.00: 0/1 carrying places; PAL: absent. Final C 1732/1756 retail bytes. Game -O2 -G8 -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-barrier. Full table-actor renderer, transform visibility, rotating packets, mirrored glow and particles reconstructed. First trial 1732/1756 bytes; final explicit nextPass loop lifetime trial. Remaining frame/loop/register scheduling; no linked builds. Reopen with renderer packet typing and loop lifetime hypothesis.  */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { float vertex[4][4]; unsigned int color[4]; float uv[4][2]; unsigned long long state[4]; } Packet;
extern int D_L02_001B30C8;
extern char *D_L02_001B359C;
extern unsigned short *D_L02_001FC060[];
extern int D_L02_001B0A68 __attribute__((sda)), D_L02_001B0A98 __attribute__((sda));
extern int D_L02_001B0A6C, D_L02_001B0A9C, D_L02_001B0AA0, D_L02_001B0AA4;
extern char D_L02_001B0A78[4] __attribute__((sda)), D_L02_001B0AB0[4] __attribute__((sda)), D_L02_001B0AF0[4] __attribute__((sda));
extern int D_L02_001B0B30 __attribute__((sda));
extern unsigned int D_L02_001B0B38[2] __attribute__((sda));
extern float D_L02_001B0B40 __attribute__((sda));
extern char D_L02_001B0B48[4] __attribute__((sda));
extern char D_L02_001BA500[];
extern float func_00283CE0(int);
extern void func_00283410(void *, void *), func_0029FC20(void *, int, void *), func_002830C0(void *, void *, void *);
extern int func_00283DB8(void *, float);
extern void func_00283788(void *, void *, void *);
extern void func_L02_002EF968(void *, int, int, void *, void *, int);
extern void func_00282C88(void *), func_002833F0(void *, void *), func_00283098(void *, void *, void *);
extern void func_00283738(void *, void *, void *), func_00280B90(void *, void *, int);
extern unsigned long long func_0027C878(int);
extern void func_00283388(void *), func_00282CF0(void *, void *, void *), func_00282DD8(void *, void *, void *);
extern void func_00282F20(void *, void *, float), func_00282CC0(void *, void *, void *);
extern float func_002A7878(float, float), func_002A7940(void);
extern unsigned int func_00283D38(unsigned int, unsigned int, float);
extern void func_00281EB8(void *, int, unsigned int, int, float, float, float);
/* Renders the visible table actors, their rotating rings, mirrored glow and particles. */
void func_L02_003E80F8(char *actor) {
    float matrices[32][16], rotation[16];
    unsigned int visible[32];
    float tilt[12];
    float probe[4];
    Packet packet[2];
    float angles[4], point[4], doubled[12], identity[16], normal[4], offset[4];
    unsigned short *entry = D_L02_001FC060[*(unsigned char *)(actor + 0x21)];
    unsigned short id;
    float frame;
    int count = 0, i, layer, pass, nextLayer, nextPass;
    unsigned int color;
    float *geometry = (float *)D_L02_001B0AB0;
    float *uv = (float *)D_L02_001B0B48;
    *(Quad *)probe = 0;
    probe[0] = 30.0f;
    probe[3] = 1.0f;
    *(Quad *)point = 0;
    frame = func_00283CE0(D_L02_001B30C8 % 600);
    point[0] = (frame * 0.0016666667f + frame * 0.0016666667f) * 3.1415927f - 3.1415927f;
    *(Quad *)angles = *(Quad *)point;
    func_00283410(rotation, angles);
    do {
        char *object;
        id = *entry++;
        object = D_L02_001B359C + (id & 0x7FFF) * 0x100;
        visible[count] = (*(unsigned short *)(object + 0x7C) >> 15) ^ 1;
        func_0029FC20(object, 0, matrices[count]);
        func_002830C0(point, probe, matrices[count]);
        point[3] = 30.0f;
        if (func_00283DB8(point, 512.0f) != -1) {
            func_00283788(matrices[count], matrices[count], rotation);
            count++;
        }
    } while ((short)id >= 0 && count < 32);
    func_L02_002EF968(packet, D_L02_001B0A68, D_L02_001B0A98, D_L02_001B0A78, D_L02_001B0AB0, 1);
    func_L02_002EF968(packet + 1, D_L02_001B0A6C, D_L02_001B0AA0, D_L02_001B0A78, D_L02_001B0AF0, 1);
    packet[0].color[1] = packet[0].color[3] = D_L02_001B0A9C;
    packet[1].color[1] = packet[1].color[3] = D_L02_001B0AA4;
    func_00282C88(angles);
    angles[0] = 0.3926991f;
    func_002833F0(tilt, angles);
    for (i = 0; i < 2; i++) {
        func_00283098(packet[i].vertex[2], packet[i].vertex[2], tilt);
        func_00283098(packet[i].vertex[3], packet[i].vertex[3], tilt);
    }
    func_00283738(doubled, tilt, tilt);
    for (pass = 0; pass < 16; pass = nextPass) {
        int pair = (pass & 1) ? 2 : 0;
        nextPass = pass + 1;
        for (layer = 0; layer < 1; layer = nextLayer) {
            nextLayer = layer + 1;
            func_00283098(packet[layer].vertex[pair], packet[layer].vertex[pair], doubled);
            func_00283098(packet[layer].vertex[pair + 1], packet[layer].vertex[pair + 1], doubled);
            for (i = 0; i < count; i++) if (visible[i]) func_00280B90(packet + layer, matrices[i], 1);
        }
    }
    packet[0].state[1] = func_0027C878(D_L02_001B0B30);
    for (i = 0; i < 4; i++) {
        packet[0].uv[i][0] = uv[i * 2];
        packet[0].uv[i][1] = uv[i * 2 + 1];
        packet[0].color[i] = D_L02_001B0B38[i & 1];
    }
    func_00283388(identity);
    for (i = 0; i < count; i++) {
        int vertex;
        if (!visible[i]) continue;
        func_00282CF0(point, D_L02_001BA500, matrices[i] + 12);
        func_00282DD8(normal, matrices[i], point);
        normal[3] = 1.0f;
        *(Quad *)(identity + 12) = *(Quad *)(matrices[i] + 12);
        for (vertex = 0; vertex < 4; vertex++) {
            float extent = vertex < 2 ? geometry[vertex * 4 + 2] + D_L02_001B0B40 : geometry[vertex * 4 + 2] - D_L02_001B0B40;
            func_00282F20(packet[0].vertex[vertex], normal, extent);
            func_00282F20(offset, matrices[i], geometry[vertex * 4]);
            func_00282CC0(packet[0].vertex[vertex], packet[0].vertex[vertex], offset);
        }
        func_00280B90(packet, identity, 0);
        for (vertex = 0; vertex < 4; vertex++) {
            float extent = vertex < 2 ? geometry[vertex * 4 + 2] + D_L02_001B0B40 : geometry[vertex * 4 + 2] - D_L02_001B0B40;
            func_00282F20(offset, normal, extent * -2.0f);
            func_00282CC0(packet[0].vertex[vertex], packet[0].vertex[vertex], offset);
        }
        func_00280B90(packet, identity, 0);
        *(Quad *)offset = 0;
        offset[0] = 2.666f;
        offset[3] = 1.0f;
        func_002830C0(offset, offset, matrices[i]);
        frame = func_002A7878(0.0f, 1.0f);
        color = func_00283D38(D_L02_001B0A98, D_L02_001B0A9C, frame);
        frame = func_002A7940();
        func_00281EB8(offset, 11, color, 1, 2.0f, 0.0f, frame);
        frame = func_002A7878(0.0f, 1.0f);
        color = func_00283D38(D_L02_001B0AA0, D_L02_001B0AA4, frame);
        frame = func_002A7940();
        func_00281EB8(offset, 11, color, 1, 2.75f, 0.0f, frame);
        frame = func_002A7940();
        func_00281EB8(offset, 49, color, 1, 2.75f, 0.0f, frame);
    }
}
