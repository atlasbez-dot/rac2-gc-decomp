/* Retained reconstruction, 23 October 2026. Game -O2 -G8 with
   -frac2-qcopy -frac2-qcopy-barrier: 1764/1804 bytes, 0/2 placements in
   each of USA v1.01, USA v2.00 and PAL. Default profile trials were 1740 and
   1732 bytes; grouped-copy trials remained 1764. Remaining differences include
   the initial interleaved vector transfer, folded adjacent tag predicates,
   saved-register/stack-slot allocation and float hazard/scheduling words.
   Source trials moved real initialization to its observed lifetime and retained
   an unsigned integer tag. Reopen with independently established original
   control-flow/record types or a qualified compiler model for the mixed copies.
   Early selected-target return intentionally skips temporary-obstacle restore,
   as the retail control flow does. No linked match is claimed. */
#include "include_asm.h"

typedef int Quad __attribute__((mode(TI)));
typedef struct { char pad[0x18]; char *object; int count; Quad position; char gap[16]; char normal[16]; } Hit;
typedef struct {
    char prefix[0x80]; float x; float y;
    char pad088[0x29c]; float pitch;
    char pad328[0x20]; short mode;
    char pad34a[0x1f46]; char *player;
} State;
extern State D_00189E20 __attribute__((nosda));
extern Hit D_L15_001BFC00;
extern char *D_L15_001FB6E0[];
extern int D_L15_001A8FF0 __attribute__((nosda));
extern int D_L15_001A8FF4 __attribute__((sda));
extern float D_L15_001AFEB0 __attribute__((sda));
extern float D_L15_001AFEB4 __attribute__((sda));
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_002761F8(void *, void *, int, void *, void *);
extern char *func_002AB1F0(void *);
extern float func_00283248(float, float);
extern float func_00282E80(void *, void *);
extern float func_00283C80(float, float);
extern float func_00282E48(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DB0(void *, void *);
extern float func_00282C48(float);
extern float func_00282DF0(void *);
extern float func_002831B0(float);
extern void func_002AF000(void *, float, float, float);
extern float func_00283CE0(int);

char *func_L15_003E2788(char *object, void *point, float *yaw, float *pitch)
{
    float origin[4];
    char offset[16];
    char start[16];
    char *ignored[128];
    float candidate[4];
    char aim[16];
    char trace[16];
    char projection[16];
    char *owner = object;
    char *state;
    char *selected;
    int ignoredCount;
    int index;
    char *target;
    float bestDistance;

    *(Quad *)origin = *(Quad *)point;
    bestDistance = D_L15_001AFEB4;
    state = *(char **)(object + 0x68);
    func_00282D30(offset, D_00189E20.player + 0xe0, 0.5f);
    selected = 0;
    func_00282CC0(start, D_00189E20.player + 0x10, offset);
    if (func_002761F8(start, origin, 6, D_00189E20.player, 0)) {
        *(Quad *)origin = D_L15_001BFC00.position;
        return 0;
    }
    ignoredCount = 0;
    index = 0;
    target = D_L15_001FB6E0[0];
    while (target) {
        char *info;
        unsigned int tag = (unsigned char)target[0x20];
        float heading, elevation, yawDifference, distance;
        int closeEnough;
        float sweepAngle;
        int clearPath;
        int traceCount;
        if (tag == 0xfe || tag == 0xfd ||
            *(short *)(target + 0xaa) == 0xe7d || *(short *)(target + 0xaa) == 0xeb0)
            goto next;
        *(Quad *)candidate = *(Quad *)(target + 0x10);
        info = func_002AB1F0(target);
        if (!info || (unsigned char)info[0xe] == 3)
            goto next;
        func_00282D30(aim, target + 0xe0, *(float *)(info + 0x10));
        func_00282CC0(candidate, candidate, aim);
        if (!target || !*(char **)(target + 0x24) ||
            *(short *)(*(char **)(target + 0x24) + 0x46) != 5)
            goto next;
        closeEnough = 0;
        heading = func_00283248(candidate[0] - origin[0], candidate[1] - origin[1]);
        elevation = func_00283248(func_00282E80(origin, candidate), candidate[2] - origin[2]);
        yawDifference = func_00283C80(*yaw, heading);
        distance = func_00282E48(origin, candidate);
        if (D_L15_001A8FF0 || D_00189E20.mode || D_L15_001A8FF4) {
            if (distance < 2.5f) {
                float forward;
                float length;
                func_00282CF0(trace, target + 0x10, D_00189E20.player + 0x10);
                forward = func_00282DB0(trace, D_00189E20.player + 0xe0);
                if (func_00282C48(forward) < 2.0f) {
                    func_00282D30(projection, D_00189E20.player + 0xe0, forward);
                    func_00282CF0(trace, trace, projection);
                    forward = func_00282DB0(trace, D_00189E20.player + 0xc0);
                    length = func_00282DF0(trace);
                    if (length != 0.0f && 1.5707963705062866f - func_002831B0(forward / length) < 1.047197699546814f)
                        closeEnough = 1;
                }
            }
        } else if (distance < 2.5f) {
            float direction = func_00283248(*(float *)(target + 0x10) - D_00189E20.x,
                                            *(float *)(target + 0x14) - D_00189E20.y);
            if (func_00283C80(*(float *)(D_00189E20.player + 0xf8), direction) < 1.047197699546814f &&
                func_00282C48(origin[2] - candidate[2]) < 2.0f)
                closeEnough = 1;
        }
        if (closeEnough && !func_002761F8(origin, candidate, 6, D_00189E20.player, 0)) {
            selected = target;
            *pitch = -elevation;
            *yaw = heading;
            break;
        }
        if (bestDistance < distance && target != *(char **)(state + 0x10))
            goto next;
        if (D_L15_001AFEB4 < distance)
            goto next;
        func_002AF000(aim, distance, *yaw, *pitch + D_00189E20.pitch * 0.5f);
        func_00282CC0(aim, aim, origin);
        sweepAngle = func_002831B0(func_00282E48(aim, candidate) / (distance + distance));
        sweepAngle += sweepAngle;
        if (D_L15_001AFEB0 * 0.01745329424738884f < sweepAngle) {
            info = func_002AB1F0(target);
            if (info) {
                float radius = func_00283CE0((unsigned char)info[0xa]) * 0.125f;
                float angle = func_002831B0(radius / distance);
                if (radius < distance) {
                    sweepAngle -= angle;
                    if (sweepAngle < 0.0f)
                        sweepAngle = 0.0f;
                }
            }
        }
        if (!(sweepAngle < D_L15_001AFEB0 * 0.01745329424738884f))
            goto next;
        clearPath = 1;
        *(Quad *)trace = *(Quad *)origin;
        traceCount = 0;
        while (func_002761F8(trace, candidate, 6, owner, 0)) {
            char *hit = D_L15_001BFC00.object;
            if (++traceCount > 6)
                break;
            if (!hit) {
                clearPath = 0;
                break;
            }
            if (*(short *)(hit + 0xaa) == 0xe7d || *(short *)(hit + 0xaa) == 0xeb0) {
                ignored[ignoredCount++] = hit;
                *(int *)(hit + 0x98) = 0;
                if (ignoredCount >= 128)
                    break;
                *(Quad *)trace = D_L15_001BFC00.position;
            } else {
                if (hit != target)
                    clearPath = 0;
                break;
            }
        }
        if (clearPath) {
            *pitch = -elevation;
            if (yawDifference < 0.174532949924469f)
                *yaw = heading;
            selected = target;
            bestDistance = distance;
            if (target == *(char **)(state + 0x10))
                return selected;
        }
next:
        target = D_L15_001FB6E0[++index];
    }
    if (ignoredCount > 0) {
        char **entry = ignored;
        do {
            char *hit = *entry++;
            *(int *)(hit + 0x98) = *(int *)(*(char **)(hit + 0x24) + 0x10);
        } while (--ignoredCount);
    }
    return selected;
}
