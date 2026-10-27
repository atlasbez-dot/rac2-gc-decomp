/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections -frac2-zero-ti-por.
 * 768/776 bytes; 0/1 USA v1.01 and USA v2.00 places.
 * The canonical function is absent from the PAL catalogue.
 * Remaining: The two real vector copies are recovered. Scalar damage-index allocation and
 * collision branches/global-base lifetime remain different. The zero vectors
 * retain ordinary TI initialization and the evidenced por profile.
 * Reopen with: Independent collision-record lifetime/branch evidence; the original
 * zero stores are now reproduced without replacing them with sq-zero helpers.
 */

#include "common.h"
typedef int OozlaQuad __attribute__((mode(TI)));
typedef struct {
    float direction[4];
    void *owner;
    int flags;
    u8 type, active;
    u16 oclass;
    float damage;
    int enabled;
} OozlaHit;
extern u8 D_00139574;
typedef struct { u8 pad[0x70]; float damage; u8 tail[0x6C]; } OozlaDamage;
extern OozlaDamage D_L01_002637A0[];
typedef struct { u8 pad[0x18]; u8 *other; int count; OozlaQuad position; u8 pad2[0x10]; float normal[4]; } OozlaCollision;
extern OozlaCollision D_L01_001BF900;
extern char *D_0018C0B0 NOT_SDA;
extern void *D_L01_001AC810;
extern void func_00282CC0(void *, void *, void *);
extern void func_002AFFD8(void *, void *, int);
extern void func_00282D30(void *, void *, float);
extern void func_L00_0038F3D8(void *);
extern void func_00282F70(void *, void *, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern void func_00283028(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern int func_00282948(void *);
extern void func_002FEE50(int);
extern void func_L00_0038DE70(void *, void *, void *);
extern void func_L00_0038E880(void *, void *, void *);
void func_L01_003839F0(u8 *object)
{
    float movement[4], rotation[4], previous[4], unused[4];
    OozlaHit hit;
    u8 *state;
    u8 *other;
    *(OozlaQuad *)movement = 0;
    state = *(u8 **)(object+0x68);
    *(OozlaQuad *)rotation = 0;
    movement[2] = 0.033333335f;
    rotation[2] = 1.0f;
    qcopy(previous, (object + 0x10));
    func_00282CC0(object + 0x10, object + 0x10, state);
    func_002AFFD8(object + 0x10, unused, 0);
    func_00282D30(unused, unused, 0.000305555585f);
    func_L00_0038F3D8(object);
    hit.owner = object;
    hit.flags = 0x830000;
    if (*(int *)(state + 0x18) < 290) hit.flags = 0x830001;
    hit.damage = D_L01_002637A0[D_00139574].damage;
    hit.enabled = 1;
    qcopy(hit.direction, state);
    func_00282F70(hit.direction, hit.direction, 1.0f);
    hit.type = 2;
    hit.direction[3] = 5627.9248046875f;
    hit.oclass = *(u16 *)(object + 0xAA);
    hit.direction[2] = 1.0f;
    hit.active = 1;
    *(int *)(state + 0x14) += 1;
    if (func_002761F8(previous, object + 0x10, 16, object, &hit)) {
        other = D_L01_001BF900.other;
        if (other) {
            if (other == D_0018C0B0 || *(short *)(other + 0xAA) == 0xC0) {
                if (*(int *)(state + 0x18) >= 290) goto finished;
            }
            if (*(void **)(other + 0x64) != D_L01_001AC810 || *(short *)(other + 0xAA) == 0x336) {
                object[0xBC] = 1;
                qcopy(object + 0x10, &D_L01_001BF900.position);
                func_00283028(movement, state, D_L01_001BF900.normal);
                func_00282F20(movement, movement, 0.033333335f);
                func_00282F20(rotation, D_L01_001BF900.normal, 1.0f);
            }
        } else if (D_L01_001BF900.count > 0) {
            object[0xBC] = 1;
            qcopy(object + 0x10, &D_L01_001BF900.position);
            func_00283028(movement, state, D_L01_001BF900.normal);
            func_00282F20(movement, movement, 0.033333335f);
            func_00282F20(rotation, D_L01_001BF900.normal, 1.0f);
        }
    } else if (func_00282948(state + 0x18)) {
        object[0xBC] = 1;
        func_00282CC0(movement, movement, state);
    }
finished:
    if (object[0xBC]) {
        func_002FEE50(*(int *)(state + 0x1C));
        if (*(int *)(state + 0x14) < 20)
            func_L00_0038DE70(object, movement, rotation);
        else
            func_L00_0038E880(object, movement, rotation);
    }
}
