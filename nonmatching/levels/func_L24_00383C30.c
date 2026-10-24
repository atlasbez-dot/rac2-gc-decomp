/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-zero-ti-por.
 * Reported final C / retail: 768 / 776 bytes; size equality is not a match.
 * us: 0/1 placements; 768/776 bytes.
 * us2: 0/1 placements; 768/776 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Mixed quad/float initialization, register lifetimes, prologue and state/collision layout differ; helper callbacks require full ABI qualification.
 * Reopening condition: New measured source-shape/scheduler or ABI remedy addressing the residual; do not repeat tied forms.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Near miss under -O2 -G0 -ffunction-sections -frac2-qcopy
 * -frac2-zero-ti-por: 768 compiled/776 retail bytes, 0/1 USA placements.
 * Quad scalar locals allocate at different stack offsets (780 bytes);
 * a grouped scratch struct or separate Vec locals fix offsets but leave
 * object/data saved registers swapped and prologue scheduling different.
 * Positive collision branch preserves retail block order (negative:764).
 * Vec {0} initializers expand scalar stores (800 bytes).
 * Helpers 0038DE70/0038E880 still need full callee ABI qualification.
 * Reopen after a matching mixed quad/float prologue and local-lifetime example.
 */
#include "include_asm.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { float x,y,z,w; } Vec;
typedef struct {
    Quad direction;
    char *object; int flags;
    unsigned char kind, enabled; unsigned short id;
    float response; int active;
} TraceOptions;
typedef struct {
    unsigned char pad0[0x18]; char *object; int count;
    Quad position; unsigned char pad30[0x10]; Vec normal;
} TraceView;
typedef struct { unsigned char pad0[0x70]; float response; unsigned char pad74[0x6c]; } Material;
extern unsigned char D_L24_001BEB00[];
#define TRACE ((TraceView *)D_L24_001BEB00)
extern unsigned char D_00189E20[];
extern unsigned char D_00139574 __attribute__((nosda));
extern Material D_L24_00261E70[];
extern void *D_L24_001AC790;
extern void func_00282CC0(void *, void *, void *);
extern void func_002AFFD8(char *, char *, int);
extern void func_00282D30(void *, void *, float);
extern void func_L00_0038F3D8(char *);
extern void func_00282F70(void *, void *, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern void func_00283028(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern int func_00282948(int *);
extern void func_002FEE50(int);
extern void func_L00_0038DE70(char *, Vec *, Vec *);
extern void func_L00_0038E880(char *, Vec *, Vec *);
void func_L24_00383C30(char *object)
{
    Vec rebound, surface, previous, movement;
    TraceOptions options;
    char *data = *(char **)(object + 0x68);
    char *position = object + 0x10;
    *(Quad *)&rebound = 0;
    *(Quad *)&surface = 0;
    ((Vec *)&rebound)->z = 0.033333335f;
    ((Vec *)&surface)->z = 1.0f;
    *(Quad *)&previous = *(Quad *)position;
    func_00282CC0(position, position, data);
    func_002AFFD8(position, (char *)&movement, 0);
    func_00282D30(&movement, &movement, 0.0003055556f);
    func_L00_0038F3D8(object);
    options.object = object;
    options.flags = 0x830000;
    if (*(int *)(data + 0x18) < 0x122) options.flags = 0x830001;
    options.active = 1;
    options.response = D_L24_00261E70[D_00139574].response;
    options.direction = *(Quad *)data;
    func_00282F70(&options, &options, 1.0f);
    options.id = *(unsigned short *)(object + 0xaa);
    options.kind = 2;
    ((Vec *)&options)->w = 5627.925f;
    ((Vec *)&options)->z = 1.0f;
    options.enabled = 1;
    ++*(int *)(data + 0x14);
    if (func_002761F8(&previous, position, 0x10, object, &options)) {
        if (TRACE->object) {
            if ((TRACE->object == *(char **)(D_00189E20 + 0x2290) ||
                 *(short *)(TRACE->object + 0xaa) == 0xc0) && *(int *)(data + 0x18) >= 0x122)
                goto finish;
            if (*(void **)(TRACE->object + 0x64) == D_L24_001AC790 &&
                *(short *)(TRACE->object + 0xaa) != 0x336) goto finish;
            object[0xbc] = 1;
            *(Quad *)position = TRACE->position;
            func_00283028(&rebound, data, &TRACE->normal);
            func_00282F20(&rebound, &rebound, 0.033333335f);
        } else {
            if (TRACE->count < 1) goto finish;
            object[0xbc] = 1;
            *(Quad *)position = TRACE->position;
            func_00283028(&rebound, data, &TRACE->normal);
            func_00282F20(&rebound, &rebound, 0.033333335f);
        }
        func_00282F20(&surface, &TRACE->normal, 1.0f);
    } else {
        if (func_00282948((int *)(data + 0x18))) {
            object[0xbc] = 1;
            func_00282CC0(&rebound, &rebound, data);
        }
    }
finish:
    if (*(unsigned char *)(object + 0xbc)) {
        func_002FEE50(*(int *)(data + 0x1c));
        if (*(int *)(data + 0x14) < 20)
            func_L00_0038DE70(object, (Vec *)&rebound, (Vec *)&surface);
        else func_L00_0038E880(object, (Vec *)&rebound, (Vec *)&surface);
    }
}
