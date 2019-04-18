#ifndef _WIN_CURSOR_H
#define _WIN_CURSOR_H

#include "rt_cursor.h"

typedef struct AtlasTex AtlasTex;

// Generated by mkproto
void hwcursorInit(void);
void hwcursorClear(void);
void hwcursorBlit(AtlasTex *texbind,int width,int height, F32 x,F32 y, F32 scale, int clr);
void hwcursorSet(void);
void hwcursorReload(HCURSOR* phCursor, int hotspot_x,int hotspot_y);
void hwcursorReloadDefault();
int iconIsNew( AtlasTex * base_spr, AtlasTex * cursor_dragged_icon );
void hwcursorSetHotSpot(int hot_x,int hot_y);

// End mkproto
#endif
