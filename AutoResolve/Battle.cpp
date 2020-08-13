#include "Battle.h"

Battle::~Battle()
{
	
}

Battle::Battle()
{
	attacker = Player();
	defender = Player();
	foundByAttacker = Equipment();
	foundByDefender = Equipment();
	treasure = nullptr;
	result = outcome::Draw;
	output = true;
	debug = false;
	fileOut = false;
	fileName = "";
	data = BattleData((string)"units.txt");
}

Battle::Battle(const string unitFile)
{
	attacker = Player();
	defender = Player();
	foundByAttacker = Equipment();
	foundByDefender = Equipment();
	treasure = nullptr;
	result = outcome::Draw;
	output = true;
	debug = false;
	fileOut = false;
	fileName = "";
	data  = new BattleData{ (string)unitFile };
}

 void Battle::treasureResults()
{
	if (debug) { cout << "treasureResults called" << endl; }
	if (debug) { cout << "treasureResults for attacker" << endl; }
	//Goes to where any bonus for finding loot at the end of a battle should be and sets the bonus to it.
	int bonus = attacker.getGeneral().getFollower().getABonus();

	if (debug) { cout << "attacker bonus is: " << bonus << endl; }
	//Looks for equipment and outputs what is returned
	foundByAttacker = treasure->findTreasure(bonus);
	if (debug) { cout << foundByAttacker.getName() << " returned from findTreasure" << endl; }
	if (output)
	{
		cout << foundByAttacker.getName() << " was found by the attacking army." << endl;
		//This outputs the stats of the equipment if it isn't the empty equipment
		if (foundByAttacker.getName() != treasure->noTreasure().getName())
		{
			cout << foundByAttacker.to_string() << endl;
		}
	}
	data.setAttackerTreasureRec(foundByAttacker.getName() != treasure->noTreasure().getName());

	if (debug) { cout << "treasureResults for defender" << endl; }
	//Then does the same as above for the defending Player.
	bonus = defender.getGeneral().getFollower().getABonus();

	if (debug) { cout << "defender bonus is: " << bonus << endl; }
	foundByDefender = treasure->findTreasure(bonus);
	if (debug) { cout << foundByDefender.getName() << " returned from findTreasure" << endl; }
	if (output)
	{
		cout << foundByDefender.getName() << " was found by the defending army." << endl;
		//This outputs the stats of the equipment if it isn't the empty equipment
		if (foundByDefender.getName() != treasure->noTreasure().getName())
		{
			cout << foundByDefender.to_string() << endl;
		}
	}
	data.setDefenderTreasureRec(foundByDefender.getName() != treasure->noTreasure().getName());
	if (debug) { cout << "Battle::treasureResults finished" << endl; }
	return;
}

//casulaties vector values
//[x][0] = # of soldiers casualties
//[x][1] = # of units completely destroyed
//[x][2] = # of Upgrades received
 void Battle::assignCasualties(vector<int>& casualties, Player& p) {

	 //Assigns casualties
	 vector<Unit> playerUnits = {};
	 playerUnits = p.getPlayerUnits();
	 if (debug) { cout << "number of player units: " << playerUnits.size() << endl; }

	 //Set Unit vector to empty if unit or soldier casualties are greater than what the Player possesses
	 if (casualties[0] >= p.getTotalSoldiers() || casualties[1] >= p.getNumberOfUnits()) {
		 vector<Unit> v = {};
		 p.setPlayerUnits(v);
		 return;
	 }
	 	 
	 int assignedSoldierCasualties = 0;
	 int assignedUnitCasualties = 0;
	 int i = 0;
	 int cas = 0;

	 if (debug) { cout << "Battle assigning casualties" << endl; }
	 while (assignedSoldierCasualties < casualties[0]){
		 if (debug) { cout << "Casualties to assign: " << casualties[0] - assignedSoldierCasualties << endl; }

		 //This makes the iterator skip units that have already lost all their soldiers.
		 while ( i < playerUnits.size()-1 && playerUnits[i].getCurrentSoldiers() == 0 ){
			 i++;
		 }

		 //Determines the amount of soldiers lost
		 //If the unit casualties is maxed out, it makes sure that the unit loses 1 less than its total number of soldiers at max; 
		 //0 if there is 1 soldier only
		 if (assignedUnitCasualties >= casualties[1]){
			 if (playerUnits[i].getCurrentSoldiers() == 1){
				 cas = 0;
			 }
			 else{
				 cas = Random::randomNumberArray(playerUnits[i].getCurrentSoldiers());
			 }
		 }
		 else{
			 cas = Random::randomNumber(playerUnits[i].getCurrentSoldiers());
		 }
		 //Ensure that cas won't total to more than casualties[0]
		 if (assignedSoldierCasualties + cas > casualties[0]) {
			 cas = casualties[0] - assignedSoldierCasualties;
		 }
		 assignedSoldierCasualties += cas;

		 //Subtracts the casualties from the amount of soldiers in the unit and declares if they have fully perished
		 playerUnits[i].setCurrentSoldiers(playerUnits[i].getCurrentSoldiers() - cas);

		 if (playerUnits[i].getCurrentSoldiers() == 0){
			 if (debug) { cout << assignedSoldierCasualties << " " << playerUnits[i].getName() << " completely destroyed." << endl; }
			 assignedUnitCasualties++;
		 }
		 else{
			 if (debug) { cout << assignedSoldierCasualties << " " << playerUnits[i].getName() << " lost " << cas << " soldiers." << endl; }
		 }
		 
		 i++;

		 //Wraps the index so it doesn't go off the end of the units array
		 if (i > playerUnits.size() - 1){
			 i = 0;
			 if (debug) { cout << "Wrapped attacker casualty assignment loop" << endl; }
			 bool soldiersAboveOne = false;

			 //Checks to make sure that at least one unit can still have casualties assigned to it
			 for (Unit j : playerUnits) {

				 if (j.getCurrentSoldiers() > 1) {
					 soldiersAboveOne = true;
					 if (debug) { cout << "soldiersAboveOne set to true" << endl; }
				 }
			 }

			 //If there are no more casualties that can be assigned
			 if (!soldiersAboveOne) {
				 casualties[0] = assignedSoldierCasualties;
				 if (debug) { cout << "reassigned casualties[0] to assignedSoldierCasualties" << endl; }
			 }

		 }
	 }

	 //Reassigns attacker's unit vector
	 vector<Unit> attackerUnitsAfterCasualties = {};
	 for (int i = 0; i < playerUnits.size(); i++){
		 if (playerUnits[i].getCurrentSoldiers() > 0){
			 attackerUnitsAfterCasualties.push_back(playerUnits[i]);
		 }
	 }
	 p.setPlayerUnits(attackerUnitsAfterCasualties);
	 return;
 }

//totalCasualties vector values
//[0][x] = Attacker's values
//[1][x] = Defender's values
//[x][0] = # of soldiers that are casualties
//[x][1] = # of units completely destroyed
//[x][2] = # of Upgrades received
void Battle::battleOutput(vector<vector<int>>& totalCasualties) //Base battle-end console output
{
	if (debug) { cout << "battleOutput called, calling treasureResults" << endl; }
	treasureResults();
	if (output)
	{
		if (debug) { cout << "Made it into output" << endl; }
		cout << EnumerationConversions::to_string(result) << endl;
	}

	if (output)
	{
		cout << "Attacker Soldier Casualties: " << totalCasualties[0][0] << endl;
		cout << "Attacker Unit Casualties: " << totalCasualties[0][2] << endl;
		cout << "Attacker General is " << EnumerationConversions::to_string(attacker.getGeneral().getState()) << endl;
		cout << "Defender Soldier Casualties: " << totalCasualties[0][0] << endl;
		cout << "Defender Upgrades: " << totalCasualties[0][2] << endl;
		cout << "Defender General is " << EnumerationConversions::to_string(defender.getGeneral().getState()) << endl;
	}

	if (debug) { cout << "Battle::battleOutput finished" << endl; }
	if (fileOut) {
		if (debug) { cout << "writing to file: " << fileName << endl; }
		data.writeToFile(fileName);
		if (debug) { cout << "Out of writing to file" << endl; }
	}
	return;
}

float Battle::battleCalculate() //contains the base calculations needed for battles
{
	data.setAttacker(attacker);
	data.setDefender(defender);
	data.setBattleType(type);

	if (debug) { cout << "battleCalculate called" << endl; }
	//Comparing these at the end will determine victory/draw/defeat in relation to the attacker
	//The defTotal is subtracted from the attTotal, thus a positive result is a victory for the attacker,
	//and the opposite from a negative result
	float attTotal = 0;
	float defTotal = 0;
	//Adds units + portions of reinforcements
	attTotal = attacker.getCavalry() + attacker.getMelee() + attacker.getRanged();
	if (debug) { cout << "attacker unit sum:" << attTotal << " Battle::battleCalculate" << endl; }
	defTotal = defender.getCavalry() + defender.getMelee() + defender.getRanged();
	if (debug) { cout << "defender unit sum:" << defTotal << " Battle::battleCalculate" << endl; }

	//Adds random values to randomize the battle outcome more
	int attRand = Random::randomNumberGroup(10, 1, 10);
	data.setAttackerRandoms(attRand);
	attTotal += attRand;
	attTotal /= 6;
	if (debug) { cout << "attacker sum with randoms:" << attTotal << " Battle::battleCalculate" << endl; }
	int defRand = Random::randomNumberGroup(10, 1, 10);
	data.setDefenderRandoms(defRand);
	defTotal += defRand;
	defTotal /= 6;
	if (debug) { cout << "defender sum with randoms:" << defTotal << " Battle::battleCalculate" << endl; }

	//Adds rank and autoresolve bonuses from generals
	attTotal += attacker.getGeneral().getRank();
	if (debug) { cout << "attacker sum with general:" << attTotal << " Battle::battleCalculate" << endl; }
	defTotal += defender.getGeneral().getRank();
	if (debug) { cout << "defender sum with general:" << defTotal << " Battle::battleCalculate" << endl; }
	attTotal += attacker.getGeneral().getARBonus();
	if (debug) { cout << "attacker sum with general autobonus: " << attTotal << " Battle::battleCalculate" << endl; }
	defTotal += defender.getGeneral().getARBonus();
	if (debug) { cout << "defender sum with general autobonus: " << defTotal << " Battle::battleCalculate" << endl; }

	//Adds R-P-S stuff to attacker, but not defender so the difference isn't added twice
	attTotal += ((double)attacker.getCavalry() - (double)defender.getRanged()) * 1.5;
	if (debug) { cout << "attacker sum with cav-ran RPS:" << attTotal << " Battle::battleCalculate" << endl; }
	attTotal += ((double)attacker.getMelee() - (double)defender.getCavalry()) * 1.5;
	if (debug) { cout << "attacker sum with mel-cav RPS:" << attTotal << " Battle::battleCalculate" << endl; }
	attTotal += ((double)attacker.getRanged() - (double)defender.getMelee()) * 1.5;
	if (debug) { cout << "attacker sum with ran-mel RPS:" << attTotal << " Battle::battleCalculate" << endl; }
	
	float finalTotal = attTotal - defTotal;

	if (debug) { cout << "Battle::battleCalculate finished, returned: " << finalTotal << endl; }
	return finalTotal;
}

//calculates the number of casualties from a battle and returns in a specific format
void Battle::calculateCas(vector<vector<int>>& totalCasualties) 
{

	if (debug) { cout << "CalculateCas called" << endl; }
	int attSoldierCasualties = 0;
	int defSoldierCasualties = 0;

	int attSoldierTotal = 0;
	int defSoldierTotal = 0;
	//Totals the amount of soldiers in the armies
	attSoldierTotal = attacker.getTotalSoldiers();
	defSoldierTotal = defender.getTotalSoldiers();

	if (debug) { cout << "attacker soldier total: " << attSoldierTotal << " Battle::CalculateCas" << endl; }
	if (debug) { cout << "defender soldier total: " << defSoldierTotal << " Battle::CalculateCas" << endl; }

	//Uses the value of the outcome to determine the amount of casualties that will be taken
	attSoldierCasualties = Random::randomNumberGroup(((int)result + 1), 1, attSoldierTotal / 10);
	if (debug) { cout << "attacker soldier casualty total: " << attSoldierCasualties << " Battle::CalculateCas" << endl; }
	defSoldierCasualties = Random::randomNumberGroup((9 - (int)result), 1, defSoldierTotal / 10);
	if (debug) { cout << "defender soldier casualty total: " << defSoldierCasualties << " Battle::CalculateCas" << endl; }

	//Calculates the amounts of upgrades received; they are used in the campaign
	int attUpgr = defSoldierCasualties / 6;
	data.setAttackerUpgrades(attUpgr);
	if (debug) { cout << "attacker upgrade total: " << attUpgr << " Battle::CalculateCas" << endl; }
	int defUpgr = attSoldierCasualties / 6;
	data.setDefenderUpgrades(defUpgr);
	if (debug) { cout << "defender upgrade total: " << defUpgr << " Battle::CalculateCas" << endl; }

	//Calculates the max amount of units that are destroyed
	int attUnitCasualties = (attSoldierCasualties / 7) - 1;
	if (attUnitCasualties <= 0)
	{
		attUnitCasualties = 0;
	}
	if (debug) { cout << "attacker unit casualty total: " << attUnitCasualties << " Battle::CalculateCas" << endl; }
	int defUnitCasualties = (defSoldierCasualties / 7) - 1;
	if (defUnitCasualties <= 0)
	{
		defUnitCasualties = 0;
	}
	if (debug) { cout << "defender unit casualty total: " << defUnitCasualties << " Battle::CalculateCas" << endl; }

	//Determines whether or not either of the generals are wounded/killed
	//attacker.getGeneral().setState(generalState::Unharmed);
	if (Random::randomNumber(10) < 2)
	{
		attacker.getGeneral().setState(generalState::Wounded);
		if (debug) { cout << "attacker General state set to Wounded Battle::CalculateCas" << endl; }
		cout << "Att gen wounded" << endl;
		if (Random::randomNumber(10) < 2)
		{
			cout << "Att gen slain" << endl;
			attacker.getGeneral().setState(generalState::Slain);
			if (debug) { cout << "attacker General state set to Slain Battle::CalculateCas" << endl; }
		}
	}
	else { if (debug) { cout << "attacker General unharmed" << endl; } }

	//defender.getGeneral().setState(generalState::Unharmed);
	if (Random::randomNumber(10) < 2)
	{
		defender.getGeneral().setState(generalState::Wounded);
		cout << "def gen wounded" << endl;
		if (debug) { cout << "defender General state set to Wounded Battle::CalculateCas" << endl; }
		if (Random::randomNumber(10) < 2)
		{
			cout << "Def gen slain" << endl;
			defender.getGeneral().setState(generalState::Slain);
			if (debug) { cout << "defender General state set to Slain Battle::CalculateCas" << endl; }
		}
	}
	else { if (debug) { cout << "defender General unharmed" << endl; } }
	cout << "Att Gen state: " << EnumerationConversions::to_string(attacker.getGeneral().getState()) << endl;
	cout << "Def Gen state: " << EnumerationConversions::to_string(defender.getGeneral().getState()) << endl;
	
	
	data.setAttackerGeneralState(attacker.getGeneral().getState());
	data.setDefenderGeneralState(defender.getGeneral().getState());

	//Creates the vectors that contain the casualty data
	vector<int> attackerCasVec{ attSoldierCasualties, attUnitCasualties, attUpgr };
	if (debug) { cout << "Attacker Casualty vector initialized Battle::CalculateCas" << endl; }
	vector<int> defenderCasVec{ defSoldierCasualties, defUnitCasualties, defUpgr };
	if (debug) { cout << "Defender Casualty vector initialized Battle::CalculateCas" << endl; }

	if (debug) { cout << "Moving on to casualty assignment Battle::CalculateCas" << endl; }
	assignCasualties(attackerCasVec, attacker);
	assignCasualties(defenderCasVec, defender);

	data.setAttackerCasualties(attackerCasVec);
	data.setDefenderCasualties(defenderCasVec);

	data.setAttackerEnd(attacker);
	data.setDefenderEnd(defender);

	totalCasualties = { attackerCasVec,defenderCasVec };
}

void Battle::printData() const
{
	cout << "Battle printData called" << endl
		<< "Battle attacker: " << endl;
	attacker.printData();
	cout << "Battle defender: " << endl;
	defender.printData();
	cout << "Battle result: " << EnumerationConversions::to_string(result) << endl;
	if (treasure->isInitialized()) { cout << "Battle Treasure Initialized" << endl; }
}

void Battle::determineOutcome(const float endingTotal) {
	//All results are in relation to the attacker.
	//Victory
	if (endingTotal > 2) {
		if (endingTotal >= 20) {
			result = outcome::Decisive_Victory;
		}
		else if (endingTotal >= 10) {
			result = outcome::Heroic_Victory;
		}
		else {
			result = outcome::Close_Victory;
		}
	}
	//Defeat
	else if (endingTotal < -2) {
		if (endingTotal <= -20){
			result = outcome::Crushing_Defeat;
		}
		else if (endingTotal <= -10) {
			result = outcome::Valiant_Defeat;
		}
		else {
			result = outcome::Close_Defeat;
		}
	}
	//Draw
	else {
		result = outcome::Draw;
	}

	data.setAttackerWon((int)result < 4);
	data.setOutcome(result);
}

