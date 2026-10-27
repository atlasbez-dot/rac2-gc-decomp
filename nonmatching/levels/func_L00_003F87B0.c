/* Reconstruction; not linked. Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 26 October 2026 (M14): 568/580 bytes (was 556). Retail's slot loop is not loop-optimised (the
 * index check is recomputed, 1 is rematerialised in the loop, no reversal), which a goto loop
 * gives; direction as a union so it is allocated first (sp+0, impact at sp+0x10); 1/600 is
 * 0x3ADA740F; the remove flag as select-style stores. Left: retail keeps the table base and a
 * second slot copy in callee-saved registers (eight saved, 0x90 frame) and holds 1 in s3 for the
 * impact stores.
 */
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vec;
typedef unsigned char u8;
typedef struct { Quad vector; int owner, flags; u8 kind, active; unsigned short id; float delay; int enabled; } Impact;
typedef struct { int timer, first, second; float phase, damage; char *object; int owner, hold; } Slot;

extern Quad D_00189E20;
extern Slot D_L00_002533B0[30];
extern float func_00283B98(float, float);
extern int func_002AB1F0(u8 *);
extern void func_00282D30(void *, void *, float);
extern void func_00282F20(void *, void *, float);
extern void func_002A8C00(char *, int, int, float, void *);
extern void func_002A8E20(void *, void *);
extern int func_00282948(void *);
extern void func_L00_003F89F8(void *);
extern float func_00283180(float);
extern int func_00283D38(int, int, float);
extern void func_002A0488(void *, int, int, int);
extern void ref_L00_003F87B0_00(void (*)(char *), char *);
extern void func_L00_003F9040(char *);

void func_L00_003F87B0(char *object)
{
    Vec direction;
    Impact impact;
    Slot *slot;
    int i;
    int remove;
    float *health;
    int color;

    *(Quad *)(object + 0x10) = D_00189E20;
    slot = D_L00_002533B0;
    i = 0;
loop:
    {
        if (D_L00_002533B0[i].object != 0) {
            slot->phase = func_00283B98(slot->phase, 0.20943955f);
            remove = 0;
            if (*(signed char *)(slot->object + 0x20) < 0)
                remove = 1;
            if (*(int *)(slot->object + 0x98) == 0)
                remove = 1;
            health = (float *)func_002AB1F0((u8 *)slot->object);
            if (health == 0) {
                remove = 1;
            } else {
                *health -= slot->damage;
                if (*health <= 0.0f) {
                    remove = 1;
                    func_00282D30(&direction, slot->object + 0xC0, -1.0f);
                    func_00282F20(&impact, &impact, 0.0016666668f);
                    *(int *)(object + 0xB8) = slot->owner;
                    func_002A8C00((char *)&impact, (int)object, 0x810000, 0.001f, &direction);
                    impact.vector = direction.q;
                    *(float *)((char *)&impact.vector + 12) = 5627.925f;
                    impact.active = 1;
                    impact.kind = 5;
                    impact.enabled = 1;
                    impact.id = *(unsigned short *)(slot->object + 0xAA);
                    func_002A8E20(slot->object, &impact);
                }
            }
            if (func_00282948(slot) != 0)
                remove = 1;
            if (remove) {
                func_L00_003F89F8(slot);
                slot->object = 0;
            } else if (slot->hold == 0) {
                color = func_00283D38(slot->first, slot->second, (func_00283180(slot->phase) + 1.0f) * 0.5f);
                func_002A0488(slot->object, color & 255, (color >> 8) & 255, (color >> 16) & 255);
            } else {
                slot->hold--;
            }
        }
        slot++;
        i++;
        if (i < 30)
            goto loop;
    }
    ref_L00_003F87B0_00(func_L00_003F9040, object);
}
