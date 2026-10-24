/* 2026-10-23 reconstruction. Measured with -O2 -G32 -Wa,-G32 -ffunction-sections. us: 0/3 placements;
   05_feltzin_system: 768 bytes, expected 788; us2: 0/3 placements; 05_feltzin_system: 768 bytes,
   expected 788; pal: 0/3 placements; 05_feltzin_system: 768 bytes, expected 788. Three meaningful
   source/profile trials. Real eight-word palette, signed glyph metrics and 64-bit drawing arguments
   are retained. G32 plus GNU-as G32 gives the measured GP accesses; float loop scheduling and counter
   registers differ by20bytes. Reopen with a matching lookahead loop witness. Historical screening is
   preserved below. */

/* func_L05_00302CE8 - 788 bytes, 3 place(s), level 05_feltzin_system,
   retail at 0x00302ce8. Screened with tools/w10_screen.py: 3 call(s)
   [func_0027E018@00302EE8, func_0027E018@00302F30, func_0027E018@00302F7C];
   data addresses materialised [0xff0000]; float constants [-]; $gp-relative
   small data: yes   saves: -; callee-saved registers saved [-]; words plain
   C cannot emit [COP1 468010A0@0x00a8, COP1 46800020@0x00f4, COP1
   46800020@0x0120]. Head: addiu $sp, $sp, -0x70 ; sd $s1, 0x28($sp) ; daddu
   $s1, $t0, $zero ; sw $a0, 0x10($sp) ; sw $a1, 0x14($sp) ; dsll32 $v0,
   $s1, 0. Not matched in this wave: the float code has to come out of the
   same expression tree to keep the FPU registers. What would unblock it:
   the exact source expression tree, so this cc1 picks the same registers in
   the same order. */

#include "common.h"
typedef struct { u8 u,v; s8 y,advance; } L05Glyph;
extern u32 D_L05_001A8D00[8] __attribute__((sda));
extern int D_L05_001B2028 __attribute__((sda));
extern void func_0027E018(int,int,int,int,int,int,int,int,u64,u64);
int func_L05_00302CE8(int x,int y,int width,int height,u64 color,const u8 *text,int count,u64 texture,const L05Glyph *font)
{
    int index=0,cursorX=x,cursorY=y,scan;
    const u8 *word;
    const L05Glyph *glyph;
    float wordWidth,startX;
    u8 character;
    D_L05_001A8D00[0] = (s32)color;
    if (count && *text) {
        while (cursorY+16 <= y+height) {
            word = text+index;
            scan = index;
            startX = cursorX;
            wordWidth = 0.0f;
            if (index != count && *word != 32 && *word >= 16) {
                const u8 *p = word;
                do {
                    wordWidth += font[*p].advance;
                    ++scan;
                    ++p;
                } while (scan != count && *p != 32 && *p >= 16);
            }
            wordWidth = startX+wordWidth;
            if ((float)(x+width) < wordWidth) {
                if (*word != 32 && *word >= 16) --index;
                cursorY += 16;
                cursorX = x;
            } else if ((u32)(*word-8) < 8) {
                if (D_L05_001B2028) {
                    color &= 0xFF000000ULL;
                    color |= D_L05_001A8D00[*word-8]&0xFFFFFF;
                }
            } else {
                character = *word;
                if (font[character].advance != 0) {
                    if ((u8)(character+128) < 40) {
                        glyph = &font[character+64];
                        func_0027E018(cursorX+glyph->advance,cursorY+glyph->y,16,16,glyph->u,glyph->v,16,16,color,texture);
                    }
                    character = *word;
                    if (character < 32) {
                        glyph = &font[character];
                        func_0027E018(cursorX,cursorY+glyph->y,24,16,glyph->u,glyph->v,24,16,color,texture);
                    } else if (character > 32) {
                        glyph = &font[character];
                        func_0027E018(cursorX,cursorY+glyph->y,16,16,glyph->u,glyph->v,16,16,color,texture);
                    }
                    cursorX += font[*word].advance;
                }
            }
            ++index;
            if (index == count || text[index] == 0) break;
        }
    }
    return cursorY-y+16;
}
