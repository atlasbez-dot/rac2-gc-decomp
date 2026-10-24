/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: SDK EE-GCC 2.9-ee-991111-01.
 * Profile: sdk -O2 -G2 -ffunction-sections.
 * Reported final C / retail: 680 / 692 bytes; size equality is not a match.
 * us: 0/1 placements.
 * us2: not run: US candidate failed.
 * pal: not run: US candidate failed.
 * Residual: Retained readable frame-bank selection/metadata body. Five forms: 680,696,708,704,704 /692; branch merging, swaps and allocation unresolved.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Identity: rac2 = rac1 + 0x3E20 in this object (0012D100.c's func_0012D420
   is rac1 src/core/00125630.c func_00129600), so 0x0012D4B0 is rac1's
   func_00129690 -- which rac1 keeps as `INCLUDE_ASM` (line 1821 of that
   file), i.e. unmatched there too.  The bytes are identical: searching the
   rac1 boot ELF for this body finds it at 0x00129550, exactly rac1's
   0x00129690 minus the 0x140 shift the ELF has from rac1-decomp's PAL
   addresses over this region.

   It opens with `t1 = s[0x174]; t2 = s[0x150]; xori $v0,$t1,3` -- the same
   two selector fields and the same `== 3` tests as its matched neighbour
   func_00129600 in 0012D100.c -- and then runs a 692-byte dispatch with
   four arms and the same `- 1` countdown shape.  Reading func_00129600
   first is the cheapest way in.

   Not attempted as C in this run: no rac1 source, no near miss already paid
   for it, and 692 bytes of recursive arm selection is more than one
   iteration of this wave's budget. */

/* Expanded screening: sdk -O2 -G2 -ffunction-sections.
 * Five distinct forms, best initial 680/692 bytes, later 696/708/704/704. Initial frame metadata tail and first control-flow region agree structurally; branch sharing, ready-value materialization and buffer-swap scheduling differ. Retained final structured control-flow variant is 704 bytes. Reopen with a concrete CFG/allocation hypothesis.
 * tools/check.py func_0012D4B0 --diff --version us: 0 of 1 places; exit 1.
 */
/* Select the decoded picture buffers and publish frame metadata. */
int func_0012D4B0(void *arg0, int second_field) {
    char *s = arg0;
    int structure = *(int *)(s + 0x174);
    int picture_type = *(int *)(s + 0x150);
    char *frame = 0;
    int ready = 0;
    int threshold = structure == 3 ? 2 : 4;
    char *temp;

    if (picture_type == 3) {
        *(int *)(s + 0x1C0) = *(int *)(s + 0x1C4);
        *(int *)(s + 0x1D0) = *(int *)(s + 0x1D4);
        *(int *)(s + 0x1E0) = *(int *)(s + 0x1E4);
        if (*(int *)(s + 0xA0) + *(int *)(s + 0xA4) >= threshold) {
            *(int *)(s + 0xE8) = 0;
            *(int *)(s + 0x1A8) = 0;
            *(int *)(s + 0x1A4) = 0;
        }
        if ((*(int *)(s + 0xE8) != 0 || *(int *)(s + 0x1A8) != 0) &&
            *(int *)(s + 0x1A4) == 0) {
            *(int *)(*(char **)(s + 0x1B8) + 0x28) = 0;
            *(int *)(*(char **)(s + 0x1C8) + 0x28) = 0;
            *(int *)(*(char **)(s + 0x1D8) + 0x28) = 0;
            structure = *(int *)(s + 0x174);
        }
        *(int *)(s + 0xE8) = 0;
        *(int *)(s + 0x1A8) = 0;
        if (structure == 3) {
            if (*(int *)(*(char **)(s + 0x1B8) + 0x28) == 1 ||
                *(int *)(s + 0x1A4) != 0) {
                ready = *(int *)(*(char **)(s + 0x1BC) + 0x28) == 1;
            }
        } else if ((*(int *)(*(char **)(s + 0x1C8) + 0x28) == 1 &&
                    *(int *)(*(char **)(s + 0x1D8) + 0x28) == 1) ||
                   *(int *)(s + 0x1A4) != 0) {
            if (*(int *)(*(char **)(s + 0x1CC) + 0x28) == 1) {
                ready = *(int *)(*(char **)(s + 0x1DC) + 0x28) == 1;
            }
        }
    } else {
        if (second_field == 0) {
            temp = *(char **)(s + 0x1B8);
            *(char **)(s + 0x1B8) = *(char **)(s + 0x1BC);
            *(char **)(s + 0x1BC) = temp;
            temp = *(char **)(s + 0x1C8);
            *(char **)(s + 0x1C8) = *(char **)(s + 0x1CC);
            *(char **)(s + 0x1CC) = temp;
            temp = *(char **)(s + 0x1D8);
            *(char **)(s + 0x1D8) = *(char **)(s + 0x1DC);
            *(char **)(s + 0x1DC) = temp;
        }
        *(int *)(s + 0x1C0) = *(int *)(s + 0x1BC);
        *(int *)(s + 0x1D0) = *(int *)(s + 0x1CC);
        *(int *)(s + 0x1E0) = *(int *)(s + 0x1DC);
        if (structure == 3) {
            if (picture_type != 2) goto mark_ready;
            if (*(int *)(*(char **)(s + 0x1B8) + 0x28) == 1) goto mark_ready;
        } else {
            temp = structure == 1 ? *(char **)(s + 0x1DC) : *(char **)(s + 0x1CC);
            if (picture_type != 2) goto mark_ready;
            if (second_field != 0 && *(int *)(temp + 0x28) == 1) goto mark_ready;
            if (*(int *)(*(char **)(s + 0x1C8) + 0x28) == 1 &&
                *(int *)(*(char **)(s + 0x1D8) + 0x28) == 1) goto mark_ready;
        }
        goto publish;
mark_ready:
        ready = 1;
    }
publish:
    switch (structure) {
        case 3: frame = *(char **)(s + 0x1C0); break;
        case 1: frame = *(char **)(s + 0x1D0); break;
        case 2: frame = *(char **)(s + 0x1E0); break;
    }
    *(int *)(frame + 0x28) = 0;
    *(unsigned long *)(frame + 0x18) = *(unsigned long *)(s + 0x828);
    *(int *)(frame + 0x2C) = *(int *)(s + 0x150);
    *(unsigned long *)(frame + 0x20) = *(unsigned long *)(s + 0x830);
    *(int *)(frame + 0x30) = *(int *)(s + 0x174);
    *(int *)(frame + 0x34) = *(int *)(s + 0x13C);
    *(int *)(frame + 0x38) = *(int *)(s + 0x188);
    *(int *)(frame + 0x3C) = *(int *)(s + 0x178);
    *(int *)(frame + 0x40) = *(int *)(s + 0x184);
    *(int *)(frame + 0x44) = *(int *)(s + 0x18C);
    *(int *)(frame + 0x48) = *(int *)(s + 0x190);
    *(int *)(frame + 0x4C) = *(int *)(s + 0x194);
    *(int *)(frame + 0x50) = *(int *)(s + 0x198);
    *(int *)(frame + 0x54) = *(int *)(s + 0x19C);
    *(int *)(frame + 0x58) = *(int *)(s + 0x1A0);
    *(int *)(frame + 0x5C) = *(int *)(s + 0x148);
    *(int *)(frame + 0x60) = *(int *)(s + 0x14C);
    return ready;
}
