/* 0 of 27 places match - last line: 00_aranos_tutorial: 640 bytes, expected 596

   The body is in place: the state's aim vector is cleared, the mode byte maps the
   caller's mode, the object's id is looked up and its record copied into the state's
   table, the object's own fields are stamped with the id and the mode, the state's
   aim values are computed from the caller's scale, the state's counter picks a value
   from a $gp table, and the two tail calls run on the state's flags.

   Measured and still different:

   * the 16-byte copy.  Retail writes `lq $v0,0($s0)` then `sq $v0,0($a0)` (the load
     from the object, the store into the table entry); this cc1 emits a second `lq`
     where the store belongs, so the copy is two loads and a store.
   * the float registers.  Retail keeps the caller's scale in $f20 and the 0.0 constant
     in $f21, and materialises 1.0f in $f0 for the division; this cc1 copies the
     scale into $f21 and materialises 1.0f in $f1.
   * the prologue.  Retail saves $s4,$s2,$s3,$s0,$s1,$ra in that order, this cc1
     $s4,$s3,$s0,$s1,$s2,$ra.
   * the `bltz` over the id block is one word short (the block it skips is one
     instruction longer here).

   The state is reached through a struct view (the member offsets are the retail
   ones: 0xC20..0xC34, 0x2290, 0x22B4, 0x22B8, 0x22BA, 0x2494, 0x24B0), which is what
   gives retail's `lui`/`addiu` base with the offsets folded; the $gp table of floats
   is `D_L00_001A7DF8` (0x001AEFF0 - 0x71F8), declared `sda` with a size, in a `-g8`
   unit.  The unit needs `-G8` (the table is reached through $gp), so the body lives
   in a sibling file; the flags it needs are the default ones.  */
#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef int TI128_L00_002D2168 __attribute__((mode(TI)));

/* The fields of the level state this function reads and writes. */
typedef struct {
    u8 pad0[0xC20];
    f32 aim_scale;
    f32 aim_div;
    s32 flags;
    s32 aim_slot;
    s32 counter;
    s32 counter2;
    u8 pad1[0x2290 - 0xC38];
    u8 *object;
    u8 pad2[0x22B4 - 0x2294];
    u8 flag22b4;
    u8 pad3[3];
    u8 flag22b8;
    u8 pad4[1];
    u8 flag22ba;
    u8 pad5[0x2494 - 0x22BB];
    s32 slot;
    u8 pad6[0x24B0 - 0x2498];
    s32 mode;
} L00_002D2168_State;

extern L00_002D2168_State D_00189E20_state;

/* The byte that selects the mode the caller's argument is turned into. */
extern u8 D_001A7A45 __attribute__((nosda));

/* The two tables the object is looked up in. */
extern char D_L00_001B4400[] __attribute__((nosda));

extern char D_L00_001B4A00[] __attribute__((nosda));

/* The table of 16-byte records the object's id selects. */
extern char D_L00_001E98C0[] __attribute__((nosda));

/* The table of values the state's counter selects. */
extern f32 D_L00_001A7DF8[2] __attribute__((sda));

extern int func_0029FA88(char *);
extern int func_002A2450(char *, int);
extern void func_0011AEA0(int);
extern int func_0029F390(char *);
extern int func_L00_002A4DB0(char *, int, int, char *);
extern int func_00283CF0(float);
extern void func_L00_002D24B8(void);
extern void func_L00_002D1C40(int, int, float);
extern void func_L00_002D1F60(void);
extern void func_L00_002D1FD8(int, int, float);

/* Hands the object the caller's argument names to the game: the state's aim vector is
   cleared, the object's id is looked up, the id's record is copied into the state's
   table and the object's own fields are stamped with the id and the caller's mode. */
void func_L00_002D2168(int a0, int a1, float f12)
{
    char *obj;
    int id;
    int mode;
    int second;
    float scale;
    f32 zero = 0.0f;

    if (D_00189E20_state.flags & 2)
        *(int *)(D_00189E20_state.object + 0x44) = 0;
    obj = D_00189E20_state.object;

    mode = a0;
    second = a1;
    scale = f12;

    if (D_001A7A45 != 0) {
        if (mode == 0x31)
            mode = 0x32;
        else
            mode = ((mode ^ 0x32) == 0) ? 0x31 : mode;
    }

    id = func_0029FA88(obj);
    if (id >= 0) {
        func_002A2450(obj, id | 0x300);
        func_0011AEA0(0);
        *(TI128_L00_002D2168 *)(D_L00_001E98C0 + id * 16) = *(TI128_L00_002D2168 *)obj;
        if (*(u8 *)(obj + 0x42) != 0xFF)
            *(u8 *)(obj + 0xA9) = *(u8 *)(obj + 0x42);
        *(TI128_L00_002D2168 *)(D_L00_001E98C0 + id * 16) = *(TI128_L00_002D2168 *)(obj + 0x80);
        *(u8 *)(obj + 0x42) = 0xFF;
        *(u8 *)(obj + 0x40) = id;
    }
    *(u8 *)(obj + 0x41) = second;
    *(u8 *)(obj + 0x43) = mode;
    func_0029F390(obj);

    if (*(u8 *)(obj + 0x42) != 0xFF) {
        *(int *)(obj + 0x58) = func_L00_002A4DB0(obj, *(u8 *)(obj + 0x42), *(u8 *)(obj + 0x40),
                                                D_L00_001B4400);
    }
    *(int *)(obj + 0x5C) = func_L00_002A4DB0(obj, *(u8 *)(obj + 0x43), *(u8 *)(obj + 0x41),
                                            D_L00_001B4A00);

    if (zero < scale) {
        D_00189E20_state.aim_scale = 1.0f;
        D_00189E20_state.aim_div = 1.0f / scale;
        *(float *)(obj + 0x44) = zero;
        D_00189E20_state.counter = -1;
    } else {
        D_00189E20_state.aim_div = 1.0f;
        D_00189E20_state.counter2 = 0;
        D_00189E20_state.counter = func_00283CF0(-scale) - 1;
        *(float *)(obj + 0x44) = zero;
    }

    func_L00_002D24B8();

    *(u8 *)(obj + 0x6C) = *(u8 *)(*(int *)(*(int *)(obj + 0x24) + mode * 4) + 0x11);
    if (scale < 0.0f) {
        D_00189E20_state.aim_slot = 1;
        scale = (float)(int)D_L00_001A7DF8[D_00189E20_state.counter];
    }

    if (D_00189E20_state.flag22b4 == 0)
        func_L00_002D1C40(mode, second, scale);
    if (D_00189E20_state.flag22b4 == 0 && D_00189E20_state.flag22ba == 0 && mode == D_00189E20_state.mode)
        D_00189E20_state.flag22b8 = 0;
    func_L00_002D1F60();
    if (D_00189E20_state.slot != 0)
        func_L00_002D1FD8(mode, second, scale);
}


