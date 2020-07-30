#pragma once
#include "Battle.h"
#include "TownStats.h"
#include "EnumerationConversions.h"


class RaidBattle : public Battle
{
private:
	TownStats townLevel;
	battleType type = battleType::Raid;

public:
	~RaidBattle();
	RaidBattle();
	RaidBattle(bool debugI);
	RaidBattle(const string unitFile);

	void battleOutput(vector<vector<int>> totalCasualties, int suppGained);
	void calculate();

	TownStats getTownStats() const{
		return townLevel; 	};
	
	void setTownStats(const TownStats townLevelI) { 
		townLevel = townLevelI; };

	void setDebug(bool debugI) {
		debug = debugI;
		townLevel.setDebug(debug);
		Battle::setDebug(debugI);
	}
	void printData() const;
};

