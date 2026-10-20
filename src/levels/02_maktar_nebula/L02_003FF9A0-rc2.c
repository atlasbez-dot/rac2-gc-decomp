
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

extern s8 D_0018C0B4[];
extern s32 ref_L02_003FF9A0_00 __attribute__((sda));
extern s8 D_001395B8[];
extern u8 D_00139568[];
extern s8 ref_L02_003FF9A0_01[];
extern s8 ref_L02_003FF9A0_02[];
extern void ref_L02_003FF9A0_03(s32, s32);
extern s32 ref_L02_003FF9A0_04(s32, s32, s32);
extern void ref_L02_003FF9A0_05(void *, s32, s32);
extern s32 ref_L02_003FF9A0_06(void);
extern void *ref_L02_003FF9A0_07(s32);
extern void ref_L02_003FF9A0_08(void *);
extern void ref_L02_003FF9A0_09(void *, void *);

void func_L02_003FF9A0(s8 *arg0) {
    void *s2;
    void **p;
    void *ret;
    s32 idx;
    s8 *b6;
    u8 *b5;
    s8 *b4;
    u8 flag;

    s2 = *(void **)((s8 *)arg0 + 0x68);
    if (*(s32 *)D_0018C0B4 != 0x6F) {
        ref_L02_003FF9A0_03(0x6F, 1);
    }
    if (ref_L02_003FF9A0_04(0x40, 0x3C, 0) != 0) {
        ref_L02_003FF9A0_05(arg0, 7, -1);
        idx = *(s16 *)((s8 *)s2 + 0x118) + 1;
        if (idx < 0xE) {
            b6 = D_001395B8;
            b5 = D_00139568;
            b4 = ref_L02_003FF9A0_01;
            p = (void **)((s32)(idx * 4) + (s32)&ref_L02_003FF9A0_00);
            do {
                ret = ref_L02_003FF9A0_07(*(s32 *)((s8 *)*p + 8));
                flag = *(u8 *)((s32)ret + (s32)b6);
                if (flag == 0) {
                    goto next;
                }
                if (idx >= 0xC) {
                    if (ref_L02_003FF9A0_06() == 0) {
                        goto next;
                    }
                }
                if (idx == 7) {
                    if (*(u8 *)(b4 + (s32)b5[0x1E] * 0xE0 + 4) == 0) {
                        goto next;
                    }
                }
                if (idx == 8) {
                    if (*(u8 *)(b4 + (s32)b5[0x2A] * 0xE0 + 4) == 0) {
                        goto next;
                    }
                }
                *(s16 *)((s8 *)s2 + 0x118) = idx;
                *(u8 *)(b6 + 0x3C) = *(u8 *)((s8 *)s2 + 0x118);
                return;
next:
                idx += 1;
                p += 1;
            } while (idx < 0xE);
        }
    } else {
        if (ref_L02_003FF9A0_04(0x10, 0x3C, 0) != 0) {
            ref_L02_003FF9A0_08(arg0);
            return;
        }
        ref_L02_003FF9A0_09(ref_L02_003FF9A0_02, arg0);
    }
}
