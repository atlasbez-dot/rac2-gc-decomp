/* Retained C reconstruction, 2026-10-23. Not linked or counted.
   Profile: -O2 -G8 -ffunction-sections -fno-strength-reduce
   USA: 176/180 bytes, 0/27 placements; size differs from retail.
   us: 0/27, pal: 0/27, us2: 0/27.
   Revisit loop delay-slot selection; the skipped record advance remains missing.
*/
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
