/* Retained readable reconstruction; NOT MATCHING and no exact-C credit.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g
 * Fresh local measure: 1336/1372 bytes; 0/2 USA v1.01 placements; frame 0x90 versus 0x80.
 * Evidence: A measured resident motion-prefix view and addresses at use remove long-lived derived pointers; the position-anchor form ties. Three independent 16-byte scratch vectors and all live clamp magnitudes remain present. The view does not define the full resident object extent.
 * Reopen: Reopen with real resident-base/scalar temporary lifetimes or allocator evidence; do not share simultaneously live scratch storage or add padding.
 * Older notes below are historical. Equal size and allocator diagnostics do
 * not establish relocation/binding qualification or linked equality.
 */
#include "common.h"

/* 1372/1372; us/us2 0/2 each; PAL absent.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * Resident movement projection preserves three independent 16-byte scratch vectors and full helper inputs, including the live clamp magnitudes omitted by the reference decompiler. Frame/register allocation and resident-base lifetimes differ. No padding added. Reopen with original aggregate/lifetime evidence.
 */
typedef int TI128 __attribute__((mode(TI)));
extern u8 D_00189E20[];
extern void func_L00_002D4140(u32, void *, void *);
extern float func_L00_002D3A58(char *);
extern void func_L00_002D3BD8(char *, int, float);
extern float func_L00_002D3B00(char *);
extern void func_L00_002D3B58(TI128 *, TI128 *, float);
extern float func_00282DF0(void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282C88(TI128 *);
extern void func_L00_002B5A88(void);
extern void func_L09_002B7238(void);
extern void func_00282CF0(void *, void *, void *);
extern void func_L00_002B5250(void);
extern float func_00282DB0(void *, void *);
extern void func_L00_002D3960(char *, char *);
extern float func_L00_002B5590(void *);
extern void func_00282D30(void *, void *, float);

/* Measured resident prefix; this view does not claim the full hero extent. */
typedef struct HeroMotionPrefix {
    u8 unknown00[0x80];
    TI128 position;
    u8 unknown90[0x60];
    TI128 velocity, impulse, displacement, projected, up, flat, impulseMove;
} HeroMotionPrefix;

void func_L11_002CDE10(void) {
    TI128 initial, planar, vertical;
    HeroMotionPrefix *motion = (HeroMotionPrefix *)D_00189E20;
    char *position = (char *)&motion->position;
    u8 *hero = (u8 *)motion;
    float limit, magnitude, component, savedW;
    int state = *(int *)(hero + 0x2294);
    qcopy(&initial, position);
    func_L00_002D4140(*(u32 *)(hero + 0x588), ((char *)&motion->impulse), hero + 0x90);
    state = *(int *)(hero + 0x2294);
    if (state == 0x14 || state == 0x5B || state == 0x58 || state == 0x81) {
        if (*(short *)(hero + 0x1F0) == 0) {
            magnitude = func_L00_002D3A58(((char *)&motion->velocity));
            limit = *(float *)(hero + 0x264) - 0.02f;
            if (limit < magnitude)
                func_L00_002D3BD8(((char *)&motion->velocity), (int)((char *)&motion->velocity), limit);
        }
        component = func_L00_002D3B00(((char *)&motion->velocity));
        if (component < -*(float *)(hero + 0x31C)) {
            limit = -*(float *)(hero + 0x31C) - 0.02f;
            if (limit > 0.0f)
                limit = 0.0f;
            func_L00_002D3B58((TI128 *)((char *)&motion->velocity), (TI128 *)((char *)&motion->velocity), limit);
        }
    } else if (*(int *)(hero + 0x229C) != 13 && *(int *)(hero + 0x229C) != 14 && state != 0x44 && *(short *)(hero + 0x1F0) == 0) {
        magnitude = func_00282DF0(((char *)&motion->velocity));
        limit = *(float *)(hero + 0x264) - 0.02f;
        if (limit < magnitude)
            func_00282F20(((char *)&motion->velocity), ((char *)&motion->velocity), limit);
    }
    func_00282CC0(position, position, ((char *)&motion->velocity));
    func_00282CC0(position, position, hero + 0xA60);
    func_00282C88((TI128 *)(hero + 0xA60));
    *(u32 *)(hero + 0x26C) = 0;
    hero[0x287] = 0;
    if (func_00282DF0(((char *)&motion->impulse)) <= 0.00009999999747378752f) {
        func_L00_002B5A88();
        func_L09_002B7238();
        func_00282CF0(((char *)&motion->displacement), position, &initial);
        func_L00_002B5250();
    } else {
        func_L09_002B7238();
    }
    func_00282CF0(((char *)&motion->projected), position, &initial);
    qcopy(((char *)&motion->flat), ((char *)&motion->projected));
    qcopy(((char *)&motion->up), ((char *)&motion->projected));
    func_00282F20(((char *)&motion->projected), ((char *)&motion->projected), 1.0f);
    magnitude = func_00282DB0(((char *)&motion->projected), ((char *)&motion->velocity));
    if (magnitude < 0.0f)
        magnitude = 0.0f;
    func_00282F20(((char *)&motion->projected), ((char *)&motion->velocity), magnitude);
    qcopy(&planar, ((char *)&motion->velocity));
    func_L00_002D3960((char *)&planar, (char *)&planar);
    func_L00_002D3960(((char *)&motion->flat), ((char *)&motion->flat));
    func_00282F20(((char *)&motion->flat), ((char *)&motion->flat), 1.0f);
    magnitude = func_00282DB0(((char *)&motion->flat), &planar);
    if (magnitude < 0.0f)
        magnitude = 0.0f;
    func_00282F20(((char *)&motion->flat), &planar, magnitude);
    qcopy(&vertical, ((char *)&motion->velocity));
    func_L00_002D3BD8((char *)&vertical, (int)&vertical, 0.0f);
    func_L00_002D3BD8(((char *)&motion->up), (int)((char *)&motion->up), 0.0f);
    func_00282F20(((char *)&motion->up), ((char *)&motion->up), 1.0f);
    magnitude = func_00282DB0(((char *)&motion->up), &vertical);
    if (magnitude < 0.0f)
        magnitude = 0.0f;
    func_00282F20(((char *)&motion->up), &vertical, magnitude);
    *(float *)(hero + 0x170) = func_00282DF0(((char *)&motion->projected));
    *(float *)(hero + 0x174) = func_L00_002D3A58(((char *)&motion->projected));
    qcopy(&planar, ((char *)&motion->projected));
    *(float *)(hero + 0x178) = func_L00_002B5590(&planar);
    *(float *)(hero + 0x180) = func_L00_002D3B00(((char *)&motion->projected));
    if (*(float *)(hero + 0x178) < 0.0f)
        *(float *)(hero + 0x178) = 0.0f;
    qcopy(&planar, position);
    if (func_00282DF0(((char *)&motion->impulse)) > 0.00009999999747378752f) {
        func_00282CC0(position, position, ((char *)&motion->impulse));
        savedW = *(float *)(((char *)&motion->impulse) + 0xC);
        func_00282C88((TI128 *)((char *)&motion->impulse));
        *(float *)(((char *)&motion->impulse) + 0xC) = savedW;
        func_L00_002B5A88();
        func_L09_002B7238();
        func_00282CF0(((char *)&motion->displacement), position, &initial);
        func_L00_002B5250();
    }
    func_00282CF0(((char *)&motion->impulseMove), position, &planar);
    *(float *)(hero + 0x184) = func_00282DF0(((char *)&motion->impulseMove));
    *(float *)(((char *)&motion->impulseMove) + 0xC) = *(float *)(((char *)&motion->impulse) + 0xC);
    *(float *)(((char *)&motion->impulse) + 0xC) = 0.0f;
    func_00282CF0(((char *)&motion->displacement), position, &initial);
    *(float *)(hero + 0x17C) = 0.0f;
    if (*(float *)(hero + 0x174) > 0.004000000189989805f) {
        component = *(float *)(((char *)&motion->displacement) + 8) / *(float *)(hero + 0x174);
        if (component > 0.5f)
            component = 0.5f;
        else if (component < -0.5f)
            component = -0.5f;
        *(float *)(hero + 0x17C) = component;
    }
    if (*(float *)(hero + 0x170) > 0.8666667342185974f) {
        func_00282D30(((char *)&motion->displacement), ((char *)&motion->displacement), 0.8666667342185974f / *(float *)(hero + 0x170));
        *(float *)(hero + 0x170) = 0.8666667342185974f;
    }
}
