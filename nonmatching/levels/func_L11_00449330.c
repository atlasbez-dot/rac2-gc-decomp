/* func_L11_00449330 (200 bytes, 1 place: 11:00449330) -- NEAR MISS, not integrated.
   This C compiles to 212 bytes against retail's 200: twelve bytes over.
   The float constants and every call are retail's; the frame is 0x60 against retail's 0x50
   (two callee-saved registers too many) and the register allocation differs.
   What it is: when the object's byte at +0x31 is set it builds a direction vector
   (func_0032CD98 with 0.1 and 1/3), hands it to func_003004E0 with the level's own
   D_001A8F20, then runs func_003386D8 with the object's 0x354 record, the level's table and
   the 16 bytes the caller passed; otherwise it releases the 0x354 record and clears it.
   What differs:
   1. the frame: retail keeps the object in $s1 and the state in $s2 and saves three
      registers; this cc1 needs $s3 and $s4 as well, so the frame grows by 0x10.
   2. the copy of the caller's 16 bytes to the stack argument: retail does it in the delay
      slot of the first branch (`sq $v0,0x10($sp)`), this cc1 later.
   The float literals are measured: the retail's 0x3DCCCCCE is `0.10000001f`, its 0x3E2AAAAB
   is `0.33333334f` and its 0x3B360B61 (1/360) is `0.0027777778f`; this cc1's decimal to
   float conversion is one ulp off for the exact decimal of a float, so the literals have to
   be the ones above. */

typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef int TI128 __attribute__((mode(TI)));

extern s32 func_0032CD98(TI128 *a0, f32 f12, f32 f13);
extern void func_003004E0(TI128 *a0, TI128 *a1, void *a2);
extern void func_003386D8(void *a0, s32 a1, void *a2, void *a3, s32 a4, s32 a5,
                          void *a6, void *a7, f32 f12, void *a8, TI128 a9);
extern void func_00322818(u32 a0);

extern u8 D_001A8F20[];

void func_L11_00449330(char *object, TI128 *a1) {
    char *state = *(char **)(object + 0x68);
    TI128 v = *a1;
    TI128 local;

    if (object[0x31] != 0) {
        func_0032CD98(&local, 0.10000001f, 0.33333334f);
        func_003004E0(&local, &local, D_001A8F20);
        func_003386D8(object, 0x9D8, (char *)(*(u32 *)(state + 0x354) + 0x10),
                      (char *)(*(u32 *)(state + 0x354) + 0xF0), 0, 0, &local,
                      D_001A8F20, 0.0027777778f, D_001A8F20, v);
    }
    func_00322818(*(u32 *)(state + 0x354));
    *(u32 *)(state + 0x354) = 0;
}
