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

extern void func_002FC560(s32 a, s64 b);
extern void func_0027DE50(s32 a, s16 b, s32 c, s16 d, u64 e);
extern s32 D_001A72E0;
extern s8 D_001A6480[];

void func_0027DCE8(void *arg0) {
    s64 temp_v0;
    s8 *p;

    temp_v0 = (*(s64 *)((s8 *)(arg0) + (8)));
    if (temp_v0 != 0) {
        func_002FC560(0x42, temp_v0 & (((s64)0xFF00 << 24) | 0xFF));
    }
    if ((*(s32 *)((s8 *)(arg0) + (4))) & 0xFF000000) {
        func_002FC560(0x4E, ((D_001A72E0 >> 13) | 0x01000000) | ((s64)0x8000 << 17));
        p = D_001A6480;
        func_0027DE50(0, *(s16 *)(p + 0x152), 0, *(s16 *)(p + 0x150), (*(u32 *)((s8 *)(arg0) + (4))));
        func_002FC560(0x4E, 0x01000000 | (D_001A72E0 >> 13));
    }
    if ((*(s64 *)((s8 *)(arg0) + (8))) != 0) {
        func_002FC560(0x42, ((s64)0x8000 << 24) | 0x44);
    }
}
