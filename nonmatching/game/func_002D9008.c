/* Retention review: external whole-object extents remain incomplete.
 * Declaration-only corrections below were not recompiled. Measurements in the
 * retained header describe the original private trial, not this revised text.
 */
/* Complete manual reconstruction; not linked.
 * Profile: -O2 -G0 -ffunction-sections.
 * us: 0/28 placements; exit 1.
 * us2: 0/28 placements; exit 1.
 * pal: 0/28 placements; exit 1.
 * USA compiled 1356 bytes; retail 1484 bytes.
 * The retained body uses an 0x80-byte frame versus retail 0xB0 and different cell-coordinate spills. Reopen with evidence for the independent coordinate lifetimes and mixed small-data accesses.
 */

typedef struct { short fields[12]; } MenuTextRectangle;
extern char *D_001F2854;
extern char D_00263B50[], D_00264290[], D_00263EF0[];
extern unsigned char D_001A7A60[], D_001A7BB4;
extern void func_002FC560(unsigned int, unsigned long long);
extern void func_0027C540(int);
extern void *func_00115484(void *, int, int);
extern unsigned long func_0027C878(int);
extern int func_00288FB8(int);
extern void func_0027F120(void), func_0027F110(void), func_0027C660(void);
extern void func_0027FC70(short *, unsigned long, int, int, unsigned long, char *);
extern void func_002D9CF8(int, int, int);
extern void func_0028FAB8(int, int, int, int, int, int);

extern int D_001ABAD8, D_001ABADC, D_001ABAE8;
extern int D_001AA43C __attribute__((sda));
extern int D_001B1598;
extern unsigned char D_001A7AF8[], D_001395B8[];
extern unsigned int func_002884B0(unsigned int);
extern int func_00282C30(int);
extern void func_0028FC48(int, int, int, int, unsigned long, int);
extern void func_0028EE98(int, int, int, int, int, int);

extern char D_001F2840[];
extern unsigned char D_00139568[], D_00239BA0[];
extern void func_002D8EC0(char *, short *, int, int, int, int);
extern int func_0028E588(int, int);

int func_002D9008(char *object)
{
    short *record = *(short **)(object + 0x48);
    int active = *(char **)(D_001F2854 + 0xE8) == object;
    int width, height, xStart, xStep, yStart, yStep;
    int row, column, index = 0, x, y, nextY, state, right, bottom;
    int drawable, texture;
    unsigned long colour, pulse;
    unsigned char *entry;
    func_002FC560(66, 0x8000000044ULL);
    func_002FC560(71, 11);
    func_0027C540(0);
    width = D_001ABAD8;
    height = D_001ABADC;
    if (*(int *)(object + 0x44) >= 2) {
        xStart = *(int *)(object + 0x34) << 4;
        xStep = width + ((*(int *)(object + 0x20) << 4) -
                (*(int *)(object + 0x34) << 5) - *(int *)(object + 0x44) * width) /
                (*(int *)(object + 0x44) - 1);
    } else {
        xStart = ((*(int *)(object + 0x20) << 4) - width) >> 1;
        xStep = 0;
    }
    if (*(int *)(object + 0x30) & 2) {
        yStep = height + D_001ABAE8;
        yStart = *(int *)(object + 0x38) << 4;
    } else if (*(int *)(object + 0x40) >= 2) {
        yStart = *(int *)(object + 0x38) << 4;
        yStep = height + ((*(int *)(object + 0x24) << 4) -
                (*(int *)(object + 0x38) << 5) - *(int *)(object + 0x40) * height) /
                (*(int *)(object + 0x40) - 1);
    } else {
        yStep = 0;
        yStart = ((*(int *)(object + 0x24) << 4) - height) >> 1;
    }
    y = yStart;
    for (row = 0; row < *(int *)(object + 0x40); row++) {
        nextY = y + yStep;
        x = xStart;
        for (column = 0; column < *(int *)(object + 0x44); column++) {
            state = 0;
            drawable = record[2] == 0 ? D_001A7AF8[record[3]] : D_001395B8[record[3]];
            right = x + width;
            bottom = y + height;
            if (drawable) {
                if (record[2] == 0) {
                    int key = record[3];
                    entry = D_00239BA0 + D_00139568[key] * 224;
                    if (*(int *)((char *)&D_001F2840 + 0x40 + *(int *)(entry + 0xC) * 4) == key)
                        state = ((*(int *)(object + 0x30) ^ 1) & 1) << 2;
                    if (state == 0) state = entry[4] ? 3 : 0;
                    if (*(int *)((char *)&D_001F2840 + 0x144) && (*(int *)(object + 0x30) & 8)) state = 2;
                    if (*(int *)((char *)&D_001F2840 + 0x148) && (*(int *)(object + 0x30) & 4)) state = 2;
                    if (func_002884B0((unsigned short)record[0]))
                        func_002D8EC0(object, record, column, row, x >> 4, (y >> 4) + 36);
                }
                if (active && *(int *)(object + 0x3C) == index) {
                    pulse = (unsigned int)(((func_00282C30((D_001B1598 & 63) - 32) + 64) * 0x10202) | 0x80000000u);
                    colour = state == 4 ? (unsigned long)(int)0x80101010u : (unsigned long)D_001AA43C;
                    func_0028FC48(x - 48, y - 48, right + 48, bottom + 48, pulse, 1);
                    func_0028FC48(x - 16, y - 16, right + 16, bottom + 16, colour, 1);
                    if (state == 4)
                        func_0028FC48(x - 64, y - 64, right + 64, bottom + 64, 0x80FFFFFFUL, 1);
                }
                entry = D_00239BA0 + D_00139568[record[3]] * 224;
                texture = func_0028E588(*(unsigned short *)(entry + 0x3C), record[1]);
                func_0028EE98(texture, x, y, width, height, 128);
                if (state == 2)
                    func_0028FC48(x - 64, y - 64, right + 64, bottom + 64, 0x60202020UL, 1);
            } else if (active && *(int *)(object + 0x3C) == index) {
                pulse = (unsigned int)(((func_00282C30((D_001B1598 & 63) - 32) + 64) * 0x10202) | 0x80000000u);
                colour = (unsigned long)D_001AA43C;
                func_0028FC48(x - 48, y - 48, right + 48, bottom + 48, pulse, 1);
                func_0028FC48(x - 16, y - 16, right + 16, bottom + 16, colour, 1);
            }
            index++;
            record += 5;
            x += xStep;
        }
        y = nextY;
    }
    func_0027C660();
    return 2;
}
