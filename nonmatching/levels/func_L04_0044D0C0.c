/* USA v1.01/v2.00: 0/1; PAL absent from catalogue; 888/868 bytes. G8 with -frac2-qcopy,
 * -frac2-qcopy-barrier -frac2-zero-ti-barrier -fno-gcse; default
 * qcopy also gives 888 bytes. Frame keeps an extra s2/f20; constant
 * stores, zero and TI copies schedule differently. Reopen with typed
 * object/data layouts and evidence for constant lifetimes.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int TI128 __attribute__((mode(TI)));
extern u8 *D_L04_001B24DC __attribute__((sda));
extern float D_L04_001B1870 __attribute__((sda));
extern u8 D_L04_001B1880[8] __attribute__((sda));
extern u8 D_L04_001B9680[];
extern float func_002A89A8(void *, int, float);
extern int func_00283CF0(float);
extern void func_L04_0033CB88(void *);
extern int func_002A7820(int, int);
extern void func_002AB650(void *);
extern void func_002A7750(void *, int, int);
extern void func_002A7470(void *, int, int, int);
extern float func_00282E48(void *, void *);
extern void func_002A93B0(void *);
extern void *func_002A9640(void *, int, int);
extern int func_002B0ED8(void *, void *, int);
extern void func_L04_0044D7E0(void *);
extern void func_002B3BA8(void *, int, void *, int, float, float);

void func_L04_0044D0C0(u8 *object) {
    u8 *data = *(u8 **)(object + 0x68);
    u8 *other;
    int result;
    object[0x23] = 0x80;
    if (object[0x20] == 0) {
        *(float *)(object + 0x18) = func_002A89A8(object + 0x10, 0, 0.5f);
        *(TI128 *)(object + 0xF0) = 0;
        if (*(int *)(data + 0x328) != -1) {
            float height = *(float *)(D_L04_001B24DC + *(int *)(data + 0x328) * 256 + 0x18);
            *(unsigned int *)(object + 0x98) = 0;
            *(u16 *)(object + 0x34) |= 0x41;
            *(float *)(object + 0x18) = height + 1.4f;
        }
        *(int *)(data + 0x320) = 0;
        *(int *)(data + 0x324) = 0;
        data[0x48] = func_00283CF0(15.0f);
        data[0x4A] = func_00283CF0(4.0f);
        *(float *)(data + 0x7C) = 0.10000000894069672f;
        *(float *)(data + 0x94) = 0.3499999940395355f;
        *(float *)(data + 0x90) = 0.3499999940395355f;
        data[0x29] = 1;
        *(int *)(data + 0xA8) = 3;
        data[0x72] = 9;
        data[0x76] = 10;
        *(float *)(data + 0x80) = 0.05000000447034836f;
        *(float *)(data + 0x88) = 0.003055555745959282f;
        *(float *)(data + 0x8C) = 0.0005555555690079927f;
        *(float *)(data + 0x9C) = 0.4f;
        data[0xD2] = 6;
        data[0xD3] = 11;
        data[0x70] = 6;
        data[0x71] = 9;
        data[0x77] = 11;
        *(float *)(data + 0x84) = 0.003055555745959282f;
        data[0xCC] = 6;
        data[0xCD] = 11;
        data[0xCE] = 6;
        data[0xCF] = 11;
        func_L04_0033CB88(data + 0x140);
        *(float *)(data + 0x14C) = 2.5f;
        *(float *)(data + 0x148) = 2.0f;
        *(int *)(data + 0x140) = func_00283CF0(D_L04_001B1870 * 1024.0f);
        *(float *)(data + 0x144) = D_L04_001B1870;
        *(float *)(data + 0x164) = *(float *)(data + 0x30C) * 0.01666666753590107f;
        if (*(float *)(data + 0x2EC) != 12439.400390625f) {
            *(TI128 *)(data + 0x2E0) = *(TI128 *)(object + 0x10);
            *(float *)(data + 0x2EC) = 12439.400390625f;
        }
        *(TI128 *)(data + 0x110) = *(TI128 *)(data + 0x2E0);
        *(float *)(data + 0x120) = 0.5f;
        *(u16 *)(data + 0x300) = func_002A7820(120, 700);
        *(int *)(data + 0x31C) = 0;
        func_002AB650(object);
        data[0x28] = 0;
        *(int *)(data + 0x318) = 0;
        *(float *)(data + 0x230) = *(float *)(object + 0x2C);
        *(float *)(data + 0x220) = *(float *)(data + 0x30);
        *(void **)(data + 0x200) = D_L04_001B1880;
        *(float *)(data + 0x330) = (float)data[0x34];
        func_002A7750(object, 1, 0);
        if (object[0x43] != 0)
            func_002A7470(object, 0, 0, 0);
    }
    if (object[0x31] && func_00282E48(object + 0x10, D_L04_001B9680) < 24.0f) {
        func_002A93B0(object);
        object[0x6F] = 22;
    }
    other = func_002A9640(object, 0x230000, 0);
    if (other && other[0x28] == 8) {
        object[0x20] = 8;
        object[0xBC] = 4;
    }
    result = func_002B0ED8(object, data + 0x60, 0);
    if (result) {
        if (result == 5) {
            *(int *)(data + 0xF0) = 0;
            *(float *)(data + 0xF4) = 0.8377581834793091f;
        }
        func_L04_0044D7E0(object);
    }
    func_002B3BA8(object, -1, data + 0x2E0, 0, *(float *)(data + 0x2F4), 10.0f);
}
