/* Readable C reconstruction, measured 2026-10-23.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0/27, us2: 0/27, pal: not carried.
 * 512 bytes, retail544. Data-base reuse, mixed GP/absolute references and save-state copy scheduling differ.
 * Tried: Truthful C70-byte state buffers,16-byte parameter block and measured player/settings subfields, qualified qcopy/barrier with G8.
 * Reopen: A verified data-layout/declaration remedy for the retail mixed address forms.
 * Historical screening notes follow unchanged. No handwritten-assembly inference.
 */

/* func_L00_00358B30 - 544 bytes, 27 places (every level), retail at 0x00358B30.
 *
 * Screened, not matched in wave 13 (worker s1): 9 call(s), 1 `$gp`-relative small-data
 * access (`swc1 $f3, 0x29A0($gp)`), MMI words [lq `$v1` / sq `$a0`, lq `$v1` / sq `$a1`].
 * Two obstacles: the 16-byte copies are retail's materialised-pointer form (this cc1
 * always folds a constant offset into the lq/sq pair) and the `$gp` access needs a
 * `-G8` unit, so the body belongs in a `L00_00358B30-g8.c` file.  No C was written in
 * this wave.
 */

typedef int Quadword __attribute__((mode(TI)));
extern unsigned char D_00189E20[];
extern unsigned char D_00188660[];
extern unsigned short D_001A63F0 __attribute__((nosda));
extern unsigned char D_L00_0021DDB0[0xC70];
extern unsigned char D_L00_0021D140[0xC70];
extern int D_L00_001C9340 __attribute__((nosda));
extern unsigned char D_L00_001B1980[16];
extern float D_L00_001B1990;
extern unsigned char *D_L00_001B1E9C __attribute__((nosda));
extern unsigned char *D_L00_001B1EA0 __attribute__((nosda));
extern void *func_00282A60(void *, int, unsigned int);
extern void *func_00282AB0(void *, const void *, unsigned int);
extern void func_L00_00303530(int, int);
extern void func_00282A28(void);
extern void func_L00_002B2A40(int, int);
extern void func_002A0F48(void *);
extern void func_002833F0(void *, const void *);
extern void func_L00_002D9D98(void);
extern void func_L00_00358E50(void);

void func_L00_00358B30(void) {
    unsigned char *saved = D_L00_0021DDB0;
    unsigned char *player = D_00189E20;
    unsigned char *settings = D_00188660;
    unsigned char *entity;
    int kind;
    int i;
    player[0x22C6] = 15;
    if (*(int *)saved == 0) {
        func_00282A60(D_L00_0021D140, 0, 0xC70);
    } else {
        func_00282AB0(D_L00_0021D140, saved, 0xC70);
        *(Quadword *)(player + 0x80) = *(Quadword *)(saved + 0x10);
        *(Quadword *)(player + 0x90) = *(Quadword *)(saved + 0x20);
        *(int *)(*(unsigned char **)(player + 0x2290) + 0x38) = *(int *)(saved + 0x30);
        *(int *)(*(unsigned char **)(player + 0x2290) + 0x3C) = *(int *)(saved + 0x34);
        settings[0x6B] |= 7;
        D_001A63F0 = *(unsigned short *)(saved + 0xC64);
        *(int *)(settings + 0x64) = *(int *)(saved + 0x38);
        settings[0x68] = saved[0x3C];
        settings[0x69] = saved[0x3D];
        settings[0x6A] = saved[0x3E];
        if (D_L00_001C9340 != *(int *)(saved + 0xC68))
            func_L00_00303530(*(int *)(saved + 0xC68), *(int *)(saved + 0xC64));
        D_L00_001B1980[0] = saved[0x3F];
        D_L00_001B1980[1] = saved[0x40];
        D_L00_001B1980[2] = saved[0x41];
        *(float *)(D_L00_001B1980 + 4) = *(float *)(saved + 0x44);
        *(float *)(D_L00_001B1980 + 8) = *(float *)(saved + 0x48);
        *(float *)(D_L00_001B1980 + 12) = *(float *)(saved + 0x4C);
        D_L00_001B1990 = *(float *)(saved + 0x50);
        if (*(int *)(saved + 0x54) != 0 && *(int *)(saved + 0x54) != 3) {
            kind = 0;
            switch (*(int *)(saved + 0x54)) {
            case 1: kind = 0x57; break;
            case 2: kind = 0x1A3; break;
            default: func_00282A28(); break;
            }
            i = 0;
            while ((entity = D_L00_001B1E9C + (i << 8)) < D_L00_001B1EA0) {
                ++i;
                if (*(short *)(entity + 0xAA) == kind) {
                    func_L00_002B2A40(*(int *)(saved + 0x54), *(int *)(saved + 0x5C));
                    break;
                }
            }
        }
        func_002A0F48(*(unsigned char **)(player + 0x2290));
        func_002833F0(*(unsigned char **)(player + 0x2290) + 0xC0, player + 0x90);
        func_L00_002D9D98();
        func_L00_00358E50();
    }
}
