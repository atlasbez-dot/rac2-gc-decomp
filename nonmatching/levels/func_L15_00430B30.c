/* Near-miss twins: 336 bytes, expected 332, 0 of 1 place each (level 15 gorn).
 *
 * Profile: -O2 -G8 -ffunction-sections.
 * Last verdict: `python scratch/wslcmp.py src/levels/15_gorn/L15_00315428-g8.c func_L15_00430B30`
 *   func_L15_00430B30: 0 of 1 places match   [15_gorn: 336 bytes, expected 332]
 *
 * Remaining difference: the block base register.  Retail keeps 0x220000 in
 * $s3 and makes one copy for the loop; this cc1 materialises the same base in
 * $s6 and keeps a second register alive, one instruction over.  The list walk,
 * the two material calls and the stage report match.
 */
/* The two material passes over the level's live-object list: the first one at
   boot time, the second one when the countdown stage is armed.  Each walks the
   list the level published, patches the objects that carry its material id and
   then reports the pass to the stage when the countdown is over. */
extern char D_L15_00220000[];
extern int D_L15_001B2714;
extern int D_L15_001B2148;
extern void func_002B7320(void);
extern void func_L05_0037B210(void);
extern void func_L05_00379F18(int);
extern char *func_L05_00379EB8(void);
extern int func_L00_004272A0(void);
extern void func_L05_0037B280(char *, int);
extern void func_L05_0037CEE0(char *, char *, float);
extern void func_L05_0037D608(char *, char *, float);
extern void func_L15_00430590(char *, int);

void func_L15_00430B30(char *obj)
{
    char *list;
    int count;

    if (D_L15_001B1534 != 0)
        return;
    *(int *)(D_L15_00220000 + 0x1E10 + 0x2C) = 0;
    D_L15_001B1534 = 1;
    func_002B7320();
    func_L05_0037B210();
    func_L05_00379F18(0);
    list = func_L05_00379EB8();
    count = func_L00_004272A0();
    if (count > 0) {
        do {
            char *item = *(char **)list;

            if (*(short *)(item + 0xAA) == 0xF93) {
                func_L05_0037B280(item, 1);
                func_L05_0037CEE0(item,
                            (char *)D_L15_001B2714
                                + (*(int *)(D_L15_00220000 + 0x1E10 + 0x10) << 7) + 0x30,
                            32.0f);
                func_L05_0037D608(item,
                            (char *)D_L15_001B2714
                                + (*(int *)(D_L15_00220000 + 0x1E10 + 0x10) << 7) + 0x30,
                            32.0f);
            }
            count--;
            list += 4;
        } while (count != 0);
    }
    if (*(int *)(D_L15_00220000 + 0x1E10 + 0x10) == 0 && D_L15_001B2148 >= 6)
        func_L15_00430590(obj, 1);
}

extern char *func_L05_0037B440(int, int);
extern void func_L15_00435E80(char *);
extern void func_L15_00436090(char *);
extern char *func_L05_00379ED0(int);
extern int func_L15_00381CF0(char *);

void func_L15_00430C80(char *obj)
{
    char *list;
    int count;
    char *made;

    if (D_L15_001B1534 != 0)
        return;
    *(int *)(D_L15_00220000 + 0x1E10 + 0x2C) = 0;
    D_L15_001B1534 = 1;
    func_002B7320();
    func_L05_0037B210();
    func_L05_00379F18(0);
    list = func_L05_00379EB8();
    count = func_L00_004272A0();
    if (count > 0) {
        do {
            char *item = *(char **)list;

            if (*(short *)(item + 0xAA) == 0x957) {
                func_L05_0037B280(item, 1);
                func_L05_0037CEE0(item,
                            (char *)D_L15_001B2714
                                + (*(int *)(D_L15_00220000 + 0x1E10 + 0x10) << 7) + 0x30,
                            32.0f);
                func_L05_0037D608(item,
                            (char *)D_L15_001B2714
                                + (*(int *)(D_L15_00220000 + 0x1E10 + 0x10) << 7) + 0x30,
                            32.0f);
            }
            count--;
            list += 4;
        } while (count != 0);
    }
    made = func_L05_0037B440(0x1211, 1);
    if (made != 0) {
        func_L15_00435E80(made);
        func_L15_00436090(made);
    }
    func_L15_00381CF0(func_L05_00379ED0(0x1211));
    if (*(int *)(D_L15_00220000 + 0x1E10 + 0x10) == 0 && D_L15_001B2148 >= 6)
        func_L15_00430590(obj, 2);
}
