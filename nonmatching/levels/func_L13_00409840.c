/* func_L13_00409840: M3 2026-10-26: rewritten (the old draft mixed up the arms): 348/348, 13 register-only lines, only the two parameters swap $s1/$s2. Callee func_L13_004094C0 is func_L00_003BFF58. In the permuter queue.
 */
typedef struct {
    char pad0[0xC4];
    char *path;
    short cur;
    short goal;
} Walk_409840;

extern Walk_409840 *func_L00_003BFF58(char *, char *);
extern int func_002B6228(void *, void *, int, int);
extern void func_L13_004095F8(void *, void *);
extern float func_00282E80(void *, void *);
extern int D_001A79F0 __attribute__((section(".sdata")));

int func_L13_00409840(char *obj, char *path)
{
    Walk_409840 *w = func_L00_003BFF58(obj, path);

    if (w == 0)
        return 0;
    if (path != w->path)
        func_002B6228(obj, path, -1, 0);
    if (D_001A79F0 == 0x45) {
        func_L13_004095F8(obj, path + (w->cur * 16 + 0x10));
        if (func_00282E80(obj + 0x10, path + (w->cur * 16 + 0x10)) <= 0.5f) {
            if (w->goal == w->cur)
                return 1;
            if (w->goal < w->cur)
                w->cur = w->cur - 1;
            else
                w->cur = w->cur + 1;
        }
    } else {
        func_L13_004095F8(obj, path + (w->goal * 16 + 0x10));
        if (func_00282E80(obj + 0x10, path + (w->goal * 16 + 0x10)) <= 0.5f) {
            if (w->goal == w->cur)
                return 1;
            if (w->goal < w->cur)
                w->cur = w->cur - 1;
            else
                w->cur = w->cur + 1;
        }
    }
    return 0;
}
