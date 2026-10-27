/* Retained complete manual C reconstruction; NOT an exact match.
 * Measured profile: -O2 -G0 -ffunction-sections.
 * Final compiled/retail size: 2316/2312 bytes.
 * Coverage: us: 0/1 placements (exit 1); us2: 0/1 placements (exit 1); pal: absent from both
 * catalogues (exit 1).
 * Storage and contracts: Six clobbering snapshots preserve old position/rotation, private initial
 * position, child positions and the mutable full delta whose Z becomes the target height. Initial
 * and post-movement child paths are separate. Both child component updates remain after their
 * copies. Real pointer allocator result and canonical integer dispatcher input slots are retained.
 * Residual: 2316B versus 2312B, both 0x80 frames. Prefix through +0x6C agrees, then branch targets
 * differ at +0x70; state-3 FP operands, allocation-result register and constructor scheduling
 * differ. Equal-size scope/mixed/overlay forms are not byte-identical.
 * Reopen with: Allocator or source lifetime evidence explaining the short-lived constructor result
 * and the state-3 FP comparison/order, without pins or prototype changes.
 * M34 2026-10-26: now 2312/2312 (first difference +0x70, branch offsets only until +0x108):
 *   the state-3 test reads F(obj,0x18) first (`F(obj,0x18) > F(ctx,0x98)`), the brightness clamp
 *   is `if (value > 208) value = 208; else if (value < 80) value = 80;` (retail's slti 0xD1
 *   first), and the constructor result has its own local (`made`; retail keeps it in $v1).
 *   Left: argument-register numbering in case 0 (retail a2/a3/a1 where this gives a1/a2/a0),
 *   the brightness or-chain grouping (twelve spellings tried, none exact), the sound-handle
 *   index scaling (retail mult by 0x70 before the table base), and a few delay-slot fills.
 * Whole-behavior and strict linked-image qualification remain unverified.
 * Failed SRC unit/marker/profile are restored after these private per-function checks.
 */
#include "common.h"

typedef unsigned int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vec;
extern Vec D_00189EA0;
extern char D_001886D4[];
extern float func_00283B98(float,float),func_00283198(float),func_00283180(float),func_00282C48(float),func_002A7940(void);
extern float func_00282E80(void *,void *),func_00282E48(void *,void *);
extern int func_00283CF0(float),func_L00_00324120(int),func_002E59B0(void *,int),func_002E5CF8(int,int,void *),func_002ACBC8(void *,int);
extern void func_002A7750(void *,int,int),func_002E59F8(int),func_0029F338(void *),func_002A0F48(void *);
extern char *func_0029EFD0(int);
extern void func_00282CC0(void *,void *,void *),func_00282CF0(void *,void *,void *),func_002AD6F0(void *,void *,void *,void *);
extern float func_002AA3A8(void *,void *,float,float,float,float);
extern int func_002E5DA0(int,int,void *,int);
#define I(p,o) (*(int *)((p)+(o)))
#define F(p,o) (*(float *)((p)+(o)))
#define P(p,o) (*(char **)((p)+(o)))
#define STOP_SOUND() { handle=I(ctx,0x88); if(handle!=-1 && P(D_001886D4+handle*0x70,0x14)==obj && D_001886D4[handle*0x70]) func_002E59F8(handle); I(ctx,0x88)=-1; }
#define START_SOUND() if(!func_002E59B0(obj,I(ctx,0x88))) I(ctx,0x88)=func_002E5CF8(0,4,obj)
#define SET_ACTIVE(s) func_002A7750(obj,s,-1); I(P(ctx,0x9C),0x78)=0x8000DF2A; func_002E5DA0(0,0,obj,0x8A1); I(P(ctx,0x9C),0x98)=0
void func_L00_003D0008(char *obj) {
    struct { Vec old,rotation,delta,offset; } frame;
    char *ctx=P(obj,0x68),*child,*made;
    unsigned int brightness;
    int value,handle;
    qcopy(&frame.old,obj+0x10); qcopy(&frame.rotation,obj+0xF0);
    switch((unsigned char)obj[0x20]) {
    case 0:
        I(ctx,0x5C)|=1; qcopy(ctx+0x60,obj+0x10); obj[0x20]=1;
        if(!I(ctx,0x90)) { F(ctx,0x94)=F(ctx,0x68); F(ctx,0x98)=F(ctx,0x8C); I(ctx,0x80)=0; }
        else { I(ctx,0x80)=1; F(ctx,0x94)=F(ctx,0x8C); F(ctx,0x98)=F(ctx,0x68); }
        I(ctx,0x84)=0; I(ctx,0x88)=-1;
        made=func_0029EFD0(0xC16); P(ctx,0x9C)=made;
        if(!made) { func_0029F338(obj); return; }
        made[0x30]=obj[0x30]; *(short *)(P(ctx,0x9C)+0x32)=*(short *)(obj+0x32); P(ctx,0x9C)[0x31]=1;
        *(long long *)(P(ctx,0x9C)+0x38)=*(long long *)(obj+0x38);
        child=P(ctx,0x9C); qcopy(child+0x10,obj+0x10); F(child,0x18)+=0.25f;
        frame.delta.f[0]=func_00283180(F(obj,0xF8)); frame.delta.f[1]=func_00283198(F(obj,0xF8)); frame.delta.f[2]=0;
        child=P(ctx,0x9C)+0x10; func_00282CC0(child,child,&frame.delta);
        func_002A0F48(P(ctx,0x9C)); F(ctx,0xA0)=func_002A7940(); break;
    case 1:
        F(ctx,0xA0)=func_00283B98(F(ctx,0xA0),0.10471977f);
        value=func_00283CF0((func_00283198(F(ctx,0xA0))*4.0f-3.0f)*208.0f);
        if(value>208) value=208; else if(value<80) value=80;
        brightness=value; I(P(ctx,0x9C),0x78)=brightness<<16|brightness<<8|0x80000000|brightness;
        if(func_L00_00324120((int)P(ctx,0x9C))) {
            if(!I(ctx,0x80)) { SET_ACTIVE(3); }
            else { func_002A7750(obj,2,-1); I(P(ctx,0x9C),0x98)=0; I(P(ctx,0x9C),0x78)=0x8000DF2A; func_002E5DA0(0,0,obj,0x8A1); }
            START_SOUND();
        }
        if(func_00282C48(F(obj,0x18)-D_00189EA0.f[2])>6.0f && !I(ctx,0x80) && func_00282E80(obj+0x10,&D_00189EA0)<25.0f) { START_SOUND(); SET_ACTIVE(3); }
        else if(func_00282C48(F(obj,0x18)-D_00189EA0.f[2])>6.0f && I(ctx,0x80)==1) { START_SOUND(); SET_ACTIVE(2); }
        break;
    case 2:
        qcopy(&frame.delta,obj+0x10); frame.delta.f[2]=F(ctx,0x94);
        if(func_00282E48(obj+0x10,&frame.delta)>0.25f) { func_002AA3A8(obj+0x18,ctx+0xA8,frame.delta.f[2],0.02f,0.3f,0.10000001f); ++I(ctx,0x84); break; }
        if(!func_L00_00324120((int)P(ctx,0x9C)) && (func_00282E80(obj+0x10,&D_00189EA0)>2.0f || F(obj,0x18)>D_00189EA0.f[2])) {
            I(ctx,0x80)=0; STOP_SOUND(); func_002A7750(obj,1,-1); I(P(ctx,0x9C),0x78)=0x808C8C8C; I(P(ctx,0x9C),0x98)=I(P(P(ctx,0x9C),0x24),0x10);
        } else { if(I(ctx,0x84)>0) { func_002E5CF8(1,0,obj); I(ctx,0x84)=0; } STOP_SOUND(); }
        break;
    case 3:
        if(F(obj,0x18)>F(ctx,0x98)) {
            if(F(obj,0x18)-D_00189EA0.f[2]<1.8f && D_00189EA0.f[2]<F(obj,0x18)) {
                if(func_002ACBC8(&D_00189EA0,I(ctx,0xA4))) break;
                func_002AA3A8(obj+0x18,ctx+0xA8,F(ctx,0x98),0.02f,0.3f,0.10000001f);
            } else func_002AA3A8(obj+0x18,ctx+0xA8,F(ctx,0x98),0.0016666667f,0.0033333334f,0.10000001f);
            ++I(ctx,0x84); break;
        }
        if(!func_L00_00324120((int)P(ctx,0x9C)) && (func_00282E80(obj+0x10,&D_00189EA0)>2.0f || F(obj,0x18)>D_00189EA0.f[2])) {
            I(ctx,0x80)=1; STOP_SOUND(); func_002A7750(obj,1,-1); I(P(ctx,0x9C),0x78)=0x808C8C8C; I(P(ctx,0x9C),0x98)=I(P(P(ctx,0x9C),0x24),0x10); I(ctx,0x84)=0;
        } else { if(I(ctx,0x84)>0) { func_002E5CF8(1,0,obj); I(ctx,0x84)=0; } STOP_SOUND(); }
        break;
    }
    func_00282CF0(&frame.delta,obj+0x10,&frame.old);
    func_002AD6F0(ctx+0x20,&frame.delta,&frame.rotation,obj+0xF0);
    qcopy(P(ctx,0x9C)+0x10,obj+0x10);
    frame.offset.f[0]=func_00283180(F(obj,0xF8)); frame.offset.f[1]=func_00283198(F(obj,0xF8)); frame.offset.f[2]=0;
    child=P(ctx,0x9C)+0x10; func_00282CC0(child,child,&frame.offset); F(P(ctx,0x9C),0x18)+=0.25f;
}
