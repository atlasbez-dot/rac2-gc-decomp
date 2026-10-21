/* func_L20_00310E38 (1212 bytes, 303 instructions, level 20 only) -- MAPPING,
   not integrated.

   This body reaches small data through $gp (seven accesses), so it belongs in
   the -G8 unit: src/levels/20_yeedil/L20_002DEBE0-g8.c.  The marker is back
   in place there.

   WHAT IT IS.  The yeedil level's per-object update: it walks an array of
   objects, marks the ones that need a re-init, and then runs the level's
   "one shot" set-up when the level's own state asks for it.  It is not a
   dispatch and has no jump table: one loop over the objects, then a straight
   tail.

   THE PROLOGUE (0x00310E38 .. 0x00310E94):

     0x00310E38  addiu  $sp,$sp,-0xE0        the frame is 0xE0
     0x00310E3C  sd     $s1,0x88($sp)        the saved GPRs $s0..$s7 and $ra
     0x00310E40  sd     $s7,0xB8($sp)        at 0x80..0xC0, and $f20 at 0xD0
     0x00310E44  daddu  $s1,$zero,$zero      $s1 = the loop counter (0)
     0x00310E48  sd     $s0,0x80($sp)
     0x00310E4C  sd     $s2,0x90($sp)
     0x00310E50  sd     $s3,0x98($sp)
     0x00310E54  sd     $s4,0xA0($sp)
     0x00310E58  sd     $s5,0xA8($sp)
     0x00310E5C  sd     $s6,0xB0($sp)
     0x00310E60  sd     $ra,0xC0($sp)
     0x00310E64  jal    func_00310BD0        the level's set-up, called first
     0x00310E68  swc1   $f20,0xD0($sp)
     0x00310E6C  lui    $v1,%hi(D_1BDCC0)   the 64-bit address of the level
     0x00310E70  daddu  $s7,$v1,$zero       state (D_1BDCC0)
     0x00310E74  addiu  $v1,$v1,%lo(D_1BDCC0)
     0x00310E78  lh     $v0,0x44($v1)       the level's counter at +0x44
     0x00310E7C  blezl  $v0,...             if it is <= 0, skip the whole loop
     0x00310E80  lw     $v1,-0x7600($gp)     = 0x001A79F0, the object array
     0x00310E84  daddu  $s3,$v1,$zero       $s3 = its 64-bit address
     0x00310E88  addiu  $s6,$zero,0xE29     the three type constants:
     0x00310E8C  addiu  $s5,$zero,0xD54       0xE29, 0xD54, 0xFA0
     0x00310E90  addiu  $s4,$zero,0xFA0
     0x00310E94  addiu  $s2,$s3,0x18C       $s2 = &array[0x18C]

   THE LOOP (0x00310E98 .. 0x00310F20).  It walks the pointers at
   $s3+0x18C, and for each object:

     0x00310E98  lw     $s0,0x0($s2)        the object pointer
     0x00310E9C  beqz   $s0,...             skip a null one
     0x00310EA0  lh     $v0,0xAA($s0)       its type at +0xAA
     0x00310EA4  bne    $v0,$s6,...         0xE29 -> the "reset" path
     0x00310EAC  lhu    $v0,0x34($s0)       its flags at +0x34
     0x00310EB0  ori    $v0,$v0,0x800       set the 0x800 flag
     0x00310EB4  sh     $v0,0x34($s0)
     0x00310EBC  bne    $v0,$s5,...         0xD54 -> the other path
     0x00310EC4  jal    func_00375EE0       a per-object call
     0x00310ECC  beql   $s0,$zero,...       a null object -> the end
     0x00310ED4  lh     $v0,0xAA($s0)
     0x00310ED8  bnel   $v0,$s4,...         0xFA0 -> the end
     0x00310EE0  lw     $a1,0x68($s0)       its field at +0x68
     0x00310EE4  beqz   $a1,...             no field -> skip
     0x00310EEC  lui    $a2,0x80AAAAD2      two float constants in a2/a3
     0x00310EF4  lui    $a3,0x80396464
     0x00310EFC  mtc1   $at,$f12            0x3D7A35E0
     0x00310F00  addiu  $a1,$a1,0xC
     0x00310F08  jal    func_0033AE48       the "spawn" call
     0x00310F14  addiu  $s1,$s1,0x1        the counter
     0x00310F18  slt     $v0,$s1,$v0         against the level's counter
     0x00310F1C  bnez   $v0,0x00310E98      the loop back edge

   AFTER THE LOOP (0x00310F24 .. 0x003112C8).  The level's own state decides
   what happens next:

     0x00310F24  addiu  $v0,$a1,-0x4        the state at +0x30 is 0 or 1?
     0x00310F28  sltiu  $v0,$v0,0x2
     0x00310F2C  beqz   $v0,0x00311144       yes -> a different path
     0x00310F34  lw     $a2,0x19C($a0)
     0x00310F44  daddu  $s5,$v0,$zero       $s5 = the 64-bit D_00189E20
     0x00310F60  bne    $a1,$v0,...         the state 4 -> another path
     0x00310F68  sw     $v0,0x5C0($v1)      D_00189E20[0x5C0] = the field
     0x00310F74  lw     $s0,-0x5BBC($gp)    three small globals
     0x00310F7C  lw     $s3,-0x5BB8($gp)
     0x00310F80  lw     $s0,-0x5BB4($gp)
     0x00310F88  lw     $s3,-0x5BB0($gp)
     0x00310F8C  addiu  $s4,$s7,%lo(D_1BDCC0)
     0x00310F94  lw     $v1,0x34($s4)       the level's state at +0x34
     0x003110A8  por    $v0,$zero,$zero     a 128-bit zero for the local
     0x003110C4  sq     $v0,0x70($sp)
     0x003110E0  jal    func_00302728       the local at sp+0x70 is set up
     0x003110E4  jal    func_00302260       and copied
     0x003110F4  jal    func_00302290
     0x00311118  jal    func_00302548
     0x0031112C  jal    func_00420850
     0x003111DC  jal    func_0033AE90
     0x00311238  jal    func_00302260
     0x00311280  jal    func_0041A018       the level's big set-up call

   THE CALLS: 20 in all, to 17 distinct callees - func_00310BD0, func_00375EE0,
   func_0033AE48, func_00301FE8, func_00326488, func_00302D50, func_00326528,
   func_00302548, func_00302260, func_003B4240, func_003B4440, func_002FAE78,
   func_00302728, func_00302290, func_00420850, func_0033AE90, func_0041A018.

   THE $gp ACCESSES (seven, which is why the body needs -G8):

     0x00310E80  lw $v1,-0x7600($gp)   = 0x001A79F0
     0x00310F74  lw $s0,-0x5BBC($gp)   = 0x001A9434
     0x00310F7C  lw $s3,-0x5BB8($gp)   = 0x001A9438
     0x00310F80  lw $s0,-0x5BB4($gp)   = 0x001A943C
     0x00310F88  lw $s3,-0x5BB0($gp)   = 0x001A9440
     0x003111CC  lw $v1,-0x5BC0($gp)   = 0x001A9430
     0x00311210  lw $v0,-0x5BC0($gp)   = 0x001A9430

   The 128-bit zero at 0x003110A8 (`por $v0,$zero,$zero ; sq $v0,0x70($sp)`)
   is the same 128-bit zero store the compiler profile folds to `sq $zero`
   whenever the register is dead after the store (see the note in
   nonmatching/levels/func_L20_0039BB18.c): here the zero feeds only one
   store, so the por is likely to be lost the same way.

*/

   ------------------------------------------------------------------
   2026-10-21, worker 13 of the level-20 wave (wave 5): the map, finer.

   THE FRAME.  0xE0.  The saved GPRs are at 0x80..0xB8 ($s0..$s7), $ra at
   0xC0 and $f20 at 0xD0.  The prologue's order is

       0x00310E3C  sd    $s1, 0x88($sp)
       0x00310E40  sd    $s7, 0xB8($sp)
       0x00310E44  daddu $s1, $zero, $zero     $s1 = 0, the loop counter
       0x00310E48  sd    $s0, 0x80($sp)
       0x00310E4C  sd    $s2, 0x90($sp)
       ...
       0x00310E60  sd    $ra, 0xC0($sp)
       0x00310E64  jal   f_00310BD0            func_L00_002FC980()
       0x00310E68   swc1  $f20, 0xD0($sp)

   ($s1 = 0 and $s7 = the state pointer are set BEFORE the saves of
   $s0..$s6: the frame-save-first patch keeps the frame's instructions in
   emission order, and the two sets come first in the source.)

   THE LEVEL STATE.  $s7 is the 64-bit address of D_1BDCC0; the code uses
   the 32-bit half in $v1 (`addiu $v1,$v1,%lo(D_1BDCC0)`) and the 64-bit
   half in $s7 (`daddu $s7,$v1,$zero`), the two forms of GCC's `la`.
   The state's counter is at +0x44 (a SIGNED short: `lh`), its mode at
   +0x30, its state at +0x34, its "other" pointer at +0x1A8, its two
   counters at +0x1B4 and +0x1B8, and its field at +0x19C.

   THE FIRST LOOP (0x00310E98 .. 0x00310F20).  $s3 is the 64-bit address
   of the object array (D_001A79F0, at -0x7600($gp)) and $s2 walks the
   pointers at +0x18C.  The body, per object:

       0x00310E98  lw    $s0, 0x0($s2)        the object
       0x00310E9C  beqz  $s0, .L00310EBC
       0x00310EA0   lh    $v0, 0xAA($s0)      its type (a signed short)
       0x00310EA4  bne   $v0, $s6, .L00310EBC   (0xE29?)
       0x00310EA8   nop
       0x00310EAC  lhu   $v0, 0x34($s0)      its flags
       0x00310EB0  ori   $v0, $v0, 0x800     set the 0x800 flag
       0x00310EB4  sh    $v0, 0x34($s0)
       0x00310EB8  lh    $v0, 0xAA($s0)      the type, read again
       .L00310EBC:
       0x00310EBC  bne   $v0, $s5, .L00310ECC   (0xD54?)
       0x00310EC0   nop
       0x00310EC4  jal   f_00375EE0             func_002E64A0(object)
       0x00310EC8   daddu $a0, $s0, $zero
       .L00310ECC:
       0x00310ECC  beql  $s0, $zero, .L00310F14  a null object ends the loop
       0x00310ED0   lh    $v0, 0x44($s3)
       0x00310ED4  lh    $v0, 0xAA($s0)
       0x00310ED8  bnel  $v0, $s4, .L00310F14   (0xFA0?) ends the loop
       0x00310EDC   lh    $v0, 0x44($s3)
       0x00310EE0  lw    $a1, 0x68($s0)      its field
       0x00310EE4  beqz  $a1, .L00310F10
       0x00310EE8   daddu $a0, $s0, $zero
       0x00310EEC  lui   $a2, 0x80AAAAD2     two float halves
       0x00310EF0  lui   $a3, 0x80396464
       0x00310EF4  lui   $at, 0x3D7A35E0
       0x00310EF8   ori   $at, $at, 0x35E0
       0x00310EFC  mtc1  $at, $f12
       0x00310F00  addiu $a1, $a1, 0xC
       0x00310F04   ori   $a2, $a2, 0xAAAAD2
       0x00310F08  jal   f_0033AE48             func_L00_00326048(...)
       0x00310F0C   ori   $a3, $a3, 0x396464
       .L00310F10:
       0x00310F10  lh    $v0, 0x44($s3)      the level's counter
       .L00310F14:
       0x00310F14  addiu $s1, $s1, 0x1
       0x00310F18  slt   $v0, $s1, $v0       SIGNED: the counter is an int
       0x00310F1C  bnez  $v0, 0x00310E98
       0x00310F20   addiu $s2, $s2, 0x4

   The three constants are materialised in $s6 (0xE29), $s5 (0xD54) and
   $s4 (0xFA0), before the loop.  The call's three float arguments are
   0x80AAAAD2 and 0x80396464 (as two 32-bit words in $a2 and $a3) and
   0x3D7A35E0 in $f12.

   AFTER THE LOOP (0x00310F24 .. 0x003112C8), in this order:

     0x00310F24  the array's first word (D_001A79F0) is compared with 0x14
     0x00310F38  the state's mode at +0x30: `(mode - 4) < 2` (the two
                 states 4 and 5)
     0x00310F4C  D_00189E20 is reached as `lui`/`addiu` (the 32-bit half
                 in $v1) and as `daddu $s5,$v0,$zero` (the 64-bit half)
     0x00310F60  the mode 4 -> D_00189E20[0x5C0] = the field at +0x19C,
                 and the two counters at +0x1B4 and +0x1B8 are read; the
                 mode 5 -> the pointer at +0x1A8
     0x00310F74  four small globals through $gp (-0x5BBC, -0x5BB8,
                 -0x5BB4, -0x5BB0 = 0x001A9434, 0x001A9438, 0x001A943C,
                 0x001A9440)
     0x00310F8C  the state's +0x34 against the first of them; if it is
                 equal, func_00301FE8 is called with D_1C6AE0 and 0x50,
                 D_001AF3B0 is set to 1 and 0.2f (0x3F4CCCCD) is stored
                 at D_1C6AE0+0x24
     0x00310FD0  the two comparisons that decide whether the object is
                 updated
     0x00310FE0  func_00326488, func_00302D50 (D_18A550), func_00326528
                 (12.0f, 0.1f), func_00302548, func_00302260, func_003B4240,
                 func_003B4440, func_002FAE78 (f_003B4BA0)
     0x00311080  the state's +0x30 == 5 and its +0x34 == the third small
                 global, then the 16-byte local at sp+0x70 is built
     0x003110A8  por $v0,$zero,$zero ; sq $v0,0x70($sp)   (the zero)
     0x003110CC  swc1 $f0,0x70($sp)   18.0f  (0x41900000)
     0x003110D4  swc1 $f1,0x74($sp)   -2.5f  (0xC0200000)
     0x003110DC  swc1 $f20,0x78($sp)  1.0f   (0x3F800000)
     0x003110E0  func_00302728, func_00302260, func_00302290,
                 func_00302548, func_00420850
     0x0031113C  D_00189E20[0x5C0] = 0 (the "nothing changed" path)
     0x00311148  the state's mode at +0x30: `(mode - 2) < 3` (the modes
                 2, 3 and 4) and its counter at +0x44
     0x00311180  THE SECOND LOOP, over the same array: the type at +0xAA
                 is read as an UNSIGNED short (`lhu`), `(type - 0xD0E) < 2`
                 selects the types 0xD0E and 0xD0F, and 0x7C is set to
                 0x3FF or 0x0F; then the type is compared with 0xCE0 and
                 the mode with 3, and func_0033AE90 is called
     0x003111FC  the state's mode == 3 and its +0x34 == the small global
                 at -0x5BC0 (0x001A9430): a 16-byte copy of the field at
                 +0x198+0x10 into sp+0x20, then func_00302260, then
                 func_0041A018 (with 1.0f and 20.0f), then D_1B9E80's
                 fields (0x3DB851EC at +0x160, 0x37 at +0x168, 0x3DA3D70A
                 at +0x180, 0x46 at +0x188)

   THE LOCALS.  sp+0x20 (16 bytes, the copy), sp+0x60 (16 bytes), sp+0x70
   (the 16-byte vector: 18.0f, -2.5f, 1.0f and a zero word), and the
   saved registers above 0x80.

   THE FLOAT CONSTANTS: 0x41900000 (18.0f), 0xC0200000 (-2.5f),
   0x3F800000 (1.0f), 0x3F4CCCCD (0.2f), 0x41400000 (12.0f),
   0x3D8F5C29 (0.1f), 0x3DB851EC (0.09f), 0x3DA3D70A (0.08f),
   0x41A00000 (20.0f), 0x3D7A35E0, 0x80AAAAD2 and 0x80396464.

   ------------------------------------------------------------------
   2026-10-21, worker 13 of the level-20 wave (wave 5): THE FIRST C.

   The attempt below is the first C this body has.  It follows the map
   above and gets the body STRUCTURE right (the first loop, the tail's
   phases, the second loop, the last block), but it is 88 bytes SHORT of
   the retail ("tools/check.py func_L20_00310E38: 1124 bytes, expected
   1212") and the order of the instructions is still the attempt's.

   WHAT IS STILL WRONG, in the order the diff shows it:

     1. THE FRAME is 0x70, the retail's is 0xE0.  The retail's locals are
        the 16 bytes at sp+0x20, the 16 bytes at sp+0x60 and the 16 bytes
        at sp+0x70 (the vector 18.0f, -2.5f, 1.0f), and the saved
        registers start at 0x80.  The attempt declares one 16-byte local
        and one 16-byte local, so the frame is half the size; the three
        locals the retail has are the ones the tail uses (the copy at
        sp+0x20, the vector at sp+0x60 and the vector at sp+0x70).

     2. THE SPLIT 64-BIT ADDRESS (the known wall).  The retail keeps
        D_1BDCC0's address twice: the 32-bit half in $v1
        (`addiu $v1,$v1,%lo(D_1BDCC0)`) and the 64-bit half in $s7
        (`daddu $s7,$v1,$zero`), and every later use of the 64-bit form
        adds the %lo again (`addiu $a0,$s7,%lo(D_1BDCC0)`).  The attempt
        emits the plain 32-bit form and the address is computed once.

     3. THE OBJECT ARRAY is read through $gp in the retail
        (`lw $v1,-0x7600($gp)` = 0x001A79F0) and its 64-bit address is
        kept in $s3 (`daddu $s3,$v1,$zero`); the attempt takes the array
        through a pointer.

     4. THE LOOP'S BRANCH-LIKELYs.  The retail's two "skip the rest of
        the body" branches are branch-LIKELYs (`beql $s0,$zero` and
        `bnel $v0,$s4`) whose delay slot holds the RELOAD of the level's
        counter (`lh $v0,0x44($s3)`); the delay slot is annulled when the
        branch is taken, so the counter is not reloaded on that path.
        The attempt emits plain branches with the reload in the delay
        slot of the branch that follows.

     5. THE 128-BIT ZERO (the wall of the project's
        rac2_fold_zero_ti_store) and THE 128-BIT COPY at the end
        (`addiu $v1,$v1,0x10 ; lq $v0,0x0($v1) ; sq $v0,0x0($s0)`, the
        address materialised - the shape this compiler only gives for a
        plain pointer, a symbol or a stack slot, so the copy has to be
        written so that the source's address is a stack slot).

   The attempt is in the -G8 unit (the body reaches D_001A79F0 and the
   four small globals through $gp), and it needs the level's data named
   D_L20_001BDCC0, D_L20_001C6AE0, D_L20_001B9E80, D_L20_001B9FC0,
   D_L20_001BA1F0 and the boot's D_001A79F0, D_001A9430..D_001A9440,
   D_0018A550, D_001AF3B0 and D_00189E20.


/* func_L20_00310E38: the level's per-object update (see
   nonmatching/levels/func_L20_00310E38.c for the map and the walls). */

typedef union {
    TI128 q;
    float f[4];
} L20_00310E38_V4;

typedef struct {
    char pad00[0x30];
    int mode;
    int state;
    char pad38[0x0C];
    short counter;
    char pad46[0x152];
    void *f198;
    int f19C;
    char pad1A0[0x8];
    void *f1A8;
    char pad1AC[0x8];
    int f1B4;
    int f1B8;
} L20_00310E38_State;

typedef struct {
    char pad00[0x24];
    float f24;
} L20_00310E38_C6AE0;

typedef struct {
    char pad00[0x160];
    float f160;
    int f164;
    int f168;
    int f16C;
    char pad170[0x10];
    float f180;
    char pad184[0x4];
    int f188;
} L20_00310E38_B9E80;

extern L20_00310E38_State D_L20_001BDCC0;

extern L20_00310E38_C6AE0 D_L20_001C6AE0;

extern L20_00310E38_B9E80 D_L20_001B9E80;

extern int D_L20_001B9FC0[];

extern int D_L20_001BA1F0[];

extern int D_001A79F0;

extern int D_001A9430;

extern int D_001A9434;

extern int D_001A9438;

extern int D_001A943C;

extern int D_001A9440;

extern int D_0018A550[];

extern int D_001AF3B0;

extern int D_00189E20[];

extern void func_L00_002FC980(void *);

extern void func_002E64A0(void *);

extern void func_L00_00326048(void *, void *, s32, s32, float);

extern void func_00326488(void *, void *, void *);

extern void func_00302D50(void *, void *);

extern void func_00326528(void *, void *, void *, float);

extern void func_00302548(void *, void *);

extern void func_00302260(void *, void *, void *);

extern void func_003B4240(void *, void *, void *);

extern void func_003B4440(void *);

extern void func_002FAE78(void *, void *);

extern void func_00301FE8(void *, void *, int);

extern void func_00302728(void *, void *, void *);

extern void func_00302290(void *, void *, void *);

extern void func_00420850(void *, void *, void *, float);

extern void func_0033AE90(void);

extern void func_0041A018(void *, void *, int, int, int, int, int, int, float, float);

void func_L20_00310E38(void *arg0)
{
    L20_00310E38_State *st;
    L20_00310E38_V4 vec;
    u32 *array;
    u32 *walk;
    void *obj;
    int counter;
    int limit;
    short type;
    unsigned short flags;
    u32 field;
    float v0;
    float v3;
    void *target;

    func_L00_002FC980(arg0);
    st = &D_L20_001BDCC0;
    limit = st->counter;
    counter = 0;
    if (limit <= 0)
        goto after_loop;
    array = (u32 *)D_001A79F0;
    walk = &array[0x18C / 4];
    for (;;) {
        obj = (void *)*walk;
        walk++;
        if (obj != 0) {
            type = *(short *)((char *)obj + 0xAA);
            if (type == 0xE29) {
                flags = *(unsigned short *)((char *)obj + 0x34);
                flags |= 0x800;
                *(unsigned short *)((char *)obj + 0x34) = flags;
                type = *(short *)((char *)obj + 0xAA);
            }
            if (type == 0xD54)
                func_002E64A0(obj);
        }
        if (obj == 0)
            goto loop_end;
        type = *(short *)((char *)obj + 0xAA);
        if (type != 0xFA0)
            goto loop_end;
        field = *(u32 *)((char *)obj + 0x68);
        if (field != 0)
            func_L00_00326048(obj, (void *)(field + 0xC), 0x80AAAAD2, 0x80396464,
                              0x3D7A35E0f);
loop_end:
        counter++;
        limit = st->counter;
        if (!(counter < limit))
            break;
    }
after_loop:
    if (D_001A79F0 != 0x14)
        goto the_end;
    if ((unsigned int)(st->mode - 4) >= 2)
        goto mode_other;
    if (st->mode == 4) {
        D_00189E20[0x5C0 / 4] = st->f19C;
        target = st->f1B8;
    } else {
        target = st->f1A8;
    }
    func_00326488(target, 0, (void *)&vec);
    func_00302D50(&D_0018A550[0], (void *)&vec);
    v3 = D_L20_001C6AE0.f24;
    v0 = 12.0f - v3;
    v0 = v0 * 0.1f;
    v3 = v3 + v0;
    D_L20_001C6AE0.f24 = v3;
    func_00302548(&D_L20_001C6AE0.f24, &D_0018A550[0]);
    func_00302260(&D_L20_001C6AE0.f24, &D_L20_001C6AE0, 0);
    func_003B4240(target, 0, 0);
    func_003B4440(target);
    func_002FAE78(&func_L20_00310E38, target);
    if (st->mode == 5 && st->state == D_001A943C - 1) {
        vec.q = 0;
        vec.f[0] = 18.0f;
        vec.f[1] = -2.5f;
        vec.f[2] = 1.0f;
        func_00302728((void *)&vec, (void *)&vec, &D_L20_001BA1F0[0]);
        func_00302260((void *)&vec, (void *)&vec, &D_L20_001BA1F0[0] - 0x230);
        func_00302290((void *)&vec, &D_0018A550[0] - 0x230, (void *)&vec);
        func_00302548((void *)&vec, (void *)&vec);
        func_00420850((void *)D_0018A550[0], (void *)&vec, (void *)&vec, 0.0f);
    }
    if (st->state == D_001A9434) {
        func_00301FE8(&D_L20_001C6AE0, 0, 0x50);
        D_001AF3B0 = 1;
        D_L20_001C6AE0.f24 = 0.2f;
    }
    if (!(D_001A9434 < st->state && st->state < D_001A9438)) {
        D_00189E20[0x5C0 / 4] = 0;
        goto mode_other;
    }
mode_other:
    if ((unsigned int)(st->mode - 2) >= 3)
        goto the_end;
    if (st->counter <= 0)
        goto the_end;
    {
        int i = 0;
        u32 *w = (u32 *)((char *)st + 0x18C);
        for (;;) {
            obj = (void *)*w;
            w++;
            {
                unsigned short t = *(unsigned short *)((char *)obj + 0xAA);
                if ((unsigned int)(t - 0xD0E) < 2) {
                    short sv = (short)t;
                    *(unsigned short *)((char *)obj + 0x7C) =
                        (sv == 0xD0F) ? 0x0F : 0x3FF;
                }
            }
            if (*(short *)((char *)obj + 0xAA) == 0xCE0) {
                if (st->mode == 3 && st->state < D_001A9430)
                    func_0033AE90();
            }
            i++;
            limit = st->counter;
            if (!(i < limit))
                break;
        }
    }
    if (st->mode == 3 && st->state == D_001A9430) {
        TI128 tmp;
        tmp = *(TI128 *)(st->f198 + 0x10);
        func_00302260((void *)&tmp, (void *)&tmp, (void *)D_001A9430);
        func_0041A018((void *)&tmp, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 1.0f, 20.0f);
        D_L20_001B9E80.f160 = 0.09f;
        D_L20_001B9E80.f168 = 0x37;
        D_L20_001B9E80.f180 = 0.08f;
        D_L20_001B9E80.f188 = 0x46;
        D_L20_001B9E80.f16C = 0;
    }
the_end:
    return;
}
