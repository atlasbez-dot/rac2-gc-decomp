/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 840 / 840 bytes; size equality is not a match.
 * us: 0/1 placements.
 * us2: 0/1 placements.
 * pal: 0/1 placements.
 * Residual: Equal size; register allocation and absolute-read/GP-write of shared count differ. No manufactured aliases introduced.
 * Reopening condition: New measured source/data-layout or allocator hypothesis; do not repeat retained flag/control-flow trials or use artificial aliases/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* US trial: 840/840 bytes, 0/1 matching placements.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Remaining: register allocation and mixed absolute/GP addressing of the count.
 * -fno-gcse produced836 bytes. No aliases were introduced to force addressing. */
#include "include_asm.h"
typedef int Quad __attribute__((mode(TI)));
extern char *D_L23_001B1484 __attribute__((sda));
extern char D_00189E20[];
extern char D_L23_00259050[];
extern int D_L23_001B3738[3];
extern int D_L23_001B3744 __attribute__((sda));
extern float D_L23_001B1414 __attribute__((sda));
extern Quad D_L23_001C0AA0;
extern float func_00282E48(char *, char *);
extern int func_L23_0041D1F0(char *, int, int, int);
extern void func_002A7750(unsigned char *, unsigned char, int);
extern float func_L23_0041E220(char *);
extern int func_002A77E0(int);
extern int func_L23_0041D0A0(char *, int, float);
extern void func_00282D30(char *, char *, float);
extern void func_00282CC0(char *, char *, char *);
extern void func_L23_00418650(char *, float);
extern int func_002761F8(void *, void *, int, void *, int);
extern void func_L23_0041C7D8(void *, int);

/* Refresh the active effect pools, then choose a new free spawn position. */
void func_L23_0041CD58(char *object) {
    struct { Quad position, offset; } local;
    char *state = *(char **)(D_L23_001B1484 + 0x68);
    int group = 0;
    int remaining;
    int next;
    int oldCount;
    int oldTotal;
    int spawnGroup;
    char **slot;
    int *count;
    float alpha;
    char *axis;
    float scale;
    do {
        count = &D_L23_001B3738[group];
        slot = (char **)(D_L23_00259050 + group * 240);
        next = group + 1;
        remaining = 49;
        do {
            if (*slot && *(float *)(state + 0x20) > 0.0f &&
                (*(char **)(D_00189E20 + 0x2290))[0x43] != 6 && func_00282E48(*slot + 0x10, D_00189E20 + 0x80) < 12.0f) {
                if (func_L23_0041D1F0(object, (int)*slot, group, 1)) {
                    if ((*slot)[0x20] == 0) {
                        func_002A7750((unsigned char *)*slot, 16, 0);
                        (*slot)[0x23] = 127;
                    }
                    oldCount = *count;
                    oldTotal = D_L23_001B3744;
                    *slot = 0;
                    *count = oldCount - 1;
                    D_L23_001B3744 = oldTotal - 1;
                } else {
                    alpha = func_L23_0041E220(*slot) * 0.083333336f;
                    if (alpha > 1.0f) alpha = 1.0f;
                    else if (alpha < 0.1f) alpha = 0.1f;
                    (*slot)[0x23] = (int)(alpha * 127.0f);
                }
            }
            remaining--;
            slot++;
        } while (remaining >= 0);
        group = next;
    } while (group < 3);
    if (!func_002A77E0(30) && D_L23_001B3744 < 12) {
        func_L23_0041D0A0((char *)&local.position, 1, 0.0f);
        spawnGroup = 0;
        do {
            slot = (char **)(D_L23_00259050 + spawnGroup * 240);
            next = spawnGroup + 1;
            remaining = 49;
            do {
                if (*slot && func_00282E48(*slot + 16, (char *)&local.position) < 4.0f) {
                    axis = *slot + func_002A77E0(2) * 16 + 0xC0;
                    if (func_002A77E0(2)) scale = D_L23_001B1414;
                    else scale = -D_L23_001B1414;
                    func_00282D30((char *)&local.offset, axis, scale);
                    func_00282CC0((char *)&local.position, (char *)&local.position, (char *)&local.offset);
                    func_L23_00418650((char *)&local.position, 0.0f);
                }
                remaining--;
                slot++;
            } while (remaining >= 0);
            spawnGroup = next;
        } while (spawnGroup < 3);
        local.offset = local.position;
        func_L23_00418650((char *)&local.offset, 3.0f);
        if (func_002761F8(&local.offset, &local.position, 18, 0, 0))
            local.position = D_L23_001C0AA0;
        func_L23_0041C7D8(&local.position, 0);
    }
}
