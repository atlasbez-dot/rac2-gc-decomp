/* 25 October 2026 approved-helper experiment; original C below is preserved.
 * Trial profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses -g
 * Trial checks: us: 0/28; us2: 0/27; pal: 0/27.
 * 1624/1628 bytes with the correct 0x210 frame. Approved qcopy reproduces the four source-object copy pairs, but initial FPR/GPR scheduling and resident-object base lifetime still differ. A truthful typed prefix was 1612 bytes and did not close the body.
 * Reopen: Independent evidence for resident-base lifetime or source-parameter/FPR scheduling; the centrally audited scoped callee and its real two integer arguments must remain.
 * No exact, linked or native-runtime credit is claimed.
 */

/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -mno-split-addresses -g.
 * Prior worker coverage: US 0/28; final scoped-ref source unmeasured in US2/PAL.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Manual reconstruction with qualified per-placement call identity.
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   -mno-split-addresses -g.
   Final source is 1628 bytes, frame0x210, but US matches0/28; the first
   real difference is the argument/FPR move at+0x24. Nine bounded trials
   preceded the independently qualified scoped-ref test, which also failed.
   ref_002FDF40_00 preserves the two actual integer arguments29,1 at+0x1A8.
   Its bootstub/levelcallee identity variation and unsigned32 zero/one
   result were audited centrally across82 US/US2/PAL carrying placements;
   caller ignores that result. No extra FP or stack arguments are required.
   Before the scoped-ref correction, final US2/PAL checks were0/27 each;
   the final scoped-ref source was checked only for US after that test failed.
   Source position is16bytes; every basis/rotation here is a genuine48-byte
   three-row matrix. Allocation and resident-base lifetime differences remain.
   Reopen only with a new measured lifetime/declaration mechanism, not another
   flag sweep. No exact-match or native-behavior credit is claimed.
*/
/* Screened, not matched in wave 13 (worker g3): 50 call(s), 1 $gp-relative small-data access(es), MMI words [10 pairs] (the lq/sq family, which mode(TI) reaches), float constants [none]. The body is straight-line code
   whose register allocation and the materialisation of its constant addresses have to be
   reproduced word for word; no C was written in this wave. */

typedef unsigned char u8;
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
extern char D_00189E20[];
extern int D_001A8CA0 __attribute__((sda)), D_001A8CA4;
extern unsigned int D_00138320;
extern float D_001B5570[12], D_001B5340[4];
extern void func_00282D30(void *,void *,float);
extern void func_002AFFD8(char *,char *,int);
extern unsigned int ref_002FDF40_00(int,int);
extern void func_00282F20(void *,void *,float);
extern float func_00282DB0(void *,void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282DD8(void *,void *,void *);
extern float func_00283198(float), func_00283180(float);
extern void func_00283958(void *,void *);
extern void func_00283738(void *,void *,void *);
extern float func_00282DF0(void *);
extern float func_002A7798(float);
extern void func_00283098(void *,void *,void *);
extern void func_00282CC0(void *,void *,void *);
extern int func_002AB1F0(u8 *);

void func_002FDF40(Vector *output, Vector *origin, char *targetObject,
                   char *sourceObject, float minimum, float maximum,
                   float speed, float acceleration)
{
    Vector projected, temporary, normal, target;
    Vector displacement, correction, originProjection, targetProjection;
    Vector gravity, working, sourcePosition;
    float sourceBasis[12];
    Vector quaternion, axis, forward;
    float orientedBasis[12], rotation[12];
    Vector testVector;
    float duration, reciprocal, angle, projection, planeOffset, factor, reach;
    float *targetData;
    if(sourceObject) {
        sourcePosition.q=*(Quad *)(sourceObject+0x10);
        *(Quad *)(sourceBasis+0)=*(Quad *)(sourceObject+0xc0);
        *(Quad *)(sourceBasis+4)=*(Quad *)(sourceObject+0xd0);
        *(Quad *)(sourceBasis+8)=*(Quad *)(sourceObject+0xe0);
    } else {
        char *heroObject=*(char **)(D_00189E20+0x2290);
        sourcePosition.q=*(Quad *)(heroObject+0x10);
        *(Quad *)(sourceBasis+0)=*(Quad *)(D_00189E20+0x730);
        *(Quad *)(sourceBasis+4)=*(Quad *)(D_00189E20+0x740);
        *(Quad *)(sourceBasis+8)=*(Quad *)(D_00189E20+0x750);
    }
    output->f[0]=1.0f; output->f[1]=0.0f; output->f[2]=0.0f; output->f[3]=0.0f;
    if(*(short *)(D_00189E20+0x348)!=0 && D_001A8CA4==0)
        func_00282D30(&normal,*(char **)(D_00189E20+0x2290)+0xe0,-1.0f);
    else func_002AFFD8((char *)&sourcePosition,(char *)&normal,0);
    reach=maximum;
    if(!targetObject) {
        if(*(int *)(D_00189E20+0x2294)==1) ref_002FDF40_00(29,1);
        if((D_00138320&4)==0 || D_00189E20[0x22bc]!=0) {
            func_00283098(output,output,sourceBasis);
        } else {
            func_00282F20(&forward,D_001B5570,1.0f);
            func_00282D30(&temporary,&normal,func_00282DB0(&forward,&normal));
            func_00282CF0(&projected,&forward,&temporary);
            func_00282F20(&projected,&projected,1.0f);
            func_00282DD8(&axis,&forward,&projected);
            angle=func_00282DB0(&forward,&projected)*0.5f;
            func_00282D30(&quaternion,&axis,func_00283198(angle));
            quaternion.f[3]=func_00283180(angle);
            func_00283958(&quaternion,rotation);
            func_00283738(orientedBasis,rotation,D_001B5570);
            planeOffset=-func_00282DB0(&sourcePosition,&normal);
            func_00282F20(&testVector,D_001B5570,1.0f);
            projection=func_00282DB0(&normal,&testVector);
            if(projection>0.0f) {
                factor=(func_00282DB0(&normal,D_001B5340)+planeOffset)/projection;
                func_00282D30(&testVector,&testVector,factor);
                func_00282CF0(&testVector,D_001B5340,&testVector);
                func_00282CF0(&testVector,&testVector,D_001B5340);
                func_00282D30(&temporary,&normal,func_00282DB0(&testVector,&normal));
                func_00282CF0(&projected,&testVector,&temporary);
                reach=func_00282DF0(&projected);
                if(maximum<reach) reach=maximum;
                else if(reach<minimum) reach=minimum;
            }
            reach=maximum*func_002A7798(reach/maximum);
            func_00283098(output,output,orientedBasis);
        }
        func_00282F20(output,output,reach);
        func_00282CC0(&target,output,&sourcePosition);
    } else {
        if((unsigned)(*(unsigned short *)(targetObject+0xaa)-0xa8d)>1 ||
            (targetData=(float *)func_002AB1F0((u8 *)targetObject))==0 || !(targetData[0]>0.0f)) {
            target.q=*(Quad *)(targetObject+0x10);
        } else if(D_001A8CA0==0 && *(short *)(D_00189E20+0x348)==0) {
            target.q=*(Quad *)(targetObject+0x10);
            target.f[2]+=targetData[4];
        } else {
            func_00282D30(&quaternion,targetObject+0xe0,targetData[4]);
            func_00282CC0(&target,targetObject+0x10,&quaternion);
        }
    }
    func_00282CF0(&displacement,&target,origin);
    func_00282D30(&temporary,&normal,func_00282DB0(&displacement,&normal));
    func_00282CF0(&projected,&displacement,&temporary);
    func_00282F20(output,&projected,speed);
    duration=func_00282DF0(&projected)/speed;
    reciprocal=1.0f/duration;
    func_00282D30(&originProjection,&normal,func_00282DB0(origin,&normal));
    func_00282D30(&targetProjection,&normal,func_00282DB0(&target,&normal));
    func_00282D30(&gravity,&normal,acceleration*duration*duration*0.5f);
    func_00282CF0(&working,&originProjection,&targetProjection);
    func_00282CC0(&working,&working,&gravity);
    func_00282D30(&working,&working,-1.0f);
    func_00282D30(&correction,&working,reciprocal);
    func_00282CC0(output,output,&correction);
}
