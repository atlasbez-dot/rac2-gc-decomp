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

extern s32 ref_L03_00425030_00(s32);

void func_L03_00425030(void *arg0) {
    s8 *temp = *(s8 **)((s8 *)arg0 + 0x68);
    f32 *random_out;
    s8 *cursor;
    s32 count;
    s32 value;
    s32 fill_count ;

    count = 3;
    random_out = (f32 *)(temp + 0x10);
    do {
        count -= 1;
        *random_out = (f32)ref_L03_00425030_00(0xFF);
        random_out += 1;
    } while (count >= 0);

    fill_count = 3;
    cursor = temp + 0x3C;
    value = 0xFF;
    *(f32 *)(temp + 0x20) = -1.0f;
    *(f32 *)(temp + 0x24) = -2.25f;
    *(f32 *)(temp + 0x28) = 1.25f;
    *(f32 *)(temp + 0x2C) = 2.5f;
    do {
        *(s32 *)cursor = value;
        fill_count -= 1;
        cursor -= 4;
        value -= 0x40;
    } while (fill_count >= 0);
    *(volatile f32 *)(temp + 0x4C) = 2.0f;
    *(volatile f32 *)(temp + 0x48) = 2.46f;
    *(volatile f32 *)(temp + 0x40) = 2.0f;
    *(volatile f32 *)(temp + 0x44) = 2.46f;
}
