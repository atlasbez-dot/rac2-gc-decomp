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

extern s32 *func_00335E20(void *);
extern void *func_00288FB8(s32);
extern void func_00335F88(void *, f32, f32, f32, f32);
extern void func_003361E0(void *, void *, s32);
extern void func_00336390(void *, s32, s32);
extern void func_00336710(void *, void *, s32);
extern void func_003369A8(void *, void *, s32);
extern void func_00336A38(void *, void *);
extern void *func_00336DA8(s32, s32);
extern s32 func_00336E40(s32);
extern void func_003428E0(void *, s32);
extern void func_00343028(void *, f32, f32);
extern void func_00343038(void *, f32);
extern void func_003435B0(void *, s32);
extern void func_00343798(void *, s32);
extern s32 D_001A8CFC;
extern s8 D_001ADC10[];
extern s8 D_001ADC18[];
extern s8 D_001ADC20[];
extern s8 D_001ADC30[];
extern s8 D_001ADC88[];
extern s8 D_001AE0C0[];

void func_00343260(s8 *arg0, s32 arg1) {
    s8 *temp_v0;
    s8 *sp0;
    s8 *s2p;
    s8 *s3p;
    s8 *s4p;
    s8 *s5p;
    s8 *s6p;
    s8 *s0p;
    s8 *tb;

    (*(s32 *)((s8 *)(arg0) + (0x28C))) = arg1;
    if (arg1 != 0) {
        temp_v0 = func_00336DA8(0x10, func_00336E40(arg1));
        (*(s32 *)((s8 *)(arg0) + (0x288))) = (s32)temp_v0;
        (*(s32 *)((s8 *)(temp_v0) + (4))) = 0;
        (*(s32 *)((s8 *)(temp_v0) + (8))) = 0;
        (*(s32 *)((s8 *)(temp_v0) + (0xC))) = 0;
        (*(s32 *)((s8 *)(temp_v0) + (0))) = 0;
    }
    (*(s32 *)((s8 *)(arg0) + (0x290))) = 1;
    (*(f32 *)((s8 *)((*(s32 *)((s8 *)(arg0) + (0x288)))) + (0))) = 251.0f;
    s3p = arg0 + 0x4C;
    s4p = arg0 + 0x98;
    s5p = arg0 + 0x1B0;
    (*(f32 *)((s8 *)((*(s32 *)((s8 *)(arg0) + (0x288)))) + (4))) = 210.0f;
    s6p = arg0 + 0x1F8;
    func_003361E0(arg0, D_001ADC10, arg1);
    s2p = arg0 + 0x240;
    func_003361E0(s3p, D_001ADC18, arg1);
    sp0 = arg0 + 0xE4;
    func_003361E0(s4p, D_001ADC20, arg1);
    func_003369A8(s5p, D_001ADC30, arg1);
    tb = D_001ADC88;
    func_003369A8(s6p, tb, arg1);
    func_003369A8(s2p, tb, arg1);
    s0p = arg0 + 0x298;
    func_00336710(sp0, D_001AE0C0, arg1);
    *func_00335E20(arg0) = 0x60442D00;
    *func_00335E20(s3p) = 0x60241700;
    *func_00335E20(s4p) = 0x55F0C070;
    *func_00335E20(s5p) = 0x80F0F0F0;
    *func_00335E20(s2p) = 0x80F0F0F0;
    *func_00335E20(s6p) = 0x80F0F0F0;
    *func_00335E20(sp0) = 0x80F0F0F0;
    func_00336390(arg0, D_001A8CFC + 0x8710, 0x99);
    func_00336390(s3p, D_001A8CFC + 0x8710, 0x9A);
    func_00336390(s4p, D_001A8CFC + 0x8710, 0x9B);
    func_00336A38(s5p, arg0 + 0x120);
    func_00336A38(s6p, arg0 + 0x160);
    func_00336A38(s2p, func_00288FB8(0x2D4F));
    func_003435B0(arg0, 0);
    func_00335F88(sp0, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003428E0(s0p, arg1);
    func_00343028(s0p, 0.0f, 40.0f);
    func_00343038(s0p, 32.0f);
    (*(s32 *)((s8 *)(arg0) + (0x330))) = 0;
    func_00343798(arg0, 0);
}
