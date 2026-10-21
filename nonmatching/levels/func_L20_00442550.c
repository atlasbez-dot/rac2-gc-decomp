/* near-miss: func_L20_00442550 (20_yeedil, 496 bytes).
   Wave 5 (20_yeedil, 2026-10-21, worker 03).
 *
 * The candidate below recovers the body: the calls, their order and their
 * arguments, the three level globals, the two branches and the tail are the
 * retail's, instruction for instruction.  It is 488 bytes against the
 * retail's 496 and the residue is ONE thing: the float register allocation.
 *
 * This cc1 merges the float temporaries into one pseudo that crosses three
 * calls, so it lands in the callee-saved $f20, the frame grows from 0x30 to
 * 0x40 and the whole body shifts by the four extra instructions; the retail
 * keeps the temporaries in $f0/$f1/$f2.  `cc1 -da' (x.i.lreg) shows the
 * merged pseudo: "Register 89 used 21 times across 50 insns; set 10 times;
 * crosses 3 calls".  The retail's $f0 is never live across a call: the two
 * loads of the state's 0xF8 are in different paths - one in the delay slot
 * of the `bnel' (dead before the call) and one after it.
 *
 * The body, for the next worker:
 *  - the frame is 0x30 with $s0/$s1/$s2/$s3 at 0x00/0x08/0x10/0x18 and $ra
 *    at 0x20; $s0 is the argument, $s2 the state (arg0+0x68), $s1 the boot
 *    global D_00189E20 and $s3 = $s1+0x80;
 *  - the first call is func_002AA2E8(arg0+0x48, 1.0f, 0.033333335f) - the
 *    constant 1/30 is 0x3D088889;
 *  - the byte at arg0+0x94 selects: when it is 2, func_002AA800(s2+0x1804,
 *    1, 0.0f, D_L20_001B2124 * 0.00014544412f) runs (180.0f is at
 *    gp+0x3134 and the constant is 0x3918825C);
 *  - the state's 0xF8 is then added to arg0+0x18, and the state's 0x7C is
 *    subtracted from its 0xF8;
 *  - the word at D_00189E20+0x2294 selects: when it is not 0x8C, the pair
 *    (D_00189E20+0x80, D_00189E20+0x84) is offset by arg0+0x10 and
 *    arg0+0x14 and given to func_00283248, whose result goes to
 *    func_L01_00322288(arg0, result); otherwise func_00282E80(s3, arg0+0x10)
 *    runs, and if its result is at most 4.0f the state's 0x88 is raised by
 *    5.0f, stored twice, func_002A89A8(s3, 0, 0.5f) runs and the halfwords
 *    at D_00189E20+0x1F0 and +0x1E0 are set to 5, after which the same
 *    func_00283248 call uses the record at D_L20_001B308C + (the word at
 *    s2+0x230) * 128, whose floats at +0x30 and +0x34 are offset by
 *    arg0+0x10 and arg0+0x14;
 *  - the tail: if the value loaded from arg0+0x18 is at most the state's
 *    0xE0, that value is stored to arg0+0x18, func_002E5CF8(0, 0, arg0)
 *    runs, and the state's 0xF8 times -0.4f (D_L20_001B2134, at gp+0x3144)
 *    is compared with 1/60 (0.016666668f): when it is smaller, the state's
 *    0xF8 is stored and then zeroed as an int and the function returns 1,
 *    otherwise it returns 0.
 *  - the body needs a -G8 unit: the two floats are read through $gp.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

#ifndef RAC2_T_REC_42550
#define RAC2_T_REC_42550
typedef struct {
    unsigned char pad0[0x30];
    float f30;
    float f34;
    unsigned char pad1[0x48];
} Rec_42550;
#endif

extern float D_L20_001B2124 __attribute__((sda));

extern float D_L20_001B2134 __attribute__((sda));

extern char D_00189E20[];

extern Rec_42550 *D_L20_001B308C;

extern float func_002AA2E8(float *, float, float);

extern void func_002AA800(char *, int, float, float);

extern float func_00282E80(char *, char *);

extern float func_002A89A8(void *, int, float);

extern float func_00283248(float, float);

extern int func_L01_00322288(char *, float);

extern int func_002E5CF8(int, int, char *);

int func_L20_00442550(char *arg0) {
    char *s0 = arg0;
    char *s2 = *(char **)(arg0 + 0x68);
    char *s1;
    char *s3;
    float f0;
    float f1;
    int v0;
    Rec_42550 *p;

    func_002AA2E8((float *)(s0 + 0x48), 1.0f, 0.033333335f);

    if (*(u8 *)(s0 + 0x94) == 2) {
        func_002AA800(s2 + 0x1804, 1, 0.0f, D_L20_001B2124 * 0.00014544412f);
        f0 = *(float *)(s2 + 0xF8);
    } else {
        f0 = *(float *)(s2 + 0xF8);
    }

    s1 = D_00189E20;

    f1 = *(float *)(s0 + 0x18);
    f1 = f1 + f0;
    *(float *)(s0 + 0x18) = f1;

    f0 = *(float *)(s2 + 0xF8);
    f1 = *(float *)(s2 + 0x7C);
    f0 = f0 - f1;
    *(float *)(s2 + 0xF8) = f0;

    if (*(int *)(s1 + 0x2294) != 0x8C) {
        f1 = *(float *)(s1 + 0x84);
        f0 = *(float *)(s1 + 0x80);
        func_00283248(f0 - *(float *)(s0 + 0x10), f1 - *(float *)(s0 + 0x14));
        func_L01_00322288(s0, f0);
        f0 = *(float *)(s0 + 0x18);
    } else {
        s3 = s1 + 0x80;
        f0 = func_00282E80(s3, s0 + 0x10);
        if (f0 <= 4.0f) {
            f0 = *(float *)(s1 + 0x88) + 5.0f;
            *(float *)(s1 + 0x88) = f0;
            func_002A89A8(s3, 0, 0.5f);
            *(float *)(s1 + 0x88) = f0;
            *(unsigned short *)(s1 + 0x1F0) = 5;
            *(unsigned short *)(s1 + 0x1E0) = 5;
        }
        v0 = *(int *)(s2 + 0x230);
        p = &D_L20_001B308C[v0];
        func_00283248(p->f30 - *(float *)(s0 + 0x10), p->f34 - *(float *)(s0 + 0x14));
        func_L01_00322288(s0, f0);
        f0 = *(float *)(s0 + 0x18);
    }

    f1 = *(float *)(s2 + 0xE0);
    if (f0 <= f1) {
        *(float *)(s0 + 0x18) = f1;
        func_002E5CF8(0, 0, s0);
        f0 = -D_L20_001B2134;
        f1 = *(float *)(s2 + 0xF8) * f0;
        if (f1 < 0.016666668f) {
            *(float *)(s2 + 0xF8) = f1;
            *(int *)(s2 + 0xF8) = 0;
            return 1;
        }
    }
    return 0;
}
