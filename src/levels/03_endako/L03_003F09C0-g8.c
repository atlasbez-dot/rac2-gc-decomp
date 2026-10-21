#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* These bodies reach D_L03_001B2A1C with `lw $a2,0x3A2C($gp)`, which only a
 * -G8 unit emits; the same symbol is reached with an absolute `lui`/`lw` pair
 * inside func_L03_003F66D8 and func_L03_0041D128, so those stay in the -G0 file. */
extern u8 *D_L03_001B2A1C __attribute__((sda));

/* The two words the entity's state is chosen by, both reached through $gp. */
extern s32 D_L03_001B108C __attribute__((sda));
extern u32 D_L03_001B1058 __attribute__((sda));

extern void func_002A7750(void *entity, int a, int b);
extern int func_002A77E0(int id);

/* The engine's particle and light helpers, called with the level's own copies. */
extern void func_00282948(void *target);
extern void func_00282978(void *target);
extern void func_002AEC48(void *entity, void *target, int a, float f0, float f1);
extern void func_002AFDD8(void *entity, void *out, void *target, int a);
extern void func_0029FCC0(void *entity, int a, void *out);
extern u8 *func_002BDCE8(void *p, float f0, float f1, float f2, int z, void *local,
                         float f3, int v, int t);
extern int func_00283CF0(float f);
extern void func_002B0990(void *entity, float *target, float f, int a, int b);

/* The level's own float, reached through $gp. */
extern float D_L03_001B1BF0 __attribute__((sda));

/* What the engine builds a particle from: two words, then two floats. */
typedef struct {
    s32 a;
    s32 b;
    f32 c;
    f32 d;
} ParticleSetup;

/* The stream table itself is `lui $v0,0x20 ; addiu $v0,$v0,-0x4A60` (absolute). */
extern u8 *D_L03_001FB5A0[];

/* Picks the entity's next behaviour.  A global word chooses it when it is not
 * negative; else the state's own counters do, each one running down as it is
 * used.  Every behaviour sets up its timers and calls. */
void func_L03_003F62C8(u8 *entity) {
    u8 *state = *(u8 **)(entity + 0x68);
    s32 sel;

    if (D_L03_001B108C >= 0) {
        sel = D_L03_001B108C;
    } else if (state[0x30A] != 0) {
        state[0x30A]--;
        sel = 1;
    } else if (state[0x309] != 0) {
        state[0x309]--;
        sel = 0;
    } else if (state[0x30B] != 0) {
        state[0x30B]--;
        sel = 2;
    } else {
        sel = func_002A77E0(state[0x308] + 1);
    }

    switch (sel) {
    case 0:
        func_002A7750(entity, 7, 3);
        if (state[0x308] >= 2) {
            *(float *)(state + 0x2F8) = 0.6981318f;
            *(float *)(state + 0x2FC) = -0.6981318f;
        } else if (func_002A77E0(2) != 0) {
            *(float *)(state + 0x2F8) = 0.6981318f;
        } else {
            *(float *)(state + 0x2FC) = -0.6981318f;
        }
        state[0x30B] = 1;
        break;
    case 1:
        *(u32 *)(state + 0x2E4) = 300;
        func_002A7750(entity, 9, 4);
        state[0x309] = func_002A77E0(2) + 1;
        break;
    case 2:
        *(u32 *)(state + 0x2E4) = D_L03_001B1058;
        func_002A7750(entity, 12, 5);
        state[0x309] = 1;
        break;
    }
}

/* Walks the entity's stream, storing 1 at +0x2D6 of every record whose halfword
 * at +0xAA is 0xFFC.  Twin of func_L01_003B5290 (same file layout, level 1). */
void func_L03_0041D0A8(u8 *entity) {
    u8 *list;
    u8 *p;
    u8 *base;

    if (entity[0x21] == 0xFF)
        return;
    list = D_L03_001FB5A0[entity[0x21]];
    if (list == 0)
        return;
    p = list;
    base = D_L03_001B2A1C;
    for (;;) {
        u8 *q = base + ((*(unsigned short *)p & 0x7FFF) << 8);

        if (*(signed char *)(q + 0x20) >= 0) {
            if (*(short *)(q + 0xAA) == 0xFF3) {
                *(short *)(*(u8 **)(q + 0x68) + 0x2D6) = 1;
            }
        }
        if (*(short *)p < 0)
            break;
        p += 2;
    }
}

/* Same walk as func_L03_0041D0A8 after seeding two state halfwords. */
void func_L03_0041E240(u8 *entity) {
    u8 *state = *(u8 **)(entity + 0x68);
    u8 *list;
    u8 *p;
    u8 *base;

    *(short *)(state + 0x336) = 1;
    *(short *)(state + 0x330) = 0xF0;
    if (entity[0x21] == 0xFF)
        return;
    list = D_L03_001FB5A0[entity[0x21]];
    if (list == 0)
        return;
    p = list;
    base = D_L03_001B2A1C;
    for (;;) {
        u8 *q = base + ((*(unsigned short *)p & 0x7FFF) << 8);

        if (*(signed char *)(q + 0x20) >= 0) {
            if (*(short *)(q + 0xAA) == 0xFFC) {
                *(short *)(*(u8 **)(q + 0x68) + 0x336) = 1;
            }
        }
        if (*(short *)p < 0)
            break;
        p += 2;
    }
}

/* Sets the entity's two blend channels up, then fires two particles: the engine builds
 * each one from the state's direction, a random count and a colour, and the caller fills
 * the record's own fields in.  The two blocks fill the FIRST particle's header again, and
 * the second one keeps its own pointer to the sub-record: both are the original's own
 * wording, and the compiler's schedule depends on it. */
void func_L03_0041DFA8(u8 *entity) {
    u8 *state = *(u8 **)(entity + 0x68);
    float buf[4];
    ParticleSetup setup;
    float vec[4];
    u16 timer;
    s32 count;
    f32 f;
    u8 *particle;
    u8 *particle2;
    u8 *data;
    u8 *data2;

    func_00282948(state + 0x34C);
    func_00282978(state + 0x330);
    func_00282978(state + 0x332);
    func_002AEC48(entity, state + 0x220, 0, 0.03f, 0.3f);
    func_002AEC48(entity, state + 0x2A0, 1, 0.03f, 0.3f);
    timer = *(u16 *)(entity + 0x96);
    if (timer <= 0xFFFE)
        *(u16 *)(entity + 0x96) = timer + 1;
    func_002AFDD8(entity, buf, state + 0x1A0, 0);
    f = buf[1] * D_L03_001B1BF0;
    *(float *)(entity + 0xF0) = f;
    /* The four words the engine reads the particle's setup from, in the order the
     * original stores them. */
    setup.a = 0;
    setup.c = -0.02f;
    setup.d = 1.0f;
    setup.b = 0;
    count = func_002A77E0(16);
    if (func_002A77E0(2))
        count = -count;
    func_0029FCC0(entity, 4, vec);
    vec[2] += 0.1f;
    particle = func_002BDCE8(vec, 0.1f, 1.0f, 0.9f, count, &setup,
                             105000.0f, 0xDF204080, 0);
    if (particle != 0) {
        data = particle + 0x20;
        *(u16 *)(particle + 0xA) = 5;
        particle[9] = func_00283CF0(4.0f) + 0x70;
        *(u32 *)(data + 4) = 2;
        data[0xA] = 0xDF;
        data[0xB] = particle[0xA];
    }
    particle2 = func_002BDCE8(vec, 0.1f, 1.0f, 0.9f, count, &setup,
                              105000.0f, 0xDF204080, 0);
    data2 = particle2;
    if (data2 != 0) {
        *(u16 *)(particle + 0xA) = 5;
        data2 += 0x20;
        particle[9] = func_00283CF0(4.0f) + 0x70;
        *(u32 *)(data2 + 4) = 2;
        data2[0xA] = 0xDF;
        data2[0xB] = particle[0xA];
    }
    if (entity[0x31] != 0)
        func_002B0990(entity, (float *)(state + 0x360), 2.5f, 5, 1);
}
