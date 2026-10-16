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

extern f32 ref_L00_003C2F10_00(f32, f32);
extern void ref_L00_003C2F10_01(void *, void *, s32, s32, s32, s32, s32, s32);
extern void ref_L00_003C2F10_02(void *, void *);

void func_L00_003C2F10(void *arg0) {
    s32 fill_value ;
    s32 call_a0 ;
    s32 call_a1 ;
    s32 call_a2 ;
    s32 call_a3 ;
    s32 call_t0 ;
    s32 call_t1 ;
    s32 call_t2 ;
    s32 call_t3 ;
    u8 state;
    u8 *data;
    f32 *angle;

    state = *(u8 *)((u8 *)arg0 + 0x20);
    data = *(u8 **)((u8 *)arg0 + 0x68);
    if (state == 0) {
        goto state_zero;
    }
    if (state == 1) {
        goto state_one;
    }
    goto done;

state_zero:
    if (*(s64 *)data == -1) {
        goto done;
    }
    fill_value = 0xFF;
    call_a0 = (s32)arg0;

    *(u8 *)((u8 *)arg0 + 0x30) = (u8)fill_value;
    call_a1 = (s32)(data + 0x30);
    call_a2 = 0x64;
    call_t1 = -1;
    call_a3 = *(s32 *)(data + 4);
    call_t2 = 7;
    call_t0 = *(s32 *)data;
    call_t3 = 0;
    ref_L00_003C2F10_01((void *)call_a0, (void *)call_a1, call_a2, call_a3,
                  call_t0, call_t1, call_t2, call_t3);
    *(s8 *)(data + 0xC5A) = 1;
    *(u8 *)((u8 *)arg0 + 0x20) = 1;
    goto done;

state_one:
    angle = (f32 *)((u8 *)arg0 + 0xF4);
    *angle = ref_L00_003C2F10_00(*angle, *(f32 *)(data + 8) * 0.00029088825f);
    ref_L00_003C2F10_02(arg0, data + 0x30);

done:
    return;
}
