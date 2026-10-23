/* func_L03_003E2C08 (near miss, level 03 endako, 396 bytes at 8 places).
 *
 * First pass: the candidate below compiles to 344 bytes against retail's 396,
 * so the walk, the arms and the calls are not yet retail's.  More important,
 * two of its arms branch OUTSIDE its own catalogue extent, into
 * func_L03_003E2D98's extent (0x2D98 + 304 bytes).  That is a catalogue
 * observation, not something C can fix: the two rows look like one body with a
 * shared tail, so a candidate here needs the shared block named (and the
 * catalogue corrected) before it can be placed.
 *
 * What the retail does, measured from the bytes:
 *   - the count comes from a $gp word at 0x1B0B50 (the offset 0x1B60 from
 *     $gp = 0x1AEFF0), so the unit needs a -G8 sibling;
 *   - the table's base is materialised as 0x29BCD0 (lui $v0,0x2A /
 *     addiu $s5,$v0,-0x4330) and the entries are sixteen bytes: a type word,
 *     the two results and a fourth word, all three of them set to -1 before
 *     the walk;
 *   - the entry's type word selects the arm: 1, 2 and 3 call
 *     func_L03_003E2D98 (entity, rec[i] + 0x20, i, 0, 0) and then a second
 *     call whose fourth argument points at a stack slot and whose fifth
 *     argument is $t0; 0 and anything above 3 skip the call;
 *   - the two arms for the types 1 and 2 branch to 0x2E50 and 0x2E44, which
 *     are inside func_L03_003E2D98's extent (0x2D98 + 0x130), so the two
 *     catalogue rows share a tail.
 *
 * The table's address differs from level to level, so it needs a ref_ name
 * (ref_L03_003E2C08_00) rather than a D_L03_ address.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 type;
    u32 r0;
    u32 r1;
    u32 flag;
} Entry;

extern u32 D_L03_001B0B50 __attribute__((sda));

extern Entry *ref_L03_003E2C08_00;

extern u32 func_L03_003E2D98(u8 *, u32, u32, u32 *, u32);

void func_L03_003E2C08(u8 *a0) {
    u8 *rec = *(u8 **)(a0 + 0x68);
    u32 count = D_L03_001B0B50;
    Entry *e = ref_L03_003E2C08_00;
    s32 i;
    u32 sv;

    for (i = 0; i < count; i++) {
        u8 *ent = (u8 *)(rec + i);
        u32 kind = e->type;

        e->r0 = -1;
        e->r1 = -1;
        e->flag = -1;
        switch (kind) {
        case 1:
            e->r0 = func_L03_003E2D98(a0, ent[0x20], i, 0, 0);
            break;
        case 2:
            e->r0 = func_L03_003E2D98(a0, ent[0x20], i, 0, 0);
            sv = e->r0;
            e->r1 = func_L03_003E2D98(a0, sv, i, &sv, 0);
            break;
        case 3:
            e->r0 = func_L03_003E2D98(a0, ent[0x20], i, 0, 0);
            sv = e->r0;
            e->r1 = func_L03_003E2D98(a0, ent[0x20], i, &sv, 1);
            break;
        }
        e++;
    }
}
