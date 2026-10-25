/* Retained C for the 56-byte body at USA v1.01 0x002C38A8.
 * The generator now excludes the eight-byte preceding stack-restoration prefix,
 * preserving the original end and canonical name in all three releases.
 * Historical checks found the 56-byte C instruction-exact at all 28 USA places;
 * this retained draft has not been recompiled or integrated by the boundary fix.
 * Requalify with the current compiler, helper interfaces and strict linked builds
 * before claiming C coverage. The skipped bytes remain assembly.
 */
extern int func_00282978(short *);
extern void func_002B9180(void *);
void func_002C38A0(char *self)
{
    if (func_00282978((short *)(self + 10)) != 0)
        func_002B9180(self);
}
