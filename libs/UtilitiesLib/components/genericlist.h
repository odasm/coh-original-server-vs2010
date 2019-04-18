#ifndef _GENERICLIST_H
#define _GENERICLIST_H

#ifndef _MEMCHECK_H
#include "memcheck.h"
#endif

// Generated by mkproto
void listScrubMember(void * member, int size);
void * listAddForeignMember(void ** headptr, void * newlink);
#define listAddNewMember(headptr, size) listAddNewMember_dbg(headptr, size MEM_DBG_PARMS_INIT)
void * listAddNewMember_dbg(void ** headptr, int size MEM_DBG_PARMS);
void listFreeMember(void * member, void ** headptr);
void listClearList(void ** headptr);
void listDestroyList(void ** headptr, void (*pfnDestroy)(void *pv));
int listCheckList(void * headptr, int count);
void listCopyItem(void * target, void * source, int size);
void listRemoveMember(void * member, void ** headptr);
int listLength(void *headptr);
void listQsort(void ** headptr, int (__cdecl *compare )(const void **, const void **));
int listInList(void *headptr, void *member);
void *listInsertionSort( void *list, int (*compare)(void *, void *) );
// End mkproto
#endif