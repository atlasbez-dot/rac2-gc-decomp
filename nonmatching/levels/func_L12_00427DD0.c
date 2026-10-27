/* Near miss, 2026-10-26 (M11): 360/368 bytes, -O2 -G0 -ffunction-sections -g; 0/2 places.
 * The func_L09_004050E0 burst (F282) with the guarded func_002AB6D8 call and the colour draw.
 * Left, as in func_L02_003CEA28: retail keeps a second callee-saved copy of &impulse ($s3,
 * frame 0x70) for the func_002B0A68 call. An inline colour helper did not create it.
 */
typedef int Copy128 __attribute__((mode(TI)));
typedef union { Copy128 q; float f[4]; } Vector16;

extern void func_002AB6D8(void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern char D_00189EA0[];
extern int D_L12_001A8FF0;
extern void func_002A6C58(char *, int, int);
extern int func_002E5CF8(int, int, char *);
extern void func_00283098(void *, void *, void *);
extern void func_002AC728(char *, void *, int, float, float);
extern void func_002AFEB8(char *, void *, void *, float, void *);
extern int func_002A77E0(int);
extern void func_002B0A68(char *, int, float *, unsigned char, float, float, float, float);
extern void func_0029F338(void *);

/* The func_L09_004050E0 burst behind an optional matrix rebuild, with a ground-snapped
   impulse and a colour drawn when the level asks for one. */
void func_L12_00427DD0(char *object)
{
    Vector16 position, offset, impulse;
    char *origin;
    float zero;
    int colour;

    if (*(short *)(*(char **)(object + 0x68) + 0x358) != 0)
        func_002AB6D8(object + 0xC0, object + 0xF0);
    origin = object + 0x10;
    func_002A6C58(object, 0, 3);
    zero = 0.0f;
    func_002E5CF8(1, 0, object);
    offset.q = 0;
    offset.f[2] = 0.75f;
    func_00283098(&position, &offset, object + 0xC0);
    func_00282CC0(&position, &position, origin);
    func_002AC728(object, &position, -1, 0.333f, zero);
    func_00282CF0(&impulse, origin, D_00189EA0);
    func_002AFEB8(object, &impulse, &impulse, zero, 0);
    func_00282F20(&impulse, &impulse, 0.10000001f);
    colour = 255;
    if (D_L12_001A8FF0 != 0) colour = func_002A77E0(255);
    func_002B0A68(object, colour & 0x1F, impulse.f, 255, 3.0f, 6.0f, 3.0f, 6.0f);
    func_0029F338(object);
}
