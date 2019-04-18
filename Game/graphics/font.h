#ifndef _FONT_H
#define _FONT_H

#include "stdtypes.h"
#include "rt_font.h"


// Generated by mkproto
void fontInitCriticalSection();
void fontSaveText(char *buf,int size);
void fontRestoreText(char *buf);
void fontInit();
int fontNew(FontInfo *font_info);
void fontText(F32 x,F32 y,const char *str);
void fontTextf(F32 x,F32 y,char const *fmt, ...);
void fontSysText(F32 x,F32 y,const char *str, U8 r, U8 g, U8 b);
void xyprintf(int x,int y,char const *fmt, ...);
void xyprintfcolor(int x,int y,U8 r, U8 g, U8 b, char const *fmt, ...);
void fontDefaults();
void fontScale(F32 scale_x,F32 scale_y);
void fontColor(int rgb);
void fontAlpha(int a);
void fontSet(S32 font_index);
F32 fontStringWidth(char *s);
F32 fontStringWidthf(char *s, ...);
F32 fontLocX(F32 x);
F32 fontLocY(F32 y);
void fontRenderEditor();
void fontRenderGame();
void fontRender();
int fontLoadImage(char *texname);
void fontReplaceImage(int font_id,char *texname);
void displayLog();
void clearLog();
void printToScreenLog(int forcetoprint, char const *fmt, ...);
void fontTouchTextures();
// End mkproto
#endif
