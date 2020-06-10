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
	const static faction intToFaction(int faction);
	const static monsterType intToMonsterType(int monsterType);
	const static unitType intToUnitType(int unitType);

	const static string outputIntAsOutcome(int outcome);

	const static string to_string(equipmentType e);
	const static string to_string(outcome o);
	const static string to_string(faction f);
	const static string to_string(monsterType m);
	const static string to_string(defenses d);
	const static string to_string(battleType b);
	const static string to_string(unitType u);
	
	const static equipmentType stringToEquipType(string nameI);
};

