#pragma once
#include <iostream>

using std::cout;
using std::endl;

/*
This class only contains static functions for ensuring that values are within determined bounds
*/
class ValueAssurance
{
private:

public:
	static int inputCheck(int toCheck, int max, int min);
};

