/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 1440 / 1432 bytes; size equality is not a match.
 * us: 0/1 placements; 1440/1432 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: 8 excess bytes and extra saved register/frame16 bytes. Absolute/GP mixed global accesses and damage-phase control-flow selection remain.
 * Reopening condition: New measured source/data-layout or allocator hypothesis; do not repeat retained flag/control-flow trials or use artificial aliases/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* 1440/1432 bytes after4 trials. GPR allocation, mixed absolute/GP globals remain. All stack-tail explosion arguments came from retail stores.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. */
#include "include_asm.h"
typedef int Quad __attribute__((mode(TI)));
extern char *D_L23_001B1484 __attribute__((sda));
extern int D_L23_001B1468 __attribute__((sda));
extern int D_L23_001B1434 __attribute__((sda));
extern char *D_L23_001B13D0 __attribute__((sda));
extern float D_L23_001B16D0 __attribute__((sda));
extern int D_L23_001B3720;
extern unsigned char D_001A7AFD;
extern int func_002F5D10(void);
extern void func_002A6C58(char *, int, int);
extern void func_L23_0041D9B0(void);
extern void func_L00_003294F0(unsigned char *, int);
extern void func_0029F338(void *);
extern void func_0032C700(void *, int, int, int, int, int, int, int, float, float, int, int, int, int);
extern int func_002E5CF8(int, int, char *);
extern void func_0029FC20(char *, int, char *);
extern void func_00282D30(char *, char *, float);
extern float func_002A7878(float, float);
extern void func_00282CC0(char *, char *, char *);
extern char *func_00273730(char *, int, int, int, char *, char *, float *, int, float, float);
extern void func_00310C88(void);
extern int func_002A77E0(int);

/* Move through the encounter's damage phases, detaching pieces and spawning debris. */
void func_L23_0041D398(char *object) {
    struct { Quad velocity, matrix[4], random; } local;
    char *state = *(char **)(D_L23_001B1484 + 0x68);
    char **parts;
    char *old, *replacement, *particle;
    int i, index;
    unsigned short timer;
    float scale;
    if (!D_001A7AFD) {
        if ((unsigned short)*(short *)(object + 0x96) <= D_L23_001B1468 + 200 || func_002F5D10()) {
            if (!D_001A7AFD && (unsigned short)*(short *)(object + 0x96) > D_L23_001B1468 + 60) {
                if (!D_L23_001B13D0) return;
                state = *(char **)(D_L23_001B13D0 + 0x68);
                state[13] = 1;
                state[8] = 0;
                func_L00_003294F0((unsigned char *)D_L23_001B13D0, 1);
                D_L23_001B13D0 = 0;
                return;
            }
            goto update_parts;
        }
    } else if ((unsigned short)*(short *)(object + 0x96) <= D_L23_001B1468 + 60) goto update_parts;
    func_002A6C58(object, 0, 3);
    func_L23_0041D9B0();
    return;
update_parts:
    if (D_L23_001B1434) {
        parts = (char **)(state + 0x36C);
        for (i = 5; i < 10; i++, parts++) {
            if (!D_L23_001B3720) {
                func_0029F338(*parts);
                *parts = 0;
                *(unsigned short *)(object + 0x34) |= 0x41;
                func_0032C700(object + 16, 1, 135, 120, 120, 115, 125, 1, 6.5f, 20.0f, 1, 1, 1, 0);
                func_002E5CF8(12, 0, object);
            } else if (*parts) {
                index = 10 - D_L23_001B3720;
                func_0029FC20(object, i - 4, (char *)local.matrix);
                func_00282D30((char *)&local.velocity, (char *)&local.matrix[1], D_L23_001B16D0);
                scale = func_002A7878(0.0f, D_L23_001B16D0 * 0.5f);
                func_00282D30((char *)&local.random, object + 0xE0, scale);
                func_00282CC0((char *)&local.velocity, (char *)&local.velocity, (char *)&local.random);
                old = *parts;
                particle = func_00273730(old, 1, *(short *)(old + 0xAA), index, old + 16, old + 0xF0, (float *)&local.velocity, 255, 140.0f, 25.0f);
                if (particle) *(void (**)(void))(particle + 0x64) = func_00310C88;
            }
        }
        D_L23_001B3720--;
        return;
    }
    timer = *(unsigned short *)(object + 0x96);
    if ((D_L23_001B1468 << 1) / 3 < timer) {
        parts = (char **)(state + 0x358);
        func_0032C700(object + 16, 1, 45, 30, 40, 25, 85, 1, 4.5f, 20.0f, 1, 1, 1, 0);
        func_002E5CF8(11, 0, object);
        for (i = 4; i >= 0; i--, parts++) {
            replacement = parts[5];
            if (replacement && *parts) {
                old = *parts;
                *(Quad *)(replacement + 0xC0) = *(Quad *)(old + 0xC0);
                *(Quad *)(replacement + 0xD0) = *(Quad *)(old + 0xD0);
                *(Quad *)(replacement + 0xE0) = *(Quad *)(old + 0xE0);
                *(Quad *)(replacement + 0x10) = *(Quad *)(old + 0x10);
                *(unsigned short *)(replacement + 0x34) &= 0xFFF9;
                *(unsigned short *)(parts[5] + 0x34) |= 0x4000;
                *(unsigned short *)(parts[5] + 0x34) &= 0xFFBE;
                func_0029F338(*parts);
                *parts = 0;
            }
        }
        D_L23_001B1434 = 1;
        D_L23_001B3720 = 10;
        return;
    }
    if (D_L23_001B1468 / 3 < timer) {
        if (timer & 15) return;
    index = func_002A77E0(5);
    parts = (char **)(state + 0x358 + index * 4);
    old = *parts;
    scale = func_002A7878(4.0f, 12.0f);
    func_00282D30((char *)&local.velocity, old + 0xD0, scale);
    func_00282CC0((char *)&local.velocity, (char *)&local.velocity, *parts + 16);
    scale = func_002A7878(2.3f, 3.7f);
    func_0032C700(&local.velocity, index & 1, 20, 10, 14, 15, 25, 0, scale, 20.0f, 1, 1, 1, 0);
    func_002E5CF8(func_002A77E0(3) + 13, 0, object);
        return;
    }
    if (timer & 31) return;
    index = func_002A77E0(5);
    parts = (char **)(state + 0x358 + index * 4);
    old = *parts;
    scale = func_002A7878(4.0f, 12.0f);
    func_00282D30((char *)&local.velocity, old + 0xD0, scale);
    func_00282CC0((char *)&local.velocity, (char *)&local.velocity, *parts + 16);
    scale = func_002A7878(2.3f, 3.7f);
    func_0032C700(&local.velocity, index & 1, 20, 10, 14, 15, 25, 0, scale, 20.0f, 1, 1, 1, 0);
    func_002E5CF8(func_002A77E0(3) + 13, 0, object);
}
