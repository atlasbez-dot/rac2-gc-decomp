/* Nonmatching reconstruction; game compiler, -O2 -G8 -ffunction-sections.
   us: 16_snivelak: instruction at +0x8c differs.
   us2: 16_snivelak: instruction at +0x8c differs.
   pal: 16_snivelak: instruction at +0x8c differs.
   Same 788-byte extent. Packet field stores, zero float stores and rotation load allocation differ from +0x8c. Reopen with a typed render-packet layout and measured field order. */
typedef unsigned int u32;
typedef int s32;
typedef float f32;
extern s32 D_L16_001B1C38 __attribute__((sda));
extern f32 func_002A78D8(f32, f32);
extern s32 func_00283CF0(f32);
extern void func_L16_00418218(char *);
extern unsigned long long func_0027C878(s32);
extern void func_00283410(char *, char *);
extern void func_00282D30(char *, char *, f32);
extern void func_00280B90(char *, char *, s32);

/* Draws two textured layers, independently fading each corner's color. */
void func_L16_004182A8(char *self, f32 *position, s32 rgb, s32 alpha, s32 secondAlpha) {
    char vertices[0x90];
    char matrix[0x40];
    f32 rotation[4];
    char *st = *(char **)(self + 0x68);
    alpha -= func_00283CF0(func_002A78D8(0.0f, 5.0f)) << 24;
    func_L16_00418218(vertices);
    *(f32 *)(vertices + 0x50) = *(f32 *)(st + 0x10);
    *(f32 *)(vertices + 0x58) = *(f32 *)(st + 0x10);
    *(f32 *)(vertices + 0x5C) = 1.0f;
    *(f32 *)(vertices + 0x60) = *(f32 *)(st + 0x10) + 1.0f;
    *(f32 *)(vertices + 0x6C) = 1.0f;
    *(f32 *)(vertices + 0x68) = *(f32 *)(st + 0x10) + 1.0f;
    *(s32 *)(vertices + 0x54) = 0;
    *(s32 *)(vertices + 0x64) = 0;
    *(unsigned long long *)(vertices + 0x78) = func_0027C878(D_L16_001B1C38);
    *(s32 *)(vertices + 0x40) = rgb + alpha;
    *(unsigned long long *)(vertices + 0x88) = 0x8000000048ULL;
    *(unsigned long long *)(vertices + 0x80) = 0xFF9000000260ULL;
    *(unsigned long long *)(vertices + 0x70) = 0;
    alpha -= func_00283CF0(func_002A78D8(0.0f, 9.0f)) << 24;
    *(s32 *)(vertices + 0x44) = rgb + alpha;
    alpha -= func_00283CF0(func_002A78D8(0.0f, 9.0f)) << 24;
    *(s32 *)(vertices + 0x48) = rgb + alpha;
    alpha -= func_00283CF0(func_002A78D8(0.0f, 9.0f)) << 24;
    *(s32 *)(vertices + 0x4C) = rgb + alpha;
    rotation[0] = 1.5707964897155762f;
    rotation[1] = *(f32 *)(self + 0xF4);
    rotation[2] = *(f32 *)(self + 0xF8);
    rotation[3] = 0;
    func_00283410(matrix, (char *)rotation);
    *(f32 *)(matrix + 0x30) = position[0];
    *(f32 *)(matrix + 0x34) = position[1];
    *(f32 *)(matrix + 0x38) = position[2];
    *(f32 *)(matrix + 0x3C) = 1.0f;
    func_00282D30(vertices, vertices, 1.0f);
    func_00282D30(vertices + 16, vertices + 16, 1.0f);
    func_00282D30(vertices + 32, vertices + 32, 1.0f);
    func_00282D30(vertices + 48, vertices + 48, 1.0f);
    func_00280B90(vertices, matrix, 0);
    *(f32 *)(vertices + 0x50) = *(f32 *)(st + 0x18);
    *(f32 *)(vertices + 0x58) = *(f32 *)(st + 0x18);
    *(f32 *)(vertices + 0x5C) = 1.0f;
    *(unsigned long long *)(vertices + 0x88) = 0x8000000044ULL;
    *(s32 *)(vertices + 0x54) = 0;
    secondAlpha -= func_00283CF0(func_002A78D8(0.0f, 9.0f)) << 24;
    *(s32 *)(vertices + 0x40) = rgb + secondAlpha;
    secondAlpha -= func_00283CF0(func_002A78D8(0.0f, 9.0f)) << 24;
    *(s32 *)(vertices + 0x44) = rgb + secondAlpha;
    secondAlpha -= func_00283CF0(func_002A78D8(0.0f, 9.0f)) << 24;
    *(s32 *)(vertices + 0x48) = rgb + secondAlpha;
    secondAlpha -= func_00283CF0(func_002A78D8(0.0f, 9.0f)) << 24;
    *(s32 *)(vertices + 0x4C) = rgb + secondAlpha;
    *(f32 *)(vertices + 0x60) = *(f32 *)(st + 0x18) + 1.0f;
    *(f32 *)(vertices + 0x6C) = 1.0f;
    *(f32 *)(vertices + 0x68) = *(f32 *)(st + 0x18) + 1.0f;
    *(s32 *)(vertices + 0x64) = 0;
    func_00280B90(vertices, matrix, 0);
}
