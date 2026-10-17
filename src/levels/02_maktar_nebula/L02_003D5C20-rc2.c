
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

void func_L02_003D5C20(void *arg0) {
    s32 *var_s0;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 var_s2;
    void *temp_s1;
    void *temp_s4;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s1 + 0x300);
    if (temp_a0 != 0) {
        ref_L02_003D5C20_00(temp_a0);
        *(s32 *)((u8 *)temp_s1 + 0x300) = 0;
    }
    temp_s4 = (u8 *)temp_s1 + 0x220;
    var_s0 = (s32 *)((u8 *)temp_s1 + 0x2A0);
    var_s2 = 4;
    do {
        temp_a0_2 = *var_s0;
        var_s2 -= 1;
        if (temp_a0_2 != 0) {
            ref_L02_003D5C20_01(temp_a0_2);
            *var_s0 = 0;
        }
        var_s0 += 1;
    } while (var_s2 >= 0);
    if (*(u8 *)((u8 *)temp_s1 + 0x261) != 0) {
        ref_L02_003D5C20_02(arg0, (u8 *)temp_s1 + 0x260);
    }
    if (*(u8 *)((u8 *)temp_s1 + 0x221) != 0) {
        ref_L02_003D5C20_02(arg0, temp_s4);
    }
    ref_L02_003D5C20_03(temp_s4, 0, 0x40);
    ref_L02_003D5C20_03(temp_s4, 0, 0x40);
}
