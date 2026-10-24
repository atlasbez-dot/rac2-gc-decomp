/* Retained reconstruction, 23 October 2026. Game -O2 -G0 with
   -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por -g:
   776/776 bytes, 0/2 USA v1.01 and 0/2 USA v2.00 placements; absent from PAL.
   First difference +0x28: the shared por-fed stack clear is scheduled after
   saves/state/constant setup. Owner rejection also retains a different GPR/load
   order. Bounded source/profile trials and flag rechecks explored byte
   signedness, the containing hit/camera layouts, global reloads, scalar source
   order and aggregate zero initializers (812 bytes). Reopen with independent
   original initialization/layout evidence or a qualified shared-clear scheduling
   model; no register pins, artificial barriers or volatile probes retained. */
#include "include_asm.h"

typedef int Quad __attribute__((mode(TI)));
extern void func_00282CC0(void *, void *, void *);
extern void func_002AFFD8(void *, void *, int);
extern void func_00282D30(void *, void *, float);
extern void func_L00_0038F3D8(void *);
extern void func_00282F70(void *, void *, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern void func_00283028(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern int func_00282948(void *);
extern void func_002FEE50(int);
extern void func_L00_0038DE70(void *, void *, void *);
extern void func_L00_0038E880(void *, void *, void *);
extern unsigned char D_00139574;
typedef struct { char pad[0x70]; float radius; char tail[0x6c]; } Camera;
typedef struct { char pad[0x18]; char *object; int count; Quad position; char gap[16]; char normal[16]; } Hit;
extern Camera D_L15_00276FF0[];
extern Hit D_L15_001BFC00;
extern void *D_0018C0B0;
extern void *D_L15_001AC810;



void func_L15_003AA298(unsigned char *object)
{
    float delta[4];
    float normal[4];
    char previous[16];
    char temporary[16];
    char collision[48];
    char *position = (char *)object + 0x10;
    char *state;

    *(Quad *)delta = 0;
    state = *(char **)(object + 0x68);
    *(Quad *)normal = 0;
    delta[2] = 0.03333333507180214f;
    normal[2] = 1.0f;
    *(Quad *)previous = *(Quad *)position;
    func_00282CC0(position, position, state);
    func_002AFFD8(position, temporary, 0);
    func_00282D30(temporary, temporary, 0.0003055555862374604f);
    func_L00_0038F3D8(object);
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
    *(short *)(collision + 0x1a) = *(unsigned short *)(object + 0xaa);
    *(float *)(collision + 8) = 1.0f;
    collision[0x19] = 1;
    ++*(int *)(state + 0x14);
    if (func_002761F8(previous, position, 0x10, object, collision)) {
        if (D_L15_001BFC00.object) {
            if ((D_L15_001BFC00.object == D_0018C0B0 || *(short *)(D_L15_001BFC00.object + 0xaa) == 0xc0) &&
                *(int *)(state + 0x18) >= 0x122)
                goto finished;
            if (D_L15_001AC810 == *(void **)(D_L15_001BFC00.object + 0x64) && *(short *)(D_L15_001BFC00.object + 0xaa) != 0x336)
                goto finished;
            *(unsigned char *)(object + 0xbc) = 1;
            *(Quad *)(object + 0x10) = D_L15_001BFC00.position;
            func_00283028(delta, state, D_L15_001BFC00.normal);
            func_00282F20(delta, delta, 0.03333333507180214f);
            func_00282F20(normal, D_L15_001BFC00.normal, 1.0f);
        } else if (D_L15_001BFC00.count > 0) {
            *(unsigned char *)(object + 0xbc) = 1;
            *(Quad *)position = D_L15_001BFC00.position;
            func_00283028(delta, state, D_L15_001BFC00.normal);
            func_00282F20(delta, delta, 0.03333333507180214f);
            func_00282F20(normal, D_L15_001BFC00.normal, 1.0f);
        }
    } else if (func_00282948(state + 0x18)) {
        *(unsigned char *)(object + 0xbc) = 1;
        func_00282CC0(delta, delta, state);
    }
finished:
    if ((unsigned char)object[0xbc]) {
        func_002FEE50(*(int *)(state + 0x1c));
        if (*(int *)(state + 0x14) < 20)
            func_L00_0038DE70(object, delta, normal);
        else
            func_L00_0038E880(object, delta, normal);
    }
}
