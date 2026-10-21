/* func_L09_004082D0, 420 bytes, 1 placement (level 9, 0x004082D0).  Best candidate 420
   bytes - the retail's size - with 46 of its 105 words byte-identical.

   The body: the resident word D_L09_001B2388 gates the whole function (the retail
   skips everything when it is below 5), the object's byte +0x30 is set to 0xFF, the
   16 bytes of a position are copied to the stack - the hero's at 0x00189EA0 or the
   level's own at 0x001B9A00, chosen by the sub-object's byte +0xBE - and the object's
   state byte +0x95 says whether the sub-object's four slots are searched for a record
   (through func_325E78) at all.  The counter +0xBC is then bumped into the state byte
   +0x20, and the two id lists the sub-object holds are walked: the 28 entries at +0x10
   through func_L09_00408250, the 13 at +0x84 through func_L09_004081F0.

   What is the retail's, byte for byte, in this candidate: the frame (0x50), the
   `lui $v0,0x1B ; lw $v0,0x2388($v0)` that reads the gate word, the eight saved
   registers, the `slti`/`bnez` pair that guards the body, the 16-byte copy through
   `lq`/`sq`, both tail loops with their call argument lists and their delay slots, and
   the epilogue.

   What is left, and what would unblock it:

   - The state byte's test.  The retail branches on it - `bne $v1,$v0` with
     `daddu $s4,$zero,$zero` in the delay slot and `addiu $s4,$zero,0x1` after it - and
     this cc1 computes it as a boolean (`xori $v0,$v1,0x1 ; sltiu $s4,$v0,0x1`): the
     "if (c) x = 1; else x = 0" shape is merged into a value by this cc1 whatever the
     source says.  Measured spellings: the if/else, the else-if chain, the switch
     (which keeps the comparison as a register compare but lays the cases out
     differently), the ternary, the early `flag = 0` in the same block and in an outer
     one.  All of them merge.  What would unblock it: the source expression tree, so
     that the comparison stays a branch and the constant 1 stays in a register.
   - The 16-byte copy.  The retail keeps the address in $v1
     (`lui $v1,0x1C ; addiu $v1,$v1,-0x6600 ; lui $v1,0x19 ; addiu $v1,$v1,-0x6160 ;
     lq $v0,0($v1) ; sq $v0,0($sp)`), this cc1 puts it in $v0 (`lq $v0,0($v0)`) and
     moves the `sq` into the delay slot of the state test.  The same wall as
     func_L00_00396288, func_L02_003CED70 and func_L20_00449338.
   - The flag's zero initialisation is scheduled early (at +0x1C), so the prologue
     carries one instruction more than the retail's and $s4 is saved second against the
     retail's fourth; the 0xFF constant lands in $v1 against the retail's $v0.
   - The scan of the four slots.  The retail uses `beql` with the pointer increment in
     the annulled slot (`lw $a1,0($s0) ; beql $a1,$s5,... ; addiu $s0,$s0,0x4`) and the
     reset `daddu $s0,$s3,$zero` at the branch target; this cc1 branches normally and
     puts the reset in the next branch's delay slot.  The two pointer increments also
     land in different slots than the retail's, and the loop's set-up (the counter, the
     -1, the pointer) comes out in another order.
   - The tail block (the +0xBC and +0x20 bytes) is restructured by the flow pass: the
     retail keeps one shared "if (a0[0x20] != 0) return" test for both arms of the
     flag, this cc1 gives each arm its own test.

   The gate word is read through `__attribute__((sda))` in this -G0 unit, which is what
   gives the retail's `lui $r,%hi(X)` / `lw $r,%lo(X)($r)` form (docs/COMPILER-NOTES.md,
   "the temporary in the destination register").  Without the attribute the load is
   split over two registers and the %hi is hoisted above the frame setup. */

typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern s32 D_L09_001B2388 __attribute__((sda));

extern char D_L09_00189EA0[];
extern char D_L09_001B9A00[];

extern s32 func_325E78(char *a0, s32 a1);
extern void func_L09_00408250(char *a0, char *a1, s32 a2, s32 a3);
extern void func_L09_004081F0(char *a0, s32 a1, char *a2, s32 a3);

/* 128-bit copies reach lq/sq only through TImode. */
typedef int TQ_L09_004082D0 __attribute__((mode(TI)));

void func_L09_004082D0(u8 *a0) {
    char *s3;
    TQ_L09_004082D0 *src;
    s32 *p;
    s32 *q;
    s32 i;
    s32 r;
    s32 flag = 0;
    TQ_L09_004082D0 buf;

    if (D_L09_001B2388 >= 5) {
        s3 = *(char **)(a0 + 0x68);
        a0[0x30] = 0xFF;
        if (*(s8 *)(s3 + 0xBE) != 0) {
            src = (TQ_L09_004082D0 *)D_L09_001B9A00;
        } else {
            src = (TQ_L09_004082D0 *)D_L09_00189EA0;
        }
        buf = *src;
        if (a0[0x95] == 0) {
            for (i = 0, p = (s32 *)s3; i < 4; i++) {
                s32 v = *p;
                p++;
                if (v == -1) {
                    p = (s32 *)s3;
                    continue;
                }
                r = func_325E78((char *)&buf, v);
                p++;
                if (r == 0) {
                    continue;
                }
                flag = 1;
                break;
            }
        } else if (a0[0x95] == 1) {
            flag = 1;
        } else {
            flag = 0;
        }
        if (flag) {
            if (a0[0xBC] != 0) {
                if (a0[0x20] != 0) {
                    return;
                }
            }
            a0[0xBC] = 1;
        } else {
            if (a0[0x20] != 0) {
                a0[0xBC] = a0[0x20];
            } else {
                a0[0xBC] = 0;
            }
        }
        a0[0x20] = a0[0xBC] + 1;
        p = (s32 *)(s3 + 0x10);
        for (i = 28; i >= 0; i--) {
            s32 v = *p;
            if (v != -1) {
                func_L09_00408250(a0, s3, v, flag);
            }
            p++;
        }
        q = (s32 *)(s3 + 0x84);
        for (i = 13; i >= 0; i--) {
            s32 v = *q;
            if (v != -1) {
                func_L09_004081F0(a0, v, s3, flag);
            }
            q++;
        }
    }
}
