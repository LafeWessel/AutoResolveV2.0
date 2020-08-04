#include "Treasure.h"

Treasure::~Treasure()
{
}

Treasure::Treasure()
{
	armor = {};
	weapon = {};
	trinket = {};
	banner = {};
	follower = {};
	dragon = {};
	debug = false;
	initialized = false;
	equipmentFilePath = "equipment.txt";
}

Treasure::Treasure(bool debugI) {
	armor = {};
	weapon = {};
	trinket = {};
	banner = {};
	follower = {};
	dragon = {};
	initialized = false;
	this->setDebug(debugI);
	equipmentFilePath = "equipment.txt";
}

Treasure::Treasure(vector<Equipment> armorI, vector<Equipment> weaponI, vector<Equipment> trinketI,
	vector<Equipment> bannerI, vector<Equipment> followerI, vector<Equipment> dragonI, bool debugI)
{
	armor = armorI;
	weapon = weaponI;
	trinket = trinketI;
	banner = bannerI;
	follower = followerI;
	dragon = dragonI;
	debug = debugI;
	initialized = false;
	equipmentFilePath = "equipment.txt";
}

/*
Returns a random Armor
*/
 Equipment Treasure::findArmor()const
{
	if (debug) { cout << "armor size: " << banner.size() << endl; }
	int selection = Random::randomNumberArray(armor.size());
	if (debug) { cout << "selection: " << selection << endl; }
	return armor[selection];
}

/*
Returns a random Banner
*/
 Equipment Treasure::findBanner()const
{
	if (debug) { cout << "banner size: " << banner.size() << endl; }
	int selection = Random::randomNumberArray(banner.size());
	if (debug) { cout << "selection: " << selection << endl; }
	return banner[selection];
}

/*
Returns a random Follower
*/
 Equipment Treasure::findFollower()const
{
	if (debug) { cout << "follower size: " << follower.size() << endl; }
	int selection = Random::randomNumberArray(follower.size());
	if (debug) { cout << "selection: " << selection << endl; }
	return follower[selection];
}

/*
Returns a random Dragon equipment
*/
 Equipment Treasure::findDragonEq()const
{
	if (debug) { cout << "dragon size: " << dragon.size() << endl; }
	int selection = Random::randomNumberArray(dragon.size());
	if (debug) { cout << "selection: " << selection << endl; }
	return dragon[selection];
}

/*
Returns a random Trinket
*/
 Equipment Treasure::findTrinket()const
{
	if (debug) { cout << "trinket size: " << trinket.size() << endl; }
	int selection = Random::randomNumberArray(trinket.size());
	if (debug) { cout << "selection: " << selection << endl; }
	return trinket[selection];
}

/*
Returns a random Weapon
*/
 Equipment Treasure::findWeapon()const
{
	if (debug) { cout << "weapon size: " << weapon.size() << endl; }
	int selection = Random::randomNumberArray(weapon.size());
	if (debug) { cout << "selection: " << selection << endl; }
	return weapon[selection];
}

/*
Initializes CSVDataReader class and reads in equipment before sorting it
*/
void Treasure::initialize()
{
	if (debug) { cout << "initializeTreasure() called." << endl; }

	CSVDataReader reader(debug);
	if (debug) { cout << "CSVDataReader initialized" << endl; }

	vector<Equipment> allEquipment = reader.readEquipment(equipmentFilePath);
	if (debug) { cout << "All equipment read" << endl; }

	sortEquipment(allEquipment);
	if (debug) { cout << " intitializeTreasure() finished" << endl; }

	initialized = true;
	return;
}

/*
Returns an Equipment object if a random int in range 1-8 + bonus is >= 5 
*/
 Equipment Treasure::findTreasure(const int bonus)const
{
	if (debug) { cout << " findTreasure() called" << endl; }
	int total = Random::randomNumber(1,8) + bonus;
	//if (debug) { cout << "random + bonus = " << total << endl; }
	if ( total >= 5)
	{
		switch (Random::randomNumber(1,5))
		{
		case(1):
			//if (debug) { cout << " findArmor() returned" << endl; }
			return this->findArmor();
			break;
		case(2):
			//if (debug) { cout << " findWeapon() returned" << endl; }
			return this->findWeapon();
			break;
		case(3):
			//if (debug) { cout << " findTrinket() returned" << endl; }
			return this->findTrinket();
			break;
		case(4):
			//if (debug) { cout << " findBanner() returned" << endl; }
			return this->findBanner();
			break;
		case(5):
			//if (debug) { cout << " findFollower() returned" << endl; }
			return this->findFollower();
			break;
		default:
			cerr << "No type selected" << endl;
			return this->noTreasure();
		}
	}
	else
	{
		if (debug) { cout << " noTreasure() returned" << endl; }
		return this->noTreasure();
	}
	//if (debug) { cout << " findTreasure() finished" << endl; }
}

/*
Sorts equipment in passed vector into appropriate equipment type vectors
*/
void Treasure::sortEquipment(vector<Equipment> toSort)
{
	if (debug) { cout << "sortEquipment called" << endl; }
	for (int i = 0; i < toSort.size(); i++)
	{
		switch (toSort[i].getEqType())
		{
		case (equipmentType::armor):
			armor.push_back(toSort[i]);
			break;
		case (equipmentType::weapon):
			weapon.push_back(toSort[i]);
			break;
		case (equipmentType::trinket):
			trinket.push_back(toSort[i]);
			break;
		case (equipmentType::banner):
			banner.push_back(toSort[i]);
			break;
		case (equipmentType::follower):
			follower.push_back(toSort[i]);
			break;
		case (equipmentType::dragon):
			dragon.push_back(toSort[i]);
			break;
		default:
			cerr << "no armor type found, " << endl;
			break;
		}
	}
}

void Treasure::setDebug(bool debugI) {
	if (debugI) { cout << "treasure setDebug called" << endl; }
	debug = debugI;

	if (initialized) {
		for (Equipment e : armor){
			e.setDebug(debug);
		}
		for (Equipment e : weapon) {
			e.setDebug(debug);
		}
		for (Equipment e : trinket) {
			e.setDebug(debug);
		}
		for (Equipment e : banner) {
			e.setDebug(debug);
		}
		for (Equipment e : follower) {
			e.setDebug(debug);
		}
		for (Equipment e : dragon) {
			e.setDebug(debug);
		}
	}

	if (debug) { cout << "treasure setDebug finished, total" << endl; }
}

/*
Prints all the equipment in a vector of equipment
*/
 void Treasure::printEquipmentVector(const vector<Equipment>& equipVector, const string name) const
{
	for (int i = 0; i < equipVector.size(); i++)
	{
		cout << "Treasure " << name << " vector at " << i << ":" << endl;
		cout << equipVector[i].to_string() << endl;
	}
}

/*
Prints the equipments in the Treasure class
*/
 void Treasure::printData()const
{
	cout << "Treasure printData called" << endl;
	printEquipmentVector(armor, "armor");
	printEquipmentVector(weapon, "weapon");
	printEquipmentVector(banner, "banner");
	printEquipmentVector(trinket, "trinket");
	printEquipmentVector(follower, "follower");
	printEquipmentVector(dragon, "dragon");
}

