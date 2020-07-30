#pragma once
#include "outcome.h"
#include "Player.h"
#include "Treasure.h"
#include "Equipment.h"
#include "battleType.h"
#include "BattleData.h"
#include "EnumerationConversions.h"
#include "Random.h"
#include <algorithm>
#include <cmath>

#include <array>
#include <vector>
#include <string>
#include <chrono>
#include <random>

#include <iostream>

//using namespace std;



class Battle // siege, raid, normal and naval battles inherit from this class
{

public:
	Treasure *treasure;
	BattleData data;
	Player attacker;
	Player defender;
	outcome result;
	battleType type;
	string fileName;
	Equipment foundByAttacker;
	Equipment foundByDefender;

	bool output;
	bool debug;
	bool fileOut;

public:
	~Battle();
	Battle();
	Battle(const bool debugI);
	Battle(const string unitFile);

	//int randomNumberBattle(int range);
	//int calculateBattleRandoms(int randomRolls, int randomRange);
	//int randomNumberCas(int range);
	//string outputGenState(int state);

	Player getAttacker() const{ return attacker; };
	Player getDefender() const{ return defender; };
	outcome getOutcome() const{ 
		return result; };
	battleType getBattleType() const{ return type; };
	bool getOutput()const { return output; };
	bool getDebug()const { return debug; };
	bool getFileOutBool()const { return fileOut; };
	string getFileName() const { return fileName; };
	Equipment getFoundByAttacker() const { return foundByAttacker; };
	Equipment getFoundByDefender() const { return foundByDefender; };

	void setAttacker(const Player attackerI) { attacker = attackerI;
		attacker.setDebug(debug); };
	void setDefender(const Player defenderI) { defender = defenderI; 
		defender.setDebug(debug); };
	void setOutcome(const outcome resultI) { 
		result = resultI; };
	void setBattleType(const battleType b) { type = b; };
	void setOutput(const bool outputI) { output = outputI; };
	void setFileOut(const bool fileOutI) { fileOut = fileOutI; };
	void setFileName(const string fileName) { this->fileName = fileName; };
	void setDebug(const bool debugI) { 
		debug = debugI;
		if (treasure->isInitialized()) {
			treasure->setDebug(debug);
		}
		attacker.setDebug(debug);
		defender.setDebug(debug);
	};
	void setTreasure(Treasure& treasureI) {
		treasure = &treasureI;
		treasure->setDebug(treasureI.getDebug());
	};

	void printData() const;

	void treasureResults(); //Determines whether or not loot is found at the end of a battle.
	void calculateCas(vector<vector<int>>& totalCasualties); //Determines the amount of casualties at the end of a battle
	void assignCasualties(vector<int>& casualties, Player& p); //assigns casualties to a player
	void battleOutput(vector<vector<int>>& totalCasualties); //Output at end of battle, normally supplemented by other output in inherited classes
	float battleCalculate() const; //Calculates the battle, is almost always supplemented by other calculations in inherited classes
	void determineOutcome(const float endingTotal);
};




