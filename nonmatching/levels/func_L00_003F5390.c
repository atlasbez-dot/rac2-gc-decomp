/* Bounded manual reconstruction; not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * 700/708 bytes; us: 0/27 places; us2: 0/27 places; pal: absent from catalogue.
 * Collision request and particle vectors are alternative scratch roles; the explicit union
 * recovers the retail 0xc0 frame. Input banks and pointer/int returns were checked in retail,
 * including the third float input of002C2210. Outgoing call setup and hit-list loop scheduling
 * still differ. Reopen with a matching request/emitter allocation witness.
 * Historical screening note below predates this C attempt.
 */
/* from src/levels/shared/L00_003EE100.c: not written this wave. Retail 708 bytes, 27 place(s), first word at L00:003f5390.
 * Rule: MMI/LQ/SQ (op 0x1e).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x003f5390  addiu       $sp, $sp, -0xC0
 *   0x003f5394  sd          $s2, 0x70($sp)
 *   0x003f5398  sd          $s3, 0x78($sp)
 *   0x003f539c  daddu       $s2, $a0, $zero
 *   0x003f53a0  sd          $s0, 0x60($sp)
 *   0x003f53a4  addiu       $s3, $sp, 0x20
 * Kept as data for the maintainers. */

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
extern HitSettings D_00139568 __attribute__((nosda));
extern HitTuning D_L00_00262570[] __attribute__((nosda));
extern int D_L00_001ADB2C __attribute__((sda));
extern char *D_0018C0B0 __attribute__((nosda));
extern char *D_L00_001C3280[] __attribute__((nosda));
extern char *func_0032C700(void *, int, int, int, int, int, int, int, int, int, int, int, float, float);
extern void func_00282F20(void *, void *, float);
extern int func_00277F48(void *, int, void *, void *, float);
extern int func_00334160(char *, int, int);
extern int func_002A7820(int, int);
extern int func_002A77E0(int);
extern float func_002A78D8(float, float);
extern char *func_002C2210(void *, int, int, int, int, void *, int, float, float, float);

void func_L00_003F5390(char *object, HitVector *source) {
    char *state = *(char **)(object + 0x68);
    HitVector position;
    /* The collision request and the particle vectors are alternative scratch data. */
    union { HitRequest request; struct { HitVector zero, jitter; } particles; } scratch;
    int count, i, lifetime, sign;
    char **entry;
    position.word = source->word;
    if (D_L00_00262570[D_00139568.index].enabled) {
        func_0032C700(object + 0x10, 1, 0x28, 0x14, 0x1E, 0x28, 0x32, 1,
                      1, 1, 0, D_L00_001ADB2C, 1.0f, 20.0f);
        scratch.request.flags = 0x810000;
        scratch.request.active = 1;
        scratch.request.owner = object;
        scratch.request.scale = D_L00_00262570[D_00139568.index].scale;
        scratch.request.direction.word = *(HitWord128 *)state;
        func_00282F20(&scratch.request.direction, &scratch.request.direction, 1.0f);
        scratch.request.direction.values[3] = 5627.9248046875f;
        scratch.request.enabled = 3;
        scratch.request.kind = 2;
        scratch.request.classId = *(unsigned short *)(object + 0xAA);
        count = func_00277F48(&position, 1, D_0018C0B0, &scratch.request, 2.0f);
        if (count > 0) {
            entry = D_L00_001C3280;
            do {
                char *target = *entry;
                entry++;
                count--;
                func_00334160(target, 0x42, *(int *)(object + 0xB8));
            } while (count);
        }
    } else {
        scratch.particles.zero.word = 0;
        i = 7;
        do {
            lifetime = func_002A7820(6, 16);
            sign = func_002A77E0(2) ? -1 : 1;
            i--;
            scratch.particles.jitter.values[0] = position.values[0] + func_002A78D8(0.0f, 0.5f);
            scratch.particles.jitter.values[1] = position.values[1] + func_002A78D8(0.0f, 0.5f);
            scratch.particles.jitter.values[2] = position.values[2] + func_002A78D8(0.0f, 0.5f);
            func_002C2210(&scratch.particles.jitter, lifetime, 0x4010FF10, 2, sign, &scratch.particles.zero, 1, 10.0f, 0.1f, 0.0f);
            func_002C2210(&scratch.particles.jitter, lifetime, (int)0xC0FFFFFF, 2, sign, &scratch.particles.zero, 1, 2.0f, 0.1f, 0.0f);
        } while (i >= 0);
    }
}
