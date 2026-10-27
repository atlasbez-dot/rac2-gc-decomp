/* Near miss, 2026-10-26 (M11): 392/396 bytes, -O2 -G0 -ffunction-sections -g; 0/4 places.
 * The body is the func_L09_004050E0 burst (F282): real prototypes for func_0032C700 (14
 * arguments) and func_002AFEB8 (float before the trailing pointer). Left: retail keeps a
 * second callee-saved copy of &impulse ($s3, frame 0x80) for the func_002B0A68 call, and
 * the guarded func_002AB6D8 call fills its branch slot with the first argument (beqz, not
 * beql). Pointer and zero-local variants did not move either.
 */
typedef int Copy128 __attribute__((mode(TI)));
typedef union { Copy128 q; float f[4]; } Vector16;

extern void func_002AB6D8(void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern char D_00189EA0[];
extern int D_L02_001A8FF0;
extern void func_002A6C58(char *, int, int);
extern int func_002E5CF8(int, int, char *);
extern void func_00283098(void *, void *, void *);
extern void func_0032C700(void *, int, int, int, int, int, int, int, float, float, int, int, int, int);
extern void func_002AFEB8(char *, void *, void *, float, void *);
extern int func_002A77E0(int);
extern void func_002B0A68(char *, int, float *, unsigned char, float, float, float, float);
extern void func_0029F338(void *);

/* The func_L09_004050E0 burst with a flash at the object, a ground-snapped impulse and a
   colour drawn when the level asks for one. */
void func_L02_003CEA28(char *object)
{
    Vector16 position, offset, impulse;
    char *origin;
    int colour;

    if (*(short *)(*(char **)(object + 0x68) + 0x338) != 0)
        func_002AB6D8(object + 0xC0, object + 0xF0);
    origin = object + 0x10;
    func_002A6C58(object, 0, 3);
    func_002E5CF8(1, 0, object);
    offset.q = 0;
    offset.f[2] = 1.0f;
    func_00283098(&position, &offset, object + 0xC0);
    func_00282CC0(&position, &position, origin);
    func_0032C700(origin, 0, 0, 0, 0, 10, 20, 0, 0.333f, 20.0f, 1, 0, 0, 0);
    func_00282CF0(&impulse, origin, D_00189EA0);
    func_002AFEB8(object, &impulse, &impulse, 0.0f, 0);
    func_00282F20(&impulse, &impulse, 0.10000001f);
    colour = 255;
    if (D_L02_001A8FF0 != 0) colour = func_002A77E0(255);
    func_002B0A68(object, colour & 0x1F, impulse.f, 255, 3.0f, 6.0f, 3.0f, 6.0f);
    func_0029F338(object);
}
