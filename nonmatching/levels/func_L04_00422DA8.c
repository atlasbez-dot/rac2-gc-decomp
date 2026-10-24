/* USA v1.01/v2.00/PAL checked, 0/1 each; default G0, 944/976
 * bytes. Structured flare state and integer base indexing reduce the
 * original 992-byte draft. Register allocation, float clamp scheduling,
 * and loop address lifetimes remain. Reopen with retail data layout
 * and compiler induction-variable evidence.
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef float f32;
struct BarlowFlareState {
    u8 *object;
    int active;
    f32 intensity;
    int unused0C;
    s16 opacity[14];
    int unused2C;
    s16 texture[14];
    int unused4C;
    u32 colors[14];
    int unused88[2];
    f32 displacement[14];
    int unusedC8[2];
    f32 size[14];
};
extern struct BarlowFlareState D_L04_001B9980;
extern int D_001A7348, D_001A734C, D_001A7350, D_001A7354;
extern int D_L04_001B0D08;
extern u8 D_L04_001B9680[];
extern f32 func_00282E48(void *, void *);
extern f32 func_00283CE0(int);
extern void func_00279BD8(void *, void *);
extern int func_0027C878(int);
extern f32 func_00282C48(f32);
extern int func_00283CF0(f32);
extern void func_002FC560(int, unsigned long long);
extern void func_0027E018(int, int, int, int, int, int, int, int, long long, long long);

void func_L04_00422DA8(u8 *object) {
    struct BarlowFlareState *flare = &D_L04_001B9980;
    u8 *data = *(u8 **)(object + 0x68);
    f32 projected[4], center[4], offset[4], displacement[4], screen[4];
    f32 distance, fade, edge, vertical, half;
    int i, texture, alpha, size, x, y;
    u32 color;
    if (flare->active == 1) {
      if (!(flare->object[0x20] & 0x80)) {
       if (flare->intensity > 0.0f) {
    distance = func_00282E48(D_L04_001B9680, data + 0x30);
    center[0] = func_00283CE0(D_001A7348);
    center[1] = func_00283CE0(D_001A734C);
    func_00279BD8(projected, data + 0x30);
    projected[0] = (projected[0] - func_00283CE0(D_001A7350)) * 0.0625f;
    projected[1] = (projected[1] - func_00283CE0(D_001A7354)) * 0.0625f;
    offset[0] = center[0] - projected[0];
    offset[1] = center[1] - projected[1];
    {
    f32 *sizes = flare->size;
    for (i = 0; i < 14; i++, sizes++) {
        texture = func_0027C878(*(s16 *)((u32)flare + (i << 1) + 0x30) + 0x49);
        displacement[0] = offset[0] * sizes[-16];
        displacement[1] = offset[1] * sizes[-16];
        screen[0] = center[0] + displacement[0];
        screen[1] = center[1] + displacement[1];
        fade = distance - 5.0f;
        if (fade > 1.0f)
            fade = 1.0f;
        else if (fade < 0.0f)
            fade = 0.0f;
        edge = func_00282C48(offset[0]) / center[0] * -5.0f + 5.5f;
        if (edge > 1.0f)
            edge = 1.0f;
        else if (edge < 0.0f)
            edge = 0.0f;
        vertical = func_00282C48(offset[1]) / center[1] * -5.0f + 5.5f;
        if (vertical > 1.0f)
            vertical = 1.0f;
        else if (vertical < 0.0f)
            vertical = 0.0f;
        edge *= vertical;
        edge *= flare->intensity;
        alpha = func_00283CF0(fade * edge * *(s16 *)((u32)flare + (i << 1) + 0x10));
        color = (alpha << 24) | (*(u32 *)((u32)flare + (i << 2) + 0x50) & 0xFFFFFF);
        size = func_00283CF0((f32)D_L04_001B0D08 * *sizes);
        func_002FC560(0x42, 0x8000000048ULL);
        half = (float)(size >> 1);
        x = func_00283CF0(screen[0] - half);
        y = func_00283CF0(screen[1] - half);
        func_0027E018(x, y, size, size, 0, 0, 0x40, 0x40, (int)color, texture);
    }
    }
    flare->intensity = 0.0f;
       }
      } else {
        flare->active = 0;
      }
    } else {
        flare->active = 0;
    }
}
