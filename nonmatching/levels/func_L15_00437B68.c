/*
 * Complete manual reconstruction retained as nonmatching; no coverage credit.
 * Fresh qualified-compiler checks, 2026-10-25.
 * Profile: -O2 -G8 -ffunction-sections -fno-strength-reduce
 * Coverage: US: 0/1; US2: 0/1; PAL: 0/1.
 * Compiled text: 1716 bytes; retail: 1740 bytes.
 * Remaining difference: The full packet is 208 bytes:144 bytes of draw data and a complete64-byte
 * matrix. Snapshotting all three corner indices before82D30, separate U/V and color-index streams,
 * and the observed face/corner update phase improve1600 to1704 bytes. The bounded no-strength-
 * reduce hypothesis gives1716/1740 and restores frame0x150; the remaining SQ/LQ spill belongs to
 * face rather than the retail corner counter. No scalar was falsely declared TI and external array
 * bounds remain unknown. Alpha extraction keeps the observed signed right shift, with an unsigned
 * operand for the final color left shift.
 * Reopen when: Recover the true integer induction/caller-save allocation from real allocator
 * diagnostics; preserve packet/matrix sizes and avoid forced spills, fabricated extents or TI
 * scalar types.
 */

#include "common.h"

#include "include_asm.h"
typedef struct { float x,y,z,w; } GornVec __attribute__((aligned(16)));
typedef unsigned int GornQuad __attribute__((mode(TI)));
typedef struct { GornVec vertex[4]; unsigned int color[4]; float uv[8]; long long tag[4]; GornVec matrix[4]; } GornPacket;
typedef struct { short position,uv,color; } GornCorner;
extern GornVec D_L15_002B6D50[];
extern GornCorner D_L15_002B74E0[][4];
extern float D_L15_002B7E40[][2];
extern unsigned int D_L15_002B8688[];
extern int D_001B1870,D_001B1878;
extern long long func_0027C878(int);
extern void func_00282D30(void *,const void *,float);
extern void func_00280B90(void *,void *,int);
void func_L15_00437B68(char *object,int preview)
{
    GornPacket packet;
    char *state;
    int i,face,corner,alpha;
    unsigned int color;
    GornCorner *indices;
    short *color_indices;
    GornVec *vertex;
    float *u, *v;
    unsigned int *colors;
    state=*(char **)(object+0x68);
    packet.tag[1]=func_0027C878(72);
    packet.tag[2]=0xFF9000000260LL;
    packet.tag[3]=0x8000000044LL;
    packet.tag[0]=0;
    qcopy(&packet.matrix[0], (object+0xC0));
    qcopy(&packet.matrix[1], (object+0xD0));
    qcopy(&packet.matrix[2], (object+0xE0));
    packet.matrix[3].x=*(float *)(object+0x10);
    packet.matrix[3].y=*(float *)(object+0x14);
    packet.matrix[3].z=*(float *)(object+0x18);
    packet.matrix[3].w=1.0f;
    packet.color[0]=0x80808080;
    packet.color[3]=0x80808080;
    packet.color[2]=0x80808080;
    packet.color[1]=0x80808080;
    *(float *)(state+4)-=0.00045f;
    if (*(float *)(state+4)<=-8.0f) *(float *)(state+4)+=8.0f;
    if (preview) {
        for (i=120;i>=0;i--) D_L15_002B6D50[i].z=300.0f;
        for(face=0;face<100;) {
            indices=D_L15_002B74E0[face++];color_indices=&indices->color;vertex=packet.vertex;u=packet.uv;v=packet.uv+1;colors=packet.color;
            corner=0;
            while(corner<4) {
                short position_index=indices->position, uv_index=indices->uv, color_index=*color_indices;
                ++corner;
                func_00282D30(vertex,&D_L15_002B6D50[position_index],1.0f);
                *u=D_L15_002B7E40[uv_index][0]+*(float *)(state+4);
                *v=D_L15_002B7E40[uv_index][1];
                *colors=(D_L15_002B8688[color_index]&0xFFFFFF)|0x7F000000;
                vertex++;u+=2;v+=2;colors++;indices++;color_indices+=3;
            }
            func_00280B90(&packet,0,0);
        }
        return;
    }
    for (i=120;i>=0;i--) D_L15_002B6D50[i].z=800.0f;
    for(face=0;face<100;) {
        indices=D_L15_002B74E0[face++];color_indices=&indices->color;vertex=packet.vertex;u=packet.uv;v=packet.uv+1;colors=packet.color;
        for(corner=3;corner>=0;corner--) {
            short position_index=indices->position, uv_index=indices->uv, color_index=*color_indices;
                func_00282D30(vertex,&D_L15_002B6D50[position_index],1.0f);
            *u=D_L15_002B7E40[uv_index][0]+*(float *)(state+4);
            *v=D_L15_002B7E40[uv_index][1];
            *colors=D_L15_002B8688[color_index];
            vertex++;u+=2;v+=2;colors++;indices++;color_indices+=3;
        }
        func_00280B90(&packet,0,0);
    }
    for (i=120;i>=0;i--) D_L15_002B6D50[i].z=1200.0f;
    for(face=0;face<100;) {
        indices=D_L15_002B74E0[face++];color_indices=&indices->color;vertex=packet.vertex;u=packet.uv;v=packet.uv+1;colors=packet.color;
        for(corner=3;corner>=0;corner--) {
            short position_index=indices->position, uv_index=indices->uv, color_index=*color_indices;
                func_00282D30(vertex,&D_L15_002B6D50[position_index],1.0f);
            *u=D_L15_002B7E40[uv_index][0]+*(float *)(state+4);
            *v=D_L15_002B7E40[uv_index][1];
            *colors=D_L15_002B8688[color_index];
            vertex++;u+=2;v+=2;colors++;indices++;color_indices+=3;
        }
        func_00280B90(&packet,0,0);
    }
    if (D_001B1870) {
        for (i=120;i>=0;i--) D_L15_002B6D50[i].z=405.0f;
        for(face=0;face<100;) {
            indices=D_L15_002B74E0[face++];color_indices=&indices->color;vertex=packet.vertex;u=packet.uv;v=packet.uv+1;colors=packet.color;
            for(corner=0;corner<4;corner++) {
                short position_index=indices->position, uv_index=indices->uv, color_index=*color_indices;
                func_00282D30(vertex,&D_L15_002B6D50[position_index],1.0f);
                *u=D_L15_002B7E40[uv_index][0]+*(float *)(state+4);
                *v=D_L15_002B7E40[uv_index][1];
                color=D_L15_002B8688[color_index];
                alpha=((int)color>>24)-D_001B1878;
                if (alpha<0) alpha=0;
                *colors=(color&0xFFFFFF)|((unsigned int)alpha<<24);
                vertex++;u+=2;v+=2;colors++;indices++;color_indices+=3;
            }
            func_00280B90(&packet,0,0);
        }
    }
}
