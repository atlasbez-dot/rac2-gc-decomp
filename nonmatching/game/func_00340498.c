/* func_00340498 (412 bytes, 28 places: the boot and the 27 levels) - screening attempt.
 *
 * The shape of the function is understood and recorded here so that the next attempt
 * does not have to rediscover it:
 *
 *  - $s0 is the object; the frame is 0xF0 bytes;
 *  - five eight-byte copies (ldl/ldr + sdl/sdr, what this cc1 emits for an aggregate
 *    of two words) land on the stack at +0x00, +0x10, +0x20, +0x30 and +0x40, from the
 *    data addresses 0x1AE078, 0x1AE080, 0x1AE078 (again), 0x1AE088 and 0x1AE090.
 *    The stride of sixteen bytes says the locals are sixteen-byte objects; the copy
 *    is of the first eight bytes of each;
 *  - a 23-word argument block is built at $sp+0x50 and its address is kept in $s5
 *    (the stores are "0x54($s5)" and so on), with the fields
 *      +0x00 = 0x25FF58 (a data address: lui 0x26 / addiu -0x60A8)
 *      +0x04 = 4            +0x08 = 6
 *      +0x0C = obj->[0x814] +0x10 = obj->[0x818]
 *      +0x14 = $sp          +0x18 = $sp+0x10   +0x1C = $sp+0x20
 *      +0x20 = $sp+0x30     +0x24 = $sp+0x40
 *      +0x28 = obj+0x17C    +0x2C = obj+0x98   +0x30 = obj+0x214
 *      +0x34 = obj+0x260    +0x38 = 0
 *      +0x3C = obj+0x7D0    +0x40 = obj+0xA18  +0x44 = obj+0x870
 *      +0x48 = obj->[0x80C] +0x4C = obj->[0x820]
 *      +0x50 = 0            +0x54 = (obj->[0x81C] < 1)   +0x58 = 0
 *    The stores come in a permutation of that order, and the store of the constant 1
 *    to +0x54 is dead (the sltiu overwrites it);
 *  - the calls are `jal func_336390` with a0 = obj+0x17C, a1 = *(0x1A8CFC) + 0x8710
 *    and a2 = 0x23, then `jal func_337210` with a0 = $sp+0x50.
 *
 * The attempt below (the field list above, the block passed by pointer) comes out at
 * 428 bytes against retail's 412: the frame is 0x100 instead of 0xF0, the compiler
 * keeps seven callee-saved registers and the frame pointer, and it addresses the
 * block through $sp instead of through the base register $s5 that retail keeps.
 *
 * What is open: the type of the five locals (sixteen bytes each), the type of the
 * argument block, the order in which the twenty-three fields are assigned in the
 * source (the compiler's store order is a permutation of it, and retail's order is
 * the one to hit), and the names of the data addresses, which differ in every
 * program and therefore need a D_LNN_ or ref_ name.
 */
typedef struct { int a, b; } Pair;

typedef struct {
    int f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34,
        f38, f3c, f40, f44, f48, f4c, f50, f54, f58;
} InitArgs;

extern Pair D_001AE078;
extern Pair D_001AE080;
extern Pair D_001AE088;
extern Pair D_001AE090;
extern unsigned int D_001A8CFC;
extern unsigned int D_0025FF58;
extern void func_336390(void *, void *, int);
extern void func_337210(void *);

void func_00340498(u8 *obj)
{
    Pair q0 = D_001AE078;
    Pair q1 = D_001AE080;
    Pair q2 = D_001AE078;
    Pair q3 = D_001AE088;
    Pair q4 = D_001AE090;
    InitArgs a;

    a.f00 = (int)D_0025FF58;
    a.f04 = 4;
    a.f08 = 6;
    a.f0c = *(int *)(obj + 0x814);
    a.f10 = *(int *)(obj + 0x818);
    a.f14 = (int)&a;
    a.f18 = (int)&q0;
    a.f1c = (int)&q1;
    a.f20 = (int)&q2;
    a.f24 = (int)&q3;
    a.f28 = (int)(obj + 0x17C);
    a.f2c = (int)(obj + 0x98);
    a.f30 = (int)(obj + 0x214);
    a.f34 = (int)(obj + 0x260);
    a.f38 = 0;
    a.f3c = (int)(obj + 0x7D0);
    a.f40 = (int)(obj + 0xA18);
    a.f44 = (int)(obj + 0x870);
    a.f48 = *(int *)(obj + 0x80C);
    a.f4c = *(int *)(obj + 0x820);
    a.f50 = 0;
    a.f54 = *(int *)(obj + 0x81C) < 1;
    a.f58 = 0;

    func_336390(obj + 0x17C, *(unsigned int *)D_001A8CFC + 0x8710, 0x23);
    func_337210(&a);
}
