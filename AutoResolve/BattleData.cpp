#include "BattleData.h"

BattleData::BattleData()
{
	//Makes sure the data array is the correct size/length
	data.resize(141);
	fill(data.begin(), data.end(), "None");
	debug = false;
	unitFilePath = "units.txt";
}

BattleData::BattleData(const bool debugI)
{
	//Makes sure the data array is the correct size/length
	data.resize(141);
	fill(data.begin(), data.end(),"None");
	debug = debugI;
	unitFilePath = "units.txt";
}

BattleData::BattleData( const string unitFilePathI)
{
	//Makes sure the data array is the correct size/length
	data.resize(141);
	fill(data.begin(), data.end(), "None");
	debug = false;
	unitFilePath = unitFilePathI;
}

//Sets type of battle
void BattleData::setBattleType(const battleType type) {
	data[0] = EnumerationConversions::to_string(type);
}

//Sets values for the attacker at the start of the battle
void BattleData::setAttacker(const Player& p) {
	data[7] = to_string(p.getGeneral().getRank()); //General Rank
	data[8] = to_string(p.getGeneral().getARBonus()); //General AutoResolve Bonus
	data[9] = to_string(p.getGeneral().getArmor().getABonus()); //General Armor Bonus
	data[10] = to_string(p.getGeneral().getWeapon().getABonus()); //General Weapon Bonus
	data[11] = to_string(p.getGeneral().getFollower().getABonus()); //General Follower Bonus
	data[12] = to_string(p.getGeneral().getBanner().getABonus()); //General Banner Bonus
	data[13] = to_string(p.getGeneral().getTrinket().getABonus()); //General Trinket Bonus
	data[14] = to_string((int)p.getAdvComDeck()); //Access to Advanced Combat Deck
	data[15] = to_string(p.getMelee() + p.getRanged() + p.getCavalry()); //Total beginning unit bonus
	data[16] = to_string(p.getMelee()); //Total beginning melee bonus
	data[17] = to_string(p.getRanged()); //Total beginning ranged bonus
	data[18] = to_string(p.getCavalry()); //Total beginning cavalry bonus
	data[19] = to_string(p.getTotalSoldiers()); //Total beginning soldiers

	data[63] = to_string(p.getNumberOfUnits()); //Total beginning units
	data[64] = to_string(p.getReinforcements()); //Total reinforcements
	data[70] = EnumerationConversions::to_string(p.getFaction());
	setAttackerUnitTotals(p.getPlayerUnits());
}

//Sets values for the defender at the start of the battle
void BattleData::setDefender(const Player& p) {
	data[75] = to_string(p.getGeneral().getRank()); //General rank
	data[76] = to_string(p.getGeneral().getARBonus()); //General AutoResolve Bonus
	data[77] = to_string(p.getGeneral().getArmor().getABonus()); //General armor bonus
	data[78] = to_string(p.getGeneral().getWeapon().getABonus()); //General weapon bonus
	data[79] = to_string(p.getGeneral().getFollower().getABonus()); //General follower bonus
	data[80] = to_string(p.getGeneral().getBanner().getABonus()); //General banner bonus
	data[81] = to_string(p.getGeneral().getTrinket().getABonus()); //General trinket bonus
	data[82] = to_string((int)p.getAdvComDeck()); //Access to advanced combat deck
	data[83] = to_string(p.getMelee() + p.getRanged() + p.getCavalry()); //Total beginning unit bonus
	data[84] = to_string(p.getMelee()); //Total beginning melee bonus
	data[85] = to_string(p.getRanged()); //Total beginning ranged bonus
	data[86] = to_string(p.getCavalry()); //Total beginning cavalry bonus
	data[87] = to_string(p.getTotalSoldiers()); //Total beginning soldiers

	data[131] = to_string(p.getNumberOfUnits()); //Total beginning units
	data[132] = to_string(p.getReinforcements()); //Total reinforcements
	data[138] = EnumerationConversions::to_string(p.getFaction());
	setDefenderUnitTotals(p.getPlayerUnits());

}

//Sets the RNG attacker bonus
void BattleData::setAttackerRandoms(const int rand) {
	data[1] = to_string(rand);
}

//Sets the RNG defender bonus
void BattleData::setDefenderRandoms(const int rand) {
	data[2] = to_string(rand);
}

//Set the ending total
void BattleData::setEndingTotal(const int end) {
	data[3] = to_string(end);
}

//Sets general state after battle
void BattleData::setAttackerGeneralState(const generalState state) {
	data[68] = EnumerationConversions::to_string(state);
}

//Sets general state after battle
void BattleData::setDefenderGeneralState(const generalState state) {
	data[136] = EnumerationConversions::to_string(state);
}

//Sets number of supplies
void BattleData::setSupplies(const int supp) {
	data[6] = to_string(supp);
}

//Sets the outcome of the battle
void BattleData::setOutcome(const outcome o) {
	data[4] = EnumerationConversions::to_string(o);
}

//Sets whether the attacker won
void BattleData::setAttackerWon(const bool won) {
	data[5] = to_string((int)won);
}

void BattleData::setAttackerCasualties(const vector<int> cas) {
	data[67] = to_string(cas[0]); //Total soldier casualties
	data[66] = to_string(cas[1]); //Total unit casualties
}

void BattleData::setDefenderCasualties(const vector<int> cas) {
	data[135] = to_string(cas[0]); //Total soldier casualties
	data[134] = to_string(cas[1]); //Total unit casualties
}

//Sets whether the attacker received treasure
void BattleData::setAttackerTreasureRec(const bool t) {
	data[69] = to_string((int)t);
}

//Sets whether the defender received treasure
void BattleData::setDefenderTreasureRec(const bool t) {
	data[137] = to_string((int)t);
}

//Sets the attacker ships
void BattleData::setAttackerShips(const int ships) {
	data[71] = to_string(ships);
}

//Sets the defender ships
void BattleData::setDefenderShips(const int ships) {
	data[139] = to_string(ships);
}

//Sets attacker upgrades
void BattleData::setAttackerUpgrades(const int up) {
	data[65] = to_string(up);
}

//Sets defender upgrades
void BattleData::setDefenderUpgrades(const int up) {
	data[133] = to_string(up);
}

//Sets attacker rams
void BattleData::setRams(const int ram) {
	data[72] = to_string(ram);
}

//Sets attacker siege towers
void BattleData::setSiegeTowers(const int siege) {
	data[73] = to_string(siege);
}

//Sets attacker catapults
void BattleData::setCatapults(const int cat) {
	data[74] = to_string(cat);
}

//Sets town stats
void BattleData::setTownStats(const TownStats& ts) {
	data[140] = EnumerationConversions::to_string(ts.getDefenses());
}

//Sets attacker ending values
void BattleData::setAttackerEnd(const Player& p) {
	data[20] = to_string(p.getMelee() + p.getRanged() + p.getCavalry()); //Total ending unit bonus
	data[21] = to_string(p.getMelee()); //Total ending melee bonus
	data[22] = to_string(p.getRanged()); //Total ending ranged bonus
	data[23] = to_string(p.getCavalry()); //Total ending cavalry bonus
	data[24] = to_string(p.getTotalSoldiers()); //Total ending soldiers
}

//Sets defender ending values
void BattleData::setDefenderEnd(const Player& p) {
	data[88] = to_string(p.getMelee() + p.getRanged() + p.getCavalry()); //Total ending unit bonus
	data[89] = to_string(p.getMelee()); //Total ending melee bonus
	data[90] = to_string(p.getRanged()); //Total ending ranged bonus
	data[91] = to_string(p.getCavalry()); //Total ending cavalry bonus
	data[92] = to_string(p.getTotalSoldiers()); //Total ending soldiers
}

//Prints the data from the data vector
void BattleData::printData() const
{
	for (int i = 0; i < data.size(); i++)
	{
		cout << "i: " << i << " = " << data[i] << endl;
	}
}

//Writes the data to a given file
void BattleData::writeToFile(const string fileName) const
{
	if (debug) { cout << endl << "Attempting to write to file: " << fileName << endl; }
	fstream file;
	file.open(fileName, ios::app);

	while (!file) {
		//Wait for file to be opened
	}


	if (file) {
		if (debug) { cout << "File successfully opened" << endl; }

		string out = "";
		for (int i = 0; i < data.size(); i++)
		{
			for (char c : data[i]) {
				file.write(&c, 1);
			}
			if (i < data.size() - 1) {
				file.write(",", 1);
			}
			
		}
		file.write("\n",1);

		
		file.close();
	}
	else {
		cerr << "Unable to open file: " << fileName << endl;
	}
}

string BattleData::getDataAtIndex(const int index) const
{
	ValueAssurance::inputCheck(index, data.size() - 1, 0);
	return data[index];
}

//Returns a vector of the names of all the units in units.txt
void BattleData::getUnitNames()  { 

	unitNames = {};

	//Create 4 rosters, one for each faction, then read in their units and add them to the data column
	Roster rebel = Roster();
	rebel.setFaction(faction::rebel);
	rebel.setFilePath(unitFilePath);
	rebel.buildRoster();
	Roster beladimir = Roster();
	beladimir.setFaction(faction::beladimir);
	beladimir.setFilePath(unitFilePath);
	beladimir.buildRoster();
	Roster lerastir = Roster();
	lerastir.setFaction(faction::lerastir);
	lerastir.setFilePath(unitFilePath);
	lerastir.buildRoster();
	Roster menoriad = Roster();
	menoriad.setFaction(faction::menoriad);
	menoriad.setFilePath(unitFilePath);
	menoriad.buildRoster();

	for (Unit u : rebel.getUnits()) {
		unitNames.push_back(u.getName());
	}
	for (Unit u : beladimir.getUnits()) {
		unitNames.push_back(u.getName());
	}
	for (Unit u : lerastir.getUnits()) {
		unitNames.push_back(u.getName());
	}
	for (Unit u : menoriad.getUnits()) {
		unitNames.push_back(u.getName());
	}
}

//Sets the total number of each kind of unit in the output array for the attacker
void BattleData::setAttackerUnitTotals(vector<Unit> u) {
	getUnitNames();
	vector<int> totalUnits;
	totalUnits.resize(unitNames.size());
	fill(totalUnits.begin(), totalUnits.end(), 0);

	//Increments the correct column to count the number of units of a certain type in the vector
	for (int i = 0; i < u.size(); i++) {
		for (int j = 0; j < unitNames.size(); j++) {
			if (u[i].getName() == unitNames[j]) {
				totalUnits[j]++;
			}
		}
	}
	//Assign values to the correct locations in the data vector
	for (int i = 0; i < totalUnits.size(); i++) {
		data[i + 25] = to_string(totalUnits[i]);
	}

}

//Sets the total number of each kind of unit in the output array for the defender
void BattleData::setDefenderUnitTotals(vector<Unit> u) {
	getUnitNames();
	vector<int> totalUnits;
	totalUnits.resize(unitNames.size());
	fill(totalUnits.begin(), totalUnits.end(), 0);

	//Increments the correct column to count the number of units of a certain type in the vector
	for (int i = 0; i < u.size(); i++) {
		for (int j = 0; j < unitNames.size(); j++) {
			if (u[i].getName() == unitNames[j]) {
				totalUnits[j]++;
			}
		}
	}
	//Assign values to the correct locations in the data vector
	for (int i = 0; i < totalUnits.size(); i++) {
		data[i + 93] = to_string(totalUnits[i]);
	}

}
