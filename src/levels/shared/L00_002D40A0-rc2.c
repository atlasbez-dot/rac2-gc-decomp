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
extern s8 D_00189E20[];
extern void ref_L00_002D40A0_00(s32, s32);

void func_L00_002D40A0(TI *arg0, s32 arg1, f32 fparg0) {
    s8 *temp_v1 ;
    TI temp_v0 ;

    temp_v0 = *arg0;
    temp_v1 = D_00189E20 + 0x18A0;
    *(volatile TI *)temp_v1 = temp_v0;
    temp_v1 = temp_v1 - 0x18A0;
    (*(f32 *)((s8 *)(temp_v1) + (0x18AC))) = fparg0;
    (*(s32 *)((s8 *)(temp_v1) + (0x18B0))) = arg1;
    if ((u32)((*(s32 *)((s8 *)(temp_v1) + (0x2294))) - 0x62) >= 3U) {
        ref_L00_002D40A0_00(0x62, 2);
    }
}
