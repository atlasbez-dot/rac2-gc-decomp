/* Retention review: external whole-object extents remain incomplete.
 * Declaration-only corrections below were not recompiled. Measurements in the
 * retained header describe the original private trial, not this revised text.
 */
/* Retained manual C reconstruction; not linked and not matching.
 * Profile: -O2 -G0 -ffunction-sections -mno-split-addresses -ffast-math
 * Local tools/check.py measurements: us: 1084 compiled bytes, 0/1 placements, exit 1; us2: 1084 compiled bytes, 0/1 placements, exit 1; pal: catalogue absent (exit 1).
 * Retail extent: 1072 bytes. No exact-C credit and no full build performed.
 * Residual: 1084 versus 1072 bytes (+12), with the correct 0xB0 frame under no-split-addresses. Scalar clamp/call setup and register scheduling differ. Eight live FP inputs f12-f19 are retained.
 * Reopen: Reopen after identifying the remaining scalar clamp/max and call-setup scheduling differences using compiler RTL, retaining all eight FP inputs and measured literals.
 * Arrays with unknown total extent remain incomplete. Pointer-offset views do
 * not establish the full sizes or ownership of game records.
 */
/* Steers toward the target, clamps speed, then resolves the proposed movement. */
typedef unsigned char u8;
#define I32(p,o) (*(int *)((p)+(o)))
#define F32(p,o) (*(float *)((p)+(o)))
extern float func_00283248(float,float),func_00282E20(void *),func_00282E80(void *,void *);
extern void func_00282CF0(void *,void *,void *),func_00282CC0(void *,void *,void *);
struct family_27f9_object;
extern float func_002A7CA0(struct family_27f9_object *,float *,float,float,float,float);
extern float func_00283180(float),func_00283198(float);
extern float func_L01_003BD560(void *,float,float,float,float);
extern float D_00189EA0[];
extern void func_002AF000(float *,float,float,float);
extern int func_002A8240(void *,void *,int,float,float,float);
extern float func_L01_00310BC0(float *,float,float,float,float,float);
extern int func_L01_003165E8(char *,int,char *,char *,char *);
int func_L01_003BE058(u8 *object,float turn,float turn2,float rate,float acceleration,float brake,float maxspeed,float altitude,float deadzone)
{
    u8 *state=*(u8 **)(object+0x68);
    float direction[4] __attribute__((aligned(16)));
    float proposed[4] __attribute__((aligned(16)));
    float angle, distance, step, cap, pitch, height;
    int flags=0;
    angle=func_00283248(F32(state,0x1e0)-F32(object,0x10),F32(state,0x1e4)-F32(object,0x14));
    func_00282CF0(direction,state+0x1e0,object+0x10);
    distance=func_00282E20(direction)-deadzone;
    if(distance<0.0f) distance=0.0f;
    cap=acceleration*0.00027777778450399637f;
    step=acceleration*(distance*0.00027777778450399637f);
    if(cap<step) step=cap;
    F32(state,0x240)+=step;
    if(distance<F32(state,0x240)*10.0f)
        F32(state,0x240)-=brake*F32(state,0x240);
    if(distance<deadzone) flags=8;
    cap=maxspeed*F32(state,0x28c)*0.01666666753590107f;
    if(cap<F32(state,0x240)) F32(state,0x240)=cap;
    else if(F32(state,0x240)<-cap) F32(state,0x240)=-cap;
    func_002A7CA0((struct family_27f9_object *)object,(float *)(state+0x244),angle,
        turn*0.000004848137450608192f,turn2*0.000004848137450608192f,rate*0.0002908882452175021f);
    proposed[0]=func_00283180(angle)*F32(state,0x240)*10.0f;
    proposed[1]=func_00283198(angle)*F32(state,0x240)*10.0f;
    proposed[2]=0.0f;
    func_00282CC0(proposed,proposed,object+0x10);
    height=F32(state,0x27c);
    if(object[0x20]==8 && height<D_00189EA0[2]) height=D_00189EA0[2];
    proposed[2]=func_L01_003BD560(proposed,F32(state,0x1d8)+2.0f,F32(state,0x1d8)-3.0f,height,F32(state,0x288));
    if(func_00282E80(object+0x10,D_00189EA0)<5.0f && D_00189EA0[2]<proposed[2]) proposed[2]=D_00189EA0[2];
    proposed[2]+=altitude;
    pitch=func_00283248(func_00282E80(object+0x10,proposed),proposed[2]-F32(object,0x18));
    func_002AF000((float *)(state+0x1f0),F32(state,0x240),F32(object,0xf8),pitch);
    if(object[0x20]!=8) F32(state,0x1f8)*=0.4f;
    else if((unsigned int)(object[0x95]-1)<2) {
        I32(state,0x1f0)=0;
        I32(state,0x1f4)=0;
    }
    flags|=func_002A8240(object,state+0x1f0,0,0.0f,0.3f,0.0f);
    F32(object,0xf4)=func_L01_00310BC0((float *)(state+0x248),F32(object,0xf4),-pitch,
        0.0017453294713050127f,0.0008726647356525064f,0.0008726647356525064f);
    if(I32(state,0x238)>0 && func_L01_003165E8((char *)(object+0x10),I32(state,0x210),*(char **)(state+0x218),*(char **)(state+0x21c),(char *)-1)==0) flags|=7;
    if(flags&7) func_002A7CA0((struct family_27f9_object *)object,(float *)(state+0x244),angle,
        turn*0.000014544411897077225f,turn2*0.000004848137450608192f,rate*0.0008726647356525064f);
    return flags;
}
