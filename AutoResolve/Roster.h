#pragma once
#include "CSVRow.h"
#include "faction.h"
#include "Unit.h"
#include "unitType.h"
#include "CSVDataReader.h"
#include "EnumerationConversions.h"

#include <vector>
#include <string>
#include <iostream>

class Roster
{
private:
	vector<Unit> factionUnits;
	faction fact;
	string rosterFilePath;
	bool debug;

public:
	~Roster();
	Roster();
	Roster(bool debugI);
	Roster(vector<Unit> unitsI, faction factI);

	vector<Unit> getUnitsOfType(const unitType type) const;
	vector<Unit> getUnits() const{ 
		return factionUnits; };
	faction getFaction() const{ 
		return fact; };
	int getNumberOfUnits() const{ 
		return factionUnits.size(); };
	Unit getUnitAtIndex(const int index) const{ 
		return factionUnits[index]; };

	void setUnits(const vector<Unit> unitsI) { 
		factionUnits = unitsI; };
	void setFaction(const faction factI) { 
		fact = factI; };

	bool getDebug() const { return debug; };
	void setDebug(const bool debugI) { 
		debug = debugI; 
		for (int i = 0; i < factionUnits.size(); i++) {
			factionUnits[i].setDebug(debug);
		}
	};
	string getFilePath() const { return rosterFilePath; };
	void setFilePath(const string filePath) { rosterFilePath = filePath; };
	void printData() const;
	void buildRoster();
};

