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

#ifndef __LLBC_CORE_LOG_LOG_RUNNABLE_H__
#define __LLBC_CORE_LOG_LOG_RUNNABLE_H__

#include "llbc/common/Common.h"

#include "llbc/core/thread/Task.h"

__LLBC_NS_BEGIN

/**
 * Pre-declare some classes.
 */
class LLBC_Logger;

__LLBC_NS_END

__LLBC_NS_BEGIN

/**
 * \brief Log Runnable class encapsulation.
 */
class LLBC_LogRunnable : public LLBC_BaseTask
{
public:
    /**
     * Constructor/Destructor.
     */
    LLBC_LogRunnable();
    virtual ~LLBC_LogRunnable();

public:
    /**
     * Add logger to runnable.
     * @param[in] logger - the logger.
     * @return int - return 0 if success, otherwise return -1.
     */
    int AddLogger(LLBC_Logger *logger);

    /**
     * Stop log runnable, it just send stop signal to task, must call Wait() to real stop runnable.
     */
    void Stop();

public:
    /**
     * Cleanup method, when task terminated, will call this method.
     */
    virtual void Cleanup();

    /**
     * Task service routine.
     */
    virtual void Svc();

private:
    /**
     * Try pop and process log data.
     * @param[in] maxPopWaitTime - the max pop wait time, in milli-second.
     * @return bool - return true if process success, otherwise return false.
     */
    bool TryPopAndProcLogData(int maxPopWaitTime);

    /**
     * Flush all loggers.
     * @param[in] force - force or not.
     * @param[in] now   - now time, in milli-seconds. if is set to 0, will call LLBC_GetMilliSeconds() to fetch now time.
     */
    void FlushLoggers(bool force, sint64 now);

private:
    volatile bool _stoped;
    std::vector<LLBC_Logger *> _loggers;
};

__LLBC_NS_END

#endif // !__LLBC_CORE_LOG_LOG_RUNNABLE_H__
