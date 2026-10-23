/* Retained plain-C attempt: 376/376 bytes; first difference +0x8.
 * us: 0/27, pal: 0/27, us2: 0/27.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -fno-schedule-insns.
 * Register allocation and scheduling differ despite the correct frame size and grouped quadword copies. Next: independent lifetimes for the output walker and four stack axes.
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


void func_L00_003DE490(char *object)
{
    Quad axes[4];
    Quad offset, point;
    int i;
    char *out = D_L00_00247800;
    axes[0] = *(Quad *)(object + 0xc0);
    axes[3] = *(Quad *)(object + 0xd0);
    func_00282D30(axes + 1, axes, -1.0f);
    func_00282D30(axes + 2, axes + 3, -1.0f);
    *(Quad *)(out + 0x40) = axes[0];
    *(Quad *)(out + 0x50) = axes[1];
    *(Quad *)(out + 0x60) = axes[2];
    *(Quad *)(out + 0x70) = axes[3];
    object += 0x10;
    for (i = 0; i < 8; i++) {
        if (i < 4)
            func_00282CC0(out, axes + (i >> 1), axes + ((i & 1) + 2));
        func_00282F20(out, out, D_L00_001B044C);
        func_00282CC0(out, out, object);
        func_00282F20(&offset, &D_L00_001B2B30, -D_L00_001B0448);
        func_00282CC0(out, out, &offset);
        func_00282CC0(&point, &offset, object);
        out += 0x10;
    }
}
