/* from src/levels/11_joba/L11_003D6270-g8.c: C that compiles but does not match yet */
/* Runs the two records of the object's state through the engine's angle helpers and
   folds the object's measured direction into them. Needs the -g8 profile (the walk
   length is reached through $gp) and a -g8.c source unit when checked again. */
extern void func_00282C88(TI128 *a0);

extern void func_00282F20(f32 *dst, f32 *a, f32 len);

extern f32 func_00283180(f32 a0);

extern f32 func_00283198(f32 a0);

extern f32 func_00283B98(f32 a0, f32 a1);

extern f32 D_L11_001B05DC __attribute__((sda));

typedef int TI128 __attribute__((mode(TI)));

void func_L11_003F4060(u8 *arg0) {
    u8 *s4 = arg0;
    u8 *s3 = *(u8 **)(s4 + 0x68);
    f32 vec[4];
    u8 *rec;
    u8 *p;
    s32 i;

    for (i = 0; i < 2; i++) {
        s32 j;

        rec = s3 + 0xA0 + i * 0xA0;
        func_00282C88((TI128 *)vec);
        if (*(s16 *)(s3 + i * 2 + 0x278) != 1) {
            func_00282F20(vec, (f32 *)(s4 + 0xE0), D_L11_001B05DC);
        }
        p = rec;
        for (j = 1; j >= 0; j--) {
            func_00283B98(*(f32 *)(p + 0x40), *(f32 *)(p + 0x60));
            *(f32 *)(p + 0x40) = func_00283B98(*(f32 *)(p + 0x44), *(f32 *)(p + 0x64));
            *(f32 *)(p + 0x44) = func_00283B98(*(f32 *)(p + 0x48), *(f32 *)(p + 0x68));
            *(f32 *)(p + 0x48) = func_00283180(*(f32 *)(p + 0x40));
            *(f32 *)(p + 0x20) = vec[0] + *(f32 *)(p + 0x48) * *(f32 *)(p + 0x80);
            *(f32 *)(p + 0x24) = vec[1] + func_00283198(*(f32 *)(p + 0x44)) * *(f32 *)(p + 0x84);
            *(f32 *)(p + 0x28) = vec[2] - func_00283198(*(f32 *)(p + 0x48)) * *(f32 *)(p + 0x88);
            p += 0x10;
        }
    }
}
