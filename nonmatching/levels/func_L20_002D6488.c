/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * 1944/2044 bytes. us: 0/1 places; us2: 0/1 places; pal: absent.
 * Remaining: Input/history counter branches, zero-history increment and fresh level-flag
 * reads are corrected against retail. The object cursor advances one EE
 * pointer, the 9999 store precedes its early-out, signed history remainders
 * select the proper nonnegative operand, and ordered float guards preserve
 * NaN behavior. Both transforms receive every destination/source/FP input.
 * Modes 1 and 4 share the first transform and scalar-pair arms; both
 * transform variants use D_00189F00, and every other mode takes the
 * second transform and flag-selected scalar pair.
 * The final mode-dependent clear uses !=0x2E. Real timer widths, canonical
 * callees and complete vector transfers remain retained. The 0x80 frame
 * agrees, but resident bases, loop layout and scalar allocation differ.
 * Reopen with: Independent resident-base and loop lifetime evidence. Preserve the
 * corrected guards, modulo sign handling, pointer stride and full contracts;
 * no semantic equivalence beyond the reviewed paths is asserted.
 */

#include "common.h"



extern char D_00189E20[];
extern char D_00138180[];
extern char D_00189EA0[];
extern char D_00189F00[];

extern char *D_L20_001FBEE0[];
extern char D_L20_00267060[];

extern u8 D_001A7AFF;

extern int D_L20_001A8F00 __attribute__((sda));
extern int D_L20_001A8F00_1 __asm__("D_L20_001A8F00") NOT_SDA;

extern int D_L20_001B2AC8 __attribute__((sda));
extern int D_L20_001B2AC8_1 __asm__("D_L20_001B2AC8") NOT_SDA;

extern float D_L20_001B29E0;
extern float D_L20_001B29E4 __attribute__((sda));
extern float D_L20_001B29E4_1 __asm__("D_L20_001B29E4") NOT_SDA;

extern void func_L00_002B9380(void);
extern int func_00282978(s16 *);
extern int func_00282948(s32 *);
extern void func_L00_002A7A10(void);
extern s32 func_002ABB78(void *);
extern s32 func_002A77E0(s32);
extern f32 func_00282E48(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, f32);
extern void func_002A8F70(void *, void *, s32, void *, void *, f32);
extern f32 func_L00_002D3B00(void *);
extern void func_00282C88(void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282D30(void *, void *, f32);
extern f32 func_00282DF0(void *);
extern void func_L00_002C3838(void);
extern void func_L00_002D36E0(f32 *, s32, f32, f32, f32);
extern void func_L00_002D3778(void *, void *, f32);
extern void func_L00_002B30E8(void);
extern void func_L20_002D7730(s32, s32);

void func_L20_002D6488(void)
{
    char *p = D_00189E20;
    char *q;
    char *r;
    char *r2;
    char *s = D_00189EA0;
    char **u;
    char *s2 = D_00189EA0;
    s16 kind;
    char *w;
    char *t;
    s32 i;
    s32 n;
    s32 x;
    f32 buf[4];
    f32 buf2[4];
    f32 f20v;
    f32 f1v;

    if (*(u8 *)(p + 0x22BD) == 0) {
        func_L00_002B9380();
    }

    *(s32 *)(p + 0x1B8) += 1;
    *(s32 *)(p + 0x1BC) += 1;
    *(s32 *)(p + 0x1C0) += 1;
    *(s32 *)(p + 0x1C4) += 1;

    func_00282978((s16 *)(p + 0x1E0));
    func_00282978((s16 *)(p + 0x1DC));
    func_00282978((s16 *)(p + 0x1D2));
    func_00282978((s16 *)(p + 0x1E4));
    func_00282978((s16 *)(p + 0x1F8));
    func_00282978((s16 *)(p + 0x1FE));
    func_00282948((s32 *)(p + 0x1D4));
    func_00282978((s16 *)(p + 0x210));
    func_00282978((s16 *)(p + 0x1D0));
    func_00282978((s16 *)(p + 0x1F4));
    func_00282978((s16 *)(p + 0x1F6));
    func_00282978((s16 *)(p + 0x204));
    func_00282978((s16 *)(p + 0x206));
    func_00282978((s16 *)(p + 0x1F0));
    func_00282978((s16 *)(p + 0x1EC));
    func_00282978((s16 *)(p + 0x1EE));
    func_00282978((s16 *)(p + 0x208));
    func_00282978((s16 *)(p + 0x200));
    func_00282978((s16 *)(p + 0x20E));
    func_00282978((s16 *)(p + 0x20A));
    func_00282978((s16 *)(p + 0x214));
    func_00282978((s16 *)(p + 0x212));
    func_00282978((s16 *)(p + 0x1FC));
    func_00282978((s16 *)(p + 0x216));
    func_00282978((s16 *)(p + 0x1FA));
    func_00282978((s16 *)(p + 0x218));
    func_00282978((s16 *)(p + 0x1F2));
    func_00282978((s16 *)(p + 0x21A));
    func_00282978((s16 *)(p + 0x21C));
    func_00282978((s16 *)(p + 0x1DE));
    func_00282978((s16 *)(p + 0x1E6));
    func_00282978((s16 *)(p + 0x222));
    func_00282978((s16 *)(p + 0x224));
    func_00282978((s16 *)(p + 0x226));

    r = D_00138180;

    if (!(*(s32 *)(r + 0x1A0) & 4)) {
        *(u16 *)(p + 0x20C) = 0;
    }

    if (*(s16 *)(p + 0x21C) != 0) {
        func_L00_002A7A10();
    }

    r2 = D_00138180;

    if (*(u8 *)(p + 0x22B8) == 0) {
        *(s32 *)(p + 0x1D8) = 0;
    } else {
        *(s32 *)(p + 0x1D8) += 1;
    }

    q = D_00189E20;

    if (*(s32 *)(r2 + 0x1D4) != 0) {
        n = *(s32 *)(q + 0x1CC);
        *(s32 *)(q + 0x1C8) = 0;
        *(s32 *)(q + 0x1CC) = n + 1;
    } else {
        n = *(s32 *)(q + 0x1C8);
        *(s32 *)(q + 0x1CC) = 0;
        *(s32 *)(q + 0x1C8) = n + 1;
    }

    if (*(u8 *)(q + 0x22C3) != 0 && *(s32 *)(q + 0x229C) == 0 && *(s32 *)(q + 0x340) != 0) {
        if (*(f32 *)(q + 0x170) < 0.0016666668f) {
            if (*(f32 *)(q + 0x184) < 0.0016666668f) {
                qcopy((q + 0x80), (q + 0x2030));
            }
        }
    }

    if (*(s16 *)(q + 0x1454) == 0) {
        *(s32 *)(q + 0x1E8) += 1;
    } else {
        *(s32 *)(q + 0x1E8) = 0;
    }

    if (*(s32 *)(q + 0x24CC) != 0) {
        if (D_L20_001A8F00 != 0) {
            goto after_flag;
        }
        if (*(u8 *)(q + 0x22B4) == 4) {
            if (*(s32 *)(q + 0x2294) == 0x6F) {
                goto load_flag;
            }
            if (!(*(s32 *)(r2 + 0x1A4) & 0x10)) {
                goto load_flag;
            }
            *(s32 *)(q + 0x24CC) = 0;
            *(u16 *)(q + 0x1E0) = 0;
            func_L20_002D7730(0x91, 1);
        }
        goto check_flag;
    }
load_flag:
check_flag:
    n = D_L20_001A8F00_1;
    if (n != 0) {
        goto after_flag;
    }
    if (0.0f < D_L20_001B29E0) {
        *(u16 *)(q + 0x22A) += 1;
    } else {
        *(u16 *)(q + 0x22A) = 0;
    }
    f1v = D_L20_001B29E4;
    if (*(s16 *)(q + 0x22A) >= 0x79) {
        *(int *)&D_L20_001B29E0 = 0;
        *(u16 *)(q + 0x22A) = 0;
        f1v = D_L20_001B29E4_1;
    }
    if (0.0f < f1v) {
        *(u16 *)(q + 0x228) += 1;
    } else {
        *(u16 *)(q + 0x228) = 0;
    }
    if (*(s16 *)(q + 0x228) >= 0x79) {
        *(u16 *)(q + 0x228) = 0;
        D_L20_001B29E4_1 = 0;
    }
after_flag:

    if (*(s16 *)(q + 0x224) == 0) {
        goto end_objects;
    }

    u = D_L20_001FBEE0;
    t = *u;
    if (t == 0) {
        goto end_objects;
    }
    f20v = 15.37f;
    kind = 0x16;
    s2 = D_00189EA0;
    w = D_00189E20;
object_loop:
    if (func_002ABB78(t) == 0) {
        if (*(s32 *)(t + 0x24) != 0) {
            if (*(s16 *)(*(s32 *)(t + 0x24) + 0x46) == kind) {
                goto have_value;
            }
        }
        goto next;
    }
have_value:
    if ((D_L20_001B2AC8 & 7) != (((s32)t >> 8) & 7)) {
        if (func_002A77E0(4) != 0) {
            goto next;
        }
    }
    {
        f32 f = func_00282E48(s2, t + 0x10);

        if (f < f20v) {
            func_00282CF0(buf, t + 0x10, s2);
            func_00282F20(buf, buf, 1.7f);
            func_002A8F70(t, *(void **)(w + 0x2290), 0x04000000, s2, buf, 1.0f);
        }
    }
next:
    ++u;
    t = *u;
    if (t != 0) {
        goto object_loop;
    }
end_objects:

    for (w = D_L20_00267060; w < D_L20_00267060 + 0x1C0; w += 0x70) {
        func_00282948((s32 *)(w));
    }

    *(f32 *)(q + 0x24DC) = 9999.0f;
    if (*(s16 *)(q + 0x34E) == 0) {
        goto no_frames;
    }
    {
        f32 f = func_L00_002D3B00(q + 0xF0);

        if (!(f < 0.0f)) {
            goto no_frames;
        }
    }
    if (*(s32 *)(q + 0x23C8) == 0x20) {
        func_00282C88(buf);
        i = 0;
        x = *(s32 *)(q + 0x23C4);
frame_loop:
        {
            s32 d;
            s32 a;
            s32 b;
            s32 c;
            s32 e;
            s32 p1;
            s32 p2;

            d = x - i;
            a = d + 0x1F;
            b = d + 0x1E;
            c = d + 0x3D;
            e = d + 0x3E;
            if (b >= 0) {
                c = b;
            }
            if (a >= 0) {
                e = a;
            }
            p1 = a - ((e >> 5) << 5);
            p2 = b - ((c >> 5) << 5);
            func_00282CF0(buf2, q + 0x1D90 + (p1 << 4), q + 0x1D90 + (p2 << 4));
            func_00282CC0(buf, buf, buf2);
        }
        i++;
        x = *(s32 *)(q + 0x23C4);
        if (i < 8) {
            goto frame_loop;
        }
        func_00282D30(buf, buf, 0.125f);
        {
            f32 f = func_00282DF0(buf);

            if (f < 0.016666668f) {
                *(u16 *)(q + 0x202) += 1;
            } else {
                *(u16 *)(q + 0x202) = 0;
            }
        }
    }
no_frames:

    func_L00_002C3838();

    if (*(u8 *)(q + 0x22B4) == 1 || *(u8 *)(q + 0x22B4) == 4) {
        func_L00_002D36E0((f32 *)D_00189F00, 1, 0.0f, 0.0f, 0.4f);
    } else {
        func_L00_002D36E0((f32 *)D_00189F00, 1, 0.0f, 0.0f, 0.7f);
    }

    if ((D_L20_001B2AC8 & 3) == 0) {
        if (*(u8 *)(q + 0x22B4) == 1 || *(u8 *)(q + 0x22B4) == 4) {
            *(f32 *)(q + 0x24A4) = 2.125f;
            *(f32 *)(q + 0x24A8) = 1.25f;
        } else {
            if (D_001A7AFF) {
                *(f32 *)(q + 0x24A4) = 14.0f;
                *(f32 *)(q + 0x24A8) = 4.5f;
            } else {
                *(f32 *)(q + 0x24A4) = 4.25f;
                *(f32 *)(q + 0x24A8) = 2.25f;
            }
        }
    }

    {
        f32 f = *(f32 *)(q + 0x31C);

        if (f < 4.0f) {
            qcopy((q + 0xD0), (q + 0x2D0));
            func_L00_002D3778(q + 0xD0, q + 0xD0, 0.5f);
        } else {
            qcopy((q + 0xD0), (q + 0xE0));
        }
    }

    {
        s32 ptr = *(s32 *)(q + 0x5C0);

        if (ptr != 0) {
            if (!(*(u16 *)(ptr + 0x34) & 0x1000)) {
                *(s32 *)(q + 0x5C0) = 0;
            } else if (ptr == *(s32 *)(q + 0x33C)) {
                *(s32 *)(q + 0x5C0) = 0;
            }
        }
    }
    if (*(s32 *)(q + 0x5C0) != 0) {
        if (*(s32 *)(q + 0x1248) != 0x2E) {
            *(s32 *)(q + 0x5C0) = 0;
        }
    }

    if (*(f32 *)(q + 0x88) < 1.0f) {
        func_L00_002B30E8();
    }
}
