/*
 * Near miss (M23, 2026-10-26): 880/880 bytes, 32 differing instructions, all in the timer loop
 * at the top; everything after the loop matches. us: 0/28.
 * Profile: -O2 -G32 -Wa,-G32 -ffunction-sections (a sibling of 002DB1B0-g32.c).
 * Residual: retail keeps the row address in $v1 across both arms and stores the new timer once at
 * the join (`sh $v0, 0xA($v1)`), the loaded halfword in $a0; this C reloads menu->rows for the
 * else arm's store. A row pointer per arm gets the join store but changes the loop's induction.
 */
typedef struct { char p00[0x14]; char *owner; int value; char p1c[0x118]; int fallback; } MenuRoot;
typedef struct { char reserved[0x1B4]; int alt; char p1b8[0xC]; int flags; } PadState;
typedef struct { short message; short action; int value; short pad8; unsigned short timer; } MenuRow;
typedef struct { char p00[0x30]; int flags; MenuRow *rows; int up; int down; int cursor; } ListMenu;

extern MenuRoot D_001F2840;
extern PadState D_00138180;
extern int D_001AA440 __attribute__((sda));
extern int D_001A79F0;
extern int D_001A7424;
extern int *D_001AA4F0;
extern void func_00295C50(int);
extern void func_0027D330(int);
extern void func_002C9C60(float);
extern int func_002D5E38(ListMenu *, int, int *);
extern int func_002E5E58(int, unsigned int, void *);

int func_002D5EC0(ListMenu *menu)
{
    int active = *(ListMenu **)(D_001F2840.owner + 0xE8) == menu;
    int i;
    int count;
    int old;
    int flags;
    int buttons;

    for (i = 0; menu->rows[i].message != 0; i++) {
        int timer;
        if (active && menu->cursor == i) {
            if ((short)menu->rows[i].timer < 32000)
                timer = menu->rows[i].timer + 1;
            else
                timer = 32000;
            menu->rows[i].timer = timer;
        } else {
            if (D_001AA440 < (short)menu->rows[i].timer)
                menu->rows[i].timer = D_001AA440;
            if ((short)menu->rows[i].timer > 0)
                timer = menu->rows[i].timer - 1;
            else
                timer = 0;
            menu->rows[i].timer = timer;
        }
    }
    if (!active)
        return 0;
    flags = D_00138180.flags;
    if (flags & 0x900) {
        if (menu->flags & 0x20)
            func_00295C50(D_001A79F0);
        return -1;
    }
    if (flags & 0x10) {
        int value;
        int status;
        if (menu->flags & 0x20)
            func_00295C50(D_001A79F0);
        value = *(int *)(D_001F2840.owner + 0xE0);
        if (value != 0)
            D_001F2840.value = value;
        else if (D_001F2840.fallback == 0) {
            status = -1;
            goto finish;
        }
        status = 0;
finish:
        return status;
    }
    if ((flags & 0x40) && ((D_001A7424 ^ 1) & 1)) {
        int result;
        if (menu->flags & 0x20) {
            func_0027D330(4);
            func_002C9C60(4.0f);
        }
        result = 0;
        if (func_002D5E38(menu, menu->rows[menu->cursor].action, &result) != 0)
            return result;
    }
    count = 0;
    while (menu->rows[count].message != 0)
        count++;
    old = menu->cursor;
    if (menu->flags & 1)
        buttons = D_00138180.alt;
    else
        buttons = D_00138180.flags;
    if ((buttons & 0x1000) || ((menu->flags & 0x100) && (buttons & 4))) {
        if (menu->cursor != 0)
            menu->cursor = menu->cursor - 1;
        else if (menu->flags & 0x1000)
            menu->cursor = count - 1;
        else
            *(int *)(D_001F2840.owner + 0x128) = menu->up;
    }
    if ((buttons & 0x4000) || ((menu->flags & 0x100) && (buttons & 8))) {
        int cur = menu->cursor;
        if (menu->rows[cur + 1].message != 0 && menu->rows[cur + 1].action != 0)
            menu->cursor = cur + 1;
        else if (menu->flags & 0x1000)
            menu->cursor = 0;
        else
            *(int *)(D_001F2840.owner + 0x128) = menu->down;
    }
    if (menu->cursor != old || *(int *)(D_001F2840.owner + 0x128) != 0) {
        func_002E5E58(3, 0, 0);
        if (menu->flags & 0x20)
            func_00295C50(D_001AA4F0[menu->cursor]);
    }
    return 0;
}
