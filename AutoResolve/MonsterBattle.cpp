#include "MonsterBattle.h"

MonsterBattle::~MonsterBattle()
{
}

MonsterBattle::MonsterBattle() : Battle()
{
	monster = Monster();
	type = battleType::Monster;
	fileName = EnumerationConversions::to_string(type) + "Data.txt";
}


MonsterBattle::MonsterBattle(const string unitFile) : Battle(unitFile) {
	monster = Monster();
	type = battleType::Monster;
	fileName = EnumerationConversions::to_string(type) + "Data.txt";
}

void MonsterBattle::battleOutput(vector<int>& totalCasualties) //Outputs information at the end of the Monster battle
{
	if (debug) { cout << "Calling battleOutput, MonsterBattle::monsterOutput" << endl; }
	if (output)
	{
		cout << (int)result << endl
			<< "Attacker Soldier Cas: " << totalCasualties[0] << endl
			<< "Attacker Unit Cas: " << totalCasualties[1] << endl
			<< "Attacker General is " << EnumerationConversions::to_string(attacker.getGeneral().getState()) << endl;
		if ((int)result < 4)
		{
			cout << "Coins gained: " << monster.getCoinReward() << endl;
		}
	}

	if (fileOut) {
		if (debug) { cout << "writing to file: " << fileName << endl; }
		data.shorten();
		data.writeToFile(fileName);
		if (debug) { cout << "Out of writing to file" << endl; }
	}


	if (debug) { cout << "MonsterBattle::monsterOutput finished" << endl; }
	return;
}

void MonsterBattle::monsterCasualties(vector<int>& attackerCasVec) //Calculates the casualties
{

	int attSoldierCasualties = 0;
	int attSoldierTotal = attacker.getCavalry() + attacker.getMelee() + attacker.getRanged();
	if (debug) { cout << "Attacking soldier total:" << attSoldierTotal << " MonsterBattle::monsterCasualties" << endl; }
	//Calculates the soldier and unit casualties
	attSoldierCasualties = Random::randomNumberGroup(((int)result + 1), 1, attSoldierTotal / 10);
	if (debug) { cout << "Attacking soldier casualties:" << attSoldierCasualties << " MonsterBattle::monsterCasualties" << endl; }
	int attUnitCasualties = attSoldierCasualties / 7;
	if (attSoldierCasualties < 0){
		attSoldierCasualties = 0;
	}
	if (debug) { cout << "Attacking unit casualties:" << attUnitCasualties << " MonsterBattle::monsterCasualties" << endl; }

	//Determines if the general is wounded or killed
	if (Random::randomNumber(10) < 2){
		attacker.getGeneral().setState(generalState::Wounded);
		if (debug) { cout << "attacker General state set to Wounded Battle::CalculateCas" << endl; }
		if (Random::randomNumber(10) < 2){
			attacker.getGeneral().setState(generalState::Slain);
			if (debug) { cout << "attacker General state set to Slain Battle::CalculateCas" << endl; }
		}
	}
	else { if (debug) { cout << "attacker General unharmed" << endl; } }
	data.setAttackerGeneralState(attacker.getGeneral().getState());

	attackerCasVec = { attSoldierCasualties, attUnitCasualties};
	assignCasualties(attackerCasVec, attacker);

	data.setAttackerCasualties(attackerCasVec);

	if (debug) { cout << "MonsterBattle::monsterCasualties finished" << endl; }
	return;
}

void MonsterBattle::calculate()
{
	//Comparing these at the end will determine victory/draw/defeat in relation to the attacker
	//The monTotal is subtracted from the attTotal, thus a positive result is a victory for the attacker,
	//and the opposite for a negative result
	float attTotal = 0;
	float monTotal = 0;

	data.setAttacker(attacker);
	data.setBattleType(type);
	data.setMonster(monster);

	//Adds units + portions of reinforcements
	attTotal += attacker.getCavalry() + attacker.getMelee() + attacker.getRanged();
	if (debug) { cout << "attacker unit sum:" << attTotal << " MonsterBattle::calculateMonster" << endl; }


	//Adds random values to randomize the battle outcome more
	int attRand = Random::randomNumberGroup(10, 1, 10);
	attTotal += attRand;
	data.setAttackerRandoms(attRand);
	if (debug) { cout << "attacker sum with randoms:" << attTotal << " MonsterBattle::calculateMonster" << endl; }
	int monRand = Random::randomNumberGroup(10, 1, 10);
	monTotal += monRand;
	data.setDefenderRandoms(monRand);
	if (debug) { cout << "monster sum with randoms:" << monTotal << " MonsterBattle::calculateMonster" << endl; }

	//Adds rank and autoresolve bonuses from general and monster
	attTotal += attacker.getGeneral().getRank();
	if (debug) { cout << "attacker sum with general: " << attTotal << " MonsterBattle::calculateMonster" << endl; }
	attTotal += attacker.getGeneral().getARBonus();
	if (debug) { cout << "attacker sum with general autobonus: " << attTotal << " MonsterBattle::calculateMonster" << endl; }
	monTotal += monster.getARValue();
	if (debug) { cout << "monster sum with monster autobonus: " << monTotal << " MonsterBattle::calculateMonster" << endl; }

	//Determines outcome and casualties then calls output function
	determineOutcome(attTotal - monTotal);
	data.setEndingTotal(attTotal - monTotal);
	if (debug) { cout << "Outcome returned from determineOutcome:" << (int)result << " MonsterBattle::calculateMonster" << endl; }
	vector<int> casualty{};
	monsterCasualties(casualty);
	if (debug) { cout << "monsterCasualties called MonsterBattle::calculateMonster" << endl; }
	data.setAttackerEnd(attacker);
	battleOutput(casualty);


	if (debug) { cout << "MonsterBattle::calculateMonster finished" << endl; }
	return;
}

void MonsterBattle::printData() const
{
	cout << "MonsterBattle printData called" << endl
		<< "MonsterBattle attacker: " << endl;
	attacker.printData();
	cout << "MonsterBattle monster: " << endl;
	monster.printData();
	cout << "MonsterBattle result: " << (int)result << endl;
}