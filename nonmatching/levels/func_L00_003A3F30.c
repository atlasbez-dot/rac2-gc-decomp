/* Reconstruction checked 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections.
 * Final check.py coverage: us 0/27, us2 0/27.
 * Manual state/input/cooldown reconstruction704/700 under default G8.
 * Remaining: Extra float save, player/global addressing and conditional layout differ.
 * Reopen with a typed player-state aggregate and ordinary-C control-flow witness.
 * Historical screening below is preserved; its blanket C/ISA claims are not acceptance evidence.
 */

/* func_L00_003A3F30 - 700 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x003a3f30. Screened with tools/w10_screen.py: 13 call(s)
   [func_002A75E0@003A3F90, func_L00_0037E000@003A3FA4,
   func_L00_002C42E0@003A3FE8, func_L00_002D4040@003A401C,
   func_00273318@003A405C, func_00282948@003A4084, func_002829D8@003A409C,
   func_L00_002D3F30@003A40EC, func_0029FCC0@003A410C,
   func_002E5CF8@003A411C, func_002A75E0@003A4134,
   func_L00_003AB8B8@003A4140, func_002E5CF8@003A4188]; data addresses
   materialised [0x190000, 0x190000, 0x260000, 0x3dcc0000, 0x600f0000,
   0x60000000, 0x600f0000, 0x140000, 0x1b0000, 0x140000, 0x1b0000, 0x140000,
   0x1b0000, 0x140000, 0x260000]; float constants [0x40000000, 0x42b40000,
   0x3f800000]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [-]. Head: addiu $sp, $sp,
   -0x40 ; sd $s0, 0x10($sp) ; sd $s1, 0x18($sp) ; daddu $s0, $a0, $zero ;
   sd $s2, 0x20($sp) ; sd $s3, 0x28($sp). Not matched in this wave: the body
   is straight-line code whose register allocation and the materialisation
   of its constant addresses have to be reproduced word for word. What would
   unblock it: the exact source expression tree, so this cc1 picks the same
   registers in the same order. */

#include "common.h"
extern char *D_0018C0B0 NOT_SDA;
extern int D_0018C0B4 NOT_SDA;
extern unsigned char D_0018C0DC NOT_SDA;
extern float D_L00_001AF624 __attribute__((sda));
extern float D_L00_0025C64C NOT_SDA;
extern int D_0018B270 NOT_SDA, D_0018AA18 NOT_SDA;
extern unsigned int D_00138320 NOT_SDA, D_00138324 NOT_SDA, D_0018B050 NOT_SDA;
extern int D_0018B060 NOT_SDA;
extern int D_L00_001B2860 NOT_SDA;
extern int D_0018C354 NOT_SDA;
extern unsigned char D_00139580 NOT_SDA;
typedef struct { char prefix[0x54]; float fireRate; char tail[0x88]; } WeaponEntry;
extern WeaponEntry D_L00_00262570[];
extern void func_002A75E0(void *, int, int, int, int);
extern void func_L00_0037E000(void *);
extern void func_L00_002C42E0(int, int);
extern int func_L00_002D4040(int);
extern void func_00273318(void *, unsigned int, int, int, int, int, float, float, float);
extern int func_00282948(void *);
extern int func_002829D8(void *);
extern int func_L00_002D3F30(int, int);
extern void func_0029FCC0(char *, int, char *);
extern int func_002E5CF8(int, int, char *);
extern char *func_L00_003AB8B8(void *, void *);

/* Update the firing effect and its input-controlled cooldown. */
void func_L00_003A3F30(char *moby)
{
    float position[4];
    float *cooldown = *(float **)(moby + 0x68);
    int ready = 1;
    if (*(unsigned char *)(moby + 0x20) == 0)
        *(unsigned char *)(moby + 0x20) = 1;
    if (*(unsigned char *)(moby + 0x42) == *(unsigned char *)(moby + 0x43) &&
        (*(unsigned char *)(moby + 0x60) & 2))
        func_002A75E0(moby, 1, 0, 2, 0);
    func_L00_0037E000(D_0018C0B0);
    *(float *)(moby + 0x2C) = *(float *)(*(char **)(moby + 0x24) + 0x24) * D_L00_001AF624;
    D_L00_0025C64C = 0.1f;
    if (D_0018C0B4 == 1)
        func_L00_002C42E0(29, 1);
    if (D_0018C0B4 == 29) {
        unsigned int color = 0x600FFF0F;
        if (*cooldown > 0.0f && func_L00_002D4040(-1))
            color = 0x600000FF;
        func_00273318(moby, color, 0, 0x27, -1, 4, 2.0f, 0.0f, 90.0f);
    }
    if (D_0018B270)
        D_0018AA18 = D_0018B270;
    if (D_0018C0B4 == 29)
        ready = func_00282948(&D_0018C354) != 0;
    else
        D_0018C354 = 40;
    if (func_002829D8(cooldown) && !D_0018C0DC &&
        (D_00138320 & D_0018B050) && D_0018B060 > 22 && ready) {
        if (func_L00_002D3F30(-1, 1)) {
            char *effect;
            D_L00_001B2860 = 1;
            func_0029FCC0(moby, 0, (char *)position);
            func_002E5CF8(1, 0, moby);
            func_002A75E0(moby, 2, 0, 2, 0);
            effect = func_L00_003AB8B8(position, moby);
            if (effect)
                *(char **)(effect + 0xB8) = moby;
        } else if ((D_00138324 & D_0018B050) || D_L00_001B2860 == 1) {
            func_002E5CF8(0, 0, moby);
            D_L00_001B2860 = 0;
        }
        *cooldown = 1.0f / D_L00_00262570[D_00139580].fireRate;
    }
}
