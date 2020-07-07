#include "Roster.h"

Roster::~Roster()
{
}
Roster::Roster() //void initializer
{
	factionUnits = {};
	fact = faction::rebel;
	rosterFilePath = "units.txt";
	debug = false;
}

Roster::Roster(bool debugI)
{
	factionUnits = {};
	fact = faction::rebel;
	rosterFilePath = "units.txt";
	this->setDebug(debugI);
}

Roster::Roster(vector<Unit> unitsI, faction factI) //initializer
{
	factionUnits = unitsI;
	fact = factI;
	rosterFilePath = "units.txt";
	debug = false;
}

vector<Unit> Roster::getUnitsOfType(const unitType type) const//gets all of the units of a specific type
{
	if (debug) { cout << "Roster::getUnitsOfType called for unitType: " << 
		EnumerationConversions::to_string(type) << endl; }
	vector<Unit> unitsI = {};
	for (int i = 0; i < factionUnits.size(); i++) 
	{
		if (factionUnits[i].getUnitType() == type) 
		{
			unitsI.push_back(factionUnits[i]);
			if (debug) { cout << "unitsI pushed back: " << factionUnits[i].getName() << endl; }
		}
	}
	if (debug) { cout << "Roster::getUnitsOfType finished" << endl; }
	return unitsI;
}

void Roster::buildRoster() //Reads units in from the 'units' file and adds them to the roster if they match the roster's faction
{
	if (debug) { cout << "roster build roster called" << endl; }
	CSVDataReader reader(debug);
	factionUnits = reader.readUnits(fact, rosterFilePath);
	if (debug) { cout << "units vector size: " << factionUnits.size() << endl; }
	if (factionUnits.size() < 1) { throw invalid_argument("factionUnits not initialized with any elements"); }
	return;
}

void Roster::printData() const
{
	cout << "Roster printData called" << endl
		<< "Roster Faction: " << EnumerationConversions::to_string(fact) << endl;
	for (int i = 0; i < factionUnits.size(); i++) 
	{
		cout << "Roster factionUnits vector at " << i << ":" << endl <<
			factionUnits[i].to_string();
	}
}
