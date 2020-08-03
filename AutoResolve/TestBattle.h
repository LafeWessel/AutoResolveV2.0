#pragma once
#include "NormalBattle.h"
#include "NavalBattle.h"
#include "SiegeBattle.h"
#include "RaidBattle.h"
#include "MonsterBattle.h"

/*
Requirements:


- Must create and run a battle of a given type

- Must be able to save the results to a file if specified

- Must be able to run tests an arbitrary amount of times


*/



class TestBattle
{
private:
	bool debug;
	bool outputToFile;
	int numberOfTests;
	string outputFile;
	battleType type;

	void initBattle(Battle& b);
	void runTest(vector<int>& outcomes);
	void setFileString();
	void initPlayer(Player& p, const Treasure* t);
	

public:
	~TestBattle();
	TestBattle();

	void initializeAndRun();

	void setOutputToFile(const bool output) {
		outputToFile = output; };
	void setDebug(const bool debug) {
		this->debug = debug; };
	void setNumberOfTests(const int numTests) {
		numberOfTests = numTests; };
	void setOutputFile(const string file) {
		outputFile = file; };
	void setBattleType(const battleType type) {
		this->type = type;
		setFileString(); };


	bool getDebug() const {
		return debug; };
	int getNumberOfTests() const {
		return numberOfTests; };
	string getOutputFile() const {
		return outputFile; };
	battleType getBattleType() const {
		return type; };


};

