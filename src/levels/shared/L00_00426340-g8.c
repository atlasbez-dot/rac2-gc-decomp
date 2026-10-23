#include "include_asm.h"

extern void ref_L00_00428560_00(char *);

extern void ref_L00_0042ABF8_00(char *);

extern void ref_L00_0042B688_00(char *);

void func_L00_00428560(char *o)
{
    ref_L00_00428560_00(o);
}

void func_L00_0042ABF8(char *o)
{
    ref_L00_0042ABF8_00(o);
}

void func_L00_0042B688(char *o)
{
    ref_L00_0042B688_00(o);
}
extern char D_L00_001ADC68[4] __attribute__((sda));

extern char D_L00_001ADC48[4] __attribute__((sda));

extern void func_L00_0042B408(char *);

void func_L00_0042B6A8(char *a0)
{
    *(char **)a0 = D_L00_001ADC68;
    func_L00_0042B408(a0);
}

void func_L00_0042B6C8(char *a0)
{
    *(char **)a0 = D_L00_001ADC48;
    func_L00_0042B408(a0);
}

/* The global this one writes sits at a different address from level to level, and it is
 * not the one func_L00_004272A0 reads in every level, so it takes a name of its own. */
extern int ref_L00_00427290_00 __attribute__((sda));

void func_L00_00427290(void)
{
    ref_L00_00427290_00 = 1;
}


extern int D_L00_001B2700 __attribute__((sda));

extern int D_L00_001B15DC __attribute__((sda));

int func_L00_004272A0(void)
{
    return D_L00_001B15DC;
}

int func_L00_0042B730(void)
{
    return D_L00_001B2700;
}

extern float D_L00_001B15B8 __attribute__((sda));

extern char D_L00_001B9040[];

extern char D_00189F70[];

extern int D_001A7BAC;

extern float D_L00_001A8904;

extern int D_L00_001A8FF0;

extern void func_00282CC0(char *, char *, char *);

extern float func_00283B98(float, float);

extern void func_L00_004208C8(char *, float *);

extern void func_L00_004224D0(char *);

extern void func_L00_00421C50(char *);

extern void func_L00_00426340(int);

extern void func_L00_00422268(char *);

/* Builds the hero's 16-byte block from the hero record and the parameter block, stores the
   table's current blend weight in the global, refines the block's last float with the
   parameter block's own float (the hero's own float only when the global allows it) and
   hands the block to the object's own refresh, which then runs the five owner helpers.
   The retail reaches the blend table through $gp, so this body needs the small-data
   profile (-G8, from this file's name). */
void func_L00_004263B8(char *object)
{
    char local[16];
    char *hero = D_00189F70;
    char *self = object;
    char *parameters = D_L00_001B9040;
    float value = (&D_L00_001B15B8)[D_001A7BAC];
    float first;

    D_L00_001A8904 = value;
    func_00282CC0(local, hero, parameters);
    first = *(float *)(hero + 12);
    if (D_L00_001A8FF0 != 0) {
        first = 0.0f;
    }
    *(float *)(local + 12) = func_00283B98(first, *(float *)(parameters + 12));
    func_L00_004208C8(self, (float *)local);
    func_L00_004224D0(self);
    func_L00_00421C50(self);
    func_L00_00426340((int)self);
    func_L00_00422268(self);
}
