/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -g -mno-split-addresses.
 * Reported final C / retail: 956 / 956 bytes; size equality is not a match.
 * us: 0/1 placements.
 * us2: 0/1 placements.
 * pal: absent from catalogue (not a match).
 * Residual: First +0x230: float constants and remainder/angle scheduling. Same total size. No remaining hypothesis after three tied source forms.
 * Reopening condition: New concrete supported compiler/API/identity hypothesis only; see retained source comment. No repeated flag or permutation sweep.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained complete reconstruction, 956/956 bytes with -O2 -G8 -g
   -ffunction-sections -mno-split-addresses. US and US2: 0/1; PAL absent.
   Six meaningful source/profile trials. First residual +0x230: ordering and
   allocation of 1.0/500.0/600.0 constants around the signed remainder and angle.
   Initial qcopy profile was 964 bytes; this stack-to-stack copy uses ordinary
   displaced TI moves. Reopen only with a new supported scheduling hypothesis. */
#include "common.h"

typedef struct { u8 before_state[0x68]; u8 *state; u8 rest[0x94]; } AnimationObject;
typedef int TI128 __attribute__((mode(TI)));
extern u8 *D_L02_001B359C __attribute__((nosda));
extern s32 D_L02_001B30C8 __attribute__((nosda));
extern float D_L02_001B2420 __attribute__((sda));
extern float D_L02_001B2424 __attribute__((sda));
extern float D_L02_001B2428 __attribute__((sda));
extern s32 D_L02_001B242C __attribute__((sda));
extern float D_L02_001B2430 __attribute__((sda));
extern s32 func_L02_00400B00(u8 *);
extern s32 func_00283DB8(float *, float);
extern void func_L02_0042ED48(u8 *);
extern s32 func_002B3868(u8 *);
extern s32 func_002A77E0(s32);
extern void func_002A7470(u8 *, s32, s32, s32);
extern void func_002A7750(u8 *, u8, s32);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern float func_00283B98(float, float);

/* Select an animation from the controller's speed and the rotating angular gates. */
void func_L02_0042E988(u8 *object)
{
    float bounds[8];
    u8 *state = *(u8 **)(object + 0x68);
    float speed;
    float angle;
    float direction;
    float x;
    float y;
    s32 cycle;
    s32 remainder;

    if (!func_L02_00400B00(D_L02_001B359C + (*(s32 *)state << 8)))
        return;
    *(TI128 *)(bounds + 4) = 0;
    bounds[4] = *(float *)(object + 0x10);
    bounds[5] = *(float *)(object + 0x14);
    bounds[6] = *(float *)(object + 0x18);
    bounds[7] = 5.0f;
    *(TI128 *)bounds = *(TI128 *)(bounds + 4);
    if (func_00283DB8(bounds, 255.0f) <= 0) {
        *(u16 *)(object + 0x32) = 0;
        return;
    }
    *(u16 *)(object + 0x32) = 0xFF;
    func_L02_0042ED48(object);
    speed = *(float *)(((AnimationObject *)D_L02_001B359C)[*(s32 *)state].state + 0x6C);
    switch (object[0x20]) {
    case 1:
        if (func_002B3868(object) && object[0x43] != func_002A77E0(2))
            func_002A7470(object, func_002A77E0(2), 0, 10);
        if (speed > D_L02_001B2428 && func_002A77E0(60) == 0)
            func_002A7750(object, 2, -1);
        else if (speed < D_L02_001B2420 && func_002A77E0(60) == 0)
            func_002A7750(object, 3, -1);
        break;
    case 2:
        if (func_002B3868(object)) {
            if (object[0x43] != func_002A77E0(2) + 2)
                func_002A7470(object, func_002A77E0(2) + 2, 0, 10);
        } else if (speed < D_L02_001B2424 && func_002A77E0(60) == 0)
            func_002A7750(object, 1, -1);
        break;
    case 3:
        cycle = D_L02_001B242C;
        remainder = D_L02_001B30C8 % cycle;
        x = *(float *)(object + 0x10) - 500.0f;
        y = *(float *)(object + 0x14) - 600.0f;
        bounds[7] = 1.0f;
        angle = (float)remainder * -6.2831855f / (float)cycle + 3.1415927f;
        bounds[4] = 500.0f;
        bounds[6] = 500.0f;
        bounds[5] = 600.0f;
        direction = func_00283248(x, y);
        if (func_00283C80(direction, angle) < D_L02_001B2430 ||
            func_00283C80(direction, func_00283B98(angle, 3.1415927f)) < D_L02_001B2430) {
            if (object[0x43] != 4)
                func_002A7470(object, 4, 0, 10);
        } else if ((object[0x60] & 2) && object[0x43] != func_002A77E0(2))
            func_002A7470(object, func_002A77E0(2), 0, 10);
        if (speed > D_L02_001B2424 && func_002A77E0(60) == 0)
            func_002A7750(object, 1, -1);
        break;
    }
}
