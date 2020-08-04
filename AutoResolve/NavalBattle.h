#pragma once
#include "Battle.h"

class NavalBattle : public Battle
{
private:
	int attackerShips;
	int defenderShips;
	battleType type = battleType::Naval;

public:
	~NavalBattle();
	NavalBattle();
	NavalBattle(const string unitFile);

	void battleOutput(vector<vector<int>> totalCasualties);
	void calculate();

	int getAttackerShips() const { 
		return attackerShips; };
	int getDefenderShips() const {
		return defenderShips; };

	void setAttackerShips(const int attShipsI) { 
		attackerShips = attShipsI; };
	void setDefenderShips(const int defShipsI) { 
		defenderShips = defShipsI; };

	void printData() const;
};

