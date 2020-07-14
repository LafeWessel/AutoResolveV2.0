#pragma once
#include "faction.h"
#include "General.h"
#include "Player.h"
#include "Roster.h"
#include "Unit.h"
#include "EnumerationConversions.h"

#include <vector>
#include <string>

#include <iostream>

class Player //This is used in every kind of battle.
{
private:

	vector<Unit> playerUnits;
	int Melee; //Melee autoresolve bonus total
	int Cavalry; //Cavalry autoresolve bonus total
	int Ranged; //Ranged autoresolve bonus total
	General general;
	bool AdvCombatDeck;
	faction fact;
	bool debug;
	int Reinforcements;

	void setupUnitAutoresolveBonuses();

public:
	~Player();
	Player();
	Player(bool debugI);
	Player(vector<Unit> unitsI, General generalI, int ReinforceI, bool AdvCombatDeckI, faction FactI);

	vector<Unit> getPlayerUnits() const{ 
		return playerUnits; };
	int getMelee() const{ 
		return Melee; };
	int getCavalry() const{ 
		return Cavalry; };
	int getRanged() const{ 
		return Ranged; };
	int getReinforcements() const{
		return Reinforcements; };
	General getGeneral() const{ 
		return general; };
	bool getAdvComDeck() const{ 
		return AdvCombatDeck; };
	faction getFaction() const{
		return fact; };
	Unit getUnitAtIndex(const int index) const{ 
		if (index >= 0 && index < playerUnits.size()){
			if (debug) { cout << playerUnits[index].getName() << endl; }
			return playerUnits[index];
		}else{
			cerr << "player invalid unit vector index selected: " << index << endl;
			return Unit{};
		}
	};
	int getNumberOfUnits() const{ 
		return playerUnits.size(); };
	int getTotalSoldiers() const{
		int totalSoldiers = 0;
		for (int i = 0; i < playerUnits.size(); i++) {
			totalSoldiers += playerUnits[i].getCurrentSoldiers();
		}
		return totalSoldiers;
	}

	void setReinforcements(const int ReinforceI);
	void setPlayerUnits(const vector<Unit> unitsI);
	void setGeneral(const General generalI) { 
		general = generalI;
		general.setDebug(debug);};
	void setAdvCombatDeck(const bool advComDeckI) { 
		AdvCombatDeck = advComDeckI; };
	void setFaction(const faction factionI) { 
		fact = factionI; };
	
	bool getDebug() const{ return debug; }
	void setDebug(const bool debugI) {
		debug = debugI;
		general.setDebug(debug);
		for (int i = 0; i < playerUnits.size(); i++) {
			playerUnits[i].setDebug(debug);
		}
	}
	void printData() const;
};
