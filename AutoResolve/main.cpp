/*
* main.cpp
*
* Created on: May 6, 2020
*   Author: Lafe Wessel
*/

#pragma once
#include <algorithm>
#include <cmath>

#include <vector>
#include <string>

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <chrono>
#include <random>

/*
#include "Battle.h"
#include "CSVRow.h"
#include "defenses.h"
#include "Equipment.h"
#include "faction.h"
#include "General.h"
#include "Monster.h"
#include "MonsterBattle.h"


#include "monsterType.h"
#include "NavalBattle.h"
#include "NormalBattle.h"
#include "outcome.h"
#include "Player.h"
#include "RaidBattle.h"
#include "Roster.h"
#include "SiegeBattle.h"
#include "townStats.h"
#include "Treasure.h"
#include "Unit.h"
#include "unitType.h"
#include "BattleData.h"
*/

using namespace std;

/*
TODO Section:

TODO-Make a way for the tests to use solely randomized values
TODO-Make a way for all the data in a battle, including results, cas, etc. to be captured in an array/vector
TODO-Make sure that casualties are actually assigned for MonsterBattle
TODO-Make each battle write to a certain file and each have boolean for whether or not they write to the file
TODO-Implement a Gaussian distribution for random results for BattleRandoms calculations, centering distribution at 5 (?)
TODO-Change win-loss ratio in tests to be % wins
TODO-add const where appropriate in function signatures
TODO-Create an auto-balancing feature to determine what is an equal distribution of power -> AI
TODO-Can use a model to determine what contributes most to success?
TODO-Can make a db of results from numerous battles then analyze it with R or python
TODO-Add Randoms class, implement functions as static so they can be called without instantiating Random object
TODO-Learn and implement Qt GUI
*/





//Called on program start
int main()
{
	bool cont = true;

	//Initialize BattleData.csv if it hasn't already been
	string fileName = "BattleData.csv";
	fstream file;
	file.open(fileName);
	if (!file) {
		cerr << "Unable to open BattleData.csv" << endl;
	}
	else {
		cout << "BattleData.csv opened and closed" << endl;
		file.close();
	}

	   	 
	while(cont) {
		bool debug = false;
		bool fileOut = false;
		char toDebug = 'a';//Placeholder character

		//Check to see if user wants to debug application
		while (toDebug != 'y' && toDebug != 'n')
		{
			cout << "Would you like to debug? (y/n)" << endl;
			cin >> toDebug;
			cin.get();
		}
		if (toDebug == 'y')
		{
			debug = true;
		}

		//Check to see if user wants to send results to BattleData.csv
		toDebug = 'a';
		while (toDebug != 'y' && toDebug != 'n')
		{
			cout << "Would you like to output results to a file? (y/n)" << endl;
			cin >> toDebug;
			cin.get();
		}
		if (toDebug == 'y')
		{
			fileOut = true;
		}


		if (debug) { cout << "Program started" << endl; }

		//Get the number of tests the user would like to perform
		int tests = 1;
		cout << "How many tests:" << endl;
		cin >> tests;
		cin.get();
		tests = abs(tests);
		if (debug) { cout << "Tests set to: " << tests << endl; }
	
		//Check to see if user wants to use randomized values
		char randomTest = 'a';
		while (randomTest != 'y' && randomTest != 'n')
		{
			cout << "Would you like to test with randomized values? (y/n)" << endl;
			cin >> randomTest;
			cin.get();
			//	cout << toDebug <<  endl;
		}
		

		//TODO uncomment 2 next comments
		if (randomTest == 'y') {
			//randomizedTests(tests, debug, fileOut, fileName);
		}
		else {
			//standardTests(tests, debug, fileOut, fileName);
		}

		if (debug) { cout << "Program finished, press Enter to continue" << endl; }
		cin.get();//This keeps the console window open
		
		//Check to see if the user would like to perform more tests
		char toCont = 'a';
		while (toCont != 'y' && toCont != 'n')
		{
			cout << "Would you like to make more calculations? (y/n)" << endl;
			cin >> toCont;
			cin.get();
			//	cout << toDebug <<  endl;
		}
		if (toCont == 'y') {
			cont = true;
		}
		else {
			cont = false;
		}
	}
	

	return 0;
}
