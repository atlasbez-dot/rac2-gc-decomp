/* Near miss: the C body reproduces the retail byte for byte, but the catalogue
   extent is eight bytes too long.

   func_002C1E50, boot 0x002C1E50, catalogue size 160 (0xA0).

   The retail bytes are

       002c1e50  addiu $sp,$sp,0x50     <- the SDK compiler's prologue group
       002c1e54  nop
       002c1e58  addiu $sp,$sp,-0x20    <- the real frame setup
       ...                                (the body, 152 bytes)
       002c1eec  addiu $sp,$sp,0x20

   The eight bytes at 0x002C1E50 are the SDK 3.01 compiler's positive stack
   adjustment; our cc1 emits a single `subu $sp,$sp,frame` for a frame of this
   size, so it cannot produce them.  Every boot function whose extent opens on
   `addiu $sp,$sp,+N ; nop` shows the same group, and in every level copy of
   this function the same eight bytes stand in the same place, so they are
   part of the compiled body and not alignment filler.

   Compiling this C gives 152 bytes; the retail body from 0x002C1E58 on is
   identical, instruction for instruction.  tools/check.py reports
   "152 bytes, expected 160" at every one of the 27 places.

   What would unblock it: the eight-byte prologue group.  If the catalogue
   extent started at 0x002C1E58 (the real prologue) this C would match, and
   the same holds for the seven other rows that open on the group.

   Tried: the `while`/`continue`, `if`/`else` and `goto` spellings of the
   loop, a local copy of the flag byte, and the `if (...) goto body;` recipe
   from docs/COMPILER-NOTES.md.  The body matches in every spelling; only the
   prologue group is missing.
*/

extern void func_00282CC0_17(char *dst, char *src, char *vec);
extern float func_00283CE0_2(int v);
extern float func_00282C48(float);
extern int func_00283D38_3(int handle, int previous, float ratio);
extern int func_00282978(short *);
extern void func_002B9180(char *);

/* Copies the sub-object's vector over the object's, adds the two stored floats to a
   lookup of the halfword at offset 10, packs the result into the word at offset 4
   and removes the object when the halfword helper says so. */
void func_002C1E50(char *self)
{
    char *motion = self + 0x20;
    float f;

    *(unsigned char *)(self + 8) = *(unsigned char *)(self + 8) + *(unsigned char *)(motion + 0x1C);
    func_00282CC0_17(self + 0x10, self + 0x10, motion);
    f = func_00283CE0_2(*(short *)(self + 0xA));
    f = f * *(float *)(motion + 0x10) - 1.0f;
    f = func_00282C48(f);
    *(int *)(self + 4) = func_00283D38_3(*(int *)(motion + 0x18), *(int *)(motion + 0x14), f);
    if (func_00282978((short *)(self + 0xA)) != 0)
        func_002B9180(self);
}
