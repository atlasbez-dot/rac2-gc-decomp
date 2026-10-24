/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections (reported default game profile).
 * Reported final C / retail: 888 / 856 bytes; size equality is not a match.
 * us: 0/28 placements; 888/856 bytes.
 * us2: 0/28 placements; 888/856 bytes.
 * pal: 0/28 placements; 888/856 bytes.
 * Residual: List/grid allocation; faithful raw control-word copies and actual selector reloads retained over shorter less faithful form.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Nonmatching manual reconstruction, 2026-10-23.
 * 00303210: 888 bytes versus retail 856; frame 0xB0.
 * Profile: default -O2 -G0 -ffunction-sections.
 * All carrying US/US2/PAL checks returned zero matches and exit 1;
 * catalogue absence is recorded separately and never counted as success.
 * Control-point values are copied as raw words with each measured selector reload. List and grid-loop allocation/scheduling differ.
 * Reopen only with new measured source/type/scheduling evidence. No artificial
 * barriers, register pins, generated decompiler C or omitted behavior were used.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef int ParticleWord __attribute__((mode(TI)));
typedef union { ParticleWord word; float f[4]; } ParticleVector;
typedef struct { float x,y,z,w; } V4_F213135aa;
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);

extern unsigned short *D_001EE5A0[];
extern int D_001B1B78 __attribute__((sda));
extern char *D_001B1B5C __attribute__((sda));
extern V4_F213135aa ref_00303210_00[];
extern int func_002A8508(int, int);

/* Read the surface's four control points and regenerate its 8 by 8 mesh. */
void func_00303210(char *object)
{
    char *state=*(char **)(object+0x68);
    unsigned short *entry;
    char *control, *settings;
    ParticleVector first, second, left, right;
    float columnWeight;
    int column, row, surface;
    unsigned int list;
    if (func_002A8508((u8)object[0x21],-1)==5) {
        entry=D_001EE5A0[(u8)object[0x21]];
        for (;;) {
            list=(u8)object[0x21];
            if (list==0xff || D_001B1B78<(int)list || !entry) break;
            if ((short)entry[-1]<0 && entry!=D_001EE5A0[list]) break;
            control=(char *)((u32)D_001B1B5C+(*entry&0x7fff)*0x100);
            if (!control) break;
            if (*(short *)(control+0xaa)==0x1130) {
                settings=*(char **)(control+0x68);
                if (*(u32 *)(settings+0x14)>3) *(int *)(settings+0x14)=0;
                *(u32 *)(state+0x50+*(int *)(settings+0x14)*4)=*(u32 *)(control+0x10);
                *(u32 *)(state+0x60+*(int *)(settings+0x14)*4)=*(u32 *)(control+0x14);
                ++entry;
                if (!*(int *)(settings+0x14)) *(u32 *)(state+0x70)=*(u32 *)(control+0x18);
            } else ++entry;
        }
    } else {
        *(int *)(state+0x50)=0; *(int *)(state+0x60)=0;
        *(int *)(state+0x54)=0; *(int *)(state+0x64)=0;
        *(int *)(state+0x58)=0; *(int *)(state+0x68)=0;
        *(int *)(state+0x5c)=0; *(int *)(state+0x6c)=0;
        *(int *)(state+0x70)=0;
    }
    surface=*(int *)(state+0x40);
    for (row=0; row<8; ++row) {
        for (column=0; column<8; ++column) {
            first.f[0]=*(float *)(state+0x54)-*(float *)(state+0x50);
            first.f[1]=*(float *)(state+0x64)-*(float *)(state+0x60);
            first.f[2]=0; first.f[3]=1.0f;
            second.f[0]=*(float *)(state+0x58)-*(float *)(state+0x5c);
            second.f[1]=*(float *)(state+0x68)-*(float *)(state+0x6c);
            second.f[2]=0; second.f[3]=1.0f;
            columnWeight=(float)column*0.14285715f;
            func_00282D30(&first,&first,columnWeight);
            func_00282D30(&second,&second,columnWeight);
            left.f[0]=*(float *)(state+0x50); left.f[1]=*(float *)(state+0x60);
            left.f[2]=0; left.f[3]=1.0f;
            func_00282CC0(&left,&left,&first);
            right.f[0]=*(float *)(state+0x5c); right.f[1]=*(float *)(state+0x6c);
            right.f[2]=0; right.f[3]=1.0f;
            func_00282CC0(&right,&right,&second);
            func_00282CF0(&right,&right,&left);
            func_00282D30(&right,&right,(float)row*0.14285715f);
            func_00282CC0(&left,&left,&right);
            ref_00303210_00[surface*64+row*8+column].x=left.f[0];
            ref_00303210_00[surface*64+row*8+column].y=left.f[1];
            ref_00303210_00[surface*64+row*8+column].z=*(float *)(state+0x70);
        }
    }
}
