#ifndef RELAY_TYPES_H
#define RELAY_TYPES_H

#include "net_structdefs.h"
#include "textparser.h"


#define CMDRELAY_PROTOCOL_VERSION 20050504

// status of a relay client
typedef enum CmdRelayCmdStatus
{
	CMDRELAY_CMDSTATUS_READY,
	CMDRELAY_CMDSTATUS_BUSY,
	CMDRELAY_CMDSTATUS_ERROR,
	CMDRELAY_CMDSTATUS_APPLYING_PATCH,
	CMDRELAY_CMDSTATUS_CUSTOM_CMD,
}CmdRelayCmdStatus;


// type of client, used to determine which should start launchers / dbservers, etc
#define RELAY_TYPE_MAPSERVER	(1 << 0)
#define RELAY_TYPE_DBSERVER		(1 << 1)
#define RELAY_TYPE_CUSTOM		(1 << 2)	// runs custom scripts
#define RELAY_TYPE_ARENASERVER  (1 << 3)
#define RELAY_TYPE_LOGSERVER		(1 << 4)
#define RELAY_TYPE_STATSERVER  (1 << 5)
#define RELAY_TYPE_ALL			(RELAY_TYPE_MAPSERVER | RELAY_TYPE_DBSERVER | RELAY_TYPE_CUSTOM | RELAY_TYPE_ARENASERVER | RELAY_TYPE_LOGSERVER | RELAY_TYPE_STATSERVER)


static StaticDefineInt cmdRelayTypeDef[] = {
	DEFINE_INT
	{ "None",			0 },
	{ "ArenaServer",	RELAY_TYPE_ARENASERVER },
	{ "MapServer",		RELAY_TYPE_MAPSERVER },
	{ "DbServer",		RELAY_TYPE_DBSERVER },
	{ "LogServer",		RELAY_TYPE_LOGSERVER },
	{ "StatServer",		RELAY_TYPE_STATSERVER },
	{ "Custom",			RELAY_TYPE_CUSTOM },
	{ "All",			RELAY_TYPE_ALL },
	DEFINE_END
};


// messages sent from server to each cmd relay client
enum
{
	CMDRELAY_REQUEST_UPDATE_SELF = COMM_MAX_CMD,	// make sure these initial 2 are always first, to
	CMDRELAY_REQUEST_PROTOCOL,						// insure that all clients know about these commands!
	CMDRELAY_REQUEST_STATUS,
	CMDRELAY_REQUEST_APPLY_PATCH,
	CMDRELAY_REQUEST_KILL_ALL_MAPSERVER,
	CMDRELAY_REQUEST_KILL_ALL_LAUNCHER,
	CMDRELAY_REQUEST_START_DBSERVER,
	CMDRELAY_REQUEST_START_LAUNCHER,
	CMDRELAY_REQUEST_CUSTOM_CMD,
	CMDRELAY_REQUEST_CANCEL_ALL,
	CMDRELAY_REQUEST_RUN_BATCH_FILE,
	CMDRELAY_REQUEST_START_ALL,
	CMDRELAY_REQUEST_STOP_ALL,
	CMDRELAY_REQUEST_KILL_ALL_ARENASERVER,
	CMDRELAY_REQUEST_KILL_ALL_STATSERVER,
	CMDRELAY_REQUEST_START_ARENASERVER,
	CMDRELAY_REQUEST_START_STATSERVER,
};

// messages sent from command relay to svr mon
enum
{
	CMDRELAY_ANSWER_STATUS = COMM_MAX_CMD,
	CMDRELAY_ANSWER_PROTOCOL,
	CMDRELAY_ANSWER_ACTION_SUCCESS,
	CMDRELAY_ANSWER_ACTION_FAILURE,
};


#endif RELAY_TYPES_H
