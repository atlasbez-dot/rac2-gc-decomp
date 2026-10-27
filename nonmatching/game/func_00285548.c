/* Mid worker 7: near-miss draft of boot func_00285548 (448 B), file flags -O2 -G8 (src/game/00284FC0.c).
   Header words, the GS packet constants, the (x << 4) + 0x8000 - (y << 3) corner arithmetic (kept as separate
   locals so the 0x8000 stays in a register) and the sda-pointer idiom (lui+lw loads, $gp store in the call's
   delay slot) match. 416 B vs 448 B: retail reloads the packet pointer (`lui/lw 0x22A8`) after the quadword stores
   before adding 0x60, this cc1 folds it into the new-pointer register; and the ten constant loads are scheduled
   later than retail's. No spelling tried makes the stores clobber the cached pointer. */
extern int *D_001B22A8 __attribute__((sda));
extern void func_002FC518(int);
extern void func_002FC560(unsigned int, unsigned long long);

void func_00285548(int a0, int a1, int a2, int a3, int a4, int a5, unsigned int a6)
{
    long long *q;
    int x0;
    int y0;
    int x1;
    int y1;

    func_002FC518(0x13000000);
    func_002FC560(0x42, 0x64);
    *(int *)((char *)D_001B22A8 + 0) = 0x10000006;
    *(int *)((char *)D_001B22A8 + 4) = 0;
    *(int *)((char *)D_001B22A8 + 8) = 0;
    *(int *)((char *)D_001B22A8 + 12) = 0x50000006;
    x0 = (a0 << 4) + 0x8000;
    y0 = (a1 << 4) + 0x8000;
    x1 = (a2 << 4) + 0x8000;
    y1 = (a3 << 4) + 0x8000;
    x0 -= a4 << 3;
    x1 -= a4 << 3;
    y0 -= a5 << 3;
    y1 -= a5 << 3;
    q = (long long *)D_001B22A8;
    D_001B22A8 = (int *)((char *)q + 16);
    q[2] = 0x1000000000000001LL;
    q[13] = x1 | ((long long)y1 << 16);
    q[3] = 0xE;
    q[9] = a6;
    q[12] = x0 | ((long long)y0 << 16);
    q[4] = 0x33003;
    q[5] = 0x47;
    q[6] = 0x2400000000000001LL;
    q[7] = 0x10;
    q[8] = 0x106;
    q[10] = 0x2400000000008001LL;
    q[11] = 0x44;
    D_001B22A8 = (int *)((char *)D_001B22A8 + 0x60);
    func_002FC560(0x42, 0x8000000044LL);
    func_002FC518(0x13000000);
}
