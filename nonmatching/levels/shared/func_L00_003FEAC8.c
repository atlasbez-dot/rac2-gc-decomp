/* from src/levels/shared/L00_003F8E08-g8.c: C that compiles close to the retail's bytes
   but does not match; needs a -G8 unit (the body reads level data through $gp). */

/* The body: the object keeps a pointer to a table of 0xE0-byte records at +0x68; the
   record the boot's byte at 0x00139581 picks supplies one float; the new object is
   handed to the level's own copy of func_00282F20 and the result is written back. */

#ifndef RAC2_T_QUAD_3FEAC8
#define RAC2_T_QUAD_3FEAC8
typedef int Quad_3feac8 __attribute__((mode(TI)));
#endif

#ifndef RAC2_T_ENTRY_262570_3FEAC8
#define RAC2_T_ENTRY_262570_3FEAC8
/* One record of the level's table of 0xE0-byte entries at D_L00_00262570. */
typedef struct {
    unsigned char pad00[0x70];
    float f70;
    unsigned char pad74[0xE0 - 0x74];
} Entry_262570_3feac8;
#endif

/* The boot's resident byte that picks the table row (0x00139581). */
extern unsigned char D_00139581[];

/* The level's own table of records, and the small-data float it hands to the last call. */
extern Entry_262570_3feac8 D_L00_00262570[];
extern float D_L00_001B0C14 __attribute__((sda));

/* The bodies the retail calls reach, at 0x3FEBA0, 0x2EE238, 0x31A768 and 0x3A98E8 in
   level 00; each sits at another address in the other levels. */
extern void ref_L00_003FEAC8_00(void *, void *, void *, int);
extern float ref_L00_003FEAC8_01(void *);
extern int ref_L00_003FEAC8_02(int, int);
extern int ref_L00_003FEAC8_03(void *, void *, void *, int, float, float, float);

void func_L00_003FEAC8(char *self, char *arg1, Quad_3feac8 *arg2, int index)
{
    int *base = *(int **)(self + 0x68);
    Quad_3feac8 vec;
    float f21;
    float f20;
    int r;

    vec = *arg2;
    f21 = D_L00_00262570[D_00139581[0]].f70;
    ref_L00_003FEAC8_00(self, arg1, arg2, index);
    f20 = ref_L00_003FEAC8_01(&vec);
    r = ref_L00_003FEAC8_02(1, 30);
    r = ref_L00_003FEAC8_03(arg1, &vec, self, r, f20, f21, D_L00_001B0C14);
    *(int *)((char *)base + index * 4 + 0x10) = r;
    if (r != 0) {
        *(int *)(r + 0xB8) = self;
    }
}
