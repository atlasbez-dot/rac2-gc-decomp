/* func_L09_003F02D0 (92 bytes, 1 place) -- measured 0 of 1: candidate is 96 bytes, one word over.
   (Wave 6, Docker-free ruler; provisional until the container revalidates.)

   Retail (23 instructions):
     sp -= 0x10 ; $at = 0x41200000 (10.0f) -> $f0 ; sd $ra
     a2 = 10 (the s16 store) ; $at = 0x3F800000 (1.0f) -> $f1
     a3 = 3 ; v0 = state = *(a0+0x68) ; t0 = 1 ; a1 = 0 ; v1 = *(v0+0xA4)
     sh a2,0x24(v0) ; swc1 f0,0x20(v0) ; a2 = 1 (the call's 3rd arg)
     sw v1,0x8C(v0) ; sb a3,0x28(v0) ; swc1 f1,0x30(v0)
     jal func_002A7750(a0, 0, 1, 3) ; sb t0,0x2F(v0)   <- in the delay slot

   Note a3 = 3 serves BOTH the byte store at 0x28 and the call's fourth argument:
   that sharing is what keeps retail at 23 instructions.

   The candidate below is 24: this cc1 materialises the 3 twice (t0 for the store,
   a3 for the argument) and its scheduler also emits the stores in a different order
   (sh 0x24, sw 0x8C, sb 0x2F, swc1 0x20, sb 0x28, jal, swc1 0x30). Four source
   shapes were measured (shared `int mode = 3;` locals, swapped last two stores,
   three shared locals) -- all stay at 96 bytes, so the duplicate is in the
   scheduler, not the allocator.
*/

typedef signed short s16;
typedef unsigned char u8;

extern void func_002A7750_4(unsigned char *, int, int, int);

void func_L09_003F02D0(u8 *a0) {
    u8 *state = *(u8 **)(a0 + 0x68);

    *(s16 *)(state + 0x24) = 10;
    *(float *)(state + 0x20) = 10.0f;
    *(int *)(state + 0x8C) = *(int *)(state + 0xA4);
    *(char *)(state + 0x28) = 3;
    *(float *)(state + 0x30) = 1.0f;
    *(char *)(state + 0x2F) = 1;
    func_002A7750_4(a0, 0, 1, 3);
}
