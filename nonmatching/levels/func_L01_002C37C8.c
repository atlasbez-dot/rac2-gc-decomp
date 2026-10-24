/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -Wa,-G8 -g -frac2-qcopy -frac2-qcopy-barrier
 * -frac2-zero-ti-por.
 * Prior worker coverage: US 0/1; US2 absent from catalogue; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* NONMATCHING: manual reconstruction of the complete state dispatcher.
 * Retail US: 15068 bytes, one placement. Final candidate: 14900 bytes,
 * 0/1 placements, tools/check.py exit 1. US2/PAL have no catalogue entry.
 * Checked source: src/levels/01_oozla/L01_002C37C8-g8.c.
 * Profile: -O2 -G8 -ffunction-sections -Wa,-G8 -g -frac2-qcopy
 *          -frac2-qcopy-barrier -frac2-zero-ti-por.
 * Six bounded trials: a TI-local/float-pointer form hit convert_move ICE;
 * honest 16-byte stack unions compiled at 15036 bytes; typed resident/input
 * views 14880; integer animation snapshot 14880; deferred choices 14896;
 * four explicit particle-vector components 14900. No padding or ASM used.
 * All 62 nondefault state values from the verified reference are represented;
 * the retail table has 141 entries. The 160-byte frame is recovered, but
 * snapshots still spill differently and address/branch/register choices differ.
 * This is a retained source hypothesis, not a semantic or linked-match claim.
 * Unordered FP branches and the complete field/record layouts need further
 * retail review. Unbounded arrays remain incomplete; no size is fabricated
 * to force small data. Several procedure return intents remain unresolved;
 * this caller only uses their side effects, as documented in the ABI review.
 * The update callback is invoked as void(char*) by the existing dispatcher;
 * the draw callback's explicit word return is preserved. Registration stores
 * code addresses as 32-bit words. No callback is invoked through a guessed
 * signature in this function. No existing helper definition is modified.
 * Reopen with justified control-flow/source lifetime forms and full layout
 * qualification. The active source retains its INCLUDE_ASM marker.
 */
typedef int Quadword __attribute__((mode(TI)));
typedef union StackVector { Quadword bits; float value[4]; } StackVector;
typedef int V4_F6a70b950 __attribute__((mode(TI)));
typedef unsigned char u8;
typedef int s32;
typedef float f32;

/* Measured resident prefix. The complete allocation extends beyond this view. */
typedef struct ResidentView {
    unsigned char gap0[0x80];
    StackVector v80;
    StackVector v90;
    unsigned char gapA0[0x50];
    StackVector vF0;
    unsigned char gap100[0x10];
    StackVector v110;
    unsigned char gap120[0x30];
    StackVector v150;
    StackVector v160;
    float f170;
    float f174;
    float f178;
    unsigned char gap17C[0x24];
    float f1A0;
    unsigned char gap1A4[0x4];
    float f1A8;
    unsigned char gap1AC[0x4];
    float f1B0;
    float f1B4;
    int f1B8;
    unsigned char gap1BC[0x4];
    unsigned int f1C0;
    unsigned int f1C4;
    unsigned char gap1C8[0x8];
    short f1D0;
    short f1D2;
    int f1D4;
    unsigned char gap1D8[0x8];
    short f1E0;
    unsigned char gap1E2[0x2];
    short f1E4;
    unsigned char gap1E6[0x6];
    short f1EC;
    short f1EE;
    unsigned char gap1F0[0x2];
    short f1F2;
    unsigned char gap1F4[0xC];
    short f200;
    short f202;
    unsigned char gap204[0x4];
    short f208;
    unsigned char gap20A[0x14];
    short f21E;
    unsigned char gap220[0x58];
    float f278;
    unsigned char gap27C[0xB];
    unsigned char f287;
    unsigned char gap288[0x90];
    float f318;
    float f31C;
    float f320;
    unsigned char gap324[0x10];
    float f334;
    int f338;
    union { int integer; char *pointer; } f33C;
    int f340;
    unsigned char gap344[0x4];
    short f348;
    short f34A;
    short f34C;
    short f34E;
    unsigned char gap350[0xBE];
    unsigned char f40E;
    unsigned char gap40F[0x1];
    int f410;
    unsigned char gap414[0x1C];
    int f430;
    int f434;
    float f438;
    unsigned char gap43C[0x4];
    int f440;
    unsigned char gap444[0x58];
    unsigned char f49C;
    unsigned char f49D;
    unsigned char f49E;
    unsigned char f49F;
    unsigned char gap4A0[0xC];
    short f4AC;
    short f4AE;
    unsigned char gap4B0[0x18];
    float f4C8;
    float f4CC;
    float f4D0;
    unsigned char gap4D4[0x3C];
    float f510;
    float f514;
    unsigned char gap518[0x2];
    short f51A;
    unsigned char gap51C[0x4];
    float f520;
    unsigned char gap524[0x2];
    short f526;
    unsigned char gap528[0x2];
    short f52A;
    unsigned char gap52C[0x2];
    unsigned char f52E;
    unsigned char f52F;
    unsigned char gap530[0x48];
    unsigned int f578;
    unsigned char gap57C[0x34];
    float f5B0;
    unsigned char gap5B4[0x648];
    short fBFC;
    unsigned char gapBFE[0x2];
    float fC00;
    unsigned char gapC04[0x1C];
    float fC20;
    unsigned char gapC24[0x4];
    unsigned int fC28;
    int fC2C;
    unsigned char gapC30[0x8];
    float fC38;
    unsigned char gapC3C[0x8];
    int fC44;
    unsigned char gapC48[0x250];
    int fE98;
    unsigned char gapE9C[0x8];
    unsigned int fEA4;
    unsigned char gapEA8[0x378];
    char * f1220;
    unsigned char gap1224[0xC];
    unsigned int f1230;
    unsigned char gap1234[0x6];
    unsigned char f123A;
    unsigned char gap123B[0x1];
    unsigned char f123C;
    unsigned char gap123D[0xB];
    int f1248;
    unsigned char gap124C[0xC4];
    char * f1310;
    char * f1314;
    unsigned char gap1318[0x1C];
    int f1334;
    unsigned char gap1338[0x11C];
    short f1454;
    unsigned char f1456;
    unsigned char gap1457[0x3B];
    unsigned char f1492;
    unsigned char f1493;
    unsigned char gap1494[0x6];
    unsigned char f149A;
    unsigned char f149B;
    unsigned char gap149C[0x1];
    unsigned char f149D;
    unsigned char gap149E[0x62];
    int f1500;
    unsigned char gap1504[0x350];
    int f1854;
    unsigned char gap1858[0x48];
    StackVector v18A0;
    int f18B0;
    unsigned char gap18B4[0xC];
    int f18C0;
    unsigned char gap18C4[0x9CC];
    char * f2290;
    unsigned int f2294;
    int f2298;
    unsigned int f229C;
    int f22A0;
    int f22A4;
    unsigned char gap22A8[0x8];
    int f22B0;
    unsigned char f22B4;
    unsigned char f22B5;
    unsigned char gap22B6[0x1];
    unsigned char f22B7;
    unsigned char f22B8;
    unsigned char f22B9;
    unsigned char f22BA;
    unsigned char gap22BB[0x1];
    unsigned char f22BC;
    unsigned char gap22BD[0x2];
    unsigned char f22BF;
    unsigned char f22C0;
    unsigned char gap22C1[0x43];
    int f2304;
    unsigned char gap2308[0x18];
    unsigned int f2320;
    unsigned char gap2324[0x110];
    int f2434;
    unsigned char gap2438[0x54];
    int f248C;
    unsigned char gap2490[0x10];
    unsigned int f24A0;
    unsigned char gap24A4[0xC];
    unsigned int f24B0;
    int f24B4;
    float f24B8;
    unsigned char gap24BC[0x10];
    int f24CC;
    unsigned char gap24D0[0xB];
    unsigned char f24DB;
    unsigned char gap24DC[0xC];
    unsigned int f24E8;
    short f24EC;
    unsigned char gap24EE[0x1];
    unsigned char f24EF;
    unsigned char gap24F0[0x6];
    short f24F6;
    unsigned char gap24F8[0x2];
    short f24FA;
    short f24FC;
} ResidentView;
extern ResidentView D_00189E20;
typedef struct InputView {
    unsigned char prefix[0x1A0];
    unsigned int buffered;
    unsigned int pressed;
    unsigned char gap1A8[0x18];
    unsigned int secondaryBuffered;
    unsigned int secondaryPressed;
} InputView;
extern InputView D_00138180;
extern unsigned char D_00139568[];
extern unsigned char D_00188660[];
extern int D_001A79F0;
extern unsigned char D_001A7AFA;
extern unsigned char D_001A7BB3;
extern char D_L01_001A7CA0[];
extern char D_L01_001A7CB0[];
extern float D_L01_001A7DB4;
extern float D_L01_001A7DC0;
extern int D_L01_001A7DD8[];
extern int D_L01_001A8A48;
extern int D_L01_001A8FF4;
extern int D_L01_001A9034;
extern int D_L01_001B2084;
extern float D_L01_001B21A8;
extern float D_L01_001B94C0[];
extern float D_L01_001B94D8;
extern char D_L01_0025CF40[][112];
extern float D_L01_0025D364;
extern float D_L01_0025D368;
extern char D_L01_0025EC90[][44];
extern char D_L01_002637A0[][224];

extern int func_00282948(int *);
extern int func_00282978(short *);
extern void func_00282D30(void *, void *, float);
extern float func_00282DF0(void *);
extern float func_00282E48(void *, void *);
extern float func_00282E80(void *, void *);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_00283B98(float, float);
extern float func_00283C80(float, float);
extern int func_00283CF0(float);
/* The registration stores seven 32-bit words. Callback code addresses use
 * their verified input positions, and the draw callback preserves its result. */
extern int func_0028B3D0(int, int, int, int, int, int, int);
extern void func_0028BDB0(u8 *);
extern void func_0028BE00(char *);
extern int func_0028C6D0(char *);
extern void func_002A7470(char *, int, int, int);
extern void func_L00_002A61C8(int, int, int, int);
extern void func_L00_002A6708(void);
extern void func_L00_002A9E30(float, float, float, float);
extern void func_L00_002AABE0(int, int, int);
extern void func_L00_002B30E8(void);
extern void func_L00_002B39F0(int, float);
extern int func_L00_002C3A40(void);
extern void func_L00_002CA0B0(void);
extern int func_L00_002CA4E0(int *);
extern int func_L00_002CAB08(void);
extern int func_L00_002CAF20(void);
extern void func_L00_002CB038(void);
extern void func_L00_002CB218(void);
extern void func_L00_002CB2D8(void);
extern void func_L00_002D2168(int, int, float);
extern float func_L00_002D3D98(float *, float *, int *, float);
extern unsigned int func_L00_0032EF10(unsigned int, int, int *);
extern void *func_L00_0033C0D0(char *, void *, void *, void *, int);
extern int func_L01_002A7248(int);
extern int func_L01_002AE128(float *, float *, void *);
extern int func_L01_002B3788(int);
extern void func_L01_002B46A0(void);
extern int func_L01_002BEB90(long, int);
extern int func_L01_002C1A70(void);
extern void func_L01_002C2CF0(void);
extern float func_L01_002C81D0(float, float, float);
extern f32 func_00282C48(f32 a0);
extern void func_0029FCC0(char *a0, int a1, char *a2);
extern s32 func_002A7820(s32 a0, s32 a1);
extern f32 func_002AA2E8(f32 *value, f32 target, f32 step);
extern void func_002AC9F8(float *p, float threshold);
extern void func_002E59F8(s32 a0);
extern unsigned long func_L00_002A4EF0(unsigned long param_1);
extern void func_L00_002A6188(void);
extern int func_L00_002AB108(float *out, float scale, float amount);
extern s32 func_L00_002ADEA0(s32 index);
extern void func_L00_002AF7D0(void);
extern s32 func_L00_002B3248(u8 *object);
extern int func_L00_002B3268(float x);
extern int func_L00_002B9B88(int index, int flags);
extern int func_L00_002C8C00(void);
extern int func_L00_002C9FC8(int arg0, int arg1);
extern void func_L00_002CA478(void);
extern int func_L00_002CAD90(void);
extern void func_L00_002D1AE8(void);
extern void func_L00_002D24B8(void);
extern void func_L00_002D24D0(int value);
extern void func_L00_002D3248(short arg0, unsigned char arg1, unsigned char arg2, unsigned char arg3, float arg4, float arg5);
extern float func_L00_002D3B00(char *in);
extern void func_L00_002D3B58(V4_F6a70b950 *dst, V4_F6a70b950 *src, float k);
extern void func_L00_0030C710(int argument);
extern void func_L00_0030C7F8(int argument);
extern int func_L00_004272A0(void);
extern void func_L01_002C1988(unsigned long x);

#define STATE D_00189E20.f2294
#define TIMER D_00189E20.f1B8
#define MOTION D_00189E20.f229C
#define FRAME D_00189E20.fC38
#define BLEND D_00189E20.f24B8
#define HEIGHT D_00189E20.f31C
#define INPUT D_00138180.buffered
#define PRESSED D_00138180.pressed

void func_L01_002C37C8(void)
{
    char *object = D_00189E20.f2290;
    int previousMotion = MOTION;
    int previousPhase = D_00189E20.f2298;
    int previousAnimation = (unsigned char)object[0x43];
    StackVector position;
    StackVector joint;
    StackVector delta;
    int selected;
    int buffered;
    int count;
    int frame;
    int window;
    int blocked;
    int enabled;
    int animation;
    int blendFrames;
    int next;
    int mode;
    float speed;
    float acceleration;
    float decay;
    float angle;
    float length;
    float target;
    char *row;
    char *attachment;

    if (func_L01_002B3788(1)) goto done;
    func_L00_002CB038();
    if (D_00189E20.f24CC <= 0 && (STATE == 0 || STATE == 2)) {
        next = 0x39;
        goto change;
    }
    if (func_L01_002C1A70() || func_L00_002C8C00()) goto done;
    if (((PRESSED | D_00138180.secondaryPressed) & 0x10) && D_00189E20.f123C != 2 &&
        !D_L01_001A8FF4 && !D_001A7BB3 && D_L01_001B2084 > 7 &&
        (!D_00189E20.f22BC || D_00189E20.f22B4 == 1 || D_00189E20.f1D2) &&
        (!D_00189E20.f22B7 || D_00189E20.f22B4 == 1 || D_00189E20.f1D2) &&
        (D_00189E20.f22B4 == 0 || D_00189E20.f22B4 == 3)) {
        D_00189E20.f24F6 = D_00189E20.f24FA ? 0x1B : 0xF;
        func_0028B3D0(0x23, 0, (int)func_0028BDB0, (int)func_0028BE00,
                     (int)func_0028C6D0, 0, 0);
        func_L00_0030C7F8(0x168);
        func_L00_0030C710(0xB4);
    }
    func_L00_002CB218();
    func_L00_002CB2D8();
    if (D_00189E20.v80.value[2] < D_L01_001B21A8 && HEIGHT > 2.0f && D_00189E20.f22B4 != 2 && STATE != 0x74) {
        next = 0x74;
        goto change;
    }

    switch (STATE) {
    case 0:
        if ((INPUT & 4) && !D_00189E20.f1500 && !func_L00_004272A0()) {
            next = 1;
            break;
        }
        func_L00_002D24B8();
        if (D_00189E20.f24EF) { next = 0x82; break; }
        D_00189E20.f1456 = 0;
        if (D_00189E20.f1334 == 2) {
            attachment = D_00189E20.f1310;
            if (attachment && (attachment[0x60] & 2) && attachment[0x43] != 1)
                func_002A7470(attachment, 1, 0, 7);
            attachment = D_00189E20.f1314;
            if (attachment && (attachment[0x60] & 2) && attachment[0x43] != 1)
                func_002A7470(attachment, 1, 0, 7);
        }
        if (D_L01_0025D368 > 0.6108653f || D_L01_0025D364 > 0.43633235f) {
            attachment = D_00189E20.f1310;
            if (attachment && attachment[0x43] != 1) func_002A7470(attachment, 1, 0, 12);
            attachment = D_00189E20.f1314;
            if (attachment && attachment[0x43] != 1) func_002A7470(attachment, 1, 0, 12);
        }
        if (func_L00_002A4EF0((unsigned char)object[0x43]) == func_L01_002A7248(0)) {
            if (func_L00_002CA4E0(&selected)) {
                row = D_L01_0025CF40[selected];
                D_00189E20.f208 = 120;
                D_00189E20.f248C = selected;
                *(int *)(row + 0x20) = (int)(*(float *)(row + 0x1C) * 60.0f);
                if (*(int *)(row + 4)) func_L01_002BEB90(0x3C, 1);
                else func_L00_002D2168(*(int *)(row + 8), 0, 12.0f);
            }
        } else if (D_00189E20.fC28 & 2) {
            enabled = D_00189E20.f22B8 && D_00189E20.f22BA &&
                ((unsigned char)D_00189E20.f2290[0x43] == D_00189E20.f24B0 || D_00189E20.fE98);
            if (!enabled) {
                D_00189E20.f22B8 = 0;
                animation = func_L01_002A7248(0);
                func_L00_002D2168(animation, 0, animation == 0x51 ? 18.0f : -2.0f);
            }
        }
        if (TIMER > 10 && D_00189E20.f1314 && D_00189E20.f1314[0x43] == 1 &&
            func_00282948((int *)((char *)&D_00189E20 + 0x24E8)) &&
            D_L01_0025D368 < 0.5585054f && D_L01_0025D364 < 0.3490659f && D_00189E20.f1334 == 2) {
            D_00189E20.f24E8 = func_002A7820(0x6E, 0x10E);
            func_L00_002D1AE8();
        }
        if (D_00189E20.f22B8 && !D_00189E20.fC2C && D_00189E20.f22BA && !D_00189E20.f24EC) {
            animation = func_L00_002ADEA0(0);
            if (animation == D_00189E20.f24B4) {
                animation = *(unsigned int *)(D_L01_002637A0[D_00139568[animation]] + 0x28);
                if ((unsigned char)D_00189E20.f2290[0x43] != animation) {
                    if (D_00189E20.fE98) D_00189E20.fEA4 = 1;
                    D_00189E20.f24B0 = animation;
                    func_L00_002D2168(animation, 0, -4.0f);
                }
            } else func_L00_002AF7D0();
        }
        func_L00_002B39F0(0, 1.0f);
        if (D_00189E20.f149A && !D_00189E20.f34C) { next = 0x76; break; }
        if (D_00189E20.f34E >= 5 && HEIGHT > 0.4f) {
            if (D_00189E20.f22A0 == 8 && TIMER < 15) goto done;
            next = 6;
            break;
        }
        if (D_00189E20.f1E0) goto done;
        enabled = !((D_00189E20.f22A0 == 1 || D_00189E20.f22A0 == 0x1D) && TIMER < 5);
        if (enabled && D_00189E20.f348 != 1) {
            window = D_00189E20.f1EE ? 1 : 7;
            if (func_L00_002C9FC8(window, 0)) goto done;
        }
        if (D_00189E20.f348 == 1 && !D_L01_001A9034 && func_L00_0032EF10(0x40, 7, 0)) {
            next = 0x6E;
            break;
        }
        if ((INPUT & 8) && D_00189E20.f340 && (D_00189E20.f2290[0x43] != 0x1A || FRAME >= 108.0f)) {
            next = 4;
            break;
        }
        enabled = 1;
        if ((D_00189E20.f22A0 == 1 || D_00189E20.f22A0 == 0x1D) && TIMER < 24 && D_00189E20.f348 != 1) {
            func_L00_002B39F0(0, 1.0f);
            if (func_00283C80(D_00189E20.f1A0, D_L01_001B94D8) > 1.2217306f &&
                func_00282E48(D_00189E20.v80.value, D_L01_001B94C0) < 2.5f) enabled = 0;
        }
        blocked = func_L00_002B3268(0.17453295f);
        if (!enabled || (!blocked && BLEND <= 0.22f)) goto done;
        func_L00_002A61C8(D_00189E20.f149D, 0, 0, 30);
        func_L00_002A61C8(D_00189E20.f149D, 1, 0, 30);
        next = 2;
        break;

    case 1:
        if (!D_00189E20.f22B4 && (!D_00189E20.f22BA || D_00189E20.f22B5)) {
            animation = (INPUT & 8) ? 13 : func_L01_002A7248(1);
            if ((INPUT & 8) || (unsigned char)D_00189E20.f2290[0x43] != animation)
                func_L00_002D2168(animation, 0, 8.0f);
        }
        attachment = D_00189E20.f1220;
        enabled = !(attachment && func_L00_002B3248((unsigned char *)attachment) && attachment[0x20]);
        if (((INPUT & 4) || !enabled) && (D_00189E20.f22B5 || TIMER < 31)) goto done;
        if (D_00189E20.f22B4) goto cancelAction;
        if (INPUT & 8) { next = 4; break; }
        func_L01_002BEB90(0, 0);
        animation = func_L01_002A7248(1);
        if ((unsigned char)D_00189E20.f2290[0x43] != animation) func_L00_002D2168(animation, 0, 8.0f);
        goto done;
    case 2: case 0x2E: case 0x70:
        if (D_00189E20.f40E && (*(float *)(object + 0x44) > 0.9f || object[0x42] != -1)) D_00189E20.f40E = 0;
        if (D_00189E20.f149A && !D_00189E20.f34C) { next = 0x76; break; }
        if (D_00189E20.f34E >= 5 && !(D_00189E20.f22A4 == 0x12 && D_00189E20.f22B9) &&
            HEIGHT > 1.35f && !func_L00_002CAD90()) { next = 6; break; }
        window = D_00189E20.f1EE ? 1 : 9;
        if (!func_L00_0032EF10(0x40, window, 0) || (D_00189E20.f34E > 4 && !D_00189E20.f202)) {
            if (D_00189E20.f34E) goto done;
            if ((INPUT & 4) && !D_00189E20.f1500 && !func_L00_004272A0() &&
                (!D_00189E20.f1492 || (D_00189E20.f174 < 0.033333335f && D_00189E20.f320 < 0.087266475f))) {
                next = 1;
                break;
            }
            if (INPUT & 8) { next = 4; break; }
            blocked = func_L00_002B3268(0.03490659f);
            if (STATE != 2) goto done;
            if ((BLEND >= 0.17f && !D_00189E20.f1E0) || blocked ||
                (D_00189E20.f410 && func_00282C48(D_00189E20.f1A8) >= 0.017453294f)) {
                func_L00_002CA0B0();
                goto done;
            }
            if (func_L00_002CAF20()) goto done;
            if (!func_L01_002BEB90(0, 0)) goto done;
            func_002AC9F8(D_00189E20.v160.value, 0.025000002f);
            if (D_00189E20.f1B4 > 0.025000002f) D_00189E20.f1B4 = 0.025000002f;
            animation = func_L01_002A7248(1);
            func_L00_002D2168(animation, 0, animation == 0x51 ? 15.0f : -1.0f);
            goto done;
        }
        func_L00_002B39F0(0, 1.0f);
        if (func_L00_002C9FC8(window, 1)) goto done;
        next = BLEND > 0.85f && !D_00189E20.f1454 ? 9 : 7;
        break;

    case 3:
        if ((INPUT & 4) && !D_00189E20.f1500 && !func_L00_004272A0()) { next = 1; break; }
        if (!D_00189E20.f1E0) {
            if (PRESSED & 0x40) { next = 7; break; }
            if (INPUT & 8) { next = 4; break; }
        }
        if (D_00189E20.f34E >= 9 && HEIGHT > 0.3f) { next = 6; break; }
        if (!(D_00189E20.fC28 & 2)) {
            if (BLEND <= 0.2f || D_00189E20.f1E0) goto done;
            if (func_L01_002A7248(0) == 0x51) {
                if (FRAME > 10.0f && func_L01_002BEB90(0, 0))
                    func_L00_002D2168(func_L01_002A7248(0), 0, 17.0f);
            } else if (D_00189E20.f1B4 == 0.0f) {
                func_L01_002BEB90(0, 0);
                goto done;
            }
            if (BLEND > 0.5f) { next = 2; break; }
        }
        goto done;

    case 4:
        if ((INPUT & 4) && !D_00189E20.f1500 && !func_L00_004272A0()) { next = 1; break; }
        if (TIMER > 11 && !(INPUT & 8)) {
            func_L01_002BEB90(0, 0);
            func_L00_002D2168(func_L01_002A7248(0), 0, -2.0f);
            goto done;
        }
        if (D_00189E20.f149A && !D_00189E20.f34C) { next = 0x76; break; }
        if (func_L00_002CAB08()) goto done;
        if (func_L00_0032EF10(0x80, 15, 0) && !D_00189E20.f123A && D_00189E20.f1248 == 10)
            func_L01_002BEB90(21, 1);
        if (D_00189E20.f34E < 9 || (D_00189E20.f22A0 == 8 && TIMER < 15)) goto done;
        next = 6;
        break;

    case 6: case 0x2C:
        if (!D_00189E20.f2298 && (TIMER > 17 || HEIGHT > 1.75f)) {
            func_L00_002D2168(11, 0, 16.0f);
            D_00189E20.f2298 = 1;
            D_00189E20.f24A0 = STATE == 0x2C ? 7 : 0;
        }
        if (!D_00189E20.f34E) {
            func_L00_002A6188();
            if (D_00189E20.v110.value[2] < -0.15f) D_00189E20.v110.value[2] = -0.15f;
            if (D_00189E20.vF0.value[2] < -0.15f) D_00189E20.vF0.value[2] = -0.15f;
            if (D_00189E20.f24CC <= 0) { next = 0x39; break; }
            enabled = D_00189E20.f33C.integer == 0;
            if (TIMER < 90) {
                if (D_00189E20.f2298 == 1) {
                    if (func_L01_002BEB90(0, 0)) func_L00_002D2168(12, 9, -1.0f);
                    func_L00_002D3B58((V4_F6a70b950 *)D_00189E20.v160.value, (V4_F6a70b950 *)D_00189E20.v160.value, 0.0f);
                    func_002AC9F8(D_00189E20.v160.value, 0.116666675f);
                    D_00189E20.f1E0 = D_00189E20.f22A0 == 0x2C ? 10 : 7;
                    if (enabled && TIMER > 50) D_00189E20.f1E0 = 18;
                    acceleration = 0.019f;
                    decay = 0.002f;
                    window = 10;
                    count = 2;
                } else if (BLEND <= 0.5f || D_00189E20.f1E0) {
                    if (D_00189E20.f174 > 0.050000004f) {
                        if (func_L01_002BEB90(3, 0)) {
                            func_L00_002D2168(6, 0, 12.0f);
                            func_002AC9F8(D_00189E20.v160.value, 0.12833333f);
                        }
                        goto done;
                    }
                    func_L01_002BEB90(0, 1);
                    goto settleSlowly;
                } else {
                    func_L01_002BEB90(2, 1);
                    acceleration = 0.016f;
                    decay = 0.002f;
                    window = 7;
                    count = 2;
                }
            } else {
                if (func_L01_002BEB90(0, 0)) func_L00_002D2168(12, 4, 6.0f);
                if (enabled) D_00189E20.f1E0 = 22;
                acceleration = 0.022f;
                decay = 0.004f;
                window = 10;
                count = 4;
            }
            func_L00_002D3248(window, count, 0, 1, acceleration, decay);
            goto done;
        }
        if (D_00189E20.f24CC <= 0) goto done;
        if ((INPUT & 0x40) && D_001A7AFA && func_L00_002ADEA0(3) != 4 &&
            !D_00189E20.f24FC && !D_00189E20.f1E0 && HEIGHT > 0.6f) { next = 8; break; }
        if (D_00189E20.f202 > 20 && func_L00_002C9FC8(D_00189E20.f1EE ? 1 : 6, 0)) goto done;
        if (!D_00189E20.f578) goto done;
        next = 23;
        break;

    case 7: case 9: case 10: case 11: case 12: case 13: case 14:
    case 15: case 16: case 17: case 18: case 27: case 56:
    case 102: case 110: case 129: case 137:
        if (D_00189E20.f52E && (window = func_L00_002C3A40()) > 0 &&
            (TIMER < window || D_00189E20.f49C) && D_00189E20.f340 &&
            (STATE != 11 || func_L00_0032EF10(0x40, 7, 0))) {
            enabled = 1;
            if (STATE == 27 || D_00189E20.f49C) enabled = func_L00_0032EF10(0x40, 7, 0) != 0;
            if (STATE == 11 && !D_00189E20.f49C) enabled = 0;
            if (enabled && func_L00_0032EF10(0x1F000, 5, 0) && (INPUT & 8)) {
                next = 11;
                break;
            }
        }
        if (D_00189E20.f1F2 && (STATE == 7 || STATE == 9) && TIMER > 19) { next = 0x82; break; }
        if (STATE == 27 && TIMER > 20 && D_00189E20.f278 > 0.7f) {
            D_00189E20.f22BC = 0;
            D_00189E20.f22BF = 0;
        }
        if (TIMER < 7 && func_L00_0032EF10(8, 2, 0) && STATE != 16 &&
            STATE != 10 && STATE != 18 && STATE != 56 && STATE != 17 && STATE != 14 && STATE != 102) {
            mode = func_L00_002ADEA0(3);
            if (mode == 2 && D_001A7AFA && !D_00189E20.f24FC && D_00189E20.f178 > 0.015000001f)
                func_L01_002BEB90(10, 1);
            else if (func_L00_002ADEA0(3) == 3 && !D_00189E20.f24FC &&
                     D_00189E20.f178 > 0.015000001f && !D_00189E20.f1E4)
                func_L01_002BEB90(16, 1);
        }
        if (TIMER > D_00189E20.f51A) {
            if (!D_00189E20.f49C) { next = 6; break; }
        } else if (!D_00189E20.f49C && (STATE == 10 || STATE == 16) && D_00189E20.f278 < 0.9f &&
                   D_00189E20.f287 && func_00282DF0(D_00189E20.vF0.value) > 0.116666675f) {
            length = func_00282DF0(D_00189E20.v110.value);
            target = func_00282DF0(D_00189E20.vF0.value);
            if (length < target * 0.5f && !D_00189E20.f578 && HEIGHT < 2.0f) { next = 0x77; break; }
        }
        blocked = STATE == 14 && FRAME < 35.0f;
        if (TIMER <= D_00189E20.f4AC) goto done;
        if (TIMER == D_00189E20.f4AC + 1) {
            if (!D_00189E20.f49D) {
                if (STATE != 14) {
                    func_L00_002D3D98(D_00189E20.v80.value, D_00189E20.vF0.value, &count, D_00189E20.f520);
                    func_L00_002A9E30(D_00189E20.f4C8, (float)count, D_00189E20.f514, -1.0f);
                    if (D_00189E20.fC20 > 1.5f) D_00189E20.fC20 = 1.5f;
                }
                goto done;
            }
            count = D_00189E20.f430 - TIMER;
            target = D_00189E20.f438;
            goto smoothAirAnimation;
        }
        if (D_00189E20.f49D && TIMER >= D_00189E20.f430 && TIMER < D_00189E20.f434) {
            count = D_00189E20.f440 - D_00189E20.f430;
            target = D_00189E20.f4C8;
            goto smoothAirAnimation;
        }
        if (D_00189E20.f338 == 1) {
            func_L00_002B9B88(12, 0);
            func_L00_002AABE0(3, 24, 1);
        }
        enabled = D_00189E20.f49C + 1;
        if (!D_00189E20.f49C && !D_00189E20.f34E) {
            enabled = 0;
            if (D_00189E20.f49E && !blocked) {
                func_L00_002A6188();
                D_00189E20.f49C = 1;
                D_00189E20.f24DB = 0;
                if (BLEND < 0.2f && D_00189E20.f1B4 > 0.041666668f) D_00189E20.f1B4 = 0.041666668f;
                func_L00_002D3248(5, 2, 0, 1, 0.016f, 0.002f);
                blendFrames = func_00283CF0(D_00189E20.f4D0);
                enabled = D_00189E20.f49C;
                if (FRAME < D_00189E20.f4CC - 1.5f) {
                    func_L00_002D2168(func_L00_002A4EF0((unsigned char)object[0x43]), blendFrames + 2, 7.0f);
                    enabled = D_00189E20.f49C;
                }
            }
        }
        D_00189E20.f49C = enabled;
        if (!D_00189E20.f49C) {
            if (D_00189E20.f49E) {
                if ((unsigned char)object[0x41] < func_00283CF0(D_00189E20.f4D0)) {
                    if (STATE != 14 || FRAME >= 37.0f) {
                        D_00189E20.f4AE = func_00283CF0(func_L01_002C81D0(60.0f, D_00189E20.f520, -1.0f));
                        func_L00_002A9E30(D_00189E20.f4CC, (float)D_00189E20.f4AE, D_00189E20.f514, 0.2f);
                    } else func_002AA2E8(&D_00189E20.fC20, 1.0f, 0.15f);
                    if (!blocked) {
                        blendFrames = func_00283CF0(D_00189E20.f4D0);
                        if (D_00189E20.fC20 > 1.8f)
                            func_L00_002D2168(func_L00_002A4EF0((unsigned char)object[0x43]),
                                             blendFrames + 2, (float)(D_00189E20.f4AE + 3));
                    }
                    if (D_00189E20.fC20 < 0.2f) D_00189E20.fC20 = 0.2f;
                    if (D_00189E20.fC20 > 2.7f) D_00189E20.fC20 = 2.7f;
                }
                if (STATE == 9 && D_00189E20.f4CC - FRAME > 6.0f) {
                    animation = func_L00_002A4EF0((unsigned char)object[0x42]);
                    if (animation == 8 || func_L00_002A4EF0((unsigned char)object[0x42]) == 9) {
                        if (object[0x42] == object[0x43] && D_00189E20.f1B0 < D_L01_001A7DC0 * 0.0016666668f &&
                            D_00189E20.f174 < 0.041666668f) {
                            speed = 9.0f / D_00189E20.fC20;
                            if (9.0f / D_00189E20.fC20 > 10.0f) speed = 10.0f;
                            frame = func_00283CF0(FRAME);
                            func_L00_002D2168(7, (frame + 4) / 2, speed);
                            STATE = 7;
                        }
                    }
                }
                frame = func_00283CF0(FRAME);
                if (frame == func_00283CF0(D_00189E20.f4CC)) D_00189E20.fC20 = 0.0f;
            }
        } else D_00189E20.fC20 = 1.0f;
        if (D_00189E20.f49C) {
            if (STATE == 10) {
                if (func_L01_002BEB90(3, 0)) {
                    func_L00_002D2168(5, 0, -2.0f);
                    func_00282D30(D_00189E20.v160.value, D_00189E20.v160.value, 0.8f);
                }
                goto done;
            }
            if (!D_00189E20.f149A && !D_00189E20.f1E0 && func_L00_0032EF10(0x40, 8, 0) && D_00189E20.f34E < 4) {
                next = D_00189E20.f1B0 > D_L01_001A7DB4 &&
                    func_00283C80(D_00189E20.f1A0, D_00189E20.v90.value[2]) < 1.0471976f &&
                    D_00189E20.f174 > D_L01_001A7DC0 * 0.014166668f ? 9 : 7;
                break;
            }
        }
        if (D_00189E20.f49C < 2 || STATE == 10) {
            if (D_00189E20.f49E && TIMER >= D_00189E20.f52A && D_00189E20.f510 < HEIGHT) func_L01_002BEB90(6, 1);
        } else func_L01_002C2CF0();
        if (STATE == 16 && TIMER >= 61 && HEIGHT > 1.5f) { next = 6; break; }
        enabled = STATE == 7 || STATE == 9 || STATE == 17;
        if (D_00189E20.f1D4 && !D_00189E20.f49C && enabled && (STATE != 17 || TIMER >= 26) &&
            func_L00_0032EF10(0x40, 7, &buffered) && TIMER > buffered) { next = 17; break; }
        if ((STATE == 10 || STATE == 16) && TIMER > 25 && D_00189E20.f34A) D_00189E20.f526 = 20;
        window = STATE == 16 ? 8 : 20;
        if (STATE == 14 && HEIGHT > 4.0f) {
            if (!D_00189E20.f49E && D_00189E20.fC20 < 1.3f) func_002AA2E8(&D_00189E20.fC20, 1.3f, 0.1f);
            window = 17;
            D_00189E20.f526 = 17;
        }
        count = TIMER - 4;
        if (count < 2) count = 2;
        if (count > 30) count = 30;
        if (!D_00189E20.f49F && !D_00189E20.f49C) {
            enabled = func_L00_0032EF10(0x40, count, 0) != 0;
            if (enabled || STATE == 14 || STATE == 15 || STATE == 13) {
                if (STATE != 14 && !D_00189E20.f22B8 && (!D_00189E20.f149A || HEIGHT >= 0.4f) &&
                    D_00189E20.f52F && TIMER > 14) {
                    if (!D_00189E20.f49E || (HEIGHT > 0.7f &&
                        func_00282C48(func_L00_002D3B00((char *)D_00189E20.vF0.value)) < 0.09666667f))
                        func_L01_002BEB90(14, 1);
                }
            }
            if (D_001A7AFA && func_L00_002ADEA0(3) != 4 && !D_00189E20.f24FC &&
                (INPUT & 0x40) && TIMER > window && TIMER > D_00189E20.f526) {
                target = STATE == 9 || STATE == 7 ? 1.0f : 0.6f;
                if (STATE == 14) target = 1.5f;
                if (HEIGHT > target) func_L01_002BEB90(8, 1);
            }
        }
        if (D_00189E20.f578 && STATE != 11) { next = 23; break; }
        goto done;
smoothAirAnimation:
        if ((float)count > 0.0f) func_L00_002A9E30(target, (float)count, D_00189E20.f514, -1.0f);
        goto done;

    case 8:
        if (D_00189E20.f1D4 && TIMER <= 8) {
            if (D_00189E20.f22A0 == 7 || D_00189E20.f22A0 == 9 || D_00189E20.f22A0 == 14 || D_00189E20.f22A0 == 17) {
                next = 17;
                break;
            }
            goto done;
        }
        if (TIMER >= 31 && !(INPUT & 0x40) && !(D_00138180.secondaryBuffered & 0x40)) { next = 6; break; }
        if (D_00189E20.f578) { next = 23; break; }
        if (D_00189E20.f34E && HEIGHT >= 0.4f) goto done;
        if (TIMER < 10) D_00189E20.f1EE = 12 - TIMER;
        func_L00_002B39F0(0, 1.0f);
        if (D_00189E20.f22A0 == 16 && TIMER < 4) {
            if (func_L01_002BEB90(3, 0)) {
                func_L00_002D2168(5, 0, -1.0f);
                D_00189E20.f1E0 = 34;
            }
            goto done;
        }
        if (INPUT & 8) {
            func_L01_002BEB90(4, 1);
            goto settleSlowly;
        }
        if (D_00189E20.f1B0 <= D_L01_001A7DB4 || func_00283C80(D_00189E20.f1A0, D_00189E20.v90.value[2]) >= 1.5707964f) {
            if (D_00189E20.f1B0 <= D_L01_001A7DB4) {
                if (!D_00189E20.f34E) {
                    if (!func_L01_002BEB90(0, 0)) goto done;
                    func_L00_002D2168(func_L01_002A7248(0), 0, -2.0f);
                } else {
                    if (!func_L01_002BEB90(0, 0)) goto done;
                    func_L00_002D2168(7, 23, 9.0f);
                }
                goto settleSlowly;
            }
            if (D_00189E20.f1492 || D_00189E20.f22B9) { next = 2; break; }
            func_L01_002BEB90(2, 0);
            if (STATE == 2) {
                D_00189E20.f2298 = 1;
                func_L00_002D2168(4, D_L01_001A7DD8[1], 12.0f);
            }
        } else {
            if (D_00189E20.f1492 || D_00189E20.f22B9) { next = 2; break; }
            func_L01_002BEB90(2, 0);
            if (STATE == 2) {
                D_00189E20.f2298 = 1;
                func_L00_002D2168(4, 2, 8.0f);
                D_00189E20.f40E = 1;
            }
        }
        func_L00_002D3248(5, 2, 1, 0, 0.016f, 0.002f);
        goto done;
settleSlowly:
        func_L00_002D3248(5, 2, 0, 1, 0.016f, 0.002f);
        goto done;

    case 19: case 21:
        row = D_L01_0025EC90[D_00189E20.fBFC];
        window = (func_00283CF0(FRAME) - *(int *)(row + 12)) * 2;
        if (STATE == 21) window = 8;
        if ((float)*(int *)(row + 20) < FRAME) {
            if (!D_00189E20.fC2C) {
                if ((STATE != 21 || D_00189E20.f348 != 1) && func_L00_0032EF10(0x40, window, 0)) {
                    if (!(INPUT & 8)) { next = 7; break; }
                    if (func_L00_002CAB08()) goto done;
                }
                goto finishAttack;
            }
        } else {
finishAttack:
            if (!D_00189E20.fC2C) {
                if (FRAME > 34.0f && BLEND > 0.9f) {
                    func_L01_002BEB90(2, 0);
                    func_L00_002D2168(3, D_L01_001A7DD8[D_00189E20.f2298], 13.0f);
                    goto done;
                }
                if ((float)*(int *)(row + 24) < FRAME) {
                    if (BLEND > 0.8f) { next = 2; break; }
                    if (FRAME <= (float)(*(int *)(row + 24) + 5) && !(D_00189E20.fC28 & 2)) goto done;
                    func_L01_002BEB90(0, 0);
                    goto done;
                }
            }
        }
        if (STATE != 21) goto done;
        if (D_00189E20.f1248 != 10) { next = 0; break; }
        goto finishLongAttack;

    case 20:
        if (STATE == 20) {
            count = func_00283CF0(func_L01_002C81D0(60.0f, 0.036111113f, -1.0f));
            if (D_00189E20.fC00 == 0.0f) D_00189E20.fC20 = 0.33f;
            else if (!D_00189E20.f34E) D_00189E20.fC20 = FRAME < 26.0f ? 2.0f : 1.0f;
            else if (!count || 26.0f - FRAME <= 1.0f) D_00189E20.fC20 = 1.0f;
            else {
                func_L00_002A9E30(26.0f, (float)count, 0.5f, -1.0f);
                if (HEIGHT < 0.7f && D_00189E20.fC20 < 0.75f) D_00189E20.fC20 = 0.75f;
            }
        }
        row = D_L01_0025EC90[D_00189E20.fBFC];
        frame = func_00283CF0(FRAME);
        if ((float)*(int *)(row + 20) < FRAME) {
            if (D_00189E20.fC2C) goto done;
            if (func_L00_0032EF10(0x40, (frame - *(int *)(row + 12)) * 2, 0)) {
                if (!(INPUT & 8)) { next = 7; break; }
                if (func_L00_002CAB08()) goto done;
            }
        }
        if (!D_00189E20.fC2C && (float)*(int *)(row + 24) < FRAME) func_L01_002BEB90(0, 0);
        goto done;

    case 22:
        if (FRAME > 12.5f && !D_00189E20.f24EF && D_00189E20.f34E && HEIGHT > 1.0f) { next = 6; break; }
        if (TIMER < 28) goto done;
        if (D_00189E20.f24CC <= 0) { next = 0x39; break; }
        if (!D_00189E20.f24EF) { func_L01_002BEB90(0, 0); goto done; }
        next = 0x82;
        break;
    case 23:
        if (FRAME > 13.5f) func_L01_002BEB90(24, 0);
        goto done;

    case 24:
        if ((D_00189E20.fC28 & 2) && D_00189E20.f2290[0x43] == 32) func_L00_002D2168(33, 0, 6.0f);
        func_L00_002B39F0(0, 1.0f);
        if (!func_L01_002AE128(D_00189E20.v80.value, D_00189E20.v90.value, 0)) {
            func_L01_002BEB90(6, 1);
            D_00189E20.f1D0 = 10;
            goto done;
        }
        if ((BLEND > 0.5f && func_L00_0032EF10(0x40, 9, 0) &&
             func_00283C80(D_00189E20.f1A0, D_00189E20.v90.value[2]) > 2.3561947f) || (PRESSED & 8)) {
            func_L01_002BEB90(6, 1);
            D_00189E20.f22BF = 1;
            D_00189E20.f1D0 = 10;
            goto done;
        }
        if (func_L00_0032EF10(0x40, 17, 0)) { next = 27; break; }
        if (BLEND <= 0.5f) goto done;
        angle = 1.5707965f;
        if (func_00283C80(D_00189E20.f1A0, func_00283B98(D_00189E20.v90.value[2], angle)) >= 0.78539824f) {
            angle = -1.5707965f;
            if (func_00283C80(D_00189E20.f1A0, func_00283B98(D_00189E20.v90.value[2], angle)) >= 0.78539824f) goto done;
        }
        position.bits = D_00189E20.v80.bits;
        position.value[0] += func_00283180(func_00283B98(D_00189E20.v90.value[2], angle)) * 0.3f;
        position.value[1] += func_00283198(func_00283B98(D_00189E20.v90.value[2], angle)) * 0.3f;
        if (func_L01_002AE128(position.value, D_00189E20.v90.value, 0)) {
            next = angle < 0.0f ? 26 : 25;
            break;
        }
        goto done;

    case 25: case 26:
        angle = STATE == 26 ? -1.5707965f : 1.5707965f;
        position.bits = D_00189E20.v80.bits;
        position.value[0] += func_00283180(func_00283B98(D_00189E20.v90.value[2], angle)) * 0.3f;
        position.value[1] += func_00283198(func_00283B98(D_00189E20.v90.value[2], angle)) * 0.3f;
        func_L00_002B39F0(0, 1.0f);
        if (BLEND < 0.5f || func_00283C80(D_00189E20.f1A0, func_00283B98(D_00189E20.v90.value[2], angle)) > 0.78539824f ||
            !func_L01_002AE128(position.value, D_00189E20.v90.value, 0)) {
            if (D_00189E20.fC28 & 2) { next = 24; break; }
        }
        if (BLEND > 0.5f && func_L00_0032EF10(0x40, 9, 0) &&
            func_00283C80(D_00189E20.f1A0, D_00189E20.v90.value[2]) > 2.3561947f) {
            func_L01_002BEB90(6, 1);
            D_00189E20.f1D0 = 40;
            D_00189E20.f22BF = 1;
            goto done;
        }
        if (func_L00_0032EF10(0x40, 9, 0)) { next = 27; break; }
        goto done;

    case 29:
        if (!D_00189E20.f22B4 && (!D_00189E20.f22BA || D_00189E20.f22B5))
            func_L00_002D2168((INPUT & 8) ? 13 : func_L01_002A7248(1), 0, 8.0f);
        if (INPUT & 4) goto done;
        if (STATE == 29) {
            func_L01_002BEB90(0, 0);
            animation = func_L01_002A7248(1);
            if ((unsigned char)D_00189E20.f2290[0x43] != animation)
                func_L00_002D2168(animation, 0, 8.0f);
        }
        D_L01_001A8A48 = 0;
        goto done;
    case 31:
        if (D_00189E20.f1220 && !D_00189E20.fC2C && FRAME > 20.0f) func_L01_002BEB90(0, 0);
        goto done;
    case 34:
        if (FRAME > 19.0f && func_L00_0032EF10(0x40, 11, 0)) {
            if (!(INPUT & 8)) { next = 7; break; }
            func_L00_002CAB08();
        } else if (FRAME >= 21.0f) func_L01_002BEB90(0, 0);
        goto done;
    case 47:
        if ((INPUT & D_00189E20.f1230) || D_00189E20.f1EC) goto done;
        if (D_00189E20.f2290[0x43] == 54) { func_L01_002BEB90(0, 0); goto done; }
        next = 0;
        break;
    case 48:
        if ((!D_00189E20.f1493 && !D_00189E20.f200) || HEIGHT > 1.0f) {
            if (D_00189E20.f2434 != -1 &&
                *(char **)(D_00188660 + D_00189E20.f2434 * 112 + 0x88) == D_00189E20.f2290 &&
                D_00188660[D_00189E20.f2434 * 112 + 0x74]) func_002E59F8(D_00189E20.f2434);
            D_00189E20.f2434 = -1;
            if (func_L01_002BEB90(0, 0)) {
                func_L00_002D2168(func_L01_002A7248(0), 0, 17.0f);
                D_00189E20.v160.bits = D_00189E20.v150.bits;
            }
        }
        goto done;

    case 0x39: case 0x43: case 0x5F: case 0x67: case 0x7D: case 0x7F:
        if (!(D_00189E20.fC28 & 2) && !D_00189E20.f22C0) goto done;
        if (D_00189E20.f21E) {
            D_00189E20.f22C0 = 1;
            D_00189E20.fC20 = 0.0f;
            func_00282978((short *)((char *)&D_00189E20 + 0x21E));
            return;
        }
        func_L00_002B30E8();
        return;
    case 60:
        if ((INPUT & 4) && !D_00189E20.f1500 && !func_L00_004272A0()) { next = 1; break; }
        if (!D_00189E20.f34E && !(INPUT & 0x40) && !(INPUT & 8)) {
            func_L01_002B46A0();
            if (D_00189E20.f1B0 <= 0.0f) {
                if (!(D_00189E20.fC28 & 2)) goto done;
                func_L00_002CA478();
                next = 0;
                break;
            }
        }
        next = 61;
        break;
    case 61:
        if (TIMER < 9) goto done;
        func_L00_002CA478();
        if (!D_00189E20.f34E) {
            if (func_L00_002C9FC8(7, 0)) goto done;
            next = 4;
            if (!(INPUT & 8)) {
                func_L01_002B46A0();
                next = D_00189E20.f1B0 <= 0.0f ? 0 : 2;
            }
        } else next = 6;
        break;

    case 98:
        if (func_00282E80(D_00189E20.v80.value, D_00189E20.v18A0.value) >= 0.2f) {
            func_L00_002CA0B0();
            goto done;
        }
        if (D_00189E20.f170 < 0.045f && func_00283C80(D_00189E20.v90.value[2], D_00189E20.v18A0.value[3]) < 0.03490659f) {
            next = 100;
            break;
        }
        if (!D_00189E20.f22B4 || D_00189E20.f170 < 0.045f) goto done;
        next = 99;
        break;
    case 99:
        if (!(D_00189E20.fC28 & 2)) goto done;
        next = 98;
        break;
    case 100:
        if ((D_00189E20.fC28 & 2) || D_00189E20.f18B0) func_L01_002BEB90(0, 1);
        if (func_00282E80(D_00189E20.v80.value, D_00189E20.v18A0.value) <= 0.2f) goto done;
        next = 98;
        break;
    case 101:
        if (D_00189E20.f18C0 < 3 && D_00189E20.f18C0 * 7 + 10 < TIMER &&
            func_L00_0032EF10(0x40, 7, &buffered)) func_L01_002BEB90(102, 1);
        if (D_00189E20.v80.value[2] < D_00189E20.f334 - 1.2f || TIMER >= 171) {
            func_L00_002B30E8();
            return;
        }
        goto done;
    case 109:
        if (FRAME <= (float)*(int *)(D_L01_0025EC90[D_00189E20.fBFC] + 24)) goto done;
        next = 0;
        break;
    case 116:
        if (D_001A79F0 == 13) {
            if (D_00189E20.f22A4 == 30 || D_00189E20.f22B0 == 30) {
                if ((D_00189E20.v80.value[2] < 51.0f && TIMER > 30) ||
                    (TIMER > 30 && D_00189E20.f287 && (D_00189E20.v110.value[2] >= 0.0f || D_00189E20.f149B))) {
                    func_L00_002B30E8();
                    return;
                }
            } else if (D_00189E20.v80.value[2] < 89.0f || (TIMER > 20 && D_00189E20.f287 && D_00189E20.v110.value[2] >= 0.0f)) {
                func_L00_002B30E8();
                return;
            }
        }
        if (TIMER >= 121) { func_L00_002B30E8(); return; }
        goto done;
    case 118:
        if (TIMER > 300) func_L00_002B30E8();
        if (D_00189E20.f149A) goto done;
        next = D_00189E20.f34E ? 6 : 0;
        break;
    case 119:
        if (!(D_00189E20.fC28 & 2)) goto done;
        next = 0;
        break;
    case 120:
        if (D_00189E20.v80.value[2] < D_00189E20.f334 - 1.2f || TIMER >= 151) { func_L00_002B30E8(); return; }
        goto done;

    case 123:
        enabled = D_00189E20.f348 != 0 || (!(INPUT & 8) && TIMER > 60) || D_00189E20.f22B8;
        if (enabled) {
            if (D_00189E20.f2304) D_00189E20.f2320 = 1;
            func_L00_002B9B88(9, 0);
            D_00189E20.f1E0 = 30;
            func_L01_002BEB90(3, 0);
            func_L00_002D2168(6, 4, 11.0f);
            goto done;
        }
        if (!D_00189E20.f287) goto emitJointParticles;
        length = func_00282DF0(D_00189E20.v110.value);
        target = func_00282DF0(D_00189E20.vF0.value);
        if (length >= target * 0.75f && !func_L00_002AB108(0, 1.0f, 1.25f)) goto emitJointParticles;
        next = 119;
        break;
emitJointParticles:
        delta.value[0] = -0.083333336f;
        delta.value[1] = 0.0f;
        delta.value[2] = 0.0f;
        delta.value[3] = 0.0f;
        func_0029FCC0(D_00189E20.f2290, 22, (char *)&position);
        func_0029FCC0(D_00189E20.f2290, 23, (char *)&joint);
        func_L00_0033C0D0(D_00189E20.f2290, &position, &delta, D_L01_001A7CA0, 1);
        func_L00_0033C0D0(D_00189E20.f2290, &position, &delta, D_L01_001A7CB0, 1);
        func_L00_0033C0D0(D_00189E20.f2290, &joint, &delta, D_L01_001A7CA0, 1);
        func_L00_0033C0D0(D_00189E20.f2290, &joint, &delta, D_L01_001A7CB0, 1);
        goto done;

    case 130:
        if (func_L00_002D3B00((char *)D_00189E20.vF0.value) < 0.0f && D_00189E20.f340 &&
            (!D_00189E20.f33C.pointer || *(short *)(D_00189E20.f33C.pointer + 0xAA) == 0x8E2) &&
            func_L01_002BEB90(0, 0)) {
            D_00189E20.f24EF = 0;
            func_L00_002D2168(7, 23, 9.0f);
            func_L00_002D3248(5, 2, 0, 1, 0.016f, 0.002f);
        }
        if (D_00189E20.f5B0 != 0.0f) goto done;
        next = D_001A79F0 == 13 && D_00189E20.f318 < 69.0f ? 116 : 6;
        break;
    case 131:
        if (FRAME > 37.0f) {
            if (!D_00189E20.fC2C) {
                if (func_L00_0032EF10(0x40, 7, 0)) {
                    if (!(INPUT & 8)) { next = 7; break; }
                    if (func_L00_002CAB08()) goto done;
                }
                goto finishRecovery;
            }
        } else {
finishRecovery:
            if (!D_00189E20.fC2C && FRAME > 37.0f) {
                func_L01_002BEB90(0, 0);
                func_L00_002D2168(func_L01_002A7248(0), 0, 15.0f);
                goto done;
            }
        }
        if (STATE != 21) goto done;
finishLongAttack:
        if (TIMER >= 101 && D_00189E20.fC44 <= 25) {
            func_L00_002D24D0(2);
            D_00189E20.fC44 = 26;
        }
        goto done;
    case 133:
        if (TIMER < 4 || !(PRESSED & 0x10)) goto done;
cancelAction:
        func_L01_002C1988(0);
        goto done;
    case 140:
        if (D_00189E20.fC28 & 2) func_L00_002D2168(151, 0, 2.0f);
        if (TIMER < 51 || D_00189E20.f1E0) goto done;
        if (D_00189E20.f24CC <= 0) { next = 0x39; break; }
        if (func_L01_002BEB90(0, 0)) func_L00_002D2168(func_L01_002A7248(0), 0, 13.0f);
        goto done;
    default:
        goto done;
    }
change:
    func_L01_002BEB90(next, 1);
done:
    if (previousMotion != MOTION) func_L00_002A6708();
    if ((D_00189E20.f22A0 == 60 && STATE != 61) || (D_00189E20.f22A0 == 61 && D_00189E20.f1854))
        func_L00_002CA478();
    if (previousPhase != D_00189E20.f2298) D_00189E20.f1C0 = 0;
    if (previousAnimation != (unsigned char)object[0x43]) D_00189E20.f1C4 = 0;
}
