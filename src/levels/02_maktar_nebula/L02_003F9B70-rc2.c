
/* SPDX-License-Identifier: MIT
 * MIT License
 * 
 * Copyright (c) 2026 Forja contributors
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

/* The resident table already holds the retail label addresses. The unused
 * label list keeps each C branch available; it is not read by the program. */
extern void *D_L02_002A5560[];

s32 func_L02_003F9B70(s32 a0) {
    {
    static void *volatile rc2_labels[] = {&&rc2_case_0, &&rc2_case_1, &&rc2_case_2, &&rc2_case_3, &&rc2_case_4, &&rc2_case_5, &&rc2_case_6, &&rc2_case_7, &&rc2_case_8, &&rc2_case_9, &&rc2_case_10, &&rc2_case_11, &&rc2_case_12, &&rc2_case_13};
    u32 rc2_selector = (u32)(a0);
    if (rc2_selector > 13U) goto rc2_default;
goto *D_L02_002A5560[rc2_selector];

    rc2_case_0:
        return 0x31;
    rc2_case_2:
        return 0x32;
    rc2_case_3:
        return 0x33;
    rc2_case_1:
        return 0x34;
    rc2_case_4:
        return 0x35;
    rc2_case_5:
        return 0x36;
    rc2_case_6:
        return 0x37;
    rc2_case_7:
        return 0x38;
    rc2_case_9:
        return 0x39;
    rc2_case_10:
        return 0x3A;
    rc2_case_11:
        return 0x3B;
    rc2_case_8:
        return 0x91;
    rc2_case_12:
        return 0x92;
    rc2_case_13:
        return 0x93;
    rc2_default:
        return -1;
    
rc2_switch_end: ;
}
}
