#include "include_asm.h"

INCLUDE_ASM("asm/game", func_00308600);

INCLUDE_ASM("asm/game", func_00308768);

INCLUDE_ASM("asm/game", func_00308DB8);

INCLUDE_ASM("asm/game", func_003092A0);


INCLUDE_ASM("asm/game", func_0030A188);

INCLUDE_ASM("asm/game", func_0030A348);

INCLUDE_ASM("asm/game", func_0030BBA0);

INCLUDE_ASM("asm/game", func_0030C188);




INCLUDE_ASM("asm/game", func_0030CAD0);

INCLUDE_ASM("asm/game", func_0030CCD0);

/* func_0030D430 is matched in its own unit, src/game/0030D430-g8.c. */

INCLUDE_ASM("asm/game", func_0030D5B8);

INCLUDE_ASM("asm/game", func_0030DB88);

INCLUDE_ASM("asm/game", func_0030DE88);



extern char *func_002A9640(char *, int, int);
extern void func_00282948(int *);
extern void func_002E5CF8(int, int, char *);
extern void func_002AB800(char *, char *);
extern void func_002ACB48(float *, float);
/* Integer and float arguments have separate register banks. This interleaving
   preserves the measured argument setup order. */
extern void func_002ABBB8(void *, void *, void *, float, float, int, int, int,
                         float, float, float, float, int, float, int, int, int, int, int);
extern void func_002AB8C0(char *, char *);

void func_0030E700(char *object)
{
    char *state = *(char **)(object + 0x68);
    char *hit = func_002A9640(object, 0x30001, 0);
    float direction[4];

    func_00282948((int *)(state + 0x28));
    func_00282948((int *)(state + 0x2C));
    if (hit != 0 && (*(int *)(hit + 0x20) != *(int *)(state + 0x34) ||
                     *(int *)(state + 0x28) == 0)) {
        *(int *)(state + 0x34) = *(int *)(hit + 0x20);
        *(int *)(state + 0x28) = 30;
        if (*(int *)(state + 0x2C) == 0) {
            if (*(unsigned short *)(hit + 0x28) == 0x101 && *(int *)(state + 0x30) == 0) {
                *(int *)(state + 0x2C) = 100;
                *(int *)(state + 0x30) = 1;
            } else {
                *(int *)(state + 0x30) = 0;
            }
        }
        func_002E5CF8(0, 0, object);
        *(float *)(state + 0x24) -= *(float *)(hit + 0x2C);
        func_002AB800(object, state);
        if (*(float *)(state + 0x24) < 0.0f) {
            func_002ACB48(direction, 0.5f);
            func_002ABBB8(object, direction, 0, 0.0f, 0.0f, 0, 0, 0,
                         4.0f, 3.0f, 9.0f, 1.0f, 2, 12.0f, 1, 1, -1, 0, 0x810001);
            object[0x20] = 6;
        }
    }
    ((unsigned char *)object)[0xA8] = 0xFF;
    func_002AB8C0(object, state);
}

INCLUDE_ASM("asm/game", func_0030E8A8);

INCLUDE_ASM("asm/game", func_0030ECC8);

INCLUDE_ASM("asm/game", func_0030F408);
