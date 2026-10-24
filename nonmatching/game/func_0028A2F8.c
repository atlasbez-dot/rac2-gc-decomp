/* Retained manual C reconstruction; not linked and not credited as matching.
 * Checked source: src/game/0028A2F8-g8.c
 * Profile: -O2 -G8 -ffunction-sections -g
 * Retail US extent: 888 bytes.
 * us: 0/28 (exit 1, 844 compiled bytes); us2: catalogue absent (exit 1); pal: catalogue absent (exit 1).
 * Residual: 844/888 bytes. The candidate saves s0 in addition to ra and retains the row base across calls. Global loads, transition branches and row arithmetic are scheduled differently.
 * Reopen only with: Qualify the real shared counter-state storage and a meaningful C alias/lifetime model that removes the saved base without omitted transitions.
 * No complete linked build was run for this candidate.
 */
#include "include_asm.h"

typedef struct {
    int value;
    int timer;
    int age;
    short reserved;
    short state;
} CounterTransition;
extern CounterTransition D_001B1928[2];
extern int D_001B1948, D_001B194C, D_001B1950, D_001B1954, D_001B1958;
extern int D_001A8BB0;
extern int D_001A79F8 __attribute__((sda));
extern int func_0029B780(void);
extern void func_0029CBA8(int);
extern void func_0028A278(void);
extern void func_0029B698(int);

void func_0028A2F8(void)
{
    CounterTransition *row;
    int index;
    int previous;
    int delta;
    int i;
    if (func_0029B780())
        return;
    func_0029CBA8((int)&D_001B1948);
    if (D_001A8BB0 == 5 && D_001A79F8 < D_001B1948) {
        func_0028A278();
    } else if (!D_001B1958 && D_001B1954 == -1 && D_001A79F8 < D_001B1948) {
        index = D_001B1928[0].state != 0;
        row = &D_001B1928[index];
        row->state = 1;
        row->timer = 0;
        row->age = 0;
        row->value = D_001B1948 - D_001A79F8;
        D_001B1954 = index;
        D_001B1958 = 1;
    } else if (!D_001B1958 && D_001B1954 == -1 && D_001B1948 + D_001B1950 < D_001A79F8) {
        index = D_001B1928[0].state != 0;
        row = &D_001B1928[index];
        row->state = 1;
        row->value = 0;
        row->timer = 0;
        row->age = 0;
        D_001B1954 = index;
        D_001B1958 = 0;
    }
    index = D_001B1954;
    if (index != -1) {
        row = &D_001B1928[index];
        if (row->state != 3) {
            previous = row->value;
            if (previous >= 0) {
                row->value = D_001A79F8 - D_001B1948 + D_001B1950;
                if (row->value != previous)
                    row->timer = 0;
            }
            row->timer++;
            row->age++;
            if (row->timer > 60) {
                D_001B194C = D_001B1948;
                D_001B1950 = row->value;
                row->state = 3;
                row->timer = -1;
            }
        }
    }
    if (index == -1 && (D_001B1928[0].state == 3 || D_001B1928[1].state == 3))
        func_0029B698(180);
    for (i = 0, row = D_001B1928; i < 2; i++, row++) {
        if (row->state == 1) {
            if (row->age >= 15)
                row->state = 2;
        } else if (row->state == 3) {
            row->timer++;
            delta = (int)((float)D_001B1950 * 0.0714285746f);
            D_001B1948 += delta;
            row->value -= delta;
            if (D_001B1958) {
                if (row->value > 0)
                    row->value = 0;
            } else if (row->value < 0) {
                row->value = 0;
            }
            if (row->timer >= 15) {
                if (D_001B1948 != D_001B194C + D_001B1950)
                    D_001B1948 = D_001B194C + D_001B1950;
                D_001B1950 = 0;
                D_001B1954 = -1;
                row->state = 0;
                D_001B1958 = 0;
            }
        }
    }
}
