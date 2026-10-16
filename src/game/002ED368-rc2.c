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

extern s32 D_001ABF0C;
extern f32 func_00283CE0(s32);
extern s32 func_00283CF0(f32);
extern s32 func_00283D38(s32, s32, f32);
extern f32 func_00283B98(f32, f32);
extern f32 func_002A7878(f32, f32);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282D30(void *, f32, void *);
extern s32 func_00282948(void *);

void func_002ED368(s32 arg0) {
    s8 *temp_s0;
    s8 *temp_s1;
    f32 temp_f20;
    s32 temp_v1;
    s32 var_s2;
    s32 var_s3;

    if (D_001ABF0C != 0) {
        var_s3 = 0;
        var_s2 = 0;
        do {
            temp_s1 = (s8 *) (var_s2 + D_001ABF0C);
            if ((*(s32 *)((s8 *)(temp_s1) + (0x48))) == arg0) {
                temp_f20 = func_00283CE0((*(s32 *)((s8 *)(temp_s1) + (0x40))));
                temp_f20 = temp_f20 / func_00283CE0((*(s32 *)((s8 *)(temp_s1) + (0x44))));
                (*(s32 *)((s8 *)(temp_s1) + (0x38))) = func_00283CF0((f32) (*(s32 *)((s8 *)(temp_s1) + (0x34))) * temp_f20);
                temp_v1 = (*(s32 *)((s8 *)(temp_s1) + (0x2C)));
                (*(s32 *)((s8 *)(temp_s1) + (0x30))) = temp_v1;
                (*(s32 *)((s8 *)(temp_s1) + (0x30))) = func_00283D38(0x3F3F3F, temp_v1, temp_f20 * temp_f20 * temp_f20);
                (*(f32 *)((s8 *)(temp_s1) + (0x24))) = func_00283B98((*(f32 *)((s8 *)(temp_s1) + (0x24))), (*(f32 *)((s8 *)(temp_s1) + (0x20))));
                if ((*(s32 *)((s8 *)(temp_s1) + (0x3C))) != 0) {
                    (*(f32 *)((s8 *)(temp_s1) + (0x28))) = (*(f32 *)((s8 *)(temp_s1) + (0x28))) + func_002A7878(0.00100000005f, 0.00300000003f);
                }
                temp_s0 = temp_s1 + 0x10;
                func_00282CC0(temp_s1, temp_s1, temp_s0);
                func_00282D30(temp_s0, 0.99000001f, temp_s0);
                if (func_00282948(temp_s1 + 0x40) != 0) {
                    (*(s32 *)((s8 *)(temp_s1) + (0x48))) = 0;
                }
            }
            var_s3 += 1;
            var_s2 += 0x50;
        } while (var_s3 < 0x200);
    }
}
