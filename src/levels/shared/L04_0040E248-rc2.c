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

s32 ref_L04_0040E248_00(s32, s32);
extern u8 D_00188660[];

void func_L04_0040E248(s32 arg0, void *arg1) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_a1_5;
    s32 temp_a1_6;
    s32 temp_a1_7;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;
    void *temp_v1_7;

    temp_a1 = (*(s32 *)((s8 *)(arg1) + (0x748)));
    if (temp_a1 != -1) {
        temp_v1 = D_00188660 + (temp_a1 * 0x70);
        if (((*(s32 *)((s8 *)(temp_v1) + (0x88))) == arg0) && ((*(u8 *)((s8 *)(temp_v1) + (0x74))) != 0)) {
            ref_L04_0040E248_00(temp_a1, temp_a1);
        }
    }
    temp_a1_2 = (*(s32 *)((s8 *)(arg1) + (0x74C)));
    (*(s32 *)((s8 *)(arg1) + (0x748))) = -1;
    if (temp_a1_2 != -1) {
        temp_v1_2 = D_00188660 + (temp_a1_2 * 0x70);
        if (((*(s32 *)((s8 *)(temp_v1_2) + (0x88))) == arg0) && ((*(u8 *)((s8 *)(temp_v1_2) + (0x74))) != 0)) {
            ref_L04_0040E248_00(temp_a1_2, temp_a1_2);
        }
    }
    temp_a1_3 = (*(s32 *)((s8 *)(arg1) + (0x714)));
    (*(s32 *)((s8 *)(arg1) + (0x74C))) = -1;
    if (temp_a1_3 != -1) {
        temp_v1_3 = D_00188660 + (temp_a1_3 * 0x70);
        if (((*(s32 *)((s8 *)(temp_v1_3) + (0x88))) == arg0) && ((*(u8 *)((s8 *)(temp_v1_3) + (0x74))) != 0)) {
            ref_L04_0040E248_00(temp_a1_3, temp_a1_3);
        }
    }
    temp_a1_4 = (*(s32 *)((s8 *)(arg1) + (0x3BC)));
    (*(s32 *)((s8 *)(arg1) + (0x714))) = -1;
    if (temp_a1_4 != -1) {
        temp_v1_4 = D_00188660 + (temp_a1_4 * 0x70);
        if (((*(s32 *)((s8 *)(temp_v1_4) + (0x88))) == arg0) && ((*(u8 *)((s8 *)(temp_v1_4) + (0x74))) != 0)) {
            ref_L04_0040E248_00(temp_a1_4, temp_a1_4);
        }
    }
    temp_a1_5 = (*(s32 *)((s8 *)(arg1) + (0x328)));
    (*(s32 *)((s8 *)(arg1) + (0x3BC))) = -1;
    if (temp_a1_5 != -1) {
        temp_v1_5 = D_00188660 + (temp_a1_5 * 0x70);
        if (((*(s32 *)((s8 *)(temp_v1_5) + (0x88))) == arg0) && ((*(u8 *)((s8 *)(temp_v1_5) + (0x74))) != 0)) {
            ref_L04_0040E248_00(temp_a1_5, temp_a1_5);
        }
    }
    temp_a1_6 = (*(s32 *)((s8 *)(arg1) + (0x330)));
    (*(s32 *)((s8 *)(arg1) + (0x328))) = -1;
    if (temp_a1_6 != -1) {
        temp_v1_6 = D_00188660 + (temp_a1_6 * 0x70);
        if (((*(s32 *)((s8 *)(temp_v1_6) + (0x88))) == arg0) && ((*(u8 *)((s8 *)(temp_v1_6) + (0x74))) != 0)) {
            ref_L04_0040E248_00(temp_a1_6, temp_a1_6);
        }
    }
    temp_a1_7 = (*(s32 *)((s8 *)(arg1) + (0x334)));
    (*(s32 *)((s8 *)(arg1) + (0x330))) = -1;
    if (temp_a1_7 != -1) {
        temp_v1_7 = D_00188660 + (temp_a1_7 * 0x70);
        if (((*(s32 *)((s8 *)(temp_v1_7) + (0x88))) == arg0) && ((*(u8 *)((s8 *)(temp_v1_7) + (0x74))) != 0)) {
            ref_L04_0040E248_00(temp_a1_7, temp_a1_7);
        }
    }
    (*(s32 *)((s8 *)(arg1) + (0x324))) = 0;
    (*(s32 *)((s8 *)(arg1) + (0x334))) = -1;
    (*(s32 *)((s8 *)(arg1) + (0x32C))) = 0;
}
