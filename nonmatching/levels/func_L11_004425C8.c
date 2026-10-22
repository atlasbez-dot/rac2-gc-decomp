/* func_L11_004425C8 (328 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 328 bytes, the same length as retail, but 31 words differ; every difference
   is the shape of an absolute address, the calls and the float constants are right.

   check.py (11_joba), with the source below, compiled in src/levels/11_joba/L11_0043E1A0.c
   (-O2 -G0 -ffunction-sections):
     00442668  lui   $a0, 0x1B          |  lui   $a0, 0x0
     0044266C  lw    $a0, 0x368C($a0)  |  lw    $a0, 0x0($a0)
   What is measured and right:
   - the float constants are 2.16f (0x400A3D71) and -2.52f (0xC02147AE), the level's
     default is 30.0f; the spellings are the natural ones, not the bit patterns;
   - the level's table D_L11_001B368C is scaled by 128 (sll 7) and the entry is taken
     at +0x30, as func_L11_004417E8 does;
   - the resident byte D_001395B8 is indexed by the result of func_L11_0043E108(1),
     and the branch picks the state's 0x15C or 0x158 slot;
   - the two handlers are the level's own func_L11_00445D28 and func_L11_004411C8, and
     the level's own func_L11_0043E108;
   - the function ends by storing -1 into the resident word D_001AA170.
   Tried and not enough:
   - D_L11_001B368C without the sda attribute: the order of the head changes (the
     state's 0x170 load and the two constants swap places), the sda attribute is what
     puts the head in retail's order;
   - the table through a local pointer, and the two branches merged into one: both
     change the call sequence.
   Next idea: the retail address shape is the "one register" form (the %hi in the
   destination, the %lo as the displacement). Plain C reaches it only when the
   symbol's address is not materialised, which needs the two branches to name the
   table through two C names (the double-name pattern in docs/COMPILER-NOTES.md);
   the same holds for D_L11_001CAE40 and D_001AA170. */

typedef float f32;
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern s32 D_L11_001CAE40;

extern u8 *D_L11_001B368C __attribute__((sda));

extern u8 D_001395B8[];

extern s32 D_001AA170;

extern u8 D_00189EA0[];

extern void func_L11_00445D28(u8 *, s32);

extern void func_L11_004411C8(u8 *);

extern void func_002A7750(u8 *, s32, s32);

extern void func_L00_002D7140(s32);

extern void func_L00_00303530(s32, void *);

extern void func_00282C88(void *);

extern s32 func_L11_0043E108(s32);

extern void func_L00_002B9D60(s32, s32, s32, s32);

extern void func_002DF3F8(void *, void *);

extern void func_L01_00323310(void *, void *);

/* Restarts the actor's state machine, releases the level's helper objects and hands
   the state's slots to the two level handlers. */
s32 func_L11_004425C8(u8 *obj) {
    u8 *state = *(u8 **)(obj + 0x68);
    f32 buf[4];

    func_L11_00445D28(obj, 0x20);
    func_002A7750(obj, 1, -1);
    if (*(s32 *)(state + 0x170) != 0) {
        func_L00_002D7140(*(s32 *)(state + 0x170));
        *(s32 *)(state + 0x170) = 0;
    }
    if (D_L11_001CAE40 != 0) {
        func_L00_00303530(0, *(void **)(state + 0x2F4));
    }
    func_00282C88(buf);
    if (D_001395B8[func_L11_0043E108(1)] != 0) {
        buf[2] = 2.16f;
        func_L00_002B9D60((s32)(D_L11_001B368C + (*(s32 *)(state + 0x15C) << 7)) + 0x30, (s32)buf, 0, 1);
    } else {
        buf[2] = -2.52f;
        func_L00_002B9D60((s32)(D_L11_001B368C + (*(s32 *)(state + 0x158) << 7)) + 0x30, (s32)buf, 0, 1);
    }
    func_002DF3F8(D_00189EA0, D_00189EA0 + 0x10);
    func_L11_004411C8(obj);
    func_L01_00323310(*(void **)(state + 0x2F4), *(void **)(state + 0x2FC));
    D_001AA170 = -1;
    return -1;
}
