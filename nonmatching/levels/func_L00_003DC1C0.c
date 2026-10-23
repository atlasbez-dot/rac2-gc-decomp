/* Retained plain-C attempt: 264/268 bytes; first difference +0x14.
 * us: 0/27, pal: name absent, us2: 0/27.
 * Profile: -O2 -G8 -ffunction-sections -g.
 * The entry pointer copy is folded into its +0x10 addition. Next: evidence for the original address-carrier type or lifetime.
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

int func_L00_003DC1C0(char *object, void *velocity)
{
    char *position = object;
    char *base = D_00189E20;
    char *axis;
    int handle;
    float speed;
    position += 0x10;
    handle = func_L00_002AE888(*(char **)(base + 0x2290) + 0xc0, 5, 0,
                    D_L00_001B03DC, *(float *)(base + 0x98), 0.3926991f, 0.3926991f);
    speed = func_002A7878(D_L00_001B03E0, D_L00_001B03DC);
    func_002FDF40(velocity, position, handle, 0, D_L00_001B03E0, speed,
                 D_L00_001B03D4 * 0.016666668f, D_L00_001B03E4 * 0.00027777778f);
    if (handle == 0) {
        axis = *(char **)(base + 0x2290);
    axis += 0xe0;
        func_002ACEC0(velocity, velocity, axis, func_002A7878(-0.19634955f, 0.19634955f));
    }
    return handle;
}
