/* Animation-range selection and frame conversion are reconstructed, with the real unsigned division followed by signed remainder and typed containing range/matrix arrays. Only canonical table identity D_L00_001A7DA8 is retained; an experimental numbered absolute alias was removed. GP versus absolute end-field access, range classification and loop allocation remain different. The old byte-view draft was 876/964 bytes; typed containing-object and explicit classification drafts were measured without claiming a match. Reopen with a legitimate model of the single range table and its two access forms.
 * Profile: -O2 -G8 -ffunction-sections -Wa,-G32
 * us: 920 bytes, expected 964; 0/27 placements
 * us2: 920 bytes, expected 964; 0/27 placements
 */
#include "include_asm.h"
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

typedef struct { float start, end, reserved0, reserved1; } AnimationRange;
extern AnimationRange D_L00_001A7DA8[2] __attribute__((sda));
extern int D_L00_001A7DC8[2][2] __attribute__((sda));
extern void func_L00_002D2168(int, int, float);

void func_L00_002CA0B0(void)
{
    float limit;
    int old;
    if (D_00189E20.mode_22b4 == 1) {
        D_00189E20.animation_scale = D_00189E20.field_170 * 90.0f;
        if (D_00189E20.animation_scale < 0.5f) D_00189E20.animation_scale = 0.5f;
        return;
    }
    if (D_00189E20.flag_1454 != 0 && D_00189E20.flag_1456 != 0) {
        if (((unsigned char *)D_00189E20.object)[0x43] != 20)
            func_L00_002D2168(20, 0, 11.0f);
        D_00189E20.animation_scale = D_00189E20.animation_time * 25.0f;
        if (D_00189E20.animation_scale < 0.7f) D_00189E20.animation_scale = 0.7f;
        if (2.2f < D_00189E20.animation_scale) D_00189E20.animation_scale = 2.2f;
        return;
    }
    if (((unsigned char *)D_00189E20.object)[0x43] == 20) {
        func_L00_002D2168(D_00189E20.frame + 3, 0, 7.0f);
    } else if (D_00189E20.count_1c0 > 4 && D_00189E20.flag_40e == 0) {
        float time = D_00189E20.animation_time;
        float start;
        int before_range;
        old = D_00189E20.frame;
        start = D_L00_001A7DA8[old].start * 0.01666666753590107f;
        before_range = time < start;
        if (before_range || D_L00_001A7DA8[old].end * 0.01666666753590107f < time) {
            if (before_range) {
                while (time < start) {
                    --D_00189E20.frame;
                    start = D_L00_001A7DA8[D_00189E20.frame].start * 0.01666666753590107f;
                }
            } else {
                int next = old;
                while (D_L00_001A7DA8[next].end * 0.01666666753590107f < time) next++;
                D_00189E20.frame = next;
            }
            if (D_00189E20.frame < 0) D_00189E20.frame = 0;
            if (D_00189E20.frame > 1) D_00189E20.frame = 1;
            if (old != D_00189E20.frame) {
                char *object = D_00189E20.object;
                void **frames = (void **)(*(char **)(object + 0x24) + 0x48);
                unsigned int before = ((unsigned char *)frames[old + 3])[0x10];
                unsigned int after = ((unsigned char *)frames[D_00189E20.frame + 3])[0x10];
                int frame = ((unsigned char)object[0x41] * after) / before;
                frame = (frame + D_L00_001A7DC8[old][D_00189E20.frame]) % (int)after;
                func_L00_002D2168(D_00189E20.frame + 3, frame, 8.0f);
            }
        }
    }
    if (D_00189E20.frame == 0) {
        D_00189E20.animation_scale = D_00189E20.animation_time * 157.0f;
        if (D_00189E20.animation_scale < 0.6f) D_00189E20.animation_scale = 0.6f;
        limit = 4.0f;
    } else if (D_00189E20.frame == 1) {
        D_00189E20.animation_scale = D_00189E20.animation_time * 14.0f;
        if (D_00189E20.animation_scale < 0.6f) D_00189E20.animation_scale = 0.6f;
        limit = 2.2f;
    } else return;
    if (limit < D_00189E20.animation_scale) D_00189E20.animation_scale = limit;
}
