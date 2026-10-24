/* 2026-10-23 C reconstruction. Measured with -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-
   barrier. us: 0/2 placements, 16_snivelak: 1528 bytes, expected 1544; us2: 0/2 placements,
   16_snivelak: 1528 bytes, expected 1544; pal: canonical name absent. Box initialization, interaction,
   bounce and state transitions reconstructed. Current AFDD8 pointer types and float absolute-value
   inputs are explicit. The0x80 frame agrees; control-flow merging and scheduling remain16bytes short.
   Reopen when: An exact state-machine branch-layout witness. Historical screening follows unchanged.
 */

/* func_L16_00395250 - 1544 bytes, 2 place(s), level 16_snivelak, retail at
   0x00395250. Screened with tools/w10_screen.py: 37 call(s)
   [func_002AFFD8@003952E8, func_L00_00325600@00395304,
   func_L00_00325600@00395314, func_002AB6D8@0039532C,
   func_002A7750@0039537C, func_00282F20@00395398, func_00282CC0@003953AC,
   func_00282948@003953B4, func_00282E48@003953CC, func_00288E18@00395448,
   func_L00_0032EF10@00395480, func_L16_003960F8@003954B4,
   func_002AFDD8@003954F0, func_00282CF0@00395504, func_002AFDD8@00395518,
   func_00282F20@00395534, func_00282F20@00395544, func_00282DB0@00395550,
   func_L16_002C0BC8@00395568, func_L16_00395D30@00395570,
   func_002A7750@00395580, func_00282C48@003955D4,
   func_L00_0032EF10@00395628, func_L16_002C0BC8@0039568C,
   func_003355A8@00395694, func_00288E18@003956C8, func_002A7750@00395720,
   func_00282F20@00395734, func_00282CC0@00395744,
   func_L16_00395858@0039574C, func_L16_003959B8@00395754,
   func_L16_00395C00@0039575C, func_L16_00395ED0@00395764,
   func_002B3868@00395774, func_00282C48@003957BC, func_00282F20@00395814,
   func_00282CC0@00395824]; data addresses materialised [0x1b0000, 0x1b0000,
   0x190000, 0x190000, 0x190000, 0x280000, 0x190000, 0x190000, 0x3e4c0000,
   0x3b360000, 0x3ada0000, 0xbeaa0000, 0x190000, 0x190000, 0x3b360000,
   0x3ada0000, 0xbeaa0000]; float constants [0x3f800000, 0x3fe00000,
   0x3f800000, 0x3f800000, 0x3f800000]; $gp-relative small data: no   saves:
   -; callee-saved registers saved [-]; words plain C cannot emit [LQ/SQ
   7A220000@0x00d0, LQ/SQ 7C620000@0x00d4]. Head: addiu $sp, $sp, -0x80 ;
   addiu $v0, $zero, 0x1 ; sd $s3, 0x48($sp) ; sd $s0, 0x30($sp) ; daddu
   $s3, $a0, $zero ; sd $s1, 0x38($sp). Not matched in this wave: the
   128-bit copy needs an `lq`/`sq` pair; plain C reaches it only through a
   `mode(TI)` local, and this cc1 folds the destination offset into the `sq`
   where retail materialises the pointer first. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
#define F(p,o) (*(float *)((u8 *)(p)+(o)))
#define I(p,o) (*(int *)((u8 *)(p)+(o)))
extern char D_00189E20[];
extern u8 D_0018B05A NOT_SDA,D_0018C0D4 NOT_SDA;
extern s16 D_0018CAC0 NOT_SDA;
extern int D_0018B068 NOT_SDA,D_0018B040 NOT_SDA,D_00189FD8 NOT_SDA,D_0018C0B4 NOT_SDA;
extern float D_0018A13C NOT_SDA;
extern int D_001A79F0 __attribute__((sda));
extern int D_L16_0027F078 NOT_SDA,D_L16_0027F09C NOT_SDA,D_L16_001A8FF0 NOT_SDA;
extern u8 *D_L16_001B2B1C NOT_SDA;
extern float D_L16_001AF430 __attribute__((sda));
extern float D_L16_001AF434 __attribute__((sda));
extern float D_L16_001AF438 __attribute__((sda));
extern void func_002AFFD8(char *,char *,int);
extern void func_L00_00325600(void *,void *,void *);
extern void func_002AB6D8(float *,float *);
extern void func_002A7750(u8 *,u8,s32);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern int func_00282948(int *);
extern float func_00282E48(void *,void *);
extern int func_00288E18(int,int);
extern int func_L00_0032EF10(int,int,int);
extern int func_L16_003960F8(char *);
extern void func_002AFDD8(char *,char *,char *,char *);
extern void func_00282CF0(void *,void *,void *);
extern float func_00282DB0(void *,void *);
extern void func_L16_002C0BC8(int,int);
extern void func_L16_00395D30(char *);
extern float func_00282C48(float);
extern void func_003355A8(int);
extern void func_L16_00395858(char *);
extern void func_L16_003959B8(char *);
extern void func_L16_00395C00(char *);
extern void func_L16_00395ED0(char *);
extern s32 func_002B3868(u8 *);
void func_L16_00395250(u8 *object)
{
    float position[4],direction[4],forward[4];
    u8 *state=*(u8 **)(object+0x68);
    u8 *target;
    float value,velocity;
    u8 mode;
    switch (object[0x20]) {
    case 0:
        if (!D_L16_001A8FF0) return;
        F(object,0x2C)=F(*(u8 **)(object+0x24),0x24);
        func_002AFFD8((char *)object+0x10,(char *)position,0);
        *(u16 *)(object+0x34)|=0x100;
        func_L00_00325600(object+0xC0,position,0);
        func_L00_00325600(object+0xC0,position,0);
        *(Quad *)(state+0x10)=*(Quad *)(object+0x10);
        func_002AB6D8((float *)(object+0xC0),(float *)(state+0x20));
        target=D_L16_001B2B1C+(I(state,4)<<8);
        I(state,0x58)=0;
        if (!target || target[0x20]==254 || target[0x20]==253) { F(state,0x34)=1.0f; mode=4; }
        else { F(state,0x34)=0.0f; mode=1; }
        break;
    case 1:
        func_00282F20(position,object+0xE0,D_L16_001AF430);
        func_00282CC0(object+0x10,position,state+0x10);
        if (func_00282948((int *)(state+0x3C)) && func_00282E48(object+0x10,D_00189E20+0x80)<1.75f) {
            if (D_0018B05A || D_0018C0D4) goto decay;
            if (D_0018CAC0!=-1 && D_L16_0027F078==0 && D_L16_0027F09C==-1) {
                func_00288E18(0x9C7,30);
                D_0018CAC0=-1;
            }
            if (D_0018B068!=10) goto decay;
            if (D_0018B040) {
                if (!func_L00_0032EF10(0x80,7,0) || D_0018A13C>=0.2f || !func_L16_003960F8((char *)object)) goto decay;
                if (F(state,0x34)<1.0f) {
                    func_002AFDD8((char *)object,(char *)forward,D_00189E20,0);
                    func_00282CF0(direction,D_00189E20+0x80,object+0x10);
                    func_002AFDD8((char *)object,(char *)direction,(char *)direction,0);
                    direction[2]=0.0f;
                    forward[2]=0.0f;
                    func_00282F20(direction,direction,1.0f);
                    func_00282F20(forward,forward,1.0f);
                    if (func_00282DB0(direction,forward)<0.2f) { func_L16_002C0BC8(0x37,1); func_L16_00395D30((char *)object); }
                    func_002A7750(object,2,-1);
                }
            }
        }
        goto decay;
    case 2:
        if ((!func_L00_0032EF10(0x80,7,0) || D_00189FD8<21) && F(state,0x34)<1.0f && D_0018C0B4==0x37) {
            func_00282F20(position,object+0xE0,D_L16_001AF434);
            func_00282CC0(object+0x10,position,state+0x10);
            func_L16_00395858((char *)object);
            func_L16_003959B8((char *)object);
            func_L16_00395C00((char *)object);
            func_L16_00395ED0((char *)object);
            return;
        }
        if (D_0018C0B4==0x37) func_L16_002C0BC8(0,1);
        func_003355A8(1);
        I(state,0x3C)=20;
        I(state,0x58)++;
        if (I(state,0x58)==3 || I(state,0x58)==6) func_00288E18(0x9C7,30);
        if (F(state,0x34)>=1.0f) {
            if (D_001A79F0==26) D_0018CAC0=-1;
            F(state,0x34)=1.0f;
            mode=4;
        } else mode=1;
        break;
    case 4:
        if (func_002B3868(object)) F(state,0x44)=D_L16_001AF430;
        velocity=F(state,0x48)-0.0027777778f;
        F(state,0x48)=velocity;
        value=F(state,0x44)+velocity;
        F(state,0x44)=value;
        if (value<=D_L16_001AF438) {
            F(state,0x44)=D_L16_001AF438;
            if (func_00282C48(F(state,0x48))>0.0016666668f) F(state,0x48)*=-0.333f;
            else *(u16 *)(object+0x34)|=2;
        }
        func_00282F20(position,object+0xE0,F(state,0x44));
        func_00282CC0(object+0x10,position,state+0x10);
        return;
    default:
        return;
    }
    func_002A7750(object,mode,-1);
    return;
decay:
    if (F(state,0x34)==0.0f) return;
    velocity=F(state,0x40)-0.0027777778f;
    F(state,0x40)=velocity;
    value=F(state,0x34)+velocity;
    F(state,0x34)=value;
    if (value>0.0f) return;
    F(state,0x34)=0.0f;
    if (func_00282C48(F(state,0x40))<=0.0016666668f) F(state,0x40)=0.0f;
    else { value=F(state,0x40)*-0.333f; F(state,0x34)=value; F(state,0x40)=value; }
}
