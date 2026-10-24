/* Retained manual C reconstruction; not linked or counted.
 * Retail: 924 bytes. Checked trial: src/levels/12_todano/L12_0041EA18-g8.c
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * us: 0/1 placements (exit 1), 908 compiled bytes
 * us2: explicit catalogue absence (exit 1); no credit
 * pal: explicit catalogue absence (exit 1); no credit
 * Residual: The 0x60-byte frame size agrees, but the initial vector capture and object/data live ranges use different GPRs; mixed GP and absolute accesses to the shared height-table pointer also remain.
 * Reopen: Recover the original position-pointer lifetime and the measured dual addressing of the height table before reopening.
 * The ASM marker and trial-only file profile were restored after checks.
 */

#include "common.h"
typedef int LiftQuad __attribute__((mode(TI)));
extern u8 *D_L12_001B2F8C;
extern u8 D_00189E20[];
extern int D_00138324;
extern u8 D_00188660[];
extern void func_002A7750(u8 *object, int animation, int frame);
extern int func_002B38B8(u8 *object);
extern float func_00282C48(float x);
extern void func_002B0C28(int channel, int message, int mode);
extern float func_00282E80(void *a, void *b);
extern int func_002ACBC8(void *point, int index);
extern float func_002AA548(float *value, float *velocity, float target, float minimum, float acceleration, float maximum);
extern void func_002E59F8(int index);
extern int func_002E5CF8(int index, int kind, char *object);
extern void func_00282CF0(void *out, void *a, void *b);
extern void func_002AD6F0(void *matrix, void *offset, void *a, void *b);

void func_L12_0041EA18(u8 *object)
{
    LiftQuad oldPosition;
    LiftQuad displacement;
    u8 *data = *(u8 **)(object + 0x68);
    u8 *sound;
    float target;
    float rate;
    float reference;
    int index;
    oldPosition = *(LiftQuad *)(object + 0x10);
    if (object[0x20] == 0) {
        *(LiftQuad *)(data + 0x70) = *(LiftQuad *)(object + 0x10);
        func_002A7750(object, 1, -1);
    } else if (object[0x20] == 1 && func_002B38B8(object)) {
        if (*(int *)(data + 0x68))
            target = *(float *)(D_L12_001B2F8C + *(int *)(data + 0x60) * 128 + 0x38);
        else
            target = *(float *)(data + 0x78);
        if (func_00282C48(target - *(float *)(object + 0x18)) < 2.0f) {
            reference = *(float *)(D_L12_001B2F8C + *(int *)(data + 0x60) * 128 + 0x38);
            if (*(u8 **)(D_00189E20 + 0x33c) == object && *(int *)(D_00189E20 + 0x340)) {
                func_002B0C28(8, 0x279a, 1);
                if (D_00138324 & 0x10)
                    *(int *)(data + 0x68) = (*(int *)(data + 0x68) + 1) & 1;
            } else if (*(int *)(data + 0x68)) {
                if (func_00282C48(*(float *)(D_00189E20 + 0x88) - *(float *)(data + 0x78)) < 4.0f &&
                    func_00282E80(D_00189E20 + 0x80, object + 0x10) < 24.0f)
                    *(int *)(data + 0x68) = 0;
            } else {
                if (func_00282C48(*(float *)(D_00189E20 + 0x88) - reference) < 4.0f &&
                    func_00282E80(D_00189E20 + 0x80, object + 0x10) < 24.0f)
                    *(int *)(data + 0x68) = 1;
            }
        }
        rate = 0.003888888983055949f;
        if (*(int *)(data + 0x68)) {
            if (*(float *)(D_00189E20 + 0x88) < *(float *)(object + 0x18) - 1.0f &&
                func_002ACBC8(D_00189E20 + 0x80, *(int *)(data + 0x60))) {
                target += 3.0f;
                rate = 0.007777777966111898f;
            } else {
                target += 0.5f;
            }
        }
        func_002AA548((float *)(object + 0x18), (float *)(data + 0x6c), target, 0.0019444444915279746f, rate, 0.5f);
        if (func_00282C48(target - *(float *)(object + 0x18)) < 0.8f) {
            index = *(int *)(data + 0x80);
            if (index != -1) {
                sound = D_00188660 + index * 112;
                if (*(u8 **)(sound + 0x88) == object && sound[0x74])
                    func_002E59F8(index);
            }
            *(int *)(data + 0x80) = -1;
        } else {
            sound = D_00188660 + *(int *)(data + 0x80) * 112;
            if (*(u8 **)(sound + 0x88) != object || sound[0x74] == 0)
                *(int *)(data + 0x80) = func_002E5CF8(0, 4, (char *)object);
        }
    }
    func_00282CF0(&displacement, object + 0x10, &oldPosition);
    func_002AD6F0(data + 0x20, &displacement, object + 0xf0, object + 0xf0);
}
