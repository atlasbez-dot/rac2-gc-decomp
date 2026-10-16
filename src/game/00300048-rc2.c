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

extern void func_00282D30(void *, void *, f32);
extern void func_00282CC0(void *, void *, void *);
extern void func_002A7A00(void *, f32, f32);
extern s32 func_002A7820(s32, s32);
extern void func_0032E588(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32);
extern s8 D_001B5570[];
extern f32 D_001AD820 __attribute__((sda));
extern f32 D_001AD824 __attribute__((sda));
extern f32 D_001AD828 __attribute__((sda));
extern f32 D_001AD82C __attribute__((sda));

void func_00300048(void) {
    s8 A[16];
    s8 B[16];
    s8 C[16];
    s8 D[16];
    s32 n = 5;
    s8 *P = D_001B5570;
    s8 *Q = P - 0x230;
    do {
        n -= 1;
        func_00282D30(A, P, 9.0f);
        func_00282CC0(B, Q, A);
        func_002A7A00(C, 0.1f, 3.0f);
        func_00282D30(A, P, 3.0f);
        func_00282CC0(D, Q, A);
        func_00282CC0(C, D, C);
        func_0032E588(B, C, func_002A7820(8, 12), 0x808080, 0x808080, 0xFF1010, 0xFF1010, 0xFF1010, D_001AD820, D_001AD824, D_001AD828, D_001AD82C);
    } while (n >= 0);
}
