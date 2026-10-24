/* Complete manual reconstruction; not linked.
 * Profile: -O2 -G0 -ffunction-sections.
 * us: 0/28 placements; exit 1.
 * us2: 0/28 placements; exit 1.
 * pal: 0/28 placements; exit 1.
 * USA compiled 796 bytes; retail 804 bytes.
 * The frame/saves and twelve-byte table-copy temporaries differ. Reopen with a measured source-lifetime hypothesis for the four complete tables, retaining the ninth stack argument and f0 return.
 */

typedef struct { float values[3]; } StageFloatTable;
typedef struct { int values[3]; } StageIntTable;
extern StageFloatTable D_001AE628, D_001AE638;
extern StageIntTable D_001AE648, D_001AE658;
extern void func_003363C0(unsigned char *, float);

typedef unsigned char u8;
extern char *D_L00_001A904C_3 __attribute__((sda));
extern void func_00336390(char *, char *, int);

float func_0034A4E0(char *object, int value, int *count, int *group,
                    float *scale, int *first, int *second, int *last,
                    float *offset)
{
    StageFloatTable scales = D_001AE628;
    StageFloatTable results = D_001AE638;
    StageIntTable firsts = D_001AE648;
    StageIntTable seconds = D_001AE658;
    int index = value - 1;
    float position, result = 0.0f;
    char *left, *right;

    *last = 0;
    *group = value < 21 ? 1 : 2;
    if (index < 0) index = 0;
    if ((unsigned int)(value - 1) < 20) {
        position = (float)(index / 4);
        *count = 6;
        *scale = scales.values[0];
        *first = firsts.values[0];
        *second = seconds.values[0];
        *offset = 0.0f;
        result = results.values[0];
        left = object + 0x5C;
        right = object + 0xA8;
        func_003363C0((u8 *)left, position);
        func_003363C0((u8 *)right, position);
        func_00336390(left, D_L00_001A904C_3 + 0x8710, 17);
        func_00336390(right, D_L00_001A904C_3 + 0x8710, 18);
    } else if ((unsigned int)(value - 21) < 20) {
        int row = index / 4 - 5;
        if (row < 0) row = 0;
        position = (float)row;
        *count = 10;
        *scale = scales.values[1];
        *first = firsts.values[1];
        *second = seconds.values[1];
        *offset = -0.5f;
        result = results.values[1];
        left = object + 0x5C;
        right = object + 0xA8;
        func_003363C0((u8 *)left, position);
        func_003363C0((u8 *)right, position);
        func_00336390(left, D_L00_001A904C_3 + 0x8710, 19);
        func_00336390(right, D_L00_001A904C_3 + 0x8710, 20);
    } else if ((unsigned int)(value - 41) < 40) {
        int row = index / 4 - 10;
        if (row < 0) row = 0;
        position = (float)row;
        *count = 10;
        *scale = scales.values[2];
        *first = firsts.values[2];
        *second = seconds.values[2];
        *offset = -0.5f;
        *last = 1;
        result = results.values[2];
        left = object + 0x5C;
        right = object + 0xA8;
        func_003363C0((u8 *)left, position);
        func_003363C0((u8 *)right, position);
        func_00336390(left, D_L00_001A904C_3 + 0x8710, 21);
        func_00336390(right, D_L00_001A904C_3 + 0x8710, 22);
    }
    return result;
}
