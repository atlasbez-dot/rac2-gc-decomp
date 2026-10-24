/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -mno-split-addresses.
 * Prior worker coverage: US 0/2; US2 0/2; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Historical analysis (summary).
 * Historical screening catalogued calls, vector operations and data addressing without a
 * complete manual reconstruction. Its generated call/address lists and decoded instruction
 * header remain private. The dated manual reconstruction and recorded worker profile below
 * supersede that screening; no unsupported impossibility or handwritten classification is
 * carried forward.
 */

/* Wave4 manual reconstruction, 2026-10-23. Nonmatching; historical screening above
   is summarized; generated listings and unsupported classifications remain private.
   Trial source: src/levels/shared/L18_002DEFF8-g8-qcopy.c
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses
   Family vector uses actual current three-float12B definition. Two level-only handler calls retain normal scoped reference. Timers and history stores reconstructed; exact source tree/register allocation unresolved.
   us: func_L18_002DEFF8: 0 of 2 places match (src/levels/shared/L18_002DEFF8-g8-qcopy.c), exit 1; us2: func_L18_002DEFF8: 0 of 2 places match (src/levels/shared/L18_002DEFF8-g8-qcopy.c), exit 1; pal: absent_from_catalogue, exit 1
*/
#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
typedef struct { float x,y,z; } FamilyC94396F4Vector_Fc94396f4;
typedef struct { int timer; unsigned char fields[0x6c]; } TimedRecord;
extern char D_00189E20[];
extern unsigned int D_00138320 __attribute__((nosda)),D_00138324 __attribute__((nosda));
extern int D_00138354 __attribute__((nosda));
extern unsigned char D_001A7AFF __attribute__((nosda));
extern int D_L18_001A8F00 __attribute__((nosda));
extern float D_L18_001B2260 __attribute__((nosda)),D_L18_001B2264 __attribute__((sda));
extern unsigned int D_L18_001B2348 __attribute__((sda));
extern char *D_L18_001FB6E0[];
extern TimedRecord D_L18_002653E0[4];
extern Vector128 D_0018BBB0[32];
extern void func_L00_002B9380(void);
extern int func_00282978(short *);
extern int func_00282948(int *);
extern void func_L00_002A7A10(void);
extern int ref_L18_002DEFF8_00(int,int);
extern int func_002ABB78(char *);
extern int func_002A77E0(int);
extern float func_00282E48(void *,void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_002A8F70(void *,void *,unsigned int,void *,void *,float);
extern float func_L00_002D3B00(char *);
extern void func_00282C88(Vector128 *);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282D30(void *,void *,float);
extern float func_00282DF0(void *);
extern void func_L00_002C3838(void);
extern void func_L00_002D36E0(float *,int,float,float,float);
extern void func_L00_002D3778(FamilyC94396F4Vector_Fc94396f4 *,FamilyC94396F4Vector_Fc94396f4 *,float);
extern void func_L00_002B30E8(void);
void func_L18_002DEFF8(void)
{
    Vector128 sum[1],delta[1];
    char *player=D_00189E20;
    char **entry;
    char *object;
    unsigned int frame;
    int i,index,previous;
    if(*(unsigned char *)(player+0x22bd)==0) func_L00_002B9380();
    (*(int *)(player+0x1b8))++; (*(int *)(player+0x1bc))++; (*(int *)(player+0x1c0))++; (*(int *)(player+0x1c4))++;
    func_00282978((short *)(player+0x1e0));
    func_00282978((short *)(player+0x1dc));
    func_00282978((short *)(player+0x1d2));
    func_00282978((short *)(player+0x1e4));
    func_00282978((short *)(player+0x1f8));
    func_00282978((short *)(player+0x1fe));
    func_00282948((int *)(player+0x1d4));
    func_00282978((short *)(player+0x210));
    func_00282978((short *)(player+0x1d0));
    func_00282978((short *)(player+0x1f4));
    func_00282978((short *)(player+0x1f6));
    func_00282978((short *)(player+0x204));
    func_00282978((short *)(player+0x206));
    func_00282978((short *)(player+0x1f0));
    func_00282978((short *)(player+0x1ec));
    func_00282978((short *)(player+0x1ee));
    func_00282978((short *)(player+0x208));
    func_00282978((short *)(player+0x200));
    func_00282978((short *)(player+0x20e));
    func_00282978((short *)(player+0x20a));
    func_00282978((short *)(player+0x214));
    func_00282978((short *)(player+0x212));
    func_00282978((short *)(player+0x1fc));
    func_00282978((short *)(player+0x216));
    func_00282978((short *)(player+0x1fa));
    func_00282978((short *)(player+0x218));
    func_00282978((short *)(player+0x1f2));
    func_00282978((short *)(player+0x21a));
    func_00282978((short *)(player+0x21c));
    func_00282978((short *)(player+0x1de));
    func_00282978((short *)(player+0x1e6));
    func_00282978((short *)(player+0x222));
    func_00282978((short *)(player+0x224));
    func_00282978((short *)(player+0x226));
    if((D_00138320&4)==0) *(short *)(player+0x20c)=0;
    if(*(short *)(player+0x21c)!=0) func_L00_002A7A10();
    if(*(unsigned char *)(player+0x22b8)==0) *(int *)(player+0x1d8)=0;
    else (*(int *)(player+0x1d8))++;
    if(D_00138354==0) { *(int *)(player+0x1cc)=0; (*(int *)(player+0x1c8))++; }
    else { *(int *)(player+0x1c8)=0; (*(int *)(player+0x1cc))++; }
    if(*(unsigned char *)(player+0x22c3)!=0 && *(int *)(player+0x229c)==0 && *(int *)(player+0x340)!=0 && *(float *)(player+0x170)<0.001666666824f && *(float *)(player+0x184)<0.001666666824f) *(Vector128 *)(player+0x80)=*(Vector128 *)(player+0x2030);
    if(*(short *)(player+0x1454)==0) (*(int *)(player+0x1e8))++; else *(int *)(player+0x1e8)=0;
    if(*(int *)(player+0x24cc)==0 || D_L18_001A8F00==0) {
        if(*(int *)(player+0x24cc)!=0 && *(unsigned char *)(player+0x22b4)==4 && *(int *)(player+0x2294)!=0x6f && (D_00138324&0x10)!=0) {
            *(int *)(player+0x24cc)=0; *(short *)(player+0x1e0)=0; ref_L18_002DEFF8_00(0x91,1);
        }
        if(D_L18_001A8F00==0) {
            if(D_L18_001B2260>0.0f) (*(short *)(player+0x22a))++; else *(short *)(player+0x22a)=0;
            if(*(short *)(player+0x22a)>120) { D_L18_001B2260=0.0f; *(short *)(player+0x22a)=0; }
            if(D_L18_001B2264>0.0f) (*(short *)(player+0x228))++; else *(short *)(player+0x228)=0;
            if(*(short *)(player+0x228)>120) { *(short *)(player+0x228)=0; D_L18_001B2264=0.0f; }
        }
    }
    if(*(short *)(player+0x224)!=0) {
        for(entry=D_L18_001FB6E0;(object=*entry)!=0;entry++) {
            if((func_002ABB78(object)!=0 || (*(void **)(object+0x24)!=0 && *(short *)(*(char **)(object+0x24)+0x46)==0x16)) && ((D_L18_001B2348&7)==((unsigned int)object>>8&7) || func_002A77E0(4)==0)) {
                if(func_00282E48(player+0x80,object+0x10)<15.37f) {
                    func_00282CF0(sum,object+0x10,player+0x80);
                    func_00282F20(sum,sum,1.7f);
                    func_002A8F70(object,*(void **)(player+0x2290),0x4000000u,player+0x80,sum,1.0f);
                }
            }
        }
    }
    for(i=0;i<4;i++) func_00282948(&D_L18_002653E0[i].timer);
    *(float *)(player+0x24dc)=9999.0f;
    if(*(short *)(player+0x34e)!=0 && func_L00_002D3B00(player+0xf0)<0.0f) {
        if(*(int *)(player+0x23c8)==32) {
            func_00282C88(sum);
            for(i=0;i<8;i++) {
                index=(*(int *)(player+0x23c4)-i+31)%32;
                previous=(*(int *)(player+0x23c4)-i+30)%32;
                func_00282CF0(delta,&D_0018BBB0[index],&D_0018BBB0[previous]);
                func_00282CC0(sum,sum,delta);
            }
            func_00282D30(sum,sum,0.125f);
            if(func_00282DF0(sum)<0.016666668f) (*(short *)(player+0x202))++;
            else *(short *)(player+0x202)=0;
        }
    } else *(short *)(player+0x202)=0;
    func_L00_002C3838();
    if(*(unsigned char *)(player+0x22b4)==4) func_L00_002D36E0((float *)(player+0xe0),1,0.0f,0.0f,0.4f);
    else func_L00_002D36E0((float *)(player+0xe0),1,0.0f,0.0f,0.7f);
    frame=D_L18_001B2348;
    if((frame&3)==0) {
        if(*(unsigned char *)(player+0x22b4)==4) { *(float *)(player+0x24a8)=1.25f; *(float *)(player+0x24a4)=2.125f; }
        else if(D_001A7AFF==0) { *(float *)(player+0x24a8)=2.25f; *(float *)(player+0x24a4)=4.25f; }
        else { *(float *)(player+0x24a8)=4.5f; *(float *)(player+0x24a4)=14.0f; }
    }
    if(*(float *)(player+0x31c)<4.0f) {
        *(Vector128 *)(player+0xd0)=*(Vector128 *)(player+0x2d0);
        func_L00_002D3778((FamilyC94396F4Vector_Fc94396f4 *)(player+0xd0),(FamilyC94396F4Vector_Fc94396f4 *)(player+0xd0),0.5f);
    } else *(Vector128 *)(player+0xd0)=*(Vector128 *)(player+0xe0);
    object=*(char **)(player+0x5c0);
    if(object!=0) {
        if((*(unsigned short *)(object+0x34)&0x1000)==0 || object==*(char **)(player+0x33c)) *(void **)(player+0x5c0)=0;
        if(*(void **)(player+0x5c0)!=0 && *(int *)(player+0x1248)!=0x2e) *(void **)(player+0x5c0)=0;
    }
    if(*(float *)(player+0x88)<1.0f) func_L00_002B30E8();
}
