/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections (suffix profile).
 * Reported final C / retail: 1008 / 1028 bytes; size equality is not a match.
 * us: 0/27 placements; 1008/1028 bytes.
 * us2: 0/27 placements; 1008/1028 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Complete interaction controller, final1012/1028 bytes after preserving the root-qualified deliberate sixth273318 call slot4. First-save allocation, global-base reuse, branches and ignored call-result scheduling differ. Original scalar return/unused-formal intent for that output operation remains unknown; the observed caller prefix is preserved.
 * Reopening condition: New ABI/CFG/allocator evidence or a measured compiler-model improvement; do not repeat tied forms.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained complete manual reconstruction; not an exact match.
 * Source profile: -O2 -G8 -ffunction-sections (suffix profile).
 * Complete interaction controller, final1012/1028 bytes after preserving the root-qualified deliberate sixth273318 call slot4. First-save allocation, global-base reuse, branches and ignored call-result scheduling differ. Original scalar return/unused-formal intent for that output operation remains unknown; the observed caller prefix is preserved.
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

void func_L00_003FE4C8(char *object) {
    float origin[4];
    float destination[4];
    char *state = *(char **)(object + 0x68);
    char **list;
    char *member;
    u32 color;
    int allowed = 1;
    int any;
    int count;
    int index;
    int phase;

    func_L00_003FE8D0(object);
    if (D_0018C0B4 == 1) func_L00_002C42E0(29, 1);
    if (D_0018B270 != 0) D_0018AA18 = D_0018B270;
    if (object[0x42] == object[0x43] && (object[0x60] & 2))
        func_002A75E0(object, 1, 0, 6, 0);
    if (*(s16 *)(state + 6) != 0 && func_00282978((s16 *)(state + 6))) func_L00_002AF7D0();
    func_00283098(origin, D_L00_001B0BF0, object + 0xC0);
    func_00282CC0(origin, origin, object + 0x10);
    func_002829D8((float *)state);
    if (D_0018C0B4 == 29) {
        if (func_00282948(&D_0018C354)) {
            if (*(float *)state > 0.0f || !func_L00_002D4040(-1) || object[0x20] != 1)
                color = 0x600000FF;
            else color = 0x600FFF0F;
            func_00273318(1.0f, 0.0f, 90.0f, object, color, 0, 31, -1, 4);
        } else allowed = 0;
    } else D_0018C354 = 40;
    phase = (u8)object[0x20];
    if (phase == 1) {
        if (D_L00_001A8F00 != 0 || !allowed || *(float *)state != 0.0f || D_0018C0DC != 0 ||
            (u8)object[0x42] > 1 || !(D_00138320 & D_0018B050) || D_0018B060 < 23) return;
        if (func_L00_002D4040(-1)) {
            func_L00_002D3F30(-1, 1);
            D_L00_001B2BE8 = phase;
            if (D_0018C0B4 != 29) func_002A75E0(object, 2, 0, 2, 0);
            func_002E5CF8(0, 0, object);
            func_L00_002AF568();
            object[0x20] = 2;
            *(u16 *)(state + 4) = D_L00_001B0C00;
            *(u16 *)(state + 6) = D_L00_001B0C08;
            *(int *)(state + 8) = 0;
        } else if ((D_00138324 & D_0018B050) || D_L00_001B2BE8 == 1) {
            func_002E5CF8(1, 0, object);
            D_L00_001B2BE8 = 0;
        }
        *(float *)state = 1.0f / *(float *)(D_L00_00262570 + D_00139581 * 0xE0 + 0x54);
    } else if (phase == 2) {
        if (!func_00282978((s16 *)(state + 4))) return;
        func_L00_003FE920(object, destination, *(int *)(state + 8), origin);
        func_L00_003FEAC8(object, origin, destination, *(int *)(state + 8));
        index = *(int *)(state + 8) + 1;
        *(int *)(state + 8) = index;
        if (index < D_L00_001B0C0C) *(u16 *)(state + 4) = D_L00_001B0C04;
        else object[0x20] = 3;
    } else {
        any = 0;
        count = D_L00_001B0C0C;
        list = (char **)(state + 0x10);
        while (count > 0) {
            member = *list;
            if (member != 0) {
                any = 1;
                if ((*(s16 *)(member + 0xAA) != 0x5D8 || (u8)member[0x20] == 0xFE ||
                     (u8)member[0x20] == 0xFD) && !(D_00138320 & D_0018B050)) *list = 0;
            }
            count--;
            list++;
        }
        if (!any) object[0x20] = 1;
    }
}
