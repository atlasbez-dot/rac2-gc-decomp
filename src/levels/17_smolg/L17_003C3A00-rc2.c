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

typedef int TI __attribute__((mode(TI)));
typedef struct { f32 f0, f1, f2, f3; } V4;

extern f32 ref_L17_003C3A00_00(f32);
extern void ref_L17_003C3A00_01(s8 *, s8 *, s8 *);
extern void ref_L17_003C3A00_02(s8 *, s8 *, s32);
extern void ref_L17_003C3A00_03(s8 *, s8 *, s8 *);
extern f32 ref_L17_003C3A00_04 __attribute__((sda));
extern f32 ref_L17_003C3A00_05 __attribute__((sda));

s32 func_L17_003C3A00(s8 *arg0, TI *arg1, s32 arg2) {
    V4 loc0;
    V4 sp10;
    s8 pad[0x30];
    V4 sp50;
    V4 sp60;

    *(TI *)&loc0 = *arg1;
    ref_L17_003C3A00_02((s8 *)&sp10, arg0 + 0xC0, arg2);
    ref_L17_003C3A00_01((s8 *)&sp60, (s8 *)&loc0, arg0 + 0x10);
    *(TI *)&sp50 = *(TI *)&sp60;
    ref_L17_003C3A00_03((s8 *)&sp50, (s8 *)&sp50, (s8 *)&sp10);
    if (!(ref_L17_003C3A00_00(sp50.f0) < ref_L17_003C3A00_04)) {
        return 0;
    }
    if (!(ref_L17_003C3A00_00(sp50.f1) < ref_L17_003C3A00_05)) {
        return 0;
    }
    if (!(ref_L17_003C3A00_00(loc0.f2 - *(f32 *)(arg0 + 0x18)) < 4.0f)) {
        return 0;
    }
    if (0.9f < *(f32 *)(arg0 + 0x18) - loc0.f2) {
        return 1;
    }
    return 0;
}
