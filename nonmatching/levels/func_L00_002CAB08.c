/* Near miss (M38): 652/648 bytes, us 0/27, us2 0/27, absent from PAL. Profile -O2 -G0
 * -ffunction-sections -frac2-keep-block-order -frac2-gcse-unsplit-edges.
 * Solved: the head through the first func_L00_002ADEA0 test is exact with arm 11 written as the
 * `then` of `if (gate && offset > 0 && func_L00_0032EFB0(..)) ref(11,1); else {...}` (retail
 * keeps that call uncross-jumped, with its own `b` to the epilogue).
 * Retail facts not yet reproduced: (1) every later arm (10, 16, 13, 15) branches BACK to arm
 * 11's `jal` with its a0 in the delay slot, so the shared call is arm 11's; only the default
 * (7) has its own call, falling into the epilogue. A trailing shared ref(state,1) puts the join
 * at the end instead. (2) D_001A7AFA is read lui/lbu with a nop in the preceding bne slot: a
 * split absolute access whose lui does not fill the slot (plain extern lets the lui fill it;
 * the sda incomplete array gives a $gp lbu in the slot and folds 15/7 into a movn). */
#include "include_asm.h"
#include "common.h"
typedef struct {
    unsigned char pad0[0x160]; float velocity[4];
    float field_170, elapsed_174, speed_178;
    unsigned char pad1[0x1B4 - 0x17C]; float animation_time; int count_1b8;
    unsigned char pad2[4]; int count_1c0;
    unsigned char pad3[0x1E0 - 0x1C4]; short flag_1e0;
    unsigned char pad4[2]; short flag_1e4;
    unsigned char pad5[0x278 - 0x1E6]; float distance_278;
    unsigned char pad6[4]; float angle_280; unsigned char flag_284;
    unsigned char pad7[0x40E - 0x285]; unsigned char flag_40e;
    unsigned char pad8[0x49C - 0x40F]; unsigned char level_49c;
    unsigned char pad9[0xC20 - 0x49D]; float animation_scale;
    unsigned char pad10[4]; int flags_c28;
    unsigned char pad11[0x1454 - 0xC2C]; short flag_1454; unsigned char flag_1456;
    unsigned char pad12[0x1492 - 0x1457]; unsigned char flag_1492;
    unsigned char pad13[0x2290 - 0x1493]; void *object; int mode, frame;
    unsigned char pad14[0x22B4 - 0x229C]; unsigned char mode_22b4;
    unsigned char pad15[4]; unsigned char flag_22b9;
    unsigned char pad16[0x24A0 - 0x22BA]; int reset_24a0;
    unsigned char pad17[0x24B8 - 0x24A4]; float timer;
    unsigned char pad18[0x24FC - 0x24BC]; short flag_24fc;
} HeroActionState;
extern HeroActionState D_00189E20;

extern unsigned int D_00138320[];
extern int ref_L00_002CAB08_00(int, int);

extern int func_L00_002C3A40(void);
extern int func_L00_0032EFB0(int, int, int, int);
extern int func_L00_0032EF10(int, int, int *);
extern int func_L00_002ADEA0(int);
extern unsigned char D_001A7AFA;

int func_L00_002CAB08(void)
{
    int offset;
    int state;
    if (D_00189E20.mode == 14) return 0;
    offset = func_L00_002C3A40();
    if ((D_00138320[0] & 8) && offset > 0 && func_L00_0032EFB0(0x40, 0x1F000, offset + 5, offset)) {
        ref_L00_002CAB08_00(11, 1);
    } else {
        if (D_00189E20.count_1b8 < 7) return 0;
        if (!func_L00_0032EF10(0x40, 9, 0)) return 0;
        if (func_L00_002ADEA0(3) == 2 && D_001A7AFA != 0 &&
            D_00189E20.flag_24fc == 0 &&
            (2.5f < D_00189E20.distance_278 || D_00189E20.angle_280 < 0.785398244857788086f) &&
            0.7f < D_00189E20.timer &&
            0.015000000596046448f < D_00189E20.speed_178) {
            state = 10;
        } else if (func_L00_002ADEA0(3) == 3 && D_00189E20.flag_24fc == 0 &&
            0.7f < D_00189E20.timer &&
            (2.5f < D_00189E20.distance_278 || D_00189E20.flag_284 != 0) &&
            0.015000000596046448f < D_00189E20.speed_178) {
            if (D_00189E20.flag_1e4 != 0) return 1;
            state = 16;
        } else if (func_L00_002ADEA0(3) == 3 && D_00189E20.flag_24fc == 0) {
            state = 13;
        } else if (func_L00_002ADEA0(3) == 2 && D_00189E20.flag_24fc == 0 && D_001A7AFA != 0) {
            state = 15;
        } else {
            state = 7;
        }
        ref_L00_002CAB08_00(state, 1);
    }
    return 1;
}
