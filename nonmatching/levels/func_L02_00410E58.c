/* Readable C reconstruction, 23 October 2026. Profile: -O2 -G0 -ffunction-sections -frac2-qcopy
 * -frac2-qcopy-barrier -mno-split-addresses -g.
 * us: 272/272 bytes, 0/7 carrying placements.
 * us2: 272/272 bytes, 0/7 carrying placements.
 * pal: 272/272 bytes, 0/7 carrying placements.
 * Three source/profile trials. A live child pointer removes two alias reloads and recovers
 * the 272-byte size. The remaining initial resident-base materialization and register schedule
 * differ at +0x4. -g did not improve it. Reopen with a truthful resident-view/address-lifetime
 * witness.
 * The historical screening below predates this C and is superseded; por/quadword instructions
 * alone are not evidence of handwritten assembly. No linked qualification was run.
 */

/* Superseded historical screen, retained for provenance. */
/* func_L02_00410E58 - 272 bytes, 7 place(s), level 02_maktar_nebula, retail
   at 0x00410e58. Screened with tools/w10_screen.py: 2 call(s)
   [func_0029EFD0@00410EB8, func_00283B98@00410F1C]; data addresses
   materialised [0x190000, 0x40060000]; float constants [-]; $gp-relative
   small data: no   saves: -; callee-saved registers saved [-]; words plain
   C cannot emit [LQ/SQ 7A820000@0x009c, LQ/SQ 7C620000@0x00a0, LQ/SQ
   7A620000@0x00a8, LQ/SQ 7C820000@0x00ac, COP1 46806B60@0x00b8]. Head:
   addiu $sp, $sp, -0x60 ; lui $v0, 0x19 ; sd $s0, 0x0($sp) ; sd $s1,
   0x8($sp) ; sd $s2, 0x10($sp) ; daddu $s1, $zero, $zero. Not matched in
   this wave: the 128-bit copy needs an `lq`/`sq` pair; plain C reaches it
   only through a `mode(TI)` local, and this cc1 folds the destination
   offset into the `sq` where retail materialises the pointer first. What
   would unblock it: the exact source expression tree, so this cc1 picks the
   same registers in the same order. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;
typedef int Quad __attribute__((mode(TI)));
extern u8 *func_0029EFD0(int);
extern float func_00283B98(float,float);
extern u8 D_00189E20[];

/* Create the three orbiting children with evenly spaced headings. */
void func_L02_00410E58(u8 *object)
{
    u8 **slot=(u8 **)(*(u8 **)(object+0x68)+0x14);
    int i=0;
    do {
        *slot=func_0029EFD0(0xC61);
        *(u16 *)(*slot+0x32)=0x40;
        (*slot)[0x31]=1;
        *(u64 *)(*slot+0x38)=*(u64 *)(*(u8 **)(D_00189E20+0x2290)+0x38);
        *(u16 *)(*slot+0x34)=*(u16 *)(object+0x34);
        {
            u8 *child=*slot;
            float heading;
            *(Quad *)(child+0x10)=*(Quad *)(object+0x10);
            *(Quad *)(child+0xF0)=*(Quad *)(object+0xF0);
            heading=func_00283B98(*(float *)(child+0xF8),(float)i*2.0943954f);
            *(float *)(*slot+0xF8)=heading;
        }
        slot++;
        i++;
    } while (i<3);
}
