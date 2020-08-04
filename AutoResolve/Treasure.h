#pragma once
#include "CSVRow.h"
#include "Equipment.h"
#include "CSVDataReader.h"
#include "Random.h"

#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <iostream>

//This class keeps all the equipment to allow for finding of specific equipment and battle loot calculation
class Treasure 
{

private:
	vector<Equipment> armor;
	vector<Equipment> weapon;
	vector<Equipment> trinket;
	vector<Equipment> banner;
	vector<Equipment> follower;
	vector<Equipment> dragon;
	bool debug;
	bool initialized;
	string equipmentFilePath = "equipment.txt";

	void sortEquipment(vector<Equipment> toSort);

public:
	~Treasure();
	Treasure();
	Treasure(const bool debugI);
	Treasure(const vector<Equipment> armorI, const vector<Equipment> weaponI, const vector<Equipment> trinketI, 
		const vector<Equipment> bannerI, const vector<Equipment> followerI, const vector<Equipment> dragonI, const bool debugI);
	
	/*
	Returns an empty equipment class with name "No Treasure"
	*/
	 Equipment noTreasure()const{
		Equipment empty{ "No Treasure",0,0,0,equipmentType::null,"",0 };
		return empty;
	};

	//Subtracts 1 from the array so that it doesn't run off the end of the array of equipment
	 Equipment findArmor()const;
	 Equipment findWeapon()const;
	 Equipment findTrinket()const;
	 Equipment findBanner()const;
	 Equipment findDragonEq()const;
	 Equipment findFollower()const;

	 vector<Equipment> getArmorVector() const { return armor; };
	 vector<Equipment> getWeaponVector() const { return weapon; };
	 vector<Equipment> getTrinketVector() const { return trinket; };
	 vector<Equipment> getBannerVector() const { return banner; };
	 vector<Equipment> getFollowerVector() const { return follower; };
	 vector<Equipment> getDragonVector() const { return dragon; };

	 Equipment findTreasure(const int bonus)const; //Used at the end of battles to determine loot results

	void setArmorVector(const vector<Equipment> equipVectorI) { 
		armor = equipVectorI; 
		for (int i = 0; i < armor.size(); i++) {
			armor[i].setDebug(debug);
		}
	};
	void setWeaponVector(const vector<Equipment> equipVectorI) {
		weapon = equipVectorI;
		for (int i = 0; i < weapon.size(); i++) {
			weapon[i].setDebug(debug);
		}
	};
	void setTrinketVector(const vector<Equipment> equipVectorI) {
		trinket = equipVectorI;
		for (int i = 0; i < trinket.size(); i++) {
			trinket[i].setDebug(debug);
		}
	};
	void setBannerVector(const vector<Equipment> equipVectorI) {
		banner = equipVectorI;
		for (int i = 0; i < banner.size(); i++) {
			banner[i].setDebug(debug);
		}
	};
	void setFollowerVector(const vector<Equipment> equipVectorI) {
		follower = equipVectorI;
		for (int i = 0; i < follower.size(); i++) {
			follower[i].setDebug(debug);
		}
	};
	void setDragonVector(const vector<Equipment> equipVectorI) {
		dragon = equipVectorI;
		for (int i = 0; i < dragon.size(); i++) {
			dragon[i].setDebug(debug);
		}
	};

	bool isInitialized() const { return initialized; };
	bool getDebug() const{ return debug; }
	void setDebug(const bool debugI);
	string getFilePath() const { return equipmentFilePath; };
	void setFilePath(const string filePath) { equipmentFilePath = filePath; };
	void printEquipmentVector(const vector<Equipment>& equipVector, const string name)const;
	void printData()const;

	void initialize(); //This grabs all the data from the file containing the equipment
};

