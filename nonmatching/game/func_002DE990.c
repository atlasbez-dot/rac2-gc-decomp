/* Retained manual C reconstruction; not linked and not credited as exact.
 * Checked source: src/game/002DE990-copy.c
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy
 * Retail US size: 1728 bytes.
 * Final checks: us: 0/28, exit 1, 1736 compiled bytes; us2: 0/28, exit 1, 1736 compiled bytes; pal: catalogue absent, exit 1.
 * Residual: 1736/1728 bytes with the correct 0x3760 frame. Explicit 32-byte chunks retain two live quadwords and replace the old 64-bit block-move kernel. Entry/global-base construction, index allocation, load order and loop padding still differ. Fourteen individual qcopy calls per record regress to 2264 bytes and were rejected.
 * Reopen only with: A measured addressing/index or load-order policy for the two-live-quad chunk, preserving the unaligned 64-byte state copy and all reload/restore semantics.
 * Reviewed EE helpers follow the source-method policy in AGENTS.md.
 * No complete linked build or native runtime validation was performed here.
 */
#include "common.h"

typedef unsigned int QuadDE990 __attribute__((mode(TI)));
typedef struct RecordDE990 { QuadDE990 data[14]; } RecordDE990;
typedef struct StateDE990 { unsigned char bytes[64]; } StateDE990;
extern StateDE990 D_001A79F8;
extern int D_001A7AF0;
extern unsigned char D_0018C958[];
extern unsigned char D_001A7AF8[];
extern int D_00139868[];
extern RecordDE990 D_00239BA0[];
extern unsigned char D_00139568[];
extern int D_00139688[];
extern unsigned char D_001A7A60[];
extern unsigned char D_001A7A40[];
extern unsigned char D_001A7A80[];
extern unsigned char D_001A7AB8[];
extern unsigned char D_0019B278[];
extern unsigned char D_001395B8[];
extern int D_001A73B8[];





extern unsigned char D_001A7B94, D_001A7B95;
extern unsigned char D_001A7B08;
extern unsigned char D_00189E20[];
extern unsigned char D_001393E0[];
extern char D_001F2A40[];
extern void func_00282AB0(void *, void *, int);
extern void func_00282A60(void *, int, int);
extern void func_00298E08(void);
extern int func_00287FF8(int, int);
extern int func_00288870(RecordDE990 *, int, int);
extern void func_0029ADA0(char *);
void func_002DE990(int selected)
{
    int savedFlags[56];
    int savedWords[56];
    int savedSlots[56];
    RecordDE990 savedRecords[56];
    int saved32[32];
    unsigned char saved56[56];
    int saved12[12];
    StateDE990 savedState;
    unsigned char savedBlock[112];
    RecordDE990 first, second;
    int resident, hadCard, i;
    QuadDE990 *copySource, *copyDestination, *copyEnd;
    unsigned char control;
    D_001A79F8.bytes[0x12]++;
    D_001A79F8.bytes[0x3a] = 1;
    D_001A79F8.bytes[0x3b] = 0;
    resident = D_001A7AF0;
    hadCard = *(unsigned short *)(D_0018C958 + 0x84);
    savedState = D_001A79F8;
    for (i = 0; i < 56; i++) {
        savedFlags[i] = D_001A7AF8[i];
        savedWords[i] = D_00139868[i];
        copySource = D_00239BA0[i].data;
        copyDestination = savedRecords[i].data;
        copyEnd = copySource + 14;
        do {
            QuadDE990 firstQuad = copySource[0];
            QuadDE990 secondQuad = copySource[1];
            copyDestination[0] = firstQuad;
            copyDestination[1] = secondQuad;
            copySource += 2;
            copyDestination += 2;
        } while (copySource != copyEnd);
        savedSlots[i] = D_00139568[i];
    }
    for (i = 0; i < 32; i++) saved32[i] = D_001A7A60[i];
    for (i = 0; i < 12; i++) saved12[i] = D_001A7A40[i];
    savedFlags[51] = 0;
    savedFlags[36] = 0;
    savedFlags[20] = 0;
    savedFlags[13] = 0;
    savedFlags[38] = 0;
    savedFlags[39] = 0;
    savedFlags[46] = 0;
    savedFlags[48] = 0;
    savedFlags[55] = 0;
    savedFlags[21] = 0;
    savedFlags[2] = 0;
    savedFlags[3] = 0;
    savedFlags[4] = 0;
    savedFlags[19] = 0;
    savedFlags[8] = 0;
    func_00282AB0(savedBlock, D_0019B278, 112);
    control = D_001395B8[0x90];
    for (i = 0; i < 56; i++) saved56[i] = D_001A7A80[i];
    func_00298E08();
    func_00282AB0(D_0019B278, savedBlock, 112);
    D_001395B8[0x90] = control;
    func_00282A60(D_001A7AB8, 0, 56);
    for (i = 0; i < 56; i++) D_001A7A80[i] = saved56[i];
    for (i = 7; i >= 0; i--) D_001A73B8[i] = 0;
    D_001A79F8 = savedState;
    D_001A73B8[0] = 30;
    D_001A73B8[1] = 42;
    *(short *)(D_001A79F8.bytes + 0x22) = 0;
    *(int *)(D_001A79F8.bytes + 0x24) = 0;
    *(int *)(D_001A79F8.bytes + 0x18) = 0;
    *(int *)(D_001A79F8.bytes + 0x1c) = 0;
    D_001A7B94 = 0;
    D_001A7B95 = 0;
    if (hadCard && *(unsigned short *)(D_0018C958 + 0x84) == 0)
        *(unsigned short *)(D_0018C958 + 0x84) = 1;
    for (i = 0; i < 56; i++) {
        D_001A7AF8[i] = savedFlags[i];
        D_00139868[i] = savedWords[i];
        copySource = savedRecords[i].data;
        copyDestination = D_00239BA0[i].data;
        copyEnd = copySource + 14;
        do {
            QuadDE990 firstQuad = copySource[0];
            QuadDE990 secondQuad = copySource[1];
            copyDestination[0] = firstQuad;
            copyDestination[1] = secondQuad;
            copySource += 2;
            copyDestination += 2;
        } while (copySource != copyEnd);
        D_00139568[i] = savedSlots[i];
        D_00139688[i] = *(unsigned short *)((unsigned char *)&D_00239BA0[D_00139568[i]] + 0x8e);
    }
    for (i = 0; i < 32; i++) D_001A7A60[i] = saved32[i];
    for (i = 0; i < 12; i++) D_001A7A40[i] = saved12[i];
    D_001A7B95 = 0;
    D_001A7B94 = 0;
    func_00287FF8(10, 3);
    if (D_001A7B08) {
        if (*((unsigned char *)&D_00239BA0[D_00139568[0x10]] + 4) == 0)
            func_00287FF8(16, 2);
        else
            func_00287FF8(16, 3);
    }
    if (*((unsigned char *)&D_00239BA0[D_00139568[0x10]] + 4) == 0) {
        func_00288870(&first, 16, 2);
        func_00288870(&second, 16, 0);
        D_00139868[16] = (int)((float)*(int *)((char *)&first + 0x6c) *
            (float)D_00139868[16] / (float)*(int *)((char *)&second + 0x6c));
    }
    *(short *)(D_00189E20 + 0x24fc) = 1;
    D_001A7AF0 = resident;
    if (selected >= 0) {
        *(short *)(D_001393E0 + 0x18) = selected;
        *(int *)(D_001393E0 + selected * 28 + 0x30) = 0;
        func_0029ADA0(D_001F2A40);
        *(char **)(D_001393E0 + 0x174) = D_001F2A40;
        *(int *)(D_001393E0 + 0x148) = 0;
        if (*(int *)(D_001393E0 + 0x164) < 0) {
            *(int *)(D_001393E0 + 0x168) = 0;
            *(int *)(D_001393E0 + 0x164) = 19;
        }
    }
}
