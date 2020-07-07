#include "TownStats.h"

TownStats::~TownStats()
{
}

TownStats::TownStats()
{
	supplies = 0;
	townDefense = defenses::None;
	debug = false;
}

TownStats::TownStats(bool debugI)
{
	supplies = 0;
	townDefense = defenses::None;
	this->setDebug(debugI);
}

TownStats::TownStats(defenses defenseI)
{
	townDefense = defenseI;
	debug = false;
	updateStats();
}

void TownStats::updateStats()
{
	supplies = 4 + (int)townDefense; //this takes the town level and determines the number of supplies it has
}

void TownStats::printData() const
{
	cout << "townStats printData called:" << endl
		<< "townStats Supplies: " << supplies << endl
		<< "townStats Defenses: " << EnumerationConversions::to_string(townDefense) << endl;
}