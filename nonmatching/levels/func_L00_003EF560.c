/* Bounded manual reconstruction, 2026-10-25; not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * 1180/1180 bytes; us: 0/27 placements; us2: 0/27 placements; pal: absent from catalogue.
 * Complete six-color aggregates and all 9/10/50 emission loops are preserved. Only local aggregate
 * alignment is 16 bytes; each color aggregate remains 24 bytes. Frame 0xf0 differs from retail
 * 0x110; floating constant lifetimes and outgoing-call storage remain unresolved.
 * Reopen with independent evidence for original floating constant and emitter-call local lifetimes.
 * Do not invent stack padding.
 * Prior complete variants and diagnostic dumps are preserved privately.
 * No candidate or linked-build credit is claimed.
 * 26 October 2026 (M14): 1180/1180 bytes, 90 differing lines (from 228). func_002BCB00 takes a
 * ninth int on the stack (retail sw zero, 0(sp)); the 1/60 rate local, an object+0xC0 base local
 * used outside loop 1, the plain struct copy and taking the colour slot pointers right after each
 * pick. Left: retail lq/sq copy at fixed sp offsets, a long-lived &velocity register (fp) used in
 * loop 2 and the spill of base (frame 0x110 vs 0x100).
 */
#include "common.h"

typedef int BurstWord128 __attribute__((mode(TI)));
typedef union { BurstWord128 word; float f[4]; } BurstVector;
typedef struct { unsigned int values[6]; } BurstColors;
extern BurstVector D_L00_001B8DC0 __attribute__((nosda));
extern BurstColors D_L00_001B0840 __attribute__((nosda));
extern BurstColors D_L00_001B0858 __attribute__((nosda));
extern unsigned char D_L00_0029AEF0[] __attribute__((nosda));
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DF0(void *);
extern float func_002A7878(float, float);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282FB8(void *, void *, float);
extern void func_00283098(void *, void *, void *);
extern int func_002A7820(int, int);
extern char *func_00308600(void *, void *, int, int, int);
extern float func_002A7940(void);
extern void func_002AF000(float *, float, float, float);
extern void func_00282C88(BurstWord128 *);
extern int func_002A77E0(int);
extern char *func_002BBCB0(void *, void *, unsigned int, unsigned int, int, int, int, int, float, float);
extern char *func_00312B70(void *, void *, int, int);
extern int func_002AAFA0(unsigned int, int);
extern char *func_002BCB00(void *, void *, int, int, int, int, int, int, int, float);

void func_L00_003EF560(char *object, BurstVector *position) {
    BurstVector delta, velocity, random;
    /* Both 24-byte local copies begin on observed 16-byte stack boundaries. */
    BurstColors colorsA __attribute__((aligned(16)));
    BurstColors colorsB __attribute__((aligned(16)));
    char *base;
    float distance, pitch, yaw, speed, rate;
    int i, a, b, lifetimeA, lifetimeB;
    int colorA, colorB;
    unsigned int *pa, *pb;
    rate = 0.016666668f;
    base = object + 0xC0;
    func_00282CF0(&delta, &D_L00_001B8DC0, position);
    distance = func_00282DF0(&delta);
    random.word = 0;
    random.f[0] = func_002A7878(-1.0f, 1.0f);
    random.f[1] = func_002A7878(-1.0f, 1.0f);
    random.f[2] = func_002A7878(-1.0f, 1.0f);
    delta.f[2] += distance * 0.5f;
    velocity = random;
    func_00282F20(&velocity, &velocity, distance * 0.0033333336468786f);
    func_00282F20(&delta, &delta, (distance + distance) * rate);
    func_00282CC0(&velocity, &velocity, &delta);
    func_00282FB8(&velocity, &velocity, 0.1666666716337204f);
    func_00283098(&velocity, &velocity, base);
    lifetimeA = func_002A7820(60, 90);
    func_00308600(position, &velocity, lifetimeA, 0, 0);
    i = 8;
    do {
        i--;
        pitch = func_002A7878(0.4363323450088501f, 0.7853982448577881f);
        yaw = func_002A7940();
        speed = func_002A7878(13.0f, 20.0f);
        func_002AF000(random.f, speed * 0.016666668f, yaw, pitch);
        func_00283098(&random, &random, object + 0xC0);
        lifetimeA = func_002A7820(60, 90);
        func_00308600(position, &random, lifetimeA, 1, 0);
    } while (i >= 0);
    func_00282C88(&velocity.word);
    i = 9;
    do {
        i--;
        speed = func_002A7878(8.0f, 10.0f);
        colorsA = D_L00_001B0840;
        colorsB = D_L00_001B0858;
        pa = &colorsA.values[func_002A77E0(6)];
        pb = &colorsB.values[func_002A77E0(6)];
        lifetimeA = func_002A7820(20, 40);
        lifetimeB = func_002A7820(50, 70);
        func_002BBCB0(position, &velocity, *pa, *pb, lifetimeA, lifetimeB, 0, 0,
                     600000.0f, speed * 0.016666668f * 1.5f);
    } while (i >= 0);
    *(float *)(D_L00_0029AEF0 + 0x20) = 40.0f;
    *(float *)(D_L00_0029AEF0 + 0x24) = 40.0f;
    *(float *)(D_L00_0029AEF0 + 0x28) = 40.0f;
    func_00312B70(D_L00_0029AEF0, position, 0, 0);
    i = 49;
    do {
        i--;
        pitch = func_002A7878(0.13962635397911072f, 0.6108652949333191f);
        yaw = func_002A7940();
        speed = func_002A7878(16.0f, 30.0f);
        func_002AF000(random.f, speed * 0.016666668f, yaw, pitch);
        colorA = func_002AAFA0(0x4F007FFF, 0);
        colorB = func_002AAFA0(0x1F00007F, 0);
        func_00283098(&random, &random, base);
        lifetimeA = func_002A7820(60, 120);
        func_002BCB00(position, &random, colorA, colorB, lifetimeA - 10, 1, -1, -1, 0, 40000.0f);
    } while (i >= 0);
}
