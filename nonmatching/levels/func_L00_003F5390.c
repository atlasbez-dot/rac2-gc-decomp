/* 26 October 2026 (M24): -O2 -G8 -ffunction-sections -frac2-zero-ti-por, 708/708 bytes, 39 lines off (registers): index D_00139568[0x17] as an incomplete array, hit loop indexed, func_0032C700 with its matched prototype, func_002C2210 floats before the vector. */
/*
 * Retained manual near miss; not linked or counted.
 * Final measured profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por.
 * Final C / retail: 700 / 708 bytes.
 * us:0/27 placements, exit1; us2:0/27 placements, exit1.
 * pal: absent from catalogue, exit1; absence is not a match.
 * 6 bounded source/profile trials; three natural source forms tie.
 * Correct0xC0 frame and explicit scratch overlap; outgoing GPR/FP call setup and hit-list/particle-loop scheduling differ.
 * Reopen only with: An independently matching collision-request/emitter allocation witness; no invented formal-order or barrier change.
 * Measured in the dedicated src unit before its marker/profile were restored; this body is retained unchanged modulo this comment.
 * Historical draft and trial variants remain private. Behavior and strict linked equality remain unverified.
 */

#include "common.h"
typedef int HeroQ __attribute__((mode(TI)));
typedef union { unsigned char b[0x2600]; signed char c[0x2600]; short h[0x1300]; unsigned short uh[0x1300]; int i[0x980]; unsigned int u[0x980]; float f[0x980]; char *ptr[0x980]; HeroQ q[0x260]; } Hero;
extern unsigned char D_00189E20[];
#define H ((Hero *)D_00189E20)

typedef int HitWord128 __attribute__((mode(TI)));
typedef union { HitWord128 word; float values[4]; } HitVector;
typedef struct { char prefix[0x17]; unsigned char index; } HitSettings;
typedef struct { char prefix[4]; unsigned char enabled; char middle[0x74-5]; float scale; char suffix[0xE0-0x78]; } HitTuning;
typedef struct {
    HitVector direction;
    void *owner;
    int flags;
    unsigned char enabled, kind;
    unsigned short classId;
    float scale;
    int active;
    char suffix[12];
} HitRequest;
extern unsigned char D_00139568[];
extern HitTuning D_L00_00262570[] __attribute__((nosda));
extern int D_L00_001ADB2C;

extern char *D_L00_001C3280[] __attribute__((nosda));
extern void *func_0032C700(void *, int, int, int, int, int, int, int, float, float, int, int, int, int);
extern void func_00282F20(void *, void *, float);
extern int func_00277F48(void *, int, void *, void *, float);
extern int func_00334160(char *, int, int);
extern int func_002A7820(int, int);
extern int func_002A77E0(int);
extern float func_002A78D8(float, float);
extern char *func_002C2210(void *, int, unsigned int, int, int, float, float, void *, float, int);

void func_L00_003F5390(char *object, HitVector *source) {
    char *state = *(char **)(object + 0x68);
    HitVector position;

    union { HitRequest request; struct { HitVector zero, jitter; } particles; } scratch;
    int count, i;
    char **entry;
    qcopy(&position,source);
    if (D_L00_00262570[D_00139568[0x17]].enabled) {
        func_0032C700(object + 0x10, 1, 0x28, 0x14, 0x1E, 0x28, 0x32, 1, 1.0f, 20.0f,
                      1, 1, 0, D_L00_001ADB2C);
        scratch.request.flags = 0x810000;
        scratch.request.active = 1;
        scratch.request.owner = object;
        scratch.request.scale = D_L00_00262570[D_00139568[0x17]].scale;
        qcopy(&scratch.request.direction,state);
        func_00282F20(&scratch.request.direction, &scratch.request.direction, 1.0f);
        scratch.request.direction.values[3] = 5627.9248046875f;
        scratch.request.enabled = 3;
        scratch.request.kind = 2;
        scratch.request.classId = *(unsigned short *)(object + 0xAA);
        count = func_00277F48(&position, 1, H->ptr[2212], &scratch.request, 2.0f);
        for (i = 0; i < count; i++)
            func_00334160(D_L00_001C3280[i], 0x42, *(int *)(object + 0xB8));
    } else {
        scratch.particles.zero.word=0;
        i = 7;
        do {
            int lifetime = func_002A7820(6, 16);
            int sign = func_002A77E0(2) ? -1 : 1;
            scratch.particles.jitter.values[0] = position.values[0] + func_002A78D8(0.0f, 0.5f);
            scratch.particles.jitter.values[1] = position.values[1] + func_002A78D8(0.0f, 0.5f);
            scratch.particles.jitter.values[2] = position.values[2] + func_002A78D8(0.0f, 0.5f);
            func_002C2210(&scratch.particles.jitter, lifetime, 0x4010FF10, 2, sign, 10.0f, 0.1f, &scratch.particles.zero, 0.0f, 1);
            func_002C2210(&scratch.particles.jitter, lifetime, (int)0xC0FFFFFF, 2, sign, 2.0f, 0.1f, &scratch.particles.zero, 0.0f, 1);
        } while (--i >= 0);
    }
}
