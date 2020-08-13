#pragma once
#include "Equipment.h"
#include "faction.h"
#include "generalState.h"
#include <algorithm>
#include <cmath>

#include <array>
#include <vector>
#include <string>

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;
class General //This is used by the Player class
{
private:
	int rank;
	int AutoResEqBonus; //Auto resolve bonus from Equipment
	Equipment armor;
	Equipment weapon;
	Equipment trinket;
	Equipment banner;
	Equipment follower;
	generalState currentState;
	bool debug;

public:
	~General();
	General();
	General(const bool debugI);
	General(const int rankI, const Equipment armorI, const Equipment weaponI, 
		const Equipment trinketI, const Equipment bannerI, const Equipment followerI);
	void updateARBonus();

	int getRank() const{ 
		return rank;};
	int getARBonus() const{ 
		return AutoResEqBonus; };
	Equipment getArmor() const{ 
		return armor; };
	Equipment getWeapon() const{ 
		return weapon; };
	Equipment getTrinket() const{ 
		return trinket; };
	Equipment getBanner() const{ 
		return banner; };
	Equipment getFollower() const{ 
		return follower; };
	generalState getState() const {
		return currentState; };

	void setRank(const int rankI) { 
		rank = rankI; };
	void setArmor(const Equipment equipI) { 
		armor = equipI;
		armor.setDebug(debug);
		updateARBonus();};
	void setWeapon(const Equipment equipI) { 
		weapon = equipI; 
		weapon.setDebug(debug);
		updateARBonus();};
	void setTrinket(const Equipment equipI) { 
		trinket = equipI;
		trinket.setDebug(debug);
		updateARBonus();};
	void setBanner(const Equipment equipI) { 
		banner = equipI; 
		banner.setDebug(debug);
		updateARBonus();};
	void setFollower(const Equipment equipI) { 
		follower = equipI;
		follower.setDebug(debug);
		updateARBonus();};
	void setState(const generalState state) {
		currentState = state; };

	bool getDebug() const { return debug; };
	void setDebug(const bool debugI) {
		if (debugI) { cout << "general setDebug called" << endl; }
		debug = debugI;
		armor.setDebug(debug);
		weapon.setDebug(debug);
		trinket.setDebug(debug);
		banner.setDebug(debug);
		follower.setDebug(debug);
	};
	void printData() const;
};
