/* Nonmatching reconstruction; game compiler, -O2 -G8 -ffunction-sections.
   us: 16_snivelak: 256 bytes, expected 268.
   us2: 16_snivelak: 256 bytes, expected 268.
   pal: func_L16_0041EBE8 is in neither catalogue of pal.
   Retail accesses one scalar both absolutely and through GP. A mixed sized-array/alias trial was rejected as untruthful; retained source uses one canonical scalar. Reopen with a truthful mixed access model. */
typedef unsigned char u8;
typedef int s32;
typedef float f32;
extern f32 D_L16_001B1FC4 __attribute__((sda));
extern f32 D_L16_001B1FC8 __attribute__((sda));
extern f32 D_L16_001B1FCC __attribute__((sda));
extern f32 D_L16_001B1FD0 __attribute__((sda));
extern f32 D_L16_001B3AAC __attribute__((sda));
extern s32 func_002B38B8(char *);
extern void func_002A7750(char *, s32, s32);
extern f32 func_00282C48(f32);
extern void func_L16_0041ECF8(char *, f32);

/* Accelerates the rotating group, then settles it into the next state. */
void func_L16_0041EBE8(char *self) {
    switch (*(u8 *)(self + 0x20)) {
    case 0:
        if (func_002B38B8(self)) {
            D_L16_001B1FC4 = 0;
            D_L16_001B3AAC = 0;
            func_002A7750(self, 1, -1);
        }
        break;
    case 1:
        D_L16_001B3AAC += D_L16_001B1FCC * 0.000004848137450608192f;
        D_L16_001B1FC4 += D_L16_001B3AAC;
        if (D_L16_001B1FC4 >= D_L16_001B1FC8 * 0.01745329424738884f) {
            D_L16_001B1FC4 = D_L16_001B1FC8 * 0.01745329424738884f;
            D_L16_001B3AAC = D_L16_001B3AAC * D_L16_001B1FD0;
            if (func_00282C48(D_L16_001B3AAC) < 0.000290888245f)
                func_002A7750(self, 2, -1);
        }
        func_L16_0041ECF8(self, D_L16_001B1FC4);
        break;
    }
}
