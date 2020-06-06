#include "EnumerationConversions.h"

/*
Returns the faction corresponding to the integer passed
*/
const faction EnumerationConversions::intToFaction(int faction) {

	switch (faction) {
		case 1:
			return faction::rebel;
			break;
		case 2:
			return faction::beladimir;
			break;
		case 3:
			return faction::lerastir;
			break;
		case 4:
			return faction::menoriad;
			break;
		default:
			cerr << "Invalid integer passed to intToFaction" << endl;
	}
	return faction::rebel;
}

/*
Returns the monsterType corresponding to the integer passed
*/
const monsterType EnumerationConversions::intToMonsterType(int monsterType) {
	switch (monsterType) {
		case 1:
			return monsterType::Minotaur;
			break;
		case 2:
			return monsterType::Hobgoblin;
			break;
		case 3:
			return monsterType::Troll;
			break;
		case 4:
			return monsterType::Giant;
			break;
		case 5:
			return monsterType::Demon;
			break;
		case 6:
			return monsterType::Dragon;
			break;
		default:
			cerr << "Invalid integer passed to intToMonsterType" << endl;
	}
	return monsterType::Empty;
}

/*
Outputs an integer as its corresponding outcome enum class name.
TODO rename to outcomeToString
*/
const string EnumerationConversions::outputIntAsOutcome(int outcome) 
{
	switch (outcome)
	{
	case(1):
		return "Decisive Victory";
		break;
	case(2):
		return "Heroic Victory";
		break;
	case(3):
		return "Close Victory";
		break;
	case(4):
		return "Draw";
		break;
	case(5):
		return "Close Defeat";
		break;
	case(6):
		return "Valiant Defeat";
		break;
	case(7):
		return "Crushing Defeat";
		break;
	default:
		cerr << " No valid outcome chosen " << endl;	
	}
	return "";
}