/* Bounded manual reconstruction, 2026-10-25; not linked.
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 1656/1648 bytes; us: 0/1 placements; us2: 0/1 placements; pal: 0/1 placements.
 * All twenty complete template quadwords, nine-by-nine seams and full normal vectors remain. Shared
 * packet append copies have genuine memory effects. Complete16-byte GP constants use
 * G16/assemblerG16; the other observed absolute constants and this routine packet cursor remain
 * absolute. The packed-color result uses its 32-bit bank. Frame 0xc0 agrees, but phase/height
 * induction, palette/normal allocation and cursor scheduling differ.
 * Reopen with measured row/cursor lifetimes and exact packet source dependencies. Do not shrink the
 * constants to force small data or drop template entries.
 * Original variants, retail context and allocator diagnostics remain private.
 * No exact-C, linked-build or runtime credit is claimed.
 */
#include "common.h"


typedef unsigned int Quad __attribute__((mode(TI)));
extern void func_L01_003CAFE0(void), func_L01_003CB540(void);
extern float func_00283180(float), func_00283198(float), func_00283B98(float, float);
extern void func_00282DD8(float *, float *, float *), func_00282F20(float *, float *, float);
extern float func_00282DB0(float *, float *);
extern u32 func_00283D38(unsigned int, unsigned int, float);
extern int D_L01_001B2088;
extern float D_L01_001B0370 __attribute__((sda)), D_L01_001B0378 __attribute__((sda));
extern int D_L01_001B0374 __attribute__((sda)), D_L01_001B037C __attribute__((sda));
extern float D_L01_001B0380 __attribute__((sda)), D_L01_001B0384 __attribute__((sda));
extern float D_L01_001B0388 __attribute__((sda)), D_L01_001B038C __attribute__((sda));
extern short D_L01_00297580[][9][4];
extern unsigned int D_L01_00297960[][9];
extern unsigned char *D_L01_001B036C __attribute__((sda));
/* This routine uses absolute accesses to the real packet cursor. */
extern unsigned char *D_L01_001B2CC8 NOT_SDA;
/* All are complete 16-byte constants; their observed address forms differ. */
extern Quad D_L01_001B01E0 __attribute__((sda));
extern Quad D_L01_001B01F0 NOT_SDA, D_L01_001B0200 NOT_SDA, D_L01_001B0210 NOT_SDA;
extern Quad D_L01_001B0220 __attribute__((sda)), D_L01_001B0230 __attribute__((sda));
extern Quad D_L01_001B0260 __attribute__((sda)), D_L01_001B0290 __attribute__((sda));
#define APPEND_QUAD(value) do { qcopy(D_L01_001B2CC8, &(value)); D_L01_001B2CC8 += 16; } while (0)
void func_L01_003CB668(void)
{
    int i, j;
    func_L01_003CAFE0();
    {
        int firstPhase[8], secondPhase[8];
        float firstAngle = (float)(D_L01_001B2088 % (D_L01_001B0374 * 2) - D_L01_001B0374)
            * (3.14159274f / (float)D_L01_001B0374);
        float secondAngle = (float)(D_L01_001B2088 % (D_L01_001B037C * 2) - D_L01_001B037C)
            * (3.14159274f / (float)D_L01_001B037C);
        for (i = 0; i < 8; i++) {
            firstPhase[i] = (int)((func_00283180(firstAngle) + 1.0f) * D_L01_001B0370);
            secondPhase[i] = (int)((func_00283180(secondAngle) + 1.0f) * D_L01_001B0378);
            firstAngle = func_00283B98(firstAngle, 0.785398006f);
            secondAngle = func_00283B98(secondAngle, 0.785398006f);
        }
        for (i = 0; i < 8; i++)
            for (j = 0; j < 8; j++)
                D_L01_00297580[i][j][2] = (unsigned short)firstPhase[(i + j) & 7]
                    + (unsigned short)secondPhase[(-i) & 7];
        for (j = 0; j < 9; j++) D_L01_00297580[8][j][2] = D_L01_00297580[0][j][2];
        for (i = 0; i < 9; i++) D_L01_00297580[i][8][2] = D_L01_00297580[i][0][2];
    }
    {
        float direction[4] __attribute__((aligned(16)));
        float horizontal[4] __attribute__((aligned(16)));
        float vertical[4] __attribute__((aligned(16)));
        float normal[4] __attribute__((aligned(16)));
        unsigned int c, target;
        direction[0] = func_00283180(D_L01_001B0384) * func_00283180(D_L01_001B0388);
        direction[1] = func_00283198(D_L01_001B0384) * func_00283180(D_L01_001B0388);
        direction[2] = func_00283198(D_L01_001B0388);
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                horizontal[0] = D_L01_001B0380;
                horizontal[1] = 0.0f;
                horizontal[2] = (float)(D_L01_00297580[i][j + 1][2] - D_L01_00297580[i][j][2]) * 0.0009765625f;
                vertical[0] = 0.0f;
                vertical[1] = D_L01_001B0380;
                vertical[2] = (float)(D_L01_00297580[i + 1][j][2] - D_L01_00297580[i][j][2]) * 0.0009765625f;
                func_00282DD8(normal, vertical, horizontal);
                func_00282F20(normal, normal, 1.0f);
                c = (int)(func_00282DB0(normal, direction) * 128.0f);
                target = 0x80000000 | (c << 8) | (c << 16) | c;
                D_L01_00297960[i][j] = func_00283D38(
                    *(unsigned int *)(D_L01_001B036C + (i + 2) * 128 + 8 + j * 4), target, D_L01_001B038C);
            }
        }
        for (j = 0; j < 9; j++) D_L01_00297960[8][j] = D_L01_00297960[0][j];
        for (i = 0; i < 9; i++) D_L01_00297960[i][8] = D_L01_00297960[i][0];
    }
    APPEND_QUAD(D_L01_001B0220);
    APPEND_QUAD(D_L01_001B01E0);
    APPEND_QUAD(D_L01_001B0230);
    APPEND_QUAD(D_L01_001B0260);
    APPEND_QUAD(D_L01_001B0290);
    APPEND_QUAD(D_L01_001B0220);
    APPEND_QUAD(D_L01_001B01F0);
    APPEND_QUAD(D_L01_001B0230);
    APPEND_QUAD(D_L01_001B0260);
    APPEND_QUAD(D_L01_001B0290);
    APPEND_QUAD(D_L01_001B0220);
    APPEND_QUAD(D_L01_001B0200);
    APPEND_QUAD(D_L01_001B0230);
    APPEND_QUAD(D_L01_001B0260);
    APPEND_QUAD(D_L01_001B0290);
    APPEND_QUAD(D_L01_001B0220);
    APPEND_QUAD(D_L01_001B0210);
    APPEND_QUAD(D_L01_001B0230);
    APPEND_QUAD(D_L01_001B0260);
    APPEND_QUAD(D_L01_001B0290);
    func_L01_003CB540();
}
