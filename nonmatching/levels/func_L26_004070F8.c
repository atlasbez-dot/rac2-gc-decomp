/* func_L26_004070F8 (312 bytes, 1 placement, level 26 jamming array): NEAR MISS.
   This plain C compiles to 308 bytes against retail's 312 and reproduces retail's
   instruction sequence everywhere except the register allocation of the first half.

   Measured with the project compiler (-O2 -G0 -ffunction-sections), the body was
   recovered: kind 0 clears the record (the byte at +0x30 becomes 0xFF, the record's
   words at +4 and +0x10 become 0) and switches it to kind 1; kind 1 runs the level's
   own checks and complains through func_00288E18 (the boot's func_00288E18) with the
   ids 0x9C5 and 0x9B5. The spellings that matter and were measured:
     - the switch on the moby's kind byte again reproduces retail's branch layout, with
       both case bodies out of line;
     - the constants are the ids 0x9C5/0x1C and 0x9B5/0xC, the mask 0xA5E0, the
       counter limit 0x4B1 and the level's own limit 0x597;
     - the second comparison is unsigned (`sltu`), the limit test is signed (`slti`);
     - the bit test at the end needs the mask in a variable: written as
       `(Z & (1u << S)) == 0` cc2 turns it into the "is the bit set" form
       (`srlv`/`andi`) instead of retail's `addiu $v0,$zero,1; sllv $v0,$v0,$a1`;
     - the condition before the second half of the checks is `U == 0 || a < b`: with the
       opposite polarity the checks end up inline instead of out of line.

   What is left:
     - the register allocation. Retail keeps the kind byte in $a1 and this cc1 in $a2,
       and retail loads the level's flag with the split-address form
       (`lui $v0,0x1B ; lw $v0,-0x7010($v0)`, the same register) where this cc1 uses a
       separate address register (`lui $v0 ; lw $v1,%lo($v0)`). Both are the same
       addresses; only the registers and the block order differ, and they follow from
       one free register that retail has and this cc1 does not.
     - the length: 308 against 312 bytes, one instruction short (retail materialises
       the level table's address twice, in the branch delay slot and in the body).

   The declarations below are the ones the body needs; the file it came from is
   src/levels/26_jamming_array/L26_002EC840.c. */

typedef unsigned char u8;
typedef unsigned short u16;

extern void func_002A7750(char *, int, int);
extern void func_00288E18(int, int);

extern int D_L26_001A8FF0;
extern int D_L26_001A79F0;
extern unsigned int D_L26_0018CAB0;
extern unsigned int D_L26_0018C9F0;
extern int D_L26_0018C0B4;
extern int D_L26_001B1748;
extern int D_L26_001A7390;

typedef struct {
    int f0;
    char pad[0x20];
    int f24;
} D_L26_0027D5C8_t;

typedef struct {
    char pad[0x1A4];
    unsigned short f1a4;
    int f1a8;
} D_L26_0018C750_t;

extern D_L26_0027D5C8_t D_L26_0027D5C8;
extern D_L26_0018C750_t D_L26_0018C750;

void func_L26_004070F8(char *a0) {
    char *m = a0;
    char *ctl = *(char **)(m + 0x68);
    u8 kind = *(u8 *)(m + 0x20);
    unsigned int mask;

    switch (kind) {
    case 0:
        *(u8 *)(m + 0x30) = 0xFF;
        *(int *)(ctl + 0x4) = 0;
        *(int *)(ctl + 0x10) = 0;
        func_002A7750(m, 1, -1);
        break;
    case 1:
        if (D_L26_001A8FF0 != 0) {
            if (D_L26_0027D5C8.f0 == 0 && D_L26_0027D5C8.f24 == -1) {
                if ((D_L26_0018CAB0 & ((unsigned int)kind << D_L26_001A79F0)) == 0) {
                    func_00288E18(0x9C5, 0x1C);
                }
            }
            if (D_L26_0018C750.f1a4 == 0 ||
                (unsigned int)(D_L26_0018C750.f1a4 | 0xA5E0) <
                    (unsigned int)(D_L26_001A7390 - D_L26_0018C750.f1a8)) {
                if (D_L26_0018C0B4 == 0 && D_L26_001B1748 >= 0x4B1) {
                    mask = 1u << D_L26_001A79F0;
                    if ((D_L26_0018C9F0 & mask) == 0) {
                        func_00288E18(0x9B5, 0xC);
                    }
                }
            }
        }
        break;
    }
}
