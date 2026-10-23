/* 0 of 16 places match - last line: 00_aranos_tutorial: 316 bytes, expected 356
 *
 * The level's per-object updater.  The body walks two tables indexed by the
 * first argument (a record of 32 bytes at D_001B2514 and a block of 64 bytes
 * at D_001B251C), then runs five float helpers of the boot code
 * (func_002EE5B0, func_002EE238 twice, func_002EE050 twice, func_002EE1A8,
 * func_002EE108) and writes three reciprocals back into the block.
 *
 * What was measured and works:
 *  - the two tables are read absolutely (`lui $a0,0x1B ; lw $a0,0x2514($a0)`),
 *    so they are plain globals, not sda ones;
 *  - the record's byte at 0x1D indexes the table at 0x226700, whose word is
 *    the object the float at 0x5C is multiplied with;
 *  - the three reciprocals are 1.0f divided by the value of a
 *    func_002EE238 call, and their stores land in the delay slots of the
 *    calls that follow.
 *
 * What still differs (40 bytes, ten instructions):
 *  - the retail copies the first argument into 64 bits first
 *    (`daddu $v1,$a0,$zero`) and scales that copy (`sll $v0,$v1,5` and
 *    `sll $v1,$v1,6`), while this cc1 scales the 32-bit argument and keeps
 *    the 64-bit copy of the second argument instead;
 *  - the frame is 0x50 in retail (it saves $s0-$s5 and $ra) against 0x60
 *    here: this candidate needs one more callee-saved register, because the
 *    record, the block and the three block offsets are live at the same time;
 *  - the order of the five float calls and the three reciprocals is a
 *    first guess: retail's schedule keeps $f21 for the first result and
 *    $f12/$f13 for the two others, with the first helper's result unused.
 */

extern int *D_001B2514;

extern int *D_001B251C;

extern int D_L00_00226700[];

extern float func_002EE5B0(long a0, long a1);

extern float func_002EE238(long a0);

extern float func_002EE050();

extern void func_002EE1A8(long a0, long a1, float f12);

extern void func_002EE108(long a0, long a1, long a2);

void func_L00_0036AE00(int index, int flag)
{
    int *rec = (int *)((char *)D_001B2514 + index * 32);
    int *blk = (int *)((char *)D_001B251C + index * 64);
    int *obj = D_L00_00226700[(unsigned char)rec[0x1D]];
    float f21;
    float f12;
    float f13;
    float f0;

    func_002EE5B0((long)rec, (long)((char *)obj + 0x50));
    f21 = func_002EE238((long)blk);
    f12 = f21;
    f13 = func_002EE050();
    f21 = func_002EE238((long)((char *)blk + 0x10));
    f13 = f21;
    f12 = f21;
    f0 = func_002EE050();

    f0 = (float)obj[0x5C] * f0;
    *(float *)((char *)rec + 0xC) = f0;
    func_002EE1A8((long)rec, (long)rec, *(float *)((char *)blk + 0x3C));
    func_002EE108((long)rec, (long)rec, (long)((char *)blk + 0x30));

    f0 = 1.0f / func_002EE238((long)blk);
    *(float *)((char *)blk + 0xC) = f0;
    f0 = 1.0f / func_002EE238((long)((char *)blk + 0x10));
    *(float *)((char *)blk + 0x1C) = f0;
    f21 = 1.0f / func_002EE238((long)((char *)blk + 0x20));
    *(float *)((char *)blk + 0x2C) = f21;

    if (flag != 0)
        *(unsigned char *)((char *)rec + 0x1E) = 1;
}
