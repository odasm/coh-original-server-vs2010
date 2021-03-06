#ifndef _BUILDERIZER_COMM_H_
#define _BUILDERIZER_COMM_H_

#include "net.h"

#define BUILDERIZER_PORT 8907
#define BUILDERIZER_FLAGS (LINK_PACKET_VERIFY | LINK_COMPRESS)

enum 
{
	BUILDCOMM_REQUESTCONFIGS = COMM_MAX_CMD,
	BUILDCOMM_REQUESTSTATUS,
	BUILDCOMM_STARTBUILD,
	BUILDCOMM_STOPBUILD,
	BUILDCOMM_PAUSEBUILD,
	BUILDCOMM_RESUMEBUILD,
	BUILDCOMM_RESTARTBUILD,
	BUILDCOMM_RUNSTEP,
} BuildClientCommands;

enum 
{
	BUILDCOMM_DISCONNECTED = COMM_MAX_CMD,
	BUILDCOMM_SENDCONFIGS,
	BUILDCOMM_SENDSTATUS,
} BuildServerCommands;

// client helper functions
int lostServerLink();
int waitForServerMsg(Packet **pak_p);
void handleNetMsg(Packet *pak,int cmd,NetLink* link,void *user_data);

#endif