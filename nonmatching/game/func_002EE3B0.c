/* func_002EE3B0 (608 bytes, boot 0x2EE3B0, 28 places)
 *
 * Draft, not compiled: the body is decoded, the type chain is not reproduced yet.
 *
 * The body: it takes the owner pointer, asks func_002ED688 for the object and
 * returns when there is none or when the word at +0x10 of the object is zero.
 * It then calls func_002EE6A8 on the owner and switches on the result: the
 * retail tests it against 3, 1, 0xD, 2, 5, 0xC and more, and each arm loads a
 * float constant (0x3ED55556, 0x3ECCCCEC, 0x3E088889, 0x3BA3D70A and more) and
 * jumps to the tail, which computes with the object's fields and calls the
 * float helpers.  The unit has to be built with -G8: the body has thirteen
 * `$gp` accesses.
 *
 * What has to be reproduced: the chain of comparisons on the type (the retail
 * uses `bne` against a value loaded with `addiu` and a `b` to the next arm),
 * the float constant of each arm and the FPU register it is built in, and the
 * tail.
 *
 * What would unblock it: a `switch` spelling that this cc1 lays out as the
 * retail's chain of `bne`/`b` (the level 20 wave found the `switch` keeps the
 * retail shape where an if/else chain does not), and the float constants'
 * register allocation.
 */
extern int func_002ED688(unsigned char *);
extern int func_002EE6A8(unsigned char *);

void func_002EE3B0(unsigned char *owner)
{
    char *obj = (char *)func_002ED688(owner);
    int type;

    if (obj == 0)
        return;
    if (*(int *)(obj + 0x10) == 0)
        return;
    type = func_002EE6A8(owner);
    switch (type) {
    case 3:
    case 1:
    case 0xD:
    case 2:
    case 5:
    case 0xC:
        break;
    }
}
