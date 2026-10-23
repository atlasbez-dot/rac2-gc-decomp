/* Near miss from src/levels/shared/L05_003D33E8-g8.c: 296 bytes, expected 292; 0 of 4 places.
   Kept as a starting point; not linked, not counted.

   The source unit needs -G8 (the level's global is reached through $gp). The frame, the
   float registers and the call sequence are right. What still differs against retail
   (level 05 at 0x00418D68):
   - retail saves $s2, $s3 and $s4 before $s0 and $s1 and interleaves the copies of the
     arguments with the saves; here $s0 is saved first and the copies of the arguments
     follow the saves as a group;
   - retail puts the argument setup of every call in the call's delay slot (daddu $a0,$s0,$zero
     after the first jal, mov.s $f12,$f24 after the third, daddu $a2,$s3,$zero after the
     fourth, daddu $a2,$s4,$zero after the fifth); here the scheduler fills those slots with
     the float arithmetic instead and keeps the argument setups as separate instructions;
   - the loop is rotated here: the "a0 = i" of the next iteration is computed at the end of
     the body, so one instruction more than retail, and the 16-byte copy of buf[0] into
     buf[1] lands in the delay slot of the first call instead of inside the loop.

   The 16-byte copy needs the two locals in one array (TI128 buf[2]): with two separate
   locals this compiler folds the copy out of the loop and then copies the other way.

   The level's global at 0x1B0FBC has to be named D_L05_001B0FBC (with
   __attribute__((sda))): with a ref_ name for it the $gp-relative access comes out with a
   zero offset (lw $a1,0x0($gp)) instead of the retail's 0x1FCC. The calls go to the boot's
   functions by their catalogue names. */

typedef int TI128 __attribute__((mode(TI)));

typedef int s32;

extern float func_00283CE0(s32);

extern float func_002A7940(void);

extern void func_002ACB48(void *, float);

extern void func_00281EB8(void *, int, int, int, float, float, float);

extern int D_L05_001B0FBC __attribute__((sda));

extern void func_00282CC0(void *, void *, void *);

void func_L05_00418D68(void *a0, void *a1, s32 a2, s32 a3, float f12, float f13, float f14)
{
    TI128 buf[2];
    float step;
    float p;
    float q;
    float scale;
    float angle;
    float dir;
    float len;
    s32 i;

    dir = f12;
    angle = f13;
    len = f14;
    buf[0] = *(TI128 *)a0;
    step = 1.0f / func_00283CE0(a2);
    for (i = 0; i < a2; i++) {
        p = func_00283CE0(i) * step;
        scale = angle - dir;
        scale = scale * p;
        scale = dir + scale;
        q = func_002A7940();
        buf[1] = buf[0];
        func_002ACB48(&buf[1], len);
        func_00281EB8(&buf[1], D_L05_001B0FBC, 1, a3, scale, 0.0f, q);
        func_00282CC0(&buf[0], &buf[0], a1);
    }
}
