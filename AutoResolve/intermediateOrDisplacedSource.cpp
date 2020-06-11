
/*

//This outputs the results from a vector of battle results and also some statistics about them
void predictionOutput(vector<int> rawResults)
{
	//This makes a vector and fills it with the number of times an outcome is found in the vector that is passed in
	vector<int> processedResults{ 0,0,0,0,0,0,0 };
	int i = 0;
	while (i < rawResults.size())
	{
		processedResults[rawResults[i] - 1]++;
		i++;
	}

	//Outputs results
	i = 0;
	while (i < processedResults.size())
	{
		cout << "Results Processed at " << i << ": " << processedResults[i] << " : ";
		outputIntAsOutcome(i + 1);
		cout << endl;
		i++;
	}

	//Makes some floats that are used in statistics output below
	float success = (processedResults[0] + processedResults[1] + processedResults[2]);
	float total = 0.0;
	for (int i = 0; i < 7; i++)
	{
		total += processedResults[i];
	}
	//float total = (processedResults[0] + processedResults[1] + processedResults[2] + processedResults[3] + processedResults[4] + processedResults[5] + processedResults[6]);
	float victory = success / total;
	float draw = processedResults[3] / total;
	float loss = (1 - (draw + victory));

	cout << "Percent Victory: " << victory * 100 << endl;
	cout << "Percent Draw: " << draw * 100 << endl;
	cout << "Percent Loss: " << loss * 100 << endl;
	if (loss == 0)
	{
		cout << "Win - loss ratio: " << victory * 100 << endl;
	}
	else
	{
		cout << "Win - loss ratio: " << abs(victory / loss) << endl;
	}
	return;
}

//Creates and fills all the classes needed for a battle. Is called by the battleTestStd functions
void testSetupStd(Battle& battle, bool debug, Treasure& treasure)
{
	if (debug) { cout << "test setup called" << endl; }

	General attackerGen{};
	attackerGen.setArmor(treasure.findArmor());
	attackerGen.setBanner(treasure.findBanner());
	attackerGen.setFollower(treasure.findFollower());
	attackerGen.setTrinket(treasure.findTrinket());
	attackerGen.setWeapon(treasure.findWeapon());
	attackerGen.setRank(10);
	attackerGen.setDebug(debug);
	if (debug) { cout << "General initialized" << endl; }

	faction attFac = faction::beladimir;
	if (debug) { cout << "faction set" << endl; }

	Roster beladimirRoster{};
	beladimirRoster.setDebug(debug);
	beladimirRoster.setFaction(attFac);
	beladimirRoster.buildRoster();
	if (debug) { cout << "Roster built" << endl; }

	int size = beladimirRoster.getNumberOfUnits()-1;
	if (debug) { cout << "size of beladimir roster: " << size << endl; }
	vector<Unit> units{};
	Unit read{};
	int randomIndex;
	for (int i = 0; i < 20; i++)
	{
		randomIndex = randomNumberInt(size);
		if (debug) { cout << "randomIndex generated: " << randomIndex << endl; }
		read = beladimirRoster.getUnitAtIndex(randomIndex);
		read.setDebug(debug);
		if (debug) { cout << "Unit grabbed: " << read.getName() << endl; }
		units.push_back(read);
	}
	if (debug) { cout << "unit vector size: " << units.size() << endl; }
	Player attacker{};
	attacker.setDebug(debug);
	attacker.setFaction(attFac);
	attacker.setGeneral(attackerGen);
	attacker.setAdvCombatDeck(false);
	attacker.setReinforcements(10);
	attacker.setPlayerUnits(units);

	battle.setAttacker(attacker);
	if (debug) { cout << "Battle attacker set to attacker " << endl; }
	battle.setDefender(attacker);
	if (debug) { cout << "Battle defender set to attacker " << endl; }
	return;
}

//These 5 functions create a vector of results from creating and calculating battles with basic information
//that is then sent to predictionOutput()
//They are used for standard, symmetrical battle testing
void battleTestStd(int tests, NormalBattle battle, bool debug, Treasure& treasure, bool fileOut, string filename)
{
	if (debug) { cout << "battleTest - normal called; calling testSetup" << endl; }
	testSetupStd(battle, debug, treasure);
	vector<int> resultsRaw{};

	if (debug) { cout << "tests to do: " << tests << endl; }

	for (int i = 0; i < tests; i++)
	{
		NormalBattle norm = battle;
		norm.setOutput(debug);
		norm.setDebug(debug);
		norm.calculateNormal();
		resultsRaw.push_back((int)norm.getOutcome());
		if (debug) { cout << "ResultsRaw pushed: " << (int)norm.getOutcome() << endl; }
		if (debug) { cout << endl << endl << endl << endl; }
	}
	cout << "Normal Battle results:" << endl;
	predictionOutput(resultsRaw);
	
	return;
}

void battleTestStd(int tests, SiegeBattle battle, bool debug, Treasure& treasure, bool fileOut, string filename)
{
	if (debug) { cout << "battleTest - siege called; calling testSetup" << endl; }
	testSetupStd(battle, debug, treasure);

	battle.setCatapults(5);
	if (debug) { cout << "Catapults set to 5 " << endl; }
	battle.setRams(5);
	if (debug) { cout << "Rams attacker set to 5 " << endl; }
	battle.setSiegeTowers(5);
	if (debug) { cout << "Siege towers attacker set to 5 " << endl; }
	battle.setTownLevel(5);
	if (debug) { cout << "town level set to 5 " << endl; }
	vector<int> resultsRaw{};

	if (debug) { cout << "tests to do: " << tests << endl; }

	for (int i = 0; i < tests; i++)
	{
		SiegeBattle norm = battle;
		norm.setOutput(debug);
		norm.setDebug(debug);
		norm.calculateSiege();
		resultsRaw.push_back((int)norm.getOutcome());
		if (debug) { cout << "ResultsRaw pushed: " << (int)norm.getOutcome() << endl; }
		if (debug) { cout << endl << endl << endl << endl; }
	}
	cout << "Siege Battle results:" << endl;
	predictionOutput(resultsRaw);
	
	return;
}

void battleTestStd(int tests, RaidBattle battle, bool debug, Treasure& treasure, bool fileOut, string filename)
{
	if (debug) { cout << "battleTest - raid called; calling testSetup" << endl; }
	testSetupStd(battle, debug, treasure);
	battle.setTownLevel(5);
	if (debug) { cout << "town level set to 5 " << endl; }
	vector<int> resultsRaw{};

	if (debug) { cout << "tests to do: " << tests << endl; }

	for (int i = 0; i < tests; i++)
	{
		RaidBattle norm = battle;
		norm.setOutput(debug);
		norm.setDebug(debug);
		norm.calculateRaid();
		resultsRaw.push_back((int)norm.getOutcome());
		if (debug) { cout << "ResultsRaw pushed: " << (int)norm.getOutcome() << endl; }
		if (debug) { cout << endl << endl << endl << endl; }
	}
	cout << "Raid Battle results:" << endl;
	predictionOutput(resultsRaw);
	
	return;

}

void battleTestStd(int tests, NavalBattle battle, bool debug, Treasure& treasure, bool fileOut, string filename)
{
	if (debug) { cout << "battleTest - naval called; calling testSetup" << endl; }
	testSetupStd(battle, debug, treasure);
	battle.setAttackerShips(10);
	battle.setDefenderShips(10);
	vector<int> resultsRaw{};

	if (debug) { cout << "tests to do: " << tests << endl; }

	for (int i = 0; i < tests; i++)
	{
		NavalBattle norm = battle;
		norm.setOutput(debug);
		norm.setDebug(debug);
		norm.calculateNaval();
		resultsRaw.push_back((int)norm.getOutcome());
		if (debug) { cout << "ResultsRaw pushed: " << (int)norm.getOutcome() << endl; }
		if (debug) { cout << endl << endl << endl << endl; }
	}
	cout << "Naval Battle results:" << endl;
	predictionOutput(resultsRaw);
	
	return;
}

void battleTestStd(int tests, MonsterBattle battle, bool debug, Treasure& treasure, bool fileOut, string filename)
{
	if (debug) { cout << "battleTest - monster called" << endl; }
	Equipment equip{};
	equip.setDebug(debug);
	equip = treasure.findArmor();
	General attackerGen{ 10,equip,equip,equip,equip,equip };
	attackerGen.setDebug(debug);
	faction attFac = faction::beladimir;
	Roster beladimirRoster{};
	beladimirRoster.setDebug(debug);
	beladimirRoster.setFaction(attFac);
	beladimirRoster.buildRoster();

	int size = beladimirRoster.getNumberOfUnits();
	if (debug) { cout << "size of beladimir roster: " << size << endl; }
	vector<Unit> units{};
	Unit read{};
	int randomIndex;
	for (int i = 1; i < 20; i++)
	{
		randomIndex = randomNumberInt(size - 1);
		if (debug) { cout << "randomIndex generated: " << randomIndex << endl; }
		read = beladimirRoster.getUnitAtIndex(randomIndex);
		if (debug) { cout << "Unit grabbed: " << read.getName() << endl; }
		units.push_back(read);
	}
	Player attacker{};
	attacker.setDebug(debug);
	attacker.setFaction(attFac);
	attacker.setGeneral(attackerGen);
	attacker.setAdvCombatDeck(false);
	attacker.setReinforcements(10);
	attacker.setPlayerUnits(units);

	Monster monster = {};
	monster.setMonsterType(monsterType::Dragon);
	monster.setTreasure(treasure);

	battle.setPlayer(attacker);
	battle.setMonster(monster);
	vector<int> resultsRaw{};

	if (debug) { cout << "tests to do: " << tests << endl; }
	for (int i = 0; i < tests; i++)
	{
		MonsterBattle norm = battle;
		norm.setOutput(debug);
		norm.setDebug(debug);
		norm.calculateMonster();
		resultsRaw.push_back((int)norm.getOutcome());
		if (debug) { cout << "ResultsRaw pushed: " << (int)norm.getOutcome() << endl; }
		if (debug) { cout << endl << endl << endl << endl; }
	}
	cout << "Monster Battle results:" << endl;
	predictionOutput(resultsRaw);
	
	return;
}

//Runs n battle tests with standard, symmetrical values
void standardTests(int tests, bool debug, bool fileOut, string fileName) {

	Treasure treasure{};
	treasure.setDebug(debug);
	treasure.initializeTreasure();

	NormalBattle normal{};
	normal.setTreasure(treasure);
	normal.setDebug(debug);
	if (debug) { cout << "Normal battle initialized void" << endl; }
	battleTestStd(tests, normal, debug, treasure, fileOut, fileName);
	if (debug) { cout << "Tested Normal battle, press Enter to continue" << endl; }
	if (debug) { cin.get(); }

	SiegeBattle siege{};
	siege.setTreasure(treasure);
	siege.setDebug(debug);
	if (debug) { cout << "Siege battle initialized void" << endl; }
	battleTestStd(tests, siege, debug, treasure, fileOut, fileName);
	if (debug) { cout << "Tested Siege battle, press Enter to continue" << endl; }
	if (debug) { cin.get(); }

	RaidBattle raid{};
	raid.setTreasure(treasure);
	raid.setDebug(debug);
	if (debug) { cout << "Raid battle initialized void" << endl; }
	battleTestStd(tests, raid, debug, treasure, fileOut, fileName);
	if (debug) { cout << "Tested Raid battle, press Enter to continue" << endl; }
	if (debug) { cin.get(); }

	NavalBattle naval{};
	naval.setTreasure(treasure);
	naval.setDebug(debug);
	if (debug) { cout << "Naval battle initialized void" << endl; }
	battleTestStd(tests, naval, debug, treasure, fileOut, fileName);
	if (debug) { cout << "Tested Naval battle, press Enter to continue" << endl; }
	if (debug) { cin.get(); }

	MonsterBattle monster = new MonsterBattle(debug);
	monster.getMonster().setTreasure(treasure);
	if (debug) { cout << "Monster battle initialized void" << endl; }
	monster.setDebug(debug);
	if (debug) { cout << "Monster battle treasure set" << endl; }
	battleTestStd(tests, monster, debug, treasure, fileOut, fileName);
	if (debug) { cout << "Tested Monster battle, press Enter to continue" << endl; }
	if (debug) { cin.get(); }

	return;
}

//Creates and fills all the classes needed for a battle in a random, asymmetric way. Called by battleTestRand functions
void testSetupRand(Battle& battle, bool debug, Treasure& treasure) {
	if (debug) { cout << "testSetupRand called" << endl; }

	//Create generals
	General attGen = {};
	attGen.setDebug(debug);
	if (randomNumberInt(1,10) >= 5){attGen.setArmor(treasure.findArmor());}
	if (randomNumberInt(1, 10) >= 5) {attGen.setBanner(treasure.findBanner());}
	if (randomNumberInt(1, 10) >= 5) {attGen.setFollower(treasure.findFollower());}
	if (randomNumberInt(1, 10) >= 5) {attGen.setTrinket(treasure.findTrinket());}
	if (randomNumberInt(1, 10) >= 5) {attGen.setWeapon(treasure.findWeapon());}
	attGen.setRank(randomNumberInt(1,10));

	General defGen = {};
	defGen.setDebug(debug);
	if (randomNumberInt(1, 10) >= 5) {defGen.setArmor(treasure.findArmor());}
	if (randomNumberInt(1, 10) >= 5) {defGen.setBanner(treasure.findBanner());}
	if (randomNumberInt(1, 10) >= 5) {defGen.setFollower(treasure.findFollower());}
	if (randomNumberInt(1, 10) >= 5) {defGen.setTrinket(treasure.findTrinket());}
	if (randomNumberInt(1, 10) >= 5) {defGen.setWeapon(treasure.findWeapon());}
	defGen.setRank(randomNumberInt(1, 10));
	
	//Select factions
	faction attFac = intToFac(randomNumberInt(1, 4));
	faction defFac = intToFac(randomNumberInt(1, 4));

	//Create Rosters
	Roster attRos = {};
	attRos.setDebug(debug);
	attRos.setFaction(attFac);
	attRos.buildRoster();

	Roster defRos = {};
	defRos.setDebug(debug);
	defRos.setFaction(defFac);
	defRos.buildRoster();

	//Fill Rosters
	int attSize = attRos.getNumberOfUnits() - 1;
	int attNumU = randomNumberInt(1, 20);
	vector<Unit> attU = {};
	for (int i = 0; i < attNumU; i++) {
		attU.push_back(attRos.getUnitAtIndex(randomNumberInt(attSize)));
	}

	int defSize = defRos.getNumberOfUnits() - 1;
	int defNumU = randomNumberInt(1, 20);
	vector<Unit> defU = {};
	for (int i = 0; i < defNumU; i++) {
		defU.push_back(defRos.getUnitAtIndex(randomNumberInt(defSize)));
	}

	//Create Players
	Player attacker{};
	attacker.setDebug(debug);
	attacker.setFaction(attFac);
	attacker.setGeneral(attGen);
	attacker.setAdvCombatDeck(randomNumberInt(1));
	attacker.setReinforcements(randomNumberInt(10));
	attacker.setPlayerUnits(attU);

	Player defender{};
	defender.setDebug(debug);
	defender.setFaction(defFac);
	defender.setGeneral(defGen);
	defender.setAdvCombatDeck(randomNumberInt(1));
	defender.setReinforcements(randomNumberInt(10));
	defender.setPlayerUnits(defU);

	//Assign attacker and defender
	battle.setAttacker(attacker);
	battle.setDefender(defender);

}

//Specific case of testSetupRand for MonsterBattle class
void testSetupRand(MonsterBattle& battle, bool debug, Treasure& treasure) {
	if (debug) { cout << "testSetupRand MonsterBattle called" << endl; }
	General attGen = {};
	attGen.setDebug(debug);
	if (randomNumberInt(1, 10) >= 5) { attGen.setArmor(treasure.findArmor()); }
	if (randomNumberInt(1, 10) >= 5) { attGen.setBanner(treasure.findBanner()); }
	if (randomNumberInt(1, 10) >= 5) { attGen.setFollower(treasure.findFollower()); }
	if (randomNumberInt(1, 10) >= 5) { attGen.setTrinket(treasure.findTrinket()); }
	if (randomNumberInt(1, 10) >= 5) { attGen.setWeapon(treasure.findWeapon()); }
	attGen.setRank(randomNumberInt(1, 10));

	faction attFac = intToFac(randomNumberInt(1, 4));

	Roster attRos = {};
	attRos.setDebug(debug);
	attRos.setFaction(attFac);
	attRos.buildRoster();

	int attSize = attRos.getNumberOfUnits() - 1;
	int attNumU = randomNumberInt(1, 20);
	vector<Unit> attU = {};
	for (int i = 0; i < attNumU; i++) {
		attU.push_back(attRos.getUnitAtIndex(randomNumberInt(attSize)));
	}

	Player attacker{};
	attacker.setDebug(debug);
	attacker.setFaction(attFac);
	attacker.setGeneral(attGen);
	attacker.setAdvCombatDeck(randomNumberInt(1));
	attacker.setReinforcements(randomNumberInt(1, 10));
	attacker.setPlayerUnits(attU);

	Monster monster = {};
	monster.setMonsterType(intToMType(randomNumberInt(1, 6)));
	monster.setTreasure(treasure);

	battle.setPlayer(attacker);
	battle.setMonster(monster);
}

//These 5 functions create a vector of results from creating and calculating battles with randomized information
//that is sent to PredictionOutput()
//They are used for asymmetrical, randomized battle testing
void battleTestRand(int tests, NormalBattle battle, bool debug, Treasure& treasure, bool fileOut, string filename) {
	if (debug) { cout << "Normal battleTestRand called" << endl; }

	vector<int> resultsRaw{};

	if (debug) { cout << "tests to do: " << tests << endl; }

	for (int i = 0; i < tests; i++) 
	{
		testSetupRand(battle, debug, treasure);
		NormalBattle norm = battle;
		norm.setOutput(debug);
		norm.setDebug(debug);
		norm.calculateNormal();
		resultsRaw.push_back((int)norm.getOutcome());
		if (debug) { cout << "ResultsRaw pushed: " << (int)norm.getOutcome() << endl; }
		if (debug) { cout << endl << endl << endl << endl; }
	}
	cout << "Normal Battle results:" << endl;
	predictionOutput(resultsRaw);

	return;
}

void battleTestRand(int tests, SiegeBattle battle, bool debug, Treasure& treasure, bool fileOut, string filename) {
	if (debug) { cout << "Siege battleTestRand called" << endl; }


	testSetupRand(battle, debug, treasure);
	battle.setCatapults(randomNumberInt(5));
	battle.setRams(randomNumberInt(5));
	battle.setSiegeTowers(randomNumberInt(5));
	battle.setTownLevel(randomNumberInt(1,5));
	vector<int> resultsRaw{};

	if (debug) { cout << "tests to do: " << tests << endl; }

	for (int i = 0; i < tests; i++)
	{
		testSetupRand(battle, debug, treasure);
		battle.setCatapults(randomNumberInt(5));
		if (debug) { cout << "Catapults set to 5 " << endl; }
		battle.setRams(randomNumberInt(5));
		if (debug) { cout << "Rams attacker set to 5 " << endl; }
		battle.setSiegeTowers(randomNumberInt(5));
		if (debug) { cout << "Siege towers attacker set to 5 " << endl; }
		battle.setTownLevel(randomNumberInt(1, 5));
		if (debug) { cout << "town level set to 5 " << endl; }
		SiegeBattle norm = battle;
		norm.setOutput(debug);
		norm.setDebug(debug);
		norm.calculateSiege();
		resultsRaw.push_back((int)norm.getOutcome());
		if (debug) { cout << "ResultsRaw pushed: " << (int)norm.getOutcome() << endl; }
		if (debug) { cout << endl << endl << endl << endl; }
	}
	cout << "Siege Battle results:" << endl;
	predictionOutput(resultsRaw);
	
	return;
}

void battleTestRand(int tests, RaidBattle battle, bool debug, Treasure& treasure, bool fileOut, string filename) {
	if (debug) { cout << "Raid battleTestRand called" << endl; }
	vector<int> resultsRaw{};

	if (debug) { cout << "tests to do: " << tests << endl; }

	for (int i = 0; i < tests; i++)
	{
		testSetupRand(battle, debug, treasure);
		battle.setTownLevel(randomNumberInt(1, 5));
		RaidBattle norm = battle;
		norm.setOutput(debug);
		norm.setDebug(debug);
		norm.calculateRaid();
		resultsRaw.push_back((int)norm.getOutcome());
		if (debug) { cout << "ResultsRaw pushed: " << (int)norm.getOutcome() << endl; }
		if (debug) { cout << endl << endl << endl << endl; }
	}
	cout << "Raid Battle results:" << endl;
	predictionOutput(resultsRaw);

	return;
}

void battleTestRand(int tests, NavalBattle battle, bool debug, Treasure& treasure, bool fileOut, string filename) {
	if (debug) { cout << "Naval battleTestRand called" << endl; }
	vector<int> resultsRaw{};

	if (debug) { cout << "tests to do: " << tests << endl; }

	for (int i = 0; i < tests; i++)
	{
		testSetupRand(battle, debug, treasure);
		battle.setAttackerShips(randomNumberInt(1, 10));
		battle.setDefenderShips(randomNumberInt(1, 10));
		NavalBattle norm = battle;
		norm.setOutput(debug);
		norm.setDebug(debug);
		norm.calculateNaval();
		resultsRaw.push_back((int)norm.getOutcome());
		
		if (debug) { cout << "ResultsRaw pushed: " << (int)norm.getOutcome() << endl; }
		if (debug) { cout << endl << endl << endl << endl; }
	}
	cout << "Naval Battle results:" << endl;
	predictionOutput(resultsRaw);

	return;
}

void battleTestRand(int tests, MonsterBattle battle, bool debug, Treasure& treasure, bool fileOut, string filename) {
	if (debug) { cout << "Monster battleTestRand called" << endl; }
	vector<int> resultsRaw{};

	if (debug) { cout << "tests to do: " << tests << endl; }

	for (int i = 0; i < tests; i++)
	{
		testSetupRand(battle, debug, treasure);
		MonsterBattle norm = battle;
		norm.setOutput(debug);
		norm.setDebug(debug);
		norm.calculateMonster();
		resultsRaw.push_back((int)norm.getOutcome());
		if (debug) { cout << "ResultsRaw pushed: " << (int)norm.getOutcome() << endl; }
		if (debug) { cout << endl << endl << endl << endl; }
	}
	cout << "Monster Battle results:" << endl;
	predictionOutput(resultsRaw);
	
	return;
}

//Runs numerous battle tests with asymmetric, randomized values
void randomizedTests(int tests, bool debug, bool fileOut, string fileName) {
	
	Treasure treasure{};
	treasure.setDebug(debug);
	treasure.initializeTreasure();

	NormalBattle normal{};
	normal.setTreasure(treasure);
	normal.setDebug(debug);
	if (debug) { cout << "Normal battle initialized void" << endl; }
	battleTestRand(tests, normal, debug, treasure, fileOut, fileName);
	if (debug) { cout << "Tested Normal battle, press Enter to continue" << endl; }
	if (debug) { cin.get(); }

	SiegeBattle siege{};
	siege.setTreasure(treasure);
	siege.setDebug(debug);
	if (debug) { cout << "Siege battle initialized void" << endl; }
	battleTestRand(tests, siege, debug, treasure,  fileOut,  fileName);
	if (debug) { cout << "Tested Siege battle, press Enter to continue" << endl; }
	if (debug) { cin.get(); }

	RaidBattle raid{};
	raid.setTreasure(treasure);
	raid.setDebug(debug);
	if (debug) { cout << "Raid battle initialized void" << endl; }
	battleTestRand(tests, raid, debug, treasure,  fileOut,  fileName);
	if (debug) { cout << "Tested Raid battle, press Enter to continue" << endl; }
	if (debug) { cin.get(); }

	NavalBattle naval{};
	naval.setTreasure(treasure);
	naval.setDebug(debug);
	if (debug) { cout << "Naval battle initialized void" << endl; }
	battleTestRand(tests, naval, debug, treasure,  fileOut,  fileName);
	if (debug) { cout << "Tested Naval battle, press Enter to continue" << endl; }
	if (debug) { cin.get(); }

	MonsterBattle monster{};
	if (debug) { cout << "Monster battle initialized void" << endl; }
	monster.setDebug(debug);
	if (debug) { cout << "Monster battle treasure set" << endl; }
	battleTestRand(tests, monster, debug, treasure,  fileOut,  fileName);
	if (debug) { cout << "Tested Monster battle, press Enter to continue" << endl; }
	if (debug) { cin.get(); }

	return;
}

*/