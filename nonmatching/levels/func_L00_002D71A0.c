/* Complete retained reconstruction of the 32-record override selector.
 * Measured with -O2 -G8 -ffunction-sections. The default typed-array draft
 * was 1132/1104 bytes; the byte-offset record view below is 1108/1104 on
 * USA v1.01, 0/27 placements. First instruction difference is +0x4:
 * retail keeps the shared pool high address directly in s4, while this
 * draft materializes it in v0 and copies it to s4. Pool/index lifetimes,
 * branch delay slots and the return join also differ; this is not merely
 * one padding word. An unchanged C body with -fno-gcse is 1116 bytes;
 * disabling sched1 and changing scan/declaration spelling were neutral.
 * A positive selected guard plus a named zero produced 1112 bytes.
 * Reopen with a source-level global-address lifetime/coalescing hypothesis
 * supported by an independent control; do not add barriers or register pins.
 */
#include "include_asm.h"

typedef struct {
    float primary, secondary, offset, roll, blend, extra;
    unsigned char flag24, flag25;
    short flag26;
    unsigned char priority, active, mode, timed_mode;
    float point[4];
    short timer, reset_timer;
    int angle, expiry, flag60;
} OverrideRecord;

typedef struct { char pad[256]; float x, y; } InputState;

extern char D_L00_001BB9F0[];
#define SLOT(i) ((OverrideRecord *)(D_L00_001BB9F0 + (i) * 64))
extern int D_L00_001B1884 __attribute__((sda));
extern char D_00138180[];
extern void func_L00_002D7140(void *);
extern void func_0026FF08(int, int, float, float, float, float);
extern void func_L00_00424A08(int, float, float);
extern void func_L00_00424A50(float, float);
extern void func_L00_00424A88(int, float, float);
extern void func_L00_00424B20(float);
extern void func_L00_00424B48(int);
extern void func_L00_00424B70(float, float);
extern void ref_L00_002D71A0_01(float, float);
extern void func_L00_00424C00(void);
extern void func_L00_00424C28(void);
extern void func_L00_00424C60(void);
extern void ref_L00_002D71A0_00(void);
extern void func_L00_002D7938(float);
extern void func_L00_00424F00(void *, float, float);
extern int func_00282978(void *);
extern float func_00283CE0(int);
extern float func_00282C48(float);

int func_L00_002D71A0(void)
{
    OverrideRecord *scan = (OverrideRecord *)D_L00_001BB9F0;
    int i;
    int priority = -1;
    int selected = -1;

    for (i = 0; i < 32; ++i, ++scan) {
        if (scan->active != 0) {
            if (scan->expiry != 0 && --scan->expiry == 0) {
                func_L00_002D7140(scan);
            } else if (scan->priority > priority) {
                priority = scan->priority;
                selected = i;
            }
        }
    }
    if (selected >= 0 && D_L00_001B1884 >= 0 && selected != D_L00_001B1884 &&
        SLOT(D_L00_001B1884)->blend >= 0.0f &&
        SLOT(selected)->blend < 0.0f)
        func_0026FF08(0, 3, 1.1243411f, 0.005f, 0.2f, 0.0f);
    D_L00_001B1884 = selected;
    if (selected < 0)
        return -1;

    if (SLOT(selected)->primary >= 0.0f) {
        func_L00_00424A08(0, SLOT(selected)->primary, 0.001f);
        if (SLOT(selected)->primary < 4.64f ||
            SLOT(selected)->primary > 6.0f)
            func_L00_00424C00();
    }
    if (SLOT(selected)->secondary >= 0.0f)
        func_L00_00424A50(SLOT(selected)->secondary, 0.001f);
    if (SLOT(selected)->roll >= 0.0f)
        func_L00_00424B20(SLOT(selected)->roll);
    if (SLOT(selected)->offset >= 0.0f)
        func_L00_00424A88(0, SLOT(selected)->offset, 0.005f);
    if (SLOT(selected)->extra >= 0.0f)
        func_L00_002D7938(SLOT(selected)->extra);
    if (SLOT(selected)->flag26 != 0)
        func_L00_00424C60();
    if (SLOT(selected)->flag60 != 0)
        ref_L00_002D71A0_00();
    if (SLOT(selected)->flag24 != 0) {
        func_L00_00424C00();
        func_L00_00424B48(0);
        func_L00_00424C28();
        ref_L00_002D71A0_01(0.01f, 0.2f);
        func_L00_00424B70(0.03f, 0.2f);
    }
    if (SLOT(selected)->flag25 != 0) {
        func_L00_00424C28();
        func_L00_00424B70(0.03f, 0.2f);
        ref_L00_002D71A0_01(0.0075f, 0.2f);
    }
    if (SLOT(selected)->blend >= 0.0f)
        func_0026FF08(0, 3, SLOT(selected)->blend, 0.005f, 0.2f, 0.0f);
    if ((float)SLOT(selected)->mode > 0.0f)
        func_L00_00424F00(SLOT(selected)->point,
                         func_00283CE0(SLOT(selected)->angle) * 0.017453294f, 0.0f);
    if ((float)SLOT(selected)->timed_mode > 0.0f) {
        if (func_00282978(&SLOT(selected)->timer) != 0)
            func_L00_00424F00(SLOT(selected)->point,
                             func_00283CE0(SLOT(selected)->angle) * 0.017453294f, 0.0f);
        if (func_00282C48(((InputState *)D_00138180)->x) > 0.01f ||
            func_00282C48(((InputState *)D_00138180)->y) > 0.01f)
            SLOT(selected)->timer = SLOT(selected)->reset_timer;
    }
    return selected;
}
