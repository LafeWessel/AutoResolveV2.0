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

TODO-implement Monster and MonsterBattle for BattleData

TODO-Make each battle write to a certain file and each have boolean for whether or not they write to the file

TODO-Make a db of results from tests then analyze

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
		bool output = continueLoop((string)"Would you like to output results to a file?");
		//Get the number of tests the user would like to perform
		int tests = 1;
		cout << "How many tests:" << endl;
		cin >> tests;
		cin.get();
		if (debug) { cout << "Tests set to: " << tests << endl; }

		int type = 1;
		cout << "What type (Normal:1, Siege:2, Raid:3, Naval:4, Monster:5)" << endl;
		cin >> type;
		type = ValueAssurance::inputCheck(type,5,1);
		if (debug) { cout << "Type set to: " << type << endl; }

		Treasure treasure = new Treasure();
		treasure.setDebug(debug);
		treasure.initialize();

		TestBattle t{};
		t.setTreasure(&treasure);
		t.setNumberOfTests(tests);
		t.setBattleType((battleType)(type));
		t.setDebug(debug);
		t.setOutputToFile(output);
		t.initializeAndRun();


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



	return 0;
}
