/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 144 / 148 bytes; size equality is not a match.
 * us: 0/1 placements; 144/148 bytes.
 * us2: not run / not reported.
 * pal: not run / not reported.
 * Residual: Retained readable C. Default -O2 -G0 -ffunction-sections. Retail uses the same table and fields; reconstruction remains nonmatching.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical manual summary: The earlier multiply-shape screen is superseded by the manual draft. R5900 multiply result behavior must be considered when revisiting allocation; the old screen does not establish handwritten-assembly status. The original map is retained privately; no extracted instruction, opcode, address or generated table is reproduced here. */

/* Retained readable C. Default -O2 -G0 -ffunction-sections.
 * Retail uses the same table and fields; reconstruction remains nonmatching.
 */
extern unsigned char D_00189E20[];
/* Latest trial: 144/148 bytes, US 0/1. Earlier result-variable form was
 * 148/148 but did not match the split address materialisation and result register.
 * The retail three-operand mult is a live record-stride multiplication, not an
 * assembly-only obstacle. Reopen with a meaningful control-flow/address form.
 */
extern unsigned char D_00139568[];
extern unsigned char D_L19_00265870[];
extern int func_L00_002ADEA0(int);

int func_L19_002A88C8(int enabled) {
    if (D_00189E20[0x22B4] == 4)
        return 13;
    if (enabled && D_00189E20[0x22BA] && *(short *)(D_00189E20 + 0x24EC) == 0)
        return *(int *)(D_L19_00265870 + D_00139568[func_L00_002ADEA0(0)] * 0xE0 + 0x28);
    if (*(int *)(D_00189E20 + 0x24CC) == 1)
        return 81;
    return 0;
}
