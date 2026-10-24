/* Nonmatching: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L00_0039E7A8: 0 of 19 places match (src/levels/shared/L00_0039E7A8-g8.c); us2: absent; pal: absent. Two source trials824 then840/872 bytes, original0x30 frame. Resident scalar accesses outside GP reach use truthful NOT_SDA; player bitmap indices preserve signedness where retail does. Ground-height helper float return and incoming live flag/height arguments verified; overlay clear index supplied. Remaining boolean/control-flow and field-load allocation, no fake padding. Reopen with source state/branch lifetime hypothesis. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
extern int D_L00_001B19C8;
extern unsigned char D_0018C0D4 NOT_SDA;
extern u32 D_0018C0BC NOT_SDA;
extern int D_0018C0B4 NOT_SDA;
extern int D_001A79F0 __attribute__((sda));
extern unsigned char D_0019B2E8[], D_0019B4A8[];
extern unsigned char D_L00_0021E214[], D_L00_0021D5A4[];
extern float D_00189EA0[4];
extern char *D_L00_001AF440 __attribute__((sda));
extern void func_L00_0042A500(int);
extern int func_00282948(int *), func_002ACBC8(void *, int);
extern void func_002A0430(unsigned int);
extern float func_002A89A8(void *, int, float), func_00282C48(float);
extern void func_002DF3F8(void *, void *), func_002B0A18(int, int);
/* Applies a regional activation trigger and records its checkpoint flags. */
void func_L00_0039E7A8(char *actor) {
    int *state = *(int **)(actor + 0x68);
    unsigned int flags;
    unsigned short id;
    unsigned char *packed;
    unsigned char bits;
    int active;
    float point[4];
    if (*(u8 *)(actor + 0x30) < 0x20) *(u8 *)(actor + 0x30) = 0x20;
    if (D_L00_001B19C8 == 0 && state[5] != -1) func_L00_0042A500(state[5]);
    flags = state[2];
    if (flags & 8) return;
    if (*(u8 *)(actor + 0xBC) == 0) {
        *(u8 *)(actor + 0xBC) = 1;
        state[8] = 0;
        state[7] = 0;
        return;
    }
    if (state[6] != -1 && !(D_0019B2E8[state[6] + D_001A79F0 * 16] & 0x80)) return;
    if ((flags & 2) && D_0018C0D4 != 1) return;
    if ((flags & 4) && D_0018C0D4 != 3 && D_0018C0D4 != 0) return;
    if ((flags & 16) && D_0018C0BC > 1 && D_0018C0BC != 9) return;
    if ((flags & 32) && D_0018C0B4 == 49) return;
    if (state[3] == 2 && func_00282948(state + 8)) state[3] = 0;
    active = func_002ACBC8(D_00189EA0, state[0]);
    if (!active) {
        id = *(u16 *)(actor + 0xB2);
        if (D_L00_0021E214[id]) active = 1;
        else {
            bits = D_0019B4A8[(id >> 1) + D_001A79F0 * 0x400];
            if (id & 1) active = ((bits >> 4) & 7) != 0;
            else active = (bits & 7) != 0;
        }
    }
    if (!active) {
        if (state[3]) state[3] = 2;
    } else {
        if (state[3] && (state[4] == 0 || state[8] != 0)) goto finish;
        state[3] = 1;
        func_002A0430(*(u8 *)(actor + 0xB0));
        *(Quad *)point = *(Quad *)(actor + 0x10);
        point[2] = func_002A89A8(point, 0, 0.5f);
        if (func_00282C48(*(float *)(actor + 0x18) - point[2]) > 2.0f) point[2] = *(float *)(actor + 0x18);
        func_002DF3F8(point, actor + 0xF0);
        D_L00_0021D5A4[*(short *)(actor + 0xB2)] = 0;
        D_L00_0021E214[*(short *)(actor + 0xB2)] = 0;
        packed = D_0019B4A8 + ((*(short *)(actor + 0xB2)) >> 1) + D_001A79F0 * 0x400;
        bits = *packed;
        if (*(u16 *)(actor + 0xB2) & 1) *packed = bits & 0x8F;
        else *packed = bits & 0xF8;
        if (state[9] && D_L00_001AF440 != actor) {
            func_002B0A18(0x2F36, 90);
            D_L00_001AF440 = actor;
        }
        state[8] = 900;
    }
finish:
    if (*(u8 *)(actor + 0x20) == 0 && (D_0019B2E8[*(u8 *)(actor + 0xB0) + D_001A79F0 * 16] & 0x80)) *(u8 *)(actor + 0x20) = 1;
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_0039E7A8 - 872 bytes, 19 place(s), level 00_aranos_tutorial,
   retail at 0x0039e7a8. Screened with tools/w10_screen.py: 8 call(s)
   [func_L00_0042A500@0039E7F4, func_00282948@0039E8F4,
   func_002ACBC8@0039E90C, func_002A0430@0039E9B8, func_002A89A8@0039E9D8,
   func_00282C48@0039E9E8, func_002DF3F8@0039EA14, func_002B0A18@0039EA98];
   data addresses materialised [0x1b0000, 0x190000, 0x190000, 0x190000,
   0x190000, 0x190000, 0x190000, 0x220000, 0x1a0000, 0x220000, 0x220000,
   0x1a0000, 0x1a0000, 0x1a0000, 0x1a0000]; float constants [0x1a0000,
   0x1a0000, 0x3f000000, 0x40000000]; $gp-relative small data: no   saves:
   -; callee-saved registers saved [-]; words plain C cannot emit [LQ/SQ
   78620000@0x021c, LQ/SQ 7FA20000@0x0220]. Head: addiu $sp, $sp, -0x30 ; sd
   $s0, 0x10($sp) ; sd $s1, 0x18($sp) ; daddu $s0, $a0, $zero ; sd $ra,
   0x20($sp) ; lbu $v0, 0x30($s0). Not matched in this wave: the 128-bit
   copy needs an `lq`/`sq` pair; plain C reaches it only through a
   `mode(TI)` local, and this cc1 folds the destination offset into the `sq`
   where retail materialises the pointer first. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */
