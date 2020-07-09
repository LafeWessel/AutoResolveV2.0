#pragma once
#include "outcome.h"
#include "Player.h"
#include "Treasure.h"
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

	bool output;
	bool debug;
	bool fileOut;

public:
	~Battle();
	Battle();
	Battle(const bool debugI);
	Battle(const Player attackerI, const Player defenderI);
	Battle(const Player attackerI, const Player defenderI, const bool fileOutI, const string fileNameI);

	//int randomNumberBattle(int range);
	//int calculateBattleRandoms(int randomRolls, int randomRange);
	//int randomNumberCas(int range);
	//string outputGenState(int state);

	Player getAttacker() const{ return attacker; };
	Player getDefender() const{ return defender; };
	outcome getOutcome() const{ if (debug) { cout << "battle outcome gotten: " << EnumerationConversions::to_string(result) << endl; }
		return result; };
	battleType getBattleType() const{ return type; };
	bool getOutput()const { return output; };
	bool getDebug()const { return debug; };
	bool getFileOutBool()const { return fileOut; };
	string getFileName() const { return fileName; };

	void setAttacker(const Player attackerI) { attacker = attackerI;
		attacker.setDebug(debug); };
	void setDefender(const Player defenderI) { defender = defenderI; 
		defender.setDebug(debug); };
	void setOutcome(const outcome resultI) { if (debug) { cout << "battle outcome set to: " << EnumerationConversions::to_string(resultI) << endl; }
		result = resultI; };
	void setBattleType(const battleType b) { type = b; };
	void setOutput(const bool outputI) { output = outputI; };
	void setFileOut(const bool fileOutI) { fileOut = fileOutI; };
	void setFileName(const string fileName) { this->fileName = fileName; };
	void setDebug(const bool debugI) { if (debugI) { cout << "battle setDebug called" << endl; }
		debug = debugI; 
		treasure->setDebug(debug);
		attacker.setDebug(debug);
		defender.setDebug(debug);
	};
	void setTreasure(Treasure& treasureI) {
		treasure = &treasureI;
		treasure->setDebug(treasureI.getDebug());
	};

	void printData() const;

	void treasureResults() const; //Determines whether or not loot is found at the end of a battle.
	void CalculateCas(vector<vector<int>>& totalCasualties); //Determines the amount of casualties at the end of a battle
	void assignCasualties(vector<int>& casualties, int playerType); //assigns casualties to a player
	void battleOutput(vector<vector<int>>& totalCasualties); //Output at battle, normally supplemented by other output in inherited classes
	float battleCalculate(); //Calculates the battle, is almost always supplemented by other calculations in inherited classes
};




