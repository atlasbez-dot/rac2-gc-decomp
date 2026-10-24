/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * Reported final C / retail: 1048 / 1044 bytes; size equality is not a match.
 * us: 0/1 placements; 1048/1044 bytes.
 * us2: 0/1 placements; 1048/1044 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Mixed quad/float scheduling and final-copy address lifetime; four ignored helper return contracts not fully qualified.
 * Reopening condition: New measured source-shape/scheduler or ABI remedy addressing the residual; do not repeat tied forms.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Near miss: 1048 compiled/1044 retail bytes, 0/1 USA placements.
 * Tested G8 and G0 with qcopy/zero-ti-por, plus qcopy-barrier.
 * Explicit object+0x10 in the final copy fixes saved register allocation but
 * adds one address operation; the original position alias is 1044 bytes
 * with object/position/constant saved registers permuted. Union zero
 * initializers change prologue scheduling but do not fix it.
 * Remaining helper ABIs requiring full callee audit: 002FD1B8, 00312D58,
 * 002BFB38 and the final 0038DE70 callback. Caller bank inputs preserved.
 * Reopen with a mixed quad/float initialization scheduling witness.
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
extern void func_002FEE70(int, void *, int);
extern void func_00300190(void *, void *);
extern void func_00300248(int, int);
extern void func_002FE880(void *, float *, float);
extern void func_L00_0038F178(char *);
extern int func_00278E78(void);
extern void func_002FD1B8(int, int, int, float, float, float, float);
extern void func_00282C88(void *);
extern char *func_00312D58(void *, float);
extern float func_002A7940(void);
extern float func_002A7878(float, float);
extern float func_00283180(float);
extern float func_00283198(float);
extern int func_002A7820(int, int);
extern int func_002A77E0(int);
extern void func_002BFB38(void *, void *, int, int);
extern int D_L24_001B1F30 __attribute__((sda));
extern int D_L24_001B1F38 __attribute__((sda));
void func_L24_00383818(char *object)
{
    Vec previous;
    union { Quad bits; Vec vector; } rebound = {0}, surface = {0};
    TraceOptions options;
    Vec point, velocity;
    char *data = *(char **)(object + 0x68);
    char *position = object + 0x10;
    int count, duration, kind;
    float direction, speed;
    char *effect;
    rebound.vector.z = 0.033333335f;
    surface.vector.z = 1.0f;
    *(Quad *)&previous = *(Quad *)position;
    func_00282CC0(position, data, position);
    func_002FEE70(*(int *)(data + 0x1c), data, 0);
    func_00300190(position, position);
    func_00300248((int)data, (int)data);
    func_002FE880(position, (float *)data, 0.0030555557f);
    func_L00_0038F178(object);
    options.object = object;
    options.flags = 0x830000;
    if (*(int *)(data + 0x18) < 0x122) options.flags = 0x830001;
    options.active = 1;
    options.response = D_L24_00261E70[D_00139574].response;
    options.direction = *(Quad *)data;
    func_00282F70(&options, &options, 1.0f);
    options.id = *(unsigned short *)(object + 0xaa);
    ((Vec *)&options)->z = 1.0f;
    ((Vec *)&options)->w = 5627.925f;
    options.kind = 2;
    options.enabled = 1;
    if (func_002761F8(&previous, position, 0x10, object, &options)) {
        if (func_00278E78() == 0 && *(float *)(data + 8) < 0.0f) {
            func_002FD1B8(D_L24_001B1F30, D_L24_001B1F38, 1,
                         *(float *)(object + 0x10), *(float *)(object + 0x14), 0.5f, -0.35f);
            *(int *)(data + 0x14) = 1;
            func_00282C88(data);
            *(float *)(data + 8) = -0.025000002f;
            point.x = *(float *)(object + 0x10);
            point.y = *(float *)(object + 0x14);
            point.z = ((Vec *)&TRACE->position)->z;
            effect = func_00312D58(&point, 2.0f);
            if (effect) effect[0x23] = 0x70;
            count = 15;
            do {
                --count;
                direction = func_002A7940();
                speed = func_002A7878(0.0f, 0.050000004f);
                velocity.x = func_00283180(direction) * speed;
                velocity.y = func_00283198(direction) * speed;
                velocity.z = func_002A7878(0.050000004f, 0.10833334f);
                duration = func_002A7820(0x5a, 0x78);
                kind = func_002A77E0(2);
                func_002BFB38(&point, &velocity, kind, duration);
            } while (count >= 0);
            goto finish;
        }
        if (TRACE->object) {
            if ((TRACE->object == *(char **)(D_00189E20 + 0x2290) ||
                 *(short *)(TRACE->object + 0xaa) == 0xc0) && *(int *)(data + 0x18) >= 0x122)
                goto finish;
            if (*(void **)(TRACE->object + 0x64) == D_L24_001AC790 &&
                *(short *)(TRACE->object + 0xaa) != 0x336) goto finish;
        } else if (TRACE->count < 1) goto finish;
        object[0xbc] = 1;
        *(Quad *)(object + 0x10) = TRACE->position;
        func_00283028(&rebound, data, &TRACE->normal);
        func_00282F20(&rebound, &rebound, 0.033333335f);
        func_00282F20(&surface, &TRACE->normal, 1.0f);
    } else if (func_00282948((int *)(data + 0x18))) {
        object[0xbc] = 1;
        func_00282CC0(&rebound, &rebound, data);
    }
finish:
    if (*(unsigned char *)(object + 0xbc)) {
        func_002FEE50(*(int *)(data + 0x1c));
        func_L00_0038DE70(object, &rebound.vector, &surface.vector);
    }
}
