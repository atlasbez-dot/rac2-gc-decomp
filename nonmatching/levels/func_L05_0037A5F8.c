/* 2026-10-23 reconstruction. Measured with -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-
   barrier -frac2-zero-ti-por. us: 0/4 placements; 05_feltzin_system: 1156 bytes, expected 1168; us2:
   0/4 placements; 05_feltzin_system: 1156 bytes, expected 1168; pal: 0/4 placements;
   05_feltzin_system: 1156 bytes, expected 1168. Three meaningful trials. Historical por-clear
   impossibility below is superseded by the qualified zero-TI profile. Retained complete HUD traversal
   preserves64-bit texture/color words and signed color extension. Remaining frame/prologue, zero-clear
   and scalar scheduling differ by12bytes. Reopen with an exact HUD transform witness. Historical
   screening is preserved below. */

/* MMI (SPECIAL2) instruction: no C spelling. 1168 bytes, level
   05_feltzin_system. Retail at 0x0037A5F8 carries the SPECIAL2 words
   0x700024A9, 0x700014A9 (+0x018C, +0x0304) - opcode 0x1C, which rabbitizer
   prints as `INVALID`; it is the MMI family (pcpyld and its relatives) the
   sixth wave recorded and that no C spelling reaches. This cc1 emits
   `lq`/`sq` for a `mode(TI)` local and `ldl`/`ldr`/`sdl`/`sdr` for a struct
   assignment, never the packed copy. ASM_FUNC candidate, as for the rest of
   the family. */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
extern float D_L05_001AC4E0 __attribute__((sda));
extern float D_L05_001AC4E4 __attribute__((sda));
extern float D_L05_001AC4E8 __attribute__((sda));
extern float D_L05_001AC4EC __attribute__((sda));
extern int D_L05_001AC4F0 __attribute__((sda));
extern int D_L05_001AC4F4 __attribute__((sda));
extern float D_L05_001AC4F8 __attribute__((sda));
extern int D_L05_001AC4FC __attribute__((sda));
extern float D_L05_001B2D84 NOT_SDA;
extern u8 *D_L05_00225DD0[];
extern u16 *D_L05_001FB220[];
extern u8 *D_L05_001B251C NOT_SDA;
extern float D_L05_001B96C0[4];
extern float D_L05_001B98F0[12];
extern u64 func_0027C878(int);
extern void func_L05_003008C0(float,float,float,float,int,int,int,int,u64,u64);
extern int func_L00_004272A0(void);
extern s32 func_002ED688(u8 *);
extern float func_00282E48(void *,void *);
extern void func_002833F0(void *,void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_002836E8(void *,void *);
extern void func_00283098(void *,void *,void *);
extern float func_002A7798(float);
extern int func_00283CF0(float);
void func_L05_0037A5F8(void)
{
    float offset[4],rotation[4],rotate[12],view[12];
    float distance,scale,size,x,y,initialY;
    u64 texture,color;
    u8 *object,*state;
    u16 *list;
    int i,alpha;
    initialY = (float)(int)(D_L05_001AC4E4*D_L05_001B2D84+0.5f);
    texture = func_0027C878(D_L05_001AC4FC);
    func_L05_003008C0(D_L05_001AC4E0,initialY,D_L05_001AC4E8,D_L05_001AC4EC,0,0,D_L05_001AC4F0,D_L05_001AC4F4,0x80808080ULL,texture);
    for (i=0;i<func_L00_004272A0();) {
        list = D_L05_001FB220[D_L05_00225DD0[i][0x21]];
        i++;
        if (!list) continue;
        do {
            object = D_L05_001B251C+((*list&0x7FFF)<<8);
            state = (u8 *)func_002ED688(object);
            if (*(int *)(state+0x110) && *(int *)(state+0x14C)) {
                distance = func_00282E48(D_L05_001B96C0,object+0x10);
                if (distance <= 128.0f) {
                    *(Quad *)rotation = 0;
                    rotation[2] = 1.5707964f;
                    scale = distance*D_L05_001AC4F8*0.0078125f;
                    func_002833F0(rotate,rotation);
                    func_00282CF0(offset,object+0x10,D_L05_001B96C0);
                    func_00282F20(offset,offset,scale);
                    func_002836E8(view,D_L05_001B98F0);
                    func_00283098(offset,offset,view);
                    func_00283098(offset,offset,rotate);
                    alpha = func_00283CF0(func_002A7798(1.0f-distance*0.0078125f)*128.0f);
                    size = offset[2]*0.125f+D_L05_001AC4E8*0.5f;
                    if (*(int *)(state+0x158)) { alpha=128; size=D_L05_001AC4E8*0.5f; }
                    if (size <= D_L05_001AC4E8+D_L05_001AC4E8) { if (size < 0.0f) size=0.0f; }
                    else size=D_L05_001AC4E8+D_L05_001AC4E8;
                    x = offset[0]+D_L05_001AC4E0;
                    y = (float)(int)((D_L05_001AC4E4-offset[1])*D_L05_001B2D84+0.5f);
                    color = (s64)(*(s32 *)(state+0x150) | (alpha<<24));
                    texture = func_0027C878(D_L05_001AC4FC);
                    func_L05_003008C0(x,y,size,size,0,0,D_L05_001AC4F0,D_L05_001AC4F4,color,texture);
                } else if (*(int *)(state+0x158)) {
                    *(Quad *)rotation = 0;
                    rotation[2] = 1.5707964f;
                    scale = D_L05_001AC4F8;
                    func_002833F0(rotate,rotation);
                    func_00282CF0(offset,object+0x10,D_L05_001B96C0);
                    func_00282F20(offset,offset,scale);
                    func_002836E8(view,D_L05_001B98F0);
                    func_00283098(offset,offset,view);
                    func_00283098(offset,offset,rotate);
                    size = D_L05_001AC4E8;
                    if (size <= D_L05_001AC4E8+D_L05_001AC4E8) { if (size<0.0f) size=0.0f; }
                    else size=D_L05_001AC4E8+D_L05_001AC4E8;
                    x = offset[0]+D_L05_001AC4E0;
                    y = (float)(int)((D_L05_001AC4E4-offset[1])*D_L05_001B2D84+0.5f);
                    color = (s64)(s32)(*(u32 *)(state+0x150) | 0x80000000U);
                    texture = func_0027C878(D_L05_001AC4FC);
                    func_L05_003008C0(x,y,size,size,0,0,D_L05_001AC4F0,D_L05_001AC4F4,color,texture);
                }
            }
        } while ((s16)*list++ >= 0);
    }
}
