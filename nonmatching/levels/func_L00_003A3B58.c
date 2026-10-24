/* Reconstruction checked 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final check.py coverage: us 0/27, us2 0/27.
 * Manual aim/spawn reconstruction952/980 with qcopy/barrier G8.
 * Remaining: Aim-result/target globals, mixed GP/direct state access, branches and register allocation differ.
 * Reopen with a measured target-state aggregate model.
 * The qualified R5900 view decodes the cited SPECIAL2 word as por, not an unknown instruction.
 * Historical screening below is preserved; its blanket C/ISA claims are not acceptance evidence.
 */

/* MMI (SPECIAL2) instruction: no C spelling. 980 bytes, level
   00_aranos_tutorial. Retail at 0x003A3B58 carries the SPECIAL2 word
   0x700014A9 (+0x02CC) - opcode 0x1C, which rabbitizer prints as `INVALID`;
   it is the MMI family (pcpyld and its relatives) the sixth wave recorded
   and that no C spelling reaches. This cc1 emits `lq`/`sq` for a `mode(TI)`
   local and `ldl`/`ldr`/`sdl`/`sdr` for a struct assignment, never the
   packed copy. ASM_FUNC candidate, as for the rest of the family. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
typedef struct { char prefix[0x50]; float speed; char tail[0x8C]; } WeaponEntry;
extern WeaponEntry D_L00_00262570[];
extern unsigned char D_0013957F NOT_SDA;
extern short D_0018C30C NOT_SDA;
extern float D_0018A580[4];
extern int D_0018B320 NOT_SDA;
extern VectorBits D_0018AA18;
extern int D_L00_001ADB2C __attribute__((sda));
extern char *D_0018C0B0 NOT_SDA;
extern char *D_L00_001BF218 NOT_SDA;
extern void func_0029FCC0(char *, int, char *);
extern void func_00282F20(void *, void *, float);
extern int func_00291308(int, void *, unsigned int, float);
extern void func_L00_0037FA90(char *, char *, float, float, float);
extern void func_L00_0032A1A8(char *, char *, char *, float);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DB0(void *, void *);
extern void func_00282D30(void *, void *, float);
extern char *func_L00_003A7C30(void *, void *, int, int);
extern int func_00277F48(void *, int, void *, int, float);
extern int func_002ABB78(char *);
extern int func_L00_003A80F8(char *, void *);
extern char *func_002C2210(void *, int, unsigned int, int, int, void *, int, float, float, float);

/* Aim and spawn a beam, then flash four layers around its muzzle. */
void func_L00_003A3B58(char *moby)
{
    float origin[4], velocity[4], targetPosition[4], delta[4], unit[4];
    char *state = *(char **)(moby + 0x68);
    char *beam;
    float speed = D_L00_00262570[D_0013957F].speed * (1.0f / 60.0f);
    int mode = 0;
    if (D_0018C30C == 1) {
        func_0029FCC0(moby, 0, (char *)origin);
        func_00282F20(velocity, moby + 0xD0, -speed);
    } else {
        func_0029FCC0(moby, 0, (char *)origin);
        func_00282F20(velocity, D_0018A580, speed);
    }
    *(int *)(state + 0x10) = func_00291308(0, origin, 0x7F608060, 15.0f);
    *(int *)(state + 0x14) = 30;
    if (D_0018B320) {
        mode = 1;
        func_L00_0037FA90((char *)velocity, (char *)origin, speed, 128.0f, 0.3490659595f);
    } else if (*(char **)&D_0018AA18) {
        func_L00_0032A1A8(*(char **)&D_0018AA18, (char *)origin, (char *)velocity, speed);
    }
    if (D_L00_001ADB2C) {
        char *target = *(char **)(state + 0x30);
        if ((target && D_0018B320) || !*(char **)&D_0018AA18 || D_0018B320) {
            if (target)
                *(VectorBits *)targetPosition = *(VectorBits *)(target + 0x10);
            else
                *(VectorBits *)targetPosition = D_0018AA18;
            func_00282CF0(delta, targetPosition, origin);
            mode = 2;
            func_00282F20(unit, velocity, 1.0f);
            func_00282D30(velocity, unit, func_00282DB0(unit, delta) + 3.0f);
        }
    }
    beam = func_L00_003A7C30(origin, velocity, *(int *)(state + 0x18), mode);
    if (beam)
        *(char **)(beam + 0xB8) = moby;
    if (func_00277F48(origin, 1, D_0018C0B0, 0, 1.0f) && D_L00_001BF218) {
        char *hit = D_L00_001BF218;
        char *model = *(char **)(hit + 0x24);
        if ((model && *(short *)(model + 0x46) == 5) || func_002ABB78(hit))
            func_L00_003A80F8(beam, hit + 0x10);
    }
    *(VectorBits *)targetPosition = 0;
    func_002C2210(origin, 8, 0x4010FF10, 2, 1, targetPosition, 1, 7.0f, 0.1f, 0.0f);
    func_002C2210(origin, 8, 0x4010FF10, 2, -1, targetPosition, 1, 5.0f, 0.1f, 0.0f);
    func_002C2210(origin, 8, 0xC0FFFFFF, 2, 1, targetPosition, 1, 3.0f, 0.1f, 0.0f);
    func_002C2210(origin, 8, 0xB0FFFFFF, 2, -1, targetPosition, 1, 2.5f, 0.1f, 0.0f);
}
