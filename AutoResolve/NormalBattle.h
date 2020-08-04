#pragma once
#include "Battle.h"

class NormalBattle : public Battle
{
private:
	battleType type = battleType::Normal;
public:
	~NormalBattle();
	NormalBattle();

	void battleOutput(vector<vector<int>> totalCasualties);
	void calculate();

	void printData() const;
};

