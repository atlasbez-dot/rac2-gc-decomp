/* Retained complete C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * Compiled 1232 bytes; retail 1272 bytes.
 * us: 0/1 placements match (exit 1).
 * us2: 0/1 placements match (exit 1).
 * pal: canonical name absent; no match credit.
 * Remaining: Repeated path-target captures and state handoffs retain complete clobbering
 * sixteen-byte copies, both height queries and the 64-bit endpoint masks. Ordered mode reads
 * and later position-pointer scope preserve the observed state decisions, but switch
 * allocation, reloads and pointer scheduling remain different in the correct 0xB0 frame. The
 * two-formal func_L23_00418DC0 contract is retained; its incidental live A2 was not turned
 * into a fabricated third input. The projection helper retains its float return and the
 * displacement consumer takes a full quadword pointer. The first distance guard uses
 * !(secondDistance < distance), evaluates the distance call once and preserves unordered-to-
 * COPY behavior; an ordered <= is not equivalent.
 * Reopen: Independent branch-local path/source lifetime evidence or a qualified compiler
 * explanation for the remaining switch/PRE allocation; do not change the two-input helper
 * merely for code generation.
 */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef unsigned long long Mask;
extern int *D_L23_001FF300[];
extern Mask D_L23_002595C8[][2];
extern float D_L23_001B1410 __attribute__((sda));
extern void func_L23_00418650(char *, float);
extern int func_L23_00418BC8(char *, char *, char *);
extern void func_L23_00418DC0(char *, int);
extern float func_00282E48(char *, char *);
extern float func_L00_0031BDC0(float *, const float *, const float *, const float *);
extern void func_L23_004190C8(char *, Mask, int, int);
extern void func_00282CF0(char *, char *, char *);
extern void func_00282F20(char *, char *, float);
extern void func_L23_0041BFF0(char *);
extern int func_L22_003300E8(char *, Quad *);
extern void func_L23_0041C040(char *);
#define H(off) (*(short *)(state + (off)))

/* Advance the selected path segment and send its displacement to the object. */
void func_L23_004186D0(char *object, float height) {
    struct { Quad target, raised, secondary, point; float before, after; } local;
    char *state = *(char **)(object + 0x68);
    char *position;
    char *point;
    int *list;
    int index, next, slot;
    float distance;
    short mode;
    qcopy(&local.target,*(void **)(state+0x400));
    qcopy(&local.raised,*(void **)(state+0x400));
    func_L23_00418650((char *)&local.raised, 0.0f);
    qcopy(&local.secondary,*(void **)(state+0x400));
    func_L23_00418650((char *)&local.secondary, height);
    func_L23_00418BC8(object, object+16, *(char **)(state + 0x400));
    if (H(0x390) != 0)
        func_L23_00418650(state + 0x3A0, *(float *)(state + 0x588));
    if (H(0x390) == 0) H(0x390) = 1;
    mode = H(0x390);
    position = object+16;
    H(0x406) = 0;
    if (mode) {
        switch (mode) {
        case 1:
            func_L23_00418DC0(object, 1);
            index = H(0x396);
            list = D_L23_001FF300[*(int *)(state + H(0x394) * 4 + 0x230)];
            point = (char *)list + index * 16 + 16;
            qcopy(&local.point,point);
            H(0x390) = 2;
            distance = func_00282E48(point, (char *)&local.raised);
            if (H(0x396) == 0) {
                if (!(func_00282E48((char *)list + 32, (char *)&local.raised) < distance)) {
                    H(0x392) = -1;
                    qcopy(state+0x3A0,&local.point);
                } else {
                    H(0x392) = 1;
                    func_L00_0031BDC0((float *)(state + 0x3A0), (float *)&local.point,
                        (float *)((char *)list + H(0x396) * 16 + 32), (float *)position);
                }
            } else if (H(0x396) == *list - 1) {
                if (func_00282E48((char *)list + *list * 16 - 16, (char *)&local.raised) < distance) {
                    H(0x392) = -1;
                    func_L00_0031BDC0((float *)(state + 0x3A0), (float *)&local.point,
                        (float *)((char *)list + H(0x396) * 16), (float *)position);
                } else {
                    H(0x392) = 1;
                    qcopy(state+0x3A0,&local.point);
                }
            } else {
                local.before = func_00282E48((char *)list + H(0x396) * 16, (char *)&local.raised);
                local.after = func_00282E48((char *)list + H(0x396) * 16 + 32, (char *)&local.raised);
                if (local.before < local.after) H(0x392) = -1;
                else H(0x392) = 1;
                func_L00_0031BDC0((float *)(state + 0x3A0), (float *)&local.point,
                    (float *)((char *)list + H(0x392) * 16 + 16), (float *)position);
            }
            func_L23_00418650(state + 0x3A0, height);
            break;
        case 2:
            if (func_00282E48(position, state + 0x3A0) < 2.0f) H(0x390) = 3;
            else qcopy(&local.target,state+0x3A0);
            break;
        case 3:
            if (func_00282E48(position, state + 0x3A0) < 2.0f) {
                next = H(0x396) + H(0x392);
                slot = *(int *)(state + 0x230 + H(0x394) * 4);
                if (next < 0) func_L23_004190C8(object, D_L23_002595C8[slot][0], 1, 1);
                else if (next < *D_L23_001FF300[slot]) H(0x396) = next;
                else func_L23_004190C8(object, D_L23_002595C8[slot][1], 1, 1);
                slot = *(int *)(state + 0x230 + H(0x394) * 4);
                point = (char *)D_L23_001FF300[slot] + H(0x396) * 16 + 16;
                qcopy((state + 0x3A0) ,point);
                func_L23_00418650(state + 0x3A0, height);
            }
            qcopy(&local.target,state+0x3A0);
            break;
        case 4:
            H(0x390) = 0;
            break;
        }
    }
    func_00282CF0((char *)&local.point, (char *)&local.target, position);
    func_00282F20((char *)&local.point, (char *)&local.point, *(float *)(state + 0x5C8) * 0.016666668f);
    func_L23_0041BFF0(object);
    func_L22_003300E8(object, &local.point);
    func_L23_0041C040(object);
    D_L23_001B1410 = 1.0f;
}
