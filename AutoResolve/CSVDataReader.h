#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include "Equipment.h"
#include "Unit.h"
#include "faction.h"
#include "CSVRow.h"
#include "EnumerationConversions.h"

class CSVDataReader
{
private:
	bool debug;

public:
	CSVDataReader();
	CSVDataReader(bool debugI);
	~CSVDataReader();	
	
	vector<Equipment> readEquipment(const string path);
	vector<Unit> readUnits(const faction fact, const string path);

	void setDebug(const bool debugI) { debug = debugI; };
	bool getDebug() const { return debug; };
};

