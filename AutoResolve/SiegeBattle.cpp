#include "SiegeBattle.h"

SiegeBattle::~SiegeBattle()
{
}

SiegeBattle::SiegeBattle() : Battle()//void initializer
{
	rams = 0;
	catapults = 0;
	siegeTowers = 0;
	townLevel = TownStats();
	Battle::type = battleType::Siege;
}


SiegeBattle::SiegeBattle(const string unitFile) : Battle(unitFile) {
	rams = 0;
	catapults = 0;
	siegeTowers = 0;
	townLevel = TownStats();
	Battle::type = battleType::Siege;
}

void SiegeBattle::calculate() //combines base Battle calculation with the extras needed for Siege Battles, then calls output
{
	float overallTot = battleCalculate();
	if (debug) { cout << "Overall total returned from battleCalculate SiegeBattle::calculateSiege" << endl; }

	data.setRams(rams);
	data.setSiegeTowers(siegeTowers);
	data.setCatapults(catapults);
	data.setTownStats(townLevel);
	data.setSupplies(townLevel.getSupplies());

	//Siege Battle-specific calculations
	overallTot -= ((int)townLevel.getDefenses() * 10) - 10;
	if (debug) { cout << "Overall total - (townLevel(" << EnumerationConversions::to_string(townLevel.getDefenses()) << ") * 10) -10 SiegeBattle::calculateSiege" << endl; }
	overallTot += rams * 2;
	if (debug) { cout << "Overall total + rams(" << rams << ")*2 SiegeBattle::calculateSiege" << endl; }
	overallTot += catapults * 3;
	if (debug) { cout << "Overall total + catapults(" << catapults << ") * 3 SiegeBattle::calculateSiege" << endl; }
	overallTot += siegeTowers * 4;
	if (debug) { cout << "Overall total + siegeTowers(" << siegeTowers << ") * 4 SiegeBattle::calculateSiege" << endl; }

	//Determines the outcome and calculates the casualties
	determineOutcome(overallTot);
	if (debug) { cout << "Outcome returned from determineOutcome:" << (int)result << " SiegeBattle::calculateSiege" << endl; }
	vector<vector<int>> totalCasualties = {};
	calculateCas(totalCasualties);
	if (debug) { cout << "CalculateCas called SiegeBattle::calculateSiege" << endl; }

	battleOutput(totalCasualties);
	if (debug) { cout << "SiegeBattle::calculateSiege finished" << endl; }
}

void SiegeBattle::battleOutput(vector<vector<int>> totalCasualties) //uses base Battle output and adds Siege outputs
{
	if (debug) { cout << "Calling battleOutput, SiegeBattle::SiegeOutput" << endl; }
	Battle::battleOutput(totalCasualties);

	if (output){
		if ((int)result < 4) {
			cout << "The settlement was taken by the attackers." << endl;
			cout << "The defending army/garrison has been completely destroyed." << endl;
		}
		else {
			cout << "The settlement was successfully held by the defenders." << endl;
		}
	}
	if (debug) { cout << "SiegeBattle::SiegeOutput finished" << endl; }
	return;
}

void SiegeBattle::printData() const
{
	cout << "SiegeBattle printData called" << endl
		<< "SiegeBattle rams: " << rams << endl
		<< "SiegeBattle catapults: " << catapults << endl
		<< "SeigeBattle siege towers: " << siegeTowers << endl
		<< "SiegeBattle townLevel(townStats): " << endl;
	townLevel.printData();
	Battle::printData();
}