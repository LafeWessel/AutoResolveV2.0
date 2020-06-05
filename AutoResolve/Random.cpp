#include "Random.h"
/*
Returns a random number between 0 and range
TODO determine if inclusive
*/
const int Random::randomNumber(int range)
{
	typedef std::chrono::high_resolution_clock myclock;
	std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());

	if (range == 0)
	if (range == 0)
	{
		return 0;
	}
	std::uniform_int_distribution<int> dRange(0, abs(range));
	return dRange(generator);
}

/*
Returns a random number between min and max
TODO determine if inclusive
*/
const int Random::randomNumber(int min, int max) {
	typedef std::chrono::high_resolution_clock myclock;
	std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());

	if (max == 0)
	{
		return 0;
	}
	std::uniform_int_distribution<int> dRange(abs(min), abs(max));
	return dRange(generator);
}