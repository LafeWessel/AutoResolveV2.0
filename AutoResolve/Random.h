#pragma once
#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <cmath>


/*
This class contains only static methods for the generation of random numbers
*/
class Random
{
private:

public:
	static int randomNumber(const int range);
	static int randomNumber(const int min, const int max);
	static int randomNumberArray(const int range);


};

