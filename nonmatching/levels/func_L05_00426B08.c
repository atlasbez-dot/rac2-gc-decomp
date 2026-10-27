/* func_L05_00426B08: M15 2026-10-26: 212/212, 4 lines off under -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier: a Moby struct view fixes the 0xF8 store against the $gp read, and D_L05_001B2528 as an .sdata macro word gives the tied read. Left: retail loads 0xFBF into a register before the loop (xor), cc1 folds it to xori (permuter queued).
 */
typedef int TI128 __attribute__((mode(TI)));

typedef struct Moby_426B08 {
    char pad0[0x10];
    TI128 pos;
    char pad20[0x24 - 0x20];
    float *cls;
    struct Moby_426B08 *next;
    float f2C;
    unsigned char b30;
    unsigned char b31;
    unsigned short h32;
    char pad34[0xAA - 0x34];
    short oclass;
    char padAC[0xF0 - 0xAC];
    float vF0[2];
    float fF8;
} Moby_426B08;

extern Moby_426B08 *func_0029EFD0(int);
extern void func_00282C88(void *);
extern float func_002A7940(void);
extern Moby_426B08 *D_L05_001B1504 __attribute__((sda));
extern Moby_426B08 *D_L05_001B2528 __attribute__((section(".sdata")));
extern void func_L05_00426D98(Moby_426B08 *);

Moby_426B08 *func_L05_00426B08(Moby_426B08 *src)
{
    Moby_426B08 *m = func_0029EFD0(0x117F);

    if (m != 0) {
        m->b30 = 0xFF;
        m->h32 = 0xFF;
        m->b31 = 1;
        m->pos = src->pos;
        func_00282C88(m->vF0);
        m->fF8 = func_002A7940();
        if (D_L05_001B1504 == 0) {
            Moby_426B08 *p = D_L05_001B2528;

            if (p != 0) {
                Moby_426B08 *r = 0;
                int id = 0xFBF;

                do {
                    if (p->oclass == id)
                        r = p;
                    p = p->next;
                } while (p != 0);
                D_L05_001B1504 = r;
            }
        }
        func_L05_00426D98(m);
        m->f2C = m->cls[9];
        return m;
    }
    return 0;
}
