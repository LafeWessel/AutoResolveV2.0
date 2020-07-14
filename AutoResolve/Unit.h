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
		return name;};
	 int getARBonus() const{ 
		return autoResBonus * (currentSoldiers/soldiersPerUnit); };
	 int getSoldiersPerUnit() const{ 
		return soldiersPerUnit;};
	 int getCurrentSoldiers() const{
		return currentSoldiers;};
	 faction getFaction() const{
		return fact; };
	 unitType getUnitType() const{
		return type;};

	void setName(const string nameI) { 
		name = nameI;};
	void setARBonus(const int ARBonusI) { 
		autoResBonus = ARBonusI;};
	void setCurrentSoldiers(const int currentSoldiersI) {
		ValueAssurance::inputCheck(currentSoldiersI, soldiersPerUnit, 0);
		currentSoldiers = currentSoldiersI;};
	void setSoldiersPerUnit(const int soldiersPerUI) { 
		soldiersPerUnit = soldiersPerUI;};
	void setFaction(const faction factI) { 
		fact = factI;};
	void setUnitType(const unitType typeI) {
		type = typeI; };

	void setDebug(const bool debugI) { debug = debugI; };
	 bool getDebug() const{ return debug; };
	 string to_string()const;
};