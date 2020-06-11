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

Unit::Unit(const bool debugI) {
	name = "No Name";
	autoResBonus = 1;
	soldiersPerUnit = 1;
	currentSoldiers = 1;
	fact = faction::rebel;
	type = unitType::Melee;
	this->setDebug(debugI);
}

Unit::Unit(const string nameI, const int autoResBonusI, const int soldiersPerUnitI, const int currentSoldiersI,
	const faction factI, const unitType typeI)
{
	name = nameI;
	autoResBonus = autoResBonusI;
	soldiersPerUnit = soldiersPerUnitI;
	currentSoldiers = currentSoldiersI;
	fact = factI;
	type = typeI;
	debug = false;
}

 string Unit::to_string()const
{
	return "Unit printData called\nUnit name: " + name +
		"\nUnit autoresolve bonus: " + std::to_string(autoResBonus) +
		"\nUnit soldiersPerUnit: " + std::to_string(soldiersPerUnit) +
		"\nUnit currentSoldiers: " + std::to_string(currentSoldiers) +
		"\nUnit faction: " + EnumerationConversions::to_string(fact) +
		"\nUnit unitType: " + EnumerationConversions::to_string(type) +"\n";
}