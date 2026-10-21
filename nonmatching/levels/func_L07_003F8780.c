/* Near miss from src/levels/07_siberius/L07_003F4578-g8.c: the build refuses this body at its
   place — instruction at +0x70 differs. Kept as a starting point;
   not linked, not counted. */

/* Standalone declarations recovered from src/levels/07_siberius/L07_003F4578-g8.c. */
typedef unsigned char      u8;

typedef unsigned int       u32;

typedef signed int         s32;

typedef float              f32;

extern void func_421288(s32 a, f32 b, f32 c);

extern void func_4212D0(f32 a, f32 b);

extern u8 *func_2CD050(s32 a);

extern f32 D_L07_001B10B8 __attribute__((sda));

extern f32 D_L07_001B10BC __attribute__((sda));

extern u32 D_L07_001B10C0 __attribute__((sda));

void func_L07_003F8780(u8 *a0)
{
    u8 *s1 = *(u8 **)(a0 + 0x68);

    func_421288(0, D_L07_001B10B8, 0.003f);
    func_4212D0(D_L07_001B10BC, 0.003f);
    if (*(u8 *)(a0 + 0x95) != 0) {
        if (*(u32 *)(s1 + 0x450) == 0)
            *(u32 *)(s1 + 0x450) = func_2CD050(5);
        *(f32 *)(*(u8 **)(s1 + 0x450) + 0x0) = D_L07_001B10B8;
        *(f32 *)(*(u8 **)(s1 + 0x450) + 0x4) = D_L07_001B10BC;
        *(u32 *)(*(u8 **)(s1 + 0x450) + 0x34) = D_L07_001B10C0;
    }
}

/* --- wave 24, worker 04 (2026-10-21) --------------------------------------------
   Re-measured: 164 bytes, 35 of 41 words identical, the fault is the scheduler's
   order of the two $gp constant loads in the last block (ours keeps them next to
   their use, retail hoists them to the top of the block); the rest of the body
   matches word for word, including the 0.003f constant in $f20 saved in the
   frame and the four reloads of the 0x450 slot.
   What I added to the measurements:
   - the constant is 0.003f (0x3B449BA6), and the file's own `f32 f = 0.003f`
     local and the literal spelled twice both give the same 164 bytes.
   - the 0x450 pointer must be re-read from the slot for every store (the stores
     may alias it): a local pointer gives none of the reloads.
   - reading the three constants into locals first keeps them in $f21/$f22 and
     grows the frame to 0x38; the (u8 *) cast on all three stores, the word-index
     form of the offsets (+1, +0xD) and the reverse order of the second and third
     store change nothing.
   Last check.py line: "07_siberius: instruction at +0x70 differs". */
