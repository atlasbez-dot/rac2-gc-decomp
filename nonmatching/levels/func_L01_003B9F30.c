/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G16 -ffunction-sections -Wa,-G16 -frac2-qcopy.
 * Reported final C / retail: 4208 / 4220 bytes; size equality is not a match.
 * us: 0/1 placements; 4208/4220 bytes.
 * us2: 0/1 placements; 4208/4220 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: See the retained source comment for the measured residual.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Unmatched manual reconstruction. Closest measured profile:
 * -O2 -G16 -ffunction-sections -Wa,-G16 -frac2-qcopy: 4208 versus 4220 bytes,
 * 0/1 placements in US and US2. PAL has no canonical catalogue entry.
 * Without qcopy, 4136/4140 bytes; retail frame is 0xB0, this source uses 0xD0
 * with additional FPR saves. First difference remains at +0, not a 12-byte tail.
 * The real 16-byte zero/vector object is declared at its full observed width.
 * Lookahead passes position+6 in f12; Ghidra omitted that live float argument.
 * Zero-register quadword stores are represented as real aggregate zeroing.
 * Current canonical D6B70 has no arguments and overwrites a0 at entry. This C
 * honors that contract; the retail caller nevertheless loads a discarded handle
 * before its call, contributing a source/interface mismatch.
 * Helper audits preserve AA548/AAA00 f0 results, C9828's float plus five GPR
 * inputs, and C19D8's object-pointer result with two FP and three GPR inputs.
 * Behavior and linked-image equality are unverified. Reopen after an established
 * FPR lifetime/frame remedy and a qualified canonical ignored-handle contract.
 */
typedef unsigned int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float v[4]; } Vector;
struct Rac2Native_5f824a0e369ccf7b_src_record;
typedef struct {
    float f0;
    float f4;
    float f8;
    float f12;
    float f16;
    float f20;
    unsigned char f24;
    unsigned char f25;
    short f26;
    unsigned char f28;
    unsigned char f29;
    unsigned char f30;
    unsigned char f31;
    unsigned char pad32[16];
    short f48;
    short f50;
    int f52;
    int f56;
    int f60;
} PoolRecord64;
extern char D_00189E20[];
extern unsigned char D_0019B2E8[];
extern int D_001A79F0[] __attribute__((sda));
extern char *D_L01_001FE180[];
extern char *D_L01_001B255C __attribute__((sda));
extern float D_L01_001AFE18[4] __attribute__((sda));
extern float D_L01_002A48B0[], D_L01_002A45D0[];
extern struct Rac2Native_5f824a0e369ccf7b_src_record D_L01_00297300;
extern struct Rac2Native_5f824a0e369ccf7b_src_record D_L01_00297380;
extern struct Rac2Native_5f824a0e369ccf7b_src_record D_L01_00297400;
extern float func_L01_003BAFB0(void);
extern int func_001163B0(void);
extern void func_002A7470(unsigned char *, int, int, int);
extern void func_002A7750(unsigned char *, unsigned char, int);
extern int func_002A77E0(int);
extern int func_002A7820(int, int);
extern float func_002A7878(float, float);
extern float func_00282E48(void *, void *);
extern float func_00282E80(void *, void *);
extern float func_00282E20(void *);
extern float func_00282DF0(void *);
extern float func_00283248(float, float);
extern float func_00283180(float), func_00283198(float);
extern float func_00283BE0(float, float), func_00283C80(float, float);
extern int func_00283CF0(float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_0029FCC0(char *, int, char *);
extern void *func_002A9640(void *, unsigned int, int);
extern float func_002AA150(float, float, float);
extern float func_002AA2E8(float *, float, float);
extern float func_002AA548(float, float, float, float, void *, void *);
extern float func_002AAA00(float, float, float, float, void *, void *, int);
extern float func_002AAC80(float, float, float, float, void *);
extern void func_002AC9F8(float *, float), func_002ACB48(float *, float);
extern void func_002AD6F0(void *, void *, void *, void *);
extern void func_002AEC48(void *, void *, int, float, float);
extern void func_002AEF28(float *, float *, float *, float, float, float);
extern void func_002B0990(void *, float *, float, int, int);
extern char *func_002C19D8(float, float, void *, void *, int);
extern void func_002C9828(float, void *, int, void *, void *, void *);
extern int func_L00_002D6998(struct Rac2Native_5f824a0e369ccf7b_src_record *);
extern void func_L00_002D6B70(void);
extern PoolRecord64 *func_L00_002D70A0(int);
extern void func_L00_002D7140(unsigned char *);
#define I(p,o) (*(int *)((char *)(p)+(o)))
#define F(p,o) (*(float *)((char *)(p)+(o)))
#define H(p,o) (*(short *)((char *)(p)+(o)))
#define U(p,o) (*(unsigned short *)((char *)(p)+(o)))
#define P(p,o) (*(char **)((char *)(p)+(o)))

void func_L01_003B9F30(unsigned char *object)
{
    Vector old_position, old_rotation, direction, target, velocity;
    char *context = P(object, 0x68);
    char *outbound = D_L01_001FE180[I(context, 0x290)];
    char *inbound = D_L01_001FE180[I(context, 0x294)];
    char *hit, *child, *other;
    float surface, yaw, rate, x, y;
    int i, ready, index;
    unsigned char animation;
    old_position.q = *(Quadword *)(object + 0x10);
    old_rotation.q = *(Quadword *)(object + 0xF0);
    surface = func_L01_003BAFB0();
    if (object[0x20] > 1) F(object, 0x18) = F(context, 0x2A8);
    switch (object[0x20]) {
    case 0:
        if (surface > 0.0f) {
            F(context, 0x2B4) = 1.0f / func_00282E48(outbound + 0x10, outbound + 0x20);
            F(context, 0x2B8) = 1.0f / func_00282E48(inbound + 0x10, inbound + 0x20);
            I(context, 0x2F0) = -1;
            *(Quadword *)(object + 0x10) = *(Quadword *)(outbound + 0x10);
            F(object, 0xF8) = func_00283248(F(outbound, 0x20) - F(object, 0x10), F(outbound, 0x24) - F(object, 0x14));
            F(context, 0x2D4) = F(object, 0x18);
            I(context, 0x2AC) = 0;
            animation = object[0x43];
            if (animation != (func_001163B0() & 1)) {
                index = func_001163B0() & 1;
                func_002A7470(object, index, 0, func_002A7820(10, 20));
            }
            I(context, 0x8C) |= 0x10;
            if (I(context, 0x2D8) == 0) index = 2;
            else {
                object[0x31] = 0;
                I(object, 0x98) = 0;
                U(object, 0x34) |= 1;
                index = 1;
            }
            func_002A7750(object, index, -1);
        }
        break;
    case 1:
        object[0x31] = 0;
        I(object, 0x98) = 0;
        U(object, 0x34) |= 1;
        ready = 1;
        for (i = 0; i < 5; ++i) {
            index = I(context, 0x2DC + 4*i);
            if (index != -1 && !(D_0019B2E8[index + D_001A79F0[0]*16] & 0x80)) ready = 0;
        }
        if (ready) {
            object[0x31] = 1;
            U(object, 0x34) &= ~1;
            I(object, 0x98) = I(P(object, 0x24), 0x10);
            func_002A7750(object, 2, -1);
        }
        break;
    case 2:
        hit = func_002A9640(object, 0x10000, 0);
        if (!hit || (P(hit, 0x20) && H(P(hit, 0x20), 0xAA) == 0xCE7)) {
            rate = func_00282E80(object + 0x10, D_00189E20 + 0x80);
            if (rate < 10.0f) {
                if (object[0x43]) func_002A7470(object, 0, 0, func_002A7820(10, 20));
                func_0029FCC0(object, 0, (char *)&direction);
                func_00282CF0(&direction, D_00189E20 + 0xE0, &direction);
                yaw = func_00283248(direction.v[0], direction.v[1]);
                yaw = func_00283BE0(yaw, F(object, 0xF8));
                rate = -func_00283248(func_00282E20(&direction), direction.v[2]);
                if (yaw > 2.2689283f) yaw = 2.2689283f;
                else if (yaw < -2.2689283f) yaw = -2.2689283f;
                if (rate > 0.52359885f) rate = 0.52359885f;
                else if (rate < -0.52359885f) rate = -0.52359885f;
                F(context, 0xF4) = rate;
                for (i = 2; i >= 0; --i) F(context, 0xF0 + i*0x80) = yaw * 0.33333334f;
            } else if ((object[0x60] & 2) && !func_002A77E0(1)) {
                if (object[0x42] == 0 && !func_002A77E0(2)) {
                    if (object[0x43] != 1) func_002A7470(object, 1, 0, 10);
                } else if (object[0x42] == 1 && object[0x43] != 0) {
                    func_002A7470(object, 0, 0, 10);
                }
                F(object, 0x48) = func_002A7878(0.8f, 1.2f);
            }
            if (P(D_00189E20, 0x33C) == (char *)object && I(D_00189E20, 0x340)) {
                func_L00_002D6998(&D_L01_00297300);
                if (object[0x43] != 2) func_002A7470(object, 2, 5, 3);
                func_002A7750(object, 3, -1);
            }
        } else {
            if (P(D_00189E20, 0x33C) == (char *)object && I(D_00189E20, 0x340)) func_L00_002D6998(&D_L01_00297300);
            if (object[0x43] != 2) func_002A7470(object, 2, 5, 3);
            func_002A7750(object, 3, -1);
        }
        object[0xA8] = 0xFF;
        break;
    case 3:
        if (object[0x60] & 2) {
            if (P(D_00189E20, 0x33C) == (char *)object && I(D_00189E20, 0x340)) I(context, 0x2F0) = func_L00_002D6998(&D_L01_00297380);
            if (object[0x43] != 3) func_002A7470(object, 3, 0, 6);
            F(context, 0x2CC) = F(context, 0x2D0) = 10.0f;
            func_002A7750(object, 4, -1);
        }
        break;
    case 4:
        i = func_00283CF0(F(context, 0x2B0));
        if (F(outbound, i*16 + 0x1C) > 0.0f) {
            i = func_00283CF0(F(context, 0x2B0));
            F(context, 0x2CC) = F(outbound, i*16 + 0x1C);
        }
        func_002AA2E8((float *)(context + 0x2D0), F(context, 0x2CC), 0.33333334f);
        rate = F(context, 0x2B4);
        func_002AA548((float)(I(outbound, 0)-1), rate*0.005f, rate*0.0016666667f, F(context, 0x2D0)*rate*0.016666668f, context+0x2B0, context+0x2BC);
        func_002C9828(F(context, 0x2B0), outbound, 0, object+0x10, &direction, 0);
        F(object, 0xF8) = func_002AA150(F(object, 0xF8), direction.v[2], 0.5f);
        target.q = 0;
        if (F(context, 0x2B0)+6.0f < (float)(I(outbound, 0)-1)) {
            target.q = *(Quadword *)(object+0x10);
            velocity.q = *(Quadword *)(object+0xF0);
            func_002C9828(F(context, 0x2B0)+6.0f, outbound, 0, &target, &velocity, 0);
            func_00282CF0(&target, &target, object+0x10);
            yaw = func_00283248(target.v[0], target.v[1]);
            yaw = func_00283BE0(yaw, F(object, 0xF8));
            F(context, 0xF0) = yaw; F(context, 0xF8) = yaw*0.5f;
            F(context, 0x174) = yaw*0.33333334f; F(context, 0x1F4) = -yaw*0.5f;
        }
        target.v[0] = func_00283180(F(object, 0xF8))*10.0f;
        target.v[1] = func_00283198(F(object, 0xF8))*10.0f;
        target.v[2] = 0.0f;
        func_00282CC0(&target, &target, object+0x10);
        target.v[3] = 12345.0f;
        if (!func_002A77E0(4)) {
            velocity.q = *(Quadword *)(object+0x10);
            func_002ACB48(velocity.v, 0.05f);
            velocity.v[2] = surface;
            rate = func_002A7878(2.0f, 3.0f);
            i = func_002A77E0(6);
            child = func_002C19D8(rate, 13000.0f, &velocity, D_L01_001AFE18, ((i+20)<<24)|0x5060);
            if (child) child[9] = func_00283CF0(16.0f)+32;
        }
        if ((float)(I(outbound, 0)-1) <= F(context, 0x2B0)) {
            func_L00_002D6B70();
            I(context, 0x2F0) = -1;
            if (P(D_00189E20, 0x33C) == (char *)object && I(D_00189E20, 0x340)) func_L00_002D6998(&D_L01_00297400);
            if (object[0x43] != 6) func_002A7470(object, 6, 0, 10);
            U(object, 0x96) = 0;
            object[0x20] = 5;
            I(context, 0x2C0) = 20;
            F(context, 0x2B0) = 0.0f;
        }
        if ((I(context, 0x298) == -1 && target.v[3] != 12345.0f) ||
            P(D_00189E20, 0x33C) != (char *)object || !I(D_00189E20, 0x340)) goto clear_effect;
        index = I(context, 0x298);
        if (index != -1) {
            other = D_L01_001B255C + index*0x100;
            if (func_00282E80(object+0x10, other+0x10) < F(context, 0x29C)) {
                target.v[0] = F(other, 0x10); target.v[1] = F(other, 0x14); target.v[2] = F(other, 0x18);
                target.v[3] = 12345.0f;
            }
        }
        if (target.v[3] == 12345.0f) {
            if (!P(context, 0x2AC)) {
                P(context, 0x2AC) = func_L00_002D70A0(5);
                if (!P(context, 0x2AC)) break;
            }
            child = P(context, 0x2AC);
            func_00282CF0(child+0x20, &target, D_00189E20+0x80);
            I(child, 0x34) = 3;
            child[0x1F] = 1;
        }
        break;
    case 5:
    case 7:
        func_0029FCC0(object, 0, (char *)&target);
        if (object[0x20] == 5) {
            direction.q = *(Quadword *)(inbound+0x10);
            direction.v[2] -= 1.5f;
            x = F(inbound, 0x20); y = F(inbound, 0x24);
        } else {
            direction.q = *(Quadword *)(outbound+0x10);
            x = F(outbound, 0x20); y = F(outbound, 0x24);
        }
        yaw = func_00283248(x-direction.v[0], y-direction.v[1]);
        func_00282CF0(&velocity, &direction, object+0x10);
        rate = func_00282DF0(&velocity);
        func_002AAC80(rate, 0.001666667f, 0.001666667f, 0.10000001f, context+0x2C4);
        func_002AC9F8(velocity.v, F(context, 0x2C4));
        func_00282CC0(object+0x10, object+0x10, &velocity);
        F(object, 0x18) = F(outbound, 0x18) + (object[0x20] == 5 ? D_L01_002A48B0 : D_L01_002A45D0)[U(object, 0x96)];
        if (U(object, 0x96) < 180) {
            U(object, 0x96)++;
            if (!func_002A77E0(8)) {
                func_002ACB48(target.v, 0.01f);
                target.v[2] = surface;
                rate = func_002A7878(0.02f, 0.1f); i = func_002A77E0(6);
                func_002C19D8(rate, 8000.0f, &target, D_L01_001AFE18, ((i+20)<<24)|0x5060);
            }
        } else {
            if (object[0x43]) func_002A7470(object, 0, 0, 10);
            func_002AAA00(yaw, 0.000387851f, 0.0003393696097191423f, 0.02617994323372841f, object+0xF8, context+0x2C8, 0);
            if (func_00283C80(F(object, 0xF8), yaw) < 0.001f) {
                object[0xA8] = 0xFF; object[0x20] = object[0x20] == 5 ? 6 : 2;
                F(context, 0x2B0) = 0.0f;
            }
        }
        if (surface < target.v[2] && !func_002A77E0(6)) {
            target.q = *(Quadword *)(object+0x10);
            func_002ACB48(target.v, 0.5f); target.v[2] = surface;
            rate = func_002A7878(2.0f, 3.0f); i = func_002A77E0(6);
            child = func_002C19D8(rate, 13000.0f, &target, D_L01_001AFE18, ((i+20)<<24)|0x5060);
            if (child) child[9] = func_00283CF0(16.0f)+32;
        }
clear_effect:
        if (P(context, 0x2AC)) { func_L00_002D7140(P(context, 0x2AC)); P(context, 0x2AC) = 0; }
        break;
    case 6:
        rate = F(context, 0x2B8)*0.0022222223f;
        func_002AA548((float)(I(inbound, 0)-1), rate, rate, F(context, 0x2B8)*0.16666667f, context+0x2B0, context+0x2BC);
        func_002C9828(F(context, 0x2B0), inbound, 0, object+0x10, object+0xF0, 0);
        F(object, 0x18) -= 1.5f;
        if ((float)(I(inbound, 0)-1) <= F(context, 0x2B0)) {
            U(object, 0x96) = 0;
            if (object[0x43] != 7) func_002A7470(object, 7, 0, 10);
            object[0x20] = 7; F(context, 0x2B0) = 0.0f;
        }
        break;
    }
    if (object[0x20] > 1) {
        F(context, 0x2A8) = F(object, 0x18);
        F(object, 0x18) = F(object, 0x18) - F(context, 0x2D4) + surface;
        func_002AEF28((float *)object, (float *)(context+0x2A0), (float *)(context+0x2A4), 0.03490659f, 0.05f, 0.01f);
        for (i = 0; i < 3; ++i) func_002AEC48(object, context+0x90+i*0x80, i, 0.02f, 0.3f);
        if (object[0x20] != 6 && object[0x20] != 0 && !func_002A77E0(49)) {
            rate = func_002A7878(3.0f, 5.0f); i = func_002A77E0(6);
            child = func_002C19D8(rate, 13000.0f, object+0x10, D_L01_001AFE18, ((i+20)<<24)|0x5060);
            if (child) child[9] = func_00283CF0(16.0f)+32;
        }
        func_00282CF0(&direction, object+0x10, &old_position);
        if (surface-0.2f < F(object, 0x18)) func_002AD6F0(context+0x50, &direction, object+0xF0, object+0xF0);
    }
    func_002B0990(object, (float *)(context+0x300), 2.5f, 4, 1);
}
