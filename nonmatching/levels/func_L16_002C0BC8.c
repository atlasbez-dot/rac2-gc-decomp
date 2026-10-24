/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -fno-gcse -g.
 * Reported final C / retail: 13808 / 14236 bytes; size equality is not a match.
 * us: 0/1 placements; 13808/14236 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: Complete manual actions/state history/default/postlude. Correct0x80 frame; allocation, scheduling, conditional joins and switch layout differ. Final int selector agrees with existing s32 callers; original formal source spelling remains an inference. Marker restored and failed profile removed.
 * Reopening condition: Measured transition-family allocation or source-shape evidence.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Nonmatching Snivelak player transition, 2026-10-23. Seven bounded US trials.
 * Final profile: -O2 -G8 -ffunction-sections -frac2-qcopy
 * -frac2-qcopy-barrier -fno-gcse -g. US: 13808 versus retail 14236 bytes,
 * 0/1, check.py exit 1. The function is absent from US2 and PAL catalogues;
 * absence is not a match. The final stack frame is the measured 0x80 bytes.
 * A named resident view without the final optimization profile was 13648 bytes
 * with a 0x90 frame; a raw resident-byte view gave 13652 and a 0xA0 frame.
 * Allocation, instruction scheduling, conditional joins and switch block layout
 * remain different. Reopen with measured transition-family allocation/source
 * evidence, not another unmotivated permutation or an artificial barrier.
 *
 * All 148 retail table entries at 0x002A1BA0 were decoded: 79 nondefault entries
 * and the shared default at 0x002C41E4. Every nondefault case and alias is present,
 * with complete state history, cancellation/redirect behavior and the postlude.
 * The 44-byte variant record starts at 0x0025F290; selector and threshold are
 * its +4/+8 fields. Resident views below are partial, not whole-size claims.
 * AC9F8 receives the live destination of each preceding copy: player+0x160
 * in case 4, player+0xF0 in case 22. The A9640 pointer return, 64-bit A4EF0
 * identity and canonical typed list APIs are preserved. Path helper 341820
 * receives five GPR values plus f12 and returns a boolean GPR result; its
 * writable index/fraction pointers address two real four-byte local fields.
 * Ignored marker-helper results still have unresolved original return intent.
 */

/* Resident player fields are addressed relative to the canonical resident block.
 * Widths below follow the retail loads/stores; unknown fields retain their offsets. */
typedef int Quadword __attribute__((mode(TI)));
typedef unsigned char u8;
struct Rac2Native_5b4b17178a13f443_SmallSlotReset128Owner;
typedef struct Rac2Native_5b4b17178a13f443_SmallSlotReset128Owner SlotOwner;
typedef struct {
    char pad0[35];        /* 0   */
    unsigned char f35;    /* 35  */
    char pad36[8];        /* 36  */
    float f44;            /* 44  */
    unsigned char f48;    /* 48  */
    unsigned char f49;    /* 49  */
    unsigned short f50;   /* 50  */
    unsigned short f52;   /* 52  */
    char pad54[2];        /* 54  */
    long long f56;        /* 56  */
    char pad64[34];       /* 64  */
    unsigned char f98;    /* 98  */
    char pad99[21];       /* 99  */
    int f120;             /* 120 */
    unsigned short f124;  /* 124 */
    char pad126[26];      /* 126 */
    int f152;             /* 152 */
    char pad156[14];      /* 156 */
    short f170;           /* 170 */
} Src_F66766f2b;

typedef struct {
    char pad0[256];       /* 0   */
    int a[4];             /* 256 */
    int b[4];             /* 272 */
    Src_F66766f2b *c[4];            /* 288 */
    float d[4];           /* 304 */
    int pad320;           /* 320 */
    Src_F66766f2b *src;             /* 324 */
    int count;            /* 328 */
} List_F66766f2b;
typedef struct { int reserved00; int selector; int threshold; u8 reserved0c[0x20]; } TransitionVariant;
/* A partial view through the last statistic touched here, not an object-size claim. */
typedef struct {
    u8 prefix[0x2290];
    u8 *object;
    int state, phase, motion, previous, previousMotion, previousTime, olderState, olderMotion;
    u8 mode, override, reserved22B6, movement;
    u8 remaining[0x2948-0x22B8];
} PlayerTransitionView;
extern PlayerTransitionView D_00189E20;
extern int D_L16_001A8F00;
extern unsigned int D_001A79F0 __attribute__((sda));
extern unsigned int D_001A7390 __attribute__((sda));
extern int D_L16_001A8FF4 __attribute__((sda));
extern float D_L16_001A7CD8 __attribute__((sda));
extern float D_L16_001A7CDC __attribute__((sda));
extern int D_001A7B90;
extern unsigned char D_001A7A45;
extern int D_L16_001A7DD8[] __attribute__((sda));
extern unsigned char D_L16_001A7DE0[] __attribute__((sda));
extern unsigned char D_L16_001A7E00[] __attribute__((sda));
extern TransitionVariant D_L16_0025F290[];
extern unsigned char D_L16_0025F420[];
extern float D_L16_001B9B08;
extern int D_L16_001B9DC0;

extern void func_L00_00322EC8(SlotOwner *);
extern void func_L00_002D6940(void);
extern void func_L00_002AF3D8(int, int);
extern void func_L00_002AF7D0(void);
extern int func_002A7820(int, int);
extern void func_L00_002AB3E0(void);
extern void func_L01_002C1988(unsigned long);
extern int func_L01_002A7248(int);
extern void func_L00_002D2168(int, int, float);
extern float func_L00_002D3A58(char *);
extern void func_L00_002B39F0(int, float);
extern float func_00283C80(float, float);
extern float func_00282E20(void *);
extern void func_002AC9F8(float *, float);
extern int func_L00_002B9B88(int, int);
extern void func_L00_002A61C8(int, int, int, int);
extern void func_L00_002AABE0(int, int, int);
extern void func_L00_00322A98(void *, char *);
extern void func_L00_00322AC0(List_F66766f2b *, int, int, float);
extern int func_L00_002D6900(unsigned int);
extern float func_L00_002AE070(int);
extern int func_L00_002C3A78(void);
extern int func_00283CF0(float);
extern unsigned long func_L00_002A4EF0(unsigned long);
extern void func_002A7470(void *, int, int, int);
extern unsigned int func_L00_002ADE68(int);
extern int func_L00_002B3248(u8 *);
extern void func_L00_002B75A0(float, float, float);
extern void func_L00_0041E958(float, float, float);
extern void func_L00_002BA508(void);
extern void func_L00_002B6118(float);
extern void *func_002A9640(void *, unsigned int, int);
extern void func_L00_002A4EF8(long);
extern int func_L00_002CAF20(void);
extern float func_00282E48(void *, void *);
extern float func_00282DF0(void *);
extern float func_00282DB0(void *, void *);
extern void func_00282F20(void *, void *, float);
extern int func_L00_00341820(void *, void *, int *, float *, int, float);
extern int D_L16_001A9010;
extern void func_L00_002D2470(int, int);
extern void func_00282C88(Quadword *);
extern float func_00283248(float, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern float func_L00_002B9B38(void *, int);
extern float func_00283B98(float, float);
extern float func_002A78D8(float, float);
extern float func_00283180(float);
extern float func_00283198(float);
extern int func_L00_002ADF80(void);
extern void func_L00_002A6708(void);

#define BASE 0x00189E20
#define AT(a) ((u8 *)&D_00189E20 + ((a) - BASE))
#define B(a) (*(unsigned char *)AT(a))
#define H(a) (*(short *)AT(a))
#define U16(a) (*(unsigned short *)AT(a))
#define I(a) (*(int *)AT(a))
#define W(a) (*(unsigned int *)AT(a))
#define F(a) (*(float *)AT(a))
#define P(a) (*(u8 **)AT(a))
#define COPY(a,b) (*(Quadword *)AT(a) = *(Quadword *)AT(b))
#define STATE D_00189E20.state
#define PHASE D_00189E20.phase
#define MOTION D_00189E20.motion
#define PREVIOUS D_00189E20.previous
#define PREVIOUS_MOTION D_00189E20.previousMotion
#define OLDER_STATE D_00189E20.olderState
#define OLDER_MOTION D_00189E20.olderMotion
#define OBJECT D_00189E20.object
#define PLAY(id,rate,flags) func_L00_002D2168((id),(flags),(rate))

/* Install a player transition, retaining state history and the selected animation. */
int func_L16_002C0BC8(int requested, int animate)
{
    u8 *object;
    int oldPhase;
    unsigned char oldMovement;
    unsigned char savedAnimation;
    int index, variant, frames;
    unsigned int animation, flags, count;
    unsigned long selected;
    float rate, value;
    TransitionVariant *entry;
    void *effect;
    Quadword point;
    Quadword pathPoint;
    struct { int index; float fraction;  } pathState;
    float heading, otherHeading;
    u8 *settings;

    if (MOTION == 0x14 && (requested != 0x61 || animate != 2))
        return 0;
    if ((D_L16_001A8F00 == 2 || D_L16_001A8F00 == 6) && animate != 2)
        return 0;
    if (I(0x18C2EC) == 0 && (MOTION == 2 || MOTION == 7)
            && requested != 6 && requested != 0x39 && requested != 0x43
            && requested != 0x91 && requested != 0x5F && requested != 0x74
            && requested != 0x78 && requested != 0x79 && requested != 0x7C
            && requested != 0x67 && requested != 0x7D && requested != 0x7F)
        return 0;
    oldPhase = PHASE;
    object = OBJECT;
    oldMovement = D_00189E20.movement;
    OLDER_STATE = PREVIOUS;
    OLDER_MOTION = PREVIOUS_MOTION;
    D_00189E20.previousTime = I(0x189FD8);
    PREVIOUS = STATE;
    PREVIOUS_MOTION = MOTION;
    PHASE = 0;
    if (D_00189E20.override == 1)
        D_00189E20.override = 0;
    B(0x18C0DC) = 0;
    STATE = (int)requested;
    if (D_00189E20.mode == 0) {
        *(int *)(OBJECT + 0x9C) = 0;
        B(0x18C0DD) = 0;
        D_00189E20.movement = 0;
        B(0x18C0E2) = 0;
        B(0x18C0DF) = 0;
        U16(0x18C324) = 0;
        func_L00_00322EC8((SlotOwner *)AT(0x18B700));
    }
    if (!H(0x18A01A))
        func_L00_002D6940();
    func_L00_002AF3D8(PREVIOUS, STATE);
    W(0x18AFA8) = 0;
    switch (requested) {
    case 0:
        MOTION = 0; W(0x18C2C0) = 0;
        if (I(0x18B068) == 0x1A) func_L00_002AF7D0();
        B(0x18C30F) = 0;
        W(0x18AFC0) = func_002A7820(0x32,100);
        func_L00_002AB3E0();
        if (D_00189E20.mode) { func_L01_002C1988(0); return 1; }
        COPY(0x189F80,0x189F40);
        if (B(0x18B2BA) && !H(0x18A16C)) { requested = 0x76; goto redirect; }
        W(0x18AFA8) = 0x68;
        if (!animate) goto finish;
        rate = func_L01_002A7248(0) == 0x51 ? 18.0f : -1.0f;
        animation = func_L01_002A7248(0);
        break;
    case 1:
        W(0x18C2C0) = 4; MOTION = 0;
        if (B(0x18C0DA) || (animation = func_L01_002A7248(1), OBJECT[0x43] == animation)
                || !animate) goto finish;
        rate = 18.0f;
        break;
    case 2: case 0x70:
        MOTION = 1; W(0x18C2C0) = 0;
        if (PREVIOUS_MOTION != 4 && OLDER_MOTION != 4)
            F(0x189FD4) = func_L00_002D3A58((char *)AT(0x189F40));
        COPY(0x18A210,0x189E20);
        W(0x18A230) = 0; F(0x18A228)=F(0x189EB8);
        if (F(0x189FD4) > 0.116666675f) F(0x189FD4) = 0.116666675f;
        B(0x18A22F) = 0;
        func_L00_002B39F0(0,1.0f);
        if (func_00283C80(F(0x189EB8),F(0x189FC0)) > 1.5707965f
                && (PREVIOUS_MOTION == 4 || PREVIOUS == 3 || OLDER_STATE == 3))
            F(0x189FD4) = 0.0f;
        W(0x18AFA8) = 0x68;
        if (B(0x18B2BA) && (!H(0x18A16C) || F(0x18A13C) < 0.3f)) {
            requested = 0x76; goto redirect;
        }
        PHASE = 0; B(0x18A22C) = 0; B(0x18A22E) = 0;
        if (!animate) goto finish;
        frames = I(0x18C2EC) == 1 ? 12 : 8;
        if (OLDER_STATE == 0x22 || PREVIOUS == 0x22) frames = 15;
        if (OLDER_STATE == 0x83 || PREVIOUS == 0x83) frames = 15;
        if (PREVIOUS == 0x13) frames = 13;
        if (OLDER_STATE == 6 || OLDER_STATE == 0x2C) frames = 18;
        if (OLDER_MOTION == 4 && B(0x18A2BC) > 5) frames = 13;
        rate = (float)frames;
phaseAnimation:
        PLAY(PHASE + 3,rate,D_L16_001A7DD8[PHASE]);
        goto finish;
    case 3:
        MOTION = 1; W(0x18C2C0) = 0; COPY(0x189F80,0x189F40);
        if (B(0x18B2BA) && !H(0x18A16C)) { requested = 0x76; goto redirect; }
        if (func_L00_002CAF20()) return 0;
        if (func_L01_002A7248(0) == 0x51) {
            if (!animate) goto finish;
            if (!func_L16_002C0BC8(0,0)) return 0;
            PLAY(func_L01_002A7248(0),18.0f,0);
            return 0;
        }
        if (!animate) goto finish;
        savedAnimation = object[0x42];
        goto chooseRunAnimation;
    case 4:
        MOTION = 12; W(0x18C2C0) = 0;
        F(0x189FD4) = func_00282E20(AT(0x189F40));
        if (F(0x189FD4) > 0.116666675f) F(0x189FD4) = 0.116666675f;
        if (B(0x18B2BA) && !H(0x18A16C)) { requested = 0x76; goto redirect; }
        W(0x18AFA8) = 0x68; COPY(0x189F80,0x189F40);
        func_002AC9F8((float *)AT(0x189F80),0.116666675f);
        if (F(0x189F98) > 0.058333337f) func_L00_002B9B88(9,0);
        if (animate) {
            PLAY(13, OBJECT[0x42] == func_L01_002A7248(0) ? 9.0f : 14.0f,2);
            func_L00_002D2470(3,18);
        }
        goto finish;
    case 6: case 0x74:
        MOTION = 2; W(0x18C2C0) = 0;
        if (STATE == 0x74) {
            MOTION = 20;
            if (D_00189E20.mode == 1) {
                if (D_001A79F0 == 3) func_L00_0035F5A0(17,0,(int)OBJECT);
                else if (D_001A79F0 == 14) func_L00_0035F5A0(21,0,(int)OBJECT);
            }
        }
        F(0x18A8A0)=6.111111491918563843e-03f; F(0x18A8A4)=1.944444491527974606e-03f;
        if (STATE == 0x74) {
            if (!D_00189E20.mode) H(0x18C2F6) = func_L00_002B9B88(14,0x20);
            F(0x18A8B0) = func_002A78D8(5.235988646745681763e-02f,0.072722062468528747559f);
            F(0x18A8B4) = func_002A78D8(5.235988646745681763e-02f,0.072722062468528747559f);
        }
        W(0x18AFA8) = 0x68; PHASE = 0; COPY(0x189F10,0x189F40);
        if (!animate) goto finish;
        if (F(0x18A13C) > 1.75f) { PLAY(11,12.0f,0); PHASE = 1; goto finish; }
        animation = 10; rate = 10.0f;
        break;
    case 7: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
    case 16: case 17: case 18: case 27: case 40: case 41: case 56: case 69:
    case 72: case 91: case 102: case 110: case 129: case 137: case 146:
        if (STATE != 0x81 && P(0x18A15C)
                && (*(short *)(P(0x18A15C)+0xAA) == 0x9B9
                    || *(short *)(P(0x18A15C)+0xAA) == 0xF05)) {
            requested = 0x81; goto redirect;
        }
        if (STATE != 0x6E && H(0x18A168) == 1 && requested != 14
                && requested != 56 && !D_L16_001A8FF4) {
            requested = 0x6E; goto redirect;
        }
        B(0x18C2FB) = PREVIOUS == 17 && !B(0x18C2FA) ? B(0x18C2FB)+1 : 0;
        if (H(0x18A012)) { requested = 0x82; goto redirect; }
        if (H(0x18A032)) {
            I(0x189FD8) = D_00189E20.previousTime; W(0x18AFA8) = 0;
            STATE = PREVIOUS; PHASE = oldPhase; return 0;
        }
        MOTION = 4; W(0x18C2C0) = (unsigned)(STATE-40) < 2 ? 3 : 0x50;
        if (STATE == 7 || STATE == 15 || STATE == 13 || (STATE == 11 && PREVIOUS_MOTION != 4)) {
            savedAnimation=B(0x18B2BD);
            func_L00_002A61C8(B(0x18B2BD),0,0,30);
            func_L00_002A61C8(savedAnimation,1,0,30);
        }
        COPY(0x189F10,0x189F40);
        if (STATE != 18 && B(0x18B2B4) && F(0x189EA8) < F(0x18A150)+0.5f)
            func_L00_002AABE0(3,0x10,0);
        if (STATE == 102) func_L00_002B9B88(8,0);
        F(0x18A340)=0.00825f; I(0x18A268)=-1; F(0x18A320)=5.555555690079927444e-03f;
        F(0x18A330)=2.5f; U16(0x18A348)=B(0x18B2B2); U16(0x18A33A)=80;
        F(0x18A2B4)=2.501639127731323242e-01f; F(0x18A2C0)=8.333333730697631836e-01f;
        F(0x18A2B0)=F(0x189EA8); B(0x18A2BE)=0; B(0x18A2BC)=0;
        W(0x18A2D0)=0; W(0x18A2D4)=0; B(0x18A2BD)=0;
        F(0x18A324)=3.055555745959281921e-03f; U16(0x18A344)=0; B(0x18A34C)=0;
        B(0x18A34E)=0; B(0x18A34F)=0; U16(0x18A34A)=70;
        U16(0x18A346)=0; F(0x18A334)=5.000000000000000000e-01f; F(0x18A2C4)=9.916666895151138306e-02f;
        W(0x18A278)=0; B(0x18A2BF)=0; W(0x18A3B4)=0; U16(0x18C2F8)=0;
        if (STATE == 7) {
            F(0x18A278)=9.652500040829181671e-03f; F(0x18A2EC)=30.0f; F(0x18A2F0)=12.0f;
            F(0x18A32C)=2.3f; F(0x18A328)=1.28f; F(0x18A2C8)=1.28f;
            B(0x18A34F)=1; U16(0x18A338)=15; F(0x18A2E8)=18.0f;
            F(0x18A2D8)=0.6f; H(0x18A2CC)=5; F(0x18A2C4)=9.916666895151138306e-02f;
            B(0x18A34C)=1; B(0x18A34E)=1;
        } else if (STATE == 0x81) {
            F(0x18A32C)=D_L16_001A7CD8+0.5f;
            F(0x18A340)=D_L16_001A7CDC*0.00027777778f;
            H(0x18A2CC)=5; F(0x18A2D8)=0.6f; F(0x18A2E8)=18.0f;
            F(0x18A2EC)=30.0f; F(0x18A2F0)=12.0f; F(0x18A328)=D_L16_001A7CD8;
            U16(0x18A338)=15; U16(0x18A33A)=400; F(0x18A330)=300.0f;
            U16(0x18A34A)=1200; F(0x18A2C4)=1.166666746139526367e-01f;
            F(0x18A2C8)=D_L16_001A7CD8; U16(0x18A346)=1200;
            if (D_001A79F0 == 16) W(0x18A2C4)=0;
            func_L00_00322A98(OBJECT,(char *)AT(0x18B700));
            func_L00_00322AC0((List_F66766f2b *)AT(0x18B700),70,2,0.0f);
            func_L00_00322AC0((List_F66766f2b *)AT(0x18B700),35,4,0.0f);
            func_L00_00322AC0((List_F66766f2b *)AT(0x18B700),17,6,0.0f);
        } else if (STATE == 56) {
            H(0x18A2CC)=5; F(0x18A2D8)=0.6f;
            F(0x18A2E8)=18.0f; F(0x18A2EC)=26.0f; F(0x18A2F0)=13.0f;
            F(0x18A32C)=5.55f; F(0x18A328)=5.5f; U16(0x18A338)=2;
            U16(0x18A33A)=120; B(0x18A2BF)=1; F(0x18A2C8)=5.5f;
            func_L00_002A4EF8(1);
            if (PREVIOUS==56 || OLDER_STATE==56 || !I(0x18C2EC)) {
                ++I(0x18B6E0);
                if (I(0x18B6E0)>2 || !I(0x18C2EC)) {
                    if (D_001A79F0==2 && D_L16_001A9010) { requested=0x7d; goto redirect; }
                    if (*(int *)(*(u8 **)(OBJECT+0x24)+0x1f0)) { requested=0x79; goto redirect; }
                    func_L16_002C0BC8(0x39,1); return 0;
                }
            } else I(0x18B6E0)=0;
            U16(0x18A34A)=150; U16(0x18A33E)=4;
            F(0x18A340)=0.004166667f; U16(0x18A33C)=5;
        } else if (STATE == 102) {
            MOTION=25;
            F(0x18A32C)=F(0x189EA8)<F(0x18A154) ? F(0x18A154)-F(0x189EA8) : 0.0f;
            F(0x18A2C8)=F(0x18A32C)+1.7f; F(0x18A32C)+=1.75f;
            B(0x18A2BF)=1; H(0x18A2CC)=5; F(0x18A2D8)=0.6f; F(0x18A2E8)=18.0f;
            F(0x18A2EC)=30.0f; F(0x18A2F0)=12.0f; U16(0x18A338)=19;
            F(0x18A328)=F(0x18A2C8);
        } else if (STATE == 40) {
            H(0x18A2CC)=5; F(0x18A2D8)=0.8f; F(0x18A2E8)=18.0f;
            F(0x18A2EC)=28.0f; F(0x18A2F0)=14.0f;
            F(0x18A32C)=2.45f; F(0x18A328)=2.4f; U16(0x18A338)=17;
            MOTION=15; F(0x18A340)=0.0075000003f; F(0x18A2C8)=2.4f; W(0x18A4B4)=0;
            if (B(0x18B2B8)) {
                ((float *)&point)[3]=0.0f;
                F(0x18A328)=7.1f; F(0x18A32C)=7.1499996f;
                F(0x18A340)=0.003888889f;
                ((float *)&point)[1]=104.0f; ((float *)&point)[0]=331.0f;
                ((float *)&point)[2]=145.0f; F(0x18A2C8)=7.1f;
                if (func_00282E48(AT(0x189EA0),&point)<10.0f) {
                    F(0x18A2C8)+=0.7f; F(0x18A328)+=0.7f; F(0x18A32C)+=0.7f;
                }
            }
        } else if (STATE == 41) {
            H(0x18A2CC)=2; F(0x18A2D8)=0.8f; F(0x18A2E8)=18.0f;
            F(0x18A2EC)=31.0f; F(0x18A2F0)=14.0f;
            F(0x18A32C)=2.55f; F(0x18A328)=2.5f; U16(0x18A338)=10;
            MOTION=15; F(0x18A340)=0.006666667f; W(0x18A4B4)=0; F(0x18A2C8)=2.5f;
        } else if (STATE == 9) {
            F(0x18A2EC)=29.0f; F(0x18A2F0)=11.0f; F(0x18A32C)=2.7f;
            F(0x18A328)=1.0f; F(0x18A2C8)=1.0f;
            B(0x18A34F)=1; U16(0x18A338)=15; F(0x18A2E8)=18.0f;
            F(0x18A2D8)=0.6f; H(0x18A2CC)=5; F(0x18A2C4)=0.099166669f;
            B(0x18A34C)=1; B(0x18A34E)=1;
        } else if (STATE == 110) {
            F(0x18A2D8)=0.6f; F(0x18A2C4)=1.160250008106231689e-01f;
            F(0x18A2E8)=18.0f; F(0x18A2EC)=30.0f; F(0x18A2F0)=12.0f;
            F(0x18A32C)=2.75f; F(0x18A328)=2.7f; U16(0x18A338)=5;
            B(0x18A2BF)=1; F(0x18A2C8)=2.7f; H(0x18A2CC)=5;
            B(0x18A34C)=1; B(0x18A34E)=0; B(0x18A34F)=0;
        } else if (STATE == 10) {
            U16(0x18A346)=70; H(0x18A2CC)=5; F(0x18A2D8)=0.6f;
            F(0x18A2E8)=18.0f; F(0x18A2EC)=29.0f; F(0x18A2F0)=10.0f;
            F(0x18A32C)=1.95f; F(0x18A328)=1.9f; U16(0x18A338)=14;
            F(0x18A340)=0.0030555557f; B(0x18A34E)=1; U16(0x18A33A)=120;
            U16(0x18A34A)=90; F(0x18A2C8)=1.9f;
        } else if (STATE == 16) {
            F(0x18A2E8)=18.0f; F(0x18A2EC)=30.0f; F(0x18A2F0)=11.0f;
            F(0x18A32C)=1.55f; H(0x18A2CC)=5; F(0x18A2D8)=0.8f;
            F(0x18A328)=1.5f; F(0x18A2C8)=1.5f; U16(0x18A338)=1;
            func_L00_002D6900(20);
            F(0x18A328)=0.4f; F(0x18A32C)=0.9f; F(0x18A2C8)=0.4f;
            if (F(0x189FA4)<0.33333334f) {
                func_L00_00322A98(OBJECT,(char *)AT(0x18B700));
                func_L00_00322AC0((List_F66766f2b *)AT(0x18B700),40,2,0.0f);
                func_L00_00322AC0((List_F66766f2b *)AT(0x18B700),20,4,0.0f);
                func_L00_00322AC0((List_F66766f2b *)AT(0x18B700),10,6,0.0f);
            }
            B(0x18A34E)=1; W(0x18A274)=F(0x18A13C)>1.4f ? 0x3DC28F5C : 0x3E444445;
            F(0x18A340)=0.002361111f; F(0x18A324)=1.388888899236917496e-02f; F(0x18A320)=1.222222298383712769e-02f;
        } else if (STATE == 27) {
            B(0x18A34E)=1; H(0x18A2CC)=10; F(0x18A2D8)=0.85f;
            F(0x18A2E8)=20.0f; F(0x18A2EC)=29.0f; F(0x18A2F0)=19.0f;
            F(0x18A32C)=2.05f; F(0x18A328)=2.0f; F(0x18A334)=1.0f;
            F(0x18A340)=0.0069444445f; F(0x18A2C8)=2.0f; U16(0x18A338)=1;
            W(0x18A2DC)=0; B(0x18A2BF)=1; B(0x18C0DF)=1; B(0x18C0DC)=1;
        } else if (STATE == 17) {
            H(0x18A2CC)=9; F(0x18A2D8)=0.6f; F(0x18A2E8)=12.0f;
            F(0x18A2EC)=20.0f; F(0x18A2F0)=10.0f; U16(0x18A338)=12;
            if (!B(0x18C2FA)) {
                F(0x18A32C)=1.85f; F(0x18A2C8)=1.8f; F(0x18A2B8)=2.833333611488342285e-02f;
            } else {
                F(0x18A32C)=3.35f; F(0x18A2C8)=3.3f; F(0x18A2B8)=8.166667073965072632e-02f;
            }
            B(0x18A2BF)=1; F(0x18A328)=F(0x18A2C8);
            func_L00_002D6900(27); U16(0x18A34A)=80; F(0x18A340)=0.008055556f;
            COPY(0x18A310,0x18A300); B(0x18A34C)=1; U16(0x18C2F8)=1; D_00189E20.movement=1;
        } else if (STATE == 13) {
            F(0x18A2E8)=26.0f; F(0x18A2EC)=38.0f; F(0x18A2F0)=18.0f;
            F(0x18A32C)=4.07f; H(0x18A2CC)=9; F(0x18A2D8)=0.6f;
            F(0x18A328)=4.0f; U16(0x18A338)=14; F(0x18A2C8)=4.0f;
            func_L00_002D6900(20); F(0x18A330)=4.5f; U16(0x18A33A)=120;
            F(0x18A2C4)=3.166666626930236816e-02f; U16(0x18A346)=37;
            if (F(0x189FA4)<0.33333334f) {
                func_L00_00322A98(OBJECT,(char *)AT(0x18B700));
                func_L00_00322AC0((List_F66766f2b *)AT(0x18B700),40,3,0.0f);
                func_L00_00322AC0((List_F66766f2b *)AT(0x18B700),20,5,0.0f);
            }
            B(0x18A34E)=1;
        } else if (STATE == 15) {
            H(0x18A2CC)=9; F(0x18A2D8)=0.6f; F(0x18A2E8)=50.0f;
            F(0x18A2EC)=64.0f; F(0x18A2F0)=28.0f; F(0x18A32C)=1.7f;
            F(0x18A328)=1.65f; U16(0x18A338)=5; F(0x18A330)=4.5f;
            U16(0x18A33A)=130; F(0x18A2C4)=5.500000342726707458e-02f; U16(0x18A346)=85;
            U16(0x189FF0)=70; B(0x18A2BD)=1; F(0x18A2C8)=1.65f;
            I(0x18A250)=D_001A7B90 == 0 ? 35 : 34;
            P(0x18A264)=D_L16_001A7E00; I(0x18A254)=I(0x18A250)+36;
            B(0x18A34E)=1; F(0x18A258)=29.0f; F(0x18A25C)=50.0f; W(0x18A260)=86;
        } else if (STATE == 14) {
            F(0x18A2C8)=0.7f;
            if (F(0x18A13C)<2.0f) F(0x18A2C8)=(2.5f-F(0x18A13C))*0.5f+0.7f;
            F(0x18A32C)=F(0x18A2C8)+0.05f; U16(0x18A346)=30;
            H(0x18A2CC)=-1; F(0x18A2D8)=0.6f; F(0x18A2E8)=32.0f;
            F(0x18A2EC)=43.0f; F(0x18A2F0)=19.0f; U16(0x18A338)=14;
            F(0x18A334)=1.0f; F(0x18A2C4)=7.916667312383651733e-02f; F(0x18A328)=F(0x18A2C8);
        } else if (STATE == 11) {
            U16(0x18A34A)=50; H(0x18A2CC)=5; F(0x18A2D8)=0.6f;
            F(0x18A2E8)=18.0f; F(0x18A2EC)=31.0f; F(0x18A2F0)=24.0f;
            F(0x18A32C)=3.25f; F(0x18A328)=3.2f; U16(0x18A338)=14;
            F(0x18A330)=4.5f; F(0x18A334)=1.0f; B(0x18A2BF)=1; F(0x18A2C8)=3.2f;
            F(0x18A2E4)=func_L00_002AE070(10);
            COPY(0x18A2A0,0x189E20); I(0x18A2F4)=func_L00_002C3A78();
            F(0x18A2E0)=F(0x189FC0); COPY(0x18A290,0x189FB0);
            F(0x18A2F8)=F(0x189F94)>0.025000002f ? F(0x189F94) : 0.0f;
            W(0x18A2FC)=0; B(0x18A34C)=1;
            if (!H(0x18B274) || F(0x18C2D8)<=0.3f) B(0x18A34D)=0;
            else {
                F(0x18A2E0)=F(0x18B278); COPY(0x18A290,0x18B260);
                B(0x18A34D)=1; F(0x18A2FC)=8.333333581686019897e-02f;
            }
            B(0x18A34E)=1;
        }
        if (F(0x18A330)==0.0f) F(0x18A330)=F(0x18A2C8)*1.5f;
        if (!animate) goto finish;
        rate=5.0f;
        if (STATE==7 || STATE==110 || STATE==129 || STATE==102) animation=7;
        else if (STATE==56) { animation=67; rate=4.0f; }
        else if (STATE==40) { PLAY(77,5.0f,4); goto finish; }
        else if (STATE==41) {
            animation=30;
            value=func_00283248(F(0x18A3F0)-F(0x18A430),F(0x18A3F4)-F(0x18A434));
            if (func_00283C80(F(0x189EB8),value)>1.5707965f) animation=31;
        } else if (STATE==9) {
            animation=8; index=func_00283CF0(F(0x18AA58));
            if (func_L00_002A4EF0(object[0x42])==4) animation=D_L16_001A7DE0[index];
        } else if (STATE==10) animation=18;
        else if (STATE==16) {
            animation=38;
            if (PREVIOUS_MOTION==4 || (PREVIOUS==4 && I(0x189FD8)<7)) {
                PLAY(38,8.0f,0); H(0x18A2CC)+=3; goto finish;
            }
        } else if (STATE==27) { animation=34; rate=4.0f; }
        else if (STATE==137) { PLAY(125,9.0f,11); goto finish; }
        else if (STATE==17) { PLAY(35,7.0f,2); goto finish; }
        else if (STATE==13) animation=17;
        else if (STATE==14) { PLAY(22,7.0f,3); W(0x18AA40)=0x3F4CCCCD; goto finish; }
        else if (STATE==15) animation=21;
        else if (STATE==11) {
            animation=I(0x18A2F4)+28;
            if (D_001A7A45) { if (animation==28) animation=29; else if (animation==29) animation=28; }
            if (PREVIOUS_MOTION==4) { PLAY(animation,4.0f,1); H(0x18A2CC)=1; goto finish; }
        } else goto finish;
        break;
    case 8:
        MOTION=5; W(0x18AFA8)=0x68; W(0x18C2C0)=0;
        if (F(0x189F90)>0.075f) func_L00_002B6118(0.075f/F(0x189F90));
        W(0x18C2E8)=0; COPY(0x189F10,0x189F30);
        if (!animate) goto finish;
        animation=19; rate=-2.0f;
        break;
    case 19: case 20: case 21: case 31: case 34: case 77: case 131: case 147:
        MOTION=6;
        if (I(0x18B320) && (unsigned)(STATE-19)<3) {
            count=D_001A7390;
            if (H(0x18C75C)!=-1) { ++H(0x18C75C); count=D_001A7390; }
            if (W(0x18C760)<count) W(0x18C760)=count;
            W(0x18C764)|=(1U<<(D_001A79F0&31))|0x80000000U;
            if (H(0x18C600)!=-1) ++H(0x18C600);
            if (W(0x18C604)<D_001A7390) W(0x18C604)=D_001A7390;
            W(0x18C608)|=(1U<<(D_001A79F0&31))|0x80000000U;
            func_L00_002BA508(); STATE=PREVIOUS; MOTION=PREVIOUS_MOTION;
            goto finish;
        }
        if (requested!=131) W(0x18C2C0)=0;
        F(0x18AA14)=1.0f; I(0x18AA08)=0; W(0x18AA04)=0; U16(0x18AA1E)=0;
        if (STATE==21) {
            count=D_001A7390;
            if (H(0x18C75C)!=-1) { ++H(0x18C75C); count=D_001A7390; }
            if (W(0x18C760)<count) W(0x18C760)=count;
            W(0x18C764)|=(1U<<(D_001A79F0&31))|0x80000000U;
            if (H(0x18C600)!=-1) ++H(0x18C600);
            if (W(0x18C604)<D_001A7390) W(0x18C604)=D_001A7390;
            W(0x18C608)|=(1U<<(D_001A79F0&31))|0x80000000U;
            H(0x18AA1C)=3; W(0x18C120)=0;
            func_L00_002B75A0(14.0f,0.52359885f,-1.0f);
            W(0x18AA2C)=W(0x18AA2C)==0;
            if (animate) {
                frames=OBJECT[0x43]==26 ? 3 : 10;
                if (PREVIOUS==1) frames=17;
                PLAY(26,(float)frames,0); func_L00_002D2470(6,21);
            }
        } else if (STATE>21) {
            if (STATE==34) {
                if (animate) PLAY(44,9.0f,7);
                if (I(0x18B068)==12 && P(0x18AA00)) {
                    I(0x18AA08)=1;
                    F(0x18AA0C)=func_00283248(*(float *)(P(0x18AA00)+0x10)-F(0x189EA0),
                            *(float *)(P(0x18AA00)+0x14)-F(0x189EA4));
                    func_00282CF0(AT(0x18A9E0),P(0x18AA00)+0x10,AT(0x189EA0));
                }
            } else if (STATE<35) {
                if (STATE==31 && P(0x18B040)) {
                    func_L00_002D6900(19);
                    if (animate) { PLAY(96,-1.0f,4); func_002A7470(P(0x18B040),3,4,-1); }
                    func_L00_002B75A0(11.0f,0.8726647f,-1.0f);
                }
            } else if (STATE==131) {
                H(0x18AA1C)=3; func_L00_0041E958(64.0f,0.17453295f,0.3490659f);
                if (animate) {
                    frames=OBJECT[0x43]==26 ? 3 : 10;
                    if (PREVIOUS==1) frames=17;
                    PLAY(26,(float)frames,0);
                }
            }
        } else if (STATE==20) {
            if (H(0x18C750)!=-1) ++H(0x18C750);
            if (W(0x18C754)<D_001A7390) W(0x18C754)=D_001A7390;
            W(0x18C758)|=(1U<<(D_001A79F0&31))|0x80000000U;
            W(0x18C2C0)=0x50; H(0x18AA1C)=4; W(0x18C120)=0;
            func_L00_002B75A0(8.0f,1.0471977f,-1.0f); W(0x18AA20)=0;
            if (animate) {
                frames=11;
                if (PREVIOUS==11 && D_00189E20.previousTime<42) frames=17;
                PLAY(43,(float)frames,4);
                object=(u8 *)func_L00_002ADE68(0);
                if (func_L00_002B3248(object)) func_002A7470(object,10,4,frames+2);
            }
        } else if (STATE==19) {
            count=D_001A7390;
            if (H(0x18C3D8)!=-1) { ++H(0x18C3D8); count=D_001A7390; }
            if (W(0x18C3DC)<count) W(0x18C3DC)=count;
            W(0x18C3E0)|=(1U<<(D_001A79F0&31))|0x80000000U;
            entry=&D_L16_0025F290[H(0x18AA1C)]; variant=0; W(0x18C120)=0;
            if ((PREVIOUS==19 && (float)entry->threshold>F(0x18AA58))
                    || (OLDER_STATE==19 && I(0x189FD8)+D_00189E20.previousTime<27))
                variant=(entry->selector+1)%3;
            H(0x18AA1C)=variant;
            func_L00_002B75A0(5.0f,0.78539824f,0.78539824f);
            if (animate) {
                flags=variant==0 ? 0 : variant==1 ? 2 : 4;
                frames=variant==0 ? 5 : 7;
                if (I(0x18AA08) && variant<2) {
                    if (!B(0x18C0E3)) value=func_00283C80(F(0x18AA0C),F(0x189EB8));
                    else value=func_L00_002B9B38(AT(0x18A9E0),0);
                    frames+=func_00283CF0(value*1.5f);
                }
                PLAY(variant+23,(float)frames,flags/2);
                object=(u8 *)func_L00_002ADE68(0);
                if (func_L00_002B3248(object)) func_002A7470(object,variant+3,flags/2,frames);
            }
        }
        goto finish;
    case 22: case 140:
        MOTION=7; W(0x18C2C0)=0; func_L00_002B6118(0.5f);
        if (requested==140) B(0x18C0DC)=1;
        func_L00_002D6900(18);
        if (requested==22) { U16(0x18A02E)=45; COPY(0x189F10,0x189F40); func_002AC9F8((float *)AT(0x189F10),0.116666675f); }
        effect=func_002A9640(OBJECT,requested==22 ? 1 : 8,0);
        func_L00_002A4EF8(effect ? func_00283CF0(*(float *)((u8 *)effect+0x2C)) : 1);
        U16(0x189FFC)=77;
        if (!animate) goto finish;
        U16(0x189FFC)=77;
        PLAY(requested==22 ? 16 : 150,-3.0f,requested==22 ? 3 : 1);
        index=I(0x18AA54)++;
        *(int *)(OBJECT+0x44)=*(int *)(D_L16_0025F420+index*4+I(0x18AA50)*100);
        goto finish;
    case 23:
        MOTION=3; W(0x18C2C0)=13; F(0x18A39C)=0.0061111115f; F(0x18A3A0)=F(0x189EA8);
        if (PREVIOUS_MOTION==4) { F(0x18A39C)=F(0x18A340); F(0x18A3A0)=F(0x18A2B0); }
        B(0x18C0DC)=1; B(0x18C0DF)=1;
        if (!animate) goto finish;
        if (F(0x189F94)<=0.058333337f) { PLAY(32,11.0f,1); goto finish; }
        animation=32; rate=9.0f; break;
    case 24: case 25: case 26:
        B(0x18C0DC)=1; MOTION=3; W(0x18C2C0)=13; B(0x18C0DF)=1;
        if (requested==24) W(0x18AFA8)=0x68;
        if (!animate) goto finish;
        animation=requested==24 ? 33 : requested==25 ? 36 : 37; rate=6.0f; break;
    case 28: case 30: case 38:
        if (requested==28) B(0x18C0DC)=1;
        MOTION=requested==38 ? 8 : 9; W(0x18C2C0)=0;
        animation=func_L01_002A7248(0); rate=10.0f; break;
    case 29:
        W(0x18C2C0)=0x51; MOTION=0;
        selected=func_L00_002A4EF0(OBJECT[0x42]);
        if (selected==func_L01_002A7248(0)) goto finish;
        animation=func_L01_002A7248(0); rate=5.0f; break;
    case 35:
        MOTION=13; W(0x18C2C0)=7;
        if (H(0x18C3FC)!=-1) ++H(0x18C3FC);
        if (W(0x18C400)<D_001A7390) W(0x18C400)=D_001A7390;
        W(0x18C404)|=(1U<<(D_001A79F0&31))|0x80000000U;
        F(0x189FC0)=func_00283248(*(float *)(P(0x18A8C4)+0x10)-F(0x189EA0),
                *(float *)(P(0x18A8C4)+0x14)-F(0x189EA4));
        if (PREVIOUS==40) COPY(0x189F80,0x189F10);
climbAnimation:
        if (animate) { PLAY(47,5.0f,2); func_L00_002D2470(10,14); }
        goto finish;
    case 36:
        B(0x18C0DC)=1; MOTION=13; W(0x18C2C0)=7;
        W(0x18A8C0)=0; W(0x18A8D4)=0;
        if (animate) PLAY(48,10.0f,1);
        goto finish;
    case 37:
        B(0x18C0DC)=1; MOTION=13; W(0x18C2C0)=7;
        W(0x18A8C0)=0; W(0x18A8D4)=0;
        F(0x18A8DC)=func_00282E48(AT(0x189EA0),P(0x18A8C4)+0x10);
        if (animate) PLAY(48,5.0f,1);
        goto finish;
    case 39:
        W(0x18C2C0)=3; W(0x18AFA8)=0x68; W(0x18A468)=1;
        F(0x18A478)=-1.5707965f; MOTION=15; I(0x18A460)=0;
        W(0x18A4E8)=0; I(0x18A47C)=0;
        if (PREVIOUS_MOTION!=15) {
            W(0x18A494)=0; I(0x18A49C)=-1; F(0x18A4A0)=0.0f;
        }
        pathState.index=I(0x18A454); pathState.fraction=F(0x18A458);
        W(0x18A4D0)=0; W(0x18A4D4)=0; U16(0x18A4DE)=0;
        W(0x18A4A4)=0; W(0x18A4A8)=0; W(0x18A4AC)=0; W(0x18A4B0)=0;
        func_L00_00341820(P(0x18A450),&pathPoint,&pathState.index,&pathState.fraction,I(0x18A474),1.0f);
        func_00282CF0(&point,&pathPoint,AT(0x189EA0));
        if (func_00282DF0(&point)>0.001f) {
            func_00282F20(&point,&point,1.0f);
            if (PREVIOUS_MOTION!=15) F(0x18A4A0)=func_00282DB0(AT(0x189F30),&point);
        }
        if (P(0x18A4C8)) {
            heading=func_00283248(*(float *)(P(0x18A4C8)+0x10)-F(0x189EA0),
                    *(float *)(P(0x18A4C8)+0x14)-F(0x189EA4));
            otherHeading=func_00283248(((float *)&point)[0],((float *)&point)[1]);
            otherHeading=func_00283B98(F(0x18A478),otherHeading);
            if (func_00283C80(heading,otherHeading)>1.5707965f) {
                F(0x18A478)=1.5707965f; I(0x18A47C)=1;
            }
        }
        if (animate) PLAY(I(0x18A47C)+49,6.0f,0);
        goto finish;
    case 42:
        MOTION=15; U16(0x18AA1E)=0;
        if (PREVIOUS==42) U16(0x18AA1C)=U16(0x18AA1C)==0;
        else U16(0x18AA1C)=0;
        if (animate) {
            PLAY(H(0x18AA1C)+75,4.0f,0);
            object=(u8 *)func_L00_002ADE68(0);
            if (func_L00_002B3248(object)) func_002A7470(object,H(0x18AA1C)+12,0,4);
        }
        goto finish;
    case 43:
        MOTION=14; W(0x18C2C0)=7;
        if (H(0x18C3FC)!=-1) ++H(0x18C3FC);
        if (W(0x18C400)<D_001A7390) W(0x18C400)=D_001A7390;
        U16(0x18A91E)=1; W(0x18C404)|=(1U<<(D_001A79F0&31))|0x80000000U;
        W(0x18A908)=0; B(0x18C0DC)=1; P(0x18A8F4)=P(0x18A8F0);
        W(0x18A8FC)=0; U16(0x18A91C)=0; W(0x18A914)=0; W(0x18A918)=0;
        settings=*(u8 **)(P(0x18A8F0)+0x68);
        W(0x18A900)=*(unsigned int *)(settings+4);
        value=*(float *)(settings+0x10);
        if (value==0.0f) value=*(float *)(settings+0xc);
        *(float *)(settings+0x14)=value;
        F(0x18A928)=0.33f; F(0x18A92C)=0.18333334f; F(0x18A924)=0.025f;
        func_00282C88((Quadword *)AT(0x189EC0)); U16(0x18A026)=40;
        if (*(float *)(settings+0x24)!=0.0f) F(0x18A924)=*(float *)(settings+0x24);
        if (*(float *)(settings+0x28)!=0.0f) F(0x18A928)=*(float *)(settings+0x28);
        if (*(float *)(settings+0x2c)!=0.0f) F(0x18A92C)=*(float *)(settings+0x2c);
        F(0x18A90C)=func_00283248(*(float *)(P(0x18A8F4)+0x10)-F(0x189EA0),
                *(float *)(P(0x18A8F4)+0x14)-F(0x189EA4));
        F(0x18A904)=func_00282E48(AT(0x189EA0),P(0x18A8F4)+0x10);
        F(0x18A910)=0.0075000003f;
        if (PREVIOUS_MOTION==4) F(0x18A910)=F(0x18A340);
        else if (PREVIOUS_MOTION==2) F(0x18A910)=F(0x18A8A0);
        if (animate) { PLAY(52,11.0f,0); F(0x18AA40)=0.7f; }
        goto finish;
    case 44:
        W(0x18C2C0)=7; MOTION=2;
        func_00282C88((Quadword *)AT(0x189EC0)); COPY(0x189F10,0x189F40);
        if (!animate) goto finish;
        animation=11; rate=15.0f; break;
    case 47:
        MOTION=8; W(0x18C2C0)=0; COPY(0x189F80,0x189F30);
        PLAY(func_L01_002A7248(0),5.0f,0); U16(0x18A00C)=7; goto finish;
    case 49:
        MOTION=9; B(0x18C0DC)=1; W(0x18C2C0)=0; D_00189E20.movement=1; B(0x18C0DD)=1;
        func_L00_00322EC8((SlotOwner *)AT(0x18B850));
        if (!animate) goto finish;
        animation=func_L01_002A7248(0); rate=-1.0f; break;
    case 57:
        MOTION=20; W(0x18C2C0)=0; COPY(0x189F80,0x189F40);
        if (!animate) goto finish;
        animation=69; rate=12.0f; break;
    case 61:
        PLAY(func_L01_002A7248(0),9.0f,0);
        if (P(0x18B674)) func_002A7470(P(0x18B674),0,0,9);
        goto finish;
    case 62:
        MOTION=15; W(0x18C2C0)=0;
        if (I(0x18A460)==0) {
            if (!P(0x18A4E4)) func_L00_002A4EF8(1);
            else { func_L00_002A4EF8(func_00283CF0(*(float *)(P(0x18A4E4)+0x2C))); P(0x18A4E4)=0; }
        }
        func_L00_002B9B88(20,0);
        if (I(0x18C2EC)<1) {
            value=func_00283248(F(0x189F10),F(0x189F14));
            value=func_00283B98(value,3.14159298f);
            value=func_00283B98(value,func_002A78D8(0.52359885f,0.6108653f));
            F(0x189F40)=func_00283180(value)*F(0x18A464)*0.7f;
            F(0x189F44)=func_00283198(value)*F(0x18A464)*0.7f;
            F(0x189F48)=0.075f;
            if (I(0x18A460)>15 && I(0x18C2EC)<2) I(0x18C2EC)=2;
            OBJECT[0xA8]=255; func_L16_002C0BC8(22,1);
            U16(0x189FF0)=70; U16(0x18A014)=150; return 0;
        }
        U16(0x189FFC)=77; F(0x18A4BC)=0.041666668f;
        if (F(0x18A4A0)>0.041666668f) F(0x18A4A0)=0.041666668f;
        W(0x18A494)=0; func_00282C88((Quadword *)AT(0x189F10));
        func_00282C88((Quadword *)AT(0x189F30)); F(0x189F18)=0.18333334f;
        if (animate) PLAY(16,-3.0f,2);
        goto finish;
    case 96: case 97:
        MOTION=24; B(0x18C0DC)=1;
        func_L00_00322EC8((SlotOwner *)AT(0x18B850)); func_L00_002AF7D0();
        if (animate) PLAY(func_L01_002A7248(0),-1.0f,0);
        goto finish;
    case 98:
        MOTION=1; W(0x18C2C0)=0; F(0x189FD4)=func_00282E20(AT(0x189F40));
        B(0x18C0DC)=1;
        if (!D_00189E20.mode) func_L00_002AF7D0();
        if (!animate) goto finish;
        if (D_00189E20.mode==1) { animation=2; rate=8.0f; break; }
        if (D_00189E20.mode) goto finish;
        rate=8.0f; goto phaseAnimation;
    case 99:
        MOTION=1; W(0x18C2C0)=0;
        F(0x189FD4)=func_L00_002D3A58((char *)AT(0x189F40)); COPY(0x189F80,0x189F40);
        if (!animate) goto finish;
        savedAnimation=object[0x42];
chooseRunAnimation:
        value=F(0x18AA58); selected=6;
        if (func_L00_002A4EF0(savedAnimation)==4 && value>3.0f && value<16.0f) selected=5;
        PLAY((int)selected,9.0f,4); goto finish;
    case 100:
        MOTION=0; W(0x18C2C0)=0; func_00282C88((Quadword *)AT(0x189F80));
        W(0x18AFA8)=0x68;
        if (!animate) goto finish;
        rate=func_L01_002A7248(0)==0x51 ? 18.0f : -1.0f;
        animation=func_L01_002A7248(0); break;
    case 101:
        MOTION=25; ++I(0x18B6E0); W(0x18C2C0)=0; func_L00_002B9B88(7,0);
        W(0x18A1C0)=0; W(0x18AFA8)=0x68; W(0x189FD0)=0; F(0x189FD4)=0.0f;
        if (!animate) goto finish;
        animation=106; rate=8.0f; break;
    case 111:
        MOTION=9; B(0x18C0DC)=1; W(0x18C2C0)=0; func_L00_002AF7D0();
        if (!animate) goto finish;
        animation=func_L01_002A7248(0); rate=10.0f; break;
    case 117:
        B(0x18C0DC)=1; MOTION=9; W(0x18C2C0)=0; D_00189E20.movement=1;
        func_00282C88((Quadword *)AT(0x189F10));
        if (!animate) goto finish;
        animation=11; rate=-1.0f; break;
    case 118:
        MOTION=2; W(0x18C2C0)=0; COPY(0x189F10,0x189F40);
        if (!animate) goto finish;
        animation=11; rate=12.0f; break;
    case 119:
        MOTION=10; W(0x18C2C0)=0;
        F(0x18AA10)=func_00283B98(F(0x189EB8),3.14159298f);
        func_00282D30(AT(0x18A9F0),AT(0x189E20),-1.0f);
        F(0x189FD4)=0.15f;
        if (animate) PLAY(41,8.0f,5);
        goto finish;
    case 120:
        U16(0x18A010)=10000; MOTION=25; W(0x18C2C0)=0; func_L00_002B9B88(7,0);
        W(0x18AFA8)=0x68;
        if (!animate) goto finish;
        animation=106; rate=8.0f; break;
    case 123:
        W(0x18AFA8)=0x68; MOTION=28; W(0x18C2C0)=0;
        COPY(0x189F10,0x189F30);
        if (I(0x18B0B8)!=54) { W(0x18C0EC)=54; I(0x18C124)=I(0x18B0B8); }
        if (!animate) goto finish;
        animation=139; rate=-2.0f; break;
    case 130:
        MOTION=30; W(0x18C2C0)=0;
        if (PREVIOUS!=22) {
            F(0x18A3D0)=50.0f;
            if (F(0x18A3D8)!=0.0f) { value=F(0x18A3D8); F(0x18A3D8)=0.0f; F(0x18A3D0)=value; }
        }
        B(0x18C30F)=1; W(0x18AFA8)=0x68; W(0x18A5C8)=0;
        U16(0x18A3DE)=0; W(0x18A3C8)=0; W(0x18A3C4)=0;
        COPY(0x189F10,0x189F30); U16(0x18A3DC)=7;
        if (!animate) goto finish;
        animation=19; rate=-2.0f; break;
    case 133:
        MOTION=32; W(0x18C2C0)=8; B(0x18C0E2)=1; D_00189E20.movement=1;
        if (animate) PLAY(79,5.0f,0);
        F(0x189EB8)=*(float *)(P(0x18B650)+0xF8);
        *(Quadword *)AT(0x189EA0)=*(Quadword *)(P(0x18B650)+0x10);
        func_00282C88((Quadword *)AT(0x189F10));
        goto finish;
    case 121:
        MOTION=20; F(0x18A154)=F(0x18A138); U16(0x18A010)=10000;
        W(0x18C2C0)=0; I(0x18C2EC)=0; func_L00_002B9B88(7,0);
        if (!animate) goto finish;
        animation=106; rate=8.0f; break;
    case 138:
        MOTION=33; W(0x18C2C0)=0;
        if (H(0x18C3FC)!=-1) ++H(0x18C3FC);
        if (W(0x18C400)<D_001A7390) W(0x18C400)=D_001A7390;
        W(0x18C404)|=(1U<<(D_001A79F0&31))|0x80000000U;
        F(0x189FC0)=func_00283248(*(float *)(P(0x18A930)+0x10)-F(0x189EA0),
                *(float *)(P(0x18A930)+0x14)-F(0x189EA4));
        W(0x18A93C)=0; goto climbAnimation;
    case 139:
        MOTION=33; B(0x18C0DC)=1; W(0x18C2C0)=0;
        goto finish;
    default:
        goto finish;
    }
    PLAY(animation,rate,0);
finish:
    if (oldMovement && !D_00189E20.movement) W(0x18C13C)=1;
    if (!H(0x18A168) && I(0x18B0B8)==19 && I(0x18C124)) W(0x18C140)=1;
    if ((unsigned)(MOTION-13)>2 && (STATE!=6 || PREVIOUS!=36)
            && I(0x18B0B8)==20 && I(0x18C124)) W(0x18C140)=1;
    if (MOTION==20) { func_L00_002AF7D0(); B(0x18C0DC)=1; }
    if ((!func_L00_002ADF80() || MOTION==18) && (F(0x18A150)<D_L16_001B9B08 || MOTION==0))
        D_L16_001B9DC0=0;
    if (MOTION!=PREVIOUS_MOTION) func_L00_002A6708();
    if (MOTION!=PREVIOUS_MOTION) W(0x189FDC)=0;
    W(0x189FE4)=0; W(0x189FE0)=0; I(0x189FD8)=0;
    return 1;
redirect:
    func_L16_002C0BC8(requested,1);
    return 0;
}
