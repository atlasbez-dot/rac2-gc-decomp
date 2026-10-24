/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -frac2-zero-ti-por -frac2-keep-block-order -frac2-gcse-unsplit-edges.
 * Prior worker coverage: US 0/1; US2 absent from catalogue; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/*
 * Retained manual reconstruction, 23 October 2026; NOT MATCHING.
 *
 * USA v1.01: 15444/15444 bytes, 0/1 placements, exit 1. USA v2.00 and PAL do not carry this
 * canonical name; their absence is not a match. Frame 0xF0 agrees. First instruction mismatch is
 * +0x8: the saved resident high-base register is s7 instead of s5. Entry
 * object/substate/animation allocation and block scheduling differ. The generated 588-byte
 * switch table has not been linked at the retail table location.
 *
 * Seven bounded trials: the complete raw resident-view body was 15328 bytes; a named resident
 * prefix kept that size and corrected base construction. Ordering the state groups to the retail
 * order gave 15340. Keeping block order gave 15448; combining the qualified unsplit-edge profile
 * gave 15444. Union/struct views and debug-info controls tied the final instruction shape. The
 * debug-info flag was discarded.
 *
 * The complete manual body accounts for all 65 explicit selector values in the 147-entry retail
 * dispatch, with 82 bookkeeping-only defaults, and all 95 distinct canonical helper identities.
 * It was reconstructed against fresh Oozla bytes using the retained readable Dobbo Orbit
 * controller as a semantic aid. Peer-only alternate movement, effects and branches were removed;
 * no generated decompiler C was compiled.
 *
 * The optional contact output passed to func_L01_002AE128 is a real aligned record prefix
 * accessed through +0x3b, not the peer draft 16-byte vector. func_L00_002EE4D8 returns an
 * explicit 32-bit integer boolean. Current helper types, live GPR/FP arguments and record
 * extents were inspected before trials. The resident model covers an accessed prefix through the
 * halfword at +0x24fc, not a claim of complete object ownership. No fabricated scalar sizes,
 * aliases, inline assembly or padding operations are used.
 *
 * Reopen with independent source lifetime/control-flow evidence for the resident base and entry
 * snapshots, followed by a measured binding/placement of the retail dispatch table at USA
 * 0x002A1CE0. Equal function size does not establish instruction identity. No strict linked
 * build or runtime validation is claimed.
 *
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por
 * -frac2-keep-block-order -frac2-gcse-unsplit-edges
 */
/* Oozla hero-state dispatcher. Manual reconstruction against fresh retail;
   the retained Dobbo Orbit controller is a semantic reference only. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned int U128 __attribute__((mode(TI)));
typedef struct { int a, b, c, d; } Quad16 __attribute__((aligned(16)));
typedef struct { float x, y, z, w; } Vec4 __attribute__((aligned(16)));

typedef int TI128 __attribute__((mode(TI)));
typedef int V4_F6a70b950 __attribute__((mode(TI)));
typedef int V4_Fe23fe324 __attribute__((mode(TI)));
typedef struct { float x, y, z; } FamilyC94396F4Vector_Fc94396f4;
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
typedef int V4_L00_00338D28 __attribute__((mode(TI)));

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u32 w4;
    u8 b8;
    u8 b9;
    u16 s_a;
    float f_c;
    V4_L00_00338D28 v10;
    V4_L00_00338D28 v20;
} Obj_L00_00338D28;

/* Accessed resident prefix; this does not assert the complete player size. */
typedef struct PlayerHeroView {
    u8 prefix[0x80];
    Vec4 position, rotation;
    u8 padA0[0xF0 - 0xA0];
    Vec4 velocity, additional, displacement, actual, planar, normal;
    Vec4 additionalDisplacement, pendingResult;
    float distance, planarDistance, forwardDistance, slope, height, additionalDistance;
    u8 pad188[8];
    Vec4 direction;
    float heading, yawSpeed, angle, rotationRate, speed, targetSpeed;
    int frame;
    u8 pad1BC[4];
    int stateTimer, animationTimer;
    u8 pad1C8[0x2290 - 0x1C8];
    u8 *object;
    u32 state;
    int substate;
    u8 tail[0x2500 - 0x229C];
} PlayerHeroView;
extern PlayerHeroView D_00189E20;

#define H(type, offset) (*(type *)(((u8 *)&D_00189E20) + (offset)))
#define HP(offset) ((void *)(((u8 *)&D_00189E20) + (offset)))

extern unsigned char D_0018C750[], D_00188660[];
extern unsigned int D_001A7390, D_001A79F0, D_00138320;
extern int D_00138354;
extern unsigned char D_001A7B0B, D_001A7B2A;
extern unsigned char D_L01_001B96F0[], D_L01_0025EC90[];
extern float D_L01_001B94D8, D_L01_001B9500, D_L01_001ACEE8[];
extern int D_L01_001A9030, D_L01_001B9508, D_L01_001B94EC;
extern void *D_L01_001C3980[];

extern void func_L00_002AA938(int, int, int);
extern void func_L00_002A9E30(float, float, float, float);
extern void func_L00_002AA0F0(float, float, float);
extern int func_L00_002ADEA0(int);
extern int func_L01_002AE128(void *, void *, void *);
extern void func_L00_002AC578(void);
extern void func_L00_002B35A0(void);
extern int func_L00_002B3998(float);
extern void func_L00_002B39F0(int, float);
extern void func_L01_002B46A0(void);
extern void func_L00_002B3EF8(int, float, float, float);
extern void func_L00_002B3F68(void);
extern void func_L00_002B41B8(float, float);
extern void func_L00_002B4208(float);
extern void func_L00_002B42D8(void *);
extern void func_L00_002B54F8(float, float);
extern float func_L00_002B5590(void *);
extern void func_L00_002B6560(void);
extern void func_L01_002B7360(void);
extern void func_L00_002B75A0(float, float, float);
extern void func_L00_002B7B80(void);
extern void func_L00_002B8CB8(void);
extern void func_L00_002B94D8(float);
extern float func_L00_002B9B38(void *, int);
extern int func_L00_002B9B88(int index, int flags);
extern void func_L00_002B9BB0(int, void *, int);
extern void func_L00_002B9F00(float, float, float);
extern void func_L00_002BA508(void);
extern int func_L00_002CAF20(void);
extern void func_L00_002D2168(int, int, float);
extern void func_L00_002D34C0(FamilyC94396F4Vector_Fc94396f4 *, FamilyC94396F4Vector_Fc94396f4 *, float);
extern void func_L00_002D36E0(float *, int, float, float, float);
extern void func_L00_002D3778(FamilyC94396F4Vector_Fc94396f4 *, FamilyC94396F4Vector_Fc94396f4 *, float);
extern void func_L00_002D3798(V4_F6a70b950 *, V4_F6a70b950 *, float);
extern void func_L00_002D38A0(V4_Fe23fe324 *, V4_Fe23fe324 *, float);
extern void func_L00_002D3960(char *, char *);
extern float func_L00_002D3A58(char *);
extern float func_L00_002D3B00(char *);
extern void func_L00_002D3BD8(char *, int, float);
extern int func_L00_002D6900(unsigned int index);
extern void func_L00_00322BE0(void *, int);
extern float func_L00_0032F038(int);
extern void func_L00_0041E958(float, float, float);
extern void func_L01_002B4DA0(int);

extern int func_002761F8(void *, void *, int, void *, int);
extern int func_00277F48(void *, int, void *, void *, float);
extern float func_00282C48(float);
extern void func_00282C88(TI128 *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern float func_00282E20(void *);
extern float func_00282E48(void *, void *);
extern float func_00282E80(void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00283098(void *, void *, void *);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_00283248(float, float);
extern float func_00283B98(float, float);
extern float func_00283BE0(float, float);
extern float func_00283C80(float, float);
extern int func_00283CF0(float);
extern void func_002A8C00(char *, int, int, float, Quad16 *);
extern void func_002A8F70(void *, void *, int, void *, void *, float);
extern float func_002AA2E8(float *, float, float);
extern float func_002AA3A8(float *, float *, float, float, float, float);
extern float func_002AA738(float, int, float);
extern void func_002AA800(float *, int, float, float);
extern float func_002AA898(float *, float *, int, float, float, float, float);
extern int func_002ABB78(char *);
extern void func_002AC9F8(float *, float);
extern void func_002E59F8(int);

extern float func_00282DB0(void *, void *);
extern void func_00290010(int, int, int, float);
extern float func_002A7878(float, float);
extern float func_002AA458(void *, void *, void *, float, float, float);
extern void func_L00_002A9D38(float *, float *, float);
extern void func_L00_002AB0A8(float, float);
extern void func_L00_002AB0D8(float, float);
extern void func_L00_002AB0F0(float, float);
extern void func_L00_002B3DC0(float, float, float);
extern void func_L00_002B4308(void);
extern void func_L01_002B6948(float);
extern void func_L00_002D3B58(V4_F6a70b950 *, V4_F6a70b950 *, float);
extern int func_L00_002EE4D8(void *, void *, float);
extern int func_L00_0031D620(int, int, float);
extern u32 D_00138324;
extern float D_L01_0025D220, D_L01_0025D228;
extern void func_L00_002AB0C0(float,float);
extern void func_L00_002BA138(void *,int);
extern void func_L00_00322A98(void *, char *);
extern void func_L00_00322AC0(List_F66766f2b *, int, int, float);
extern Obj_L00_00338D28 *func_L00_00338D28(char *, char *, float);
extern unsigned char D_L01_0025D110[];
extern float D_L01_001A7DB0, D_L01_001A7DB4, D_L01_001A7DC0;
extern float D_L01_001B9748;
extern s32 func_L00_00325FC8(float *angle, s32 first_color, s32 second_color, float step);

typedef struct HeroContact {
    Vec4 position;
    Vec4 normal;
    unsigned char details[0x3C - 0x20];
} HeroContact;


void func_L01_002BA1C0(void)
{
    u32 entry_state = D_00189E20.state;
    u8 *entry_object = D_00189E20.object;
    int entry_substate = D_00189E20.substate;
    u8 entry_animation = entry_object[0x43];
    float shared_scale, shared_speed;
    void *shared_source;
    int shared_mode;

    /* Only one state arm runs per invocation. Its temporary vectors and probe
     * records share storage; every pointer passed to a common tail is resident. */
    union {
        struct {
            Vec4 forward;
        } state_00;
        struct {
            Vec4 delta;
            Vec4 movement;
            Vec4 origin;
            Vec4 force;
            unsigned char contact[48] __attribute__((aligned(16)));
        } state_14;
        struct {
            Vec4 impulse;
            Vec4 point;
            unsigned char query[48] __attribute__((aligned(16)));
        } state_1f;
        struct {
            Vec4 impulse;
        } state_02;
        struct {
            Vec4 local;
            Vec4 target_position;
            Vec4 impulse;
        } state_7b;
        struct {
            Vec4 position;
            Vec4 velocity;
        } state_30;
        struct {
            Vec4 direction;
            Vec4 side;
            Vec4 candidate;
            HeroContact contact;
        } state_19;
        struct {
            Vec4 origin;
            Vec4 endpoint;
            Vec4 force;
        } state_07;
        struct {
            Vec4 difference;
        } state_62;
        struct {
            Vec4 difference;
        } state_63;
    } workspace;

    switch (entry_state) {
case 0: case 1: case 3: case 4: case 28: case 29: case 30:
case 57: case 109: case 111: case 125:
{
    float step;
    func_L00_002B54F8(0.5f, 0.033333335f);
    func_L00_002B9F00(3.7f, 0.0f, 0.35f);
    func_L00_002B39F0(0, 1.0f);
    if ((D_00189E20.state == 1 || D_00189E20.state == 29) && H(u8, 0x22B5)) {

        *(U128 *)&workspace.state_00.forward = 0;
        workspace.state_00.forward.x = 1.0f;
        func_00283098(((void *)&D_00189E20.direction), &workspace.state_00.forward, D_L01_001B96F0);
        D_00189E20.heading = D_L01_001B94D8;
        func_L00_002B3EF8(0, 1.0f, 0.0f, 2.9088826f);
        if (H(u8, 0x22BB) && D_00189E20.frame == 120) {
            unsigned int clock;
            if (*(s16 *)(D_0018C750 + 0xD8) != -1) {
                ++*(s16 *)(D_0018C750 + 0xD8);
            }
            clock = D_001A7390;
            if (*(u32 *)(D_0018C750 + 0xDC) < clock)
                *(u32 *)(D_0018C750 + 0xDC) = clock;
            *(u32 *)(D_0018C750 + 0xE0) |= (1U << (D_001A79F0 & 31)) | 0x80000000U;
        }
    }
    if (D_00189E20.state == 3 && func_L00_002CAF20()) goto finish;
    if (D_00189E20.state == 4 &&
        (H(float, 0x24B8) > 0.2f || D_00189E20.object[0x43] == 14 || D_00189E20.object[0x43] == 15)) {
        func_L00_002B3EF8(0, 0.002f, 0.07f, 0.1163553f);
        if (func_00282C48(D_00189E20.yawSpeed) > 0.0058177654f) {
            int anim = 14 + (D_00189E20.yawSpeed < 0.0f);
            if (D_00189E20.object[0x43] != anim)
                func_L00_002D2168(anim, 0, 5.0f);
            H(float, 0xC20) = func_00282C48(D_00189E20.yawSpeed) * 18.093401f;
            if (H(float, 0xC20) < 0.55f) H(float, 0xC20) = 0.55f;
            if (H(float, 0xC20) > 2.5f) H(float, 0xC20) = 2.5f;
        } else if (D_00189E20.yawSpeed == 0.0f && D_00189E20.object[0x43] != 13) {
            func_L00_002D2168(13, 0, 7.0f);
        }
    }
    D_00189E20.speed = 0.0f;
    if (D_00189E20.state == 3) {
        step = D_00189E20.slope + 1.0f;
        if (step > 1.0f) step = 1.0f;
        step *= 0.0075000003f;
        H(float, 0x24AC) = step;
        if (D_00189E20.object[0x42] == D_00189E20.object[0x43]) {
            if (D_00189E20.planarDistance / step > 5.0f && (float)D_00189E20.object[0x41] < 5.5f) {
                func_L00_002A9E30(13.0f, D_00189E20.planarDistance / step, 0.5f, -1.0f);
                if (H(float, 0xC20) > 1.1f) H(float, 0xC20) = 1.1f;
            } else if ((float)D_00189E20.object[0x41] > 6.5f) H(float, 0xC20) = 1.0f;
        }
    } else if (D_00189E20.state == 4) {
        step = 0.0075000003f;
    } else step = 0.004916667f;
    func_L00_002B41B8(0.0f, step);
    func_00282C88((TI128 *)(((void *)&D_00189E20.velocity)));
    func_L00_002B94D8(step);
    if (!H(u8, 0x1497) || !D_001A7B0B) {
        /* Shared movement tail: mode is zero on this edge. */
        shared_mode = 0;
        goto shared_002BF77C;
    }
    if (H(float, 0x31C) > 0.2f) {
        func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), (FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.actual)), 0.0061111115f);
        goto finish;
    }
    func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), (FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), 0.015000001f);
    if (H(int, 0x33C)) {
        *(U128 *)&D_00189E20.position = H(U128, 0x2D0);
        H(s16, 0x34E) = 0;
        H(float, 0x31C) = 0.0f;
    }
    goto finish;
}


case 2: case 112:
{
    float weight, turn_step, angle, factor;
    if (!H(s16, 0x1454)) {
        float first_angle, second_angle;
        if (D_00189E20.planarDistance < 0.028333336f) {
            H(u8, 0x40C) = 1;
            if (func_00282C48(D_00189E20.angle) > 2.0943954f && H(float, 0x24B8) == 1.0f)
                H(u8, 0x40F) = 1;
        }
        first_angle = func_L00_0032F038(1);
        second_angle = func_L00_0032F038(7);
        if (func_00283C80(first_angle, second_angle) > 1.9198624f &&
            func_00282C48(D_00189E20.angle) > 1.2217306f && H(float, 0x24B8) == 1.0f) {
            H(u8, 0x40C) = 1;
            H(u8, 0x40F) = 1;
        }
        if (func_00282C48(D_00189E20.angle) < 0.087266475f) H(u8, 0x40C) = 0;
    }
    if (H(u8, 0x40F) && func_00282C48(D_00189E20.angle) < 0.06981318f) H(u8, 0x40F) = 0;
    if (H(float, 0x24B8) < 0.2f) {
        if (H(int, 0x410)) H(u8, 0x40F) = 1;
        D_00189E20.speed = 0.0f;
        D_00189E20.direction = H(Vec4, 0x3F0);
        D_00189E20.heading = H(float, 0x408);
    } else {
        func_L01_002B46A0();
        if (func_L00_002ADEA0(0) == 10 && (H(float, 0x24BC) == 1.0f || H(int, 0x410)) && !H(u8, 0x22BA)) {
            H(Vec4, 0x3F0) = D_00189E20.direction;
            H(int, 0x410) = 1;
            H(float, 0x408) = D_00189E20.heading;
        } else {
            H(Vec4, 0x3F0) = H(Vec4, 0x0);
            H(float, 0x408) = D_00189E20.rotation.z;
        }
    }
    if (H(float, 0xA70) > 0.0f) {

        func_L00_002B54F8(0.7f, 0.0f);
        workspace.state_02.impulse = H(Vec4, 0xA60);
        D_00189E20.speed += func_L00_002B5590(&workspace.state_02.impulse);
        if (D_00189E20.speed < 0.011666667f) D_00189E20.speed = 0.011666667f;
        func_00282C88((TI128 *)(HP(0xA60)));
    }
    weight = 1.0f;
    if (!H(s16, 0x1454)) {
        H(float, 0x1458) = D_00189E20.rotation.z;
        H(Vec4, 0x1440) = H(Vec4, 0x0);
        if (D_00189E20.substate == 1 && !H(u8, 0x40F) && !H(u8, 0x22BA)) {
            func_L00_002B3EF8(0, 0.02f, 0.17f, 0.16580631f);
        } else {
            angle = func_00282C48(D_00189E20.angle);
            if ((H(float, 0x24B8) < 0.9f || (H(u8, 0x22BA) && !H(u8, 0x40F))) && angle > 0.78539824f)
                weight = 0.0f;
            func_L00_002B3F68();
        }
    } else func_L00_002B35A0();
    func_L00_002B7B80();
    func_L00_002B8CB8();
    if (H(u8, 0x40F)) {
        factor = 0.09916667f - func_00282C48(D_00189E20.angle) * 0.029178405f;
        if (factor < 0.0f) factor = 0.0f;
        if (D_00189E20.speed > factor) D_00189E20.speed = factor;
    }
    weight *= 0.005f;
    turn_step = 0.0055555557f;
    if (H(u8, 0x40F)) {
        factor = 2.617994f - D_00189E20.angle;
        if (factor > 1.0f) factor = 1.0f;
        if (factor < 0.2f) factor = 0.2f;
        D_00189E20.speed *= factor;
        turn_step = 0.004722222f;
    }
    angle = func_00282C48(D_00189E20.angle);
    if (H(float, 0x24B8) < 0.75f && angle > 0.6108653f) {
        factor = 1.0f - angle * 0.4f;
        if (factor < 0.0f) factor = 0.0f;
        D_00189E20.speed *= factor;
    }
    func_L00_002B41B8(weight, turn_step);
    if (!H(u8, 0x40C) && !H(s16, 0x1454)) func_L00_002B4208(99999.0f);
    else if (!H(u8, 0x22C3)) func_L00_002B4208(H(s16, 0x1454) ? H(float, 0x1458) : D_00189E20.heading);
    else func_L00_002B42D8(H(s16, 0x1454) ? HP(0x1440) : ((void *)&D_00189E20.direction));
    func_L01_002B4DA0(1);
    if (H(s16, 0x214)) func_L00_002B9F00(5.0f, 0.2f, 0.35f);
    shared_source = ((void *)&D_00189E20.planar);
    if (H(s16, 0x34E)) {
        shared_scale = 0.0069444445f;
        goto shared_002C8084;
    }
    goto shared_002C80A0;
}


case 6: case 44:
    func_L01_002B46A0();
    if (!H(s16, 0x1E0)) func_L01_002B7360();
    func_L00_002B7B80();
    func_L00_002B54F8(0.7f, 0.0f);
    goto limit_falling_speed;

case 7: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
case 16: case 17: case 18: case 27: case 56: case 69: case 72:
case 91: case 102: case 110: case 129: case 137: case 146:
{
    float magnitude, saved_speed;
    if (D_00189E20.state == 27 && !H(s16, 0x24FC) && H(int, 0x1338) == 3 && func_L00_002B3998(10.0f))
        func_L00_002B9B88(4, 0);
    if (!H(s16, 0x528) || !H(u8, 0x1492)) {
        if (H(u8, 0x49C)) func_L00_002B39F0(0, 0.09916667f);
        func_L00_002B39F0(0, H(float, 0x4A4));
    } else D_00189E20.speed = D_00189E20.targetSpeed;
    if (D_00189E20.frame == H(s16, 0x4AC)) H(Vec4, 0x460) = D_00189E20.position;
    if (!H(u8, 0x49C) && (D_00189E20.frame >= H(s16, 0x4AC) ||
        D_00189E20.state == 11 || D_00189E20.state == 16 || D_00189E20.state == 12 ||
        D_00189E20.state == 17 || D_00189E20.state == 27 || D_00189E20.state == 137 || D_00189E20.state == 72)) {
        func_L01_002B7360();
    } else {
        func_L00_002B3EF8(0, 0.015f, 0.2f, 0.2501639f);
        saved_speed = D_00189E20.targetSpeed;
        if (H(u8, 0x49C) > 1) D_00189E20.targetSpeed *= 0.4f;
        func_L00_002B4208(H(s16, 0x1454) ? H(float, 0x1458) : 99999.0f);
        D_00189E20.targetSpeed = saved_speed;
        if (H(u8, 0x49C) != 1) func_L00_002B41B8(H(float, 0x500), H(float, 0x504));
        if (H(u8, 0x49C)) {
            if (D_00138354 && H(s16, 0x34A)) D_00189E20.targetSpeed = 0.0f;
            if (H(u8, 0x49C)) func_L00_002B94D8(H(float, 0x504));
        }
        func_L00_002B54F8(0.5f, 0.033333335f);
        if (D_00189E20.state == 9 && D_00189E20.frame < H(s16, 0x4AC) + 4)
            func_L00_002D3798((V4_F6a70b950 *)(((void *)&D_00189E20.velocity)), (V4_F6a70b950 *)(((void *)&D_00189E20.velocity)), D_00189E20.frame * 0.0044444446f);
        if (D_00189E20.state == 10 && D_00189E20.frame < 34)
            func_L00_002D3798((V4_F6a70b950 *)(((void *)&D_00189E20.velocity)), (V4_F6a70b950 *)(((void *)&D_00189E20.velocity)), D_00189E20.frame * 0.014722222f);
        if (D_00189E20.frame < 10 && H(float, 0x24B8) > 0.2f) {

            workspace.state_07.origin = D_00189E20.position;
            func_L00_002D38A0((V4_Fe23fe324 *)(&workspace.state_07.origin), (V4_Fe23fe324 *)(&workspace.state_07.origin), 0.5f);
            func_L00_002D3798((V4_F6a70b950 *)(&workspace.state_07.endpoint), (V4_F6a70b950 *)(&workspace.state_07.origin), 0.95f);
            if (func_002761F8(&workspace.state_07.origin, &workspace.state_07.endpoint, 4, D_00189E20.object, 0)) H(u32, 0x524) = 1;
        }
    }
    if (H(float, 0x490) < H(float, 0x318)) {
        H(float, 0x490) += 0.10000001f;
        if (H(float, 0x490) > H(float, 0x318)) H(float, 0x490) = H(float, 0x318);
    }
    if (H(float, 0x490) > D_00189E20.position.z) H(float, 0x490) = D_00189E20.position.z;
    if (D_00189E20.frame > H(s16, 0x4AC) && func_L00_002D3B00((char *)(((void *)&D_00189E20.velocity))) < 0.001f &&
        (!H(u8, 0x49D) || H(int, 0x434) < D_00189E20.frame) &&
        (D_00189E20.state != 14 || D_00189E20.frame > 17)) {
        H(u8, 0x49E) = 1;
        if (H(float, 0x458) != 0.0f) H(float, 0x520) = H(float, 0x458);
    }
    if (!H(u8, 0x22B4)) func_L00_002B7B80();
    if (D_00189E20.state == 16 || D_00189E20.state == 13)
        func_L00_00322BE0(HP(0x18E0), D_00189E20.frame < 13 ? 0 : 2);
    if (D_00189E20.state == 129)
        func_L00_00322BE0(HP(0x18E0), D_00189E20.frame < 14 ? 0 : 2);
    if (D_00189E20.state == 16 && D_00189E20.frame > 8 && H(float, 0xC38) < 28.0f) {

        int count, i;
        func_L00_002D36E0((float *)(&workspace.state_07.origin), 1, 0.8f, 0.0f, 0.3f);
        count = func_00277F48(&workspace.state_07.origin, 0, D_00189E20.object, 0, 0.9f);
        if (count) {
            func_00282D30(&workspace.state_07.force, ((void *)&D_00189E20.displacement), 7.0f);
            for (i = 0; i < count; i++) {
                void *object = D_L01_001C3980[i];
                if (func_002ABB78((char *)(object)))
                    func_002A8F70(object, D_00189E20.object, 0x10000, ((void *)&D_00189E20.position), &workspace.state_07.force, 1.0f);
            }
        }
    }
    func_L00_002B6560();
    goto shared_002C6844;
}


case 8:
{
    int slot;
    float speed, damping, magnitude;
    if (func_L00_002ADEA0(3) == 2) {
        slot = H(int, 0x243C);
        if (slot != -1 && *(void **)(D_00188660 + slot * 0x70 + 0x88) == D_00189E20.object &&
            D_00188660[slot * 0x70 + 0x74]) func_002E59F8(slot);
        H(int, 0x243C) = -1;
        func_L00_002B9BB0(3, D_00189E20.object, 2);
    } else {
        slot = H(int, 0x2438);
        if (slot != -1 && *(void **)(D_00188660 + slot * 0x70 + 0x88) == D_00189E20.object &&
            D_00188660[slot * 0x70 + 0x74]) func_002E59F8(slot);
        H(int, 0x2438) = -1;
        func_L00_002B9BB0(4, D_00189E20.object, 13);
    }
    speed = H(int, 0x1338) == 3 ? 0.083333336f : 0.050000004f;
    damping = 0.72f;
    if (H(u8, 0x24EF)) { speed = 0.12833333f; damping = 0.98640007f; }
    if (H(float, 0x24C8) != 0.0f) damping = H(float, 0x24C8);
    magnitude = func_L00_002D3B00((char *)(((void *)&D_00189E20.velocity)));
    func_L00_002B39F0(0, speed);
    func_L00_002B3EF8(0, 0.025f, 0.3f, 0.20943955f);
    func_L00_002B41B8(0.004166667f, 0.0019444445f);
    func_L00_002B4208(99999.0f);
    func_L00_002B7B80();
    func_L00_002D3960((char *)(((void *)&D_00189E20.velocity)), (char *)(((void *)&D_00189E20.velocity)));
    func_002AA3A8((float *)(&magnitude), (float *)(HP(0xA98)), -speed * damping, 0.025f, 0.3f, 0.28333336f);
    func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), (FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), -magnitude);
    if (D_00189E20.position.z < H(float, 0x490)) func_002AA2E8((float *)(HP(0x490)), D_00189E20.position.z, 0.06666667f);
shared_002C6844:
    func_L00_002AC578();
    goto finish;
}


case 19:
{
    unsigned char *animation = D_L01_0025EC90 + H(s16, 0xBFC) * 44;
    int kind, steer;
    float scale, distance, radius, limit, angle, magnitude;
    if (H(int, 0xC2C) || H(float, 0xC38) < (float)*(int *)(animation + 32)) H(u8, 0x1239) = 2;
    D_00189E20.speed = 0.0f;
    scale = H(float, 0xBF4);
    if (H(void *, 0xBE4) && D_00189E20.frame <= 3) {
        distance = func_00282E80(H(u8 *, 0xBE4) + 16, ((void *)&D_00189E20.position));
        if (D_L01_001A9030) distance = func_00282E48(H(u8 *, 0xBE4) + 16, ((void *)&D_00189E20.position));
        distance -= 0.5f;
        if (distance < 0.0f) distance = 0.0f;
        kind = *(int *)(animation + 4);
        if (kind == 0) { radius = 0.8f; limit = 4.0f; distance -= 0.75f; }
        else if (kind == 1) { radius = 1.7f; limit = 4.0f; distance -= 0.6f; }
        else { radius = 1.7f; limit = 1.9f; distance -= 1.3f; }
        if (func_00282C48(distance) < radius + 3.0f) {
            scale = distance * 1.1111112f;
            if (scale > limit) scale = limit;
            if (scale <= 1.0f) scale = H(float, 0xBF4);
            H(float, 0xBF4) = scale;
        }
    } else H(float, 0xBF4) = scale;
    kind = *(int *)(animation + 4);
    if (kind == 1) {
        if (H(int, 0xC2C) || H(float, 0xC38) < 9.0f) {
            if (H(float, 0xC38) > 8.0f) D_00189E20.speed = 0.050000004f;
            else if (H(float, 0xC38) > 7.0f) D_00189E20.speed = 0.075f;
            else D_00189E20.speed = 0.095f;
            D_00189E20.speed *= H(float, 0xBF4);
        }
    } else if (kind == 0) {
        if (H(float, 0xC38) < 18.0f) D_00189E20.speed = H(float, 0xBF4) * 0.07333334f;
    } else if (kind == 2 && (H(int, 0xC2C) || H(float, 0xC38) < 12.0f)) {
        D_00189E20.speed = H(float, 0xBF4) * 0.06166667f;
    }
    func_002AA2E8((float *)(HP(0xC20)), 1.0f, 0.2f);
    if (!H(int, 0xBE8) && !H(void *, 0xBE4)) {
        steer = !(*(int *)(animation + 4) == 1 && !H(int, 0xC2C) && H(float, 0xC38) > 7.0f);
        if (steer) func_L00_002B75A0(5.0f, 0.78539824f, 0.78539824f);
    } else {
        angle = H(u8, 0x22C3) ? func_L00_002B9B38(HP(0xBC0), 0) :
                               func_00283BE0(H(float, 0xBEC), D_00189E20.rotation.z);
        magnitude = func_00282C48(angle);
        if (*(int *)(animation + 4) == 1 && angle > 0.0f) H(float, 0xC20) = 1.0f / (magnitude + 1.0f);
        D_00189E20.heading = H(float, 0xBEC);
        D_00189E20.direction = H(Vec4, 0xBC0);
        func_L00_002B3EF8(0, 0.05f, 0.2f, 0.2821616f);
    }
    func_L00_002B41B8(0.010277778f, 0.007777778f);
    if (!H(int, 0xBE8)) func_L00_002B4208(99999.0f);
    else if (!H(u8, 0x22C3)) func_L00_002B4208(H(float, 0xBEC));
    else func_L00_002B42D8(HP(0xBC0));
    if (H(s16, 0x34E)) func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), (FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.planar)), 0.0069444445f);
    else func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), (FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), 0.015000001f);
    func_L00_002B9F00(3.7f, 0.0f, 0.35f);
    goto finish;
}


case 20:
{
    unsigned char *animation = D_L01_0025EC90 + H(s16, 0xBFC) * 44;
    float distance, limit, magnitude;
    int accelerate;
    if (H(int, 0xC2C) || H(float, 0xC38) < (float)*(int *)(animation + 24)) H(u8, 0x1239) = 2;
    D_00189E20.speed = 0.0f;
    accelerate = H(u8, 0x1495) || H(u8, 0x1496) || H(u8, 0x149B) || H(float, 0x31C) > 4.0f;
    if (!H(void *, 0xBE4)) {
        if (accelerate && D_00189E20.frame < 70) D_00189E20.speed = 0.075f;
        func_L00_002B41B8(0.004166667f, 0.004166667f);
        func_L00_002D3BD8((char *)(((void *)&D_00189E20.velocity)), (int)(((void *)&D_00189E20.velocity)), D_00189E20.targetSpeed);
    } else {

        func_00282CF0(&workspace.state_14.delta, H(u8 *, 0xBE4) + 16, ((void *)&D_00189E20.position));
        distance = func_L00_002D3A58((char *)(&workspace.state_14.delta));
        if ((distance > 2.0f && distance < 5.0f) || accelerate) D_00189E20.speed = 0.075f;
        func_L00_002B41B8(0.0069444445f, 0.0069444445f);
        func_00282F20(&workspace.state_14.movement, HP(0x0), D_00189E20.targetSpeed);
        func_L00_002D3BD8((char *)(((void *)&D_00189E20.velocity)), (int)(((void *)&D_00189E20.velocity)), 0.0f);
        func_00282CC0(((void *)&D_00189E20.velocity), ((void *)&D_00189E20.velocity), &workspace.state_14.movement);
    }
    if (!H(int, 0xBE8) && !H(void *, 0xBE4)) {
        if (H(float, 0xC38) < 25.0f) func_L00_002B75A0(8.0f, 1.0471977f, 1.0471977f);
    } else {
        D_00189E20.heading = H(float, 0xBEC);
        D_00189E20.direction = H(Vec4, 0xBC0);
        func_L00_002B3EF8(0, 0.05f, 0.2f, 0.2821616f);
    }
    limit = 0.12833333f;
    if (H(float, 0x31C) > 2.25f) limit = 0.064166665f;
    else if (H(float, 0x31C) > 1.8f) limit = 0.0898333266f;
    if (!H(int, 0xC2C) && H(float, 0xC38) > 23.5f && D_00189E20.displacement.z < 0.0f && H(s16, 0x34E)) {


        workspace.state_14.origin = D_00189E20.position;
        func_L00_002D3778((FamilyC94396F4Vector_Fc94396f4 *)(&workspace.state_14.origin), (FamilyC94396F4Vector_Fc94396f4 *)(&workspace.state_14.origin), -0.5f);
        func_00282F20(&workspace.state_14.force, HP(0x0), 2.0f);
        func_002A8C00((char *)(workspace.state_14.contact), (int)(D_00189E20.object), 0x10000, 2.0f, (Quad16 *)(&workspace.state_14.force));
        *(u32 *)(workspace.state_14.contact + 12) = 0x45AFDF66;
        workspace.state_14.contact[24] = 0;
        workspace.state_14.contact[25] = 1;
        *(u16 *)(workspace.state_14.contact + 26) = 71;
        func_00277F48(&workspace.state_14.origin, 0x10, D_00189E20.object, workspace.state_14.contact, 0.4f);
    }
    if (func_L00_002B3998(25.7f)) {
        func_L00_002D6900(25);
        H(u16, 0x1FA) = 50;
        if (D_001A7B2A) {
            D_L01_001B9500 = 0.1f;
            H(u16, 0x224) = 35;
            D_L01_001B9508 = 30;
            D_L01_001B94EC = 0;
        }
    }
    if (D_00189E20.frame < 9) {
        magnitude = func_L00_002D3B00((char *)(((void *)&D_00189E20.velocity)));
        func_002AA2E8((float *)(&magnitude), limit, 0.041666668f);
        shared_speed = magnitude;
    } else {
        if (D_00189E20.frame < 15) goto finish;
        func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), (FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), 0.036111113f);
        magnitude = func_L00_002D3B00((char *)(((void *)&D_00189E20.velocity)));
        if (magnitude < 0.0f) H(float, 0xC00) = 1.0f;
        shared_speed = D_L01_001A9030 ? -1.1666667f : -0.6166667f;
        magnitude = func_L00_002D3B00((char *)(((void *)&D_00189E20.velocity)));
        if (!(magnitude < shared_speed)) goto finish;
    }
    goto shared_002C8248;
}


case 21: case 131:
{
    unsigned char *animation = D_L01_0025EC90 + H(s16, 0xBFC) * 44;
    float angle, correction, speed, heading;
    int steer;
    D_00189E20.speed = 0.0f;
    if (H(int, 0xC2C) || H(float, 0xC38) < (float)*(int *)(animation + 24)) H(u8, 0x1239) = 2;
    if (!(H(int, 0x22A0) == 1 && H(int, 0x22A8) >= 21)) {
        if (!H(int, 0xBE8) && !H(void *, 0xBE4)) {
            steer = 1;
            if (D_00189E20.state == 131 && D_00189E20.frame > 11) steer = 0;
            else if (!H(int, 0xC2C) && H(float, 0xC38) > 6.0f) steer = 0;
            if (steer) {
                if (D_00189E20.state == 21) func_L00_002B75A0(14.0f, 0.52359885f, 0.78539824f);
                else func_L00_0041E958(64.0f, 0.17453295f, 0.3490659f);
            }
        } else {
            if (!H(u8, 0x22C3)) {
                angle = func_00283BE0(H(float, 0xBEC), D_00189E20.rotation.z);
                correction = func_002AA738(H(float, 0xBEC), 1, D_00189E20.rotation.z);
            } else {
                angle = func_L00_002B9B38(HP(0xBC0), 0);
                correction = func_L00_002B9B38(HP(0xBC0), 1);
            }
            if (angle > 0.0f) H(float, 0xC20) = 1.0f / (correction + 1.0f);
            D_00189E20.heading = H(float, 0xBEC);
            D_00189E20.direction = H(Vec4, 0xBC0);
            func_L00_002B3EF8(correction < 4.3633237f, 0.057f, 0.2f, 0.2821616f);
        }
    }
    if (!H(int, 0xC2C) && D_00189E20.object[0x43] == 26 && func_L00_002B3998(33.0f)) {
        if (D_00189E20.state == 21) func_L00_002BA508();
    }
    func_L00_002B41B8(0.010277778f, 0.007777778f);
    func_L00_002B4208(99999.0f);
    shared_source = ((void *)&D_00189E20.planar);
    if (!H(s16, 0x34E)) goto shared_002C80A0;
    shared_scale = 0.0069444445f;
    goto shared_002C7AA8;
}


case 22:
{
    float speed = func_L00_002D3A58((char *)(((void *)&D_00189E20.velocity)));
    if (!H(s16, 0x34E) && D_00189E20.frame >= 11) speed -= 0.0027777778f;
    else speed -= 0.0011111111f;
    if (speed < 0.0f) speed = 0.0f;
    if (H(u8, 0x1497)) func_L00_002B9F00(3.7f, 0.0f, 0.35f);
    func_L00_002D3BD8((char *)(((void *)&D_00189E20.velocity)), (int)(((void *)&D_00189E20.velocity)), speed);
    shared_scale = 0.004f;
    goto shared_002C80AC;
}


case 23: case 24:
    func_00282CF0(((void *)&D_00189E20.direction), HP(0x560), HP(0x550));
    D_00189E20.heading = func_00283248(D_00189E20.direction.x, D_00189E20.direction.y);
    func_L00_002B3EF8(0, 0.04f, 0.2f, 0.10471977f);
    if (H(u8, 0x22C3) != 2) func_002AA800((float *)(HP(0x94)), 0, 0.0f, 0.078539826f);
    func_00282CF0(((void *)&D_00189E20.velocity), HP(0x550), ((void *)&D_00189E20.position));
    func_002AC9F8((float *)(((void *)&D_00189E20.velocity)), 0.06666667f);
    goto shared_002C56BC;


case 25: case 26:
{

    func_00282CF0(((void *)&D_00189E20.direction), HP(0x560), HP(0x550));
    D_00189E20.heading = func_00283248(D_00189E20.direction.x, D_00189E20.direction.y);
    func_L00_002B3EF8(0, 0.02f, 0.2f, 0.078539826f);
    func_00282CF0(&workspace.state_19.direction, HP(0x560), HP(0x550));
    func_00282C88((TI128 *)(((void *)&D_00189E20.velocity)));
    if (D_00189E20.state == 25) func_00282DD8(&workspace.state_19.side, HP(0x2C0), &workspace.state_19.direction);
    else func_00282DD8(&workspace.state_19.side, &workspace.state_19.direction, HP(0x2C0));
    func_00282F20(&workspace.state_19.side, &workspace.state_19.side, 0.2f);
    func_00282CC0(&workspace.state_19.candidate, ((void *)&D_00189E20.position), &workspace.state_19.side);
    if (func_L01_002AE128(((void *)&D_00189E20.position), ((void *)&D_00189E20.rotation), 0) &&
        func_L01_002AE128(&workspace.state_19.candidate, ((void *)&D_00189E20.rotation), &workspace.state_19.contact)) {
        func_00282CF0(((void *)&D_00189E20.velocity), &workspace.state_19.contact, ((void *)&D_00189E20.position));
        func_00282F20(((void *)&D_00189E20.velocity), ((void *)&D_00189E20.velocity), D_L01_001ACEE8[func_00283CF0(H(float, 0xC38))] * 0.5f);
    }
    goto finish;
}


case 0x1F:
{
    if (H(s32,0xBE8)==0 && H(s32,0xBE4)==0) {
        if (D_00189E20.frame<4) func_L00_002B75A0(11.0f,0.87266469f,-1.0f);
    } else {
        D_00189E20.heading=H(float,0xBEC);
        func_L00_002B3EF8(0,0.05f,0.2f,0.28216159f);
    }
    D_00189E20.speed=0.0f;
    if (D_00189E20.frame>10 && D_00189E20.frame<18) D_00189E20.speed=0.3f;
    if (D_00189E20.frame==8 && D_00189E20.additionalDistance<0.33333334f) {
        func_L00_00322A98(D_00189E20.object,HP(0x18E0));
        func_L00_00322AC0(HP(0x18E0),48,2,0.0f);
        func_L00_00322AC0(HP(0x18E0),23,4,0.0f);
        func_L00_00322AC0(HP(0x18E0),12,6,0.0f);
    }
    func_L00_00322BE0(HP(0x18E0),D_00189E20.frame<19?0:5);
    if (D_00189E20.frame>10) func_L00_002B41B8(0.052777778f,0.025f);
    func_L00_002B4208(H(s32,0xBE8)==0?99999.0f:H(float,0xBEC));
    {
        u8 *target=H(u8*,0x1220);
        if (D_00189E20.state==0x1F && D_00189E20.frame>10 && D_00189E20.frame<22 && target) {


            float facing=D_00189E20.rotation.z,angle;
            int hit;
            workspace.state_1f.impulse.x=func_00283180(facing)*2.0f;
            workspace.state_1f.impulse.y=func_00283198(facing)*2.0f;
            workspace.state_1f.impulse.z=1.3f;
            func_002A8C00((char *)(workspace.state_1f.query), (int)(D_00189E20.object), 0x30000, 3.0f, (Quad16 *)(&workspace.state_1f.impulse));
            *(float*)(workspace.state_1f.query+12)=5627.9248f;
            *(u16*)(workspace.state_1f.query+24)=0x300;
            *(u16*)(workspace.state_1f.query+26)=*(u16*)(target+0xAA);
            facing=D_00189E20.rotation.z;
            workspace.state_1f.point.x=func_00283180(D_00189E20.rotation.z)*0.8f;
            workspace.state_1f.point.y=func_00283198(facing)*0.8f;
            workspace.state_1f.point.z=0.55f;
            func_00282CC0(&workspace.state_1f.point,&workspace.state_1f.point,((void *)&D_00189E20.position));
            hit=func_00277F48(&workspace.state_1f.point,0,target,workspace.state_1f.query,0.8f);
            func_L00_002BA138(target,hit);
            angle=func_00283B98(D_00189E20.rotation.z,-0.87266469f);
            workspace.state_1f.point.x=func_00283180(angle)*0.8f;
            workspace.state_1f.point.y=func_00283198(angle)*0.8f;
            workspace.state_1f.point.z=0.55f;
            func_00282CC0(&workspace.state_1f.point,&workspace.state_1f.point,((void *)&D_00189E20.position));
            hit=func_00277F48(&workspace.state_1f.point,0,D_00189E20.object,workspace.state_1f.query,0.8f);
            func_L00_002BA138(target,hit);
            angle=func_00283B98(D_00189E20.rotation.z,0.87266469f);
            workspace.state_1f.point.x=func_00283180(angle)*0.8f;
            workspace.state_1f.point.y=func_00283198(angle)*0.8f;
            workspace.state_1f.point.z=0.55f;
            func_00282CC0(&workspace.state_1f.point,&workspace.state_1f.point,((void *)&D_00189E20.position));
            hit=func_00277F48(&workspace.state_1f.point,0,target,workspace.state_1f.query,0.8f);
            func_L00_002BA138(target,hit);
        }
    }
    if (D_00189E20.frame>10) func_L00_002B9F00(3.7f,0.0f,0.35f);
    func_L01_002B4DA0(1);
    shared_source=((void *)&D_00189E20.actual);
    if (H(s16,0x34E)==0) goto shared_002C80A0;
    shared_scale=0.0061111115f;
    goto shared_002C8084;
}


case 0x22:
{
    D_00189E20.speed=0.0f;
    if (!H(s32,0xBE8)) func_L00_002B75A0(11.0f,0.87266469f,-1.0f);
    else {
        D_00189E20.heading=H(float,0xBEC);
        D_00189E20.direction=H(Vec4,0xBC0);
        func_L00_002B3EF8(0,0.04f,0.2f,0.28216159f);
    }
    func_L00_002B41B8(0.008333334f,0.009722223f);
    func_L00_002B4208(99999.0f);
    shared_source=((void *)&D_00189E20.displacement);
    if (H(s16,0x34E)==0) goto shared_002C80A0;
    shared_scale=0.015000001f;
    goto shared_002C8084;
}


case 0x2F:
    if (!H(u8, 0x1492)) func_L00_002B54F8(0.5f, 0.033333335f);
    else func_L00_002B54F8(0.7f, 0.0f);
    func_L00_002B9F00(3.7f, 0.0f, 0.35f);
    func_L00_002B39F0(0, 1.0f);
    func_L00_002B41B8(0.004916667f, 0.004916667f);
    func_00282C88((TI128 *)(((void *)&D_00189E20.velocity)));
    func_L00_002B94D8(0.004916667f);
    if (!H(s16, 0x34E)) func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), (FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), 0.015000001f);
    else {
        func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), (FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.displacement)), 0.0069444445f);
        func_L00_002B4308();
    }
    if ((D_00189E20.object[0x60] & 2) && D_00189E20.object[0x42] == 0x36)
        func_L00_002D2168(func_L01_002A7248(0), 0, 5.0f);
    goto finish;

case 0x30:
{
    u32 level=D_001A79F0;
    float oldHeading,headingChange,bank;
    if (level==0) {func_L00_002B9BB0(2,D_00189E20.object,19);level=D_001A79F0;}
    else if (level!=1) {func_L00_002B9BB0(2,D_00189E20.object,6);level=D_001A79F0;}
    if (level<2) func_L00_002AA938(4,2,1);
    else {

        float duration;
        func_L00_002AA938(4,2,0);
        workspace.state_30.position.x=D_00189E20.position.x+func_002A7878(-0.25f,0.25f);
        workspace.state_30.position.y=D_00189E20.position.y+func_002A7878(-0.25f,0.25f);
        workspace.state_30.position.z=D_00189E20.position.z+func_002A7878(-0.1f,0.4f);
        func_00282D30(&workspace.state_30.velocity,((void *)&D_00189E20.displacement),0.9f);
        workspace.state_30.velocity.x+=func_002A7878(-0.011666667f,0.011666667f);
        workspace.state_30.velocity.y+=func_002A7878(-0.011666667f,0.011666667f);
        workspace.state_30.velocity.z+=func_002A7878(0.016666668f,0.033333335f);
        duration=func_002A7878(37800.0f,75600.0f);
        func_L00_00338D28((char *)(&workspace.state_30.position), (char *)(&workspace.state_30.velocity), duration);
    }
    oldHeading=D_00189E20.rotation.z;D_00189E20.heading=H(float,0xB40);
    func_L00_002B3EF8(0,0.033f,0.3f,0.069813184f);
    headingChange=func_00283C80(D_00189E20.rotation.z,oldHeading);
    func_00282C88((TI128 *)(((void *)&D_00189E20.velocity)));func_L00_002B94D8(0.0019444445f);
    D_00189E20.velocity.z=D_00189E20.displacement.z-0.013888889f;
    if (D_00189E20.velocity.z> -0.011111111f) D_00189E20.velocity.z=-0.011111111f;
    if (headingChange>0.023271061f) headingChange=0.023271061f;
    bank=headingChange*9.0f;
    func_002AA898((float *)(((void *)&D_00189E20.rotation)), (float *)(HP(0xB54)), 0, bank*0.5f, 0.007f, 0.17f, 0.020362178f);
    func_002AA898((float *)(HP(0x94)), (float *)(HP(0xB58)), 0, -H(float,0xB44), 0.035f, 0.3f, 0.031997707f);
    func_L00_002AB0C0(0.009f,0.22f);func_L00_002AB0D8(0.04f,0.2f);func_L00_002AB0F0(0.02f,0.2f);
    D_L01_0025D228=bank*2.1f;D_L01_0025D220=bank*3.5f;
    goto finish;
}


case 0x3C: case 100:
    func_00282C88((TI128 *)(((void *)&D_00189E20.velocity)));goto finish;


case 0x60:
case 0x61:
    func_00282C88((TI128 *)(&D_00189E20.velocity));
    goto finish;

case 0x62:
{

    float distance;
    u8 mode;
    func_00282CF0(&workspace.state_62.difference, &H(Vec4, 0x18a0), &D_00189E20.position);
    D_00189E20.heading = func_00283248(workspace.state_62.difference.x, workspace.state_62.difference.y);
    distance = func_00282E20(&workspace.state_62.difference);
    if (0.200000003f < distance) {
        H(float, 0x24b8) = 1.0f;
        D_00189E20.heading = func_00283248(workspace.state_62.difference.x, workspace.state_62.difference.y);
        D_00189E20.speed = distance;
        if (D_L01_001A7DB4 <= distance) D_00189E20.speed = D_L01_001A7DC0 * 0.0166666675f;
        else D_00189E20.speed = D_L01_001A7DB0 * 0.0166666675f;
        if (H(u8, 0x22b4) == 1) D_00189E20.speed = 0.0150000006f;
    } else {
        H(float, 0x24b8) = 1.0f;
        D_00189E20.heading = H(float, 0x18ac);
        D_00189E20.speed = 0.0f;
    }
    mode = H(u8, 0x22b4);
    if (mode == 3) {
        func_L00_002B3EF8(0, 0.0299999993f, 0.300000012f, 0.0930842459f);
        goto check_mode_002C6AEC;
    }
    if (mode == 1 || mode == 0) {
        func_L00_002B3EF8(0, 0.0299999993f, 0.300000012f, 0.130899712f);
check_mode_002C6AEC:
        if (H(u8, 0x22b4) == 0) func_L00_002B7B80();
    }
    func_L00_002B41B8(1.0f * 0.00499999989f, 0.00555555569f);
    func_L00_002B4208(99999.0f);
    if (H(u8, 0x22b4) == 0) func_L01_002B4DA0(1);
    if (H(short, 0x34e) == 0) goto shared_002C80A0;
    shared_scale = 0.0069444445f;
    shared_source = &D_00189E20.displacement;
    goto shared_002C8084;
}


case 0x63:
{

    func_00282CF0(&workspace.state_63.difference, &H(Vec4, 0x18a0), &D_00189E20.position);
    if (func_00282DB0(&workspace.state_63.difference, &D_00189E20.pendingResult) < 0.0f)
        func_00282C88((TI128 *)(&D_00189E20.pendingResult));
    func_00282C88((TI128 *)(&D_00189E20.velocity));
    func_L00_002B94D8(0.0075000003f);
    func_L01_002B4DA0(0);
    if (H(short, 0x34e) == 0) goto shared_002C80A0;
    shared_scale = 0.0069444445f;
    shared_source = &D_00189E20.displacement;
    goto shared_002C8084;
}


case 0x65:
    func_00282C88((TI128 *)(&D_00189E20.velocity));
    if ((float)H(s32, 0x18c0) * 0.5f < H(float, 0x334) - D_00189E20.position.z)
        D_00189E20.velocity.z = -0.00416666688f;
    else D_00189E20.velocity.z = -0.0166666675f;
    goto finish;


case 0x74:
{
    float speed;
    H(u8, 0x22bc) = 1;
    func_002AA2E8((float *)(&H(float, 0xa88)), H(float, 0xa90), 0.00242406875f);
    func_002AA2E8((float *)(&H(float, 0xa8c)), H(float, 0xa94), 0.00242406875f);
    func_L00_002AA0F0(H(float, 0xa88), H(float, 0xa8c), 0.0f);
    speed = func_00282E20(&D_00189E20.velocity);
    func_L00_002EE4D8(&D_00189E20.velocity, &D_00189E20.velocity, speed * 0.899999976f);
    func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(&D_00189E20.velocity), (FamilyC94396F4Vector_Fc94396f4 *)(&D_00189E20.velocity), H(float, 0xa80));
    speed = func_L00_002D3B00((char *)(&D_00189E20.velocity));
    if (speed < -0.833333373f) {
        shared_speed = -0.833333373f;
        goto shared_002C8248;
    }
    goto finish;
}


case 0x76:
    D_00189E20.heading = H(float, 0x32c);
    D_00189E20.speed = 0.0916666687f;
    func_L01_002B6948(0.0069444445f);
    func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(&D_00189E20.velocity), (FamilyC94396F4Vector_Fc94396f4 *)(&D_00189E20.planar), 0.00499999989f);
    goto finish;


case 0x77:
    func_002AA2E8((float *)(&D_00189E20.targetSpeed), 0.0f, 0.00666666683f);
    if (D_L01_001A9030 == 0) {
        D_00189E20.velocity.x = func_00283180(H(float, 0xbf0)) * D_00189E20.targetSpeed;
        D_00189E20.velocity.y = func_00283198(H(float, 0xbf0)) * D_00189E20.targetSpeed;
        if (0.0f < H(float, 0x31c)) D_00189E20.velocity.z = D_00189E20.actual.z - 0.0069444445f;
        else D_00189E20.velocity.z = 0.0f;
        D_00189E20.heading = func_00283B98(H(float, 0xbf0), 3.14159274f);
    } else {
        func_00282F20(&D_00189E20.velocity, &H(Vec4, 0xbd0), D_00189E20.targetSpeed);
        if (0.0f < H(float, 0x31c))
            func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(&D_00189E20.velocity), (FamilyC94396F4Vector_Fc94396f4 *)(&D_00189E20.planar), 0.0069444445f);
        else func_L00_002D3B58((V4_F6a70b950 *)(&D_00189E20.velocity), (V4_F6a70b950 *)(&D_00189E20.velocity), 0.0f);
        func_00282D30(&D_00189E20.direction, &H(Vec4, 0xbd0), -1.0f);
    }
    func_L00_002B3EF8(0, 0.0500000007f, 0.200000003f, 0.282161593f);
    goto finish;


case 0x78:
    func_00282C88((TI128 *)(&D_00189E20.velocity));
    D_00189E20.velocity.z = -0.0166666675f;
    goto finish;


case 0x7b:
{

    float turn, shape;
    s32 hits, i;
    func_L00_002B9BB0(4, D_00189E20.object, 13);
    func_L00_002B39F0(0, 1.0f);
    D_00189E20.speed = 0.191666678f;
    func_L00_002A9D38((float *)(&workspace.state_7b.local), (float *)(&H(Vec4, 0x9f0)), 0.170000002f);
    turn = H(float, 0x24b8) * workspace.state_7b.local.x * 0.0203621779f;
    if (D_L01_001A9030 == 0 && D_00189E20.frame < 60) {
        turn = turn * 0.100000001f;
        D_00189E20.speed = 0.5f;
    }
    if (0.200000003f < H(float, 0x24b8)) func_L00_002B3DC0(0.0f, 0.0f, turn);
    func_L00_002B41B8(0.027777778f, 0.00416666688f);
    func_L00_002B4208(99999.0f);
    if (D_L01_001A9030 == 0) {
        func_002AA3A8((float *)(&D_00189E20.position.z), (float *)(&H(float, 0xa00)), H(float, 0x318) + 0.170000002f, 0.0399999991f, 0.300000012f, 0.125f);
    } else {
        workspace.state_7b.target_position = H(Vec4, 0x2d0);
        func_L00_002D3778((FamilyC94396F4Vector_Fc94396f4 *)(&workspace.state_7b.target_position), (FamilyC94396F4Vector_Fc94396f4 *)(&workspace.state_7b.target_position), 0.170000002f);
        func_002AA458(&D_00189E20.position, &workspace.state_7b.target_position, &H(float, 0xa00),
                     0.0399999991f, 0.300000012f, 0.125f);
    }
    func_00282D30(&workspace.state_7b.target_position, &D_00189E20.displacement, 3.0f);
    func_00282CC0(&workspace.state_7b.target_position, &workspace.state_7b.target_position, &H(Vec4, 0xe0));
    hits = func_00277F48(&workspace.state_7b.target_position, 0, D_00189E20.object, 0, 0.569999993f);
    if (hits != 0) {
        func_00282D30(&workspace.state_7b.impulse, &D_00189E20.displacement, 7.0f);
        for (i = 0; i < hits; ++i) {
            if (func_002ABB78((char *)(D_L01_001C3980[i])) != 0)
                func_002A8F70(D_L01_001C3980[i], D_00189E20.object, 0x10000,
                             &D_00189E20.position, &workspace.state_7b.impulse, 1.0f);
        }
    }
    func_L00_002AB0A8(0.0170000009f, 0.300000012f);
    func_L00_002AB0D8(0.0250000004f, 0.300000012f);
    func_L00_002AB0F0(0.0299999993f, 0.270000011f);
    shape = turn * 27.0f;
    if (1.70000005f < shape) shape = 1.70000005f;
    else if (shape < -1.70000005f) shape = -1.70000005f;
    *(float *)(D_L01_0025D110 + 0x60) = -shape;
    *(float *)(D_L01_0025D110 + 0x1c8) = shape * 0.5f;
    *(float *)(D_L01_0025D110 + 0x278) = shape * 0.5f;
    goto finish;
}


case 0x82:
{
    s32 phase, color;
    u32 held;
    float elevation, factor, step;
    func_L00_002B9BB0(4, D_00189E20.object, 13);
    phase = func_L00_0031D620(720, 180, H(float, 0x5b0) * 0.0199999996f);
    color = func_L00_00325FC8(&H(float, 0x5a0), 0x60ffffff, 0x40ffc0a0,
                             (float)phase * 0.000290888245f);
    func_00290010(2, color, 0, 1.0f - H(float, 0x5b0) * 0.0199999996f);
    held = D_00138320 & 0x40;
    if (H(float, 0x5b0) == 0.0f) held = 0;
    if (held == 0) func_002AA2E8((float *)(&H(float, 0x5b0)), 0.0f, 0.0199999996f);
    else {
        func_002AA2E8((float *)(&H(float, 0x5b0)), 0.0f, 0.100000001f);
        func_L00_002D38A0((V4_Fe23fe324 *)(&D_00189E20.velocity), (V4_Fe23fe324 *)(&D_00189E20.velocity), 0.0250000004f);
    }
    if ((D_00138324 & 0x40) != 0) func_002AA2E8((float *)(&H(float, 0x5b0)), 0.0f, 0.5f);
    func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(&D_00189E20.velocity), (FamilyC94396F4Vector_Fc94396f4 *)(&D_00189E20.velocity), 0.0075000003f);
    elevation = func_L00_002D3B00((char *)(&D_00189E20.velocity));
    if (0.100000009f < elevation)
        func_L00_002D3B58((V4_F6a70b950 *)(&D_00189E20.velocity), (V4_F6a70b950 *)(&D_00189E20.velocity), 0.100000009f);
    elevation = func_L00_002D3B00((char *)(&D_00189E20.velocity));
    if (elevation < -0.200000018f)
        func_L00_002D3B58((V4_F6a70b950 *)(&D_00189E20.velocity), (V4_F6a70b950 *)(&D_00189E20.velocity), -0.200000018f);
    elevation = func_L00_002D3B00((char *)(&D_00189E20.velocity));
    if (!(H(float, 0x5b0) <= 25.0f || H(short, 0x5be) > 89 ||
          0.0f <= elevation || 1.20000005f <= H(float, 0x31c))) {
        factor = (H(float, 0x31c) - 0.25f) * 1.0526315f;
        H(u16, 0x5be) = H(u16, 0x5be) + 1;
        if (factor < 0.0f) factor = 0.0f;
        func_L00_002D3B58((V4_F6a70b950 *)(&D_00189E20.velocity), (V4_F6a70b950 *)(&D_00189E20.velocity), elevation * factor);
        if (H(float, 0x31c) < 0.25f)
            func_002AA3A8((float *)(&D_00189E20.position.z), (float *)(&H(float, 0x5b4)), H(float, 0x318) + 0.25f, 0.0270000007f, 0.300000012f, 0.0833333358f);
    } else if (0.0f < elevation) H(short, 0x5be) = 0;
    D_L01_001B9748 = func_L00_002D3B00((char *)(&D_00189E20.velocity));
    func_L00_002B7B80();
    func_L00_002B39F0(0, H(float, 0x24b8) * 0.200000018f);
    if (H(float, 0x24b8) < 0.200000003f) D_00189E20.heading = D_00189E20.rotation.z;
    func_L00_002B3EF8(0, 0.0270000007f, 0.300000012f, H(float, 0x24b8) * 0.087266475f);
    step = 0.00138888892f;
    if (H(float, 0x24b8) < 0.200000003f) step = 0.000555555569f;
    func_L01_002B6948(step);
    goto finish;
}


case 0x85:
{
    u8 *attached = H(u8 *, 0x1830);
    D_00189E20.position = *(Vec4 *)(attached + 0x10);
    D_00189E20.rotation = *(Vec4 *)(attached + 0xf0);
    goto finish;
}


case 0x8c:
    *(U128 *)&D_00189E20.velocity = 0;
    D_00189E20.velocity.z = -0.383333355f;
    goto finish;


    default: goto finish;
    }


shared_002BF77C:
    func_L01_002B4DA0(shared_mode);
    shared_source = ((void *)&D_00189E20.planar);
    if (!H(s16, 0x34E)) goto shared_002C80A0;
    shared_scale = 0.0069444445f;
    goto shared_002C8084;

shared_002C56BC:
    func_002AA2E8((float *)(HP(0x580)), D_00189E20.position.z, 0.050000004f);
    goto finish;

limit_falling_speed:
    func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), (FamilyC94396F4Vector_Fc94396f4 *)(((void *)&D_00189E20.velocity)), H(float, 0xA80));
    {
        float vertical = func_L00_002D3B00((char *)(((void *)&D_00189E20.velocity)));
        if (vertical < -0.833333373f) {
            shared_speed = -0.833333373f;
            goto shared_002C8248;
        }
    }
    goto finish;

shared_002C7AA8:
    func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(&D_00189E20.velocity), (FamilyC94396F4Vector_Fc94396f4 *)(shared_source), shared_scale);
    goto finish;

shared_002C8084:
    func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(&D_00189E20.velocity), (FamilyC94396F4Vector_Fc94396f4 *)(shared_source), shared_scale);
    func_L00_002B4308();
    goto finish;

shared_002C80A0:
    shared_scale = 0.0150000006f;
shared_002C80AC:
    func_L00_002D34C0((FamilyC94396F4Vector_Fc94396f4 *)(&D_00189E20.velocity), (FamilyC94396F4Vector_Fc94396f4 *)(&D_00189E20.velocity), shared_scale);
    goto finish;

shared_002C8248:
    func_L00_002D3B58((V4_F6a70b950 *)(&D_00189E20.velocity), (V4_F6a70b950 *)(&D_00189E20.velocity), shared_speed);
    goto finish;

finish:
    if (entry_substate != D_00189E20.substate) D_00189E20.stateTimer = 0;
    if (entry_animation != entry_object[0x43]) D_00189E20.animationTimer = 0;
}
