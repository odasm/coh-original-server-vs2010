#ifndef UI_NET
#define UI_NET

#include "stdtypes.h"

#include "net_typedefs.h"
#ifndef POWER_SYSTEM_H__
#include "power_system.h"
#endif
// uiDock
// uiChat
// uiConsole
// uiCompass
// receive mission info from the server
// uiDialog
//uiTeam
typedef struct BasePower BasePower;
typedef struct Power Power;
typedef struct MultiStore MultiStore;
typedef struct Costume Costume;
typedef struct PowerCustomizationList PowerCustomizationList;
typedef struct Entity Entity;
typedef enum SalvageRarity SalvageRarity;
typedef struct Supergroup Supergroup;
typedef struct RoomDetail RoomDetail;
typedef enum TrayItemType TrayItemType;
typedef struct SupergroupRank SupergroupRank;

// uiEmail
// Generated by mkproto

void receiveChatMsg( Packet *pak );
void receiveConsoleOutput( Packet *pak );
void receiveConPrintf( Packet *pak );

void compass_receiveEncounterLocation( Packet *pak );
void compass_receiveTeamLocations( Packet *pak );
void compass_selectTeamLocation( Packet *pak );

void sendDockMode( int mode);
void receiveDockMode( Packet *pak );
void sendInspirationMode( int mode );
void receiveInspirationMode( Packet *pak );
void sendTrayMode( int mode );
void receiveTrayMode( Packet *pak );
void receiveTrayObjAdd( Packet *pak );

void sendChatDivider(float Chat_Divider);
void receiveChatSettings( Packet *pak, Entity *e );
void receivePlaqueDialog( Packet *pak );
void receiveDialog( Packet *pak );
void receiveDialogWithWidth( Packet *pak );
void receiveDialogNag( Packet *pak );
void receiveDialogPowerRequest( Packet *pak );
void receiveDialogIgnorable( Packet *pak );
void receiveTeamChangeDialog( Packet *pak );
void receiveMoralChoice( Packet *pak );
void receivePopHelpN(Packet *pak_in);
void receivePopHelpTag(Packet *pak_in);
void receivePopHelpReset(Packet *pak_in);
void receivePopHelpEventHappenedByTag(Packet *pak);

void receiveTeamOffer(Packet *pak );
void receiveTaskforceQuit(Packet *pak );
void receiveTaskforceKick(Packet *pak );
void receiveLevelingPactInvite(Packet *pak_in);
void receiveServerDialog(Packet *pak_in);
void receiveRewardToken( Packet * pak );
void receiveKarmaStats(Packet *pak);

void receiveAllianceOffer(Packet *pak );

void receiveLeagueOffer(Packet *pak );
void recieveLeagueTeamKick(Packet *pak);
void recieveLeagueERQuit(Packet *pak);

void receiveSuperGroupOffer(Packet *pak );
void receiveSuperResponse(Packet *pak);
void receiveRegisterSupergroup(Packet *pak);
void sgroup_sendCreate(	Supergroup* sg );
void sgroup_requestCostume(void);
void sendTeamAccept(void *data);
void sendTeamDecline(void *data);
void sendLeagueAccept(void *data);
void sendLeagueDecline(void *data);
void sendSuperGroupAccept(void *data);
void sendSuperGroupDecline(void *data);
void sendTeamKick( int db_id );
void sendSupergroupModeToggle();
void receiveTeamList( Packet * pak, Entity *e );
void receiveSuperStats(Packet *pak, Entity *e);
void receiveLeagueList( Packet *pak, Entity *e );
void receiveFriendsList(Packet *pak, Entity *e);
void sendTeamBuffMode( int mode );
void receiveTeamBuffMode( Packet *pak );

void level_buyNewPower(const Power *ppow, PowerSystem ps);
void level_increaseLevel();

void receiveTradeOffer(Packet *pak );
void recieveTradeInit( Packet *pak );
void sendTradeCancel();
void receiveTradeCancel( Packet *pak );
void sendTradeUpdate();
void receiveTradeUpdate( Packet *pak );
void receiveTradeSuccess( Packet *pak );

void spec_sendSetInventory( int fromIdx, int toIdx );
void spec_sendSetPower( int pset, int pow, int fromIdx, int toIdx );
void spec_sendRemove( int idx );
void spec_sendAddSlot( int debug );
void spec_sendRemoveFromPower( int iset, int ipow, int ispec );
void spec_sendUnslotFromPower( int iset, int ipow, int ispec, int invSpot );

void receiveEmailHeaders(Packet *pak);
void receiveEmailMessage(Packet *pak);
void receiveEmailMessageStatus(Packet *pak);

typedef struct Boost Boost;
void combineSpec_send( Boost * a, Boost *b );
void combineSpec_receiveResult( Packet * pak );
void combineBooster_send( Boost * pbA );
void combineSpec_receiveBoosterResult( Packet * pak );
void combineCatalyst_send( Boost * pbA );
void combineSpec_receiveCatalystResult( Packet * pak );


void sendEntityInfoRequest( int svr_id, int primary_tab );
void sendCombatMonitorUpdate(void);
void receiveEntityInfo( Packet *pak );
void receiveClientCombatStats( Packet *pak );
void sendSuperCostume( unsigned int primary, unsigned int secondary, unsigned int primary2, unsigned int secondary2, unsigned int tertiary, unsigned int quaternary, bool hide_emblem );
void sendSuperCostumeData( unsigned int sgColorData[][6], bool hide_emblem, int num_slots);
void receiveSuperCostume(Packet *pak);
void sendHideEmblemChange(int hide);
void receiveHideEmblemChange(Packet *pak);
void requestSGColorData();
void sendTailorTransaction( int genderChange, Costume * costume, PowerCustomizationList *powerCustList );
void sendTailoredPowerCust( PowerCustomizationList *powerCustList);
void receiveTailorOpen( Packet * pak );

typedef struct Character Character;
void sendCharacterRespec( Character *pchar, int patronID );

typedef struct KeyBind KeyBind;
void keybinds_recieve( Packet *pak, char *profile, KeyBind *kbp );
void keybind_send( const char *profile, int key, int mod, int secondary, const char *command );
void keybind_sendReset();
void keybind_sendClear( const char *profile, int key, int mod );
void keyprofile_send( const char *profile );

void sendThirdPerson();
void sendOptions(void *data);
void receiveOptions( Packet *pak );

void sendTitles(int showThe, int commonIdx, int originIdx, int color1, int color2 );
void receiveTitles( Packet * pak );

void sendDescription( char * desc, char * motto);
void receiveDescription( Packet * pak );

void store_SendBuyItem(const MultiStore *pms, int eType, int row, int col);
void store_SendBuySalvage(const MultiStore *ms, int id, int amount);
void store_SendBuyRecipe(const MultiStore *ms, int id, int amount);
void store_SendSellItem(const MultiStore *pms, const char *pchItem);
void storeReceiveOpen(Packet *pak);
void storeReceiveClose(Packet *pak);

void gift_send( int dbid, int type, int ipow, int iset, int ispec, int invIdx );

void receiveSearchResults(Packet *pak);

void receiveRewardChoice(Packet *pak);
void sendRewardChoice( int choice );

void receiveRespecOpen( Packet * pak );
void receiveAuctionOpen( Packet * pak );

void sendDividers(void);
void receiveDividers( Packet * pak );

void receiveArenaResults(Packet *pak);

typedef struct ArenaEvent ArenaEvent;
typedef struct ArenaParticipant ArenaParticipant;
void arenaSendCreateRequest(void);
void arenaSendViewResultRequest( int eventid, int uniqueid );
void arenaSendObserveRequest( int eventid, int uniqueid  );
void arenaSendJoinRequest( int eventid, int uniqueid, int ignore_active );
void arenaSendCreatorUpdate( ArenaEvent * event );
void arenaSendPlayerUpdate( ArenaEvent * event, ArenaParticipant * ap );
void arenaSendFullPlayerUpdate(ArenaEvent *event );
void arenaSendPlayerDrop( ArenaEvent * event, int kicked_dbid );
void receiveArenaInvite(Packet *pak);
void receiveArenaDialog(Packet *pak);
extern int gSentMoTD;

void ScriptUIReceive(Packet * pak);
void ScriptUIReceiveUpdate(Packet * pak);

//void character_InventionSend(Character *p);
void crafting_reverseengineer_send(int inv_idx);
void invent_SendSelectrecipe(int recipeInvIdx, int inventionlevel);
void invent_SendSlotconcept(int slotIdx, int conceptInvIdx);
void invent_SendUnSlot(int slotIdx);
void invent_SendHardenslot(int slotIdx);
void invent_SendHardenslot(int slotIdx);
void invent_SendFinalize();
void invent_SendCancel();

void sendPetCommand( int svr_id, int stance, int action, Vec3 vec );
void sendPetSay( int svr_id, char * msg );
void sendPetRename( int svr_id, char * name );
void receivePetUpdateUI(Packet * pak);
void receiveArenaManagePets(Packet * pak);
void receiveUpdatePetState(Packet * pak);
void receiveBaseInteract(Packet * pak);
void receiveBaseMode(Packet * pak);
void receiveRaidState(Packet * pak);
void arena_ManagePets(void);
void arena_CommitPetChanges(void);

typedef struct DetailRecipe DetailRecipe;
void workshop_SendCreate(const DetailRecipe *pRecipe, int iLevel, int bUseCoupon);
void workshop_SendBuy(const DetailRecipe *pRecipe);
void workshop_SendClose(void);
void baseClientSetPos( float x, float y, float z );
void sendSearchRequest(void);
void updatePlayerName(void *data);
void receiveUpdateName(Packet * pak);
void receivePrestigeUpdate(Packet * pak);
void basestorage_SendSalvageAdjust(int idStorage, const char *name, int amount);
void basestorage_SendInspirationAdjust(int idStorage, int iSet, int iPow, const char *pathInsp, int amount);
void basestorage_SendEnhancementAdjust(int idStorage, const char *pathBasePower, int iLevel, int iNumCombines, int iInv, int amount);

void sendGetSalvageImmediateUseStatus( const char* salvageName );
void receiveSalvageImmediateUseStatus(Packet* pak);

void sendPowerDelete( int iPow );
void sendSalvageDelete( const char * name, int amount, bool is_stored_salvage );
void sendRecipeDelete( const char * name, int amount );
void sendRecipeSell( const char * name, int amount );
void sendSalvageSell( const char * name, int amount );
void sendSalvageOpen( const char * name, int amount );
void receiveSalvageOpenRequest(Packet *pak_in);
void receiveSalvageOpenResults(Packet *pak_in);

void auction_updateAuctionBannedStatus(void);
void auction_updateInventory(void);
void auction_updateHistory(const char * pchIdent);
void auction_addItem(const char * pchIdent, int index, int amt, int price, int status, int id);
void auction_placeItemInInventory(int auction_id);
void auction_changeItemStatus(int auction_id, int price, int status);
void auction_getInfStored(int auction_id);
void auction_getAmtStored(int auction_id);
void auction_batchRequestItemStatus(int startIdx, int reqSize);
void uiAuctionHandleBannedUpdate(Packet *pak);

#include "MissionSearch.h" // enums
void missionserver_game_publishArc(int arcid, char *arcstr);
void missionserver_game_unpublishArc(int arcid);
void missionserver_game_voteForArc(int arcid, MissionRating vote);
void missionserver_game_setKeywordsForArc( int arcid, int votefield );
void missionserver_game_reportArc(int arcid, int type, char *comment);
void missionserver_game_requestSearchPage(MissionSearchPage category, char *context, int page, int playedFilter, int levelFiltered, int arcAuthorId);
void missionserver_game_requestArcInfo(int arcid);
void missionserver_game_requestArcData_playArc(int arcid, int test, int dev_choice);
void missionserver_game_requestArcData_viewArc(int arcid);
void missionserver_game_receiveSearchPage(Packet *pak_in);
void missionserver_game_receiveArcInfo(Packet *pak_in);
void missionserver_game_receiveArcData(Packet *pak_in);
void missionserver_game_receiveArcData_otherUser(Packet *pak_in);
void missionserver_game_comment(int arcid, char * msg);
void receiveArchitectKioskSetOpen(Packet *pak);
void receiveArchitectComplete(Packet *pak);
void receiveArchitectSouvenir(Packet *pak);
void receiveArchitectInventory(Packet *pak);
void requestArchitectInventory(void);

void receiveEditCritterCostume(Packet *pak);
//This is probably not where this should live -- maybe on entplayer?
#define MAX_OF_PET_TYPE 3

typedef struct ArenaPet
{
	char * name;		
	int cost;
	int tokenID;
	int showAsInCurrentlySelectedArmy[MAX_OF_PET_TYPE]; //Just for available
} ArenaPet;

typedef struct ArenaPetManagementInfo
{
	ArenaPet ** availablePets;
	ArenaPet ** currentPets;
} ArenaPetManagementInfo;

extern ArenaPetManagementInfo g_ArenaPetManagementInfo;

void storedsalvage_SendMoveFromPlayerInv(int amt, char *name); // AmountSliderOKCallback
void storedsalvage_SendMoveToPlayerInv(int amt, char *name); // AmountSliderOKCallback

void uiNetGetPlayNCAuthKey(int request_key, char* auth_name, char* digest_data);

void receiveAccountServerClientAuth(Packet *pak);
void receiveAccountServerNotifyRequest(Packet *pak);
void receiveAccountServerInventory(Packet *pak);
void receiveAccountServerPlayNCAuthKey(Packet *pak);

void receiveRenameBuild(Packet *pak);

void receiveRenameResponse(Packet *pak);
void receiveUnlockCharacterResponse(Packet *pak);
void receiveCheckNameResponse(Packet *pak);
void receiveLoginDialogResponse(Packet *pak);

void flashbackListClear(void);
void receiveFlashbackListResponse(Packet *pak);
void receiveFlashbackDetailResponse(Packet *pak);
void receiveFlashbackEligibilityResponse(Packet *pak);
void receiveFlashbackConfirmResponse(Packet *pak);

void receiveTaskforceTimeLimits(Packet *pak);
void levelingpactListUiUpdate();

typedef struct PlayerCreatedStoryArc PlayerCreatedStoryArc;
void sendTestStoryArc(PlayerCreatedStoryArc *pArc);

void receiveAuthBits(Packet *pak);

void sendCostumeChangeEmoteListRequest();

void receiveConfirmSGPromote(Packet *pak);

void srRequestPermissionsSetBit();
void srHandlePermissionsSetBit(Packet *pak);
void srOverridePermissionsSetBit(int value);
int srCanISetPermissions();
int srCanISetThisPermission(SupergroupRank *ranks, int myRank, int permRank, int permIdx);

void auction_listRequestItemStatus(int *idlist);
void receiveGoingRogueNag(Packet *pak);
void receiveIncarnateTrialStatus(Packet *pak);
void receiveChangeWindowColors(Packet *pak);
void receiveCombatMessage(Packet *pak);

void displaySupportHome(Packet *pak);
void displaySupportKB(Packet *pak);

void sendNewFeatureOpenRequest(int id);
void sendNewFeatureVersion(void);
void displayProductPage(Packet *pak);

// End mkproto

#endif

