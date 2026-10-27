/* Nonmatching C: Sample and interpolate the camera paths, smooth the camera position and construct its viewing frame.
 * Tested profile: -O2 -G0 -ffunction-sections.
 * Measured US size: 2516 bytes; retail: 2704 bytes.
 * Placement checks: US, US2 and PAL: 0/3 each.
 * Remaining: Cursor and vector lifetimes, common address expressions, spills and floating-point allocation differ.
 * Reopen with independent cursor and sampled-vector lifetime evidence; retain all seven complete vectors and the full projection/sample argument banks.
 */
#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;

typedef struct { int count; int reserved[3]; Vector point[0]; } CameraPath;
typedef struct { int index; float distance; } PathCursor;
extern CameraPath *D_0018A450;
extern int D_0018A454;
extern float D_0018A458;
extern int D_001A79F0;
extern float D_00189EA0[4];
extern float D_L13_001B9940[4];
extern char *D_L13_001B22C4;
extern char *D_L13_001B2140;
extern CameraPath *D_L13_001FE580[];
extern int func_L00_00341820(void *, void *, int *, float *, int, float);
extern int func_L00_00341FA8(void *, void *, void *, int *, float *, int, float, float, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_002702C8(float *, float, float, float, float, float);
extern int func_00283CF0(float);
extern float func_00282C48(float);
extern float func_00282DF0(void *);
extern void func_00282D30(void *, void *, float);
extern float func_00282DB0(void *, void *);
extern float func_002831B0(float);

extern float func_002703B0(char *, float, float, float, float, float);
extern void func_00282DD8(void *, void *, void *);
extern void func_002ACEC0(void *, void *, void *, float);

void func_L13_00438D88(char *camera) {
    Vector desired;
    Vector interpolated;
    Vector eye_offset;
    Vector direction;
    Vector point;
    Vector tangent;
    Vector sampled;
    PathCursor cursor;
    PathCursor advance;
    PathCursor selection;
    char *private = *(char **)(camera + 0x70);
    char *settings = *(char **)(D_L13_001B22C4 + *(short *)(camera + 0x84) * 32 + 0x1C);
    CameraPath *path = D_L13_001FE580[*(int *)(settings + 0x20)];
    CameraPath *markers;
    CameraPath *route;
    CameraPath *positions;
    float look_ahead = *(float *)settings;
    float angular_rate = 0.01f;
    float rate;
    float length;
    float progress;
    float distance;
    float duration;
    float angle;
    int mode = *(int *)(settings + 0x30);
    int i;
    int j;
    int previous;
    int begin;
    int end;
    int steps;
    cursor.index = D_0018A454;
    cursor.distance = D_0018A458;
    if (mode == 0) {
        *(int *)(private + 0x150) = cursor.index;
        *(float *)(private + 0x154) = cursor.distance;
        func_L00_00341820(path, &desired, (int *)(private + 0x150), (float *)(private + 0x154), 0, 1.0f);
        qcopy(private + 0x80, &desired);
        progress = cursor.distance / D_0018A450->point[cursor.index].f[3];
        length = path->point[cursor.index].f[3];
        func_00282CF0(&tangent, path->point + cursor.index + 1, path->point + cursor.index);
        func_00282F20(&point, &tangent, length * progress);
        func_00282CC0(&interpolated, path->point + cursor.index, &point);
        *(float *)(camera + 0x30) = func_002702C8((float *)private, *(float *)(camera + 0x30), interpolated.f[0], 0.01f, 0.175f, 0.0f);
        *(float *)(camera + 0x34) = func_002702C8((float *)(private + 4), *(float *)(camera + 0x34), interpolated.f[1], 0.01f, 0.175f, 0.0f);
        *(float *)(camera + 0x38) = func_002702C8((float *)(private + 8), *(float *)(camera + 0x38), interpolated.f[2], 0.01f, 0.175f, 0.0f);
    } else if (mode == 2) {
        markers = D_L13_001FE580[*(int *)(settings + 0x2C)];
        route = *(CameraPath **)(D_L13_001B2140 + *(int *)(settings + 0x24) * 32 + 0x10);
        positions = D_L13_001FE580[*(int *)(settings + 0x28)];
        previous = markers->count - 1;
        for (i = 0; i < markers->count; i++) {
            begin = func_00283CF0(markers->point[previous].f[3]);
            end = func_00283CF0(markers->point[i].f[3]);
            if (end < begin) {
                if (D_0018A454 >= begin || D_0018A454 < end) break;
            } else if (D_0018A454 >= begin && D_0018A454 < end) break;
            previous = i;
        }
        *(int *)(private + 0x160) = i;
        duration = markers->point[i].f[1];
        previous = (i + markers->count - 1) % markers->count;
        look_ahead = markers->point[previous].f[0];
        if (look_ahead == 0.0f) look_ahead = *(float *)settings;
        begin = func_00283CF0(markers->point[previous].f[3]);
        steps = D_0018A454 - begin;
        if (steps < 0) steps += route->count;
        distance = 0.0f;
        for (j = 0; j < steps; j++)
            distance += route->point[(begin + j) % route->count].f[3];
        distance += D_0018A458;
        selection.index = func_00283CF0(positions->point[previous].f[3]);
        selection.distance = 0.0f;
        func_L00_00341820(path, &point, &selection.index, &selection.distance, 1,
                         positions->point[i].f[1] * (distance / duration));
        rate = positions->point[previous].f[0];
        angular_rate = rate > 0.0f ? rate * 0.01f : 0.01f;
        if (func_00282C48(*(float *)(private + 0x10) - angular_rate) < 0.00015f)
            *(float *)(private + 0x10) = angular_rate;
        else if (*(float *)(private + 0x10) < angular_rate)
            *(float *)(private + 0x10) += 0.00015f;
        else
            *(float *)(private + 0x10) -= 0.00015f;
        *(float *)(camera + 0x30) = func_002702C8((float *)private, *(float *)(camera + 0x30), point.f[0], *(float *)(private + 0x10), 0.175f, 0.0f);
        *(float *)(camera + 0x34) = func_002702C8((float *)(private + 4), *(float *)(camera + 0x34), point.f[1], *(float *)(private + 0x10), 0.175f, 0.0f);
        *(float *)(camera + 0x38) = func_002702C8((float *)(private + 8), *(float *)(camera + 0x38), point.f[2], *(float *)(private + 0x10), 0.175f, 0.0f);
    } else {
        if (*(int *)(settings + 0x24) < 0) {
            func_L00_00341FA8(path, D_00189EA0, &sampled, &cursor.index, &cursor.distance, 0, 20.0f, 1.0f, 0.0f);
            distance = *(short *)(settings + 0x36) == 1 ? -(*(float *)(settings + 0x38) * 4.0f) : *(float *)(settings + 0x38);
            func_L00_00341820(path, &sampled, &cursor.index, &cursor.distance, 1, distance);
            qcopy(&desired, &sampled);
        } else {
            advance.index = D_0018A454;
            advance.distance = D_0018A458;
            func_L00_00341820(D_0018A450, &sampled, &advance.index, &advance.distance, 1, *(float *)(settings + 0x38));
            func_L00_00341FA8(path, &sampled, &desired, &cursor.index, &cursor.distance, 0, 20.0f, 1.0f, 0.0f);
        }
        *(float *)(camera + 0x30) = func_002702C8((float *)private, *(float *)(camera + 0x30), desired.f[0], 0.01f, 0.175f, 0.0f);
        *(float *)(camera + 0x34) = func_002702C8((float *)(private + 4), *(float *)(camera + 0x34), desired.f[1], 0.01f, 0.175f, 0.0f);
        *(float *)(camera + 0x38) = func_002702C8((float *)(private + 8), *(float *)(camera + 0x38), desired.f[2], 0.01f, 0.175f, 0.0f);
    }
    if (*(int *)(settings + 0x24) < 0) {
        func_L00_00341FA8(path, D_00189EA0, &point, &cursor.index, &cursor.distance, 0, 20.0f, 1.0f, 0.0f);
        func_L00_00341820(path, &tangent, &cursor.index, &cursor.distance,
                         !(D_001A79F0 == 14 && mode == 0), look_ahead);
        func_00282CF0(&tangent, &tangent, &point);
        func_00282CC0(&point, D_00189EA0, &tangent);
    } else {
        advance.index = D_0018A454;
        advance.distance = D_0018A458;
        func_L00_00341820(D_0018A450, &point, &advance.index, &advance.distance, 1, look_ahead);
    }
    func_00282F20(&eye_offset, D_L13_001B9940, *(float *)(private + 0xCC));
    func_00282CC0(&sampled, &eye_offset, &point);
    func_00282CF0(&direction, &sampled, camera + 0x30);
    length = func_00282DF0(&direction);
    angle = 0.0f;
    if (length != 0.0f) {
        func_00282D30(&direction, &direction, 1.0f / length);
        angle = 1.5707964f - func_002831B0(func_00282DB0(&direction, camera));
    }
    if (func_00282C48(*(float *)(private + 0x50) - angular_rate) < 0.00015f)
        *(float *)(private + 0x50) = angular_rate;
    else if (*(float *)(private + 0x50) < angular_rate)
        *(float *)(private + 0x50) += 0.00015f;
    else
        *(float *)(private + 0x50) -= 0.00015f;
    angle = func_002703B0(private + 0x64, 0.0f, angle, *(float *)(private + 0x50), 0.175f, 0.0f);
    func_00282DD8(&tangent, &direction, camera + 0x40);
    func_002ACEC0(camera, camera + 0x40, &tangent, angle);
    func_00282F20(camera + 0x40, camera, 1.0f);
    func_00282F20(camera, camera, 1.0f);
    func_00282DD8(camera + 0x10, camera, D_L13_001B9940);
    func_00282F20(camera + 0x10, camera + 0x10, 1.0f);
    func_00282DD8(camera + 0x20, camera + 0x10, camera);
}
