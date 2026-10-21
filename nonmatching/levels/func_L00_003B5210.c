/* func_L00_003B5210 (180 bytes, 27 places) -- NEAR MISS, not integrated.  G8

   New measurement (wave 12, worker s4): the `-g8` route works for the two angle
   constants - in a `-G8` sibling (`L00_003B5210-g8.c`) with

       extern float D_L00_001AFA00 __attribute__((sda));
       extern float D_L00_001AFA04 __attribute__((sda));

   they come out as retail's bare `lwc1 $f12,0xA10($gp)` and
   `lwc1 $f13,0xA14($gp)` (no `-mno-split-addresses` needed here), and the
   absolute 0x001B28D8 stays `lui $at,0x1B ; lwc1 $f12,0x28D8($at)`.

   What is left is the annulled delay slot, the same wall as
   func_L00_003B60E8: retail's `beql $v0,$zero` duplicates the `p += 0x50` into
   its annulled slot (executed only on the skipped path) and keeps the fall-through
   copy after the call, while this cc1 emits a plain `beqz` and merges the two
   increments into the loop tail.  Writing the increment in both arms of the `if`
   gives 188 bytes (the tail merging and the extra branch), so it is not that
   either; three spellings measured (the increment common, in both arms, and the
   `continue` form).

   The three pointers' declaration order does decide the callee-saved registers
   (s1 = the short array 0x001B28B0, s2 = the record 0x0023D9E0, s3 = the second
   array 0x001B28B8), as the earlier wave measured.

   Wave 12 (worker s4). */
extern short D_L00_001B28B0[];
extern short D_L00_001B28B8[];
extern float D_L00_001B28D8;
extern char D_L00_0023D9E0[];
extern float D_L00_001AFA00 __attribute__((sda));
extern float D_L00_001AFA04 __attribute__((sda));
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern void func_L00_003B52C8(void *, int, int, int, float, float, float);

void func_L00_003B5210(void)
{
    short *r = D_L00_001B28B8;
    char *p = D_L00_0023D9E0;
    short *q = D_L00_001B28B0;
    int i;

    for (i = 3; i >= 0; i--) {
        if (*q != 0) {
            int v = func_00283CF0(func_00283CE0(*r) * D_L00_001B28D8);

            func_L00_003B52C8(p, v, v, 5, D_L00_001AFA00, D_L00_001AFA04, 0.2f);
        }
        p += 0x50;
        r++;
        q++;
    }
}
