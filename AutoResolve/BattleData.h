#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>


#include "battleType.h"
#include "TownStats.h"
#include "outcome.h"
#include "Player.h"
#include "Roster.h"
#include "Unit.h"
#include "EnumerationConversions.h"
#include "ValueAssurance.h"

using std::string;

class BattleData
{

private:
	
	vector<string> data;
	bool debug;
	vector<string> unitNames;
	string unitFilePath;

	void getUnitNames();
	void setAttackerUnitTotals(const vector<Unit> u);
	void setDefenderUnitTotals(const vector<Unit> u);

public:
	BattleData();
	BattleData(const bool debugI);
	BattleData(const string unitFilePath);

	void setBattleType(const battleType type);
	void setAttacker(Player& p);
	void setDefender(Player& p);
	void setAttackerRandoms(const int rand);
	void setDefenderRandoms(const int rand);
	void setAttackerGeneralState(const generalState state);
	void setDefenderGeneralState(const generalState state);
	void setSupplies(const int supp);
	void setOutcome(const outcome o);
	void setEndingTotal(const int end);
	void setAttackerWon(const bool won);
	void setAttackerCasualties(const vector<int> cas);
	void setDefenderCasualties(const vector<int> cas);
	void setAttackerTreasureRec(const bool t);
	void setDefenderTreasureRec(const bool t);
	void setAttackerShips(const int ships);
	void setDefenderShips(const int ships);
	void setAttackerUpgrades(const int up);
	void setDefenderUpgrades(const int up);
	void setRams(const int ram);
	void setSiegeTowers(const int siege);
	void setCatapults(const int cat);
	void setTownStats(const TownStats& ts);
	void setAttackerEnd(Player& p);
	void setDefenderEnd(Player& p);

	void printData() const;
	void writeToFile(const string fileName) const;

	bool getDebug() const { return debug; };
	void setDebug(const bool debug) { this->debug = debug; };
	string getDataAtIndex(const int index) const;
};

