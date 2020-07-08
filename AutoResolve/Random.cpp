#include "Random.h"
/*
Returns a random number between 0 and range bound-inclusive
*/
int Random::randomNumber(const int range)
{
	typedef std::chrono::high_resolution_clock myclock;
	std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());

	if (range == 0)
	{
		return 0;
	}
	std::uniform_int_distribution<int> dRange(0, abs(range));
	return dRange(generator);
}

/*
Returns a random number between min and max bound-inclusive
*/
int Random::randomNumber(const int min, const int max) {
	typedef std::chrono::high_resolution_clock myclock;
	std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());

	if (max == 0)
	{
		return 0;
	}
	std::uniform_int_distribution<int> dRange(abs(min), abs(max));
	return dRange(generator);
}

/*
Returns a random number between 0 and range-1 bound-inclusive
*/
int Random::randomNumberArray(const int range)
{
	typedef std::chrono::high_resolution_clock myclock;
	std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());

	if (range == 0)
	{
		return 0;
	}
	std::uniform_int_distribution<int> dRange(0, abs(range)-1);
	return dRange(generator);
}

/*
Returns a sum of iterations random numbers between min and max bound-inclusive
//TODO Unit test
*/
int Random::randomNumberGroup(const int iterations, const int min, const int max) {
	typedef std::chrono::high_resolution_clock myclock;
	std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> dRange(abs(min), abs(max));
	if (max == 0 || iterations == 0)
	{
		return 0;
	}
	int total = 0;
	for (int i = 0; i < iterations; i++) {
		total += dRange(generator);
	}
	
	return total;
}