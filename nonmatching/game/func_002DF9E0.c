/* Mid worker 7: partial draft of boot func_002DF9E0 (GS display-list writer, 460 B), file flags sdk -O2 -G2.
   Header words, the ptr reload pattern (int * global, stores through casts) and the n = x / 32 division match; the loop
   writing the two quadword streams is merged by this cc1 into one pointer with +-8 offsets and loses retail's separate
   `a1 += 8` steps and the pre-header placement of the two shifted constants (400 B vs 460 B). */
typedef struct { char pad[0x150]; short x; short y; } Screen2DF9E0;
extern Screen2DF9E0 D_001A6480;
extern int *D_001B22A8;

void func_002DF9E0(long long arg)
{
    int x = D_001A6480.x;
    int y = D_001A6480.y;
    int n = x / 32;
    long long *q;
    int *p;
    int i;
    int u;
    int v;

    *(int *)D_001B22A8 = (n + 5) | 0x10000000;
    *(int *)((char *)D_001B22A8 + 4) = 0;
    *(int *)((char *)D_001B22A8 + 8) = 0;
    *(int *)((char *)D_001B22A8 + 12) = (n + 5) | 0x50000000;
    p = D_001B22A8;
    D_001B22A8 = p + 4;
    q = (long long *)D_001B22A8;
    q[0] = 0x1000000000000001LL;
    q[9] = 0x44;
    q[1] = 0xE;
    q[2] = 0x3D801;
    q[3] = 0x47;
    q[4] = 0x2400000000000001LL;
    q[5] = 0x10;
    q[6] = 0x146;
    q[7] = arg;
    q[8] = (long long)(n | 0x8000) | 0x2400000000000000LL;
    q += 10;
    if (n > 0) {
        long long c = (long long)(0x8000 - y * 8) << 16;
        long long d = (long long)(y * 8 + 0x7FF0) << 16;

        u = 0x8000 - x * 8;
        v = 0x8200 - x * 8;
        i = 0;
        do {
            *q++ = u | c;
            *q++ = v | d;
            u += 0x200;
            v += 0x200;
            i++;
        } while (i < n);
    }
    D_001B22A8 = (int *)((char *)D_001B22A8 + n * 16 + 0x50);
    *D_001B22A8 = 0x10000000;
    *(int *)((char *)D_001B22A8 + 4) = 0;
    *(int *)((char *)D_001B22A8 + 8) = 0x13000000;
    *(int *)((char *)D_001B22A8 + 12) = 0;
    D_001B22A8 = D_001B22A8 + 4;
}
