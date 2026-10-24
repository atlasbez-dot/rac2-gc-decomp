/* Readable C reconstruction, measured2026-10-23.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0/1, us2: 0/1, pal: not carried.
 * 1000 versus996 bytes; address/register choices and remaining caller flag/control-flow lowering differ.
 * Tried: Full64-bit dispatch return interface and observed low32-bit mask use; all12 GPR inputs to32C700 preserved.
 * Reopen: A caller data/flag lifetime remedy without changing the callee return width.
 * Historical notes below are preserved; their copy-wall claims are superseded
 * by the current qualified copy profiles. No handwritten-assembly inference.
 */

/* Not matched (worker 05, level-20 wave 5, 2026-10-21).

   The body is 996 bytes.  Its single 128-bit copy is

       addiu      $a0, $sp, 0x20      ; the address of a local buffer
       addiu      $v1, $s1, 0x10      ; $s1 = $a0, so arg0 + 0x10
       lq         $v0, 0x0($v1)
       sq         $v0, 0x0($a0)

   BOTH addresses are materialised in the retail and both are folded by this
   compiler (`lq $v0,0x10($s1)` and `sq $v0,0x20($sp)`).  The mechanism and
   every escape measured are in the note on func_L20_0039E770 in this
   directory: the CSE's find_best_addr() replaces the address pseudo of a
   128-bit access by the `plus` of a register and a constant, and the reload
   then prints the constant as the displacement.  The address stays in a
   register only when the pointer's value is not a plus of a register (a
   symbol, a load, a call result, a pointer carried by a loop), and neither
   address here is one of those.

   Note that $a0 (the local's address) is also the first argument of the call
   f_0041A018 further down, and that the retail keeps the materialised
   address in $a0 for both - the compiler hoists the address of a local that
   is passed to a function into a register.  Passing the same pointer to a
   call does NOT keep the address in a register in the 128-bit access: the
   measurement is in the note on func_L20_0039E770 (a local buffer passed to a
   call and used as the destination of a 128-bit store still gives
   `sq $2,560($sp)`).

   This body belongs in the -G8 unit?  No: it reaches no global through $gp. */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct {
    unsigned char reserved_00[0x18];
    unsigned char enabled, count, kind;
    unsigned char reserved_1b[0x65];
    unsigned char payload[1];
} DispatchContext;
extern unsigned long func_002B1C20(void *, DispatchContext *);
extern void func_L20_0039D340(unsigned char *);
extern void func_0029F338(void *);
extern void func_002A7750(unsigned char *, unsigned char, int);
extern unsigned char *func_0032C700(void *, int, int, int, int, int, int, int, int, int, int, int, float, float);
extern void func_002A6C58(void *, int, int);
extern void func_L20_0039DE88(char *);
extern void func_L20_0039DB50(char *, int, int, float);
extern int func_002B3868(unsigned char *);
extern void func_L20_0039E158(char *);
extern void func_L20_0039E1E8(void *);
extern float func_00283248(float, float);
extern int func_L01_00322288(int, float);
extern float func_00283C80(float, float);
extern void func_L01_00321178(char *, char *);
extern void func_0029FCC0(char *, int, char *);
extern void func_00282CF0(void *, const void *, const void *);
extern void func_00282F20(void *, const void *, float);
extern int func_002E5CF8(int, int, char *);
extern unsigned char *func_L09_003A06B0(void *, void *, void *, float);
extern void func_L20_0039D7B0(char *);
extern int D_L20_001A8F00;
extern int D_L20_001BDCF0;

void func_L20_0039CF58(unsigned char *object) {
    Vector position, velocity;
    unsigned char *state = *(unsigned char **)(object + 0x68);
    unsigned char *child, *target;
    unsigned long flags;
    int mode, code, hand;
    unsigned int tick;
    float angle;
    child = *(unsigned char **)(state + 0x254);
    if (child) *(int *)(child + 0x98) = 0;
    func_L20_0039D340(object);
    if (D_L20_001A8F00 == 2) {
        if (D_L20_001BDCF0 < 5) return;
        child = *(unsigned char **)(state + 0x258);
        if (child) func_0029F338(child);
        child = *(unsigned char **)(state + 0x25C);
        if (child) func_0029F338(child);
        child = *(unsigned char **)(state + 0x254);
        if (child) func_0029F338(child);
        func_0029F338(object);
        return;
    }
    mode = object[0x95];
    if (mode == 1) {
        flags = func_002B1C20(object, (DispatchContext *)(state + 0x140));
        if ((unsigned int)flags & 1) {
            position.q = *(Quadword *)(object + 0x10);
            position.f[2] += 0.5f;
            func_0032C700(&position, 0, 25, 20, 20, 20, 45, 0, mode, 0, 0, 0, 0.5f, 20.0f);
            func_002A6C58(object, 0, 3);
            func_L20_0039DE88((char *)object);
        } else if ((unsigned int)flags & 2) {
            func_002A7750(object, 3, 0);
            func_L20_0039DB50((char *)object, 0, 20, 0.0f);
        }
    }
    code = object[0x20];
    switch (code) {
    case 2:
        if (object[0x60] & 2) func_002A7750(object, 3, -1);
        break;
    case 3:
        if (func_002B3868(object)) {
            func_L20_0039E158((char *)object);
            func_L20_0039E1E8(object);
            func_L20_0039DB50((char *)object, 11, 20, 0.0f);
        }
        if (*(float *)(state + 0x84) < *(float *)(state + 0x11C)) {
            func_L01_00321178((char *)object, (char *)state + 0x260);
        } else {
            target = *(unsigned char **)(state + 0x200);
            angle = func_00283248(*(float *)(target + 0x10) - *(float *)(object + 0x10),
                                  *(float *)(target + 0x14) - *(float *)(object + 0x14));
            func_L01_00322288((int)object, angle);
            if (func_00283C80(*(float *)(object + 0xF8), angle) < 0.05235988274216652f)
                func_002A7750(object, 4, -1);
        }
        break;
    case 4:
        if (func_002B3868(object)) func_L20_0039DB50((char *)object, 10, 20, 0.0f);
        *(float *)(state + 0x284) = func_00283248(*(float *)(state + 0x1F0) - *(float *)(object + 0x10),
                                                *(float *)(state + 0x1F4) - *(float *)(object + 0x14));
        tick = *(unsigned short *)(object + 0x96) % 20;
        if (tick == 0 || tick == 10) {
            hand = tick == 0 ? 4 : 0;
            func_0029FCC0(*(char **)(state + 0x258 + hand), 0, (char *)&position);
            func_00282CF0(&velocity, state + 0x1F0, &position);
            func_00282F20(&velocity, &velocity, 0.25f);
            func_002E5CF8(1, 0, *(char **)(state + 0x254));
            func_L09_003A06B0(object, &velocity, &position, (float)state[0x34]);
        }
        target = *(unsigned char **)(state + 0x280);
        if (*(unsigned short *)(object + 0x96) > 120 || (target && (*(unsigned short *)(target + 0x34) & 1)))
            func_002A7750(object, 3, -1);
        break;
    case 6:
        return;
    }
    func_L20_0039D7B0((char *)object);
    child = *(unsigned char **)(state + 0x254);
    if (child) *(int *)(child + 0x98) = *(int *)(*(unsigned char **)(child + 0x24) + 0x10);
}
