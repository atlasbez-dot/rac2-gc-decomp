/* US and US2, game -O2/-G0: 1304 bytes versus 1316; 0/27 placements
   in each release. Absent from the PAL catalogue. Reconstructed manually from
   verified retail instructions, with helper signatures checked against current C
   or retail live inputs and return banks. Initial shared-base C was 1252 bytes;
   direct canonical resident references improved it to 1304. A partial typed
   resident view produced 1288 bytes and was rejected. Remaining differences are
   address rematerialization, register lifetimes, float constant/store scheduling
   and boolean spill selection. No fake data aliases, shortened extents, volatile
   or register constraints were introduced. Reopen with a matching resident-field
   and animation-loop lifetime idiom. No linked build or functional test run. */

/* Historical screening, superseded by the measured C attempt above. */
/* Not attempted - screened, no C written: 1316 bytes, 27 places.

   The screening: every branch of the body stays inside its own bytes, so the row is
   a whole function and not a catalogue fragment.  No MMI word (0x78/0x7A/0x7C/0x7E)
   and no COP2 (VU0) word; two multiplies, at +0xA4 (`mult $v0,$a0`) and +0x438
   (`mult $a1,$v1`).  Nothing in the row looks like handwritten assembly.

   The body is the state block's own update: it reads the resident block at
   0x00189E20, walks its tables, and writes the aim vector, the counter and the
   object's fields back.  At 1316 bytes it is the largest row of the file; its
   register allocation and the order of its stores have to be reproduced word for
   word, and the budget of this wave went to the smaller rows of the same file. */

#include "common.h"

extern u8 D_00189E20[];
extern u8 D_00188660[];
extern u8 D_L00_001B4400[];
extern float D_L00_001A7F98;
extern float D_L00_0025DB20[][25];
extern void func_L00_002D1F60(void);
extern void func_00282AB0(void *, void *, s32);
extern s32 func_L00_002A4DB0(char *, s32, s32, s32);
extern void func_L00_002D24B8(void);
extern void func_L00_002D20D0(void);
extern s32 func_00283CF0(float);
extern s32 func_002E5CF8(s32, s32, char *);
extern void func_002E59F8(s32);
extern void func_L00_002D1ED8(void);
extern void func_L00_002D2070(void);
extern float func_0029F530(char *);

void func_L00_002D24E8(void)
{
    u8 *base;
    u8 *obj;
    u8 *entry;
    u8 *sound;
    u8 *buffer;
    u8 *next;
    s32 oldFrame;
    s32 same;
    s32 lower;
    s32 upper;
    s32 i;
    s32 *events;
    s32 event;
    s32 frame;
    float oldTime;
    float delta;
    float time;
    float prior;
    float step;

    base = D_00189E20;
    obj = *(u8 **)(base + 0x2290);
    func_L00_002D1F60();
    *(s32 *)(base + 0xC28) &= ~3;
    oldFrame = obj[0x40];
    oldTime = *(float *)(obj + 0x44);
    same = obj[0x42] == obj[0x43];
    if (obj[0x42] == obj[0x43]) {
        *(float *)(obj + 0x44) = oldTime + *(float *)(base + 0xC20) * *(float *)(base + 0xC24);
    } else if (*(s32 *)(base + 0xC30) >= 0) {
        frame = *(s32 *)(base + 0xC34);
        *(float *)(obj + 0x44) = D_L00_0025DB20[*(s32 *)(base + 0xC30)][frame];
        *(s32 *)(base + 0xC34) = frame + 1;
    } else {
        *(float *)(obj + 0x44) = oldTime + *(float *)(base + 0xC24);
    }
    if (*(float *)(obj + 0x44) > 0.99f && *(float *)(obj + 0x44) < 1.01f)
        *(float *)(obj + 0x44) = 1.0f;
    if (*(float *)(obj + 0x44) > -0.01f && *(float *)(obj + 0x44) < 0.01f)
        *(float *)(obj + 0x44) = 0.0f;
    delta = *(float *)(obj + 0x44) - oldTime;
    if (*(float *)(obj + 0x44) >= 1.0f) {
        step = D_L00_001A7F98;
        buffer = D_L00_001B4400;
        next = buffer + 0x600;
        do {
            if (obj[0x42] != obj[0x43]) {
                obj[0x42] = obj[0x43];
                entry = *(u8 **)(*(u8 **)(obj + 0x24) + obj[0x43] * 4 + 0x48);
                obj[0x6E] = entry[0x12];
            }
            *(s32 *)(D_00189E20 + 0xC30) = -1;
            *(s32 *)(D_00189E20 + 0xC28) |= 1;
            *(u8 **)(obj + 0x58) = buffer;
            obj[0x40] = obj[0x41];
            func_00282AB0(buffer, next, 0x600);
            obj[0x41]++;
            if (*(s32 *)(D_00189E20 + 0xC48)) {
                *(s32 *)(D_00189E20 + 0xC48) = 0;
                *(float *)(D_00189E20 + 0xC24) = step;
                *(float *)(obj + 0x44) = 0.0f;
                obj[0x41] = *(u8 *)(D_00189E20 + 0xC44);
                *(s32 *)(obj + 0x5C) = func_L00_002A4DB0((char *)obj, obj[0x43], obj[0x41], (s32)next);
                func_L00_002D24B8();
                func_L00_002D20D0();
            } else if (*(s32 *)(D_00189E20 + 0xC40) != -1 && *(s32 *)(D_00189E20 + 0xC44) < obj[0x41]) {
                *(float *)(D_00189E20 + 0xC24) = 0.33333334f;
                *(float *)(obj + 0x44) = 0.0f;
                obj[0x41] = *(u8 *)(D_00189E20 + 0xC40);
                *(s32 *)(obj + 0x5C) = func_L00_002A4DB0((char *)obj, obj[0x43], obj[0x41], (s32)next);
                func_L00_002D20D0();
            } else {
                entry = *(u8 **)(*(u8 **)(obj + 0x24) + obj[0x43] * 4 + 0x48);
                if ((u32)obj[0x41] >= (u32)entry[0x10]) {
                    obj[0x41] = 0;
                    *(s32 *)(D_00189E20 + 0xC28) |= 2;
                }
                *(s32 *)(obj + 0x5C) = func_L00_002A4DB0((char *)obj, obj[0x43], obj[0x41], (s32)next);
                *(float *)(obj + 0x44) -= 1.0f;
                *(float *)(obj + 0x44) /= *(float *)(D_00189E20 + 0xC24);
                *(float *)(D_00189E20 + 0xC24) = **(float **)(obj + 0x58);
                *(float *)(obj + 0x44) *= *(float *)(D_00189E20 + 0xC24);
            }
        } while (*(float *)(obj + 0x44) >= 1.0f);
    }
    if (same && obj[0x6E]) {
        upper = obj[0x40] * 16 + func_00283CF0(*(float *)(obj + 0x44) * 16.0f);
        lower = oldFrame * 16 + func_00283CF0(oldTime * 16.0f);
        entry = *(u8 **)(*(u8 **)(obj + 0x24) + obj[0x42] * 4 + 0x48);
        events = (s32 *)(entry + entry[0x10] * 4 + 0x1C);
        for (i = 0; i < entry[0x12]; i++, events++) {
            event = *events;
            frame = event >> 16;
            if (lower < frame && upper >= frame) {
                func_002E5CF8(event & 0xFFFF, 0, (char *)obj);
                break;
            }
        }
    }
    if (obj[0x6D] != 255) {
        sound = D_00188660 + obj[0x6D] * 0x70;
        if (*(u8 **)(sound + 0x88) != obj)
            obj[0x6D] = 255;
        else if (*(s16 *)(sound + 0x7E) != obj[0x6C]) {
            func_002E59F8(obj[0x6D]);
            obj[0x6D] = 255;
        }
    } else if (obj[0x6C] != 255) {
        obj[0x6D] = func_002E5CF8(obj[0x6C], 4, (char *)obj);
    }
    func_L00_002D1ED8();
    func_L00_002D2070();
    prior = *(float *)(D_00189E20 + 0xC38);
    time = func_0029F530((char *)obj);
    *(float *)(D_00189E20 + 0xC38) = time;
    if (time >= prior) *(float *)(D_00189E20 + 0xC3C) = time - prior;
    else *(float *)(D_00189E20 + 0xC3C) = delta;
    *(s32 *)(D_00189E20 + 0xC2C) = obj[0x42] != obj[0x43];
}
