/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 700 / 700 bytes; size equality is not a match.
 * us: 0/27 placements.
 * us2: 0/27 placements.
 * pal: 0/27 placements.
 * Residual: The 700-byte extent and 0x60 frame agree, but allocation and absolute/GP addressing of the same lists differ. Complete table extents remain unknown; no array was shortened or forced into small data.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Readable manual reconstruction, measured 2026-10-23.
 * Retained profile: -O2 -G0 -ffunction-sections.
 * us: 0 of 27 places match; exit 1.
 * us2: 0 of 27 places match; exit 1.
 * pal: 0 of 27 places match; exit 1.
 * The 700-byte extent and 0x60 frame agree, but allocation and absolute/GP addressing of the same lists differ. Complete table extents remain unknown; no array was shortened or forced into small data.
 * 1 bounded source/profile trials; no exact-C credit is claimed.
 * Live helper inputs and consumed return banks were checked against retail and
 * current definitions. Original scalar-return intent remains unqualified for
 * procedural ASM callees whose results this body does not consume.
 * Reopen with independent layout/lifetime, table-extent or scheduling evidence;
 * no source barriers, register pins, invented aliases or padding were used.
 */

extern unsigned char *D_L00_001B1B00;
extern unsigned char **D_L00_001B1AFC;
extern unsigned char *D_L00_001B1E9C;
extern short D_L00_001B1FF0[];
extern short D_L00_001B2030[];
extern unsigned char *D_L00_001C57E8[];
extern int D_L00_001A9024;
extern unsigned char D_00189E20[];
extern int func_00282978(short *);
extern int func_L00_00329520(void *, int);
extern void func_L00_003296C0(unsigned char *, int, int);

/* Rebuild each live region's resident/object membership lists for this frame. */
void func_L00_002AE0C8(void) {
    int region, index;
    unsigned char *object;
    for (region = 0; region < *(int *)D_L00_001B1B00; ++region) {
        *(int *)D_L00_001B1AFC[region] = 0;
        *(int *)(D_L00_001B1AFC[region] + 8) = 0;
        D_L00_001B1AFC[region][4] = 0;
        if (func_00282978((short *)(D_L00_001B1B00 + region * 0x30 + 0x3A))) continue;
        if (func_L00_00329520(D_00189E20 + 0x80, region))
            func_L00_003296C0(*(unsigned char **)(D_00189E20 + 0x2290), region, 1);
        for (index = 1; index <= D_L00_001B1FF0[0]; ++index) {
            object = D_L00_001B1E9C + (D_L00_001B1FF0[index] << 8);
            if (object && *(short *)(object + 0xAA) == 0xCB &&
                object[0x20] != 0xFE && object[0x20] != 0xFD && object[0x20] == 3) {
                if (func_L00_00329520(object + 0x10, region))
                    func_L00_003296C0(object, region, 2);
            }
        }
        for (index = 0; index < D_L00_001A9024; ++index) {
            if (func_L00_00329520(D_L00_001C57E8[index] + 0x10, region))
                func_L00_003296C0(D_L00_001C57E8[index], region, 3);
        }
        for (index = 1; index <= D_L00_001B2030[0]; ++index) {
            object = D_L00_001B1E9C + (D_L00_001B2030[index] << 8);
            if (object && *(short *)(object + 0xAA) == 0xEB0 &&
                object[0x20] != 0xFE && object[0x20] != 0xFD) {
                if (func_L00_00329520(object + 0x10, region))
                    func_L00_003296C0(object, region, 4);
            }
        }
    }
    D_L00_001A9024 = 0;
}
