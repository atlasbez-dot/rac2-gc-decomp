/* 912/2960, USA v1.01/v2.00 0/9; PAL absent.
 * Profile: default -O2 -G8 -ffunction-sections.
 * Semantic reference draft factors repeated model-specific render branches into loops. Retail is unrolled, with different scheduling and mixed absolute/GP global reads. The render helper live t3 culling range is preserved. Reopen for per-model unrolled source reconstruction; runtime behavior not tested.
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int D_001A79F0 __attribute__((sda));
extern float D_00189EA8;
extern u8 D_00188660[];
extern float D_L02_001BA500[4];
extern int func_002E5CF8(int, int, char *);
extern int func_00282978(void *);
extern u32 func_00283D38(u32, u32, float);
extern float func_00282E48(void *, void *);
/* Retail consumes all eight GPR inputs, including the culling range in t3. */
extern void *func_L00_0033E220(void *, void *, u32, int, int, int, int, int, float, float);

void func_L02_0038CDE8(char *object) {
    char *data = *(char **)(object + 0x68);
    short kind = *(short *)(object + 0xAA);
    int points, i;
    float nearScale, farScale, distance;
    u32 nearColor, farColor;
    if (kind == 0x9B7 || kind == 0x9B0 || kind == 0xD2C || kind == 0xD5C) {
        if (D_001A79F0 != 13) {
            char *event = (char *)D_00188660 + *(int *)(data + 0x18) * 0x70;
            if (*(char **)(event + 0x88) != object || !event[0x74])
                *(int *)(data + 0x18) = func_002E5CF8(0, 4, object);
        }
    }
    if (*(short *)(object + 0xAA) == 0xD2C) {
        if (func_00282978(data + 0x74)) {
            *(short *)(data + 0x74) = 35;
            *(int *)(data + 0x8C) = *(int *)(data + 0x8C) == 0;
        }
        *(u32 *)(object + 0x78) = func_00283D38(*(u32 *)(object + 0x78), 0x50000046, 0.15f);
    }
    if (D_001A79F0 == 13 && D_00189EA8 > 89.0f)
        return;
    kind = *(short *)(object + 0xAA);
    nearScale = 756000.0f;
    farScale = 777000.0f;
    nearColor = 0x40804040;
    farColor = 0x20804040;
    points = 2;
    switch (kind) {
    case 0x9B0:
        points = 3;
        break;
    case 0x9B7:
    case 0xB15:
        nearColor = 0x405696FF;
        farColor = 0x205696FF;
        break;
    case 0xB13:
    case 0xD5C:
        break;
    case 0x127D:
        nearScale = 294000.0f;
        farScale = 231000.0f;
        nearColor = 0x40202080;
        farColor = 0x205696FF;
        break;
    case 0x1290:
        points = 3;
        nearScale = 210000.0f;
        farScale = 210000.0f;
        nearColor = 0x40804020;
        farColor = 0x20905010;
        break;
    case 0x134B:
        nearScale = 340200.0f;
        farScale = 194250.0f;
        break;
    default:
        return;
    }
    distance = func_00282E48(D_L02_001BA500, object + 0x10);
    if (distance < (float)*(int *)(data + 0x90)) {
        for (i = 0; i < points; i++)
            func_L00_0033E220(data + 0x30 + i * 16, object, nearColor, -1, 0, 2, 0, *(int *)(data + 0x90), *(float *)(data + 0x78) * nearScale, 0.5f);
    }
    if (distance < (float)*(int *)(data + 0x94)) {
        for (i = 0; i < points; i++)
            func_L00_0033E220(data + 0x30 + i * 16, object, farColor, -1, 1, 2, 0, *(int *)(data + 0x94), *(float *)(data + 0x78) * farScale, 0.6f);
    }
}
