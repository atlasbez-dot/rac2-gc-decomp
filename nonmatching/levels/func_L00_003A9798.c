/* func_L00_003A9798 (332 bytes, 27 places) -- NEAR MISS, not integrated.
   state: 324 bytes against retail's 332; the body is recovered, the schedule is not.

   The unit needs its own profile, in a file of its own:
     src/levels/shared/L00_003A9798.c
       -O2 -G0 -ffunction-sections -mno-split-addresses -frac2-qcopy
   and the marker in src/levels/shared/L00_003A8E28.c becomes a comment.

   check.py (00_aranos_tutorial) with the source below:
     func_L00_003A9798: 0 of 27 places match (src/levels/shared/L00_003A9798.c)
     00_aranos_tutorial: 324 bytes, expected 332

   What is measured and right:
   - the body is decoded. The record the level's builder takes is a 36-byte struct on
     the stack: a 16-byte direction copied from a1 with lq/sq, the object pointer at
     +0x10, the word 0x81000000 at +0x14, the kind bytes 3 and 2 at +0x18/+0x19, the
     object's halfword at +0x1A, the length at +0x1C and the count 1 at +0x20; then
     func_2EE3D0(&s, &s, 1.0f) normalises it, the direction's w is overwritten with
     5627.9248046875f (0x45AFDF66) and the record is handed to func_2E10E8.
   - the table is the level's 224-byte records at D_L00_00262570, indexed by the
     resident byte D_00139568[0x19]; the record's flag byte at +4 selects the kind
     (0x46 or 0x19) the sparks are made with, and the spark list is the words at
     D_L00_001C3280.
   - -mno-split-addresses is required: retail reads the index with
     `lui $v0,0x14 ; lbu $v1,-0x6A7F($v0)`, the %hi of D_00139568 with the index
     folded into the %lo, while the default profile materialises the address
     (`lui ; addiu ; lbu 0x19`) and adds an instruction.
   - -frac2-qcopy is required: retail keeps the lq/sq pair together, and the profile
     does too; without it the copy is split and the schedule differs.
   - the float constant 0x45AFDF66 (5627.9248046875f) is materialised as
     `lui $at,0x45AF ; ori $at,$at,0xDF66 ; mtc1 $at,$f0`, exactly as retail does.
   - the loop is the countdown the retail shows: `blez count,end ; s0=count ;
     ... ; s0-- ; bne s0,zero,loop`, which a `for (i = 0; i < count; i++)` produces.

   What is left (both are schedule, not code):
   - the twelve instructions that fill the record come out in the same order but
     moved: retail keeps them in source order (the length load, the four stores, the
     lq/sq pair, the 1.0f, the call's argument setup), this cc1 hoists the call's
     argument setup and the 1.0f to the top of the body and sinks the lq/sq pair
     between the stores.
   - the first loop's `lw $a0,0x0($s1)` keeps retail's empty delay slot (a nop);
     this cc1 fills it with the next instruction. The second loop's load does get a
     filled delay slot in retail, so the two differ in retail too.
   - the registers differ throughout the tail (retail reuses $v0 for the three %hi
     values, this cc1 uses $a2/$v0/$a0).

   Tried and not enough: the copy as a mode(TI) assignment and as a 16-byte struct
   assignment (identical code); the length load as a separate statement (identical
   code); two names for the spark table (D_L00_001C3280 and D_L00_001C3280_1) so
   that each loop materialises the address again (no change); `while (count--)` (the
   compiler then uses a -1 sentinel and a $s3 of its own, and the frame grows to
   0x60); the count check as `if (count > 0) { do {...} while (--count); }` (the
   check moves onto the copy, the retail checks the call's result in $a1).
   Next idea: the record's stores and the call's argument setup have to land in
   source order; nothing tried so far makes this cc1 keep them there. */

extern void func_2E10E8(int, int, int, int, float);

extern void func_2EE3D0(void *, void *, float);

extern void func_3F8AD0(int, int, int);

extern int D_0018C0B0;

extern unsigned char D_00139568[];

extern unsigned char D_L00_00262570[];

extern unsigned int D_L00_001C3280[];

typedef int TI128 __attribute__((mode(TI)));

#ifndef RAC2_T_TRAIL_3A9798
#define RAC2_T_TRAIL_3A9798
typedef struct {
    float pos[4];
    unsigned int obj;
    unsigned int magic;
    unsigned char kind;
    unsigned char kind2;
    unsigned short id;
    float len;
    unsigned int count;
} Trail_3A9798;
#endif

#ifndef RAC2_T_ENTRY262570
#define RAC2_T_ENTRY262570
typedef struct {
    unsigned char pad0[4];
    unsigned char flag;
} Entry262570;
#endif

void func_L00_003A9798(char *a0, char *a1, char *a2)
{
    Trail_3A9798 s;
    int count;
    int i;
    unsigned int *p;
    Entry262570 *e;

    s.magic = 0x81000000;
    s.len = *(float *)(a1 + 0x18);
    s.count = 1;
    s.obj = (unsigned int)a0;
    *(TI128 *)s.pos = *(TI128 *)a1;
    func_2EE3D0(&s, &s, 1.0f);
    s.kind = 3;
    s.pos[3] = 5627.9248046875f;
    s.kind2 = 2;
    s.id = *(unsigned short *)(a0 + 0xAA);
    count = func_2E10E8((int)a2, 1, D_0018C0B0, &s, 6.0f);
    e = (Entry262570 *)(D_L00_00262570 + D_00139568[0x19] * 224);
    if (e->flag != 0) {
        p = D_L00_001C3280;
        for (i = 0; i < count; i++)
            func_3F8AD0(*p++, 0x46, *(int *)(a0 + 0xB8));
    } else {
        p = D_L00_001C3280;
        for (i = 0; i < count; i++)
            func_3F8AD0(*p++, 0x19, *(int *)(a0 + 0xB8));
    }
}
