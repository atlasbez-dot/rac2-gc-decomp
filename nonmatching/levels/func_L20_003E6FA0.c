/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses.
 * Reported final C / retail: 1756 / 1804 bytes; size equality is not a match.
 * us: 0/1 placements; 1756/1804 bytes.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: Three source/profile trials; final 1756 versus 1804 bytes with the correct 0x320 frame. The full target scan, both close-target tests, cone test, temporary collider suppression and restoration are retained. Qualified qcopy removes the old transfer wall; lifetimes and allocation remain different.
 * Reopening condition: Recover target-loop pointer/cache lifetimes and the lexical scope of the collider restoration walk.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical manual summary: Earlier wide-copy and small-data experiments did not achieve equality. The current manual draft retains the measured residual without artificial dependencies or aliases. The original map is retained privately; no extracted instruction, opcode, address or generated table is reproduced here. */

/* Not matched, 2026-10-23.
 * Three source/profile trials; final 1756 versus 1804 bytes with the correct 0x320 frame. The full target scan, both close-target tests, cone test, temporary collider suppression and restoration are retained. Qualified qcopy removes the old transfer wall; lifetimes and allocation remain different.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses
 * Final us check: func_L20_003E6FA0: 0 of 1 places match (src/levels/20_yeedil/L20_003E6FA0-g8.c); exit 1.
 * This source has not passed a linked build or a runtime test.
 */
#include "common.h"
typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
extern u8 D_00189E20[];
extern u8 *D_L20_001FBEE0[];
extern int D_L20_001A8FF0;
extern int D_L20_001A8FF4 __attribute__((sda));
extern float D_0018A144;
extern float D_L20_001B0310 __attribute__((sda));
extern float D_L20_001B0314 __attribute__((sda));
extern u8 *D_L20_001C0418;
extern Vector D_L20_001C0420;
extern void func_00282D30(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282CF0(void *,void *,void *);
extern int func_002761F8(void *,void *,int,void *,void *);
extern int func_002AB1F0(u8 *);
extern float func_00283248(float,float);
extern float func_00282E80(void *,void *);
extern float func_00283C80(float,float);
extern float func_00282E48(void *,void *);
extern float func_00282C48(float);
extern float func_00282DB0(void *,void *);
extern float func_00282DF0(void *);
extern float func_002831B0(float);
extern void func_002AF000(float *,float,float,float);
extern float func_00283CE0(int);

u8 *func_L20_003E6FA0(u8 *object,Vector *position,float *yaw,float *pitch)
{
    Vector origin,forward,eye;
    u8 *disabled[128];
    Vector target,aim,difference,projection;
    u8 *state=*(u8 **)(object+0x68);
    u8 *selected,*candidate,*details,*hit;
    int disabledCount,index,attempt,valid,close;
    float best=D_L20_001B0314;
    float heading,vertical,angle,distance,checkAngle,dot,length,extent,cone;
    origin.q=position->q;
    func_00282D30(&forward,(*(u8 **)(D_00189E20+0x2290))+0xe0,0.5f);
    selected=0;
    func_00282CC0(&eye,(*(u8 **)(D_00189E20+0x2290))+0x10,&forward);
    if (func_002761F8(&eye,&origin,6,(*(u8 **)(D_00189E20+0x2290)),0)) {
        origin.q=D_L20_001C0420.q;
        return 0;
    }
    disabledCount=0;index=0;
    while ((candidate=D_L20_001FBEE0[index])!=0) {
        if (candidate[0x20]==254 || candidate[0x20]==253 || *(s16 *)(candidate+0xaa)==0xe7d || *(s16 *)(candidate+0xaa)==0xeb0) goto next;
        target.q=*(Quadword *)(candidate+0x10);
        details=(u8 *)func_002AB1F0(candidate);
        if (!details || details[0xe]==3) goto next;
        func_00282D30(&aim,candidate+0xe0,*(float *)(details+0x10));
        func_00282CC0(&target,&target,&aim);
        if (!candidate || !*(int *)(candidate+0x24) || *(s16 *)(*(u8 **)(candidate+0x24)+0x46)!=5) goto next;
        heading=func_00283248(target.f[0]-origin.f[0],target.f[1]-origin.f[1]);
        vertical=func_00283248(func_00282E80(&origin,&target),target.f[2]-origin.f[2]);
        angle=func_00283C80(*yaw,heading);
        distance=func_00282E48(&origin,&target);
        close=0;
        if (!D_L20_001A8FF0 && !(*(s16 *)(D_00189E20+0x348)) && !D_L20_001A8FF4) {
            if (distance<2.5f) {
                checkAngle=func_00283C80(*(float *)((*(u8 **)(D_00189E20+0x2290))+0xf8),func_00283248(*(float *)(candidate+0x10)-*(float *)(D_00189E20+0x80),*(float *)(candidate+0x14)-*(float *)(D_00189E20+0x84)));
                if (checkAngle<1.0471977f && func_00282C48(origin.f[2]-target.f[2])<2.0f) close=1;
            }
        } else if (distance<2.5f) {
            func_00282CF0(&difference,candidate+0x10,(*(u8 **)(D_00189E20+0x2290))+0x10);
            dot=func_00282DB0(&difference,(*(u8 **)(D_00189E20+0x2290))+0xe0);
            if (func_00282C48(dot)<2.0f) {
                func_00282D30(&projection,(*(u8 **)(D_00189E20+0x2290))+0xe0,dot);
                func_00282CF0(&difference,&difference,&projection);
                dot=func_00282DB0(&difference,(*(u8 **)(D_00189E20+0x2290))+0xc0);
                length=func_00282DF0(&difference);
                if (length!=0.0f && 1.5707964f-func_002831B0(dot/length)<1.0471977f) close=1;
            }
        }
        if (close && !func_002761F8(&origin,&target,6,(*(u8 **)(D_00189E20+0x2290)),0)) {
            selected=candidate;*pitch=-vertical;*yaw=heading;goto restore;
        }
        if ((distance<=best || candidate==*(u8 **)(state+0x10)) && distance<=D_L20_001B0314) {
            func_002AF000(aim.f,distance,*yaw,*pitch+*(float *)(D_00189E20+0x324)*0.5f);
            func_00282CC0(&aim,&aim,&origin);
            cone=2.0f*func_002831B0(func_00282E48(&aim,&target)/(distance+distance));
            if (D_L20_001B0310*0.017453294f<cone) {
                details=(u8 *)func_002AB1F0(candidate);
                if (details) {
                    extent=func_00283CE0(details[10])*0.125f;
                    checkAngle=func_002831B0(extent/distance);
                    if (extent<distance) {cone-=checkAngle;if (cone<0.0f) cone=0.0f;}
                }
            }
            valid=1;
            if (cone<D_L20_001B0310*0.017453294f) {
                difference.q=origin.q;
                attempt=0;
                for (;;) {
                    if (!func_002761F8(&difference,&target,6,object,0)) break;
                    if (++attempt>6) break;
                    hit=D_L20_001C0418;
                    if (!hit) {valid=0;break;}
                    if (*(s16 *)(hit+0xaa)!=0xe7d && *(s16 *)(hit+0xaa)!=0xeb0) {
                        if (hit!=candidate) valid=0;
                        break;
                    }
                    disabled[disabledCount++]=hit;
                    *(int *)(hit+0x98)=0;
                    if (disabledCount>=128) break;
                    difference.q=D_L20_001C0420.q;
                }
                if (valid) {
                    *pitch=-vertical;
                    if (angle<0.17453295f) *yaw=heading;
                    selected=candidate;best=distance;
                    if (candidate==*(u8 **)(state+0x10)) goto restore;
                }
            }
        }
next:
        index++;
    }
restore:
    for(index=0;index<disabledCount;index++) {
        candidate=disabled[index];
        *(int *)(candidate+0x98)=*(int *)(*(u8 **)(candidate+0x24)+0x10);
    }
    return selected;
}
