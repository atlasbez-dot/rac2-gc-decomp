/* func_L07_002B5738 - 1972 bytes, 4 place(s), level 07_siberius, retail at
   0x002b5738. Screened with tools/w10_screen.py: 42 call(s)
   [func_L00_002B54F8@002B577C, func_002AA2E8@002B57D4,
   func_L00_002B41B8@002B5818, func_L00_002D3BD8@002B5830,
   func_L00_002D3798@002B5840, func_L00_002B3EF8@002B588C,
   func_L01_002B6948@002B58A0, func_002AA2E8@002B5910,
   func_002AA2E8@002B5938, func_00282DB0@002B5958, func_00283098@002B596C,
   func_L00_002B3EF8@002B59C0, func_002AA2E8@002B5A2C,
   func_002AA2E8@002B5A68, func_002AA2E8@002B5A90, func_00283180@002B5AA8,
   func_00283198@002B5ABC, func_L00_002D3BD8@002B5ADC,
   func_L00_002D3B58@002B5AF0, func_L00_002D3BD8@002B5B00,
   func_00282CC0@002B5B10, func_00283C80@002B5B38, func_00283198@002B5B40,
   func_00283180@002B5B50, func_00283198@002B5B68,
   func_L00_002B54F8@002B5B90, func_L00_002B3EF8@002B5C08,
   func_00283180@002B5C38, func_00283198@002B5C48,
   func_L00_002D3BD8@002B5C64, func_00282F20@002B5C7C,
   func_00282CC0@002B5C8C, func_L00_002B3EF8@002B5CD8,
   func_002AA898@002B5D30, func_00283BE0@002B5D40,
   func_L00_002AA0F0@002B5D50, func_L00_002B3EF8@002B5DAC,
   func_L00_002B54F8@002B5DE8, func_L00_002D3A58@002B5E54,
   func_002AA2E8@002B5E68, func_L00_002D3BD8@002B5E78,
   func_L01_002B6948@002B5EC4]; data addresses materialised [0x190000,
   0x3f330000, 0x3be30000, 0x3afe0000, 0x3d6e0000, 0x3c480000, 0x3c4c0000,
   0x3d230000, 0x3e4c0000, 0x3e800000, 0x3bb60000, 0x3b110000, 0x3d080000,
   0x3b110000, 0x3d230000, 0x3e4c0000, 0x3dee0000, 0x3daa0000, 0x3d080000,
   0x3c280000, 0x190000, 0x3b110000, 0x3d8f0000, 0x3b110000, 0x3f330000,
   0x190000, 0x3d2c0000, 0x3e4c0000, 0x3e4a0000, 0x3da70000, 0x3da70000,
   0x1b0000, 0x3d230000, 0x3e4c0000, 0x3e4c0000, 0x3c930000, 0x3dfa0000,
   0x1c0000, 0x3d230000, 0x3e4c0000, 0x3f330000, 0x190000, 0x1a0000,
   0x3b5a0000, 0x3bb60000, 0x3b480000, 0x3b110000, 0x3a110000]; float
   constants [0x190000, 0x41500000, 0x41f00000, 0x41d80000]; $gp-relative
   small data: no   saves: -; callee-saved registers saved [-]; words plain
   C cannot emit [LQ/SQ 78820000@0x0054, LQ/SQ 7C620000@0x0058, LQ/SQ
   78620000@0x025c, LQ/SQ 7C820000@0x0260, LQ/SQ 78820000@0x046c, LQ/SQ
   7C620000@0x0470, LQ/SQ 78820000@0x0494, LQ/SQ 7E220000@0x0498, LQ/SQ
   7A220000@0x062c, LQ/SQ 7FA20000@0x0630, LQ/SQ 78620000@0x0650, LQ/SQ
   7E220000@0x0654, LQ/SQ 7BA20000@0x068c, LQ/SQ 7C620000@0x0690, LQ/SQ
   78620000@0x0698, LQ/SQ 7E220000@0x069c, LQ/SQ 78620000@0x06c4, LQ/SQ
   7E020000@0x06c8]. Head: addiu $sp, $sp, -0x50 ; lui $v0, 0x19 ; sd $s0,
   0x20($sp) ; addiu $v1, $zero, 0xA ; sd $s2, 0x30($sp) ; addiu $s0, $v0,
   -0x61E0. Not matched in this wave: the 128-bit copy needs an `lq`/`sq`
   pair; plain C reaches it only through a `mode(TI)` local, and this cc1
   folds the destination offset into the `sq` where retail materialises the
   pointer first. What would unblock it: the exact source expression tree,
   so this cc1 picks the same registers in the same order. */

/* Fresh reconstruction, 23 October 2026; supersedes the historical MMI
   screening above. Game -O2 -G0 -ffunction-sections -frac2-qcopy
   -frac2-qcopy-barrier: 1988/1972 bytes, 0/4 USA v1.01 and USA v2.00
   placements; absent from PAL. Two source trials corrected the resident
   snapshot lifetime, restore-copy order and exact floating literals; the
   first trial was 1984 bytes. Remaining differences span base-pointer/GPR
   allocation, state-branch scheduling and scalar/vector transfers.
   The SceneSnapshot type is a partial view through the measured last vector.
   Reopen with independent original resident-state layouts/control flow,
   rather than repeating flag-only allocation searches. */
#include "include_asm.h"
typedef int Quad __attribute__((mode(TI)));
extern unsigned char D_00189E20[];
typedef struct { char prefix[0x158]; float heading; char gap[0x214]; Quad position; } SceneSnapshot;
extern SceneSnapshot D_L07_001B90C0;
extern float D_L07_001A7DC0;
extern int D_L07_001A8FF0;
extern void func_L00_002B54F8(float, float);
extern float func_002AA2E8(float *, float, float);
extern void func_L00_002B41B8(float, float);
extern void func_L00_002D3BD8(char *, int, float);
extern void func_L00_002D3798(Quad *, Quad *, float);
extern void func_L00_002B3EF8(int, float, float, float);
extern void func_L01_002B6948(float);
extern float func_00282DB0(void *, void *);
extern void func_00283098(void *, void *, void *);
extern float func_00283180(float);
extern float func_00283198(float);
extern void func_L00_002D3B58(Quad *, Quad *, float);
extern void func_00282CC0(void *, void *, void *);
extern float func_00283C80(float, float);
extern void func_00282F20(void *, void *, float);
extern float func_002AA898(float *, float *, int, float, float, float, float);
extern float func_00283BE0(float, float);
extern void func_L00_002AA0F0(float, float, float);
extern float func_L00_002D3A58(char *);
/* All offsets below belong to the measured resident camera/state object. */
#define ROOT D_00189E20
#define F(o) (*(float *)(ROOT + (o)))
#define I(o) (*(int *)(ROOT + (o)))
#define H(o) (*(short *)(ROOT + (o)))
#define B(o) (*(unsigned char *)(ROOT + (o)))
#define V(o) (*(Quad *)(ROOT + (o)))

void func_L07_002B5738(void)
{
    float temporary[4];
    float angle;
    float speed;
    int mode = I(0x2294);
    if (mode == 10) {
        func_L00_002B54F8(0.7f, 0.0f);
        V(0x160) = V(0xa60);
        F(0x1b4) = F(0x174);
    } else if (mode == 16) {
        speed = F(0x454);
        if (I(0x1b8) > 54) {
            func_002AA2E8((float *)(ROOT + 0x520), 0.0069444444961845875f, 0.0019444444915279746f);
            speed = F(0x454);
            if (I(0x1b8) > 54)
                speed = 0.05833333730697632f;
        }
        F(0x1b0) = speed;
        func_L00_002B41B8(0.012222222983837128f, 0.012500000186264515f);
        func_L00_002D3BD8((char *)ROOT + 0xf0, (int)(ROOT + 0xf0), 0.0f);
        func_L00_002D3798((Quad *)(ROOT + 0xf0), (Quad *)(ROOT + 0xf0), F(0x1b4));
    } else if (mode == 27) {
        if (I(0x1b8) > 40) {
            func_L00_002B3EF8(0, 0.04f, 0.2f, 0.2501639127731323f);
            func_L01_002B6948(0.0055555556900799274f);
        }
        if (F(0xc38) >= 13.0f && F(0xc38) <= 30.0f) {
            if (F(0xc38) > 27.0f)
                func_002AA2E8((float *)(ROOT + 0x4bc), 0.0f, 0.002222222276031971f);
            else
                func_002AA2E8((float *)(ROOT + 0x4bc), 0.03333333507180214f, 0.002222222276031971f);
        }
        temporary[0] = F(0x4bc);
        temporary[1] = 0.0f;
        temporary[2] = func_00282DB0(ROOT + 0xf0, ROOT + 0x20);
        func_00283098(ROOT + 0xf0, temporary, ROOT);
    } else if (mode == 11) {
        F(0x1a0) = F(0x4c4);
        V(0x190) = V(0x480);
        func_L00_002B3EF8(0, 0.04f, 0.2f, 0.116355299949646f);
        if (I(0x4d4) == 3)
            F(0x1b4) = 0.0f;
        else
            F(0x1b4) = F(0x4d8);
        if (!B(0x52d)) {
            if (!B(0x49e) || H(0x4ae) > 11)
                func_002AA2E8((float *)(ROOT + 0x4dc), 0.07f, 0.002222222276031971f);
            else
                func_002AA2E8((float *)(ROOT + 0x4dc), 0.0f, 0.002222222276031971f);
        } else {
            speed = F(0x24b8) * 0.0833333358168602f;
            if (speed < 0.03333333507180214f)
                speed = 0.03333333507180214f;
            func_002AA2E8((float *)(ROOT + 0x4dc), speed, 0.010277777910232544f);
            F(0x1b4) = F(0x174);
        }
        if (!B(0x22c3)) {
            F(0xf0) = func_00283180(F(0x4c0)) * F(0x4dc);
            F(0xf4) = func_00283198(F(0x4c0)) * F(0x4dc);
        } else {
            func_L00_002D3BD8((char *)temporary, (int)(ROOT + 0x470), F(0x4dc));
            func_L00_002D3B58((Quad *)temporary, (Quad *)temporary, 0.0f);
            func_L00_002D3BD8((char *)ROOT + 0xf0, (int)(ROOT + 0xf0), 0.0f);
            func_00282CC0(ROOT + 0xf0, ROOT + 0xf0, temporary);
        }
        if (!B(0x22c3) && !B(0x52d)) {
            angle = func_00283C80(F(0x4c4), F(0x4c0));
            speed = F(0x4d8) * func_00283198(angle);
            F(0xf0) += func_00283180(F(0x4c4)) * speed;
            F(0xf4) += func_00283198(F(0x4c4)) * speed;
        }
        func_L00_002B54F8(0.7f, 0.0f);
        V(0x160) = V(0xa60);
    } else if (mode == 17) {
        F(0x1a0) = F(0x4fc);
        V(0x190) = V(0x4f0);
        if (I(0x1b8) > 9)
            func_L00_002B3EF8(-1, 0.042f, 0.2f, 0.1978040188550949f);
        if (I(0x1b8) > 8) {
            if (!H(0x348)) {
                F(0xf0) = func_00283180(F(0x1a0)) * 0.08166667073965073f;
                F(0xf4) = func_00283198(F(0x1a0)) * 0.08166667073965073f;
            } else {
                func_L00_002D3BD8((char *)ROOT + 0xf0, (int)(ROOT + 0xf0), 0.0f);
                func_00282F20(temporary, ROOT + 0x190, 0.08166667073965073f);
                func_00282CC0(ROOT + 0xf0, ROOT + 0xf0, temporary);
            }
        }
        F(0x1b4) = F(0x174);
    } else if (mode == 129 && !D_L07_001A8FF0) {
        func_L00_002B3EF8(0, 0.04f, 0.2f, F(0x494));
        F(0x1b4) = 0.0f;
    } else {
        if (mode == 44) {
            angle = F(0x98);
            F(0x1a8) = func_002AA898(&angle, (float *)(ROOT + 0x1a4), 0, F(0x1a0),
                                    0.017999999225139618f, 0.2f, 0.12217307090759277f);
            func_L00_002AA0F0(0.0f, 0.0f, func_00283BE0(angle, F(0x98)));
        } else {
            float oldHeading = F(0x1a0);
            *(Quad *)temporary = V(0x190);
            if (H(0x1454)) {
                F(0x1a0) = D_L07_001B90C0.heading;
                V(0x190) = D_L07_001B90C0.position;
            }
            func_L00_002B3EF8(0, 0.04f, 0.2f, F(0x494));
            if (H(0x1454)) {
                F(0x1458) = oldHeading;
                V(0x1440) = *(Quad *)temporary;
                F(0x1a0) = oldHeading;
                V(0x190) = V(0x1440);
            }
        }
        func_L00_002B54F8(0.7f, 0.0f);
        V(0x160) = V(0xa60);
        speed = 0.0055555556900799274f;
        if (F(0x1b0) < D_L07_001A7DC0 * 0.0033333336468786f) {
            if (I(0x229c) == 2) {
                float target = F(0xa84);
                angle = func_L00_002D3A58((char *)ROOT + 0xf0);
                func_002AA2E8(&angle, 0.0f, target);
                func_L00_002D3BD8((char *)ROOT + 0xf0, (int)(ROOT + 0xf0), angle);
                return;
            }
            if (!H(0x34a)) {
                speed = 0.002222222276031971f;
                if (H(0x524))
                    speed = 0.0005555555690079927f;
            } else {
                speed = 0.003055555745959282f;
            }
        }
        func_L01_002B6948(speed);
    }
}
