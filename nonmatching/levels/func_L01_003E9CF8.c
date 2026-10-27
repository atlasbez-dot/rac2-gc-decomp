/* func_L01_003E9CF8: M3 2026-10-26: the draft inverted the reuse test (retail allocates when 0x20 is 0xFE or 0xFD). -G0 with D_001B326C/D_001B3270 as .sdata macro words and the sda store name: the head is exact; 308/324: retail recomputes the entry address twice and copies it through three registers before the five stores (an inline helper?).
 */
typedef unsigned char u8;
typedef int s32;
typedef struct {
    char *obj;
    int rgb;
    int arg;
    float scale;
    void (*cb)(char *);
    int pad[3];
} Ent_3E9CF8;
extern void func_0029F338(void *);
extern char *D_001B326C __attribute__((section(".sdata")));
extern int D_001B3270 __attribute__((section(".sdata")));
extern int D_L01_001B3270 __attribute__((sda));
extern char *func_0029EFD0(int);
extern void func_002A04B8(void *, s32 *, s32 *, s32 *);
extern Ent_3E9CF8 D_L01_002502C0[];

void func_L01_003E9CF8(char *a0, int a1, void (*a2)(char *))
{
    char *p = D_001B326C;
    int x;
    int y;
    int z;
    int n;
    int rgb;
    Ent_3E9CF8 *e;
    if (p == 0 || *(short *)(p + 0xAA) != 0xC41 ||
        *(u8 *)(p + 0x20) == 0xFE || *(u8 *)(p + 0x20) == 0xFD) {
        char *q = func_0029EFD0(0xC41);
        D_001B326C = q;
        *(u8 *)(q + 0x30) = 0xFF;
    }
    *(unsigned short *)(a0 + 0x34) |= 2;
    *(int *)(a0 + 0x48) = 0;
    *(int *)(a0 + 0x44) = 0;
    if (D_001B3270 < 0x40) {
        func_002A04B8(a0, &x, &y, &z);
        e = &D_L01_002502C0[D_001B3270];
        e->obj = a0;
        e->rgb = (z << 16) | (y << 8) | x;
        e->arg = a1;
        e->scale = 1.0f;
        e->cb = a2;
        D_L01_001B3270 = D_001B3270 + 1;
    } else if (a2 != 0) {
        a2(a0);
    } else {
        func_0029F338(a0);
    }
}
