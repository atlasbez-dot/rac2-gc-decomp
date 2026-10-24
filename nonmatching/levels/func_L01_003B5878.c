/*
 * Retained complete reconstruction, 23 October 2026. USA v1.01 and v2.00: 4992/4972 bytes, 0/1
 * placement each. Canonical row absent from PAL. No matching or strict-build credit is claimed.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -fno-expensive-
 * optimizations.
 * Six bounded meaningful trials: default 4996 bytes; cached dispatch indices and moving the
 * state load after the measured initial position copy gave 4988. Disabling GCSE gave 4968 with
 * different saved GPR roles. Preserving animation reads before RNG draws and a NaN-sensitive
 * frame guard gave 4992. Disabling expensive optimizations gave 4984 and recovered the retail
 * 0x150 frame/save banks; truthful resident/collision prefix views gave the retained 4992. The
 * last null-callback type qualification does not change the verdict.
 * Remaining differences include branch/call scheduling, the first helper's redundant a0 move,
 * and mixed absolute/GP accesses to the same frame counter. No artificial argument, volatile
 * qualifier, stack padding or address alias was added to force them. The two eight-entry
 * dispatch tables were read from retail, including repeated/default destinations; their source
 * label arrays follow the existing computed-goto pattern.
 * The 64-byte matrices, 16-byte vectors, complete 64-bit dispatch flags, independent RNG draw
 * order, and live GPR/FP helper inputs were checked. An independent read-only ABI review found
 * no missing live input, stack tail or consumed return-bank mismatch. Ignored returns of marker
 * helpers remain unqualified. A8D70 retains the current canonical void* formal while this caller
 * supplies its measured integer selector. The nullable callback of 3E9CF8 is represented as
 * callable here, but its original return declaration is unknown.
 * Reopen with independently supported control-flow, original data-layout or live-range evidence.
 * Do not repeat equivalent source forms, invent callback/data identities, or reinterpret a
 * scheduling miss as handwritten assembly.
 */

#include "common.h"

typedef int Quadword __attribute__((mode(TI)));
typedef struct {
    Quadword previous_position, delta, target;
    Quadword rotation[4], inverse[4], object_inverse[4];
    float duration, weave, straight, pursuit;
} MotionWorkspace;
struct family_27f9_object { unsigned char reserved[248]; float heading; };
typedef unsigned char QwenRecovery_84e23fd54f9f_AbiByte16;
typedef struct {
    unsigned char reserved_00[0x18];
    unsigned char enabled, count, kind;
    unsigned char reserved_1b[0x65];
    unsigned char payload[1];
} Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext;
typedef unsigned long Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchFlags;

extern void func_L01_003B53C8(u8 *);
extern void func_L01_003B4C58(u8 *);
extern float func_002AA2E8(float *,float,float);
extern int func_00282948(int *);
extern int func_002A7820(int,int);
extern int func_002A77E0(int);
extern void func_002A7470(u8 *,int,int,int);
extern void func_002A7750(u8 *,u8,int);
extern void func_L01_003B49D8(u8 *,void *);
extern int func_L01_003B4AD0(u8 *,void *,float *);
extern void func_L01_003B57A8(u8 *,void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282CC0(void *,void *,void *);
extern float func_00282DF0(void *);
extern void func_00282F20(void *,void *,float);
extern float func_L00_0031CDD0(void *,void *,float *,float,float);
extern int func_002E5CF8(int,int,char *);
extern float func_0029F530(char *);
extern float func_00283248(float,float);
extern float func_002A7CA0(struct family_27f9_object *,float *,float,float,float,float);
extern float func_00282C48(float);
extern int func_002B6318(unsigned char *);
extern int func_001163B0(void);
extern void func_L01_003B50C8(char *,int,float);
extern void func_002B5258(char *);
extern void func_002B5278(QwenRecovery_84e23fd54f9f_AbiByte16 *,float);
extern float func_00283CE0(int);
extern float func_002ABB18(float);
extern float func_00283198(float);
extern float func_00282E80(void *,void *);
extern float func_00283C80(float,float);
extern int func_L01_003B4C20(u8 *);
extern void func_L01_003B4BD8(u8 *);
extern void func_002AAA00(float *,float *,int,float,float,float,float);
extern int func_002A8D70(float,float,float,void *,void *,int,int,int,int);
extern Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchFlags func_002B1C20(void *,Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *);
extern void func_0029F338(void *);
extern void func_L01_003B4480(u8 *);
extern int func_00278E78(void);
extern void func_L01_003B5290(u8 *);
extern void func_002A6C58(u8 *,int,int);
/* This call supplies a null callback. The callback receives the object; its original
   return declaration and the helper's ignored return remain unqualified. */
extern void func_L01_003E9CF8(u8 *,int,void (*)(u8 *));
extern void func_00283410(void *,void *);
extern void func_00283698(void *,void *);
extern int func_L00_0031BE88(char *);
extern void func_00283098(void *,void *,void *);
extern void func_L01_003B5310(u8 *);
/* Measured prefixes preserve the resident and collision-query field relationships. */
typedef struct {
    u8 prefix[0x80];
    float position[4];
    u8 rest[0x2290-0x90];
    u8 *object;
} HeroTargetPrefix;
typedef struct { u8 prefix[0x18]; u8 *object; } CollisionQueryPrefix;
extern HeroTargetPrefix D_00189E20;
extern int D_L01_001B2088;
extern int D_L01_001AFDB0;
extern u8 *D_L01_001B255C;
extern u8 *D_L01_001B264C NOT_SDA;
extern CollisionQueryPrefix D_L01_001BF900;
extern Quadword D_L01_001AC5A0;
extern void *D_L01_002A4570[];
extern void *D_L01_002A4590[];

#define STATE_INT(o) (*(int *)(state+(o)))
#define STATE_UINT(o) (*(unsigned int *)(state+(o)))
#define STATE_FLOAT(o) (*(float *)(state+(o)))
#define STATE_POINTER(o) (*(u8 **)(state+(o)))

/* Updates this creature's idle, pursuit, airborne, attack and recovery phases. */
void func_L01_003B5878(u8 *object)
{
    /* Keep local labels reachable while dispatching through the measured retail tables. */
    static void *phases[]={&&phase_idle,&&phase_wait,&&phase_airborne,&&phase_pursuit,
                           &&phase_attack,&&phase_dispatch,&&phase_removed,&&phase_removed};
    static void *actions[]={&&pursuit_idle,&&pursuit_wait,&&pursuit_weave,&&pursuit_done,
                            &&pursuit_straight,&&pursuit_done,&&pursuit_group,&&pursuit_leave};
    MotionWorkspace local;
    u8 *state;
    u8 *target;
    float speed,frame,angle,pitch,yaw;
    int animation,first,i;
    unsigned int phase,action;
    Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchFlags flags;

    local.previous_position=*(Quadword *)(object+0x10);
    state=*(u8 **)(object+0x68);
    if (object[0x95]) func_L01_003B53C8(object);
    phase=object[0x95];
    if (phase<8) goto *D_L01_002A4570[phase];
    goto phase_done;

phase_idle:
    func_L01_003B4C58(object);
    goto phase_done;

phase_wait:
    switch (object[0x20]) {
    case 0:
        if (STATE_INT(0x32C)>=21)
            func_002AA2E8((float *)(state+0x214),0.03333333507180214f,0.0011111111380159855f);
        else func_002AA2E8((float *)(state+0x214),0.0f,0.0011111111380159855f);
        if (func_00282948((int *)(state+0x32C))) {
            if (object[0x43]!=4) func_002A7470(object,4,0,func_002A7820(18,24));
            func_002A7750(object,1,-1);
        }
        if (STATE_INT(0x308)!=-1) func_L01_003B49D8(object,state+0x200);
        break;
    case 1:
        if (object[0x60]&2) {
            STATE_INT(0x32C)=func_002A7820(120,400);
            if (object[0x43]!=4) func_002A7470(object,4,0,func_002A7820(20,30));
            func_002A7750(object,0,-1);
        }
        break;
    case 2:
        *(Quadword *)(state+0x2E0)=*(Quadword *)(state+0x2D0);
        break;
    case 3:
        if (func_00282948((int *)(state+0x360))) {
            func_L01_003B57A8(object,&local.target);
            func_00282CF0(&local.delta,&local.target,object+0x10);
            if (func_00282DF0(&local.delta)*0.03333333507180214f < 0.13333334028720856f)
                speed=func_00282DF0(&local.delta)*0.03333333507180214f;
            else speed=0.13333334028720856f;
            func_00282F20(&local.delta,&local.delta,speed);
            local.duration=0.0f;
            ((float *)&local.delta)[2]=func_L00_0031CDD0(object+0x10,&local.target,&local.duration,speed,-0.004999999888241291f);
            *(Quadword *)(state+0x2F0)=local.delta;
            *(Quadword *)(state+0x2E0)=local.target;
            func_002E5CF8(5,0,(char *)object);
            if (object[0x43]!=3) func_002A7470(object,3,0,10);
            if (local.duration>0.0f) *(float *)(object+0x48)=38.0f/local.duration;
            func_002A7750(object,1,2);
        }
        break;
    }
    if (object[0x20]!=3 && STATE_INT(0x310)!=-1 && object[0x95]==1) {
        STATE_FLOAT(0x398)=STATE_FLOAT(0x390);
        STATE_INT(0x39C)=0;
        if (STATE_INT(0x244)==1 || STATE_INT(0x330)) {
            *(float *)(object+0x18)=STATE_FLOAT(0x34C);
            STATE_INT(0x39C)=0;
            STATE_FLOAT(0x398)=STATE_FLOAT(0x390);
            func_002A7750(object,3,1);
        }
    }
    goto phase_done;

phase_airborne:
    if (object[0x42]!=3) goto phase_done;
    frame=func_0029F530((char *)object);
    if (!(frame>5.0f)) goto phase_done;
    func_00282CC0(object+0x10,object+0x10,state+0x2F0);
    angle=func_00283248(STATE_FLOAT(0x2E0)-*(float *)(object+0x10),STATE_FLOAT(0x2E4)-*(float *)(object+0x14));
    func_002A7CA0((struct family_27f9_object *)object,(float *)(state+0x1C4),angle,
                  STATE_FLOAT(0x124)*10.0f,STATE_FLOAT(0x134)*10.0f,STATE_FLOAT(0x12C)*10.0f);
    STATE_FLOAT(0x2F8)-=0.004999999888241291f;
    if (!(STATE_FLOAT(0x2F8)<0.0f)) goto phase_done;
    if (!(func_00282C48(*(float *)(object+0x18)-STATE_FLOAT(0x2E8)) < -STATE_FLOAT(0x2F8))) goto phase_done;
    *(int *)(object+0x98)=*(int *)(*(u8 **)(object+0x24)+0x10);
    STATE_FLOAT(0x14C)=STATE_FLOAT(0x30C);
    *(Quadword *)(state+0x200)=*(Quadword *)(object+0x10);
    object[0xBC]=1;
    STATE_INT(0x330)=240;
    func_002B6318(object);
    if (object[0x43]!=8) func_002A7470(object,8,0,10);
    goto finish_attack;

phase_pursuit:
    action=object[0x20];
    if (action<8) goto *D_L01_002A4590[action];
    goto pursuit_done;
pursuit_idle:
    if (STATE_INT(0x32C)>=21)
        func_002AA2E8((float *)(state+0x214),0.03333333507180214f,0.0011111111380159855f);
    else func_002AA2E8((float *)(state+0x214),0.0f,0.0011111111380159855f);
    if (func_00282948((int *)(state+0x32C))) {
        if (!object[0xBC]) {
            STATE_INT(0x32C)=180;
            animation=object[0x43];
            if (animation!=(func_001163B0()&1)) {
                animation=func_001163B0()&1;
                first=func_002A7820(30,40);
                func_002A7470(object,animation,0,first);
            }
        } else {
            STATE_INT(0x32C)=120;
            animation=object[0x43];
            if (animation!=(func_001163B0()&1)+6) {
                animation=(func_001163B0()&1)+6;
                first=func_002A7820(30,40);
                func_002A7470(object,animation,0,first);
            }
        }
        func_002A7750(object,1,-1);
    }
    func_L01_003B49D8(object,state+0x200);
    func_L01_003B50C8((char *)object,1,-1.0f);
    goto pursuit_done;
pursuit_wait:
    if (!func_002A77E0(7)) func_002B5258((char *)object);
    if (func_00282948((int *)(state+0x32C)) && (object[0x60]&2)) {
        STATE_INT(0x32C)=func_002A7820(120,400);
        animation=19;
        if (*(u16 *)(object+0xB2)&1) animation=8;
        func_002A7470(object,animation,0,func_002A7820(25,35));
        func_002A7750(object,0,-1);
    }
    goto pursuit_done;
pursuit_weave:
    local.weave=func_00283198(func_002ABB18(func_00283CE0(D_L01_001B2088)*0.01163553074002266f))*0.8726646900177002f;
    if (func_00282E80(object+0x10,state+0x230)<4.75f) local.weave=0.0f;
    func_L01_003B4AD0(object,state+0x2E0,&local.weave);
    func_L01_003B50C8((char *)object,1,-1.0f);
    target=STATE_POINTER(0x240);
    if (func_00282E80(object+0x10,target+0x10)<3.75f) {
        target=STATE_POINTER(0x240);
        if (func_00282C48(*(float *)(object+0x18)-*(float *)(target+0x18))<0.5f) {
            target=STATE_POINTER(0x240);
            angle=func_00283248(*(float *)(target+0x10)-*(float *)(object+0x10),*(float *)(target+0x14)-*(float *)(object+0x14));
            if (func_00283C80(*(float *)(object+0xF8),angle)<0.174532949924469f) {
                *(Quadword *)(state+0x1B0)=0;
                state[0x35C]=0;
                if (object[0x43]!=10) func_002A7470(object,10,D_L01_001AFDB0,func_002A7820(16,22));
                func_002A7750(object,1,4);
            }
        }
    }
    goto pursuit_done;
pursuit_straight:
    local.straight=0.0f;
    if (STATE_INT(0x310)==-1) func_L01_003B4AD0(object,state+0x2D0,&local.straight);
    else func_L01_003B4AD0(object,D_L01_001B264C+STATE_INT(0x310)*128+0x30,&local.straight);
    func_L01_003B50C8((char *)object,1,-1.0f);
    if ((object[0x60]&2) && (*(u64 *)(state+0x1A0)&0x18000000000ULL)!=0x10000000000ULL) {
        animation=object[0x43];
        if (animation!=(func_001163B0()&1)) {
            animation=func_001163B0()&1;
            first=func_002A7820(30,40);
            func_002A7470(object,animation,0,first);
        }
        func_002A7750(object,1,-1);
    }
    goto pursuit_done;
pursuit_group:
    STATE_FLOAT(0x398)=STATE_FLOAT(0x390);
    STATE_FLOAT(0x39C)=STATE_FLOAT(0x388);
    func_L01_003B49D8(object,state+0x200);
    func_L01_003B50C8((char *)object,1,-1.0f);
    if (STATE_INT(0x244)==1 && (STATE_INT(0x38C)==-1 ||
        D_L01_001B255C[STATE_INT(0x38C)*256+0xBC])) func_002A7750(object,7,-1);
    goto pursuit_done;
pursuit_leave:
    local.pursuit=func_00283198(func_002ABB18(func_00283CE0(D_L01_001B2088)*0.01163553074002266f))*0.8726646900177002f;
    *(Quadword *)(state+0x2E0)=*(Quadword *)(D_L01_001B264C+STATE_INT(0x380)*128+0x30);
    func_L01_003B4AD0(object,state+0x2E0,&local.pursuit);
    func_L01_003B50C8((char *)object,1,-1.0f);
    if ((STATE_UINT(0x1A4)&0x80) && !object[0x31]) {
        func_0029F338(object);
        return;
    }

pursuit_done:
    if (object[0x95]!=3 || object[0x20]==4 || object[0x20]==7 || object[0x20]==6) {
        if (STATE_POINTER(0x240)==D_00189E20.object)
            *(Quadword *)(state+0x2E0)=*(Quadword *)D_00189E20.position;
        goto pursuit_distance;
    }
    STATE_FLOAT(0x398)=STATE_FLOAT(0x394);
    STATE_FLOAT(0x39C)=STATE_FLOAT(0x388);
    if (STATE_INT(0x244)==1 || STATE_INT(0x330)) {
        if (object[0x21]!=255 && **(int **)(state+0x36C)!=*(short *)(object+0xB2) &&
            **(int **)(state+0x370)!=*(short *)(object+0xB2)) goto cancel_pursuit;
        target=STATE_POINTER(0x240);
        if (!(func_00282C48(*(float *)(object+0x18)-*(float *)(target+0x18))<1.0f)) goto cancel_pursuit;
        STATE_INT(0x330)=240;
        object[0xBC]=1;
        STATE_FLOAT(0x14C)=STATE_FLOAT(0x30C);
        if (object[0x20]==2) {
            *(Quadword *)(state+0x2E0)=*(Quadword *)(STATE_POINTER(0x240)+0x10);
            goto pursuit_distance;
        }
        if (object[0x21]!=255 && **(int **)(state+0x33C)>1) goto pursuit_distance;
        if (STATE_INT(0x334)) goto pursuit_distance;
        if (!(func_00282E80(object+0x10,STATE_POINTER(0x240)+0x10)<14.0f)) goto pursuit_distance;
        *(Quadword *)(state+0x2E0)=*(Quadword *)(STATE_POINTER(0x240)+0x10);
        animation=19;
        if (*(u16 *)(object+0xB2)&1) animation=8;
        func_002A7470(object,animation,0,func_002A7820(20,30));
        func_L01_003B4C20(object);
        func_002A7750(object,2,-1);
        goto pursuit_distance;
    }
cancel_pursuit:
    if (object[0x20]==2) {
        func_L01_003B4BD8(object);
        object[0xBC]=0;
        animation=object[0x43];
        if (animation!=(func_001163B0()&1)) {
            animation=func_001163B0()&1;
            first=func_002A7820(30,40);
            func_002A7470(object,animation,0,first);
        }
        func_002A7750(object,1,-1);
    }
pursuit_distance:
    if (func_00282E80(object+0x10,STATE_POINTER(0x240)+0x10)<3.5f) {
        target=STATE_POINTER(0x240);
        if (func_00282C48(*(float *)(object+0x18)-*(float *)(target+0x18))<0.5f) {
            target=STATE_POINTER(0x240);
            angle=func_00283248(*(float *)(target+0x10)-*(float *)(object+0x10),*(float *)(target+0x14)-*(float *)(object+0x14));
            if (func_00283C80(*(float *)(object+0xF8),angle)<0.523598849773407f) {
                *(Quadword *)(state+0x1B0)=0;
                state[0x35C]=0;
                if (object[0x43]!=10) func_002A7470(object,10,D_L01_001AFDB0,func_002A7820(8,12));
                func_002A7750(object,1,4);
            } else {
                target=STATE_POINTER(0x240);
                angle=func_00283248(*(float *)(target+0x10)-*(float *)(object+0x10),*(float *)(target+0x14)-*(float *)(object+0x14));
                func_002AAA00((float *)(object+0xF8),(float *)(state+0x1C4),0,angle,STATE_FLOAT(0x124),STATE_FLOAT(0x128),STATE_FLOAT(0x12C));
            }
        }
    }
    goto phase_done;

phase_attack:
    target=STATE_POINTER(0x240);
    if (!target) {
        if (!func_002A77E0(7)) func_002B5258((char *)object);
    } else if (!func_002A77E0(7)) {
        target=STATE_POINTER(0x240);
        angle=func_00283248(*(float *)(target+0x10)-*(float *)(object+0x10),*(float *)(target+0x14)-*(float *)(object+0x14));
        func_002B5278(object,angle);
    } else {
        target=STATE_POINTER(0x240);
        angle=func_00283248(*(float *)(target+0x10)-*(float *)(object+0x10),*(float *)(target+0x14)-*(float *)(object+0x14));
        func_002AAA00((float *)(object+0xF8),(float *)(state+0x1C4),0,angle,STATE_FLOAT(0x124),STATE_FLOAT(0x128),STATE_FLOAT(0x12C));
    }
    frame=func_0029F530((char *)object);
    if (object[0x42]==10 && frame>=18.0f && frame<=25.0f) {
        for (i=0;i<5;i++) {
            if (func_002A8D70(0.5f,(float)state[0x34],1.0f,object,(void *)i,0x4000001,0,1,0) &&
                D_L01_001BF900.object==D_00189E20.object) state[0x35C]=1;
        }
    }
    if (!(frame>30.0f) && (object[0x42]==10 || object[0x43]==10)) goto phase_done;
    if (!state[0x35C]) {
        STATE_INT(0x334)=40;
        if (object[0x43]!=8) func_002A7470(object,8,0,func_002A7820(25,30));
    } else {
        STATE_INT(0x334)=100;
        if (object[0x43]!=11) func_002A7470(object,11,0,func_002A7820(25,30));
    }
    state[0x35C]=0;
    func_L01_003B4BD8(object);
finish_attack:
    STATE_FLOAT(0x398)=STATE_FLOAT(0x394);
    STATE_FLOAT(0x39C)=STATE_FLOAT(0x388);
    func_002A7750(object,1,3);
    goto phase_done;

phase_dispatch:
    flags=func_002B1C20(object,(Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *)(state+0x60));
    if (flags&1) func_002A7750(object,0,7);
    else if (flags&2) {
        *(int *)(object+0x98)=*(int *)(*(u8 **)(object+0x24)+0x10);
        func_L01_003B4480(object);
        func_L01_003B4BD8(object);
        if (func_00278E78()==3) {
            if (object[0x43]!=4) func_002A7470(object,4,0,110);
            func_002A7750(object,0,6);
        } else {
            STATE_FLOAT(0x398)=STATE_FLOAT(0x394);
            STATE_FLOAT(0x39C)=STATE_FLOAT(0x388);
            STATE_INT(0x384)=-1;
            animation=19;
            if (*(u16 *)(object+0xB2)&1) animation=8;
            func_002A7470(object,animation,0,func_002A7820(18,24));
            if (func_002B6318(object)) func_002A7750(object,1,3);
            else func_002A7750(object,4,3);
        }
    }
    goto phase_done;

phase_removed:
    func_L01_003B5290(object);
    func_002A6C58(object,0,3);
    func_L01_003B4480(object);
    func_L01_003B50C8((char *)object,5,-1.0f);
    func_L01_003B4BD8(object);
    func_L01_003E9CF8(object,0,0);

phase_done:
    if ((unsigned int)(object[0x95]-3)<2) {
        local.target=0;
        ((float *)&local.target)[2]=*(float *)(object+0xF8);
        local.delta=local.target;
        func_00283410(local.rotation,&local.delta);
        func_00283698(local.inverse,local.rotation);
        func_00283698(local.object_inverse,object+0xC0);
        if (!STATE_POINTER(0x198) || func_L00_0031BE88((char *)STATE_POINTER(0x198)))
            func_00282F20(&local.target,state+0x160,1.0f);
        else local.target=D_L01_001AC5A0;
        func_00283098(&local.target,&local.target,local.inverse);
        yaw=func_00283248(((float *)&local.target)[2],((float *)&local.target)[0]);
        pitch=-func_00283248(((float *)&local.target)[2],((float *)&local.target)[1]);
        if (yaw>0.698131799697876f) yaw=0.698131799697876f;
        else if (yaw<-0.698131799697876f) yaw=-0.698131799697876f;
        if (pitch>0.698131799697876f) pitch=0.698131799697876f;
        else if (pitch<-0.698131799697876f) pitch=-0.698131799697876f;
        func_002AAA00((float *)(object+0xF4),(float *)(state+0x358),0,yaw,0.0017453294713050127f,0.0017453294713050127f,0.10471977293491364f);
        func_002AAA00((float *)(object+0xF0),(float *)(state+0x354),0,pitch,0.0017453294713050127f,0.0017453294713050127f,0.10471977293491364f);
    }
    func_L01_003B5310(object);
}
