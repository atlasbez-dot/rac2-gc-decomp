/* func_00304F28 - near miss (wave 3, worker 4)
 *
 * The whole body is recovered: with the compiler profile
 *
 *     -O2 -G0 -ffunction-sections -frac2-qcopy
 *
 * this source compiles to retail's exact 300 bytes, and from 0x304F8C on
 * every instruction matches the retail bytes.  What is left is the prologue's
 * register allocation and the shape of the branch that skips the "no motion"
 * case:
 *
 * retail                                  this source
 *   sd $s0,0x70($sp)  / sd $s3 / sd $s1     sd $s1 / sd $s3 / sd $s0
 *   daddu $s3,$a0,$zero (the object)        daddu $s3,$a0,$zero
 *   lw $s2,0x68($s3)  (the child)           lw $s2,0x68($s3)
 *   daddu $s0,$v0,$zero (the motion)        daddu $s1,$v0,$zero
 *   addiu $a1,$sp,0x10  (before the copy)   (in the call's delay slot)
 *   beql $s0,$zero,+0xB                     beqz $s1,+0xA
 *   lw $v1,0x68($s2)   (delay slot)         addiu $s0,$sp,0x30
 *
 * So the only real difference is that the motion pointer has to land in
 * $s0 (the buffer $sp+0x30 then takes $s0 over after the motion dies),
 * while this cc1 gives the motion $s1 and the buffer $s0.  Everything after
 * the branch matches, including the two copies of the buffer address that
 * retail rematerialises.
 *
 * Tried and measured (all with -frac2-qcopy):
 *   - the motion as float * and as char *: no change;
 *   - the motion and the child with initialisers instead of assignments: no change;
 *   - the buffer as a variable (`char *buf = &vec[12]`): the motion then takes
 *     $s0, but the object and the child change places ($s1/$s2 instead of
 *     $s2/$s3) and the function loses 4 bytes (one copy of the buffer less);
 *   - the buffer as a variable pointing at &vec[8]: 8 bytes too many, a fifth
 *     callee-saved register appears;
 *   - the scratch buffer as `char vec[112]` instead of `float vec[28]`: no change.
 *
 * What would unblock it: a source shape in which the call result of
 * func_002AB1F0 outranks the scratch buffer in the global allocator
 * (the motion is used twice, the buffer four times, so the crossing count
 * of the buffer decides), and a branch the front end predicts as taken
 * (retail's `beql`, this cc1 emits a plain `beq` for every `if`/`goto`
 * spelling measured: `if (x) {...}`, `if (!x) goto l;`, `if (x) {} else {...}`).
 *
 * The scratch buffer is one `float vec[28]`: its first 16 bytes hold the
 * 16-byte copy of the child's motion state (retail's `lq`/`sq`), then
 * &vec[4] (=$sp+0x10), &vec[8] (=$sp+0x20), &vec[12] (=$sp+0x30) and
 * &vec[16] (=$sp+0x40) are the four working buffers; &vec[8] is retail's
 * func_0029FCC0 output and func_00282CF0's third argument, &vec[12] the
 * buffer of func_00282D30, func_00282CC0, func_00282CF0 and func_00282F20.
 */

typedef int TI16 __attribute__((mode(TI)));

extern float *func_002AB1F0(char *object);
extern void func_002FE8D8(void *object, float *out);
extern void func_00282D30(char *local, void *value, float scale);
extern void func_00282CC0(void *out, void *a, void *b);
extern void func_0029FCC0(void *entity, int a, void *out);
extern void func_00282CF0(void *out, void *a, void *b);
extern void func_00282F20(char *out, char *in, float length);
extern void func_002836E8(float *out, float *in);
extern void func_00283098(void *out, void *a, void *b);

void func_00304F28(char *object)
{
    float vec[28];
    char *child = *(char **)(object + 0x68);
    float *motion = func_002AB1F0(*(char **)(child + 0x68));

    func_002FE8D8(object + 0x10, &vec[4]);
    *(TI16 *)&vec[0] = *(TI16 *)(*(char **)(child + 0x68) + 0x10);
    if (motion != 0) {
        func_00282D30((char *)&vec[12], *(char **)(child + 0x68) + 0xE0, *(float *)(motion + 0x10));
        func_00282CC0(&vec[0], &vec[0], &vec[12]);
    }
    if (*(char **)(child + 0x68) == 0
            || *(unsigned char *)(*(char **)(child + 0x68) + 0x20) == 0xFE
            || *(unsigned char *)(*(char **)(child + 0x68) + 0x20) == 0xFD
            || !(*(unsigned short *)(*(char **)(child + 0x68) + 0x34) & 0x1000)) {
        *(unsigned char *)(object + 0x20) = 3;
        *(char **)(child + 0x68) = 0;
        return;
    }
    func_0029FCC0(object, 0, &vec[8]);
    func_00282CF0(&vec[12], &vec[0], &vec[8]);
    func_00282F20(child + 0x20, (char *)&vec[12], 1.0f);
    func_002836E8(&vec[16], (float *)(object + 0xC0));
    func_00283098(child + 0x20, child + 0x20, &vec[16]);
}
