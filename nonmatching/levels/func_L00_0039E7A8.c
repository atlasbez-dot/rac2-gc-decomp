/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * 840/872 bytes. us: 0/19 places; us2: absent; pal: absent.
 * Remaining: Real qcopy reproduces the complete local trigger-position transfer; current
 * live flag/height and float ground-height contracts are retained. The 0x30
 * frame agrees, but boolean/control-flow and field-load allocation still differ.
 * Reopen with: Independent trigger-state branch/lifetime evidence; the helper gives
 * the same 840-byte extent, not an exact match.
 */

/* M12, 2026-10-26: 852/872 bytes (-O2 -G8). D_001A79F0 is a plain scalar ($gp in delay slots,
 * lui/lw elsewhere); D_0019B2E8/D_0019B4A8 are MACRO_ADDR; the two flag tables are la'd at
 * 0x21D140 and 0x21DDB0 with the field offset 0x464 left in the load (this cc1 folds it into the
 * la in every spelling tried: struct field, [id + 0x464], local struct pointer). The inactive test
 * branches directly as retail. Residual: that fold, the flags copy register and a few schedules.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
extern int D_L00_001B19C8;
extern unsigned char D_0018C0D4 NOT_SDA;
extern u32 D_0018C0BC NOT_SDA;
extern int D_0018C0B4 NOT_SDA;
extern int D_001A79F0;
extern unsigned char D_0019B2E8[] MACRO_ADDR, D_0019B4A8[] MACRO_ADDR;
extern u8 D_L00_0021D140[] MACRO_ADDR, D_L00_0021DDB0[] MACRO_ADDR;
extern float D_00189EA0[4];
extern char *D_L00_001AF440 __attribute__((sda));
extern void func_L00_0042A500(int arg0);
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
    int bits;
    int active;
    float point[4];
    if (*(u8 *)(actor + 0x30) < 0x20) *(u8 *)(actor + 0x30) = 0x20;
    if (D_L00_001B19C8 == 0 && state[5] != -1) func_L00_0042A500(state[5]);
    flags = state[2];
    if (flags & 8) return;
    if (*(u8 *)(actor + 0xBC) == 0) {
        *(u8 *)(actor + 0xBC) = 1;
        state[7] = 0;
        state[8] = 0;
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
        if (!D_L00_0021DDB0[(short)id + 0x464]) {
            bits = D_0019B4A8[((short)id >> 1) + D_001A79F0 * 0x400];
            if (id & 1 ? !((bits >> 4) & 7) : !(bits & 7)) {
                if (state[3]) state[3] = 2;
                goto finish;
            }
        }
    }
    {
        if (state[3] && (state[4] == 0 || state[8] != 0)) goto finish;
        state[3] = 1;
        func_002A0430(*(u8 *)(actor + 0xB0));
        qcopy(point, (actor + 0x10));
        point[2] = func_002A89A8(point, 0, 0.5f);
        if (func_00282C48(*(float *)(actor + 0x18) - point[2]) > 2.0f) point[2] = *(float *)(actor + 0x18);
        func_002DF3F8(point, actor + 0xF0);
        D_L00_0021D140[*(short *)(actor + 0xB2) + 0x464] = 0;
        D_L00_0021DDB0[*(short *)(actor + 0xB2) + 0x464] = 0;
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
