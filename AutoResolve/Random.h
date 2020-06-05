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

	Random() {}
	~Random() {}

	static const int randomNumber(int range);
	static const int randomNumber(int min, int max);


};

