/*
 * Near miss (M19, 2026-10-26): 868/872 bytes, about 66 differing lines.
 * Profile: -O2 -G0 -ffunction-sections. us: 0/28 placements.
 * The colours are 64-bit (u64 parameters of func_0027F980/func_0027F538, unsigned long of
 * func_0028FC48): an int colour sign-extends where retail zero-extends.
 * Residual: retail spills half-8, half+7, half+9, half+74, (half+9)*16, the row-2/3 selected
 * colour and half+8 into a 0x90 frame; this keeps more in registers (0x80 frame). half+74
 * must stay a value (w - (half+74) folds to (w-74)-half); a local for it moves it early but
 * the allocation still differs.
 */
typedef unsigned char u8;
typedef unsigned long long u64;
extern int D_001A7BA0[], D_001A7B9C[], D_001A7B98[];
extern void func_0027C540(long);
extern void func_0027C660(void);
extern int func_00288FB8(int);
extern int func_0028E588(int, int);
extern void func_0027F980(int, int, u64, u8 *, int);
extern void func_0027F538(int, int, u64, u8 *, int);
extern void func_0028FC48(int, int, int, int, unsigned long, int);
extern void func_0028F788(int, int, int, int, int, int, int, int, int, int);

typedef struct {
    char pad0[0x20];
    int width;
    int height;
    char pad28[0x18];
    int selection;
} Menu;

int func_002D7DB8(Menu *menu)
{
    int quarter = menu->height >> 2;
    int half = menu->width >> 1;
    int width;
    u64 color;
    int valueX;
    func_0027C540(0);
    valueX = half + 8;
    color = menu->selection == 0 ? 0x8020FFFF : 0x80FFA888;
    func_0027F980(half - 8, quarter - 8, color, (u8 *)func_00288FB8(0x2F0F), -1);
    func_0028FC48(half + 7, quarter - 8, menu->width - 63, quarter + 8, 0x80696969, 0);
    func_0028FC48(half + 9, quarter - 6, menu->width - 65, quarter + 6, 0x80383838, 0);
    width = ((menu->width - (half + 74)) * D_001A7BA0[0]) / 1024;
    func_0028F788(func_0028E588(0xE99D, 8), (half + 9) * 16, (quarter - 6) * 16,
                  (half + 8 + width) * 16, (quarter + 5) * 16, 0, 160, 496, 336, 128);
    color = menu->selection == 1 ? 0x8020FFFF : 0x80FFA888;
    func_0027F980(half - 8, quarter * 2 - 8, color, (u8 *)func_00288FB8(0x2F10), -1);
    func_0028FC48(half + 7, quarter * 2 - 8, menu->width - 63, quarter * 2 + 8, 0x80696969, 0);
    func_0028FC48(half + 9, quarter * 2 - 6, menu->width - 65, quarter * 2 + 6, 0x80383838, 0);
    width = ((menu->width - (half + 74)) * D_001A7B9C[0]) / 1024;
    func_0028F788(func_0028E588(0xE99D, 9), (half + 9) * 16, (quarter * 2 - 6) * 16,
                  (half + 8 + width) * 16, (quarter * 2 + 5) * 16, 0, 160, 496, 336, 128);
    color = menu->selection == 2 ? 0x8020FFFF : 0x80FFA888;
    func_0027F980(half - 8, quarter * 3 - 8, color, (u8 *)func_00288FB8(0x2F11), -1);
    func_0027F538(valueX, quarter * 3 - 8, 0x80FFA888,
                  (u8 *)func_00288FB8(D_001A7B98[0] ? 0x2F13 : 0x2F12), -1);
    func_0027C660();
    return 2;
}
