/* Nonmatching reconstruction, checked 2026-10-23.
   Profile: game -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
   USA v1.01 and USA v2.00: 0/1 carrying placements each.
   PAL: this canonical function is absent from both catalogues.
   928/928 bytes; first difference +0xE8. The two global vector copies materialize their source/destination addresses in different orders and use different register roles. Scalar SDA declarations recovered retail size. A TI temporary and a union-vector spelling did not improve the final arrangement. Reopen with a source or copy-profile remedy for those two address evaluations.
   No linked build was run for this draft.
*/

typedef int Vector __attribute__((mode(TI)));
extern int D_L02_001B02C0 __attribute__((sda));
extern int D_L02_001B0200 __attribute__((sda));
extern float D_L02_001B02D0 __attribute__((sda));
extern float D_L02_001B02D4 __attribute__((sda));
extern float D_L02_001B02A8 __attribute__((sda));
extern float D_L02_001B02AC __attribute__((sda));
extern int D_L02_001B02B0 __attribute__((sda));
extern char D_L02_001B0290 __attribute__((sda));
extern float D_L02_001B01EC __attribute__((sda));
extern float D_L02_001B01F0 __attribute__((sda));
extern int D_L02_001B01F4 __attribute__((sda));
extern float D_L02_001B0214 __attribute__((sda));
extern char D_L02_001B0230 __attribute__((sda));
extern char D_L02_001B0260 __attribute__((sda));
extern float D_L02_001BA500[4];
extern void *func_0029FCC0(char *, int, void *);
extern void func_0029FC20(char *, int, void *);
extern float func_00282DF0(void *);
extern float func_002A7878(float, float);
extern int func_002A77E0(int);
extern void func_002830C0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_002ACB48(void *, float);
extern void func_L02_003449D8(void *, void *, void *, int, int);

void func_L02_003D5F50(char *self, int joint, int mirror) {
    float origin[4];
    float matrix[16];
    float direction[4];
    float velocity[4];
    float position[4];
    float offset_a[4];
    float offset_b[4];
    float delta[4];
    float strength;
    float magnitude;
    int i;
    func_0029FCC0(self, joint, origin);
    func_0029FC20(self, joint, matrix);
    *(Vector *)direction = *(Vector *)(matrix + 8);
    strength = func_00282DF0(*(char **)(self + 0x68) + 0x1B0) * 3.333333f + func_002A7878(0.0f, 0.1f);
    if (strength > 1.0f) strength = 1.0f;
    else if (strength < 0.0f) strength = 0.0f;
    *(Vector *)offset_a = *(Vector *)&D_L02_001B02C0;
    *(Vector *)offset_b = *(Vector *)&D_L02_001B0200;
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
        func_L02_003449D8(position, velocity, &D_L02_001B0290, func_002A77E0(2), 1);
    }
    func_002830C0(position, offset_b, matrix);
    func_00282CC0(position, position, origin);
    for (i = 0; (float)i < strength * (float)D_L02_001B01F4 + 2.0f; i++) {
        magnitude = func_002A7878(0.0f, strength * D_L02_001B01F0);
        func_00282F20(velocity, direction, -((D_L02_001B01EC + magnitude) * 0.016666668f));
        func_002ACB48(position, D_L02_001B0214);
        func_L02_003449D8(position, velocity, &D_L02_001B0230, func_002A77E0(2), 1);
        magnitude = func_002A7878(0.0f, strength * D_L02_001B01F0);
        func_00282F20(velocity, direction, -((D_L02_001B01EC + magnitude) * 0.016666668f));
        func_002ACB48(position, D_L02_001B0214);
        func_L02_003449D8(position, velocity, &D_L02_001B0260, func_002A77E0(2), 1);
    }
}
