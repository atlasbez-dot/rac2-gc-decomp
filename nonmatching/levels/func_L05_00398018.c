/* func_L05_00398018 (388 bytes, 4 places) -- NEAR MISS, not integrated.
   state: 372 bytes, the loop and the calls are recovered: the twenty-four entries of the
   table at 0x233560, the two exit tests (the handle at +0x6C and the flag at +0x70), the
   vector call and the three colour calls with their constants; what is left is the register
   allocation and the schedule.
   check.py (05_feltzin_system), with the source below:
     00398024  addiu $v0, $v0, 0x3560     |  addiu $v0, $v0, 0x3560
     00398034  addiu $s0, $v0, 0x30       |  addiu $s0, $v0, 0x30
     00398050  mtc1  $at, $f21            |  mtc1  $at, $f21
     00398054  mtc1  $zero, $f20          |  mtc1  $zero, $f20
     00398058  nop                       |  nop
     0039805C  nop                       |  daddu $a1, $s3, $zero  <- the base is set up early
   What is measured and right:
   - the table's address is the symbol D_L05_00233560; the state entry is that address
     plus 0x30, and both walk the table in steps of 0xB0.
   - the counter is raised at the head of the loop and the twenty-four limit is tested at
     the end, so the loop is a do-while.
   - the three colour calls take the float arguments in $f12, $f13 and $f14: the first is
     the result of func_002A7878 times 5.0, the second is 1.25, 1.24 and 1.23, the third
     is always 0.0.
   Tried and not enough: the counter at the head and at the end of the loop; the state
     pointer as a second symbol and as the base plus 0x30.
   Next idea: a lever that puts the base in $s3 and the counter in $s2, as retail does, and
   one that keeps the three colour calls' argument setup in retail's order. */

extern char D_L05_00233560[];

extern void func_L00_003F26C8(char *, char *);
extern float func_002A7878(float, float);
extern void func_00281EB8(void *, int, int, int, float, float, float);

/* Walks the table of twenty-four entries, and for each one the game keeps, lays the
   vector over it and the three colours over the result. */
void func_L05_00398018(char *arg0)
{
    char *s0;
    char *s3;
    int i;
    float f12;
    float f13;
    float f14;
    float f20;
    float f21;

    s3 = D_L05_00233560;
    s0 = s3 + 0x30;
    i = 0;
    f21 = 5.0f;
    f20 = 0.0f;
    do {
        i++;
        if (*(int *)(s0 + 0x6C) != (int)arg0)
            break;
        func_L00_003F26C8(arg0, s3);
        s3 += 0xB0;
        if (*(int *)(s0 + 0x70) != 0)
            break;
        f12 = func_002A7878(0.065f, 0.1f) * 5.0f;
        f13 = 1.25f;
        f14 = 0.0f;
        func_00281EB8(s0, 0x31, 0x3F00FFFF, 1, f12, f13, f14);
        f12 = func_002A7878(0.0325f, 0.06f) * 5.0f;
        f13 = 1.24f;
        f14 = 0.0f;
        func_00281EB8(s0, 0x31, 0x5F7F7F7F, 1, f12, f13, f14);
        f12 = func_002A7878(0.07f, 0.15f) * 5.0f;
        f13 = 1.23f;
        f14 = 0.0f;
        func_00281EB8(s0, 0x31, 0x1000003F, 1, f12, f13, f14);
        s0 += 0xB0;
    } while (i < 0x18);
}
