/* 2026-10-23 C reconstruction. Measured with -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-
   barrier. us: 0/2 placements, 16_snivelak: 1428 bytes, expected 1456; us2: 0/2 placements,
   16_snivelak: 1428 bytes, expected 1456; pal: canonical name absent. Player movement projection and
   clamping reconstructed. Forwarded live FP thresholds to func_L00_002D3BD8 are explicit, and its
   current int source-pointer interface is preserved. The0x80 frame agrees; global-address
   materialization, float expressions and division padding remain28bytes short. Reopen when: A matching
   resident-state motion witness and measured division-label remedy. Historical screening follows
   unchanged.
 */

/* func_L16_002B5EE0 - 1456 bytes, 2 place(s), level 16_snivelak, retail at
   0x002b5ee0. Screened with tools/w10_screen.py: 47 call(s)
   [func_L00_002D4140@002B5F2C, func_L00_002D3A58@002B5F74,
   func_L00_002D3BD8@002B5FA4, func_L00_002D3B00@002B5FB4,
   func_L00_002D3B58@002B5FFC, func_00282E20@002B6028,
   func_00282F70@002B605C, func_00282DF0@002B6090, func_00282F20@002B60C4,
   func_00282CC0@002B60DC, func_00282CC0@002B60EC, func_00282C88@002B60F4,
   func_00282DF0@002B6108, func_L00_002B5A88@002B6130,
   func_L09_002B7238@002B6138, func_00282CF0@002B6148,
   func_L00_002B5250@002B6150, func_L09_002B7238@002B6160,
   func_00282CF0@002B6180, func_00282F20@002B61B4, func_00282DB0@002B61C0,
   func_00282F20@002B61E0, func_L00_002D3960@002B61F8,
   func_L00_002D3960@002B6204, func_00282F20@002B6214,
   func_00282DB0@002B6220, func_00282F20@002B6240,
   func_L00_002D3BD8@002B625C, func_L00_002D3BD8@002B626C,
   func_00282F20@002B627C, func_00282DB0@002B6288, func_00282F20@002B62AC,
   func_00282DF0@002B62B4, func_L00_002D3A58@002B62C0,
   func_L00_002B5590@002B62D4, func_L00_002D3B00@002B62E0,
   func_00282DF0@002B6310, func_00282CC0@002B633C, func_00282C88@002B6348,
   func_L00_002B5A88@002B6350, func_L09_002B7238@002B6358,
   func_00282CF0@002B6368, func_L00_002B5250@002B6370,
   func_00282CF0@002B6384, func_00282DF0@002B638C, func_00282CF0@002B63AC,
   func_00282D30@002B6454]; data addresses materialised [0x190000, 0x190000,
   0x3ca30000, 0x190000, 0x3ca30000, 0x190000, 0x3ca30000, 0x190000,
   0x3ca30000, 0x38d10000, 0x190000, 0x190000, 0x38d10000, 0x3b830000,
   0x3f5d0000]; float constants [0x3f800000, 0x3f000000, 0xbf000000]; $gp-
   relative small data: no   saves: -; callee-saved registers saved [-];
   words plain C cannot emit [LQ/SQ 7A420000@0x0034, LQ/SQ 7FA20000@0x0038,
   LQ/SQ 7A020000@0x02a8, LQ/SQ 7E220000@0x02ac, LQ/SQ 7A020000@0x02b4,
   LQ/SQ 7E420000@0x02b8, LQ/SQ 7A820000@0x030c, LQ/SQ 7E620000@0x0310,
   LQ/SQ 7A820000@0x036c, LQ/SQ 7E220000@0x0370, LQ/SQ 7A020000@0x03e8,
   LQ/SQ 7FA20010@0x03f8, LQ/SQ 7AA20000@0x0420, LQ/SQ 7E620000@0x0424].
   Head: addiu $sp, $sp, -0x80 ; lui $v1, 0x19 ; sd $s2, 0x40($sp) ; sd $s0,
   0x30($sp) ; addiu $s2, $v1, -0x6160 ; sd $s1, 0x38($sp). Not matched in
   this wave: the 128-bit copy needs an `lq`/`sq` pair; plain C reaches it
   only through a `mode(TI)` local, and this cc1 folds the destination
   offset into the `sq` where retail materialises the pointer first. What
   would unblock it: the exact source expression tree, so this cc1 picks the
   same registers in the same order. */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
#define F(offset) (*(float *)(D_00189E20+(offset)))
#define I(offset) (*(int *)(D_00189E20+(offset)))
#define V(offset) (D_00189E20+(offset))
extern char D_00189E20[];
extern void func_L00_002D4140(int,void *,void *);
extern float func_L00_002D3A58(char *);
extern float func_L00_002D3B00(char *);
extern void func_L00_002D3BD8(char *,int,float);
extern void func_L00_002D3B58(Quad *,Quad *,float);
extern float func_00282E20(void *);
extern void func_00282F70(void *,void *,float);
extern float func_00282DF0(void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282C88(Quad *);
extern float func_00282DB0(void *,void *);
extern void func_00282D30(void *,void *,float);
extern void func_L00_002B5A88(void);
extern void func_L09_002B7238(void);
extern void func_L00_002B5250(void);
extern void func_L00_002D3960(char *,char *);
extern float func_L00_002B5590(void *);
void func_L16_002B5EE0(void)
{
    float oldPosition[4],horizontal[4],vertical[4];
    float value,limit,saved;
    *(Quad *)oldPosition=*(Quad *)V(0x80);
    func_L00_002D4140(I(0x588),V(0x100),V(0x90));
    if (I(0x2294)==0x14 || I(0x2294)==0x5B || I(0x2294)==0x58 || I(0x2294)==0x81) {
        if (*(s16 *)V(0x1F0)==0 && func_L00_002D3A58(V(0xF0))>F(0x264)-0.02f)
            func_L00_002D3BD8(V(0xF0),(int)V(0xF0),F(0x264)-0.02f);
        if (func_L00_002D3B00(V(0xF0)) < -F(0x31C)) {
            limit=-F(0x31C)-0.02f;
            if (limit>0.0f) limit=0.0f;
            func_L00_002D3B58((Quad *)V(0xF0),(Quad *)V(0xF0),limit);
        }
    } else if (I(0x229C)==15) {
        if (*(s16 *)V(0x1F0)==0 && func_00282E20(V(0xF0))>F(0x264)-0.02f)
            func_00282F70(V(0xF0),V(0xF0),F(0x264)-0.02f);
    } else if (I(0x229C)!=13 && I(0x229C)!=14 && *(s16 *)V(0x1F0)==0 && func_00282DF0(V(0xF0))>F(0x264)-0.02f) {
        func_00282F20(V(0xF0),V(0xF0),F(0x264)-0.02f);
    }
    func_00282CC0(V(0x80),V(0x80),V(0xF0));
    func_00282CC0(V(0x80),V(0x80),V(0xA60));
    func_00282C88((Quad *)V(0xA60));
    I(0x26C)=0;
    *(u8 *)V(0x287)=0;
    if (func_00282DF0(V(0x100))<=0.0001f) {
        func_L00_002B5A88();
        func_L09_002B7238();
        func_00282CF0(V(0x110),V(0x80),oldPosition);
        func_L00_002B5250();
    } else func_L09_002B7238();
    func_00282CF0(V(0x120),V(0x80),oldPosition);
    *(Quad *)V(0x130)=*(Quad *)V(0x120);
    *(Quad *)V(0x140)=*(Quad *)V(0x120);
    func_00282F20(V(0x120),V(0x120),1.0f);
    value=func_00282DB0(V(0x120),V(0xF0));
    if (value<0.0f) value=0.0f;
    func_00282F20(V(0x120),V(0xF0),value);
    *(Quad *)horizontal=*(Quad *)V(0xF0);
    func_L00_002D3960((char *)horizontal,(char *)horizontal);
    func_L00_002D3960(V(0x140),V(0x140));
    func_00282F20(V(0x140),V(0x140),1.0f);
    value=func_00282DB0(V(0x140),horizontal);
    if (value<0.0f) value=0.0f;
    func_00282F20(V(0x140),horizontal,value);
    *(Quad *)vertical=*(Quad *)V(0xF0);
    func_L00_002D3BD8((char *)vertical,(int)vertical,0.0f);
    func_L00_002D3BD8(V(0x130),(int)V(0x130),0.0f);
    func_00282F20(V(0x130),V(0x130),1.0f);
    value=func_00282DB0(V(0x130),vertical);
    if (value<0.0f) value=0.0f;
    func_00282F20(V(0x130),vertical,value);
    F(0x170)=func_00282DF0(V(0x120));
    F(0x174)=func_L00_002D3A58(V(0x120));
    *(Quad *)horizontal=*(Quad *)V(0x120);
    F(0x178)=func_L00_002B5590(horizontal);
    F(0x180)=func_L00_002D3B00(V(0x120));
    value=0.0f;
    if (F(0x178)>=0.0f) value=F(0x178);
    F(0x178)=value;
    *(Quad *)horizontal=*(Quad *)V(0x80);
    if (func_00282DF0(V(0x100))>0.0001f) {
        func_00282CC0(V(0x80),V(0x80),V(0x100));
        saved=F(0x10C);
        func_00282C88((Quad *)V(0x100));
        F(0x10C)=saved;
        func_L00_002B5A88();
        func_L09_002B7238();
        func_00282CF0(V(0x110),V(0x80),oldPosition);
        func_L00_002B5250();
    }
    func_00282CF0(V(0x150),V(0x80),horizontal);
    F(0x184)=func_00282DF0(V(0x150));
    F(0x15C)=F(0x10C);
    F(0x10C)=0.0f;
    func_00282CF0(V(0x110),V(0x80),oldPosition);
    F(0x17C)=0.0f;
    if (F(0x174)>0.004f) {
        F(0x17C)=F(0x118)/F(0x174);
        if (F(0x17C)>0.5f) F(0x17C)=0.5f;
        else if (F(0x17C)<-0.5f) F(0x17C)=-0.5f;
    }
    if (F(0x170)>0.86666673f) {
        func_00282D30(V(0x110),V(0x110),0.86666673f/F(0x170));
        F(0x170)=0.86666673f;
    }
}
