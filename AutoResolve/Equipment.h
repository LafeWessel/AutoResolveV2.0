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
		if (debug) { cout << "equipment name gotten: " << name << endl; }
		return name; };
	 int getABonus() const{ 
		if (debug) { cout << "equipment autoresolve bonus gotten: " << autoBonus << endl; }
		return autoBonus; };
	 int getRange() const{ 
		if (debug) { cout << "equipment range gotten: " << range << endl; }
		return range; };
	 equipmentType getEqType() const{ 
		if (debug) { cout << "equipment type gotten: " << EnumerationConversions::to_string(EquipType) << endl; }
		return EquipType; };
	 string getEffect() const{ 
		if (debug) { cout << "equipment effect gotten: " << effect << endl; }
		return effect; };
	 int getCValue() const{ 
		if (debug) { cout << "equipment coin value gotten: " << coinValue << endl; }
		return coinValue; };
	 int getIndex() const{
		if (debug) { cout << "equipment index gotten: " << index << endl; }
		return index;
	};


	void setName(const string nameI) { 
		if (debug) { cout << "equipment name set to: " << nameI << endl; }
		name = nameI; };
	void setABonus(const int autoBonusI) { 
		if (debug) { cout << "equipment autoresolve bonus set to: " << autoBonusI << endl; }
		autoBonus = autoBonusI; };
	void setRange(const int rangeI) { 
		if (debug) { cout << "equipment range set to: " << rangeI << endl; }
		range = rangeI; };
	void setEqType(const equipmentType equipTypeI) { 
		if (debug) { cout << "equipment type set to: " << EnumerationConversions::to_string(equipTypeI) << endl; }
		EquipType = equipTypeI; };
	void setEffect(const string effectI) { 
		if (debug) { cout << "equipment effect set to: " << effectI << endl; }
		effect = effectI; };
	void setCValue(const int CValI) { 
		if (debug) { cout << "equipment coin value set to: " << CValI << endl; }
		coinValue = CValI; };

	 bool getDebug() const{ return debug; };
	void setDebug(const bool debugI) {
		if (debugI) { cout << "equipment setDebug called" << endl; }
		debug = debugI;
	};
	 string to_string()const;
};

