/* SPDX-License-Identifier: GPL-3.0-only
 * OpenRAC nonmatching d43c3b99b984fb63556c844a21ee99e8e31d2deb; nonmatching/game/func_002A04B8.c
 */
/* MIT notice for Forja tooling and adaptations:
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

/* The reader of the three bytes ref_openrac_func_002A0488 packs into word 7 of the command block:
   byte 4 of the word at +0x38 goes to *a, byte 5 to *b, byte 6 to *c.  Retail loads the
   64-bit word into $a0 (the parameter register it has just read), shifts it three times
   and masks the three results before it stores them; this cc1 keeps the word in $v0,
   reuses $a0 for the second result and interleaves the shifts with the stores. */
struct A04B8 { unsigned char pad[0x38]; volatile unsigned long long word; };
void func_002A04B8(struct A04B8 *p, volatile int *a, volatile int *b, volatile int *c)
{
    register unsigned long long value __asm__("$4") = p->word;
    register unsigned long long first __asm__("$1") = value >> 32;
    register unsigned long long second __asm__("$2") = value >> 40;
    register unsigned long long third __asm__("$3") = value >> 48;
    register unsigned int firstByte __asm__("$1");
    register unsigned int secondByte __asm__("$2");
    register unsigned int thirdByte __asm__("$3");

    firstByte = (unsigned char)first;
    secondByte = (unsigned char)second;
    thirdByte = (unsigned char)third;
    __asm__ volatile ("" : "+r"(value), "+r"(firstByte), "+r"(secondByte), "+r"(thirdByte) : : "memory");
    *a = (int)firstByte;
    *b = (int)secondByte;
    *c = (int)thirdByte;
}
