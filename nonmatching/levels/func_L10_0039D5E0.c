/* Current nonmatching reconstruction; game compiler, -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
   us: 10_hrugis_cloud: instruction at +0x1c differs; func_L10_0039D5E0: 0 of 2 places match (src/levels/shared/L10_0039D5E0-copy.c).
   us2: 10_hrugis_cloud: instruction at +0x1c differs; func_L10_0039D5E0: 0 of 2 places match (src/levels/shared/L10_0039D5E0-copy.c).
   pal: func_L10_0039D5E0 is in neither catalogue of pal; func_L10_0039D5E0 is in neither catalogue of pal.
   Same 324-byte extent; three preserved integer arguments are assigned different saved registers from +0x1c. Reordering stores, an explicit timer pointer and -mno-split-addresses did not improve allocation. Retained profile is the original qcopy/barrier one. Reopen with a natural argument/field lifetime model.
   Historical screening comments below predate this measured C reconstruction. */
/* func_L10_0039D5E0 - 324 bytes, 2 place(s), level 10_hrugis_cloud, retail
   at 0x0039d5e0. Screened with tools/w10_screen.py: 1 call(s)
   [func_0029EFD0@0039D648]; data addresses materialised [0x1b0000]; float
   constants [-]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [LQ/SQ 7AC20000@0x00c0,
   LQ/SQ 7C620000@0x00c4, LQ/SQ 7AE20000@0x00cc, LQ/SQ 7C820000@0x00d0].
   Head: addiu $sp, $sp, -0x70 ; sd $s7, 0x38($sp) ; sd $s0, 0x0($sp) ;
   daddu $s7, $a0, $zero ; sd $s1, 0x8($sp) ; daddu $s0, $a3, $zero. Not
   matched in this wave: the 128-bit copy needs an `lq`/`sq` pair; plain C
   reaches it only through a `mode(TI)` local, and this cc1 folds the
   destination offset into the `sq` where retail materialises the pointer
   first. What would unblock it: the exact source expression tree, so this
   cc1 picks the same registers in the same order. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef int Quad __attribute__((mode(TI)));
extern void *func_0029EFD0(s32);
extern short D_L10_001B2DB8[4];

/* Creates a strip-effect object with its supplied vectors and rendering parameters. */
void *func_L10_0039D5E0(void *position, void *direction, s32 duration, s32 kind,
                       s32 first, s32 second, s32 third, s32 texture,
                       float jitter, float width, float height, float fade) {
    u8 *object = func_0029EFD0(0x133E);
    char *state;
    int i;
    if (object) {
        state = *(char **)(object + 0x68);
        object[0x30] = 255;
        *(u16 *)(object + 0x32) = 255;
        object[0x31] = 1;
        object[0x20] = 0;
        *(s32 *)(state + 0x2C) = kind;
        *(s32 *)(state + 0x10) = duration;
        *(s32 *)(state + 0x14) = first;
        *(s32 *)(state + 0x18) = second;
        *(s32 *)(state + 0x1C) = third;
        *(float *)(state + 0x20) = width;
        *(float *)(state + 0x24) = height;
        *(float *)(state + 0x28) = fade;
        *(s32 *)(state + 0x30) = texture;
        *(float *)(state + 0x34) = jitter;
        *(Quad *)state = *(Quad *)direction;
        *(Quad *)(object + 0x10) = *(Quad *)position;
        for (i = 2; i >= 0; i--) D_L10_001B2DB8[i] = -1;
    }
    return object;
}
