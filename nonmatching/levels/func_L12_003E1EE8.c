/* from src/levels/shared/L12_003E1CB0-g8.c (-G8 unit; the rate is read at $gp+0x1B20):
 * steps the object along its path. Best of 1 compile: 440 bytes against retail's 516,
 * 0/2 (levels 12 and 17). The whole front half is retail's: the state's +0x168 entry
 * pick with the `b` over the kind block's +0x10, the cross product into a Vec4, the
 * 16-byte copy to the working vector, the normalize, the `rate/60 < length` test, the
 * scale and the position add. What is left:
 *  (a) retail keeps the normalize/rate/scale/add tail TWICE (once at 0x3E1F70 and once
 *      out of line at 0x3E1FD0) and lets the second fall into the distance check; this
 *      cc1 cross-jumps the two identical tails into one, which costs the function a
 *      whole copy (19 instructions) and moves the entry pick's `b`;
 *  (b) retail's entry pick is `sll; addu` then `addiu` into the branch delay
 *      (`a1 + n*16 + 0x10`), while `a1 + 0x10 + (n << 4)` gives `sll; addiu; b; addu`;
 *  (c) the rate multiply has to come after the normalize call (retail loads the $gp
 *      float and builds 1/60 after `jal`); binding the call to a local `float len`
 *      should keep the product from being hoisted across the call;
 *  (d) the 0.5f threshold is one register in retail (used as both the func_002A89A8
 *      argument and the addend of the +0x18 store).
 * The $gp rate symbol is D_L12_001B1B10 (GP 0x1AEFF0 + 0x1B20); the entry table is
 * D_L12_001FEAC0 indexed as the unit's other functions do. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef int qword __attribute__((mode(TI)));

extern float D_L12_001B1B10 __attribute__((sda));
extern u8 D_L12_001FEAC0[];

extern void func_00282CF0(float *, const float *, const float *);
extern float func_00282DF0(float *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern float func_00282E48(void *, void *);
extern float func_002A89A8(void *, int, float);

int func_L12_003E1EE8(u8 *a0, u8 *a1) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *e = *(u8 **)(D_L12_001FEAC0 + (*(s32 *)(st + 0x158) << 2));
    float entry[4];
    float dir[4];
    float rot[4];
    float len;
    u8 *src;

    if (*(s32 *)(st + 0x168) > 0)
        src = a1 + 0x10 + (*(s32 *)(st + 0x168) << 4);
    else
        src = e + 0x10;
    *(qword *)entry = *(qword *)src;
    if (*(s32 *)(st + 0x168) > 0)
        func_00282CF0(rot, a1 + 0x10 + (*(s32 *)(st + 0x168) << 4),
                      a1 + (*(s32 *)(st + 0x168) << 4));
    else
        func_00282CF0(rot, e + 0x10, a1 + (*(s32 *)a1 << 4));
    *(qword *)dir = *(qword *)rot;
    len = func_00282DF0(dir);
    if (D_L12_001B1B10 * 0.016666668f < len) {
        func_00282F20(dir, dir, D_L12_001B1B10 * 0.016666668f);
        func_00282CC0(a0 + 0x10, a0 + 0x10, dir);
    }
    if (func_00282E48(a0 + 0x10, entry) <= 0.5f) {
        s32 c = *(s32 *)(st + 0x168);

        if (c == -1)
            return 1;
        if (*(s32 *)a1 - 1 == c) {
            float f;

            *(s32 *)(st + 0x168) = -1;
            f = func_002A89A8(e + 0x10, 0, 0.5f);
            if (*(float *)(e + 0x18) - f < 20.0f)
                *(float *)(e + 0x18) = f + 0.5f;
        } else {
            *(s32 *)(st + 0x168) = c + 1;
        }
    }
    return 0;
}
