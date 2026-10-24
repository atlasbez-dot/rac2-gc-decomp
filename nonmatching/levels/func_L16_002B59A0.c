/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 1156 / 1124 bytes; size equality is not a match.
 * us: 0/1 placements; 1156/1124 bytes.
 * us2: 0/1 placements; 1156/1124 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 32 excess bytes; address/register allocation differs. NaN-preserving explicit component clamps retained. Physics helper returns are bounded count/boolean GPR values, not assumed64-bit masks.
 * Reopening condition: New measured source/data-layout or allocator hypothesis; do not repeat retained flag/control-flow trials or use artificial aliases/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* 1156/1124 bytes with -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Three bounded trials; -fno-gcse identical size. Global address/register selection remain.
 * The three clamps preserve retail NaN behavior; a compact loop trial was discarded. */
#include "include_asm.h"
typedef int Quad __attribute__((mode(TI)));
extern unsigned char D_00189E20[];
extern int D_L16_001A8FF0 __attribute__((sda));
typedef struct CollisionResultView {
    int kind, unused;
    float normal[4], position[4], velocity[4];
} CollisionResultView;
extern CollisionResultView D_L16_001BFF58;
extern void func_00282C88(Quad *);
extern void func_L00_002D49F0(void);
extern float func_00282DB0(char *, char *);
extern void func_00283098(char *, char *, char *);
extern void func_L00_002D38A0(Quad *, Quad *, float);
extern void func_L00_002D36E0(float *, int, float, float, float);
extern void func_00282CC0(char *, char *, char *);
extern void func_00282CF0(char *, char *, char *);
extern int func_00277258(char *, int, char *, float);
extern int func_L00_002E0200(char *, int, char *, float, float);
extern int func_00278870(char *, float);
extern float func_00282DF0(char *);
extern void func_00282F20(char *, char *, float);
#define SH(off) (*(short *)(D_00189E20 + (off)))
#define IN(off) (*(int *)(D_00189E20 + (off)))
#define FL(off) (*(float *)(D_00189E20 + (off)))
#define BY(off) (D_00189E20[(off)])

/* Resolve up to eight collisions and measure the resulting player displacement. */
int func_L16_002B59A0(int mode) {
    struct { Quad original, offset; float delta[4]; } local;
    int i, collision;
    int facing;
    float dot, depth;
    if (SH(0x1F0)) return 1;
    local.original = *(Quad *)(D_00189E20 + 0x80);
    func_00282C88(&local.offset);
    if (SH(0x24FE)) { func_L00_002D49F0(); SH(0x24FE) = 0; }
    dot = func_00282DB0((char *)D_00189E20 + 0x20, (char *)D_00189E20 + 0x2C0);
    facing = dot > -0.92f;
    if (IN(0x229C) == 15) {
        func_00282C88(&local.offset);
        ((float *)&local.offset)[2] = 0.8f;
        func_00283098((char *)&local.offset, (char *)&local.offset, *(char **)(D_00189E20 + 0x2290) + 0xC0);
    } else if (IN(0x229C) != 17) {
        if (!BY(0x22C3) && !SH(0x218) && !facing) ((float *)&local.offset)[2] = FL(0x254);
        else if (BY(0x22B4) == 2) func_L00_002D38A0(&local.offset, &local.offset, 5.0f);
        else if (BY(0x22C3) == 1 || SH(0x218)) func_L00_002D36E0((float *)&local.offset, 0, 0.0f, 0.0f, 0.6f);
        else if (D_L16_001A8FF0) func_L00_002D38A0(&local.offset, &local.offset, 0.77f);
        else func_L00_002D36E0((float *)&local.offset, 0, 0.0f, 0.0f, FL(0x254));
    }
    func_00282CC0((char *)D_00189E20 + 0x80, (char *)D_00189E20 + 0x80, (char *)&local.offset);
    for (i = 0; i < 8; i++) {
        if (IN(0x229C) == 15) collision = func_00277258((char *)D_00189E20 + 0x80, 0x324, *(char **)(D_00189E20 + 0x2290), 0.45f);
        else {
            if (BY(0x22C3) || facing) collision = func_00277258((char *)D_00189E20 + 0x80, 0x324, *(char **)(D_00189E20 + 0x2290), FL(0x264));
            else {
                depth = FL(0x250) - FL(0x254);
                if (depth < 0.05f) depth = 0.05f;
                collision = func_L00_002E0200((char *)D_00189E20 + 0x80, 0x324, *(char **)(D_00189E20 + 0x2290), FL(0x264), depth);
            }
            if (!SH(0x1E6)) collision |= func_00278870((char *)D_00189E20 + 0x80, FL(0x264));
        }
        if (!collision) break;
        *(Quad *)(D_00189E20 + 0x80) = *(Quad *)D_L16_001BFF58.position;
        *(Quad *)(D_00189E20 + 0x230) = *(Quad *)D_L16_001BFF58.velocity;
        *(Quad *)(D_00189E20 + 0x240) = *(Quad *)D_L16_001BFF58.normal;
        IN(0x26C) = D_L16_001BFF58.kind;
        BY(0x287) = 1;
    }
    func_00282CF0((char *)D_00189E20 + 0x80, (char *)D_00189E20 + 0x80, (char *)&local.offset);
    func_00282CF0((char *)local.delta, (char *)D_00189E20 + 0x80, (char *)&local.original);
    if (func_00282DF0((char *)local.delta) <= FL(0x264) * 1.5f) return 1;
    if (mode != 15) return -1;
    if (local.delta[0] <= 512.0f) {
        if (local.delta[0] < -512.0f) local.delta[0] = -512.0f;
    } else local.delta[0] = 512.0f;
    if (local.delta[1] <= 512.0f) {
        if (local.delta[1] < -512.0f) local.delta[1] = -512.0f;
    } else local.delta[1] = 512.0f;
    if (local.delta[2] <= 512.0f) {
        if (local.delta[2] < -512.0f) local.delta[2] = -512.0f;
    } else local.delta[2] = 512.0f;
    func_00282F20((char *)local.delta, (char *)local.delta, FL(0x264));
    func_00282CC0((char *)D_00189E20 + 0x80, (char *)&local.original, (char *)local.delta);
    return -1;
}
