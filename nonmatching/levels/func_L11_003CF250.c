/* 428/448; us 0/2; absent from us2/pal.
 * Profile: -O2 -G0 -ffunction-sections.
 * Switch dispatch and a scoped resident pointer improve the 424-byte draft, but branch shape and base materialization differ. Helper 002D8EF8 has an integer status return in retail; 002B0CE0 also returns GPR status. Reopen with resident record and source-lifetime evidence.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 D_00189E20[];
extern u8 D_00189EA0[];
extern u8 D_001A7B00;
extern void func_002A7750(u8 *, u8, int);
extern int func_002B3868(u8 *);
extern void func_L00_00429020(int);
extern int func_002B0CE0(int, int, int);
extern int func_002ACBC8(void *, int);
extern int func_L11_002D8EF8(int, int);
extern float func_00283B98(float, float);
extern float func_00283198(float);
extern int func_00283CF0(float);

void func_L11_003CF250(u8 *object) {
    u8 *data = *(u8 **)(object + 0x68);
    int alpha;
    u32 color;
    switch (object[0x20]) {
    case 0:
        *(u16 *)(object + 0x34) |= 0x10;
        func_002A7750(object, 1, -1);
        break;
    case 1: {
        u8 *hero;
        if (func_002B3868(object) && *(int *)data != -1) {
            func_L00_00429020(*(int *)data);
            *(int *)data = -1;
        }
        hero = D_00189E20;
        if (*(u8 **)(hero + 0x33C) == object && *(int *)(hero + 0x340)) {
            if (D_001A7B00) {
                func_002B0CE0(12, 0x27F7, 1);
                *(u16 *)(hero + 0x1F2) = 10;
                if (*(float *)(data + 0xC) != 0.0f)
                    *(float *)(hero + 0x5B8) = *(float *)(data + 0xC);
            }
        } else if (*(int *)(hero + 0x2294) == 0x82 && *(int *)(data + 8) >= 0) {
            if (func_002ACBC8(D_00189EA0, *(int *)(data + 8)))
                func_L11_002D8EF8(6, 1);
        }
        break;
    }
    default:
        break;
    }
    if (object[0x31]) {
        *(float *)(data + 4) = func_00283B98(*(float *)(data + 4), 0.10471977293491364f);
        alpha = func_00283CF0(func_00283198(*(float *)(data + 4)) * 128.0f);
        if (alpha > 128)
            alpha = 128;
        else if (alpha < 32)
            alpha = 32;
        color = alpha;
        if (D_001A7B00)
            color <<= 8;
        *(u32 *)(object + 0x78) = color | 0x80000000;
    }
}
