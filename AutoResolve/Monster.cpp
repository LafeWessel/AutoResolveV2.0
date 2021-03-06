#include "Monster.h"


Monster::~Monster()
{
}

Monster::Monster() //void initializer
{
	treasure = &Treasure();
	type = monsterType::Empty;
	coinReward = 0;
	autoResValue = 0;
	debug = false;
}

Monster::Monster(const bool debugI)
{
	treasure = &Treasure();
	type = monsterType::Empty;
	coinReward = 0;
	autoResValue = 0;
	this->setDebug(debugI);
}

Monster::Monster(const string filePath) {
	debug = false;
	treasure = &Treasure();
	treasure->setFilePath(filePath);
	type = monsterType::Empty;
	coinReward = 0;
	autoResValue = 0;
	
}

Monster::Monster(monsterType m, Treasure& treasureI) {
	treasure = &treasureI;
	type = m;
	debug = false;
	coinReward = 0;
	autoResValue = 0;
	setValuesFromMonsterType();
}


vector<Equipment> Monster::getEquipRewards() const //This figures out the treasure gained for killing a monster, based on info elsewhere
{
	if (debug) { cout << "getEquipRewards called" << endl; }
	vector<Equipment> rewards = {};
	switch (type)
	{
	case(monsterType::Minotaur):
	{
		Equipment reward = treasure->findWeapon();
		rewards.push_back(reward);
		if (debug) { cout << "rewards pushed: " << reward.getName() << endl; }
		break;
	}
	case(monsterType::Hobgoblin):
	{
		Equipment reward = treasure->findWeapon();
		rewards.push_back(reward);
		if (debug) { cout << "rewards pushed: " << reward.getName() << endl; }
		reward = treasure->findArmor();
		rewards.push_back(reward);
		if (debug) { cout << "rewards pushed: " << reward.getName() << endl; }
		break;
	}
	case(monsterType::Troll):
	{
		Equipment reward = treasure->findWeapon();
		rewards.push_back(reward);
		if (debug) { cout << "rewards pushed: " << reward.getName() << endl; }
		reward = treasure->findTrinket();
		rewards.push_back(reward);
		if (debug) { cout << "rewards pushed: " << reward.getName() << endl; }
		break;
	}
	case(monsterType::Giant):
	{
		Equipment reward = treasure->findWeapon();
		rewards.push_back(reward);
		if (debug) { cout << "rewards pushed: " << reward.getName() << endl; }
		reward = treasure->findTrinket();
		rewards.push_back(reward);
		if (debug) { cout << "rewards pushed: " << reward.getName() << endl; }
		reward = treasure->findArmor();
		rewards.push_back(reward);
		if (debug) { cout << "rewards pushed: " << reward.getName() << endl; }
		break;
	}
	case(monsterType::Demon):
	{
		Equipment reward = treasure->findArmor();
		rewards.push_back(reward);
		if (debug) { cout << "rewards pushed: " << reward.getName() << endl; }
		reward = treasure->findBanner();
		rewards.push_back(reward);
		if (debug) { cout << "rewards pushed: " << reward.getName() << endl; }

		break;
	}
	case(monsterType::Dragon):
	{
		Equipment reward = treasure->findDragonEq();
		rewards.push_back(reward);
		if (debug) { cout << "rewards pushed: " << reward.getName() << endl; }
		break;
	}
	default:
		cerr << "Something went wrong" << endl;
		rewards.push_back(Equipment{});
	}
	return rewards;
}

void Monster::setValuesFromMonsterType()
{
	if (debug) { cout << "setValuesFromMonsterType called" << endl; }
	//These set the coin rewards; they are based on values stored in other documentation
	if ((int)type < 5)
	{
		coinReward = ((int)type + 1) * 100;
		
	}
	else if ((int)type < 6)
	{
		coinReward = ((int)type + 2) * 100;
	}
	else
	{
		coinReward = ((int)type + 1) * 200;
	}
	if (debug) { cout << "coinReward set to: " << coinReward << endl; }

	autoResValue = ((int)type * 10) + 10;
	if (debug) { cout << "autoResolve Value set to: " << autoResValue << endl; }
}

void Monster::printData() const
{
	cout << "Monster printData called" << endl
		<< "Monster monsterType: " << EnumerationConversions::to_string(type) << endl
		<< "Monster coin reward: " << coinReward << endl
		<< "Monster autoresolve value: " << autoResValue << endl;
	if (treasure) { cout << "Monster treasure pointer != null" << endl; }
}