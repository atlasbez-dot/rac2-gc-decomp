/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * Compiled 748 bytes; retail 748 bytes.
 * us: 0/1 placements match (exit 1).
 * us2: 0/1 placements match (exit 1).
 * pal: 0/1 placements match (exit 1).
 * Remaining: The shared qcopy operations reproduce the actual two complete transfers and their
 * memory ordering. Retail size and 0x60 frame agree; the first difference is +0x8 in saved-
 * register allocation. The arm-local slots temporary still crosses the join/call and changes
 * state/flip allocation.
 * Reopen: Independent slots/state pointer lifetime evidence that avoids extending the arm-local
 * temporary across the call.
 */

#include "common.h"
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
            qcopy((state + 0x3A0) ,((char *)D_L23_001FF300[slots[*(short *)(state + 0x394)]] + *(short *)(state + 0x396) * 16 + 0x10));
            func_L23_00418650(state + 0x3A0, *(float *)(state + 0x588));
        }
        func_00282CF0((char *)&vec, state + 0x3A0, obj + 0x10);
        dev = dev * 0.0625f;
        if (D_L23_001B14DC < dev)
            dev = D_L23_001B14DC;
        else if (dev < D_L23_001B14DC * 0.05f)
            dev = D_L23_001B14DC * 0.05f;
        func_00282F20((char *)&vec, (char *)&vec, dev);
        qcopy(&D_L23_001B38D0,&vec);
        func_00282CC0(obj + 0x10, obj + 0x10, (char *)&vec);
        func_L23_00418650(obj + 0x10, *(float *)(state + 0x588));
    }
    D_L23_001B1410 = 1.0f;
}
