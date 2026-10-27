/* Nonmatching: 572/572 bytes.
 * Profile: -O2 -G8 -ffunction-sections.
 * Placement checks: US: 0/2; US2: 0/2; PAL absent from catalogue.
 * 572/572 bytes. The preheader and loop are recovered with canonical data identities, but the absolute pool-pointer load uses a0 rather than v1 and the address addition follows that allocation. The old artificial three-pointer array alias is removed; the canonical scalar pointer and a halfword view of the real integer global are retained. A pool local at its point of use ties; -mno-split-addresses worsens the body to580 bytes.
 * Reopen with independently evidenced pool-pointer allocation/lifetimes. Keep the real pointer and global word owner, rather than changing array extents to affect addressing.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern int D_L09_001B2878 __attribute__((sda));

extern unsigned char *D_L09_001B285C __attribute__((nosda));

extern unsigned short *D_L09_001FB560[];

extern unsigned char *D_L09_001FE6C0[];

extern int D_L09_001B0F58 __attribute__((sda));

extern float func_00282E80(void *, void *);

extern int func_L09_003F72A8(unsigned char *);

extern int func_L09_003F71C8(unsigned char *, int);

void func_L09_003F8598(unsigned char *a0) {
    unsigned char *s3 = *(unsigned char **)(a0 + 0x68);
    TI128 v;
    unsigned short *p;
    unsigned char *e;
    unsigned char *pool;
    unsigned char *s0;
    unsigned char *best;
    unsigned char *t;
    unsigned short w;
    int idx;
    float bestd;
    float d;
    int n;

    idx = *(int *)(s3 + 0x2C0);
    if (idx == -1)
        return;
    qcopy(&v, D_L09_001FE6C0[idx] + 0x10);
    p = D_L09_001FB560[a0[0x21]];
    best = 0;
    bestd = 100000.0f;
    for (;
         a0[0x21] != 0xFF && a0[0x21] <= D_L09_001B2878 && p != 0 &&
         ((p != 0 && (short)p[-1] >= 0) || p == D_L09_001FB560[a0[0x21]]);
         p++) {
        pool = D_L09_001B285C;
        e = pool + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        s0 = *(unsigned char **)(e + 0x68);
        d = func_00282E80(e + 0x10, &v);
        if (s0 == 0)
            continue;
        if ((s0[0x302] & 1) == 0)
            continue;
        if (*(int *)(s3 + 0x420) != -1) {
            n = func_L09_003F72A8(a0) + 1;
            if (n != *(int *)(s0 + 0x420))
                continue;
            if (func_L09_003F71C8(e, n) >= *(int *)(s0 + 0x42C))
                continue;
        }
        if (*(int *)(s3 + 0x424) != 0 && *(int *)(s3 + 0x424) != *(int *)(s0 + 0x424))
            continue;
        if (d < bestd) {
            bestd = d;
            best = e;
        }
    }
    if (best != 0) {
        t = *(unsigned char **)(best + 0x68);
        w = *(unsigned short *)&D_L09_001B0F58;
        *(int *)(t + 0x2B0) = *(int *)(s3 + 0x2B0);
        *(int *)(t + 0x2B4) = *(int *)(s3 + 0x2B4);
        *(int *)(t + 0x2B8) = *(int *)(s3 + 0x2B8);
        *(int *)(t + 0x2BC) = *(int *)(s3 + 0x2BC);
        *(int *)(t + 0x2C0) = *(int *)(s3 + 0x2C0);
        *(int *)(t + 0x2D0) = *(int *)(s3 + 0x2D0);
        *(int *)(t + 0x2D4) = *(int *)(s3 + 0x2D4);
        *(unsigned short *)(t + 0x2E0) = w;
        *(int *)(t + 0x2DC) = *(int *)(s3 + 0x2C0);
        t[0x2EA] = 1;
        t[0x302] = (t[0x302] | 2) & 0xFE;
        t[0x303] = s3[0x303];
        *(unsigned short *)(best + 0x34) = *(unsigned short *)(best + 0x34) & 0xFFFD;
        t[0x31D] = 1;
        t[0x31C] = 1;
    }
}
