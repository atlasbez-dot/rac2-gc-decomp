/* 2026-10-23 bounded reconstruction, not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0 of 27 places match (src/levels/shared/L00_003F3AD0-qcopy.c); us2: 0 of 27 places match (src/levels/shared/L00_003F3AD0-qcopy.c); pal: 0 of 27 places match (src/levels/shared/L00_003F3AD0-qcopy.c).
 * 652/668 bytes, 0x160 frame versus retail 0x170. Same render family as 003F37E8 with distinct geometry and height threshold. Reopen with original render argument and loop-lifetime structure.
 * Historical note below is retained; its no-C-attempt statement predates this draft.
 */
/* from src/levels/shared/L00_003EE100.c: not written this wave. Retail 668 bytes, 27 place(s), first word at L00:003f3ad0.
 * Rule: MMI/LQ/SQ (op 0x1e).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x003f3ad0  addiu       $sp, $sp, -0x170
 *   0x003f3ad4  sd          $s0, 0x110($sp)
 *   0x003f3ad8  sd          $s2, 0x120($sp)
 *   0x003f3adc  daddu       $s0, $a0, $zero
 *   0x003f3ae0  sd          $s3, 0x128($sp)
 *   0x003f3ae4  addiu       $a0, $zero, 0x5
 * Kept as data for the maintainers. */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
typedef struct {
    TI128 vertices[4];
    unsigned int colors[4];
    float uv[4][2];
    unsigned long long header[4];
    TI128 matrix[4];
    TI128 facing;
    TI128 transformed;
} RenderPacket3AD0;
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
    int *state=*(int **)(object+0x68);
    int face,corner;
    unsigned int color;
    short *indices;
    float *uv;
    TI128 *vertex;
    unsigned int *colors;
    packet.header[1]=func_0027C878(5);
    packet.header[2]=0xff9000000260ULL;
    packet.header[3]=0x8000000048ULL;
    packet.header[0]=0;
    packet.matrix[0]=*(TI128 *)(object+0xc0);
    packet.matrix[1]=*(TI128 *)(object+0xd0);
    packet.matrix[2]=*(TI128 *)(object+0xe0);
    ((float *)&packet.matrix[3])[0]=*(float *)(object+0x10);
    ((float *)&packet.matrix[3])[1]=*(float *)(object+0x14);
    ((float *)&packet.matrix[3])[2]=*(float *)(object+0x18);
    ((float *)&packet.matrix[3])[3]=1.0f;
    color=(*state<<24)|0xff0000;
    packet.colors[0]=color;
    packet.colors[1]=color;
    packet.colors[2]=color;
    packet.colors[3]=color;
    for (face=0;face<50;face++) {
        func_00282D30(&packet.transformed,&D_L00_0029EDB0[face],1.0f);
        indices=D_L00_0029E440[face];
        func_002830C0(&packet.transformed,&packet.transformed,packet.matrix);
        func_00282CF0(&packet.facing,&packet.transformed,&D_L00_001B8DC0);
        func_00282F20(&packet.facing,&packet.facing,1.0f);
        func_00283098(&packet.transformed,&D_L00_0029EA90[face],packet.matrix);
        func_00282DB0(&packet.facing,&packet.transformed);
        vertex=packet.vertices;
        colors=packet.colors;
        uv=&packet.uv[0][0];
        for (corner=0;corner<4;corner++,indices+=2,vertex++,colors++,uv+=2) {
            func_00282D30(vertex,&D_L00_0029DE00[indices[0]],1.0f);
            uv[0]=D_L00_0029E760[indices[1]][0];
            uv[1]=D_L00_0029E760[indices[1]][1];
            if (((float *)&D_L00_0029DE00[indices[0]])[2] == 0.001432f) *colors=0xff0000;
        }
        func_00280B90(packet.vertices,packet.matrix,0);
    }
}
