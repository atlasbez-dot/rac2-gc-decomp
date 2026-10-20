/* Near miss from src/levels/20_yeedil/L20_002DEBE0.c.

   The body has the retail's frame, the same calls in the same order, the same
   register assignment ($s3 <- the fourth argument, $s4 <- the third), the
   32-bit address arithmetic and the retail's return value (a pointer, so the
   epilogue's `daddu $v0,$s0,$zero`), but three things differ:

     - the two 16-byte copies: retail materialises the pointer first
       (`addiu $a0,$s0,0x10` / `sq $v0,0x0($a0)`, and `addiu $a1,$s0,0xF0` /
       `sq $zero,0x0($a1)`), this compiler folds the constant offset into the
       `sq` (`sq $v0,0x10($s0)`, `sq $zero,0xF0($s0)`);
     - the float constants (2.0f, 0.5f) are materialised just before their use
       in the retail, this compiler hoists them in front of the 16-byte copy;
     - the second call's delay slot holds the store to arg0+0x98, the retail
       has `addiu $a1,$s0,0xF0` there (and recomputes p+0xF0 for the call,
       because the call clobbers $a1).

   The copy is the wall, and it is a compiler-level one, not a source shape:
   the fold happens in the CSE pass, in `find_best_addr` (gcc/cse.c), which
   replaces a memory operand's address register with the equivalent expression
   recorded for it when that expression is not more expensive to address.  The
   cost comes from `mips_address_cost` (gcc/config/mips/mips.c): a plus of a
   register and a *small* constant (SMALL_INT: -0x8000..0x7FFF) costs 1, the
   same as a plain register, and the tie is broken in favour of the plus, so
   `p + 0x10` is folded into the `sq`.  The retail's compiler did not fold it.

   Tried: the address as a `char *`, an `int` and an `unsigned int`; the
   address computed inside and outside the `if (p)` block; the address used
   once and twice (for the copy and as the first argument of the call); the
   copy through a `volatile` TI128 pointer (the fold is not a CSE of the
   value, so volatile does not stop it); the address as a 64-bit value (the
   fold is then impossible - the memory operand's address mode is 32-bit - but
   the address computation becomes a 64-bit `daddu`/`daddiu` instead of the
   retail's 32-bit `addiu`, and the sign/zero extension of the 32-bit address
   costs two more instructions); the offset written so that it is not a small
   integer (`p - 0xFFF0`): the fold is then avoided, but the constant no
   longer fits in a signed 16-bit immediate, so the compiler puts it in a
   register (`addu $a0,$a0,$2`).

   So: a TI copy through a register needs an address that is not a register
   plus a small constant, and the retail's addresses here are exactly that. */

typedef int TI128 __attribute__((mode(TI)));

extern void *func_0029EFD0(int);

extern float func_002A89A8(void *, int, float);

extern void func_002833F0(void *, void *);

char *func_L20_0039BDF0(void *arg0, void *arg1, int arg2, int arg3)
{
    char *p;
    int addr;
    int addr2;
    int b;

    p = (char *)func_0029EFD0(0x12C2);
    if (p) {
        *(int *)(p + 0xB8) = (int)arg0;
        *(unsigned char *)(p + 0x30) = 0xFF;
        addr = (int)p + 0x10;
        *(TI128 *)addr = *(TI128 *)arg1;
        *(int *)(arg0 + 0x98) = 0;
        *(float *)(p + 0x18) = *(float *)(p + 0x18) + 2.0f;
        *(float *)(p + 0x18) = func_002A89A8((void *)addr, 0, 0.5f);
        addr2 = (int)p + 0xF0;
        *(TI128 *)addr2 = 0;
        b = *(int *)(p + 0xB8);
        *(int *)(b + 0x98) = *(int *)(*(int *)(b + 0x24) + 0x10);
        func_002833F0((void *)((int)p + 0xC0), (void *)addr2);
        b = *(int *)(p + 0x68);
        *(int *)(b + 0x4) = arg2;
        *(int *)(b + 0x8) = arg3;
    }
    return p;
}
