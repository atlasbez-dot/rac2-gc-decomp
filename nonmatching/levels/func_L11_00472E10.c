/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections.
 * Reported final C / retail: 888 / 896 bytes; size equality is not a match.
 * us: 0/1 placements; 888/896 bytes.
 * us2: not run / not reported.
 * pal: not run / not reported.
 * Residual: Retained readable C: -O2 -G8 -ffunction-sections, US 0/1, 888/896 bytes. Unsigned/signed temporary and switch forms retain conditional moves where retail branches; the later guard/loop and saved-register allocation also differ. The same unmarked level selector supports both absolute and delay-slot GP loads. Reopen with a meaningful nibble-counter control flow rather than alias/pin tricks.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained readable C: -O2 -G8 -ffunction-sections, US 0/1, 888/896 bytes.
 * Unsigned/signed temporary and switch forms retain conditional moves where
 * retail branches; the later guard/loop and saved-register allocation also differ.
 * The same unmarked level selector supports both absolute and delay-slot GP loads.
 * Reopen with a meaningful nibble-counter control flow rather than alias/pin tricks.
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 D_001A7B2B;
extern int D_001A79F0;
extern u8 D_0019B4A8[];
extern u8 D_L11_0021F8B0[];
extern u8 D_00189EA0[];
extern u8 D_00188660[];
extern u8 *D_L11_001B359C __attribute__((sda));
extern int func_002ACD38(void *);
extern void func_L00_003672F8(void);
extern void func_L00_002B9D60(float *, float *, int, int);
extern float func_00282E80(void *, void *);
extern int func_L00_0035F5A0(int, int, int);
extern void func_002E59F8(int);
extern int func_002B38B8(u8 *);
extern void func_0029F338(void *);

void func_L11_00472E10(u8 *object) {
    float position[4];
    float rotation[4];
    int *state = *(int **)(object + 0x68);
    int id, count, slot;
    int *entry;
    u8 *record;
    u8 *counter;
    int bits;
    if (object[0x20] == 0) {
        if (D_001A7B2B) {
            id = (short)*(u16 *)(object + 0xB2);
            if (D_L11_0021F8B0[id + 0x464] == 0) {
                bits = D_0019B4A8[(id >> 1) + D_001A79F0 * 0x400];
                switch (*(u16 *)(object + 0xB2) & 1) {
                case 1: bits >>= 4; break;
                }
                if ((bits & 7) == 0 && func_002ACD38(object + 0x10)) {
                    func_L00_003672F8();
                    position[0] = 363.18f;
                    position[1] = 680.68f;
                    position[2] = 155.73f;
                    rotation[2] = 2.3561947f;
                    rotation[0] = 0;
                    rotation[1] = 0;
                    func_L00_002B9D60(position, rotation, 0, 1);
                }
            }
        }
        object[0x20] = 1;
    }
    if (func_00282E80(object + 0x10, D_00189EA0) < 32.0f) {
        if (D_001A79F0 == 11) {
            record = D_00188660 + state[8] * 0x70;
            if (*(int *)(record + 0x88) != *(int *)(D_00189EA0 + 0x2210) || record[0x74] == 0)
                state[8] = func_L00_0035F5A0(27, 6, *(int *)(D_00189EA0 + 0x2210));
        }
    } else {
        slot = state[8];
        if (slot != -1) {
            record = D_00188660 + slot * 0x70;
            if (*(int *)(record + 0x88) == *(int *)(D_00189EA0 + 0x2210) && record[0x74]) func_002E59F8(slot);
        }
        state[8] = -1;
    }
    if (!func_002B38B8(object)) {
        id = (short)*(u16 *)(object + 0xB2);
        if (!D_L11_0021F8B0[id + 0x464]) {
            bits = D_0019B4A8[(id >> 1) + D_001A79F0 * 0x400];
            switch (*(u16 *)(object + 0xB2) & 1) {
            case 1:
                if (((bits >> 4) & 7) == 0) return;
                break;
            default:
                if ((bits & 7) == 0) return;
                break;
            }
        }
    }
    entry = state;
    for (count = 7; count >= 0; --count, ++entry) {
        if (*entry != -1) func_0029F338(D_L11_001B359C + *entry * 0x100);
    }
    id = *(u16 *)(object + 0xB2);
    if (id & 1) {
        counter = D_0019B4A8 + ((short)id >> 1) + D_001A79F0 * 0x400;
        if (((*counter >> 4) & 7) != 7) *counter += 16;
    } else {
        counter = D_0019B4A8 + ((short)id >> 1) + D_001A79F0 * 0x400;
        if ((*counter & 7) != 7) ++*counter;
    }
    slot = state[8];
    if (slot != -1) {
        record = D_00188660 + slot * 0x70;
        if (*(int *)(record + 0x88) == *(int *)(D_00189EA0 + 0x2210) && record[0x74]) func_002E59F8(slot);
    }
    state[8] = -1;
    func_0029F338(object);
}
