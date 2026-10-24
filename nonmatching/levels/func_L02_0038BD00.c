/* 2228/3224, USA v1.01/v2.00 0/9; PAL absent.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * Semantic reference draft preserves route distribution, shuffled groups and model-specific light offsets. Common scale/copy loops factor retail repeated branches. All imported vector arrays have their measured full extents. Reopen for unrolled branch/lifetime reconstruction; runtime behavior not tested.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int TI128 __attribute__((mode(TI)));
struct Rail { int count; int unused[3]; float point[0][4]; };
extern u16 *D_L02_001FC060[];
extern struct Rail *D_L02_001FF1C0[];
extern char *D_L02_001B359C;
extern int D_001A79F0;
extern int D_L02_001AEE30 __attribute__((sda));
extern int D_L02_001AEE34;
extern float D_L02_001AEE38 __attribute__((sda));
extern float D_L02_001AEE3C;
extern float D_L02_001AEE80[3][4];
extern float D_L02_001AEEB0[2][4];
extern float D_L02_001AEED0[2][4];
extern float D_L02_001AEEF0[2][4];
extern float D_L02_001AEF10[2][4];
extern float D_L02_001AEF30[2][4];
extern float func_00282E48(void *, void *);
extern int func_002A77E0(int);
extern float func_00283CE0(int);
extern float func_002A7878(float, float);
extern float func_002A7940(void);
extern void func_00282C88(TI128 *);
extern float func_002A78D8(float, float);
extern int func_002A7820(int, int);
extern void func_00282D30(void *, void *, float);

void func_L02_0038BD00(char *owner, int group) {
    float primary[3][4], secondary[3][4];
    char *ownerData, *object, *data;
    struct Rail *rail;
    u16 *list, *cursor;
    int total, i, j, index, primaryCount, secondaryCount;
    float segmentLength, endDistance, spacing, speed, railCount, numerator;
    float (*extra)[4];
    short kind;
    if (!D_L02_001FC060[group])
        return;
    ownerData = *(char **)(owner + 0x68);
    owner[0x30] = 0xFF;
    rail = D_L02_001FF1C0[*(int *)ownerData];
    segmentLength = func_00282E48(rail->point[0], rail->point[1]);
    railCount = (float)rail->count;
    endDistance = func_00282E48(rail->point[0], rail->point[rail->count - 1]);
    *(u16 *)(ownerData + 0x70) = endDistance < 5.0f;
    *(struct Rail **)(ownerData + 0x60) = rail;
    *(float *)(ownerData + 0x14) = *(float *)(ownerData + 8) * (1.0f / segmentLength) * 0.01666666753590107f;
    list = D_L02_001FC060[group];
    cursor = list;
    total = 1;
    i = 0;
    while (!(*cursor & 0x8000)) {
        if (i > 0) {
            u16 temporary;
            j = func_002A77E0(i);
            temporary = list[j];
            list[j] = *cursor;
            *cursor = temporary;
        }
        cursor++;
        i++;
        total++;
    }
    spacing = ((float)rail->count * 0.4f) / (float)total;
    speed = (*(float *)(ownerData + 0x14) * 0.25f) / spacing;
    cursor = D_L02_001FC060[group];
    index = total - 1;
    do {
        object = D_L02_001B359C + (*cursor & 0x7FFF) * 256;
        data = *(char **)(object + 0x68);
        if (object != owner)
            *(u16 *)(object + 0x34) |= 2;
        numerator = func_00283CE0(index--);
        *(float *)(data + 0x10) = numerator / func_00283CE0(total) * railCount;
        *(float *)(data + 0x7C) = spacing;
        *(float *)(data + 0x84) = speed * func_002A7878(0.75f, 1.25f);
        *(float *)(data + 0x80) = func_002A7940();
        *(u16 *)(data + 0x72) = 1;
        func_00282C88((TI128 *)(data + 0x20));
        *(float *)(data + 0x28) = *(float *)(data + 4) * func_002A78D8(0.5f, 1.0f);
        *(u16 *)(data + 0x76) = func_002A7820(D_L02_001AEE30, D_L02_001AEE34);
        *(float *)(data + 0x68) = func_002A7940();
        *(float *)(data + 0x6C) = func_002A78D8(D_L02_001AEE38, D_L02_001AEE3C) * 0.0002908882452175021f;
        *(int *)(data + 0x18) = -1;
        *(int *)(data + 0x1C) = 0;
        *(int *)(data + 0x88) = 0;
        *(float *)(data + 0x78) = *(float *)(object + 0x2C) / *(float *)(*(char **)(object + 0x24) + 0x24);
        kind = *(short *)(object + 0xAA);
        primaryCount = 0;
        secondaryCount = 0;
        extra = 0;
        switch (kind) {
        case 0x9B0:
            primary[0][0] = -2.0999999046325684f;
            primary[0][1] = 0.75f;
            primary[0][2] = 0.8600000143051147f;
            primary[0][3] = 0.0f;
            primary[1][0] = -2.0999999046325684f;
            primary[1][1] = -0.75f;
            primary[1][2] = 0.8600000143051147f;
            primary[1][3] = 0.0f;
            primary[2][0] = -3.0f;
            primary[2][1] = 0.0f;
            primary[2][2] = -0.6700000166893005f;
            primary[2][3] = 0.0f;
            primaryCount = 3;
            secondaryCount = 3;
            extra = D_L02_001AEE80;
            break;
        case 0x9B7:
            primary[0][0] = -3.7179999351501465f;
            primary[0][1] = 0.0f;
            primary[0][2] = 0.7770000100135803f;
            primary[0][3] = 0.0f;
            primary[1][0] = -3.7179999351501465f;
            primary[1][1] = 0.0f;
            primary[1][2] = -0.8989999890327454f;
            primary[1][3] = 0.0f;
            primaryCount = 2;
            secondaryCount = 2;
            extra = D_L02_001AEEB0;
            break;
        case 0xB15:
            primary[0][0] = -2.424999952316284f;
            primary[0][1] = 3.364300012588501f;
            primary[0][2] = 0.9300000071525574f;
            primary[0][3] = 1.0f;
            primary[1][0] = -2.424999952316284f;
            primary[1][1] = -3.005000114440918f;
            primary[1][2] = 0.9300000071525574f;
            primary[1][3] = 1.0f;
            primaryCount = 2;
            secondaryCount = 2;
            extra = D_L02_001AEED0;
            break;
        case 0x134B:
            primary[0][0] = -0.2930000126361847f;
            primary[0][1] = 0.22200000286102295f;
            primary[0][2] = -0.14900000393390656f;
            primary[0][3] = 1.0f;
            primary[1][0] = -0.2930000126361847f;
            primary[1][1] = -0.22200000286102295f;
            primary[1][2] = -0.14900000393390656f;
            primary[1][3] = 1.0f;
            primaryCount = 2;
            secondaryCount = 2;
            extra = D_L02_001AEEF0;
            break;
        case 0xB13:
            primary[0][0] = -3.677999973297119f;
            primary[0][1] = 0.8080000281333923f;
            primary[0][2] = 0.10000000149011612f;
            primary[0][3] = 1.0f;
            primary[1][0] = -3.677999973297119f;
            primary[1][1] = -0.8080000281333923f;
            primary[1][2] = 0.10000000149011612f;
            primary[1][3] = 1.0f;
            primaryCount = 2;
            secondaryCount = 0;
            break;
        case 0xD5C:
            primary[0][0] = -3.677999973297119f;
            primary[0][1] = 0.8080000281333923f;
            primary[0][2] = 0.10000000149011612f;
            primary[0][3] = 1.0f;
            primary[1][0] = -3.677999973297119f;
            primary[1][1] = -0.8080000281333923f;
            primary[1][2] = 0.10000000149011612f;
            primary[1][3] = 1.0f;
            primaryCount = 2;
            secondaryCount = 0;
            break;
        case 0x127D:
            primary[0][0] = -0.16500000655651093f;
            primary[0][1] = 0.699999988079071f;
            primary[0][2] = -0.16099999845027924f;
            primary[0][3] = 1.0f;
            primary[1][0] = -0.16500000655651093f;
            primary[1][1] = -0.699999988079071f;
            primary[1][2] = -0.16099999845027924f;
            primary[1][3] = 1.0f;
            primaryCount = 2;
            secondaryCount = 2;
            break;
        case 0x128B:
            primary[0][0] = -0.003000000026077032f;
            primary[0][1] = 0.8429999947547913f;
            primary[0][2] = -0.30300000309944153f;
            primary[0][3] = 1.0f;
            primary[1][0] = -0.003000000026077032f;
            primary[1][1] = -0.8429999947547913f;
            primary[1][2] = -0.30300000309944153f;
            primary[1][3] = 1.0f;
            primaryCount = 2;
            secondaryCount = 2;
            extra = D_L02_001AEF10;
            break;
        case 0x1290:
            primary[0][0] = -0.8230000138282776f;
            primary[0][1] = 0.6980000138282776f;
            primary[0][2] = -0.21899999678134918f;
            primary[0][3] = 1.0f;
            primary[1][0] = -0.8230000138282776f;
            primary[1][1] = -0.6980000138282776f;
            primary[1][2] = -0.21899999678134918f;
            primary[1][3] = 1.0f;
            primary[2][0] = -1.3760000467300415f;
            primary[2][1] = 0.0f;
            primary[2][2] = 0.20800000429153442f;
            primary[2][3] = 1.0f;
            primaryCount = 3;
            secondaryCount = 3;
            break;
        case 0x1340:
            primary[0][0] = -0.2150000035762787f;
            primary[0][1] = 2.131999969482422f;
            primary[0][2] = -0.3190000057220459f;
            primary[0][3] = 1.0f;
            primary[1][0] = -0.2150000035762787f;
            primary[1][1] = -2.131999969482422f;
            primary[1][2] = -0.3190000057220459f;
            primary[1][3] = 1.0f;
            primaryCount = 2;
            secondaryCount = 2;
            extra = D_L02_001AEF30;
            break;
        default:
            break;
        }
        for (i = 0; i < primaryCount; i++) {
            func_00282D30(primary[i], primary[i], *(float *)(data + 0x78));
            *(TI128 *)(data + 0x30 + i * 16) = *(TI128 *)primary[i];
        }
        for (i = 0; i < secondaryCount; i++) {
            if (extra)
                *(TI128 *)secondary[i] = *(TI128 *)extra[i];
            else
                *(TI128 *)secondary[i] = *(TI128 *)(data + 0x30 + i * 16);
            func_00282D30(data + 0xA0 + i * 16, secondary[i], *(float *)(data + 0x78));
        }
        object[0x20] = 1;
        if (D_001A79F0 != 3)
            *(u16 *)(object + 0x32) = 0xBE;
    } while ((short)*cursor++ >= 0);
}
