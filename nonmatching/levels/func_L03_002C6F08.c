/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 absent from catalogue; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/*
 * Nonmatching reconstruction of the Endako state-entry dispatcher.
 * Retail US: 15416 bytes, one placement; final local check: 15320 bytes,
 * zero of one placements match. US2 and PAL have no catalogue entry.
 * Reproduce from the original source path with this exact per-file profile:
 * -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 *
 * All 148 retail switch entries are represented. Distinct handlers follow
 * increasing retail destinations; alias labels retain their shared body.
 * The 44-byte transition-record stride, 100-byte float-table row stride,
 * vector workspaces, memory access widths and consumed helper argument banks
 * were checked against retail. The resident byte view claims no full size.
 *
 * Bounded trials covered entry snapshots, shared case workspace, a named
 * resident view, G8/G0 profiles, physical handler order and snapshot timing.
 * Earlier compiled sizes:14980,15024,15024,14928,15016,15024 bytes.
 * Handler ordering produced15320; later snapshot timing produced15076.
 * Size proximity alone is not an instruction match. The frame remains0xA0
 * versus retail0x80, with different saved registers and branch allocation.
 * Reopen when a faithful resident-field/lifetime model explains the frame
 * and register allocation; further arbitrary case or flag sweeps are not useful.
 */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));
typedef union { u128 bits; float f[4]; } Vec4;
struct Rac2Native_5b4b17178a13f443_SmallSlotReset128Owner;
typedef struct Rac2Native_5b4b17178a13f443_SmallSlotReset128Owner SmallSlotResetOwner;
typedef struct {
    char pad0[35]; u8 f35; char pad36[8]; float f44;
    u8 f48, f49; u16 f50, f52; char pad54[2]; s64 f56;
    char pad64[34]; u8 f98; char pad99[21]; int f120;
    u16 f124; char pad126[26]; int f152; char pad156[14]; s16 f170;
} Src_F66766f2b;
typedef struct {
    char pad0[256]; int a[4], b[4]; Src_F66766f2b *c[4]; float d[4];
    int pad320; Src_F66766f2b *src; int count;
} List_F66766f2b;
typedef List_F66766f2b SlotList;
/* Three observed words in each 44-byte transition record; the tail is not interpreted. */
typedef struct { s32 kind, next, limit; u8 tail[32]; } TransitionRecord44;
extern u8 D_00189E20[];
extern u32 D_001A7390 MACRO_ADDR;
extern u32 D_001A79F0 NOT_SDA;
extern s32 D_001A7B90 NOT_SDA;
extern u8 D_001A7A45 NOT_SDA;
extern s32 D_L03_001A8F00 NOT_SDA;
extern s32 D_L03_001A8FF4 __attribute__((sda));
extern s32 D_L03_001A9010 NOT_SDA;
extern float D_L03_001A7CD8 __attribute__((sda));
extern float D_L03_001A7CDC __attribute__((sda));
extern s32 D_L03_001A7DD8[] __attribute__((sda));
extern u8 D_L03_001A7DE0[] __attribute__((sda));
extern u8 D_L03_001A7E00[] __attribute__((sda));
extern TransitionRecord44 D_L03_00262290[];
extern float D_L03_00262420[][25];
extern float D_L03_001B9988 NOT_SDA;
extern s32 D_L03_001B9C40 NOT_SDA;
extern void func_L00_00322EC8(SmallSlotResetOwner *);
extern void func_L00_002D6940(void);
extern void func_L00_002AF3D8(s32, s32);
extern void func_L00_002AF7D0(void);
extern s32 func_002A7820(s32, s32);
extern void func_L00_002AB3E0(void);
extern void func_L00_002C8BA8(s32);
extern s32 func_L03_002AB5C8(s32);
extern void func_00282C88(u128 *);
extern void func_L00_002D2168(s32, s32, float);
extern void func_002A7470(void *, s32, s32, s32);
extern float func_L00_002D3A58(char *);
extern void func_L00_002B39F0(s32, float);
extern float func_00283C80(float, float);
extern float func_00282E20(void *);
extern s32 func_L00_002CAF20(void);
extern unsigned long func_L00_002A4EF0(unsigned long);
extern void func_002AC9F8(float *, float);
extern s32 func_L00_002B9B88(s32, s32);
extern void func_L00_002D2470(s32, s32);
extern float func_00283248(float, float);
extern float func_00282E48(void *, void *);
extern s32 func_L00_00341820(void *, void *, s32 *, float *, s32, float);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DF0(void *);
extern void func_00282F20(void *, void *, float);
extern float func_00282DB0(void *, void *);
extern float func_00283B98(float, float);
extern s32 func_L00_0035F5A0(s32, s32, s32);
extern float func_002A78D8(float, float);
extern void func_L00_002B6118(float);
extern void func_L00_002A61C8(s32, s32, s32, s32);
extern void func_L00_002AABE0(s32, s32, s32);
extern void func_L00_00322A98(void *, char *);
extern void func_L00_00322AC0(List_F66766f2b *, s32, s32, float);
extern void func_L00_002A4EF8(s32);
extern s32 func_L00_002D6900(u32);
extern float func_L00_002AE070(s32);
extern s32 func_L00_002C3A78(void);
extern s32 func_00283CF0(float);
extern void func_L00_002BA508(void);
extern void func_L00_002B75A0(float, float, float);
extern u32 func_L00_002ADE68(s32);
extern s32 func_L00_002B3248(u8 *);
extern void func_L00_0041E958(float, float, float);
extern float func_L00_002B9B38(void *, s32);
extern void func_00282D30(void *, void *, float);
extern void *func_002A9640(void *, u32, s32);
extern s32 func_002E5CF8(s32, s32, char *);
extern float func_00283180(float);
extern float func_00283198(float);
extern s32 func_L00_002ADF80(void);
extern void func_L00_002A6708(void);

/* Partial resident views follow the actual load/store widths; no full player-object size is claimed. */
#define H(type, offset) (*(type *)(D_00189E20 + (offset)))
#define HP(offset) ((void *)(D_00189E20 + (offset)))

s32 func_L03_002C6F08(s32 requested, s32 reset)
{
    u8 *entryObject = H(u8 *,0x2290);
    s32 entrySubstate = H(s32,0x2298);
    u8 wasAirborne = H(u8,0x22B7);
    float speed = 0.0f, angle, value;
    s32 animation = 0, blend = 0, state = (s32)requested, n, index;
    s32 redirect;
    u8 *object;
    union {
        struct { Vec4 delta, output; struct { s32 index; float time[3]; } cursor; } path;
        Vec4 jumpTarget;
    } scratch;
    u64 code;
    if (H(s32,0x229C) == 20 && (requested != 0x61 || reset != 2)) return 0;
    if ((D_L03_001A8F00 == 2 || D_L03_001A8F00 == 6) && reset != 2) return 0;
    if (!H(s32,0x24CC) && (H(s32,0x229C) == 2 || H(s32,0x229C) == 7)) {
        switch (requested) {
        case 6: case 0x39: case 0x43: case 0x91: case 0x5F: case 0x74:
        case 0x78: case 0x79: case 0x7C: case 0x67: case 0x7D: case 0x7F: break;
        default: return 0;
        }
    }
    H(s32,0x22AC) = H(s32,0x22A0);
    H(s32,0x22B0) = H(s32,0x22A4);
    H(s32,0x22A8) = H(s32,0x1B8);
    H(s32,0x22A0) = H(s32,0x2294);
    H(s32,0x22A4) = H(s32,0x229C);
    H(s32,0x2298) = 0;
    if (H(u8,0x22B5) == 1) H(u8,0x22B5) = 0;
    H(u8,0x22BC) = 0;
    H(s32,0x2294) = state;
    if (!H(u8,0x22B4)) {
        *(s32 *)(H(u8 *,0x2290) + 0x9C) = 0;
        H(u8,0x22BD) = 0; H(u8,0x22B7) = 0; H(u8,0x22C2) = 0;
        H(u8,0x22BF) = 0; H(s16,0x2504) = 0;
        func_L00_00322EC8((SmallSlotResetOwner *)HP(0x18E0));
    }
    if (!H(s16,0x1FA)) func_L00_002D6940();
    func_L00_002AF3D8(H(s32,0x22A0), H(s32,0x2294));
    H(s32,0x1188) = 0;
    switch (requested) {
    case 0:
        H(s32,0x229C) = 0; H(s32,0x24A0) = 0;
        if (H(s32,0x1248) == 26) func_L00_002AF7D0();
        H(u8,0x24EF) = 0;
        H(s32,0x11A0) = func_002A7820(50,100);
        func_L00_002AB3E0();
        if (H(u8,0x22B4)) { func_L00_002C8BA8(0); return 1; }
        H(u128,0x160) = H(u128,0x120);
        if (H(u8,0x149A) && !H(s16,0x34C)) { redirect = 0x76; goto redirectState; }
        H(s32,0x1188) = 0x68;
        if (!reset) goto finish;
        code = func_L03_002AB5C8(0);
        speed = code == 0x51 ? 18.0f : -1.0f;
        animation = func_L03_002AB5C8(0);
        goto play;
    case 100:
        H(s32,0x229C)=0; H(s32,0x24A0)=0; func_00282C88(HP(0x160)); H(s32,0x1188)=0x68;
        if (!reset) goto finish;
        code=func_L03_002AB5C8(0); animation=func_L03_002AB5C8(0); speed=code==0x51 ? 18 : -1; goto play;
    case 61:
        func_L00_002D2168(func_L03_002AB5C8(0),0,9);
        object=H(u8 *,0x1854); if (object) func_002A7470(object,0,0,9);
        goto finish;
    case 57:
        H(s32,0x229C)=20; H(s32,0x24A0)=0; H(u128,0x160)=H(u128,0x120);
        if (!reset) goto finish;
        animation=69; speed=12; goto play;
    case 133:
        H(s32,0x229C)=32; H(s32,0x24A0)=8; H(u8,0x22C2)=1; H(u8,0x22B7)=1;
        if (reset) func_L00_002D2168(79,0,5);
        object=H(u8 *,0x1830); H(float,0x98)=*(float *)(object+0xF8); H(u128,0x80)=*(u128 *)(object+0x10);
        func_00282C88(HP(0xF0)); goto finish;
    case 1:
        H(s32,0x24A0) = 4; H(s32,0x229C) = 0;
        if (H(u8,0x22BA)) goto finish;
        animation = func_L03_002AB5C8(1);
        if (H(u8 *,0x2290)[0x43] == animation || !reset) goto finish;
        speed = 18.0f; goto play;
    case 47:
        H(s32,0x229C)=8; H(s32,0x24A0)=0; H(u128,0x160)=H(u128,0x110);
        func_L00_002D2168(func_L03_002AB5C8(0),0,5); H(s16,0x1EC)=7; goto finish;
    case 2: case 0x70:
        H(s32,0x229C) = 1; H(s32,0x24A0) = 0;
        if (H(s32,0x22A4) != 4 && H(s32,0x22B0) != 4) H(float,0x1B4) = func_L00_002D3A58(HP(0x120));
        H(u128,0x3F0) = H(u128,0); H(s32,0x410) = 0;
        H(float,0x408) = H(float,0x98);
        if (H(float,0x1B4) > 0.116666675f) H(float,0x1B4) = 0.116666675f;
        H(u8,0x40F) = 0;
        func_L00_002B39F0(0,1.0f);
        angle = func_00283C80(H(float,0x98),H(float,0x1A0));
        if (angle > 1.5707965f && (H(s32,0x22A4) == 4 || H(s32,0x22A0) == 3 || H(s32,0x22AC) == 3)) H(float,0x1B4) = 0;
        H(s32,0x1188) = 0x68;
        if (H(u8,0x149A) && (!H(s16,0x34C) || H(float,0x31C) < 0.3f)) { redirect = 0x76; goto redirectState; }
        H(s32,0x2298) = 0; H(u8,0x40C) = 0; H(u8,0x40E) = 0;
        if (!reset) goto finish;
        n = H(s32,0x24CC) == 1 ? 12 : 8;
        if (H(s32,0x22AC) == 0x22 || H(s32,0x22A0) == 0x22 || H(s32,0x22AC) == 0x83 || H(s32,0x22A0) == 0x83) n = 15;
        if (H(s32,0x22A0) == 0x13) n = 13;
        if (H(s32,0x22AC) == 6 || H(s32,0x22AC) == 0x2C) n = 18;
        if (H(s32,0x22B0) == 4 && H(u8,0x49C) > 5) n = 13;
        func_L00_002D2168(H(s32,0x2298)+3,D_L03_001A7DD8[H(s32,0x2298)],(float)n);
        goto finish;
    case 123:
        H(s32,0x1188)=0x68; H(s32,0x229C)=28; H(s32,0x24A0)=0;
        if (H(s32,0x1298)!=54) { H(s32,0x22CC)=54; H(s32,0x2304)=H(s32,0x1298); }
        H(u128,0xF0)=H(u128,0x110);
        if (!reset) goto finish;
        animation=139; speed=-2; goto play;
    case 98:
        H(s32,0x229C)=1; H(s32,0x24A0)=0; H(float,0x1B4)=func_00282E20(HP(0x120)); H(u8,0x22BC)=1;
        if (!H(u8,0x22B4)) func_L00_002AF7D0();
        if (!reset) goto finish;
        if (H(u8,0x22B4)==1) { speed=8; animation=2; goto play; }
        if (H(u8,0x22B4)) goto finish;
        func_L00_002D2168(H(s32,0x2298)+3,D_L03_001A7DD8[H(s32,0x2298)],8.0f); goto finish;
    case 3:
        H(s32,0x229C) = 1; H(s32,0x24A0) = 0;
        H(u128,0x160) = H(u128,0x120);
        if (H(u8,0x149A) && !H(s16,0x34C)) { redirect = 0x76; goto redirectState; }
        if (func_L00_002CAF20()) return 0;
        if (func_L03_002AB5C8(0) == 0x51) {
            if (!reset) goto finish;
            if (!func_L03_002C6F08(0,0)) return 0;
            func_L00_002D2168(func_L03_002AB5C8(0),0,18.0f);
            return 0;
        }
        if (!reset) goto finish;
        animation = 6;
        if (func_L00_002A4EF0(entryObject[0x42]) == 4 && H(float,0xC38) > 3.0f && H(float,0xC38) < 16.0f) animation = 5;
        speed = 9.0f; goto play;
    case 99:
        H(s32,0x229C)=1; H(s32,0x24A0)=0; H(float,0x1B4)=func_L00_002D3A58(HP(0x120)); H(u128,0x160)=H(u128,0x120);
        if (!reset) goto finish;
        animation=6;
        if (func_L00_002A4EF0(entryObject[0x42])==4 && H(float,0xC38)>3 && H(float,0xC38)<16) animation=5;
        speed=9; blend=4; goto play;
    case 4:
        H(s32,0x229C) = 12; H(s32,0x24A0) = 0;
        H(float,0x1B4) = func_00282E20(HP(0x120));
        if (H(float,0x1B4) > 0.116666675f) H(float,0x1B4) = 0.116666675f;
        if (H(u8,0x149A) && !H(s16,0x34C)) { redirect = 0x76; goto redirectState; }
        H(s32,0x1188) = 0x68; H(u128,0x160) = H(u128,0x120);
        func_002AC9F8(HP(0xF0),0.116666675f);
        if (H(float,0x178) > 0.058333337f) func_L00_002B9B88(9,0);
        if (reset) {
            speed = H(u8 *,0x2290)[0x42] == func_L03_002AB5C8(0) ? 9.0f : 14.0f;
            func_L00_002D2168(13,2,speed);
            func_L00_002D2470(3,18);
        }
        goto finish;
    case 138:
        H(s32,0x229C)=33; H(s32,0x24A0)=0;
        if (H(u16,0x25DC)!=0xFFFF) ++H(u16,0x25DC);
        if (H(u32,0x25E0)<D_001A7390) H(u32,0x25E0)=D_001A7390;
        H(u32,0x25E4)|=(1U<<(D_001A79F0&31))|0x80000000U;
        object=H(u8 *,0xB10); H(float,0x1A0)=func_00283248(*(float *)(object+0x10)-H(float,0x80),*(float *)(object+0x14)-H(float,0x84));
        H(s32,0xB1C)=0; goto shortClimb;
    case 139:
        H(s32,0x229C)=33; H(u8,0x22BC)=1; H(s32,0x24A0)=0; goto finish;
    case 35:
        H(s32,0x229C)=13; H(s32,0x24A0)=7;
        if (H(u16,0x25DC)!=0xFFFF) ++H(u16,0x25DC);
        if (H(u32,0x25E0)<D_001A7390) H(u32,0x25E0)=D_001A7390;
        H(u32,0x25E4)|=(1U<<(D_001A79F0&31))|0x80000000U;
        object=H(u8 *,0xAA4);
        H(float,0x1A0)=func_00283248(*(float *)(object+0x10)-H(float,0x80),*(float *)(object+0x14)-H(float,0x84));
        if (H(s32,0x22A0)==40) H(u128,0x160)=H(u128,0xF0);
        goto shortClimb;
    case 36:
        H(u8,0x22BC)=1; H(s32,0x229C)=13; H(s32,0x24A0)=7; H(s32,0xAA0)=0; H(s32,0xAB4)=0;
        if (!reset) goto finish;
        speed=10; animation=48; blend=1; goto play;
    case 37:
        H(u8,0x22BC)=1; H(s32,0x229C)=13; H(s32,0x24A0)=7; H(s32,0xAA0)=0; H(s32,0xAB4)=0;
        H(float,0xABC)=func_00282E48(HP(0x80),H(u8 *,0xAA4)+0x10);
        if (!reset) goto finish;
        speed=5; animation=48; blend=1; goto play;
    case 43:
        H(s32,0x229C)=14; H(s32,0x24A0)=7;
        if (H(u16,0x25DC)!=0xFFFF) ++H(u16,0x25DC);
        if (H(u32,0x25E0)<D_001A7390) H(u32,0x25E0)=D_001A7390;
        H(u32,0x25E4)|=(1U<<(D_001A79F0&31))|0x80000000U;
        H(s16,0xAFE)=1; H(s32,0xAE8)=0; H(u8,0x22BC)=1;
        H(u8 *,0xAD4)=H(u8 *,0xAD0); H(s16,0xADC)=0; H(s16,0xAFC)=0; H(s32,0xAF4)=0; H(s32,0xAF8)=0;
        object=*(u8 **)(H(u8 *,0xAD0)+0x68);
        H(s32,0xAE0)=*(s32 *)(object+4);
        value=*(float *)(object+0x10); if (value==0) value=*(float *)(object+12); *(float *)(object+0x14)=value;
        H(float,0xB08)=0.33f; H(float,0xB0C)=0.18333334f; H(float,0xB04)=0.025f;
        func_00282C88(HP(0xA0)); H(s16,0x206)=40;
        if (*(float *)(object+0x24)!=0) H(float,0xB04)=*(float *)(object+0x24);
        if (*(float *)(object+0x28)!=0) H(float,0xB08)=*(float *)(object+0x28);
        if (*(float *)(object+0x2C)!=0) H(float,0xB0C)=*(float *)(object+0x2C);
        object=H(u8 *,0xAD4);
        H(float,0xAEC)=func_00283248(*(float *)(object+0x10)-H(float,0x80),*(float *)(object+0x14)-H(float,0x84));
        H(float,0xAE4)=func_00282E48(HP(0x80),object+0x10); H(float,0xAF0)=0.0075000003f;
        if (H(s32,0x22A4)==4) H(float,0xAF0)=H(float,0x520);
        else if (H(s32,0x22A4)==2) H(float,0xAF0)=H(float,0xA80);
        if (reset) { func_L00_002D2168(52,0,11); H(float,0xC20)=0.7f; }
        goto finish;
    case 44:
        H(s32,0x24A0)=7; H(s32,0x229C)=2; func_00282C88(HP(0xA0)); H(u128,0xF0)=H(u128,0x120);
        if (!reset) goto finish;
        speed=15; animation=11; goto play;
    case 39:
        H(s32,0x24A0)=3; H(s32,0x1188)=0x68; H(s32,0x648)=1; H(float,0x658)=-1.5707965f;
        H(s32,0x229C)=15; H(s32,0x640)=0; H(s32,0x6C8)=0; H(s32,0x65C)=0;
        if (H(s32,0x22A4)!=15) { H(s32,0x674)=0; H(s32,0x67C)=-1; H(float,0x680)=0; }
        scratch.path.cursor.index=H(s32,0x634); scratch.path.cursor.time[0]=H(float,0x638);
        H(s32,0x6B0)=0; H(s32,0x6B4)=0; H(s16,0x6BE)=0; H(s32,0x684)=0;
        H(s32,0x688)=0; H(s16,0x68C)=0; H(s32,0x690)=0;
        func_L00_00341820(H(void *,0x630),&scratch.path.output,&scratch.path.cursor.index,scratch.path.cursor.time,H(s32,0x654),1.0f);
        func_00282CF0(&scratch.path.delta,&scratch.path.output,HP(0x80));
        value=func_00282DF0(&scratch.path.delta);
        if (value>0.001f) {
            func_00282F20(&scratch.path.delta,&scratch.path.delta,1.0f);
            if (H(s32,0x22A4)!=15) H(float,0x680)=func_00282DB0(HP(0x110),&scratch.path.delta);
        }
        object=H(u8 *,0x6A8);
        if (object) {
            angle=func_00283248(*(float *)(object+0x10)-H(float,0x80),*(float *)(object+0x14)-H(float,0x84));
            value=func_00283248(scratch.path.delta.f[0],scratch.path.delta.f[1]); value=func_00283B98(H(float,0x658),value);
            if (func_00283C80(angle,value)>1.5707965f) { H(float,0x658)=1.5707965f; H(s32,0x65C)=1; }
        }
        if (reset) func_L00_002D2168(H(s32,0x65C)+49,0,6);
        goto finish;
    case 23:
        H(s32,0x229C)=3; H(s32,0x24A0)=13;
        H(float,0x57C)=0.0061111115f;
        H(float,0x580)=H(float,0x88);
        if (H(s32,0x22A4)==4) { H(float,0x57C)=H(float,0x520); H(float,0x580)=H(float,0x490); }
        H(u8,0x22BC)=1; H(u8,0x22BF)=1;
        if (!reset) goto finish;
        animation=32;
        if (H(float,0x174)<=0.058333337f) { speed=11; blend=1; } else speed=9;
        goto play;
    case 24:
        H(s32,0x229C)=3; H(s32,0x24A0)=13; H(u8,0x22BC)=1; H(u8,0x22BF)=1;
        H(s32,0x1188)=0x68;
        if (!reset) goto finish;
        speed=6; animation=33; goto play;
    case 25:
        H(s32,0x229C)=3; H(s32,0x24A0)=13; H(u8,0x22BC)=1; H(u8,0x22BF)=1;
        if (!reset) goto finish;
        speed=6; animation=36; goto play;
    case 26:
        H(s32,0x229C)=3; H(s32,0x24A0)=13; H(u8,0x22BC)=1; H(u8,0x22BF)=1;
        if (!reset) goto finish;
        speed=6; animation=37; goto play;
    case 118:
        H(s32,0x229C)=2; H(s32,0x24A0)=0; H(u128,0xF0)=H(u128,0x120);
        if (!reset) goto finish;
        animation=11; speed=12; goto play;
    case 6: case 0x74:
        H(s32,0x229C) = 2; H(s32,0x24A0) = 0;
        if (H(s32,0x2294) == 0x74) {
            H(s32,0x229C) = 20;
            if (H(u8,0x22B4) == 1) {
                if (D_001A79F0 == 3) func_L00_0035F5A0(17,0,(s32)H(u8 *,0x2290));
                else if (D_001A79F0 == 14) func_L00_0035F5A0(21,0,(s32)H(u8 *,0x2290));
            }
        }
        H(float,0xA80) = 0.0061111115f; H(u32,0xA84) = 0x3AFEDCBB;
        if (H(s32,0x2294) == 0x74) {
            if (!H(u8,0x22B4)) H(s16,0x24D6) = func_L00_002B9B88(14,32);
            H(float,0xA90) = func_002A78D8(0.05235988646745682f,0.072722062f);
            H(float,0xA94) = func_002A78D8(0.05235988646745682f,0.072722062f);
        }
        H(s32,0x1188) = 0x68; H(s32,0x2298) = 0; H(u128,0xF0) = H(u128,0x120);
        if (!reset) goto finish;
        if (H(u8,0x22B4) == 1) { func_L00_002D2168(4,0,8.0f); return 1; }
        if (H(float,0x31C) > 1.75f) { func_L00_002D2168(11,0,12.0f); H(s32,0x2298) = 1; goto finish; }
        speed = 10.0f; animation = 10; goto play;
    case 130:
        H(s32,0x229C)=30; H(s32,0x24A0)=0;
        if (H(s32,0x22A0)!=22) {
            H(float,0x5B0)=50;
            if (H(float,0x5B8)!=0) { H(float,0x5B8)=0; H(float,0x5B0)=H(float,0x5B8); }
        }
        H(u8,0x24EF)=1; H(s32,0x1188)=0x68; H(s32,0x7A8)=0; H(s16,0x5BE)=0;
        H(s32,0x5A8)=0; H(s32,0x5A4)=0; H(s16,0x5BC)=7; H(u128,0xF0)=H(u128,0x110);
        if (!reset) goto finish;
        animation=19; speed=-2; goto play;
    case 8:
        H(s32,0x229C)=5; H(s32,0x1188)=0x68; H(s32,0x24A0)=0;
        if (H(float,0x170)>0.075f) func_L00_002B6118(0.075f/H(float,0x170));
        H(s32,0x24C8)=0; H(u128,0xF0)=H(u128,0x110);
        if (!reset) goto finish;
        speed=-2; animation=19; goto play;
    case 7: case 9: case 10: case 11: case 12: case 13: case 14:
    case 15: case 16: case 17: case 18: case 27: case 40: case 41:
    case 56: case 69: case 72: case 91: case 102: case 110: case 129:
    case 137: case 146:
        object = H(u8 *,0x33C);
        if (H(s32,0x2294) != 0x81 && object && (*(s16 *)(object+0xAA) == 0x9B9 || *(s16 *)(object+0xAA) == 0xF05)) { redirect=0x81; goto redirectState; }
        if (H(s32,0x2294) != 0x6E && H(s16,0x348) == 1 && requested != 14 && requested != 56 && !D_L03_001A8FF4) { redirect=0x6E; goto redirectState; }
        H(u8,0x24DB) = H(s32,0x22A0) == 17 && !H(u8,0x24DA) ? H(u8,0x24DB)+1 : 0;
        if (H(s16,0x1F2)) { redirect=0x82; goto redirectState; }
        if (H(s16,0x212)) {
            H(s32,0x1B8)=H(s32,0x22A8); H(s32,0x1188)=0;
            H(s32,0x2294)=H(s32,0x22A0); H(s32,0x2298)=entrySubstate; return 0;
        }
        H(s32,0x229C)=4;
        H(s32,0x24A0)=(u32)(state-40)<2 ? 3 : 0x50;
        if (H(s32,0x2294)==7 || H(s32,0x2294)==15 || H(s32,0x2294)==13 || (H(s32,0x2294)==11 && H(s32,0x22A4)!=4)) {
            func_L00_002A61C8(H(u8,0x149D),0,0,30);
            func_L00_002A61C8(H(u8,0x149D),1,0,30);
        }
        H(u128,0xF0)=H(u128,0x120);
        if (H(s32,0x2294)!=18 && H(u8,0x1494) && H(float,0x88)<H(float,0x330)+0.5f) func_L00_002AABE0(3,16,0);
        H(float,0x490)=H(float,0x88); H(float,0x520)=0.00825f;
        H(s32,0x448)=-1; H(u32,0x500)=0x3BB60B61;
        H(u16,0x528)=H(u8,0x1492); H(u16,0x51A)=0x50;
        H(u32,0x494)=0x3E80157C; H(u32,0x4A0)=0x3F555556;
        H(u8,0x49E)=0; H(u8,0x49C)=0; H(s32,0x4B0)=0; H(s32,0x4B4)=0;
        H(u8,0x49D)=0; H(u32,0x504)=0x3B483FB8; H(float,0x510)=2.5f;
        H(s16,0x524)=0; H(u8,0x52C)=0; H(u8,0x52E)=0; H(u8,0x52F)=0;
        H(s16,0x52A)=70; H(s16,0x526)=0; H(float,0x514)=0.5f;
        H(u32,0x4A4)=0x3DCB17E5; H(s32,0x458)=0; H(u8,0x49F)=0;
        H(s32,0x594)=0; H(s16,0x24D8)=0;
        switch (H(s32,0x2294)) {
        case 7:
            H(u32,0x458)=0x3C1E2585; H(float,0x4CC)=30; H(float,0x4D0)=12;
            H(float,0x50C)=2.3f; H(float,0x508)=1.28f; H(float,0x4A8)=1.28f;
commonJumpTuning:
            H(u8,0x52F)=1; H(s16,0x518)=15; H(float,0x4C8)=18;
            H(float,0x4B8)=0.6f; H(s16,0x4AC)=5; H(u32,0x4A4)=0x3DCB17E5;
            H(u8,0x52C)=1; H(u8,0x52E)=1; break;
        case 0x81:
            H(float,0x50C)=D_L03_001A7CD8+0.5f; H(float,0x520)=D_L03_001A7CDC*0.00027777778f;
            H(s16,0x4AC)=5; H(float,0x4B8)=0.6f; H(float,0x4C8)=18;
            H(float,0x4CC)=30; H(float,0x4D0)=12; H(float,0x508)=D_L03_001A7CD8;
            H(s16,0x518)=15; H(s16,0x51A)=400; H(float,0x510)=300;
            H(s16,0x52A)=1200; H(u32,0x4A4)=0x3DEEEEF0; H(float,0x4A8)=D_L03_001A7CD8;
            H(s16,0x526)=1200; if (D_001A79F0==16) H(u32,0x4A4)=0;
            func_L00_00322A98(H(u8 *,0x2290),HP(0x18E0));
            func_L00_00322AC0((SlotList *)HP(0x18E0),70,2,0.0f);
            func_L00_00322AC0((SlotList *)HP(0x18E0),35,4,0.0f);
            func_L00_00322AC0((SlotList *)HP(0x18E0),17,6,0.0f); break;
        case 56:
            H(s16,0x4AC)=5; H(float,0x4B8)=0.6f; H(float,0x4C8)=18;
            H(float,0x4CC)=26; H(float,0x4D0)=13; H(float,0x50C)=5.55f; H(float,0x508)=5.5f;
            H(s16,0x518)=2; H(s16,0x51A)=120; H(u8,0x49F)=1; H(float,0x4A8)=5.5f;
            func_L00_002A4EF8(1);
            if (H(s32,0x22A0)==56 || H(s32,0x22AC)==56 || !H(s32,0x24CC)) {
                ++H(s32,0x18C0);
                if (H(s32,0x18C0)>2 || !H(s32,0x24CC)) {
                    if (D_001A79F0==2 && D_L03_001A9010) redirect=0x7D;
                    else {
                        redirect=0x79;
                        if (!*(s32 *)(*(u8 **)(H(u8 *,0x2290)+0x24)+0x1F0)) { func_L03_002C6F08(0x39,1); return 0; }
                    }
                    goto redirectState;
                }
            } else H(s32,0x18C0)=0;
            H(s16,0x52A)=150; H(s16,0x51E)=4; H(float,0x520)=0.004166667f; H(s16,0x51C)=5; break;
        case 40:
            H(s16,0x4AC)=5; H(float,0x4B8)=0.8f; H(float,0x4C8)=18; H(float,0x4CC)=28; H(float,0x4D0)=14;
            H(float,0x50C)=2.45f; H(float,0x508)=2.4f; H(s16,0x518)=17; H(s32,0x229C)=15;
            H(float,0x520)=0.0075000003f; H(float,0x4A8)=2.4f; H(s32,0x694)=0;
            if (H(u8,0x1498)) {
                scratch.jumpTarget.f[0]=331.0f; scratch.jumpTarget.f[1]=104.0f; scratch.jumpTarget.f[2]=145.0f; scratch.jumpTarget.f[3]=0;
                H(float,0x508)=7.1f; H(float,0x50C)=7.1499996f; H(float,0x520)=0.003888889f; H(float,0x4A8)=7.1f;
                if (func_00282E48(HP(0x80),&scratch.jumpTarget)<10) { H(float,0x4A8)+=0.7f; H(float,0x508)+=0.7f; H(float,0x50C)+=0.7f; }
            }
            break;
        case 41:
            H(s16,0x4AC)=2; H(float,0x4B8)=0.8f; H(float,0x4C8)=18; H(float,0x4CC)=31; H(float,0x4D0)=14;
            H(float,0x50C)=2.55f; H(float,0x508)=2.5f; H(s16,0x518)=10; H(s32,0x229C)=15;
            H(float,0x520)=0.006666667f; H(s32,0x694)=0; H(float,0x4A8)=2.5f; break;
        case 9:
            H(float,0x4CC)=29; H(float,0x4D0)=11; H(float,0x50C)=2.7f; H(float,0x508)=1; H(float,0x4A8)=1;
            goto commonJumpTuning;
        case 110:
            H(float,0x4B8)=0.6f; H(u32,0x4A4)=0x3DED9E84; H(float,0x4C8)=18; H(float,0x4CC)=30; H(float,0x4D0)=12;
            H(float,0x50C)=2.75f; H(float,0x508)=2.7f; H(s16,0x518)=5; H(u8,0x49F)=1;
            H(float,0x4A8)=2.7f; H(s16,0x4AC)=5; H(u8,0x52C)=1; H(u8,0x52E)=0; H(u8,0x52F)=0; break;
        case 69:
            H(s16,0x4AC)=3; H(u32,0x4A4)=0x3D088889; H(float,0x4B8)=0.6f;
            H(float,0x4C8)=15; H(float,0x4CC)=24; H(float,0x4D0)=12;
            H(float,0x50C)=1.35f; H(float,0x508)=1.3f; H(s16,0x518)=14; H(float,0x520)=0.0069444445f;
            H(u32,0x504)=0x3C638E39; H(float,0x4A8)=1.3f; break;
        case 10:
            H(s16,0x526)=70; H(s16,0x4AC)=5; H(float,0x4B8)=0.6f; H(float,0x4C8)=18; H(float,0x4CC)=29; H(float,0x4D0)=10;
            H(float,0x50C)=1.95f; H(float,0x508)=1.9f; H(s16,0x518)=14; H(float,0x520)=0.0030555557f;
            H(u8,0x52E)=1; H(s16,0x51A)=120; H(s16,0x52A)=90; H(float,0x4A8)=1.9f; break;
        case 16:
            H(float,0x4C8)=18; H(float,0x4CC)=30; H(float,0x4D0)=11; H(float,0x50C)=1.55f;
            H(s16,0x4AC)=5; H(float,0x4B8)=0.8f; H(float,0x508)=1.5f; H(float,0x4A8)=1.5f; H(s16,0x518)=1;
            func_L00_002D6900(20); H(float,0x508)=0.4f; H(float,0x50C)=0.9f; H(float,0x4A8)=0.4f;
            if (H(float,0x184)<0.33333334f) {
                func_L00_00322A98(H(u8 *,0x2290),HP(0x18E0));
                func_L00_00322AC0((SlotList *)HP(0x18E0),40,2,0);
                func_L00_00322AC0((SlotList *)HP(0x18E0),20,4,0);
                func_L00_00322AC0((SlotList *)HP(0x18E0),10,6,0);
            }
            H(u8,0x52E)=1; H(u32,0x454)=0x3E444445;
            if (H(float,0x31C)>1.4f) H(u32,0x454)=0x3DC28F5C;
            H(float,0x520)=0.002361111f; H(u32,0x504)=0x3C638E39; H(u32,0x500)=0x3C483FB8; break;
        case 27:
            H(u8,0x52E)=1; H(s16,0x4AC)=10; H(float,0x4B8)=0.85f; H(float,0x4C8)=20; H(float,0x4CC)=29; H(float,0x4D0)=19;
            H(float,0x50C)=2.05f; H(float,0x508)=2; H(float,0x514)=1; H(float,0x520)=0.0069444445f;
            H(float,0x4A8)=2; H(s16,0x518)=1; H(s32,0x4BC)=0; H(u8,0x49F)=1; H(u8,0x22BF)=1; H(u8,0x22BC)=1; break;
        case 72:
            H(s16,0x4AC)=13; H(float,0x520)=0.007777778f; H(float,0x4B8)=0.85f; H(float,0x4C8)=8; H(float,0x4D0)=14;
            H(float,0x50C)=1.59f; H(float,0x508)=1.55f; H(s16,0x518)=1; H(float,0x4A8)=1.55f;
            H(float,0x4CC)=14; H(s32,0x4BC)=0; break;
        case 17:
            H(s16,0x4AC)=9; H(float,0x4B8)=0.6f; H(float,0x4C8)=12; H(float,0x4CC)=20; H(float,0x4D0)=10; H(s16,0x518)=12;
            if (!H(u8,0x24DA)) { H(float,0x50C)=1.85f; H(float,0x4A8)=1.8f; H(u32,0x498)=0x3CE81B50; }
            else { H(float,0x50C)=3.35f; H(float,0x4A8)=3.3f; H(u32,0x498)=0x3DA740DB; }
            H(u8,0x49F)=1; H(float,0x508)=H(float,0x4A8); func_L00_002D6900(27);
            H(s16,0x52A)=80; H(float,0x520)=0.008055556f; H(u128,0x4F0)=H(u128,0x4E0);
            H(u8,0x52C)=1; H(s16,0x24D8)=1; H(u8,0x22B7)=1; break;
        case 13:
            H(float,0x4C8)=26; H(float,0x4CC)=38; H(float,0x4D0)=18; H(float,0x50C)=4.07f;
            H(s16,0x4AC)=9; H(float,0x4B8)=0.6f; H(float,0x508)=4; H(s16,0x518)=14; H(float,0x4A8)=4;
            func_L00_002D6900(20); H(float,0x510)=4.5f; H(s16,0x51A)=120; H(u32,0x4A4)=0x3D01B4E8; H(s16,0x526)=37;
            if (H(float,0x184)<0.33333334f) {
                func_L00_00322A98(H(u8 *,0x2290),HP(0x18E0));
                func_L00_00322AC0((SlotList *)HP(0x18E0),40,3,0); func_L00_00322AC0((SlotList *)HP(0x18E0),20,5,0);
            }
            H(u8,0x52E)=1; break;
        case 15:
            H(s16,0x4AC)=9; H(float,0x4B8)=0.6f; H(float,0x4C8)=50; H(float,0x4CC)=64; H(float,0x4D0)=28;
            H(float,0x50C)=1.7f; H(float,0x508)=1.65f; H(s16,0x518)=5; H(float,0x510)=4.5f; H(s16,0x51A)=130;
            H(u32,0x4A4)=0x3D6147AF; H(s16,0x526)=85; H(s16,0x1D0)=70; H(u8,0x49D)=1; H(float,0x4A8)=1.65f;
            H(s32,0x430)=D_001A7B90 ? 34 : 35; H(s32,0x434)=H(s32,0x430)+36;
            H(void *,0x444)=D_L03_001A7E00; H(float,0x438)=29; H(float,0x43C)=50; H(s32,0x440)=86; H(u8,0x52E)=1; break;
        case 14:
            H(float,0x4A8)=0.7f;
            if (H(float,0x31C)<2) H(float,0x4A8)=(2.5f-H(float,0x31C))*0.5f+0.7f;
            H(float,0x50C)=H(float,0x4A8)+0.05f; H(s16,0x526)=30; H(s16,0x4AC)=-1;
            H(float,0x4B8)=0.6f; H(float,0x4C8)=32; H(float,0x4CC)=43; H(float,0x4D0)=19;
            H(s16,0x518)=14; H(float,0x514)=1; H(u32,0x4A4)=0x3DA22223; H(float,0x508)=H(float,0x4A8); break;
        case 11:
            H(s16,0x52A)=50; H(s16,0x4AC)=5; H(float,0x4B8)=0.6f; H(float,0x4C8)=18; H(float,0x4CC)=31; H(float,0x4D0)=10;
            H(float,0x50C)=3.25f; H(float,0x508)=3.2f; H(s16,0x518)=14; H(float,0x510)=4.5f; H(float,0x514)=1;
            H(u8,0x49F)=1; H(float,0x4A8)=3.2f; H(float,0x4C4)=func_L00_002AE070(10);
            H(u128,0x480)=H(u128,0); H(s32,0x4D4)=func_L00_002C3A78(); H(float,0x4C0)=H(float,0x1A0);
            H(u128,0x470)=H(u128,0x190); H(float,0x4D8)=H(float,0x174)>0.025000002f ? H(float,0x174) : 0;
            H(s32,0x4DC)=0; H(u8,0x52C)=1;
            if (!H(s16,0x1454) || H(float,0x24B8)<=0.3f) H(u8,0x52D)=0;
            else { H(float,0x4C0)=H(float,0x1458); H(u128,0x470)=H(u128,0x1440); H(u8,0x52D)=1; H(u32,0x4DC)=0x3DAAAAAB; }
            H(u8,0x52E)=1; break;
        default: break;
        }
        if (H(float,0x510)==0) H(float,0x510)=H(float,0x4A8)*1.5f;
        if (!reset) goto finish;
        speed=5; blend=0;
        switch (H(s32,0x2294)) {
        case 7: case 110: case 129: animation=7; break;
        case 56: speed=4; animation=67; break;
        case 40: animation=77; break;
        case 41:
            animation=30; angle=func_00283248(H(float,0x5D0)-H(float,0x610),H(float,0x5D4)-H(float,0x614));
            if (func_00283C80(H(float,0x98),angle)>1.5707965f) animation=31;
            break;
        case 9:
            animation=8; index=func_00283CF0(H(float,0xC38));
            if (func_L00_002A4EF0(entryObject[0x42])==4) animation=D_L03_001A7DE0[index];
            break;
        case 69: animation=7; blend=2; break;
        case 10: animation=18; break;
        case 16:
            animation=38;
            if (H(s32,0x22A4)==4 || (H(s32,0x22A0)==4 && H(s32,0x1B8)<7)) {
                func_L00_002D2168(38,0,8); H(s16,0x4AC)+=3; goto finish;
            }
            break;
        case 27: speed=4; animation=34; break;
        case 137: func_L00_002D2168(125,11,9); goto finish;
        case 72: speed=4; animation=9; break;
        case 17: speed=7; animation=35; blend=2; break;
        case 13: animation=17; break;
        case 14: func_L00_002D2168(22,3,7); H(float,0xC20)=0.8f; goto finish;
        case 15: animation=21; break;
        case 11:
            animation=H(s32,0x4D4)+28;
            if (D_001A7A45) { if (animation==28) animation=29; else if (animation==29) animation=28; }
            if (H(s32,0x22A4)==4) { func_L00_002D2168(animation,1,4); H(s16,0x4AC)=1; goto finish; }
            break;
        default: goto finish;
        }
        goto play;
    case 19: case 20: case 21: case 31: case 34: case 77: case 131: case 147:
        H(s32,0x229C)=6;
        if (H(s32,0x1500) && (u32)(H(s32,0x2294)-19)<3) {
            if (H(u16,0x293C)!=0xFFFF) ++H(u16,0x293C);
            if (H(u32,0x2940)<D_001A7390) H(u32,0x2940)=D_001A7390;
            H(u32,0x2944)|=(1U<<(D_001A79F0&31))|0x80000000U;
            if (H(u16,0x27E0)!=0xFFFF) ++H(u16,0x27E0);
            if (H(u32,0x27E4)<D_001A7390) H(u32,0x27E4)=D_001A7390;
            H(u32,0x27E8)|=(1U<<(D_001A79F0&31))|0x80000000U;
            func_L00_002BA508(); H(s32,0x2294)=H(s32,0x22A0); H(s32,0x229C)=H(s32,0x22A4); goto finish;
        }
        if (requested!=131) H(s32,0x24A0)=0;
        H(float,0xBF4)=1; H(s32,0xBE8)=0; H(s32,0xBE4)=0; H(s16,0xBFE)=0;
        switch (H(s32,0x2294)) {
        case 31:
            object=H(u8 *,0x1220);
            if (object) {
                func_L00_002D6900(19);
                if (reset) { func_L00_002D2168(96,4,-1); func_002A7470(object,3,4,-1); }
                func_L00_002B75A0(11.0f,0.87266469f,-1.0f);
            }
            goto finish;
        case 34:
            if (reset) func_L00_002D2168(44,7,9);
            object=H(u8 *,0xBE0);
            if (H(s32,0x1248)==12 && object) {
                H(s32,0xBE8)=1;
                H(float,0xBEC)=func_00283248(*(float *)(object+0x10)-H(float,0x80),*(float *)(object+0x14)-H(float,0x84));
                func_00282CF0(HP(0xBC0),object+0x10,HP(0x80));
            }
            goto finish;
        case 131:
            H(s16,0xBFC)=3; func_L00_0041E958(64.0f,0.17453295f,0.3490659f);
            if (reset) {
                n=H(u8 *,0x2290)[0x43]==26 ? 3 : 10;
                if (H(s32,0x22A0)==1) n=17;
                func_L00_002D2168(26,0,(float)n);
            }
            goto finish;
        case 77:
            index=H(s16,0xBFC); n=0;
            if ((H(s32,0x22A4)==6 || (H(s32,0x22B0)==6 && (u32)(H(u8 *,0x2290)[0x43]-15)<2)) &&
                !D_L03_00262290[index].kind && H(float,0xC38)<(float)D_L03_00262290[index].limit)
                n=(D_L03_00262290[index].next+1)%2;
            H(s16,0xBFC)=n+7; func_L00_002B75A0(5.0f,0.78539824f,0.78539824f);
            if (!reset) goto finish;
            speed=5; animation=n+15; blend=1; goto play;
        case 20:
            if (H(u16,0x2930)!=0xFFFF) ++H(u16,0x2930);
            if (H(u32,0x2934)<D_001A7390) H(u32,0x2934)=D_001A7390;
            H(u32,0x2938)|=(1U<<(D_001A79F0&31))|0x80000000U;
            H(s32,0x24A0)=0x50; H(s16,0xBFC)=4; H(s32,0x2300)=0;
            func_L00_002B75A0(8.0f,1.0471977f,-1.0f); H(s32,0xC00)=0;
            if (reset) {
                n=H(s32,0x22A0)==11 && H(s32,0x22A8)<42 ? 17 : 11;
                func_L00_002D2168(43,4,(float)n); object=(u8 *)func_L00_002ADE68(0);
                if (func_L00_002B3248(object)) func_002A7470(object,10,4,n+2);
            }
            goto finish;
        case 21:
            if (H(u16,0x293C)!=0xFFFF) ++H(u16,0x293C);
            if (H(u32,0x2940)<D_001A7390) H(u32,0x2940)=D_001A7390;
            H(u32,0x2944)|=(1U<<(D_001A79F0&31))|0x80000000U;
            if (H(u16,0x27E0)!=0xFFFF) ++H(u16,0x27E0);
            if (H(u32,0x27E4)<D_001A7390) H(u32,0x27E4)=D_001A7390;
            H(u32,0x27E8)|=(1U<<(D_001A79F0&31))|0x80000000U;
            H(s16,0xBFC)=3; H(s32,0x2300)=0; func_L00_002B75A0(14.0f,0.52359885f,-1.0f);
            H(s32,0xC0C)=H(s32,0xC0C)==0;
            if (reset) {
                n=H(u8 *,0x2290)[0x43]==26 ? 3 : 10;
                if (H(s32,0x22A0)==1) n=17;
                func_L00_002D2168(26,0,(float)n); func_L00_002D2470(6,21);
            }
            goto finish;
        case 19:
            if (H(u16,0x25B8)!=0xFFFF) ++H(u16,0x25B8);
            if (H(u32,0x25BC)<D_001A7390) H(u32,0x25BC)=D_001A7390;
            H(u32,0x25C0)|=(1U<<(D_001A79F0&31))|0x80000000U;
            H(s32,0x2300)=0; index=H(s16,0xBFC); n=0;
            if (H(s32,0x22A0)==19 && H(float,0xC38)<(float)D_L03_00262290[index].limit) n=(D_L03_00262290[index].next+1)%3;
            else if (H(s32,0x22AC)==19 && H(s32,0x1B8)+H(s32,0x22A8)<27) n=(D_L03_00262290[index].next+1)%3;
            H(s16,0xBFC)=n; func_L00_002B75A0(5.0f,0.78539824f,0.78539824f);
            if (reset) {
                blend=n==0 ? 0 : n==1 ? 1 : 2; index=n==0 ? 5 : 7;
                if (H(s32,0xBE8) && n<2) {
                    angle=H(u8,0x22C3) ? func_L00_002B9B38(HP(0xBC0),0) : func_00283C80(H(float,0xBEC),H(float,0x98));
                    index+=func_00283CF0(angle*1.5f);
                }
                func_L00_002D2168(n+23,blend,(float)index);
                object=(u8 *)func_L00_002ADE68(0);
                if (func_L00_002B3248(object)) func_002A7470(object,n+3,blend,index);
            }
            goto finish;
        default: goto finish;
        }
    case 42:
        H(s32,0x229C)=15; H(s16,0xBFE)=0;
        H(s16,0xBFC)=H(s32,0x22A0)==42 ? H(s16,0xBFC)==0 : 0;
        if (reset) {
            func_L00_002D2168(H(s16,0xBFC)+75,0,4);
            object=(u8 *)func_L00_002ADE68(0);
            if (func_L00_002B3248(object)) func_002A7470(object,H(s16,0xBFC)+12,0,4);
        }
        goto finish;
    case 119:
        H(s32,0x229C)=10; H(s32,0x24A0)=0; H(float,0xBF0)=func_00283B98(H(float,0x98),3.141593f);
        func_00282D30(HP(0xBD0),HP(0),-1); H(float,0x1B4)=0.15f;
        if (!reset) goto finish;
        animation=41; blend=5; speed=8; goto play;
    case 22:
        H(s32,0x229C)=7; H(s32,0x24A0)=0; func_L00_002B6118(0.5f); func_L00_002D6900(18);
        H(s16,0x20E)=45; H(u128,0xF0)=H(u128,0x120); func_002AC9F8(HP(0xF0),0.116666675f);
        object=func_002A9640(H(u8 *,0x2290),1,0);
        func_L00_002A4EF8(object ? func_00283CF0(*(float *)(object+0x2C)) : 1);
        H(s16,0x1DC)=77;
        if (!reset) goto finish;
        animation=16; blend=3; goto tablePlay;
    case 140:
        H(s32,0x229C)=7; H(s32,0x24A0)=0; func_L00_002B6118(0.5f); H(s32,0x24A0)=0; func_L00_002D6900(18);
        object=func_002A9640(H(u8 *,0x2290),8,0);
        func_L00_002A4EF8(object ? func_00283CF0(*(float *)(object+0x2C)) : 1); H(s16,0x1DC)=77;
        if (!reset) goto finish;
        animation=150; blend=1; goto tablePlay;
    case 121:
        H(s32,0x229C)=20; H(float,0x334)=H(float,0x318); H(s16,0x1F0)=10000; H(s32,0x24A0)=0; H(s32,0x24CC)=0;
        func_L00_002B9B88(7,0);
        if (!reset) goto finish;
        speed=8; animation=106; goto play;
    case 122:
        H(s32,0x229C)=20; H(float,0x334)=H(float,0x318); H(s16,0x1F0)=10000; H(s32,0x24A0)=0; H(s32,0x24CC)=0;
        object=H(u8 *,0xC18); *(u128 *)(object+0x10)=H(u128,0x80); func_002E5CF8(7,0,(char *)object);
        if (!reset) goto finish;
        speed=8; animation=17; goto play;
    case 63:
        H(s32,0x229C)=0; H(s32,0x24A0)=0;
        if (H(u8,0x149A) && !H(s16,0x34C)) { redirect=78; goto redirectState; }
        if (!reset) goto finish;
        speed=9; animation=0; goto play;
    case 75:
        H(s32,0x229C)=5; H(s32,0x24A0)=0;
        if (H(float,0x170)>0.075f) func_L00_002B6118(0.075f/H(float,0x170));
        H(u128,0xF0)=H(u128,0x110);
        if (!reset) goto finish;
        speed=12; animation=14; goto play;
    case 65:
        H(s32,0x229C)=2; H(u32,0xA84)=0x3AFEDCBB; H(s32,0x24A0)=0; H(u128,0xF0)=H(u128,0x120);
        if (!reset) goto finish;
        speed=8; animation=4; goto play;
    case 68:
        H(s32,0x229C)=2; H(s32,0x24A0)=0;
        if (!reset) goto finish;
        speed=8; animation=4; goto play;
    case 78:
        H(s32,0x229C)=2; H(s32,0x24A0)=0; H(u128,0xF0)=H(u128,0x120);
        if (!reset) goto finish;
        speed=12; animation=4; goto play;
    case 66:
        H(s32,0x229C)=7; H(s32,0x24A0)=0; func_L00_002B6118(0.5f); H(u128,0xF0)=H(u128,0x120);
        func_002AC9F8(HP(0xF0),0.083333336f); func_L00_002A4EF8(1); H(s16,0x20E)=45; H(s16,0x1DC)=50;
        if (!reset) goto finish;
        animation=6; blend=3; goto tablePlay;
    case 64:
        if (H(u8,0x149A) && !H(s16,0x34C)) { redirect=78; goto redirectState; }
        H(s32,0x229C)=1; H(s32,0x24A0)=0; H(float,0x1B4)=func_00282E20(HP(0x120));
        if (H(s32,0x22A0)==3) H(float,0x1B4)=0;
        if (!H(s32,0x22A4)) H(float,0x1B4)=func_00282E20(HP(0x160));
        H(u8,0x40F)=0; H(u8,0x40C)=0;
        if (!reset) goto finish;
        speed=8; animation=2; goto play;
    case 67:
        H(s32,0x229C)=20; H(s32,0x24A0)=0; H(s32,0x24CC)=0; H(u128,0x160)=H(u128,0x120);
        if (!reset) goto finish;
        speed=12; animation=5; goto play;
    case 70:
        H(s32,0x229C)=3; H(s32,0x24A0)=13;
        H(float,0x57C)=0.0033333334f; H(float,0x580)=H(float,0x88);
        if (H(s32,0x22A4)==4) { H(float,0x57C)=H(float,0x520); H(float,0x580)=H(float,0x490); }
        if (reset) func_L00_002D2168(8,14,7);
        goto finish;
    case 71:
        H(s32,0x229C)=3; H(s32,0x24A0)=13;
        if (!reset) goto finish;
        speed=6; animation=10; goto play;
    case 73:
        H(s32,0x229C)=3; H(s32,0x24A0)=13;
        if (!reset) goto finish;
        speed=6; animation=11; goto play;
    case 74:
        H(s32,0x229C)=3; H(s32,0x24A0)=13;
        if (!reset) goto finish;
        speed=6; animation=12; goto play;
    case 62:
        H(s32,0x229C)=15; H(s32,0x24A0)=0;
        if (!H(s32,0x640)) {
            object=H(u8 *,0x6C4);
            func_L00_002A4EF8(object ? func_00283CF0(*(float *)(object+0x2C)) : 1);
            if (object) H(u8 *,0x6C4)=0;
        }
        func_L00_002B9B88(20,0);
        if (H(s32,0x24CC)<1) {
            angle=func_00283248(H(float,0xF0),H(float,0xF4)); angle=func_00283B98(angle,3.141593f);
            angle=func_00283B98(angle,func_002A78D8(0.52359885f,0.6108653f));
            H(float,0x120)=func_00283180(angle)*H(float,0x644)*0.7f;
            H(float,0x124)=func_00283198(angle)*H(float,0x644)*0.7f; H(float,0x128)=0.075f;
            if (H(s32,0x640)>15 && H(s32,0x24CC)<2) H(s32,0x24CC)=2;
            H(u8 *,0x2290)[0xA8]=255; func_L03_002C6F08(22,1); H(s16,0x1D0)=70; H(s16,0x1F4)=150; return 0;
        }
        H(s16,0x1DC)=77; H(float,0x69C)=0.041666668f;
        if (H(float,0x680)>0.041666668f) H(float,0x680)=0.041666668f;
        H(s32,0x674)=0; func_00282C88(HP(0xF0)); func_00282C88(HP(0x110)); H(float,0xF8)=0.18333334f;
        if (!reset) goto finish;
        speed=-3; animation=16; blend=2; goto play;
    case 28:
        H(s32,0x229C)=9; H(s32,0x24A0)=0;
        H(u8,0x22BC)=1;
        speed=10; animation=func_L03_002AB5C8(0); goto play;
    case 29:
        H(s32,0x24A0)=0x51; H(s32,0x229C)=0;
        code=func_L00_002A4EF0(H(u8 *,0x2290)[0x42]);
        if (code==func_L03_002AB5C8(0)) goto finish;
        animation=func_L03_002AB5C8(0); speed=5; goto play;
    case 30:
        H(s32,0x229C)=9; H(s32,0x24A0)=0;
        speed=10; animation=func_L03_002AB5C8(0); goto play;
    case 111:
        H(s32,0x229C)=9; H(u8,0x22BC)=1; H(s32,0x24A0)=0; func_L00_002AF7D0();
        if (!reset) goto finish;
        animation=func_L03_002AB5C8(0); speed=10; goto play;
    case 38:
        H(s32,0x229C)=8; H(s32,0x24A0)=0; animation=func_L03_002AB5C8(0); speed=10; goto play;
    case 49:
        H(s32,0x229C)=9; H(u8,0x22BC)=1; H(s32,0x24A0)=0; H(u8,0x22B7)=1; H(u8,0x22BD)=1;
        func_L00_00322EC8((SmallSlotResetOwner *)HP(0x1A30));
        if (!reset) goto finish;
        animation=func_L03_002AB5C8(0); speed=-1; goto play;
    case 117:
        H(u8,0x22BC)=1; H(s32,0x229C)=9; H(s32,0x24A0)=0; H(u8,0x22B7)=1; func_00282C88(HP(0xF0));
        if (!reset) goto finish;
        animation=11; speed=-1; goto play;
    case 96: case 97:
        H(s32,0x229C)=24; H(u8,0x22BC)=1;
        func_L00_00322EC8((SmallSlotResetOwner *)HP(0x1A30)); func_L00_002AF7D0();
        if (reset) func_L00_002D2168(func_L03_002AB5C8(0),0,-1);
        goto finish;
    default: goto finish;
    }
shortClimb:
    if (reset) { func_L00_002D2168(47,2,5); func_L00_002D2470(10,14); }
    goto finish;
tablePlay:
    func_L00_002D2168(animation,blend,-3);
    index=H(s32,0xC34); H(s32,0xC34)=index+1;
    *(float *)(H(u8 *,0x2290)+0x44)=D_L03_00262420[H(s32,0xC30)][index];
    goto finish;
redirectState:
    func_L03_002C6F08(redirect,1); return 0;
play:
    func_L00_002D2168(animation,blend,speed);
finish:
    if (wasAirborne && !H(u8,0x22B7)) H(s32,0x231C)=1;
    if (!H(s16,0x348) && H(s32,0x1298)==19 && H(s32,0x2304)) H(s32,0x2320)=1;
    if ((u32)(H(s32,0x229C)-13)>2 && (H(s32,0x2294)!=6 || H(s32,0x22A0)!=36) && H(s32,0x1298)==20 && H(s32,0x2304)) H(s32,0x2320)=1;
    if (H(s32,0x229C)==20) { func_L00_002AF7D0(); H(u8,0x22BC)=1; }
    if ((!func_L00_002ADF80() || H(s32,0x229C)==18) && (H(float,0x330)<D_L03_001B9988 || !H(s32,0x229C))) D_L03_001B9C40=0;
    if (H(s32,0x229C)!=H(s32,0x22A4)) func_L00_002A6708();
    if (H(s32,0x229C)!=H(s32,0x22A4)) H(s32,0x1BC)=0;
    H(s32,0x1C4)=0; H(s32,0x1C0)=0; H(s32,0x1B8)=0;
    return 1;
}
