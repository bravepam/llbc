// The MIT License (MIT)

// Copyright (c) 2013 lailongwei<lailongwei@126.com>
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of 
// this software and associated documentation files (the "Software"), to deal in 
// the Software without restriction, including without limitation the rights to 
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of 
// the Software, and to permit persons to whom the Software is furnished to do so, 
// subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all 
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS 
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER 
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef __LLBC_TEST_CASE_CORE_EVENT_H__
#define __LLBC_TEST_CASE_CORE_EVENT_H__

#include "llbc.h"
using namespace llbc;

class TestCase_Core_Event : public LLBC_BaseTestCase
{
public:
    TestCase_Core_Event();
    virtual ~TestCase_Core_Event();

public:
    virtual int Run(int argc, char *argv[]);

private:
    void OnEvent1(LLBC_Event &ev);
    void OnEvent1Too(LLBC_Event &ev);

    void OnEvent2(LLBC_Event &ev);

private:
    void DumpEvParams(const LLBC_Event &ev);

private:
    LLBC_ListenerStub _ev1Stub;
    LLBC_ListenerStub _ev1TooStub;
};

#endif // !__LLBC_TEST_CASE_CORE_EVENT_H__
