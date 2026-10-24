/* func_L07_002B3580 - 2356 bytes, 2 place(s), level 07_siberius, retail at
   0x002b3580. Screened with tools/w10_screen.py: 36 call(s)
   [func_00282C88@002B35F8, func_L00_002ADF80@002B3658,
   func_L00_002B47A8@002B3680, func_002761F8@002B369C,
   func_L00_002E2048@002B36AC, func_00278E78@002B36F4,
   func_002A90F8@002B3718, func_002761F8@002B3760,
   func_L00_002E2048@002B3770, func_002761F8@002B37C4,
   func_002761F8@002B3814, func_002ABB78@002B3850, func_002AB1F0@002B3864,
   func_002AD0B0@002B388C, func_002B0360@002B38F0, func_00282E48@002B3908,
   0x1290e0@002B3924, func_L00_002D3EA8@002B392C, func_00283248@002B393C,
   func_00282CF0@002B3954, func_00282DB0@002B3960, func_00282C88@002B3A50,
   func_002AFF60@002B3AB8, func_002AA2E8@002B3AEC, func_00282D30@002B3B1C,
   func_00282CF0@002B3B58, func_00282F20@002B3B68,
   func_L00_002B8E48@002B3BFC, func_L00_002D3638@002B3D18,
   func_L00_002D3638@002B3D38, func_002761F8@002B3D50,
   func_002B0360@002B3D6C, func_002B0360@002B3D78, func_00282C48@002B3DA8,
   0x1290e0@002B3DD8, func_L00_002B8E48@002B3DE4]; data addresses
   materialised [0x190000, 0x400c0000, 0x40390000, 0x190000, 0x1c0000,
   0x1a0000, 0x190000, 0x1c0000, 0x190000, 0x190000, 0x190000, 0x190000,
   0x3c230000, 0x190000, 0x3c230000, 0x190000, 0x190000, 0x190000, 0x1b0000,
   0x3ca30000, 0x190000, 0x3f5f0000, 0x190000, 0x190000, 0x190000, 0x190000,
   0x1b0000, 0x190000, 0x190000, 0x190000, 0x190000, 0xbf490000, 0x3f490000,
   0xbf490000, 0x190000, 0x3f490000, 0x190000, 0x190000, 0x3e4c0000,
   0xbf490000, 0x3f490000, 0x190000, 0x3fc90000, 0x190000, 0x3ee60000,
   0xbee60000, 0x1c0000, 0x1c0000, 0x3ecc0000, 0x1c0000, 0x190000]; float
   constants [0x3f800000, 0x42000000, 0xc2400000, 0xbf800000, 0x190000,
   0x3f800000, 0xbf800000, 0x190000, 0xbf800000, 0x3f800000, 0x3e800000];
   $gp-relative small data: no   saves: -; callee-saved registers saved [-];
   words plain C cannot emit [LQ/SQ 78820000@0x0350, LQ/SQ 7E820000@0x0354,
   LQ/SQ 78820000@0x04b0, LQ/SQ 7CA20000@0x04b4, LQ/SQ 78620000@0x0578,
   LQ/SQ 7E020000@0x057c, LQ/SQ 78620000@0x0588, LQ/SQ 7E020000@0x058c].
   Head: addiu $sp, $sp, -0xE0 ; lui $v0, 0x19 ; sd $s1, 0x78($sp) ; sd $s0,
   0x70($sp) ; addiu $s1, $v0, -0x61E0 ; sd $s2, 0x80($sp). Not matched in
   this wave: the 128-bit copy needs an `lq`/`sq` pair; plain C reaches it
   only through a `mode(TI)` local, and this cc1 folds the destination
   offset into the `sq` where retail materialises the pointer first. What
   would unblock it: the exact source expression tree, so this cc1 picks the
   same registers in the same order. */

/* Fresh reconstruction, 23 October 2026; the historical screening above
   is not evidence of handwritten code. Game -O2 -G0 -ffunction-sections
   -frac2-qcopy -frac2-qcopy-barrier: compilation reaches GNU as but fails
   in all three releases before placement checks. The two normalizations
   enter func_001290BC +0x24: verified boot bytes at that offset read a1,
   compute a vector reciprocal length and store through a0 in the jr slot.
   No new function boundary or alias is claimed. The ordinary C function
   pointer/addend expression below lowers to a direct jal addend that the
   qualified GNU as rejects: x.s:423 and x.s:999, Error: illegal operands
   `jal'; then BFD assertion elf32-mips.c:2847. No size/match is claimed.
   Reopen when maintainers supply supported canonical interior-entry call
   representation or correct the measured parent extent. func_002B0360's
   first live pointer argument is the collision position, omitted by Ghidra;
   it is restored below, preserving its actual current C signature. */
#include "include_asm.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { char prefix[0x18]; unsigned char *object; int count; float position[4]; char gap[16]; float normal[4]; } Collision;
extern unsigned char D_00189E20[];
extern int D_001A79F0;
extern int D_L07_001A8FF0;
extern int D_L07_001A8FF4;
extern Collision D_L07_001BF640;
extern void func_00282C88(Quad *);
extern int func_L00_002ADF80(void);
extern void func_L00_002B47A8(void *, void *, int, float, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern int func_L00_002E2048(void);
extern int func_00278E78(void);
extern float func_002A90F8(float *, void *);
extern int func_002ABB78(char *);
extern int func_002AB1F0(unsigned char *);
extern int func_002AD0B0(unsigned char *);
extern float func_002B0360(char *);
extern float func_00282E48(void *, void *);
extern void func_001290BC(void);
extern float func_L00_002D3EA8(void *);
extern float func_00283248(float, float);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DB0(void *, void *);
extern void func_002AFF60(char *, char *, int);
extern float func_002AA2E8(float *, float, float);
extern void func_00282D30(void *, void *, float);
extern void func_00282F20(void *, void *, float);
extern void func_L00_002B8E48(void *, float *);
extern void func_L00_002D3638(float *, int, float, float, float);
extern float func_00282C48(float);
/* This entry is +0x24 inside the catalogued ASM extent, not a new function identity. */
#define normalize_vector(out, in) ((void (*)(void *, void *))((char *)func_001290BC + 0x24))((out), (in))
#define ROOT D_00189E20
#define F(o) (*(float *)(ROOT + (o)))
#define I(o) (*(int *)(ROOT + (o)))
#define H(o) (*(short *)(ROOT + (o)))
#define B(o) (*(unsigned char *)(ROOT + (o)))
#define V(o) (*(Quad *)(ROOT + (o)))
#define PLAYER (*(char **)(ROOT + 0x2290))

void func_L07_002B3580(void)
{
    float end[4];
    float start[4];
    float difference[4];
    float left[4];
    float right[4];
    float angles[2];
    float normal[4];
    float reach;
    int side;
    ++H(0x34e);
    F(0x2a8) = 1.0f;
    ++H(0x34c);
    I(0x2a0) = 0;
    I(0x2a4) = 0;
    F(0x320) = 0.0f;
    F(0x318) = 0.0f;
    func_00282C88((Quad *)(ROOT + 0x2d0));
    H(0x34a) = 0;
    F(0x31c) = 32.0f;
    I(0x33c) = 0;
    if (I(0x338))
        ++I(0x338);
    reach = F(0x264) * 2.2f;
    if (I(0x229c) == 2)
        reach = F(0x264) * 2.9f;
    if (func_L00_002ADF80())
        reach = 0.0f;
    func_L00_002B47A8(start, end, 1, reach, -48.0f);
    if (func_002761F8(start, end, 2, PLAYER, 0)) {
        B(0x149d) = func_L00_002E2048();
        if (D_L07_001BF640.object)
            B(0x149d) = 0;
        if (D_001A79F0 == 7 && D_L07_001BF640.object)
            B(0x149d) = 1;
        H(0x1490) = func_00278E78();
        if (!H(0x1490)) {
            F(0x330) = func_002A90F8(D_L07_001BF640.position, ROOT + 0x2b0);
            if (F(0x88) < F(0x330) && I(0x338) < 1)
                I(0x338) = 1;
            if (!func_002761F8(start, end, 0x24, PLAYER, 0))
                goto contacts_done;
            B(0x149d) = func_L00_002E2048();
        }
        if (H(0x1490) == 13) {
            start[2] = D_L07_001BF640.position[2] - 0.01f;
            F(0x330) = D_L07_001BF640.position[2];
            if (!func_002761F8(start, end, 4, PLAYER, 0))
                goto contacts_done;
        }
        if (H(0x1490) == 3) {
            start[2] = D_L07_001BF640.position[2] - 0.01f;
            F(0x334) = D_L07_001BF640.position[2];
            if (!func_002761F8(start, end, 4, PLAYER, 0))
                goto contacts_done;
        }
        if (H(0x1490) == 11) {
            F(0x334) = D_L07_001BF640.position[2];
        } else {
            if (D_L07_001BF640.object) {
                unsigned char *record;
                if (func_002ABB78((char *)D_L07_001BF640.object))
                    H(0x34a) = 1;
                record = (unsigned char *)func_002AB1F0(D_L07_001BF640.object);
                if (record && (*(unsigned short *)(record + 0x1e) & 8))
                    H(0x34a) = 1;
                record = (unsigned char *)func_002AD0B0(D_L07_001BF640.object);
                if (record && (*(unsigned int *)(record + 0x3c) & 8))
                    H(0x34a) = 1;
            }
            if (D_L07_001BF640.count > 0) {
                V(0x2d0) = *(Quad *)D_L07_001BF640.position;
                F(0x318) = D_L07_001BF640.position[2];
                if (D_L07_001A8FF0)
                    F(0x318) = func_002B0360((char *)D_L07_001BF640.position);
                F(0x31c) = func_00282E48(ROOT + 0x80, ROOT + 0x2d0);
                I(0x33c) = (int)D_L07_001BF640.object;
                normalize_vector(ROOT + 0x2a0, D_L07_001BF640.normal);
                F(0x320) = func_L00_002D3EA8(D_L07_001BF640.normal);
                F(0x32c) = func_00283248(D_L07_001BF640.normal[0], D_L07_001BF640.normal[1]);
                func_00282CF0(difference, ROOT + 0x2d0, ROOT + 0x80);
                if (func_00282DB0(difference, ROOT + 0x2a0) > 0.0f)
                    F(0x31c) = -F(0x31c);
                if (F(0x31c) < 0.02f) {
                    H(0x34c) = 0;
                    if (F(0x320) <= 0.8726646900177002f || B(0x22c3)) {
                        H(0x34e) = 0;
                        I(0xc10) = (int)D_L07_001BF640.object;
                    }
                }
            }
        }
    }
contacts_done:
    if (F(0x330) < F(0x88))
        I(0x338) = 0;
    if (!H(0x34e)) {
        ++I(0x340);
        V(0x2e0) = V(0x2d0);
        if (I(0x2294) != 56)
            I(0x18c0) = 0;
    } else {
        I(0x340) = 0;
    }
    func_00282C88((Quad *)(ROOT + 0x2c0));
    if (B(0x22c3) == 1) {
        if (!D_L07_001A8FF4) {
            if (F(0x2fc) == 0.0f) {
                V(0x2c0) = V(0x2a0);
                func_00282D30(ROOT + 0x2c0, ROOT + 0x2c0, -1.0f);
            } else {
                func_002AA2E8((float *)(ROOT + 0x2fc), 0.0f, 1.0f);
                V(0x2c0) = V(0x2f0);
            }
        } else {
            func_002AFF60((char *)ROOT + 0x80, (char *)ROOT + 0x2c0, 0);
        }
    } else if (B(0x22c3) == 0) {
        F(0x2c8) = -1.0f;
    } else if (B(0x22c3) == 2) {
        float sign = -1.0f;
        if (F(0xbc) > 0.0f)
            sign = 1.0f;
        func_00282CF0(ROOT + 0x2c0, ROOT + 0xb0, ROOT + 0x80);
        func_00282F20(ROOT + 0x2c0, ROOT + 0x2c0, sign);
    }
    F(0x324) = 0.0f;
    F(0x328) = 0.0f;
    I(0x310) = 0;
    I(0x314) = 0;
    I(0x308) = 0;
    I(0x30c) = 0;
    I(0x300) = 0;
    I(0x304) = 0;
    if (F(0x31c) < 0.25f &&
        (I(0x229c) == 0 || I(0x229c) == 12 || I(0x229c) == 9 || I(0x229c) == 7 ||
         (I(0x229c) == 4 && B(0x49c)) || I(0x229c) == 1)) {
        func_L00_002B8E48(ROOT + 0x2a0, difference);
        if (difference[1] > -0.7853982448577881f && difference[1] < 0.7853982448577881f)
            F(0x324) = difference[1];
        if (difference[0] > -0.7853982448577881f && difference[0] < 0.7853982448577881f)
            F(0x328) = difference[0];
        for (side = 0; side < 2; ++side) {
            float angle = 1.5707964897155762f;
            float *height = (float *)(ROOT + 0x300) + side;
            float *yaw = (float *)(ROOT + 0x308) + side;
            float *pitch = (float *)(ROOT + 0x310) + side;
            if (side == 1)
                angle = -angle;
            func_L00_002D3638(left, 1, 0.2f, angle, 0.44999998807907104f);
            func_L00_002D3638(right, 1, 0.2f, angle, -0.44999998807907104f);
            if (!func_002761F8(left, right, 0x22, PLAYER, 0)) {
                *height = 0.0f;
                *yaw = F(0x324);
                *pitch = F(0x328);
            } else {
                if (!D_L07_001A8FF0) {
                    *height = D_L07_001BF640.position[2] - F(0x318);
                } else {
                    float firstHeight = func_002B0360((char *)D_L07_001BF640.position);
                    *height = firstHeight - func_002B0360((char *)ROOT + 0x2d0);
                }
                if (func_00282C48(*height) > 0.4f)
                    *height = 0.0f;
                normalize_vector(normal, D_L07_001BF640.normal);
                func_L00_002B8E48(normal, angles);
                if (angles[1] > -0.7853982448577881f && angles[1] < 0.7853982448577881f)
                    *yaw = angles[1];
                if (angles[0] > -0.7853982448577881f && angles[0] < 0.7853982448577881f)
                    *pitch = angles[0];
            }
        }
    }
}
