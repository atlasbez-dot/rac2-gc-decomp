
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

extern void ref_L01_003EE6F0_00();
extern s32 ref_L01_003EE6F0_01(void *);
extern void ref_L01_003EE6F0_02(void *, s32, s32);
extern void ref_L01_003EE6F0_03(void *, s32, s32, s32);
extern s32 ref_L01_003EE6F0_04 __attribute__((sda));
extern s32 ref_L01_003EE6F0_05 __attribute__((sda));

void func_L01_003EE6F0(s8 *arg0) {
    s8 *s1;
    s32 st;
    s32 flags;
    f32 f0;
    f32 f2;
    s32 tv;

    s1 = *(s8 **)(arg0 + 0x68);
    ref_L01_003EE6F0_00();
    st = *(u8 *)(arg0 + 0x20);
    switch (st) {
    case 0:
        f2 = *(f32 *)(arg0 + 0xF0);
        f0 = *(f32 *)(arg0 + 0x18) + 1.0f;
        *(f32 *)(arg0 + 0x18) = f0;
        *(f32 *)(s1 + 0x14) = f2;
        *(u8 *)(arg0 + 0x20) = 1;
        if (*(u8 *)(arg0 + 0x43) != 0) {
            ref_L01_003EE6F0_03(arg0, 0, 0, 0xC);
        }
        *(s32 *)(s1 + 0x50) = 0;
        *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) | 0x1000;
        break;
    case 1:
        if ((*(u8 *)(arg0 + 0x60) & 2) != 0 && *(u8 *)(arg0 + 0x43) != 0) {
            ref_L01_003EE6F0_02(arg0, 0, 0);
        }
        if (*(u8 *)(arg0 + 0xBC) != 0) {
            *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) & 0xEFFF;
            ref_L01_003EE6F0_02(arg0, 1, 0);
            if (*(s32 *)s1 != 0) {
                *(s32 *)(s1 + 0x10) = 0xA;
                *(u8 *)(arg0 + 0x20) = 2;
                *(s32 *)(s1 + 0xC) = *(s32 *)(s1 + 4);
                break;
            }
            tv = ref_L01_003EE6F0_05;
            *(u8 *)(arg0 + 0x20) = 2;
            *(s32 *)(arg0 + 0x78) = tv;
            *(s32 *)(s1 + 0xC) = 0;
        }
        break;
    case 2:
        if (*(s32 *)s1 != 0) {
            if (ref_L01_003EE6F0_01(s1 + 0x10) != 0) {
                if (*(s32 *)(arg0 + 0x78) == ref_L01_003EE6F0_04) {
                    *(s32 *)(arg0 + 0x78) = ref_L01_003EE6F0_05;
                } else {
                    *(s32 *)(arg0 + 0x78) = ref_L01_003EE6F0_04;
                }
                *(s32 *)(s1 + 0x10) = 0xA;
            }
            if (ref_L01_003EE6F0_01(s1 + 0xC) != 0) {
                *(u8 *)(arg0 + 0xBC) = 0;
            }
        }
        flags = *(u8 *)(arg0 + 0x60);
        if ((flags & 2) != 0) {
            if (*(u8 *)(arg0 + 0x43) == 1) {
                ref_L01_003EE6F0_02(arg0, 2, 0);
            }
        }
        if (*(u8 *)(arg0 + 0xBC) == 0 && (*(u8 *)(arg0 + 0x60) & 2) != 0) {
            *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) | 0x1000;
            ref_L01_003EE6F0_02(arg0, 3, 0);
            tv = ref_L01_003EE6F0_04;
            *(u8 *)(arg0 + 0x20) = 1;
            *(s32 *)(arg0 + 0x78) = tv;
        }
        break;
    }
}
