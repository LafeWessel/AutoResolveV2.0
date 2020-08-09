#include "RaidBattle.h"

RaidBattle::~RaidBattle()
{
}

RaidBattle::RaidBattle() : Battle()
{
	townLevel = TownStats();
	type = battleType::Raid;
	fileName = EnumerationConversions::to_string(type) + "Data.txt";
}

RaidBattle::RaidBattle(const string unitFile) : Battle(unitFile) {
	townLevel = TownStats();
	type = battleType::Raid;
	fileName = EnumerationConversions::to_string(type) + "Data.txt";
}

void RaidBattle::calculate() //combines base Battle calculation with the extras needed for Raid Battles, then calls output
{
	data.setTownStats(townLevel);
	data.setSupplies(townLevel.getSupplies());

	float overallTot = battleCalculate();
	if (debug) { cout << "Overall total returned from battleCalculate RaidBattle::calculateRaid" << endl; }
	overallTot -= (((int)townLevel.getDefenses() * 10) - 10);
	if (debug) { cout << "Overall total - (townLevel(" << EnumerationConversions::to_string(townLevel.getDefenses()) << ") * 10) -10 RaidBattle::calculateRaid" << endl; }

	//Finds outcome and gets casualties
	determineOutcome(overallTot);
	if (debug) { cout << "Outcome returned from determineOutcome:" << (int)result << " RaidBattle::calculateRaid" << endl; }
	vector<vector<int>> totalCasualties = {};
	calculateCas(totalCasualties);
	if (debug) { cout << "CalculateCas called RaidBattle::calculateRaid" << endl; }

	//determines number of supplies gained
	int suppliesGained = townLevel.getSupplies() / (int)result;
	if (debug) { cout << "Supplies gained: " << suppliesGained << "RaidBattle::calculateRaid" << endl; }

	//Outputs results from battle
	battleOutput(totalCasualties, suppliesGained);
	if (debug) { cout << "RaidBattle::calculateRaid finished" << endl; }
	return;
}

void RaidBattle::battleOutput(vector<vector<int>> totalCasualties, int suppGained) //uses base Battle output and adds Raid outputs
{
	if (debug) { cout << "Calling battleOutput, RaidBattle::raidOutput" << endl; }
	Battle::battleOutput(totalCasualties);
	if (output) {
		cout << "Attacker supplies gained: " << suppGained << endl;
	}
	if (debug) { cout << "RaidBattle::raidOutput finished" << endl; }
	return;
}

void RaidBattle::printData() const
{
	cout << "RaidBattle printData called" << endl
		<< "RaidBattle townLevel(townStats): " << endl;
	townLevel.printData();
	Battle::printData();
}