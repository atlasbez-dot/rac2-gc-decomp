/* func_L04_004389C0 (396 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 396 bytes, 97 of 99 words identical; the fault is register choice in the
   "state == 0" block.
   check.py (04_barlow), with the source below:
     004389F0  lhu  $v0,0x34($s1)   |  lui  $v1,0x19
     004389F4  lui  $a0,0x0         |  lhu  $v0,0x34($s1)
     004389F8  addiu $a1,$zero,0x1  |  lw   $a0,-0x3F50($v1)
     004389FC  ori  $v0,$v0,0x800   |  addiu $a1,$zero,0x1
     00438A00  sh   $v0,0x34($s1)   |  ori  $v0,$v0,0x800
     00438A04  lw   $v1,0x0($a0)    |  ld   $v1,0x38($a0)
     00438A08  ld   $v0,0x38($v1)   |  sh   $v0,0x34($s1)
     00438A0C  sb   $a1,0x20($s1)   |  sd   $v1,0x38($s1)
     00438A10  sd   $v0,0x38($s1)   |  sb   $a1,0x20($s1)
   The 0x18C0B0 copy (g_pHeroMoby) is the only difference: ours keeps the %hi in a
   register of its own and the byte in another, retail puts the %hi in $v1 and the
   pointer in $a0. Writing the 64-bit copy FIRST (as here) is what brings the
   lui to the front; writing the 0x800 OR first moves it after the lhu.
   The last two words are the state 2: ours puts the constant in $v0 and reuses it
   for the later compare, retail materialises it twice ($v1 for the store, $v0 for
   the compare) as the sibling function func_L04_0042BF58 does.
   The measured statement order that gives the retail's frame is the 64-bit copy
   first, the 0x800 OR second and the state byte last; the flag's scope has to
   start inside the "state == 1" block or the frame loses two instructions.

   What is measured and right:
   - the unit must be a -g8 sibling (src/levels/04_barlow/L04_00422A00-g8.c):
     the D_001A79F0 read is `lw $v0,-0x7600($gp)`, which needs -G8 and the sda
     attribute; at -G0 the read comes out absolute.
   - g_pHeroMoby (0x18C0B0) must be declared nosda: the retail reads it with
     lui/addiu, not through $gp. A D_0018C0B0 name does not resolve (the build
     only knows the names the assembly uses), so the symbol_addrs name is needed.
   - the loop over the four words at the moby's start and the countdown of the
     call counter come out exactly (bgez/movn, then the 0x10 field test and the
     func_315108 test).
   - the "state == 0" copy is 64-bit wide (ld/sd) and the 0x34 field is 16-bit
     (lhu/sh) with the 0x800 bit.
   - the table test is D_0019B2E8[object byte 0xB0 + D_001A79F0 * 16] & 0x80 and
     the call happens when the flag is zero OR that bit is set.
   Tried and not enough: the 0x800 OR before or after the 64-bit copy; the state
   byte written through a u8 pointer; the flag declared before or after the moby
   pointer; the loop's index written as a pointer walk or as s4 + 4 * i. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;

extern int D_001A79F0 __attribute__((sda));
extern u8 D_0019B2E8[];
extern char *g_pHeroMoby __attribute__((nosda));
extern s32 func_33D168(u32 a0, s32 a1);
extern int func_315108(void);
extern void func_382DF8(s32 a0, s32 a1, u8 *a2);

/* Arms the object, asks the level's helpers about the objects around it, and moves the
   object's timer down while it is over the limit. */
void func_L04_004389C0(u8 *a0) {
    u8 *s1 = a0;
    u8 *s4 = *(u8 **)(a0 + 0x68);
    s32 i;

    if (s1[0x20] == 0) {
        *(u64 *)(s1 + 0x38) = *(u64 *)(g_pHeroMoby + 0x38);
        *(u16 *)(s1 + 0x34) |= 0x800;
        s1[0x20] = 1;
    }
    if (s1[0x20] == 1) {
        s32 found = 0;
        for (i = 0; i < 4; i++) {
            if (func_33D168(*(u32 *)(s4 + 4 * i), -1))
                found = 1;
        }
        if (*(u32 *)(s4 + 0x10) != 0) {
            if (func_315108() != 0) {
                if (func_33D168(*(u32 *)s4, -1) == 0)
                    found = 0;
            }
        }
        if (found == 0 || (D_0019B2E8[s1[0xB0] + (D_001A79F0 << 4)] & 0x80)) {
            func_382DF8(0, 0, s1);
            s1[0x20] = 2;
        }
    }
    if (s1[0x20] == 2) {
        f32 f1 = *(f32 *)(s1 + 0x18);
        if (f1 >= 30.0f)
            *(f32 *)(s1 + 0x18) = f1 - 0.28333336114883423f;
        if (*(f32 *)(s1 + 0x18) < 30.0f)
            s1[0x20] = 4;
    }
}
