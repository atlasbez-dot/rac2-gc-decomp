/* Retained complete manual C; no linked byte credit.
 * Profile: -O2 -G8 -Wa,-G8 -ffunction-sections
 * Compiled text: 844 bytes. us: 0/1, us2: 0/1, pal: 0/1.
 * Residual: The 0x160 frame agrees; allocation and loop scheduling differ as in func_00327D50.
 * Reopen: Original packet/state field types and lifetime evidence; retain numeric texture ID and full 64-bit descriptor return.
 */
#include "include_asm.h"
typedef struct { float x,y,z,w; } RenderVec __attribute__((aligned(16)));
typedef unsigned int RenderQuad __attribute__((mode(TI)));
typedef struct { RenderVec vertex[4]; unsigned int color[4]; float uv[8]; long long tag[4]; RenderVec matrix[4]; } RenderPacket;
extern long long func_0027C878(int);
extern void func_00282CF0(void *,const void *,const void *);
extern void func_00282F20(void *,const void *,float);
extern void func_00282DD8(void *,const void *,const void *);
extern void func_00282D30(void *,const void *,float);
extern void func_002830C0(void *,const void *,const void *);
extern void func_0027C768(void *,float *,float *);
extern float func_00283180(float),func_00283198(float),func_002A7798(float),func_00283B98(float,float);
extern void func_00280B90(void *,void *,int);
extern RenderVec D_001B5340;
extern int D_001B0A4C __attribute__((sda));
extern int D_001B0A50 __attribute__((sda));
extern int D_001B0A54 __attribute__((sda));
extern int D_001B0A58 __attribute__((sda));
extern int D_001B0A5C __attribute__((sda));
extern int D_001B0A60 __attribute__((sda));
extern unsigned int D_001B0A64 __attribute__((sda));
extern float D_001B0954 __attribute__((sda));
extern short D_0026C020[][2];
extern RenderVec D_0026BA20[];
extern float D_002373F0[][2] __attribute__((sda));
void func_00330EC0(char *object)
{
    RenderPacket packet;
    RenderVec up, *vertex;
    char *state;
    int face, corner, index;
    short (*indices)[2];
    float *u,*v,*phase;
    float delta;
    state=*(char **)(object+0x68);
    *(RenderQuad *)&up=0;
    up.z=1.0f;
    packet.tag[1]=func_0027C878(D_001B0A60);
    packet.tag[2]=0xFF9000000260LL;
    packet.tag[3]=(long long)D_001B0A4C | ((long long)D_001B0A50<<2) |
                  ((long long)D_001B0A54<<4) | ((long long)D_001B0A58<<6) | ((long long)D_001B0A5C<<32);
    packet.tag[0]=0;
    func_00282CF0(&packet.matrix[0],&D_001B5340,object+0x10);
    func_00282F20(&packet.matrix[0],&packet.matrix[0],1.0f);
    func_00282DD8(&packet.matrix[1],&packet.matrix[0],&up);
    func_00282F20(&packet.matrix[1],&packet.matrix[1],1.0f);
    func_00282DD8(&packet.matrix[2],&packet.matrix[1],&packet.matrix[0]);
    packet.matrix[3].x=*(float *)(object+0x10);
    packet.matrix[3].y=*(float *)(object+0x14);
    packet.matrix[3].z=*(float *)(object+0x18);
    packet.matrix[3].w=1.0f;
    packet.color[0]=D_001B0A64;
    packet.color[3]=D_001B0A64;
    packet.color[2]=D_001B0A64;
    packet.color[1]=D_001B0A64;
    for(face=0;face<48;face++) {
        indices=D_0026C020+face*4;
        u=packet.uv; v=packet.uv+1; vertex=packet.vertex;
        for(corner=3;corner>=0;corner--) {
            index=indices[0][1];
            func_00282D30(vertex,&D_0026BA20[indices[0][0]],*(float *)(state+0x64)*2.0f);
            func_002830C0(vertex,vertex,packet.matrix);
            func_0027C768(vertex,u,v);
            phase=D_002373F0[index];
            delta=func_00283180(phase[0]);
            delta*=func_002A7798((1.0f-*(float *)(state+0x64)/D_001B0954)*0.0125f);
            *u+=delta;
            delta=func_00283198(phase[0]);
            delta=-delta*func_002A7798((1.0f-*(float *)(state+0x64)/D_001B0954)*0.0125f);
            *v+=delta;
            if (*u>1.0f) *u=1.0f; else if (*u<0.0f) *u=0.0f;
            if (*v>1.0f) *v=1.0f; else if (*v<0.0f) *v=0.0f;
            u+=2; v+=2; indices++; vertex++;
        }
        func_00280B90(&packet,0,0);
    }
    phase=D_002373F0[0];
    for(face=97;face>=0;face--) {
        phase[0]=func_00283B98(phase[0],phase[1]);
        phase+=2;
    }
}
