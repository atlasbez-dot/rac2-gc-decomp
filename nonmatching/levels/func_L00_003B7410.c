/* func_L00_003B7410 (152 bytes, 27 places) -- NEAR MISS, not integrated.

   New measurement (wave 12, worker s4): the 128-bit copies *are* reachable from
   plain C - `typedef int TI128 __attribute__((mode(TI)));` gives retail's `lq`/`sq`
   pair, and the whole body (the four pointer copies, the two stores into the
   record, the `func_31A658(o, 2, -1)` call) comes out in retail's shape.

   What is left is one word: retail materialises the destination of the first
   copy in a register (`addiu $a0, $s0, 0x10` ; `sq $v0, 0($a0)`) where this cc1
   folds the constant offset into the `sq` (`sq $v0, 0x10($s0)`), so the candidate
   is 148 bytes against retail's 152.  This is the cost tie in cse that
   docs/COMPILER-NOTES.md records for the constant destination offset: the pointer
   only comes out materialised when it is used twice or the offset is a variable.
   Eight spellings measured (the destination as `char *` / `TI128 *`, the copy
   through a local temporary, the destination declared inside the block, the
   offset through a local variable, the copy written without a temporary): every
   one of them folds the offset.  The second copy (to `o->f68`, a loaded pointer)
   is materialised correctly in all of them.

   The four arguments are pointers: retail copies each of them with
   `daddu $sX, $aY, $zero`, and the fourth (stored into the record's byte at +0xBC)
   is a pointer too, not an int.

   Wave 12 (worker s4). */
typedef struct NODE {
    char pad0[0x8];
    int f08;
    int f0C;
    char pad1[0x24 - 0x10];
    int f24;
    int f28;
    int f2C;
    unsigned char f30;
    char pad2[0x40 - 0x31];
    int f40;
    char pad3[0x68 - 0x44];
    void *f68;
    char pad4[0xB8 - 0x6C];
    int fB8;
    unsigned char fBC;
} NODE;

typedef int TI128 __attribute__((mode(TI)));

extern NODE *func_3100D8();

extern void func_31A658();

void *func_L00_003B7410(char *a0, void *a1, void *a2, void *a3)
{
    NODE *o = func_3100D8(0x88D);
    TI128 t;

    if (o != 0) {
        char *d = (char *)o + 0x10;
        void *s = o->f68;

        o->fB8 = (int)a0;
        o->f30 = 0xFF;
        o->fBC = (unsigned char)a3;
        t = *(TI128 *)a1;
        *(TI128 *)d = t;
        t = *(TI128 *)a2;
        *(TI128 *)s = t;
        func_31A658(o, 2, -1);
    }
    return o;
}
