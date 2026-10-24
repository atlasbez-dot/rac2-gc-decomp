/* Signature/interface follow-up, 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * USA v1.01: 1608/1652 bytes, 0/1 carrying placements.
 * USA v2.00: canonical name absent from the catalogue.
 * PAL: canonical name absent from the catalogue.
 * Interface assumption: the incoming owner/key in a0 is preserved. The current void(void)
 * wrapper forwards live a0 into its key query, so original arity is underspecified and no
 * surplus argument is proven.
 * The retained C remains nonmatching. Earlier sizes and residual offsets below are
 * historical and superseded by this measurement; their reopening hypotheses remain
 * unqualified. No linked build was run for this follow-up.
 */

/* Historical measurements, superseded where inconsistent with the follow-up above. */
/* USA v1.01 0/1; absent from us2 and PAL catalogues; 1608/1652 bytes.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Retail table used, but state transition branches and gaze scheduling remain. The unused pitch clamp is optimized away. Reopen with independent evidence for pitch use and original field layout.
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; f32 f[4]; } BarlowVector;
extern u8 *D_L04_001B24DC;
extern u8 D_L04_001BF880[];
extern int D_L04_001A8F00;
extern int D_L04_001B2228;
extern u8 D_00189EA0[], D_00189EB0[];
extern BarlowVector D_00189F00;
extern f32 D_00189F30[4];
extern u8 D_001A7A40;
extern void func_L01_003128C0(void *);
extern int func_L01_003245E0(void *, int, f32);
/* Interface assumption: retain the incoming owner/key in a0. The current
 * linked wrapper is declared void(void), but its query forwards a live a0
 * key; removing this input is not independently justified. */
extern void func_L01_003246D0(void *);
extern int func_00288AA0(void *, int);
extern int func_00288BE8(void *);
extern int func_002F5D10(void);
extern void func_002A7750(void *, int, int);
extern int func_00282948(void *);
extern f32 func_002A7878(f32, f32);
extern int func_00283CF0(f32);
extern void func_002A7470(void *, int, int, int);
extern f32 func_00282E80(void *, void *);
extern f32 func_00283248(f32, f32);
extern f32 func_00283C80(f32, f32);
extern f32 func_00282DF0(void *);
extern f32 func_00283B98(f32, f32);
extern void func_002AF000(void *, f32, f32, f32);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern f32 func_00283BE0(f32, f32);
extern f32 func_00282E20(void *);
extern void func_002AEC48(void *, void *, int, f32, f32);
extern void *D_L04_002CA270[];
extern u32 D_0013979C;
extern u8 D_001A7BCD, D_00139605;
extern int D_001A79F0 __attribute__((sda));
extern u8 D_0019B2E8[];
extern void func_L04_00423178(void *);
extern void func_L00_00427290(void);
extern void func_002F5CC8(void);
extern void func_002AD7B8(int);
extern void func_00288308(int);
extern void func_002AF0A8(int);
extern void func_002A0430(int);
extern void func_002DF3F8(void *, void *);
extern void func_0029B3E0(int, int);
extern void func_0029F338(void *);

void func_L04_00423258(u8 *object) {
    static void *cases[5] = {&&state0, &&state1, &&state2, &&state3, &&state4};
    BarlowVector target, origin, delta;
    u8 *data = *(u8 **)(object + 0x68);
    unsigned int state;
    f32 rate, heading, yaw, pitch;
    int look;
    func_L04_00423178(object);
    state = object[0x20];
    if (state < 5)
        goto *D_L04_002CA270[state];
    goto stateDone;
state0:
    if (D_001A7BCD) {
        func_0029F338(object);
        return;
    }
    func_L01_003128C0(object);
    func_002A7750(object, (D_0013979C & 0x800000) ? 3 : 1, -1);
    goto stateDone;
state1:
    if (func_L01_003245E0(object, 10, 4.0f)) {
        func_L01_003246D0(object);
        if (func_00288AA0(D_L04_001BF880, 0x37)) {
            func_00288BE8(D_L04_001BF880);
            func_002A7750(object, 2, -1);
        }
    }
    goto stateDone;
state2:
    D_L04_001B2228 = 1;
    if (D_L04_001A8F00 == 2) {
        object[0x31] = 0;
        *(u16 *)(object + 0x34) |= 1;
    }
    if (!func_002F5D10()) {
        D_L04_001B2228 = 0;
        object[0x31] = 1;
        *(u16 *)(object + 0x34) &= ~1;
        func_L00_00427290();
        func_002A7750(object, 3, -1);
    }
    goto stateDone;
state3:
    if (D_00139605 && func_L01_003245E0(object, 10, 2.5f)) {
        func_L01_003246D0(object);
        if (func_00288AA0(D_L04_001BF880, 0x39)) {
            func_00288AA0(D_L04_001BF880, 5);
            func_00288AA0(D_L04_001BF880, 0x3A);
            func_00288BE8(D_L04_001BF880);
            func_002F5CC8();
            func_002A7750(object, 4, -1);
        }
    }
    goto stateDone;
state4:
    D_L04_001B2228 = 1;
    if (D_L04_001A8F00 == 2) {
        object[0x31] = 0;
        *(u16 *)(object + 0x34) |= 1;
    }
    if (!func_002F5D10()) {
        D_L04_001B2228 = 0;
        object[0x31] = 1;
        *(u16 *)(object + 0x34) &= ~1;
        func_002AD7B8(5);
        func_00288308(0x30);
        func_002AF0A8(5);
        if (object[0xB0] == 0xFF) {
            func_0029B3E0(0, -1);
        } else {
            int channel = object[0xB0];
            if (!(D_0019B2E8[channel + D_001A79F0 * 16] & 0x80))
                func_002A0430(channel);
            func_002DF3F8(D_00189EA0, D_00189EB0);
        }
        func_0029F338(object);
        return;
    }
stateDone:
    if (object[0x20] != 0) {
        if (object[0x43] == 0 && func_00282948(data + 0x11C)) {
            *(int *)(data + 0x11C) = func_00283CF0(func_002A7878(1200.0f, 2400.0f));
        } else if ((object[0x60] & 2) && object[0x43] != 0) {
            func_002A7470(object, 0, 0, 10);
        }
    }
    rate = 0.02f;
    look = 0;
    if (object[0x43] == 0) {
        look = 1;
        if (func_00282E80(object + 0x10, D_00189EA0) < 8.0f &&
            func_00283C80(*(f32 *)(object + 0xF8), func_00283248(D_00189F00.f[0] - *(f32 *)(object + 0x10), D_00189F00.f[1] - *(f32 *)(object + 0x14))) < 1.5707964897155762f) {
            if (func_00282DF0(D_00189F30) > 0.01f)
                *(int *)(data + 0x114) = 120;
            else
                func_00282948(data + 0x114);
        } else if (*(int *)(data + 0x114)) {
            *(int *)(data + 0x114) = 0;
            *(TI128 *)(data + 0x100) = D_00189F00.q;
        }
        if (func_00282948(data + 0x118)) {
            *(int *)(data + 0x118) = func_00283CF0(func_002A7878(180.0f, 300.0f));
            heading = func_00283B98(*(f32 *)(object + 0xF8), func_002A7878(-90.0f, 90.0f) * 0.01745329424738884f);
            pitch = func_002A7878(0.0f, 30.0f) * 0.01745329424738884f;
            func_002AF000(data + 0x100, 6.0f, heading, pitch);
            func_00282CC0(data + 0x100, data + 0x100, object + 0x10);
        }
        if (*(int *)(data + 0x114)) {
            target.q = D_00189F00.q;
            rate = 0.04f;
        } else {
            target.q = *(TI128 *)(data + 0x100);
        }
    }
    if (look) {
        origin.q = *(TI128 *)(object + 0x10);
        origin.f[2] += 2.0f;
        func_00282CF0(&delta, &target, &origin);
        yaw = func_00283BE0(func_00283248(delta.f[0], delta.f[1]), *(f32 *)(object + 0xF8));
        pitch = -func_00283248(func_00282E20(&delta), delta.f[2]);
        if (yaw > 1.5707964897155762f)
            yaw = 1.5707964897155762f;
        else if (yaw < -1.5707964897155762f)
            yaw = -1.5707964897155762f;
        /* This object's update computes pitch but only applies yaw. */
        if (pitch > 0.523598849773407f)
            pitch = 0.523598849773407f;
        *(f32 *)(data + 0x68) = yaw * 0.6f;
        *(f32 *)(data + 0xE8) = yaw * 0.4f;
    }
    if (D_001A7A40)
        *(f32 *)(data + 0x70) = 2.75f;
    func_002AEC48(object, data, 0, rate, 0.3f);
    func_002AEC48(object, data + 0x80, 1, rate, 0.3f);
}
