/* Complete retained reconstruction; not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Tested as src/levels/shared/L16_00395250.c.
 * us: 0/2 placements, exit 1.
 * us2: 0/2 placements, exit 1.
 * pal: explicit catalogue absence, no credit.
 * USA compiled 1528 / retail 1544 bytes.
 * Residual: Retained1528 versus1544 bytes. State-machine control-flow joins and scalar scheduling remain short; qcopy_nc tied and mnosplit produced1556 bytes.
 * Reopen with: An independently evidenced state-machine branch-layout or parameter-lifetime model; do not repeat the recorded helper/nc/address-profile forms without changed input.
 */

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
extern void func_002A7750(u8 *,s32,s32);
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
        qcopy(state+0x10,object+0x10);
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
