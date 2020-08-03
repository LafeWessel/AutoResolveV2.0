/*
* main.cpp
*
* Created on: May 6, 2020
*   Author: Lafe Wessel
*/

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <random>

#include "TestBattle.h"


using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
TODO-Make a way for the tests to use solely randomized values

TODO-implement BattleData class

TODO-Make each battle write to a certain file and each have boolean for whether or not they write to the file

TODO-Change win-loss ratio in tests to be % wins

TODO-Create an auto-balancing feature to determine what is an equal distribution of power -> AI

TODO-Make a db of results from numerous battles then analyze it with python

TODO-Learn and implement Qt GUI

*/

bool continueLoop(string loop) {
	char toCont = 'a';
	while (toCont != 'y' && toCont != 'n')
	{
		cout << loop << "(y/n)" << endl;
		cin >> toCont;
		cin.get();
	}
	if (toCont == 'y') {
		return true;
	}
	else {
		return false;
	}
}


void runApp() {
	do {
		bool debug = continueLoop((string)"Would you like to debug?");
		bool fileOut = continueLoop((string)"Would you like to output results to a file?");

		if (debug) { cout << "Program started" << endl; }

		//Get the number of tests the user would like to perform
		int tests = 1;
		cout << "How many tests:" << endl;
		cin >> tests;
		cin.get();
		tests = abs(tests);
		if (debug) { cout << "Tests set to: " << tests << endl; }

		int type = 1;
		cout << "What type (Normal:1, Siege:2, Raid:3, Naval:4, Monster:5)" << endl;
		cin >> type;
		cin.get();
		type = ValueAssurance::inputCheck(tests,5,1);
		if (debug) { cout << "Type set to: " << type << endl; }

		TestBattle t{};
		t.setNumberOfTests(tests);
		t.setBattleType(EnumerationConversions::intToBattleType(type));
		t.initializeAndRun();

		if (debug) { cout << "Calculations finished, press Enter to continue" << endl; }
		cin.get();//This keeps the console window open

	} while (continueLoop((string)"Would you like to make more calculations?"));




}

//Called on program start
int main()
{	

	//Initialize BattleData.csv if it hasn't already been
	//string fileName = "BattleData.csv";
	//fstream file;
	//file.open(fileName);
	//if (!file) {
	//	cerr << "Unable to open BattleData.csv" << endl;
	//}
	//else {
	//	cout << "BattleData.csv opened and closed" << endl;
	//	file.close();
	//} 
	
	runApp();


	TestBattle t{};
	t.setBattleType(battleType::Siege);
	t.setNumberOfTests(1);
	t.initializeAndRun();


	return 0;
}
