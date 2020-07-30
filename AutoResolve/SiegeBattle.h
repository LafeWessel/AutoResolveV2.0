#pragma once
#include "Battle.h"
#include "TownStats.h"
#include "Player.h"
#include "EnumerationConversions.h"


class SiegeBattle : public Battle
{
private:
	int rams;
	int catapults;
	int siegeTowers;
	TownStats townLevel;
	battleType type = battleType::Siege;

public:

	SiegeBattle();
	SiegeBattle(const bool debugI);
	SiegeBattle(const string unitFile);
	~SiegeBattle();

	void battleOutput(vector<vector<int>> totalCasualties);
	void calculate();

	int getRams() const { 
		return rams; };
	int getCatapults() const {
		return catapults;};
	int getSiegeTowers() const {
		return siegeTowers; };
	TownStats getTownStats() const {
		return townLevel; };

	void setRams(const int ramsI) {
		rams = ramsI; };
	void setCatapults(const int catapultsI) {
		catapults = catapultsI; };
	void setSiegeTowers(const int siegeTowersI) { 
		siegeTowers = siegeTowersI; };
	void setTownStats(const TownStats townLevelI) {
		townLevel = townLevelI;
	};

	void setDebug(const bool debugI) { 
		debug = debugI;
		townLevel.setDebug(debug);
		Battle::setDebug(debugI);
	}
	void printData() const;
};

