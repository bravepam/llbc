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

#include "llbc/comm/Packet.h"
#include "llbc/comm/Session.h"
#include "llbc/comm/protocol/ProtocolLayer.h"
#include "llbc/comm/protocol/ProtoReportLevel.h"
#include "llbc/comm/ServiceEvent.h"

namespace
{
    typedef LLBC_NS LLBC_ServiceEvent Base;
    typedef LLBC_NS LLBC_MessageBlock _Block;
    typedef LLBC_NS LLBC_SvcEvType _EvType;

    template <typename Ev>
    static _Block *__CreateEvBlock(Ev *ev)
    {
        _Block *block = LLBC_New(_Block, sizeof(int) + sizeof(Ev *));
        block->Write(&ev->type, sizeof(int));
        block->Write(&ev, sizeof(Ev *));

        return block;
    }
}

__LLBC_NS_BEGIN

LLBC_ServiceEvent::LLBC_ServiceEvent(int type)
: type(type)
{
}

LLBC_ServiceEvent::~LLBC_ServiceEvent()
{
}

LLBC_SvcEv_SessionCreate::LLBC_SvcEv_SessionCreate()
: Base(_EvType::SessionCreate)
{
}

LLBC_SvcEv_SessionCreate::~LLBC_SvcEv_SessionCreate()
{
}

LLBC_SvcEv_SessionDestroy::LLBC_SvcEv_SessionDestroy()
: Base(_EvType::SessionDestroy)
{
}

LLBC_SvcEv_SessionDestroy::~LLBC_SvcEv_SessionDestroy()
{
    LLBC_XDelete(closeInfo);
}

LLBC_SvcEv_AsyncConn::LLBC_SvcEv_AsyncConn()
: Base(_EvType::AsyncConnResult)
{
}

LLBC_SvcEv_AsyncConn::~LLBC_SvcEv_AsyncConn()
{
}

LLBC_SvcEv_DataArrival::LLBC_SvcEv_DataArrival()
: Base(_EvType::DataArrival)
, packet(nullptr)
{
}

LLBC_SvcEv_DataArrival::~LLBC_SvcEv_DataArrival()
{
    LLBC_XRecycle(packet);
}

LLBC_SvcEv_ProtoReport::LLBC_SvcEv_ProtoReport()
: Base(_EvType::ProtoReport)
, sessionId(0)
, opcode(0)

, layer(LLBC_ProtocolLayer::End)
, level(LLBC_ProtoReportLevel::Error)
, report()
{
}

LLBC_SvcEv_ProtoReport::~LLBC_SvcEv_ProtoReport()
{
}

LLBC_SvcEv_SubscribeEv::LLBC_SvcEv_SubscribeEv()
: Base(_EvType::SubscribeEv)
, id(0)
, stub(LLBC_INVALID_LISTENER_STUB)
, deleg(nullptr)
, listener(nullptr)
{
}

LLBC_SvcEv_SubscribeEv::~LLBC_SvcEv_SubscribeEv()
{
    if (listener)
        LLBC_Delete(listener);
}

LLBC_SvcEv_UnsubscribeEv::LLBC_SvcEv_UnsubscribeEv()
: Base(_EvType::UnsubscribeEv)
, id(0)
, stub(LLBC_INVALID_LISTENER_STUB)
{
}

LLBC_SvcEv_AppCfgReloadedEv::LLBC_SvcEv_AppCfgReloadedEv()
: Base(_EvType::AppCfgReloaded)
, iniReloaded(false)
, propReloaded(false)
{
}

LLBC_SvcEv_AppCfgReloadedEv::~LLBC_SvcEv_AppCfgReloadedEv()
{
}

LLBC_SvcEv_UnsubscribeEv::~LLBC_SvcEv_UnsubscribeEv()
{
}

LLBC_SvcEv_FireEv::LLBC_SvcEv_FireEv()
: Base(_EvType::FireEv)
, ev(nullptr)
{
}

LLBC_SvcEv_FireEv::~LLBC_SvcEv_FireEv()
{
    if (ev)
    {
        if (!ev->IsDontDelAfterFire())
            LLBC_Delete(ev);
        else if (dequeueHandler)
            dequeueHandler(ev);
    }
}

LLBC_MessageBlock *LLBC_SvcEvUtil::BuildSessionCreateEv(const LLBC_SockAddr_IN &local,
                                                        const LLBC_SockAddr_IN &peer,
                                                        bool isListen,
                                                        int sessionId,
                                                        int acceptSessionId,
                                                        LLBC_SocketHandle handle)
{
    typedef LLBC_SvcEv_SessionCreate _Ev;

    _Ev *ev = LLBC_New(_Ev);
    ev->isListen = isListen;
    ev->sessionId = sessionId;
    ev->acceptSessionId = acceptSessionId;
    ev->local = local;
    ev->peer = peer;
    ev->handle = handle;

    return __CreateEvBlock(ev);
}

LLBC_MessageBlock *LLBC_SvcEvUtil::BuildSessionDestroyEv(const LLBC_SockAddr_IN &local,
                                                         const LLBC_SockAddr_IN &peer,
                                                         bool isListen,
                                                         int sessionId,
                                                         int acceptSessionId,
                                                         LLBC_SocketHandle handle,
                                                         LLBC_SessionCloseInfo *closeInfo)
{
    typedef LLBC_SvcEv_SessionDestroy _Ev;

    _Ev *ev = LLBC_New(_Ev);
    ev->local = local;
    ev->peer = peer;
    ev->sessionId = sessionId;
    ev->acceptSessionId = acceptSessionId;
    ev->isListen = isListen;
    ev->handle = handle;

    ev->closeInfo = closeInfo;

    return __CreateEvBlock(ev);
}

LLBC_MessageBlock *LLBC_SvcEvUtil::BuildAsyncConnResultEv(int sessionId,
                                                          bool connected,
                                                          const LLBC_String &reason,
                                                          const LLBC_SockAddr_IN &peer)
{
    typedef LLBC_SvcEv_AsyncConn _Ev;

    _Ev *ev = LLBC_New(_Ev);
    ev->sessionId = sessionId;
    ev->connected = connected;
    ev->reason.append(reason);
    ev->peer = peer;

    return __CreateEvBlock(ev);
}

LLBC_MessageBlock *LLBC_SvcEvUtil::BuildDataArrivalEv(LLBC_Packet *packet)
{
    typedef LLBC_SvcEv_DataArrival _Ev;

    _Ev *ev = LLBC_New(_Ev);
    ev->packet = packet;

    return __CreateEvBlock(ev);
}

LLBC_MessageBlock *LLBC_SvcEvUtil::BuildProtoReportEv(int sessionId,
                                                      int opcode,
                                                      int layer,
                                                      int level,
                                                      const LLBC_String &report)
{
    typedef LLBC_SvcEv_ProtoReport _Ev;

    _Ev *ev = LLBC_New(_Ev);
    ev->sessionId = sessionId;
    ev->opcode = opcode;
    ev->layer = layer;
    ev->level = level;
    ev->report.append(report);

    return __CreateEvBlock(ev);
}

LLBC_MessageBlock *LLBC_SvcEvUtil::BuildSubscribeEventEv(int id,
                                                         const LLBC_ListenerStub &stub,
                                                         const LLBC_Delegate<void(LLBC_Event &)> &deleg,
                                                         LLBC_EventListener *listener)
{
    typedef LLBC_SvcEv_SubscribeEv _Ev;

    _Ev *ev = LLBC_New(_Ev);
    ev->id = id;
    ev->stub = stub;
    if (deleg)
        ev->deleg = deleg;
    if (listener)
        ev->listener = listener;

    return __CreateEvBlock(ev);
}

LLBC_MessageBlock *LLBC_SvcEvUtil::BuildUnsubscribeEventEv(int id, const LLBC_ListenerStub &stub)
{
    typedef LLBC_SvcEv_UnsubscribeEv _Ev;

    _Ev *ev = LLBC_New(_Ev);
    ev->id = id;
    ev->stub = stub;

    return __CreateEvBlock(ev);
}

LLBC_MessageBlock *LLBC_SvcEvUtil::BuildFireEventEv(LLBC_Event *ev,
                                                    const LLBC_Delegate<void(LLBC_Event *)> &dequeueHandler)
{
    typedef LLBC_SvcEv_FireEv _Ev;

    _Ev *wrapEv = LLBC_New(_Ev);
    wrapEv->ev = ev;
    if (dequeueHandler)
        wrapEv->dequeueHandler = dequeueHandler;

    return __CreateEvBlock(wrapEv);
}

LLBC_MessageBlock * LLBC_SvcEvUtil::BuildAppCfgReloadedEv(bool iniReloaded, bool propReloaded)
{
    typedef LLBC_SvcEv_AppCfgReloadedEv _Ev;

    _Ev *ev= LLBC_New(_Ev);
    ev->iniReloaded = iniReloaded;
    ev->propReloaded = propReloaded;

    return __CreateEvBlock(ev);
}

    void LLBC_SvcEvUtil::DestroyEvBlock(LLBC_MessageBlock *block)
{
    // Skip event type.
    block->ShiftReadPos(sizeof(int));

    LLBC_ServiceEvent *svcEv;
    block->Read(&svcEv, sizeof(LLBC_ServiceEvent *));

    LLBC_Delete(svcEv);
    LLBC_Delete(block);
}

__LLBC_NS_END

#include "llbc/common/AfterIncl.h"
