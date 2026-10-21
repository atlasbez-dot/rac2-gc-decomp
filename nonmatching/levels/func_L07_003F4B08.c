/* SPDX-License-Identifier: MIT
 * MIT License
 *
 * Copyright (c) 2026 RC2 decomp contributions
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "common.h"

/* Quadword copies: the grouped R5900 pattern reaches lq/sq with both addresses in registers.
   This unit needs -frac2-qcopy, so it lives in its own source file with that flag. */
typedef int TI128 __attribute__((mode(TI)));

extern void func_00282CC0(u8 *a, u8 *b, u8 *c);

extern void func_00282CF0(u8 *a, u8 *b, u8 *c);

extern void func_00283698(void *dst, void *src);

extern void func_00283098(void *dst, void *src, void *matrix);

extern u8 *func_0029EFD0(s32 size);

extern f32 func_002A7940(u8 *a);

/* Builds the tool's own record: the sampled vectors copied in, then the shared pass.
   The frame, the call sequence and the qcopy lq/sq pairs all match the retail bytes;
   what is left is the callee-saved register the parameter copy and the loaded pointer
   get: the retail puts the parameter copy in $s2 and the pointer in $s1, this draft puts
   the parameter copy in $s1 and the pointer in $s2. */
u8 *func_L07_003F4B08(u8 *a0, u8 *a1, void *a2, void *a3, f32 a4)
{
    f32 f;
    f32 m[16];
    u8 *s3;
    u8 *s1;
    u8 *p;
    u8 *src;
    u8 *v1;
    u8 *v2;

    f = a4;
    s3 = func_0029EFD0(0xE28);
    if (s3 != 0) {
        p = a0;
        src = p + 0x10;
        *(u32 *)(s3 + 0xB8) = (u32)p;
        *(TI128 *)(s3 + 0x10) = *(TI128 *)src;
        *(u8 *)(s3 + 0x30) = 0xFF;
        s1 = *(u8 **)(s3 + 0x68);
        v1 = s1 + 0x10;
        *(TI128 *)s1 = *(TI128 *)a2;
        *(TI128 *)v1 = *(TI128 *)a3;
        *(u32 *)(s1 + 0x20) = (u32)a1;
        *(u32 *)(s1 + 0x24) = 0;
        *(f32 *)(s1 + 0x28) = func_002A7940(src);
        *(f32 *)(s1 + 0x2C) = f;
        if (a1 != 0) {
            func_00283698(m, a1 + 0xC0);
            v2 = a1 + 0x10;
            func_00282CF0(s1, s1, v2);
            func_00282CF0(v1, v1, v2);
            func_00283098(s1, s1, m);
            func_00283098(v1, v1, m);
        }
    }
    return s3;
}
