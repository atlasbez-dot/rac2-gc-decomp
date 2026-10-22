/* func_L23_0041B188 (748 bytes, 1 place: 23:0041B188) -- NEAR MISS, not integrated.
   This C compiles to retail's 748 bytes with `-O2 -G8 -ffunction-sections -frac2-qcopy` (a -g8 unit of
   its own: the floats D_L23_001B14E4/14E8/1680/14DC/1410 are $gp words, and the two 16-byte copies are
   retail's register-address `lq`/`sq`; without the qcopy profile it is 744 bytes). 87 words differ
   (check.py: "instruction at +0x.. differs"): 59 are the same instruction with other registers, and
   28 rows are 14 words that appear only in retail plus 14 only here. The body, the call order, the
   constants and the branch shapes are retail's. What differs:
   - Callee-saved assignment (the 59 register-only words). Retail: s0 = the state, s1 = state+0x3A0,
     s2 = the flip flag (later the slot-array base), s3 = obj, s4 = obj+0x10, s5 = the side code,
     s6 = the high half of D_L23_001FF300. Here the user variable `slots` (a short-lived temporary:
     refs 6, live length 16, priority 7058) is allocated first and takes s0, which pushes the state to
     s1 (priority 6575), the flag to s0 (shared with `slots`), state+0x3A0 to s2 and the slot-array
     copy to s5. In retail the same temporary is a caller-saved `$t0`/`$v1`. The pre-scheduling order
     puts gcse's copy `R = slots` (the "PRE/HOIST: end of bb" line of the gcse dump) after the call of
     the arm, so the temporary looks call-crossing to the allocator; retail has the same copy shape
     (`daddu $s2,$t0,$zero`, `daddu $s2,$v1,$zero`) and still a caller-saved temporary. Not found:
     a spelling that makes the arm's temporary a caller-saved register.
   - The redundant `slots = (int *)(state + 0x230);` before the 16-byte copy (the join's use, as the
     source of the reaching copy) is what produces retail's two `daddu` copies and the right size; the
     other spellings measured (a named base used everywhere, the expression written inline, which folds the
     0x230 into the displacement, two names for the base) give 732-744 bytes.
   - The step test is `if (step >= count) call(...); else *(short *)(state+0x396) = step;`, which gives
     retail's `bnel ... ; sh` with the store in the slot; the other polarity gives `beqz; b; sh`.
   - The grouped 16-byte copy `D_L23_001B38D0 = vec` is also a scheduling barrier in retail: the two
     argument moves of the next call (`daddu $a0,$s4,$zero ; daddu $a1,$s4,$zero`) stay behind its
     `lq`/`sq`, while this cc1 moves them in front (4 words). A volatile asm after the copy in a scratch
     copy of this C (never for src/) puts them back and removes those 4 words: the known qcopy-barrier
     wall, separate from the allocation difference. A one-pass `do { D_L23_001B38D0 = vec; } while (0)`
     (the loop-note lever, kept out of src/ by the rules) also puts them back, but leaves a `nop` after
     the final call's slot (752 bytes). The cc1 of this tree also has an undocumented
     `-frac2-qcopy-barrier` switch ("Model the RAC2 quadword-copy scheduling barrier"); added to the
     profile line it removes those 4 words (69 words differ, all in the allocation and copy items
     above). It is not among the profiles the task lists, so nothing here depends on it. */

typedef unsigned long long u64;
typedef unsigned int u32;
typedef int TI128 __attribute__((mode(TI)));

extern float D_L23_001B14E4 __attribute__((sda));
extern float D_L23_001B14E8 __attribute__((sda));
extern float D_L23_001B1680 __attribute__((sda));
extern float D_L23_001B14DC __attribute__((sda));
extern float D_L23_001B1410 __attribute__((sda));
extern TI128 D_L23_001B38D0;
extern char D_L23_002595C8[];
extern int *D_L23_001FF300[];

extern void func_L23_00418650(char *, float);
extern float func_00282C48(float);
extern float func_00282E48(char *, char *);
extern void func_L23_004190C8(char *, u64, int, int);
extern void func_00282CF0(char *, char *, char *);
extern void func_00282F20(char *, char *, float);
extern void func_00282CC0(char *, char *, char *);

void func_L23_0041B188(char *obj) {
    char *state = *(char **)(obj + 0x68);
    int *slots;
    int *list;
    TI128 vec;
    float x, mid, dev;
    int side, flip, step, slot;

    func_L23_00418650(state + 0x3A0, *(float *)(state + 0x588));
    mid = D_L23_001B14E4;
    x = *(float *)(state + 0x5B8);
    if (mid + D_L23_001B14E8 <= x || x <= mid - D_L23_001B14E8) {
        flip = 0;
        if (mid - D_L23_001B14E8 < x) {
            side = 3;
            dev = func_00282C48(x - mid);
            if (*(u32 *)(state + 0x5F0) >= 2) {
                flip = 1;
                *(short *)(state + 0x392) = -*(short *)(state + 0x392);
            }
            *(int *)(state + 0x5F0) = 1;
        } else {
            side = 2;
            dev = func_00282C48(x - mid);
            if (*(int *)(state + 0x5F0) != 0 && *(int *)(state + 0x5F0) != 2) {
                flip = 1;
                *(short *)(state + 0x392) = -*(short *)(state + 0x392);
            }
            *(int *)(state + 0x5F0) = 2;
        }
        if (flip != 0 || func_00282E48(obj + 0x10, state + 0x3A0) < D_L23_001B1680) {
            step = *(short *)(state + 0x396) + *(short *)(state + 0x392);
            if (step < 0) {
                slots = (int *)(state + 0x230);
                func_L23_004190C8(obj, *(u64 *)(D_L23_002595C8 + (slots[*(short *)(state + 0x394)] << 4)), side, 1);
            } else {
                slots = (int *)(state + 0x230);
                slot = slots[*(short *)(state + 0x394)];
                list = D_L23_001FF300[slot];
                if (step >= *list)
                    func_L23_004190C8(obj, *(u64 *)(D_L23_002595C8 + (slot << 4) + 8), side, 1);
                else
                    *(short *)(state + 0x396) = step;
            }
            slots = (int *)(state + 0x230);
            *(TI128 *)(state + 0x3A0) = *(TI128 *)((char *)D_L23_001FF300[slots[*(short *)(state + 0x394)]] + *(short *)(state + 0x396) * 16 + 0x10);
            func_L23_00418650(state + 0x3A0, *(float *)(state + 0x588));
        }
        func_00282CF0((char *)&vec, state + 0x3A0, obj + 0x10);
        dev = dev * 0.0625f;
        if (D_L23_001B14DC < dev)
            dev = D_L23_001B14DC;
        else if (dev < D_L23_001B14DC * 0.05f)
            dev = D_L23_001B14DC * 0.05f;
        func_00282F20((char *)&vec, (char *)&vec, dev);
        D_L23_001B38D0 = vec;
        func_00282CC0(obj + 0x10, obj + 0x10, (char *)&vec);
        func_L23_00418650(obj + 0x10, *(float *)(state + 0x588));
    }
    D_L23_001B1410 = 1.0f;
}
