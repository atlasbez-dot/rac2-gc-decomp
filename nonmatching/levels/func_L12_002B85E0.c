/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 absent from catalogue; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Retained readable reconstruction, 23 October 2026; not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * US: 1008/1020 bytes, 0/1 placements, check.py exit 1.
 * US2/PAL: this name is absent from both catalogues, not a match.
 * Seven bounded trials: delaying the absolute-direction flag recovers the
 * retail saved-register set and 0x50 frame. Separate/combined guards, the
 * measured global access form, grouped copies and a guard-label form were
 * checked. gcse-unsplit-edges stayed 1008 bytes and was discarded.
 * Early-return edge layout, absolute global access scheduling, zero/copy and
 * response-branch ordering remain different. Reopen with independent evidence
 * for those control-flow or address-lifetime choices, not repeated flags.
 * Interaction entries retain their full 64-byte stride and vectors 16 bytes.
 * Ignored helper returns still unresolved in retail are marked below; no
 * linked qualification or game-behavior validation is claimed.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;

/* Resident fields used by the interaction response. This is a partial view. */
typedef struct {
    u8 unknown00[0x80];
    Vector position;
    u8 unknown90[0xF0 - 0x90];
    Vector offsetA;
    u8 unknown100[0x110 - 0x100];
    Vector offsetB;
    u8 unknown120[0x1DC - 0x120];
    short lockTimer;
    u8 unknown1DE[0x21C - 0x1DE];
    short responseTimer;
    u8 unknown21E[0x1497 - 0x21E];
    u8 suppressResponse;
    u8 unknown1498[0x1500 - 0x1498];
    int extraResponse;
    u8 unknown1504[0x2290 - 0x1504];
    char *object;
    int action;
    int unknown2298;
    int state;
    u8 unknown22A0[0x22B4 - 0x22A0];
    u8 mode;
    u8 unknown22B5[0x249C - 0x22B5];
    char *target;
    u8 unknown24A0[0x24CC - 0x24A0];
    int resource;
} InteractionPlayer;

typedef struct {
    u8 unknown00[0x10];
    Vector direction;
    char *target;
    u32 flags;
    u8 kind;
    u8 unknown29[3];
    float fadeStep;
    u32 directionFlags;
    int unknown34;
    char *owner;
    int unknown3C;
} InteractionRecord;

extern InteractionPlayer D_00189E20;
extern InteractionRecord D_L12_001C44C0[];
extern int D_L12_001A8F00 __attribute__((nosda));
extern u8 D_001A7A32 __attribute__((nosda));
extern u8 D_001A7A33 __attribute__((nosda));
extern float func_L00_0037E668(void);
extern float func_L00_0037E5F0(float);
extern void func_00282CF0(void *, const void *, const void *);
extern void func_00282CC0(void *, const void *, const void *);
extern void func_L00_002D36E0(float *, int, float, float, float);
extern void *func_002A9640(void *, u32, int);
extern int func_00283CF0(float);
extern int func_L00_002B9B88(int, int);
extern int func_L12_002C8BD0(int, int);
extern void func_L00_002B2C58(int, int, float, float);
extern void func_L00_002D3C68(char *, char *, float);
/* Inputs are qualified in retail. Ignored results do not establish the
 * original return declarations; void is an interface assumption here. */
extern void func_L00_002A6708(void);
extern void func_L00_002A4EF8(int);

/* Select the current owned interaction and optionally apply its response. */
int func_L12_002B85E0(int apply)
{
    InteractionRecord *record;
    Vector direction;
    char *actor;
    int absolute;
    float amount;

    if (D_00189E20.state == 20 || D_00189E20.state == 7 || D_00189E20.action == 49)
        return 0;
    if (D_00189E20.lockTimer != 0)
        return 0;
    if (D_L12_001A8F00 != 0)
        return 0;
    D_00189E20.target = 0;
    if ((u8)D_00189E20.object[0xA8] == 255)
        return 0;
    record = &D_L12_001C44C0[(u8)D_00189E20.object[0xA8]];
    if (record->owner != D_00189E20.object)
        return 0;
    if (!(record->flags & 9))
        return 0;
    if (record->fadeStep != 0.0f) {
        D_001A7A33 = 0;
        D_001A7A32 = 1;
    }
    if (func_L00_0037E668() != 0.0f && D_00189E20.mode == 0) {
        record->fadeStep = func_L00_0037E5F0(record->fadeStep);
        if (record->fadeStep == 0.0f)
            return 0;
    }
    D_00189E20.target = record->target;
    if (!apply)
        return 1;
    func_L00_002A6708();
    absolute = 0;
    if (record->directionFlags & 1) {
        direction.q = record->direction.q;
        if (record->direction.f[3] == 5627.9248047f)
            absolute = 1;
    } else if (record->target == 0) {
        func_L00_002D36E0(direction.f, 0, -1.0f, 0.0f, 0.0f);
    } else {
        func_00282CF0(&direction, &D_00189E20.position, record->target + 0x10);
    }
    if (D_00189E20.mode != 0) {
        if (D_00189E20.mode == 1) {
            func_L12_002C8BD0(0x42, 1);
            func_L00_002B2C58((int)&direction, absolute, 0.083333335817f, 0.05000000447f);
        }
    } else {
        actor = D_00189E20.target;
        if (actor && (*(short *)(actor + 0xAA) == 0x4EB || *(short *)(actor + 0xAA) == 0x558)) {
            func_L12_002C8BD0(0x7D, 1);
            return 1;
        }
        if ((D_00189E20.action == 1 || D_00189E20.action == 0x1D || D_00189E20.extraResponse != 0) &&
            !(record->flags & 8)) {
            actor = func_002A9640(D_00189E20.object, 1, 0);
            if (actor != 0)
                func_L00_002A4EF8(func_00283CF0(*(float *)(actor + 0x2C)));
            if (D_00189E20.resource == 0)
                func_L12_002C8BD0(0x16, 1);
            D_00189E20.lockTimer = 0x4D;
            if (D_00189E20.responseTimer == 0)
                D_00189E20.responseTimer = 0x12;
            func_L00_002B9B88(20, 0);
            return 0;
        }
        if (D_00189E20.state == 0x12)
            func_L12_002C8BD0(0x72, 1);
        else if (D_00189E20.state == 0x11)
            func_L12_002C8BD0(0x73, 1);
        else if (record->flags & 8)
            func_L12_002C8BD0(0x8C, 1);
        else
            func_L12_002C8BD0(0x16, 1);
        if (D_00189E20.action == 0x8C) {
            direction.q = 0;
        } else {
            amount = 0.055000003427f;
            if (D_00189E20.suppressResponse)
                amount = 0.0f;
            func_L00_002B2C58((int)&direction, absolute, amount, 0.028333336115f);
            if (absolute && record->kind == 4)
                func_L00_002D3C68((char *)&direction, (char *)&direction, 2.0f);
        }
    }
    func_00282CC0(&D_00189E20.offsetA, &D_00189E20.offsetA, &direction);
    func_00282CC0(&D_00189E20.offsetB, &D_00189E20.offsetB, &direction);
    return 1;
}
