#include "NormalBattle.h"

NormalBattle::~NormalBattle()
{
}

NormalBattle::NormalBattle() : Battle() //void initializer
{
	type = battleType::Normal;
	fileName = EnumerationConversions::to_string(type) + "Data.txt";
}


void NormalBattle::calculate() //Uses base battle calculations and output
{
	if (debug) { cout << "Calling battleCalculate, NormalBattle::calculateNormal" << endl; }
	float overallTot = battleCalculate();
	if (debug) { cout << "Overall total: " << overallTot << " returned from battleCalculate NormalBattle::calculateNormal" << endl; }

	//Finds result and determines casualties
	determineOutcome(overallTot);
	data.setEndingTotal(overallTot);
	if (debug) { cout << "Outcome returned from determineOutcome:" << (int)result << " NormalBattle::calculateNormal" << endl; }
	vector<vector<int>> totalCasualties = {};
	calculateCas(totalCasualties);
	if (debug) { cout << "CalculateCas called NormalBattle::calculateNormal" << endl; }

	if (debug) { cout << "calling NormalOutput NormalBattle::calculateNormal" << endl; }
	battleOutput(totalCasualties);
	if (debug) { cout << "NormalBattle::calculateNormal finished" << endl; }
	return;
}

void NormalBattle::battleOutput(vector<vector<int>> totalCasualties) //Uses base battle output
{
	if (debug) { cout << "Calling battleOutput, NormalBattle::normalOutput" << endl; }
	Battle::battleOutput(totalCasualties);
	if (debug) { cout << "NormalBattle::normalOutput finished" << endl; }
	return;
}

void NormalBattle::printData() const
{
	cout << "NormalBattle printData called" << endl;
	Battle::printData();
}