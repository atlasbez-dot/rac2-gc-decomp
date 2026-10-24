/* Reconstruction checked 23 October 2026.
 * Profile: -O2 -G0 -ffunction-sections.
 * Final check.py coverage: us 0/27, us2 0/27.
 * Literal multiplication560/576; local size with -fno-gcse556/576. Retained local-size source under default produces580/576.
 * Remaining: Extra saved GPR, material/data address lifetimes and scalar FPR assignment differ.
 * Reopen with a measured scene-material/base lifetime model.
 * Historical screening below is preserved; its blanket C/ISA claims are not acceptance evidence.
 */

/* func_L00_003A78B0 - 576 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x003a78b0. Screened with tools/w10_screen.py: 12 call(s)
   [func_00282D30@003A7958, func_00282CC0@003A7968, func_00282D30@003A7984,
   func_00282CC0@003A7998, func_00282D30@003A79B0, func_002A78D8@003A79C8,
   func_002A78D8@003A79E4, func_002A78D8@003A79FC, func_002A77E0@003A7A10,
   func_002C65A0@003A7A4C, func_002C65A0@003A7A84, func_00282CC0@003A7AAC];
   data addresses materialised [0xbdcc0000, 0x3e330000, 0x3dcc0000,
   0x48800000, 0x484d0000, 0x3e190000, 0xbd080000, 0x200000, 0x800000,
   0x1b0000, 0x200000, 0x1b0000]; float constants [-]; $gp-relative small
   data: no   saves: -; callee-saved registers saved [-]; words plain C
   cannot emit [-]. Head: addiu $sp, $sp, -0xA0 ; lui $at, 0xBDCC ; ori $at,
   $at, 0xCCCD ; mtc1 $at, $f12 ; sd $s0, 0x40($sp) ; sd $s1, 0x48($sp). Not
   matched in this wave: the body is straight-line code whose register
   allocation and the materialisation of its constant addresses have to be
   reproduced word for word. What would unblock it: the exact source
   expression tree, so this cc1 picks the same registers in the same order. */

#include "common.h"
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern float func_002A78D8(float, float);
extern int func_002A77E0(int);
extern char *func_002C65A0(void *, void *, int, unsigned int, int, int, int, int, float, float, float);
extern char D_L00_001A8F20[];
typedef struct { char prefix[0xD4]; unsigned char *material; } SceneMaterialPrefix;
extern SceneMaterialPrefix D_L00_001FE940;

/* Emit the two layers of a short particle trail. */
void func_L00_003A78B0(char *moby)
{
    float point[4], offset[4], step[4], jitter[4];
    char *state = *(char **)(moby + 0x68);
    float size = 210000.0f;
    int i;
    point[0] = *(float *)(state + 0x14);
    point[1] = *(float *)(state + 0x18);
    point[2] = *(float *)(state + 0x1C);
    point[3] = 0.0f;
    func_00282D30(offset, moby + 0xD0, -0.1f);
    func_00282CC0(point, point, offset);
    func_00282D30(step, moby + 0xE0, 0.15f);
    func_00282CC0(point, point, step);
    func_00282D30(step, moby + 0xE0, -0.03333333507f);
    for (i = 8; i >= 0; i--) {
        char *particle;
        int rotation;
        jitter[0] = point[0] + func_002A78D8(0.0f, 0.1f);
        jitter[1] = point[1] + func_002A78D8(0.0f, 0.1f);
        jitter[2] = point[2] + func_002A78D8(0.0f, 0.1f);
        rotation = func_002A77E0(255);
        func_002C65A0(jitter, D_L00_001A8F20, 4, 0x808080, rotation, 127, 127, 1,
                      size * 0.175f, size * 0.175f, 0.0f);
        particle = func_002C65A0(point, D_L00_001A8F20, 4, 0x203080, rotation, 16, 16, 1,
                                 262500.0f, 262500.0f, 0.0f);
        if (particle)
            *(unsigned char *)(particle + 2) = *D_L00_001FE940.material;
        func_00282CC0(point, point, step);
    }
}
