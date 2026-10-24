/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections.
 * Reported final C / retail: 2196 / 2576 bytes; size equality is not a match.
 * us: 0/1 placements; 2196/2576 bytes.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: Three source/profile trials; final 2196 versus 2576 bytes, frame0x40 versus 0x30. All ten merchant states, genuine variadic message calls and both payout branches are reconstructed. Branch sharing and mixed absolute/GP data accesses remain different. -mno-split-addresses triggered GNU as tc-mips.c:11867 rather than producing an object.
 * Reopening condition: Recover the original price selection and branch-sharing structure; qualify mixed absolute/GP access and investigate the assembler assertion before reusing that profile.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not matched, 2026-10-23.
 * Three source/profile trials; final 2196 versus 2576 bytes, frame0x40 versus 0x30. All ten merchant states, genuine variadic message calls and both payout branches are reconstructed. Branch sharing and mixed absolute/GP data accesses remain different. -mno-split-addresses triggered GNU as tc-mips.c:11867 rather than producing an object.
 * Profile: -O2 -G8 -ffunction-sections
 * Final us check: func_L19_0042B058: 0 of 1 places match (src/levels/19_grelbin/L19_0042B058-g8.c); exit 1.
 * This source has not passed a linked build or a runtime test.
 */
#include "common.h"
typedef struct { u8 prefix[0x30]; int field30,field34,field38,field3c,field40,field44; } BarlowUtilityQueueView;
extern int D_L19_001B2508 __attribute__((nosda));
extern int D_L19_001B2728 __attribute__((nosda));
extern int D_L19_001A8F00 __attribute__((sda));
extern u8 *D_L19_001B2A1C __attribute__((sda));
extern int D_L19_001B1FB8 __attribute__((sda));
extern u8 D_001A7A40 __attribute__((sda));
extern int D_001A79F8 __attribute__((sda));
extern u32 D_00139800,D_00138324;
extern u32 D_001A7A1C __attribute__((nosda));
extern u8 D_L19_001A7C8F __attribute__((nosda));
extern u8 D_00139641,D_0013963C,D_0013963E __attribute__((nosda));
extern u32 D_L19_0028E988[4];
extern BarlowUtilityQueueView D_L19_001BFC40;
extern void func_L19_0042AF70(void);
extern int func_L19_0042A860(void);
extern int func_002F5D10(void);
extern void func_002A7750(u8 *,u8,int);
extern void func_L01_003128C0(char *);
extern int func_L01_003245E0(u8 *,int,float);
extern void func_L01_00324550(int,...);
extern void func_L01_003246D0(u8 *);
extern int func_00288AA0(u8 *,int);
extern int func_00288BE8(BarlowUtilityQueueView *);
extern void func_002A8598(int,int);
extern void func_0029F338(void *);
extern void func_0029B3E0(int,int);
extern void func_002B0A18(int,int);
extern int func_00288E18(int,int);
extern int func_00288D58(void);
extern void func_L00_0030C710(int);
extern int func_002A7820(int,int);
extern int func_002E5DA0(int,int,char *,int);
extern void func_002AEC48(void *,void *,int,float,float);
void func_L19_0042B058(u8 *object)
{
    u8 *state=*(u8 **)(object+0x68);
    u8 *companion;
    int next,remaining,kind;
    u32 price;
    func_L19_0042AF70();
    if (D_L19_001B2508==5) func_L19_0042A860();
    switch (object[0x20]) {
    case 0:
        if (func_002F5D10()) break;
        if (D_00139800 & 0x4000000) {
            *(u16 *)(object+0x34)=(*(u16 *)(object+0x34)&0xffbe)|0x1000;
            *(int *)(object+0x98)=*(int *)(*(u8 **)(object+0x24)+0x10);
            if (D_00139641) {
                func_L19_0042A860();
                next=(int)D_001A7A1C<1?7:8;
            } else {
                price=D_L19_0028E988[2];
        if (D_L19_001A7C8F) price=D_L19_0028E988[3];
                next=(int)D_001A7A1C<(int)price?4:5;
            }
            func_002A7750(object,next,-1);
            func_L01_003128C0((char *)object);
        } else if (D_00139800 & 0x1000000) {
            func_L19_0042A860();
            *(u16 *)(object+0x34)=(*(u16 *)(object+0x34)&0xffbe)|0x1000;
            *(int *)(object+0x98)=*(int *)(*(u8 **)(object+0x24)+0x10);
            next=(int)D_001A7A1C<(int)D_L19_0028E988[D_L19_001A7C8F?1:0]?1:2;
            goto change_state;
        } else {
            *(int *)(object+0x98)=0;
            *(u16 *)(object+0x34)=(*(u16 *)(object+0x34)&0xefff)|0x41;
        }
        break;
    case 1:
        price=D_L19_0028E988[0];
        if (D_L19_001A7C8F) price=D_L19_0028E988[1];
        if ((int)D_001A7A1C<(int)price) {
            if (func_L01_003245E0(object,10,2.5f)) {
                price=D_L19_0028E988[0];
        if (D_L19_001A7C8F) price=D_L19_0028E988[1];
                func_L01_00324550(0x27dc,price,-1);
                func_L01_003246D0(object);
            }
        } else { next=2; goto change_state; }
        break;
    case 2:
        price=D_L19_0028E988[0];
        if (D_L19_001A7C8F) price=D_L19_0028E988[1];
        if ((int)D_001A7A1C<(int)price) { next=1; goto change_state; }
        if (!func_L01_003245E0(object,10,2.5f)) break;
        price=D_L19_0028E988[0];
        if (D_L19_001A7C8F) price=D_L19_0028E988[1];
        func_L01_00324550(0x27dd,price,-1);
        func_L01_003246D0(object);
        if (!(D_00138324&0x10)) break;
        func_00288AA0((u8 *)&D_L19_001BFC40,0x9a);
        price=D_L19_0028E988[0];
        if (D_L19_001A7C8F) price=D_L19_0028E988[1];
        D_001A7A1C-=price;
        func_00288BE8(&D_L19_001BFC40);
        next=3;goto change_state;
    case 3:
        D_L19_001B2728=1;
        if (D_L19_001A8F00==2) {
            object[0x31]=0;*(u16 *)(object+0x34)|=1;
        }
        if (*(int *)(state+0x80)!=-1 && D_L19_001A8F00==2) {
            companion=D_L19_001B2A1C+*(int *)(state+0x80)*0x100;
            *(u16 *)(companion+0x34)|=1;
            (D_L19_001B2A1C+*(int *)(state+0x80)*0x100)[0x31]=0;
        }
        if (func_002F5D10()) break;
        D_L19_001B2728=0;
        object[0x31]=1;*(u16 *)(object+0x34)&=0xfffe;
        if ((s8)object[0x21]!=-1) func_002A8598((s8)object[0x21],1);
        if (*(int *)(state+0x80)!=-1) {
            func_0029F338(D_L19_001B2A1C+*(int *)(state+0x80)*0x100);
            *(int *)(state+0x80)=-1;
        }
        func_0029B3E0(0,-1);
        next=D_001A7A1C>D_L19_0028E988[D_L19_001A7C8F?3:2]?5:4;
        goto change_state;
    case 4:
        price=D_L19_0028E988[2];
        if (D_L19_001A7C8F) price=D_L19_0028E988[3];
        if ((int)D_001A7A1C<(int)price) {
            if (func_L01_003245E0(object,10,2.5f)) {
                price=D_L19_0028E988[2];
        if (D_L19_001A7C8F) price=D_L19_0028E988[3];
                func_L01_00324550(0x27de,price,-1);
                func_L01_003246D0(object);
            }
        } else { next=5;goto change_state; }
        break;
    case 5:
        price=D_L19_0028E988[2];
        if (D_L19_001A7C8F) price=D_L19_0028E988[3];
        if ((int)D_001A7A1C<(int)price) {next=4;goto change_state;}
        if (!func_L01_003245E0(object,10,2.5f)) break;
        price=D_L19_0028E988[2];
        if (D_L19_001A7C8F) price=D_L19_0028E988[3];
        func_L01_00324550(0x27df,price,-1);
        func_L01_003246D0(object);
        if (!(D_00138324&0x10)) break;
        func_00288AA0((u8 *)&D_L19_001BFC40,0x99);
        price=D_L19_0028E988[2];
        if (D_L19_001A7C8F) price=D_L19_0028E988[3];
        D_001A7A1C-=price;
        func_00288BE8(&D_L19_001BFC40);
        next=6;goto change_state;
    case 6:
        D_L19_001B2728=1;
        if (D_L19_001A8F00==2) {object[0x31]=0;*(u16 *)(object+0x34)|=1;}
        if (func_002F5D10()) break;
        D_L19_001B2728=0;object[0x31]=1;*(u16 *)(object+0x34)&=0xfffe;
        if ((s8)object[0x21]!=-1) func_002A8598((s8)object[0x21],1);
        D_00139641=1;
        func_002B0A18(0x1294,-1);
        remaining=D_0013963C?1:2;
        if (D_0013963E) remaining--;
        if (remaining<1) func_00288E18(0xa10,0x67);
        else func_00288E18(0xa0f,0x66);
        func_0029B3E0(0,-1);
        next=(int)D_001A7A1C<1?7:8;goto change_state;
    case 7:
        if ((int)D_001A7A1C<1) {
            if (!func_L01_003245E0(object,10,2.5f)) break;
            if (!D_L19_001B1FB8) func_L01_00324550(0x27e2,0,-1);
            else func_L01_00324550(0x27e0,-1);
            func_L01_003246D0(object);
        } else {next=8;goto change_state;}
        break;
    case 8:
        if ((int)D_001A7A1C<1) {next=7;goto change_state;}
        if (!func_L01_003245E0(object,10,2.5f)) break;
        if (!func_00288D58()) {
            func_L01_00324550(0x27e1,D_001A7A1C,D_001A7A1C*3000,-1);
            func_L01_003246D0(object);
            if (!(D_00138324&0x10)) break;
            func_L19_0042A860();
            D_001A79F8=D_001A79F8+D_001A7A1C*3000;
            D_001A7A1C=0;
            func_L00_0030C710(180);
        } else {
            func_L01_00324550(0x27e1,D_001A7A1C,D_001A7A1C*30000,-1);
            func_L01_003246D0(object);
            if (!(D_00138324&0x10)) break;
            func_L19_0042A860();
            D_001A79F8=D_001A79F8+D_001A7A1C*30000;
            D_001A7A1C=0;
            func_L00_0030C710(180);
            kind=func_002A7820(13,17);
            func_002E5DA0(0,0,(char *)object,kind);
        }
        next=9;goto change_state;
    case 9:
        ++*(u16 *)(object+0x96);
        if (*(u16 *)(object+0x96)>0x7ff8) *(u16 *)(object+0x96)=0x7ff8;
        if ((u32)(*(u16 *)(object+0x96)-41)<49 && !(*(u16 *)(object+0x96)&3)) {
            kind=func_002A7820(13,17);
            func_002E5DA0(0,0,(char *)object,kind);
        }
        if (!func_L01_003245E0(object,10,2.5f)) func_002A7750(object,7,-1);
        else func_L01_00324550(0x27e2,D_L19_001B1FB8,-1);
        break;
    }
    goto finish;
change_state:
    func_002A7750(object,next,-1);
finish:
    if (D_001A7A40) *(float *)(state+0x70)=2.75f;
    func_002AEC48(object,state,0,0.02f,0.3f);
}
