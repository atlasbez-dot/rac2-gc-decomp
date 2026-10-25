/* Retained manual C reconstruction; not linked and not credited as exact.
 * Checked source: src/levels/07_siberius/L07_00410588-copy.c
 * Profile: -O2 -G0 -ffunction-sections
 * Final US, US2 and PAL checks: 0/1 each, exit 1; 296 compiled / 300 retail bytes.
 * The 0x40 frame, full 16-byte snapshots, 128-byte source records, cached tag,
 * signed pointer comparison, eight-slot limit and complete restore are retained.
 * Residual: 296/300 bytes in all three releases; correct 0x40 frame and full snapshot/record/walk semantics. The state and saved-rotation address allocate to s1/s0 instead of s0/s1. A table-address high half is hoisted out of the loop, while retail materializes it each iteration. Other call/address scheduling differs.
 * Reopen only with: New measured lifetime/address-model evidence for the state versus saved-snapshot address allocation and table-base materialization. Do not repeat the recorded typed-record, SDA, snapshot-array or no-GCSE trials without new input.
 * Five measured source/profile forms were bounded; regalloc diagnostics were
 * captured before the allocation trials. No strict linked build was run here.
 */
#include "common.h"
typedef int SibQuad __attribute__((mode(TI)));
typedef struct { u8 prefix[0x30]; SibQuad position; u8 middle[0x30]; SibQuad rotation; } SibRecord128;
extern SibRecord128 *D_L07_001B23CC __attribute__((sda));
extern u8 *D_L07_001B2954;
extern u8 D_L07_00227E7F;
extern void func_002833F0(void *, void *);
extern void func_L00_00323448(void *, void *, int, int, int, int, int, int);
void func_L07_00410588(u8 *self)
{
    SibQuad saved[2];
    u8 *state = *(u8 **)(self + 0x68);
    SibRecord128 *records;
    int index;
    u8 *out;
    u8 *end;
    int count;
    u8 tag;
    qcopy(&saved[0], self + 0x10);
    qcopy(&saved[1], self + 0xF0);
    index = *(int *)(state + 0xC8);
    records = D_L07_001B23CC;
    qcopy(self + 0x10, &records[index].position);
    qcopy(self + 0xF0, &records[index].rotation);
    func_002833F0(self + 0xC0, self + 0xF0);
    func_L00_00323448(self, state + 0x1B0, 0x40, -1, *(int *)(state + 0xCC), -1, 7, 0);
    end = state + 0x1400;
    tag = D_L07_00227E7F;
    count = 0;
    out = state + 0x15B0;
    do {
        s16 id = *(s16 *)(state + 0x1F8);
        u8 *table = D_L07_001B2954;
        if (table[(id << 5) + 0x1D] == tag) {
            *(u8 **)(state + 0x1F0) = out;
            count++;
            state[0x1FE] = 0;
            out += 0x20;
        }
        state += 0x50;
        if (count >= 8)
            break;
    } while ((s32)state < (s32)end);
    qcopy(self + 0x10, &saved[0]);
    qcopy(self + 0xF0, &saved[1]);
    func_002833F0(self + 0xC0, self + 0xF0);
}
