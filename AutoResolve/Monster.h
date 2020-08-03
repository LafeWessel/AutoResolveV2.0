#pragma once
#include "Equipment.h"
#include "monsterType.h"
#include "Treasure.h"
#include <algorithm>
#include <cmath>

#include <array>
#include <vector>
#include <string>

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

class Monster //is used in monster battles
{
private:
	Treasure *treasure;
	monsterType type;
	int coinReward;
	int autoResValue; //(int)type*10 + 10
	bool debug;

	void setValuesFromMonsterType();
public:
	~Monster();
	Monster();
	Monster(const bool debugI);
	Monster(const string filePath);
	Monster(monsterType m, Treasure& treasureI);

	int getCoinReward() const{ 
		return coinReward; };
	int getARValue() const{ 
		return autoResValue; };
	monsterType getMonsterType() const{ 
		return type; };

	void setMonsterType(const monsterType monTypeI) { 
		type = monTypeI; 
		setValuesFromMonsterType();}; 
	void setTreasure(Treasure& treasureI) {
		treasure = &treasureI;
		treasure->setDebug(debug);};

	bool getDebug() const{ return debug; }
	void setDebug(const bool debugI) {
		debug = debugI;
		if (treasure->isInitialized()) {
			treasure->setDebug(debug);
		}
	};
	void printData() const;

	
	vector<Equipment> getEquipRewards() const; //This gets the rewards associated with the type of Monster
};