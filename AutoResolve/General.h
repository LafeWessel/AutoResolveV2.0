#pragma once
#include "Equipment.h"
#include "faction.h"
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
	bool debug;

public:
	~General();
	General();
	General(const bool debugI);
	General(const int rankI, const Equipment armorI, const Equipment weaponI, 
		const Equipment trinketI, const Equipment bannerI, const Equipment followerI);
	void updateARBonus();

	int getRank() const{ 
		if (debug) { cout << "general rank gotten: " << rank << endl; }
		return rank;};
	int getARBonus() const{ 
		if (debug) { cout << "general autoResolveBonus gotten: " << AutoResEqBonus << endl; }
		return AutoResEqBonus; };
	Equipment getArmor() const{ 
		if (debug) { cout << "general armor gotten: " << armor.getName() << endl; }
		return armor; };
	Equipment getWeapon() const{ 
		if (debug) { cout << "general weapon gotten: " << weapon.getName() << endl; }
		return weapon; };
	Equipment getTrinket() const{ 
		if (debug) { cout << "general trinket gotten: " << trinket.getName() << endl; }
		return trinket; };
	Equipment getBanner() const{ 
		if (debug) { cout << "general banner gotten: " << banner.getName() << endl; }
		return banner; };
	Equipment getFollower() const{ 
		if (debug) { cout << "general follower gotten: " << follower.getName() << endl; }
		return follower; };

	void setRank(int rankI) { 
		if (debug) { cout << "general rank set to: " << rankI << endl; }
		rank = rankI; 
	};
	void setArmor(const Equipment equipI) { 
		if (debug) { cout << "general armor set to: " << equipI.getName() << endl; }
		armor = equipI;
		armor.setDebug(debug);
		updateARBonus();};
	void setWeapon(const Equipment equipI) { 
		if (debug) { cout << "general weapon set to: " << equipI.getName() << endl; }
		weapon = equipI; 
		weapon.setDebug(debug);
		updateARBonus();};
	void setTrinket(const Equipment equipI) { 
		if (debug) { cout << "general trinket set to: " << equipI.getName() << endl; }
		trinket = equipI;
		trinket.setDebug(debug);
		updateARBonus();};
	void setBanner(const Equipment equipI) { 
		if (debug) { cout << "general banner set to: " << equipI.getName() << endl; }
		banner = equipI; 
		banner.setDebug(debug);
		updateARBonus();};
	void setFollower(const Equipment equipI) { 
		if (debug) { cout << "general follower set to: " << equipI.getName() << endl; }
		follower = equipI;
		follower.setDebug(debug);
		updateARBonus();};

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
