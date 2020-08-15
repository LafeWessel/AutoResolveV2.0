#include "TestBattle.h"

TestBattle::~TestBattle() {

}

TestBattle::TestBattle() {
	debug = false;
	numberOfTests = 0;
	type = battleType::Normal;
	outputFile = "";
	treasure = nullptr;
	setFileString();
}

void TestBattle::initializeAndRun() {
	if (debug) { cout << "initializeAndRun called" << endl; }
	vector<int> outcomes{0,0,0,0,0,0,0};
	for (int i = 0; i < numberOfTests; i++) {

		runTest(outcomes);
		cout << "Test " << i+1 << " run" << endl;
	}

	//Output results
	cout << "\n\n\nTest results: " << endl <<
		"Number of tests: " << numberOfTests << endl <<
		"Output file: " << outputFile << endl <<
		"Battle type: " << EnumerationConversions::to_string(type) << endl <<
		"Decisive Victories: " << outcomes[0] << endl <<
		"Heroic Victories: " << outcomes[1] << endl <<
		"Close Victories: " << outcomes[2] << endl <<
		"Draws: " << outcomes[3] << endl <<
		"Close Defeats: " << outcomes[4] << endl <<
		"Valiant Defeats: " << outcomes[5] << endl <<
		"Decisive Defeats: " << outcomes[6] << endl << endl;

	float total = 0.0;
	for (int i : outcomes) {
		total += i;
	}
	
	cout << "Victory Percentage: " << ((outcomes[0] + outcomes[1] + outcomes[2]) / total) * 100 << endl;

}

void TestBattle::runTest(vector<int>& outcomes) {
	if (debug) { cout << "runTest called, type:" << EnumerationConversions::to_string(type) << endl; }
	
	//Finish initialization of each battle class within these cases
	switch (type) {

	case battleType::Normal:
	{
		NormalBattle b{};
		b.setFileOut(outputToFile);
		b.setTreasure(treasure);
		b.setDebug(debug);
		b.setOutput(debug);
		b.setFileOut(outputToFile);
		
		initBattle(b);

		b.calculate();
		outcomes[(int)b.getOutcome() - 1]++;
		break;
	}
	case battleType::Siege:
	{
		SiegeBattle b{};
		b.setFileOut(outputToFile);
		b.setTreasure(treasure);
		b.setDebug(debug);
		b.setOutput(debug);
		b.setFileOut(outputToFile);
		
		initBattle(b);

		b.setRams(Random::randomNumber(0, 5));
		b.setSiegeTowers(Random::randomNumber(0, 5));
		b.setCatapults(Random::randomNumber(0, 5));
		TownStats t{};
		t.setDefenses((defenses)(Random::randomNumber(1, 5)));
		b.setTownStats(t);

		b.calculate();
		outcomes[(int)b.getOutcome() - 1]++;

		break;
	}
	case battleType::Raid:
	{
		RaidBattle b{};
		b.setFileOut(outputToFile);
		b.setTreasure(treasure);
		b.setDebug(debug);
		b.setOutput(debug);
		b.setFileOut(outputToFile);

		initBattle(b);


		TownStats t{};
		t.setDefenses((defenses)(Random::randomNumber(1, 5)));
		b.setTownStats(t);

		b.calculate();
		outcomes[(int)b.getOutcome() - 1]++;
		break;
	}
	case battleType::Naval:
	{
		NavalBattle b{};
		b.setFileOut(outputToFile);
		b.setTreasure(treasure);
		b.setDebug(debug);
		b.setOutput(debug);
		b.setFileOut(outputToFile);

		initBattle(b);

		b.setAttackerShips(Random::randomNumber(1, 10));
		b.setDefenderShips(Random::randomNumber(1, 10));

		b.calculate();
		outcomes[(int)b.getOutcome() - 1]++;
		break;
	}
	case battleType::Monster:
	{
		MonsterBattle b{};
		b.setFileOut(outputToFile);
		b.setTreasure(treasure);
		b.setDebug(debug);
		b.setOutput(debug);
		b.setFileOut(outputToFile);

		initBattle(b);

		Monster m{};
		int mon = Random::randomNumber(1, 6);
		monsterType type = (monsterType)mon;
		m.setMonsterType(type);
		m.setTreasure(b.getTreasure());

		b.setMonster(m);
		b.calculate();
		outcomes[(int)b.getOutcome() - 1]++;
		break;
	}
	default:
		cerr << "Unknown battleType: " << (int)type << endl;
	}
}

/*
Initializes the basic data types in the Battle parent class
*/
void TestBattle::initBattle(Battle& b)
{
	if (debug) { cout << "initBattle called" << endl; }
	Player att{};
	Player def{};
	
	initPlayer(att, b.getTreasure());
	initPlayer(def, b.getTreasure());
		
	b.setAttacker(att);
	b.setDefender(def);

}

/*
Initializes random values for a Player
*/
void TestBattle::initPlayer(Player& p, const Treasure* t) {
	if (debug) { cout << "initPlayer called" << endl; }
	General g{};
	g.setRank(Random::randomNumber(1, 10));
	g.setDebug(debug);
	if (Random::randomNumber(1, 10) >= 5) { g.setArmor(t->findArmor()); }
	if (Random::randomNumber(1, 10) >= 5) { g.setBanner(t->findBanner()); }
	if (Random::randomNumber(1, 10) >= 5) { g.setFollower(t->findFollower()); }
	if (Random::randomNumber(1, 10) >= 5) { g.setTrinket(t->findTrinket()); }
	if (Random::randomNumber(1, 10) >= 5) { g.setWeapon(t->findWeapon()); }
	p.setGeneral(g);

	if (Random::randomNumber(0, 1) > 0) { p.setAdvCombatDeck(true); }

	p.setFaction((faction)(Random::randomNumber(1, 4)));
	p.setReinforcements(Random::randomNumber(0, 5));

	int numUnits = Random::randomNumber(1, 20);
	Roster r{};
	r.setFaction(p.getFaction());
	r.buildRoster();

	vector<Unit> v = {};
	for (int i = 0; i < numUnits; i++) {
		v.push_back(r.getUnitAtIndex(Random::randomNumber(0, r.getNumberOfUnits() - 1)));
	}
	p.setPlayerUnits(v);

}

void TestBattle::setFileString() {
	outputFile = EnumerationConversions::to_string(type) + "Data.txt";
}




