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

extern void func_0027AB40();
extern void func_002E5E58();
extern void func_0033AE28();
extern void func_0033B018(s32, f32, f32);
extern u8 D_001A7BB1;
extern u8 D_001A7BB0[];

s32 func_0033C2D8(s32 arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 8;
    func_0033AE28(temp_s0);
    temp_v0 = (*(s32 *)((s8 *)(arg0) + (0x2AC)));
    func_0033B018(temp_s0, (*(f32 *)((s8 *)(temp_v0) + (0))), (*(f32 *)((s8 *)(temp_v0) + (4))));
    if (arg1 & 0x40) {
        if ((*(s32 *)((s8 *)(arg0) + (0x2A8))) == 0) {
            D_001A7BB0[1] = (D_001A7BB1 == 0);
            func_002E5E58(4, 0, 0);
            func_0027AB40();
        }
    }
    return (arg1 >> 6) & 1;
}
