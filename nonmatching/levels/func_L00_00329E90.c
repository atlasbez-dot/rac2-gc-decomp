/* func_L00_00329E90 - 348 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x00329e90. Measured with tools/check.py --diff in the private
   checker root (2026-10-22): 284 of 348 bytes in the compiled object.

   What the retail does (level 04_barlow, 0x0034CE48):
     - the level keeps two slots of 0xA430 bytes at the boot data
       D_00281D20 (the first word of a slot is a callback, the second the
       entity id) and a counter D_L00_001A902C that says which slot is
       current (0 or 1);
     - the loop reads the counter, takes that slot, and compares the
       slot's id with the entity's id (the halfword at entity+0xAA): a
       free slot (id -1) or the entity's own slot ends the search, a slot
       held by somebody else flips the counter to (counter+1)%2 and the
       search is repeated, at most twice;
     - the found slot gets the entity's id and the callback, and the
       counter ends at (counter+1)%2;
     - when both slots are taken by others, the callback stored in the
       current slot is called with the slot's address and the slot is
       overwritten the same way;
     - the counter is written in two addressing forms in the same body:
       absolutely (`lui $at,0x1B ; sw $a0,-0x6FD4($at)`) and $gp-relative
       (`sw $v0,-0x5FC4($gp)`), and both forms address 0x001A902C.

   What this cc1 does with the C below:
     - the two addressing forms need two names for one address: a plain
       `extern int D_L00_001A902C;` is addressed absolutely, and
       `extern int D_L00_001A902C_1 __attribute__((sda));` is addressed
       $gp-relative (both in a unit compiled with -G8; in a -G0 unit the
       sda attribute also gives the $gp form). The sda name has to be a
       second name: the build reads each name's value from the retail
       bytes under its own relocation, so the plain and the sda name end
       at different link-time values that address the same byte;
     - retail keeps the counter's load inside the loop and reads it a
       second time in the found path; cc1 hoists both the load and the
       (counter+1)%2 out of the loop as soon as the loop does not store
       to the counter itself. Declaring the counter volatile keeps the
       loads where retail has them, but it also changes the block layout
       and the register allocation (the measured body is 284 bytes
       against retail's 348);
     - retail's branch polarity (beql to the found block) and its
       separate base+4 register for the id field are not reproduced.

   What would unblock it: the source spelling that makes the counter's
   store and its load visible to the loop-invariant pass (so that neither
   is hoisted) without the volatile, and the one that keeps the counter's
   two addressing forms apart in the source the way retail's body has
   them. */

extern volatile int D_L00_001A902C;
extern int D_L00_001A902C_1 __attribute__((sda));

/* The two slots the level's resident records live in, and the counter
   that says which of them is the current one. */
typedef struct {
    int callback;
    int id;
    char pad[0xA430 - 8];
} Rec_00281D20;

typedef void (*Callback_00281D20)(Rec_00281D20 *);

extern Rec_00281D20 D_00281D20[];

void func_L00_00329E90(void *entity, int callback, int *out) {
    int id = *(short *)((char *)entity + 0xAA);
    int tries = 0;
    int g;
    int v;
    Rec_00281D20 *rec;

    for (;;) {
        g = D_L00_001A902C;
        rec = &D_00281D20[g];
        v = rec->id;
        if (v == -1) {
            v = ~v;
            goto found;
        }
        v = ~v;
        if (v != id)
            goto other;
    found:
        *out = (v != 0);
        rec->id = id;
        rec->callback = callback;
        goto finish;
    other:
        tries++;
        D_L00_001A902C_1 = (g + 1) % 2;
        if (tries < 2)
            continue;
        rec = &D_00281D20[D_L00_001A902C_1];
        if (rec->callback != 0) {
            ((Callback_00281D20)rec->callback)(rec);
            rec = &D_00281D20[D_L00_001A902C];
        }
        *out = 0;
        rec->id = id;
        rec->callback = callback;
    finish:
        D_L00_001A902C = (D_L00_001A902C + 1) % 2;
        return;
    }
}
