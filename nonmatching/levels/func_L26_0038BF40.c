/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -frac2-zero-ti-por -mno-split-addresses.
 * Prior worker coverage: US 0/1; US2 0/1; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por
 * -mno-split-addresses
 * Measured text: 772 bytes; retail: 776 bytes. Stack frame 0xC0; retail 0xC0.
 * Final coverage: US 0/1, US2 0/1, PAL absent. Absences are not matches.
 * 3 measured source/profile forms. The four-byte size gap does not describe all instruction
 * differences: object/context GPR allocation and scheduling still differ throughout. Keeping
 * actor and world hit handling separate recovered 60 bytes, and -mno-split-addresses added
 * four more. The collision helper copies 40 bytes; the unwritten final field remains part of
 * the real context. Reopen on object/context lifetimes and branch scheduling.
 * All carrying checks are nonmatches (exit 1); no linked-build credit.
 */

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
    previous.q = *(Quad *)(object + 0x10);
    func_00282CC0(object + 0x10, object + 0x10, private);
    func_002AFFD8(object + 0x10, (char *)&direction, 0);
    func_00282D30(&direction, &direction, 0.0003055556f);
    func_L00_0038F3D8(object);
    context.flags = *(int *)(private + 0x18) < 290 ? 0x830001 : 0x830000;
    context.tail[0] = 1;
    context.material = *(float *)(D_L26_002622F0 + (unsigned int)D_00139574 * 0xE0 + 0x70);
    context.direction.q = *(Quad *)private;
    context.owner = object;
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
            *(Quad *)(object + 0x10) = D_L26_001BEFE0.q;
            func_00283028(&force, private, &D_L26_001BF000);
            func_00282F20(&force, &force, 0.033333335f);
        } else {
            if (D_L26_001BEFDC < 1) goto finish;
            object[0xBC] = 1;
            *(Quad *)(object + 0x10) = D_L26_001BEFE0.q;
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
