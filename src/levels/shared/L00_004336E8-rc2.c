
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

extern void ref_L00_004336E8_00(void *, float);
extern int ref_L00_004336E8_01(void *);
extern int *ref_L00_004336E8_02(int, int);
extern void ref_L00_004336E8_03(void *, void *, void *);
extern int ref_L00_004336E8_04(int);
extern void ref_L00_004336E8_05(void *, int, int, int);
extern void ref_L00_004336E8_06(void *, float, float, float, float, float, float);
extern void ref_L00_004336E8_07(void *, int);
extern int ref_L00_004336E8_08[2] __attribute__((sda));
void func_L00_004336E8(char *object, void *argument)
{
    int *allocation;
    char *child;
    int text, second;
    *(void **)object = argument;
    if (argument) {
        allocation = ref_L00_004336E8_02(16, ref_L00_004336E8_01(argument));
        *(int **)(object + 0x2AC) = allocation;
        allocation[1] = 0;
        allocation[2] = 0;
        allocation[3] = 0;
        allocation[0] = 0;
    }
    **(float **)(object + 0x2AC) = 255.0f;
    (*(float **)(object + 0x2AC))[1] = 195.0f;
    child = object + 8;
    ref_L00_004336E8_03(child, argument, ref_L00_004336E8_08);
    text = ref_L00_004336E8_04(0x2D61);
    second = ref_L00_004336E8_04(0x2D4E);
    ref_L00_004336E8_05(child, text, second, ref_L00_004336E8_04(0x2D4F));
    ref_L00_004336E8_06(child, 0.0f, -143.0f, 0.0f, 114.0f, 0.0f, 140.0f);
    ref_L00_004336E8_00(child, 0.4f);
    *(int *)(object + 0x2A8) = 0;
    ref_L00_004336E8_07(object, 0);
}
