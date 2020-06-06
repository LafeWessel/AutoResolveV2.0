#pragma once
#include <iostream>

#include "faction.h"
#include "monsterType.h"

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
	const static string outputIntAsOutcome(int outcome);
};

