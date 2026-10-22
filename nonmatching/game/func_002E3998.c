/* func_002E3998 (572 bytes, boot 0x2E3998, 28 places)
 *
 * Draft, not compiled: the body is decoded, the alloca and the float work are
 * not reproduced yet.
 *
 * The body: it takes the object pointer, reads the count at +0 of the object
 * and sizes the frame with it: `(count + 0xF) >> 4 << 4` bytes are taken off
 * the stack (`subu $sp,$sp,$v0`), and the frame pointer is copied into $fp.  It
 * then calls the VU0 routine func_002E4388 with the object + 0x10 and the frame
 * pointer, writes the word 0x30000007 and the word 0x14 9300 into the block at
 * 0x1B22A8, reads a word through `$gp` (-0x3210) and stores the difference at
 * the same place, walks a table of 32-byte records with the count at +0x20 and
 * the halfword at +0x2E of the object, calls func_0029CF58 with the word at
 * 0x1B1CE8 and the scaled value, and for every record that is set it calls
 * func_0029CF78, then walks the records again, calls func_0029CF58 again, and
 * finally calls the VU0 routines func_002E3E54 and func_002E3FA0 with the
 * three halfwords at +0x24, +0x26, +0x28, +0x2A and +0x2C of the record and
 * the address 0x70002000.  It ends with two calls to func_002FC560 (the error
 * strings) and restores the frame.
 *
 * The unit has to be built with -G8: the body reads a word through `$gp`
 * (-0x3210, -0x3218, -0xCDB0).
 *
 * What has to be reproduced: the alloca (the frame size arithmetic and the
 * `subu $sp,$sp,$v0`), the `lq`/`sq` copies, the eight calls and the two
 * hand-written VU0 calls.
 *
 * What would unblock it: the alloca's shape - the retail computes the size
 * with `sll`/`srl`/`addiu`/`srl`/`sll`, which is the source's own arithmetic and
 * not the compiler's `alloca`, and the float/halfword arguments of the two VU0
 * calls.
 */
typedef short s16;

extern void func_002E4388(void *, void *);
extern void func_002E3E54(void *, void *, void *, int);
extern void func_002E3FA0(void *, void *, void *, int);
extern void func_0029CF58(int, int);
extern void func_0029CF78(void);
extern void func_002FC560(int, unsigned long long);

void func_002E3998(void *object)
{
    int count = *(int *)object;

    func_002E4388((char *)object + 0x10, (void *)0);
    func_002FC560(0x47, 0x5360BULL);
    func_002FC560(0x4E, 0);
}
