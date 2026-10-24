/* func_002900B8 (1388 retail bytes): retained plain-C near miss.
 *
 * Rechecked with the current qualified compiler and assembler. Default -O2 -G8
 * -ffunction-sections emits 1364 bytes with a 0x70 frame: US 0/28 and PAL 0/28;
 * this identity is absent from the US2 catalogue. No exact-C credit.
 *
 * Corrected the fifth 0027DE50 colour argument to the measured 64-bit width.
 * The earlier 1372-byte measurement and mfc1-interlock blocker are historical:
 * the qualified toolchain now handles the interlock pattern (PR #222). Remaining
 * differences include constant/FPR lifetimes, saved registers and branch layout.
 * Four meaningful current trials: switch/default 1364, no-GCSE 1352, equivalent
 * if/else 1364, and no pre-allocation scheduling 1364. No flags remain active.
 *
 * Reopen for a concrete source-lifetime/layout explanation, not the obsolete
 * claim that immediate mfc1 consumers are inherently unrepresentable. A future
 * integration also needs the observed int callback return in 00290010's interface;
 * its registration helper stores the two int-returning callbacks unchanged.
 */
#include "include_asm.h"

extern int D_001A9000 __attribute__((sda));
extern int D_001A9004 __attribute__((sda));
extern float D_001A9008 __attribute__((sda));
extern int D_001A900C __attribute__((sda));
extern int D_001A9010 __attribute__((sda));

typedef struct {
    int active;
    int timer;
    char pad08[0x18];
    int entryIndex;
    int unk24;
} Subtitle_002900B8;

typedef struct {
    char pad[0xB0];
    float opacity;
} Hud_002900B8;

extern char *D_001A8CFC[] __attribute__((sda));
extern Subtitle_002900B8 D_00254E78;
extern Hud_002900B8 D_001B9040;
extern float D_001B23A4[] __attribute__((sda));
extern int D_001A8D40 __attribute__((sda));
extern void func_0027AB40(void);
extern float func_00283CE0(int);
extern int func_00283D38(int, int, float);
extern char *func_00336D50(char *, int);
extern void func_00300A00(char *, int, float, float, float, float, float);
extern void func_0027DE50(int, int, int, int, unsigned long);

int func_002900B8(void)
{
    float saved;
    float pulse;
    float step;
    float lower;
    float upper;
    float limit;
    int first;
    int second;
    int top;
    int i;

    if (D_001A8CFC[0] != 0 && D_00254E78.active == 0 && D_00254E78.unk24 == -1) {
        saved = D_001B9040.opacity;
        D_001B9040.opacity = 0.62f;
        func_0027AB40();
        pulse = func_00283CE0(D_001A9000) * 0.1f;
        first = func_00283D38(0x442D00, 0x60442D00, pulse);
        second = func_00283D38(0xF0C070, 0x55F0C070, pulse);
        func_00300A00(func_00336D50(D_001A8CFC[0] + 0x8710, 0xA6), first, 484.0f,
                      (float)(int)(D_001B23A4[0] * 206.0f + 0.5f), 1.0f, 1.0f, 0.0f);
        func_00300A00(func_00336D50(D_001A8CFC[0] + 0x8710, 0xA7), second, 484.0f,
                      (float)(int)(D_001B23A4[0] * 206.0f + 0.5f), 1.0f, 1.0f, 0.0f);
        if (D_001A9004 == 0) {
            if (0.0f <= D_001A9008 && D_001A9008 <= 1.0f) {
                first = func_00283D38(D_001A900C & 0xFFFFFF, D_001A900C, pulse);
                second = func_00283D38(D_001A9010 & 0xFFFFFF, D_001A9010, pulse);
                top = (int)((float)(285 - (int)((1.0f - D_001A9008) * 157.0f)) * D_001B23A4[0] + 0.5f);
                step = (float)(int)(D_001B23A4[0] * 128.0f + 0.5f) * 0.25f;
                lower = (float)(int)(D_001B23A4[0] * 285.0f + 0.5f);
                upper = lower - step + 1.0f;
                for (i = 0; i < 5; i++) {
                    limit = (float)top;
                    if (upper <= limit)
                        upper = limit;
                    func_0027DE50((int)upper, (int)lower, 477, 489, first);
                    lower -= step;
                    upper -= step;
                    if (lower <= limit)
                        break;
                }
                upper = (float)(int)(D_001B23A4[0] * 128.0f + 0.5f);
                lower = upper + step - 1.0f;
                for (i = 0; i < 5; i++) {
                    limit = (float)top;
                    if (limit <= lower)
                        lower = limit;
                    func_0027DE50((int)upper, (int)lower, 476, 488, second);
                    upper += step;
                    lower += step;
                    if (limit <= upper)
                        break;
                }
            }
        } else if (D_001A9004 == 1 || D_001A9004 == 2) {
            first = func_00283D38(D_001A900C & 0xFFFFFF, D_001A900C, pulse);
            top = (int)((float)(285 - (int)((1.0f - D_001A9008) * 157.0f)) * D_001B23A4[0] + 0.5f);
            step = (float)(int)(D_001B23A4[0] * 128.0f + 0.5f) * 0.25f;
            lower = (float)(int)(D_001B23A4[0] * 285.0f + 0.5f);
            upper = lower - step + 1.0f;
            for (i = 0; i < 5; i++) {
                limit = (float)top;
                if (upper <= limit)
                    upper = limit;
                func_0027DE50((int)upper, (int)lower, 476, 488, first);
                lower -= step;
                upper -= step;
                if (lower <= limit)
                    break;
            }
        }
        D_001B9040.opacity = saved;
        func_0027AB40();
    }
    return D_001A8D40;
}
