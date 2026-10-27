/*
 * Complete manual reconstruction retained as nonmatching; no coverage credit.
 * Fresh checks on the qualified current compiler, 2026-10-25.
 * Profile: -O2 -G0 -ffunction-sections -frac2-zero-ti-por -mno-split-addresses
 * Coverage: US: 0/1; US2: 0/1; PAL: absent from catalogue.
 * Compiled text: 776 bytes; retail text: 776 bytes.
 * Remaining difference: Frame 0xC0 matches and the first 216 bytes agree after relocation
 * normalization. Storing base flags before the conditional override fixes the earlier entry
 * allocation. Material-record address formation diverges at +0xD8; later context field scheduling
 * and collision-result base reuse differ.
 * Reopen when: Recover the actual character-parameter and collision-result source layouts,
 * including canonical base symbols and their valid extents.
 */

#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
/* The collision helper copies 40 bytes. The final word is not initialized here. */
typedef struct {
    Vector direction;
    char *owner;
    int flags;
    unsigned char mode, enabled;
    unsigned short id;
    float material;
    int tail[2];
} CollisionContext;
extern unsigned char D_00139574;
extern char D_L26_002622F0[];
extern char *D_L26_001BEFD8;
extern int D_L26_001BEFDC;
extern Vector D_L26_001BEFE0;
extern Vector D_L26_001BF000;
extern char *D_0018C0B0;
extern void *D_L26_001AC810;
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
extern void func_L00_0038DE70(void *, void *, void *);
extern void func_L00_0038E880(void *, void *, void *);

void func_L26_0038BF40(char *object) {
    Vector force;
    Vector normal;
    Vector previous;
    Vector direction;
    CollisionContext context;
    char *private = *(char **)(object + 0x68);
    char *hit;
    force.q = 0;
    force.f[2] = 0.033333335f;
    normal.q = 0;
    normal.f[2] = 1.0f;
    qcopy(&previous, (object + 0x10));
    func_00282CC0(object + 0x10, object + 0x10, private);
    func_002AFFD8(object + 0x10, (char *)&direction, 0);
    func_00282D30(&direction, &direction, 0.0003055556f);
    func_L00_0038F3D8(object);
    context.owner = object;
    context.flags = 0x830000;
    if (*(int *)(private + 0x18) < 290) context.flags = 0x830001;
    context.tail[0] = 1;
    context.material = *(float *)(D_L26_002622F0 + (unsigned int)D_00139574 * 0xE0 + 0x70);
    qcopy(&context.direction, private);
    func_00282F70(&context.direction, &context.direction, 1.0f);
    context.id = *(unsigned short *)(object + 0xAA);
    context.mode = 2;
    context.direction.f[3] = 5627.925f;
    context.direction.f[2] = 1.0f;
    context.enabled = 1;
    ++*(int *)(private + 0x14);
    if (func_002761F8(&previous, object + 0x10, 16, object, &context)) {
        hit = D_L26_001BEFD8;
        if (hit) {
            if ((hit == D_0018C0B0 || *(short *)(hit + 0xAA) == 0xC0) && *(int *)(private + 0x18) >= 290)
                goto finish;
            if (*(void **)(hit + 0x64) == D_L26_001AC810 && *(short *)(hit + 0xAA) != 0x336)
                goto finish;
            object[0xBC] = 1;
            qcopy((object + 0x10), &D_L26_001BEFE0);
            func_00283028(&force, private, &D_L26_001BF000);
            func_00282F20(&force, &force, 0.033333335f);
        } else {
            if (D_L26_001BEFDC < 1) goto finish;
            object[0xBC] = 1;
            qcopy((object + 0x10), &D_L26_001BEFE0);
            func_00283028(&force, private, &D_L26_001BF000);
            func_00282F20(&force, &force, 0.033333335f);
        }
        func_00282F20(&normal, &D_L26_001BF000, 1.0f);
    } else if (func_00282948((int *)(private + 0x18))) {
        object[0xBC] = 1;
        func_00282CC0(&force, &force, private);
    }
finish:
    if ((unsigned char)object[0xBC]) {
        func_002FEE50(*(int *)(private + 0x1C));
        if (*(int *)(private + 0x14) < 20)
            func_L00_0038DE70(object, &force, &normal);
        else
            func_L00_0038E880(object, &force, &normal);
    }
}
