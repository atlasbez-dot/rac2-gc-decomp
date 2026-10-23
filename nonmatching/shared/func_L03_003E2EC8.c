/* func_L03_003E2EC8 (near miss, level 03 endako, 336 bytes at 8 places).
 *
 * Checked in the -G0 sibling (src/levels/shared/L03_003C5B28.c): the candidate
 * is 332 bytes against retail's 336, and the branch structure, the two calls
 * and the field accesses are retail's.  What is left:
 *
 *   - the field64 test: retail keeps a signed load (lh $v1,0x64($s0)) for the
 *     test and a separate unsigned one (lhu $a0,0x64($s0)) for the decrement,
 *     both before the branch; this cc1 shortens the test to the unsigned load
 *     and reuses it, so the branch comes one instruction earlier;
 *   - the field5E < 2 test: retail lays the "field5C = 0" block out of line
 *     (the branch is bnez to it) and the byte copy in the fall-through, this
 *     cc1 keeps the "field5C = 0" block in the fall-through and branches the
 *     other way (beqz);
 *   - the mark path's rotation: retail loads the field52 word inside the
 *     rotation (lhu $a0,0x52($s0)) and puts the field64 word in the branch's
 *     delay slot, this cc1 loads the field52 word in the delay slot instead
 *     and reloads the field64 word later.
 *
 * The addresses are the record's own: rec = *(u8 **)(a0 + 0x68).  The record's
 * fields are the half-words at 0x50, 0x52, 0x5C, 0x5E, 0x62 and 0x64, the words
 * at 0x48 and 0x4C, the half-word at 0x56 and the byte arrays the half-words
 * index (rec + field + 0x10, rec + field + 0x21, rec + field + 0x30, and the
 * byte at rec + 0x52).  The signed and unsigned loads of the same half-word
 * are both needed: retail reads 0x5C unsigned for the copy and signed for the
 * comparison, and 0x64 signed for the test and unsigned for the decrement.
 */

typedef unsigned char u8;

typedef unsigned int u32;

typedef short s16;

typedef unsigned short u16;

extern void func_L03_003E3308(u8 *);

extern void func_L03_003E3018(u8 *);

/* Moves the record's cursor on: when the record's own angle and the entity's
   angle differ it marks the entity and advances the cursor, otherwise it
   resets the entity's angle and steps the record's counters back. */
void func_L03_003E2EC8(u8 *a0) {
    u8 *rec = *(u8 **)(a0 + 0x68);

    if (*(s16 *)(rec + 0x52) == *(s16 *)(rec + 0x5C)) {
        *(u8 *)(rec + *(s16 *)(rec + 0x50) + 0x10) = 0;
        *(u8 *)(rec + *(s16 *)(rec + 0x5E)) = 0xFF;
        *(u16 *)(rec + 0x50) = *(u16 *)(rec + 0x5C);
        if (*(s16 *)(rec + 0x5E) < 2) {
            *(u16 *)(rec + 0x5C) = 0;
        } else {
            *(u16 *)(rec + 0x5C) = *(u8 *)(rec + *(s16 *)(rec + 0x5E) - 2);
        }
        *(u8 *)(rec + *(s16 *)(rec + 0x5E) + 0x30) = 0xFF;
        {
            int a = *(u16 *)(rec + 0x5E) - 1;
            int b = *(u16 *)(rec + 0x64) - 1;

            if (*(s16 *)(rec + 0x64) != 0) {
                *(u16 *)(rec + 0x5E) = a;
                *(u16 *)(rec + 0x64) = b;
            } else {
                *(u16 *)(rec + 0x62) = *(u16 *)(rec + 0x62) - 1;
            }
        }
    } else {
        *(u8 *)(rec + *(s16 *)(rec + 0x52) + 0x10) = 1;
        if (*(s16 *)(rec + 0x64) == 0 &&
            *(s16 *)(rec + 0x52) == *(u8 *)(rec + *(s16 *)(rec + 0x62) + 0x21)) {
            *(u16 *)(rec + 0x62) = *(u16 *)(rec + 0x62) + 1;
        } else {
            *(u16 *)(rec + 0x64) = *(u16 *)(rec + 0x64) + 1;
        }
        *(u16 *)(rec + 0x5C) = *(u16 *)(rec + 0x50);
        *(u16 *)(rec + 0x50) = *(u16 *)(rec + 0x52);
        {
            int e = *(u16 *)(rec + 0x5E) + 1;

            *(u8 *)(rec + (s16)e) = *(u8 *)(rec + 0x52);
            *(u16 *)(rec + 0x5E) = e;
        }
    }
    func_L03_003E3308(a0);
    *(u16 *)(rec + 0x56) = 0;
    *(u32 *)(rec + 0x48) = 0;
    func_L03_003E3018(a0);
    *(u32 *)(rec + 0x4C) = 0;
}
