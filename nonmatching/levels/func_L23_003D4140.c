/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 0/1; PAL 0/1.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Nonmatching manual reconstruction.
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   1740 bytes, expected 1804; frame 0x320 agrees, all three releases fail.
   Explicit ordered FP predicates preserve the unordered paths but emit the same code.
   Reopen with a measured selection-loop allocation or branch-shape hypothesis.
*/
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
#define F(p,o) (*(float *)((u8 *)(p)+(o)))
#define I(p,o) (*(int *)((u8 *)(p)+(o)))
extern float D_L23_001B0094 __attribute__((sda)),D_L23_001B0090 __attribute__((sda));
extern u8 *D_0018C0B0 NOT_SDA;
extern float D_00189EA0[4];
extern s16 D_0018A168 NOT_SDA;
extern float D_0018A144 NOT_SDA;
extern int D_L23_001A8FF0 NOT_SDA,D_L23_001A8FF4 __attribute__((sda));
extern u8 *D_L23_001FC560[];
extern u8 *D_L23_001C0A98 NOT_SDA;
extern float D_L23_001C0AA0[4];
extern void func_00282D30(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern int func_002761F8(void *,void *,int,void *,void *);
extern s32 func_002AB1F0(u8 *);
extern float func_00283248(float,float);
extern float func_00282E80(void *,void *);
extern float func_00283C80(float,float);
extern float func_00282E48(void *,void *);
extern void func_00282CF0(void *,void *,void *);
extern float func_00282DB0(void *,void *);
extern float func_00282C48(float);
extern float func_00282DF0(void *);
extern float func_002831B0(float);
extern void func_002AF000(float *,float,float,float);
extern float func_00283CE0(s32);
u8 *func_L23_003D4140(u8 *object,float *position,float *yaw,float *pitch)
{
    float origin[4],advance[4],start[4];
    u8 *hidden[128];
    float targetPoint[4],offset[4],ray[4],projection[4];
    u8 *state=*(u8 **)(object+0x68),*candidate,*properties,*best=0,*hit;
    float bestDistance=D_L23_001B0094,heading,elevation,turn,distance,angle,perpendicular,length,extent;
    int index,hiddenCount=0,attempts,closeEnough,clear,i;
    *(Quad *)origin=*(Quad *)position;
    func_00282D30(advance,D_0018C0B0+0xE0,0.5f);
    func_00282CC0(start,D_0018C0B0+0x10,advance);
    if (func_002761F8(start,origin,6,D_0018C0B0,0)) return 0;
    for (index=0;(candidate=D_L23_001FC560[index])!=0;index++) {
        if (candidate[0x20]==254 || candidate[0x20]==253 || *(s16 *)(candidate+0xAA)==0xE7D || *(s16 *)(candidate+0xAA)==0xEB0) continue;
        *(Quad *)targetPoint=*(Quad *)(candidate+0x10);
        properties=(u8 *)func_002AB1F0(candidate);
        if (!properties || properties[0xE]==3) continue;
        func_00282D30(offset,candidate+0xE0,F(properties,0x10));
        func_00282CC0(targetPoint,targetPoint,offset);
        if (!candidate || !*(u8 **)(candidate+0x24) || *(s16 *)(*(u8 **)(candidate+0x24)+0x46)!=5) continue;
        closeEnough=0;
        heading=func_00283248(targetPoint[0]-origin[0],targetPoint[1]-origin[1]);
        length=func_00282E80(origin,targetPoint);
        elevation=func_00283248(length,targetPoint[2]-origin[2]);
        turn=func_00283C80(*yaw,heading);
        distance=func_00282E48(origin,targetPoint);
        if (!D_L23_001A8FF0 && D_0018A168==0 && D_L23_001A8FF4==0) {
            if (distance<2.5f) {
                angle=func_00283248(F(candidate,0x10)-D_00189EA0[0],F(candidate,0x14)-D_00189EA0[1]);
                if (func_00283C80(F(D_0018C0B0,0xF8),angle)<1.0471977f && func_00282C48(origin[2]-targetPoint[2])<2.0f) closeEnough=1;
            }
        } else if (distance<2.5f) {
            func_00282CF0(ray,candidate+0x10,D_0018C0B0+0x10);
            perpendicular=func_00282DB0(ray,D_0018C0B0+0xE0);
            if (func_00282C48(perpendicular)<2.0f) {
                func_00282D30(projection,D_0018C0B0+0xE0,perpendicular);
                func_00282CF0(ray,ray,projection);
                perpendicular=func_00282DB0(ray,D_0018C0B0+0xC0);
                length=func_00282DF0(ray);
                if (length!=0.0f && 1.5707964f-func_002831B0(perpendicular/length)<1.0471977f) closeEnough=1;
            }
        }
        if (closeEnough && !func_002761F8(origin,targetPoint,6,D_0018C0B0,0)) {
            best=candidate;
            *pitch=-elevation;
            *yaw=heading;
            break;
        }
        if (!((distance<=bestDistance || candidate==*(u8 **)(state+0x10)) && distance<=D_L23_001B0094)) continue;
        func_002AF000(offset,distance,*yaw,*pitch+D_0018A144*0.5f);
        func_00282CC0(offset,offset,origin);
        length=func_00282E48(offset,targetPoint);
        angle=func_002831B0(length/(distance+distance));
        angle+=angle;
        if (angle>D_L23_001B0090*0.017453294f) {
            properties=(u8 *)func_002AB1F0(candidate);
            if (properties) {
                extent=func_00283CE0(properties[0xA]);
                length=func_002831B0((extent*0.125f)/distance);
                if (extent*0.125f<distance) {
                    angle-=length;
                    if (angle<0.0f) angle=0.0f;
                }
            }
        }
        if (!(angle<D_L23_001B0090*0.017453294f)) continue;
        clear=1;
        attempts=0;
        *(Quad *)ray=*(Quad *)origin;
        while (func_002761F8(ray,targetPoint,6,object,0)) {
            if (++attempts>6) break;
            hit=D_L23_001C0A98;
            if (!hit) { clear=0; break; }
            if (*(s16 *)(hit+0xAA)!=0xE7D && *(s16 *)(hit+0xAA)!=0xEB0) {
                if (hit!=candidate) clear=0;
                break;
            }
            hidden[hiddenCount++]=hit;
            I(hit,0x98)=0;
            if (hiddenCount>127) break;
            *(Quad *)ray=*(Quad *)D_L23_001C0AA0;
        }
        if (clear) {
            *pitch=-elevation;
            if (turn<0.17453295f) *yaw=heading;
            best=candidate;
            bestDistance=distance;
            if (candidate==*(u8 **)(state+0x10)) return candidate;
        }
    }
    for (i=0;i<hiddenCount;i++) I(hidden[i],0x98)=I(*(u8 **)(hidden[i]+0x24),0x10);
    return best;
}
