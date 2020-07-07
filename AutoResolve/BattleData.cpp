#include "BattleData.h"

BattleData::BattleData()
{
	//Makes sure the data array is the correct size/length
	data.resize(141);
	fill(data.begin(), data.end(), 0);
	debug = false;
}

BattleData::BattleData(bool debugI)
{
	//Makes sure the data array is the correct size/length
	data.resize(141);
	fill(data.begin(), data.end(), 0);
	debug = debugI;
}

void BattleData::setBattleType(const battleType type) {
	data[0] = (int)type;
}

void BattleData::setAttacker(const Player& p) {
	data[7] = p.getGeneral().getRank();
	data[8] = p.getGeneral().getARBonus();
	data[9] = p.getGeneral().getArmor().getABonus();
	data[10] = p.getGeneral().getWeapon().getABonus();
	data[11] = p.getGeneral().getFollower().getABonus();
	data[12] = p.getGeneral().getBanner().getABonus();
	data[13] = p.getGeneral().getTrinket().getABonus();
	data[14] = p.getAdvComDeck();
	data[15] = p.getMelee() + p.getRanged() + p.getCavalry();
	data[16] = p.getMelee();
	data[17] = p.getRanged();
	data[18] = p.getCavalry();
	data[19] = p.getTotalSoldiers();
	data[63] = p.getNumberOfUnits();
	data[64] = p.getReinforcements();
	setAttackerUnitTotals(p.getPlayerUnits());
}

void BattleData::setDefender(const Player& p) {
	data[75] = p.getGeneral().getRank();
	data[76] = p.getGeneral().getARBonus();
	data[77] = p.getGeneral().getArmor().getABonus();
	data[78] = p.getGeneral().getWeapon().getABonus();
	data[79] = p.getGeneral().getFollower().getABonus();
	data[80] = p.getGeneral().getBanner().getABonus();
	data[81] = p.getGeneral().getTrinket().getABonus();
	data[82] = p.getAdvComDeck();
	data[83] = p.getMelee() + p.getRanged() + p.getCavalry();
	data[84] = p.getMelee();
	data[85] = p.getRanged();
	data[86] = p.getCavalry();
	data[87] = p.getTotalSoldiers();
	data[131] = p.getNumberOfUnits();
	data[132] = p.getReinforcements();
	setDefenderUnitTotals(p.getPlayerUnits());

}

void BattleData::setAttackerRandoms(const int rand) {
	data[1] = rand;
}

void BattleData::setDefenderRandoms(const int rand) {
	data[2] = rand;
}

void BattleData::setAttackerGeneralState(const int state) {
	data[68] = state;
}

void BattleData::setDefenderGeneralState(const int state) {
	data[136] = state;
}

void BattleData::setSupplies(const int supp) {
	data[6] = supp;
}

void BattleData::setOutcome(const outcome o) {
	data[4] = (int)o;
}

void BattleData::setAttackerWon(const bool won) {
	if (won) {
		data[5] = 1;
	}
	else {
		data[5] = 0;
	}
}

void BattleData::setAttackerCasualties(const vector<int> cas) {
	data[67] = cas[0];
	data[66] = cas[1];
}

void BattleData::setDefenderCasualties(const vector<int> cas) {
	data[135] = cas[0];
	data[134] = cas[1];
}

void BattleData::setAttackerTreasureRec(const bool t) {
	if (t) {
		data[69] = 1;
	}
	else {
		data[69] = 0;
	}
}

void BattleData::setDefenderTreasureRec(const bool t) {
	if (t) {
		data[137] = 1;
	}
	else {
		data[137] = 0;
	}
}

void BattleData::setAttackerShips(const int ships) {
	data[71] = ships;
}

void BattleData::setDefenderShips(const int ships) {
	data[139] = ships;
}

void BattleData::setAttackerUpgrades(const int up) {
	data[65] = up;
}

void BattleData::setDefenderUpgrades(const int up) {
	data[133] = up;
}

void BattleData::setRams(const int ram) {
	data[72] = ram;
}

void BattleData::setSiegeTowers(const int siege) {
	data[73] = siege;
}

void BattleData::setCatapults(const int cat) {
	data[74] = cat;
}

void BattleData::setTownStats(const TownStats& ts) {
	data[140] = (int)ts.getDefenses();
}

void BattleData::setAttackerEnd(const Player& p) {
	data[20] = p.getMelee() + p.getRanged() + p.getCavalry();
	data[21] = p.getMelee();
	data[22] = p.getRanged();
	data[23] = p.getCavalry();
	data[24] = p.getTotalSoldiers();
}

void BattleData::setDefenderEnd(const Player& p) {
	data[88] = p.getMelee() + p.getRanged() + p.getCavalry();
	data[89] = p.getMelee();
	data[90] = p.getRanged();
	data[91] = p.getCavalry();
	data[92] = p.getTotalSoldiers();
}

void BattleData::printData() const
{
	for (int i = 0; i < data.size(); i++)
	{
		cout << "i: " << i << " = " << data[i] << endl;
	}
}

void BattleData::writeToFile(const string fileName)
{
	fstream file;
	file.open(fileName);
	if (file) {
		if (debug) { cout << "File successfully opened" << endl; }
		for (int i = 0; i < data.size()-1; i++)
		{
			file << data[i] << ",";
			if (debug) { cout << data[i] << " written to file" << endl; }
		}
		file << data[data.size() - 1] << endl;
	}
	else {
		cerr << "Unable to open file!" << endl;
	}
}


vector<string> BattleData::getUnitNames() const { //Returns a vector of the names of all the units in units.txt
	//Create 4 rosters, one for each faction, then read in their units and add them to the data column
	Roster rebel = Roster();
	rebel.setFaction(faction::rebel);
	rebel.buildRoster();
	Roster beladimir = Roster();
	beladimir.setFaction(faction::beladimir);
	beladimir.buildRoster();
	Roster lerastir = Roster();
	lerastir.setFaction(faction::lerastir);
	lerastir.buildRoster();
	Roster menoriad = Roster();
	menoriad.setFaction(faction::menoriad);
	menoriad.buildRoster();

	vector<string> names = {}; //Will contain the names of all the units available
	for (Unit u : rebel.getUnits()) {
		names.push_back(u.getName());
	}
	for (Unit u : beladimir.getUnits()) {
		names.push_back(u.getName());
	}
	for (Unit u : lerastir.getUnits()) {
		names.push_back(u.getName());
	}
	for (Unit u : menoriad.getUnits()) {
		names.push_back(u.getName());
	}

	return names;
}

//Sets the total number of each kind of unit in the output array for the attacker
void BattleData::setAttackerUnitTotals(vector<Unit> u) {
	vector<string> names = getUnitNames();
	vector<int> totalUnits(names.size());
	for (int i = 0; i < totalUnits.size(); i++) {
		totalUnits[i] = 0;
	}

	//Increments the correct column to count the number of units of a certain type in the vector
	for (int i = 0; i < u.size(); i++) {
		for (int j = 0; j < names.size(); i++) {
			if (u[i].getName() == names[j]) {
				totalUnits[j]++;
			}
		}
	}
	for (int i = 0; i < totalUnits.size(); i++) {
		data[i + 25] = totalUnits[i];
	}

}

//Sets the total number of each kind of unit in the output array for the defender
void BattleData::setDefenderUnitTotals(vector<Unit> u) {
	vector<string> names = getUnitNames();
	vector<int> totalUnits(names.size());
	for (int i = 0; i < totalUnits.size(); i++) {
		totalUnits[i] = 0;
	}

	//Increments the correct column to count the number of units of a certain type in the vector
	for (int i = 0; i < u.size(); i++) {
		for (int j = 0; j < names.size(); i++) {
			if (u[i].getName() == names[j]) {
				totalUnits[j]++;
			}
		}
	}
	for (int i = 0; i < totalUnits.size(); i++) {
		data[i + 93] = totalUnits[i];
	}

}
