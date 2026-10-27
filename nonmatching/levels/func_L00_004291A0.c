/* Retained complete C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections -fno-strength-reduce
 * 952/964 bytes; 0/11 placements in us and us2; pal has no catalogue entry.
 * Residual: The 0x90 frame agrees, but loop address lifetimes, modulo/call scheduling and saved-register allocation differ.
 * Reopen: Independent path/weight cursor lifetime evidence or a matched counterpart with the same measured path records.
 * Trial source markers and per-file flags are restored after checking.
 */

#include "common.h"
typedef int InitQuad __attribute__((mode(TI)));
extern u8 *D_L00_001B1844;
extern u8 D_L00_001BD2C0[];
extern u8 *D_L00_001FDA80[];
extern u8 D_L00_001B8C80[];
extern float func_00283248(float x, float y);
extern float func_00282E48(float *a, float *b);
extern float func_00283CE0(int x);
extern void func_00282C88(InitQuad *v);
extern int func_L00_002C42E0(int event, int value);

/* Partial records follow only the fields used by the two path walks.
 * Retail reserves eight weight/index slots and assumes at most eight accepted
 * entries; it does not add a bounds check to the path scan. */
typedef struct {
    u8 unknown00[0x20];
    int pathIndex;
    int secondPathIndex;
    u8 unknown28[0x10];
    u8 active;
    u8 unknown39;
    short duration;
    float speed;
    u8 unknown40[0xC];
    int eventGate;
    int initialized;
    u8 unknown54[0xC];
    float weights[8];
    int indices[8];
} PathConfig;
typedef struct {
    int first;
    int second;
    float distance;
    float secondDistance;
    int current;
    short node;
    short duration;
} MotionPrefix;

void func_L00_004291A0(u8 *object)
{
    PathConfig *data = *(PathConfig **)(D_L00_001B1844 + *(short *)(object + 0x84) * 32 + 0x1c);
    MotionPrefix *motion = (MotionPrefix *)(*(u8 **)(object + 0x70) + 0x40);
    u8 *pathState;
    u8 *path;
    float *weightBase = data->weights;
    int *indices = data->indices;
    int accepted = 0;
    int i;
    int *reset;
    float distance;
    float *entry;
    InitQuad *transform;
    data->active = 1;
    motion->first = 0;
    motion->second = 0;
    motion->distance = 0;
    motion->secondDistance = 0;
    motion->current = 0;
    motion->node = 0;
    motion->duration = data->duration;
    pathState = *(u8 **)(object + 0x70) + 0x58;
    reset = data->indices;
    for (i = 7; i >= 0; i--) {
        *(float *)((u8 *)reset - 0x20) = 0.0f;
        *reset++ = -1;
    }
    *(float *)(pathState + 0x30) = func_00283248(1.0f, *(float *)(D_L00_001BD2C0 + 0xb0)) * 2.0f;
    if (data->initialized == 0 && data->pathIndex >= 0) {
        float *weightCursor = weightBase;
        path = D_L00_001FDA80[data->pathIndex];
        for (i = 0; i < *(int *)path; i++) {
            int byteOffset = i * 16;
            entry = (float *)(path + 0x10 + byteOffset);
            if (entry[3] > 0.0f) {
                *weightCursor = entry[3];
                if (entry[3] > 180.0f)
                    *weightCursor = *(float *)(pathState + 0x30) * 57.2957763671875f;
                weightCursor++;
                indices[accepted++] = i;
            }
            distance = func_00282E48(entry, (float *)(path + 0x10 + ((i + 1) % *(int *)path) * 16));
            entry[3] = distance;
            if (i < *(int *)path - 1)
                motion->distance += distance;
        }
    }
    if (data->duration > 0)
        data->speed = (motion->distance / func_00283CE0(data->duration)) * 60.0f;
    if (data->secondPathIndex >= 0) {
        path = D_L00_001FDA80[data->secondPathIndex];
        for (i = 0; i < *(int *)path; i++) {
            entry = (float *)(path + 0x10 + i * 16);
            distance = func_00282E48(entry, (float *)(path + 0x10 + ((i + 1) % *(int *)path) * 16));
            entry[3] = distance;
            if (i < *(int *)path - 1)
                motion->secondDistance += distance;
        }
    }
    path = *(u8 **)(object + 0x70);
    *(float *)path = 0.03f;
    *(float *)(path + 4) = 0.2f;
    func_00282C88((InitQuad *)(path + 0x10));
    path = *(u8 **)(object + 0x70);
    *(float *)(path + 0x20) = 0.03f;
    *(float *)(path + 0x24) = 0.2f;
    func_00282C88((InitQuad *)(path + 0x30));
    transform = *(InitQuad **)(D_L00_001B8C80 + 0x194);
    qcopy(object + 0x30, transform + 3);
    qcopy(object, transform);
    qcopy(object + 0x10, transform + 1);
    qcopy(object + 0x20, transform + 2);
    if (data->eventGate == 0)
        func_L00_002C42E0(0x6f, 1);
    data->initialized = 1;
}
