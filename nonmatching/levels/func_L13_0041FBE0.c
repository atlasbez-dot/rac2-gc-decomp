/* MMI (SPECIAL2) instruction: no C spelling. 1648 bytes, level 13_boldan.
   Retail at 0x0041FBE0 carries the SPECIAL2 word 0x700014A9 (+0x0438) -
   opcode 0x1C, which rabbitizer prints as `INVALID`; it is the MMI family
   (pcpyld and its relatives) the sixth wave recorded and that no C spelling
   reaches. This cc1 emits `lq`/`sq` for a `mode(TI)` local and
   `ldl`/`ldr`/`sdl`/`sdr` for a struct assignment, never the packed copy.
   ASM_FUNC candidate, as for the rest of the family. */

/* Manual C reconstruction, retained after bounded retail comparison.
 * This body supersedes the historical screening conclusions above.
 * Profile: -O2 -G64 -Wa,-G64 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -frac2-zero-ti-por
 * Measured text: 1612 bytes; retail: 1648 bytes. US/US2/PAL: 0/2 placements in each
 * carrying release.
 * 3 distinct measured forms. Retail 1648 bytes; frame 0x570 now matches. Setup-vector
 * copies and distinct additive/subtractive offsets follow the retail buffers; scheduling,
 * packet pointer walking and spills differ. Earlier 1540/1596-byte forms omitted distinct
 * retail temporaries. Real seven 144-byte packets, 48-byte rotation basis, 64-byte
 * transform and 64-byte vertex arrays are preserved. Reopen on pointer iteration and
 * source lifetimes.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
typedef struct { Vector vertex[4]; unsigned int color[4]; float uv[4][2]; unsigned long long state[4]; } DrawPacket;
extern float D_L13_001B98C0[4];
extern unsigned int D_L13_001B1A90 __attribute__((sda));
extern unsigned int D_L13_001B1A94, D_L13_001B1A98, D_L13_001B1A9C;
extern int D_L13_001B1A40 __attribute__((sda));
extern int D_L13_001B1A44;
extern float D_L13_001B1A50[4][2] __attribute__((sda));
extern float D_L13_001B1A70[4][2] __attribute__((sda));
extern Vector D_L13_001B1AB0[4] __attribute__((sda));
extern Vector D_L13_001B1AF0[4] __attribute__((sda));
extern Vector D_L13_001B1B30[4] __attribute__((sda));
extern float D_L13_001B1BB0 __attribute__((sda));
extern float D_L13_001B1BB4 __attribute__((sda));
extern float D_L13_001B1BB8 __attribute__((sda));
extern int D_L13_001B1BBC __attribute__((sda));
extern int D_L13_001B1BC0 __attribute__((sda));
extern void func_00283658(void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_002AFDD8(char *, char *, char *, char *);
extern void func_00282D30(void *, void *, float);
extern float func_00283198(float);
extern unsigned int func_00283D38(unsigned int, unsigned int, float);
extern void func_L02_002EF968(void *, int, unsigned int, void *, void *, int);
extern void *func_00115484(void *, int, unsigned int);
extern void func_002833F0(void *, void *);
extern void func_L01_002E1510(void *, int, void *, int, void *);
extern void func_00282CC0(void *, void *, void *);

void func_L13_0041FBE0(char *object) {
    float transform[16];
    Vector direction;
    DrawPacket packet[7];
    unsigned int edge_a;
    unsigned int edge_b;
    Vector rotation;
    Vector setup[2];
    Vector offsets[2];
    Vector subtract_offsets[2];
    float rotation_matrix[12];
    char *private = *(char **)(object + 0x68);
    unsigned int main_color;
    unsigned int trim_color;
    float amount;
    float fade_a;
    float fade_b;
    int i;
    func_00283658(transform, object + 0xC0);
    *(Quad *)(transform + 12) = *(Quad *)(object + 0x10);
    transform[15] = 1.0f;
    func_00282F20(transform, transform, 4.0f);
    func_00282F20(transform + 4, transform + 4, 10.0f);
    func_00282CF0(&direction, D_L13_001B98C0, object + 0x10);
    func_002AFDD8(object, (char *)&direction, (char *)&direction, 0);
    if (direction.f[0] < 0.0f) func_00282D30(transform, transform, -1.0f);
    amount = func_00283198(*(float *)(private + 0x20)) * 0.5f + 0.5f;
    main_color = func_00283D38(D_L13_001B1A90, D_L13_001B1A94, amount);
    trim_color = func_00283D38(D_L13_001B1A98, D_L13_001B1A9C, amount);
    fade_a = *(float *)(private + 4);
    if (fade_a < 0.2f) fade_a = 1.0f - fade_a * 5.0f;
    edge_a = func_00283D38(D_L13_001B1A9C, D_L13_001B1A9C & 0xFFFFFF, fade_a);
    fade_b = *(float *)(private + 8);
    if (fade_b < 0.2f) fade_b = 1.0f - fade_b * 5.0f;
    edge_b = func_00283D38(D_L13_001B1A9C, D_L13_001B1A9C & 0xFFFFFF, fade_b);
    if (*(float *)private < 1.0f) {
        main_color = func_00283D38(main_color & 0xFFFFFF, main_color, *(float *)private);
        trim_color = func_00283D38(trim_color & 0xFFFFFF, trim_color, *(float *)private);
        edge_a = func_00283D38(edge_a & 0xFFFFFF, edge_a, *(float *)private);
        edge_b = func_00283D38(edge_b & 0xFFFFFF, edge_b, *(float *)private);
    }
    func_L02_002EF968(packet, D_L13_001B1A40, main_color, D_L13_001B1A50, D_L13_001B1AB0, 1);
    func_L02_002EF968(packet + 1, D_L13_001B1A44, trim_color, D_L13_001B1A70, D_L13_001B1AF0, 1);
    func_L02_002EF968(packet + 2, D_L13_001B1A44, trim_color, D_L13_001B1A70, D_L13_001B1B30, 1);
    func_L02_002EF968(packet + 3, D_L13_001B1A44, edge_a, D_L13_001B1A70, D_L13_001B1AF0, 1);
    func_L02_002EF968(packet + 4, D_L13_001B1A44, edge_a, D_L13_001B1A70, D_L13_001B1B30, 1);
    func_L02_002EF968(packet + 5, D_L13_001B1A44, edge_b, D_L13_001B1A70, D_L13_001B1AF0, 1);
    func_L02_002EF968(packet + 6, D_L13_001B1A44, edge_b, D_L13_001B1A70, D_L13_001B1B30, 1);
    for (i = 0; i < 4; i++) {
        packet[1].uv[i][0] += *(float *)(private + 0xC);
        packet[2].uv[i][0] -= *(float *)(private + 0xC);
        packet[3].uv[i][0] += *(float *)(private + 0xC);
        packet[4].uv[i][0] -= *(float *)(private + 0xC);
        packet[5].uv[i][0] += *(float *)(private + 0xC);
        packet[6].uv[i][0] -= *(float *)(private + 0xC);
        packet[3].vertex[i].f[2] -= *(float *)(private + 4) * D_L13_001B1BB4;
        packet[4].vertex[i].f[2] += *(float *)(private + 4) * D_L13_001B1BB4;
        packet[5].vertex[i].f[2] -= *(float *)(private + 8) * D_L13_001B1BB4;
        packet[6].vertex[i].f[2] += *(float *)(private + 8) * D_L13_001B1BB4;
    }
    setup[0].quad = 0;
    setup[0].f[2] = -3.1415927f / D_L13_001B1BB8;
    setup[1].quad = 0;
    setup[1].f[2] = D_L13_001B1BB0;
    rotation.quad = setup[0].quad;
    setup[0].quad = setup[1].quad;
    func_00115484(offsets, 0, 32);
    offsets[0].f[2] = *(float *)(private + 4) * D_L13_001B1BB4;
    offsets[1].f[2] = *(float *)(private + 8) * D_L13_001B1BB4;
    subtract_offsets[0].quad = offsets[0].quad;
    subtract_offsets[1].quad = offsets[1].quad;
    func_002833F0(rotation_matrix, &rotation);
    func_L01_002E1510(packet, D_L13_001B1BBC, rotation_matrix, D_L13_001B1BC0, transform);
    for (i = 0; i < 4; i++) {
        func_00282CC0(packet[0].vertex + i, D_L13_001B1AB0 + i, setup);
        func_00282CC0(packet[1].vertex + i, D_L13_001B1AF0 + i, setup);
        func_00282CC0(packet[2].vertex + i, D_L13_001B1B30 + i, setup);
        func_00282CC0(packet[3].vertex + i, D_L13_001B1AF0 + i, setup);
        func_00282CC0(packet[4].vertex + i, D_L13_001B1B30 + i, setup);
        func_00282CC0(packet[5].vertex + i, D_L13_001B1AF0 + i, setup);
        func_00282CC0(packet[6].vertex + i, D_L13_001B1B30 + i, setup);
        func_00282CF0(packet[3].vertex + i, packet[3].vertex + i, subtract_offsets);
        func_00282CC0(packet[4].vertex + i, packet[4].vertex + i, offsets);
        func_00282CF0(packet[5].vertex + i, packet[5].vertex + i, subtract_offsets + 1);
        func_00282CC0(packet[6].vertex + i, packet[6].vertex + i, offsets + 1);
    }
    func_002833F0(rotation_matrix, &rotation);
    func_L01_002E1510(packet, D_L13_001B1BBC, rotation_matrix, D_L13_001B1BC0, transform);
}
