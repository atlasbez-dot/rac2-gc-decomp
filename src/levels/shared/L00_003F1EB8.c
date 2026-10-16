/* SPDX-License-Identifier: GPL-3.0-only
 * Adapted from func_L00_003DC910 by OpenRAC contributors.
 * Source: OpenRAC/rac2-gc-decomp, src/levels/shared/L00_003D37E8.c,
 * revision 3ac8eccb3f943584afee8a2c5722b7cf7080931d.
 * Per-placement adaptations: RC2 decomp contributions.
 * See LICENSE for the GNU General Public License version 3.
 */
#include "common.h"

extern void ref_L00_003F1EB8_00(char *pkt);
extern void ref_L00_003F1EB8_01(char *pkt, float angle);
extern long long ref_L00_003F1EB8_02(char *p);
extern float ref_L00_003F1EB8_03(float x, float y);
extern float ref_L00_003F1EB8_04(char *p, float *v);
extern void ref_L00_003F1EB8_05(float *matrix, float *quat);
extern void ref_L00_003F1EB8_06(float *off, float *v, char *p);
extern void ref_L00_003F1EB8_07(float *dst, float *src, float angle);
extern void ref_L00_003F1EB8_08(char *pkt, float *matrix, int mode);

typedef struct {
    char pad_000[0x140];
    float x_140;
    float y_144;
    float z_148;
} L00AimVector;
extern L00AimVector ref_L00_003F1EB8_09;

void func_L00_003F1EB8(char *pos, int a1, int a2, char *a3, int t0,
                       float fA, float fB, float fC)
{
    char pkt[144];
    float m[16];
    float quat[4];
    float off[4];
    long long r;

    ref_L00_003F1EB8_00(pkt);
    r = ref_L00_003F1EB8_02(a3);

    *(long long *)(pkt + 136) = ((long long)t0 << 2) | 0x8000000040LL;
    *(long long *)(pkt + 128) = 280993940374112LL;
    *(int *)(pkt + 76) = a1 + (a2 << 24);
    *(int *)(pkt + 72) = a1 + (a2 << 24);
    *(int *)(pkt + 68) = a1 + (a2 << 24);
    *(int *)(pkt + 64) = a1 + (a2 << 24);
    *(long long *)(pkt + 112) = 0LL;
    *(long long *)(pkt + 120) = r;

    quat[3] = 0.0f;
    quat[2] = ref_L00_003F1EB8_03(ref_L00_003F1EB8_09.x_140 - *(float *)(pos + 0),
                              ref_L00_003F1EB8_09.y_144 - *(float *)(pos + 4));
    quat[1] = -ref_L00_003F1EB8_03(ref_L00_003F1EB8_04(pos, &ref_L00_003F1EB8_09.x_140),
                               ref_L00_003F1EB8_09.z_148 - *(float *)(pos + 8));
    quat[0] = fB;

    ref_L00_003F1EB8_05(m, quat);
    ref_L00_003F1EB8_06(off, &ref_L00_003F1EB8_09.x_140, pos);
    ref_L00_003F1EB8_07(off, off, fC);

    m[12] = *(float *)(pos + 0) + off[0];
    m[13] = *(float *)(pos + 4) + off[1];
    m[14] = *(float *)(pos + 8) + off[2];
    m[15] = 1.0f;

    ref_L00_003F1EB8_01(pkt, fA);
    ref_L00_003F1EB8_08(pkt, m, 0);
}
