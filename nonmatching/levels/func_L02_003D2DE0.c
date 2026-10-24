/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 5384 / 5412 bytes; size equality is not a match.
 * us: 0/1 placements; 5384/5412 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: 28 bytes short; frame 0x80 vs retail0x70. Extra saved s5 holds state+0x2c0 waypoint across case3 calls; retail rematerializes this pointer. Not an effect-tuning-base issue.
 * Reopening condition: Concrete lifetime/control-flow change avoiding the saved waypoint pointer, followed by exact comparison.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Nonmatching manual reconstruction of the first Maktar sentry state machine.
 * Retail US: 5412 bytes; final trial: 5384 bytes, 0/1 placements, exit 1.
 * US2 and PAL do not carry this canonical function in their catalogues.
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections -frac2-qcopy
 *          -frac2-qcopy-barrier.
 * Four bounded trials: qcopy/barrier 5384, qcopy 5380, ordinary copies 5236,
 * and the explicit waypoint view 5384. Final frame 0x80 differs from 0x70.
 * The extra s5 preserves state+0x2c0 across case-three calls; retail instead
 * rematerializes it. This is not the effect-tuning base. Reopen with a proven
 * local lifetime/control-flow change that removes that saved waypoint pointer.
 * All states, paired throw cases and the common final update are retained.
 * WaypointView and EffectTuning are partial measured views, not full layouts.
 * The callback and FC248 leaf declarations retain observed extra caller slots;
 * their current leaves ignore those slots, so no invented fixed ABI is used.
 */
typedef unsigned char u8;
typedef int Quadword __attribute__((mode(TI)));
typedef struct { u8 prefix[0x2C0]; float waypoint[4]; float previousPosition[4]; } WaypointView;
/* Partial current dispatch context; the payload's full extent is not inferred. */
typedef struct {
    u8 reserved_00[0x18]; u8 enabled, count, kind; u8 reserved_1b[0x65]; u8 payload[1];
} Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext;
typedef unsigned long Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchFlags;
typedef struct { u8 prefix[0x20]; float amount; int reserved24; int kind; int detail; } EffectTuning;
extern EffectTuning D_L02_001BA500;
extern float D_L02_001B3F58 __attribute__((sda));
extern float D_L02_001B01B0[4] __attribute__((sda));
extern float D_L02_001B01C0[4] __attribute__((sda));
extern float D_L02_001B01D0[4] __attribute__((sda));
extern int D_L02_001B01E0 __attribute__((sda));
extern int D_L02_001A903C;
extern char *D_0018C2BC;
extern u8 D_001A7A61;
extern float D_00189EA0[4];
extern void func_L02_003D4308(char *);
extern float func_00282E80(void *, void *);
extern float func_00282E48(void *, void *);
extern float func_00283248(float, float);
extern float func_0029F530(char *);
extern int func_002B3890(u8 *);
extern int func_002B3868(u8 *);
extern void *func_002B60B0(u8 *, float, float, float, float);
extern void func_L02_003D5B90(char *);
/* The retail callback site supplies a parent even though this leaf ignores it. */
extern int func_L00_0042AB40();
extern void func_002A7470(char *, int, int, int);
extern void func_002A7750(u8 *, u8, int);
extern void func_L02_003D4ED0(char *);
extern void func_L02_003D4FD0(char *, Quadword *, float, float);
extern float func_002A7878(float, float);
extern int func_002A77E0(int);
extern void func_L02_003D4A48(char *);
extern void func_L02_003DB880(char *);
extern void func_L02_003FC020(char *, char *);
extern void func_002B5258(char *);
extern void func_L02_003D4AF0(char *, int);
extern float func_L02_002F21C0(void *, void *);
extern void func_L01_00321178(char *, char *);
extern float func_00283C80(float, float);
extern void func_L02_003D69F0(void);
extern void func_L02_003D5118(char *, int);
extern void func_L02_003D6690(char *, int);
extern int func_L02_003D4D00(char *);
extern int func_L02_003D4A60(char *);
extern Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchFlags func_002B1C20(void *, Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *);
/* Extra caller slots are retained at this legacy entry; its leaf ignores them. */
extern void func_L02_003FC248();
extern int func_002E5E58(int, int, void *);
extern void func_002B0A18(int, int);
extern void func_L01_003E9CF8(char *, int, void (*)(char *));
extern void func_L02_003D4900(char *);
extern void func_002B5278(u8 *, float);
extern void func_L02_003D4E00(char *);
extern int func_00282978(short *);
extern int func_L02_003D4D68(char *);
extern int func_L02_003D52A8(char *);
extern void func_00282C88(Quadword *);
extern void func_L02_003D5660(char *, int);
extern int func_L02_003D5748(char *, int);
extern void func_L02_003D46B8(char *);
#define B(o) (*(u8 *)(state+(o)))
#define H(o) (*(short *)(state+(o)))
#define I(o) (*(int *)(state+(o)))
#define W(o) (*(unsigned int *)(state+(o)))
#define F(o) (*(float *)(state+(o)))
#define P(o) (*(char **)(state+(o)))
#define SET_MODE(m,r) func_002A7750((u8 *)self,(u8)(m),(r))

/* Drive the large Maktar sentry's locomotion and paired throw sequences. */
void func_L02_003D2DE0(char *self)
{
    char *state=*(char **)(self+0x68);
    float target[4], position[4];
    float distance, yaw, frame, value;
    int result, nextMode, hand, animation;
    unsigned long events;
    unsigned char flags;
    short phase;

    D_L02_001B3F58=0.7853981633974483f;
    func_L02_003D4308(self);
    *(Quadword *)target=*(Quadword *)(P(0x30C)+0x10);
    distance=func_00282E80(self+0x10,target);
    yaw=func_00283248(target[0]-*(float *)(self+0x10),target[1]-*(float *)(self+0x14));
    frame=func_0029F530(self);
    flags=(u8)self[0x95];
    if (flags==2) {
        if (func_002B3890((u8 *)self)) {
            B(0x70)=18; I(0xA8)=4; B(0xD6)=1; W(0x148)|=4;
            F(0x30)=5.0f; I(0x14C)=-1;
        }
        if (!(D_L02_001B01B0[2]-1.0f<=*(float *)(self+0x18)))
            *(float *)(self+0x18)=D_L02_001B01B0[2]-1.0f;
    } else if (flags==1) {
        if (func_002B3890((u8 *)self)) {
            B(0xD6)=0; B(0x70)=8; I(0xA8)=3; W(0x148)&=~4U; F(0x30)=3.0f;
            func_002B60B0((u8 *)self,0.0044444446f,0.13333334f,0.008435759f,0.20943955f);
            func_L02_003D5B90(self); I(0x14C)=func_L00_0042AB40(*(char **)(self+0xB8));
        }
    } else if (flags==3 || flags==4) {
        if (func_002B3890((u8 *)self)) func_L02_003D5B90(self);
    }
    switch ((u8)self[0x20]) {
    case 1: return;
    case 2:
        if (func_002B3868((u8 *)self)) {
            D_L02_001B01E0=1; *(unsigned short *)(self+0x96)=0;
            if (self[0x43]) func_002A7470(self,0,0,10);
        }
        if (*(unsigned short *)(self+0x96)>120) {
            if (self[0x42]==9) {
                func_L02_003D4ED0(self); *(Quadword *)position=*(Quadword *)(state+0x2D0);
                yaw=func_00283248(target[0]-*(float *)(self+0x10),target[1]-*(float *)(self+0x14));
                func_L02_003D4FD0(self,(Quadword *)position,yaw,0.0f);
            } else {
                if (self[0x43]!=9) func_002A7470(self,9,0,10);
                self[0x95]=2; *(Quadword *)(state+0x2D0)=*(Quadword *)(self+0x10);
                *(Quadword *)((WaypointView *)state)->waypoint=*(Quadword *)D_L02_001B01D0;
            }
        }
        if (func_00282E80(self+0x10,D_L02_001B01B0)<18.0f) { H(0x32E)=0; SET_MODE(20,2); }
        break;
    case 3:
        if (func_002B3868((u8 *)self)) {
            if (self[0x43]!=9) func_002A7470(self,9,0,10);
            *(Quadword *)(state+0x2D0)=*(Quadword *)(self+0x10);
            value=func_002A7878(20.0f,40.0f)*0.017453294f;
            if (func_002A77E0(2)) value=-value;
            F(0x308)=value; *(Quadword *)((WaypointView *)state)->waypoint=*(Quadword *)D_L02_001B01C0;
            func_L02_003D4A48(self); func_L02_003DB880(P(0x310));
            func_L02_003FC020(*(char **)(self+0xB8),P(0x310));
        }
        func_L02_003D4ED0(self); *(Quadword *)position=*(Quadword *)(state+0x2D0);
        yaw=func_00283248(D_00189EA0[0]-*(float *)(self+0x10),D_00189EA0[1]-*(float *)(self+0x14));
        func_L02_003D4FD0(self,(Quadword *)position,yaw,0.0f);
        if (func_00282E48(self+0x10,((WaypointView *)state)->waypoint)<0.5f) SET_MODE(4,1);
        break;
    case 4:
        if (func_002B3868((u8 *)self) && self[0x43]) func_002A7470(self,0,0,15);
        func_002B5258(self);
        if (H(0x318)) SET_MODE(2,1);
        break;
    case 6:
        if (func_002B3868((u8 *)self) && self[0x43]!=1) func_002A7470(self,1,0,10);
        if (!func_002A77E0(400)) func_L02_003D4AF0(self,-1);
        if (func_L02_002F21C0(target,D_L02_001B01B0)<529.0f)
            func_L01_00321178(self,(char *)target);
        else func_L02_003D4AF0(self,1);
        if ((self[0x42]==1 && frame>1.0f && frame<3.0f) || (frame>16.0f && frame<18.0f)) {
            D_L02_001BA500.amount=0.05f; D_L02_001BA500.kind=25; D_L02_001BA500.detail=0;
        }
        if (distance<9.0f && func_00283C80(yaw,*(float *)(self+0xF8))<0.087266475f
                && frame>3.0f && frame<15.0f) SET_MODE(7,1);
        break;
    case 7:
        if (func_002B3868((u8 *)self)) {
            if (self[0x43]!=2) func_002A7470(self,2,0,10);
            func_L02_003D69F0(); self[0xBC]=0;
        }
        if (self[0x42]==2 && frame>19.0f && frame<23.0f) {
            func_L02_003D5118(self,0); func_L02_003D6690(self,0);
        } else if (self[0xBC]==0) {
            if (self[0x42]==2 && frame>23.0f) { func_L02_003D69F0(); self[0xBC]=1; }
        } else if (self[0x42]==2 && frame>32.0f && frame<36.0f) {
            func_L02_003D5118(self,1); func_L02_003D6690(self,1);
        } else if (self[0xBC]==1 && self[0x42]==2 && frame>36.0f) {
            func_L02_003D69F0(); self[0xBC]=2;
        }
        if (self[0x60]&2) {
            SET_MODE((func_L02_003D4D00(self) || func_L02_003D4A60(self)) ? 19 : 6,1);
            if (!func_002A77E0(3) || D_0018C2BC==self)
                func_L02_003D4AF0(self,D_0018C2BC==self ? 0 : -1);
        }
        break;
    case 8:
        *(Quadword *)position=*(Quadword *)(self+0x10);
        if (F(0x20)>0.0f) {
            events=func_002B1C20(self,(void *)(state+0x60));
            if (events&2) SET_MODE((func_L02_003D4D00(self) || func_L02_003D4A60(self)) ? 19 : 6,1);
        } else if (frame<=95.0f || frame>=97.0f) {
            if (frame>110.0f) SET_MODE(9,-1);
        } else { D_L02_001BA500.amount=0.4f; D_L02_001BA500.kind=25; D_L02_001BA500.detail=0; }
        if (func_00282E80(self+0x10,D_L02_001B01B0)>18.0f)
            *(Quadword *)(self+0x10)=*(Quadword *)position;
        break;
    case 9:
        if (func_002B3868((u8 *)self)) {
            *(int *)(self+0x48)=0; *(short *)(self+0x96)=0;
            func_L02_003FC248(self,0,-1); *(int *)(self+0x98)=*(int *)(*(char **)(self+0x24)+0x10);
        }
        if (*(unsigned short *)(self+0x96)>60) {
            *(float *)(self+0x48)=1.0f;
            if (D_L02_001B01E0 && !D_001A7A61) {
                D_001A7A61=1; func_002E5E58(1,0,0); func_002B0A18(0x1233,-1); D_L02_001A903C=1;
            }
            func_L01_003E9CF8(self,0,func_L02_003D4900);
            if (P(0x310) && (u8)P(0x310)[0x20]!=254 && (u8)P(0x310)[0x20]!=253 && (u8)P(0x310)[0x20]>2) {
                func_L02_003DB880(P(0x310)); func_L02_003FC020(*(char **)(self+0xB8),P(0x310));
            }
        }
        break;
    case 10:
        if (self[0x95]==2) {
            *(Quadword *)position=*(Quadword *)((WaypointView *)state)->waypoint;
            func_L02_003D4FD0(self,(Quadword *)position,yaw,0.0f);
        } else func_002B5278((u8 *)self,*(float *)(self+0xF8));
        if (self[0x60]&2) { SET_MODE(H(0x324),H(0x326)); *(int *)(self+0x48)=0; }
        break;
    case 11:
        if (func_002B3868((u8 *)self)) {
            if (self[0x43]!=9) func_002A7470(self,9,0,10);
            H(0x31C)=0; *(Quadword *)(state+0x2D0)=*(Quadword *)(self+0x10);
            value=func_002A7878(20.0f,40.0f)*0.017453294f;
            if (func_002A77E0(2)) value=-value;
            F(0x308)=value;
        }
        func_L02_003D4E00(self); func_L02_003D4ED0(self);
        *(Quadword *)position=*(Quadword *)(state+0x2D0);
        func_L02_003D4FD0(self,(Quadword *)position,yaw,0.0f);
        if (!func_002A77E0(400)) func_L02_003D4AF0(self,0);
        if (distance<40.0f && distance>5.0f && func_00282978((short *)(state+0x31C))) {
            if (!func_002A77E0(2)) SET_MODE(15,2); else SET_MODE(12,2);
            if (!func_002A77E0(6)) func_L02_003D4AF0(self,0);
        }
        if (func_L02_003D4D68(self)) SET_MODE(20,2);
        if (func_L02_003D4A60(self)) SET_MODE(3,2);
        break;
    case 12:
        if (func_002B3868((u8 *)self)) H(0x328)=0;
        if (!H(0x328)) {
            result=func_L02_003D52A8(self);
            if (!result) { func_L02_003D5B90(self); SET_MODE(11,-1); }
            else if (result==2 && self[0x42]!=10 && self[0x43]!=10) func_002A7470(self,10,0,7);
        } else {
            *(Quadword *)position=*(Quadword *)(self+0x10);
            func_L02_003D4FD0(self,(Quadword *)position,*(float *)(self+0xF8),0.0f);
        }
        if (!H(0x328) && self[0x42]==10 && frame>19.0f) {
            func_00282C88((Quadword *)(state+0x1B0)); func_L02_003D5660(self,0); H(0x328)=1;
        }
        if (H(0x328)) {
            result=func_L02_003D5748(self,0);
            if (result==1) SET_MODE(14,2);
            else if (result==2) { func_L02_003D5B90(self); H(0x328)=0; }
        }
        if (H(0x328)==1 && self[0x42]==10 && frame>27.0f) SET_MODE(13,2);
        break;
    case 13:
        if (func_002B3868((u8 *)self) && self[0x43]!=11) func_002A7470(self,11,0,7);
        *(Quadword *)position=*(Quadword *)(self+0x10);
        func_L02_003D4FD0(self,(Quadword *)position,*(float *)(self+0xF8),0.0f);
        if (H(0x328) && func_L02_003D5748(self,0)==2) {
            SET_MODE(14,2); func_L02_003D5B90(self); H(0x328)=0;
        }
        break;
    case 14:
        if (func_002B3868((u8 *)self) && self[0x43]!=12) func_002A7470(self,12,0,7);
        if (H(0x328) && func_L02_003D5748(self,0)==2) { func_L02_003D5B90(self); H(0x328)=0; }
        *(Quadword *)position=*(Quadword *)(self+0x10);
        func_L02_003D4FD0(self,(Quadword *)position,*(float *)(self+0xF8),0.0f);
        if (!H(0x328) && self[0x42]==12 && frame>6.0f) { func_L02_003D5B90(self); SET_MODE(11,2); }
        break;
    case 15:
        if (func_002B3868((u8 *)self)) H(0x328)=0;
        if (!H(0x328)) {
            result=func_L02_003D52A8(self);
            if (!result) { func_L02_003D5B90(self); SET_MODE(11,-1); }
            else if (result==2 && self[0x42]!=13 && self[0x43]!=13) func_002A7470(self,13,0,7);
        } else {
            *(Quadword *)position=*(Quadword *)(self+0x10);
            func_L02_003D4FD0(self,(Quadword *)position,*(float *)(self+0xF8),0.0f);
        }
        if (!H(0x328) && self[0x42]==13 && frame>19.0f) {
            func_00282C88((Quadword *)(state+0x1B0)); func_L02_003D5660(self,1); H(0x328)=1;
        }
        if (H(0x328)) {
            result=func_L02_003D5748(self,1);
            if (result==1) SET_MODE(17,2);
            else if (result==2) { func_L02_003D5B90(self); H(0x328)=0; }
        }
        if (H(0x328)==1 && self[0x42]==13 && frame>27.0f) SET_MODE(16,2);
        break;
    case 16:
        if (func_002B3868((u8 *)self) && self[0x43]!=14) func_002A7470(self,14,0,7);
        *(Quadword *)position=*(Quadword *)(self+0x10);
        func_L02_003D4FD0(self,(Quadword *)position,*(float *)(self+0xF8),0.0f);
        if (H(0x328) && func_L02_003D5748(self,1)==2) { SET_MODE(17,2); func_L02_003D5B90(self); H(0x328)=0; }
        break;
    case 17:
        if (func_002B3868((u8 *)self) && self[0x43]!=15) func_002A7470(self,15,0,7);
        if (H(0x328) && func_L02_003D5748(self,1)==2) { func_L02_003D5B90(self); H(0x328)=0; }
        *(Quadword *)position=*(Quadword *)(self+0x10);
        func_L02_003D4FD0(self,(Quadword *)position,*(float *)(self+0xF8),0.0f);
        if (!H(0x328) && self[0x42]==15 && frame>6.0f) { func_L02_003D5B90(self); SET_MODE(11,2); }
        break;
    case 18:
        *(Quadword *)position=*(Quadword *)(state+0x2D0);
        func_L02_003D4FD0(self,(Quadword *)position,*(float *)(self+0xF8),0.0f);
        events=func_002B1C20(self,(void *)(state+0x60));
        if (events&1) { SET_MODE(20,2); H(0x32C)=1; }
        else if (events&2) SET_MODE(11,2);
        break;
    case 19:
        if (func_002B3868((u8 *)self) && self[0x43]!=17) func_002A7470(self,17,0,10);
        value=func_0029F530(self);
        if (self[0x42]==17 && value>9.0f) { self[0x95]=2; self[0xBE]&=~2; }
        if (self[0x60]&2) SET_MODE(11,2);
        break;
    case 20:
        if (func_002B3868((u8 *)self)) {
            W(0x148)&=~4U;
            if (self[0x43]!=9) func_002A7470(self,9,0,10);
            func_L02_003D5B90(self);
        }
        if (D_L02_001B01B0[2]+1.0f<=*(float *)(self+0x18) || *(float *)(self+0x18)<=D_L02_001B01B0[2]) {
            *(Quadword *)position=*(Quadword *)(self+0x10); position[2]=D_L02_001B01B0[2];
            func_L02_003D4FD0(self,(Quadword *)position,yaw,0.0f);
        } else {
            if (self[0x42]!=18 && self[0x43]!=18) func_002A7470(self,18,0,10);
            func_002B5278((u8 *)self,yaw);
        }
        if (self[0x42]==18 && (H(0x1D0)!=0 || !(D_L02_001B01B0[2]+0.2f<=*(float *)(self+0x18)))) {
            if (!H(0x32C)) SET_MODE(6,1);
            else { func_002A7470(self,4,0,3); B(0x7A)=0; SET_MODE(8,3); }
            if (self[0x42]==18 && frame>8.0f && frame<10.0f) {
                D_L02_001BA500.amount=0.2f; D_L02_001BA500.kind=25; D_L02_001BA500.detail=0;
            }
        }
        break;
    }
    func_L02_003D46B8(self);
}
