/* func_L00_00321878 (2,988 bytes, 27 level places; boot twin func_002ADB78 in
 * src/game/002AA800.c differs only in one jal target). Opus big39, 26 October 2026.
 *
 * Bolt-reward spawner: picks the amount, applies the fast-clear bonus/penalty against a
 * per-level par value (ref_L00_00321878_00, an absolute symbol whose value differs per
 * level: 0x12C here, 0x12C0/0x168/0x1E0/... elsewhere, 0x77FCB227 in the boot), splits it
 * into 1000/500/100/50/20/5/1 pieces (capped by `limit` under flag 8) and spawns them
 * through func_00302470 with a random arc, aimed at target `target` when it is >= 0.
 *
 * Status: 2920 of 2988 bytes, 730/747 instructions;
 * the control flow, call sequence, stack frame and spill slots agree. Left:
 *  - the (double)0.1f printf argument now matches: retail's inline ori/dsll/ori/dsll is
 *    the assembler's default since integrate/holds (li.d into GPRs); measured 26 October
 *    2026, 2920/2988 bytes at -O2 -G0 -ffunction-sections, the four words in place.
 *  - D_L00_001B1CE0[b0] index: the address temporary and the loaded byte swap v1/a0.
 *  - local-alloc order in the five capped split steps (constant v0/v1 against the
 *    compare result).
 *  - the n5 and n1 capped steps: retail keeps n5 as the cmove destination (spilled,
 *    copy of q, reloaded for *5) and stores n1 twice; this source gives one store each.
 *    Those missing reloads shift reload's round-robin spill registers, so the fixup
 *    block, the spill reloads in the loop and the loop test registers rotate; with
 *    the same registers jump2 cross-jumps the duplicated top loop test into the bottom
 *    one, which retail keeps (its two copies use different registers).
 * Findings: the loop must be a plain `while` (loop notes give the counts their loop
 * weight so fast lands in $fp; `if + do-while` lets loop.c hoist the constants, a goto
 * loop drops the weights). The D_001A7A14 store stays out of the delay slot only when
 * read as D_001A7A08[3] (sda incomplete array, nonzero offset).
 */
#include "common.h"

extern void func_00282C88(void *);
extern int func_002A77E0(int);
extern void func_0026FEB8(const char *, ...);
extern float func_00283CE0(int);
extern float func_002A7940(void);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_002A7878(float, float);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern int func_002A88A0(float *, float *, float, float, float);
extern int func_002C94C8(int, void *, void *, void *);
extern int func_00302470(char *, float *, float *, int, int, int);

extern int D_001A79F0 __attribute__((sda));
extern int D_L00_001A8FC0[] __attribute__((sda));
extern unsigned char D_L00_001B1CE0[];
extern int D_0018D198[];
extern int D_0018D208[];
extern int D_001A7A08[] __attribute__((sda));
extern unsigned char D_001A7A0B[] __attribute__((sda));
extern unsigned char D_001A7A32[] __attribute__((sda));
extern char *D_001FDA80[];
extern char D_L00_001AA298[];
extern char D_L00_001AA2A8[];
extern char D_L00_001AA2B8[];
extern char D_L00_001AA2C8[];
extern char ref_L00_00321878_00[];

void func_L00_00321878(char *moby, int lo, int hi, int flags, int target, int limit, float height)
{
    float base[4] __attribute__((aligned(16)));
    float pos[4] __attribute__((aligned(16)));
    float vel[4] __attribute__((aligned(16)));
    float flat[4] __attribute__((aligned(16)));
    float aim[4] __attribute__((aligned(16)));
    float hit[4] __attribute__((aligned(16)));
    float part[4] __attribute__((aligned(16)));
    float t0;
    float t1;
    int n1, n5, n20, n50, n100, n500, n1000;
    int fast;
    int clear;
    int amount;
    int doubled;
    int left;
    int rem;

    func_00282C88(base);
    n1 = 0;
    n5 = 0;
    n20 = 0;
    n50 = 0;
    n100 = 0;
    n500 = 0;
    n1000 = 0;
    if (!(flags & 0x20)) {
        if (((unsigned char *)moby)[0xB0] != 0xFF) {
            int cls = *(unsigned short *)(moby + 0xAA);

            if (cls < 500 || cls > 540)
                D_L00_001A8FC0[0] = D_L00_001B1CE0[((unsigned char *)moby)[0xB0]] >> 7;
        }
    }
    clear = !(flags & 0x20);
    fast = 0;
    if (D_L00_001A8FC0[0] != 0)
        fast = clear;
    if (flags == 0)
        return;
    if (lo == 0 && hi == 0)
        return;
    if (lo <= 0)
        lo = 1;
    amount = func_002A77E0(hi - lo + 1) + lo;
    doubled = D_001A7A08[0] & 0xFFFF0000;
    if (doubled)
        amount *= 2;
    if (amount < 500 && fast) {
        int level = D_001A79F0;
        int time = D_0018D198[level];

        if (time != 0) {
            int rate = D_0018D208[level] * 3600 / time;

            if (doubled)
                rate /= 2;
            if (rate < (int)ref_L00_00321878_00 / 2) {
                if (rate <= (int)ref_L00_00321878_00 * 3 / 10) {
                    func_0026FEB8(D_L00_001AA298);
                    amount *= 5;
                } else {
                    func_0026FEB8(D_L00_001AA2A8,
                                  ((int)ref_L00_00321878_00 * 19 / 30 - rate) / ((int)ref_L00_00321878_00 / 15));
                    amount = amount * ((int)ref_L00_00321878_00 * 19 / 30 - rate) / ((int)ref_L00_00321878_00 / 15);
                }
                if (D_001A7A0B[0] != 0) {
                    if ((int)ref_L00_00321878_00 * 10 / 3 < amount)
                        amount = (int)ref_L00_00321878_00 * 10 / 3;
                } else {
                    if ((int)ref_L00_00321878_00 * 5 / 3 < amount)
                        amount = (int)ref_L00_00321878_00 * 5 / 3;
                }
            } else if ((int)ref_L00_00321878_00 < rate) {
                if ((int)ref_L00_00321878_00 * 7 / 6 < rate) {
                    func_0026FEB8(D_L00_001AA2B8, 0.1f);
                    amount /= 10;
                } else {
                    func_0026FEB8(D_L00_001AA2B8,
                                  func_00283CE0(((int)ref_L00_00321878_00 * 6 / 5 - rate) / ((int)ref_L00_00321878_00 * 4 / 15)));
                    amount = amount * ((int)ref_L00_00321878_00 * 6 / 5 - rate) / ((int)ref_L00_00321878_00 * 4 / 15);
                }
                if (amount <= 0)
                    amount = 1;
            }
        }
    }
    left = amount;
    if (flags & 8) {
        n1000 = left / 1000;
        if (limit < n1000)
            n1000 = limit;
        left -= n1000 * 1000;
        rem = limit - n1000;
        if (rem > 0) {
            int q = left / 500;
            int t = rem;

            if (q <= rem)
                t = q;
            n500 = t;
            left -= t * 500;
            rem -= t;
            if (rem > 0) {
                int q = left / 100;
                int t = rem;

                if (q <= rem)
                    t = q;
                n100 = t;
                left -= t * 100;
                rem -= t;
                if (rem > 0) {
                    int q = left / 50;
                    int t = rem;

                    if (q <= rem)
                        t = q;
                    n50 = t;
                    left -= t * 50;
                    rem -= t;
                    if (rem > 0) {
                        int q = left / 20;
                        int t = rem;

                        if (q <= rem)
                            t = q;
                        n20 = t;
                        left -= t * 20;
                        rem -= t;
                        if (rem > 0) {
                            int q = left / 5;
                            int t = rem;

                            if (q <= rem)
                                t = q;
                            n5 = t;
                            left -= t * 5;
                            rem -= t;
                            if (rem > 0) {
                                n1 = left;
                                if (rem < n1)
                                    n1 = rem;
                            }
                        }
                    }
                }
            }
        }
        if (D_001A7A32[0] != 0)
            left /= D_001A7A32[0];
        D_001A7A08[3] += left;
    } else {
        if (left >= 1000) {
            n1000 = left / 1000;
            left -= n1000 * 1000;
        }
        if (left >= 500) {
            n500 = left / 500;
            left -= n500 * 500;
        }
        if (left >= 100) {
            n100 = left / 100;
            left -= n100 * 100;
        }
        if (left >= 50) {
            n50 = left / 50;
            left -= n50 * 50;
        }
        if (left >= 20) {
            n20 = left / 20;
            left -= n20 * 20;
        }
        if (left >= 5) {
            n5 = left / 5;
            left -= n5 * 5;
        }
        n1 = left;
        if (n1000 < 0 || n500 < 0 || n100 < 0 || n50 < 0 || n20 < 0 || n5 < 0 || n1 < 0) {
            func_0026FEB8(D_L00_001AA2C8);
            if (n1 < 0)
                n1 = 0;
            if (n1000 < 0)
                n1000 = 0;
            if (n500 < 0)
                n500 = 0;
            if (n100 < 0)
                n100 = 0;
            if (n50 < 0)
                n50 = 0;
            if (n20 < 0)
                n20 = 0;
            if (n5 < 0)
                n5 = 0;
        }
    }
    while (n1 != 0 || n5 != 0 || n20 != 0 || n50 != 0 || n100 != 0 || n500 != 0 || n1000 != 0) {
        float angle;

        func_00282D30(pos, moby, 1.0f / 1024.0f);
        angle = func_002A7940();
        vel[0] = func_00283180(angle) * (1.0f / 60.0f) * func_002A7878(0.0f, 3.0f);
        vel[1] = func_00283198(angle) * (1.0f / 60.0f) * func_002A7878(0.0f, 3.0f);
        vel[2] = 0.0f;
        vel[2] = func_002A7878(3.7f, 6.0f) * (1.0f / 60.0f);
        flat[0] = vel[0];
        flat[1] = vel[1];
        flat[2] = 0.0f;
        func_00282F20(flat, flat, 0.5f);
        func_00282CC0(pos, pos, flat);
        pos[2] += height;
        if (target >= 0) {
            float when = 120.0f;
            int n = func_002A88A0(&t0, &t1, -0.0015f, vel[2] - -0.0015f,
                                  pos[2] - *(float *)(D_001FDA80[target] + 0x18));

            if ((float)n >= 1.0f && 0.0f < t0 && t0 < when)
                when = t0;
            func_00282D30(aim, vel, when);
            func_00282CC0(aim, aim, moby + 0x10);
            func_002C94C8(target, moby + 0x10, aim, hit);
            func_00282CF0(aim, hit, pos);
            aim[2] = 0.0f;
            func_00282F20(part, aim, 0.25f);
            func_00282CF0(aim, aim, part);
            func_00282D30(aim, aim, 1.0f / when);
            vel[0] = aim[0];
            vel[1] = aim[1];
        }
        func_00282CC0(vel, vel, base);
        if (n1000 != 0) {
            func_00302470(moby, pos, vel, flags, 1000, fast);
            n1000--;
        } else if (n500 != 0) {
            func_00302470(moby, pos, vel, flags, 500, fast);
            n500--;
        } else if (n100 != 0) {
            func_00302470(moby, pos, vel, flags, 100, fast);
            n100--;
        } else if (n50 != 0) {
            func_00302470(moby, pos, vel, flags, 50, fast);
            n50--;
        } else if (n20 != 0) {
            func_00302470(moby, pos, vel, flags, 20, fast);
            n20--;
        } else if (n5 != 0) {
            func_00302470(moby, pos, vel, flags, 5, fast);
            n5--;
        } else {
            func_00302470(moby, pos, vel, flags, 1, fast);
            n1--;
        }
    }
}
