/* from src/levels/18_damosel/L18_002E68B0.c: C that compiles but does not match */
/* The level's word is D_0015F40 and its byte D_001A7AFD; the block is the
 * boot's D_0012EA0, whose words at +0x221C and +0x2294 are D_00150BC and
 * D_00150B4.  The two `bnel`/`beql` slots carry the load of the entity's
 * sub-state, which the plain source does not reach; the branch order and the
 * register allocation differ as well. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_308590(void *a0);
extern void func_30EC98(u32 a0, u32 a1);
extern s32 func_33B410(void *a0, u32 a1);
extern void func_37B810(u32 a0, void *a1, void *a2);
extern void func_340D18(u32 a0, s32 a1);

extern u16 D_0015F40;
extern u8 D_001A7AFD;
extern u8 D_001A7A67;
extern u32 D_00150B4;
extern u32 D_00150BC;
extern u32 D_0012EA0;
extern u32 D_L18_001A903C;

void func_L18_003A0C28(u8 *entity) {
    u8 *state;
    u32 a0;
    u32 a1;

    state = *(u8 **)(entity + 0x68);
    if (entity[0x20] == 0) {
        entity[0x30] = 0xFF;
        *(u16 *)(state + 0xE) = 0x28;
        *(u16 *)(state + 0xC) = 0;
        entity[0x20] = 1;
    }
    if (D_0015F40 != 0)
        goto after;
    if (D_001A7AFD != 0) {
        if (func_308590(state + 0xE) != 0)
            func_30EC98(0xA27, 0x7E);
    }
after:
    if (entity[0x20] != 1)
        goto end;
    a0 = *(u32 *)(state + 0x8);
    if (a0 == 0) {
        a1 = *(u32 *)(state + 0x0);
        if (func_33B410((void *)D_0012EA0, a1) == 0)
            goto end;
        if (D_00150BC == 15) {
            *(u32 *)(state + 0x8) = entity[0x20];
            goto end;
        }
        goto end;
    }
    if (a0 == entity[0x20]) {
        *(u32 *)(state + 0x8) = 0;
        if (func_33B410((void *)(D_0012EA0 + 0x80), *(u32 *)(state + 0x4)) != 0)
            goto end;
        if (D_001A7A67 == 0) {
            func_37B810(1, 0, 0);
            func_340D18(0x1233, -1);
            D_001A7A67 = a0;
            D_L18_001A903C = a0;
        }
        goto end;
    }
    goto end;
end:
    return;
}
