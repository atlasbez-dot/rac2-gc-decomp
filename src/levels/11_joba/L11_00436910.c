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

extern void ref_L11_00436910_00(void *, s32, s32, s32);
extern void ref_L11_00436910_01(void *, s32, s32);
extern void ref_L11_00436910_02(void *, f32, f32, f32, f32);
extern void ref_L11_00436910_03(void *);
extern void ref_L11_00436910_04(void *, u8, u8, u8);
extern void ref_L11_00436910_05(void *, s32, f32, f32);

void func_L11_00436910(void *arg0, s32 arg1, s32 arg2) {
    void *s1;
    s32 w;
    void *t1 ;

    s1 = (*(void **)((s8 *)(arg0) + (0x68)));
    (*(s16 *)((s8 *)(s1) + (0x282))) = 0;
    (*(s16 *)((s8 *)(s1) + (0x88))) = 0;
    (*(f32 *)((s8 *)(s1) + (0x20))) = (f32) (*(s16 *)((s8 *)(s1) + (0x24)));
    (*(s16 *)((s8 *)(s1) + (0x286))) = arg2;
    ref_L11_00436910_02(arg0, 0.00444444455206394195556640625f, 0.13333334028720855712890625f, 0.006981317885220050811767578125f, 0.2094395458698272705078125f);
    t1 = (*(void **)((s8 *)(arg0) + (0x24)));
    w = (*(s32 *)((s8 *)(t1) + (0x10)));
    (*(u16 *)((s8 *)(arg0) + (0x34))) = (u16) (((*(u16 *)((s8 *)(arg0) + (0x34))) | 0x1000) & 0xFFB9);
    (*(s32 *)((s8 *)(arg0) + (0x98))) = w;
    (*(s8 *)((s8 *)(arg0) + (0x7F))) = 0;
    if ((*(s16 *)((s8 *)(s1) + (0x286))) != 0) {
        ref_L11_00436910_01(arg0, 7, 3);
        (*(u16 *)((s8 *)(arg0) + (0x34))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x34))) | 0x100);
        ref_L11_00436910_00(arg0, 1, 0, 0);
        ref_L11_00436910_03(arg0);
        ref_L11_00436910_05(arg0, 0, 2.0f, 2.0f);
    } else {
        ref_L11_00436910_01(arg0, 3, 0);
        (*(s8 *)((s8 *)(arg0) + (0x31))) = 1;
        (*(u16 *)((s8 *)(arg0) + (0x34))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x34))) & 0xFEFE);
    }
    (*(s8 *)((s8 *)(s1) + (0x2E))) = 1;
    (*(s16 *)((s8 *)(s1) + (0x284))) = arg1;
    (*(s8 *)((s8 *)(s1) + (0x6A))) = 0;
    if ((*(s16 *)((s8 *)(s1) + (0x50))) != 0) {
        (*(s16 *)((s8 *)(s1) + (0x50))) = 0;
        ref_L11_00436910_04(arg0, (*(u8 *)((s8 *)(s1) + (0x54))), (*(u8 *)((s8 *)(s1) + (0x55))), (*(u8 *)((s8 *)(s1) + (0x56))));
        (*(s16 *)((s8 *)(s1) + (0x52))) = 1;
    }
}
