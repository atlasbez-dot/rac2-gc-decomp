/* Retained complete manual C; no linked byte credit.
 * Profile: -O2 -G8 -Wa,-G8 -ffunction-sections
 * Compiled text: 844 bytes. us: 0/1, us2: 0/1, pal: 0/1.
 * Residual: The 0x160 frame agrees; GPR allocation, scalar GP setup, loop pointers and operation scheduling differ.
 * Reopen: Original packet/state field types and lifetime evidence; pointer induction and truthful scalar SDA declarations have already been tried.
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
extern int D_001B01B4 __attribute__((sda));
extern int D_001B01B8 __attribute__((sda));
extern int D_001B01BC __attribute__((sda));
extern int D_001B01C0 __attribute__((sda));
extern int D_001B01C4 __attribute__((sda));
extern int D_001B01C8 __attribute__((sda));
extern unsigned int D_001B01CC __attribute__((sda));
extern float D_001B00F4 __attribute__((sda));
extern short D_0026A6A0[][2];
extern RenderVec D_0026A0A0[];
extern float D_0022AC90[][2] __attribute__((sda));
void func_00327D50(char *object)
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
    packet.tag[1]=func_0027C878(D_001B01C8);
    packet.tag[2]=0xFF9000000260LL;
    packet.tag[3]=(long long)D_001B01B4 | ((long long)D_001B01B8<<2) |
                  ((long long)D_001B01BC<<4) | ((long long)D_001B01C0<<6) | ((long long)D_001B01C4<<32);
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
    packet.color[0]=D_001B01CC;
    packet.color[3]=D_001B01CC;
    packet.color[2]=D_001B01CC;
    packet.color[1]=D_001B01CC;
    for(face=0;face<48;face++) {
        indices=D_0026A6A0+face*4;
        u=packet.uv; v=packet.uv+1; vertex=packet.vertex;
        for(corner=3;corner>=0;corner--) {
            index=indices[0][1];
            func_00282D30(vertex,&D_0026A0A0[indices[0][0]],*(float *)(state+0x24)*2.0f);
            func_002830C0(vertex,vertex,packet.matrix);
            func_0027C768(vertex,u,v);
            phase=D_0022AC90[index];
            delta=func_00283180(phase[0]);
            delta*=func_002A7798((1.0f-*(float *)(state+0x24)/D_001B00F4)*0.0125f);
            *u+=delta;
            delta=func_00283198(phase[0]);
            delta=-delta*func_002A7798((1.0f-*(float *)(state+0x24)/D_001B00F4)*0.0125f);
            *v+=delta;
            if (*u>1.0f) *u=1.0f; else if (*u<0.0f) *u=0.0f;
            if (*v>1.0f) *v=1.0f; else if (*v<0.0f) *v=0.0f;
            u+=2; v+=2; indices++; vertex++;
        }
        func_00280B90(&packet,0,0);
    }
    phase=D_0022AC90[0];
    for(face=97;face>=0;face--) {
        phase[0]=func_00283B98(phase[0],phase[1]);
        phase+=2;
    }
}
