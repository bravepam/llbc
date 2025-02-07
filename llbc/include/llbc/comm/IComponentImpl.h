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

#ifdef __LLBC_COMM_ICOMPONENT_H__

__LLBC_NS_BEGIN

inline LLBC_ComponentMethods::LLBC_ComponentMethods()
{
}

inline LLBC_ComponentMethods::~LLBC_ComponentMethods()
{
}

inline const LLBC_ComponentMethods::Methods &LLBC_ComponentMethods::GetAllMethods() const
{
    return _meths;
}

inline const LLBC_ComponentMethod &LLBC_ComponentMethods::GetMethod(const char *methName) const
{
    static const LLBC_ComponentMethod nullMeth;
    Methods::const_iterator it = _meths.find(methName);
    if (UNLIKELY(it == _meths.end()))
    {
        LLBC_SetLastError(LLBC_ERROR_NOT_FOUND);
        return nullMeth;
    }

    return it->second;
}

template <typename ComponentCls>
int LLBC_ComponentMethods::AddMethod(ComponentCls *component, const char *methName, int (ComponentCls::*meth)(const LLBC_Variant &arg, LLBC_Variant &ret))
{
    if (UNLIKELY(!methName || LLBC_StrLenA(methName) == 0 || !meth))
    {
        LLBC_SetLastError(LLBC_ERROR_ARG);
        return LLBC_FAILED;
    }

    if (UNLIKELY(!_meths.emplace(methName, LLBC_ComponentMethod(component, meth)).second))
    {
        LLBC_SetLastError(LLBC_ERROR_REPEAT);
        return LLBC_FAILED;
    }

    return LLBC_OK;
}

inline int LLBC_ComponentMethods::CallMethod(const char *methName, const LLBC_Variant &arg, LLBC_Variant &ret)
{
    const LLBC_ComponentMethod &meth = GetMethod(methName);
    if (UNLIKELY(!meth))
        return LLBC_FAILED;

    return meth(arg, ret);
}

inline LLBC_IService *LLBC_IComponent::GetService() const
{
    return _svc;
}

inline uint64 LLBC_IComponent::GetCaredEvents() const
{
    return _caredEvents;
}

inline bool LLBC_IComponent::IsCaredEvents(uint64 compEvs) const
{
    return (_caredEvents & compEvs) == compEvs;
}

inline bool LLBC_IComponent::IsCaredEventOffset(int compEvOffset) const
{
 #if defined(_MSC_VER) || defined(_MSC_EXTENSIONS) || defined(__WATCOMC__)
    return IsCaredEvents(1Ui64 << compEvOffset);
#else
    return IsCaredEvents(1ULL << compEvOffset);
#endif
}

inline const LLBC_ComponentMethods *LLBC_IComponent::GetAllMethods() const
{
    return _meths;
}

template <typename ComponentCls>
int LLBC_IComponent::AddMethod(const char *methName, int (ComponentCls::*meth)(const LLBC_Variant &arg, LLBC_Variant &ret))
{
    if (!_meths)
        _meths = LLBC_New(LLBC_ComponentMethods);

    return _meths->AddMethod<ComponentCls>(dynamic_cast<ComponentCls *>(this), methName, meth);
}

inline int LLBC_IComponent::CallMethod(const char *methName, const LLBC_Variant &arg, LLBC_Variant &ret)
{
    if (UNLIKELY(!_meths))
    {
        LLBC_SetLastError(LLBC_ERROR_NOT_FOUND);
        return LLBC_FAILED;
    }

    return _meths->CallMethod(methName, arg, ret);
}

inline void LLBC_IComponent::OnUpdate()
{
}

inline void LLBC_IComponent::OnIdle(int idleTime)
{
}

__LLBC_NS_END

#endif // __LLBC_COMM_ICOMPONENT_H__
