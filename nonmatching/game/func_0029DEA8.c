/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections.
 * Prior worker coverage: US 0/28; US2 0/28; PAL 0/28.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Nonmatching manual reconstruction of func_0029DEA8 (4376 retail bytes).
   Profile: -O2 -G8 -ffunction-sections.
   Ten bounded meaningful source trials: 4256 -> 4316 -> 4332 -> 4248 ->
   4388 -> 4376 -> 4384 bytes. The retained 4384-byte form localizes the
   remaining differences to the last constant cases/shared coordinate tail
   and the second loop's constant/register allocation. All three releases
   finish at 0 of 28 places, exit 1. A prior 4376-byte form first differed
   at +0x160 and hoisted a parent-pointer load across typed field stores.
   Integer/short/unsigned-short cached-key views tied; do not repeat them.

   The old screening-only note misclassified register copies as fourteen
   pointer inputs. The actual first input is a signed selector, and the
   second is tested as a flag. The only direct helper is func_00297FE8,
   with two FP inputs, two float output pointers and a 32-bit selector.
   All 87 manually transcribed coordinate pairs agree bit-for-bit with
   the verified reference. The record stride and field widths come from
   retail accesses, not host sizes. Signedness of the 16-bit flag field
   is immaterial to the observed masks; its signed view retains the
   measured full-width complement mask.

   Binding evidence: ref_0029DEA8_00 is the partial state at boot 0x1C4FA0,
   level 0 0x1C93A0; ref_01 is the list-pointer table at 0x258C10/0x281650;
   ref_02 is the target-pointer table at 0x1C1220/0x1C5620; ref_03 is the
   parent-list pointer at 0x1B1A58/0x1B1D98. The three SDA inputs ref_04,
   ref_05 and ref_06 are boot 0x1A9598,0x1A9DB0,0x1A9B20 and level 0
   0x1A98D8,0x1AA0F0,0x1A9E60. ref_06 is a measured adjacent float pair
   (8 bytes), so ordinary G8 is truthful. The cache arrays each span 21
   words (0x54 bytes apart). The overall state and target views remain
   partial layouts. The null-cache-address branch is present in retail
   despite being unreachable for the observed linked state address.

   Reopen only with a new shared-tail/FPR-lifetime or second-loop
   allocation hypothesis. No exact candidate or runtime validation claimed.
*/
#include "common.h"

/* Only measured fields are named. The terminated entry list advances by 0x28. */
typedef struct MapEntry {
    s16 key,parent;
    s16 flags;
    u8 reserved06[4];
    s16 state;
    u8 reserved0c[12];
    float x,y,scale;
    int visible;
} MapEntry;
typedef struct {
    u8 reserved00[0x20];
    MapEntry *entries;
    u8 reserved24[0xE4];
    int cachedX[21],cachedY[21];
} MapEntryState;
typedef struct { float x,y,z; unsigned int flags; } MapDefinition;
typedef struct { u8 reserved00[0x10]; float x,y; u8 reserved18[0xE0]; float scale; } MapTarget;
typedef struct { u8 reserved00[0x24]; s16 enabled; u8 reserved26[2]; } MapParent;
typedef struct { float x,y; } MapCoordinates;

/* These objects move between the boot and level placements. */
extern MapEntryState ref_0029DEA8_00;
extern MapEntry *ref_0029DEA8_01[];
extern MapTarget *ref_0029DEA8_02[];
extern MapParent *ref_0029DEA8_03;
extern int ref_0029DEA8_04 __attribute__((sda));
extern int ref_0029DEA8_05 __attribute__((sda));
extern MapCoordinates ref_0029DEA8_06 __attribute__((sda));
extern u8 D_001A7BE8[];
extern int D_001A79F0;
typedef struct { u8 reserved00[0x80]; float x,y,z; } MapPlayerView;
extern MapPlayerView D_00189E20;
extern MapDefinition D_00139A28[];
extern void func_00297FE8(float,float,float *,float *,int);

void func_0029DEA8(int selector,int update)
{
    float x,y,fallbackX,fallbackY;
    MapEntry *entry,*cursor;
    int offset,index,mapSelector;
    if (selector<21 && D_001A7BE8[selector]) ref_0029DEA8_00.entries=ref_0029DEA8_01[selector];
    else ref_0029DEA8_00.entries=0;
    if (D_00189E20.z!=0.0f && selector==D_001A79F0 && update) {
        mapSelector=selector+100;
        if (!ref_0029DEA8_04) mapSelector=selector;
        func_00297FE8(D_00189E20.x,D_00189E20.y,&x,&y,mapSelector);
        ref_0029DEA8_00.cachedX[selector]=(int)(x*4096.0f)<<16;
        ref_0029DEA8_00.cachedY[selector]=(int)(y*4096.0f)<<16;
    } else if ((int)ref_0029DEA8_00.cachedX==0) {
        ref_0029DEA8_00.cachedX[selector]=0x08000000;
        ref_0029DEA8_00.cachedY[selector]=0x08000000;
    }
    if (!ref_0029DEA8_00.entries) return;
    offset=0;
    while (!(ref_0029DEA8_00.entries[offset].flags&4)) {
        entry=&ref_0029DEA8_00.entries[offset];
        if (ref_0029DEA8_05) {
            fallbackX=ref_0029DEA8_06.x;
            fallbackY=ref_0029DEA8_06.y;
            goto writeFallback;
        } else {
            if (entry->key==-1000) { entry->x=0.415f; entry->y=0.39f; }
            else if (entry->key==-0x396) { entry->x=0.635f; entry->y=0.065f; }
            else if (entry->key==-0x3E2) { entry->x=0.42292f; entry->y=0.20047f; }
            else if (entry->key==-0x3E1) { entry->x=0.4615f; entry->y=0.69332f; }
            else if (entry->key==-0x3DD) { entry->x=0.188f; entry->y=0.51f; }
            else if (entry->key==-0x3DC) { entry->x=0.8f; entry->y=0.75f; }
            else if (entry->key==-0x3D8) { entry->x=0.697f; entry->y=0.465f; }
            else if (entry->key==-0x3D3) { entry->x=0.29598f; entry->y=0.16702f; }
            else if (entry->key==-0x3CF) { entry->x=0.65519f; entry->y=0.73443f; }
            else if (entry->key==-0x3CA) { entry->x=0.80234f; entry->y=0.26487f; }
            else if (entry->key==-0x3C9) { entry->x=0.43668f; entry->y=0.05949f; }
            else if (entry->key==-0x3C8) { entry->x=0.43668f; entry->y=0.05949f; }
            else if (entry->key==-0x3C7) { entry->x=0.24665f; entry->y=0.30165f; }
            else if (entry->key==-0x3C1) { entry->x=0.465f; entry->y=0.68f; }
            else if (entry->key==-0x3C0) { entry->x=0.71f; entry->y=0.4f; }
            else if (entry->key==-0x3C4) { entry->x=0.46784f; entry->y=0.2526f; }
            else if (entry->key==-0x3C3) { entry->x=0.71312f; entry->y=0.72318f; }
            else if (entry->key==-0x3B7) { entry->x=0.67f; entry->y=0.48f; }
            else if (entry->key==-0x3B6) { entry->x=0.37f; entry->y=0.8f; }
            else if (entry->key==-1) { entry->x=0.234375f; entry->y=0.30078125f; }
            else if (entry->key==-2) { entry->x=0.5390625f; entry->y=0.365234375f; }
            else if (entry->key==-3) { entry->x=0.58203125f; entry->y=0.6875f; }
            else if (entry->key==-4) { entry->x=0.720703125f; entry->y=0.728515625f; }
            else if (entry->key==-5) { entry->x=0.8671875f; entry->y=0.23046875f; }
            else if (entry->key==-6) { entry->x=0.48046875f; entry->y=0.5703125f; }
            else if (entry->key==-7) { entry->x=0.625f; entry->y=0.72265625f; }
            else if (entry->key==-0x3D5) { entry->x=0.365f; entry->y=0.3f; }
            else if (entry->key==-0x3AE) { entry->x=0.4f; entry->y=0.65f; }
            else if (entry->key==-0x3AD) { entry->x=0.63f; entry->y=0.58f; }
            else if (entry->key==-0x3A7) { entry->x=0.785f; entry->y=0.26f; }
            else if (entry->key==-0x3A6) { entry->x=0.586f; entry->y=0.365f; }
            else if (entry->key==-0x3A5) { entry->x=0.627f; entry->y=0.769f; }
            else if (entry->key==-0x3B3) { entry->x=0.12f; entry->y=0.92f; }
            else if (entry->key==-0x3AC) { entry->x=0.373f; entry->y=0.795f; }
            else if (entry->key==-0x3A4) { entry->x=0.688f; entry->y=0.705f; }
            else if (entry->key==-0x39E) { entry->x=0.422f; entry->y=0.582f; }
            else if (entry->key==-0x39A) { entry->x=0.615f; entry->y=0.658f; }
            else if (entry->key==-0x3A1) { entry->x=0.537f; entry->y=0.61f; }
            else if (entry->key==-0x3A0) { entry->x=0.394f; entry->y=0.558f; }
            else if (entry->key==-0x39F) { entry->x=0.395f; entry->y=0.625f; }
            else if (entry->key==-0x39B) { entry->x=0.337f; entry->y=0.284f; }
            else if (entry->key==-0x3E6) { entry->x=0.253f; entry->y=0.66f; }
            else if (entry->key==-0x3E0) { entry->x=0.435f; entry->y=0.9f; }
            else if (entry->key==-0x3DF) { entry->x=0.415f; entry->y=0.195f; }
            else if (entry->key==-0x3DB) { entry->x=0.485f; entry->y=0.755f; }
            else if (entry->key==-0x3DA) { entry->x=0.5f; entry->y=0.083f; }
            else if (entry->key==-0x3D7) { entry->x=0.58f; entry->y=0.61f; }
            else if (entry->key==-0x3D6) { entry->x=0.76f; entry->y=0.775f; }
            else if (entry->key==-0x3D4) { entry->x=0.342f; entry->y=0.645f; }
            else if (entry->key==-0x3D2) { entry->x=0.565f; entry->y=0.91f; }
            else if (entry->key==-0x3D1) { entry->x=0.465f; entry->y=0.695f; }
            else if (entry->key==-0x3D0) { entry->x=0.285f; entry->y=0.115f; }
            else if (entry->key==-0x3CE) { entry->x=0.865f; entry->y=0.73f; }
            else if (entry->key==-0x3CD) { entry->x=0.683f; entry->y=0.945f; }
            else if (entry->key==-0x3CC) { entry->x=0.633f; entry->y=0.665f; }
            else if (entry->key==-0x3CB) { entry->x=0.718f; entry->y=0.615f; }
            else if (entry->key==-0x3C6) { entry->x=0.805f; entry->y=0.788f; }
            else if (entry->key==-0x3C5) { entry->x=0.766f; entry->y=0.752f; }
            else if (entry->key==-0x3C2) { entry->x=0.547f; entry->y=0.665f; }
            else if (entry->key==-0x3BF) { entry->x=0.77f; entry->y=0.895f; }
            else if (entry->key==-0x3BE) { entry->x=0.545f; entry->y=0.585f; }
            else if (entry->key==-0x3BB) { entry->x=0.555f; entry->y=0.287f; }
            else if (entry->key==-0x3BA) { entry->x=0.554f; entry->y=0.5f; }
            else if (entry->key==-0x3B9) { entry->x=0.573f; entry->y=0.51f; }
            else if (entry->key==-0x3B8) { entry->x=0.2f; entry->y=0.62f; }
            else if (entry->key==-0x3BC) { entry->x=0.687f; entry->y=0.523f; }
            else if (entry->key==-0x3B5) { entry->x=0.565f; entry->y=0.915f; }
            else if (entry->key==-0x3B4) { entry->x=0.71f; entry->y=0.515f; }
            else if (entry->key==-0x3B2) { entry->x=0.103f; entry->y=0.897f; }
            else if (entry->key==-0x3B1) { entry->x=0.23f; entry->y=0.403f; }
            else if (entry->key==-0x3B0) { entry->x=0.23f; entry->y=0.45f; }
            else if (entry->key==-0x3AF) { entry->x=0.703f; entry->y=0.38f; }
            else if (entry->key==-0x3AB) { entry->x=0.375f; entry->y=0.78f; }
            else if (entry->key==-0x3AA) { entry->x=0.115f; entry->y=0.635f; }
            else if (entry->key==-0x3A9) { entry->x=0.268f; entry->y=0.53f; }
            else if (entry->key==-0x3A8) { entry->x=0.46f; entry->y=0.628f; }
            else if (entry->key==-0x3A3) { entry->x=0.613f; entry->y=0.71f; }
            else if (entry->key==-0x3A2) { entry->x=0.424f; entry->y=0.465f; }
            else if (entry->key==-0x39D) { entry->x=0.412f; entry->y=0.605f; }
            else if (entry->key==-0x39C) { entry->x=0.445f; entry->y=0.695f; }
            else if (entry->key==-0x399) { entry->x=0.515f; entry->y=0.647f; }
            else if (entry->key==-0x398) { entry->x=0.505f; entry->y=0.402f; }
            else if (entry->key==-0x397) { entry->x=0.39f; entry->y=0.275f; }
            else if (entry->key==-0x3BD) { entry->x=0.18f; entry->y=0.33f; }
            else if (entry->key==-0x3E4) { entry->x=0.422f; entry->y=0.1f; }
            else if (entry->key==-0x3DE) { entry->x=0.486f; entry->y=0.865f; }
            else if (entry->key==-0x3E3) {
                fallbackX=0.405f;
                fallbackY=0.081f;
writeFallback:
                entry->x=fallbackX;
                entry->y=fallbackY;
            }
            else if (selector==D_001A79F0) {
                if (ref_0029DEA8_02[entry->key]) {
                    func_00297FE8(ref_0029DEA8_02[entry->key]->x,ref_0029DEA8_02[entry->key]->y,
                        &ref_0029DEA8_00.entries[offset].x,&ref_0029DEA8_00.entries[offset].y,selector);
                    ref_0029DEA8_00.entries[offset].scale=ref_0029DEA8_02[entry->key]->scale;
                }
            } else {
                func_00297FE8(D_00139A28[entry->key].x,D_00139A28[entry->key].y,
                    &ref_0029DEA8_00.entries[offset].x,&ref_0029DEA8_00.entries[offset].y,selector);
                ref_0029DEA8_00.entries[offset].scale=D_00139A28[entry->key].z;
            }
        }
        offset++;
    }
    if (!(ref_0029DEA8_00.entries[0].flags&4)) {
        index=0;
        offset=0;
        do {
        cursor=(MapEntry *)((u8 *)ref_0029DEA8_00.entries+offset);
        (*(int *)((u8 *)cursor+0x24))=0;
        (*(short *)((u8 *)cursor+4))&=~0x10;
        if ((*(short *)((u8 *)cursor+2))==-1) (*(int *)((u8 *)cursor+0x24))=1;
        else (*(int *)((u8 *)cursor+0x24))=ref_0029DEA8_03[(*(short *)((u8 *)cursor+2))].enabled==1;
        if (((*(short *)((u8 *)cursor+4))&0x1000) && ((D_00139A28[(*(short *)cursor)].flags^1)&1)) (*(int *)((u8 *)cursor+0x24))=0;
        if (ref_0029DEA8_00.entries[index].state) ref_0029DEA8_00.entries[index].flags|=0x10;
        index++; offset+=0x28;
        } while (!(ref_0029DEA8_00.entries[index].flags&4));
    }
}

/* Historical comments/maps retained from the previous near miss. These describe
 * that previous source; any superseded type, allocation or impossibility claims
 * are historical observations, not properties of the corrected body above. */

/* Historical analysis (summary).
 * Historical screening misread register copies as fourteen pointer inputs and reported a
 * small-data scheduling blocker. The manual reconstruction above qualifies the actual signed
 * selector, flag, record views and floating-output helper. The earlier decoded instruction
 * excerpt remains private; its input-count conclusion is superseded.
 */
