/* 2026-10-23 readable reconstruction. Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 488/512 bytes, 0/2 placements in each of us, us2 and pal. Local frame/register allocation differs; retail also mixes absolute and GP access to the same globals. One C reconstruction measured. Reopen with evidence for the original record/counter access representation.
 * Earlier screening-only commentary is preserved below as historical context.
 */
/* from src/levels/shared/L11_002C5E80.c: not written this wave. Retail 512 bytes, 2 place(s), first word at L11:002c5e80.
 * Rule: MMI/LQ/SQ (op 0x1e).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x002c5e80  addiu       $sp, $sp, -0x80
 *   0x002c5e84  lui         $v1, 0x1B
 *   0x002c5e88  lw          $v1, 0x2DC4($v1)
 *   0x002c5e8c  sd          $s1, 0x38($sp)
 *   0x002c5e90  sd          $s2, 0x40($sp)
 *   0x002c5e94  daddu       $s1, $zero, $zero
 * Kept as data for the maintainers. */

typedef int Vec128_L11 __attribute__((mode(TI)));
extern Nearby_L11 *D_L11_001B2DC0;
extern int D_L11_001B2DC4;
extern float func_00282E48(void *, void *);
extern float func_00282E80(void *, void *);
extern float func_00282C48(float);
extern int func_L00_00341FA8(void *, void *, void *, int *, float *, int, float, float, float);

int func_L11_002C5E80(void *position, int **owner, float *target, int *contact, float *height, int *kind, int *excluded, int *required)
{
    float local[4] __attribute__((aligned(16)));
    int hit;
    float distance;
    int i;
    *(Vec128_L11 *)local = *(Vec128_L11 *)position;
    for (i = 0; i < D_L11_001B2DC4; i++) {
        if (excluded && D_L11_001B2DC0[i].owner == excluded) continue;
        if (required && D_L11_001B2DC0[i].owner != required) continue;
        if (!*D_L11_001B2DC0[i].owner) continue;
        if (func_00282E48(&D_L11_001B2DC0[i], local) > D_L11_001B2DC0[i].radius) continue;
        if (func_L00_00341FA8(D_L11_001B2DC0[i].owner, local, target, &hit, &distance, D_L11_001B2DC0[i].kind, 12.0f, 10.0f, 0.0f)) {
            if (func_00282E80(local, target) < 1.7f && func_00282C48(local[2] - target[2]) < 1.5f) {
                *owner = D_L11_001B2DC0[i].owner;
                *contact = hit;
                *height = distance;
                *kind = D_L11_001B2DC0[i].kind;
                return 1;
            }
        }
    }
    return 0;
}
