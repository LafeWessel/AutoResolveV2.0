#include "Unit.h"

Unit::~Unit()
{
}

Unit::Unit()
{
	name = "No Name";
	autoResBonus = 1;
	soldiersPerUnit = 1;
	currentSoldiers = 1;
	fact = faction::rebel;
	type = unitType::Melee;
	debug = false;
}

Unit::Unit(bool debugI) {
	name = "No Name";
	autoResBonus = 1;
	soldiersPerUnit = 1;
	currentSoldiers = 1;
	fact = faction::rebel;
	type = unitType::Melee;
	this->setDebug(debugI);
}

Unit::Unit(string nameI, int autoResBonusI, int soldiersPerUnitI, int currentSoldiersI, faction factI, unitType typeI)
{
	name = nameI;
	autoResBonus = autoResBonusI;
	soldiersPerUnit = soldiersPerUnitI;
	currentSoldiers = currentSoldiersI;
	fact = factI;
	type = typeI;
	debug = false;
}

const string Unit::printData()
{
	return "Unit printData called\nUnit name: " + name +
		"\nUnit autoresolve bonus: " + to_string(autoResBonus) +
		"\nUnit soldiersPerUnit: " + to_string(soldiersPerUnit) +
		"\nUnit currentSoldiers: " + to_string(currentSoldiers) +
		"\nUnit faction: " + EnumerationConversions::to_string(fact) +
		"\nUnit unitType: " + EnumerationConversions::to_string(type) +"\n";
}