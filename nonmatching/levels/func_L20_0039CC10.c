/* Readable C reconstruction, measured2026-10-23.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0/1, us2: 0/1, pal: 0/1.
 * Retail size840 reached; final US check fails at +0x268 in the last quad colour/UV initialization. Relocations remain unqualified beyond the mismatch.
 * Tried: Packet geometry/header union, delayed object-position address and grouped/separate colour/UV assignments.
 * Reopen: A demonstrated final packet-store ordering source shape.
 * Historical notes below are preserved; their copy-wall claims are superseded
 * by the current qualified copy profiles. No handwritten-assembly inference.
 */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct { unsigned char pad[0x70]; long f70, f78, f80, f88; } QuadPacket;
typedef union {
    QuadPacket packet;
    struct { Vector corners[4]; unsigned int colours[4]; float uv[8]; } geometry;
} RenderQuad;
extern void func_00281DE8(QuadPacket *, int, int, int);
extern void func_00280B90(QuadPacket *, void *, int);
extern void func_00282CF0(void *, const void *, const void *);
extern void func_00282F20(void *, const void *, float);
extern void func_00282CC0(void *, const void *, const void *);
extern void func_00282DD8(void *, const void *, const void *);
extern Vector D_L20_001B9FC0;

void func_L20_0039CC10(unsigned char *object) {
    RenderQuad quad;
    Vector direction, offset, second, side;
    unsigned char *state = *(unsigned char **)(object + 0x68);
    Vector *position;
    float *uv;
    int i;
    func_00281DE8(&quad.packet, 23, 0, 128);
    quad.geometry.colours[0] = quad.geometry.colours[1] = 0x40108080;
    quad.geometry.colours[2] = quad.geometry.colours[3] = 0x40101080;
    quad.geometry.uv[0] = 0.0f; quad.geometry.uv[1] = 0.0f;
    quad.geometry.uv[2] = 0.0f; quad.geometry.uv[3] = 1.0f;
    quad.geometry.uv[4] = 1.0f; quad.geometry.uv[5] = 0.0f;
    quad.geometry.uv[6] = 1.0f; quad.geometry.uv[7] = 1.0f;
    uv = quad.geometry.uv;
    i = 3;
    do {
        *uv -= *(float *)(state + 0x28);
        if (*uv <= 7.0f) *uv += 7.0f;
        --i;
        uv += 2;
    } while (i >= 0);
    *(float *)(state + 0x28) += 0.1f;
    if (4.0f <= *(float *)(state + 0x28)) *(float *)(state + 0x28) -= 4.0f;
    position = (Vector *)(object + 0x10);
    func_00282CF0(&direction, position, &D_L20_001B9FC0);
    func_00282F20(&offset, state + 0x10, -2.0f);
    func_00282CC0(&second, position, &offset);
    func_00282DD8(&side, &direction, &offset);
    func_00282F20(&side, &side, 0.1f);
    func_00282CC0(&quad.geometry.corners[0], position, &side);
    func_00282CF0(&quad.geometry.corners[1], position, &side);
    func_00282CC0(&quad.geometry.corners[2], &second, &side);
    func_00282CF0(&quad.geometry.corners[3], &second, &side);
    func_00280B90(&quad.packet, 0, 0);
    quad.geometry.colours[0] = quad.geometry.colours[2];
    quad.geometry.colours[1] = quad.geometry.colours[3];
    quad.geometry.colours[2] = quad.geometry.colours[3] = 0x801010;
    quad.geometry.corners[0].q = quad.geometry.corners[2].q;
    quad.geometry.corners[1].q = quad.geometry.corners[3].q;
    func_00282CC0(&quad.geometry.corners[2], &quad.geometry.corners[2], &offset);
    func_00282CC0(&quad.geometry.corners[3], &quad.geometry.corners[3], &offset);
    func_00280B90(&quad.packet, 0, 0);
    func_00281DE8(&quad.packet, 14, 1, 128);
    quad.geometry.colours[0] = 0x40FF0020;
    quad.geometry.uv[7] = 1.0f;
    quad.geometry.colours[2] = 0xFF0020;
    quad.geometry.colours[1] = 0x40FF0020;
    quad.geometry.uv[0] = 0.0f; quad.geometry.uv[1] = 0.0f;
    quad.geometry.uv[2] = 0.0f; quad.geometry.uv[3] = 1.0f;
    quad.geometry.uv[4] = 1.0f; quad.geometry.uv[5] = 0.0f;
    quad.geometry.uv[6] = 1.0f;
    quad.geometry.colours[3] = 0xFF0020;
    func_00282F20(&side, &side, 0.6f);
    func_00282CC0(&quad.geometry.corners[0], position, &side);
    func_00282CF0(&quad.geometry.corners[1], position, &side);
    func_00282CC0(&second, position, &offset);
    func_00282CC0(&second, &second, &offset);
    func_00282CC0(&quad.geometry.corners[2], &second, &side);
    func_00282CF0(&quad.geometry.corners[3], &second, &side);
    func_00280B90(&quad.packet, 0, 0);
}
