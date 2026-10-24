/* Manual C near miss retained on 2026-10-24; no exact-C credit.
 * Measured unit: src/levels/shared/L00_002E2C30.c
 * Game compiler profile: -O2 -G0 -ffunction-sections -g
 * Compiled/US retail bytes: 1148/1156.
 * Actual release checks: US: 0/27 (exit 1); US2: 0/27 (exit 1); PAL: 0/27 (exit 1).
 * Residual: Frame and initial calls agree; selected-entry allocation, FP temporaries, grey packing and branch scheduling differ. Debug labels restore 28 bytes of missing division padding.
 * Reopen only for: A concrete selected-entry/FP allocation hypothesis; do not repeat raw versus typed or G0/mno-split/debug trials.
 * The ASM marker and trial-only flags were restored after measurement.
 */

/* Draws the selected item with its fade and repeated outline strokes. */
typedef struct UIFadeState {
    char pad00[0x20];
    short selected;
    char pad22[0x356];
    float fade;
    int repeats;
    float spacing;
} UIFadeState;
extern UIFadeState D_L00_001BC200;
typedef struct UIFadeEntry {
    int key, textBase;
    char pad08[12];
    int position;
    char pad18[8];
    int stride;
    int tail;
} UIFadeEntry;
extern UIFadeEntry D_L00_001BC588[];
extern int func_002798A0(int, int *, int *);
extern int func_L00_002E36F8(int);
extern void func_L00_002E30B8(float, int, int, int, int, int);
void func_L00_002E2C30(float progress, int item)
{
    int bank, index, text, position, i, grey;
    int colour;
    UIFadeEntry *entry;
    float fade;
    if (!func_002798A0(item, &bank, &index))
        return;
    text = func_L00_002E36F8(D_L00_001BC588[bank].textBase + index);
    if (!text)
        return;
    entry = &D_L00_001BC588[D_L00_001BC200.selected];
    position = entry->position + item * entry->stride;
    fade = D_L00_001BC200.fade;
    if (progress > 1.0f - fade) {
        fade = (progress - 1.0f + fade) / fade;
        if (fade > 1.0f) fade = 1.0f;
        else if (fade < 0.0f) fade = 0.0f;
        func_L00_002E30B8(fade, text, 3, -1, position, 1);
        for (i = D_L00_001BC200.repeats; i >= 0; i--) {
            fade = (progress - 1.0f + D_L00_001BC200.fade) /
                D_L00_001BC200.fade + i * D_L00_001BC200.spacing;
            grey = (int)(((float)(D_L00_001BC200.repeats - i) /
                (float)D_L00_001BC200.repeats) * 255.0f);
            colour = (grey << 16) | ((grey << 8) | 0x80000000) | grey;
            if (fade > 1.0f) fade = 1.0f;
            else if (fade < 0.0f) fade = 0.0f;
            func_L00_002E30B8(fade, text, 3, colour, position, 0);
        }
    } else if (progress < fade) {
        fade = progress / fade;
        if (fade > 1.0f) fade = 1.0f;
        else if (fade < 0.0f) fade = 0.0f;
        func_L00_002E30B8(fade, text, 2, -1, position, 1);
        for (i = D_L00_001BC200.repeats; i >= 0; i--) {
            fade = progress / D_L00_001BC200.fade -
                i * D_L00_001BC200.spacing;
            grey = (int)(((float)(D_L00_001BC200.repeats - i) /
                (float)D_L00_001BC200.repeats) * 255.0f);
            colour = (grey << 16) | ((grey << 8) | 0x80000000) | grey;
            if (fade > 1.0f) fade = 1.0f;
            else if (fade < 0.0f) fade = 0.0f;
            func_L00_002E30B8(fade, text, 2, colour, position, 0);
        }
    } else {
        func_L00_002E30B8(1.0f, text, 0, -1, position, 1);
        func_L00_002E30B8(-2.2f, text, 1, 0x80000000, position - 2, 0);
        func_L00_002E30B8(0.0f, text, 1, 0x80000000, position - 2, 0);
        func_L00_002E30B8(2.2f, text, 1, 0x80000000, position - 2, 0);
        func_L00_002E30B8(-2.2f, text, 1, 0x80000000, position + 2, 0);
        func_L00_002E30B8(0.0f, text, 1, 0x80000000, position + 2, 0);
        func_L00_002E30B8(2.2f, text, 1, 0x80000000, position + 2, 0);
        func_L00_002E30B8(1.0f, text, 0, -1, position, 0);
    }
}
