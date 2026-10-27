/* Retained near miss; not matching.
 * Profile: -O2 -G0 -ffunction-sections. 856/860 bytes, US 0/27.
 * M8, 26 October 2026: the D_L00_001B1BBC clear is retail's `lui $at; sw` store kept out of
 * the copy's slots, which an sda object at a nonzero offset reproduces (D_L00_001B1BB8[1]);
 * the item fields go through a 28-byte ShopItem view. That fixes the opening copy and
 * leaves about 35 instructions: retail computes model + index*28 twice (once into $v0 for the
 * price, again into $s1 for the name) while this source CSEs it into one register, and the
 * 4-byte gap sits in that tail.
 */
typedef struct { unsigned int word[4]; } PanelColors;
typedef struct { int price; int pad[3]; unsigned char *name; int pad2[2]; } ShopItem;
extern PanelColors D_L00_001AD768;
extern char D_L00_0022F7C0[];
extern float D_L00_001B25E0 __attribute__((sda));
extern int D_L00_001B1BB8[] __attribute__((sda));
extern int D_001A7340 __attribute__((sda));
extern int D_001A79FC __attribute__((sda));
extern int func_0028E588(int, int);
extern void func_0028EA58(int, int, int, int, int, unsigned int *);
extern int func_00288FB8(int);
extern void func_0027FA10(int, int, unsigned long long, unsigned char *, int);
extern void func_002F9BC0(char *, int);
extern void func_0027F5B8(int, int, unsigned long long, unsigned char *, int);
extern int func_0027FB40(int, int, unsigned long long, unsigned char *, int);
extern void func_0027F980(int, int, unsigned long long, unsigned char *, int);

void func_L00_003778F0(void) {
    PanelColors colors;
    char text[256];
    char *model = D_L00_0022F7C0;
    int index = *(int *)(model + 0x80);
    colors = D_L00_001AD768;
    D_L00_001B1BB8[1] = 0;
    func_0028EA58(func_0028E588(0xEAA8, 0), 16, (int)(D_L00_001B25E0 * 51.0f + 0.5f),
                  192, (int)(D_L00_001B25E0 * 96.0f + 0.5f), colors.word);
    func_0028EA58(func_0028E588(0xEAA8, 0), 400, (int)(D_L00_001B25E0 * 51.0f + 0.5f),
                  -192, (int)(D_L00_001B25E0 * 96.0f + 0.5f), colors.word);
    func_0028EA58(func_0028E588(0xEAA8, 0), 16, (int)(D_L00_001B25E0 * 243.0f + 0.5f),
                  192, -(int)(D_L00_001B25E0 * 96.0f + 0.5f), colors.word);
    func_0028EA58(func_0028E588(0xEAA8, 0), 400, (int)(D_L00_001B25E0 * 243.0f + 0.5f),
                  -192, -(int)(D_L00_001B25E0 * 96.0f + 0.5f), colors.word);
    func_0027FA10(270, (int)(D_L00_001B25E0 * 218.0f + 0.5f), 0x80F0F0F0ULL,
                  (unsigned char *)func_00288FB8(0x318C), -1);
    func_002F9BC0(text, ((ShopItem *)(model + 0x144))[index].price);
    func_0027F5B8(270, (int)(D_L00_001B25E0 * 218.0f + 0.5f), 0x80F0F0F0ULL, (unsigned char *)text, -1);
    func_0027FB40(D_001A7340 >> 1, (int)(D_L00_001B25E0 * 277.0f + 0.5f), 0x80F0F0F0ULL,
                  ((ShopItem *)(model + 0x144))[index].name, -1);
    colors.word[0] = 0x60F0F0B0;
    colors.word[1] = 0x60F0F0B0;
    colors.word[2] = 0x60F0F0B0;
    colors.word[3] = 0x60F0F0B0;
    func_002F9BC0(text, D_001A79FC);
    func_0027F980(444, 17, 0x80FFFFFFULL, (unsigned char *)text, -1);
    func_0028EA58(func_0028E588(0xEAA2, 3), 458, (int)(D_L00_001B25E0 * 15.0f + 0.5f),
                  32, (int)(D_L00_001B25E0 * 32.0f + 0.5f), colors.word);
}
