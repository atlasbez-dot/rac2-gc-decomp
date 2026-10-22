/* func_00350190 - 76 bytes, 28 places (the boot and every level).

   Near miss: 68 of 76 bytes match at every place.  The only difference is the
   pair of privileged instructions the retail body ends with:

       0x003501c4  0000000f  sync
       0x003501c8  42000038  ei

   The rest of the body is reproduced byte for byte by the C below, including
   the `lui`/`lw` pairs for D_001AE7D8 and D_001B23CC and the store through
   `$at`.

   `sync` and `ei` are privileged R5900 instructions that this compiler never
   emits.  Measured: `__builtin___sync_synchronize()` compiles to a call to
   an undefined `__builtin___sync_synchronize` symbol, and `strings` on
   build/compiler/tools/cc1 shows no `sync` builtin at all.  The only C
   spelling of them is an inline `asm`, which AGENTS.md forbids in src/.

   What would unblock it: a maintainer decision to accept this body as
   handwritten assembly (ASM_FUNC), because it uses instructions the
   compiler never emits; or a compiler option that lowers a barrier to
   `sync`/`ei`.

   Tried: the C below with the `sda` attribute on both globals (which is what
   gives the retail's `lui`/`lw` pairs and the store through `$at`).
*/

extern volatile int D_001AE7D8 __attribute__((sda));
extern char *D_001B23CC[] __attribute__((sda));
extern void func_00351FA0(unsigned char *);

int func_00350190(void)
{
    if (D_001AE7D8 != 0) {
        func_00351FA0(D_001B23CC[0] + 0xD9168);
        D_001AE7D8 = 0;
    }
    return 0;
}
