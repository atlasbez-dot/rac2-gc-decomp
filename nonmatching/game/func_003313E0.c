/* near miss: 436/416 B at default flags. Retail frame 0x70 (base sp0, vel sp10, pos sp20; only s0-s3), keeps 0x1F2540 base in s3 but rematerialises 83968.0f and &D_001A8BD0 per call; this cc1 hoists them (f21/f22, s4/s5), grows the frame to 0x90 and puts the quad at sp20. */
#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

typedef struct Gf2540 {
    char pad0[0xD4];
    unsigned char *fD4;
    char pad1[0x170 - 0xD8];
    unsigned char *f170;
} Gf2540;

typedef struct Gparticle {
    char pad0[2];
    unsigned char f2;
} Gparticle;

extern Gf2540 D_001F2540;
extern char D_001A8BD0[];

extern void func_00282D30(void *, float);
extern void func_00282CC0(void *, void *, void *);
extern float func_002A7878(float, float);
extern int func_002A77E0(int);
extern Gparticle *func_002C65A0(void *, void *, int, unsigned int, int, int, int, float, float, float, int);

void func_003313E0(TI128 *a0)
{
    TI128 base;
    float vel[4];
    float pos[3];
    int i = 8;
    int rnd;
    Gparticle *p;

    base = *a0;
    func_00282D30(vel, 0.5f);
    func_00282CC0(&base, &base, vel);
    do {
        i--;
        pos[0] = ((float *)&base)[0] + func_002A7878(0.0f, 0.1f);
        pos[1] = ((float *)&base)[1] + func_002A7878(0.0f, 0.1f);
        pos[2] = ((float *)&base)[2] + func_002A7878(0.0f, 0.1f);
        rnd = func_002A77E0(0xFF);
        p = func_002C65A0(pos, D_001A8BD0, 10, 0x407FFF, rnd, 0x7F, 0, 83968.0f, 83968.0f, 0.0f, 1);
        if (p != 0)
            p->f2 = D_001F2540.f170[5];
        p = func_002C65A0(pos, D_001A8BD0, 10, 0x406080, rnd, 0x7F, 0, 83968.0f, 83968.0f, 0.0f, 1);
        if (p != 0)
            p->f2 = *D_001F2540.fD4;
    } while (i >= 0);
}
