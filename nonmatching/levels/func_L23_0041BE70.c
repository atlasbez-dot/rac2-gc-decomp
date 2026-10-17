/* func_L23_0041BE70 (164 bytes, 1 place) -- measured 0 of 1: EXACT SIZE, every
   instruction right, only the layout of the two arms differs (first difference +0x1c,
   the branch offset). (Wave 6 w08, Docker-free ruler; provisional.)

   This one must live in the -g8 sibling: retail reads the level object with
   `lw $a2,0x2494($gp)`, and at -O2 -G0 the `sda` attribute does NOT produce the
   gp form (a plain `lui/lw` pair appears instead, one word more, 168 bytes).
   Compiled with -O2 -G8 -ffunction-sections the load comes out `lw $a2,0x0($gp)`
   and the size is exactly 164.

   Retail hands three different objects to func_002A90C8(state, *(int *)(arg0+0x20),
   0x10000, a3, *(float *)(arg0+0x2C)), chosen by the slot index at state+0x60C:
     index != -1 -> a0 = *(state+0x358 + index*4), a3 = 0x001B36E0
     index == -1 -> p = *(state+0x610);
        p == 0            -> a0 = the level object,      a3 = level object + 0x10
        (p->0x34 | 0x4000) -> a0 = p,                    a3 = 0x001B36E0

   Four shapes measured (if/else, inverted if/else, early return, nested returns):
   all 164 bytes, all differing at +0x1c only. Retail lays the arms out as
   [p == 0 call][index call][p != 0 call] -- the index arm between the two p arms --
   where this cc1 emits [p == 0][p != 0][index]; the branch at +0x1c jumps over one
   block instead of the other. Nothing else differs.
*/

typedef unsigned short u16;

extern char *D_L23_001B1484 __attribute__((sda));
extern char D_001B36E0[];
extern void func_002A90C8(char *a0, int a1, int a2, char *a3, float f12);

void func_L23_0041BE70(char *arg0) {
    char *state = D_L23_001B1484;
    char *sub = *(char **)(state + 0x68);
    int index = *(int *)(sub + 0x60C);

    if (index == -1) {
        char *p = *(char **)(sub + 0x610);

        if (p == 0) {
            func_002A90C8(state, *(int *)(arg0 + 0x20), 0x10000, state + 0x10,
                          *(float *)(arg0 + 0x2C));
        } else if ((*(u16 *)(p + 0x34) | 0x4000) != 0) {
            func_002A90C8(p, *(int *)(arg0 + 0x20), 0x10000, D_001B36E0,
                          *(float *)(arg0 + 0x2C));
        }
    } else {
        func_002A90C8(*(char **)(sub + 0x358 + index * 4), *(int *)(arg0 + 0x20),
                      0x10000, D_001B36E0, *(float *)(arg0 + 0x2C));
    }
}
