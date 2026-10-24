/* Nonmatching reconstruction; game compiler, -O2 -G8 -ffunction-sections.
   us: 16_snivelak: 392 bytes, expected 356.
   us2: 16_snivelak: 392 bytes, expected 356.
   pal: func_L16_00419140 is in neither catalogue of pal.
   Scalar absolute declarations retain truthful object sizes but increase address hoisting and alter loop allocation. Tested explicit pointer reuse and argument masking. Reopen with a verified absolute-symbol model and loop allocation. */
typedef unsigned int u32;
typedef int s32;
typedef float f32;
extern f32 D_L16_001B1C60 __attribute__((sda));
extern f32 D_L16_001B1C70 __attribute__((sda));
extern s32 D_L16_001B1C78 __attribute__((sda));
extern s32 D_L16_001B1C80 __attribute__((sda));
extern s32 D_L16_001B1C90 __attribute__((sda));
extern f32 D_L16_001B1C64 __attribute__((nosda));
extern f32 D_L16_001B1C68 __attribute__((nosda));
extern f32 D_L16_001B1C6C __attribute__((nosda));
extern f32 D_L16_001B1C74 __attribute__((nosda));
extern s32 D_L16_001B1C7C __attribute__((nosda));
extern s32 D_L16_001B1C84 __attribute__((nosda));
extern s32 D_L16_001B1C88 __attribute__((nosda));
extern s32 D_L16_001B1C8C __attribute__((nosda));
extern void func_002A7A00(char *, f32, f32);
extern s32 func_002A7820(s32, s32);
extern s32 func_002A77E0(s32);
extern void func_002C3150(char *, char *, u32, u32, f32, u32, u32);
extern void func_00282C88(char *);
extern void func_00282CC0(char *, char *, char *);
extern f32 func_002A7878(f32, f32);

/* Emits one central particle and the configured ring of falling particles. */
void func_L16_00419140(char *self) {
    char velocity[16];
    char position[16];
    s32 i;
    s32 kind;
    s32 alpha;
    char *origin = self + 16;
    func_002A7A00(velocity, D_L16_001B1C60 * 0.01666666753590107f,
                  D_L16_001B1C64 * 0.01666666753590107f);
    kind = func_002A7820(D_L16_001B1C80, D_L16_001B1C84) & 255;
    alpha = func_002A77E0(255);
    func_002C3150(origin, velocity, D_L16_001B1C78, kind, D_L16_001B1C70, alpha & 255, 0);
    func_00282C88(velocity);
    for (i = 0; i < D_L16_001B1C90; i++) {
        func_002A7A00(position, 0.0f, 0.25f);
        func_00282CC0(position, position, self + 16);
        *(f32 *)(velocity + 8) = -(func_002A7878(D_L16_001B1C68, D_L16_001B1C6C) * 0.01666666753590107f);
        kind = func_002A7820(D_L16_001B1C88, D_L16_001B1C8C) & 255;
        alpha = func_002A77E0(255);
        func_002C3150(position, velocity, D_L16_001B1C7C, kind, D_L16_001B1C74, alpha & 255, 0);
    }
}
