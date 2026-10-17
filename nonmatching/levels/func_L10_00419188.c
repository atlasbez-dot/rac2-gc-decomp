/* 0 of 1 places match - last line: 10_hrugis_cloud: 84 bytes, expected 96.
   ROW IS EIGHT BYTES TOO LONG. The candidate walks the same list as func_L10_00417440 with the
   store value 2; it compiles to 84 bytes and retail's real body is 88 (0x419188..0x4191E0:
   `lbu 0x21/$a0`, the lui/addiu table at 0x1FB1E0, `beqz` to the shared epilogue, then the
   lhu/lh pair loop). The row claims 0x419188+0x60 and the extra eight bytes are an UNREACHABLE
   second epilogue `jr $ra; nop` at 0x4191E0 - both the `beqz` and the loop exit reach 0x4191D8
   - and the next catalogue row (func_L10_004191E8) starts exactly at 0x4191E8. Maintainer data:
   re-cut the row to 0x58.
   Independently, the candidate is four bytes short of even the 88-byte body: the cc1 loads the
   table entry into $a0 where retail loads into $v0 and copies with `daddu $a0,$v0,$zero` in the
   `beqz` delay slot, and it hoists the `lui` of the D_001B251C address where retail rebuilds it
   inside the loop - the same two traits as func_L10_00417440 above.
   Below: the whole candidate (declarations as used in src/levels/10_hrugis_cloud/L10_003170D0.c). */

extern u16 *D_L10_001FB1E0[];
extern u8 *D_001B251C;

void func_L10_00419188(u8 *arg0)
{
    u16 *q = D_L10_001FB1E0[arg0[0x21]];

    if (q != 0) {
        do {
            *(u8 *)(D_001B251C + ((*q & 0x7FFF) << 8) + 0x20) = 2;
        } while (*(s16 *)q++ >= 0);
    }
}
