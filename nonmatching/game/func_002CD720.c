/* from src/game/002CD620.c: 344 bytes against retail's 340, not matched.
 * Everything up to the second call matches, including the flag tests with the fallback
 * branch. Retail puts the high half of the 0x26 struct base into $s2 in the delay slot of
 * the second call and reuses the $v0 copy of it at the join; this cc1 places the lui after
 * the following branch and materialises it again at the join (+4 bytes). */
typedef struct {
    char reserved00[0x14];
    char *source;
    int value;
    char reserved1c[0x118];
    int fallback;
} CallbackState_002CD720;

typedef struct {
    char pad0[0x44];
    int f44;
    char pad48[8];
    int f50;
    int f54;
    int f58;
} State_0025E2B8_002CD720;

extern CallbackState_002CD720 D_001F2840;
extern int D_00138344;
extern State_0025E2B8_002CD720 D_0025E2B8;
extern char *D_0025E284;
extern int D_0025E464;
extern short D_001A63AC;
extern char *D_001A8CFC[] __attribute__((sda));
extern int func_00336EF0(void);
extern int func_0029C480(int);

int func_002CD720(void)
{
    int result = 0;
    int result1;
    int result2;
    int result3;
    int flags;
    int value;

    result1 = func_00336EF0();
    flags = D_00138344;
    if (flags & 0x10) {
        value = *(int *)(D_001F2840.source + 0xE0);
        if (value != 0)
            D_001F2840.value = value;
        else if (D_001F2840.fallback == 0) {
            result = -1;
            goto after_first;
        }
        result = 0;
    } else if (flags & 0x900) {
        result = 1;
    } else {
        func_0029C480(flags);
    }
after_first:
    if (D_001A8CFC[0] == 0)
        return result;
    result2 = func_00336EF0();
    if (result1 == result2 && D_001A63AC == 0 &&
        ((D_0025E2B8.f50 == result1 && D_0025E2B8.f44 == 2) ||
         (D_0025E2B8.f54 == result1 && D_0025E2B8.f44 == 4))) {
        *(int *)(D_0025E284 + 0x10) &= -5;
    } else {
        *(int *)(D_0025E284 + 0x10) |= 4;
    }
    if (result2 != result1)
        D_0025E464 = -0x22C;
    result3 = func_00336EF0();
    D_0025E2B8.f58 = result3;
    return result;
}
