/**********************************************************************
 *<
	FILE:			AVCMod.cpp
	DESCRIPTION:	Vertex Color Modifier
	CREATED BY:		Christer Janson
	HISTORY:		Created Monday, June 02, 1997

	This modifier is the keeper of vertex colors generated by the
	"Apply Vertex Colors" Utility plug-in.

 *>	Copyright (c) 1997 Kinetix, All Rights Reserved.
 **********************************************************************/

#include "ApplyVC.h"

//--- ClassDescriptor and class vars ---------------------------------

IObjParam*			ApplyVCMod::ip =	NULL;

class AVCClassDesc:public ClassDesc {
	public:
	int 			IsPublic() { return 0; }
	void *			Create(BOOL loading = FALSE) { return new ApplyVCMod(!loading);}
	const TCHAR *	ClassName() { return GetString(IDS_AVCM_CNAME); }
	SClass_ID		SuperClassID() { return OSM_CLASS_ID; }
	Class_ID		ClassID() { return APPLYVC_MOD_CLASS_ID; }
	const TCHAR* 	Category() { return _T("");}
};

static AVCClassDesc vcmodDesc;
extern ClassDesc* GetApplyVCModDesc() {return &vcmodDesc;}


//--- ApplyVCMod methods -------------------------------


ApplyVCMod::ApplyVCMod(BOOL create)
{	
	iValid.SetEmpty();
}

void ApplyVCMod::DeleteThis()
{
	delete this;
}

void ApplyVCMod::GetClassName(TSTR& s)
{
	s= GetString(IDS_AVCM_CNAME);
}

Class_ID ApplyVCMod::ClassID()
{
	return APPLYVC_MOD_CLASS_ID;
}

TCHAR* ApplyVCMod::GetObjectName()
{
	return GetString(IDS_AVCM_ONAME);
}

CreateMouseCallBack* ApplyVCMod::GetCreateMouseCallBack()
{
	return NULL;
}

// Prevent us from being copied in TrackView/ModifierStack.
BOOL ApplyVCMod::CanCopyAnim()
{
	return FALSE;
}

ChannelMask ApplyVCMod::ChannelsUsed()
{
	return VERTCOLOR_CHANNEL | TOPO_CHANNEL;
}

ChannelMask ApplyVCMod::ChannelsChanged()
{
	return VERTCOLOR_CHANNEL | TOPO_CHANNEL;
}

BOOL ApplyVCMod::DependOnTopology(ModContext &mc)
{
	return TRUE;
}

Class_ID ApplyVCMod::InputType()
{
	return mapObjectClassID;
}

int ApplyVCMod::NumRefs()
{
	return 0;
}

int ApplyVCMod::NumSubs()
{
	return 0;
}

#define MIX_COLOR_CHUNK		0x110
#define VX_COLOR_CHUNK		0x120

IOResult ApplyVCMod::Load(ILoad *iload)
{
	IOResult res;
	ULONG nb;

	ResetColTab();

	Modifier::Load(iload);	
	while (IO_OK==(res=iload->OpenChunk())) {
		switch(iload->CurChunkID())  {
			case MIX_COLOR_CHUNK: {
				Color* col = new Color();
				res=iload->Read(col,sizeof(Color),&nb);
				mixedVertexColors.Append(1, &col, 25);
				break;
			}

			case VX_COLOR_CHUNK: {
				FaceColor* faceCol = new FaceColor;
				for (int j=0; j<3; j++) {
					iload->Read(&faceCol->colors[j],sizeof(Color),&nb);
				}
				faceColors.Append(1, &faceCol, 25);
				break;
			}
			default:
				break; 
		}
		iload->CloseChunk();
		if (res!=IO_OK) 
			return res;
	}
	return IO_OK;
}

IOResult ApplyVCMod::Save(ISave *isave)
{
	IOResult res;
	ULONG nb;
	int i, j;

	Modifier::Save(isave);

	for (i=0; i<mixedVertexColors.Count(); i++) {
		isave->BeginChunk(MIX_COLOR_CHUNK);
		res = isave->Write(mixedVertexColors[i], sizeof(Color), &nb);
		isave->EndChunk();
	}

	for (i=0; i<faceColors.Count(); i++) {
		isave->BeginChunk(VX_COLOR_CHUNK);
		for (j=0; j<3; j++) {
			res = isave->Write(faceColors[i]->colors[j], sizeof(Color), &nb);
		}
		isave->EndChunk();
	}

	return IO_OK;
}

static INT_PTR CALLBACK panelDlgProc(
		HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_MOUSEMOVE:
			GetCOREInterface()->RollupMouseMessage(hWnd,msg,wParam,lParam); 
			break;
		default:
			return FALSE;
	}
	return TRUE;
}	

void ApplyVCMod::BeginEditParams(IObjParam *ip, ULONG flags,Animatable *prev)
{
	this->ip = ip;

	TimeValue t = ip->GetTime();
	NotifyDependents(Interval(t,t), PART_ALL, REFMSG_BEGIN_EDIT);
	NotifyDependents(Interval(t,t), PART_ALL, REFMSG_MOD_DISPLAY_ON);
	SetAFlag(A_MOD_BEING_EDITED);

	hPanel = ip->AddRollupPage(
		hInstance,
		MAKEINTRESOURCE(IDD_VCMOD_PANEL),
		panelDlgProc,
		GetString(IDS_AVCM_PANELTITLE),
		0);

	iValid.SetEmpty();
}
		
void ApplyVCMod::EndEditParams( IObjParam *ip, ULONG flags,Animatable *next )
{	
	this->ip = NULL;

	TimeValue t = ip->GetTime();
	ip->DeleteRollupPage(hPanel);
	hPanel = NULL;
	ClearAFlag(A_MOD_BEING_EDITED);
 	NotifyDependents(Interval(t,t), PART_ALL, REFMSG_END_EDIT);
	NotifyDependents(Interval(t,t), PART_ALL, REFMSG_MOD_DISPLAY_OFF);
}

Interval ApplyVCMod::LocalValidity(TimeValue t)
{	
  // aszabo|feb.05.02 If we are being edited, 
	// return NEVER to forces a cache to be built after previous modifier.
	if (TestAFlag(A_MOD_BEING_EDITED))
		return NEVER;
	return GetValidity(t);
}

RefTargetHandle ApplyVCMod::Clone(RemapDir& remap) 
{
	ApplyVCMod* newmod = new ApplyVCMod(FALSE);	

	for (int i=0; i<mixedVertexColors.Count(); i++) {
		Color* c = new Color(*mixedVertexColors[i]);
		newmod->mixedVertexColors.Append(1, &c, 25);
	}
	BaseClone(this, newmod, remap);
	return newmod;
}


void ApplyVCMod::ModifyTriObject(TriObject* obj, TimeValue t)
{
	static int calls = 0;
	iValid = FOREVER;
	Interval valid = GetValidity(t);

	Mesh &mesh = obj->GetMesh();	

	if (mixedVertexColors.Count() > 0) {
		mesh.setNumVertCol(mesh.numVerts);
		mesh.setNumVCFaces(mesh.numFaces);

		for (int i=0; i<mesh.numVerts; i++) {
			mesh.vertCol[i] = i<mixedVertexColors.Count() ?
				Point3(mixedVertexColors[i]->r, mixedVertexColors[i]->g, mixedVertexColors[i]->b) :
				Point3(1.0f, 1.0f, 1.0f);
			}

		for (int i=0; i<mesh.numFaces; i++) {
			mesh.vcFace[i].t[0] = mesh.faces[i].v[0];
			mesh.vcFace[i].t[1] = mesh.faces[i].v[1];
			mesh.vcFace[i].t[2] = mesh.faces[i].v[2];
			}
		}
	else if (faceColors.Count() > 0) {
		int numVCVerts = mesh.numFaces*3;
		mesh.setNumVCFaces(mesh.numFaces);
		mesh.setNumVertCol(numVCVerts);

		int faceVert = 0;
		for (int i=0; i<mesh.numFaces; i++) {
			for (int j=0; j<3; j++) {
				mesh.vertCol[faceVert] = i<faceColors.Count() ? 
					Point3(faceColors[i]->colors[j].r, faceColors[i]->colors[j].g, faceColors[i]->colors[j].b) :
					Point3(1.0f, 1.0f, 1.0f);
				faceVert++;
				}
			}

		faceVert = 0;
		for (int i=0; i<mesh.numFaces; i++) {
			mesh.vcFace[i].t[0] = faceVert++;
			mesh.vcFace[i].t[1] = faceVert++;
			mesh.vcFace[i].t[2] = faceVert++;
			}
		}

	NotifyDependents(Interval(t,t), PART_VERTCOLOR & PART_EXCLUDE_RADIOSITY, REFMSG_CHANGE);
	NotifyDependents(Interval(t,t), PART_TOPO & PART_EXCLUDE_RADIOSITY, REFMSG_CHANGE);
	obj->UpdateValidity(VERT_COLOR_CHAN_NUM, valid);
}


/////////////////////////////////////////////////////////////////////
// Note: 
//    The vertex color data that is used by the ModifyPolyObject 
//    method was created based on this PolyObject's displayed 
//    TriMesh (Mesh). This data is mapped back to the original 
//    PolyMesh (MNMesh).  The mapping relies on the same process 
//    that was used by the method MNMesh::OutToTri() to generate 
//    the Mesh.
// Warning:
//    The mapping used in this method will need to be updated if 
//    anything changes in the way MNMesh generates its displayed Mesh.
// Author: 
//    Wayne Catalfano
// Date:
//    August 30, 2000
//
///////////////////////////////////////////////////////////////////////
void ApplyVCMod::ModifyPolyObject(PolyObject* pPolyObj, TimeValue t)
{
	static int calls = 0;
	iValid = FOREVER;
	Interval valid = GetValidity(t);

	MNMesh& mesh = pPolyObj->GetMesh();
	if (mesh.MNum() < 1) mesh.SetMapNum (1);

	// get the vertex color map
	MNMap* pVCMap = mesh.M(0);

	// initialize to an all white map if necessary
	if (pVCMap->GetFlag(MN_DEAD)) mesh.InitMap(0);

	if (mixedVertexColors.Count() > 0) {
		pVCMap->setNumVerts (mesh.VNum());
		pVCMap->setNumFaces (mesh.FNum());

		// MNMesh keeps the vertices in the same order when it creates
		// the Mesh.  The Mesh vertices Map directly back to the MNMesh
		// vertices in the same order.
		for (int i=0; i<mesh.VNum(); i++) {
			pVCMap->v[i] = i<mixedVertexColors.Count() ?
				Point3(mixedVertexColors[i]->r, mixedVertexColors[i]->g, mixedVertexColors[i]->b) :
				Point3(1.0f, 1.0f, 1.0f);
		}

		for (int i=0; i<mesh.FNum(); i++) {
			if (mesh.F(i)->GetFlag (MN_DEAD)) continue;
			pVCMap->F(i)->SetSize(mesh.F(i)->deg);
			for (int j=0; j<mesh.F(i)->deg;++j) {
				pVCMap->F(i)->tv[j] = mesh.F(i)->vtx[j];
			}
		}
	}
	else if (faceColors.Count() > 0) {
		int numVCVerts = 0;
		for (int i=0; i<mesh.FNum(); i++) {
			if (mesh.F(i)->GetFlag (MN_DEAD)) continue;
			numVCVerts += mesh.F(i)->deg;
		}
		pVCMap->setNumVerts (numVCVerts);
		pVCMap->setNumFaces (mesh.FNum());

		// This mapping process mimicks the process used to generate  
		// the Mesh in the method MNMesh::OutToTri().
		int faceVert = 0;
		int triFaceIndx = 0;
		BitArray faceVertSet;
		for (int i=0; i<mesh.FNum(); i++) {
			if (mesh.F(i)->GetFlag (MN_DEAD)) continue;
			pVCMap->F(i)->SetSize(mesh.F(i)->deg);
			faceVertSet.SetSize(mesh.F(i)->deg);
			faceVertSet.ClearAll();
			int tnum = mesh.F(i)->TriNum()*3;
			Tab<int> triVerts;
			// The method MNFace::GetTriangles is at the heart of the 
			// process used to map Mesh triangles back to MNMesh faces.
			mesh.F(i)->GetTriangles (triVerts);
			for (int j=0; j<tnum; j+=3) {
				for (int k=0; k<3; ++k) {
					int vertIndex = triVerts[j+k];
					// check if we already added a vert for this index
					if (!faceVertSet[vertIndex]) {
						pVCMap->v[faceVert] = triFaceIndx<faceColors.Count() ? 
							Point3(faceColors[triFaceIndx]->colors[k].r, 
								   faceColors[triFaceIndx]->colors[k].g, 
								   faceColors[triFaceIndx]->colors[k].b) :
							Point3(1.0f, 1.0f, 1.0f);

						pVCMap->F(i)->tv[vertIndex] = faceVert;
						faceVertSet.Set(vertIndex);
						faceVert++; 
					}
				}
				++triFaceIndx;
			}
		}
	}

	NotifyDependents(Interval(t,t), PART_VERTCOLOR & PART_EXCLUDE_RADIOSITY, REFMSG_CHANGE);
	NotifyDependents(Interval(t,t), PART_TOPO & PART_EXCLUDE_RADIOSITY, REFMSG_CHANGE);
	pPolyObj->UpdateValidity(VERT_COLOR_CHAN_NUM, valid);
}

void ApplyVCMod::ModifyObject(TimeValue t, ModContext &mc, ObjectState * os, INode *node) 
{
	// handle TriObjects
	if (os->obj->IsSubClassOf(triObjectClassID)) {
		TriObject *tobj = (TriObject*)os->obj;
		ModifyTriObject(tobj, t);
	}
	// handle PolyObjects
	else if (os->obj->IsSubClassOf(polyObjectClassID)) {
		PolyObject *pPolyObj = (PolyObject*)os->obj;
		ModifyPolyObject(pPolyObj, t);
	}
	// Convert to a tri mesh if possible
	else if(os->obj->CanConvertToType(triObjectClassID)) {
		TriObject  *triOb = (TriObject *)os->obj->ConvertToType(t, triObjectClassID);
		// Now stuff this into the pipeline!
		os->obj = triOb;

		ModifyTriObject(triOb, t);
	}
}		

RefTargetHandle ApplyVCMod::GetReference(int i)
{
	return NULL;
}

void ApplyVCMod::SetReference(int i, RefTargetHandle rtarg)
{
}

Animatable* ApplyVCMod::SubAnim(int i)
{
	return NULL;
}

TSTR ApplyVCMod::SubAnimName(int i)
{
	return _T("");
}

RefResult ApplyVCMod::NotifyRefChanged(
		Interval changeInt, 
		RefTargetHandle hTarget, 
   		PartID& partID, 
   		RefMessage message) 
{
	return REF_SUCCEED;
}

void ApplyVCMod::ResetColTab()
{
	int i;
	// Reset table of mixed colors
	for (i=0; i<mixedVertexColors.Count(); i++) {
		delete mixedVertexColors[i];
	}
	mixedVertexColors.ZeroCount();
	mixedVertexColors.Shrink();

	// Reset table of vertex colors
	for (i=0; i<faceColors.Count(); i++) {
		delete faceColors[i];
	}
	faceColors.ZeroCount();
	faceColors.Shrink();

	iValid.SetEmpty();
}

// Public access function.
// Please note that multiple vertex colors are not implemetned yet.
// Please use SetMixedColors() for now.
void ApplyVCMod::SetColors(FaceColorTab& colorTab)
	{
	ResetColTab();

	for (int i=0; i<colorTab.Count(); i++) {
		FaceColor* faceCol = new FaceColor;

		for (int j=0; j<3; j++) {
			faceCol->colors[j] = colorTab[i]->colors[j];
		}
		faceColors.Append(1, &faceCol, 25);
	}

	NotifyDependents(FOREVER, PART_VERTCOLOR & PART_EXCLUDE_RADIOSITY, REFMSG_CHANGE);
	}


// Public access function.
void ApplyVCMod::SetMixedColors(ColorTab& colorTab)
{
	ResetColTab();

	for (int i=0; i<colorTab.Count(); i++) {
		Color* col = new Color(*colorTab[i]);
		mixedVertexColors.Append(1, &col, 25);
	}

	NotifyDependents(FOREVER, PART_VERTCOLOR & PART_EXCLUDE_RADIOSITY, REFMSG_CHANGE);
}
