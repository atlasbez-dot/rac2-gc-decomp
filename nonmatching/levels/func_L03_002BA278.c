/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: proposed -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier; not compiled.
 * Retail extent: 2180 bytes; final compiled size not separately reported.
 * us: not-run Known all-release canonical func_001290BC+0x24 jal-addend assembler rejection; no fake alias..
 * us2: not-run Known all-release canonical func_001290BC+0x24 jal-addend assembler rejection; no fake alias..
 * pal: not-run Known all-release canonical func_001290BC+0x24 jal-addend assembler rejection; no fake alias..
 * Residual: Complete manual homolog with Endako branch differences retained. Unqualified interior-entry call representation.
 * Reopening condition: Qualified canonical-symbol-plus-addend call route or measured generator boundary correction.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Endako contact update, reconstructed from existing manually written
 * func_L07_002B3580 and verified retail branch differences. This version
 * omits Siberius's mode13/mode3 extra raycasts and mode11 floor case;
 * mode1 actions0x79/0x7a skip the common contact block. Endako also lacks
 * the sibling's +0x18c0 state clear. Collision base is level03 001bfDC0.
 * No compile was repeated: both normalizations require canonical
 * func_001290BC+0x24, the same all-release assembler blocker documented
 * in the sibling. The existing GNU assembler rejects direct jal addends.
 * No fake alias, numeric resident entry, catalogue edit or match claim.
 * Reopen with a qualified canonical interior-entry call representation.
 */
#include "include_asm.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { char prefix[0x18]; unsigned char *object; int count; float position[4]; char gap[16]; float normal[4]; } Collision;
extern unsigned char D_00189E20[];
extern int D_001A79F0;
extern int D_L03_001A8FF0;
extern int D_L03_001A8FF4;
extern Collision D_L03_001BFDC0;
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

void func_L03_002BA278(void)
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
        if (D_L03_001BFDC0.object)
            B(0x149d) = 0;
        if (D_001A79F0 == 7 && D_L03_001BFDC0.object)
            B(0x149d) = 1;
        H(0x1490) = func_00278E78();
        if (!H(0x1490)) {
            F(0x330) = func_002A90F8(D_L03_001BFDC0.position, ROOT + 0x2b0);
            if (F(0x88) < F(0x330) && I(0x338) < 1)
                I(0x338) = 1;
            if (!func_002761F8(start, end, 0x24, PLAYER, 0))
                goto contacts_done;
            B(0x149d) = func_L00_002E2048();
        }
        if (H(0x1490) != 1 || (unsigned int)(I(0x2294) - 0x79) > 1) {
            if (D_L03_001BFDC0.object) {
                unsigned char *record;
                if (func_002ABB78((char *)D_L03_001BFDC0.object))
                    H(0x34a) = 1;
                record = (unsigned char *)func_002AB1F0(D_L03_001BFDC0.object);
                if (record && (*(unsigned short *)(record + 0x1e) & 8))
                    H(0x34a) = 1;
                record = (unsigned char *)func_002AD0B0(D_L03_001BFDC0.object);
                if (record && (*(unsigned int *)(record + 0x3c) & 8))
                    H(0x34a) = 1;
            }
            if (D_L03_001BFDC0.count > 0) {
                V(0x2d0) = *(Quad *)D_L03_001BFDC0.position;
                F(0x318) = D_L03_001BFDC0.position[2];
                if (D_L03_001A8FF0)
                    F(0x318) = func_002B0360((char *)D_L03_001BFDC0.position);
                F(0x31c) = func_00282E48(ROOT + 0x80, ROOT + 0x2d0);
                I(0x33c) = (int)D_L03_001BFDC0.object;
                normalize_vector(ROOT + 0x2a0, D_L03_001BFDC0.normal);
                F(0x320) = func_L00_002D3EA8(D_L03_001BFDC0.normal);
                F(0x32c) = func_00283248(D_L03_001BFDC0.normal[0], D_L03_001BFDC0.normal[1]);
                func_00282CF0(difference, ROOT + 0x2d0, ROOT + 0x80);
                if (func_00282DB0(difference, ROOT + 0x2a0) > 0.0f)
                    F(0x31c) = -F(0x31c);
                if (F(0x31c) < 0.02f) {
                    H(0x34c) = 0;
                    if (F(0x320) <= 0.8726646900177002f || B(0x22c3)) {
                        H(0x34e) = 0;
                        I(0xc10) = (int)D_L03_001BFDC0.object;
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
    } else {
        I(0x340) = 0;
    }
    func_00282C88((Quad *)(ROOT + 0x2c0));
    if (B(0x22c3) == 1) {
        if (!D_L03_001A8FF4) {
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
                if (!D_L03_001A8FF0) {
                    *height = D_L03_001BFDC0.position[2] - F(0x318);
                } else {
                    float firstHeight = func_002B0360((char *)D_L03_001BFDC0.position);
                    *height = firstHeight - func_002B0360((char *)ROOT + 0x2d0);
                }
                if (func_00282C48(*height) > 0.4f)
                    *height = 0.0f;
                normalize_vector(normal, D_L03_001BFDC0.normal);
                func_L00_002B8E48(normal, angles);
                if (angles[1] > -0.7853982448577881f && angles[1] < 0.7853982448577881f)
                    *yaw = angles[1];
                if (angles[0] > -0.7853982448577881f && angles[0] < 0.7853982448577881f)
                    *pitch = angles[0];
            }
        }
    }
}
