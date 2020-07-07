#include "General.h"

General::~General()
{
}

General::General()
{
	rank = 1;
	AutoResEqBonus = 0;
	armor = Equipment();
	weapon = Equipment();
	trinket = Equipment();
	banner = Equipment();
	follower = Equipment();
	debug = false;
	updateARBonus();
}

General::General(const bool debugI)
{
	rank = 1;
	AutoResEqBonus = 0;
	armor = Equipment();
	weapon = Equipment();
	trinket = Equipment();
	banner = Equipment();
	follower = Equipment();
	this->setDebug(debugI);
	updateARBonus();
}

General::General(const int rankI, const Equipment armorI, const Equipment weaponI, 
	const Equipment trinketI, const Equipment bannerI, const Equipment followerI)
{
	rank = rankI;
	armor = armorI;
	weapon = weaponI;
	trinket = trinketI;
	banner = bannerI;
	follower = followerI;
	debug = false;
	updateARBonus();
}

void General::updateARBonus()
{
	if (debug) { cout << "general updateARBonus called" << endl; }
	AutoResEqBonus = armor.getABonus() + weapon.getABonus() + trinket.getABonus() + banner.getABonus();
}

void General::printData() const
{
	cout << "General printData called" << endl
		<< "General rank: " << rank << endl
		<< "General autoresolve equipment bonus: " << AutoResEqBonus << endl <<
		"General armor: " << endl << armor.to_string() <<
		"General weapon: " << endl << weapon.to_string() <<
		"General trinket: " << endl << trinket.to_string() <<
		"General banner: " << endl << banner.to_string() <<
		"General follower: " << endl << follower.to_string() << endl;
}