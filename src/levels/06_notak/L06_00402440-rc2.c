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

extern void ref_L06_00402440_00(void *);
extern void ref_L06_00402440_01(void *, s32, s32);
extern s32 ref_L06_00402440_02(void *, s32, s32);
extern void ref_L06_00402440_03(void *, void *, f32, f32, f32);
extern void ref_L06_00402440_04(void *, void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void ref_L06_00402440_05(void *);
extern s32 ref_L06_00402440_06 __attribute__((sda));
extern s32 ref_L06_00402440_07 __attribute__((sda));
extern s32 ref_L06_00402440_08 __attribute__((sda));
extern s32 ref_L06_00402440_09 __attribute__((sda));

void func_L06_00402440(void *arg0) {
    u8 mode = *(u8 *)((u8 *)arg0 + 0x20);
    void *temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    f32 scratch[4];
    s32 temp_stack0 ;
    s32 temp_stack8 ;

    switch (mode) {
    case 0:
        if (*(s32 *)((u8 *)temp_s1 + 4) != 0) {
            *(u16 *)((u8 *)arg0 + 0x34) |= 0x8000;
        }
        ref_L06_00402440_01(arg0, 1, -1);
        return;
    case 1:
        if (ref_L06_00402440_02(arg0, 0x4010000, 0) != 0 && *(s32 *)temp_s1 == 0) {
            ref_L06_00402440_01(arg0, 2, -1);
        }
        *(u8 *)((u8 *)arg0 + 0xA8) = 0xFF;
        return;
    case 2:
        temp_stack0 = 0xFFFF;
        temp_stack8 = 0xFF;
        ref_L06_00402440_04(arg0, &ref_L06_00402440_08, &ref_L06_00402440_07, &ref_L06_00402440_06,
                     0xFFFF, 0, ref_L06_00402440_09, 6, temp_stack0, temp_stack8, 0);
        ref_L06_00402440_03(arg0, scratch, 1.0f, 1.0f, 3.0f);
        ref_L06_00402440_05(arg0);
        ref_L06_00402440_00(arg0);
        return;
    }
}
