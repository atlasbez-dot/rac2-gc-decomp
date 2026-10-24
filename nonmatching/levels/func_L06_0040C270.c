/* Nonmatching reconstruction, 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final check.py coverage: us 0/1; no linked build run.
 * Default and qcopy/barrier both 1732/1804.
 * Remaining: Aim/visibility loop register allocation, temporary-vector lifetimes and branch layout differ.
 * Reopen with typed aim-state/visibility data and a measured source-lifetime hypothesis.
 */
#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern char *D_0018C0B0;
extern char D_00189EA0[];
extern float D_0018A144;
extern short D_0018A168;
extern int D_L06_001A8FF0;
extern int D_L06_001A8FF4 __attribute__((sda));
extern float D_L06_001B0360 __attribute__((sda));
extern float D_L06_001B0364 __attribute__((sda));
extern char *D_L06_001FB760[];
extern char *D_L06_001BFC98;
extern char D_L06_001BFCA0[];
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

/* Choose an unobstructed aim target, temporarily ignoring penetrable objects. */
char *func_L06_0040C270(char *moby, float *position, float *yaw, float *pitch)
{
    float origin[4], offset[4], start[4];
    char *ignored[128];
    float targetPosition[4], projected[4], rayPosition[4], perpendicular[4];
    char *state = *(char **)(moby + 0x68);
    char *selected = 0;
    int ignoredCount = 0, index;
    float nearest = D_L06_001B0364;
    *(VectorBits *)origin = *(VectorBits *)position;
    func_00282D30(offset, D_0018C0B0 + 0xE0, 0.5f);
    func_00282CC0(start, D_0018C0B0 + 0x10, offset);
    if (func_002761F8(start, origin, 6, D_0018C0B0, 0))
        return 0;
    for (index = 0; D_L06_001FB760[index]; index++) {
        char *target = D_L06_001FB760[index];
        char *component;
        float targetYaw, targetPitch, yawDifference, distance;
        int close = 0;
        if (*(unsigned char *)(target + 0x20) == 0xFE ||
            *(unsigned char *)(target + 0x20) == 0xFD ||
            *(short *)(target + 0xAA) == 0xE7D || *(short *)(target + 0xAA) == 0xEB0)
            continue;
        *(VectorBits *)targetPosition = *(VectorBits *)(target + 0x10);
        component = func_002AB1F0(target);
        if (!component || *(unsigned char *)(component + 0xE) == 3)
            continue;
        func_00282D30(projected, target + 0xE0, *(float *)(component + 0x10));
        func_00282CC0(targetPosition, targetPosition, projected);
        if (!target || !*(char **)(target + 0x24) ||
            *(short *)(*(char **)(target + 0x24) + 0x46) != 5)
            continue;
        targetYaw = func_00283248(targetPosition[0] - origin[0], targetPosition[1] - origin[1]);
        targetPitch = func_00283248(func_00282E80(origin, targetPosition), targetPosition[2] - origin[2]);
        yawDifference = func_00283C80(*yaw, targetYaw);
        distance = func_00282E48(origin, targetPosition);
        if (!D_L06_001A8FF0 && !D_0018A168 && !D_L06_001A8FF4) {
            if (distance < 2.5f) {
                float heading = func_00283248(*(float *)(target + 0x10) - *(float *)D_00189EA0,
                                              *(float *)(target + 0x14) - *(float *)(D_00189EA0 + 4));
                if (func_00283C80(*(float *)(D_0018C0B0 + 0xF8), heading) < 1.0471977f &&
                    func_00282C48(origin[2] - targetPosition[2]) < 2.0f)
                    close = 1;
            }
        } else if (distance < 2.5f) {
            float along, side, length;
            func_00282CF0(rayPosition, target + 0x10, D_0018C0B0 + 0x10);
            along = func_00282DB0(rayPosition, D_0018C0B0 + 0xE0);
            if (func_00282C48(along) < 2.0f) {
                func_00282D30(perpendicular, D_0018C0B0 + 0xE0, along);
                func_00282CF0(rayPosition, rayPosition, perpendicular);
                side = func_00282DB0(rayPosition, D_0018C0B0 + 0xC0);
                length = func_00282DF0(rayPosition);
                if (length != 0.0f && 1.5707964f - func_002831B0(side / length) < 1.0471977f)
                    close = 1;
            }
        }
        if (close && !func_002761F8(origin, targetPosition, 6, D_0018C0B0, 0)) {
            selected = target;
            *pitch = -targetPitch;
            *yaw = targetYaw;
            break;
        }
        if ((distance <= nearest || target == *(char **)(state + 0x10)) && distance <= D_L06_001B0364) {
            float angle;
            func_002AF000(projected, distance, *yaw, *pitch + D_0018A144 * 0.5f);
            func_00282CC0(projected, projected, origin);
            angle = func_002831B0(func_00282E48(projected, targetPosition) / (distance + distance));
            angle += angle;
            if (angle > D_L06_001B0360 * 0.017453294f) {
                component = func_002AB1F0(target);
                if (component) {
                    float radius = func_00283CE0(*(unsigned char *)(component + 0xA)) * 0.125f;
                    float correction = func_002831B0(radius / distance);
                    if (radius < distance) {
                        angle -= correction;
                        if (angle < 0.0f)
                            angle = 0.0f;
                    }
                }
            }
            if (angle < D_L06_001B0360 * 0.017453294f) {
                int clear = 1, attempts = 0;
                *(VectorBits *)rayPosition = *(VectorBits *)origin;
                while (func_002761F8(rayPosition, targetPosition, 6, moby, 0)) {
                    char *hit;
                    if (++attempts > 6)
                        break;
                    hit = D_L06_001BFC98;
                    if (!hit) {
                        clear = 0;
                        break;
                    }
                    if (*(short *)(hit + 0xAA) != 0xE7D && *(short *)(hit + 0xAA) != 0xEB0) {
                        if (hit != target)
                            clear = 0;
                        break;
                    }
                    ignored[ignoredCount++] = hit;
                    *(int *)(hit + 0x98) = 0;
                    if (ignoredCount > 127)
                        break;
                    *(VectorBits *)rayPosition = *(VectorBits *)D_L06_001BFCA0;
                }
                if (clear) {
                    *pitch = -targetPitch;
                    if (yawDifference < 0.17453295f)
                        *yaw = targetYaw;
                    selected = target;
                    nearest = distance;
                    if (target == *(char **)(state + 0x10))
                        return target;
                }
            }
        }
    }
    for (index = 0; index < ignoredCount; index++) {
        char *target = ignored[index];
        *(int *)(target + 0x98) = *(int *)(*(char **)(target + 0x24) + 0x10);
    }
    return selected;
}
