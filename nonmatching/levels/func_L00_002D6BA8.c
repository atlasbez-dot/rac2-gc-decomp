/* func_L00_002D6BA8: retained near miss (M9, 2026-10-26).
 * Profile -O2 -G0 -ffunction-sections. 1068/1068 bytes, 0/27; 8 instructions differ,
 * all one register swap: the two count-array addresses (sp+0x10, sp+0x20) get s3/s4
 * the other way round from retail. A real switch (with case 0) gives the retail jump
 * table; natural indexed clear/divide loops give retail's operand order and scheduling.
 * Why: gcse creates the address pseudos in hash order (sp+16 first, regno 473 < 474) and
 * global-alloc breaks the equal-priority tie by allocno. Retail needs sp+32's pseudo to
 * win: a shorter live range or one more ref. Clear-loop store permutations (24),
 * final-loop pointer walks (48) and array declaration orders don't do it (separate
 * declarations modulated/additive/modulate give a 2-word miss but the wrong stack layout).
 */
#include "include_asm.h"
typedef unsigned char u8;
typedef struct {
    u8 field0;
    u8 active;
    u8 channel;
    u8 modulate;
    short delay;
    short count;
    short phase;
    short rise;
    short fall;
    u8 amplitude;
    u8 bias;
} ConditionalResetSlot;

extern ConditionalResetSlot D_L00_001B8C00[8];

extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern float func_00283180(float);

/* Advance eight pulse envelopes and combine the two output channels. */
int func_L00_002D6BA8(int *out)
{
    int modulated[2], modulate_count[2], additive_count[2];
    int active = 0;
    int i;
    for (i = 0; i < 2; i++) {
        out[i] = 0;
        modulated[i] = 0;
        modulate_count[i] = 0;
        additive_count[i] = 0;
    }

    for (i = 0; i < 8; ++i) {
        if (D_L00_001B8C00[i].field0 != 0) {
            ConditionalResetSlot *slot;
            int phase;
            int sample;
            active++;
            if (D_L00_001B8C00[i].active == 0 &&
                D_L00_001B8C00[i].count-- <= 0)
                D_L00_001B8C00[i].field0 = 0;
            if (D_L00_001B8C00[i].delay != 0) {
                D_L00_001B8C00[i].delay--;
                continue;
            }
            D_L00_001B8C00[i].phase++;
            slot = &D_L00_001B8C00[i];
            sample = 0;
            phase = slot->phase % (slot->rise + slot->fall);
            switch (slot->field0) {
            case 0:
                break;
            case 1:
            if (phase < slot->rise)
                sample = slot->amplitude + slot->bias;
            else
                sample = slot->bias;
            break;
            case 2:
            if (phase < slot->rise)
                sample = slot->amplitude * phase / slot->rise;
            else
                sample = slot->amplitude * (slot->fall + slot->rise - phase) / slot->fall;
            sample += slot->bias;
            break;
            case 3:
            if (phase < slot->rise)
                sample = slot->amplitude * phase / slot->rise + slot->bias;
            break;
            case 4:
            if (phase >= slot->rise)
                sample = slot->amplitude * (slot->fall + slot->rise - phase) / slot->fall + slot->bias;
            break;
            case 5:
            {
                float value, amplitude, denominator;
                if (phase < slot->fall) {
                    value = func_00283CE0(phase);
                    denominator = func_00283CE0(slot->fall);
                    value *= 3.1415927f;
                    value /= denominator;
                } else {
                    value = func_00283CE0(phase - slot->fall);
                    denominator = func_00283CE0(slot->rise);
                    value *= 3.1415927f;
                    value /= denominator;
                    value = 3.1415927f - value;
                }
                value = func_00283180(value);
                amplitude = func_00283CE0(slot->amplitude);
                sample = func_00283CF0((value * amplitude + amplitude) * 0.5f) + slot->bias;
                if (sample > 255) sample = 255;
            }
                break;
            }
            if (slot->modulate != 0) {
                modulated[slot->channel] += sample;
                modulate_count[slot->channel]++;
            } else {
                out[slot->channel] += sample;
                additive_count[slot->channel]++;
            }
        }
    }

    for (i = 0; i < 2; i++) {
        if (additive_count[i] != 0)
            out[i] /= additive_count[i];
        if (modulate_count[i] != 0) {
            modulated[i] /= modulate_count[i];
            out[i] = out[i] * modulated[i] / 255;
        }
    }
    return active;
}
