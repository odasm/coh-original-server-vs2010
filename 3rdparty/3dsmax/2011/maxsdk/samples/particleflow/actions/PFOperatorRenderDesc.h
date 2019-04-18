/**********************************************************************
 *<
	FILE:			PFOperatorRenderDesc.h

	DESCRIPTION:	Render Operator Class Descriptor (declaration)
											 
	CREATED BY:		Oleg Bayborodin

	HISTORY:		created 11-06-02

 *>	Copyright (c) 2001, All Rights Reserved.
 **********************************************************************/

#ifndef  _PFOPERATORRENDERDESC_H_
#define  _PFOPERATORRENDERDESC_H_

#include "max.h"
#include "iparamb2.h"

namespace PFActions {

//	Descriptor declarations
class PFOperatorRenderDesc: public ClassDesc2 {
	public:
	~PFOperatorRenderDesc();
	int 			IsPublic();
	void *			Create(BOOL loading = FALSE);
	const TCHAR *	ClassName();
	SClass_ID		SuperClassID();
	Class_ID		ClassID();
	Class_ID		SubClassID();
	const TCHAR* 	Category();

	const TCHAR*	InternalName();
	HINSTANCE		HInstance();

	INT_PTR Execute(int cmd, ULONG_PTR arg1, ULONG_PTR arg2, ULONG_PTR arg3);

	static HBITMAP m_depotIcon;
	static HBITMAP m_depotMask;
};

} // end of namespace PFActions

#endif // _PFOPERATORRENDERDESC_H_