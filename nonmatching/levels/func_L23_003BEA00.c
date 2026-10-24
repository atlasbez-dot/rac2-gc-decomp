/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-zero-ti-por.
 * Prior worker coverage: US 0/1; US2 absent from catalogue; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Nonmatching manual reconstruction.
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-zero-ti-por
   4040 bytes, expected 4016; frame 0xB0 agrees, US fails.
   Nine bounded semantic/profile trials included local initialization, ordered FP,
   physical switch order and float/TI/union vector copies; closest source retained.
   Cases 12 and 13 both exit, verified in the 13-entry retail table at 0x2AB130.
   func_002A90C8 receives four GPR arguments and a live damage float in f12;
   the current wrapper declaration omits that forwarded float. Its repair belongs
   to integration, and the measured caller argument is preserved here.
   func_002A8C28 and func_0032C700 have inferred ignored-result contracts;
   six GPR plus three FP, and twelve GPR plus two FP inputs respectively.
   Reopen with a new stack-vector scheduling or shared-switch-tail hypothesis.
*/
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct Moby_003BF9B0 Moby_003BF9B0;
typedef struct {
    u8 reserved_00[0x18]; u8 enabled,count,kind;
    u8 reserved_1b[0x65]; u8 payload[1];
} Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext;
#define F(p,o) (*(float *)((char *)(p)+(o)))
#define I(p,o) (*(int *)((char *)(p)+(o)))
#define S(p,o) (*(short *)((char *)(p)+(o)))
#define U(p,o) (*(unsigned short *)((char *)(p)+(o)))
#define P(p,o) (*(char **)((char *)(p)+(o)))
extern int D_L23_001B1424,D_L23_001B36F0;
extern u8 *D_L23_001B36B0,*D_0018C0B0;
extern float D_L23_001B36A4,D_L23_001B36F4,D_L23_001B36F8;
extern float D_L23_001B36D0[4],D_00189EA0[4],D_L23_001C0AA0[4];
extern u8 D_00189F00[];
extern int D_L23_001B3708;
extern float D_L23_001AFA14 __attribute__((sda));
extern int D_L23_001AFA38 __attribute__((sda));
extern float D_L23_001AFA4C __attribute__((sda));
extern float D_L23_001AFA58 __attribute__((sda));
extern float D_L23_001AFA5C __attribute__((sda));
extern float D_L23_001AFA60 __attribute__((sda));
extern float D_L23_001AFA6C __attribute__((sda));
extern float D_L23_001AFA78 __attribute__((sda));
extern float D_L23_001AFA80 __attribute__((sda));
extern float D_L23_001AFA88 __attribute__((sda));
extern float D_L23_001AFA8C __attribute__((sda));
extern float D_L23_001AFA90 __attribute__((sda));
extern int D_L23_001AFA94 __attribute__((sda));
extern int D_L23_001AFA98 __attribute__((sda));
extern int D_L23_001AFA9C __attribute__((sda));
extern void func_L23_003BF9B0(Moby_003BF9B0 *);
extern int func_L23_0041E548(void),func_L23_0041E418(void);
extern int func_002A90C8(int,int,int,int,float);
extern int func_002A8F70(int,int,int,int,int,float);
extern int func_002A8C28(void *,void *,int,int,int,int,float,float,float);
extern int func_0032C700(void *,int,int,int,int,int,int,int,int,int,int,int,float,float);
extern void func_L23_003C1960(char *),func_L23_003C1988(char *);
extern void func_L23_003C0028(char *),func_L23_003C00D0(char *);
extern void func_L23_003C1B58(char *),func_L23_003C1AE8(char *);
extern void func_L23_003C16D8(char *),func_L23_003BFE38(char *);
extern void func_L23_003C1E88(void *);
extern void func_L23_003C01F8(char *,int);
extern void func_L23_003C02C8(u8 *);
extern float func_002B0360(char *);
extern void func_00282CF0(void *,void *,void *);
extern float func_L02_00329C48(char *,Quad *,char *);
extern float func_00282E48(void *,void *),func_00282DF0(void *);
extern int func_L23_003C0A60(void *,void *,void *);
extern void func_L23_00418650(char *,float);
extern unsigned long func_002B1C20(void *,Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *);
extern void func_002E59F8(int);
extern void func_00283098(void *,void *,void *);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282F20(void *,void *,float),func_00282D30(void *,void *,float);
extern int func_002E5DA0(int,int,char *,int);
extern void func_L22_003A3C70(int,int);
extern int func_002B3868(u8 *),func_002B3890(u8 *);
extern int func_L00_0035F5A0(int,int,int);
extern void func_L23_003BFFC0(char *,int,int,int,int,float);
extern void func_L23_003BFE90(char *,float,int,int);
extern void func_002A7750(u8 *,u8,int);
extern void func_L00_002E6CF0(void (*)(void *),void *);
extern void func_L11_003404E0(char *);
extern int func_002761F8(void *,void *,int,void *,void *);
extern float func_0029F530(char *),func_002A7878(float,float);
extern int func_002AEB60(char *,float);
extern void *func_L23_004256F0(u8 *,u8 *,u8 *,u8,u8,short,short,int,float,float,float,float,int,int,int,int);
extern void func_0029FCC0(char *,int,char *);
extern int func_L00_002D6900(unsigned int);

void func_L23_003BEA00(u8 *object)
{
    float difference[4],point[4],local[4];
    char *state=*(char **)(object+0x68);
    int facing,selected,index,mask;
    unsigned long flags;
    float distance,range;
    func_L23_003BF9B0((Moby_003BF9B0 *)object);
    if (D_L23_001B1424>200) return;
    if (func_L23_0041E548())
        func_002A90C8((int)object,(int)object,0x10000,(int)(object+0x10),(float)D_L23_001B36F0);
    selected=D_L23_001B36B0==object;
    facing=0;
    S(state,0x326)=0;
    if (selected && (unsigned int)(object[0x20]-9)>2)
        func_L23_003C1960((char *)object);
    if (object[0x20]!=13) {
        F(state,0x270)=func_002B0360((char *)object+0x10);
        func_00282CF0(difference,D_00189EA0,object+0x10);
        if (func_L02_00329C48((char *)object,(Quad *)difference,0)<=0.7853982f) facing=1;
        distance=func_00282E48(D_00189EA0,object+0x10);
        range=D_L23_001AFA6C;
        F(state,0x27C)=distance;
        S(state,0x324)=0;
        if (distance<range)
            S(state,0x324)=func_L23_003C0A60(object,object+0x10,D_00189EA0);
        *(Quad *)(state+0x300)=*(Quad *)(object+0x10);
        func_L23_00418650(state+0x300,0.0f);
    }
    if (object[0x95]==3) {
        flags=func_002B1C20(object,(Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *)(state+0x140));
        if (I(state,0x3B4)!=-1) {
            func_002E59F8(I(state,0x3B4)); I(state,0x3B4)=-1;
        }
        if (object[0x43]==8 && func_00282DF0(state+0x1C0)>0.0f) {
            if (F(state,0x270)<D_L23_001B36A4) func_L23_00418650((char *)object+0x10,0.0f);
            *(Quad *)local=0; local[2]=F(state,0x174);
            *(Quad *)point=*(Quad *)local;
            func_00283098(point,point,object+0xC0);
            func_00282CC0(point,point,object+0x10);
            func_00282F20(difference,state+0x1C0,4.0f);
            func_00282CC0(point,point,difference);
            func_002A8C28(object,point,0x90000,0,1,0,5.0f,100.0f,0.0f);
        }
        if ((U(state,0x178)&1) && S(state,0x2A4)==0) {
            func_002E5DA0(5,0,(char *)object,0x7E5);
            func_0032C700(P(state,0x2A0)+0x10,1,35,20,20,20,45,1,1,0,0,0,2.5f,20.0f);
            S(state,0x2A4)=1;
            if (P(state,0x38)==(char *)D_0018C0B0) {
                *(Quad *)difference=*(Quad *)(object+0x10);
                func_L23_00418650((char *)difference,0.0f);
                index=func_L23_0041E418();
                if (index!=-1) func_L22_003A3C70((int)D_00189EA0,index);
            }
            *(Quad *)(object+0x10)=*(Quad *)D_00189EA0;
            func_L23_00418650((char *)object+0x10,-D_L23_001B36A4+-D_L23_001B36A4);
        }
        if (flags&1) func_L23_003C0028((char *)object);
        else if (func_002B3868(object) && object[0x43]==8) {
            func_L00_0035F5A0(31,0,0);
            func_L23_003BFFC0((char *)object,8,0,4,2,1.0f);
            S(state,0x26)=25; S(state,0x2A6)=0;
            func_0032C700(P(state,0x2A0)+0x10,0,10,15,15,15,15,0,0,0,0,0,1.0f,20.0f);
        } else if (flags&2) func_002A7750(object,5,0);
    }
    switch (object[0x20]) {
    case 5:
        if (func_002B3890(object)) {
            func_L23_003BFFC0((char *)object,3,0,4,3,1.0f);
            if (I(state,0x3B4)!=-1) { func_002E59F8(I(state,0x3B4)); I(state,0x3B4)=-1; }
        }
        if (U(object,0x96)>8) func_002A7750(object,7,1);
        else if (U(object,0x96)>=11) {
            mask=object[0x43]!=3;
            if (((u8 *)P(state,0x2A0))[0x43]!=3) mask|=2;
            if (mask) func_L23_003BFFC0((char *)object,3,0,20,mask,1.0f);
            func_L11_003404E0((char *)object);
        }
        break;
    case 1:
        if (func_002B3890(object)) func_L23_003C00D0((char *)object);
        else if (U(object,0x96)>=6) func_002A7750(object,3,0);
        break;
    case 2:
        I(object,0x98)=0;
        if (func_002B3890(object)) {
            func_L23_003C00D0((char *)object);
            func_L23_003BFFC0((char *)object,9,0,0,1,1.0f);
            func_L23_003BFFC0((char *)object,1,0,0,2,1.0f);
            func_L23_003C01F8((char *)object,1);
            S(state,0x3BC)=1; F(state,0x3B8)=(float)D_L23_001AFA38;
        }
        func_L00_002E6CF0(func_L23_003C1E88,object);
        break;
    case 6:
        func_L23_003C1B58((char *)object); break;
    case 3:
        if (func_002B3890(object) && object[0x43]!=1)
            func_L23_003BFFC0((char *)object,1,0,4,3,1.0f);
        func_L11_003404E0((char *)object);
        if (S(state,0x110)) {
            func_002A7750(object,5,0);
            func_L23_003BFFC0((char *)object,3,0,10,3,1.0f);
        } else {
            func_00282D30(point,object+0xE0,-3.0f);
            func_00282CC0(point,point,object+0x10);
            func_00282D30(difference,object+0xE0,0.2f);
            func_00282CC0(difference,difference,object+0x10);
            if (func_002761F8(difference,point,18,0,0) && !(4.0f<=func_00282E48(D_L23_001C0AA0,object+0x10)))
                func_002A7750(object,4,0);
        }
        break;
    case 4:
        if (func_002B3890(object) && object[0x43]!=2)
            func_L23_003BFFC0((char *)object,2,0,6,3,1.0f);
        else if ((object[0x60]&2) || func_0029F530((char *)object)>12.0f) {
            func_002A7750(object,5,0);
            func_L23_003BFFC0((char *)object,3,0,20,3,1.0f);
        }
        func_L11_003404E0((char *)object);
        break;
    case 7:
        if (func_002B3890(object)) {
            I(state,0x250)=200;
            F(state,0x2A8)=D_L23_001AFA58+func_002A7878(0.0f,D_L23_001AFA58*0.5f);
            P(state,0x320)=(char *)D_00189EA0;
        }
        if (!object[0x31]) F(state,0x2A8)=D_L23_001AFA60;
        else if (F(state,0x2A8)==D_L23_001AFA60)
            F(state,0x2A8)=D_L23_001AFA58+func_002A7878(0.0f,D_L23_001AFA58*0.5f);
        if (I(state,0x250)==0) func_002A7750(object,5,0);
        else if (S(state,0x324) && facing && F(state,0x27C)<D_L23_001AFA78)
            func_002A7750(object,8,2);
        else func_L23_003C02C8(object);
        break;
    case 8:
        if (func_002B3868(object)) F(state,0x2A8)=D_L23_001AFA58+func_002A7878(0.0f,D_L23_001AFA58*0.5f);
        if (((u8 *)P(state,0x2A0))[0x43]!=4) {
            func_L23_003BFFC0((char *)object,4,0,10,2,1.0f);
            I(P(state,0x2A0),0x48)=D_L23_001B3708;
        }
        if (!S(state,0x324) || F(state,0x27C)>D_L23_001AFA80) {
            func_002A7750(object,5,0); I(state,0x250)=0;
        } else if (F(state,0x27C)>D_L23_001AFA88 ||
                   ((unsigned int)(object[0x43]-5)<2 && F(state,0x27C)>D_L23_001AFA88-2.0f)) {
            P(state,0x320)=(char *)D_00189EA0; func_L23_003C02C8(object);
        } else {
            func_L23_003BFFC0((char *)object,3,0,10,1,1.0f); func_L11_003404E0((char *)object);
        }
        if (func_002AEB60(P(state,0x2A0),28.0f)) func_L23_003BFE90((char *)object,D_L23_001B36F4+D_L23_001B36F4,(int)D_00189F00,0);
        else if (func_002AEB60(P(state,0x2A0),14.0f)) func_L23_003BFE90((char *)object,D_L23_001B36F4+D_L23_001B36F4,(int)D_00189F00,1);
        break;
    case 9:
        if (func_002B3868(object)) {
            func_L23_003BFFC0((char *)object,6,0,12,1,D_L23_001AFA14);
            func_L23_003BFFC0((char *)object,8,0,12,2,4.0f);
            func_L23_003C1988((char *)object);
            P(state,0x328)=func_L23_004256F0((u8 *)state+0x330,object,(u8 *)state+0x340,50,70,30,5,0x7F7F7F,0.7f,0.85f,0.5f,1.2f,0x7F7F7F,0,-1,0);
            P(state,0x32C)=func_L23_004256F0((u8 *)state+0x330,object,(u8 *)state+0x340,50,70,10,2,0x3F00000,1.9f,2.05f,0.5f,1.2f,0x3F0000,0,-1,0);
            F(state,0x2A8)=D_L23_001AFA5C;
            I(state,0x3B4)=func_002E5DA0(4,4,(char *)object,0x7E5);
        }
        if (!S(state,0x324) || F(state,0x27C)>D_L23_001AFA80) {
            func_002A7750(object,5,0); I(state,0x250)=0; break;
        }
        func_0029FCC0(P(state,0x2A0),1,state+0x330);
        func_0029FCC0(P(state,0x2A0),0,state+0x340);
        if ((int)U(object,0x96)>D_L23_001AFA94) {
            P(state,0x320)=(char *)D_00189EA0;
            if (F(state,0x27C)<D_L23_001AFA8C) func_002A7750(object,10,2);
            func_L23_003C02C8(object);
        }
        break;
    case 10:
        if (!S(state,0x324) || F(state,0x27C)>D_L23_001AFA90) { func_002A7750(object,5,0); break; }
        func_0029FCC0(P(state,0x2A0),1,state+0x330);
        func_0029FCC0(P(state,0x2A0),0,state+0x340);
        if (func_002B3868(object)) {
            func_L23_003C1988((char *)object);
            P(state,0x328)=func_L23_004256F0((u8 *)state+0x330,object,(u8 *)D_L23_001B36D0,95,80,35,5,0x5F0000,4.0f,4.25f,0.7f,1.3f,0x5F2020,0,-1,0);
            P(state,0x32C)=func_L23_004256F0((u8 *)state+0x340,object,(u8 *)D_L23_001B36D0,95,80,35,5,0x5F0000,4.0f,4.25f,0.7f,1.3f,0x5F2020,0,-1,0);
            break;
        }
        if ((int)U(object,0x96)<=D_L23_001AFA98) break;
        func_00282CC0(difference,state+0x330,state+0x340);
        func_00282D30(difference,difference,0.5f);
        if (func_00282E48(difference,D_L23_001B36D0)<D_L23_001AFA4C) {
            func_00282F20(point,P(state,0x2A0)+0xE0,0.25f);
            func_00282CC0(point,point,P(state,0x2A0)+0xC0);
            func_00282D30(point,point,15.0f); point[3]=5627.9248f;
            func_002A8F70((int)D_0018C0B0,(int)object,0x10007,(int)(object+0x10),(int)point,D_L23_001B36F8);
            func_L00_002D6900(43);
            func_0032C700(D_L23_001B36D0,1,10,10,10,10,45,0,0,1,0,0,1.2f,20.0f);
            S(state,0x3BE)=1;
        }
        func_002A7750(object,11,2);
        break;
    case 11:
        if (func_002B3868(object)) {
            if (I(state,0x3B4)!=-1) { func_002E59F8(I(state,0x3B4)); I(state,0x3B4)=-1; }
        } else if ((int)U(object,0x96)<=D_L23_001AFA9C) {
            if ((int)U(object,0x96)>=D_L23_001AFA9C-5 && S(state,0x3BE)) {
                func_L00_0035F5A0(29,0,0); S(state,0x3BE)=0; func_L00_002D6900(43);
            }
        } else { func_L23_003C1960((char *)object); func_002A7750(object,5,0); }
        break;
    case 12:
    case 13:
        break;
    }
    func_L23_003BFE38((char *)object);
    if (object[0x20]!=13) { func_L23_003C16D8((char *)object); func_L23_003C1AE8((char *)object); }
}
