/* USA v1.01, 164 bytes, 0/28 placements. Best trial uses -G8.
 * Six compiles total, including one stub. Three final source wordings emitted
 * identical bytes. First difference +0x70: update pointer in a0 instead of v1,
 * update value in v1 instead of v0; six instructions differ in that tail.
 * Named first-path pointer and nosda output binding recover the entire prefix.
 * Reopen with concrete lifetime/allocation evidence for the second update path.
 */
typedef struct {
    char reserved00[0x14];
    char *source;
    int value;
    char reserved1c[0x118];
    int fallback;
} CallbackState;
typedef struct { char reserved00[0x1C4]; int flags; } MenuGameState;
extern MenuGameState D_00138180;
extern CallbackState D_001F2840;

extern unsigned char D_001A7BB4;
extern int D_0025E0B0 __attribute__((nosda));

int func_002D5048(int selection)
{
    CallbackState *state = &D_001F2840;
    D_0025E0B0 = D_001A7BB4;
    if (*(int *)(state->source + 0xE8) != selection)
        return 0;
    if ((D_00138180.flags & 0x900) && state->fallback == 0)
        return 1;
    if (D_00138180.flags & 0x10) {
        CallbackState *update = &D_001F2840;
        int value = *(int *)(update->source + 0xE0);
        if (value != 0)
            update->value = value;
        else if (update->fallback == 0) {
            value = -1;
            goto return_value;
        }
        value = 0;
return_value:
        return value;
    }
    return 0;
}
