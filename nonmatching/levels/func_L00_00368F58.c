/* 0 of 27 places match - last line: 00_aranos_tutorial: 168 bytes, expected 176
 *
 * The clamp-and-scale body of func_L00_00368F58. Measured facts:
 *  - the three destinations are one 12-byte block at 0x001B24E0: declaring them as
 *    the array `float D_001B24E0[3]` and writing D_001B24E0[1], D_001B24E0[2] and
 *    D_001B24E0[0] reproduces retail's `addiu $v0,$v1,0x24E0` + `swc1 0x4/0x8($v0)`
 *    and the separate `swc1 $f0,0x24E0($v1)` - three separate globals give three
 *    separate `lui`s instead;
 *  - the 4.0f constant has to be assigned after the first clamp, or the compiler
 *    hoists its load above the division (retail loads it after the clamp);
 *  - retail's float schedule is value*4, 2*base, value*6, base*(value*4),
 *    (2*base)*value, base*(value*6) and stores the three results in that order;
 *    this cc1 schedules value*6 second and stores base*(value*6) second.
 *
 * What still differs (8 bytes, two instructions):
 *  - retail has `nop; nop` between `mtc1 $at,$f2` (1.0f) and `div.s $f4,$f1,$f0`;
 *    this cc1 never pads there, and the two nops are what pushes retail's
 *    `div.s` seven instructions below the `mtc1` that wrote $f1 (0.62f) where
 *    this candidate's division is five below;
 *  - the six 0.0f constant is loaded late in retail (between the base load and
 *    the first multiply) and early here.
 *
 * Wave 8 re-measured both with more spellings:
 *  - the two nops are not a hazard pad this cc1 can be talked into emitting:
 *    it emits none at that distance in any of the spellings tried, so they
 *    are part of retail's schedule and not something the source can ask for;
 *  - the 1.0f lands in $f5 here against retail's $f2.  Naming the 1.0f in a
 *    local moves it to $f2, but then the 4.0f is materialised too early and
 *    the whole float schedule changes; keeping the 4.0f late (as retail has
 *    it) keeps the 1.0f in $f5.  The two wants fight each other.
 */
extern float D_001BD370;

extern float D_001B24DC;

extern float D_001B24E0[];

extern void func_002EF080(int);

void func_L00_00368F58(int force)
{
    float value = 0.62f / D_001BD370;
    float four;
    float base;
    float fourValue;
    float sixValue;
    float twice;

    if (value < 1.0f)
        value = 1.0f;
    four = 4.0f;
    if (four < value)
        value = four;
    if (force)
        value = 1.0f;
    base = D_001B24DC;
    fourValue = value * four;
    twice = base + base;
    sixValue = value * 6.0f;
    D_001B24E0[1] = base * fourValue;
    D_001B24E0[2] = twice * value;
    D_001B24E0[0] = base * sixValue;
    func_002EF080(force);
}
