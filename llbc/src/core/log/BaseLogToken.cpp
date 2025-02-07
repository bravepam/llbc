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

#include "llbc/common/Export.h"
#include "llbc/common/BeforeIncl.h"

#include "llbc/core/log/LogFormattingInfo.h"
#include "llbc/core/log/BaseLogToken.h"

__LLBC_NS_BEGIN

LLBC_BaseLogToken::LLBC_BaseLogToken()
: _formatter(nullptr)
, _nextToken(nullptr)
{
}

LLBC_BaseLogToken::~LLBC_BaseLogToken()
{
    LLBC_XDelete(_formatter);
}

LLBC_LogFormattingInfo *LLBC_BaseLogToken::GetFormatter() const
{
    return _formatter;
}

void LLBC_BaseLogToken::SetFormatter(LLBC_LogFormattingInfo *formatter)
{
    LLBC_XDelete(_formatter);
    _formatter = formatter;
}

LLBC_ILogToken *LLBC_BaseLogToken::GetTokenNext() const
{
    return _nextToken;
}

void LLBC_BaseLogToken::SetTokenNext(LLBC_ILogToken *next)
{
    _nextToken = next;
}

__LLBC_NS_END

#include "llbc/common/AfterIncl.h"
