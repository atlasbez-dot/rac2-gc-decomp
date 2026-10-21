/* from src/game/002E7018.c: C that compiles close to the function but not to
   its bytes (tools/check.py: 0 of 28 places match, the first difference is at
   +0x24; the size is right, 144 bytes).

   The function places the world: it clears the selector's two shorts, sets the
   level's float, calls func_002FC138, moves the level's offset back by one
   screen, adds it to the two absolute positions, and tells the level which
   bank to use.

   The two shorts share one base in retail ("sh $v1,0x22($v0)" and
   "sh $zero,0x20($v0)" with $v0 holding 0x152C00), so they are one structure
   here.  The world offset is read through an absolute address in retail
   ("lw $a2,0x2610($a2)") and written back through $gp ("sw $a2,0x3620($gp)");
   the two names below are the same address read two ways.

   What still differs: this cc1 schedules the float store's address
   materialisation ("lui $a0") before the short store, retail schedules it
   after; retail loads the two positions in the order of the source and this
   cc1 loads the second one first.  Eleven wordings (the float through a
   volatile symbol, the shorts through a volatile structure, the two sums in
   temporaries, the state through a pointer, the order of the statements)
   compile to the same bytes. */

typedef struct { char pad00[0x20]; short unk20; short unk22; } Sel52C00;

extern Sel52C00 D_00152C00;

extern float ref_L00_00360ED0_00;
extern int ref_L00_00360ED0_01;
extern int ref_L00_00360ED0_02 __attribute__((sda));

typedef struct { char pad00[0x0C]; int unk0C; int unk10; } World2E71B8;

typedef struct {
    char pad00[0x34];
    int unk34;
    char pad38[0x34];
    int unk6C;
    int unk70;
} State2E71B8;

extern World2E71B8 ref_L00_00360ED0_03;
extern State2E71B8 ref_L00_00360ED0_04;

extern void func_002FC138(void);
extern void func_002E6D88(int);

void func_002E71B8(void)
{
    int base;

    D_00152C00.unk22 = -1;
    ref_L00_00360ED0_00 = 1.0f;
    D_00152C00.unk20 = 0;
    func_002FC138();

    base = ref_L00_00360ED0_01 - 0x60000;
    ref_L00_00360ED0_04.unk70 = ref_L00_00360ED0_03.unk10 + base;
    ref_L00_00360ED0_04.unk6C = ref_L00_00360ED0_03.unk0C + base;
    ref_L00_00360ED0_02 = base;
    func_002E6D88(3);
    ref_L00_00360ED0_04.unk34 = 1;
}
