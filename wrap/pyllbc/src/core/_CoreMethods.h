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

//!!! This file is auto generated by script tool, do not modify it!!!

#ifndef __PYLLBC_AUTOGEN_CORE__COREMETHODS_H__
#define __PYLLBC_AUTOGEN_CORE__COREMETHODS_H__

#include "pyllbc/common/LibHeader.h"
#include "pyllbc/common/Macro.h"
#include "src/core/bundle/_Bundle.h"
#include "src/core/config/_Property.h"
#include "src/core/file/_Directory.h"
#include "src/core/helper/_GUIDHelper.h"
#include "src/core/log/_Log.h"
#include "src/core/random/_Random.h"
#include "src/core/thread/_Task.h"
#include "src/core/utils/_Util_Misc.h"
#include "src/core/utils/_Util_String.h"

class pyllbc_CoreMethods
{
public:
    pyllbc_CoreMethods()
    {
        createtask.ml_name = "createtask";
        createtask.ml_meth = (PyCFunction)_pyllbc_createtask;
        createtask.ml_flags = METH_VARARGS;
        createtask.ml_doc = "pyllbc library method/function";
        Property_ToContent.ml_name = "Property_ToContent";
        Property_ToContent.ml_meth = (PyCFunction)_pyllbc_Property_ToContent;
        Property_ToContent.ml_flags = METH_VARARGS;
        Property_ToContent.ml_doc = "pyllbc library method/function";
        GetBundleResPath.ml_name = "GetBundleResPath";
        GetBundleResPath.ml_meth = (PyCFunction)_pyllbc_GetBundleResPath;
        GetBundleResPath.ml_flags = METH_VARARGS;
        GetBundleResPath.ml_doc = "pyllbc library method/function";
        BoolJudge.ml_name = "BoolJudge";
        BoolJudge.ml_meth = (PyCFunction)_pyllbc_BoolJudge;
        BoolJudge.ml_flags = METH_VARARGS;
        BoolJudge.ml_doc = "pyllbc library method/function";
        GetMainBundle.ml_name = "GetMainBundle";
        GetMainBundle.ml_meth = (PyCFunction)_pyllbc_GetMainBundle;
        GetMainBundle.ml_flags = METH_VARARGS;
        GetMainBundle.ml_doc = "pyllbc library method/function";
        RandReal.ml_name = "RandReal";
        RandReal.ml_meth = (PyCFunction)_pyllbc_RandReal;
        RandReal.ml_flags = METH_VARARGS;
        RandReal.ml_doc = "pyllbc library method/function";
        Property_RemoveAllPropertyes.ml_name = "Property_RemoveAllPropertyes";
        Property_RemoveAllPropertyes.ml_meth = (PyCFunction)_pyllbc_Property_RemoveAllPropertyes;
        Property_RemoveAllPropertyes.ml_flags = METH_VARARGS;
        Property_RemoveAllPropertyes.ml_doc = "pyllbc library method/function";
        HashString.ml_name = "HashString";
        HashString.ml_meth = (PyCFunction)_pyllbc_HashString;
        HashString.ml_flags = METH_VARARGS;
        HashString.ml_doc = "pyllbc library method/function";
        SeedRand.ml_name = "SeedRand";
        SeedRand.ml_meth = (PyCFunction)_pyllbc_SeedRand;
        SeedRand.ml_flags = METH_VARARGS;
        SeedRand.ml_doc = "pyllbc library method/function";
        istaskexist.ml_name = "istaskexist";
        istaskexist.ml_meth = (PyCFunction)_pyllbc_istaskexist;
        istaskexist.ml_flags = METH_VARARGS;
        istaskexist.ml_doc = "pyllbc library method/function";
        Property_ToFile.ml_name = "Property_ToFile";
        Property_ToFile.ml_meth = (PyCFunction)_pyllbc_Property_ToFile;
        Property_ToFile.ml_flags = METH_VARARGS;
        Property_ToFile.ml_doc = "pyllbc library method/function";
        Property_GetProperty.ml_name = "Property_GetProperty";
        Property_GetProperty.ml_meth = (PyCFunction)_pyllbc_Property_GetProperty;
        Property_GetProperty.ml_flags = METH_VARARGS;
        Property_GetProperty.ml_doc = "pyllbc library method/function";
        GenGUID.ml_name = "GenGUID";
        GenGUID.ml_meth = (PyCFunction)_pyllbc_GenGUID;
        GenGUID.ml_flags = METH_VARARGS;
        GenGUID.ml_doc = "pyllbc library method/function";
        GetModuleFileName.ml_name = "GetModuleFileName";
        GetModuleFileName.ml_meth = (PyCFunction)_pyllbc_GetModuleFileName;
        GetModuleFileName.ml_flags = METH_VARARGS;
        GetModuleFileName.ml_doc = "pyllbc library method/function";
        istaskactivated.ml_name = "istaskactivated";
        istaskactivated.ml_meth = (PyCFunction)_pyllbc_istaskactivated;
        istaskactivated.ml_flags = METH_VARARGS;
        istaskactivated.ml_doc = "pyllbc library method/function";
        Property_GetComments.ml_name = "Property_GetComments";
        Property_GetComments.ml_meth = (PyCFunction)_pyllbc_Property_GetComments;
        Property_GetComments.ml_flags = METH_VARARGS;
        Property_GetComments.ml_doc = "pyllbc library method/function";
        RandInt.ml_name = "RandInt";
        RandInt.ml_meth = (PyCFunction)_pyllbc_RandInt;
        RandInt.ml_flags = METH_VARARGS;
        RandInt.ml_doc = "pyllbc library method/function";
        Property_FromContent.ml_name = "Property_FromContent";
        Property_FromContent.ml_meth = (PyCFunction)_pyllbc_Property_FromContent;
        Property_FromContent.ml_flags = METH_VARARGS;
        Property_FromContent.ml_doc = "pyllbc library method/function";
        Property_GetPropertyNames.ml_name = "Property_GetPropertyNames";
        Property_GetPropertyNames.ml_meth = (PyCFunction)_pyllbc_Property_GetPropertyNames;
        Property_GetPropertyNames.ml_flags = METH_VARARGS;
        Property_GetPropertyNames.ml_doc = "pyllbc library method/function";
        pushmsg.ml_name = "pushmsg";
        pushmsg.ml_meth = (PyCFunction)_pyllbc_pushmsg;
        pushmsg.ml_flags = METH_VARARGS;
        pushmsg.ml_doc = "pyllbc library method/function";
        Property_HasProperty.ml_name = "Property_HasProperty";
        Property_HasProperty.ml_meth = (PyCFunction)_pyllbc_Property_HasProperty;
        Property_HasProperty.ml_flags = METH_VARARGS;
        Property_HasProperty.ml_doc = "pyllbc library method/function";
        Property_GetValue.ml_name = "Property_GetValue";
        Property_GetValue.ml_meth = (PyCFunction)_pyllbc_Property_GetValue;
        Property_GetValue.ml_flags = METH_VARARGS;
        Property_GetValue.ml_doc = "pyllbc library method/function";
        currenttaskid.ml_name = "currenttaskid";
        currenttaskid.ml_meth = (PyCFunction)_pyllbc_currenttaskid;
        currenttaskid.ml_flags = METH_VARARGS;
        currenttaskid.ml_doc = "pyllbc library method/function";
        popmsg.ml_name = "popmsg";
        popmsg.ml_meth = (PyCFunction)_pyllbc_popmsg;
        popmsg.ml_flags = METH_VARARGS;
        popmsg.ml_doc = "pyllbc library method/function";
        Property_FromFile.ml_name = "Property_FromFile";
        Property_FromFile.ml_meth = (PyCFunction)_pyllbc_Property_FromFile;
        Property_FromFile.ml_flags = METH_VARARGS;
        Property_FromFile.ml_doc = "pyllbc library method/function";
        Property_Delete.ml_name = "Property_Delete";
        Property_Delete.ml_meth = (PyCFunction)_pyllbc_Property_Delete;
        Property_Delete.ml_flags = METH_VARARGS;
        Property_Delete.ml_doc = "pyllbc library method/function";
        Property_SetValue.ml_name = "Property_SetValue";
        Property_SetValue.ml_meth = (PyCFunction)_pyllbc_Property_SetValue;
        Property_SetValue.ml_flags = METH_VARARGS;
        Property_SetValue.ml_doc = "pyllbc library method/function";
        LogMsg.ml_name = "LogMsg";
        LogMsg.ml_meth = (PyCFunction)_pyllbc_LogMsg;
        LogMsg.ml_flags = METH_VARARGS;
        LogMsg.ml_doc = "pyllbc library method/function";
        refcnt.ml_name = "refcnt";
        refcnt.ml_meth = (PyCFunction)_pyllbc_refcnt;
        refcnt.ml_flags = METH_VARARGS;
        refcnt.ml_doc = "pyllbc library method/function";
        GetBundleName.ml_name = "GetBundleName";
        GetBundleName.ml_meth = (PyCFunction)_pyllbc_GetBundleName;
        GetBundleName.ml_flags = METH_VARARGS;
        GetBundleName.ml_doc = "pyllbc library method/function";
        Property_New.ml_name = "Property_New";
        Property_New.ml_meth = (PyCFunction)_pyllbc_Property_New;
        Property_New.ml_flags = METH_VARARGS;
        Property_New.ml_doc = "pyllbc library method/function";
        NewBundle.ml_name = "NewBundle";
        NewBundle.ml_meth = (PyCFunction)_pyllbc_NewBundle;
        NewBundle.ml_flags = METH_VARARGS;
        NewBundle.ml_doc = "pyllbc library method/function";
        InitBundle.ml_name = "InitBundle";
        InitBundle.ml_meth = (PyCFunction)_pyllbc_InitBundle;
        InitBundle.ml_flags = METH_VARARGS;
        InitBundle.ml_doc = "pyllbc library method/function";
        InitLoggerMgr.ml_name = "InitLoggerMgr";
        InitLoggerMgr.ml_meth = (PyCFunction)_pyllbc_InitLoggerMgr;
        InitLoggerMgr.ml_flags = METH_VARARGS;
        InitLoggerMgr.ml_doc = "pyllbc library method/function";
        Property_RemoveProperty.ml_name = "Property_RemoveProperty";
        Property_RemoveProperty.ml_meth = (PyCFunction)_pyllbc_Property_RemoveProperty;
        Property_RemoveProperty.ml_flags = METH_VARARGS;
        Property_RemoveProperty.ml_doc = "pyllbc library method/function";
        Property_GetPropertyCount.ml_name = "Property_GetPropertyCount";
        Property_GetPropertyCount.ml_meth = (PyCFunction)_pyllbc_Property_GetPropertyCount;
        Property_GetPropertyCount.ml_flags = METH_VARARGS;
        Property_GetPropertyCount.ml_doc = "pyllbc library method/function";
        Property_SetComments.ml_name = "Property_SetComments";
        Property_SetComments.ml_meth = (PyCFunction)_pyllbc_Property_SetComments;
        Property_SetComments.ml_flags = METH_VARARGS;
        Property_SetComments.ml_doc = "pyllbc library method/function";
        GetBundlePath.ml_name = "GetBundlePath";
        GetBundlePath.ml_meth = (PyCFunction)_pyllbc_GetBundlePath;
        GetBundlePath.ml_flags = METH_VARARGS;
        GetBundlePath.ml_doc = "pyllbc library method/function";
        NewRandom.ml_name = "NewRandom";
        NewRandom.ml_meth = (PyCFunction)_pyllbc_NewRandom;
        NewRandom.ml_flags = METH_VARARGS;
        NewRandom.ml_doc = "pyllbc library method/function";
        gettaskcount.ml_name = "gettaskcount";
        gettaskcount.ml_meth = (PyCFunction)_pyllbc_gettaskcount;
        gettaskcount.ml_flags = METH_VARARGS;
        gettaskcount.ml_doc = "pyllbc library method/function";
        DelBundle.ml_name = "DelBundle";
        DelBundle.ml_meth = (PyCFunction)_pyllbc_DelBundle;
        DelBundle.ml_flags = METH_VARARGS;
        DelBundle.ml_doc = "pyllbc library method/function";
        DelRandom.ml_name = "DelRandom";
        DelRandom.ml_meth = (PyCFunction)_pyllbc_DelRandom;
        DelRandom.ml_flags = METH_VARARGS;
        DelRandom.ml_doc = "pyllbc library method/function";
    }

public:
    ::PyMethodDef createtask;
    ::PyMethodDef Property_ToContent;
    ::PyMethodDef GetBundleResPath;
    ::PyMethodDef BoolJudge;
    ::PyMethodDef GetMainBundle;
    ::PyMethodDef RandReal;
    ::PyMethodDef Property_RemoveAllPropertyes;
    ::PyMethodDef HashString;
    ::PyMethodDef SeedRand;
    ::PyMethodDef istaskexist;
    ::PyMethodDef Property_ToFile;
    ::PyMethodDef Property_GetProperty;
    ::PyMethodDef GenGUID;
    ::PyMethodDef GetModuleFileName;
    ::PyMethodDef istaskactivated;
    ::PyMethodDef Property_GetComments;
    ::PyMethodDef RandInt;
    ::PyMethodDef Property_FromContent;
    ::PyMethodDef Property_GetPropertyNames;
    ::PyMethodDef pushmsg;
    ::PyMethodDef Property_HasProperty;
    ::PyMethodDef Property_GetValue;
    ::PyMethodDef currenttaskid;
    ::PyMethodDef popmsg;
    ::PyMethodDef Property_FromFile;
    ::PyMethodDef Property_Delete;
    ::PyMethodDef Property_SetValue;
    ::PyMethodDef LogMsg;
    ::PyMethodDef refcnt;
    ::PyMethodDef GetBundleName;
    ::PyMethodDef Property_New;
    ::PyMethodDef NewBundle;
    ::PyMethodDef InitBundle;
    ::PyMethodDef InitLoggerMgr;
    ::PyMethodDef Property_RemoveProperty;
    ::PyMethodDef Property_GetPropertyCount;
    ::PyMethodDef Property_SetComments;
    ::PyMethodDef GetBundlePath;
    ::PyMethodDef NewRandom;
    ::PyMethodDef gettaskcount;
    ::PyMethodDef DelBundle;
    ::PyMethodDef DelRandom;
};

#define pyllbc_s_CoreMethods LLBC_Singleton< ::pyllbc_CoreMethods, LLBC_DummyLock>::Instance()

#endif // !__PYLLBC_AUTOGEN_CORE__COREMETHODS_H__

