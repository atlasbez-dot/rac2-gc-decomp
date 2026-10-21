/* func_L08_0042F938 (392 bytes, 1 place) - NOT ATTEMPTED, never compiled.
 *
 * The reading of the retail disassembly, for whoever takes it next:
 *
 *  - the record's byte at +0x20 is the state: 1 takes the "already spawned" arm
 *    (it asks func_32A170(a0, 0x401, 0) for the model, gives up with
 *    *(u8 *)(a0 + 0xA8) = 0xFF when the model is missing or already in use, and
 *    otherwise calls func_327758(a0, 2, -1) and still gives up with 0xFF);
 *    0 calls func_327758(a0, 1, -1) and returns; 2 runs the whole body; anything
 *    above 2 returns 0.
 *
 *  - the body builds a 16-byte block on the stack at sp+0x20 (the retail stores it
 *    with `sq $v0,0x20($sp)`, so the low half comes out of the argument
 *    registers, and `swc1 $f0,0x28($sp)` puts 7.0f in the upper half), hands it
 *    to func_2F9DF0(a0 = &block, a1 = a0 + 0x10, a2 = &block), then calls
 *    func_4061F8(&block, 1, 25, 20, 20, 20, 45, 1) and
 *    func_3386D8(a0, $gp+0x2F00, $gp+0x2EF8, $gp+0x2EF0, 0xFFFF, 0, -1, 7),
 *    and ends with func_334860(a0, 5), func_3352F8(a0, 4768, 0) and
 *    func_31D540(a0).
 *
 *  - the three $gp-relative words are level-08 data at 0x1B1EF0, 0x1B1EE8 and
 *    0x1B1EE0 ($gp = 0x1AEFF0).  A C reference to them therefore needs a -G8
 *    source unit, e.g. src/levels/08_tabora/L08_00423970-g8.c with the
 *    declarations marked __attribute__((sda)).
 *
 *  - the block's first word is the state byte again, so the `sq` form suggests a
 *    128-bit local assigned from the argument registers; that is the part that
 *    needs the most work to reproduce.
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;
