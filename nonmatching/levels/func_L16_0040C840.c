/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * Reported final C / retail: 1352 / 1348 bytes; size equality is not a match.
 * us: 0/1 placements; 1352/1348 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: Frame 0x90 versus retail 0x80, extra saved GPR; x random lower bound is 0.5, verified in f21. Preserve dispatch flags64 and both stack words on L13_00412748.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Manual reconstruction, 2026-10-23: NOT MATCHED. US 1352/1348 bytes,
 * 0/1 placements; profile: -O2 -ffunction-sections G8 qcopy/qcopy-barrier/zero-ti-por.
 * Frame 0x90 versus retail 0x80, extra saved GPR; x random lower bound is 0.5, verified in f21. Preserve dispatch flags64 and both stack words on L13_00412748.
 * Historical screening notes below are preserved; the current measured
 * residual replaces any earlier claim that lq/sq/por cannot be emitted. */
#include "common.h"
/* Assembly interfaces below preserve their observed argument banks. Ignored
 * returns are unqualified; only the pointer, float and flag results are used. */
extern void func_L16_0040CD88(u8 *), func_L16_0040CF98(u8 *), func_L16_0040D258(u8 *);
extern int func_002A77E0(int), func_002A7820(int, int), func_00282978(short *);
extern void func_002A7750(void *, u8, int), func_002A7470(void *, int, int, int);
typedef struct {
    u8 reserved_00[0x18];
    u8 enabled, count, kind;
    u8 reserved_1b[0x65];
    u8 payload[1];
} Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext;
typedef unsigned long Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchFlags;
extern Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchFlags func_002B1C20(
    void *, Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *);
extern void func_002A7A00(void *, float, float), func_00282CC0(void *, void *, void *);
extern float func_00282C48(float), func_002A7878(float, float), func_002A78D8(float, float);
extern u8 *func_00273730(void *, int, int, int, void *, void *, void *, int, float, float);
extern u8 *func_0029EFD0(int);
extern void func_002B37E8(void *, void *), func_002AB650(void *), func_00310C88(void *);
extern float func_002A89A8(void *, int, float);
extern void func_L13_00412748(void *, int, int, int, int, int, int, int, float, int, int);
extern void func_002A6C58(void *, int, int), func_0029F338(void *);
extern int func_002AEB60(void *, float);
extern void func_0029FCC0(char *, int, char *), func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_L16_00413D10(void *, void *, void *, int, float);
extern int func_L09_00329028(char *, int);
extern float D_L16_001A8F20[4];
extern int D_L16_001B9B48, D_L16_001B9B28, D_L16_001B9B2C;
extern float D_L16_001B9B20, D_L16_001B9B40;

void func_L16_0040C840(u8 *moby)
{
    u8 *state = *(u8 **)(moby + 0x68);
    float velocity[4] __attribute__((aligned(16)));
    float aim[4] __attribute__((aligned(16)));
    Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchFlags flags;
    u8 *child;
    int i;
    func_L16_0040CD88(moby);
    switch (moby[0x95]) {
    case 1:
        if (*(int *)(state + 0x354) != 1 && *(int *)(state + 0x240) != 1)
            break;
        goto activate;
    case 0:
        *(short *)(state + 0x23e) = func_002A77E0(30);
        if (*(int *)(state + 0x240) == 1 && func_00282978((short *)(state + 0x23e)))
            goto activate;
        if (*(int *)(state + 0x244)) {
            func_002A7750(moby, 2, 1);
            *(int *)(state + 0x244) = 0;
            if (*(int *)(state + 0x238) < 300)
                *(int *)(state + 0x238) = func_002A7820(480, 600);
        }
        break;
    case 2:
        if (*(int *)(state + 0x240) == 1) break;
        if (*(int *)(state + 0x354) != 1) goto idle;
        break;
    case 3:
        flags = func_002B1C20(moby, (Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *)(state + 0x140));
        if (flags & 1) {
            for (i = 0; i < 4; i++) {
                func_002A7A00(velocity, 0.13333334f, 0.20000002f);
                velocity[2] = func_00282C48(velocity[2]);
                velocity[2] *= 1.5f;
                func_00282CC0(velocity, velocity, D_L16_001A8F20);
                child = func_00273730(moby, 1, *(short *)(moby + 0xaa), i,
                    moby + 0x10, moby + 0xf0, velocity, 255, 30.0f, 15.0f);
                *(void (**)(void *))(child + 0x64) = func_00310C88;
            }
            child = func_0029EFD0(0x10ce);
            func_002B37E8(child, moby);
            *(float *)(child + 0x18) = func_002A89A8(moby + 0x10, 0, 0.5f);
            func_002AB650(child);
            func_L13_00412748(moby + 0x10, 0, 45, 40, 40, 40, 45, 1, 1.0f, 1, 1);
            D_L16_001B9B48 = 90;
            D_L16_001B9B20 = 0.2f;
            D_L16_001B9B28 = 60;
            D_L16_001B9B40 = 0.1f;
            D_L16_001B9B2C = 0;
            velocity[0] = func_002A78D8(0.5f, 4.0f) * 0.016666668f;
            velocity[1] = func_002A78D8(0.0f, 4.0f) * 0.016666668f;
            velocity[2] = func_002A7878(7.0f, 9.0f) * 0.016666668f;
            velocity[2] = func_00282C48(velocity[2]);
            velocity[2] *= 3.0f;
            func_00282CC0(velocity, velocity, D_L16_001A8F20);
            child = func_00273730(moby, 3, 0xecb, 0, moby + 0x10,
                moby + 0xf0, velocity, 255, 180.0f, 25.0f);
            func_002AB650(child);
            func_002A6C58(moby, 0, 3);
            func_0029F338(moby);
            return;
        }
        if (!(flags & 2)) break;
        if (*(int *)(state + 0x240) != 1 && *(int *)(state + 0x354) != 1) {
idle:
            func_002A7750(moby, 2, 1);
            *(int *)(state + 0x238) = func_002A7820(580, 600);
            break;
        }
activate:
        if (moby[0x43] != 1) func_002A7470(moby, 1, 0, 10);
        func_002A7750(moby, 3, 2);
        break;
    }
    if (moby[0x20] == 3) {
        if (func_002AEB60(moby, 1.0f)) {
            func_0029FCC0((char *)moby, 2, (char *)velocity);
            func_00282CF0(aim, state + 0x1f0, velocity);
            func_00282F20(aim, aim, 0.416666687f);
            func_L16_00413D10(moby, aim, velocity, 0, 2.0f);
        }
        if (*(int *)(state + 0x24c) != -1)
            func_L09_00329028((char *)moby, *(int *)(state + 0x24c));
        if (*(unsigned short *)(moby + 0x96) > 180) {
            if (moby[0x43]) func_002A7470(moby, 0, 0, 10);
            func_002A7750(moby, 4, -1);
        }
    } else if (moby[0x20] == 4) {
        if (*(int *)(state + 0x24c) != -1)
            func_L09_00329028((char *)moby, *(int *)(state + 0x24c));
        if (*(unsigned short *)(moby + 0x96) > 180) {
            if (moby[0x43] != 1) func_002A7470(moby, 1, 0, 10);
            func_002A7750(moby, 3, -1);
        }
    }
    func_L16_0040CF98(moby);
    func_L16_0040D258(moby);
}
