/* Readable C reconstruction, 23 October 2026. Profile: -O2 -G8 -ffunction-sections -frac2-qcopy
 * -frac2-qcopy-barrier.
 * us: 2164/2220 bytes, 0/7 carrying placements.
 * us2: canonical name absent.
 * pal: canonical name absent.
 * One complete control state machine with the retail 0x50 frame. Callback identities, true
 * floating helper returns, both transition arguments and all child updates are preserved.
 * func_L00_00303530 receives the live variant in a1 unless negative, when zero is supplied.
 * One canonical actor-table pointer represents retail mixed GP/absolute reads. Block/store
 * order and pointer lifetimes remain; reopen on typed state/control-flow evidence.
 * The historical screening below predates this C and is superseded; por/quadword instructions
 * alone are not evidence of handwritten assembly. No linked qualification was run.
 */

/* Superseded historical screen, retained for provenance. */
/* func_L02_00410450 - 2220 bytes, 7 place(s), level 02_maktar_nebula,
   retail at 0x00410450. Screened with tools/w10_screen.py: 30 call(s)
   [func_L02_00410E58@004104AC, func_L02_004114A0@004105D0,
   func_002E5CF8@00410604, func_L00_002D40A0@00410624,
   func_002A8C28@00410658, func_L00_002D40F0@004106CC,
   func_L00_002C42E0@0041076C, func_L00_002E6CF0@00410820,
   func_002AA2E8@00410838, func_002A7750@00410860,
   func_L00_002B9D60@004108F8, func_002E5CF8@0041092C,
   func_L02_00410D00@0041095C, func_002B3868@0041096C,
   func_L00_002E6CF0@004109FC, func_002AA2E8@00410A14,
   func_002AA548@00410A9C, func_L02_00410D00@00410AB4,
   func_002B3868@00410AC4, func_L02_00410D00@00410AE4,
   func_L00_002C8BA8@00410B34, func_002E5CF8@00410B68,
   func_L00_002E6EF8@00410B78, func_002B3868@00410B88,
   func_L00_00303530@00410C2C, func_L00_00303530@00410C40,
   func_L00_002B9D60@00410C78, func_L02_00410D00@00410C80,
   func_002A7750@00410C90, func_L00_002E6EF8@00410CA0]; data addresses
   materialised [0x2a0000, 0x190000, 0x140000, 0x10000, 0x39910000,
   0x39910000, 0x3ff90000, 0x190000, 0x410000, 0x3d880000, 0x1b0000,
   0x1a0000, 0x1a0000, 0x3e4c0000, 0x3ff90000, 0x3ff90000, 0x410000,
   0x3d880000, 0x39910000, 0x39910000, 0x3c880000, 0x190000, 0x3ca30000,
   0x3f990000, 0x410000, 0x410000, 0x190000, 0x3ca30000, 0xbe4c0000,
   0x3ff90000, 0x3e4c0000, 0x410000]; float constants [0x1a0000, 0x3fc00000,
   0x41a00000, 0x3f800000, 0x3f800000, 0x3e800000, 0x3f800000, 0x3f800000,
   0x3f800000, 0x3f800000]; $gp-relative small data: no   saves: -; callee-
   saved registers saved [-]; words plain C cannot emit [LQ/SQ
   78620000@0x047c, LQ/SQ 7FA20000@0x0480, LQ/SQ 78620000@0x07fc, LQ/SQ
   7FA20000@0x0800]. Head: addiu $sp, $sp, -0x50 ; sd $s2, 0x20($sp) ; sd
   $s0, 0x10($sp) ; daddu $s2, $a0, $zero ; sd $s1, 0x18($sp) ; sd $s3,
   0x28($sp). Not matched in this wave: the 128-bit copy needs an `lq`/`sq`
   pair; plain C reaches it only through a `mode(TI)` local, and this cc1
   folds the destination offset into the `sq` where retail materialises the
   pointer first. What would unblock it: the exact source expression tree,
   so this cc1 picks the same registers in the same order. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
typedef struct {
    int primary,secondary,key,secondaryKey,reserved10;
    u8 *children[3];
    float orbitA,orbitB,rateA,rateB;
    int reserved30;
    float timer;
    int handle;
    float opacity;
    int variant;
} OrbitState;
typedef void (*DrawCallback)(void *);
extern void func_L02_00410E58(u8 *);
extern void func_L02_00410D00(u8 *);
extern void func_L02_004114A0(u8 *);
extern void func_L02_00410F68(u8 *);
extern void func_L02_00411530(u8 *);
extern int func_002E5CF8(int,int,char *);
extern void func_L00_002D40A0(Quad *,int,float);
extern int func_002A8C28(float,float,float,u8 *,void *,int,int,int,int);
extern int func_L00_002D40F0(void);
extern int func_L00_002C42E0(int,int);
extern void func_L00_002E6CF0(DrawCallback,void *);
extern void func_L00_002E6EF8(DrawCallback,void *);
extern float func_002AA2E8(float *,float,float);
extern void func_002A7750(u8 *,u8,int);
extern void func_L00_002B9D60(void *,void *,int,int);
extern int func_002B3868(u8 *);
extern float func_002AA548(float *,float *,float,float,float,float);
extern void func_L00_002C8BA8(int);
extern void func_L00_00303530(int,int);
extern int D_001A79F0 __attribute__((sda));
extern u8 D_0019B2E8[];
extern u8 D_00189E20[];
extern u32 D_00138324;
extern int D_L02_001A8FB4 __attribute__((sda));
extern u8 *D_L02_001B359C __attribute__((sda));
extern float D_L02_001B1A58 __attribute__((sda));
extern float D_L02_001B1A5C __attribute__((sda));
extern float D_L02_001B1A60 __attribute__((sda));

/* Run the control's activation, orbit and captured-object transition states. */
void func_L02_00410450(u8 *object)
{
    OrbitState *state=*(OrbitState **)(object+0x68);
    u8 **slot;
    u8 *actor,*data;
    int left,answer;
    float *value,*velocity,goal;
    Vector position;
    switch(object[0x20]) {
    case 0:
        object[0x30]=0xFF;object[0x20]=1;
        func_L02_00410E58(object);
        func_L02_00410D00(object);
        break;
    case 1:
        if(state->key>=0 && !(D_0019B2E8[state->key+D_001A79F0*16]&0x80)) {
            *(int *)(object+0x98)=0;
            *(u16 *)(object+0x34)=(*(u16 *)(object+0x34)&0xEFFF)|0x41;
            slot=state->children;left=2;
            do {
                *(u16 *)(*slot+0x34)|=0x41;
                *(u16 *)(*slot+0x34)&=0xEFFF;
                *(int *)(*slot+0x98)=0;
                slot++;
            } while(--left>=0);
            break;
        }
        *(u16 *)(object+0x34)=(*(u16 *)(object+0x34)&0xFFBE)|0x1000;
        *(int *)(object+0x98)=*(int *)(*(u8 **)(object+0x24)+0x10);
        slot=state->children;left=2;
        do {
            *(u16 *)(*slot+0x34)&=0xFFBE;
            *(u16 *)(*slot+0x34)|=0x1000;
            *(int *)(*slot+0x98)=*(int *)(*(u8 **)(*slot+0x24)+0x10);
            slot++;
        } while(--left>=0);
        if(state->primary!=-1 && *(u8 **)(D_00189E20+0x33C)==object) {
            if(*(short *)(D_00189E20+0x34E)) goto propagate;
            func_L02_004114A0(object);
            if((D_00138324&0x10) && D_L02_001A8FB4==11) {
                func_002E5CF8(0,0,(char *)object);
                object[0x20]=2;state->rateA=0;state->rateB=0;
                func_L00_002D40A0((Quad *)(object+0x10),0,*(float *)(object+0xF8));
                func_002A8C28(1.5f,20.0f,1.0f,object,object+0x10,0x10000,0,1,0);
            }
        }
        break;
    case 2:
        *(u16 *)(object+0x34)=(*(u16 *)(object+0x34)&0xFFBE)|0x1000;
        *(int *)(object+0x98)=*(int *)(*(u8 **)(object+0x24)+0x10);
        slot=state->children;left=2;
        do {
            *(u16 *)(*slot+0x34)&=0xFFBE;*(u16 *)(*slot+0x34)|=0x1000;
            *(int *)(*slot+0x98)=*(int *)(*(u8 **)(*slot+0x24)+0x10);slot++;
        } while(--left>=0);
        answer=func_L00_002D40F0();goal=1;
        if(state->orbitA<1.0f) {value=&state->orbitA;velocity=&state->rateA;}
        else if(1.0f<=state->orbitB) {
            if(D_L02_001A8FB4!=11 || state->orbitA<=0.25f) {
                if(answer==2) {func_L00_002C42E0(0x6F,1);state->timer=1.95f;object[0x20]=3;}
                else if(answer==0) object[0x20]=4;
            }
            func_L02_00410D00(object);
            break;
        } else {value=&state->orbitB;velocity=&state->rateB;}
        goto adjust;
    case 3:
        *(u16 *)(object+0x34)=(*(u16 *)(object+0x34)&0xFFBE)|0x1000;
        *(int *)(object+0x98)=*(int *)(*(u8 **)(object+0x24)+0x10);
        slot=state->children;left=2;
        do {
            *(u16 *)(*slot+0x34)&=0xFFBE;*(u16 *)(*slot+0x34)|=0x1000;
            *(int *)(*slot+0x98)=*(int *)(*(u8 **)(*slot+0x24)+0x10);slot++;
        } while(--left>=0);
        if(state->timer==0.0f) {
            D_00189E20[0x22B5]=1;
            if(state->handle<0) {
                actor=D_L02_001B359C+state->primary*0x100;
                if(state->secondary!=-1 && (D_0019B2E8[state->secondaryKey+D_001A79F0*16]&0x80)) actor=D_L02_001B359C+state->secondary*0x100;
                data=*(u8 **)(actor+0x68);
                position.q=*(Quad *)(actor+0x10);position.f[2]+=0.2f;
                func_L00_002B9D60(&position,actor+0xF0,0,1);
                actor[0x20]=4;
                *(float *)(data+0x34)=0;*(float *)(data+0x28)=0;*(float *)(data+0x2C)=0;
                *(float *)(data+0x24)=1;*(float *)(data+0x20)=1;
                func_002E5CF8(1,0,(char *)actor);
                object[0x20]=1;state->orbitA=0;state->orbitB=0;state->rateA=0;state->rateB=0;state->timer=1.95f;
                func_L02_00410D00(object);
            } else func_002A7750(object,5,-1);
        } else {
            func_L00_002E6CF0((DrawCallback)func_L02_00410F68,object);
            func_002AA2E8(&state->timer,0,0.06666667f);
        }
        break;
    case 4:
        func_002B3868(object);
        *(u16 *)(object+0x34)=(*(u16 *)(object+0x34)&0xFFBE)|0x1000;
        *(int *)(object+0x98)=*(int *)(*(u8 **)(object+0x24)+0x10);
        slot=state->children;left=2;
        do {
            *(u16 *)(*slot+0x34)&=0xFFBE;*(u16 *)(*slot+0x34)|=0x1000;
            *(int *)(*slot+0x98)=*(int *)(*(u8 **)(*slot+0x24)+0x10);slot++;
        } while(--left>=0);
        if(state->timer<1.95f) {
            func_L00_002E6CF0((DrawCallback)func_L02_00410F68,object);
            func_002AA2E8(&state->timer,1.95f,0.06666667f);
        } else {
            goal=0;
            if(state->orbitB>0.0f) {value=&state->orbitB;velocity=&state->rateA;}
            else if(state->orbitA>0.0f) {value=&state->orbitA;velocity=&state->rateB;}
            else {object[0x20]=1;func_L02_00410D00(object);break;}
            goto adjust;
        }
        func_L02_00410D00(object);
        break;
    adjust:
        func_002AA548(value,velocity,goal,D_L02_001B1A58*0.00027777778f,D_L02_001B1A5C*0.00027777778f,D_L02_001B1A60*0.016666668f);
        func_L02_00410D00(object);
        break;
    case 5:
        if(func_002B3868(object)) state->opacity=1;
        state->opacity-=0.02f;D_00189E20[0x22B5]=1;
        if(state->opacity<=-0.2f) {
            actor=D_L02_001B359C+state->primary*0x100;
            actor[0x20]=6;object[0x20]=1;state->timer=1.95f;
            state->orbitA=0;state->orbitB=0;state->rateA=0;state->rateB=0;
            func_L00_00303530(state->handle,state->variant<0?0:state->variant);
            position.q=*(Quad *)(actor+0x10);position.f[2]+=0.2f;
            func_L00_002B9D60(&position,actor+0xF0,0x6F,1);
            func_L02_00410D00(object);
            func_002A7750(object,1,-1);
        }
        func_L00_002E6EF8((DrawCallback)func_L02_00411530,object);
        break;
    case 6:
        if(func_002B3868(object)) {
            state->orbitA=1;state->orbitB=1;func_L02_00410D00(object);state->opacity=0;
        }
        state->opacity+=0.02f;D_00189E20[0x22B5]=1;
        if(state->opacity>=1.2f) {
            func_L00_002C8BA8(0);object[0x20]=4;
            state->rateA=0;state->rateB=0;state->timer=0;state->orbitB=1;state->orbitA=1;
            func_002E5CF8(1,0,(char *)object);
        }
        func_L00_002E6EF8((DrawCallback)func_L02_00411530,object);
        break;
    }
propagate:
    slot=state->children;left=2;
    do {
        if(*slot) *(u16 *)(*slot+0x34)=(*(u16 *)(*slot+0x34)&0xFF7F)+(*(u16 *)(object+0x34)&0x80);
        slot++;
    } while(--left>=0);
}
