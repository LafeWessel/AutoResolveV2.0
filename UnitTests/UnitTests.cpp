#include <iostream>
#include "CppUnitTest.h"
#include "../AutoResolve/Random.h"
#include "../AutoResolve/Random.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(RandomTest)
	{
	public:
		
		//Tests to make sure the random number is within 0 - 2 inclusive
		TEST_METHOD(TestRandomNumberZeroBasedTwo) {

			int random = Random::randomNumber(2);
			//cast to float to ensure that only one function signature is valid
			Assert::AreEqual(1, (float)random, 1);
		}

		//Tests to make sure that 0 is returned when 0 is passed to randomNumber
		TEST_METHOD(TestRandomNumberIntZeroBasedZero) {

			int random = Random::randomNumber(0);
			Assert::AreEqual(0, random);
		}

		TEST_METHOD(TestRandomNumberIntTwoBounds) {

		}

	};
}
