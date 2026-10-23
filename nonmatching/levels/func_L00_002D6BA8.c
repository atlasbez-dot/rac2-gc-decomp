/* Retained reconstruction: func_L00_002D6BA8, 2026-10-23.
 * Default game profile: -O2 -G0 -ffunction-sections.
 * 1068/1068 bytes, 0/27 placements in each of USA, PAL and USA v2;
 * the first differing instruction is +0x18. Not linked or counted.
 * The count-array bases use s3/s4 in the opposite order to retail, and
 * entry/final-loop scheduling and two pointer-add operand orders differ.
 * Keep distinct final walking pointers: merging them shortens the body.
 * Reopen with independent evidence for the original counter-array lifetimes.
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
extern void *D_L00_002A0AC0[6];

/* Advance eight pulse envelopes and combine the two output channels. */
int func_L00_002D6BA8(int *out)
{
    /* These are the six real arms of the existing level dispatch table. */
    static void *arms[] = {&&contribute, &&square, &&triangle, &&ramp_up,
                           &&ramp_down, &&sine};
    int modulated[2], modulate_count[2], additive_count[2];
    int *output = out;
    int *sum = modulated;
    int *mod_count = modulate_count;
    int *add_count = additive_count;
    int *output_clear = output;
    int *add_clear = add_count;
    int *mod_clear = mod_count;
    int active = 0;
    int i = 1;
    do {
        *sum++ = 0;
        *mod_clear++ = 0;
        *output_clear++ = 0;
        *add_clear++ = 0;
    } while (--i >= 0);

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
            { unsigned int kind = slot->field0;
              if (kind >= 6) goto contribute;
              goto *D_L00_002A0AC0[kind];
            }

square:
            if (phase < slot->rise)
                sample = slot->amplitude + slot->bias;
            else
                sample = slot->bias;
            goto contribute;
triangle:
            if (phase < slot->rise)
                sample = slot->amplitude * phase / slot->rise;
            else
                sample = slot->amplitude * (slot->fall + slot->rise - phase) / slot->fall;
            sample += slot->bias;
            goto contribute;
ramp_up:
            if (phase < slot->rise)
                sample = slot->amplitude * phase / slot->rise + slot->bias;
            goto contribute;
ramp_down:
            if (phase >= slot->rise)
                sample = slot->amplitude * (slot->fall + slot->rise - phase) / slot->fall + slot->bias;
            goto contribute;
sine:
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
contribute:
            if (slot->modulate != 0) {
                modulated[slot->channel] += sample;
                mod_count[slot->channel]++;
            } else {
                output[slot->channel] += sample;
                add_count[slot->channel]++;
            }
        }
    }

    {
        int *out_tail = output;
        int *mod_tail = mod_count;
        int *add_tail = add_count;
        int *sum_tail = modulated;
        i = 1;
        do {
            if (*add_tail != 0)
                *out_tail /= *add_tail;
            if (*mod_tail != 0) {
                int value = *out_tail;
                *sum_tail /= *mod_tail;
                *out_tail = value * *sum_tail / 255;
            }
            out_tail++;
            sum_tail++;
            mod_tail++;
            add_tail++;
        } while (--i >= 0);
    }
    return active;
}
