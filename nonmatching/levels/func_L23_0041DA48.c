/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections -fno-gcse.
 * Reported final C / retail: 1916 / 2008 bytes; size equality is not a match.
 * us: 0/1 placements; 1916/2008 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: 92 fewer bytes; object copies and absolute/GP mixed reads differ. Real16-byte palette and8-aligned16-byte color views retained. Real ninth802E0 argument3 and29B888 tenth tailargs verified.
 * Reopening condition: New measured source/data-layout or allocator hypothesis; do not repeat retained flag/control-flow trials or use artificial aliases/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* 1916/2008 bytes after3 trials. Remaining allocation, mixed absolute/GP global access and object copy layout. Palette/color objects retain real16-byte extents.
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections -fno-gcse. */
#include "include_asm.h"
typedef unsigned long long U64;
typedef struct ColorView { unsigned int word[4]; } ColorView __attribute__((aligned(8)));
extern char *D_L23_001A904C;
extern char *D_L23_001B1484 __attribute__((sda));
extern float D_L23_001B16D8 __attribute__((sda));
extern float D_L23_001B16D4 __attribute__((sda));
extern float D_L23_001B3004;
extern int D_L23_001B3000;
extern int D_0018B694, D_001A7340;
extern ColorView D_L23_001B16E0 __attribute__((sda));
extern ColorView D_L23_001B16F0 __attribute__((sda));
extern int D_L23_001B1770[4] __attribute__((sda));
extern char D_L23_001B1788[];
extern int D_L23_001B1FA8, D_L23_001B1FAC;
extern int D_L23_001B374C, D_L23_001B3750, D_L23_001B3754;
extern int D_L23_001B3748 __attribute__((sda));
extern int D_L23_001B1424 __attribute__((sda));
extern int D_L23_001B1700 __attribute__((sda));
extern int D_L23_001B1704 __attribute__((sda));
extern int D_L23_001B1708 __attribute__((sda));
extern int D_L23_001B170C __attribute__((sda));
extern int D_L23_001B1710 __attribute__((sda));
extern int D_L23_001B1714 __attribute__((sda));
extern int D_L23_001B1718 __attribute__((sda));
extern int D_L23_001B171C __attribute__((sda));
extern int D_L23_001B1720 __attribute__((sda));
extern int D_L23_001B1724 __attribute__((sda));
extern int D_L23_001B1728 __attribute__((sda));
extern int D_L23_001B172C __attribute__((sda));
extern int D_L23_001B1730 __attribute__((sda));
extern int D_L23_001B1734 __attribute__((sda));
extern int D_L23_001B1738 __attribute__((sda));
extern int D_L23_001B173C __attribute__((sda));
extern int D_L23_001B1740 __attribute__((sda));
extern int D_L23_001B1744 __attribute__((sda));
extern int D_L23_001B1748 __attribute__((sda));
extern int D_L23_001B174C __attribute__((sda));
extern int D_L23_001B1750 __attribute__((sda));
extern int D_L23_001B1754 __attribute__((sda));
extern int D_L23_001B1758 __attribute__((sda));
extern int D_L23_001B175C __attribute__((sda));
extern int D_L23_001B1760 __attribute__((sda));
extern int D_L23_001B1764 __attribute__((sda));
extern int D_L23_001B1768 __attribute__((sda));
extern int D_L23_001B176C __attribute__((sda));
extern int D_L23_001B1780 __attribute__((sda));
extern int func_00336D50(unsigned char *, int);
extern void func_00300A00(char *, int, float, float, float, float, float);
extern int func_0028E588(int, int);
extern int func_0028EA58(int, int, int, int, int, int *);
extern void func_0027EAE8(int, int, int, int, int, void *);
extern int func_00115DA8(char *, char *, ...);
extern int func_001157AC(char *);
extern int func_0027FB40(int, int, int, unsigned char *, int);
extern int func_00288FB8(int);
extern int func_L00_0030DD70(int, int);
extern void func_0029CC50(int, int, int);
extern void func_00282948(char *);
extern void func_002802E0(unsigned short *, int, int, int, int, int, int, int, int);
extern void func_0029B888(int, int, int, int, int, int, int, int, int, int);
extern void func_L00_0030CF60(void);

/* Draw the encounter's meters, counters and optional prompt panel. */
int func_L23_0041DA48(void) {
    char text[64];
    ColorView color;
    unsigned short panel[16];
    char *state = *(char **)(D_L23_001B1484 + 0x68);
    int image, x, y, right, message, a, b, length, rasterY;
    float position, ratio;
    image = func_00336D50((unsigned char *)D_L23_001A904C + 0x8710, 195);
    position = D_L23_001B16D8 * D_L23_001B3004 + 0.5f;
    if (D_L23_001B3000 == 1) rasterY = (int)(position + 3.0f);
    else rasterY = (int)position;
    func_00300A00((char *)image, 0x60442D00, D_L23_001B16D4, (float)rasterY, 1.0f, 1.0f, 0.0f);
    image = func_00336D50((unsigned char *)D_L23_001A904C + 0x8710, 196);
    position = D_L23_001B16D8 * D_L23_001B3004 + 0.5f;
    if (D_L23_001B3000 == 1) rasterY = (int)(position + 3.0f);
    else rasterY = (int)position;
    func_00300A00((char *)image, 0x60241700, D_L23_001B16D4, (float)rasterY, 1.0f, 1.0f, 0.0f);
    image = func_00336D50((unsigned char *)D_L23_001A904C + 0x8710, 197);
    position = D_L23_001B16D8 * D_L23_001B3004 + 0.5f;
    if (D_L23_001B3000 == 1) rasterY = (int)(position + 3.0f);
    else rasterY = (int)position;
    func_00300A00((char *)image, 0x55F0C070, D_L23_001B16D4, (float)rasterY, 1.0f, 1.0f, 0.0f);
    image = func_0028E588(0xEAA4, 1);
    func_0028EA58(image, D_L23_001B171C, (int)((float)D_L23_001B1720 * D_L23_001B3004 + 0.5f), D_L23_001B1724, D_L23_001B1728, D_L23_001B1770);
    image = func_0028E588(0xEAA4, 2);
    func_0028EA58(image, D_L23_001B172C, (int)((float)D_L23_001B1730 * D_L23_001B3004 + 0.5f), D_L23_001B1734, D_L23_001B1738, D_L23_001B1770);
    ratio = (float)D_0018B694 / (float)*(short *)(state + 0x2F4);
    x = D_L23_001B1708 + D_L23_001B1700 + D_L23_001B1718;
    y = D_L23_001B170C + D_L23_001B1704 / 2 - D_L23_001B1710 / 2;
    color = D_L23_001B16E0;
    color.word[1] = (color.word[1] & 0xFFFF00FF) | ((int)(ratio * 255.0f) << 8);
    D_L23_001B1780++;
    func_0027EAE8(x, y, x + (int)(ratio * (float)D_L23_001B1714), y + D_L23_001B1710, 0xFFFFF1, &color);
    ratio = *(float *)(state + 0x20) / (float)*(short *)(state + 0x2F6);
    color = D_L23_001B16F0;
    right = D_001A7340 - D_L23_001B1708 - D_L23_001B1700 - 4;
    color.word[0] = (color.word[1] & 0xFFFF00FF) | ((int)(ratio * 255.0f) << 8);
    func_0027EAE8(right - (int)(ratio * (float)D_L23_001B1714), y, right, y + D_L23_001B1710, 0xFFFFF1, &color);
    image = func_0028E588(0xEAA5, 0);
    position = (float)D_L23_001B1740 * D_L23_001B3004 + 0.5f;
    if (D_L23_001B3000 == 1) rasterY = (int)(position + 1.0f);
    else rasterY = (int)position;
    func_0028EA58(image, D_L23_001B173C, rasterY, D_L23_001B1744, D_L23_001B1748, D_L23_001B1770);
    func_00115DA8(text, D_L23_001B1788, D_L23_001B1FA8);
    length = func_001157AC(text);
    func_0027FB40(D_L23_001B1754, (int)((float)D_L23_001B1758 * D_L23_001B3004 + 0.5f), D_L23_001B174C, (unsigned char *)text, length);
    if (D_L23_001B1FAC) {
        image = func_0028E588(0xEAA5, 1);
        position = (float)D_L23_001B1760 * D_L23_001B3004 + 0.5f;
        if (D_L23_001B3000 == 1) rasterY = (int)(position + 1.0f);
        else rasterY = (int)position;
        func_0028EA58(image, D_L23_001B175C, rasterY, D_L23_001B1764, D_L23_001B1768, D_L23_001B1770);
    }
    if (D_L23_001B1FAC > 1) {
        image = func_0028E588(0xEAA5, 1);
        position = (float)D_L23_001B1760 * D_L23_001B3004 + 0.5f;
        if (D_L23_001B3000 == 1) rasterY = (int)(position + 1.0f);
        else rasterY = (int)position;
        func_0028EA58(image, D_L23_001B175C + D_L23_001B176C, rasterY, D_L23_001B1764, D_L23_001B1768, D_L23_001B1770);
    }
    message = D_L23_001B374C;
    if (message != -1 && D_L23_001B3748 == 0) {
        if (message == 1) { func_00288FB8(0x1240); func_0029CC50(0x1240, D_L23_001B3750, -1); }
        else if (message == 0) func_L00_0030DD70(func_00288FB8(0x2FA3), -1);
        else if (message == 2) { func_00288FB8(0x1241); func_0029CC50(0x1241, *(short *)(state + 0x2FC), -1); }
        D_L23_001B3754 = 0;
        func_00282948((char *)&D_L23_001B3754);
        if (D_L23_001B3754 < 1) D_L23_001B374C = -1;
    }
    if (D_L23_001B1424) {
        func_002802E0(panel, 240, 480, 44, 468, 256, (int)(D_L23_001B3004 * 320.0f + 0.5f), 16, 3);
        a = func_00288FB8(0x9FC);
        b = func_00288FB8(0x2F2C);
        func_0029B888((int)panel, 0x80F0F0F0, a, 0, 0, -1, 0, b, 0, 0);
    }
    func_L00_0030CF60();
    return 1;
}
