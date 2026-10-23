/* func_L00_002D23C0, 176 bytes, 27 placements.  ABANDON - two registers and a store order.
   Wave 8 w8-10: the draft below is now 176 bytes, the retail's exact size, and every
   instruction matches except three things:
   - the clamped comparison value is in $a2 here and in $a1 in the retail, and the
     caller's index is in $a3 here and in $a2 in the retail (one allocation step);
   - the `andi $a1,$v0,0xFF` sits before `sb $a1,0x40($s1)` here and after it in the
     retail, so $a1 is still live when the mask is computed here (the retail reuses the
     dead parameter's register);
   - the two byte stores come out 0x40 then 0x41, the retail has 0x41 then 0x40.

   What was measured (six source forms, all with the same size):
   - The clamped byte must be an `int`, not an `unsigned char`: with `unsigned char`
     the compiler masks the LEFT operand and emits `sltu`; with an `int` the mask stays
     on the right operand only and the comparison is the retail's signed `slt`
     (`andi $a1,$v0,0xFF` + `slt $a1,$v1,$a1`). This is the fix that took the body
     from 180 to 176 bytes.
   - The two index stores must be written 0x42 then 0x43 and BEFORE the call: this cc1
     reverses them and fills the `jal` delay slot with the last one, which is exactly
     the retail's `sb $a2,0x42($s1)` in the slot. Written the other way round, the
     0x43 store lands in the slot and the index has to stay live across the call (then
     it needs a callee-saved register and the body grows).
   - The order of the two byte stores (0x40/0x41) is fixed by the scheduler: this cc1
     always emits 0x40 then 0x41, the retail has 0x41 then 0x40. -fno-schedule-insns
     keeps the source order but moves the `jal` after `lui $s0,0x1B` and breaks the
     call sequence (180 bytes, wrong order).
   - The allocator tie between the index copy and the masked value is decided by the
     priority of the two pseudos (refs and live length); no declaration order tried
     moves the index into $a2.

   Unblocking: a source shape that leaves the mask after the 0x40 store (so $a1 is dead
   there) and that reverses the two byte stores. */

typedef int s32;
typedef unsigned char u8;

extern char *D_0018C0B0;
extern void func_00310498(void *);
extern int func_002A4DB0(void *, int, int, void *);
extern char D_001B4400[];

void func_L00_002D23C0(int a0, int a1)
{
    char *o = D_0018C0B0;
    s32 t;

    *(unsigned char *)(o + 0x41) = a1 + 1;
    *(unsigned char *)(o + 0x40) = a1;
    t = *(unsigned char *)(*(int *)(*(int *)(o + 0x24) + (a0 << 2) + 0x48) + 0x10) - 1;
    if (t < (unsigned char)(a1 + 1))
        *(unsigned char *)(o + 0x41) = t;
    *(int *)(o + 0x44) = 0;
    *(unsigned char *)(o + 0x42) = a0;
    *(unsigned char *)(o + 0x43) = a0;
    func_00310498(o);
    *(int *)(o + 0x58) = func_002A4DB0(o, *(unsigned char *)(o + 0x42),
                                       *(unsigned char *)(o + 0x40), D_001B4400);
    *(int *)(o + 0x5C) = func_002A4DB0(o, *(unsigned char *)(o + 0x43),
                                       *(unsigned char *)(o + 0x41), D_001B4400 + 0x600);
}
