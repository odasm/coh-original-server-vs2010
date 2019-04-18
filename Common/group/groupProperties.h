#ifndef GROUPPROPERTIES_H
#define GROUPPROPERTIES_H

#include "network\netio.h"
#include "stdio.h"
#include "file.h"

typedef struct StashTableImp *StashTable;
typedef const struct StashTableImp *cStashTable;

typedef enum{
	String,
	Radius,
} PropertyType;

#define PROPERTY_NAME_STRLEN 64
typedef struct PropertyEnt
{
	char name_str[PROPERTY_NAME_STRLEN];
	char *value_str;
	PropertyType type;
} PropertyEnt;

// Generated by mkproto
PropertyEnt* createPropertyEnt();
void destroyPropertyEnt(PropertyEnt* prop);
void copyPropertyEnt(PropertyEnt* source, PropertyEnt* target);
StashTable copyPropertyStashTable(StashTable source, StashTable dest);
PropertyEnt* clonePropertyEnt(PropertyEnt* source);
void WriteGroupPropertiesToPacket(Packet* pak, StashTable properties);
StashTable ReadGroupPropertiesFromPacket(Packet* pak);
void WriteGroupPropertiesToMemSimple(char **filedatap, StashTable properties);
char* WriteGroupPropertiesToString(StashTable properties);
// End mkproto
#endif
