/* Best attempt, wave 14 w8. Last check.py line:
   func_0031D268: 0 of 2 places match (src/game/003173B0.c)
   retail 156 bytes, produced 148: the first 25 instructions are exact (the %4 expansion,
   the beqz and its delay slot, the call setup), but the closing 16-byte copy differs.
   Retail materialises both addresses and uses the zero-displacement lq/sq pair:
       lw $v1,0x284($s0) ; lw $a0,0x278($s0) ; sll $v1,$v1,4 ; addu $v1,$v1,$s0
       addiu $a0,$a0,0x10 ; addiu $v1,$v1,0x3A0 ; lq $v0,0($a0) ; sq $v0,0($v1)
   while every spelling that computes the addresses after the call folds the offsets
   into the lq/sq (the CSE takes plus(reg,const) over the register).  The only
   spellings that keep the zero displacement compute the addresses before the call,
   and then the two values must live across the call: the frame grows to 0x20 and
   retail's is 0x10, and retail re-derives both addresses after the call.  See
   the note in the wave report: the retail body re-loads the index and the pointer
   after the call, so its source keeps only the context pointer in a register.
   Measured: 30 spellings of the tail (pointer variables, TI128* variables, the
   offsets split over two statements, left- and right-associated sums, 64-bit
   pointers, a temporary) - none reproduced the pair. */

typedef int Rac2TI128_0031D268 __attribute__((mode(TI)));

extern void func_002A91F0(void *, void *);

/* Advances the ring index in the owner's context block by one, wrapping it in four
   steps, and copies the owner's 16-byte block into the slot the index names. */
void func_0031D268(char *self)
{
    char *ctx = *(char **)(self + 0x68);
    int idx = *(int *)(ctx + 0x284);
    int count = *(int *)(ctx + 0x280);
    int next = idx + 1;
    char *src;
    char *dst;

    *(int *)(ctx + 0x288) = 0;
    *(int *)(ctx + 0x284) = next % 4;
    if (count < 4) {
        *(int *)(ctx + 0x280) = count + 1;
    }
    src = *(char **)(ctx + 0x278);
    dst = ctx + (*(int *)(ctx + 0x284) * 16 + 0x3A0);
    src = src + 0x10;
    func_002A91F0(ctx + (*(int *)(ctx + 0x284) * 16 + 0x4A0), self + 0xF0);
    *(Rac2TI128_0031D268 *)dst = *(Rac2TI128_0031D268 *)src;
}
