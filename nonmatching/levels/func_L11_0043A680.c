/* func_L11_0043A680 (384 bytes, 1 place) -- NEAR MISS, not integrated. G8.
   state: 376 bytes against the retail's 384; 89 of the 96 words differ, the call
   sequence and the four float draws are the retail's, the register allocation
   and the block order are not.
   check.py (11_joba), with the source below in a -g8.c unit:
     11_joba: 376 bytes, expected 384
     func_L11_0043A680: 0 of 1 places match (src/levels/11_joba/L11_00432628-g8.c)

   What is measured and right:
   - the body needs the -G8 sibling: the retail reads the four limits through
     $gp (0x234C($gp) .. 0x2358($gp)), which are D_L11_001B133C, D_L11_001B1340,
     D_L11_001B1344 and D_L11_001B1348. At -G0 they come out absolute, so the
     body belongs in L11_00432628-g8.c with its marker taken out of
     L11_00432628.c.
   - the four draws are func_002A7878(0.0f, pi), func_002A7878(0.0f, pi),
     func_002A7878(0.0f, pi) and func_002A7878(20.0f, 40.0f); the retail stores
     the first three results at obj + 0xF0, 0xF4 and 0xF8 and multiplies the
     fourth by pi/180 into state + 0x2D4, negating it when func_002A77E0(2)
     returns non-zero.
   - the constants are taken from the disassembly, not from the arithmetic:
     pi is 0x40490FDB (3.14159274f) and pi/180 is 0x3C8EFA36 (0.017453294f).
   - the blend of the two limits is a + (b - a) * f13 in each pair, computed
     inline the way the retail does it, not through func_002AA140.

   What is left:
   - the retail keeps 0.0f in $f20 and pi in $f21 and the two arguments in
     $f22/$f23; this draft keeps pi in $f20 and the first argument in $f21.
   - the retail materialises 255 twice, in $v0 for the store at obj + 0x30 and in
     $s4 for the stores at obj + 0x32 and obj + 0xA8; this draft uses $s4 for all
     three, which is one instruction shorter than the retail's 384 bytes.
   - the retail's first draw keeps its second argument in the delay slot of the
     call, this draft sets both arguments before every call.

   Tried and not enough: the order of the first stores (the state load before and
   after the call), the declaration order of the two float locals, and the order
   of the last two statements (the store of the second limit against the call). */

extern void func_002A7750(void *, int, int);
extern float func_002A7878(float, float);
extern int func_002A77E0(int);
extern int func_00283CF0(float);
extern float D_L11_001B133C __attribute__((sda));
extern float D_L11_001B1340 __attribute__((sda));
extern float D_L11_001B1344 __attribute__((sda));
extern float D_L11_001B1348 __attribute__((sda));

typedef int TI128 __attribute__((mode(TI)));

void func_L11_0043A680(void *obj, void *arg1, float f12, float f13)
{
    char *p = obj;
    char *state;
    float f;
    float g;

    *(short *)(p + 0x32) = 255;
    *(unsigned char *)(p + 0x31) = 1;
    state = *(char **)(p + 0x68);
    func_002A7750(p, 3, 0);
    *(unsigned char *)(p + 0x30) = 255;
    *(float *)(state + 0x20) = (float)*(short *)(state + 0x24);
    *(unsigned char *)(p + 0xA8) = 255;
    *(unsigned char *)(state + 0x2E) = 1;
    *(TI128 *)(state + 0x2A0) = *(TI128 *)arg1;
    f = 0.0f;
    g = 3.14159274f;
    *(float *)(state + 0x2AC) = f12;
    *(short *)(state + 0x2EC) = 0;
    *(float *)(p + 0xF0) = func_002A7878(f, g);
    *(float *)(p + 0xF4) = func_002A7878(f, g);
    *(float *)(p + 0xF8) = func_002A7878(f, g);
    f = func_002A7878(20.0f, 40.0f);
    f = f * 0.017453294f;
    if (func_002A77E0(2) != 0)
        f = -f;
    *(float *)(state + 0x2D4) = f;
    *(unsigned char *)(p + 0xA8) = 255;
    *(unsigned short *)(p + 0x34) &= 0xFEFF;
    f = D_L11_001B133C + (D_L11_001B1340 - D_L11_001B133C) * f13;
    g = D_L11_001B1344 + (D_L11_001B1348 - D_L11_001B1344) * f13;
    *(float *)(state + 0x2E0) = f;
    *(int *)(state + 0x2E4) = func_00283CF0(g);
}
