/* Mid worker 11 near miss (func_L20_0039E9F8).
   Profile: -O2 -G8 -ffunction-sections (file named -g8.c).
   Status: same 444 bytes; about 10 instructions differ because ours loads D_L20_001B308C at the top of the function and retail after the state pointer, plus f1 vs f12 for the state's float. */
#include "common.h"

#define FLD(base, T, off) (((struct { u8 pad[off]; T v; } *)(base))->v)

extern float D_L20_001AED10 __attribute__((sda));
extern float D_L20_001AED0C __attribute__((sda));
extern char *D_L20_001B308C;

extern float func_00283B98(float, float);
extern float func_00283C80(float, float);
extern void func_002AAA00(char *, char *, int, float, float, float, float);
extern void func_002AA548(char *, char *, float, float, float, float);
extern float func_00282C48(void);
extern int func_00282C30(int);
extern void func_00282C90(char *);
extern void func_002830C0(char *, char *, char *);

void func_L20_0039E9F8(char *obj) {
    char *state = FLD(obj, char *, 0x68);
    char *entry;
    float turn;
    float spin;
    float target;
    float r;

    entry = D_L20_001B308C + (FLD(state, int, 0x84) << 7);
    turn = D_L20_001AED10 * 0.00027777778450399637f;
    spin = D_L20_001AED0C * 0.01666666753590107f;
    target = FLD(entry, float, 0x78);
    if (FLD(state, int, 0x190) < 0) {
        target = func_00283B98(target, 3.1415927410125732f);
    }
    r = func_00283C80(FLD(obj, float, 0xF8), target);
    if (r > 0.01745329424738884f) {
        func_002AAA00(obj + 0xF8, state + 0x19C, 0, target, 0.0008726647356525064f, 0.0008726647356525064f, 0.05235988646745682f);
    } else {
        func_002AA548(state + 0x194, state + 0x198, (float)FLD(state, int, 0x190), turn, turn, spin);
        r = FLD(state, float, 0x194) * (float)FLD(state, int, 0x190);
        if (r > 0.0f) {
            target = func_00282C48();
            if ((float)func_00282C30(FLD(state, int, 0x190)) <= target) {
                FLD(state, int, 0x190) = -FLD(state, int, 0x190);
            }
        }
    }
    func_00282C90(obj + 0x10);
    FLD(obj, float, 0x10) = FLD(state, float, 0x194);
    func_002830C0(obj + 0x10, obj + 0x10, D_L20_001B308C + (FLD(state, int, 0x84) << 7));
}
