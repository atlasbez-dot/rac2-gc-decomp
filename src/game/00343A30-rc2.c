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

extern s32 func_00288FB8();
extern s32 func_00335E20();
extern void func_00335F88(s32, f32, f32, f32, f32);
extern void func_003361E0(s32, s32, s32);
extern void func_00336390(s32, s32, s32);
extern void func_00336710(s32, s32, s32);
extern void func_003369A8(s32, s32, s32);
extern void func_00336A30(s32, s32);
extern void func_00336A38(s32, s32);
extern s32 func_00336DA8();
extern s32 func_00336E40();
extern void func_00344478(s32, s32);
extern s32 D_001A8CFC;
extern s8 D_001ADC10[];
extern s8 D_001ADC18[];
extern s8 D_001ADC20[];
extern s8 D_001ADC28[];
extern s8 D_001ADFC0[];
extern s8 D_001ADF20[];
extern s8 D_001ADD60[];
extern s8 D_001ADF18[];
extern s8 D_001ADF10[];
extern s8 D_001ADFC8[];
extern s8 D_001AE250[];
extern s8 D_001ADD58[];
extern s8 D_001AE030[];
extern s8 D_001ADFD8[];

void func_00343A30(s32 arg0, s32 arg1) {
    s32 sp0;
    s32 sp4;
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_v0;

    (*(s32 *)((s8 *)(arg0) + (0x434))) = arg1;
    if (arg1 != 0) {
        temp_v0 = func_00336DA8(0x10, func_00336E40(arg1));
        (*(s32 *)((s8 *)(arg0) + (0x430))) = temp_v0;
        (*(s32 *)((s8 *)(temp_v0) + (4))) = 0;
        (*(s32 *)((s8 *)(temp_v0) + (8))) = 0;
        (*(s32 *)((s8 *)(temp_v0) + (0xC))) = 0;
        (*(s32 *)((s8 *)(temp_v0) + (0))) = 0;
    }
    (*(s32 *)((s8 *)(arg0) + (0x438))) = 1;
    (*(f32 *)((s8 *)((*(s32 *)((s8 *)(arg0) + (0x430)))) + (0))) = 250.0f;
    sp0 = arg0 + 0x4C;
    temp_s3 = arg0 + 0x2E0;
    temp_s6 = arg0 + 0x1C8;
    sp4 = arg0 + 0x98;
    temp_s5 = arg0 + 0x210;
    sp8 = arg0 + 0xE4;
    (*(f32 *)((s8 *)((*(s32 *)((s8 *)(arg0) + (0x430)))) + (4))) = 207.0f;
    spC = arg0 + 0x130;
    func_003361E0(arg0, (s32)D_001ADC10, arg1);
    sp10 = arg0 + 0x17C;
    func_003361E0(sp0, (s32)D_001ADC18, arg1);
    temp_s4 = arg0 + 0x258;
    sp14 = arg0 + 0x328;
    func_003361E0(sp4, (s32)D_001ADC20, arg1);
    sp18 = arg0 + 0x370;
    func_003361E0(sp8, (s32)D_001ADC28, arg1);
    sp1C = arg0 + 0x3B8;
    func_003361E0(spC, (s32)D_001ADFC0, arg1);
    sp20 = arg0 + 0x298;
    func_003361E0(sp10, (s32)D_001ADFC8, arg1);
    func_003369A8(sp14, (s32)D_001ADF10, arg1);
    func_003369A8(sp18, (s32)D_001ADF18, arg1);
    func_003369A8(sp1C, (s32)D_001ADF20, arg1);
    func_003369A8(sp20, (s32)D_001ADD60, arg1);
    func_003369A8(temp_s3, (s32)D_001AE250, arg1);
    func_003369A8(temp_s6, (s32)D_001ADD58, arg1);
    func_003369A8(temp_s5, (s32)D_001AE030, arg1);
    *(s32 *)func_00335E20(arg0) = 0x60442D00;
    *(s32 *)func_00335E20(sp0) = 0x60241700;
    *(s32 *)func_00335E20(sp4) = 0x55F0C070;
    *(s32 *)func_00335E20(sp8) = 0x55F0C070;
    *(s32 *)func_00335E20(sp10) = 0x70FFFEED;
    *(s32 *)func_00335E20(spC) = 0x55F0C070;
    *(s32 *)func_00335E20(sp20) = 0x80F0F0F0;
    *(s32 *)func_00335E20(temp_s3) = 0x80F0F0F0;
    *(s32 *)func_00335E20(temp_s6) = 0x80F0F0F0;
    *(s32 *)func_00335E20(temp_s5) = 0x80F0F0F0;
    *(s32 *)func_00335E20(sp14) = 0x80F0F0F0;
    *(s32 *)func_00335E20(sp18) = 0x80F0F0F0;
    *(s32 *)func_00335E20(sp1C) = 0x80F0F0F0;
    func_00336A30(sp20, 1);
    func_00336A30(temp_s3, 1);
    func_00335F88(temp_s3, 0.9f, 0.9f, 0.0f, 0.0f);
    func_00336390(arg0, D_001A8CFC + 0x8710, 0x9E);
    func_00336390(sp0, D_001A8CFC + 0x8710, 0x9F);
    func_00336390(sp4, D_001A8CFC + 0x8710, 0xA0);
    func_00336390(sp8, D_001A8CFC + 0x8710, 0xA1);
    func_00336390(spC, D_001A8CFC + 0x8710, 0x5D);
    func_00336390(sp10, D_001A8CFC + 0x8710, 0x5E);
    (*(s32 *)((s8 *)(arg0) + (0x43C))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x440))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x448))) = 3;
    func_00336710(temp_s4, (s32)D_001ADFD8, arg1);
    *(s32 *)func_00335E20(temp_s4) = 0x60F0F0B0;
    func_00335F88(temp_s4, 32.0f, 32.0f, 0.0f, 0.0f);
    *(s32 *)func_00335E20(temp_s6) = 0x80F0F0F0;
    *(s32 *)func_00335E20(temp_s5) = 0x80F0F0F0;
    func_00336A38(temp_s6, func_00288FB8(0x2D54));
    func_00336A38(temp_s5, func_00288FB8(0x2D59));
    func_00336A38(sp14, arg0 + 0x400);
    func_00336A38(sp18, arg0 + 0x410);
    func_00336A38(sp1C, arg0 + 0x420);
    func_00336A30(sp14, 0);
    func_00336A30(sp18, 0);
    func_00336A30(sp1C, 0);
    (*(s32 *)((s8 *)(arg0) + (0x444))) = 0;
    func_00336A38(sp20, func_00288FB8(0x2D4F));
    func_00344478(arg0, 0);
}
