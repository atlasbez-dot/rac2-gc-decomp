/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -frac2-zero-ti-por.
 * Prior worker coverage: US 0/1; US2 0/1; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por
 * Measured text: 1036 bytes; retail: 1044 bytes. Stack frame 0xE0; retail 0xE0.
 * Final coverage: US 0/1, US2 0/1, PAL absent. Absences are not matches.
 * 2 measured source/profile forms. Register scheduling around the zero quadwords and
 * collision context differs, with an eight-byte text gap. -mno-split-addresses did not
 * improve size and was reverted. FD1B8 keeps three GPR and four float inputs, and 312D58
 * returns a pointer. Reopen on zero/vector and effect-emission lifetimes.
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


extern int D_L26_001B23B0 __attribute__((sda));
extern int D_L26_001B23B8 __attribute__((sda));
extern void func_002FEE70(int, void *, int);
extern void func_00300190(void *, void *);
extern void func_00300248(int, int);
extern void func_002FE880(void *, float *, float);
extern void func_L00_0038F178(char *);
extern int func_00278E78(void);
extern void func_002FD1B8(int, int, int, float, float, float, float);
extern void func_00282C88(Quad *);
extern char *func_00312D58(void *, float);
extern float func_002A7940(void);
extern float func_002A7878(float, float);
extern float func_00283180(float);
extern float func_00283198(float);
extern int func_002A7820(int, int);
extern int func_002A77E0(int);
extern char *func_002BFB38(void *, void *, int, int);

void func_L26_0038BB28(char *object) {
    Vector previous;
    Vector force;
    Vector normal;
    CollisionContext context;
    Vector effect_position;
    Vector velocity;
    char *private = *(char **)(object + 0x68);
    char *hit;
    char *effect;
    float angle;
    float speed;
    int count;
    int duration;
    int kind;
    force.q = 0;
    force.f[2] = 0.033333335f;
    normal.q = 0;
    normal.f[2] = 1.0f;
    previous.q = *(Quad *)(object + 0x10);
    func_00282CC0(object + 0x10, private, object + 0x10);
    func_002FEE70(*(int *)(private + 0x1C), private, 0);
    func_00300190(object + 0x10, object + 0x10);
    func_00300248((int)private, (int)private);
    func_002FE880(object + 0x10, (float *)private, 0.0030555557f);
    func_L00_0038F178(object);
    context.flags = *(int *)(private + 0x18) < 290 ? 0x830001 : 0x830000;
    context.tail[0] = 1;
    context.material = *(float *)(D_L26_002622F0 + (unsigned int)D_00139574 * 0xE0 + 0x70);
    context.direction.q = *(Quad *)private;
    context.owner = object;
    func_00282F70(&context.direction, &context.direction, 1.0f);
    context.id = *(unsigned short *)(object + 0xAA);
    context.direction.f[2] = 1.0f;
    context.direction.f[3] = 5627.925f;
    context.mode = 2;
    context.enabled = 1;
    if (!func_002761F8(&previous, object + 0x10, 16, object, &context)) {
        if (func_00282948((int *)(private + 0x18))) {
            object[0xBC] = 1;
            func_00282CC0(&force, &force, private);
        }
        goto finish;
    }
    if (!func_00278E78() && *(float *)(private + 8) < 0.0f) {
        func_002FD1B8(D_L26_001B23B0, D_L26_001B23B8, 1,
                      *(float *)(object + 0x10), *(float *)(object + 0x14), 0.5f, -0.35f);
        *(int *)(private + 0x14) = 1;
        func_00282C88((Quad *)private);
        *(float *)(private + 8) = -0.025000002f;
        effect_position.f[0] = *(float *)(object + 0x10);
        effect_position.f[1] = *(float *)(object + 0x14);
        effect_position.f[2] = D_L26_001BEFE0.f[2];
        effect = func_00312D58(&effect_position, 2.0f);
        if (effect) effect[0x23] = 0x70;
        count = 15;
        do {
            angle = func_002A7940();
            speed = func_002A7878(0.0f, 0.050000004f);
            velocity.f[0] = func_00283180(angle) * speed;
            velocity.f[1] = func_00283198(angle) * speed;
            velocity.f[2] = func_002A7878(0.050000004f, 0.10833334f);
            duration = func_002A7820(90, 120);
            kind = func_002A77E0(2);
            func_002BFB38(&effect_position, &velocity, kind, duration);
        } while (--count >= 0);
        goto finish;
    }
    hit = D_L26_001BEFD8;
    if (hit) {
        if ((hit == D_0018C0B0 || *(short *)(hit + 0xAA) == 0xC0) && *(int *)(private + 0x18) >= 290)
            goto finish;
        if (*(void **)(hit + 0x64) == D_L26_001AC810 && *(short *)(hit + 0xAA) != 0x336)
            goto finish;
    } else if (D_L26_001BEFDC < 1) goto finish;
    object[0xBC] = 1;
    *(Quad *)(object + 0x10) = D_L26_001BEFE0.q;
    func_00283028(&force, private, &D_L26_001BF000);
    func_00282F20(&force, &force, 0.033333335f);
    func_00282F20(&normal, &D_L26_001BF000, 1.0f);
finish:
    if ((unsigned char)object[0xBC]) {
        func_002FEE50(*(int *)(private + 0x1C));
        func_L00_0038DE70(object, &force, &normal);
    }
}
