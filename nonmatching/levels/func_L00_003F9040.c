/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-gcse-unsplit-edges.
 * Reported final C / retail: 760 / 804 bytes; size equality is not a match.
 * us: 0/27 placements; 760/804 bytes.
 * us2: 0/27 placements; 760/804 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Complete760/804-byte active-slot particle updater; frame0xC0 agrees. Retail writes a local reference vector whose resulting components are not subsequently consumed; ordinary C eliminates the dead scalar updates. No fake volatile or artificial use was added.
 * Reopening condition: New ABI/CFG/allocator evidence or a measured compiler-model improvement; do not repeat tied forms.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained complete manual reconstruction; not an exact match.
 * Source profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-gcse-unsplit-edges.
 * Complete760/804-byte active-slot particle updater; frame0xC0 agrees. Retail writes a local reference vector whose resulting components are not subsequently consumed; ordinary C eliminates the dead scalar updates. No fake volatile or artificial use was added.
 */
#include "common.h"
typedef int SpawnVectorWord __attribute__((mode(TI)));
typedef struct EffectSpawnSlot {
    char prefix[0x14];
    char *owner;
    char tail[8];
} EffectSpawnSlot;
extern EffectSpawnSlot D_L00_002533B0[];
extern u32 D_L00_001B0A48[2] __attribute__((sda));
extern char D_L00_001B8DC0[];
extern void func_002AFFD8(char *, char *, int);
extern void func_00282D30(void *, void *, float);
extern void func_00282C88(SpawnVectorWord *);
extern float func_002A7878(float, float);
extern float func_002A78D8(float, float);
extern float func_002A7940(void);
extern void func_002AF000(float *, float, float, float);
extern int func_002A7820(int, int);
extern int func_002A77E0(int);
extern char *func_002BDCE8(float, float, float, float, char *, int, char *, unsigned int, int);
extern int func_001163B0(void);
extern int func_00283CF0(float);
extern float func_00283CE0(int);
extern void func_00282CF0(char *, char *, char *);
extern float func_00283248(float, float);
extern float func_00283B98(float, float);
extern void func_002A7A00(float *, float, float);
extern void *func_002C16C0(void *, void *, int, u32, int, int, float, float, float, float, float);
extern void *func_002C2210(void *, int, u32, int, int, void *, int, float, float, float);

/* Emit two randomized particles for each live slot. */

void func_L00_003F9040(void) {
    float reference[4];
    float position[4];
    float direction[4];
    u32 palette[2];
    char *particle;
    char *owner;
    float magnitude;
    float angle;
    float elevation;
    int kind;
    int i;
    int j;
    int index;
    for (i = 0; i < 30; i++) {
        if (D_L00_002533B0[i].owner != 0) {
            owner = D_L00_002533B0[i].owner;
            func_002AFFD8(owner + 0x10, (char *)reference, 1);
            func_00282D30(reference, reference, *(float *)(D_L00_002533B0[i].owner + 0xC) * 0.0007812f);
            owner = D_L00_002533B0[i].owner;
            reference[0] += *(float *)(owner + 0) * 0.0009765f;
            reference[1] += *(float *)(owner + 4) * 0.0009765f;
            reference[2] += *(float *)(owner + 8) * 0.0009765f;
            for (j = 1; j >= 0; j--) {
                func_00282C88((SpawnVectorWord *)direction);
                direction[2] = func_002A7878(0.016666668f, 0.025000002f);
                magnitude = func_002A7878(0.5f, 0.75f);
                magnitude = *(float *)(D_L00_002533B0[i].owner + 0xC) * magnitude * 0.0009765f;
                angle = func_002A7940();
                elevation = func_002A7940();
                func_002AF000(position, magnitude, angle, elevation);
                owner = D_L00_002533B0[i].owner;
                position[0] += *(float *)(owner + 0) * 0.0009765f;
                position[1] += *(float *)(owner + 4) * 0.0009765f;
                position[2] += *(float *)(owner + 8) * 0.0009765f;
                kind = func_002A7820(1, 5);
                particle = func_002BDCE8(0.0f, 1.0f, 1.01f,
                                        func_002A7878(0.25f, 1.0f) * 210000.0f,
                                        (char *)position, kind, (char *)direction, 0x5A182, 1);
                *(unsigned long *)palette = *(unsigned long *)D_L00_001B0A48;
                if (particle != 0) {
                    index = func_001163B0() % 2;
                    *(u16 *)(particle + 10) = 35;
                    particle[3] = palette[index];
                    particle[9] = func_00283CF0(4.0f) + 64;
                    *(float *)(particle + 0x3C) = func_00283CE0(5);
                    *(int *)(particle + 0x24) = 3;
                    particle[0x2A] = func_002A7820(64, 128);
                    particle[0x2B] = particle[10];
                }
            }
        }
    }
}
