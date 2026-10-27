/* mid-9 draft: pointer-walk loop (404 B vs 424). Retail keeps three pointer IVs (p, p+0x10, p+0x30 in $s2/$s0/$s1), an up-counter (slti 0x80) and the floats 0.35f/0.08f hoisted into $f21/$f20 (0x40 frame); this cc1 counts down, rematerialises the constants and keeps only one IV. First call arg is 0.025f (0x3CCCCCCD). Needs -G8. */
#include "common.h"

extern char D_L05_00268E20[];
extern int D_L05_001B2350 __attribute__((sda));

extern void func_41D218(char *, char *, int, int, float);
extern float func_332C18(void);
extern void func_305768(float, float, float, char *, int, int, int);

void func_L05_0041CFE8(int key) {
    float a = 0.35f;
    float b = 0.08f;
    char *p = D_L05_00268E20;
    int i;

    i = 0;
    do {
        i++;
        if (*(int *)(p + 0x40) == key) {
            func_41D218(p, p + 0x10, 0x807F7F7F, D_L05_001B2350, 0.025f);
            func_41D218(p, p + 0x10, 0x60008000, D_L05_001B2350, 0.05f);
            func_305768(1.35f, a, func_332C18(), p + 0x30, 0x31, 0x60008000, 1);
            func_305768(1.0f, a, func_332C18(), p + 0x30, 0x31, 0x807F7F7F, 1);
            func_305768(0.125f, b, func_332C18(), p + 0x10, 0x31, 0x60008000, 1);
            func_305768(b, b, func_332C18(), p + 0x10, 0x31, 0x807F7F7F, 1);
        }
        p += 0x50;
    } while (i < 128);
}
