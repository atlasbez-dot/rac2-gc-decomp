/* func_002E3478 - near miss.
 *
 * The retail body (208 bytes): for three elements of a 12-byte record it calls
 * func_00283B98 (atan2) with the element of D_001B1990 and the element of the
 * record at 0x261DD0, writes the result back into the record, then copies the
 * three results into a frame buffer and calls func_00283430 with
 * D_001B20F0 and that buffer.
 *
 *   mult   $s1,$a0,0xC            ; the record index, a0 * 12
 *   lui    $s0,0x26 ; addiu $s0,$s0,0x1DD0   ; the record base
 *   addu   $s3,$s1,$s0             ; record + a0 * 12      (element 0)
 *   addu   $s2,$s1,$s2             ; (base + 4) + a0 * 12 (element 1)
 *   addu   $s0,$s1,$s0             ; (base + 8) + a0 * 12 (element 2)
 *   lui    $v0,0x1B ; lw $v0,0x1990($v0)      ; D_001B1990, re-read every time
 *
 * What matches: the size (208 bytes), the frame (0x40 with the buffer at
 * sp+0), the three-operand `mult` for a0 * 12, the three address forms
 * (base + offset, (base + 4) + offset, (base + 8) + offset), the re-read of
 * D_001B1990 before every call, the copy of the results into the buffer and
 * the last call.
 *
 * What differs: the register allocation.  Retail keeps four callee-saved
 * registers (the base, the offset, the first and the second element address)
 * and re-materialises the address of D_001B1990 (`lui`/`lw`) before each of
 * the three uses; this cc1 keeps the address of D_001B1990 in a fifth
 * callee-saved register, so the frame holds five registers and ra, and the
 * `lui` appears once.  The instruction order of the prologue and of the
 * second and third elements follows from that.
 *
 * Tried: the record as a struct of three floats, as a float array indexed
 * with a0 * 3 + i, as three separate base pointers (that one gives the
 * retail's address forms but hoists base + 4 and base + 8 to the prologue and
 * needs five registers), as byte offsets a0 * 12 + 4 * i, the x array read
 * through a hard-coded address, and the index as a0 * 3 against a0 * 12.
 *
 * What would unblock it: a source shape where this cc1 rematerialises the
 * address of D_001B1990 instead of keeping it in a callee-saved register.
 *
 * Measured further (coordinator): reading the table through the literal
 * address 0x001B1990 does rematerialise the base at every use, but as the
 * constant (`lui $s1,0x0 ; ori $s1,$s1,0x1990`) and not as the address
 * (`lui $v0,0x1B ; lw $v0,0x1990($v0)`) the retail has, so the symbol is
 * needed for the form and the spelling for the re-materialisation; no
 * spelling gives both.
 */
#include "include_asm.h"

typedef int s32;

typedef unsigned char u8;

extern float *D_001B1990;
extern int D_001B20F0[];
extern float ref_L00_00261DD0_00[];
extern float func_00283B98(float a, float b);
extern void func_00283430(int *a, float *b);

void func_002E3478(int a0)
{
    float buf[3];

    ((float *)ref_L00_00261DD0_00)[a0 * 3] =
        func_00283B98(((float *)ref_L00_00261DD0_00)[a0 * 3], D_001B1990[a0 * 3]);
    ((float *)((char *)ref_L00_00261DD0_00 + 4))[a0 * 3] =
        func_00283B98(((float *)((char *)ref_L00_00261DD0_00 + 4))[a0 * 3], D_001B1990[a0 * 3 + 1]);
    ((float *)((char *)ref_L00_00261DD0_00 + 8))[a0 * 3] =
        func_00283B98(((float *)((char *)ref_L00_00261DD0_00 + 8))[a0 * 3], D_001B1990[a0 * 3 + 2]);
    buf[0] = ((float *)ref_L00_00261DD0_00)[a0 * 3];
    buf[1] = ((float *)((char *)ref_L00_00261DD0_00 + 4))[a0 * 3];
    buf[2] = ((float *)((char *)ref_L00_00261DD0_00 + 8))[a0 * 3];
    func_00283430(D_001B20F0, buf);
}
