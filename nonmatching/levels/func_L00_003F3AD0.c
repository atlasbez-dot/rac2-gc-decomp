/* Bounded manual reconstruction, 2026-10-25; not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 668/668 bytes; us: 0/27 placements; us2: 0/27 placements; pal: 0/27 placements.
 * The full 144-byte packet, 64-byte matrix and two complete 16-byte vectors remain separate
 * objects; two UV streams stay inside the packet view. Frame 0x160 differs from retail 0x170 and
 * corner-loop allocation remains different.
 * Reopen with evidence for pointer spill lifetimes and the retail incrementing corner loop, rather
 * than declaration permutations.
 * Prior complete variants and diagnostic dumps are preserved privately.
 * No candidate or linked-build credit is claimed.
 */
#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
typedef struct {
    TI128 vertices[4];
    unsigned int colors[4];
    float uv[4][2];
    unsigned long long header[4];
} RenderPacket3AD0Fields;

/* Both views cover the complete 144-byte draw packet. Its UV component
   streams remain within this object, including their final loop steps. */
typedef union { RenderPacket3AD0Fields fields; float scalars[36]; } RenderPacket3AD0;
extern unsigned long long func_0027C878(int);
extern void func_00282D30(void *,void *,float);
extern void func_002830C0(void *,void *,void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_00283098(void *,void *,void *);
extern float func_00282DB0(void *,void *);
extern void func_00280B90(void *,void *,int);
extern TI128 D_L00_001B8DC0;
extern TI128 D_L00_0029EDB0[];
extern TI128 D_L00_0029EA90[];
extern short D_L00_0029E440[][8];
extern TI128 D_L00_0029DE00[];
extern float D_L00_0029E760[][2];
void func_L00_003F3AD0(char *object)
{
    RenderPacket3AD0 packet;
    TI128 matrix[4], facing, transformed;
    int *state=*(int **)(object+0x68);
    int face,corner;
    unsigned int color;
    short *indices;
    float *u, *v;
    TI128 *vertex;
    unsigned int *colors;
    packet.fields.header[1]=func_0027C878(5);
    packet.fields.header[2]=0xff9000000260ULL;
    packet.fields.header[3]=0x8000000048ULL;
    packet.fields.header[0]=0;
    qcopy(&matrix[0], object + 0xc0);
    qcopy(&matrix[1], object + 0xd0);
    qcopy(&matrix[2], object + 0xe0);
    ((float *)&matrix[3])[0]=*(float *)(object+0x10);
    ((float *)&matrix[3])[1]=*(float *)(object+0x14);
    ((float *)&matrix[3])[2]=*(float *)(object+0x18);
    ((float *)&matrix[3])[3]=1.0f;
    color=(*state<<24)|0xff0000;
    packet.fields.colors[0]=color;
    packet.fields.colors[1]=color;
    packet.fields.colors[2]=color;
    packet.fields.colors[3]=color;
    for (face=0;face<50;) {
        int faceIndex = face++;
        func_00282D30(&transformed,&D_L00_0029EDB0[faceIndex],1.0f);
        indices=D_L00_0029E440[faceIndex];
        func_002830C0(&transformed,&transformed,matrix);
        func_00282CF0(&facing,&transformed,&D_L00_001B8DC0);
        func_00282F20(&facing,&facing,1.0f);
        func_00283098(&transformed,&D_L00_0029EA90[faceIndex],matrix);
        func_00282DB0(&facing,&transformed);
        vertex=packet.fields.vertices;
        colors=packet.fields.colors;
        u=packet.scalars+20;
        v=packet.scalars+21;
        for (corner=0;corner<4;corner++,indices+=2,vertex++,colors++,u+=2,v+=2) {
            func_00282D30(vertex,&D_L00_0029DE00[indices[0]],1.0f);
            *u=D_L00_0029E760[indices[1]][0];
            *v=D_L00_0029E760[indices[1]][1];
            if (((float *)&D_L00_0029DE00[indices[0]])[2] == 0.001432f) *colors=0xff0000;
        }
        func_00280B90(packet.fields.vertices,matrix,0);
    }
}
