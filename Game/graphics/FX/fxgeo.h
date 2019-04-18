#ifndef _FXGEO_H
#define _FXGEO_H

#include "stdtypes.h"
#include "fxinfo.h"
#include "fxbhvr.h"
#include "fxfluid.h"

#define MAX_FXMINITRACKERS 50 //pretty rare, so can be too big, but I ought to dynamically alloc them
typedef struct FxMiniTracker 
{
	DefTracker *tracker;
	DefTracker *lighttracker;
	int count;
	int fxIds[MAX_FXMINITRACKERS];
	U8 alpha;
} FxMiniTracker;

typedef struct FxParams FxParams;
typedef struct FxObject FxObject;
typedef struct FxCapeInst FxCapeInst;
typedef struct ParticleSystem ParticleSystem;
typedef struct NwEmissaryData NwEmissaryData;

//An FxGeo controls one GfxNode's behavior, and propagates info about that GfxNode
//to anything else in the fx system that needs to know about it (like particle systems)
//An fxnode without a good gfxnode is a problem, and I need to make sure all situations
//where that might happen are covered
typedef struct FxGeo
{
	//////List Management (must be first)
	struct FxGeo	* next;
	struct FxGeo	* prev;
	int				handle;

	// HOT stuff
	GfxNode			* gfx_node;
	int				gfx_node_id;
	Vec3			position_last_frame;
	F32				age;				//age in frames
	U8				alpha;
	U8				fxgeo_flags;
	U8				hasCollided : 1;
	U8				isDeathFxGeo : 1;
	U8				isRoot : 1;
	U8				bhvrOverride : 1;
#ifdef NOVODEX
	U8				waitingOnNxActor : 1;
#endif
	U8				needSetCustomTextures : 1;
#ifdef NOVODEX
	NwEmissaryDataGuid		nxEmissary;
	NwEmissaryDataGuid		nxForceCollisionSphere;
#endif
	Vec3			velocity;			//Physical state
	GfxNode			* origin;			//If position node, who does it get it's position from? 
	int				originid;			//should this be fxgeos instead of gfxnodes?
	const FxBhvr	*bhvr;				//What to do every frame, assigned at creation
	Vec3			bhvr_spin;			//Jittered bhvr spin

	//////Behavior and current state
	char			name[FXSTRLEN];		//Name given to it by the event that created it
#ifdef NOVODEX_FLUIDS
	FxFluidEmitter	fluidEmitter;
#endif
	int				unique_id;			//to identify me to the sound system
	FxEvent			* event;			//Event that created it; 0 = key. not made by an event
	Mat4			world_spot;			//current world position
	Mat4			world_spot_last_frame;
	F32				world_spot_age;		//age at which the world_spot was last updated
	Vec3			spinrate;
	Vec3			cumulativescale;	//needed for when rotations and such ditch it's scale values
	Vec3			clampMinScale;
	Vec3			clampMaxScale;
	Vec3			cumulativespin;		//needed for when scales and such ditch it's spin values
	int				lifeStage;
	F32				fadingOutTime;  //length of time this fxgeo has been fading out
	F32				fadingInTime;  //length of time this fxgeo has been fading in
	char			* rgbs;				// static lighting for object if needed
	int				is_scaling;
	int				hasSplat;
	F32				lifespan;
	U8				groupTint[3]; // For color tinting via tints on groups in the editor
	U8				seq_tint_color[2][3]; // For color tinting attached sequencers/animations
	TextureOverride	seq_textures; // For swapping textures on attached sequencers/animations
	ColorPair		customTint; // For tinting based on customized power colors

	//////Interested parties that this fxgeo creates, updates and destroys
	int				seq_handle;
	ParticleSystem	* psys[MAX_PSYSPERFXGEO];
	int				psys_id[MAX_PSYSPERFXGEO];
	int				psys_count;
	int				childfxid;
	SoundEvent		* sound_triggered;

	GroupDef		* worldGroupPtr;
	int				worldGroupPtrVersion;
	char *			worldGroupName;
	FxMiniTracker	* fxMiniTracker;

	GfxNode			* splatNode;
	int				splatNodeUniqueId;

	FxCapeInst		* capeInst;

	//////Nodes and FxGeos used to move and orient 

	int				magnetid;		//handle of magnet fxgeo
	int				lookatid;		//handle of "other" fxgeo
	int				pmagnetid;		//handle of magnet for particle systems fxgeo
	int				potherid;		//handle of pother for particle systems fxgeo

	//Temp Debug
	int			bhvrage;
#ifdef NOVODEX_FLUIDS
	int			fluidage;
#endif
	int			partage[MAX_PSYSPERFXGEO];

} FxGeo;

enum 
{
	FXGEO_ACTIVE	= 0,
	FXGEO_FADINGOUT	= 1,
	FXGEO_KEY		= 2
};

// Generated by mkproto
int fxGeoCreate(void ** fxgeolist, int * fxgeocount, GfxNode * key, Mat4 offset, FxEvent * fxevent, int iskey, FxInfo *fxInfo, DefTracker * light );
int fxGeoUpdate(FxGeo * fxgeo, int * fxobject_flags, U8 inheritedAlpha, F32 animScale );
void fxGeoDestroy(FxGeo * fxgeo, int * fxobject_flags, void ** fxgeolist, int * fxgeo_count, int killtype, int fxobjectid);
int fxGeoAttachChildFx(FxGeo * fxgeo, char * childfx, FxParams *parentFxp, int seq_handle, int target_seq_handle);
int fxGeoAttachParticles(FxGeo * fxgeo, TokenizerParams ** part, int kickstart, int power, FxParams *fxp, FxInfo *fxInfo, F32 animScale );
#ifdef NOVODEX_FLUIDS
void fxGeoCreateFluid(FxGeo * fxgeo);
#endif NOVODEX_FLUIDS
void fxGeoParticlesChangeParams(FxGeo * fxgeo, FxParams * fxp, FxInfo *fxInfo);
void fxGeoAnimationChangeParams(FxGeo * fxgeo, FxParams * fxp);
int fxGeoAttachSeq(FxGeo * fxgeo, char * anim);
int fxGeoAttachWorldGroup( FxGeo * fxgeo, char * worldGroup, GroupDef * externalWorldGroupPtr );
int fxGeoAttachCape(FxGeo * fxgeo, TokenizerParams ** capeList, int seqHandle, FxParams *fxp );
Mat4Ptr fxGeoGetWorldSpot(int fxid);
int fxGeoSetAnimState( FxGeo * fxgeo, char * newstate);
FxGeo * findFxGeo( FxGeo * firstfxgeo, char * name );
void fxGeoInitialize(FxGeo * fxgeo, FxGeo * fxgeolist);
void fxGeoUpdateAnimation(FxGeo * fxgeo, int seq_handle, int parent_seq_handle, int * state, EntLight * light, U8 alpha, F32 animScale, char * additionalStates  );
void fxGeoUpdateParticleSystems(FxGeo * fxgeo, int drawstatus, int teleported, U8 inheritedAlpha, F32 animScale );
void fxGeoUpdateWorldGroup( FxGeo * fxgeo, int drawstatus, EntLight * entLight, U8 inheritedAlpha, int useStaticLighting );
void fxGeoUpdateSound( FxGeo* fxgeo, int seqHandle );
void fxGeoUpdateSplat( FxGeo * fxgeo, U8 actualAlpha );
void fxGeoUpdateCape( FxGeo* fxgeo, FxObject *fx);
int fxGeoFadeOut( FxGeo * fxgeo );
void fxGeoResetAllCapes(void);
// End mkproto 
#endif 
