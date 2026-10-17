/* 0 of 19 places match - last line: 00_aranos_tutorial: 160 bytes, expected 164
   The whole body is recovered and 40 of 41 words are byte-identical, register
   allocation included ($s0=a1, $s1=a0, $s2=index, $s3=out). The missing word is a
   LOAD-DELAY nop the pinned chain never emits (docs/COMPILER-NOTES.md, "a nop before
   jr $ra is a wall: the pinned compiler emits the compact three-instruction form"):
     retail  lwc1 $f12,0x8($s0) ; nop ; div.s $f12,$f12,$f21
     ours    lwc1 $f12,0x8($s0) ; div.s $f12,$f12,$f21
   cc1 does emit the marker there (`l.s $f12,8($16)` / `#nop` / `div.s` in the .s), and
   the object loses it (one word short, everything after shifts up by 4). Six head
   spellings measured (quotient in a local, declared-then-assigned locals, factor in a
   local, all-inline, a0[2] in a local): all 160.
   Key decode of the body (this is what the previous 172-byte draft missed): the second
   0x00283CE0 call takes (index*index + index) >> 1, and on the R5900 cc1 emits that
   product as the three-operand `mult $v0,$s2,$s2` (opcode 0x00 funct 0x18 with rd=$v0,
   word 0x02521018) whose rd is the low product - the `addu $a0,$v0,$s2` that follows
   consumes it, and `sra $a0,$a0,1` halves it. func_00283CF0 is the float->int cast
   helper (result in $v0), func_00283CE0 the int->float one (result in $f0). */

typedef float f32;
typedef int s32;

extern int func_00283CF0(float);
extern float func_00283CE0(int);

f32 func_L00_0031B9F8(const f32 *a0, const f32 *a1, s32 *a2, f32 factor) {
    s32 index = func_00283CF0(a1[2] / factor);
    f32 first = func_00283CE0(index);
    f32 second = func_00283CE0((index * index + index) >> 1);
    f32 result = a0[2] + a1[2] * first - second * factor;

    if (a2 != 0)
        *a2 = index;
    return result;
}
