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

#ifndef __LLBC_CORE_EVENT_EVENT_FIRER_H__
#define __LLBC_CORE_EVENT_EVENT_FIRER_H__

#include "llbc/common/Common.h"

#include "llbc/core/objectpool/PoolObject.h"

__LLBC_NS_BEGIN
class LLBC_Variant;

class LLBC_Event;
class LLBC_EventManager;
__LLBC_NS_END

__LLBC_NS_BEGIN

/**
 * \brief The event firer class encapsulation.
 */
class LLBC_EXPORT LLBC_EventFirer : public LLBC_PoolObject
{
public:
    /**
     * Ctor&Dtor.
     */
    LLBC_EventFirer();
    ~LLBC_EventFirer();

public:
    /**
     * Set event param.
     * 
     * @param[in] paramKey - the event param key.
     * @param[in] param    - the event param.
     * @return LLBC_EventFirer &  - the event firer reference.
     */
    template <typename KeyType, typename ParamType>
    LLBC_EventFirer &SetParam(const KeyType &paramKey, const ParamType &param);

    /**
     * Fire firer holded event.
     */
    void Fire();

public:
    /**
     * Object-Pool reflection support: clear firer object.
     */
    void Clear();

    /**
     * Object-Pool reflection support: pool instance create event callback.
     */
    void OnPoolInstCreate(LLBC_IObjectPoolInst &poolInst);

private:
    /**
     * @brief Set event info to firer.
     * @param[in] ev    - the event object.
     * @param[in] evMgr - the event manager.
     */
    void SetEventInfo(LLBC_Event *ev, LLBC_EventManager *evMgr);

    LLBC_DISABLE_ASSIGNMENT(LLBC_EventFirer);

private:
    friend class LLBC_EventManager;

private:
    LLBC_Event *_ev;
    LLBC_EventManager *_evMgr;
};

__LLBC_NS_END

#include "llbc/core/event/EventFirerImpl.h"

#endif // !__LLBC_CORE_EVENT_EVENT_FIRER_H__
