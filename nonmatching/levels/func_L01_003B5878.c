/* Retained complete manual C reconstruction; nonmatching, not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections -fno-expensive-optimizations -frac2-zero-ti-por
 * Final checks: US 0/1 and US2 0/1; 4968/4972 bytes, frame 0x150 in C and retail.
 * PAL: this canonical name is absent from both catalogues, not a pass.
 * AAA00 retains its established float return. Correcting only the old void return
 * changes no object bytes in this caller. Both used eight-entry const label tables,
 * all 64-byte matrix outputs and the dispatcher full 64-bit return contract remain.
 * The caller explicitly consumes only status bits 0/1 from the low return word.
 * Raw state-word snapshots preserve the observed LW/SW transfers without FP conversion.
 * Retail phase/fallthrough order, NaN-sensitive guards and RNG draw order are preserved.
 * The frame counter is one mutable MACRO_ADDR object: pursuit-weave reads it absolutely,
 * pursuit-leave reads the GP form. One declaration reproduces both measured accesses;
 * the old explicit SDA alias forced GP access in both phases and is removed.
 * The group pointer and attack-animation word retain their measured SDA forms.
 * The local target-to-delta transfer stays ordinary C: retail separates its stack LQ/SQ
 * around the rotation call. The subsequent matrix/target selection keeps its real lifetimes.
 * Dispatcher payload and resident/query total extents are unknown, so only opaque context
 * and incomplete external storage with measured prefix views are declared.
 * Separate scalar locals retain the measured stack slots after the vector/matrix workspace.
 * This recovers the retail F21 zero across the scale call, store and duration comparison
 * at +0x270..+0x2F8. The 0x150 frame and the full matrix extents remain unchanged.
 * Remaining: airborne F0/F1 roles, branch displacement/joins, target-address roles and
 * final easing setup differ. Equal size in an earlier variant was not a match.
 * Reopen with independent target/control lifetime or CFG evidence; preserve the
 * measured access identities, complete tables/matrices, call banks/stack and store order.
 * Bank-preserving interleavings were measured, not prohibited or assumed to solve this caller.
 * Normal/dump-enabled compilation agrees. No native-port or strict linked equality is claimed.
 */
#include "common.h"

typedef int Quadword __attribute__((mode(TI)));
typedef struct {
    Quadword previous_position, delta, target;
    Quadword rotation[4], inverse[4], object_inverse[4];
} MotionWorkspace;
struct family_27f9_object { unsigned char reserved[248]; float heading; };
typedef unsigned char QwenRecovery_84e23fd54f9f_AbiByte16;
/* The dispatcher context is opaque here; its payload extent is not established. */
typedef struct DispatchContext Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext;
typedef unsigned long Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchFlags;

extern void func_L01_003B53C8(u8 *);
extern void func_L01_003B4C58(u8 *);
extern float func_002AA2E8(float *,float,float);
extern int func_00282948(int *);
extern int func_002A7820(int,int);
extern int func_002A77E0(int);
extern void func_002A7470(u8 *,int,int,int);
extern void func_002A7750(u8 *,int,int);
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
extern float func_002AAA00(float *,float *,int,float,float,float,float);
extern int func_002A8D70(float,float,float,void *,int,int,int,int,int);
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
extern u8 D_00189E20[];
#define HERO_TARGET ((HeroTargetPrefix *)D_00189E20)
/* Mixed absolute/GP reads of the same mutable frame counter. */
extern int D_L01_001B2088 MACRO_ADDR;
extern int D_L01_001AFDB0 __attribute__((sda));
extern u8 *D_L01_001B255C __attribute__((sda));
extern u8 *D_L01_001B264C NOT_SDA;
extern u8 D_L01_001BF900[];
#define COLLISION_QUERY ((CollisionQueryPrefix *)D_L01_001BF900)
extern Quadword D_L01_001AC5A0;


#define STATE_INT(o) (*(int *)(state+(o)))
#define STATE_UINT(o) (*(unsigned int *)(state+(o)))
#define STATE_FLOAT(o) (*(float *)(state+(o)))
#define STATE_POINTER(o) (*(u8 **)(state+(o)))

/* Updates this creature's idle, pursuit, airborne, attack and recovery phases. */
void func_L01_003B5878(u8 *object)
{
    /* These used compiler-owned label tables preserve the two measured dispatches. */
    static void *const phases[8]={&&phase_idle,&&phase_wait,&&phase_airborne,&&phase_pursuit,
                           &&phase_attack,&&phase_dispatch,&&phase_removed,&&phase_removed};
    static void *const actions[8]={&&pursuit_idle,&&pursuit_wait,&&pursuit_weave,&&pursuit_done,
                            &&pursuit_straight,&&pursuit_done,&&pursuit_group,&&pursuit_leave};
    MotionWorkspace local;
    float duration, weave, straight, pursuit;
    u8 *state;
    u8 *target;
    float speed,frame,angle,pitch,yaw;
    int animation,first,i;
    unsigned int phase,action;
    /* The callee returns 64 bits; this caller consumes only low-word bits 0/1. */
    u32 flags;

    qcopy(&local.previous_position, object+0x10);
    state=*(u8 **)(object+0x68);
    if (object[0x95]) func_L01_003B53C8(object);
    phase=object[0x95];
    if (phase<8) goto *phases[phase];
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
        qcopy(state+0x2E0, state+0x2D0);
        break;
    case 3:
        if (func_00282948((int *)(state+0x360))) {
            func_L01_003B57A8(object,&local.target);
            func_00282CF0(&local.delta,&local.target,object+0x10);
            if (func_00282DF0(&local.delta)*0.03333333507180214f < 0.13333334028720856f)
                speed=func_00282DF0(&local.delta)*0.03333333507180214f;
            else speed=0.13333334028720856f;
            func_00282F20(&local.delta,&local.delta,speed);
            duration=0.0f;
            ((float *)&local.delta)[2]=func_L00_0031CDD0(object+0x10,&local.target,&duration,speed,-0.004999999888241291f);
            qcopy(state+0x2F0, &local.delta);
            qcopy(state+0x2E0, &local.target);
            func_002E5CF8(5,0,(char *)object);
            if (object[0x43]!=3) func_002A7470(object,3,0,10);
            if (duration>0.0f) *(float *)(object+0x48)=38.0f/duration;
            func_002A7750(object,1,2);
        }
        break;
    }
    if (object[0x20]!=3 && STATE_INT(0x310)!=-1 && object[0x95]==1) {
        STATE_UINT(0x398)=STATE_UINT(0x390);
        STATE_INT(0x39C)=0;
        if (STATE_INT(0x244)==1 || STATE_INT(0x330)) {
            *(float *)(object+0x18)=STATE_FLOAT(0x34C);
            STATE_INT(0x39C)=0;
            STATE_UINT(0x398)=STATE_UINT(0x390);
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
    STATE_UINT(0x14C)=STATE_UINT(0x30C);
    qcopy(state+0x200, object+0x10);
    object[0xBC]=1;
    STATE_INT(0x330)=240;
    func_002B6318(object);
    if (object[0x43]!=8) func_002A7470(object,8,0,10);
    goto finish_attack;

phase_pursuit:
    action=object[0x20];
    if (action<8) goto *actions[action];
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
    weave=func_00283198(func_002ABB18(func_00283CE0(D_L01_001B2088)*0.01163553074002266f))*0.8726646900177002f;
    if (func_00282E80(object+0x10,state+0x230)<4.75f) weave=0.0f;
    func_L01_003B4AD0(object,state+0x2E0,&weave);
    func_L01_003B50C8((char *)object,1,-1.0f);
    target=STATE_POINTER(0x240);
    if (func_00282E80(object+0x10,target+0x10)<3.75f) {
        target=STATE_POINTER(0x240);
        if (func_00282C48(*(float *)(object+0x18)-*(float *)(target+0x18))<0.5f) {
            target=STATE_POINTER(0x240);
            angle=func_00283248(*(float *)(target+0x10)-*(float *)(object+0x10),*(float *)(target+0x14)-*(float *)(object+0x14));
            if (func_00283C80(*(float *)(object+0xF8),angle)<0.174532949924469f) {
                qzero(state+0x1B0);
                state[0x35C]=0;
                if (object[0x43]!=10) func_002A7470(object,10,D_L01_001AFDB0,func_002A7820(16,22));
                func_002A7750(object,1,4);
            }
        }
    }
    goto pursuit_done;
pursuit_straight:
    straight=0.0f;
    if (STATE_INT(0x310)==-1) func_L01_003B4AD0(object,state+0x2D0,&straight);
    else func_L01_003B4AD0(object,D_L01_001B264C+STATE_INT(0x310)*128+0x30,&straight);
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
    STATE_UINT(0x398)=STATE_UINT(0x390);
    STATE_FLOAT(0x39C)=STATE_FLOAT(0x388);
    func_L01_003B49D8(object,state+0x200);
    func_L01_003B50C8((char *)object,1,-1.0f);
    if (STATE_INT(0x244)==1 && (STATE_INT(0x38C)==-1 ||
        D_L01_001B255C[STATE_INT(0x38C)*256+0xBC])) func_002A7750(object,7,-1);
    goto pursuit_done;
pursuit_leave:
    pursuit=func_00283198(func_002ABB18(func_00283CE0(D_L01_001B2088)*0.01163553074002266f))*0.8726646900177002f;
    qcopy(state+0x2E0, D_L01_001B264C+STATE_INT(0x380)*128+0x30);
    func_L01_003B4AD0(object,state+0x2E0,&pursuit);
    func_L01_003B50C8((char *)object,1,-1.0f);
    if ((STATE_UINT(0x1A4)&0x80) && !object[0x31]) {
        func_0029F338(object);
        return;
    }

pursuit_done:
    if (object[0x95]!=3) goto mirror_hero;
    if (object[0x20]==4) goto mirror_hero;
    if (object[0x20]==7) goto mirror_hero;
    if (object[0x20]==6) goto mirror_hero;
    STATE_UINT(0x398)=STATE_UINT(0x394);
    STATE_FLOAT(0x39C)=STATE_FLOAT(0x388);
    if (STATE_INT(0x244)==1 || STATE_INT(0x330)) {
        if (object[0x21]!=255 && **(int **)(state+0x36C)!=*(short *)(object+0xB2) &&
            **(int **)(state+0x370)!=*(short *)(object+0xB2)) goto cancel_pursuit;
        target=STATE_POINTER(0x240);
        if (!(func_00282C48(*(float *)(object+0x18)-*(float *)(target+0x18))<1.0f)) goto cancel_pursuit;
        STATE_INT(0x330)=240;
        object[0xBC]=1;
        STATE_UINT(0x14C)=STATE_UINT(0x30C);
        if (object[0x20]==2) goto copy_pursuit_target;
        if (object[0x21]!=255 && **(int **)(state+0x33C)>1) goto pursuit_distance;
        if (STATE_INT(0x334)) goto pursuit_distance;
        if (!(func_00282E80(object+0x10,STATE_POINTER(0x240)+0x10)<14.0f)) goto pursuit_distance;
        qcopy(state+0x2E0, STATE_POINTER(0x240)+0x10);
        animation=19;
        if (*(u16 *)(object+0xB2)&1) animation=8;
        func_002A7470(object,animation,0,func_002A7820(20,30));
        func_L01_003B4C20(object);
        func_002A7750(object,2,-1);
        goto pursuit_distance;
    }
copy_pursuit_target:
    qcopy(state+0x2E0, STATE_POINTER(0x240)+0x10);
    goto pursuit_distance;
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
    goto pursuit_distance;
mirror_hero:
    if (STATE_POINTER(0x240)==HERO_TARGET->object)
        qcopy(state+0x2E0, HERO_TARGET->position);
pursuit_distance:
    if (func_00282E80(object+0x10,STATE_POINTER(0x240)+0x10)<3.5f) {
        target=STATE_POINTER(0x240);
        if (func_00282C48(*(float *)(object+0x18)-*(float *)(target+0x18))<0.5f) {
            target=STATE_POINTER(0x240);
            angle=func_00283248(*(float *)(target+0x10)-*(float *)(object+0x10),*(float *)(target+0x14)-*(float *)(object+0x14));
            if (func_00283C80(*(float *)(object+0xF8),angle)<0.523598849773407f) {
                qzero(state+0x1B0);
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
    if (target) {
        if (!func_002A77E0(7)) {
            target=STATE_POINTER(0x240);
            angle=func_00283248(*(float *)(target+0x10)-*(float *)(object+0x10),*(float *)(target+0x14)-*(float *)(object+0x14));
            func_002B5278(object,angle);
        } else {
            target=STATE_POINTER(0x240);
            angle=func_00283248(*(float *)(target+0x10)-*(float *)(object+0x10),*(float *)(target+0x14)-*(float *)(object+0x14));
            func_002AAA00((float *)(object+0xF8),(float *)(state+0x1C4),0,angle,STATE_FLOAT(0x124),STATE_FLOAT(0x128),STATE_FLOAT(0x12C));
        }
    } else if (!func_002A77E0(7)) func_002B5258((char *)object);
    frame=func_0029F530((char *)object);
    if (object[0x42]==10 && frame>=18.0f && frame<=25.0f) {
        for (i=0;i<5;i++) {
            if (func_002A8D70(0.5f,(float)state[0x34],1.0f,object,i,0x4000001,0,1,0) &&
                COLLISION_QUERY->object==HERO_TARGET->object) state[0x35C]=1;
        }
    }
    if (!(frame>30.0f) && (object[0x42]==10 || object[0x43]==10)) goto phase_done;
    if (state[0x35C]) {
        STATE_INT(0x334)=100;
        if (object[0x43]!=11) func_002A7470(object,11,0,func_002A7820(25,30));
    } else {
        STATE_INT(0x334)=40;
        if (object[0x43]!=8) func_002A7470(object,8,0,func_002A7820(25,30));
    }
    state[0x35C]=0;
    func_L01_003B4BD8(object);
finish_attack:
    STATE_UINT(0x398)=STATE_UINT(0x394);
    STATE_FLOAT(0x39C)=STATE_FLOAT(0x388);
    func_002A7750(object,1,3);
    goto phase_done;

phase_dispatch:
    flags=(u32)func_002B1C20(object,(Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *)(state+0x60));
    if (flags&1) func_002A7750(object,0,7);
    else if (flags&2) {
        *(int *)(object+0x98)=*(int *)(*(u8 **)(object+0x24)+0x10);
        func_L01_003B4480(object);
        func_L01_003B4BD8(object);
        if (func_00278E78()==3) {
            if (object[0x43]!=4) func_002A7470(object,4,0,110);
            func_002A7750(object,0,6);
        } else {
            STATE_UINT(0x398)=STATE_UINT(0x394);
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
        if (STATE_POINTER(0x198) && !func_L00_0031BE88((char *)STATE_POINTER(0x198)))
            qcopy(&local.target, &D_L01_001AC5A0);
        else func_00282F20(&local.target,state+0x160,1.0f);
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
