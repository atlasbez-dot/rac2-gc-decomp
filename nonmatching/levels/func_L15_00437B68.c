/* Retention review: external whole-object extents remain incomplete.
 * Declaration-only corrections below were not recompiled. Measurements in the
 * retained header describe the original private trial, not this revised text.
 */
/* Retained complete manual C; no linked byte credit.
 * Profile: -O2 -G8 -Wa,-G8 -ffunction-sections -g -frac2-qcopy -frac2-qcopy-barrier
 * Compiled text: 1600 bytes. us: 0/1, us2: 0/1, pal: 0/1.
 * Residual: The draft uses a 0x130 frame rather than 0x150; retail spills the inner-loop counter with sq/lq and has different loop and GPR scheduling.
 * Reopen: Evidence explaining the actual loop-counter/storage type and source lifetime; do not force TI solely to create the retail spill.
 */
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
    GornVec *vertex;
    float *uv;
    unsigned int *colors;
    state=*(char **)(object+0x68);
    packet.tag[1]=func_0027C878(72);
    packet.tag[2]=0xFF9000000260LL;
    packet.tag[3]=0x8000000044LL;
    packet.tag[0]=0;
    *(GornQuad *)&packet.matrix[0]=*(GornQuad *)(object+0xC0);
    *(GornQuad *)&packet.matrix[1]=*(GornQuad *)(object+0xD0);
    *(GornQuad *)&packet.matrix[2]=*(GornQuad *)(object+0xE0);
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
        for(face=0;face<100;face++) {
            indices=D_L15_002B74E0[face];vertex=packet.vertex;uv=packet.uv;colors=packet.color;
            for(corner=0;corner<4;corner++) {
                func_00282D30(vertex,&D_L15_002B6D50[indices->position],1.0f);
                *uv=D_L15_002B7E40[indices->uv][0]+*(float *)(state+4);
                uv[1]=D_L15_002B7E40[indices->uv][1];
                *colors=(D_L15_002B8688[indices->color]&0xFFFFFF)|0x7F000000;
                vertex++;uv+=2;colors++;indices++;
            }
            func_00280B90(&packet,0,0);
        }
        return;
    }
    for (i=120;i>=0;i--) D_L15_002B6D50[i].z=800.0f;
    for(face=0;face<100;face++) {
        indices=D_L15_002B74E0[face];vertex=packet.vertex;uv=packet.uv;colors=packet.color;
        for(corner=3;corner>=0;corner--) {
            func_00282D30(vertex,&D_L15_002B6D50[indices->position],1.0f);
            *uv=D_L15_002B7E40[indices->uv][0]+*(float *)(state+4);
            uv[1]=D_L15_002B7E40[indices->uv][1];
            *colors=D_L15_002B8688[indices->color];
            vertex++;uv+=2;colors++;indices++;
        }
        func_00280B90(&packet,0,0);
    }
    for (i=120;i>=0;i--) D_L15_002B6D50[i].z=1200.0f;
    for(face=0;face<100;face++) {
        indices=D_L15_002B74E0[face];vertex=packet.vertex;uv=packet.uv;colors=packet.color;
        for(corner=3;corner>=0;corner--) {
            func_00282D30(vertex,&D_L15_002B6D50[indices->position],1.0f);
            *uv=D_L15_002B7E40[indices->uv][0]+*(float *)(state+4);
            uv[1]=D_L15_002B7E40[indices->uv][1];
            *colors=D_L15_002B8688[indices->color];
            vertex++;uv+=2;colors++;indices++;
        }
        func_00280B90(&packet,0,0);
    }
    if (D_001B1870) {
        for (i=120;i>=0;i--) D_L15_002B6D50[i].z=405.0f;
        for(face=0;face<100;face++) {
            indices=D_L15_002B74E0[face];vertex=packet.vertex;uv=packet.uv;colors=packet.color;
            for(corner=0;corner<4;corner++) {
                func_00282D30(vertex,&D_L15_002B6D50[indices->position],1.0f);
                *uv=D_L15_002B7E40[indices->uv][0]+*(float *)(state+4);
                uv[1]=D_L15_002B7E40[indices->uv][1];
                color=D_L15_002B8688[indices->color];
                alpha=((int)color>>24)-D_001B1878;
                if (alpha<0) alpha=0;
                *colors=(color&0xFFFFFF)|(alpha<<24);
                vertex++;uv+=2;colors++;indices++;
            }
            func_00280B90(&packet,0,0);
        }
    }
}
