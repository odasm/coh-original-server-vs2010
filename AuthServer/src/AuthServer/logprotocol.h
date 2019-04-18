#pragma once

#define MAX_SHORTCUT_LENGTH 256

enum{
	LOG_FILE_SYSTEM,
	LOG_FILE_IN,
	LOG_FILE_DB,
	LOG_FILE_AUDIT,
	LOG_FILE_ERROR,
	MAX_LOG_FILES
};

enum
{
	RP_LOG_SEND_MSG,
	RP_LOG_CHECK_STATUS,
		// d check type
	RP_CHECK_LOGD,
		// d check result
	RP_LOG_MAX
};

enum
{
	RQ_LOG_SEND_MSG, 
		// d server type
		// d log type
		// S log message
	RQ_SET_CHECK_STATUS,
		// d set option ( 1:set check, 0:unset check)
	RQ_CHECK_LOGD,
		// d check option
	RQ_SERVER_STARTED,
		// d world id
		// d server type (1~4)
	RQ_LOG_MAX
};
// added by darkangel
#define LOG_AUTH_WORLDID			201


/////////////////////////////////////////////
/////////////////////////////////////////////
// NPC catgegory
#define LOG_NPC_ENTER_WORLD			101
#define LOG_NPC_LEAVE_WORLD			102

// PLEDGE Category
#define LOG_PLEDGE_CREATE				201
#define LOG_PLEDGE_JOIN					202
#define LOG_PLEDGE_DISMISS				203
#define LOG_PLEDGE_WITHDRAW				204
#define LOG_PLEDGE_OUST					205
#define LOG_PLEDGE_NICKNAME				206
#define LOG_PLEDGE_BEGIN_PLEDGEWAR		207
#define LOG_PLEDGE_END_PLEDGEWAR		208
#define LOG_PLEDGE_END_PLEDGEWAR2		209
#define LOG_PLEDGE_END_PLEDGEWAR3		210
#define LOG_PLEDGE_CREST				211
#define LOG_PLEDGE_END_PLEDGEWAR4		212
#define LOG_PLEDGE_UPDATE_CASTLE_OWNER	213
#define LOG_PLEDGE_WRITE_TAX			214
#define LOG_PLEDGE_SET_PLEDGE_INFO		215
#define LOG_PLEDGE_DELETE_BY_TIMER		216
#define LOG_PLEDGE_SET_USER_PLEDGE_INFO		217
#define LOG_PLEDGE_CHALLENGE_REJECTED		218
#define LOG_PLEDGE_INSTALL_BATTLECAMP		219
#define LOG_PLEDGE_UNINSTALL_ALLBATTLECAMP	220
#define LOG_PLEDGE_UNINSTALL_BATTLECAMP		221
#define LOG_PLEDGE_SET_NEXT_SIEGETIME		222
#define LOG_PLEDGE_REGISTER_ATTACKER		223
#define LOG_PLEDGE_REGISTER_DEFENDER		224
#define LOG_PLEDGE_UNREGISTER_SIEGE			225
#define LOG_PLEDGE_CONFIRM_SIEGE			226
#define LOG_PLEDGE_RESET_SIEGE				227
#define LOG_PLEDGE_TRY_POSSESS				228
#define LOG_DOOR_HP_CHANGED					229
#define LOG_PLEDGE_CONTRIBUTION				230
#define LOG_WINNERPLEDGE_CONTRIBUTION		231
#define LOG_PLEDGE_OWN_AGIT					232
#define LOG_DOOR_OPENCLOSE					233
#define LOG_CASTLE_INCOME					234
#define LOG_INSTALL_AGIT_DECO				235
#define LOG_TRY_DISMISS_PLEDGE				236

// QUEST Category
#define LOG_QUEST_GET_ITEM			301
#define LOG_QUEST_DEL_ITEM			302
#define LOG_QUEST_BEGIN				303
#define LOG_QUEST_UPDATE			304
#define LOG_QUEST_END				305
#define LOG_QUEST_ONETIME			306
#define LOG_QUEST_STOP				307

// Skill Category
#define LOG_SKILL_AQUIRE			401
#define LOG_SKILL_DELETE			402
#define LOG_SKILL_CAST				403
#define LOG_SOULSHOT				404

// admin Category
#define LOG_ADMIN_DEBUGCHAR			501
#define LOG_ADMIN_SUMMONNPC			502
#define LOG_ADMIN_SUMMONITEM		503
#define LOG_ADMIN_SETPARAM			504
#define LOG_ADMIN_SETSKILL			505
#define LOG_ADMIN_TELBOOKMARK		506
#define LOG_ADMIN_SETONEQUEST		507
#define LOG_ADMIN_SETQUEST			508
#define LOG_ADMIN_KILLME			509
#define LOG_ADMIN_HOME				510
#define LOG_ADMIN_SETAI				511
#define LOG_ADMIN_SETKARMA			512
#define LOG_ADMIN_STOPSAY			513
#define LOG_ADMIN_STOPLOGIN			514
#define LOG_ADMIN_GMLISTON			515
#define LOG_ADMIN_PETITION			517
#define LOG_ADMIN_RECALL			518
#define LOG_ADMIN_TELEPORTTO		519
#define LOG_ADMIN_KICK				520
#define LOG_ADMIN_ANNOUNCE			521
#define LOG_ADMIN_SETANNOUNCE		522
#define LOG_ADMIN_DELANNOUNCE		523
#define LOG_ADMIN_SETBUILDER		524
#define LOG_ADMIN_SUMMON			525
#define LOG_ADMIN_DELSKILL			526
#define LOG_ADMIN_DELQUEST			527
#define LOG_ADMIN_UNREGISTER		528
#define LOG_ADMIN_SETDOORHP			529
#define LOG_ADMIN_SETPLEDGELEV		530
#define LOG_ADMIN_SETSIEGE			531
#define LOG_ADMIN_SETQUICKSIEGE		532
#define LOG_ADMIN_SETCASTLESTATUS	533
#define LOG_ADMIN_DEFEND			534
#define LOG_ADMIN_ATTACK			535
#define LOG_ADMIN_SETCASTLEOWNER	536
#define LOG_ADMIN_SETBP				537
#define LOG_ADMIN_POLY				538

// web admin Category
#define LOG_WEB_CHECKCHAR			601
#define LOG_WEB_CHANGELOC			602
#define LOG_WEB_SETBUILDER			603
#define LOG_WEB_CHANGENAME			604
#define LOG_WEB_KICKCHAR			605
#define LOG_WEB_ADDSKILL			606
#define LOG_WEB_DELSKILL			607
#define LOG_WEB_MODSKILL			608
#define LOG_WEB_ONETIMEQUEST		609
#define LOG_WEB_SETQUEST			610
#define LOG_WEB_DELQUEST			611
#define LOG_WEB_ADDITEM				612
#define LOG_WEB_DELITEM				613
#define LOG_WEB_MODITEM				614
#define LOG_WEB_MODCHAR				615
#define LOG_WEB_MODCHAR2			616
#define LOG_WEB_MODCHARPLEDGE		617
#define LOG_WEB_PUNISHCHAR			618
#define LOG_WEB_BUILDERACCOUNT		619
#define LOG_WEB_DISABLECHAR			620
#define LOG_WEB_ENABLECHAR			621
#define LOG_WEB_GETCHARS			622
#define LOG_WEB_SETBOOKMARK			623
#define LOG_WEB_DELBOOKMARK			624
#define LOG_WEB_SEIZEITEM			625

//	Character Category
#define	LOG_ACCOUNT_AUTHED			801 // ó�� ����
#define	LOG_ACCOUNT_LOGIN			802 // World IN
#define	LOG_CHAR_ENTER_WORLD		803 
#define	LOG_ACCOUNT_LOGOUT			804 // Account logout
#define	LOG_CHAR_LEAVE_WORLD		805
#define	LOG_CHAR_CREATE_CHAR		806
#define	LOG_CHAR_DELETE_CHAR		807
#define	LOG_CHAR_CHANGE_NAME		808
#define LOG_CHAR_CHANGE_LOCATION	809
#define	LOG_CHAR_CHANGE_LEVEL		810
#define LOG_CHAR_TELEPORT			811
#define	LOG_CHAR_SAVE_CHARINFO		812
#define	LOG_CHAR_SAVE_ITEMINFO		813
#define	LOG_CHAR_SAVE_QUEST			814
#define	LOG_CHAR_SAVE_ONETIMEQUEST	815
#define	LOG_CHAR_CHANGE_CLASS		816
#define	LOG_CHAR_CREATE_PARTY		817
#define	LOG_CHAR_JOIN_PARTY			818
#define	LOG_CHAR_DISMISS_PARTY		819
#define	LOG_CHAR_WITHDRAW_PARTY		820
#define	LOG_CHAR_OUST_PARTY			821
#define	LOG_CHAR_STAND				822
#define	LOG_CHAR_SIT				823
#define	LOG_CHAR_EQUIPITEM			824
#define	LOG_CHAR_PCATTACKPC			825
#define	LOG_CHAR_PCATTACKNPC		826
#define	LOG_CHAR_NPCATTACKPC		827
#define	LOG_CHAR_NPCATTACKNPC		828
#define	LOG_CHAR_RESTORE_DELETED	829
#define	LOG_CHAR_CONFIRM_DELETED	830
#define	LOG_ACCOUNT_LOGOUT2			831 // world out

// die Category
#define DIE_PC_DIE					1101
#define DIE_NPC_DIE					1102
#define DIE_PC_KILLPC				1103
#define DIE_PC_KILLNPC				1104
#define DIE_NPC_KILLPC				1105
#define DIE_NPC_KILLNPC				1106
#define DIE_KILL_BY_DUEL			1107
#define DIE_KILL_BY_PK				1108
#define	DIE_RESURRECT				1109
#define DIE_PC_KILLPC2				1111
#define DIE_PC_KILLNPC2				1112
#define DIE_KILL_BY_DUEL2			1113
#define DIE_KILL_BY_PK2				1114
#define	DIE_RESURRECT2				1115
#define	DIE_SUMMONED_KILLPC			1116
#define DIE_HEIGHT_DAMAGE			1117
#define	DIE_RESURRECT_BY			1118

// item Category
#define ITEM_BUY_ITEM				1001
#define ITEM_SELL_ITEM				1002
#define ITEM_DEPOSIT_ITEM			1003
#define ITEM_RETRIEVE_ITEM			1004
#define ITEM_GET_ITEM				1006
#define ITEM_DELETE_ITEM			1007
#define ITEM_DROP_ITEM				1008
#define ITEM_TRADEGIVE_ITEM			1009
#define ITEM_TRADEGET_ITEM			1010
#define ITEM_USE_ITEM				1011
#define ITEM_NPCDROP_ITEM			1012
#define ITEM_NPCSHOWSELL_ITEM		1013
#define ITEM_NPCSHOWBUY_ITEM		1014
#define ITEM_DIE_DROP_ITEM			1015
#define ITEM_TRADE_OK				1016
#define ITEM_TRADE_CANCEL			1017
#define ITEM_TRADE_BEGIN			1018
#define ITEM_ENCHANTITEM			1025
#define ITEM_ENCHANTITEM_FAIL		1026
#define ITEM_DEPOSIT_ITEM_INWARE	1027
#define ITEM_DEPOSIT_ITEM_FEE		1028
#define ITEM_RETRIEVE_ITEM_INWARE	1029
#define ITEM_SETPRIVATE_MSG			1030
#define ITEM_PRIVATESELL_ITEM		1031
#define ITEM_PRIVATEBUY_ITEM		1032
#define ITEM_CRYSTALIZE_ITEM		1033
#define ITEM_RECIPE_DELETE			1034
#define ITEM_RECIPE_CREATE			1035


// server status report category
#define SVR_REPORT_AUTHD_USER		1301
#define SVR_REPORT_SERVER_USER		1302
#define SVR_REPORT_NPC_USER			1303
#define SVR_REPORT_CACHED_USER		1304
#define SVR_REPORT_DEAD				1305
#define SVR_REPORT_START			1306

// audit category
#define AUDIT_ITEMINFO				1401
#define AUDIT_WATCHLIST_NPC			1402
#define AUDIT_WATCHLIST_ITEM		1403
#define AUDIT_WATCHLIST_ITEM2		1404

// updated category
#define UPDATE_SOCKETOPEN			1501
#define UPDATE_SOCKETSEND			1502
#define UPDATE_SOCKETCLOSE			1503

// performance monitor
#define PERF_REPORT_AUTHD			1601
#define PERF_REPORT_CACHED			1602
#define PERF_REPORT_SERVER			1603
#define PERF_REPORT_NPC				1604
#define PERF_REPORT_LOGD			1605


// character category
#define	LOG_F_ACCOUNT_AUTHED		L"%02d/%02d/%04d %02d:%02d:%02d.%03d ,%d,,%d,,,,,,%d.%d.%d.%d,,,%d,%d,%d,%d,%d,,,,,,,%s,,,\r\n"
#define	LOG_F_ACCOUNT_LOGIN			L"%02d/%02d/%04d %02d:%02d:%02d.%03d ,%d,,%d,,,,,,%d.%d.%d.%d,,,%d,%d,%d,%d,%d,,,,,,,%s,,,\r\n"
#define	LOG_F_ACCOUNT_LOGOUT		L"%02d/%02d/%04d %02d:%02d:%02d.%03d ,%d,,%d,,,,,,%d.%d.%d.%d,,,%d,%d,%d,%d,%d,,,,,,,%s,,,\r\n"
#define	LOG_F_ACCOUNT_LOGOUT2		L"%02d/%02d/%04d %02d:%02d:%02d.%03d ,%d,,%d,,,,,,%d.%d.%d.%d,,,%d,%d,%d,,,,,,,,,%s,,,\r\n"


#define	LOG_F_ACCOUNT_AUTHED_1		"%02d/%02d/%04d %02d:%02d:%02d.%03d ,%d,,%d,,,,,,%d.%d.%d.%d,,,%d,%d,%d,%d,%d,,,,,,,%s,,,\r\n"
#define	LOG_F_ACCOUNT_LOGIN_1		"%02d/%02d/%04d %02d:%02d:%02d.%03d ,%d,,%d,,,,,,%d.%d.%d.%d,,,%d,%d,%d,%d,%d,,,,,,,%s,,,\r\n"
#define	LOG_F_ACCOUNT_LOGOUT_1		"%02d/%02d/%04d %02d:%02d:%02d.%03d ,%d,,%d,,,,,,%d.%d.%d.%d,,,%d,%d,%d,%d,%d,,,,,,,%s,,,\r\n"
#define	LOG_F_ACCOUNT_LOGOUT2_1		"%02d/%02d/%04d %02d:%02d:%02d.%03d ,%d,,%d,,,,,,%d.%d.%d.%d,,,%d,%d,%d,,,,,,,,,%s,,,\r\n"
