/* Bounded manual reconstruction, 2026-10-23; not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: func_L16_003959B8: 0 of 2 places match (src/levels/shared/L16_003959B8-g8-qcopy.c); us2: func_L16_003959B8: 0 of 2 places match (src/levels/shared/L16_003959B8-g8-qcopy.c); pal: func_L16_003959B8 is in neither catalogue of pal
 * 592/584 bytes after correcting resident field offsets; pointer allocation and repeated resident/global address materialization differ. Natural vector/angle operations and exact constants are retained. Reopen with original resident object layout and source-order evidence.
 * Historical screening note below predates this C reconstruction.
 */
/* func_L16_003959B8 - 584 bytes, 2 place(s), level 16_snivelak, retail at
   0x003959b8. Screened with tools/w10_screen.py: 16 call(s)
   [func_L00_002B39F0@00395A00, func_00282CF0@00395A20,
   func_00282DD8@00395A30, func_00282F20@00395A40, func_002AFDD8@00395A58,
   func_00282F70@00395A6C, func_00283098@00395A80, func_00282DB0@00395A8C,
   func_002AA2E8@00395ADC, func_002AA2E8@00395AFC, func_00282F20@00395B28,
   func_00282CC0@00395B38, func_00282CC0@00395B90, func_00282A88@00395BA4,
   func_00282CF0@00395BB4, func_002AC9F8@00395BC8]; data addresses
   materialised [0x190000, 0x3daa0000, 0x3ab60000, 0x3ab60000, 0x40c90000,
   0x190000, 0x3dcc0000]; float constants [0x3f800000, 0x3f000000,
   0x3f800000]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [LQ/SQ 7A220000@0x0054,
   LQ/SQ 7E620000@0x0058]. Head: addiu $sp, $sp, -0xB0 ; swc1 $f20,
   0xA0($sp) ; sd $s0, 0x50($sp) ; sd $s1, 0x58($sp) ; lui $s0, 0x19 ; sd
   $s3, 0x68($sp). Not matched in this wave: the 128-bit copy needs an
   `lq`/`sq` pair; plain C reaches it only through a `mode(TI)` local, and
   this cc1 folds the destination offset into the `sq` where retail
   materialises the pointer first. What would unblock it: the exact source
   expression tree, so this cc1 picks the same registers in the same order. */

#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
typedef struct { Vector128 difference, local, previous, velocity, lateral; } MotionWorkspace;
extern char D_00189E20[];
extern float D_00189FB0[4];
extern float D_L16_001AF43C __attribute__((sda));
extern void func_L00_002B39F0(int,float);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282DD8(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_002AFDD8(char *,char *,char *,char *);
extern void func_00282F70(void *,void *,float);
extern void func_00283098(void *,void *,void *);
extern float func_00282DB0(void *,void *);
extern float func_002AA2E8(float *,float,float);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282A88(void *,int);
extern void func_002AC9F8(float *,float);
void func_L16_003959B8(char *object)
{
    MotionWorkspace local;
    char *state=*(char **)(object+0x68);
    float alignment;
    func_L00_002B39F0(0,1.0f);
    *(Vector128 *)&local.previous=*(Vector128 *)D_00189FB0;
    func_00282CF0(&local.difference,D_00189E20+0x80,object+0x10);
    func_00282DD8(D_00189FB0,&local.difference,object+0xe0);
    func_00282F20(D_00189FB0,D_00189FB0,1.0f);
    func_002AFDD8(object,(char *)&local.local,(char *)&local.difference,0);
    func_00282F70(&local.velocity,&local.local,D_L16_001AF43C);
    func_00283098(&local.velocity,&local.velocity,object+0xc0);
    alignment=func_00282DB0(&local.previous,D_00189FB0);
    if (*(float *)(D_00189E20+0x24b8)>0.5f && alignment>0.5f)
        func_002AA2E8((float *)(state+0x30),alignment*0.0833333358f,0.00138888892f);
    else func_002AA2E8((float *)(state+0x30),0.0f,0.00138888892f);
    if (*(float *)(state+0x30)!=0.0f) {
        func_00282F20(&local.lateral,D_00189FB0,*(float *)(state+0x30));
        func_00282CC0(&local.velocity,&local.velocity,&local.lateral);
        *(float *)(state+0x34)+=*(float *)(state+0x30)/(*(float *)(state+8)*6.28318548f);
        if (*(float *)(state+0x34)>1.0f) *(float *)(state+0x34)=1.0f;
    }
    func_00282CC0(&local.velocity,&local.velocity,object+0x10);
    func_00282A88(D_00189E20+0xf0,0xa0);
    func_00282CF0(D_00189E20+0xf0,&local.velocity,D_00189E20+0x80);
    func_002AC9F8((float *)(D_00189E20+0xf0),0.100000009f);
}
