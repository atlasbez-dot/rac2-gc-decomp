/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * Compiled 704 bytes; retail 704 bytes.
 * us: 0/1 placements match (exit 1).
 * us2: 0/1 placements match (exit 1).
 * pal: canonical name absent; no match credit.
 * Remaining: The aligned previous-position local and shared qcopy reach retail size, up from 688
 * bytes. The frame is 0x70, but one extra saved GPR, conditional state setup and floating
 * load/call order differ from +0x8. Recomputing position at use grows to 708 bytes. The verified
 * full float return and two-float func_002AA2E8 contract are preserved.
 * Reopen: A fragment-update witness explaining the state-dependent position lifetime without
 * retaining another saved GPR.
 */

#include "common.h"
typedef int quad __attribute__((mode(TI)));
extern char D_L16_001BFF60[];
extern f32 D_L16_001B1FF0 __attribute__((sda));
extern f32 D_L16_001B1FF4 __attribute__((sda));
extern void func_00282CC0(char *, char *, char *);
extern void func_L16_0041F150(char *);
extern s32 func_002761F8(char *, char *, s32, s32, s32);
extern void func_002A7750(char *, s32, s32);
extern void func_0032C700(char *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_002A8C28(char *, char *, u32, s32, s32, s32, f32, f32, f32);
extern s32 func_002B3868(char *);
extern f32 func_002AA2E8(f32 *, f32, f32);
extern void func_0029F338(char *);
extern void func_L16_0041F360(char *);
extern void func_L00_002E6CF0(void (*)(char *), char *);

/* Moves a fragment until impact and runs its fading shock-wave effect. */
void func_L16_0041EE90(char *self) {
    quad previous;
    char *st = *(char **)(self + 0x68);
    char *position = self + 16;
    switch (*(u8 *)(self + 0x20)) {
    case 0:
        qcopy(&previous,position);
        func_00282CC0(position, position, st);
        *(f32 *)(st + 8) -= *(f32 *)(st + 0x24);
        func_L16_0041F150(self);
        if (func_002761F8((char *)&previous, position, 0, *(s32 *)(self + 0xB8), 0)) {
            qcopy(position ,D_L16_001BFF60);
            func_002A7750(self, *(s32 *)(st + 0x20) ? 2 : 1, -1);
        }
        break;
    case 1:
        func_0032C700(position, 0, 25, 20, 20, 20, 45, 1, 1, 0, 0, 0, 1.0f, 20.0f);
        func_002A8C28(self, position, 0x10001, 0, 1, 0, 2.0f, 6.0f, 1.0f);
        func_0029F338(self);
        break;
    case 2:
        if (func_002B3868(self)) {
            func_0032C700(position, 0, 20, 15, 15, 15, 35, 1, 1, 0, 0, 0, 0.6660000085830688f, 20.0f);
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            *(f32 *)(self + 0x18) += 0.5f;
            *(f32 *)(st + 0x30) = 1.0f;
        }
        *(f32 *)(st + 0x34) += 0.06666667014360428f;
        if (*(f32 *)(st + 0x34) > 1.0f) *(f32 *)(st + 0x34) -= 1.0f;
        *(f32 *)(st + 0x2C) += D_L16_001B1FF0 * 0.01666666753590107f;
        if (*(f32 *)(st + 0x2C) >= D_L16_001B1FF4) func_002AA2E8((f32 *)(st + 0x30), 0.0f, 0.06666667014360428f);
        if (*(f32 *)(st + 0x30) <= 0.0f) func_0029F338(self);
        else func_L00_002E6CF0(func_L16_0041F360, self);
        break;
    }
}
