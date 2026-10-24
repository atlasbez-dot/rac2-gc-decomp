/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G32 -Wa,-G32 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -mno-split-addresses.
 * Prior worker coverage: US assembly/compile failure before comparison; US2 assembly/compile
 * failure before comparison; PAL assembly/compile failure before comparison.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 * Reopen only after the recorded GNU as assertion has a diagnosed remedy and the L09_0033E690
 * live-input contract is qualified against retail. A successful C frontend is not a placement
 * comparison; the historical MMI impossibility claim below is not a classification decision.
 */

/* Historical analysis (summary).
 * Historical screening treated packed-copy instructions as a categorical C barrier. That alone
 * does not establish handwritten assembly. Its raw instruction words remain private. The current
 * manual reconstruction below instead records an assembler assertion and the unresolved
 * callee-input qualification; neither a completed frontend nor the historical classification is
 * a matching placement.
 */

/* Wave4 manual reconstruction, 2026-10-23. Nonmatching; historical screening above
   is summarized; generated listings and unsupported classifications remain private.
   Trial source: src/levels/shared/L18_003F5650-g8-qcopy.c
   Profile: -O2 -G32 -Wa,-G32 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses
   C frontend completed; GAS assertion tc-mips.c:11867 at end of assembly, including final tests. G8 with and without qcopy and G32/Wa32 failed. The canonical L09_0033E690 C definition accepts two GPR arguments; callers also zero f12, which its current definition does not consume. Further retail callee qualification remains before any exact claim.
   us: compile_error, exit 1; us2: compile_error, exit 1; pal: compile_error, exit 1
*/
#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
typedef struct { u8 reserved_00[0x18]; u8 enabled,count,kind; u8 reserved_1b[0x65]; u8 payload[1]; } Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext;
#define BYTE(p,o) (*(u8 *)((p)+(o)))
#define SHORT(p,o) (*(short *)((p)+(o)))
#define USHORT(p,o) (*(u16 *)((p)+(o)))
#define WORD(p,o) (*(int *)((p)+(o)))
#define REAL(p,o) (*(float *)((p)+(o)))
#define PTR(p,o) (*(u8 **)((p)+(o)))
#define VECTOR(p,o) (*(Vector128 *)((p)+(o)))
extern int func_002B3868(u8 *);
extern void func_002A7470(u8 *,int,int,int);
extern void func_002A05A8(u8 *);
extern int func_002A7820(int,int);
extern int func_002A77E0(int);
extern float func_002A7878(float,float);
extern int func_L18_003F7320(void *);
extern void func_002A7750(u8 *,u8,int);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282D30(void *,void *,float);
extern void func_00282C88(Vector128 *);
extern float func_00282E80(void *,void *);
extern float func_00282E48(void *,void *);
extern float func_00282DB0(void *,void *);
extern void func_002A8C28(void *,void *,int,int,int,int,float,float,float);
extern int func_002ACBC8(void *,int);
extern float func_0029F530(char *);
extern void func_0029FCC0(char *,int,char *);
extern void *func_002B60B0(u8 *,float,float,float,float);
extern void func_L18_003F72D8(u8 *,u8 *);
extern int func_L18_003F75E8(int,u8 *);
extern void func_L18_003F76F0(u8 *,void *,void *);
extern int func_00277F48(void *,int,void *,int,float);
extern void func_002A8F70(void *,void *,unsigned int,void *,void *,float);
extern int func_L18_003F8E80(u8 *);
extern int func_L18_003F73B8(char *,float *);
extern int func_L18_003F7358(u8 *,u8 *);
extern int func_L18_003F7470(u8 *);
extern int func_L09_0033E690(char *,int);
extern int func_L14_00423CD0(u8 *,void *,int,short *,int,float);
extern int func_L18_0032B768(u8 *,int,int);
extern float func_00283CE0(int);
extern int func_00277258(void *,int,void *,float);
extern void func_002ACB48(float *,float);
extern void func_002B1350(void *,void *,void *,int);
extern unsigned long func_002B1C20(void *,Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *);
extern void func_002A6C58(void *,int,int);
extern void func_L18_003F74B8(void *,int);
extern Vector128 D_00189EA0 __attribute__((nosda));
extern u8 *D_0018C0B0,*D_0018C2BC;
extern int D_0018C0B4;
extern int D_001A7A00;
extern u8 *D_L18_001BFC18;
extern u8 *D_L18_001C3C80[];
extern unsigned int D_L18_001B2348;
extern Vector128 D_L18_001B0420 __attribute__((sda));
extern u16 *D_L18_001FB320[];
extern int D_L18_001B2838;
extern u8 *D_L18_001B281C;
extern u8 *D_L18_001FE480[];

void func_L18_003F5650(u8 *object)
{
    Vector128 position,offset,impulse;
    int available[4];
    u8 *state=PTR(object,0x68),*other,*spawn;
    u8 **hit;
    u16 *entry;
    int action,animation,group,index,next,count,empty;
    u8 previous;
    unsigned long flags;
    float phase,randomValue,distance,nearest,sign;
    switch(BYTE(object,0x20)) {
    case 2:
        if(func_002B3868(object)) {
            REAL(state,0x100)=0.34f; REAL(state,0x108)=0.1f; REAL(state,0x104)=0;
            if(BYTE(object,0x43)!=9) func_002A7470(object,9,0,0);
            BYTE(object,0x31)=0; BYTE(object,0xbc)=0; USHORT(object,0x34)|=1;
            return;
        }
        if(BYTE(object,0xbc)==0) {
            if(func_002ACBC8(&D_00189EA0,WORD(state,0x270))) { USHORT(object,0x96)=0; BYTE(object,0xbc)=1; }
            return;
        }
        if(BYTE(object,0xbc)!=1) return;
        offset=0; impulse=0;
        REAL(&offset,8)=REAL(state,0x104)+REAL(state,0x100);
        REAL(&impulse,8)=REAL(&offset,8);
        func_00282CC0(&position,object+0x10,&offset);
        func_002A8C28(object,&position,0x4000000,0,1,0,REAL(state,0x100)+REAL(state,0x100),10.0f,1.0f);
        if(USHORT(object,0x96)>10) {
            func_00282F20(&impulse,object+0xc0,0.06666667f);
            REAL(&impulse,8)=0.033333335f;
            func_L18_003F76F0(object,object+0x10,&impulse);
        }
        return;
    case 3:
        if(func_002B3868(object)) {
            SHORT(state,0x2a6)=0;
            func_002A7470(object,9,0,3); func_002A05A8(object);
            BYTE(object,0x31)=1; REAL(object,0x2c)=0.001f; USHORT(object,0x34)&=0xfffe;
            SHORT(state,0x294)=0; SHORT(state,0x29e)=func_002A7820(180,180); SHORT(state,0x2a4)=func_002A7820(2,4);
        } else {
            if(SHORT(state,0x2a6)==0 && USHORT(object,0x96)>=31) SHORT(state,0x2a6)=1;
            if(REAL(object,0x2c)<REAL(state,0x268)) REAL(object,0x2c)+=REAL(state,0x268)*0.1f;
            if(func_L18_003F7320(object)) {
                REAL(object,0x2c)=REAL(state,0x268);
                func_002A7750(object,6,2); func_002A7750(object,7,-1);
            }
        }
        impulse=0; offset=0;
        REAL(&offset,8)=REAL(state,0x104)+REAL(state,0x100); REAL(&impulse,8)=REAL(&offset,8);
        func_00282CC0(&position,object+0x10,&offset);
        func_002A8C28(object,&position,0x4000000,0,1,0,REAL(state,0x100)+0.2f,10.0f,1.0f);
        return;
    case 6:
        if(func_002B3868(object)) {
            animation=BYTE(object,0x43);
            if(animation!=func_002A77E0(2)+1) {
                animation=func_002A77E0(2)+1;
                index=func_002A7820(9,15); func_002A7470(object,animation,0,index);
            }
            WORD(state,0x250)=func_002A7820(480,600);
        } else if(PTR(state,0x258)) func_002A7750(object,11,-1);
        else if(WORD(state,0x278)!=-1) func_002A7750(object,13,-1);
        else if(WORD(state,0x248)==1 && D_0018C0B4!=0x6f) func_002A7750(object,12,-1);
        if(!(BYTE(object,0x60)&2)) return;
        if(func_002A77E0(49)==0) {
            if(BYTE(object,0x43)!=10) { index=func_002A7820(9,15); func_002A7470(object,10,0,index); }
        } else {
            animation=BYTE(object,0x43);
            if(animation!=func_002A77E0(2)+1) {
                animation=func_002A77E0(2)+1; index=func_002A7820(9,15); func_002A7470(object,animation,0,index);
            }
        }
        REAL(object,0x48)=func_002A7878(0.85f,1.15f); return;
    case 7: case 8:
        if(func_002B3868(object)) {
            animation=BYTE(object,0x20)==7?0:10;
            if(BYTE(object,0x43)!=animation) func_002A7470(object,animation,0,10);
            return;
        }
        if(BYTE(object,0x60)&2) goto resume_previous;
        return;
    case 9:
        if(func_002B3868(object)) {
            if(BYTE(object,0x43)!=6) func_002A7470(object,6,0,10);
            BYTE(object,0xbc)=0; SHORT(state,0x298)=0; return;
        }
        if(BYTE(object,0xbc)==0 && (BYTE(object,0x60)&2)) {
            if(BYTE(object,0x43)!=7) func_002A7470(object,7,0,10);
            BYTE(object,0xbc)=1; return;
        }
        if(BYTE(object,0xbc)==1) {
            available[0]=50;
            if(USHORT(object,0x96)>20) {
                USHORT(object,0x96)=0;
                spawn=(u8 *)func_L18_003F75E8(WORD(state,0x25c),(u8 *)available);
                if(spawn) {
                    func_00282CC0(&position,object+0x10,&D_L18_001B0420); func_00282C88(&offset);
                    REAL(&offset,8)=0.13333334f;
                    randomValue=func_002A7878(2.0f,3.0f);
                    if(func_002A77E0(2)==0) REAL(&offset,0)-=randomValue*0.016666668f;
                    else REAL(&offset,0)+=randomValue*0.016666668f;
                    randomValue=func_002A7878(2.0f,3.0f);
                    if(func_002A77E0(2)==0) REAL(&offset,4)-=randomValue*0.016666668f;
                    else REAL(&offset,4)+=randomValue*0.016666668f;
                    func_L18_003F76F0(spawn,&position,&offset);
                    WORD(spawn,0xb8)=WORD(object,0xb8); SHORT(state,0x298)++;
                }
            }
            if(SHORT(state,0x298)<3 && available[0]!=0) return;
            if(BYTE(object,0x43)!=8) func_002A7470(object,8,0,10);
            BYTE(object,0xbc)=2; return;
        }
        if(BYTE(object,0xbc)==2 && (BYTE(object,0x60)&2)) goto resume_previous;
        return;
    case 10:
        if(func_002B3868(object)) {
            if(BYTE(object,0x43)!=5) func_002A7470(object,5,0,10);
            return;
        }
        phase=func_0029F530((char *)object);
        if(BYTE(object,0x42)==5) {
            if(phase<10.0f) {
                func_002B60B0(object,0.08333333582f,0.3333333433f,0.1939254999f,2.908882618f);
                if(BYTE(object,0x94)==11 && PTR(state,0x258)) func_L18_003F72D8(object,PTR(state,0x258)+0x10);
                else func_L18_003F72D8(object,state+0x1f0);
            }
            if(BYTE(object,0x42)==5 && phase>10.0f && phase<17.0f) {
                func_0029FCC0((char *)object,0,(char *)&position);
                count=func_00277F48(&position,0,object,0,0.2f);
                for(hit=D_L18_001C3C80;count>0;count--,hit++) {
                    other=*hit;
                    if(other==D_0018C0B0) offset=D_00189EA0;
                    else { offset=VECTOR(other,0x10); if(SHORT(other,0xaa)==0xb69) continue; }
                    func_00282CF0(&impulse,other+0x10,object+0x10); REAL(&impulse,8)=0;
                    func_00282F20(&impulse,&impulse,2.0f); REAL(&impulse,12)=5627.924805f;
                    func_002A8F70(other,object,0x10001,other+0x10,&impulse,(float)BYTE(state,0x34));
                }
            }
        }
        if(!(BYTE(object,0x60)&2)) return;
        func_002B60B0(object,0.004444444552f,0.1333333403f,0.003490658943f,0.2094395459f);
        if(D_0018C2BC==object) { previous=BYTE(object,0x94); func_002A7750(object,8,-1); BYTE(object,0x94)=previous; return; }
        goto resume_previous;
    case 11:
        if(func_002B3868(object)) {
            if(BYTE(object,0x43)!=4) func_002A7470(object,4,0,10);
            REAL(state,0x24c)=0.01745329425f; return;
        }
        VECTOR(state,0x230)=VECTOR(PTR(state,0x258),0x10);
        if(func_L18_003F8E80(object) && func_L18_003F73B8((char *)object,(float *)(PTR(state,0x258)+0x10))) { action=10; goto change_state; }
        if(func_L18_003F7358(object,PTR(state,0x258))) { action=8; goto change_state; }
        other=PTR(state,0x258);
        if(other && (signed char)BYTE(other,0x20)!=-2 && (signed char)BYTE(other,0x20)!=-3 && !(USHORT(other,0x34)&1)) return;
        PTR(state,0x258)=0; func_002A7750(object,12,-1); action=8; goto change_state;
    case 12:
        if(func_002B3868(object)) {
            if(BYTE(object,0x43)!=4) func_002A7470(object,4,0,10);
            randomValue=func_002A7878(15.0f,30.0f); sign=0.017453294f;
            if(func_002A77E0(2)) sign=-0.017453294f;
            REAL(state,0x24c)=randomValue*sign; BYTE(object,0xbc)=0;
        }
        if(BYTE(object,0xbc)==0) {
            VECTOR(state,0x230)=VECTOR(state,0x1f0);
            group=WORD(state,0x27c);
            if(group!=-1 && (D_L18_001B2348&7)==((unsigned int)object>>8&7)) {
                empty=1; nearest=1000.0f;
                for(entry=D_L18_001FB320[group]; (group&255)!=255 && group<=D_L18_001B2838 && entry; entry++) {
                    if((short)entry[-1]<0 && entry!=D_L18_001FB320[group]) break;
                    other=D_L18_001B281C+(*entry&0x7fff)*256; if(!other) break;
                    if((signed char)BYTE(other,0x20)!=-2 && (signed char)BYTE(other,0x20)!=-3) {
                        distance=func_00282E80(object+0x10,other+0x10); empty=0;
                        if(distance<nearest) nearest=distance;
                    }
                    group=WORD(state,0x27c);
                }
                if(empty) { WORD(state,0x27c)=-1; WORD(state,0x278)=-1; }
            }
            if(func_L18_003F73B8((char *)object,(float *)(state+0x1f0))) {
                USHORT(object,0x96)=0; BYTE(object,0xbc)=1;
                animation=BYTE(object,0x43);
                if(animation!=func_002A77E0(2)+1) { animation=func_002A77E0(2)+1; func_002A7470(object,animation,0,10); }
            }
        } else if(BYTE(object,0xbc)==1) {
            if(func_L18_003F73B8((char *)object,(float *)(state+0x1f0)) && WORD(state,0x180)<2) func_002A7750(object,10,-1);
            else if(USHORT(object,0x96)>60) func_002A7750(object,12,-1);
        }
        if(func_L18_003F7470(object)) func_002A7750(object,9,2);
        if(WORD(state,0x248)!=1) { action=6; goto change_state; }
        return;
    case 13:
        if(func_002B3868(object)) {
            if(BYTE(object,0x43)!=4) func_002A7470(object,4,0,10);
            SHORT(state,0x29a)=func_L09_0033E690((char *)(object+0x10),WORD(state,0x278));
            randomValue=func_002A7878(15.0f,30.0f); sign=0.017453294f;
            if(func_002A77E0(2)) sign=-0.017453294f;
            REAL(state,0x24c)=randomValue*sign;
            func_002B60B0(object,0.001666666707f,0.05000000447f,0.003490658943f,0.1047197729f); return;
        }
        func_L14_00423CD0(object,state+0x230,WORD(state,0x278),(short *)(state+0x29a),0,3.0f);
        group=WORD(state,0x27c); if(group==-1) return;
        if((D_L18_001B2348&63)!=((unsigned int)object>>8&63)) return;
        empty=1;
        for(entry=D_L18_001FB320[group]; (group&255)!=255 && group<=D_L18_001B2838 && entry; entry++) {
            if((short)entry[-1]<0 && entry!=D_L18_001FB320[group]) break;
            other=D_L18_001B281C+(*entry&0x7fff)*256; if(!other) break;
            if((signed char)BYTE(other,0x20)!=-2 && (signed char)BYTE(other,0x20)!=-3) { empty=0; break; }
        }
        if(empty) { WORD(state,0x27c)=-1; WORD(state,0x278)=-1; action=12; goto change_state; }
        return;
    case 14:
        if(func_002B3868(object)) {
            REAL(state,0xa8)=1; REAL(state,0x134)=0.001f; REAL(state,0xac)=1;
            index=func_L09_0033E690((char *)(object+0x10),WORD(state,0x26c)); SHORT(state,0x29a)=index;
            other=D_L18_001FE480[WORD(state,0x26c)];
            if(SHORT(state,0x29c)==0) { next=0; if(index!=WORD(other,0)-1) next=index+1; }
            else if(index==0) next=WORD(other,0)-1;
            else next=index-1;
            func_00282CF0(&position,other+next*16+16,other+index*16+16);
            func_00282CF0(&offset,D_L18_001FE480[WORD(state,0x26c)]+SHORT(state,0x29a)*16+16,object+0x10);
            if(func_00282DB0(&offset,&position)<0) SHORT(state,0x29a)=next;
            WORD(object,0x98)=0; USHORT(object,0x34)=USHORT(object,0x34)&0xefff|0x41;
            animation=BYTE(object,0x43);
            if(animation!=func_002A77E0(2)+1) {
                animation=func_002A77E0(2)+1; index=func_002A77E0(10); func_002A7470(object,animation,index,10);
            }
            BYTE(object,0xbc)=0; return;
        }
        if(BYTE(object,0xbc)==0) {
            if(WORD(state,0x270)!=-1 && func_002ACBC8(&D_00189EA0,WORD(state,0x270))) {
                BYTE(object,0xbc)=1; USHORT(object,0x34)=USHORT(object,0x34)&0xffbe|0x1000;
                WORD(object,0x98)=WORD(PTR(object,0x24),0x10); func_L18_0032B768(object,0,2);
            }
            return;
        }
        if(func_L14_00423CD0(object,state+0x230,WORD(state,0x26c),(short *)(state+0x29a),SHORT(state,0x29c),0.2f)==0) func_002A7750(object,15,-1);
        distance=func_00282E48(object+0x10,&D_00189EA0); if(distance>=8) return;
        if(BYTE(object,0x43)!=1) func_002A7470(object,1,0,10);
        if(distance>=2) return;
        position=VECTOR(object,0x10); REAL(&position,8)+=REAL(state,0x104)+REAL(state,0x100);
        randomValue=REAL(state,0x100)+0.2f; phase=func_00283CE0(D_001A7A00);
        func_002A8C28(object,&position,1,0,1,0,randomValue,phase*0.25f,1.0f);
        if(func_00277258(&position,1,object,REAL(state,0x100)+0.2f) && D_L18_001BFC18 && SHORT(D_L18_001BFC18,0xaa)!=0xb69) {
            WORD(state,0x20)=0; func_00282F20(&offset,object+0xc0,-1.0f); func_002ACB48((float *)&offset,0.3f);
            func_002B1350(object,state+0x50,&offset,2); func_002A7750(object,17,3);
        }
        return;
    case 15:
        if(func_002B3868(object)) {
            func_002ACB48((float *)(state+0x1a0),0.05000000447f); REAL(state,0x1a8)=0.08333333582f;
            if(BYTE(object,0x43)!=13) func_002A7470(object,13,0,10); return;
        }
        if(USHORT(object,0x96)>=301) goto remove_object;
        return;
    case 16:
        if(func_002B3868(object)) {
            if(BYTE(object,0x43)!=2) func_002A7470(object,2,0,10);
            func_00282F20(state+0x1a0,object+0xc0,-0.06666667f); return;
        }
        phase=func_0029F530((char *)object);
        if(REAL(object,0x48)==1.0f && phase>23.0f) {
            REAL(object,0x48)=-0.65f; func_00282F20(state+0x1a0,object+0xc0,0.13333334f); REAL(state,0x1a8)+=0.1388889f; return;
        }
        if(REAL(object,0x48)==-0.65f && phase<3.0f) { REAL(object,0x48)=1.0f; goto resume_previous; }
        return;
    case 17:
        if(func_002B3868(object)) {
            if(BYTE(object,0x42)==12 || BYTE(object,0x43)==12) USHORT(object,0x34)&=0xefff;
            if(BYTE(object,0x94)==14) func_00282D30(state+0xd0,state+0xd0,3.0f);
        }
        flags=func_002B1C20(object,(Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *)(state+0x50));
        if((unsigned int)(BYTE(object,0x94)-14)<2) {
            phase=func_0029F530((char *)object);
            if(BYTE(object,0x42)==11 && phase>16.0f) func_002A7750(object,15,-1);
        }
        phase=func_0029F530((char *)object);
        if((flags&1) || (BYTE(object,0x42)==12 && phase>15.0f && func_002A77E0(15)==0)) goto remove_object;
        if(flags&2) {
            PTR(state,0x258)=0; previous=BYTE(object,0x95); func_002A7750(object,12,2);
            if(previous==1) { action=7; goto change_state; }
        }
        return;
    case 18:
        if(func_002B3868(object)) {
            USHORT(object,0x34)&=0xefff;
            if(BYTE(object,0x95)==2 && BYTE(object,0x43)!=3) func_002A7470(object,3,0,10);
            REAL(object,0x48)=1.0f;
        }
        if(!(BYTE(object,0x60)&2) && USHORT(object,0x96)<61) return;
        WORD(state,0x20)=0;
remove_object:
        func_002A6C58(object,0,1); func_L18_003F74B8(object,0); return;
    default: return;
    }
resume_previous:
    action=BYTE(object,0x94);
change_state:
    func_002A7750(object,action,-1);
}
