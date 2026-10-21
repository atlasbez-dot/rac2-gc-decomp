/* NEAR MISS — 168 bytes emitted, 164 expected (one instruction too many).
 * last check.py line: "14_aranos_prison: 168 bytes, expected 164"
 *
 * Everything matches except the constant 1: retail materialises it ONCE
 *   00425C58 addiu $t0,$zero,0x1
 *   00425C88 sb    $t0,0x31($v1)      ; the field write
 *   00425C8C jal   func_32BC08        ; ... and $t0 is also argument 5
 * whereas this compiler rematerialises it for the field write (`addiu $v0,$zero,0x1;
 * sb $v0,0x31($v1)`), costing one word. Tried: the literal 1 in both places, a shared
 * `int one = 1;` local, and both statement orders (store-then-call and call-then-store).
 * The early-return path carrying `daddu $v0,$v1,$zero` in the bne delay slot is reproduced,
 * as is the multiple reload of *(s0+0x120) between stores.
 */

/* --- wave 24, worker 04 (2026-10-21) --------------------------------------------
   Re-measured: 164 bytes, 39 of 41 words identical; the fault is the scheduler's
   order in the store block.  The prologue, the 0xFE/0xFD test, the
   func_0029EFD0 allocation, the four field copies and the func_002AF1D0 call
   all match word for word; only the placement of the `addiu $t0,1` (the
   constant for the 0x31 store) and of the lhu/sh pair differs.  Retail's order
   inside the block is sw, lhu, addiu(t0), daddu(a0), addiu(a2), sh, daddu(a3);
   ours emits addiu(t0) first and keeps the lhu next to its sh.  The C below is
   the one that reaches 164 bytes (the earlier draft was 168).
   What I added to the measurements:
   - the state byte at +0x20 must be read UNSIGNED: with a signed char the two
     comparisons against 0xFE/0xFD fold to false and the whole test disappears
     (38 words, measured).
   - the copies after the first one must go through the slot (s0+0x120), not
     through the local pointer: that is what gives retail's four reloads of the
     slot; a local pointer gives two and the body is 8 bytes short.
   - func_002AF1D0 takes four arguments (object, state, 2, 0).
   Last check.py line: "14_aranos_prison: instruction at +0x48 differs". */

extern void *func_0029EFD0(int size);
extern void func_002AF1D0(char *a, char *b, int c, int d);

void *func_L14_00425C08(char *a0)
{
    char *s1;
    char *s0;
    char *v1;

    s1 = a0;
    s0 = *(char **)(a0 + 0x68);
    v1 = *(char **)(s0 + 0x120);
    if (v1 == 0 || *(unsigned char *)(v1 + 0x20) == 0xFE || *(unsigned char *)(v1 + 0x20) == 0xFD) {
        v1 = (char *)func_0029EFD0(0x1142);
        if (v1 != 0) {
            *(char **)(s0 + 0x120) = v1;
            *(unsigned short *)(v1 + 0x32) = *(unsigned short *)(a0 + 0x32);
            *(unsigned char *)(*(char **)(s0 + 0x120) + 0x30) = *(unsigned char *)(a0 + 0x30);
            *(unsigned long long *)(*(char **)(s0 + 0x120) + 0x38) = *(unsigned long long *)(a0 + 0x38);
            *(unsigned char *)(*(char **)(s0 + 0x120) + 0x31) = 1;
            func_002AF1D0(a0, *(char **)(s0 + 0x120), 2, 0);
        }
        return *(char **)(s0 + 0x120);
    }
    return v1;
}
