/* Nonmatching C: Copy the camera frame, measure the selected path segments and initialize the path direction flag.
 * Tested profile: -O2 -G0 -ffunction-sections.
 * Measured US size: 588 bytes; retail: 588 bytes.
 * Placement checks: US, US2 and PAL: 0/3 each.
 * Remaining: The first placed instruction difference is at +0x8 in global-pointer loading and saved-register allocation.
 * Reopen with independent settings/source-pointer lifetime evidence; retain all five complete 16-byte transfers and the variable-length path records.
 */
#include "common.h"

typedef int Quad __attribute__((mode(TI)));

typedef struct { int count; int reserved[3]; float point[0][4]; } CameraPath;
extern char *D_L13_001B22C4;
extern char *D_L13_001B9914;
extern CameraPath *D_L13_001FE580[];
extern float D_00189EA0[4];
extern float func_00282E48(void *, void *);
extern int func_L00_00341FA8(void *, void *, void *, int *, float *, int, float, float, float);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DF0(void *);
extern void func_00282F20(void *, void *, float);
extern float func_00282DB0(void *, void *);
extern void func_L13_004388C8(char *);

void func_L13_00439820(char *camera) {
    float projected[4] __attribute__((aligned(16)));
    float tangent[4] __attribute__((aligned(16)));
    float difference[4] __attribute__((aligned(16)));
    int segment;
    float fraction;
    char *source;
    char *settings = *(char **)(D_L13_001B22C4 + *(short *)(camera + 0x84) * 32 + 0x1C);
    CameraPath *path;
    int i;
    int next;
    source = D_L13_001B9914;
    qcopy(camera + 0x30, source + 0x30);
    qcopy(camera, source);
    qcopy(camera + 0x10, source + 0x10);
    qcopy(camera + 0x20, source + 0x20);
    qcopy(camera + 0x40, camera);
    if (*(int *)(settings + 0x20) >= 0) {
        path = D_L13_001FE580[*(int *)(settings + 0x20)];
        for (i = 0; i < path->count; i++) {
            next = (i + 1) % path->count;
            path->point[i][3] = func_00282E48(path->point[i], path->point[next]);
        }
    }
    *(short *)(settings + 0x36) = 0;
    if (*(int *)(settings + 0x30) == 3) {
        path = D_L13_001FE580[*(int *)(settings + 0x20)];
        segment = 0;
        fraction = 0.0f;
        if (func_L00_00341FA8(path, D_00189EA0, projected, &segment, &fraction, 0, 20.0f, 1.0f, 0.0f)) {
            next = segment + 1;
            if (next >= path->count) next = path->count - 1;
            func_00282CF0(tangent, path->point[next], path->point[segment]);
            if (func_00282DF0(tangent) != 0.0f && next != segment) {
                func_00282F20(tangent, tangent, 1.0f);
                func_00282CF0(difference, camera + 0x30, D_00189EA0);
                if (func_00282DB0(difference, tangent) > 0.0f)
                    *(short *)(settings + 0x36) = 1;
            }
        }
    }
    func_L13_004388C8(camera);
}
