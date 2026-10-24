/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections (suffix profile).
 * Reported final C / retail: 1044 / 1080 bytes; size equality is not a match.
 * us: 0/27 placements; 1044/1080 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: Complete1044/1080-byte aimed controller, frame0x70correct. Seven-GPR FE5A0 plus f12 and its32-bit explicit boolean return were audited; both optional word-output pointers are retained. Current canonical AB1F0 returns pointer bits as s32, explicitly cast at the observed dereference. Control-flow/global-base allocation remains different.
 * Reopening condition: New ABI/CFG/allocator evidence or a measured compiler-model improvement; do not repeat tied forms.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained complete manual reconstruction; not an exact match.
 * Source profile: -O2 -G8 -ffunction-sections (suffix profile).
 * Complete1044/1080-byte aimed controller, frame0x70correct. Seven-GPR FE5A0 plus f12 and its32-bit explicit boolean return were audited; both optional word-output pointers are retained. Current canonical AB1F0 returns pointer bits as s32, explicitly cast at the observed dereference. Control-flow/global-base allocation remains different.
 */
#include "common.h"
extern int D_0018C0B4;
extern char *D_0018B270;
extern char *D_0018AA18;
extern s8 D_0018C0DC;
extern s8 D_0018C0D8;
extern int D_0018C354;
extern u32 D_00138320;
extern u32 D_00138324;
extern u32 D_0018B050;
extern int D_0018B060;
extern u8 D_00139581;
extern u8 D_0013958D;
extern int D_L00_001A8F00 __attribute__((sda));
extern int D_L00_001B2BE4;
extern int D_L00_001B2BE8 __attribute__((sda));
extern char D_L00_001B0BF0[] __attribute__((sda));
extern u16 D_L00_001B0C00 __attribute__((sda));
extern u16 D_L00_001B0C04 __attribute__((sda));
extern u16 D_L00_001B0C08 __attribute__((sda));
extern int D_L00_001B0C0C __attribute__((sda));
extern char D_L00_00262570[];
extern void func_L00_003FE8D0(char *);
extern void func_L00_002C42E0(int, int);
extern void func_002A75E0(void *, int, int, int, int);
extern int func_00282978(s16 *);
extern int func_00282948(int *);
extern void func_002829D8(float *);
extern void func_L00_002AF7D0(void);
extern void func_L00_002AF568(void);
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern int func_L00_002D4040(int);
extern int func_L00_002D3F30(int, int);
/* The caller deliberately supplies a sixth GPR word (4) in the call slot;
 * retail overwrites it before consumption. Original return/unused-formal
 * intent remains unqualified, but the observed call prefix is preserved. */
extern void func_00273318(float, float, float, void *, u32, void *, int, int, int);
extern int func_002E5CF8(int, int, char *);
extern void func_L00_003FE920(char *, void *, int, void *);
extern void func_L00_003FEAC8(char *, void *, void *, int);
extern void func_L00_003FE280(char *, char *);
extern s32 func_002AB1F0(u8 *);
extern void func_002FDF40(float, float, float, float, void *, void *, void *, void *);
extern int func_002FE5A0(float, void *, void *, void *, void *, void *, int *, int *);
extern void func_L00_003FE310(void *, void *, void *);
extern int func_L00_003FE2D0(int, int, int);
struct Rac2Native_5f824a0e369ccf7b_src_record;
extern struct Rac2Native_5f824a0e369ccf7b_src_record D_L00_0029F210;
extern int func_L00_002D6998(struct Rac2Native_5f824a0e369ccf7b_src_record *);
extern void func_L00_002D6B70(void);
extern void func_L00_002E6EF8(void (*)(void *), void *);
extern void func_L00_003FE490(void *);

/* Coordinate the multi-object interaction and its repeat/cooldown timers. */

void func_L00_003FDE48(char *object) {
    float origin[4];
    float aim[4];
    char *state = *(char **)(object + 0x68);
    char *target = 0;
    s32 target_data;
    int allowed = 1;
    int was_running;
    int mode;
    int handle;

    if (object[0x20] == 0) {
        object[0x20] = 1;
        *(int *)(state + 0x28) = -1;
        *(float *)(state + 0x20) = 0.0f;
        *(int *)(state + 0x2C) = 0;
        D_L00_001B2BE4 = 20;
    }
    if (D_0018C0B4 == 1) func_L00_002C42E0(29, 1);
    if (object[0x42] == object[0x43] && (object[0x60] & 2)) func_002A75E0(object, 1, 0, 2, 0);
    func_L00_003FE280(object, (char *)origin);
    if (D_0018B270 != 0 && (u8)D_0018B270[0x20] != 0xFE && (u8)D_0018B270[0x20] != 0xFD) {
        target_data = func_002AB1F0((u8 *)D_0018B270);
        if (target_data != 0 && *(float *)target_data > 0.0f) target = D_0018B270;
    }
    if (D_0018C0B4 == 29) allowed = func_00282948(&D_0018C354) != 0;
    else D_0018C354 = 40;
    func_002FDF40(1.6f, 10.0f, 0.25f, 0.004055555909872055f, aim, origin, target, 0);
    *(int *)(state + 0x24) = func_002FE5A0(0.004055555909872055f, origin, aim, state, state + 0x10, object, 0, 0);
    was_running = *(float *)(state + 0x20) > 0.0f;
    func_002829D8((float *)(state + 0x20));
    if (was_running && *(float *)(state + 0x20) <= 0.0f && func_L00_002D4040(-1)) func_002E5CF8(3, 0, object);
    if (*(int *)(state + 0x2C) != 0 && func_00282948((int *)(state + 0x2C))) func_L00_002AF7D0();
    mode = D_L00_001A8F00;
    if ((D_00138324 & D_0018B050) && !func_L00_002D4040(-1)) {
        func_002E5CF8(1, 0, object);
        D_L00_001B2BE4 = 20;
        mode = D_L00_001A8F00;
    }
    if (mode == 0 && *(float *)(state + 0x20) == 0.0f && D_0018C0DC == 0 &&
        (u8)object[0x42] <= 1 && (D_00138320 & D_0018B050) && D_0018B060 >= 23 && allowed) {
        if (func_L00_002D4040(-1)) {
            func_002E5CF8(0, 0, object);
            func_L00_002D3F30(-1, 1);
            func_L00_003FE310(object, origin, aim);
            func_002A75E0(object, 2, 0, 2, 0);
            func_L00_003FE2D0((int)object, (int)origin, (int)aim);
            func_L00_002AF568();
            *(int *)(state + 0x2C) = 16;
            *(int *)(state + 0x28) = func_L00_002D6998(&D_L00_0029F210);
        }
        if (!(D_00138320 & D_0018B050) || !func_L00_002D4040(-1) || D_0018C0D8 == 0) {
            handle = *(int *)(state + 0x28);
            if (handle >= 0) {
                func_L00_002D6B70();
                *(int *)(state + 0x28) = -1;
            }
        }
        *(float *)(state + 0x20) = 1.0f / *(float *)(D_L00_00262570 + D_0013958D * 0xE0 + 0x54);
    }
    func_L00_002E6EF8(func_L00_003FE490, object);
}
