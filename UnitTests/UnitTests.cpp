#include <iostream>
#include <string>

#include "CppUnitTest.h"
#include "../AutoResolve/Random.h"
#include "../AutoResolve/Random.cpp"
#include "../AutoResolve/EnumerationConversions.h"
#include "../AutoResolve/EnumerationConversions.cpp"
#include "../AutoResolve/ValueAssurance.h"
#include "../AutoResolve/ValueAssurance.cpp"
#include "../AutoResolve/Equipment.h"
#include "../AutoResolve/Equipment.cpp"
#include "../AutoResolve/Unit.h"
#include "../AutoResolve/Unit.cpp"
#include "../AutoResolve/Monster.h"
#include "../AutoResolve/Monster.cpp"
#include "../AutoResolve/Treasure.h"
#include "../AutoResolve/Treasure.cpp"
#include "../AutoResolve/CSVRow.h"
#include "../AutoResolve/CSVRow.cpp"
#include "../AutoResolve/CSVDataReader.h"
#include "../AutoResolve/CSVDataReader.cpp"
#include "../AutoResolve/battleType.h"
#include "../AutoResolve/defenses.h"
#include "../AutoResolve/equipmentType.h"
#include "../AutoResolve/faction.h"
#include "../AutoResolve/monsterType.h"
#include "../AutoResolve/outcome.h"
#include "../AutoResolve/unitType.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	//Unit tests for the Random class
	TEST_CLASS(RandomTests)
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

	//Unit tests for the EnumerationConversions class
	TEST_CLASS(EnumerationConversionsTests) {

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

		//to_string method tests
		//to_string(equipmentType) tests
		//Tests to ensure that the correct output is returned when passing null
		TEST_METHOD(equipemntTypeToStringNull) {
			Assert::AreEqual((string)"null", EnumerationConversions::to_string(equipmentType::null));
		}
		//Tests to ensure that the correct output is returned when passing armor
		TEST_METHOD(equipemntTypeToStringArmor) {
			Assert::AreEqual((string)"Armor", EnumerationConversions::to_string(equipmentType::armor));
		}
		//Tests to ensure that the correct output is returned when passing weapon
		TEST_METHOD(equipemntTypeToStringWeapon) {
			Assert::AreEqual((string)"Weapon", EnumerationConversions::to_string(equipmentType::weapon));
		}
		//Tests to ensure that the correct output is returned when passing trinket
		TEST_METHOD(equipemntTypeToStringTrinket) {
			Assert::AreEqual((string)"Trinket", EnumerationConversions::to_string(equipmentType::trinket));
		}
		//Tests to ensure that the correct output is returned when passing banner
		TEST_METHOD(equipemntTypeToStringBanner) {
			Assert::AreEqual((string)"Banner", EnumerationConversions::to_string(equipmentType::banner));
		}
		//Tests to ensure that the correct output is returned when passing dragon
		TEST_METHOD(equipemntTypeToStringDragon) {
			Assert::AreEqual((string)"Dragon", EnumerationConversions::to_string(equipmentType::dragon));
		}
		//Tests to ensure that the correct output is returned when passing follower
		TEST_METHOD(equipemntTypeToStringFollower) {
			Assert::AreEqual((string)"Follower", EnumerationConversions::to_string(equipmentType::follower));
		}

		//to_string(outcome) tests
		//Tests to ensure that the correct output is returned when passing Decisive Victory
		TEST_METHOD(outcomeToStringDecisiveVictory) {
			Assert::AreEqual((string)"Decisive Victory", EnumerationConversions::to_string(outcome::Decisive_Victory));
		}
		//Tests to ensure that the correct output is returned when passing Heroic Victory
		TEST_METHOD(outcomeToStringHeroicVictory) {
			Assert::AreEqual((string)"Heroic Victory", EnumerationConversions::to_string(outcome::Heroic_Victory));
		}
		//Tests to ensure that the correct output is returned when passing Close Victory
		TEST_METHOD(outcomeToStringCloseVictory) {
			Assert::AreEqual((string)"Close Victory", EnumerationConversions::to_string(outcome::Close_Victory));
		}
		//Tests to ensure that the correct output is returned when passing Draw
		TEST_METHOD(outcomeToStringDraw) {
			Assert::AreEqual((string)"Draw", EnumerationConversions::to_string(outcome::Draw));
		}
		//Tests to ensure that the correct output is returned when passing Close Defeat
		TEST_METHOD(outcomeToStringCloseDefeat) {
			Assert::AreEqual((string)"Close Defeat", EnumerationConversions::to_string(outcome::Close_Defeat));
		}
		//Tests to ensure that the correct output is returned when passing Valiant Defeat
		TEST_METHOD(outcomeToStringValiantDefeat) {
			Assert::AreEqual((string)"Valiant Defeat", EnumerationConversions::to_string(outcome::Valiant_Defeat));
		}
		//Tests to ensure that the correct output is returned when passing Crushing Defeat
		TEST_METHOD(outcomeToStringCrushingDefeat) {
			Assert::AreEqual((string)"Crushing Defeat", EnumerationConversions::to_string(outcome::Crushing_Defeat));
		}

		//to_string(faction) tests
		//Tests to ensure that the correct output is returned when passing Rebel
		TEST_METHOD(outcomeToStringRebel) {
			Assert::AreEqual((string)"Rebel", EnumerationConversions::to_string(faction::rebel));
		}
		//Tests to ensure that the correct output is returned when passing Beladimir
		TEST_METHOD(outcomeToStringBeladimir) {
			Assert::AreEqual((string)"Beladimir", EnumerationConversions::to_string(faction::beladimir));
		}
		//Tests to ensure that the correct output is returned when passing Lerastir
		TEST_METHOD(outcomeToStringLerastir) {
			Assert::AreEqual((string)"Lerastir", EnumerationConversions::to_string(faction::lerastir));
		}
		//Tests to ensure that the correct output is returned when passing Menoriad
		TEST_METHOD(outcomeToStringMenoriad) {
			Assert::AreEqual((string)"Menoriad", EnumerationConversions::to_string(faction::menoriad));
		}

		//to_string(monsterType) tests
		//Tests to ensure that the correct output is returned when passing Minotaur
		TEST_METHOD(outcomeToStringMinotaur) {
			Assert::AreEqual((string)"Minotaur", EnumerationConversions::to_string(monsterType::Minotaur));
		}
		//Tests to ensure that the correct output is returned when passing Hobgoblin
		TEST_METHOD(outcomeToStringHobgoblin) {
			Assert::AreEqual((string)"Hobgoblin", EnumerationConversions::to_string(monsterType::Hobgoblin));
		}
		//Tests to ensure that the correct output is returned when passing Troll
		TEST_METHOD(outcomeToStringTroll) {
			Assert::AreEqual((string)"Troll", EnumerationConversions::to_string(monsterType::Troll));
		}
		//Tests to ensure that the correct output is returned when passing Demon
		TEST_METHOD(outcomeToStringDemon) {
			Assert::AreEqual((string)"Demon", EnumerationConversions::to_string(monsterType::Demon));
		}
		//Tests to ensure that the correct output is returned when passing Dragon
		TEST_METHOD(outcomeToStringDragon) {
			Assert::AreEqual((string)"Dragon", EnumerationConversions::to_string(monsterType::Dragon));
		}
		//Tests to ensure that the correct output is returned when passing Empty
		TEST_METHOD(outcomeToStringEmpty) {
			Assert::AreEqual((string)"Empty", EnumerationConversions::to_string(monsterType::Empty));
		}

		//to_string(defenses) tests
		//Tests to ensure that the correct output is returned when passing None
		TEST_METHOD(outcomeToStringNone) {
			Assert::AreEqual((string)"None", EnumerationConversions::to_string(defenses::None));
		}
		//Tests to ensure that the correct output is returned when passing Wooden Wall
		TEST_METHOD(outcomeToStringWoodenWall) {
			Assert::AreEqual((string)"Wooden Wall", EnumerationConversions::to_string(defenses::Wooden_Wall));
		}
		//Tests to ensure that the correct output is returned when passing Wooden Wall w/ Moat
		TEST_METHOD(outcomeToStringWoodenWallWMoat) {
			Assert::AreEqual((string)"Wooden Wall w/ Moat", EnumerationConversions::to_string(defenses::Wooden_Wall_W_Moat));
		}
		//Tests to ensure that the correct output is returned when passing Stone Wall
		TEST_METHOD(outcomeToStringStoneWall) {
			Assert::AreEqual((string)"Stone Wall", EnumerationConversions::to_string(defenses::Stone_Wall));
		}
		//Tests to ensure that the correct output is returned when passing Stone Wall w/ Moat
		TEST_METHOD(outcomeToStringStoneWallWMoat) {
			Assert::AreEqual((string)"Stone Wall w/ Moat", EnumerationConversions::to_string(defenses::Stone_Wall_W_Moat));
		}

		//to_string(battleType) tests
		//Tests to ensure that the correct output is returned when passing Normal
		TEST_METHOD(outcomeToStringNormal) {
			Assert::AreEqual((string)"Normal", EnumerationConversions::to_string(battleType::Normal));
		}
		//Tests to ensure that the correct output is returned when passing Siege
		TEST_METHOD(outcomeToStringSiege) {
			Assert::AreEqual((string)"Siege", EnumerationConversions::to_string(battleType::Siege));
		}
		//Tests to ensure that the correct output is returned when passing Raid
		TEST_METHOD(outcomeToStringRaid) {
			Assert::AreEqual((string)"Raid", EnumerationConversions::to_string(battleType::Raid));
		}
		//Tests to ensure that the correct output is returned when passing Naval
		TEST_METHOD(outcomeToStringNaval) {
			Assert::AreEqual((string)"Naval", EnumerationConversions::to_string(battleType::Naval));
		}
		//Tests to ensure that the correct output is returned when passing Monster
		TEST_METHOD(outcomeToStringMonster) {
			Assert::AreEqual((string)"Monster", EnumerationConversions::to_string(battleType::Monster));
		}

		//to_string(unitType) tests
		//Tests to ensure that the correct output is returned when passing Melee
		TEST_METHOD(outcomeToStringMelee) {
			Assert::AreEqual((string)"Melee", EnumerationConversions::to_string(unitType::Melee));
		}
		//Tests to ensure that the correct output is returned when passing Cavalry
		TEST_METHOD(outcomeToStringCavalry) {
			Assert::AreEqual((string)"Cavalry", EnumerationConversions::to_string(unitType::Cavalry));
		}
		//Tests to ensure that the correct output is returned when passing Ranged
		TEST_METHOD(outcomeToStringRanged) {
			Assert::AreEqual((string)"Ranged", EnumerationConversions::to_string(unitType::Ranged));
		}

		//intToUnitType Unit Tests
		//Tests to ensure that the correct output is returned when passing 1
		TEST_METHOD(TestIntToUnitTypeOne) {
			Assert::AreEqual((int)unitType::Melee, (int)EnumerationConversions::intToUnitType(1));
		}
		//Tests to ensure that the correct output is returned when passing 2
		TEST_METHOD(TestIntToUnitTypeTwo) {
			Assert::AreEqual((int)unitType::Cavalry, (int)EnumerationConversions::intToUnitType(2));
		}
		//Tests to ensure that the correct output is returned when passing 3
		TEST_METHOD(TestIntToUnitTypeThree) {
			Assert::AreEqual((int)unitType::Ranged, (int)EnumerationConversions::intToUnitType(3));
		}
		//Tests to ensure that the correct output is returned when passing invalid value
		TEST_METHOD(TestIntToUnitTypeInvalidValue) {
			Assert::AreEqual((int)unitType::Melee, (int)EnumerationConversions::intToUnitType(4));
		}

		//stringToEquipType Unit Tests
		//Tests to ensure that the correct output is returned when passing "Null"
		TEST_METHOD(TestIntToEquipTypeNull) {
			Assert::AreEqual((int)equipmentType::null, (int)EnumerationConversions::stringToEquipType("Null"));
		}
		//Tests to ensure that the correct output is returned when passing "Armor"
		TEST_METHOD(TestIntToUnitEquipArmor) {
			Assert::AreEqual((int)equipmentType::armor, (int)EnumerationConversions::stringToEquipType("Armor"));
		}
		//Tests to ensure that the correct output is returned when passing "Weapon"
		TEST_METHOD(TestIntToUnitEquipWeapon) {
			Assert::AreEqual((int)equipmentType::weapon, (int)EnumerationConversions::stringToEquipType("Weapon"));
		}
		//Tests to ensure that the correct output is returned when passing "Trinket"
		TEST_METHOD(TestIntToUnitEquipTrinket) {
			Assert::AreEqual((int)equipmentType::trinket, (int)EnumerationConversions::stringToEquipType("Trinket"));
		}
		//Tests to ensure that the correct output is returned when passing "Banner"
		TEST_METHOD(TestIntToEquipTypeBanner) {
			Assert::AreEqual((int)equipmentType::banner, (int)EnumerationConversions::stringToEquipType("Banner"));
		}
		//Tests to ensure that the correct output is returned when passing "Dragon"
		TEST_METHOD(TestIntToEquipTypeDragon) {
			Assert::AreEqual((int)equipmentType::dragon, (int)EnumerationConversions::stringToEquipType("Dragon"));
		}
		//Tests to ensure that the correct output is returned when passing "Follower"
		TEST_METHOD(TestIntToEquipTypeFollower) {
			Assert::AreEqual((int)equipmentType::follower, (int)EnumerationConversions::stringToEquipType("Follower"));
		}
		//Tests to ensure that the correct output is returned when passing invalid value
		TEST_METHOD(TestIntToEquipTypeInvalidValue) {
			Assert::AreEqual((int)equipmentType::null, (int)EnumerationConversions::stringToEquipType("Test invalid"));
		}


	};

	//Unit tests the Value Assurance Class
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


	//Unit tests for the Equipment Class
	TEST_CLASS(EquipmentTests) {

		//Check accessors and mutators
		//Test get/setName
		TEST_METHOD(getSetName) {
			Equipment eq = new Equipment();
			eq.setName("Test");
			Assert::AreEqual((string)"Test", eq.getName());

		}
		//Test get/setABonus
		TEST_METHOD(getSetAutoBonus) {
			Equipment eq = new Equipment();
			eq.setABonus(5);
			Assert::AreEqual(5, eq.getABonus());

		}
		//Test get/setRange
		TEST_METHOD(getSetRange) {
			Equipment eq = new Equipment();
			eq.setRange(2);
			Assert::AreEqual(2,eq.getRange());

		}
		//Test get/setEqType
		TEST_METHOD(getSetEquipmentType) {
			Equipment eq = new Equipment();
			eq.setEqType(equipmentType::armor);
			Assert::AreEqual((int)equipmentType::armor,(int)eq.getEqType());

		}
		//Test get/setEffect
		TEST_METHOD(getSetEffect) {
			Equipment eq = new Equipment();
			eq.setEffect("Test");
			Assert::AreEqual((string)"Test",eq.getEffect());

		}
		//Test get/setCValue
		TEST_METHOD(getSetCoinValue) {
			Equipment eq = new Equipment();
			eq.setCValue(100);
			Assert::AreEqual(100,eq.getCValue());

		}
		//Test get/setDebug
		TEST_METHOD(getSetDebug) {
			Equipment eq = new Equipment();
			eq.setDebug(true);
			Assert::AreEqual(true,eq.getDebug());

		}

		//Check output functions
		TEST_METHOD(toString) {
			Equipment eq = new Equipment();
			eq.setDebug(false);
			eq.setName("Test Name");
			eq.setABonus(5);
			eq.setCValue(200);
			eq.setEffect("Test Effect");
			eq.setRange(3);
			eq.setEqType(equipmentType::dragon);

			string expected = "Equipment printData called\nEquipment name: Test Name\nEquipment autoresolve bonus: 5\nEquipment index: 0\nEquipment range: 3\nEquipment equipType: Dragon\nEquipment effect: Test Effect\nEquipment coin value: 200\n";


			Assert::AreEqual(expected, eq.to_string());
		}
	};

	//Unit tests for the Unit class
	TEST_CLASS(UnitClassTests) {

		//Check accessors and mutators
		//Test get/setName
		TEST_METHOD(getSetName) {
			Unit u = new Unit();
			u.setName("Test Name");
			Assert::AreEqual((string)"Test Name", u.getName());
		}

		//Test get/setARBonus
		TEST_METHOD(getSetARBonus) {
			Unit u = new Unit();
			u.setARBonus(5);
			Assert::AreEqual(5, u.getARBonus());
		}

		//Test get/setSoldiersPerUnit
		TEST_METHOD(getSetSoldiersPerUnit) {
			Unit u = new Unit();
			u.setSoldiersPerUnit(4);
			Assert::AreEqual(4, u.getSoldiersPerUnit());
		}

		//Test get/setCurrentSoldiers
		TEST_METHOD(getSetCurrentSoldiers) {
			Unit u = new Unit();
			u.setCurrentSoldiers(4);
			Assert::AreEqual(4, u.getCurrentSoldiers());
		}

		//Test get/setFaction
		TEST_METHOD(getSetFaction) {
			Unit u = new Unit();
			u.setFaction(faction::beladimir);
			Assert::AreEqual((int)faction::beladimir,(int)u.getFaction());
		}

		//Test get/setUnitType
		TEST_METHOD(getSetUnitType) {
			Unit u = new Unit();
			u.setUnitType(unitType::Cavalry);
			Assert::AreEqual((int)unitType::Cavalry,(int)u.getUnitType());
		}

		//Test get/setDebug
		TEST_METHOD(getSetDebug) {
			Unit u = new Unit();
			u.setDebug(true);
			Assert::AreEqual(true,u.getDebug());
		}

		//Test output functions
		TEST_METHOD(toString) {
			Unit u = new Unit();
			u.setName("Test Name");
			u.setARBonus(4);
			u.setSoldiersPerUnit(5);
			u.setCurrentSoldiers(6);
			u.setFaction(faction::beladimir);
			u.setUnitType(unitType::Cavalry);
			u.setDebug(true);
			string expected = "Unit printData called\nUnit name: Test Name\nUnit autoresolve bonus: 4\nUnit soldiersPerUnit: 5\nUnit currentSoldiers: 6\nUnit faction: Beladimir\nUnit unitType: Cavalry\n";
			Assert::AreEqual(expected, u.to_string());
		}

	};

	//Unit tests for Treasure class
	TEST_CLASS(TreasureTests) {

		//Test accessors and mutators
		//Test get/setDebug
		TEST_METHOD(getSetDebug) {
			Treasure t = new Treasure();
			t.setDebug(true);
			Assert::AreEqual(true, t.getDebug());
		}
		TEST_METHOD(getSetFilePath) {
			Treasure t = new Treasure();
			t.setFilePath("Test Path");
			Assert::AreEqual((string)"Test Path", t.getFilePath());
		}
		//Test find/setArmorVector
		TEST_METHOD(findSetArmorVector) {
			Treasure t = new Treasure();
			Equipment e{};
			e.setName("Test Name");
			vector<Equipment> ev = { e,e };
			t.setArmorVector(ev);
			Assert::AreEqual((string)"Test Name", t.findArmor().getName());
		}
		//Test find/setWeaponVector
		TEST_METHOD(findSetWeaponVector) {
			Treasure t = new Treasure();
			Equipment e{};
			e.setName("Test Name");
			vector<Equipment> ev = { e,e };
			t.setWeaponVector(ev);
			Assert::AreEqual((string)"Test Name", t.findWeapon().getName());
		}
		//Test find/setTrinketVector
		TEST_METHOD(findSetTrinketVector) {
			Treasure t = new Treasure();
			Equipment e{};
			e.setName("Test Name");
			vector<Equipment> ev = { e,e };
			t.setTrinketVector(ev);
			Assert::AreEqual((string)"Test Name", t.findTrinket().getName());
		}
		//Test find/setBannerVector
		TEST_METHOD(findSetBannerVector) {
			Treasure t = new Treasure();
			Equipment e{};
			e.setName("Test Name");
			vector<Equipment> ev = { e,e };
			t.setBannerVector(ev);
			Assert::AreEqual((string)"Test Name", t.findBanner().getName());
		}
		//Test find/setFollowerVector
		TEST_METHOD(findSetFollowerVector) {
			Treasure t = new Treasure();
			Equipment e{};
			e.setName("Test Name");
			vector<Equipment> ev = { e,e };
			t.setFollowerVector(ev);
			Assert::AreEqual((string)"Test Name", t.findFollower().getName());
		}
		//Test find/setDragonVector
		TEST_METHOD(findSetDragonVector) {
			Treasure t = new Treasure();
			Equipment e{};
			e.setName("Test Name");
			vector<Equipment> ev = { e,e };
			t.setDragonVector(ev);
			Assert::AreEqual((string)"Test Name", t.findDragonEq().getName());
		}
		//Test get/setArmorVector
		TEST_METHOD(getSetArmorVector) {
			Treasure t = new Treasure();
			Equipment e{};
			e.setName("Test Name");
			vector<Equipment> ev = { e };
			t.setArmorVector(ev);
			Assert::AreEqual((string)"Test Name", t.getArmorVector()[0].getName());
		}
		//Test get/setWeaponVector
		TEST_METHOD(getSetWeaponVector) {
			Treasure t = new Treasure();
			Equipment e{};
			e.setName("Test Name");
			vector<Equipment> ev = { e };
			t.setWeaponVector(ev);
			Assert::AreEqual((string)"Test Name", t.getWeaponVector()[0].getName());
		}
		//Test get/setTrinketVector
		TEST_METHOD(getSetTrinketVector) {
			Treasure t = new Treasure();
			Equipment e{};
			e.setName("Test Name");
			vector<Equipment> ev = { e };
			t.setTrinketVector(ev);
			Assert::AreEqual((string)"Test Name", t.getTrinketVector()[0].getName());
		}
		//Test get/setBannerVector
		TEST_METHOD(getSetBannerVector) {
			Treasure t = new Treasure();
			Equipment e{};
			e.setName("Test Name");
			vector<Equipment> ev = { e };
			t.setBannerVector(ev);
			Assert::AreEqual((string)"Test Name", t.getBannerVector()[0].getName());
		}
		//Test get/setFollowerVector
		TEST_METHOD(getSetFollowerVector) {
			Treasure t = new Treasure();
			Equipment e{};
			e.setName("Test Name");
			vector<Equipment> ev = { e };
			t.setFollowerVector(ev);
			Assert::AreEqual((string)"Test Name", t.getFollowerVector()[0].getName());
		}
		//Test get/setDragonVector
		TEST_METHOD(getSetDragonVector) {
			Treasure t = new Treasure();
			Equipment e{};
			e.setName("Test Name");
			vector<Equipment> ev = { e };
			t.setDragonVector(ev);
			Assert::AreEqual((string)"Test Name", t.getDragonVector()[0].getName());
		}

		//Test find functions
		//Test noTreasure
		TEST_METHOD(noTreasure) {
			Treasure t = new Treasure();
			Assert::AreEqual((string)"No Treasure", t.noTreasure().getName());
		}
		//Test findTreasure
		TEST_METHOD(findTreasureSucceed) {
			
			Equipment e{};
			e.setName("Test Name");
			vector<Equipment> ev = { e,e };
			Treasure t{ ev, ev, ev, ev, ev, ev, false };
			string name = t.findTreasure(5).getName();
			Assert::AreEqual((string)"Test Name",name);
		}

		//Test initialize
		//Test armor vector initialization
		TEST_METHOD(initializeArmor) {
			Treasure t{ true };
			t.setFilePath((string)"../AutoResolve/equipment.txt");
			t.initialize();
			bool correctLength = false;
			Assert::AreEqual(9, (int)t.getArmorVector().size());
		}
		//Test weapon vector initialization
		TEST_METHOD(initializeWeapon) {
			Treasure t{ true };
			t.setFilePath((string)"../AutoResolve/equipment.txt");
			t.initialize();
			Assert::AreEqual(9, (int)t.getWeaponVector().size());
		}
		//Test trinket vector initialization
		TEST_METHOD(initializeTrinket) {
			Treasure t{ true };
			t.setFilePath((string)"../AutoResolve/equipment.txt");
			t.initialize();
			Assert::AreEqual(9, (int)t.getTrinketVector().size());
		}
		//Test banner vector initialization
		TEST_METHOD(initializeBanner) {
			Treasure t{ true };
			t.setFilePath((string)"../AutoResolve/equipment.txt");
			t.initialize();
			Assert::AreEqual(9, (int)t.getBannerVector().size());
		}
		//Test follower vector initialization
		TEST_METHOD(initializeFollower) {
			Treasure t{ true };
			t.setFilePath((string)"../AutoResolve/equipment.txt");
			t.initialize();
			Assert::AreEqual(8, (int)t.getFollowerVector().size());
		}
		//Test dragon vector initialization
		TEST_METHOD(initializeDragon) {
			Treasure t{ true };
			t.setFilePath((string)"../AutoResolve/equipment.txt");
			t.initialize();
			Assert::AreEqual(4, (int)t.getDragonVector().size());
		}
	};

	//Unit tests for CSVRow class
	TEST_CLASS(CSVRowTests) {

		//Test get/setDebug
		TEST_METHOD(getSetDebug) {
			CSVRow c{};
			c.setDebug(true);
			Assert::AreEqual(true, c.getDebug());

		}
	};

	//Unit tests for CSVDataReader class
	TEST_CLASS(CSVDataReaderTests) {
		//Test get/setDebug
		TEST_METHOD(getSetDebug) {
			CSVDataReader c{};
			c.setDebug(true);
			Assert::AreEqual(true, c.getDebug());

		}
	};

	//Unit tests for Monster class
	TEST_CLASS(MonsterTests) {

		//Test accessors and mutators
		//Test get/setDebug
		TEST_METHOD(getSetDebug) {
			Monster m{};
			m.setDebug(true);
			Assert::AreEqual(true, m.getDebug());
		}
		//Test get/setMonsterType
		TEST_METHOD(getSetMonsterType) {
			Monster m{};
			m.setMonsterType(monsterType::Dragon);
			Assert::AreEqual((int)monsterType::Dragon, (int)m.getMonsterType());
		}
		//Test getCoinReward
		TEST_METHOD(getCoinReward) {
			Monster m{};
			m.setMonsterType(monsterType::Dragon);
			Assert::AreEqual(1400, m.getCoinReward());
		}
		//Test getARValue
		TEST_METHOD(getARValue) {
			Monster m{};
			m.setMonsterType(monsterType::Dragon);
			Assert::AreEqual(70, m.getARValue());
		}

		//Test getEquipRewards
		//Test for Minotaur
		TEST_METHOD(getEquipRewardsMinotaur) {
			Treasure t{};
			t.setFilePath("../AutoResolve/equipment.txt");
			t.initialize();
			Monster m{ monsterType::Minotaur, t };
			vector<Equipment> e = m.getEquipRewards();
			Assert::AreEqual((int)equipmentType::weapon, (int)e[0].getEqType());
		}
		//Test for Hobgoblin
		TEST_METHOD(getEquipRewardsHobgoblinWeapon) {
			Treasure t{};
			t.setFilePath("../AutoResolve/equipment.txt");
			t.initialize();
			Monster m{ monsterType::Hobgoblin, t };
			vector<Equipment> e = m.getEquipRewards();
			Assert::AreEqual((int)equipmentType::weapon, (int)e[0].getEqType());
		}
		TEST_METHOD(getEquipRewardsHobgoblinArmor) {
			Treasure t{};
			t.setFilePath("../AutoResolve/equipment.txt");
			t.initialize();
			Monster m{ monsterType::Hobgoblin, t };
			vector<Equipment> e = m.getEquipRewards();
			Assert::AreEqual((int)equipmentType::armor,(int)e[1].getEqType());
		}
		//Test for Troll
		TEST_METHOD(getEquipRewardsTrollWeapon) {
			Treasure t{};
			t.setFilePath("../AutoResolve/equipment.txt");
			t.initialize();
			Monster m{ monsterType::Troll, t };
			vector<Equipment> e = m.getEquipRewards();
			Assert::AreEqual((int)equipmentType::weapon,(int)e[0].getEqType());
		}
		TEST_METHOD(getEquipRewardsTrollTrinket) {
			Treasure t{};
			t.setFilePath("../AutoResolve/equipment.txt");
			t.initialize();
			Monster m{ monsterType::Troll, t };
			vector<Equipment> e = m.getEquipRewards();
			Assert::AreEqual((int)equipmentType::trinket, (int)e[1].getEqType());
		}
		//Test for Giant
		TEST_METHOD(getEquipRewardsGiantWeapon) {
			Treasure t{};
			t.setFilePath("../AutoResolve/equipment.txt");
			t.initialize();
			Monster m{ monsterType::Giant, t };
			vector<Equipment> e = m.getEquipRewards();
			Assert::IsTrue(equipmentType::weapon == e[0].getEqType());
		}
		TEST_METHOD(getEquipRewardsGiantTrinket) {
			Treasure t{};
			t.setFilePath("../AutoResolve/equipment.txt");
			t.initialize();
			Monster m{ monsterType::Giant, t };
			vector<Equipment> e = m.getEquipRewards();
			Assert::IsTrue(equipmentType::trinket == e[1].getEqType());
		}
		TEST_METHOD(getEquipRewardsGiantArmor) {
			Treasure t{};
			t.setFilePath("../AutoResolve/equipment.txt");
			t.initialize();
			Monster m{ monsterType::Giant, t };
			vector<Equipment> e = m.getEquipRewards();
			Assert::IsTrue(equipmentType::armor == e[2].getEqType());
		}
		//Test for Demon
		TEST_METHOD(getEquipRewardsDemonArmor) {
			Treasure t{};
			t.setFilePath("../AutoResolve/equipment.txt");
			t.initialize();
			Monster m{ monsterType::Demon, t };
			vector<Equipment> e = m.getEquipRewards();
			Assert::IsTrue(equipmentType::armor == e[0].getEqType());
		}
		TEST_METHOD(getEquipRewardsDemonBanner) {
			Treasure t{};
			t.setFilePath("../AutoResolve/equipment.txt");
			t.initialize();
			Monster m{ monsterType::Demon, t };
			vector<Equipment> e = m.getEquipRewards();
			Assert::IsTrue(equipmentType::banner == e[1].getEqType());
		}
		//Test for Empty
		TEST_METHOD(getEquipRewardsEmpty) {
			Treasure t{};
			t.setFilePath("../AutoResolve/equipment.txt");
			t.initialize();
			Monster m{ monsterType::Empty, t };
			vector<Equipment> e = m.getEquipRewards();
			Assert::AreEqual((string)"", e[0].getName());
		}
		//Test for Invalid
		TEST_METHOD(getEquipRewardsInvalid) {
			Treasure t{};
			t.setFilePath("../AutoResolve/equipment.txt");
			t.initialize();
			Monster m{};
			m.setTreasure(t);
			vector<Equipment> e = m.getEquipRewards();
			Assert::AreEqual((string)"", e[0].getName());
		}
	};
}
