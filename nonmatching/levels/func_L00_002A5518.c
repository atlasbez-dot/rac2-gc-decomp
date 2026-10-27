/* Nonmatching C: Clamp the control rotations and initialize or retire the seven resident effect records.
 * Tested profile: -O2 -G64 -Wa,-G64 -ffunction-sections.
 * Measured US size: 752 bytes; retail: 808 bytes.
 * Placement checks: US and US2: 0/27 each; PAL: absent from the catalogue.
 * Remaining: Floating-point clamp reloads, branch scheduling and vector-loop spills differ.
 * Reopen with independent clamp and copy-loop lifetime evidence; retain the seven-entry index/vector tables and twelve-entry fade table.
 */
#include "common.h"

typedef int Vector __attribute__((mode(TI)));
extern unsigned char D_00189E20[];
extern unsigned char D_L00_0025BE10[];
extern Vector D_L00_0025DD90[7];
extern Vector D_L00_0025DE00[7];
extern Vector D_L00_0025DE70[7];
extern int D_L00_001A7E40[7] __attribute__((sda));
extern float D_L00_001A7E10[12] __attribute__((sda));
extern void func_L00_002A5480(void);
extern void func_0029F9F0(char *, char *);
extern void func_0029F978(unsigned char *, unsigned int, unsigned char *);

void func_L00_002A5518(void) {
    unsigned char *control = D_L00_0025BE10;
    unsigned char *hero;
    unsigned char *record;
    Vector *a;
    Vector *b;
    Vector *c;
    Vector *out_a;
    Vector *out_b;
    Vector *out_c;
    unsigned char *scan;
    int *indices;
    int i;
    *(float *)(control + 0x8A8) = *(float *)(control + 0x278) * 0.25f;
    if (*(float *)(control + 0x8A8) > 0.148353f)
        *(float *)(control + 0x8A8) = 0.148353f;
    else if (*(float *)(control + 0x8A8) < -0.148353f)
        *(float *)(control + 0x8A8) = -0.148353f;
    *(float *)(control + 0x8A4) = *(float *)(control + 0x274) * 0.35714287f;
    if (*(float *)(control + 0x8A4) > 0.296706f)
        *(float *)(control + 0x8A4) = 0.296706f;
    if (*(float *)(control + 0x8A4) < -0.17453295f)
        *(float *)(control + 0x8A4) = -0.17453295f;
    hero = D_00189E20;
    if ((unsigned int)(*(unsigned char *)(*(char **)(hero + 0x2290) + 0x43) - 1) < 2) {
        if (*(float *)(control + 0x8A8) > 0.03490659f)
            *(float *)(control + 0x8A8) = 0.03490659f;
        if (*(float *)(control + 0x8A8) < -0.03490659f)
            *(float *)(control + 0x8A8) = -0.03490659f;
        if (*(float *)(control + 0x8A4) > 0.122173056f)
            *(float *)(control + 0x8A4) = 0.122173056f;
        if (*(float *)(control + 0x8A4) < -0.122173056f)
            *(float *)(control + 0x8A4) = -0.122173056f;
    }
    func_L00_002A5480();
    if (*(int *)(hero + 0x1180) == 0) return;
    *(int *)(hero + 0x1180) += 1;
    if (*(int *)(hero + 0x1180) >= 12)
        *(int *)(hero + 0x1180) = 0;
    if (*(int *)(hero + 0x1180) == 0) {
        record = hero + 0xEC0;
        for (i = 6; i >= 0; i--, record += 0x40) {
            if (record[1]) func_0029F9F0(*(char **)(hero + 0x2290), (char *)record);
        }
        return;
    }
    record = hero + 0xEC0;
    scan = hero;
    out_a = (Vector *)(hero + 0xED0);
    out_b = (Vector *)(hero + 0xEE0);
    out_c = (Vector *)(hero + 0xEF0);
    a = D_L00_0025DD90;
    b = D_L00_0025DE00;
    c = D_L00_0025DE70;
    indices = D_L00_001A7E40;
    for (i = 6; i >= 0; i--, record += 0x40, scan += 0x40, out_a += 4, out_b += 4, out_c += 4, a++, b++, c++, indices++) {
        if (!scan[0xEC1]) {
            func_0029F978(*(unsigned char **)(hero + 0x2290), *indices, record);
            scan[0xEC3] = 1;
            qcopy(out_a, a);
            qcopy(out_b, b);
            qcopy(out_c, c);
        }
    }
    record = D_00189E20 + 0xECC;
    for (i = 6; i >= 0; i--, record += 0x40)
        *(float *)record = D_L00_001A7E10[*(int *)(D_00189E20 + 0x1180)];
}
