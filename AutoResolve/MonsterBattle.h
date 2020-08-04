#pragma once
#include "Monster.h"
#include "battleType.h"
#include "Battle.h"
#include "Random.h"

class MonsterBattle : public Battle
{
private:
	battleType type = battleType::Monster;
	Monster monster;

public:
	~MonsterBattle();
	MonsterBattle();
	MonsterBattle(const string unitFile);

	void battleOutput(vector<int>& totalCasualties);
	void monsterCasualties(vector<int>& attackerCasVec); //Calculates the casualties, needs only a 1D vector since there is only 1 Player
	void calculate(); //Calculates the outcome and calls Casualty and output functions

	Monster getMonster() const{ 
		return monster; };

	void setMonster(const Monster monsterI) { 
		monster = monsterI;
		monster.setDebug(debug);};
	void setDebug(bool debugI) {
		debug = debugI;
		monster.setDebug(debug);
		Battle::setDebug(debugI);
	};

	void printData() const;
};

