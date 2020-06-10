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
	Equipment(bool debugI);
	Equipment(string nameI, int autoBonusI, int numberI, int rangeI, equipmentType EquipTypeI, string effectI, int coinValueI);
	

	const string getName() { 
		if (debug) { cout << "equipment name gotten: " << name << endl; }
		return name; };
	const int getABonus() { 
		if (debug) { cout << "equipment autoresolve bonus gotten: " << autoBonus << endl; }
		return autoBonus; };
	const int getRange() { 
		if (debug) { cout << "equipment range gotten: " << range << endl; }
		return range; };
	const equipmentType getEqType() { 
		if (debug) { cout << "equipment type gotten: " << EnumerationConversions::to_string(EquipType) << endl; }
		return EquipType; };
	const string getEffect() { 
		if (debug) { cout << "equipment effect gotten: " << effect << endl; }
		return effect; };
	const int getCValue() { 
		if (debug) { cout << "equipment coin value gotten: " << coinValue << endl; }
		return coinValue; };
	const int getIndex() {
		if (debug) { cout << "equipment index gotten: " << index << endl; }
		return index;
	};


	void setName(string nameI) { 
		if (debug) { cout << "equipment name set to: " << nameI << endl; }
		name = nameI; };
	void setABonus(int autoBonusI) { 
		if (debug) { cout << "equipment autoresolve bonus set to: " << autoBonusI << endl; }
		autoBonus = autoBonusI; };
	void setRange(int rangeI) { 
		if (debug) { cout << "equipment range set to: " << rangeI << endl; }
		range = rangeI; };
	void setEqType(equipmentType equipTypeI) { 
		if (debug) { cout << "equipment type set to: " << EnumerationConversions::to_string(equipTypeI) << endl; }
		EquipType = equipTypeI; };
	void setEffect(string effectI) { 
		if (debug) { cout << "equipment effect set to: " << effectI << endl; }
		effect = effectI; };
	void setCValue(int CValI) { 
		if (debug) { cout << "equipment coin value set to: " << CValI << endl; }
		coinValue = CValI; };

	const bool getDebug() { return debug; };
	void setDebug(bool debugI) {
		if (debugI) { cout << "equipment setDebug called" << endl; }
		debug = debugI;
	};
	const string printData();
};

