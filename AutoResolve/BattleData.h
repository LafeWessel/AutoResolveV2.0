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

class BattleData
{

private:
	
	vector<int> data;
	bool debug;

	vector<string> getUnitNames() const;
	void setAttackerUnitTotals(const vector<Unit> u);
	void setDefenderUnitTotals(const vector<Unit> u);

public:
	BattleData();
	BattleData(const bool debugI);

	void setBattleType(const battleType type);
	void setAttacker(const Player& p);
	void setDefender(const Player& p);
	void setAttackerRandoms(const int rand);
	void setDefenderRandoms(const int rand);
	void setAttackerGeneralState(const int state);
	void setDefenderGeneralState(const int state);
	void setSupplies(const int supp);
	void setOutcome(const outcome o);
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
	void setAttackerEnd(const Player& p);
	void setDefenderEnd(const Player& p);

	void printData() const;
	void writeToFile(const string fileName);
};

