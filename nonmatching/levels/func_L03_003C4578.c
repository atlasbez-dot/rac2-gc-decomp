/* func_L03_003C4578 (644 bytes, 2 places) -- NEAR MISS, not integrated, and walled by the build.
   Needs the -g8 profile (gp-relative data, group count through $gp):
   src/levels/shared/L03_002AB5C8-g8.c.
   State: 644 bytes, retail's size; 3 words of 161 differ (check.py at both places says
   "instruction at +0x1bc differs"), all in the last `if` of the body:
     retail                                 this C
     lui   $v1,0x1B                         lw    $v1,0x378($s1)
     lw    $v1,0x2548($v1)   (D_..2548)     lui   $v0,0x1B
     lw    $v0,0x378($s1)                   lw    $v0,0x2548($v0)
   i.e. retail loads the frame counter D_L03_001B2548 first (into $v1) and the state field
   second (into $v0); this cc1 does it the other way round. sched1 breaks the tie between the two
   loads by register weight and the state load is the last use of `s1` (REG_DEAD), so it wins;
   seven spellings measured (`D != s1[0x378]`, `s1[0x378] != D`, `!(D == ...)`, a temp for either
   side, `nosda` and `sda` for D) all give the same order. Diagnostic: an extra store through
   `s1` after the `if` (`*(int *)(s1 + 0x37C) = 0;`, one word too many, never in src/) flips the
   two loads to retail's order, so in retail `s1` is still live past the compare when sched1 runs;
   no use of it survives in retail's code, and the use that vanishes before the final code is
   not found.
   Walled anyway: the nine-entry `switch (a0[0x95])` compiles to a jump table in `.rdata` (retail's
   is in the level's data: `lui $v0,0x2B ; addiu $v0,$v0,-0x7010` at level 3) and tools/build.py
   refuses it with `needs .rodata at its place, which is not C`, as func_00118CC8. check.py cannot
   see it; with a placement for the table in the build this body needs only the three words above.
   Measured and right:
   - `case 0:` before `default:` starts the table at 0 (`sltiu $v0,$v1,9`, no `addiu $v1,$v1,-1`).
   - the state pointer is read before the test: `unsigned char *s1 = *(unsigned char **)(a0 +
     0x68); if (a0[0x31] != 0) { ... }` gives `beqz $v0` with `lw $s1,0x68($s0)` in its delay
     slot, where an early `return` (or the load after the test) gives `beql` with the
     epilogue's `ld $s0` in it.
   - the second word of each pair (0x1AFF14, 1C, 24, 2C, 3C, 44, 4C) is retail's `lui $v1,0x1B ;
     lw $v1,off($v1)` with the destination as the temporary, i.e. the bare symbol load the
     assembler expands: `extern int X[3] __attribute__((sda));` (size over 8 in a -G8 unit) read
     as `X[0]`. `nosda` makes cc1 split the address itself, which separates the `lui` from the
     `lw`, changes the schedule and lets cross-jumping merge the case 8 and case 2 blocks.
   - the first word of each pair is `extern int X __attribute__((sda));` (a `lw` through $gp); the
     pair goes through a local `int pair[2]` (retail stores the words at 0($sp) and 4($sp) and
     reloads them as $a0/$a1), assigned in the order pair[0], pair[1], scale in every arm.
   - the scale constant 0x3998825C is `0.00029088825f` (the nearest decimal to pi/10800 gives
     0x3998825B).
   - the callee types: func_00283B98 (float, float) -> float, func_00283198 (float) -> float,
     func_00283D38 (int, int, float) -> int; the last call's result goes to a0[0x78]. */
#include "include_asm.h"

extern int D_L03_001B2A38 __attribute__((sda));
extern unsigned char *D_L03_001B2A1C[3] __attribute__((sda));
extern unsigned short *D_L03_001FB5A0[];

extern float func_00283B98(float, float);
extern float func_00283198(float);
extern int func_00283D38(int, int, float);
extern void func_L00_002E6CF0(void *, void *);
extern void func_L03_003C4800(unsigned char *);

extern int D_L03_001B2548;

extern int D_L03_001AFF10 __attribute__((sda));
extern int D_L03_001AFF14[3] __attribute__((sda));
extern int D_L03_001AFF18 __attribute__((sda));
extern int D_L03_001AFF1C[3] __attribute__((sda));
extern int D_L03_001AFF20 __attribute__((sda));
extern int D_L03_001AFF24[3] __attribute__((sda));
extern int D_L03_001AFF28 __attribute__((sda));
extern int D_L03_001AFF2C[3] __attribute__((sda));
extern int D_L03_001AFF38 __attribute__((sda));
extern int D_L03_001AFF3C[3] __attribute__((sda));
extern int D_L03_001AFF40 __attribute__((sda));
extern int D_L03_001AFF44[3] __attribute__((sda));
extern int D_L03_001AFF48 __attribute__((sda));
extern int D_L03_001AFF4C[3] __attribute__((sda));
extern float D_L03_001AFF50 __attribute__((sda));
extern float D_L03_001AFF54 __attribute__((sda));
extern float D_L03_001AFF58 __attribute__((sda));
extern float D_L03_001AFF5C __attribute__((sda));

/* Per object kind (a0[0x95]: 1 and 7, 8, 2..6, else) it picks a pair of ids and a scale, turns
   the object's phase (the float at 0x35C of its state) by that scale, stores the result of
   func_00283D38 on the pair and the new phase in a0[0x78], and, when the state's counter at
   0x378 is not the frame counter, stamps the counter into the state of every entity of its group
   and registers func_L03_003C4800 for the object with func_L00_002E6CF0. */
void func_L03_003C4578(unsigned char *a0) {
    unsigned char *s1 = *(unsigned char **)(a0 + 0x68);
    int pair[2];
    float scale;
    float t;
    float r;
    unsigned short *q;
    unsigned char *e;

    if (a0[0x31] != 0) {
        switch (a0[0x95]) {
        case 1:
        case 7:
            pair[0] = D_L03_001AFF18;
            pair[1] = D_L03_001AFF1C[0];
            scale = D_L03_001AFF58 * 0.00029088825f;
            break;
        case 8:
            pair[0] = D_L03_001AFF20;
            pair[1] = D_L03_001AFF24[0];
            scale = D_L03_001AFF5C * 0.00029088825f;
            break;
        case 2:
            pair[0] = D_L03_001AFF20;
            pair[1] = D_L03_001AFF24[0];
            scale = D_L03_001AFF54 * 0.00029088825f;
            break;
        case 3:
            pair[0] = D_L03_001AFF38;
            pair[1] = D_L03_001AFF3C[0];
            scale = D_L03_001AFF54 * 0.00029088825f;
            break;
        case 4:
            pair[0] = D_L03_001AFF48;
            pair[1] = D_L03_001AFF4C[0];
            scale = D_L03_001AFF54 * 0.00029088825f;
            break;
        case 5:
            pair[0] = D_L03_001AFF40;
            pair[1] = D_L03_001AFF44[0];
            scale = D_L03_001AFF54 * 0.00029088825f;
            break;
        case 6:
            pair[0] = D_L03_001AFF28;
            pair[1] = D_L03_001AFF2C[0];
            scale = D_L03_001AFF54 * 0.00029088825f;
            break;
        case 0:
        default:
            pair[0] = D_L03_001AFF10;
            pair[1] = D_L03_001AFF14[0];
            scale = D_L03_001AFF50 * 0.00029088825f;
            break;
        }
        t = func_00283B98(*(float *)(s1 + 0x35C), scale);
        *(float *)(s1 + 0x35C) = t;
        r = func_00283198(t);
        *(int *)(a0 + 0x78) = func_00283D38(pair[0], pair[1], r * 0.5f + 0.5f);
        if (D_L03_001B2548 != *(int *)(s1 + 0x378)) {
            for (q = D_L03_001FB5A0[a0[0x21]];
                 a0[0x21] != 0xFF && a0[0x21] <= D_L03_001B2A38 && q != 0 &&
                 ((q != 0 && (short)q[-1] >= 0) || q == D_L03_001FB5A0[a0[0x21]]);
                 q++) {
                e = D_L03_001B2A1C[0] + ((*q & 0x7FFF) << 8);
                if (e == 0)
                    break;
                *(int *)(*(unsigned char **)(e + 0x68) + 0x378) = D_L03_001B2548;
            }
            func_L00_002E6CF0(func_L03_003C4800, a0);
        }
    }
}
