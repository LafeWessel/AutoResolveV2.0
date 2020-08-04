#include "CSVDataReader.h"

CSVDataReader::CSVDataReader()
{
	debug = false;
}

CSVDataReader::CSVDataReader(const bool debugI)
{
	debug = debugI;
}

CSVDataReader::~CSVDataReader()
{
}

//Order of variables in Equipment file :
//1. Type : A(Armor), W(Weapon), T(Trinket), B(Banner), F(Follower) (string / char)
//2. Name(string)
//3. Effect(s) (string)
//4. Coin Value(int)
//5. Index Value(int)
//6. Autoresolve Bonus(int)
//7. Range(int)

vector<Equipment> CSVDataReader::readEquipment(const string path)
{
	if (debug) { cout << "readEquipment() called." << endl; }

	vector<Equipment> readEquip{};
	
	ifstream file(path);
	if (debug) { cout << path <<" tried" << endl; }
	if (!file)
	{
		cerr << path << " file not found" << endl;
		throw invalid_argument(path + " file not found.");
	}
	CSVRow row;
	row.setDebug(debug);
	string theEquipType;
	string theName;
	string theEffect;
	string theCoinValue;
	string theIndexNumber;
	string theAutoBonus;
	string theRange;

	//Reads the equipment file and puts equipment's values in the correct vectors then initializes the treasure
	while (file >> row)
	{
		//if (debug) { cout << "CSVDataReader Starting to read." << endl; }

		theEquipType = row[0];
		theName = row[1];
		theEffect = row[2];
		theCoinValue = row[3];
		theIndexNumber = row[4];
		theAutoBonus = row[5];
		theRange = row[6];

		Equipment inputEquip(theName, stoi(theAutoBonus), stoi(theIndexNumber), stoi(theRange), EnumerationConversions::stringToEquipType(theEquipType), theEffect, stoi(theCoinValue));
		readEquip.push_back(inputEquip);
	}

	return readEquip;
}

//Order of Variables in Units file :
//1. Faction : 1, 2, 3 or 4, follows the enum class defined below(int)
//2. Name(string)
//3. Type : Melee(1), Cavalry(2) or Ranged(3) (int)
//4. Autoresolve Bonus(int)
//5. Soldiers in each unit(int)
//All variables are comma - separated, so there must be no extraneous commas.
vector<Unit> CSVDataReader::readUnits(const faction fact, const string path)
{
		
	//if (debug) { cout << "Faction selected: " << EnumerationConversions::to_string(fact) << endl; }

	ifstream file (path);
	if (debug) { cout << path << " tried" << endl; }
	if (!file)
	{
		cerr << path << " file not found." << endl;
		throw invalid_argument(path + " file not found.");
	}
	vector<Unit> readUnits{};
	CSVRow row;
	row.setDebug(debug);
	string Name;
	string ARBonus;
	string SoldiersPerU;
	faction Faction;
	unitType UnitType;
	Unit unitRead{};
	unitRead.setDebug(debug);

	//Reads the equipment file and puts equipment in the correct vectors then initializes the treasure
	while (file >> row)
	{

		Faction = (faction)(stoi(row[0]));
		UnitType = (unitType)(stoi(row[2]));

		unitRead.setName(row[1]);
		unitRead.setARBonus(stoi(row[3]));
		unitRead.setSoldiersPerUnit(stoi(row[4]));
		unitRead.setCurrentSoldiers(stoi(row[4]));
		unitRead.setFaction(Faction);
		unitRead.setUnitType(UnitType);


		if (unitRead.getFaction() == fact)
		{
			readUnits.push_back(unitRead);
			if (debug) { cout << "factionUnits pushed: " << unitRead.getName() << endl; }
		}
		else
		{
			if (debug) { cout << unitRead.getName() << " was not pushed." << endl; }
		}
	}
	return readUnits;


}

