#ifndef _GROUPNETRECV_H
#define _GROUPNETRECV_H

#include "group.h"
#include "netio.h"

// Generated by mkproto
void demoLoadMap(char *mapname);
void worldReceiveGroups(Packet *pak);
void setClientFlags(GroupDef *def, const char *blameFileName);
bool onIndoorMission(void);
void clientLoadMapStart(char *mapname);
void finishLoadMap(bool tray_link_all, bool do_auto_weld, bool do_demo_fixup);
void receiveDynamicDefChanges(Packet *pak);
// End mkproto

extern char gMapName[256];

#endif