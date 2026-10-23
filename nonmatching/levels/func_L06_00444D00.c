/* Near miss from src/levels/shared/L06_0035EA68.c: 388 bytes, expected 400; 0 of 10 places.
   Kept as a starting point; not linked, not counted.

   The body, the three walks and the calls are right in outline. What still differs against
   retail (level 06 at 0x00444D00):
   - retail's frame is 0x50 and it saves $s0-$s6; here the frame is 0x60 and $s7 is saved
     as well, because the value of the field at 0x95 has to survive the call to
     func_L00_00329520 (retail keeps it in $v1 and only uses it in a block that is never
     reached), so this body is four instructions short;
   - retail's tests of the flag, of the field at 0xBC and of the field at 0x20 are laid out
     as a chain of branches that all end in the same store, with a fourth, unreachable
     test of the flag; the source that produces that shape is not found yet;
   - retail's walk over the four entries at the state's 0x10 and over the thirteen entries
     at the state's 0x44 count down from 12 and 13, and both use the state's words as
     32-bit values with -1 as the end marker; here the counters and the pointers come out
     in another order.

   The level's globals (0x1B9840 and 0x189EA0) and the calls to func_L00_00329520,
   func_L01_003909E0 and func_L01_003907B8 have a different address in every level, so
   they are refs here. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef int TI128 __attribute__((mode(TI)));

extern const char ref_L06_00444D00_00[];

extern const char ref_L06_00444D00_01[];

extern s32 ref_L06_00444D00_02(void *, s32);

extern void ref_L06_00444D00_03(void *, void *, s32);

extern void ref_L06_00444D00_04(s32, void *, s32);

void func_L06_00444D00(char *object)
{
    char *state;
    const char *src;
    TI128 buf;
    s32 flag = 0;
    s32 i;
    s32 j;
    s32 k;
    s32 *p;
    s32 v;
    s32 found;

    state = *(char **)(object + 0x68);
    *(u8 *)(object + 0x30) = 0xFF;
    if (state[0x7E])
        src = ref_L06_00444D00_00;
    else
        src = ref_L06_00444D00_01;
    buf = *(TI128 *)src;
    found = object[0x95];
    v = 1;
    i = 0;
    p = (s32 *)state;
    do {
        i++;
        if (i >= 4)
            break;
        if (*p == -1)
            continue;
        v = ref_L06_00444D00_02(&buf, *p);
        if (v == 0)
            continue;
        flag = (found == v);
        break;
    } while (1);

    if (flag != 0) {
        if (object[0xBC] != 0) {
            if (object[0x20] == 0) {
                if (flag == 0)
                    *(u8 *)(object + 0xBC) = v;
                else {
                    *(u8 *)(object + 0xBC) = 1;
                    *(u8 *)(object + 0xBC) = 0;
                }
            } else {
                *(u8 *)(object + 0xBC) = object[0x20];
            }
        } else {
            *(u8 *)(object + 0xBC) = v;
        }
    } else {
        *(u8 *)(object + 0xBC) = v;
    }

    p = (s32 *)((char *)state + 0x10);
    j = 12;
    do {
        if (*p != -1)
            ref_L06_00444D00_03(object, state, flag);
        j--;
        p++;
    } while (j >= 0);

    p = (s32 *)((char *)state + 0x44);
    k = 13;
    do {
        if (*p != -1)
            ref_L06_00444D00_04(*p, state, flag);
        k--;
        p++;
    } while (k >= 0);
}
