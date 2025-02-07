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

#ifdef __LLBC_COMM_SERVICE_H__

__LLBC_NS_BEGIN

inline int LLBC_Service::Multicast(int svcId, const LLBC_SessionIdSet &sessionIds, int opcode, LLBC_ICoder *coder, int status)
{
    // Call internal MulticastSendCoder<> template method to complete.
    // validCheck = true
    return MulticastSendCoder<LLBC_SessionIdSet>(svcId, sessionIds, opcode, coder, status);
}

inline int LLBC_Service::Multicast(int svcId, const LLBC_SessionIdList &sessionIds, int opcode, LLBC_ICoder *coder, int status)
{
    // Call internal MulticastSendCoder<> template method to complete.
    // validCheck = true
    return MulticastSendCoder<LLBC_SessionIdList>(svcId, sessionIds, opcode, coder, status);
}

inline int LLBC_Service::Multicast(int svcId, const LLBC_SessionIdSet &sessionIds, int opcode, const void *bytes, size_t len, int status)
{
    LLBC_LockGuard guard(_lock);
    if (UNLIKELY(!_started))
    {
        LLBC_SetLastError(LLBC_ERROR_NOT_INIT);
        return LLBC_FAILED;
    }

    // Foreach to call internal method LockableSend() method to complete.
    // lock = false
    // validCheck = true
    for (LLBC_SessionIdSetCIter sessionIt = sessionIds.begin();
         sessionIt != sessionIds.end();
         ++sessionIt)
        LockableSend(svcId, *sessionIt, opcode, bytes, len, status, false);

    return LLBC_OK;
}

inline int LLBC_Service::Multicast(int svcId, const LLBC_SessionIdList &sessionIds, int opcode, const void *bytes, size_t len, int status)
{
    LLBC_LockGuard guard(_lock);
    if (UNLIKELY(!_started))
    {
        LLBC_SetLastError(LLBC_ERROR_NOT_INIT);
        return LLBC_FAILED;
    }

    // Foreach to call internal method LockableSend() method to complete.
    // lock = false
    // validCheck = true
    for (LLBC_SessionIdListCIter sessionIt = sessionIds.begin();
         sessionIt != sessionIds.end();
         ++sessionIt)
        LockableSend(svcId, *sessionIt, opcode, bytes, len, status, false);

    return LLBC_OK;
}

inline LLBC_EventManager &LLBC_Service::GetEventManager()
{
    return _evManager;
}

inline LLBC_SafetyObjectPool &LLBC_Service::GetSafetyObjectPool()
{
    return _safetyObjectPool;
}

inline LLBC_UnsafetyObjectPool &LLBC_Service::GetUnsafetyObjectPool()
{
    return _unsafetyObjectPool;
}

inline LLBC_ObjectPoolInst<LLBC_Packet> & LLBC_Service::GetPacketObjectPool()
{
    return _packetObjectPool;
}

inline LLBC_ObjectPoolInst<LLBC_MessageBlock> &LLBC_Service::GetMsgBlockObjectPool()
{
    return _msgBlockObjectPool;
}

__LLBC_NS_END

#endif // __LLBC_COMM_SERVICE_H__
