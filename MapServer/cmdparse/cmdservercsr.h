#ifndef _CMDSERVERCSR_H
#define _CMDSERVERCSR_H

typedef struct ClientLink ClientLink;

// Generated by mkproto
Entity *findEntOrRelayOfflineById(ClientLink *admin,int db_id,char *orig_cmd, int *result);
Entity *findEntOrRelayById(ClientLink *admin,int db_id,char *orig_cmd, int *result);
// Passing a pointer to "result" will cause it to synchronously do the operation and give feedback if the entity isn't online
Entity *findEntOrRelay(ClientLink *admin,char *player_name,char *orig_cmd, int *result);
int relayCommandStart(ClientLink *admin, int db_id, char *orig_cmd, Entity** ep, int* online);
void relayCommandEnd(Entity** ep, int* online);
void sendToServer(int map_id, char* msg); // must be called with "cmdrelay\n" at start of msg
void sendToAllServers(char *msg); // must be called with "cmdrelay\n" at start of msg
void sendToAllGroupMembers(int db_id, int group_type, char *msg); // must be called with "cmdrelay\n" at start of msg
void spawnVillain(char* spawnParams, ClientLink* client, int count);
int  spawnVillainMob(int count, int min_level, int max_level, ClientLink* client);
void spawnPet(char* spawnParams, ClientLink* client, int count);
void spawnNPC(char* spawnParams, ClientLink* client, int count);
void spawn(char* spawnParams, ClientLink* client, int count);
void csrBanChat(char *player_name,char *orig_cmd,int min, int admin_auth_id, int admin_db_id);
void csrKick(ClientLink *admin,char *player_name,char *orig_cmd,char *reason,int ban);
void csrBan(ClientLink *admin,char *player_name,char *orig_cmd,char *reason);
void csrUnban(ClientLink *admin,char *player_name,char *orig_cmd);
void csrInvincible(ClientLink *client,int invincible_state);
void csrUnstoppable(ClientLink *client,int unstoppable_state);
void csrAlwaysHit(ClientLink *client,int alwayshit_state);
void csrDoNotTriggerSpawns(ClientLink *client,int donottriggerspawns_state);
void csrUntargetable(ClientLink *client,int untargetable_state);
void csrPvPSwitch(ClientLink *client, int pvpswitch_state);
void csrPvPActive(ClientLink *client, int pvpactive_state);
void csrServerWho(ClientLink *client,int status_server_id);
void csrWho(ClientLink *client,char *player_name);
void csrWhoAll(ClientLink *client);
void csrSupergroupWho(ClientLink *client,char *group_name);
void csrGroupWho(ClientLink *client, char *whocmd, int group_id);
void csrCsr(ClientLink *admin, int effective_accesslevel, int return_dbid, char *player_name, char *cmd, char *orig_cmd);
void csrCsrOffline(ClientLink *admin, int effective_accesslevel, int return_dbid, int target_dbid, char *cmd, char *orig_cmd);
int csrRadius(ClientLink *admin, float radius, char *cmd);
int csrMap(ClientLink *admin, char *cmd);

// End mkproto
char * csrPlayerInfo(char ** estr, ClientLink * client, char *player_name, int detailed);
char * csrPlayerTrayInfo(char ** estr, ClientLink * client, char *player_name);
char * csrPlayerSpecializationInfo(char ** estr, ClientLink * client, char * player_name);
char * csrPlayerTeamInfo(char ** estr, ClientLink * client, char *player_name);
void csrPetition(Entity *e,char *msg);

void csrPowersCashInEnhancements(ClientLink *client);
void csrPowersReset(ClientLink *client, const char *pchPrimary, const char *pchFirst, const char *pchSecondary);
void csrPowersBuyDev(ClientLink *client, char *pchCat, char *pchSet, char *pchPow);
void csrPowersBuy(ClientLink *client, char *pchCat, char *pchSet, char *pchPow);
void csrPowersBuySet(ClientLink *client, char *pchCat, char *pchSet);
void csrPowersCheck(ClientLink *client);
void csrPowersDebug(ClientLink *client, char *pchCat, char *pchSet, char *pchPow);

void csrBadgesShow(ClientLink *client, int all);
void csrBadgeGrantAll(Entity *e);
void csrBadgeRevokeAll(Entity *e);
void csrBadgeStatsShow(ClientLink *client, char *pchStat);

void csrPowerInfo(ClientLink *client);
void csrPowerInfoBuild(ClientLink *client, int build);
void csrPowerChangeLevelBought(ClientLink *client, char *pchCat, char *pchSet, char *pchPow, int iNewLevel);

void csrCritterList( ClientLink *client );
void csrNextCritterById( ClientLink *client, int id );
void csrNextCritterByName( ClientLink *client, char *name );
void csrAuthKick( ClientLink *client, char *player_name );
void csrNextArchVillain( ClientLink *client );
void csrListen( ClientLink *client, char * player_name );

void csrEditDescription( Entity * e, char * str );
void csrDestroyBase( int db_id, int sg_id );
void csrJoinSupergroup( Entity *e, int super_id );
void csrPowersAutoEnhance( Entity *e, int useIO );
void csrPowersMaxSlots( Entity *e );

void csrPrintDbFlags( ClientLink *client, Entity *e );
void csrSetDbFlag( ClientLink *client, Entity *e, char * flag_name, int flag_val );

void csrClearMARTYHistory(ClientLink *admin, char *player_name, char *orig_cmd, char *reason);
void csrPrintMARTYHistory(ClientLink *admin, char *player_name, char *orig_cmd);
#endif
