

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Fri Mar 06 04:36:15 2026
 */
/* Compiler settings for .\repoInfo.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __repoInfo_i_h__
#define __repoInfo_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILabelInfo_FWD_DEFINED__
#define __ILabelInfo_FWD_DEFINED__
typedef interface ILabelInfo ILabelInfo;
#endif 	/* __ILabelInfo_FWD_DEFINED__ */


#ifndef __LabelInfo_FWD_DEFINED__
#define __LabelInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class LabelInfo LabelInfo;
#else
typedef struct LabelInfo LabelInfo;
#endif /* __cplusplus */

#endif 	/* __LabelInfo_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ILabelInfo_INTERFACE_DEFINED__
#define __ILabelInfo_INTERFACE_DEFINED__

/* interface ILabelInfo */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ILabelInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0AA81A7A-885B-4FF0-87C7-707740257C6C")
    ILabelInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getInfo( 
            /* [in] */ BSTR labelStr,
            /* [retval][out] */ BSTR *ret) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILabelInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILabelInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILabelInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILabelInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILabelInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILabelInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILabelInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILabelInfo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getInfo )( 
            ILabelInfo * This,
            /* [in] */ BSTR labelStr,
            /* [retval][out] */ BSTR *ret);
        
        END_INTERFACE
    } ILabelInfoVtbl;

    interface ILabelInfo
    {
        CONST_VTBL struct ILabelInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILabelInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILabelInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILabelInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILabelInfo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILabelInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILabelInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILabelInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILabelInfo_getInfo(This,labelStr,ret)	\
    ( (This)->lpVtbl -> getInfo(This,labelStr,ret) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILabelInfo_INTERFACE_DEFINED__ */



#ifndef __repoInfoLib_LIBRARY_DEFINED__
#define __repoInfoLib_LIBRARY_DEFINED__

/* library repoInfoLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_repoInfoLib;

EXTERN_C const CLSID CLSID_LabelInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("5008843B-6715-47EC-81F9-965F9419D5FE")
LabelInfo;
#endif
#endif /* __repoInfoLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


