/* Reconstructed on 2026-10-23. Profile: -O2 -G8 -ffunction-sections
 * -frac2-qcopy -frac2-qcopy-barrier -frac2-gcse-unsplit-edges.
 * US, US2 and PAL: 1596/1600 bytes, 0/27 placements per release.
 * Default profile gave 1580 bytes. Tested joint-pair array declarations, SDA table
 * declarations, G64, assembler G64 and no-split-addresses. Copy and branch profiles
 * preserve the expected broad structure; address forms, allocation and scheduling
 * still differ. Reopen with a measured table/packet layout or original codegen
 * control. Retail por zero materialization is compiler-reachable, not an ASM proof.
 * The older comment below is preserved as historical provenance, not a conclusion.
 */
/* MMI (SPECIAL2) instruction: no C spelling. 1600 bytes, level
   00_aranos_tutorial. Retail at 0x0038FE10 carries the SPECIAL2 word
   0x700044A9 (+0x00F8) - opcode 0x1C, which rabbitizer prints as `INVALID`;
   it is the MMI family (pcpyld and its relatives) the sixth wave recorded
   and that no C spelling reaches. This cc1 emits `lq`/`sq` for a `mode(TI)`
   local and `ldl`/`ldr`/`sdl`/`sdr` for a struct assignment, never the
   packed copy. ASM_FUNC candidate, as for the rest of the family. */

#include "include_asm.h"
typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern float func_002A7878(float, float);
extern Vector D_L00_001B8DC0;
/* The draw packet has four positions, four packed colors and four UV pairs. */
typedef unsigned long long PacketWord;
typedef struct { int index[2]; } JointPair;
typedef struct {
    Vector position[4];
    unsigned int color[4];
    float uv[4][2];
    PacketWord tag, primitive, texture, blend;
} DrawPacket;
extern char *D_0018B130;
extern JointPair D_L00_001AF0D0[], D_L00_001AF0D8[];
extern Vector D_L00_001AF030[4] __attribute__((sda));
extern Vector D_L00_001AF070[4] __attribute__((sda));
extern float D_L00_001AF0B0[4][2] __attribute__((sda));
extern float D_L00_001AF0B4[4][2];
extern Vector D_0018A0E0;
extern Vector D_L00_00290E00[196];
extern float D_L00_00239020[196][3], D_L00_00291A40[196][2];
extern unsigned int D_L00_00292060[196];
extern void func_0029FD48(void *, int, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern void func_00283388(void *);
extern void func_00283788(void *, void *, void *);
extern PacketWord func_0027C878(int);
extern void func_00280B90(void *, void *, int);
extern void func_002830C0(void *, void *, void *);
extern void func_002FC560(int, PacketWord);
extern void func_00280328(void);
extern void func_00281810(int, void *, void *, void *, int);

void func_L00_0038FE10(char *object)
{
    DrawPacket packet;
    Vector basis[4], joints[2];
    JointPair jointIndices;
    Vector up, matrix[4], adjustment[4], frame[4], point;
    char *state = *(char **)(object + 0x68);
    int i;
    if (D_0018B130 == 0 ||
        (*(short *)(D_0018B130 + 0xAA) != 0x260 && *(short *)(D_0018B130 + 0xAA) != 0x96C))
        return;
    packet.blend = 0x8000000048ULL;
    packet.texture = 0xFF9000000260ULL;
    packet.tag = 0;
    if (*(int *)(state + 4)) {
        jointIndices = D_L00_001AF0D0[0];
        func_0029FD48(D_0018B130, 2, &jointIndices, joints);
    } else {
        jointIndices = D_L00_001AF0D8[0];
        func_0029FD48(D_0018B130, 2, &jointIndices, joints);
    }
    up.q = 0;
    up.f[1] = 1.0f;
    func_00282CF0(&basis[2], &joints[0], &joints[1]);
    func_00282F20(&basis[2], &basis[2], 1.0f);
    basis[2].f[3] = 0.0f;
    func_00282DD8(&basis[0], &up, &basis[2]);
    func_00282F20(&basis[0], &basis[0], 1.0f);
    basis[0].f[3] = 0.0f;
    func_00282DD8(&basis[1], &basis[2], &basis[0]);
    basis[1].f[3] = 0.0f;
    basis[3].q = joints[1].q;
    basis[3].f[3] = 1.0f;
    *(Quadword *)(object + 0xC0) = basis[0].q;
    *(Quadword *)(object + 0xD0) = basis[1].q;
    *(Quadword *)(object + 0xE0) = basis[2].q;
    *(Quadword *)(object + 0x10) = basis[3].q;
    func_00283388(adjustment);
    adjustment[3].f[3] = 1.0f;
    adjustment[3].f[2] = -0.075f;
    adjustment[3].f[0] = 0.0f;
    adjustment[3].f[1] = 0.0f;
    func_00283788(matrix, basis, adjustment);
    packet.primitive = func_0027C878(12);
    for (i = 0; i < 4; i++) {
        packet.color[i] = 0x80808080;
        if (i == 0 || i == 2)
            func_00282D30(&packet.position[i], &D_L00_001AF030[i], *(float *)(state + 0x2C));
        else {
            func_00282D30(&packet.position[i], &D_L00_001AF030[i], *(float *)(state + 0x2C));
            packet.position[i].f[2] -= func_002A7878(0.0f, 0.1f);
        }
        packet.uv[i][0] = D_L00_001AF0B0[i][0];
        packet.uv[i][1] = D_L00_001AF0B4[i][0];
    }
    func_00280B90(&packet, matrix, 0);
    for (i = 0; i < 4; i++) {
        if (i == 0 || i == 2)
            func_00282D30(&packet.position[i], &D_L00_001AF070[i], *(float *)(state + 0x2C));
        else {
            func_00282D30(&packet.position[i], &D_L00_001AF070[i], *(float *)(state + 0x2C));
            packet.position[i].f[2] -= func_002A7878(0.0f, 0.1f);
        }
    }
    func_00280B90(&packet, matrix, 0);
    packet.primitive = func_0027C878(11);
    func_00282D30(&frame[3], &basis[2], -0.13f);
    func_00282CC0(&frame[3], &frame[3], &basis[3]);
    func_00282CF0(&frame[0], &D_L00_001B8DC0, &frame[3]);
    func_00282F20(&frame[0], &frame[0], 1.0f);
    func_00282DD8(&frame[1], &frame[0], &D_0018A0E0);
    func_00282F20(&frame[1], &frame[1], -1.0f);
    func_00282DD8(&frame[2], &frame[1], &frame[0]);
    packet.color[0] = packet.color[3] = packet.color[2] = packet.color[1] = 0x7F2020FF;
    for (i = 3; i >= 0; i--) {
        func_00282D30(&packet.position[3-i], &D_L00_001AF030[3-i], 0.1f);
        func_002830C0(&packet.position[3-i], &packet.position[3-i], frame);
    }
    func_00280B90(&packet, 0, 0);
    func_002FC560(6, func_0027C878(10));
    func_002FC560(0x42, packet.blend);
    func_002FC560(8, 0);
    func_002FC560(0x14, 0xFF9000000260ULL);
    func_002FC560(0x4A, 0);
    func_00280328();
    for (i = 195; i >= 0; i--) {
        int index = 195 - i;
        float phase;
        func_00282D30(&point, &D_L00_00290E00[index], *(float *)(state + 0x20));
        func_002830C0(&point, &point, basis);
        phase = D_L00_00291A40[index][1] - 0.025f;
        D_L00_00239020[index][0] = point.f[0];
        D_L00_00239020[index][1] = point.f[1];
        D_L00_00239020[index][2] = point.f[2];
        D_L00_00291A40[index][1] = phase;
        if (phase < -7.0f)
            D_L00_00291A40[index][1] = phase + 7.0f;
    }
    func_00281810(148, D_L00_00239020, D_L00_00292060, D_L00_00291A40, 1);
    func_00281810(50, D_L00_00239020 + 146, D_L00_00292060 + 146, D_L00_00291A40 + 146, 1);
}
