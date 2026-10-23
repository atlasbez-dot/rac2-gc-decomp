/* Retained plain-C attempt: 292/292 bytes; first difference +0x10.
 * us: 0/27, pal: 0/27, us2: 0/27.
 * Profile: -O2 -G8 -ffunction-sections -g.
 * Saved-register permutation remains after -g restored the division label padding. Next: independent lifetime evidence for the axis/base/position locals.
 */
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float v[4]; } Vector;
extern float func_002A7878(float low, float high);
extern void func_0029FCC0(char *object, int joint, void *out);
extern void func_L00_0033C0D0(char *object, void *position, void *velocity, void *parameters, int mode);
extern char D_L00_001B02E8 __attribute__((sda));
extern char D_L00_001B02F8 __attribute__((sda));
extern char D_L00_001B0308 __attribute__((sda));


extern char D_00189E20[] __attribute__((nosda));
extern float func_00283CE0(int value);
extern float func_00283180(float angle);
extern float func_00283198(float angle);
extern float func_002831B0(float value);
extern void func_00282F20(void *out, void *vector, float scale);
extern void func_00282CC0(void *out, void *left, void *right);
extern void func_00282CF0(void *out, void *left, void *right);
extern void func_00282D30(void *out, void *vector, float scale);
extern float func_00282DB0(void *left, void *right);
extern float func_00282DF0(void *vector);
extern float func_002AA898(float *position, float *velocity, int direction, float target, float acceleration, float damping, float limit);


extern float D_L00_001B03D4 __attribute__((sda));
extern float D_L00_001B03DC __attribute__((sda));
extern float D_L00_001B03E0 __attribute__((sda));
extern float D_L00_001B03E4 __attribute__((sda));
extern int func_L00_002AE888(void *axis, int mode, int flag, float value, float z, float low, float high);
extern void func_002FDF40(void *velocity, void *position, int handle, int mode, float a, float b, float c, float d);
extern void func_002ACEC0(void *out, void *source, void *axis, float angle);

void func_L00_003D3FB0(void *unused, char *position)
{
    Vector temporary;
    float scale = 1.2f;
    float angle = func_00283CE0(*(int *)(position + 0x38));
    char *base;
    char *axis;
    float wave;
    wave = func_00283CE0(3);
    wave = 3.1415927f / wave;
    angle *= wave;
    base = D_00189E20;
    axis = *(char **)(base + 0x2290);
    axis += 0xd0;
    wave = func_00283180(angle);
    func_00282F20(&temporary, axis, wave * scale);
    func_00282CC0(position, &temporary, base + 0x80);
    axis = *(char **)(base + 0x2290);
    axis += 0xe0;
    wave = func_00283198(angle);
    func_00282F20(&temporary, axis, wave * scale + 2.2f);
    func_00282CC0(position, position, &temporary);
    axis = *(char **)(base + 0x2290);
    axis += 0xc0;
    wave = func_00283198(angle);
    func_00282F20(&temporary, axis, wave + wave);
    func_00282CC0(position, position, &temporary);
}
