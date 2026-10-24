/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 1028 / 1028 bytes; size equality is not a match.
 * us: 0/1 placements.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: Three source/profile trials; final 1028 bytes and the correct 0x600 frame. The historical quadword transfer wall is solved, but basis/output pointer allocation and inner-loop scheduling differ. The color workspace has290 entries; draw submissions intentionally overlap boundary entries. The third vector-subtract argument is preserved explicitly.
 * Reopening condition: Recover basis/output pointer lifetimes and naturally separate the wide/narrow vertex walks.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical manual summary: The earlier screen required small-data addressing and different wide-copy address formation. The current manual draft retains the measured profile; pointer allocation and scheduling remain unresolved. The original map is retained privately; no extracted instruction, opcode, address or generated table is reproduced here. */

/* Not matched, 2026-10-23.
 * Three source/profile trials; final 1028 bytes and the correct 0x600 frame. The historical quadword transfer wall is solved, but basis/output pointer allocation and inner-loop scheduling differ. The color workspace has290 entries; draw submissions intentionally overlap boundary entries. The third vector-subtract argument is preserved explicitly.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Final us check: func_L20_0039F560: 0 of 1 places match (src/levels/20_yeedil/L20_0039F560-g8.c); exit 1.
 * This source has not passed a linked build or a runtime test.
 */
#include "common.h"
typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct { Vector vertex[4]; unsigned int color[4]; float uv[8]; unsigned long long reserved,texture,state,flags; } QuadPacket;
extern int D_L20_001AED20 __attribute__((sda));
extern float D_L20_001AED24 __attribute__((sda));
extern float D_L20_001AED28 __attribute__((sda));
extern float D_L20_001AED2C __attribute__((sda));
extern int D_L20_001AED30 __attribute__((sda));
extern Vector D_L20_001B9FC0;
extern float D_L20_0023D8D0[][3];
extern Vector D_L20_0029DC20[];
extern u8 D_L20_0029EE40[];
extern Vector D_L20_0029F760[];
extern short D_L20_0029FD60[32][4];
extern unsigned long long func_0027C878(int);
extern void func_002FC560(unsigned int,unsigned long long);
extern void func_00282C98(void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282DD8(void *,void *,void *);
extern void func_00282D30(void *,void *,float);
extern int func_00283CF0(float);
extern void func_00280328(void);
extern void func_002830C0(void *,void *,void *);
extern void func_00281810(int,void *,void *,void *,int);
extern void func_00280B90(QuadPacket *,void *,int);

void func_L20_0039F560(u8 *object)
{
    QuadPacket packet;
    Vector basis[4], up, relative, transformed;
    unsigned int colors[290];
    u8 *state=*(u8 **)(object+0x68);
    float (*output)[3];
    Vector *input;
    unsigned int *color;
    short *face;
    Vector *vertex, *narrowVertex;
    float wide,narrow;
    unsigned int rgba;
    int i,j;
    packet.texture=func_0027C878(D_L20_001AED20);
    packet.state=0xff9000000260ULL;
    packet.flags=0x8000000044ULL;
    packet.reserved=0;
    func_002FC560(0x47,0x53001);
    func_00282C98(&up);
    basis[3].q=*(Quadword *)(object+0x10);
    basis[3].f[3]=1.0f;
    output=D_L20_0023D8D0;
    i=289;
    func_00282CF0(&relative,&D_L20_001B9FC0,&basis[3]);
    func_00282F20(&basis[0],&relative,1.0f);
    func_00282DD8(&basis[1],&basis[0],&up);
    func_00282F20(&basis[1],&basis[1],1.0f);
    func_00282DD8(&basis[2],&basis[1],&basis[0]);
    func_00282D30(&basis[0],&basis[0],D_L20_001AED24);
    func_00282D30(&basis[1],&basis[1],D_L20_001AED24);
    func_00282D30(&basis[2],&basis[2],D_L20_001AED24);
    rgba=func_00283CF0((float)D_L20_001AED30 * *(float *)(state+0x14));
    packet.color[0]=packet.color[1]=packet.color[2]=packet.color[3]=(rgba&0xffffff)|*(u32 *)(state+4);
    func_002FC560(6,func_0027C878(D_L20_001AED20));
    func_002FC560(0x42,0x8000000044ULL);
    func_002FC560(8,0);
    func_002FC560(0x14,0xff9000000260ULL);
    func_002FC560(0x4a,0);
    func_00280328();
    input=D_L20_0029DC20;
    color=colors;
    do {
        func_002830C0(&transformed,input,basis);
        i--;
        (*output)[0]=transformed.f[0];
        (*output)[1]=transformed.f[1];
        (*output)[2]=transformed.f[2];
        *color=packet.color[0];
        output++;color++;input++;
    } while (i>=0);
    func_00281810(148,D_L20_0023D8D0,colors,D_L20_0029EE40,1);
    func_00281810(109,(u8 *)D_L20_0023D8D0+0x6d8,colors+146,D_L20_0029EE40+0x490,1);
    func_00281810(36,(u8 *)D_L20_0023D8D0+0xbe8,colors+254,D_L20_0029EE40+0x7f0,1);
    packet.texture=func_0027C878(11);
    packet.flags=0x8000000048ULL;
    rgba=func_00283CF0(*(float *)(state+0x14)*64.0f);
    packet.color[0]=(rgba<<24)|*(u32 *)(state+4);
    packet.color[1]=packet.color[0];
    packet.color[3]=0;packet.color[2]=0;
    wide=D_L20_001AED28*D_L20_001AED2C;
    narrow=D_L20_001AED28;
    i=0;
    do {
        face=D_L20_0029FD60[i];
        i++;
        vertex=packet.vertex;
        narrowVertex=packet.vertex;
        j=0;
        do {
            if (j>=2) func_00282D30(vertex,&D_L20_0029F760[*face],wide);
            else func_00282D30(narrowVertex,&D_L20_0029F760[*face],narrow);
            j++; vertex++; narrowVertex++; face++;
        } while (j<4);
        packet.uv[0]=0.5f;
        packet.uv[1]=0.5f;
        packet.uv[2]=0.5f;
        packet.uv[3]=0.5f;
        packet.uv[4]=0.5f;
        packet.uv[5]=1.0f;
        packet.uv[6]=0.5f;
        packet.uv[7]=1.0f;
        func_00280B90(&packet,basis,0);
    } while (i<32);
}
