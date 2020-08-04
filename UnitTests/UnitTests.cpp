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
#include "../AutoResolve/General.h"
#include "../AutoResolve/General.cpp"
#include "../AutoResolve/TownStats.h"
#include "../AutoResolve/TownStats.cpp"
#include "../AutoResolve/Roster.h"
#include "../AutoResolve/Roster.cpp"
#include "../AutoResolve/Player.h"
#include "../AutoResolve/Player.cpp"
#include "../AutoResolve/BattleData.h"
#include "../AutoResolve/BattleData.cpp"
#include "../AutoResolve/Battle.h"
#include "../AutoResolve/Battle.cpp"
#include "../AutoResolve/NavalBattle.h"
#include "../AutoResolve/NavalBattle.cpp"
#include "../AutoResolve/NormalBattle.h"
#include "../AutoResolve/NormalBattle.cpp"
#include "../AutoResolve/SiegeBattle.h"
#include "../AutoResolve/SiegeBattle.cpp"
#include "../AutoResolve/RaidBattle.h"
#include "../AutoResolve/RaidBattle.cpp"
#include "../AutoResolve/MonsterBattle.h"
#include "../AutoResolve/MonsterBattle.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	//Unit tests for Random class
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

	//Unit tests for EnumerationConversions class
	TEST_CLASS(EnumerationConversionsTests) {

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

		//to_string generalState tests
		//Test when passing Unharmed
		TEST_METHOD(toStringGeneralStateUnharmed) {
			Assert::AreEqual((string)"Unharmed", EnumerationConversions::to_string(generalState::Unharmed));
		}
		//Test when passing Wounded
		TEST_METHOD(toStringGeneralStateWounded) {
			Assert::AreEqual((string)"Wounded", EnumerationConversions::to_string(generalState::Wounded));
		}
		//Test when passing Slain
		TEST_METHOD(toStringGeneralStateSlain) {
			Assert::AreEqual((string)"Slain", EnumerationConversions::to_string(generalState::Slain));
		}
	};

	//Unit tests for Value Assurance Class
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
			Monster m{(string)"../AutoResolve/equipment.txt"};
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
			m.setTreasure(&t);
			vector<Equipment> e = m.getEquipRewards();
			Assert::AreEqual((string)"", e[0].getName());
		}
	};

	//Unit tests for General class
	TEST_CLASS(GeneralTests) {
		
		//Test accessors and mutators
		//Test get/setRank
		TEST_METHOD(getSetRank) {
			General g{};
			g.setRank(5);
			Assert::AreEqual(5, g.getRank());
		}
		//Test get/setArmor
		TEST_METHOD(getSetArmor) {
			General g{};
			Equipment e{};
			e.setABonus(3);
			g.setArmor(e);
			Assert::AreEqual(3, g.getArmor().getABonus());
		}
		//Test get/setWeapon
		TEST_METHOD(getSetWeapon) {
			General g{};
			Equipment e{};
			e.setABonus(3);
			g.setWeapon(e);
			Assert::AreEqual(3, g.getWeapon().getABonus());
		}
		//Test get/setTrinket
		TEST_METHOD(getSetTrinket) {
			General g{};
			Equipment e{};
			e.setABonus(3);
			g.setTrinket(e);
			Assert::AreEqual(3, g.getTrinket().getABonus());
		}
		//Test get/setBanner
		TEST_METHOD(getSetBanner) {
			General g{};
			Equipment e{};
			e.setABonus(3);
			g.setBanner(e);
			Assert::AreEqual(3, g.getBanner().getABonus());
		}
		//Test get/setFollower
		TEST_METHOD(getSetFollower) {
			General g{};
			Equipment e{};
			e.setABonus(3);
			g.setFollower(e);
			Assert::AreEqual(3, g.getFollower().getABonus());
		}
		//Test get/setState
		TEST_METHOD(getSetState) {
			General g{};
			g.setState(generalState::Wounded);
			Assert::AreEqual((int)generalState::Wounded, (int)g.getState());
		}
		//Test get/setDebug
		TEST_METHOD(getSetDebug) {
			General g{};
			g.setDebug(true);
			Assert::AreEqual(true, g.getDebug());
		}
		//Test getARBonus
		TEST_METHOD(getARBonus) {
			General g{};
			Assert::AreEqual(0, g.getARBonus());
		}
		//Test updateARBonus
		//Test updateARBonus in setArmor
		TEST_METHOD(updateARBonusArmor) {
			General g{};
			Equipment e{};
			e.setABonus(3);
			g.setArmor(e);
			Assert::AreEqual(3, g.getARBonus());
		}
		//Test updateARBonus in setWeapon
		TEST_METHOD(updateARBonusWeapon) {
			General g{};
			Equipment e{};
			e.setABonus(3);
			g.setWeapon(e);
			Assert::AreEqual(3, g.getARBonus());
		}
		//Test updateARBonus in setTrinket
		TEST_METHOD(updateARBonusTrinket) {
			General g{};
			Equipment e{};
			e.setABonus(3);
			g.setTrinket(e);
			Assert::AreEqual(3, g.getARBonus());
		}
		//Test updateARBonus in setBanner
		TEST_METHOD(updateARBonusBanner) {
			General g{};
			Equipment e{};
			e.setABonus(3);
			g.setBanner(e);
			Assert::AreEqual(3, g.getARBonus());
		}
		//Test updateARBonus in constructor
		TEST_METHOD(updateARBonusConstructor) {
			Equipment e{};
			e.setABonus(1);
			General g{ 1,e,e,e,e,e };
			Assert::AreEqual(4, g.getARBonus());
		}
	};

	//Unit tests for TownStats class
	TEST_CLASS(TownStatsTests) {

		//Test accessors and mutators
		//Test get/setSupplies
		TEST_METHOD(getSetSupplies) {
			TownStats t{};
			t.setSupplies(5);
			Assert::AreEqual(5, t.getSupplies());
		}
		//Test get/setDefenses
		TEST_METHOD(getSetDefenses) {
			TownStats t{};
			t.setDefenses(defenses::Stone_Wall);
			Assert::AreEqual((int)defenses::Stone_Wall, (int)t.getDefenses());
		}
		//Test get/setDebug
		TEST_METHOD(getSetDebug) {
			TownStats t{};
			t.setDebug(true);
			Assert::AreEqual(true, t.getDebug());
		}
		//Test updateStats
		TEST_METHOD(updateStats) {
			TownStats t{ defenses::Stone_Wall };
			Assert::AreEqual(8, t.getSupplies());
		}
	};

	//Unit tests for Roster class
	TEST_CLASS(RosterTests) {
		//Test accessors/mutators
		//Test get/setFaction
		TEST_METHOD(getSetFaction) {
			Roster r{};
			r.setFaction(faction::lerastir);
			Assert::AreEqual((int)faction::lerastir, (int)r.getFaction());
		}
		//Test get/setDebug
		TEST_METHOD(getSetDebug) {
			Roster r{};
			r.setDebug(true);
			Assert::AreEqual(true, r.getDebug());
		}
		//Test get/setFilePath
		TEST_METHOD(getSetFilePath) {
			Roster r{};
			r.setFilePath("Test Path");
			Assert::AreEqual((string)"Test Path", r.getFilePath());
		}
		//Test get/setUnits
		TEST_METHOD(getSetUnits) {
			Roster r{};
			Unit u{};
			u.setName("Test Unit");
			vector<Unit> v = { u,u,u };
			r.setUnits(v);
			Assert::AreEqual(3, (int)r.getUnits().size());
		}
		//Test getNumberOfUnits
		TEST_METHOD(getNumberOfUnits) {
			Roster r{};
			Unit u{};
			u.setName("Test Unit");
			vector<Unit> v = { u,u,u };
			r.setUnits(v);
			Assert::AreEqual(3, (int)r.getNumberOfUnits());
		}
		//Test getUnitAtIndex
		TEST_METHOD(getUnitAtIndex) {
			Roster r{};
			Unit u{};
			u.setName("Test Unit");
			vector<Unit> v = { u,u,u };
			u.setName("Test Name");
			v.push_back(u);
			r.setUnits(v);
			Assert::AreEqual((string)"Test Name", r.getUnitAtIndex(3).getName());

		}
		//Test getUnitsOfType
		TEST_METHOD(getUnitsOfType) {
			Roster r{};
			Unit u{};
			u.setUnitType(unitType::Melee);
			vector<Unit> v = { u,u,u };
			u.setUnitType(unitType::Cavalry);
			v.push_back(u);
			r.setUnits(v);
			Assert::AreEqual(1, (int)r.getUnitsOfType(unitType::Cavalry).size());
		}

		//Test buildRoster
		//Test Rebel reading
		TEST_METHOD(buildRosterRebel) {
			Roster r{};
			r.setFilePath("../AutoResolve/units.txt");
			r.setFaction(faction::rebel);
			r.buildRoster();
			Assert::AreEqual(9, r.getNumberOfUnits());
		}
		//Test Lerastir reading
		TEST_METHOD(buildRosterLerastir) {
			Roster r{};
			r.setFilePath("../AutoResolve/units.txt");
			r.setFaction(faction::lerastir);
			r.buildRoster();
			Assert::AreEqual(10, r.getNumberOfUnits());
		}
		//Test Beladimir reading
		TEST_METHOD(buildRosterBeladimir) {
			Roster r{};
			r.setFilePath("../AutoResolve/units.txt");
			r.setFaction(faction::beladimir);
			r.buildRoster();
			Assert::AreEqual(9, r.getNumberOfUnits());
		}
		//Test Menoriad reading
		TEST_METHOD(buildRosterMenoriad) {
			Roster r{};
			r.setFilePath("../AutoResolve/units.txt");
			r.setFaction(faction::menoriad);
			r.buildRoster();
			Assert::AreEqual(10, r.getNumberOfUnits());
		}
	};

	//Unit tests for Player class
	TEST_CLASS(PlayerTests) {
		//Test accessors/mutators
		//Test get/setDebug
		TEST_METHOD(getSetDebug) {
			Player p{};
			p.setDebug(true);
			Assert::AreEqual(true, p.getDebug());
		}
		//Test get/setGeneral
		TEST_METHOD(getSetGeneral) {
			Player p{};
			General g{};
			g.setRank(5);
			p.setGeneral(g);
			Assert::AreEqual(5, p.getGeneral().getRank());
		}
		//Test get/setAdvCombatDeck
		TEST_METHOD(getSetAdvCombatDeck) {
			Player p{};
			p.setAdvCombatDeck(true);
			Assert::AreEqual(true, p.getAdvComDeck());
		}
		//Test get/setReinforcements
		TEST_METHOD(getSetReinforcements) {
			Player p{};
			p.setReinforcements(4);
			Assert::AreEqual(4, p.getReinforcements());
		}
		//Test get/setFaction
		TEST_METHOD(getSetFaction) {
			Player p{};
			p.setFaction(faction::lerastir);
			Assert::AreEqual((int)faction::lerastir, (int)p.getFaction());
		}
		//Test getMelee
		TEST_METHOD(getMelee) {
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Melee);
			vector<Unit> v{ u,u,u };
			p.setPlayerUnits(v);
			Assert::AreEqual(12, p.getMelee());
		}
		//Test getRanged
		TEST_METHOD(getRanged) {
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Ranged);
			vector<Unit> v{ u,u,u };
			p.setPlayerUnits(v);
			Assert::AreEqual(12, p.getRanged());
		}
		//Test getCavalry
		TEST_METHOD(getCavalry) {
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Cavalry);
			vector<Unit> v{ u,u,u };
			p.setPlayerUnits(v);
			Assert::AreEqual(12, p.getCavalry());
		}
		//Test get/setPlayerUnits
		TEST_METHOD(getSetPlayerUnits) {
			Player p{};
			Unit u{};
			vector<Unit> v{ u,u,u };
			p.setPlayerUnits(v);
			Assert::AreEqual(3, (int)p.getPlayerUnits().size());
		}
		//Test getUnitAtIndex
		TEST_METHOD(getUnitAtIndex) {
			Player p{};
			Unit u{};
			u.setName("None");
			vector<Unit> v{ u,u,u };
			u.setName("Test Name");
			v.push_back(u);
			p.setPlayerUnits(v);
			Assert::AreEqual((string)"Test Name",p.getUnitAtIndex(3).getName());
		}
		//Test getNumberOfUnits
		TEST_METHOD(getNumberOfUnits) {
			Player p{};
			Unit u{};
			vector<Unit> v{ u,u,u };
			p.setPlayerUnits(v);
			Assert::AreEqual(3, p.getNumberOfUnits());
		}
		//Test getTotalSoldiers
		TEST_METHOD(getTotalSoldiers) {
			Player p{};
			Unit u{};
			u.setSoldiersPerUnit(4);
			u.setCurrentSoldiers(4);
			vector<Unit> v{ u,u,u };
			p.setPlayerUnits(v);
			Assert::AreEqual(12, p.getTotalSoldiers());
		}


	};

	//Unit tests for BattleData class
	TEST_CLASS(BattleDataTests) {
		//Test accessors/mutators
		//Test get/setDebug
		TEST_METHOD(getSetDebug) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			b.setDebug(true);
			Assert::AreEqual(true, b.getDebug());
		}

		//Test setBattleType
		TEST_METHOD(setBattleType) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			b.setBattleType(battleType::Naval);
			Assert::AreEqual(EnumerationConversions::to_string(battleType::Naval), b.getDataAtIndex(0));
		}
		//Test setAttacker general rank
		TEST_METHOD(setAttackerGeneralRank) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			General g{};
			Player p{};
			g.setRank(5);
			p.setGeneral(g);
			b.setAttacker(p);
			Assert::AreEqual((string)"5", b.getDataAtIndex(7));
		}
		//Test setAttacker general AR bonus
		TEST_METHOD(setAttackerGeneralARBonus) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			General g{};
			Equipment e{};
			e.setABonus(5);
			g.setArmor(e);
			g.setWeapon(e);
			Player p{};
			p.setGeneral(g);
			b.setAttacker(p);
			Assert::AreEqual((string)"10", b.getDataAtIndex(8));
		}
		//Test setAttacker general armor bonus
		TEST_METHOD(setAttackerGeneralArmor) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			General g{};
			Equipment e{};
			e.setABonus(5);
			g.setArmor(e);
			Player p{};
			p.setGeneral(g);
			b.setAttacker(p);
			Assert::AreEqual((string)"5", b.getDataAtIndex(9));
		}
		//Test setAttacker general weapon bonus
		TEST_METHOD(setAttackerGeneralWeapon) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			General g{};
			Equipment e{};
			e.setABonus(5);
			g.setWeapon(e);
			Player p{};
			p.setGeneral(g);
			b.setAttacker(p);
			Assert::AreEqual((string)"5", b.getDataAtIndex(10));
		}
		//Test setAttacker general follower bonus
		TEST_METHOD(setAttackerGeneralFollower) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			General g{};
			Equipment e{};
			e.setABonus(5);
			g.setFollower(e);
			Player p{};
			p.setGeneral(g);
			b.setAttacker(p);
			Assert::AreEqual((string)"5", b.getDataAtIndex(11));
		}
		//Test setAttacker general banner bonus
		TEST_METHOD(setAttackerGeneralBanner) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			General g{};
			Equipment e{};
			e.setABonus(5);
			g.setBanner(e);
			Player p{};
			p.setGeneral(g);
			b.setAttacker(p);
			Assert::AreEqual((string)"5", b.getDataAtIndex(12));
		}
		//Test setAttacker general trinket bonus
		TEST_METHOD(setAttackerGeneralTrinket) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			General g{};
			Equipment e{};
			e.setABonus(5);
			g.setTrinket(e);
			Player p{};
			p.setGeneral(g);
			b.setAttacker(p);
			Assert::AreEqual((string)"5", b.getDataAtIndex(13));
		}
		//Test setAttacker Adv Combat Deck
		TEST_METHOD(setAttackerAdvCombatDeck) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			p.setAdvCombatDeck(true);
			b.setAttacker(p);
			Assert::AreEqual((string)"1", b.getDataAtIndex(14));
		}
		//Test setAttacker Unit bonus
		TEST_METHOD(setAttackerUnitBonus) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			Unit u{};
			u.setARBonus(4);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setAttacker(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(15));
		}
		//Test setAttacker melee
		TEST_METHOD(setAttackerMelee) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Melee);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setAttacker(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(16));
		}
		//Test setAttacker ranged
		TEST_METHOD(setAttackerRanged) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Ranged);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setAttacker(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(17));
		}
		//Test setAttacker cavalry
		TEST_METHOD(setAttackerCavalry) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Cavalry);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setAttacker(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(18));
		}
		//Test setAttacker total soldiers
		TEST_METHOD(setAttackerTotalSoldiers) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			Unit u{};
			u.setCurrentSoldiers(4);
			u.setUnitType(unitType::Cavalry);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setAttacker(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(19));
		}
		//Test setAttacker number of units
		TEST_METHOD(setAttackerTotalUnits) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			Unit u{};
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setAttacker(p);
			Assert::AreEqual((string)"4", b.getDataAtIndex(63));
		}
		//Test setAttacker reinforcements
		TEST_METHOD(setAttackerReinforcements) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			p.setReinforcements(5);
			b.setAttacker(p);
			Assert::AreEqual((string)"5", b.getDataAtIndex(64));
		}
		//Test setDefender general rank
		TEST_METHOD(setDefenderGeneralRank) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			General g{};
			Player p{};
			g.setRank(5);
			p.setGeneral(g);
			b.setDefender(p);
			Assert::AreEqual((string)"5", b.getDataAtIndex(75));
		}
		//Test setDefender general AR bonus
		TEST_METHOD(setDefenderGeneralARBonus) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			General g{};
			Equipment e{};
			e.setABonus(5);
			g.setArmor(e);
			g.setWeapon(e);
			Player p{};
			p.setGeneral(g);
			b.setDefender(p);
			Assert::AreEqual((string)"10", b.getDataAtIndex(76));
		}
		//Test setDefender general armor bonus
		TEST_METHOD(setDefenderGeneralArmor) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			General g{};
			Equipment e{};
			e.setABonus(5);
			g.setArmor(e);
			Player p{};
			p.setGeneral(g);
			b.setDefender(p);
			Assert::AreEqual((string)"5", b.getDataAtIndex(77));
		}
		//Test setDefender general weapon bonus
		TEST_METHOD(setDefenderGeneralWeapon) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			General g{};
			Equipment e{};
			e.setABonus(5);
			g.setWeapon(e);
			Player p{};
			p.setGeneral(g);
			b.setDefender(p);
			Assert::AreEqual((string)"5", b.getDataAtIndex(78));
		}
		//Test setDefender general follower bonus
		TEST_METHOD(setDefenderGeneralFollower) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			General g{};
			Equipment e{};
			e.setABonus(5);
			g.setFollower(e);
			Player p{};
			p.setGeneral(g);
			b.setDefender(p);
			Assert::AreEqual((string)"5", b.getDataAtIndex(79));
		}
		//Test setDefender general banner bonus
		TEST_METHOD(setDefenderGeneralBanner) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			General g{};
			Equipment e{};
			e.setABonus(5);
			g.setBanner(e);
			Player p{};
			p.setGeneral(g);
			b.setDefender(p);
			Assert::AreEqual((string)"5", b.getDataAtIndex(80));
		}
		//Test setDefender general trinket bonus
		TEST_METHOD(setDefenderGeneralTrinket) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			General g{};
			Equipment e{};
			e.setABonus(5);
			g.setTrinket(e);
			Player p{};
			p.setGeneral(g);
			b.setDefender(p);
			Assert::AreEqual((string)"5", b.getDataAtIndex(81));
		}
		//Test setDefender Adv Combat Deck
		TEST_METHOD(setDefenderAdvCombatDeck) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			p.setAdvCombatDeck(true);
			b.setDefender(p);
			Assert::AreEqual((string)"1", b.getDataAtIndex(82));
		}
		//Test setDefender Unit bonus
		TEST_METHOD(setDefenderUnitBonus) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			Unit u{};
			u.setARBonus(4);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setDefender(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(83));
		}
		//Test setDefender melee
		TEST_METHOD(setDefenderMelee) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Melee);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setDefender(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(84));
		}
		//Test setDefender ranged
		TEST_METHOD(setDefenderRanged) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Ranged);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setDefender(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(85));
		}
		//Test setDefender cavalry
		TEST_METHOD(setDefenderCavalry) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Cavalry);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setDefender(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(86));
		}
		//Test setDefender total soldiers
		TEST_METHOD(setDefenderTotalSoldiers) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			Unit u{};
			u.setCurrentSoldiers(4);
			u.setUnitType(unitType::Cavalry);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setDefender(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(87));
		}
		//Test setDefender number of units
		TEST_METHOD(setDefenderTotalUnits) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			Unit u{};
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setDefender(p);
			Assert::AreEqual((string)"4", b.getDataAtIndex(131));
		}
		//Test setDefender reinforcements
		TEST_METHOD(setDefenderReinforcements) {
			BattleData b{(string)"../AutoResolve/units.txt"};
			Player p{};
			p.setReinforcements(5);
			b.setDefender(p);
			Assert::AreEqual((string)"5", b.getDataAtIndex(132));
		}

		//Test setAttackerRandoms
		TEST_METHOD(setAttackerRandoms) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			int r = Random::randomNumberGroup(10, 1, 10);
			b.setAttackerRandoms(r);
			Assert::AreEqual(to_string(r), b.getDataAtIndex(1));
		}
		//Test setDefenderRandoms
		TEST_METHOD(setDefenderRandoms) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			int r = Random::randomNumberGroup(10, 1, 10);
			b.setDefenderRandoms(r);
			Assert::AreEqual(to_string(r), b.getDataAtIndex(2));
		}
		//Test setAttackerGeneralState
		TEST_METHOD(setAttGenState) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			b.setAttackerGeneralState(generalState::Slain);
			Assert::AreEqual(EnumerationConversions::to_string(generalState::Slain),b.getDataAtIndex(68));
		}
		//Test setDefenderGeneralState
		TEST_METHOD(setDefGenState) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			b.setDefenderGeneralState(generalState::Slain);
			Assert::AreEqual(EnumerationConversions::to_string(generalState::Slain), b.getDataAtIndex(136));
		}
		//Test setSupplies
		TEST_METHOD(setSupplies) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			b.setSupplies(5);
			Assert::AreEqual((string)"5", b.getDataAtIndex(6));
		}
		//Test setOutcome
		TEST_METHOD(setOutcome) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			b.setOutcome(outcome::Decisive_Victory);
			Assert::AreEqual(EnumerationConversions::to_string(outcome::Decisive_Victory), b.getDataAtIndex(4));
		}
		//Test setAttackerWon
		TEST_METHOD(setAttackerWon) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			b.setAttackerWon(true);
			Assert::AreEqual((string)"1", b.getDataAtIndex(5));
		}
		//Test setAttackerCasualties unit
		TEST_METHOD(setAttackerCasualtiesUnit) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			vector<int> v = { 0,5 };
			b.setAttackerCasualties(v);
			Assert::AreEqual((string)"5", b.getDataAtIndex(66));
		}
		//Test setAttackerCasualties soldier
		TEST_METHOD(setAttackerCasualtiesSoldier) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			vector<int> v = { 5,0 };
			b.setAttackerCasualties(v); 
			Assert::AreEqual((string)"5", b.getDataAtIndex(67));
		}
		//Test setDefenderCasualties unit
		TEST_METHOD(setDefenderCasualtiesUnit) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			vector<int> v = { 0,5 };
			b.setDefenderCasualties(v);
			Assert::AreEqual((string)"5", b.getDataAtIndex(134));
		}
		//Test setDefenderCasualties soldier
		TEST_METHOD(setDefenderCasualtiesSoldier) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			vector<int> v = { 5,0 };
			b.setDefenderCasualties(v);
			Assert::AreEqual((string)"5", b.getDataAtIndex(135));
		}
		//Test setAttackerTreasureRec
		TEST_METHOD(setAttackerTreasureRec) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			b.setAttackerTreasureRec(true);
			Assert::AreEqual((string)"1", b.getDataAtIndex(69));
		}
		//Test setDefenderTreasureRec
		TEST_METHOD(setDefenderTreasureRec) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			b.setDefenderTreasureRec(true);
			Assert::AreEqual((string)"1", b.getDataAtIndex(137));
		}
		//Test setAttackerShips
		TEST_METHOD(setAttackerShips) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			b.setAttackerShips(5);
			Assert::AreEqual((string)"5", b.getDataAtIndex(71));
		}
		//Test setDefenderShips
		TEST_METHOD(setDefenderShips) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			b.setDefenderShips(5);
			Assert::AreEqual((string)"5", b.getDataAtIndex(139));
		}
		//Test setAttackerUpgrades
		TEST_METHOD(setAttackerUpgrades) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			b.setAttackerUpgrades(5);
			Assert::AreEqual((string)"5", b.getDataAtIndex(65));
		}
		//Test setDefenderUpgrades
		TEST_METHOD(setDefenderUpgrades) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			b.setDefenderUpgrades(5);
			Assert::AreEqual((string)"5", b.getDataAtIndex(133));
		}
		//Test setRams
		TEST_METHOD(setRams) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			b.setRams(5);
			Assert::AreEqual((string)"5", b.getDataAtIndex(72));
		}
		//Test setSiegeTowers
		TEST_METHOD(setSiegeTowers) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			b.setSiegeTowers(5);
			Assert::AreEqual((string)"5", b.getDataAtIndex(73));
		}
		//Test setCatapults
		TEST_METHOD(setCatapults) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			b.setCatapults(5);
			Assert::AreEqual((string)"5", b.getDataAtIndex(74));
		}
		//Test setTownStats
		TEST_METHOD(setTownStats) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			TownStats t{};
			t.setDefenses(defenses::Stone_Wall_W_Moat);
			b.setTownStats(t);
			Assert::AreEqual(EnumerationConversions::to_string(defenses::Stone_Wall_W_Moat), b.getDataAtIndex(140));
		}
		//Test setAttackerEnd unit bonus
		TEST_METHOD(setAttackerEndUnitBonus) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			Player p{};
			Unit u{};
			u.setARBonus(4);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setAttackerEnd(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(20));
		}
		//Test setAttackerEnd melee
		TEST_METHOD(setAttackerEndMelee) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Melee);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setAttackerEnd(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(21));
		}
		//Test setAttackerEnd ranged
		TEST_METHOD(setAttackerEndRanged) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Ranged);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setAttackerEnd(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(22));
		}
		//Test setAttackerEnd cavalry
		TEST_METHOD(setAttackerEndCavalry) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Cavalry);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setAttackerEnd(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(23));
		}
		//Test setAttackerEnd total soldiers
		TEST_METHOD(setAttackerEndTotalSoldiers) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			Player p{};
			Unit u{};
			u.setSoldiersPerUnit(4);
			u.setCurrentSoldiers(4);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setAttackerEnd(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(24));
		}
		//Test setDefenderEnd unit bonus
		TEST_METHOD(setDefenderEndUnitBonus) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			Player p{};
			Unit u{};
			u.setARBonus(4);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setDefenderEnd(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(88));
		}
		//Test setDefenderEnd melee
		TEST_METHOD(setDefenderEndMelee) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Melee);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setDefenderEnd(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(89));
		}
		//Test setDefenderEnd ranged
		TEST_METHOD(setDefenderEndRanged) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Ranged);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setDefenderEnd(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(90));
		}
		//Test setDefenderEnd cavalry
		TEST_METHOD(setDefenderEndCavalry) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			Player p{};
			Unit u{};
			u.setARBonus(4);
			u.setUnitType(unitType::Cavalry);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setDefenderEnd(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(91));
		}
		//Test setDefenderEnd total soldiers
		TEST_METHOD(setDefenderEndTotalSoldiers) {
			BattleData b{ (string)"../AutoResolve/units.txt" };
			Player p{};
			Unit u{};
			u.setSoldiersPerUnit(4);
			u.setCurrentSoldiers(4);
			vector<Unit> v = { u,u,u,u };
			p.setPlayerUnits(v);
			b.setDefenderEnd(p);
			Assert::AreEqual((string)"16", b.getDataAtIndex(92));
		}
	};

	//Unit tests for Battle class
	TEST_CLASS(BattleTests) {
		//Test accessors/mutators
		//Test get/setAttacker
		TEST_METHOD(getSetAttacker) {
			Player p{};
			p.setAdvCombatDeck(true);
			Battle b((string)"../AutoResolve/units.txt");
			b.setAttacker(p);
			Assert::AreEqual(true, b.getAttacker().getAdvComDeck());
		}
		//Test get/setDefender
		TEST_METHOD(getSetDefender) {
			Player p{};
			p.setAdvCombatDeck(true);
			Battle b((string)"../AutoResolve/units.txt");
			b.setDefender(p);
			Assert::AreEqual(true, b.getDefender().getAdvComDeck());
		}
		//Test get/setOutcome
		TEST_METHOD(getSetOutcome) {
			Battle b ((string)"../AutoResolve/units.txt");
			b.setOutcome(outcome::Decisive_Victory);
			Assert::AreEqual((int)outcome::Decisive_Victory, (int)b.getOutcome());
		}
		//Test get/setBattleType
		TEST_METHOD(getSetBattleType) {
			Battle b((string)"../AutoResolve/units.txt");
			b.setBattleType(battleType::Monster);
			Assert::AreEqual((int)battleType::Monster, (int)b.getBattleType());
		}
		//Test get/setDebug
		TEST_METHOD(getSetDebug) {
			Battle b((string)"../AutoResolve/units.txt");
			b.setDebug(true);
			Assert::AreEqual(true, b.getDebug());
		}
		//Test get/setOutput
		TEST_METHOD(getSetOutput) {
			Battle b((string)"../AutoResolve/units.txt");
			b.setOutput(false);
			Assert::AreEqual(false, b.getOutput());
		}
		//Test get/setFileOut
		TEST_METHOD(getSetFileOut) {
			Battle b((string)"../AutoResolve/units.txt");
			b.setFileOut(true);
			Assert::AreEqual(true, b.getFileOutBool());
		}
		//Test get/setFileName
		TEST_METHOD(getSetFileName) {
			Battle b((string)"../AutoResolve/units.txt");
			b.setFileName("Test Name");
			Assert::AreEqual((string)"Test Name", b.getFileName());
		}
		//Test treasureResults attacker positive, defender positive
		TEST_METHOD(treasureResultsAttPosDefPos) {
			Equipment e{};
			e.setABonus(8);
			General g{};
			g.setFollower(e);
			Player p{};
			p.setGeneral(g);
			Battle b((string)"../AutoResolve/units.txt");
			b.setAttacker(p);
			e.setABonus(8);
			g.setFollower(e);
			p.setGeneral(g);
			b.setDefender(p);
			Treasure t{};
			t.setFilePath((string)"../AutoResolve/equipment.txt");
			t.initialize();
			b.setTreasure(&t);
			b.treasureResults();
			bool att = (b.getFoundByAttacker().getName() != "No Treasure");
			bool def = (b.getFoundByDefender().getName() != "No Treasure");
			Assert::IsTrue(att && def);

		}
		//Test treasureResults attacker positive, defender negative
		TEST_METHOD(treasureResultsAttPosDefNeg) {
			Equipment e{};
			e.setABonus(8);
			General g{};
			g.setFollower(e);
			Player p{};
			p.setGeneral(g);
			Battle b{ (string)"../AutoResolve/units.txt" };
			b.setAttacker(p);
			e.setABonus(-8);
			g.setFollower(e);
			p.setGeneral(g);
			b.setDefender(p);
			Treasure t{};
			t.setFilePath((string)"../AutoResolve/equipment.txt");
			t.initialize();
			b.setTreasure(&t);
			b.treasureResults();
			bool att = (b.getFoundByAttacker().getName() != "No Treasure");
			bool def = (b.getFoundByDefender().getName() == "No Treasure");
			Assert::IsTrue(att && def);

		}
		//Test treasureResults attacker negative, defender positive
		TEST_METHOD(treasureResultsAttNegDefPos) {
			Equipment e{};
			e.setABonus(-8);
			General g{};
			g.setFollower(e);
			Player p{};
			p.setGeneral(g);
			Battle b{ (string)"../AutoResolve/units.txt" };
			b.setAttacker(p);
			e.setABonus(8);
			g.setFollower(e);
			p.setGeneral(g);
			b.setDefender(p);
			Treasure t{};
			t.setFilePath((string)"../AutoResolve/equipment.txt");
			t.initialize();
			b.setTreasure(&t);
			b.treasureResults();
			bool att = (b.getFoundByAttacker().getName() == "No Treasure");
			bool def = (b.getFoundByDefender().getName() != "No Treasure");
			Assert::IsTrue(att && def);

		}
		//Test treasureResults attacker negative, defender negative
		TEST_METHOD(treasureResultsAttNegDefNeg) {
			Equipment e{};
			e.setABonus(-8);
			General g{};
			g.setFollower(e);
			Player p{};
			p.setGeneral(g);
			Battle b{ (string)"../AutoResolve/units.txt" };
			b.setAttacker(p);
			e.setABonus(-8);
			g.setFollower(e);
			p.setGeneral(g);
			b.setDefender(p);
			Treasure t{};
			t.setFilePath((string)"../AutoResolve/equipment.txt");
			t.initialize();
			b.setTreasure(&t);
			b.treasureResults();
			bool att = (b.getFoundByAttacker().getName() == "No Treasure");
			bool def = (b.getFoundByDefender().getName() == "No Treasure");
			Assert::IsTrue(att && def);

		}
		
		//Test assignCasualties
		TEST_METHOD(assignCasualties) {
			vector<int> cas{
				10, //Soldier casualties
				2,	//Unit casualties
				0, }; //Upgrades 

			Unit u{};
			u.setSoldiersPerUnit(4);
			u.setCurrentSoldiers(4);
			vector<Unit> v  {u,u,u,u,u};
			Player p{};
			p.setPlayerUnits(v);
			Battle b{ (string)"../AutoResolve/units.txt" };
			b.assignCasualties(cas, p);
			Assert::AreEqual(10, p.getTotalSoldiers());
			
		}
		//Test assignCasualties with 0 soldier casualties
		TEST_METHOD(assignCasualtiesZeroSoldierCas) {
			vector<int> cas{
				0, //Soldier casualties
				2,	//Unit casualties
				0, }; //Upgrades 

			Unit u{};
			u.setSoldiersPerUnit(4);
			u.setCurrentSoldiers(4);
			vector<Unit> v{ u,u,u,u,u };
			Player p{};
			p.setPlayerUnits(v);
			Battle b{ (string)"../AutoResolve/units.txt" };
			b.assignCasualties(cas, p);
			Assert::AreEqual(20, p.getTotalSoldiers());

		}
		//Test assignCasualties with 0 unit casualties
		TEST_METHOD(assignCasualtiesZeroUnitCas) {
			vector<int> cas{
				10, //Soldier casualties
				0,	//Unit casualties
				0, }; //Upgrades 

			Unit u{};
			u.setSoldiersPerUnit(4);
			u.setCurrentSoldiers(4);
			vector<Unit> v{ u,u,u,u,u };
			Player p{};
			p.setPlayerUnits(v);
			Battle b{ (string)"../AutoResolve/units.txt" };
			b.assignCasualties(cas, p);
			Assert::AreEqual(10, p.getTotalSoldiers());
			Assert::AreEqual(5, p.getNumberOfUnits());

		}
		//Test assignCasualties with fewer units than unit casualties
		TEST_METHOD(assignCasualtiesFewerUnitCas) {
			vector<int> cas{
				20, //Soldier casualties
				6,	//Unit casualties
				0, }; //Upgrades 

			Unit u{};
			u.setSoldiersPerUnit(4);
			u.setCurrentSoldiers(4);
			vector<Unit> v{ u,u,u,u,u };
			Player p{};
			p.setPlayerUnits(v);
			Battle b{ (string)"../AutoResolve/units.txt" };
			b.assignCasualties(cas, p);
			Assert::AreEqual(0, p.getNumberOfUnits());

		}
		//Test assignCasualties with fewer soldiers than soldier casualties
		TEST_METHOD(assignCasualtiesFewerSoldierCas) {
			vector<int> cas{
				25, //Soldier casualties
				5,	//Unit casualties
				0, }; //Upgrades 

			Unit u{};
			u.setSoldiersPerUnit(4);
			u.setCurrentSoldiers(4);
			vector<Unit> v{ u,u,u,u,u };
			Player p{};
			p.setPlayerUnits(v);
			Battle b{ (string)"../AutoResolve/units.txt" };
			b.assignCasualties(cas, p);
			Assert::AreEqual(0, p.getTotalSoldiers());
			Assert::AreEqual(0, p.getNumberOfUnits());

		}
		//Test assignCasualties with more soldier cas than can be had considering unit cas
		TEST_METHOD(assignCasualtiesFewerSoldierUnitCas) {
			vector<int> cas{
				21, //Soldier casualties
				1,	//Unit casualties
				0, }; //Upgrades 

			Unit u{};
			u.setSoldiersPerUnit(4);
			u.setCurrentSoldiers(4);
			vector<Unit> v{ u,u,u,u,u };
			Player p{};
			p.setPlayerUnits(v);
			Battle b{ (string)"../AutoResolve/units.txt" };
			b.assignCasualties(cas, p);
			Assert::AreEqual(0, p.getNumberOfUnits());
			Assert::AreEqual(0, p.getTotalSoldiers());
		}

		//Test determineOutcome
		//Test determineOutcome decisive victory
		TEST_METHOD(determineOutcomeDecisiveVictory) {
			Battle b((string)"../AutoResolve/units.txt");
			b.determineOutcome(20);
			Assert::AreEqual((int)outcome::Decisive_Victory, (int)b.getOutcome());
		}
		//Test determineOutcome heroic victory
		TEST_METHOD(determineOutcomeHeroicVictory) {
			Battle b((string)"../AutoResolve/units.txt");
			b.determineOutcome(10);
			Assert::AreEqual((int)outcome::Heroic_Victory, (int)b.getOutcome());
		}
		//Test determineOutcome close victory
		TEST_METHOD(determineOutcomeCloseVictory) {
			Battle b((string)"../AutoResolve/units.txt");
			b.determineOutcome(3);
			Assert::AreEqual((int)outcome::Close_Victory, (int)b.getOutcome());
		}
		//Test determineOutcome crushing defeat
		TEST_METHOD(determineOutcomeCrushingDefeat) {
			Battle b((string)"../AutoResolve/units.txt");
			b.determineOutcome(-20);
			Assert::AreEqual((int)outcome::Crushing_Defeat, (int)b.getOutcome());
		}
		//Test determineOutcome valiant defeat
		TEST_METHOD(determineOutcomeValiantDefeat) {
			Battle b((string)"../AutoResolve/units.txt");
			b.determineOutcome(-10);
			Assert::AreEqual((int)outcome::Valiant_Defeat, (int)b.getOutcome());
		}
		//Test determineOutcome close defeat
		TEST_METHOD(determineOutcomeCloseDefeat) {
			Battle b((string)"../AutoResolve/units.txt");
			b.determineOutcome(-3);
			Assert::AreEqual((int)outcome::Close_Defeat, (int)b.getOutcome());
		}
		//Test determineOutcome draw
		TEST_METHOD(determineOutcomeDraw) {
			Battle b((string)"../AutoResolve/units.txt");
			b.determineOutcome(0);
			Assert::AreEqual((int)outcome::Draw, (int)b.getOutcome());
		}
	};

	//Unit tests for Normal Battle class
	TEST_CLASS(NormalBattleTests) {
		//None should be needed
	};

	//Unit tests for Naval Battle class
	TEST_CLASS(NavalBattleTests) {
		//Test get/setAttackerShips
		TEST_METHOD(getSetAttackerShips) {
			NavalBattle b ((string)"../AutoResolve/units.txt");
			b.setAttackerShips(5);
			Assert::AreEqual(5, b.getAttackerShips());
		}
		//Test get/setDefenderShips
		TEST_METHOD(getSetDefenderShips) {
			NavalBattle b ((string)"../AutoResolve/units.txt");
			b.setDefenderShips(5);
			Assert::AreEqual(5, b.getDefenderShips());
		}
	};

	//Unit tests for Siege Battle class
	TEST_CLASS(SiegeBattleTests) {
		//Test get/setRams
		TEST_METHOD(getSetRams) {
			SiegeBattle b ((string)"../AutoResolve/units.txt");
			b.setRams(5);
			Assert::AreEqual(5, b.getRams());
		}
		//Test get/set Siege Towers
		TEST_METHOD(getSetSiegeTowers) {
			SiegeBattle b((string)"../AutoResolve/units.txt");
			b.setSiegeTowers(5);
			Assert::AreEqual(5, b.getSiegeTowers());
		}
		//Test get/set Catapults
		TEST_METHOD(getSetCatapults) {
			SiegeBattle b ((string)"../AutoResolve/units.txt");
			b.setCatapults(5);
			Assert::AreEqual(5, b.getCatapults());
		}
		//Test get/set Town Stats
		TEST_METHOD(getSetTownStats) {
			SiegeBattle b ((string)"../AutoResolve/units.txt");
			TownStats t{};
			t.setSupplies(5);
			b.setTownStats(t);
			Assert::AreEqual(5, b.getTownStats().getSupplies());
		}
	};

	//Unit tests for Raid Battle class
	TEST_CLASS(RaidBattleTests) {
		//Test get/set Town Stats
		TEST_METHOD(getSetTownStats){
			RaidBattle b ((string)"../AutoResolve/units.txt");
			TownStats t{};
			t.setSupplies(5);
			b.setTownStats(t);
			Assert::AreEqual(5, b.getTownStats().getSupplies());
		}
	};

	//Unit tests for Monster Battle class
	TEST_CLASS(MonsterBattleTests) {
		//Test get/set Monster
		TEST_METHOD(getSetMonster) {
			MonsterBattle b ((string)"../AutoResolve/units.txt");
			Monster m{(string)"../AutoResolve/equipment.txt"};
			m.setMonsterType(monsterType::Demon);
			b.setMonster(m);
			Assert::AreEqual((int)monsterType::Demon, (int)b.getMonster().getMonsterType());
		}
	};

	//Unit tests for TestBattle class
	TEST_CLASS(TestBattleTests) {
		
	};
}
