/*
 * Retained complete manual reconstruction; not linked or counted.
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections
 * Retail: 928 bytes; compiled: 944 bytes.
 * Final coverage: us: 0/1; us2: 0/1; pal: catalogue absent.
 * Residual: 944/928 bytes. Both global offset captures are full 16-byte vectors; the
 * particle descriptors remain incomplete external records because only a 24-byte prefix
 * is established. Their former char 1-byte declarations and the vector-as-int 4-byte
 * declarations are removed. Source/destination address roles and opaque-record
 * addressing remain different.
 * Reopen: Independent full descriptor storage/layout evidence and measured address
 * lifetimes. The constructor reads pointers at 0/4/8, a duration word at0x10 and float
 * at0x14; 0xC remains unknown. Do not invent total record capacity or use a one-byte
 * extent to force SDA.
 */
#include "common.h"

typedef int Vector __attribute__((mode(TI)));
extern float D_L02_001B02C0[4] __attribute__((sda));
extern float D_L02_001B0200[4] __attribute__((sda));
extern float D_L02_001B02D0 __attribute__((sda));
extern float D_L02_001B02D4 __attribute__((sda));
extern float D_L02_001B02A8 __attribute__((sda));
extern float D_L02_001B02AC __attribute__((sda));
extern int D_L02_001B02B0 __attribute__((sda));
extern char D_L02_001B0290[] __attribute__((sda));
extern float D_L02_001B01EC __attribute__((sda));
extern float D_L02_001B01F0 __attribute__((sda));
extern int D_L02_001B01F4 __attribute__((sda));
extern float D_L02_001B0214 __attribute__((sda));
extern char D_L02_001B0230[] __attribute__((sda));
extern char D_L02_001B0260[] __attribute__((sda));
extern char D_L02_001BA500[];
extern void func_0029FCC0(char *, int, char *);
extern void func_0029FC20(char *, int, char *);
extern float func_00282DF0(void *);
extern float func_002A7878(float, float);
extern int func_002A77E0(int);
extern void func_002830C0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_002ACB48(void *, float);
extern void *func_L02_003449D8(void *, void *, void *, void *, int);

void func_L02_003D5F50(char *self, int joint, int mirror) {
    float origin[4] __attribute__((aligned(16)));
    float matrix[16] __attribute__((aligned(16)));
    float direction[4] __attribute__((aligned(16)));
    float velocity[4] __attribute__((aligned(16)));
    float position[4] __attribute__((aligned(16)));
    float offset_a[4] __attribute__((aligned(16)));
    float offset_b[4] __attribute__((aligned(16)));
    float delta[4] __attribute__((aligned(16)));
    float strength;
    float magnitude;
    int i;
    func_0029FCC0(self, joint, (char *)origin);
    func_0029FC20(self, joint, (char *)matrix);
    qcopy(direction, matrix + 8);
    strength = func_00282DF0(*(char **)(self + 0x68) + 0x1B0) * 3.333333f + func_002A7878(0.0f, 0.1f);
    if (strength > 1.0f) strength = 1.0f;
    else if (strength < 0.0f) strength = 0.0f;
    qcopy(offset_a, D_L02_001B02C0);
    qcopy(offset_b, D_L02_001B0200);
    if (mirror) {
        offset_a[1] = -offset_a[1];
        offset_b[1] = -offset_b[1];
    }
    func_002830C0(position, offset_a, matrix);
    func_00282CC0(position, position, origin);
    func_00282CF0(delta, D_L02_001BA500, position);
    delta[2] = 0.0f;
    func_00282F20(delta, delta, D_L02_001B02D0);
    func_00282CC0(position, position, delta);
    for (i = 0; i < D_L02_001B02B0; i++) {
        magnitude = func_002A7878(0.0f, strength * D_L02_001B02AC);
        func_00282F20(velocity, direction, -((D_L02_001B02A8 + magnitude) * 0.016666668f));
        func_002ACB48(position, D_L02_001B02D4);
        func_L02_003449D8(position, velocity, D_L02_001B0290, (void *)(u32)func_002A77E0(2), 1);
    }
    func_002830C0(position, offset_b, matrix);
    func_00282CC0(position, position, origin);
    for (i = 0; (float)i < strength * (float)D_L02_001B01F4 + 2.0f; i++) {
        magnitude = func_002A7878(0.0f, strength * D_L02_001B01F0);
        func_00282F20(velocity, direction, -((D_L02_001B01EC + magnitude) * 0.016666668f));
        func_002ACB48(position, D_L02_001B0214);
        func_L02_003449D8(position, velocity, D_L02_001B0230, (void *)(u32)func_002A77E0(2), 1);
        magnitude = func_002A7878(0.0f, strength * D_L02_001B01F0);
        func_00282F20(velocity, direction, -((D_L02_001B01EC + magnitude) * 0.016666668f));
        func_002ACB48(position, D_L02_001B0214);
        func_L02_003449D8(position, velocity, D_L02_001B0260, (void *)(u32)func_002A77E0(2), 1);
    }
}
