#pragma once
#include "equipmentType.h"
#include "EnumerationConversions.h"
#include <algorithm>
#include <cmath>

#include <array>
#include <vector>
#include <string>

#include <iostream>

using namespace std;
//This is used for all the equipment that is read in when the a Treasure class has initializeTreasure() is called.
//Used by generals and at the end of battles
class Equipment
{
private:
	string name;
	int autoBonus;
	int index; //unused, maybe remove? will always be read in from the csv
	int range;
	equipmentType EquipType;
	string effect;
	int coinValue;
	bool debug;

public:
	~Equipment();
	Equipment();
	Equipment(const bool debugI);
	Equipment(const string nameI, const int autoBonusI, const int numberI, const int rangeI, 
		const equipmentType EquipTypeI, const string effectI, const int coinValueI);
	

	 string getName() const{ 
		return name; };
	 int getABonus() const{ 
		return autoBonus; };
	 int getRange() const{ 
		return range; };
	 equipmentType getEqType() const{ 
		return EquipType; };
	 string getEffect() const{ 
		return effect; };
	 int getCValue() const{ 
		return coinValue; };
	 int getIndex() const{
		return index;
	};


	void setName(const string nameI) { 
		name = nameI; };
	void setABonus(const int autoBonusI) { 
		autoBonus = autoBonusI; };
	void setRange(const int rangeI) { 
		range = rangeI; };
	void setEqType(const equipmentType equipTypeI) { 
		EquipType = equipTypeI; };
	void setEffect(const string effectI) { 
		effect = effectI; };
	void setCValue(const int CValI) { 
		coinValue = CValI; };
	
	bool getDebug() const{ return debug; };
	void setDebug(const bool debugI) {
		debug = debugI;
	};
	 string to_string()const;
};

