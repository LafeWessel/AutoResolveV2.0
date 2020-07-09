#pragma once
#include "faction.h"
#include "unitType.h"
#include "EnumerationConversions.h"
#include "ValueAssurance.h"
#include <algorithm>
#include <cmath>
#include <string>

class Unit
{
private:
	string name;
	int autoResBonus;
	int soldiersPerUnit;
	int currentSoldiers;
	faction fact;
	unitType type;
	bool debug;

public:
	~Unit();
	Unit();
	Unit(const bool debugI);
	Unit(const string nameI, const int autoResBonusI, const int soldiersPerUnitI, const int currentSoldiersI,
		const faction factI, const unitType typeI);

	 string getName() const{ 
		if (debug) { cout << "unit name gotten: " << name << endl; }
		return name;};
	 int getARBonus() const{ 
		if (debug) { cout << "unit autoresolve bonus gotten: " << autoResBonus << endl; }
		return autoResBonus * (currentSoldiers/soldiersPerUnit); };
	 int getSoldiersPerUnit() const{ 
		if (debug) { cout << "unit number of soldiers per unit gotten: " << soldiersPerUnit << endl; }
		return soldiersPerUnit;};
	 int getCurrentSoldiers() const{
		if (debug) { cout << "unit current soldiers gotten: " << currentSoldiers << endl; }
		return currentSoldiers;};
	 faction getFaction() const{
		if (debug) { cout << "unit faction gotten: " << (int)fact << endl; }
		return fact; };
	 unitType getUnitType() const{
		if (debug) { cout << "unit type gotten: " << (int)type << endl; }
		return type;};

	void setName(const string nameI) { 
		if (debug) { cout << "unit name set to: "<< nameI << endl; }
		name = nameI;};
	void setARBonus(const int ARBonusI) { 
		if (debug) { cout << "unit autoresolve bonus set to: " << ARBonusI << endl; }
		autoResBonus = ARBonusI;};
	void setCurrentSoldiers(const int currentSoldiersI) {
		if (debug) { cout << "unit current soldiers set to: " << currentSoldiersI << endl; }
		ValueAssurance::inputCheck(currentSoldiersI, soldiersPerUnit, 0);
		currentSoldiers = currentSoldiersI;};
	void setSoldiersPerUnit(const int soldiersPerUI) { 
		if (debug) { cout << "unit soldiers per unit set to: " << soldiersPerUI << endl; }
		soldiersPerUnit = soldiersPerUI;};
	void setFaction(const faction factI) { 
		if (debug) { cout << "unit faction set to: " << (int)factI << endl; }
		fact = factI;};
	void setUnitType(const unitType typeI) {
		if (debug) { cout << "unit type set to: " << (int)typeI << endl; }
		type = typeI; };

	void setDebug(const bool debugI) { debug = debugI; };
	 bool getDebug() const{ return debug; };
	 string to_string()const;
};