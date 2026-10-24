/* 2026-10-23 C reconstruction. Measured with -O2 -G64 -Wa,-G64 -ffunction-sections -frac2-qcopy
   -frac2-qcopy-barrier -frac2-zero-ti-por. us: 0/2 placements, 16_snivelak: 1072 bytes, expected 1016;
   us2: 0/2 placements, 16_snivelak: 1072 bytes, expected 1016; pal: canonical name absent. Render
   instance collection and repeated packet transforms reconstructed. The true32-byte UV table
   and64-byte matrices use G64 with GNU-as G64. Full frame is0xA60, but stack pointer lifetimes,
   initial clears and render-loop scheduling differ. Historical por/MMI impossibility below is
   superseded: C emits the required instruction family. Reopen when: An exact instance-collection and
   two-packet traversal witness, followed by full all-placement checking. Historical screening follows
   unchanged.
 */

/* MMI (SPECIAL2) instruction: no C spelling. 1016 bytes, level 16_snivelak.
   Retail at 0x003C32F8 carries the SPECIAL2 words 0x70002CA9, 0x70001CA9
   (+0x001C, +0x0028) - opcode 0x1C, which rabbitizer prints as `INVALID`;
   it is the MMI family (pcpyld and its relatives) the sixth wave recorded
   and that no C spelling reaches. This cc1 emits `lq`/`sq` for a `mode(TI)`
   local and `ldl`/`ldr`/`sdl`/`sdr` for a struct assignment, never the
   packed copy. ASM_FUNC candidate, as for the rest of the family. */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { float vertices[4][4]; u8 attributes[0x50]; } L16DrawPacket;
extern int D_L16_001B2648 NOT_SDA;
extern u16 *D_L16_001FB660[];
extern u8 *D_L16_001B2B1C NOT_SDA;
extern int D_L16_001B2B38 __attribute__((sda));
extern int D_L16_001B02D8 __attribute__((sda));
extern int D_L16_001B0308 __attribute__((sda));
extern float D_L16_001B02E8[8];
extern float D_L16_001B0320[16];
extern float D_L16_001B0360[16];
extern int D_L16_001B02DC NOT_SDA;
extern int D_L16_001B0310 NOT_SDA;
extern int D_L16_001B030C NOT_SDA;
extern int D_L16_001B0314 NOT_SDA;
extern float func_00283CE0(int);
extern void func_00283410(void *,void *);
extern void func_00283658(void *,void *);
extern void func_002830C0(void *,void *,void *);
extern int func_00283DB8(void *,float);
extern void func_00283788(void *,void *,void *);
extern void func_L03_002EFB60(void *,void *,float);
extern void func_L02_002EF968(void *,int,int,void *,void *,int);
extern void func_00282C88(Quad *);
extern void func_002833F0(void *,void *);
extern void func_00283098(void *,void *,void *);
extern void func_00283738(void *,void *,void *);
extern void func_00280B90(void *,void *,int);
void func_L16_003C32F8(u8 *object)
{
    float matrices[32][16],rotation[16],localRotation[12],sphere[4];
    L16DrawPacket packets[2];
    float angles[4],projected[4],combined[12];
    u16 *list;
    u8 *other;
    float phase;
    int count=0,pass,pair,i,j;
    *(Quad *)sphere = 0;
    sphere[0] = 30.0f;
    sphere[3] = 1.0f;
    *(Quad *)projected = 0;
    phase = func_00283CE0(D_L16_001B2648%1200)*0.00083333335f;
    projected[2] = (phase+phase)*3.1415927f-3.1415927f;
    *(Quad *)angles = *(Quad *)projected;
    func_00283410(rotation,angles);
    list = D_L16_001FB660[object[0x21]];
    while (object[0x21] != 255 && object[0x21] <= D_L16_001B2B38 && list) {
        if ((s16)list[-1]<0 && list != D_L16_001FB660[object[0x21]]) break;
        other = D_L16_001B2B1C+((*list&0x7FFF)<<8);
        if (!other) break;
        if (other[0x20] == 1) {
            func_00283658(matrices[count],other+0xC0);
            *(Quad *)(matrices[count]+12) = *(Quad *)(other+0x10);
            matrices[count][15] = 1.0f;
            func_002830C0(projected,sphere,matrices[count]);
            projected[3] = 30.0f;
            if (func_00283DB8(projected,512.0f) != -1) {
                func_00283788(matrices[count],matrices[count],rotation);
                func_L03_002EFB60(matrices[count],matrices[count],*(float *)(other+0x2C)/(*(float **)(other+0x24))[9]);
                *(Quad *)(matrices[count]+12) = *(Quad *)(other+0x10);
                matrices[count][15] = 1.0f;
                count++;
            }
        }
        list++;
    }
    func_L02_002EF968(&packets[0],D_L16_001B02D8,D_L16_001B0308,D_L16_001B02E8,D_L16_001B0320,1);
    func_L02_002EF968(&packets[1],D_L16_001B02DC,D_L16_001B0310,D_L16_001B02E8,D_L16_001B0360,1);
    *(int *)(packets[0].attributes+4) = D_L16_001B030C;
    *(int *)(packets[1].attributes+4) = D_L16_001B0314;
    *(int *)(packets[0].attributes+12) = D_L16_001B030C;
    *(int *)(packets[1].attributes+12) = D_L16_001B0314;
    func_00282C88((Quad *)angles);
    angles[2] = 0.3926991f;
    func_002833F0(localRotation,angles);
    for (i=0;i<2;i++) {
        func_00283098(packets[i].vertices[2],packets[i].vertices[2],localRotation);
        func_00283098(packets[i].vertices[3],packets[i].vertices[3],localRotation);
    }
    func_00283738(combined,localRotation,localRotation);
    for (pass=0;pass<16;pass++) {
        pair = (pass&1) ? 2 : 0;
        for (i=0;i<2;i++) {
            func_00283098(packets[i].vertices[pair],packets[i].vertices[pair],combined);
            func_00283098(packets[i].vertices[pair+1],packets[i].vertices[pair+1],combined);
            for (j=count;j>0;j--) func_00280B90(&packets[i],matrices[count-j],1);
        }
    }
}
