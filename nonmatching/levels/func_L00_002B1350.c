/* Opus big36 draft, 26 October 2026: NOT MATCHING.
 * Profile: -O2 -G0 -ffunction-sections (default).
 * 782/784 instructions; 36 opcode-level rows differ, the rest is a callee-saved rotation:
 * retail slot*4 s2, hero base s3/s4, keepHelmet s4, hero %hi s5, changed s6, keepSuit s7;
 * here base s2, slot*4 s3, %hi s4, changed s5. Left: slot-1 item reads (retail addiu +0x50 then
 * 0x1248), the 0x77 default without movz, several delay-slot fills (nop / beql) and the
 * current[0]/queued addressing through the D+0x1239 pose pointer. Absolute globals use
 * offset-indexed sda tables (D_001A7A00[], D_001A7B08[]) and a macro view D_001A7398_m.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
typedef struct { u8 pad00[0xC]; u8 rank; } MobyClass;
typedef struct { u8 pad00[0x24]; MobyClass *cls; u8 pad28[0x54]; s16 visible; } SlotMoby;
typedef struct { u8 pad00[0x34]; int dirty; } Panel;
/* One equipment slot of the hero (0x50 bytes). */
typedef struct {
    SlotMoby *moby, *holster;
    u8 pad08[0x11];
    u8 pose, swap, pad1B, state, restPose, pad1E[2];
    int anim, mode, item;
    u8 pad2C[0x24];
} Slot;
typedef struct {
    u8 pad0000[0x80];
    Vector position;
    u8 pad0090[0xE00];
    Panel *panel[2];
    u8 pad0E98[0x308];
    int quickTimer;
    u8 pad11A4[0x7C];
    Slot slots[4];
    u8 pad1360[0x137];
    u8 swimming;
    u8 pad1498[0x43C];
    int armed;
    u8 pad18D8[0x9BC];
    int move, pad2298, state;
    u8 pad22A0[0x16];
    u8 pending, locked, refresh, pad22B9[2], skin, blocked, pad22BD[0xB];
    int request[4], pad22D8[3], current[4], pad22F4[3], previous[4], pad2310[3], restore[4];
    int pad232C[3], queued;
    u8 pad233C[0x1B4];
    u8 diving;
} HeroState;
typedef struct { u8 pad00[4]; u8 fancy; u8 pad05[0xF]; int sound; u8 pad18[4]; int skin, pad20, flags; u8 pad28[0xB8]; } ItemClass;
extern u8 D_00189E20[];
extern u32 D_00138180[];
extern u8 D_00139568[];
extern ItemClass D_L00_00262570[];
extern int D_001A7398[];
extern int D_001A7398_m[] __attribute__((sda));
extern u8 D_001A7A80[];
extern u8 D_001A7A00[] __attribute__((sda));
extern u8 D_001A7B08[] __attribute__((sda));
extern void func_L00_003ECC90(Vector *, int);
extern int func_L00_002D3F30(int, int);
extern void func_L00_003C3A70(int);
extern int func_L00_0032EF10(int, int, int *);
extern int func_L00_002D6418(void);
extern int func_L00_002ADF80(void);
extern int func_002829A8(void *, int);
extern int func_00294630(int);
extern void func_00294420(int);
extern void func_L00_002AB3E0(void);
extern int func_002A7820(int, int);
extern void func_L00_002B1308(int);
extern void func_L00_002AF7D0(void);
extern void func_002A7470(void *, int, int, int);

/* Applies the hero's pending item request for equipment slot SLOT. */
void func_L00_002B1350(int slot) {
    Vector point;
    int changed, keepHelmet, keepSuit, combo, sound, item;
    if (slot == 0) {
        if (((HeroState *)D_00189E20)->locked && ((HeroState *)D_00189E20)->slots[slot].item != 10)
            ((HeroState *)D_00189E20)->pending = 1;
    }
    if (slot == 0 && ((HeroState *)D_00189E20)->locked && ((HeroState *)D_00189E20)->slots[slot].item == 10) {
        if (((HeroState *)D_00189E20)->request[slot] == 0x1F) {
            qcopy(&point, &((HeroState *)D_00189E20)->position);
            point.f[2] += 1.5f;
            if (D_L00_00262570[D_00139568[0x1F]].fancy) func_L00_003ECC90(&point, 0xB02);
            else func_L00_003ECC90(&point, 0xCB2);
            ((HeroState *)D_00189E20)->request[slot] = 0;
        }
        if (((HeroState *)D_00189E20)->request[slot] == 9) {
            if (func_L00_002D3F30(9, 1)) ((HeroState *)D_00189E20)->armed = 1;
            else ((HeroState *)D_00189E20)->armed = 0;
            ((HeroState *)D_00189E20)->request[slot] = 0;
        }
        if (((HeroState *)D_00189E20)->request[slot] == 0x2D) {
            func_L00_003C3A70(D_L00_00262570[D_00139568[0x2D]].fancy != 0);
            ((HeroState *)D_00189E20)->request[slot] = 0;
        }
    }
    changed = 0;
    if (((HeroState *)D_00189E20)->blocked && slot == 0 &&
        (!((HeroState *)D_00189E20)->pending || ((HeroState *)D_00189E20)->slots[slot].item == 10)) {
        ((HeroState *)D_00189E20)->pending = 0;
        return;
    }
    if (func_L00_0032EF10(0x80, 3, 0) || ((HeroState *)D_00189E20)->pending) {
        if (slot == 0 && ((HeroState *)D_00189E20)->slots[slot].item != 10) {
            if (((HeroState *)D_00189E20)->pending) {
                if (((HeroState *)D_00189E20)->slots[slot].item != 0 && ((HeroState *)D_00189E20)->slots[slot].item != 0x1F && ((HeroState *)D_00189E20)->slots[slot].item != 0x2D && ((HeroState *)D_00189E20)->slots[slot].item != 9)
                    ((HeroState *)D_00189E20)->previous[slot] = ((HeroState *)D_00189E20)->slots[slot].item;
            }
            ((HeroState *)D_00189E20)->current[slot] = 10;
            changed = 1;
        }
    }
    if (slot == 0) {
        combo = 0;
        if (((HeroState *)D_00189E20)->slots[0].item == 10 && D_001A7398_m[0] && (D_001A7A80[D_001A7398_m[0]] & 0x20)) {
            if ((D_00138180[0x1A0 / 4] & 3) == 3) combo = (D_00138180[0x1A4 / 4] & 3) != 0;
        }
        if (((D_00138180[0x1A4 / 4] & 0x20) || ((D_00138180[0x1A4 / 4] & 5) && func_L00_002D6418()) || combo) &&
            !((HeroState *)D_00189E20)->locked) {
            item = D_001A7398[slot];
            if (((HeroState *)D_00189E20)->slots[0].item != item && item) {
                changed = 1;
                ((HeroState *)D_00189E20)->current[slot] = item;
            }
        }
    }
    if (slot == 1) {
        if (((HeroState *)D_00189E20)->state == 0xF && D_001A7B08[4]) {
            Slot *s = &((HeroState *)D_00189E20)->slots[slot];
            if (D_001A7398_m[1] != 0x14 || !s->item) {
                ((HeroState *)D_00189E20)->request[slot] = 0x14;
                if (s->item) ((HeroState *)D_00189E20)->previous[slot] = s->item;
                else ((HeroState *)D_00189E20)->previous[slot] = 0x77;
            }
        }
        if (((HeroState *)D_00189E20)->swimming && D_001A7B08[3] &&
            (D_001A7398_m[1] != 0x13 || !((HeroState *)D_00189E20)->slots[slot].item)) {
            ((HeroState *)D_00189E20)->request[slot] = 0x13;
            if (((HeroState *)D_00189E20)->slots[slot].item)
                ((HeroState *)D_00189E20)->previous[slot] = ((HeroState *)D_00189E20)->slots[slot].item;
            else ((HeroState *)D_00189E20)->previous[slot] = 0x77;
        }
    }
    if (slot == 2 && ((HeroState *)D_00189E20)->slots[slot].moby) {
        if (((HeroState *)D_00189E20)->state == 0x11 || ((HeroState *)D_00189E20)->move == 0x73 ||
            ((HeroState *)D_00189E20)->move == 0x67 || ((HeroState *)D_00189E20)->move == 0x7F ||
            ((HeroState *)D_00189E20)->diving)
            ((HeroState *)D_00189E20)->slots[slot].moby->visible = 1;
        else ((HeroState *)D_00189E20)->slots[slot].moby->visible = 0;
    }
    keepHelmet = 0;
    keepSuit = 0;
    if (slot == 3) {
        if (func_L00_002ADF80() || ((HeroState *)D_00189E20)->move == 0x12) {
            if (D_001A7398_m[3] != 4 && ((HeroState *)D_00189E20)->slots[slot].item != 4) {
                ((HeroState *)D_00189E20)->request[slot] = 4;
                keepHelmet = 1;
                ((HeroState *)D_00189E20)->previous[slot] = ((HeroState *)D_00189E20)->slots[slot].item;
            }
        } else if (((HeroState *)D_00189E20)->slots[slot].item == 4 && ((HeroState *)D_00189E20)->previous[slot]) {
            ((HeroState *)D_00189E20)->restore[slot] = 1;
        }
        if (((HeroState *)D_00189E20)->move == 0x82) {
            if (D_001A7398[slot] != 8 && ((HeroState *)D_00189E20)->slots[slot].item != 8) {
                keepSuit = 1;
                ((HeroState *)D_00189E20)->previous[slot] = ((HeroState *)D_00189E20)->slots[slot].item;
                ((HeroState *)D_00189E20)->request[slot] = 8;
            }
        } else if (((HeroState *)D_00189E20)->slots[slot].item == 8 && ((HeroState *)D_00189E20)->previous[slot]) {
            ((HeroState *)D_00189E20)->restore[slot] = 1;
        }
        if (((HeroState *)D_00189E20)->move == 8 &&
            (D_001A7398[slot] == 4 || D_001A7398[slot] == ((HeroState *)D_00189E20)->move)) {
            if (D_001A7A00[9]) ((HeroState *)D_00189E20)->request[slot] = 3;
            else ((HeroState *)D_00189E20)->request[slot] = 2;
        }
    }
    if (((HeroState *)D_00189E20)->restore[slot]) {
        ((HeroState *)D_00189E20)->restore[slot] = 0;
        item = ((HeroState *)D_00189E20)->previous[slot];
        if (item && item != ((HeroState *)D_00189E20)->slots[slot].item) {
            if (item == 0x77) item = 0;
            ((HeroState *)D_00189E20)->previous[slot] = 0;
            D_001A7398[slot] = item;
            ((HeroState *)D_00189E20)->current[slot] = item;
            if (slot == 0) D_L00_00262570[D_00139568[((HeroState *)D_00189E20)->current[0]]].flags = 0x20;
            changed = 1;
        }
    }
    if (((HeroState *)D_00189E20)->request[slot] == 0x1F || ((HeroState *)D_00189E20)->request[slot] == 0x3D) {
        qcopy(&point, &((HeroState *)D_00189E20)->position);
        point.f[2] += 1.5f;
        if (D_L00_00262570[D_00139568[0x1F]].fancy) func_L00_003ECC90(&point, 0xB02);
        else func_L00_003ECC90(&point, 0xCB2);
        ((HeroState *)D_00189E20)->request[slot] = 0;
    }
    if (((HeroState *)D_00189E20)->request[slot] == 9) {
        if (func_L00_002D3F30(9, 1)) ((HeroState *)D_00189E20)->armed = 1;
        else ((HeroState *)D_00189E20)->armed = 0;
        ((HeroState *)D_00189E20)->request[slot] = 0;
    }
    if (((HeroState *)D_00189E20)->request[slot] == 0x2D) {
        func_L00_003C3A70(D_L00_00262570[D_00139568[0x2D]].fancy != 0);
        ((HeroState *)D_00189E20)->request[slot] = 0;
    }
    if (((HeroState *)D_00189E20)->request[slot]) {
        if (((HeroState *)D_00189E20)->request[slot] != ((HeroState *)D_00189E20)->current[slot]) {
            if (slot == 1 && !((HeroState *)D_00189E20)->previous[slot]) {
                *(s16 *)&D_001A7A00[0x24] = ((HeroState *)D_00189E20)->request[slot];
                if (*(s16 *)&D_001A7A00[0x24] == 0x77) *(s16 *)&D_001A7A00[0x24] = 0;
            }
            if (((HeroState *)D_00189E20)->request[slot] == 0x77) {
                ((HeroState *)D_00189E20)->current[slot] = 0;
                D_001A7398[slot] = 0;
            } else {
                if (slot == 0) {
                    item = D_001A7398_m[0];
                    if (item != 0x26 && item != 0x33 && item && ((HeroState *)D_00189E20)->request[0] != 0x26 &&
                        ((HeroState *)D_00189E20)->request[0] != 0x33 && ((HeroState *)D_00189E20)->request[0] != item)
                        *(int *)&D_001A7A00[4] = item;
                }
                item = ((HeroState *)D_00189E20)->request[slot];
                ((HeroState *)D_00189E20)->current[slot] = item;
                if (!keepHelmet || item != 4) D_001A7398[slot] = item;
                if (!keepSuit || ((HeroState *)D_00189E20)->current[slot] != 8)
                    D_001A7398[slot] = ((HeroState *)D_00189E20)->current[slot];
                if (slot == 0) D_L00_00262570[D_00139568[((HeroState *)D_00189E20)->current[0]]].flags = 0x20;
            }
            changed = 1;
        } else {
            ((HeroState *)D_00189E20)->request[slot] = 0;
        }
    }
    if (((HeroState *)D_00189E20)->slots[slot].state == 2) changed = 0;
    if (((HeroState *)D_00189E20)->slots[slot].state == 1 && !((HeroState *)D_00189E20)->slots[slot].pose) ((HeroState *)D_00189E20)->slots[slot].pose = ((HeroState *)D_00189E20)->slots[slot].restPose;
    if (!func_002829A8(&((HeroState *)D_00189E20)->slots[slot].pose, 1)) changed = 0;
    if (slot == 0) {
        if (changed) {
            changed = 0;
            ((HeroState *)D_00189E20)->queued = ((HeroState *)D_00189E20)->current[0];
        }
        if (((HeroState *)D_00189E20)->queued) {
            sound = D_L00_00262570[D_00139568[((HeroState *)D_00189E20)->queued]].sound;
            if (!func_00294630(sound)) {
                func_00294420(sound);
            } else {
                changed = 1;
                ((HeroState *)D_00189E20)->current[0] = ((HeroState *)D_00189E20)->queued;
                ((HeroState *)D_00189E20)->queued = 0;
            }
        }
    }
    if (changed) {
        ((HeroState *)D_00189E20)->slots[slot].anim = 3;
        func_L00_002AB3E0();
        ((HeroState *)D_00189E20)->quickTimer = func_002A7820(0x32, 0x5A);
        func_L00_002B1308(((HeroState *)D_00189E20)->current[slot]);
        if (((HeroState *)D_00189E20)->refresh) func_L00_002AF7D0();
        if (slot == 0) {
            if (((HeroState *)D_00189E20)->current[0] == 10) D_001A7A00[8] = 1;
            else D_001A7A00[8] = 0;
        }
        if (slot == 3) {
            if (((HeroState *)D_00189E20)->slots[3].item == 3) D_001A7A00[9] = 1;
            else D_001A7A00[9] = 0;
        }
        ((HeroState *)D_00189E20)->slots[slot].swap = 0;
        ((HeroState *)D_00189E20)->request[slot] = 0;
        ((HeroState *)D_00189E20)->pending = 0;
        if (slot == 0 && D_L00_00262570[D_00139568[((HeroState *)D_00189E20)->current[slot]]].skin != ((HeroState *)D_00189E20)->skin) {
            if (((HeroState *)D_00189E20)->panel[0]) ((HeroState *)D_00189E20)->panel[0]->dirty = 1;
            if (((HeroState *)D_00189E20)->panel[1]) ((HeroState *)D_00189E20)->panel[1]->dirty = 1;
        }
        if (((HeroState *)D_00189E20)->slots[slot].moby && ((HeroState *)D_00189E20)->slots[slot].moby->cls->rank >= 3)
            func_002A7470(((HeroState *)D_00189E20)->slots[slot].moby, 2, 0, 2);
        if (((HeroState *)D_00189E20)->slots[slot].holster && slot != 3 &&
            ((HeroState *)D_00189E20)->slots[slot].holster->cls->rank >= 3)
            func_002A7470(((HeroState *)D_00189E20)->slots[slot].holster, 2, 0, 2);
        ((HeroState *)D_00189E20)->slots[slot].mode = 3;
    }
    if (slot == 2 && !D_001A7398_m[2] && !((HeroState *)D_00189E20)->slots[2].moby)
        ((HeroState *)D_00189E20)->request[2] = 0x2F;
    if (slot == 1 && !D_001A7398_m[1] && !((HeroState *)D_00189E20)->slots[1].moby)
        ((HeroState *)D_00189E20)->request[1] = 0x34;
}
