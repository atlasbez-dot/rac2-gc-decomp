/* func_002E3BD8 (628 bytes, boot 0x2E3BD8, 28 places)
 *
 * Draft, not compiled: the body is decoded, the alloca and the float work are
 * not reproduced yet.
 *
 * The body: it is the twin of func_002E3998 - it takes the object pointer,
 * reads the count at +0 of the object, sizes the frame with
 * `(count + 0xF) >> 4 << 4` bytes (`subu $sp,$sp,$v0`), copies the frame
 * pointer into $fp and calls the VU0 routine func_002E4388 with the object +
 * 0x10 and the frame pointer.  It then writes the words 0x30000007 and 0x14
 * 9300 into the block at 0x1B22A8, reads a word through `$gp` (-0x3210) and
 * stores the difference, walks the 32-byte records with the count at +0x20 and
 * the halfword at +0x2E of the object, calls func_0029CF58 with the word at
 * 0x1B1CE8 and the scaled halfword, calls func_0029CF78 for the records that
 * are set, and finally calls the VU0 routines func_002E3E54 and func_002E3FA0
 * with the halfwords at +0x24, +0x26, +0x28, +0x2A and +0x2C of the record.
 * It ends with the two error strings.
 *
 * The unit has to be built with -G8: the body reads words through `$gp`
 * (-0x3210, -0x3218).
 *
 * What has to be reproduced: the alloca's shape, the eight calls and their
 * arguments, the `daddu` copies of the record's halfwords into $s1, $s2 and
 * $t0, and the two hand-written VU0 calls.
 *
 * What would unblock it: the alloca's shape and the argument setup of the two
 * VU0 calls (as in func_002E3998).
 */
extern void func_002E4388(void *, void *);
extern void func_002E3E54(void *, void *, void *, int);
extern void func_002E3FA0(void *, void *, void *, int);
extern void func_0029CF58(int, int);
extern void func_0029CF78(void);
extern void func_002FC560(int, unsigned long long);

void func_002E3BD8(void *object)
{
    int count = *(int *)object;

    func_002E4388((char *)object + 0x10, (void *)0);
    func_002FC560(0x47, 0x5360BULL);
    func_002FC560(0x4E, 0);
}
