/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * The existing manual body below is preserved. A separately measured pointer-spelling
 * variant used this profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * That variant reported US 0/1; US2 0/1; PAL absent from catalogue. Its results are not a fresh
 * measurement of the preserved body. Both variants have the same recorded 952/960-byte residual.
 * Reopen only with independent source lifetime/allocation evidence beyond the historical
 * forms below. No declaration or body from that variant is substituted here.
 */

/* Historical analysis (summary).
 * Historical manual analysis measured 952/960 bytes, with 199 of 240 words aligned after
 * relocation normalization; that was not a match. The preserved body walks the group id list,
 * tests entities in local coordinates and updates the two player-relative paths. Remaining
 * differences were the swapped id/entity register roles, local projection-pointer allocation, a
 * constant lifetime and address materialization around the final vector transfer. Pointer
 * renaming, loop forms, flag types, declaration order and argument ordering tied. Extra
 * artificial tests changed allocation but did not provide a valid remedy. Reopen only with
 * independent lifetime/address evidence; the earlier instruction excerpts remain private.
 */

typedef unsigned short u16;
typedef int TI128 __attribute__((mode(TI)));

extern void func_00283698(void *dst, void *src);
extern void func_00282CF0(void *dst, void *a, void *b);
extern void func_002AFDD8(void *a, void *b, void *c, void *d);
extern float func_00282C48(float a);
extern void func_002830C0(void *dst, void *a, void *b);
extern float func_002A7878(float a, float b);
extern float func_00282C10(float a);
extern void func_00282D30(void *dst, void *src, float s);
extern void func_L14_003C96E0(char *e, void *v, float a, float b, float c);
extern void func_L00_002C42E0(int a0, int a1);
extern unsigned short *D_L14_001FB060[];
extern unsigned char *D_L14_001B259C __attribute__((sda));
extern int D_L14_001B25B8 __attribute__((sda));
extern char *D_L14_001B268C __attribute__((sda));
extern char D_00189E20[];
extern char D_00189EA0[];

void func_L14_003CB868(char *self) {
    float mtx[16];
    float off[4];
    float tmp[4];
    float vec[4];
    char *state = *(char **)(self + 0x68);
    unsigned short *p;
    unsigned char *e;
    char *hero;
    char *hero2;
    int inside;
    float a;
    float b;
    float c;

    func_00283698(mtx, self + 0xC0);
    for (p = D_L14_001FB060[*(int *)(state + 0x64)];
         (*(int *)(state + 0x64) & 0xFF) != 0xFF && *(int *)(state + 0x64) <= D_L14_001B25B8 &&
         p != 0 && ((p != 0 && (short)p[-1] >= 0) || p == D_L14_001FB060[*(int *)(state + 0x64)]);
         p++) {
        e = D_L14_001B259C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (e[0x20] != 0xFE) {
            if (e[0x20] != 0xFD) {
                func_00282CF0(off, e + 0x10, self + 0x10);
                func_002AFDD8(self, off, off, mtx);
                off[3] = 1.0f;
                off[0] = off[0] + 2.0f;
                inside = func_00282C48(off[0]) < 1.0f && func_00282C48(off[1]) < 1.0f;
                if (inside) {
                    func_002830C0(tmp, off, D_L14_001B268C + (*(int *)(state + 0x60) << 7));
                    func_L14_003C96E0((char *)e, tmp,
                                      *(float *)(D_L14_001B268C + (*(int *)(state + 0x60) << 7) + 0x38) +
                                          func_002A7878(1.0f, 2.0f),
                                      0.0055555557f, 0.0055555557f);
                }
            }
        }
    }
    hero = D_00189E20;
    if ((*(char **)(hero + 0x33C) == self && *(int *)(hero + 0x340) != 0) ||
        *(float *)(hero + 0x31C) < 0.5f) {
        func_00282CF0(off, D_00189EA0, self + 0x10);
        func_002AFDD8(self, off, off, mtx);
        off[3] = 1.0f;
        off[0] = off[0] + 2.0f;
        inside = func_00282C48(off[0]) < 1.0f && func_00282C48(off[1]) < 1.0f;
        if (inside) {
            func_002830C0(tmp, off, D_L14_001B268C + (*(int *)(state + 0x60) << 7));
            hero2 = D_00189E20;
            a = *(float *)(D_L14_001B268C + (*(int *)(state + 0x60) << 7) + 0x38) + 1.5f;
            b = (a - *(float *)(hero2 + 0x88)) * 2.0f;
            c = (a - tmp[2]) * 2.0f;
            func_00282CF0(vec, tmp, hero2 + 0x80);
            func_00282D30(vec, vec, 1.0f / (func_00282C10(b / 0.0055555557f) + func_00282C10(c / 0.0055555557f)));
            vec[2] = func_00282C10(b * 0.0055555557f);
            func_L00_002C42E0(0x44, 1);
            *(TI128 *)(D_00189E20 + 0xF0) = *(TI128 *)vec;
        }
    }
}
