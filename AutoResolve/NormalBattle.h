#pragma once
#include "Battle.h"

class NormalBattle : public Battle
{
private:
	
public:
	~NormalBattle();
	NormalBattle();

	void battleOutput(vector<vector<int>> totalCasualties);
	void calculate();

	void printData() const;
};

