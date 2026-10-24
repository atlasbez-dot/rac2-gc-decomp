/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -Wall
 * -Werror.
 * Prior worker coverage: US 0/1; US2 absent from catalogue; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Complete readable C reconstruction, measured 2026-10-23.
 * Retained profile: -O2 -G0 -ffunction-sections -frac2-qcopy
 *                   -frac2-qcopy-barrier -Wall -Werror.
 * US: 14,692 bytes against 15,028; 0 of 1 placements, comparison exit 1.
 * USA v2.00 and PAL do not carry this name in either catalogue.
 * The 148-entry retail table has 62 destinations, including the common exit;
 * all 93 explicit labels and 61 nondefault destination groups are represented.
 * Cases 0x92 and 0x93 retain their original shared targets. State arms follow
 * increasing retail destination order, rather than the decompiler's label order.
 * Seven bounded trials covered a local resident view, direct resident expressions,
 * scoped views, physical case order, distinct-arm expansion and qualified copy/
 * address profiles. Best frame is 0xA0 against retail 0x80; allocation, base
 * materialization, common tails and ordinary scheduling still differ.
 * The unbounded table declarations below preserve unknown complete extents;
 * no array was reduced or forced into small data to reproduce GP addressing.
 * Live helper inputs were checked against retail and current definitions.
 * Procedural ASM helpers' original scalar-return intent remains unqualified;
 * this body does not consume their incidental scalar results.
 * Reopen with original player-record/lifetime or table-extent evidence, rather
 * than arbitrary permutations, invented memory effects or compiler barriers.
 */

#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } Vector;
typedef struct { int count; int reserved[3]; Vector points[0]; } Path;
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

typedef struct Rac2Native_5b4b17178a13f443_SmallSlotReset128Owner {
    unsigned char prefix_00[0x120];
    void *slots_120[10];
    int count_148;
    int active_14c;
} Rac2Native_5b4b17178a13f443_SmallSlotReset128Owner;

typedef Rac2Native_5b4b17178a13f443_SmallSlotReset128Owner SmallSlotReset128Owner;

extern u8 D_00189E20[];
extern u32 D_001A7390 __attribute__((sda));
extern u32 D_001A79F0;
extern int D_001A7B90;
extern char D_001A7A45;
extern int D_L11_001A8F00;
extern int D_L11_001A9010;
extern int D_L11_001A8FF4 __attribute__((sda));
extern float D_L11_001A7CD8 __attribute__((sda));
extern float D_L11_001A7CDC __attribute__((sda));
extern int D_L11_001A7DD8[];
extern u8 D_L11_001A7DE0[];
extern u8 D_L11_001A7E00[];
extern u8 D_L11_00275090[];
extern u8 D_L11_00275220[];
extern float D_L11_001BA8C8;
extern int D_L11_001BAB80;

extern void func_00282C88(TI128 *);
extern void func_00282CF0(void *,const void *,const void *);
extern void func_00282D30(void *,const void *,float);
extern float func_00282DB0(const void *,const void *);
extern float func_00282DF0(const void *);
extern float func_00282E20(const void *);
extern float func_00282E48(const void *,const void *);
extern void func_00282F20(void *,const void *,float);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_00283248(float,float);
extern float func_00283B98(float,float);
extern float func_00283C80(float,float);
extern int func_00283CF0(float);
extern void func_002A7470(void *,int,int,int);
extern int func_002A7820(int,int);
extern float func_002A78D8(float,float);
extern void *func_002A9640(void *,u32,int);
extern void func_002AC9F8(float *,float);
extern int func_002E5CF8(int,int,char *);
extern unsigned long func_L00_002A4EF0(unsigned long);
extern void func_L00_002A4EF8(int);
extern void func_L00_002A61C8(int,int,int,int);
extern void func_L00_002A6708(void);
extern void func_L00_002AABE0(int,int,int);
extern void func_L00_002AB3E0(void);
extern u32 func_L00_002ADE68(int);
extern int func_L00_002ADF80(void);
extern float func_L00_002AE070(int);
extern void func_L00_002AF3D8(int,int);
extern void func_L00_002AF7D0(void);
extern int func_L00_002B3248(u8 *);
extern void func_L00_002B39F0(int,float);
extern void func_L00_002B6118(float);
extern void func_L00_002B75A0(float,float,float);
extern float func_L00_002B9B38(void *,int);
extern int func_L00_002B9B88(int,int);
extern void func_L00_002BA508(void);
extern int func_L00_002C3A78(void);
extern void func_L00_002C8BA8(int);
extern int func_L00_002CAF20(void);
extern void func_L00_002D2168(int,int,float);
extern void func_L00_002D2470(int,int);
extern float func_L00_002D3A58(char *);
extern int func_L00_002D6900(u32);
extern void func_L00_002D6940(void);
extern void func_L00_00322A98(void *,char *);
extern void func_L00_00322AC0(List_F66766f2b *,int,int,float);
extern void func_L00_00322EC8(SmallSlotReset128Owner *);
extern int func_L00_00341820(const Path *,Vector *,int *,float *,int,float);
extern int func_L00_0035F5A0(int,int,int);
extern void func_L00_0041E958(float,float,float);
extern int func_L03_002AB5C8(int);


#define player D_00189E20

/* All resident fields below are views of the single player-state object. */
#define BYTE(o) (*(u8 *)(player + (o)))
#define HALF(o) (*(u16 *)(player + (o)))
#define SHORT(o) (*(s16 *)(player + (o)))
#define WORD(o) (*(s32 *)(player + (o)))
#define BITS(o) (*(u32 *)(player + (o)))
#define REAL(o) (*(f32 *)(player + (o)))
#define PTR(o) (*(u8 **)(player + (o)))
#define VEC(o) (player + (o))
#define COPY_VECTOR(dst,src) (*(TI128 *)VEC(dst) = *(TI128 *)VEC(src))

/* Changes the player's action, initializes its movement parameters and selects animation. */
s32 func_L11_002D8EF8(long action, s32 animate) {

    u8 *objectSnapshot;
    s32 oldStep;
    u8 wasGliding;
    u8 oldWeapon;
    s32 current, selected, mode, index, pathIndex;
    float pathOffset, oldDamage;
    TI128 pathPoint, direction;
    u8 *effect, *object;
    unsigned long weaponMode;
    u32 animation;
    u8 redirect;
    f32 frames, value, angle;
    if (WORD(0x229C) == 0x14 && (action != 0x61 || animate != 2)) return 0;
    if ((D_L11_001A8F00 == 2 || D_L11_001A8F00 == 6) && animate != 2) return 0;
    if (WORD(0x24CC) == 0 && (WORD(0x229C) == 2 || WORD(0x229C) == 7)) {
        if (action != 6 && action != 0x39 && action != 0x43 && action != 0x91 &&
            action != 0x5F && action != 0x74 && action != 0x78 && action != 0x79 &&
            action != 0x7C && action != 0x67 && action != 0x7D && action != 0x7F) return 0;
    }
    objectSnapshot=PTR(0x2290); oldStep=WORD(0x2298); wasGliding=BYTE(0x22B7);
    WORD(0x22AC) = WORD(0x22A0);
    WORD(0x22B0) = WORD(0x22A4);
    WORD(0x22A8) = WORD(0x1B8);
    WORD(0x22A0) = WORD(0x2294);
    WORD(0x22A4) = WORD(0x229C);
    WORD(0x2298) = 0;
    if (BYTE(0x22B5) == 1) BYTE(0x22B5) = 0;
    BYTE(0x22BC) = 0;
    WORD(0x2294) = action;
    if (BYTE(0x22B4) == 0) {
        *(s32 *)(PTR(0x2290) + 0x9C) = 0;
        BYTE(0x22BD) = 0;
        BYTE(0x22B7) = 0;
        BYTE(0x22C2) = 0;
        BYTE(0x22BF) = 0;
        HALF(0x2504) = 0;
        func_L00_00322EC8((SmallSlotReset128Owner *)VEC(0x18E0));
    }
    if (SHORT(0x1FA) == 0) func_L00_002D6940();
    func_L00_002AF3D8(WORD(0x22A0), WORD(0x2294));
    WORD(0x1188) = 0;
    switch (action) {
    case 0:
        WORD(0x229C) = 0;
        BITS(0x24A0) = 0;
        if (WORD(0x1248) == 0x1A) func_L00_002AF7D0();
        BYTE(0x24EF) = 0;
        WORD(0x11A0) = func_002A7820(50, 100);
        func_L00_002AB3E0();
        if (BYTE(0x22B4)) { func_L00_002C8BA8(0); return 1; }
        COPY_VECTOR(0x160, 0x120);
        if (BYTE(0x149A) && SHORT(0x34C) == 0) { redirect = 0x76; goto redirect_action; }
        WORD(0x1188) = 0x68;
        if (!animate) goto finish;
        animation = func_L03_002AB5C8(0);
        if (animation == 0x51) frames = 18.0f;
        else frames = -1.0f;
        animation = func_L03_002AB5C8(0);
        break;
    case 0x64:
        WORD(0x229C)=0; BITS(0x24A0)=0; func_00282C88((TI128 *)VEC(0x160)); WORD(0x1188)=0x68;
        if (!animate) goto finish;
        animation=func_L03_002AB5C8(0); frames=animation==0x51 ? 18.0f:-1.0f;
        animation=func_L03_002AB5C8(0); break;
    case 0x3D:
        func_L00_002D2168(func_L03_002AB5C8(0),0,9.0f);
        if (PTR(0x1854)) func_002A7470(PTR(0x1854),0,0,9);
        goto finish;
    case 0x39:
        WORD(0x229C)=20; BITS(0x24A0)=0; COPY_VECTOR(0x160,0x120);
        if (!animate) goto finish;
        animation=0x45; frames=12.0f; break;
    case 0x85:
        WORD(0x229C)=32; BITS(0x24A0)=8; BYTE(0x22C2)=1; BYTE(0x22B7)=1;
        if (animate) func_L00_002D2168(0x4F,0,5.0f);
        REAL(0x98)=*(float *)(PTR(0x1830)+0xF8); *(TI128 *)VEC(0x80)=*(TI128 *)(PTR(0x1830)+0x10);
        func_00282C88((TI128 *)VEC(0xF0)); goto finish;
    case 0x86:
        BYTE(0x22C2)=1; WORD(0x229C)=32; BITS(0x24A0)=8; BYTE(0x22B7)=1;
        if (!animate) goto finish;
        frames=5.0f; animation=0x4F; break;
    case 1:
        BITS(0x24A0) = 4;
        WORD(0x229C) = 0;
        if (BYTE(0x22BA)) goto finish;
        animation = func_L03_002AB5C8(1);
        if (PTR(0x2290)[0x43] == animation || !animate) goto finish;
        frames = 18.0f;
        break;
    case 0x2F:
        WORD(0x229C)=8; BITS(0x24A0)=0; COPY_VECTOR(0x160,0x110);
        func_L00_002D2168(func_L03_002AB5C8(0),0,5.0f); HALF(0x1EC)=7; goto finish;
    case 2:
    case 0x70:
        WORD(0x229C) = 1;
        BITS(0x24A0) = 0;
        if (WORD(0x22A4) != 4 && WORD(0x22B0) != 4) REAL(0x1B4) = func_L00_002D3A58((char *)VEC(0x120));
        COPY_VECTOR(0x3F0, 0);
        BITS(0x410) = 0;
        BITS(0x408) = BITS(0x98);
        if (REAL(0x1B4) > 0.11666667461395264f) REAL(0x1B4) = 0.11666667461395264f;
        BYTE(0x40F) = 0;
        func_L00_002B39F0(0, 1.0f);
        value = func_00283C80(REAL(0x98), REAL(0x1A0));
        if (value > 1.5707964897155762f &&
            (WORD(0x22A4) == 4 || WORD(0x22A0) == 3 || WORD(0x22AC) == 3)) REAL(0x1B4) = 0;
        WORD(0x1188) = 0x68;
        if (BYTE(0x149A)) {
            if (SHORT(0x34C) == 0 || REAL(0x31C) < 0.3f) { redirect = 0x76; goto redirect_action; }
        }
        WORD(0x2298) = 0; BYTE(0x40C) = 0; BYTE(0x40E) = 0;
        if (!animate) goto finish;
        selected = WORD(0x24CC) == 1 ? 12 : 8;
        if (WORD(0x22AC) == 0x22 || WORD(0x22A0) == 0x22 || WORD(0x22AC) == 0x83 || WORD(0x22A0) == 0x83) selected = 15;
        if (WORD(0x22A0) == 0x13) selected = 13;
        if (WORD(0x22AC) == 6 || WORD(0x22AC) == 0x2C) selected = 18;
        if (WORD(0x22B0) == 4 && BYTE(0x49C) > 5) selected = 13;
        frames = (float)selected;
    play_step_animation:
        func_L00_002D2168(WORD(0x2298)+3,D_L11_001A7DD8[WORD(0x2298)],frames);
        goto finish;
    case 0x7B:
        WORD(0x1188)=0x68; WORD(0x229C)=28; BITS(0x24A0)=0; COPY_VECTOR(0xF0,0x110);
        if (WORD(0x1298)!=0x36) { BITS(0x22CC)=0x36; WORD(0x2304)=WORD(0x1298); }
        if (!animate) goto finish;
        frames=-2.0f; animation=0x8B; break;
    case 0x62:
        WORD(0x229C)=1; BITS(0x24A0)=0; REAL(0x1B4)=func_00282E20(VEC(0x120)); BYTE(0x22BC)=1;
        if (!BYTE(0x22B4)) func_L00_002AF7D0();
        if (!animate) goto finish;
        animation=2;
        if (BYTE(0x22B4)!=1) {
            if (BYTE(0x22B4)) goto finish;
            frames=8.0f; goto play_step_animation;
        }
        frames=8.0f; break;
    case 3:
        WORD(0x229C) = 1; BITS(0x24A0) = 0;
        COPY_VECTOR(0x160, 0x120);
        if (BYTE(0x149A) && SHORT(0x34C) == 0) { redirect = 0x76; goto redirect_action; }
        if (func_L00_002CAF20()) return 0;
        if (func_L03_002AB5C8(0) == 0x51) {
            if (!animate) goto finish;
            if (!func_L11_002D8EF8(0, 0)) return 0;
            func_L00_002D2168(func_L03_002AB5C8(0), 0, 18.0f);
            return 0;
        }
        if (!animate) goto finish;
        oldWeapon = objectSnapshot[0x42];
        goto run_animation;
    case 0x63:
        WORD(0x229C)=1; BITS(0x24A0)=0; REAL(0x1B4)=func_L00_002D3A58((char *)VEC(0x120)); COPY_VECTOR(0x160,0x120);
        if (!animate) goto finish;
        oldWeapon=objectSnapshot[0x42];
    run_animation:
        value=REAL(0xC38); selected=6;
        if (func_L00_002A4EF0(oldWeapon)==4 && value>3.0f && value<16.0f) selected=5;
        func_L00_002D2168(selected,4,9.0f); goto finish;
    case 4:
        WORD(0x229C) = 12; BITS(0x24A0) = 0;
        REAL(0x1B4) = func_00282E20(VEC(0x120));
        if (REAL(0x1B4) > 0.11666667461395264f) REAL(0x1B4) = 0.11666667461395264f;
        if (BYTE(0x149A) && SHORT(0x34C) == 0) { redirect = 0x76; goto redirect_action; }
        WORD(0x1188) = 0x68;
        COPY_VECTOR(0x160, 0x120);
        func_002AC9F8((float *)VEC(0x120), 0.11666667461395264f);
        if (REAL(0x178) > 0.05833333730697632f) func_L00_002B9B88(9, 0);
        if (animate) {
            if (PTR(0x2290)[0x42] == func_L03_002AB5C8(0)) func_L00_002D2168(13, 2, 9.0f);
            else func_L00_002D2168(13, 2, 14.0f);
            func_L00_002D2470(3, 18);
        }
        goto finish;
    case 0x8A:
        WORD(0x229C)=33; BITS(0x24A0)=0;
        if (SHORT(0x25DC)!=-1) SHORT(0x25DC)++;
        if (BITS(0x25E0)<D_001A7390) BITS(0x25E0)=D_001A7390;
        BITS(0x25E4)|=(1U<<(D_001A79F0&31))|0x80000000U;
        REAL(0x1A0)=func_00283248(*(float *)(PTR(0xB10)+0x10)-REAL(0x80),*(float *)(PTR(0xB10)+0x14)-REAL(0x84));
        BITS(0xB1C)=0;
    ledge_animation:
        if (animate) { func_L00_002D2168(0x2F,2,5.0f); func_L00_002D2470(10,14); }
        goto finish;
    case 0x8B:
        WORD(0x229C)=33; BYTE(0x22BC)=1; BITS(0x24A0)=0; goto finish;
    case 0x23:
        WORD(0x229C)=13; BITS(0x24A0)=7;
        if (SHORT(0x25DC)!=-1) SHORT(0x25DC)++;
        if (BITS(0x25E0)<D_001A7390) BITS(0x25E0)=D_001A7390;
        BITS(0x25E4)|=(1U<<(D_001A79F0&31))|0x80000000U;
        REAL(0x1A0)=func_00283248(*(float *)(PTR(0xAA4)+0x10)-REAL(0x80),*(float *)(PTR(0xAA4)+0x14)-REAL(0x84));
        if (WORD(0x22A0)==0x28) COPY_VECTOR(0x160,0xF0);
        goto ledge_animation;
    case 0x24:
        BYTE(0x22BC)=1; WORD(0x229C)=13; BITS(0x24A0)=7;
        BITS(0xAA0)=0; BITS(0xAB4)=0;
        if (!animate) goto finish;
        frames=10.0f; animation=0x30; goto animate_once;
    case 0x25:
        BYTE(0x22BC)=1; WORD(0x229C)=13; BITS(0x24A0)=7;
        BITS(0xAA0)=0; BITS(0xAB4)=0;
        REAL(0xABC)=func_00282E48(VEC(0x80),PTR(0xAA4)+0x10);
        if (!animate) goto finish;
        frames=5.0f; animation=0x30;
    animate_once:
        func_L00_002D2168(animation,1,frames); goto finish;
    case 0x2B:
        WORD(0x229C)=14; BITS(0x24A0)=7;
        if (SHORT(0x25DC)!=-1) SHORT(0x25DC)++;
        if (BITS(0x25E0)<D_001A7390) BITS(0x25E0)=D_001A7390;
        HALF(0xAFE)=1; BITS(0x25E4)|=(1U<<(D_001A79F0&31))|0x80000000U;
        BITS(0xAE8)=0; BYTE(0x22BC)=1; PTR(0xAD4)=PTR(0xAD0);
        HALF(0xADC)=0; HALF(0xAFC)=0; BITS(0xAF4)=0; BITS(0xAF8)=0;
        effect=*(unsigned char **)(PTR(0xAD0)+0x68);
        BITS(0xAE0)=*(u32 *)(effect+4);
        value=*(float *)(effect+0x10);
        if (value==0.0f) value=*(float *)(effect+0xC);
        *(float *)(effect+0x14)=value;
        REAL(0xB08)=0.33f; REAL(0xB0C)=0.18333334f; REAL(0xB04)=0.025f;
        func_00282C88((TI128 *)VEC(0xA0)); HALF(0x206)=0x28;
        if (*(float *)(effect+0x24)!=0) REAL(0xB04)=*(float *)(effect+0x24);
        if (*(float *)(effect+0x28)!=0) REAL(0xB08)=*(float *)(effect+0x28);
        if (*(float *)(effect+0x2C)!=0) REAL(0xB0C)=*(float *)(effect+0x2C);
        REAL(0xAEC)=func_00283248(*(float *)(PTR(0xAD4)+0x10)-REAL(0x80),*(float *)(PTR(0xAD4)+0x14)-REAL(0x84));
        REAL(0xAE4)=func_00282E48(VEC(0x80),PTR(0xAD4)+0x10);
        REAL(0xAF0)=0.007500000298023224f;
        if (WORD(0x22A4)==4) REAL(0xAF0)=REAL(0x520);
        else if (WORD(0x22A4)==2) REAL(0xAF0)=REAL(0xA80);
        if (animate) { func_L00_002D2168(0x34,0,11.0f); REAL(0xC20)=0.7f; }
        goto finish;
    case 0x2C:
        BITS(0x24A0)=7; WORD(0x229C)=2;
        func_00282C88((TI128 *)VEC(0xA0)); COPY_VECTOR(0xF0,0x120);
        if (!animate) goto finish;
        animation=11; frames=15.0f; break;
    case 0x71:
        pathIndex=WORD(0x6E4); pathOffset=REAL(0x6E8);
        BITS(0x24A0)=3; WORD(0x229C)=26; BYTE(0x22B7)=1; WORD(0x1188)=0x68; BITS(0x6F0)=0; BITS(0x708)=0;
        func_L00_00341820((const Path *)PTR(0x6E0),(Vector *)&pathPoint,&pathIndex,&pathOffset,WORD(0x6FC),1.0f);
        func_00282CF0(&direction,&pathPoint,VEC(0x80)); value=func_00282DF0(&direction);
        if (value>0.001f) { func_00282F20(&direction,&direction,1.0f); REAL(0x6F4)=func_00282DB0(VEC(0x110),&direction); }
        REAL(0x6F4)*=0.5f;
        if (REAL(0x6F4)<0) REAL(0x6F4)=0;
        frames=8.0f; animation=0x6C; break;
    case 0x17:
        WORD(0x229C)=3; BITS(0x24A0)=13;
        REAL(0x57C)=0.006111111491918564f; REAL(0x580)=REAL(0x88);
        if (WORD(0x22A4)==4) { REAL(0x57C)=REAL(0x520); REAL(0x580)=REAL(0x490); }
        BYTE(0x22BC)=1; BYTE(0x22BF)=1;
        if (!animate) goto finish;
        animation=0x20;
        if (REAL(0x174)<=0.05833333730697632f) { frames=11.0f; goto animate_once; }
        frames=9.0f; break;
    case 0x18:
        WORD(0x229C)=3; WORD(0x1188)=0x68; BITS(0x24A0)=13;
        BYTE(0x22BC)=1; BYTE(0x22BF)=1;
        if (!animate) goto finish;
        frames=6.0f; animation=0x21; break;
    case 0x19:
        BYTE(0x22BC)=1; WORD(0x229C)=3; BITS(0x24A0)=13; BYTE(0x22BF)=1;
        if (!animate) goto finish;
        frames=6.0f; animation=0x24; break;
    case 0x1A:
        BYTE(0x22BC)=1; WORD(0x229C)=3; BITS(0x24A0)=13; BYTE(0x22BF)=1;
        if (!animate) goto finish;
        frames=6.0f; animation=0x25; break;
    case 0x76:
        WORD(0x229C)=2; BITS(0x24A0)=0; COPY_VECTOR(0xF0,0x120);
        if (!animate) goto finish;
        frames=12.0f; animation=11; break;
    case 6:
    case 0x74:
        WORD(0x229C) = 2; BITS(0x24A0) = 0;
        if (WORD(0x2294) == 0x74) {
            WORD(0x229C) = 0x14;
            if (BYTE(0x22B4) == 1) {
                if (D_001A79F0 == 3) func_L00_0035F5A0(17, 0, (s32)PTR(0x2290));
                else if (D_001A79F0 == 14) func_L00_0035F5A0(21, 0, (s32)PTR(0x2290));
            }
        }
        REAL(0xA80) = 0.006111111491918564f;
        BITS(0xA84) = 0x3AFEDCBB;
        if (WORD(0x2294) == 0x74) {
            if (!BYTE(0x22B4)) HALF(0x24D6) = func_L00_002B9B88(14, 0x20);
            REAL(0xA90) = func_002A78D8(0.05235988646745682f, 0.07272206246852875f);
            REAL(0xA94) = func_002A78D8(0.05235988646745682f, 0.07272206246852875f);
        }
        WORD(0x1188) = 0x68; WORD(0x2298) = 0;
        COPY_VECTOR(0xF0, 0x120);
        if (!animate) goto finish;
        if (BYTE(0x22B4) == 1) { func_L00_002D2168(4, 0, 8.0f); return 1; }
        if (REAL(0x31C) > 1.75f) { func_L00_002D2168(11, 0, 12.0f); WORD(0x2298) = 1; goto finish; }
        frames = 10.0f; animation = 10;
        break;
    case 0x82:
        oldDamage=REAL(0x5B8);
        WORD(0x229C)=30; BITS(0x24A0)=0;
        if (WORD(0x22A0)!=0x16) {
            REAL(0x5B0)=50.0f;
            if (REAL(0x5B8)!=0) { REAL(0x5B8)=0; REAL(0x5B0)=oldDamage; }
        }
        BYTE(0x24EF)=1; WORD(0x1188)=0x68; BITS(0x7A8)=0; HALF(0x5BE)=0; BITS(0x5A8)=0; BITS(0x5A4)=0;
        COPY_VECTOR(0xF0,0x110); HALF(0x5BC)=7;
        if (!animate) goto finish;
        frames=-2.0f; animation=0x13; break;
    case 8:
        WORD(0x229C) = 5; WORD(0x1188) = 0x68; BITS(0x24A0) = 0;
        if (REAL(0x170) > 0.075f) func_L00_002B6118(0.075f / REAL(0x170));
        WORD(0x24C8) = 0; COPY_VECTOR(0xF0, 0x110);
        if (!animate) goto finish;
        frames = -2.0f; animation = 0x13;
        break;
    case 7: case 9: case 10: case 0xB: case 0xC: case 0xD: case 0xE: case 0xF:
    case 0x10: case 0x11: case 0x12: case 0x1B: case 0x28: case 0x29: case 0x38:
    case 0x45: case 0x48: case 0x5B: case 0x66: case 0x6E: case 0x81: case 0x89: case 0x92:
        if (WORD(0x2294) != 0x81 && PTR(0x33C) &&
            (*(s16 *)(PTR(0x33C) + 0xAA) == 0x9B9 || *(s16 *)(PTR(0x33C) + 0xAA) == 0xF05)) {
            redirect = 0x81; goto redirect_action;
        }
        if (WORD(0x2294) != 0x6E && SHORT(0x348) == 1 && action != 0xE &&
            action != 0x38 && !D_L11_001A8FF4) { redirect = 0x6E; goto redirect_action; }
        if (WORD(0x22A0) == 0x11 && !BYTE(0x24DA)) BYTE(0x24DB)++;
        else BYTE(0x24DB) = 0;
        if (SHORT(0x1F2)) { redirect = 0x82; goto redirect_action; }
        if (SHORT(0x212)) {
            WORD(0x1B8) = WORD(0x22A8); WORD(0x1188) = 0;
            WORD(0x2294) = WORD(0x22A0); WORD(0x2298) = oldStep;
            return 0;
        }
        WORD(0x229C) = 4;
        BITS(0x24A0) = (u32)(action - 0x28) < 2 ? 3 : 0x50;
        oldWeapon=BYTE(0x149D);
        if (WORD(0x2294) == 7 || WORD(0x2294) == 0xF || WORD(0x2294) == 0xD ||
            (WORD(0x2294) == 0xB && WORD(0x22A4) != 4)) {
            func_L00_002A61C8(BYTE(0x149D), 0, 0, 30);
            func_L00_002A61C8(oldWeapon, 1, 0, 30);
        }
        COPY_VECTOR(0xF0, 0x120);
        if (WORD(0x2294) != 0x12 && BYTE(0x1494) && REAL(0x88) < REAL(0x330) + 0.5f)
            func_L00_002AABE0(3, 0x10, 0);
        if (WORD(0x2294)==0x66) func_L00_002B9B88(8,0);
        REAL(0x490) = REAL(0x88);
        REAL(0x520) = 0.00825f;
        WORD(0x448) = -1;
        BITS(0x500) = 0x3BB60B61;
        REAL(0x510) = 2.5f;
        HALF(0x528) = BYTE(0x1492);
        HALF(0x51A) = 80;
        BITS(0x494) = 0x3E80157C;
        BITS(0x4A0) = 0x3F555556;
        BYTE(0x49E) = 0; BYTE(0x49C) = 0;
        BITS(0x4B0) = 0; BITS(0x4B4) = 0; BYTE(0x49D) = 0;
        BITS(0x504) = 0x3B483FB8;
        HALF(0x524) = 0; BYTE(0x52C) = 0; BYTE(0x52E) = 0; BYTE(0x52F) = 0;
        HALF(0x52A) = 70; HALF(0x526) = 0;
        REAL(0x514) = 0.5f; BITS(0x4A4) = 0x3DCB17E5;
        BITS(0x458) = 0; BYTE(0x49F) = 0;
        BITS(0x594) = 0; HALF(0x24D8) = 0;
        if (WORD(0x2294) == 7) {
            BITS(0x458) = 0x3C1E2585;
            REAL(0x4CC) = 30.0f; REAL(0x4D0) = 12.0f;
            REAL(0x50C) = 2.3f; REAL(0x508) = 1.28f; REAL(0x4A8) = 1.28f;
            goto running_profile;
        } else if (WORD(0x2294) == 0x81) {
            REAL(0x50C) = D_L11_001A7CD8 + 0.5f;
            REAL(0x520) = D_L11_001A7CDC * 0.0002777777845f;
            SHORT(0x4AC) = 5; REAL(0x4B8) = 0.6f; REAL(0x4C8) = 18.0f;
            REAL(0x4CC) = 30.0f; REAL(0x4D0) = 12.0f;
            REAL(0x508) = D_L11_001A7CD8; HALF(0x518) = 15; HALF(0x51A) = 400;
            REAL(0x510) = 300.0f; HALF(0x52A) = 1200;
            BITS(0x4A4) = 0x3DEEEEF0; REAL(0x4A8) = D_L11_001A7CD8; HALF(0x526) = 1200;
            if (D_001A79F0 == 16) BITS(0x4A4) = 0;
            func_L00_00322A98(PTR(0x2290), (char *)VEC(0x18E0));
            func_L00_00322AC0((List_F66766f2b *)VEC(0x18E0), 70, 2, 0.0f);
            func_L00_00322AC0((List_F66766f2b *)VEC(0x18E0), 35, 4, 0.0f);
            func_L00_00322AC0((List_F66766f2b *)VEC(0x18E0), 17, 6, 0.0f);
        } else if (WORD(0x2294) == 0x38) {
            SHORT(0x4AC) = 5; REAL(0x4B8) = 0.6f;
            REAL(0x4C8) = 18.0f; REAL(0x4CC) = 26.0f; REAL(0x4D0) = 13.0f;
            REAL(0x50C) = 5.55f; REAL(0x508) = 5.5f;
            HALF(0x518) = 2; HALF(0x51A) = 120; BYTE(0x49F) = 1; REAL(0x4A8) = 5.5f;
            func_L00_002A4EF8(1);
            if (WORD(0x22A0) == 0x38 || WORD(0x22AC) == 0x38 || WORD(0x24CC) == 0) {
                WORD(0x18C0)++;
                if (WORD(0x18C0) > 2 || WORD(0x24CC) == 0) {
                    if (D_001A79F0 == 2 && D_L11_001A9010) redirect = 0x7D;
                    else {
                        if (*(s32 *)(*(u8 **)(PTR(0x2290) + 0x24) + 0x1F0) == 0) {
                            func_L11_002D8EF8(0x39, 1); return 0;
                        }
                        redirect = 0x79;
                    }
                    goto redirect_action;
                }
            } else WORD(0x18C0) = 0;
            HALF(0x52A) = 150; HALF(0x51E) = 4;
            REAL(0x520) = 0.004166666884f; HALF(0x51C) = 5;
        } else if (WORD(0x2294) == 0x66) {
            WORD(0x229C)=25;
            REAL(0x50C)=REAL(0x88)<REAL(0x334) ? REAL(0x334)-REAL(0x88):0.0f;
            REAL(0x4A8)=REAL(0x50C)+1.7f; REAL(0x50C)+=1.75f;
            BYTE(0x49F)=1; SHORT(0x4AC)=5; REAL(0x4B8)=0.6f; REAL(0x4C8)=18.0f;
            REAL(0x4CC)=30.0f; REAL(0x4D0)=12.0f; HALF(0x518)=19; REAL(0x508)=REAL(0x4A8);
        } else if (WORD(0x2294) == 9) {
            REAL(0x4CC) = 29.0f; REAL(0x4D0) = 11.0f;
            REAL(0x50C) = 2.7f; REAL(0x508) = 1.0f; REAL(0x4A8) = 1.0f;
        running_profile:
            BYTE(0x52F) = 1; HALF(0x518) = 15; REAL(0x4C8) = 18.0f;
            REAL(0x4B8) = 0.6f; SHORT(0x4AC) = 5; BITS(0x4A4) = 0x3DCB17E5;
            BYTE(0x52C) = 1; BYTE(0x52E) = 1;
        } else if (WORD(0x2294) == 0x6E) {
            REAL(0x4B8) = 0.6f; BITS(0x4A4) = 0x3DED9E84;
            REAL(0x4C8) = 18.0f; REAL(0x4CC) = 30.0f; REAL(0x4D0) = 12.0f;
            REAL(0x50C) = 2.75f; REAL(0x508) = 2.7f; HALF(0x518) = 5;
            BYTE(0x49F) = 1; REAL(0x4A8) = 2.7f; SHORT(0x4AC) = 5;
            BYTE(0x52C) = 1; BYTE(0x52E) = 0; BYTE(0x52F) = 0;
        } else if (WORD(0x2294) == 0x45) {
            SHORT(0x4AC)=3; BITS(0x4A4)=0x3D088889; REAL(0x4B8)=0.6f;
            REAL(0x4C8)=15.0f; REAL(0x4CC)=24.0f; REAL(0x4D0)=12.0f;
            REAL(0x50C)=1.35f; REAL(0x508)=1.3f; HALF(0x518)=14;
            REAL(0x520)=0.0069444444961845875f; BITS(0x504)=0x3C638E39; REAL(0x4A8)=1.3f;
        } else if (WORD(0x2294) == 10) {
            HALF(0x526) = 70; SHORT(0x4AC) = 5; REAL(0x4B8) = 0.6f;
            REAL(0x4C8) = 18.0f; REAL(0x4CC) = 29.0f; REAL(0x4D0) = 10.0f;
            REAL(0x50C) = 1.95f; REAL(0x508) = 1.9f; HALF(0x518) = 14;
            REAL(0x520) = 0.003055555746f; BYTE(0x52E) = 1;
            HALF(0x51A) = 120; HALF(0x52A) = 90; REAL(0x4A8) = 1.9f;
        } else if (WORD(0x2294) == 0x10) {
            REAL(0x4C8) = 18.0f; REAL(0x4CC) = 30.0f; REAL(0x4D0) = 11.0f;
            REAL(0x50C) = 1.55f; SHORT(0x4AC) = 5; REAL(0x4B8) = 0.8f;
            REAL(0x508) = 1.5f; REAL(0x4A8) = 1.5f; HALF(0x518) = 1;
            func_L00_002D6900(20);
            REAL(0x508) = 0.4f; REAL(0x50C) = 0.9f; REAL(0x4A8) = 0.4f;
            if (REAL(0x184) < 0.3333333433f) {
                func_L00_00322A98(PTR(0x2290), (char *)VEC(0x18E0));
                func_L00_00322AC0((List_F66766f2b *)VEC(0x18E0), 40, 2, 0.0f);
                func_L00_00322AC0((List_F66766f2b *)VEC(0x18E0), 20, 4, 0.0f);
                func_L00_00322AC0((List_F66766f2b *)VEC(0x18E0), 10, 6, 0.0f);
            }
            BYTE(0x52E) = 1; BITS(0x454) = 0x3E444445;
            if (REAL(0x31C) > 1.4f) BITS(0x454) = 0x3DC28F5C;
            REAL(0x520) = 0.00236111111f; BITS(0x504) = 0x3C638E39; BITS(0x500) = 0x3C483FB8;
        } else if (WORD(0x2294) == 0x1B) {
            BYTE(0x52E) = 1; SHORT(0x4AC) = 10; REAL(0x4B8) = 0.85f;
            REAL(0x4C8) = 20.0f; REAL(0x4CC) = 29.0f; REAL(0x4D0) = 19.0f;
            REAL(0x50C) = 2.05f; REAL(0x508) = 2.0f; REAL(0x514) = 1.0f;
            REAL(0x520) = 0.006944444496f; REAL(0x4A8) = 2.0f; HALF(0x518) = 1;
            BITS(0x4BC) = 0; BYTE(0x49F) = 1; BYTE(0x22BF) = 1; BYTE(0x22BC) = 1;
        } else if (WORD(0x2294) == 0x48) {
            SHORT(0x4AC)=13; REAL(0x520)=0.007777777966111898f; REAL(0x4B8)=0.85f;
            REAL(0x4C8)=8.0f; REAL(0x4D0)=14.0f; REAL(0x50C)=1.59f; REAL(0x508)=1.55f;
            HALF(0x518)=1; REAL(0x4A8)=1.55f; REAL(0x4CC)=14.0f; BITS(0x4BC)=0;
        } else if (WORD(0x2294) == 0x11) {
            SHORT(0x4AC) = 9; REAL(0x4B8) = 0.6f;
            REAL(0x4C8) = 12.0f; REAL(0x4CC) = 20.0f; REAL(0x4D0) = 10.0f; HALF(0x518) = 12;
            if (!BYTE(0x24DA)) { REAL(0x50C) = 1.85f; REAL(0x4A8) = 1.8f; BITS(0x498) = 0x3CE81B50; }
            else { REAL(0x50C) = 3.35f; REAL(0x4A8) = 3.3f; BITS(0x498) = 0x3DA740DB; }
            BYTE(0x49F) = 1; REAL(0x508) = REAL(0x4A8); func_L00_002D6900(27);
            HALF(0x52A) = 80; REAL(0x520) = 0.008055555634f;
            COPY_VECTOR(0x4F0, 0x4E0); BYTE(0x52C) = 1; HALF(0x24D8) = 1; BYTE(0x22B7) = 1;
        } else if (WORD(0x2294) == 0xD) {
            REAL(0x4C8) = 26.0f; REAL(0x4CC) = 38.0f; REAL(0x4D0) = 18.0f;
            REAL(0x50C) = 4.07f; SHORT(0x4AC) = 9; REAL(0x4B8) = 0.6f;
            REAL(0x508) = 4.0f; HALF(0x518) = 14; REAL(0x4A8) = 4.0f;
            func_L00_002D6900(20); REAL(0x510) = 4.5f; HALF(0x51A) = 120;
            BITS(0x4A4) = 0x3D01B4E8; HALF(0x526) = 37;
            if (REAL(0x184) < 0.3333333433f) {
                func_L00_00322A98(PTR(0x2290), (char *)VEC(0x18E0));
                func_L00_00322AC0((List_F66766f2b *)VEC(0x18E0), 40, 3, 0.0f);
                func_L00_00322AC0((List_F66766f2b *)VEC(0x18E0), 20, 5, 0.0f);
            }
            BYTE(0x52E) = 1;
        } else if (WORD(0x2294) == 0xF) {
            SHORT(0x4AC) = 9; REAL(0x4B8) = 0.6f;
            REAL(0x4C8) = 50.0f; REAL(0x4CC) = 64.0f; REAL(0x4D0) = 28.0f;
            REAL(0x50C) = 1.7f; REAL(0x508) = 1.65f; HALF(0x518) = 5;
            REAL(0x510) = 4.5f; HALF(0x51A) = 130; BITS(0x4A4) = 0x3D6147AF;
            HALF(0x526) = 85; HALF(0x1D0) = 70; BYTE(0x49D) = 1; REAL(0x4A8) = 1.65f;
            WORD(0x430) = D_001A7B90 == 0 ? 35 : 34;
            PTR(0x444) = (u8 *)D_L11_001A7E00;
            WORD(0x434) = WORD(0x430) + 36;
            BYTE(0x52E) = 1; REAL(0x438) = 29.0f; REAL(0x43C) = 50.0f; BITS(0x440) = 86;
        } else if (WORD(0x2294) == 0xE) {
            REAL(0x4A8) = 0.7f;
            if (REAL(0x31C) < 2.0f) REAL(0x4A8) = (2.5f - REAL(0x31C)) * 0.5f + 0.7f;
            REAL(0x50C) = REAL(0x4A8) + 0.05f; HALF(0x526) = 30; SHORT(0x4AC) = -1;
            REAL(0x4B8) = 0.6f; REAL(0x4C8) = 32.0f; REAL(0x4CC) = 43.0f; REAL(0x4D0) = 19.0f;
            HALF(0x518) = 14; REAL(0x514) = 1.0f; BITS(0x4A4) = 0x3DA22223; REAL(0x508) = REAL(0x4A8);
        } else if (WORD(0x2294) == 0xB) {
            HALF(0x52A) = 50; SHORT(0x4AC) = 5; REAL(0x4B8) = 0.6f;
            REAL(0x4C8) = 18.0f; REAL(0x4CC) = 31.0f; REAL(0x4D0) = 24.0f;
            REAL(0x50C) = 3.25f; REAL(0x508) = 3.2f; HALF(0x518) = 14;
            REAL(0x510) = 4.5f; REAL(0x514) = 1.0f; BYTE(0x49F) = 1; REAL(0x4A8) = 3.2f;
            REAL(0x4C4) = func_L00_002AE070(10); COPY_VECTOR(0x480, 0);
            WORD(0x4D4) = func_L00_002C3A78(); BITS(0x4C0) = BITS(0x1A0); COPY_VECTOR(0x470, 0x190);
            REAL(0x4D8) = REAL(0x174) > 0.025000002f ? REAL(0x174) : 0.0f;
            BITS(0x4DC) = 0; BYTE(0x52C) = 1;
            if (!SHORT(0x1454) || REAL(0x24B8) <= 0.3f) BYTE(0x52D) = 0;
            else {
                BITS(0x4C0) = BITS(0x1458); COPY_VECTOR(0x470, 0x1440);
                BYTE(0x52D) = 1; BITS(0x4DC) = 0x3DAAAAAB;
            }
            BYTE(0x52E) = 1;
        }
        if (REAL(0x510) == 0.0f) REAL(0x510) = REAL(0x4A8) * 1.5f;
        if (!animate) goto finish;
        if (WORD(0x2294) == 7 || WORD(0x2294) == 0x6E || WORD(0x2294) == 0x81 || WORD(0x2294) == 0x66) { frames = 5.0f; animation = 7; }
        else if (WORD(0x2294) == 0x38) { frames = 4.0f; animation = 0x43; }
        else if (WORD(0x2294) == 9) {
            animation = 8; index = func_00283CF0(REAL(0xC38));
            if (func_L00_002A4EF0(objectSnapshot[0x42]) == 4) animation = D_L11_001A7DE0[index];
            frames = 5.0f;
        } else if (WORD(0x2294) == 0x45) { frames=5.0f; animation=7; goto animate_five; }
        else if (WORD(0x2294) == 10) { frames = 5.0f; animation = 18; }
        else if (WORD(0x2294) == 0x10) {
            if (WORD(0x22A4) == 4 || (WORD(0x22A0) == 4 && WORD(0x1B8) < 7)) {
                func_L00_002D2168(0x26, 0, 8.0f); SHORT(0x4AC) += 3; goto finish;
            }
            frames = 5.0f; animation = 0x26;
        } else if (WORD(0x2294) == 0x1B) { frames = 4.0f; animation = 0x22; }
        else if (WORD(0x2294) == 0x89) { func_L00_002D2168(0x7D, 11, 9.0f); goto finish; }
        else if (WORD(0x2294) == 0x48) { frames=4.0f; animation=9; }
        else if (WORD(0x2294) == 0x11) { frames = 7.0f; animation = 0x23; goto animate_two; }
        else if (WORD(0x2294) == 0xD) { frames = 5.0f; animation = 17; }
        else if (WORD(0x2294) == 0xE) { func_L00_002D2168(0x16, 3, 7.0f); REAL(0xC20) = 0.8f; goto finish; }
        else if (WORD(0x2294) == 0xF) { frames = 5.0f; animation = 21; }
        else if (WORD(0x2294) == 0xB) {
            animation = WORD(0x4D4) + 28;
            if (D_001A7A45) { if (animation == 28) animation = 29; else if (animation == 29) animation = 28; }
            if (WORD(0x22A4) == 4) { func_L00_002D2168(animation, 1, 4.0f); SHORT(0x4AC) = 1; goto finish; }
            frames = 5.0f;
        } else goto finish;
        break;
    case 0x13: case 0x14: case 0x15: case 0x1F: case 0x22: case 0x4D: case 0x83: case 0x93:
        WORD(0x229C) = 6;
        if (WORD(0x1500) && (u32)(WORD(0x2294) - 0x13) < 3) {
            animation = D_001A7390;
            if (SHORT(0x293C) != -1) { SHORT(0x293C)++; animation = D_001A7390; }
            if (BITS(0x2940) < animation) BITS(0x2940) = animation;
            BITS(0x2944) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
            if (SHORT(0x27E0) != -1) SHORT(0x27E0)++;
            if (BITS(0x27E4) < D_001A7390) BITS(0x27E4) = D_001A7390;
            BITS(0x27E8) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
            func_L00_002BA508(); WORD(0x2294) = WORD(0x22A0); WORD(0x229C) = WORD(0x22A4);
            goto finish;
        }
        if (action != 0x83) BITS(0x24A0) = 0;
        REAL(0xBF4) = 1.0f; WORD(0xBE8) = 0; BITS(0xBE4) = 0; HALF(0xBFE) = 0;
        if (WORD(0x2294) == 0x1F) {
            if (WORD(0x1220)) {
                func_L00_002D6900(19);
                if (animate) {
                    func_L00_002D2168(0x60, 4, -1.0f);
                    func_002A7470(PTR(0x1220), 3, 4, -1);
                }
                func_L00_002B75A0(11.0f, 0.8726646900177002f, -1.0f);
            }
            goto finish;
        }
        if (WORD(0x2294) == 0x83) {
            SHORT(0xBFC) = 3;
            func_L00_0041E958(64.0f, 0.174532949924469f, 0.349065899848938f);
            if (animate) {
                selected = PTR(0x2290)[0x43] == 0x1A ? 3 : 10;
                if (WORD(0x22A0) == 1) selected = 17;
                func_L00_002D2168(0x1A, 0, (f32)selected);
            }
            goto finish;
        }
        if (WORD(0x2294) == 0x22) {
            if (animate) func_L00_002D2168(0x2C, 7, 9.0f);
            if (WORD(0x1248) == 12 && PTR(0xBE0)) {
                WORD(0xBE8) = 1;
                REAL(0xBEC) = func_00283248(*(f32 *)(PTR(0xBE0) + 0x10) - REAL(0x80),
                                            *(f32 *)(PTR(0xBE0) + 0x14) - REAL(0x84));
                func_00282CF0(VEC(0xBC0), PTR(0xBE0) + 0x10, VEC(0x80));
            }
            goto finish;
        }
        if (WORD(0x2294)==0x4D) {
            index=SHORT(0xBFC); selected=0;
            if ((WORD(0x22A4)==6 || (WORD(0x22B0)==6 && (u32)(PTR(0x2290)[0x43]-15)<2)) &&
                *(s32 *)(D_L11_00275090+index*44)==0 && REAL(0xC38)<(float)*(s32 *)(D_L11_00275090+index*44+8))
                selected=(*(s32 *)(D_L11_00275090+index*44+4)+1)%2;
            SHORT(0xBFC)=selected+7;
            func_L00_002B75A0(5.0f,0.785398244857788f,0.785398244857788f);
            if (!animate) goto finish;
            animation=selected+15; frames=5.0f; goto animate_once;
        }
        if (WORD(0x2294) == 0x14) {
            if (SHORT(0x2930) != -1) SHORT(0x2930)++;
            if (BITS(0x2934) < D_001A7390) BITS(0x2934) = D_001A7390;
            BITS(0x2938) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
            BITS(0x24A0) = 0x50; SHORT(0xBFC) = 4; WORD(0x2300) = 0;
            func_L00_002B75A0(8.0f, 1.047197699546814f, -1.0f); BITS(0xC00) = 0;
            if (animate) {
                selected = WORD(0x22A0) == 11 && WORD(0x22A8) < 42 ? 17 : 11;
                func_L00_002D2168(0x2B, 4, (f32)selected);
                animation = func_L00_002ADE68(0);
                if (func_L00_002B3248((u8 *)animation)) func_002A7470((u8 *)animation, 10, 4, selected + 2);
            }
            goto finish;
        }
        if (WORD(0x2294) == 0x15) {
            animation = D_001A7390;
            if (SHORT(0x293C) != -1) { SHORT(0x293C)++; animation = D_001A7390; }
            if (BITS(0x2940) < animation) BITS(0x2940) = animation;
            BITS(0x2944) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
            if (SHORT(0x27E0) != -1) SHORT(0x27E0)++;
            if (BITS(0x27E4) < D_001A7390) BITS(0x27E4) = D_001A7390;
            BITS(0x27E8) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
            SHORT(0xBFC) = 3; WORD(0x2300) = 0;
            func_L00_002B75A0(14.0f, 0.523598849773407f, -1.0f);
            BITS(0xC0C) = BITS(0xC0C) == 0;
            if (animate) {
                selected = PTR(0x2290)[0x43] == 0x1A ? 3 : 10;
                if (WORD(0x22A0) == 1) selected = 17;
                func_L00_002D2168(0x1A, 0, (f32)selected); func_L00_002D2470(6, 21);
            }
            goto finish;
        }
        if (WORD(0x2294) != 0x13) goto finish;
        animation = D_001A7390;
        if (SHORT(0x25B8) != -1) { SHORT(0x25B8)++; animation = D_001A7390; }
        if (BITS(0x25BC) < animation) BITS(0x25BC) = animation;
        BITS(0x25C0) |= (1u << (D_001A79F0 & 31)) | 0x80000000u;
        index = SHORT(0xBFC);
        mode = 0; WORD(0x2300) = 0;
        if ((WORD(0x22A0) == 0x13 && (f32)*(s32 *)(D_L11_00275090+index*44+8) > REAL(0xC38)) ||
            (WORD(0x22AC) == 0x13 && WORD(0x1B8) + WORD(0x22A8) < 27)) mode = (*(s32 *)(D_L11_00275090+index*44+4) + 1) % 3;
        SHORT(0xBFC) = mode;
        func_L00_002B75A0(5.0f, 0.785398244857788f, 0.785398244857788f);
        if (animate) {
            current = mode == 0 ? 0 : mode == 1 ? 2 : 4;
            selected = mode == 0 ? 5 : 7;
            if (WORD(0xBE8) && mode < 2) {
                if (!BYTE(0x22C3)) angle = func_00283C80(REAL(0xBEC), REAL(0x98));
                else angle = func_L00_002B9B38(VEC(0xBC0), 0);
                selected += func_00283CF0(angle * 1.5f);
            }
            func_L00_002D2168(mode + 0x17, current / 2, (f32)selected);
            animation = func_L00_002ADE68(0);
            if (func_L00_002B3248((u8 *)animation)) func_002A7470((u8 *)animation, mode + 3, current / 2, selected);
        }
        goto finish;
    case 0x6D:
        WORD(0x229C)=6; HALF(0xBFE)=0;
        if (WORD(0x22A0)==0x6D) {
            selected=SHORT(0xBFC); SHORT(0xBFC)=5;
            if (*(s32 *)(D_L11_00275090+4+selected*44)==0) SHORT(0xBFC)=6;
        } else SHORT(0xBFC)=5;
        selected=*(s32 *)(D_L11_00275090+4+SHORT(0xBFC)*44);
        if (animate) {
            func_L00_002D2168(selected+0x17,selected==0,5.0f);
            object= (u8 *)func_L00_002ADE68(0);
            if (func_L00_002B3248(object)) func_002A7470(object,selected+12,selected==0,5);
        }
        goto finish;
    case 0x77:
        WORD(0x229C)=10; BITS(0x24A0)=0; REAL(0xBF0)=func_00283B98(REAL(0x98),3.1415929794311523f);
        func_00282D30(VEC(0xBD0),VEC(0),-1.0f); REAL(0x1B4)=0.15f;
        if (!animate) goto finish;
        func_L00_002D2168(0x29,5,8.0f); goto finish;
    case 0x16:
        WORD(0x229C)=7; BITS(0x24A0)=0;
        func_L00_002B6118(0.5f); func_L00_002D6900(0x12);
        HALF(0x20E)=45; COPY_VECTOR(0xF0,0x120);
        func_002AC9F8((float *)VEC(0x120),0.11666667461395264f);
        effect=func_002A9640(PTR(0x2290),1,0);
        func_L00_002A4EF8(effect ? func_00283CF0(*(float *)(effect+0x2C)) : 1);
        HALF(0x1DC)=0x4D;
        if (!animate) goto finish;
        animation=0x10; mode=3; goto damage_animation;
    case 0x8C:
        WORD(0x229C)=7; BITS(0x24A0)=0; func_L00_002B6118(0.5f); BYTE(0x22BC)=1; func_L00_002D6900(0x12);
        effect=func_002A9640(PTR(0x2290),8,0);
        func_L00_002A4EF8(effect ? func_00283CF0(*(float *)(effect+0x2C)):1);
        HALF(0x1DC)=0x4D;
        if (!animate) goto finish;
        animation=0x96; mode=1; goto damage_animation;
    case 0x65:
        WORD(0x229C)=25; WORD(0x18C0)++; BITS(0x24A0)=0; func_L00_002B9B88(7,0);
        BITS(0x3A0)=0; WORD(0x1188)=0x68; BITS(0x1B0)=0; REAL(0x1B4)=0;
        if (!animate) goto finish;
        frames=8.0f; animation=0x6A; break;
    case 0x78:
        HALF(0x1F0)=10000; WORD(0x229C)=25; BITS(0x24A0)=0; func_L00_002B9B88(7,0); WORD(0x1188)=0x68;
        if (!animate) goto finish;
        frames=8.0f; animation=0x6A; break;
    case 0x79:
        WORD(0x229C)=20; REAL(0x334)=REAL(0x318); HALF(0x1F0)=10000; BITS(0x24A0)=0; WORD(0x24CC)=0;
        func_L00_002B9B88(7,0);
        if (!animate) goto finish;
        frames=8.0f; animation=0x6A; break;
    case 0x7A:
        WORD(0x229C)=20; HALF(0x1F0)=10000; REAL(0x334)=REAL(0x318); BITS(0x24A0)=0; WORD(0x24CC)=0;
        *(TI128 *)(PTR(0xC18)+0x10)=*(TI128 *)VEC(0x80);
        func_002E5CF8(7,0,(char *)PTR(0xC18));
        if (!animate) goto finish;
        frames=8.0f; animation=0x11; break;
    case 0x3F:
        WORD(0x229C)=0; BITS(0x24A0)=0;
        if (BYTE(0x149A) && SHORT(0x34C)==0) { redirect=0x4E; goto redirect_action; }
        if (!animate) goto finish;
        animation=0; frames=9.0f; break;
    case 0x4B:
        WORD(0x229C)=5; BITS(0x24A0)=0;
        if (REAL(0x170)>0.075f) func_L00_002B6118(0.075f/REAL(0x170));
        COPY_VECTOR(0xF0,0x110);
        if (!animate) goto finish;
        animation=14; frames=12.0f; break;
    case 0x41:
        WORD(0x229C)=2; REAL(0xA84)=0.0019444444915279746f; BITS(0x24A0)=0; COPY_VECTOR(0xF0,0x120);
        if (!animate) goto finish;
        animation=4; frames=8.0f; break;
    case 0x44:
        WORD(0x229C)=2; BITS(0x24A0)=0;
        if (!animate) goto finish;
        animation=4; frames=8.0f; break;
    case 0x4E:
        WORD(0x229C)=2; BITS(0x24A0)=0; COPY_VECTOR(0xF0,0x120);
        if (!animate) goto finish;
        animation=4; frames=12.0f; break;
    case 0x42:
        WORD(0x229C)=7; BITS(0x24A0)=0; func_L00_002B6118(0.5f); COPY_VECTOR(0xF0,0x120);
        func_002AC9F8((float *)VEC(0x120),0.0833333358168602f); func_L00_002A4EF8(1);
        HALF(0x20E)=0x2D; HALF(0x1DC)=0x32;
        if (!animate) goto finish;
        animation=6; mode=3;
    damage_animation:
        func_L00_002D2168(animation,mode,-3.0f);
        index=WORD(0xC34)++;
        *(u32 *)(PTR(0x2290)+0x44)=*(u32 *)(D_L11_00275220+index*4+WORD(0xC30)*100);
        goto finish;
    case 0x40:
        if (BYTE(0x149A) && SHORT(0x34C)==0) { redirect=0x4E; goto redirect_action; }
        WORD(0x229C)=1; BITS(0x24A0)=0; REAL(0x1B4)=func_00282E20(VEC(0x120));
        if (WORD(0x22A0)==3) REAL(0x1B4)=0;
        if (WORD(0x22A4)==0) REAL(0x1B4)=func_00282E20(VEC(0x160));
        BYTE(0x40F)=0; BYTE(0x40C)=0;
        if (!animate) goto finish;
        animation=2; frames=8.0f; break;
    case 0x43:
        WORD(0x229C)=20; BITS(0x24A0)=0; WORD(0x24CC)=0; COPY_VECTOR(0x160,0x120);
        if (!animate) goto finish;
        animation=5; frames=12.0f; break;
    case 0x46:
        WORD(0x229C)=3; BITS(0x24A0)=13; REAL(0x57C)=0.0033333334140479565f; REAL(0x580)=REAL(0x88);
        if (WORD(0x22A4)==4) { REAL(0x57C)=REAL(0x520); REAL(0x580)=REAL(0x490); }
        if (animate) func_L00_002D2168(8,14,7.0f);
        goto finish;
    case 0x47:
        WORD(0x229C)=3; BITS(0x24A0)=13;
        if (!animate) goto finish;
        frames=6.0f; animation=10; break;
    case 0x49:
        WORD(0x229C)=3; BITS(0x24A0)=13;
        if (!animate) goto finish;
        frames=6.0f; animation=11; break;
    case 0x4A:
        WORD(0x229C)=3; BITS(0x24A0)=13;
        if (!animate) goto finish;
        frames=6.0f; animation=12; break;
    case 0x3E:
        WORD(0x229C)=15; BITS(0x24A0)=0;
        if (!WORD(0x640)) {
            if (!PTR(0x6C4)) func_L00_002A4EF8(1);
            else { func_L00_002A4EF8(func_00283CF0(*(float *)(PTR(0x6C4)+0x2C))); PTR(0x6C4)=0; }
        }
        func_L00_002B9B88(0x14,0);
        if (WORD(0x24CC)<1) {
            angle=func_00283248(REAL(0xF0),REAL(0xF4));
            angle=func_00283B98(angle,3.1415929794311523f);
            value=func_002A78D8(0.523598849773407f,0.6108652949333191f);
            angle=func_00283B98(angle,value);
            REAL(0x120)=func_00283180(angle)*REAL(0x644)*0.7f;
            REAL(0x124)=func_00283198(angle)*REAL(0x644)*0.7f;
            REAL(0x128)=0.075f;
            if (WORD(0x640)>15 && WORD(0x24CC)<2) WORD(0x24CC)=2;
            PTR(0x2290)[0xA8]=255; func_L11_002D8EF8(0x16,1);
            HALF(0x1D0)=0x46; HALF(0x1F4)=0x96; return 0;
        }
        HALF(0x1DC)=0x4D; REAL(0x69C)=0.0416666679084301f;
        if (REAL(0x680)>0.0416666679084301f) REAL(0x680)=0.0416666679084301f;
        BITS(0x674)=0; func_00282C88((TI128 *)VEC(0xF0)); func_00282C88((TI128 *)VEC(0x110)); REAL(0xF8)=0.18333333730697632f;
        if (!animate) goto finish;
        func_L00_002D2168(0x10,2,-3.0f); goto finish;
    case 0x1C:
        BYTE(0x22BC)=1; WORD(0x229C)=9; BITS(0x24A0)=0;
        animation=func_L03_002AB5C8(0); frames=10.0f; break;
    case 0x1D:
        BITS(0x24A0)=0x51; WORD(0x229C)=0;
        weaponMode=func_L00_002A4EF0(PTR(0x2290)[0x42]);
        if (weaponMode==func_L03_002AB5C8(0)) goto finish;
        animation=func_L03_002AB5C8(0); frames=5.0f; break;
    case 0x1E:
        WORD(0x229C)=9; BITS(0x24A0)=0;
        animation=func_L03_002AB5C8(0); frames=10.0f; break;
    case 0x6F:
        WORD(0x229C)=9; BYTE(0x22BC)=1; BITS(0x24A0)=0; func_L00_002AF7D0();
        if (!animate) goto finish;
        animation=func_L03_002AB5C8(0); frames=10.0f; break;
    case 0x26:
        WORD(0x229C)=8; BITS(0x24A0)=0;
        animation=func_L03_002AB5C8(0); frames=10.0f; break;
    case 0x31:
        WORD(0x229C)=9; BYTE(0x22BC)=1; BITS(0x24A0)=0; BYTE(0x22B7)=1; BYTE(0x22BD)=1;
        func_L00_00322EC8((SmallSlotReset128Owner *)VEC(0x1A30));
        if (!animate) goto finish;
        animation=func_L03_002AB5C8(0); frames=-1.0f; break;
    case 0x75:
        BYTE(0x22BC)=1; WORD(0x229C)=9; BITS(0x24A0)=0; BYTE(0x22B7)=1;
        func_00282C88((TI128 *)VEC(0xF0));
        if (!animate) goto finish;
        frames=-1.0f; animation=11; break;
    case 0x60:
    case 0x61:
        WORD(0x229C)=24; BYTE(0x22BC)=1; func_L00_00322EC8((SmallSlotReset128Owner *)VEC(0x1A30));
        func_L00_002AF7D0();
        if (animate) func_L00_002D2168(func_L03_002AB5C8(0),0,-1.0f);
        goto finish;
    default: goto finish;
    }
    func_L00_002D2168(animation,0,frames);
    goto finish;
redirect_action:
    func_L11_002D8EF8(redirect,1); return 0;
animate_two:
    func_L00_002D2168(animation,2,frames); goto finish;
animate_five:
    func_L00_002D2168(animation,5,frames); goto finish;
finish:
    if (wasGliding && !BYTE(0x22B7)) BITS(0x231C)=1;
    if (!SHORT(0x348) && WORD(0x1298)==0x13 && WORD(0x2304)) BITS(0x2320)=1;
    if ((u32)(WORD(0x229C)-13)>2 && (WORD(0x2294)!=6 || WORD(0x22A0)!=0x24) && WORD(0x1298)==0x14 && WORD(0x2304)) BITS(0x2320)=1;
    if (WORD(0x229C)==20) { func_L00_002AF7D0(); BYTE(0x22BC)=1; }
    if ((!func_L00_002ADF80() || WORD(0x229C)==18) && (REAL(0x330)<D_L11_001BA8C8 || !WORD(0x229C))) D_L11_001BAB80=0;
    if (WORD(0x229C)!=WORD(0x22A4)) func_L00_002A6708();
    if (WORD(0x229C)!=WORD(0x22A4)) BITS(0x1BC)=0;
    BITS(0x1C4)=0; BITS(0x1C0)=0; WORD(0x1B8)=0;
    return 1;
}
