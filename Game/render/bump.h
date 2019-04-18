#ifndef _BUMP_H
#define _BUMP_H

#include "stdtypes.h"
#include "rt_model_cache.h"
typedef struct Model Model;
typedef struct TexReadInfo TexReadInfo;

// A number of shaders all now assume this is 1
#define TANGENT_SCALE 1.f

// Generated by mkproto
int isBumpMapped(Model *model);
void bumpInitObj(Model *model);
void bumpMakeNormalMap(TexReadInfo *image, F32 scale,int mirror);
void bumpInit();
// End mkproto
#endif
