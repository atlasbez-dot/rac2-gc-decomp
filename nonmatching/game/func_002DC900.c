/* func_002DC900 (428 bytes, 28 places; catalogue entry 0x2DC908). Menu slot text.
   26 October 2026 (M32): 420/428 as a -G8 unit (the half-height word D_001ABBEC is a
   $gp read). Left: the slot index address sum order, retail's `(idx << 3) | 4` text
   entry address with the base added last, and the branchy half-offset (retail sets 0,
   then loads and halves in the not-taken path). */
typedef struct {
    char pad000[0x30];
    int value;
    char pad034[0x18];
} Slot_002DC900;

typedef struct {
    int unk0;
    int unk4;
} Text_002DC900;

extern char D_001393E0[];
extern char D_001F2840[];
extern Text_002DC900 D_00258D70[];
extern int D_001ABBEC __attribute__((sda));
extern void func_0027C540(long);
extern void func_0027C660(void);
extern char *func_00288FB8(int);
extern char *func_002DF1F8(char *, int);
extern void func_0027FAA8(int, int, unsigned long, char *, int);

/* Menu line for the current slot: prints its name (and the follow-up line)
   while the menu is in its listing state. */
int func_002DC900(int *box)
{
    char buf[64];
    char *s = D_001393E0;
    char *g = D_001F2840;
    int idx;
    int next;
    int y;
    int *text;

    idx = *(int *)((int)s + *(int *)(*(char **)(*(char **)(g + 0x14) + 0xE8) + 0x40) * 0x1C + 0x30) % 0x1C;
    func_0027C540(0);
    if (*(int *)(s + 0x15C) < 3 && *(int *)(s + 0x164) < 0 && *(int *)(g + 0x164) >= 11
        && *(int *)(s + 8) == 2) {
        if (idx == -1) {
            y = box[7] + D_001ABBEC / 2;
            func_0027FAA8(box[6], y, 0x80F0F0F0, func_00288FB8(0x2F14), -1);
        } else {
            text = (int *)(idx * 8 + 4 + (int)D_00258D70);
            next = *text;
            y = box[7] + (next < 0 ? D_001ABBEC >> 1 : 0);
            func_0027FAA8(box[6], y, 0x80F0F0F0, func_002DF1F8(buf, idx), -1);
            if (next >= 0) {
                y = box[7] + D_001ABBEC;
                func_0027FAA8(box[6], y, 0x80F0F0F0, func_00288FB8(*text), -1);
            }
        }
    }
    func_0027C660();
    return 2;
}
