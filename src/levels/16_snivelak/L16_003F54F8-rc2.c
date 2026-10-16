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

extern void ref_L16_003F54F8_00(s8 *, s32, s32);
extern s32 ref_L16_003F54F8_01(s8 *, s32, s32);
extern void ref_L16_003F54F8_02(s8 *);
extern void ref_L16_003F54F8_03(s8 *);
extern void ref_L16_003F54F8_04(s32, s32, s8 *);
extern void ref_L16_003F54F8_05(s8 *);

void func_L16_003F54F8(s8 *arg0) {
    u8 temp_v1;

    temp_v1 = (*(u8 *)((s8 *)(arg0) + (0x20)));
    switch (temp_v1) {
    case 0:
        (*(s16 *)((s8 *)(arg0) + (0x32))) = 0x200;
        (*(u16 *)((s8 *)(arg0) + (0x34))) = (*(u16 *)((s8 *)(arg0) + (0x34))) | 0x4000;
        ref_L16_003F54F8_00(arg0, 1, -1);
        return;
    case 1:
        if (ref_L16_003F54F8_01(arg0, 0x80000, 0) != 0) {
            ref_L16_003F54F8_02(arg0);
            ref_L16_003F54F8_03(arg0);
            ref_L16_003F54F8_04(0, 0, arg0);
            ref_L16_003F54F8_05(arg0);
        }
        return;
    }
}
