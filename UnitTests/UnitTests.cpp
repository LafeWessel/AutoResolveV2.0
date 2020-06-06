#include <iostream>
#include <string>


#include "CppUnitTest.h"
#include "../AutoResolve/Random.h"
#include "../AutoResolve/Random.cpp"
#include "../AutoResolve/EnumerationConversions.h"
#include "../AutoResolve/EnumerationConversions.cpp"
#include "../AutoResolve/ValueAssurance.h"
#include "../AutoResolve/ValueAssurance.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	//Unit tests for the Random class
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

		//Tests to make sure that the random generated is within or equal to the bounds
		TEST_METHOD(TestRandomNumberIntTwoBounds) {
			int random = Random::randomNumber(1, 3);
			Assert::AreEqual(2, float(random), 1);
		}

	};

	//Tests for the EnumerationConversions class
	TEST_CLASS(EnumerationConversionsTest) {

		//intToFaction Unit Tests
		//Tests to ensure that the correct output is returned when passing 1
		TEST_METHOD(TestIntToFactionOne) {
			Assert::AreEqual((int)faction::rebel, (int)EnumerationConversions::intToFaction(1));
		}
		//Tests to ensure that the correct output is returned when passing 2
		TEST_METHOD(TestIntToFactionTwo) {
			Assert::AreEqual((int)faction::beladimir, (int)EnumerationConversions::intToFaction(2));
		}
		//Tests to ensure that the correct output is returned when passing 3
		TEST_METHOD(TestIntToFactionThree) {
			Assert::AreEqual((int)faction::lerastir, (int)EnumerationConversions::intToFaction(3));
		}
		//Tests to ensure that the correct output is returned when passing 4
		TEST_METHOD(TestIntToFactionFour) {
			Assert::AreEqual((int)faction::menoriad, (int)EnumerationConversions::intToFaction(4));
		}
		//Tests to ensure that the correct output is returned when passing invalid value
		TEST_METHOD(TestIntToFactionInvalidInput) {
			Assert::AreEqual((int)faction::rebel, (int)EnumerationConversions::intToFaction(5));
		}

		//intToMonsterType Unit Tests
		//Tests to ensure that the correct output is returned when passing 1
		TEST_METHOD(TestIntToMonsterTypeOne) {
			Assert::AreEqual((int)monsterType::Minotaur, (int)EnumerationConversions::intToMonsterType(1));
		}
		//Tests to ensure that the correct output is returned when passing 2
		TEST_METHOD(TestIntToMonsterTypeTwo) {
			Assert::AreEqual((int)monsterType::Hobgoblin, (int)EnumerationConversions::intToMonsterType(2));
		}
		//Tests to ensure that the correct output is returned when passing 3
		TEST_METHOD(TestIntToMonsterTypeThree) {
			Assert::AreEqual((int)monsterType::Troll, (int)EnumerationConversions::intToMonsterType(3));
		}
		//Tests to ensure that the correct output is returned when passing 4
		TEST_METHOD(TestIntToMonsterTypeFour) {
			Assert::AreEqual((int)monsterType::Giant, (int)EnumerationConversions::intToMonsterType(4));
		}
		//Tests to ensure that the correct output is returned when passing 5
		TEST_METHOD(TestIntToMonsterTypeFive) {
			Assert::AreEqual((int)monsterType::Demon, (int)EnumerationConversions::intToMonsterType(5));
		}
		//Tests to ensure that the correct output is returned when passing 6
		TEST_METHOD(TestIntToMonsterTypeSix) {
			Assert::AreEqual((int)monsterType::Dragon, (int)EnumerationConversions::intToMonsterType(6));
		}
		//Tests to ensure that the correct output is returned when passing invalid value
		TEST_METHOD(TestIntToMonsterTypeInvalidInput) {
			Assert::AreEqual((int)monsterType::Empty, (int)EnumerationConversions::intToMonsterType(7));
		}

		//outputIntAsOutcome Unit Tests
		//Tests to ensure that the correct output is returned when passing 1
		TEST_METHOD(outputIntAsOutcomeOne) {
			Assert::AreEqual((string)"Decisive Victory", EnumerationConversions::outputIntAsOutcome(1));
		}
		//Tests to ensure that the correct output is returned when passing 2
		TEST_METHOD(outputIntAsOutcomeTwo) {
			Assert::AreEqual((string)"Heroic Victory", EnumerationConversions::outputIntAsOutcome(2));
		}
		//Tests to ensure that the correct output is returned when passing 3
		TEST_METHOD(outputIntAsOutcomeThree) {
			Assert::AreEqual((string)"Close Victory", EnumerationConversions::outputIntAsOutcome(3));
		}
		//Tests to ensure that the correct output is returned when passing 4
		TEST_METHOD(outputIntAsOutcomeFour) {
			Assert::AreEqual((string)"Draw", EnumerationConversions::outputIntAsOutcome(4));
		}
		//Tests to ensure that the correct output is returned when passing 5
		TEST_METHOD(outputIntAsOutcomeFive) {
			Assert::AreEqual((string)"Close Defeat", EnumerationConversions::outputIntAsOutcome(5));
		}
		//Tests to ensure that the correct output is returned when passing 6
		TEST_METHOD(outputIntAsOutcomeSix) {
			Assert::AreEqual((string)"Valiant Defeat", EnumerationConversions::outputIntAsOutcome(6));
		}
		//Tests to ensure that the correct output is returned when passing 7
		TEST_METHOD(outputIntAsOutcomeSeven) {
			Assert::AreEqual((string)"Crushing Defeat", EnumerationConversions::outputIntAsOutcome(7));
		}
		//Tests to ensure that the correct output is returned when passing invalid value
		TEST_METHOD(outputIntAsOutcomeInvalidInput) {
			Assert::AreEqual((string)"", EnumerationConversions::outputIntAsOutcome(8));
		}


	};


	//Tests the Value Assurance Class
	TEST_CLASS(ValueAssuranceTests) {

		//inputCheck Unit Tests
		//Tests to ensure that bounds are correctly clamped
		TEST_METHOD(inputCheckWithinBounds) {
			Assert::AreEqual(5, ValueAssurance::inputCheck(5, 6, 4));
		}
		//Tests to ensure that bounds are correctly clamped
		TEST_METHOD(inputCheckOnTopBound) {
			Assert::AreEqual(5, ValueAssurance::inputCheck(5, 5, 4));
		}
		//Tests to ensure that bounds are correctly clamped
		TEST_METHOD(inputCheckOnBottomBound) {
			Assert::AreEqual(5, ValueAssurance::inputCheck(5, 6, 5));
		}
		//Tests to ensure that bounds are correctly clamped
		TEST_METHOD(inputCheckOutOfUpperBound) {
			Assert::AreEqual(6, ValueAssurance::inputCheck(7, 6, 5));
		}
		//Tests to ensure that bounds are correctly clamped
		TEST_METHOD(inputCheckOutOfLowerBound) {
			Assert::AreEqual(5, ValueAssurance::inputCheck(4, 6, 5));
		}


	};
}
