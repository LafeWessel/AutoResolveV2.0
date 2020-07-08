#include "ValueAssurance.h"

/*
Checks integer input between 2 given bounds and clamps them, bound inclusive
*/
int ValueAssurance::inputCheck(int toCheck, const int max, const int min) 
{
	if (toCheck < min)//Check against lowest possible value
	{
		toCheck = min;
		cout << "Too small, set to: " << min << endl;
	}
	else if (toCheck > max) //Check against highest possible value
	{
		toCheck = max;
		cout << "Too large, set to: " << max << endl;
	}
	return toCheck;
}

