/* Near miss from src/levels/14_aranos_prison/L14_00304190-g8.c - 300 bytes against retail's
 * 344; 85 of 86 words differ.
 *
 * Kept as a starting point; not linked, not counted.  This is a first reading of the body,
 * not a close attempt: three known walls stand between it and retail.
 *
 * What the body is:
 *   - the state is at self+0x68; its +0x7C is a flag and its +0x60 an index into a table
 *     of 0x80-byte entries that D_L14_001B268C (at $gp+0x369C) points to.  Retail reads
 *     the entry's float at +0x38 into $f12 in the branch delay slot, but the value is
 *     dead: the next instruction loads self's +0x70 over it.  The load of the table
 *     pointer and the table read are therefore dead in the C as well, and this cc1
 *     removes them (retail keeps them: the $gp load, the sll, the addu, the branch and
 *     the lwc1 are five words this cc1 does not emit).
 *   - the first call is func_3254B8(self+0x18, state+0x74, state->f70, 0.0011111111f,
 *     0.0022222222f, 1.0f) - the constants are 0x3A91A2B4 and 0x3B11A2B4.
 *   - then a 16-byte record is built on the stack: twelve zero bytes and the state's
 *     +0x74 float at the record's +8.  Retail materialises the zero in $v0
 *     (`por $v0,$zero,$zero`) and stores the register (`sq $v0,0x10($sp)`); this cc1
 *     folds the store to `sq $zero` - the same wall the sibling func_L14_00304190 hits.
 *     The record is then copied to the outgoing argument area (`lq $v0,0x10($sp)` and
 *     `sq $v0,0x0($sp)`) and passed as $a1 = sp.
 *   - then the ring of the group's own entries (D_00188660, 0x70 bytes each) is stepped:
 *     when the state's +0x74 float is above 0.01f, the entry at the state's +0x78 is
 *     looked up and, if this object owns it and the entry is free, a new one is asked
 *     for with func_369AD0(0, 4, self); at the end the entry is released with
 *     func_3697D0 when the object does not own it and the entry is in use, and the
 *     state's +0x78 is set to -1.
 *
 * The last part is the same shape as the matched func_L14_003E4A40 (the owner test is
 * the other way round here: the call needs the owner to be this object).
 *
 * The frame is 0x30 here against retail's 0x40: retail keeps the record at +0x10 and its
 * copy in the outgoing area at +0x0, this cc1 keeps one record at +0x0 and passes its
 * address.
 *
 * The walls, in the order they block:
 *   1. the dead table read has to survive dead-code elimination, which needs the
 *      source to spell it as a volatile read (the game's compiler kept it plain);
 *   2. the zero record has to be stored as a register pair (`por`+`sq`), which this
 *      cc1 folds to `sq $zero`;
 *   3. the record has to be copied to the outgoing area, which needs the callee to take
 *      the record by value while the caller hands it a pointer.
 *
 * Not tried yet: the 16-byte record as a TI128 local spelled as a union with two
 * `long long`s, and the table read as a volatile float.
 */
typedef struct {
    char pad[0x38];
    float f;
} L14Entry;

typedef int TI128 __attribute__((mode(TI)));

typedef union {
    TI128 i;
    float f[4];
} L14Quad;

extern L14Entry *D_L14_001B268C __attribute__((sda));
extern char D_00188660[];
extern void func_3254B8(void *a0, void *a1, float a2, float a3, float a4, float a5);
extern void func_328DA8(void *a0, TI128 b, void *a2, void *a3);
extern float func_2F5B78(float a);
extern int func_369AD0(int a0, int a1, char *a2);
extern void func_3697D0(int a0);

void func_L14_003DF6A0(char *self) {
    char *s0 = *(char **)(self + 0x68);
    L14Quad b;
    float f12;
    int idx;

    if (*(int *)(s0 + 0x7C) != 0) {
        f12 = D_L14_001B268C[*(int *)(s0 + 0x60)].f;
    }
    f12 = *(float *)(s0 + 0x70);
    func_3254B8(self + 0x18, s0 + 0x74, f12, 0.0011111111f, 0.0022222222f, 1.0f);
    b.i = 0;
    b.f[2] = *(float *)(s0 + 0x74);
    func_328DA8(s0 + 0x20, b.i, self + 0xF0, self + 0xF0);
    if (0.01f < func_2F5B78(*(float *)(s0 + 0x74))) {
        char *e = D_00188660 + *(int *)(s0 + 0x78) * 0x70;

        if (*(int *)(e + 0x88) == (int)self && *(unsigned char *)(e + 0x74) == 0) {
            *(int *)(s0 + 0x78) = func_369AD0(0, 4, self);
        }
    }
    idx = *(int *)(s0 + 0x78);
    if (idx != -1) {
        char *e = D_00188660 + idx * 0x70;

        if (*(int *)(e + 0x88) != (int)self && *(unsigned char *)(e + 0x74) != 0) {
            func_3697D0(idx);
        }
    }
    *(int *)(s0 + 0x78) = -1;
}
