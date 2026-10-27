/* Mid worker 7: near miss, boot func_0029D830 (412 B), file flags -O2 -G8 (plain) in src/game/0029BCC8.c.
   Structure, branches, register assignment of the entry loops match retail; the residual is the data access.
   Retail addresses D_001B1A58/D_001B1A54 with `lui $at; sw lo($at)` and keeps the pointer test on $v0 with the
   `s0 = v0` copy in the bnez delay slot. This cc1 treats the 4-byte externs as small data (`sw $v0,sym` in the
   delay slot -> $gp form, 396 B); `nosda` hoists the high halves into registers (420 B, extra saved regs);
   incomplete arrays do the same; -mno-split-addresses keeps $gp and also sinks the counter into a register.
   Needs a way to get the absolute two-instruction form without hoisting. */

typedef struct Entry29D830 {
    short id;
    short a;
    int ka;
    short b;
    short pad0A;
    int kb;
    unsigned short flags;
    char pad12[10];
    int (*fn)(int);
    int arg;
    short state;
    short result;
} Entry29D830;
typedef struct { char pad[0x230]; int index; } Base29D830;
extern Base29D830 D_001C4FA0;
extern Entry29D830 *D_00258BA0[];
extern Entry29D830 *D_001B1A58;
extern int D_001B1A54;
extern unsigned char D_001A7BE8[];
extern int func_0029D9D0(int, int);

int func_0029D830(void)
{
    Entry29D830 *e;

    D_001B1A58 = D_00258BA0[D_001C4FA0.index];
    if (D_001B1A58 == 0)
        return 0;
    e = D_001B1A58;
    for (; e->id != 0; e++) {
        if ((e->flags & 4) && D_001A7BE8[D_001C4FA0.index] == 0) {
            e->state = 0;
            continue;
        }
        if (func_0029D9D0(e->a, e->ka) == 0)
            e->state = 0;
        else if (func_0029D9D0(e->b, e->kb) == 0)
            e->state = 1;
        else
            e->state = 2;
    }
    for (e = D_001B1A58; e->id != 0; e++) {
        if (e->fn != 0)
            e->result = e->fn(e->arg);
    }
    D_001B1A54 = 0;
    for (e = D_001B1A58; e->id != 0; e++) {
        if (e->state == 1 && (e->flags & 2) == 0)
            D_001B1A54++;
    }
    return D_001B1A54 == 0;
}
