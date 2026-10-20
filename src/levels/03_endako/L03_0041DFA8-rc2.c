
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

extern void ref_L03_0041DFA8_00(void *);
extern void ref_L03_0041DFA8_01(void *);
extern s32 ref_L03_0041DFA8_02(f32);
extern void ref_L03_0041DFA8_03(void *, s32, void *);
extern s32 ref_L03_0041DFA8_04(s32);
extern void ref_L03_0041DFA8_05(void *, void *, s32, f32, f32);
extern void ref_L03_0041DFA8_06(void *, void *, void *, s32);
extern void ref_L03_0041DFA8_07(void *, void *, s32, s32, f32);
extern void *ref_L03_0041DFA8_08(void *, f32, f32, f32, s32, s32 *, f32, u32, s32);
extern f32 ref_L03_0041DFA8_09 __attribute__((sda));

typedef struct {
    u8 pad00[4];
    f32 value04;
    u8 pad08[8];
    s32 value10;
    s32 value14;
    f32 value18;
    f32 value1C;
    u8 params20[8];
    f32 value28;
} LocalFrame;

void func_L03_0041DFA8(void *arg0) {
    void *temp_s4 = *(void **)((u8 *)arg0 + 0x68);
    LocalFrame frame;
    u16 temp_v1;
    s32 temp_s3;
    void *first;
    void *second;
    u8 *first_tail;
    u8 *second_tail;

    ref_L03_0041DFA8_00((u8 *)temp_s4 + 0x34C);
    ref_L03_0041DFA8_01((u8 *)temp_s4 + 0x330);
    ref_L03_0041DFA8_01((u8 *)temp_s4 + 0x332);
    ref_L03_0041DFA8_05(arg0, (u8 *)temp_s4 + 0x220, 0, 0.03f, 0.3f);
    ref_L03_0041DFA8_05(arg0, (u8 *)temp_s4 + 0x2A0, 1, 0.03f, 0.3f);

    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = temp_v1 + 1;
    }

    ref_L03_0041DFA8_06(arg0, &frame, (u8 *)temp_s4 + 0x1A0, 0);
    *(f32 *)((u8 *)arg0 + 0xF0) = frame.value04 * ref_L03_0041DFA8_09;
    frame.value10 = 0;

    frame.value18 = -0.02f;
    frame.value1C = 1.0f;

    frame.value14 = 0;
    temp_s3 = ref_L03_0041DFA8_04(0x10);
    temp_s3 = (ref_L03_0041DFA8_04(2) != 0) ? -temp_s3 : temp_s3;
    ref_L03_0041DFA8_03(arg0, 4, frame.params20);
    frame.value28 += 0.1f;

    first = ref_L03_0041DFA8_08(frame.params20, 0.1f, 1.0f, 0.9f,
                          temp_s3, &frame.value10, 105000.0f, 0xDF204080U, 0);
    if (first != 0) {
        *(s16 *)((u8 *)first + 0xA) = 5;
        first_tail = (u8 *)first + 0x20;
        *(s8 *)((u8 *)first + 9) = (s8)(ref_L03_0041DFA8_02(4.0f) + 0x70);
        *(s32 *)(first_tail + 4) = 2;
        *(u8 *)(first_tail + 0xA) = (u8)0xDF;
        *(u8 *)(first_tail + 0xB) = *(u8 *)((u8 *)first + 0xA);
    }

    second = ref_L03_0041DFA8_08(frame.params20, 0.1f, 1.0f, 0.9f,
                           temp_s3, &frame.value10, 105000.0f, 0xDF204080U, 0);
    if (second != 0) {
        *(s16 *)((u8 *)first + 0xA) = 5;
        second_tail = (u8 *)second + 0x20;
        *(s8 *)((u8 *)first + 9) = (s8)(ref_L03_0041DFA8_02(4.0f) + 0x70);
        *(s32 *)(second_tail + 4) = 2;
        *(u8 *)(second_tail + 0xA) = (u8)0xDF;
        *(u8 *)(second_tail + 0xB) = *(u8 *)((u8 *)first + 0xA);
    }

    if (*(u8 *)((u8 *)arg0 + 0x31) != 0) {
        ref_L03_0041DFA8_07(arg0, (u8 *)temp_s4 + 0x360, 5, 1, 2.5f);
    }
}
