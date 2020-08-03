#include "NavalBattle.h"

NavalBattle::~NavalBattle()
{
}


NavalBattle::NavalBattle() : Battle()//void initializer
{
	attackerShips = 0;
	defenderShips = 0;
}

NavalBattle::NavalBattle(bool debugI) : Battle(debugI)
{
	attackerShips = 0;
	defenderShips = 0;
}

NavalBattle::NavalBattle(const string unitFile) : Battle(unitFile) {
	attackerShips = 0;
	defenderShips = 0;
}

void NavalBattle::battleOutput(vector<vector<int>> totalCasualties) //uses base Battle output and adds naval outputs
{
	if (debug) { cout << "Calling battleOutput, NavalBattle::NavalOutput" << endl; }

	Battle::battleOutput(totalCasualties);
	if (output) {
		cout << "Attacker Ship Cas: " << totalCasualties[0][totalCasualties[0].size() - 1] << endl;
		cout << "Defender Ship Cas " << totalCasualties[1][totalCasualties[1].size() - 1] << endl;
	}
	if (debug) { cout << "NavalBattle::navalOutput finished" << endl; }
	return;
}

void NavalBattle::calculate() //combines base Battle calculation with the extras needed for Naval Battles, then calls output
{
	if (debug) { cout << "Calling battleCalculate, NavalBattle::calculateNaval" << endl; }
	//Uses base calculations and adds Naval Battle calculations
	float overallTot = battleCalculate();
	if (debug) { cout << "Overall total returned from battleCalculate NavalBattle::calculateNaval" << endl; }
	overallTot += attackerShips * 3;
	if (debug) { cout << "Overall total + attacker ships(" << attackerShips << ")*3 NavalBattle::calculateNaval" << endl; }
	overallTot -= defenderShips * 3;
	if (debug) { cout << "Overall total defender ships(" << defenderShips << ")*3 NavalBattle::calculateNaval" << endl; }

	//Gets the outcome and calculates the casualties
	determineOutcome(overallTot);
	if (debug) { cout << "Outcome returned from determineOutcome:" << (int)result << " NavalBattle::calculateNaval" << endl; }
	vector<vector<int>> totalCasualties = {};
	calculateCas(totalCasualties);
	if (debug) { cout << "CalculateCas called NavalBattle::calculateNaval" << endl; }

	//Ensure that ship casualties are only assigned to ships if there are unit casualties
	if (totalCasualties[0][1] > 0) {
		totalCasualties[0].push_back(totalCasualties[0][1] - 1);
		attackerShips -= totalCasualties[0][totalCasualties[0].size()-1];
	}
	if (totalCasualties[1][1] > 0) {
		totalCasualties[1].push_back(totalCasualties[1][1] - 1);
		attackerShips -= totalCasualties[1][totalCasualties[1].size() - 1];
	}

	//Calls output function
	battleOutput(totalCasualties);
	if (debug) { cout << "NavalBattle::calculateNaval finished" << endl; }
	return;
}

void NavalBattle::printData() const
{
	cout << "NavalBattle printData called" << endl
		<< "NavalBattle attacker ships: " << attackerShips << endl
		<< "NavalBattle defender ships: " << defenderShips << endl;
	Battle::printData();
}

