/* Reconstruction checked 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * Final check.py coverage: us 0/27, us2 0/27.
 * Qcopy/barrier/-g source equals580 bytes; splitting lifetime arithmetic onto separate lines gave588/580 and was reverted.
 * Remaining: First difference +0x34; short-circuit/create exits, table-base scheduling and division padding differ.
 * Reopen with source control-flow and typed table lifetime evidence.
 * Historical screening below is preserved; its blanket C/ISA claims are not acceptance evidence.
 */

/* func_L00_003A7C30 - 580 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x003a7c30. Screened with tools/w10_screen.py: 14 call(s)
   [func_002B4038@003A7C70, func_0029EFD0@003A7C88, func_003001E0@003A7CD0,
   func_00283CF0@003A7D1C, func_00283CE0@003A7D2C,
   func_L00_0032A088@003A7D54, func_002AFFD8@003A7D68,
   func_00282D30@003A7D7C, func_L00_003A8060@003A7D88,
   func_L00_003A8E28@003A7DC8, func_00282DF0@003A7DF4,
   func_00282F20@003A7E04, func_00282CC0@003A7E2C,
   func_L00_003A80F8@003A7E38]; data addresses materialised [0x140000,
   0x260000, 0x3c880000, 0x1c0000]; float constants [0x43000000, 0x3f800000,
   0xbf800000]; $gp-relative small data: yes   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [LQ/SQ 7A620000@0x0088,
   LQ/SQ 7E820000@0x008c, LQ/SQ 7A020000@0x01b8, LQ/SQ 7C620000@0x01bc,
   LQ/SQ 7A620000@0x01ec, LQ/SQ 7E020000@0x01f0]. Head: addiu $sp, $sp,
   -0x60 ; addiu $v0, $zero, -0x1 ; sd $s0, 0x20($sp) ; sd $s3, 0x38($sp) ;
   daddu $s0, $a2, $zero ; sd $s5, 0x48($sp). Not matched in this wave: the
   128-bit copy needs an `lq`/`sq` pair; plain C reaches it only through a
   `mode(TI)` local, and this cc1 folds the destination offset into the `sq`
   where retail materialises the pointer first. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
typedef struct { char pad[0x50]; float speed; char tail[0x8C]; } WeaponEntry;
extern WeaponEntry D_L00_00262570[];
extern unsigned char D_0013957F;
extern unsigned int D_L00_001AF6D4 __attribute__((sda));
extern float D_L00_001B8DC0[4], D_L00_001B8FF0[4];
extern int func_002B4038(int, int);
extern char *func_0029EFD0(int);
extern void func_003001E0(void *, void *, void *);
extern int func_00283CF0(float);
extern float func_00283CE0(int);
extern char *func_L00_0032A088(int, int);
extern void func_002AFFD8(char *, char *, int);
extern void func_00282D30(void *, void *, float);
extern void func_L00_003A8060(char *, char *);
extern void func_L00_003A8E28(void *);
extern float func_00282DF0(void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_L00_003A80F8(char *, void *);

/* Spawn and configure one moving beam effect. */
char *func_L00_003A7C30(void *position, void *velocity, int handle, int mode)
{
    float normal[4], previous[4];
    char *moby, *state;
    if (handle == -1 || !func_002B4038(0x5CB, handle))
        return 0;
    moby = func_0029EFD0(0x5D6);
    if (!moby)
        return 0;
    *(unsigned char *)(moby + 0x30) = 0xFF;
    *(unsigned short *)(moby + 0x32) = 0xFF;
    *(unsigned char *)(moby + 0x31) = 1;
    state = *(char **)(moby + 0x68);
    *(VectorBits *)(moby + 0x10) = *(VectorBits *)position;
    *(unsigned char *)(moby + 0x20) = 0;
    *(short *)(state + 0x12) = mode;
    func_003001E0(state, velocity, position);
    *(short *)(state + 0x10) = func_00283CF0(128.0f / (D_L00_00262570[D_0013957F].speed * (1.0f / 60.0f)));
    *(float *)(state + 0x14) = 1.0f / func_00283CE0(*(short *)(state + 0x10));
    *(short *)(state + 0x1A) = handle;
    *(char **)(state + 0x1C) = func_L00_0032A088(0x5CB, handle);
    func_002AFFD8(moby + 0x10, (char *)normal, 1);
    func_00282D30(normal, normal, -1.0f);
    func_L00_003A8060(moby, (char *)normal);
    if (D_L00_001AF6D4 >= 4)
        D_L00_001AF6D4 = 0;
    *(short *)(state + 0x18) = D_L00_001AF6D4;
    D_L00_001AF6D4 = (int)(D_L00_001AF6D4 + 1) % 3;
    func_L00_003A8E28(moby);
    if (mode == 1) {
        *(VectorBits *)(state + 0x30) = *(VectorBits *)D_L00_001B8DC0;
        func_00282F20(state + 0x20, D_L00_001B8FF0, func_00282DF0(velocity));
    }
    if (mode == 2) {
        *(VectorBits *)previous = *(VectorBits *)position;
        func_00282CC0(moby + 0x10, position, velocity);
        if (func_L00_003A80F8(moby, previous))
            *(unsigned char *)(moby + 0x20) = 2;
    }
    return moby;
}
