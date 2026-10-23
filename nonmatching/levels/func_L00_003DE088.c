/* Retained plain-C attempt: 252/252 bytes; first difference +0x30.
 * us: 0/27, pal: 0/27, us2: 0/27.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * The constant-255 register and initial byte/halfword stores are scheduled differently; the quadword copies and later call sequence agree. Next: independently established header-field types/lifetimes.
 */
typedef int Quad __attribute__((mode(TI)));
extern char D_00189E20[] __attribute__((nosda));
extern char *D_L00_001B043C __attribute__((sda));
extern int D_L00_001B2B4C;
extern float D_L00_001B0448 __attribute__((sda));
extern float D_L00_001B044C __attribute__((sda));
extern char D_L00_00247800[] __attribute__((nosda));
extern Quad D_L00_001B2B30 __attribute__((sda));
extern char *func_0029EFD0(int type);
extern void func_002833F0(void *out, void *vector);
extern int func_002A0F48(void *object);
extern int func_002FED90(void *object, int mode, float x, float y, float z);
extern void func_00282D30(void *out, void *source, float scale);
extern void func_00282F20(void *out, void *source, float scale);
extern void func_00282CC0(void *out, void *left, void *right);


char *func_L00_003DE088(Quad *position, Quad *velocity)
{
    char *object = func_0029EFD0(0xb58);
    char *state;
    char *base;
    int visibility = 255;
    if (object != 0) {
        state = *(char **)(object + 0x68);
        *(unsigned char *)(object + 0x30) = visibility;
        *(short *)(object + 0x32) = visibility;
        *(Quad *)(object + 0x10) = *position;
        *(Quad *)state = *velocity;
        *(unsigned char *)(object + 0x20) = 0;
        *(unsigned short *)(object + 0x34) |= 0x100;
        *(float *)(object + 0x2c) *= 0.25f;
        base = D_00189E20;
        *(float *)(object + 0xf0) = *(float *)(base + 0x90);
        *(float *)(object + 0xf4) = *(float *)(base + 0x94);
        *(float *)(object + 0xf8) = *(float *)(base + 0x98);
        func_002833F0(object + 0xc0, object + 0xf0);
        *(int *)(state + 0x1c) = 0x7f000000;
        D_L00_001B043C = object;
        func_002A0F48(object);
        D_L00_001B2B4C = func_002FED90(object, 0, 1.0f, 1.0f, 1.0f);
    }
    return object;
}
