/* Retained manual reconstruction, 2026-10-24.
 * Profile: -O2 -G8 -ffunction-sections.
 * Final measurements: us: 0/28 placements, exit1, 1208 compiled bytes; us2:
 * 0/28 placements, exit1, 1208 compiled bytes; pal: catalogue absent
 * (exit1).
 * Remaining: The full menu flow is retained. Retail uses an inline
 * rounding-mode cvt.w.s; this draft calls the existing, retail-qualified
 * func_00283CF0 converter to preserve its semantics. The resulting real
 * extra call and the remaining allocation/branch differences prevent a
 * match. PAL catalogue absence is not a successful check.
 * Reopen with: A qualified standard-C compiler mechanism for the inlined
 * rounding-mode conversion, followed by renewed allocation and whole-caller
 * checks.
 * No byte-match or linked-build credit is claimed.
 */
/* Radial-menu selection, navigation debounce, and exit-state transfer.
 * The rounding helper has the same cvt.w.s semantics as retail's inlined
 * conversion. Matching needs compiler support for that inlined conversion. */
extern void func_00287E60(void);
extern float func_00282C10(float);
extern float func_00283248(float, float);
extern int func_00283CF0(float);
extern int func_002A9588(int, int, int, int, int);
extern int func_002E5E58(int, int, void *);
extern void func_00287E18(void);
extern int func_0028B5D0(int);
extern char D_00138180[];
extern char D_00189E20[];
extern short D_001B189C, D_001B18A0, D_001B18A2, D_001B18A4;
extern int D_001B18D0;
extern int D_001A8D48;
extern int **D_001B18D4;
extern int D_001B8DC0, D_001B8DC4, D_001B8DB8, D_001B8DBC;
extern unsigned char D_001A7BB3;
extern int D_001B18FC, D_001B1900, D_001B18F8, D_001B1598;

void func_0028CCE0(unsigned char *object)
{
    float x, y, magnitude, angle;
    int old, choice;
    unsigned char *fade = object + 0x70;
    func_00287E60();
    *(int *)(object + 0x7C) = 180;
    *(int *)(object + 0x6C) = 24;
    *(int *)(D_00138180 + 0x1CC) = 2;
    x = *(float *)(D_00138180 + 0x148);
    y = *(float *)(D_00138180 + 0x14C);
    magnitude = func_00282C10(x * x + y * y);
    if (magnitude != 0.0f) {
        x /= magnitude;
        y /= magnitude;
    }
    angle = func_00283248(x, y);
    if ((*(int *)(object + 0x78) >> 24) == 0 && D_001B189C &&
        !(*(int *)(D_00138180 + 0x1C4) & 0xF000)) {
        if (!(magnitude < 0.5f)) {
            --*(int *)(object + 0x78);
            if (*(int *)(object + 0x78) == -1) {
                *(int *)(object + 0x74) = -1;
                *(int *)(object + 0x78) = 0x10000FF;
            }
        } else {
            *(int *)(object + 0x74) = -1;
            *(int *)(object + 0x78) = 0x10000FF;
        }
    }
    old = *(int *)(object + 0x74);
    if (*(signed char *)(object + 0x7B) == 1) {
        if (magnitude > 0.0f) {
            if (magnitude > 0.9f) {
                float sectors = (float)D_001B18D0;
                float phase = angle + 3.14159274101257324219f;
                phase += 3.14159274101257324219f;
                phase += 1.57079637050628662109f;
                phase += 3.14159274101257324219f / sectors;
                phase *= 0.15915493667125701904f;
                *(int *)(object + 0x74) = func_00283CF0(phase * sectors) % D_001B18D0;
            }
        } else if (*(int *)(D_00138180 + 0x1C4) & 0xF000) {
            choice = old;
            if (*(int *)(D_00138180 + 0x1C4) & 0x1000) {
                if (choice == -1) choice = D_001B8DC0;
                else choice = D_001B18D4[D_001A8D48][choice * 7 + 4];
            }
            if (*(int *)(D_00138180 + 0x1C4) & 0x4000) {
                if (choice == -1) choice = D_001B8DC4;
                else choice = D_001B18D4[D_001A8D48][choice * 7 + 5];
            }
            if (*(int *)(D_00138180 + 0x1C4) & 0x8000) {
                if (choice == -1) choice = D_001B8DB8;
                else choice = D_001B18D4[D_001A8D48][choice * 7 + 2];
            }
            if (*(int *)(D_00138180 + 0x1C4) & 0x2000) {
                if (choice == -1) choice = D_001B8DBC;
                else choice = D_001B18D4[D_001A8D48][choice * 7 + 3];
            }
            *(int *)(object + 0x74) = choice;
        }
    }
    if (*(int *)(object + 0x74) != old) {
        func_002A9588(0, 0, 1, 0, 1);
        fade[1] = 0;
        func_002E5E58(3, 0, 0);
    } else if (fade[1] < 8) ++fade[1];
    if (!(*(int *)(D_00138180 + 0x1C0) & 0x10)) {
        if (*(int *)(D_00138180 + 0x1C8) & 0x10) {
            int current = *(int *)(object + 0x74);
            *(int *)(D_00189E20 + 0x24E4) = current == -1 ? 0 :
                D_001B18D4[D_001A8D48][current * 7 + 6];
            if (D_001A7BB3) func_00287E18();
        }
        if (*fade) --*fade;
    } else if (*fade < 8) ++*fade;
    if (*(int *)(D_00189E20 + 0x24E4) == 6 && !D_001B18A0)
        *(int *)(D_00189E20 + 0x24E4) = 0;
    if (*(int *)(D_00189E20 + 0x24E4) == 7 && !D_001B18A4)
        *(int *)(D_00189E20 + 0x24E4) = 0;
    if (*(int *)(D_00189E20 + 0x24E4) == 5 && !D_001B18A2)
        *(int *)(D_00189E20 + 0x24E4) = 0;
    if (!*fade) {
        D_001B18FC = *(int *)(object + 0x78);
        D_001B1900 = *(int *)(object + 0x74);
        func_0028B5D0(*(int *)(object + 0x64));
        {
            int saved = D_001B1598;
            *(int *)(object + 0x6C) = -6;
            D_001B18F8 = saved;
        }
    }
}
