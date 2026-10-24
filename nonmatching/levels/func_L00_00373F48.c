/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G64 -Wa,-G64 -ffunction-sections.
 * Reported final C / retail: 784 / 1024 bytes; size equality is not a match.
 * us: 0/27 placements; 784/1024 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: Purchase branches, repeated metadata queries, address sharing and frame allocation differ. Every state and both inventory-bit updates are retained. The external runtime menu parameter array remains incomplete rather than inventing its complete extent. Reopen on the original menu-state/metadata expression layout.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G64 -Wa,-G64 -ffunction-sections
 * Measured text: 784 bytes; retail: 1024 bytes. Stack frame 0x30.
 * Final coverage: US 0/27, US2 absent, PAL absent. Absences are not matches.
 * 1 measured source/profile forms. Purchase branches, repeated metadata queries, address
 * sharing and frame allocation differ. Every state and both inventory-bit updates are
 * retained. The external runtime menu parameter array remains incomplete rather than
 * inventing its complete extent. Reopen on the original menu-state/metadata expression
 * layout.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

extern char D_L00_0022F7C0[];
extern char D_00138180[];
extern unsigned char D_001A7A80[];
extern unsigned char D_00139568[];
extern char D_L00_00262570[];
/* Runtime menu parameters; the element count belongs to the selected menu. */
extern int D_L00_001AD4F0[] __attribute__((sda));
extern void func_L00_00373F40(void);
extern int func_002B0D70(void);
extern int func_002E5CF8(int, int, char *);
extern int func_00288FB8(int);
extern void func_002F88D8(void *);
extern int func_L00_00326950(int);
extern void func_L00_002F5890(int);
extern void func_002F73A8(void);
extern void func_002FB1A0(void);

void func_L00_00373F48(int *answer) {
    char *model = D_L00_0022F7C0;
    int cost = *(int *)(model + 0x148 + *(int *)(model + 0x80) * 16);
    int state = *(int *)(model + 0x84);
    int category;
    int group;
    int enabled;
    char *metadata;
    if (state == 1) {
        if (*(int *)(model + 0x740) == 0) *(int *)(model + 0x84) = 0;
        else {
            func_L00_00373F40();
            *(int *)(model + 0x84) = 2;
        }
    } else if (state == 2) {
        if (*(unsigned int *)(D_00138180 + 0x1C4) & 0x10) {
            *answer = 0;
            *(int *)(model + 0x84) = 4;
        } else if (*(unsigned int *)(D_00138180 + 0x1C4) & 0x40)
            *(int *)(model + 0x84) = 3;
    } else if (state == 3) {
        *answer = 0;
        if (func_002B0D70() < cost) func_002E5CF8(2, 17, *(char **)(model + 0x28));
        else {
            category = *(int *)(model + 0x140 + *(int *)(model + 0x80) * 16);
            group = *(int *)(model + 0x144 + *(int *)(model + 0x80) * 16);
            *answer = (D_001A7A80[group] & (1u << ((category & 15) << 1)) & 255u) == 0;
        }
        *(int *)(model + 0x84) = 4;
    } else if (state == 4) {
        if (*answer == 0) func_002E5CF8(0, 17, *(char **)(model + 0x28));
        else if (func_002B0D70() < cost) {
            func_002F88D8((void *)func_00288FB8(0x2DCC));
            func_002E5CF8(0, 17, *(char **)(model + 0x28));
        } else {
            func_002F88D8((void *)func_00288FB8(0x2DCB));
            func_002E5CF8(7, 17, *(char **)(model + 0x28));
            func_L00_00326950(cost);
            func_L00_002F5890(D_L00_001AD4F0[*(int *)(model + 0x80)]);
            category = *(int *)(model + 0x140 + *(int *)(model + 0x80) * 16);
            group = *(int *)(model + 0x144 + *(int *)(model + 0x80) * 16);
            metadata = D_L00_00262570 + (unsigned int)D_00139568[group] * 0xE0;
            if (category == 0) enabled = *(int *)(metadata + 0x98);
            else if (category == 1) enabled = *(int *)(metadata + 0x9C);
            else if (category == 2) enabled = *(int *)(metadata + 0xA0);
            else enabled = 0;
            if (enabled) D_001A7A80[group] |= (unsigned char)(1u << ((category & 15) << 1));
            category = *(int *)(model + 0x140 + *(int *)(model + 0x80) * 16);
            group = *(int *)(model + 0x144 + *(int *)(model + 0x80) * 16);
            metadata = D_L00_00262570 + (unsigned int)D_00139568[group] * 0xE0;
            if (category == 0) enabled = *(int *)(metadata + 0x98);
            else if (category == 1) enabled = *(int *)(metadata + 0x9C);
            else if (category == 2) enabled = *(int *)(metadata + 0xA0);
            else enabled = 0;
            if (enabled && (D_001A7A80[group] & (1u << ((category * 2) & 31)) & 255u))
                D_001A7A80[group] |= (unsigned char)(1u << ((category * 2 + 1) & 31));
            func_002F73A8();
        }
        *(int *)(model + 0x84) = 0;
        func_002FB1A0();
    }
}
