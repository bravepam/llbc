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

#ifdef __LLBC_CORE_LOG_LOGGER_H__

__LLBC_NS_BEGIN

LLBC_FORCE_INLINE int LLBC_Logger::GetLogLevel() const
{
    return _logLevel;
}

inline int LLBC_Logger::Debug(const char *tag, const char *file, int line, const char *func, const char *fmt, ...)
{
    if (LLBC_LogLevel::Debug < _logLevel)
        return LLBC_OK;

    va_list va;
    va_start(va, fmt);
    int ret = VOutput(LLBC_LogLevel::Debug, tag, file, line, func, fmt, va);
    va_end(va);

    return ret;
}

inline int LLBC_Logger::Info(const char *tag, const char *file, int line, const char *func, const char *fmt, ...)
{
    if (LLBC_LogLevel::Info < _logLevel)
        return LLBC_OK;

    va_list va;
    va_start(va, fmt);
    int ret = VOutput(LLBC_LogLevel::Info, tag, file, line, func, fmt, va);
    va_end(va);

    return ret;
}

inline int LLBC_Logger::Warn(const char *tag, const char *file, int line, const char *func, const char *fmt, ...)
{
    if (LLBC_LogLevel::Warn < _logLevel)
        return LLBC_OK;

    va_list va;
    va_start(va, fmt);
    int ret = VOutput(LLBC_LogLevel::Warn, tag, file, line, func, fmt, va);
    va_end(va);

    return ret;
}

inline int LLBC_Logger::Error(const char *tag, const char *file, int line, const char *func, const char *fmt, ...)
{
    if (LLBC_LogLevel::Error < _logLevel)
        return LLBC_OK;

    va_list va;
    va_start(va, fmt);
    int ret = VOutput(LLBC_LogLevel::Error, tag, file, line, func, fmt, va);
    va_end(va);

    return ret;
}

inline int LLBC_Logger::Fatal(const char *tag, const char *file, int line, const char *func, const char *fmt, ...)
{
    if (LLBC_LogLevel::Fatal < _logLevel)
        return LLBC_OK;

    va_list va;
    va_start(va, fmt);
    const int ret = VOutput(LLBC_LogLevel::Fatal, tag, file, line, func, fmt, va);
    va_end(va);

    return ret;
}

inline int LLBC_Logger::Output(int level, const char *tag, const char *file, int line, const char *func, const char *fmt, ...) 
{
    if (level < _logLevel)
        return LLBC_OK;

    va_list va;
    va_start(va, fmt);
    const int ret = VOutput(level, tag, file, line, func, fmt, va);
    va_end(va);

    return ret;
}

__LLBC_NS_END

#endif // __LLBC_CORE_LOG_LOGGER_H__

