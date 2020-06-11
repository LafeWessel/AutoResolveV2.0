#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "faction.h"
#include "monsterType.h"
#include "equipmentType.h"
#include "outcome.h"
#include "battleType.h"
#include "defenses.h"
#include "unitType.h"

using std::vector;
using std::string;
using std::endl;

/*
This class only contains static functions for converting to and from enumerations from various
data types
TODO possibly implement templates here?
*/
class EnumerationConversions
{
private:


public:
	 static faction intToFaction(int faction);
	 static monsterType intToMonsterType(int monsterType);
	 static unitType intToUnitType(int unitType);

	 static string outputIntAsOutcome(int outcome);

	 static string to_string(const equipmentType e);
	 static string to_string(const outcome o);
	 static string to_string(const faction f);
	 static string to_string(const monsterType m);
	 static string to_string(const defenses d);
	 static string to_string(const battleType b);
	 static string to_string(const unitType u);
	
	 static equipmentType stringToEquipType(const string nameI);
};

