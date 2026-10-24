/* Current nonmatching reconstruction; game compiler, -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
   us: 18_damosel: 240 bytes, expected 244; func_L18_003F8EA8: 0 of 3 places match (src/levels/shared/L18_003F8EA8-copy.c).
   us2: 18_damosel: 240 bytes, expected 244; func_L18_003F8EA8: 0 of 3 places match (src/levels/shared/L18_003F8EA8-copy.c).
   pal: 18_damosel: 240 bytes, expected 244; func_L18_003F8EA8: 0 of 3 places match (src/levels/shared/L18_003F8EA8-copy.c).
   240 bytes against 244. The copy and index transitions are present; f20 is moved into a branch delay slot where retail saves it before the copy and keeps a nop. Qcopy, qcopy/barrier and debug profiles did not close the gap. Reopen with a natural explanation of that scheduling.
   Historical screening comments below predate this measured C reconstruction. */
/* func_L18_003F8EA8 - 244 bytes, 3 place(s), level 18_damosel, retail at
   0x003f8ea8. Screened with tools/w10_screen.py: 2 call(s)
   [func_L02_002F21C0@003F8EF8, func_L02_002F21C0@003F8F40]; data addresses
   materialised [0x200000]; float constants [-]; $gp-relative small data: no
   saves: -; callee-saved registers saved [-]; words plain C cannot emit
   [LQ/SQ 78620000@0x0040, LQ/SQ 7CA20000@0x0044]. Head: addiu $sp, $sp,
   -0x30 ; lui $v0, 0x20 ; sd $s0, 0x0($sp) ; addiu $v0, $v0, -0x1B80 ; swc1
   $f20, 0x20($sp) ; daddu $s0, $a3, $zero. Not matched in this wave: the
   128-bit copy needs an `lq`/`sq` pair; plain C reaches it only through a
   `mode(TI)` local, and this cc1 folds the destination offset into the `sq`
   where retail materialises the pointer first. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */

typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef float f32;
typedef int Quad __attribute__((mode(TI)));
extern char *D_L18_001FE480[];
extern f32 func_L02_002F21C0(char *, char *);

/* Advances or reverses a waypoint index when the object reaches the current point. */
s32 func_L18_003F8EA8(char *self, char *point, s32 route, s16 *index, s32 reverse, f32 radius) {
    char *path = D_L18_001FE480[route];
    *(Quad *)point = ((Quad *)(path + 16))[*index];
    if (reverse) {
        if (func_L02_002F21C0(self + 16, point) < radius * radius) --*index;
        if (*index < 0) {
            *index = *(u16 *)path - 1;
            return 0;
        }
    } else {
        if (func_L02_002F21C0(self + 16, point) < radius * radius) ++*index;
        if (*index >= *(s32 *)path) {
            *index = 0;
            return 0;
        }
    }
    return 1;
}
