/* RAC1-helper follow-up, 2026-10-25: NOT MATCHING; no exact-C credit.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Fresh local measurement: 724/732 bytes, 0/27 US placements, frame 0x30.
 * Change: Approved qcopy preserves five real aligned transfers. Two readable inline predicates distinguish the active standard and upgraded weapon families.
 * Residual: The predicates improve the previous 652-byte body. A common-return form measured 716 and no-split-addresses 704; null-guard, predicate/list block order and allocation remain different.
 * Reopen: Reopen on measured list-count/global base lifetimes or predicate materialization; do not add padding or change the 64-byte list and 0xE0 weapon strides.
 * Earlier measurements/screens below are historical; they do not prohibit
 * the currently approved shared transfer helpers or establish linked equality.
 */
/* Nonmatching: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L00_00398810: 0 of 27 places match (src/levels/shared/L00_00398810.c); us2: func_L00_00398810: 0 of 27 places match (src/levels/shared/L00_00398810.c); pal: func_L00_00398810: 0 of 27 places match (src/levels/shared/L00_00398810.c). One full reconstruction652/732 bytes, original frame0x30. Truthful64-byte projectile list(count+31 short indices), E0-byte weapon records and16-byte copies. Current predicates/list walks compile more compactly than retail; pool/global identity and source predicate expansion remain hypotheses. Factory pointer/handle banks and current integer-pointer list helper APIs verified. Reopen with measured source predicate/list lifetime evidence; no padding or aliases added. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { int active; unsigned char kind; char pad05[0xDB]; } WeaponRecord;
typedef struct { short count; short index[31]; } ProjectileList;
extern char *D_0018C0B0;
extern unsigned char D_00139579;
extern WeaponRecord D_L00_00262570[];
extern ProjectileList D_L00_001B1FF0 MACRO_ADDR;
extern char *D_L00_001B1E9C;
extern char *func_0029EFD0(int);
extern int func_002FED90(void *, int, float, float, float);
extern void func_002AB650(u8 *);
extern void func_002ACAD0(int, unsigned short *), func_002ACA50(int, short *, short), func_002A0F48(void *);
/* Separate predicates match the weapon pool's two active families. */
static __inline__ int projectile_standard_weapon(void) {
    WeaponRecord *entry = D_L00_00262570 + D_00139579;
    if (!entry->active) return 0;
    return entry->kind == 2 || entry->kind == 1;
}
static __inline__ int projectile_upgraded_weapon(void) {
    WeaponRecord *entry = D_L00_00262570 + D_00139579;
    if (!entry->active) return 0;
    return entry->kind == 3;
}
/* Creates a projectile and retires the oldest live entries when the shared list is full. */
char *func_L00_00398810(char *position, char *direction) {
    char *actor = func_0029EFD0(0xCB);
    char *state, *hero, *oldest;
    int i, age, oldestAge;
    short *slot;
    if (!actor) return 0;
    *(unsigned short *)(actor + 0x32) = 0x1FF;
    *(unsigned char *)(actor + 0x30) = 0xFF;
    *(unsigned short *)(actor + 0x34) |= 0x100;
    state = *(char **)(actor + 0x68);
    qcopy(actor + 0x10, position);
    qcopy(state + 0x10, direction);
    *(unsigned char *)(actor + 0x20) = 0;
    hero = D_0018C0B0;
    qcopy(actor + 0xC0, hero + 0xC0);
    qcopy(actor + 0xD0, hero + 0xD0);
    qcopy(actor + 0xE0, hero + 0xE0);
    *(int *)(state + 0x30) = 0;
    *(int *)(state + 0x2C) = 0;
    *(int *)(state + 0x28) = 0;
    *(int *)(state + 0x20) = func_002FED90(actor, 0, 1.0f, 1.0f, 1.0f);
    func_002AB650((u8 *)actor);
    *(short *)(state + 0xC) = 4;
    *(short *)(state + 0xE) = 15;
    *(unsigned char *)(state + 7) = 250;
    *(short *)state = 0;
    *(unsigned char *)(state + 8) = 0;
    *(unsigned char *)(state + 9) = 0;
    *(int *)(state + 0x44) = 0;
    *(int *)(state + 0x48) = 0;
    *(int *)(state + 0x4C) = 0;
    *(int *)(state + 0x40) = 0;
    *(int *)(state + 0x3C) = 0;
    *(int *)(state + 0x38) = 0;
    if (projectile_standard_weapon() || projectile_upgraded_weapon()) *(float *)(state + 0x24) = 60.0f;
    else *(float *)(state + 0x24) = 6.0f;
    while (D_L00_001B1FF0.count > 5) {
        oldest = 0;
        oldestAge = 0;
        slot = D_L00_001B1FF0.index;
        for (i = D_L00_001B1FF0.count; i > 0; i--, slot++) {
            char *candidate = D_L00_001B1E9C + *slot * 0x100;
            if (candidate && *(short *)(candidate + 0xAA) == 0xCB && *(unsigned char *)(candidate + 0x20) < 4) {
                age = *(int *)(*(char **)(candidate + 0x68) + 0x3C);
                if (oldestAge <= age) { oldest = candidate; oldestAge = age; }
            }
        }
        if (oldest) {
            *(unsigned char *)(oldest + 0x20) = 5;
            func_002ACAD0((int)oldest, (unsigned short *)&D_L00_001B1FF0);
            *(int *)(*(char **)(oldest + 0x68) + 0x40) = 1;
        }
    }
    func_002ACA50((int)actor, (short *)&D_L00_001B1FF0, 31);
    func_002A0F48(actor);
    return actor;
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_00398810 - 732 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x00398810. Screened with tools/w10_screen.py: 6 call(s)
   [func_0029EFD0@00398834, func_002FED90@003988D8, func_002AB650@003988E4,
   func_002ACAD0@00398A88, func_002ACA50@00398AB8, func_002A0F48@00398AC0];
   data addresses materialised [0x190000, 0x140000, 0x260000, 0x1b0000,
   0x1b0000, 0x1b0000, 0x1b0000, 0x1b0000, 0x1b0000]; float constants
   [0x3f800000, 0x42700000, 0x40c00000]; $gp-relative small data: no
   saves: -; callee-saved registers saved [-]; words plain C cannot emit
   [LQ/SQ 7A420000@0x0058, LQ/SQ 7C820000@0x005c, LQ/SQ 7A620000@0x0064,
   LQ/SQ 7C620000@0x0068, LQ/SQ 78620000@0x0080, LQ/SQ 7CC20000@0x0084,
   LQ/SQ 78A20000@0x0090, LQ/SQ 7C620000@0x0094, LQ/SQ 78820000@0x00a0,
   LQ/SQ 7C620000@0x00a4]. Head: addiu $sp, $sp, -0x30 ; sd $s2, 0x10($sp) ;
   sd $s3, 0x18($sp) ; daddu $s2, $a0, $zero ; sd $s1, 0x8($sp) ; daddu $s3,
   $a1, $zero. Not matched in this wave: the 128-bit copy needs an `lq`/`sq`
   pair; plain C reaches it only through a `mode(TI)` local, and this cc1
   folds the destination offset into the `sq` where retail materialises the
   pointer first. What would unblock it: the exact source expression tree,
   so this cc1 picks the same registers in the same order. */
