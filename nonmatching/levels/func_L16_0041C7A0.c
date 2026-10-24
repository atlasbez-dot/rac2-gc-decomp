/* Nonmatching reconstruction; game compiler, -O2 -G0 -ffunction-sections.
   us: 16_snivelak: instruction at +0x60 differs.
   us2: 16_snivelak: instruction at +0x60 differs.
   pal: func_L16_0041C7A0 is in neither catalogue of pal.
   Same 420-byte extent and control flow; four initialization words swap f1/f2. Multiple load/store wordings reached the bound without fixing allocation. Reopen with a structural explanation of the backup-field allocation. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;
extern f32 func_00283B98(f32, f32);
extern f32 func_00283BE0(f32, f32);
extern s32 func_002829D8(char *);
extern void func_L16_0041C948(char *);
extern void func_002A7750(char *, s32, s32);

/* Controls the timed rotation cycle and restores the original settings. */
void func_L16_0041C7A0(char *self) {
    char *st = *(char **)(self + 0x68);
    f32 a, b, angle;
    switch (*(u8 *)(self + 0x20)) {
    case 0:
        *(s32 *)(st + 0) = 0;
        *(s32 *)(st + 4) = 0;
        *(s32 *)(st + 8) = 0;
        *(s32 *)(st + 12) = 0;
        *(s32 *)(st + 16) = 0;
        a = *(f32 *)(st + 20);
        angle = *(f32 *)(self + 0xF0);
        b = *(f32 *)(st + 24);
        *(f32 *)(st + 40) = angle;
        *(s32 *)(st + 36) = *(u8 *)(self + 0xBC);
        *(f32 *)(st + 32) = b;
        *(f32 *)(st + 28) = a;
        func_002A7750(self, 1, -1);
        break;
    case 1:
        if (*(u8 *)(self + 0xBC))
            func_002A7750(self, 4, -1);
        break;
    case 4:
        if (*(s32 *)(st + 16) < 180) {
            *(f32 *)(self + 0xF0) = func_00283B98(*(f32 *)(self + 0xF0), 0.0872664749622345f);
            *(s32 *)(st + 16) += 5;
        } else func_002A7750(self, 2, -1);
        break;
    case 2:
        if (func_002829D8(st + 20)) func_002A7750(self, 3, -1);
        break;
    case 3:
        if (func_002829D8(st + 24)) func_002A7750(self, 5, -1);
        func_L16_0041C948(self);
        break;
    case 5:
        if (*(s32 *)(st + 16) > 0) {
            *(f32 *)(self + 0xF0) = func_00283BE0(*(f32 *)(self + 0xF0), 0.0872664749622345f);
            *(s32 *)(st + 16) -= 5;
        } else {
            *(u8 *)(self + 0xBC) = *(u8 *)(st + 36);
            *(f32 *)(st + 20) = *(f32 *)(st + 28);
            *(f32 *)(st + 24) = *(f32 *)(st + 32);
            *(f32 *)(self + 0xF0) = *(f32 *)(st + 40);
            func_002A7750(self, 1, -1);
        }
        break;
    }
}
