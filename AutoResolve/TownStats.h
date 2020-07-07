#pragma once
#include "defenses.h"
#include "EnumerationConversions.h"
#include <algorithm>
#include <cmath>
#include <iostream>


using namespace std;
class TownStats //Is used in raid and siege battles to keep data on the town
{
private:
	int supplies; //These are used in Raid battles and can be used during campaigns
	defenses townDefense;
	bool debug;

public:
	~TownStats();
	TownStats();
	TownStats(bool debugI);
	TownStats(defenses defenseI);
	void updateStats();

	int getSupplies() const {
		if (debug) { cout << "town stats supplies gotten: " << supplies << endl; }
		return supplies;
	};
	defenses getDefenses() const {
		if (debug) { cout << "town stats defenses gotten: " << (int)townDefense << endl; }
		return townDefense;
	};


	void setSupplies(const int suppliesI) {
		if (debug) { cout << "town stats supplies set to: " << suppliesI << endl; }
		supplies = suppliesI;
	};
	void setDefenses(const defenses defenseI) {
		townDefense = defenseI;
		if (debug) { cout << "town stats defenses set to: " << EnumerationConversions::to_string(defenseI) << endl; }
		updateStats();
	}

	bool getDebug()const { return debug; }
	void setDebug(const bool debugI) { debug = debugI; }
	void printData() const;
};
