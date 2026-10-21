/* func_003076F0 - near miss (wave 3, worker 4)
 *
 * The function is the twin of func_00304F28 (same shape, the child's motion
 * is at +0x64 instead of +0x68).  With the compiler profile
 *
 *     -O2 -G0 -ffunction-sections -frac2-qcopy
 *
 * this source compiles to retail's exact 276 bytes, and from 0x307764 on
 * every instruction matches the retail bytes.  What is left is the
 * prologue's register allocation and the branch that skips the "no motion"
 * case:
 *
 * retail                                  this source
 *   sd $s0,0x70($sp) / sd $s2,0x80         sd $s1,0x78 / sd $s3,0x88
 *   daddu $s2,$a0,$zero (the object)        daddu $s3,$a0,$zero
 *   lw $s3,0x68($s2) (the child)            lw $s2,0x68($s3)
 *   daddu $s0,$v0,$zero (the motion)        daddu $s1,$v0,$zero
 *   addiu $a1,$sp,0x10 (before the copy)    (in the call's delay slot)
 *   beql $s0,$zero,+0xB                     beqz $s1,+0xA
 *   lw $v1,0x64($s3)   (the delay slot)     addiu $s0,$sp,0x30
 *
 * So three things are missing: the motion pointer has to land in $s0 (the
 * buffer $sp+0x30 then takes $s0 over after the motion dies), the object has
 * to be in $s2 and the child in $s3 (this cc1 has them the other way round),
 * and the branch over the "no motion" block has to be the one the front end
 * predicts as taken.
 *
 * Tried and measured (all with -frac2-qcopy):
 *   - the scratch buffer as `float vec[28]` (the copy is its first 16 bytes)
 *     against five separate 16-byte locals: the array is the only shape that
 *     gives retail's frame (0xA0) and retail's buffer addresses;
 *   - the motion as float * and as char *, with initialisers instead of
 *     assignments: no change;
 *   - the buffer as a variable: the motion then takes $s0, but the object
 *     and the child change places and the function loses 4 bytes;
 *   - `if (motion == 0) goto skip;`, `if (motion == 0) {} else {...}` and
 *     `if (motion != 0) {...}`: all three compile to the same plain `beq`,
 *     never to retail's `beql`;
 *   - the scratch buffer as `char vec[112]`: no change.
 *
 * What would unblock it: the same three things as for func_00304F28 (the
 * motion's register, the object/child order and the branch hint).
 *
 * The buffers: &vec[0] (=$sp+0x00) is the 16-byte copy of the child's motion
 * state and the out buffer of func_00282CC0, &vec[4] (=$sp+0x10) is the out
 * buffer of func_002FE8D8, &vec[8] (=$sp+0x20) is the out buffer of
 * func_0029FCC0 and the third argument of func_00282CF0, &vec[12] (=$sp+0x30)
 * is the buffer of func_00282D30, func_00282CC0, func_00282CF0 and
 * func_00283098, and &vec[16] (=$sp+0x40) is the buffer of func_002836E8 and
 * func_00283098.
 */

typedef int TI16 __attribute__((mode(TI)));

extern float *func_002AB1F0(char *object);
extern void func_002FE8D8(void *object, float *out);
extern void func_00282D30(char *local, void *value, float scale);
extern void func_00282CC0(void *out, void *a, void *b);
extern void func_0029FCC0(void *entity, int a, void *out);
extern void func_00282CF0(void *out, void *a, void *b);
extern void func_002836E8(float *out, float *in);
extern void func_00283098(void *out, void *a, void *b);

void func_003076F0(char *object)
{
    float vec[28];
    char *child = *(char **)(object + 0x68);
    float *motion = func_002AB1F0(*(char **)(child + 0x64));

    func_002FE8D8(object + 0x10, &vec[4]);
    *(TI16 *)&vec[0] = *(TI16 *)(*(char **)(child + 0x64) + 0x10);
    if (motion != 0) {
        func_00282D30((char *)&vec[12], *(char **)(child + 0x64) + 0xE0, *(float *)(motion + 0x10));
        func_00282CC0(&vec[0], &vec[0], &vec[12]);
    }
    if (*(char **)(child + 0x64) == 0
            || *(unsigned char *)(*(char **)(child + 0x64) + 0x20) == 0xFE
            || *(unsigned char *)(*(char **)(child + 0x64) + 0x20) == 0xFD
            || !(*(unsigned short *)(*(char **)(child + 0x64) + 0x34) & 0x1000)) {
        *(unsigned char *)(object + 0x20) = 3;
        *(char **)(child + 0x64) = 0;
        return;
    }
    func_0029FCC0(object, 0, &vec[8]);
    func_00282CF0(&vec[12], &vec[0], &vec[8]);
    func_002836E8(&vec[16], (float *)(object + 0xC0));
    func_00283098(child + 0x20, &vec[12], &vec[16]);
}
