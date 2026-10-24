/* Retained reconstruction, 23 October 2026. Game -O2 -G8 with
   -frac2-qcopy -frac2-qcopy-barrier: 1044/1044 bytes, 0/2 USA v1.01 and
   0/2 USA v2.00 placements; absent from PAL. First difference +0x18:
   the shared por-fed clear at stack +0x10 is scheduled late. Collision field
   stores, loop setup and owner rejection retain further GPR/scheduling changes.
   Two measured source orders keep the retail size. Reopen with independent
   shared-clear scheduling evidence and collision-record field/layout evidence.
   The special collision response and 16-particle loop use the measured ABI. */
#include "include_asm.h"

typedef int Quad __attribute__((mode(TI)));
typedef struct { char pad[0x70]; float radius; char tail[0x6c]; } Camera;
typedef struct { char pad[0x18]; char *object; int count; Quad position; char gap[16]; char normal[16]; } Hit;
extern Camera D_L15_00276FF0[];
extern Hit D_L15_001BFC00;
extern unsigned char D_00139574 __attribute__((nosda));
extern void *D_0018C0B0 __attribute__((nosda));
extern void *D_L15_001AC810 __attribute__((nosda));
extern void *D_L15_001B2DB0 __attribute__((sda));
extern void *D_L15_001B2DB8 __attribute__((sda));
extern void func_00282CC0(void *, void *, void *);
extern void func_002FEE70(int, void *, int);
extern void func_00300190(void *, void *);
extern void func_00300248(void *, void *);
extern void func_002FE880(void *, void *, float);
extern void func_L00_0038F178(void *);
extern void func_00282F70(void *, void *, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern int func_00278E78(void);
extern void func_002FD1B8(void *, void *, int, float, float, float, float);
extern void func_00282C88(void *);
extern char *func_00312D58(void *, float);
extern float func_002A7940(void);
extern float func_002A7878(float, float);
extern float func_00283180(float);
extern float func_00283198(float);
extern int func_002A7820(int, int);
extern int func_002A77E0(int);
extern void func_002BFB38(void *, void *, int, int);
extern void func_00283028(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern int func_00282948(void *);
extern void func_002FEE50(int);
extern void func_L00_0038DE70(void *, void *, void *);

void func_L15_003A9E80(unsigned char *object)
{
    char previous[16];
    float delta[4];
    float normal[4];
    char collision[48];
    float effectPosition[4];
    float effectVelocity[4];
    char *position = (char *)object + 0x10;
    char *state;

    *(Quad *)delta = 0;
    state = *(char **)(object + 0x68);
    *(Quad *)normal = 0;
    delta[2] = 0.03333333507180214f;
    normal[2] = 1.0f;
    *(Quad *)previous = *(Quad *)position;
    func_00282CC0(position, state, position);
    func_002FEE70(*(int *)(state + 0x1c), state, 0);
    func_00300190(position, position);
    func_00300248(state, state);
    func_002FE880(position, state, 0.003055555745959282f);
    func_L00_0038F178(object);
    *(void **)(collision + 0x10) = object;
    *(int *)(collision + 0x14) = 0x830000;
    if (*(int *)(state + 0x18) < 0x122)
        *(int *)(collision + 0x14) = 0x830001;
    *(float *)(collision + 0x1c) = ((Camera *)((char *)D_L15_00276FF0 + D_00139574 * 0xe0))->radius;
    *(int *)(collision + 0x20) = 1;
    *(Quad *)collision = *(Quad *)state;
    func_00282F70(collision, collision, 1.0f);
    collision[0x18] = 2;
    *(float *)(collision + 0xc) = 5627.9248046875f;
    *(unsigned short *)(collision + 0x1a) = *(unsigned short *)(object + 0xaa);
    *(float *)(collision + 8) = 1.0f;
    collision[0x19] = 1;
    if (func_002761F8(previous, position, 0x10, object, collision)) {
        if (!func_00278E78() && *(float *)(state + 8) < 0.0f) {
            char *effect;
            int i;
            func_002FD1B8(D_L15_001B2DB0, D_L15_001B2DB8, 1,
                         *(float *)(object + 0x10), *(float *)(object + 0x14), 0.5f, -0.35f);
            *(int *)(state + 0x14) = 1;
            func_00282C88(state);
            *(float *)(state + 8) = -0.02500000223517418f;
            effectPosition[0] = *(float *)(object + 0x10);
            effectPosition[1] = *(float *)(object + 0x14);
            effectPosition[2] = ((float *)&D_L15_001BFC00.position)[2];
            effect = func_00312D58(effectPosition, 2.0f);
            if (effect)
                effect[0x23] = 0x70;
            for (i = 15; i >= 0; --i) {
                float angle = func_002A7940();
                float speed = func_002A7878(0.0f, 0.05000000447034836f);
                int life;
                effectVelocity[0] = func_00283180(angle) * speed;
                effectVelocity[1] = func_00283198(angle) * speed;
                effectVelocity[2] = func_002A7878(0.05000000447034836f, 0.10833334177732468f);
                life = func_002A7820(90, 120);
                func_002BFB38(effectPosition, effectVelocity, func_002A77E0(2), life);
            }
        } else if (D_L15_001BFC00.object) {
            if ((D_L15_001BFC00.object == D_0018C0B0 || *(short *)(D_L15_001BFC00.object + 0xaa) == 0xc0) &&
                *(int *)(state + 0x18) >= 0x122)
                goto finished;
            if (D_L15_001AC810 == *(void **)(D_L15_001BFC00.object + 0x64) &&
                *(short *)(D_L15_001BFC00.object + 0xaa) != 0x336)
                goto finished;
            object[0xbc] = 1;
            *(Quad *)(object + 0x10) = D_L15_001BFC00.position;
            func_00283028(delta, state, D_L15_001BFC00.normal);
            func_00282F20(delta, delta, 0.03333333507180214f);
            func_00282F20(normal, D_L15_001BFC00.normal, 1.0f);
        } else if (D_L15_001BFC00.count > 0) {
            object[0xbc] = 1;
            *(Quad *)(object + 0x10) = D_L15_001BFC00.position;
            func_00283028(delta, state, D_L15_001BFC00.normal);
            func_00282F20(delta, delta, 0.03333333507180214f);
            func_00282F20(normal, D_L15_001BFC00.normal, 1.0f);
        }
    } else if (func_00282948(state + 0x18)) {
        object[0xbc] = 1;
        func_00282CC0(delta, delta, state);
    }
finished:
    if (object[0xbc]) {
        func_002FEE50(*(int *)(state + 0x1c));
        func_L00_0038DE70(object, delta, normal);
    }
}
