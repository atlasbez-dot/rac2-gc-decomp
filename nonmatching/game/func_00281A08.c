/* Complete manual reconstruction; NOT MATCHING and never linked.
   Tested profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   Actual final-source coverage: us: 0/7 placements, 968 compiled bytes; us2: 0/7 placements, 968 compiled bytes; pal: 0/7 placements, 968 compiled bytes.
   968/980 bytes, frame 0x9E0 versus 0xA00. The 16 real 0x90 packets and 64-byte matrix, all 8 GPR inputs, 32-bit colors, interpolation steps and ring update are retained. Argument spills, global-table addressing and register allocation differ.
   Reopen only with: Independent evidence for argument/local lifetime and real UV table extent/storage; retain the full matrix fourth row.
*/

#include "include_asm.h"
typedef unsigned long u64;
typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 bits; float f[4]; } UiVector;
typedef struct { UiVector vertices[4]; unsigned int colors[4]; float uv[4][2];
                 u64 primitive, texture, state, flags; } UiDrawPacket;
extern float func_00283CE0(int);
extern unsigned int func_00283D38(int, int, float);
extern u64 func_0027C878(int);
extern void func_002839D0(void *, void *);
extern void func_002830C0(void *, void *, void *);
extern void func_00280B90(void *, int, int);
extern int D_001A89D0, D_001A89D4, D_001A89D8;
extern float D_001A89E0[][2];

void func_00281A08(UiVector *vertices, int vertex_count, UiVector *positions,
                   UiVector *rotations, int phase, int steps,
                   int first_color, int last_color, float blend)
{
    UiDrawPacket packets[16];
    UiVector matrix[4];
    int ring, i, step;
    float increment;
    unsigned int color;
    if (steps < 2)
        return;
    ring = 2;
    increment = 1.0f / func_00283CE0(steps - 1);
    blend *= increment;
    color = func_00283D38(first_color, last_color, increment);
    for (i = 0; i < (vertex_count >> 1); i++) {
        int j;
        packets[i].texture = func_0027C878(D_001A89D0);
        packets[i].colors[1] = color;
        packets[i].state = 0xFF9000000260UL;
        packets[i].primitive = 5;
        packets[i].flags = ((long)D_001A89D4 << 2) | ((long)D_001A89D8 << 6) | 0x8000000000UL;
        packets[i].colors[0] = color;
        for (j = 3; j >= 0; j--) {
            int index = 3 - j;
            packets[i].uv[index][0] = D_001A89E0[index][0];
            packets[i].uv[index][1] = D_001A89E0[index][1];
        }
    }
    func_002839D0(&rotations[phase], matrix);
    matrix[3].bits = positions[phase].bits;
    matrix[3].f[3] = 1.0f;
    for (i = 0; i < vertex_count; i++)
        func_002830C0(&packets[i >> 1].vertices[i & 1], vertices + i, matrix);
    for (step = 1; step < steps; step++) {
        unsigned int next_color;
        int next_ring;
        phase = (phase + steps - 1) % steps;
        func_002839D0(&rotations[phase], matrix);
        matrix[3].bits = positions[phase].bits;
        matrix[3].f[3] = 1.0f;
        next_color = func_00283D38(first_color, last_color, blend);
        blend += increment;
        if (blend > 1.0f)
            blend = 1.0f;
        next_ring = ring + 2;
        for (i = 0; i < vertex_count; i++) {
            int slot = ring + (i & 1);
            func_002830C0(&packets[i >> 1].vertices[slot], vertices + i, matrix);
            packets[i >> 1].colors[slot] = next_color;
        }
        ring = next_ring % 4;
        for (i = 0; i < (vertex_count >> 1); i++)
            func_00280B90(&packets[i], 0, 1);
    }
}
