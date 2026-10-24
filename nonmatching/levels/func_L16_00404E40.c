/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * Reported final C / retail: 272 / 268 bytes; size equality is not a match.
 * us: 0/1 placements; 272/268 bytes.
 * us2: 0/1 placements; 272/268 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: FP phi register/move selection and GPR allocation; reopen with a source lifetime hypothesis.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Manual reconstruction, 2026-10-23: NOT MATCHED. US 272/268 bytes,
 * 0/1 placements; profile: -O2 -ffunction-sections G0 qcopy/qcopy-barrier/zero-ti-por.
 * FP phi register/move selection and GPR allocation; reopen with a source lifetime hypothesis.
 * Historical screening notes below are preserved; the current measured
 * residual replaces any earlier claim that lq/sq/por cannot be emitted. */
/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

#include "common.h"
typedef int BossQuadword __attribute__((mode(TI)));
extern u8 *D_L16_001FE7C0[];
extern void func_00282CF0(void *, void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_00282E48(void *, void *);
extern float func_00282E80(void *, void *);
extern int func_L07_00321D68(char *, void *);
extern void func_0029FCC0(char *, int, char *);
extern void func_0029FC20(char *, int, char *);
extern void func_00283678(void *, void *);
extern void func_002A0F48(void *);

int func_L16_00404E40(u8 *moby)
{
    float point[4] __attribute__((aligned(16)));
    float step[4] __attribute__((aligned(16)));
    u8 *state = *(u8 **)(moby + 0x68);
    u8 *path = D_L16_001FE7C0[*(int *)(state + 0x294)];
    if (*(int *)(state + 0x2a4) >= *(int *)path) return 1;
    *(BossQuadword *)point = *(BossQuadword *)(path + 16 + *(int *)(state + 0x2a4) * 16);
    func_00282CF0(step, point, moby + 0x10);
    func_00282F20(step, step, 0.20000002f);
    func_L07_00321D68((char *)moby, step);
    {
        float distance;
        if (!*(int *)(state + 0x2ac)) distance = func_00282E80(moby + 0x10, point);
        else distance = func_00282E48(moby + 0x10, point);
        if (distance < 0.5f) (*(int *)(state + 0x2a4))++;
    }
    return 0;
}
