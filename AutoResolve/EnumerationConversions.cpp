#include "EnumerationConversions.h"

/*
Returns the faction corresponding to the integer passed
*/
 faction EnumerationConversions::intToFaction(const int faction){

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
 monsterType EnumerationConversions::intToMonsterType(const int monsterType){
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
TODO replace references to this with to_string(outcome)
*/
 string EnumerationConversions::outputIntAsOutcome(const int outcome){
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

/*
Returns a string that corresponds to the equipmentType passed based on its name
*/
 string EnumerationConversions::to_string(const equipmentType e){
	switch ((int)e)
	{
	case(1):
		return "null";
		break;
	case(2):
		return "Armor";
		break;
	case(3):
		return "Weapon";
		break;
	case(4):
		return "Trinket";
		break;
	case(5):
		return "Banner";
		break;
	case(6):
		return "Dragon";
		break;
	case(7):
		return "Follower";
		break;
	default:
		cerr << " No valid outcome chosen " << endl;
	}
	return "";
}

/*
Returns a string that corresponds to the outcome passed based on its name
*/
 string EnumerationConversions::to_string(const outcome o){
	switch ((int)o)
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

/*
Returns a string that corresponds to the faction passed based on its name
*/
 string EnumerationConversions::to_string(const faction f){
	switch ((int)f)
	{
	case(1):
		return "Rebel";
		break;
	case(2):
		return "Beladimir";
		break;
	case(3):
		return "Lerastir";
		break;
	case(4):
		return "Menoriad";
		break;
	default:
		cerr << " No valid outcome chosen " << endl;
	}
	return "";
}

/*
Returns a string that corresponds to the outcome passed based on its name
*/
 string EnumerationConversions::to_string(const monsterType m){
	switch ((int)m)
	{
	case(1):
		return "Minotaur";
		break;
	case(2):
		return "Hobgoblin";
		break;
	case(3):
		return "Troll";
		break;
	case(4):
		return "Giant";
		break;
	case(5):
		return "Demon";
		break;
	case(6):
		return "Dragon";
		break;
	case(7):
		return "Empty";
		break;
	default:
		cerr << " No valid outcome chosen " << endl;
	}
	return "";
}

/*
Returns a string that corresponds to the defenses passed based on its name
*/
 string EnumerationConversions::to_string(const defenses d) {
	switch ((int)d)
	{
	case(1):
		return "None";
		break;
	case(2):
		return "Wooden Wall";
		break;
	case(3):
		return "Wooden Wall w/ Moat";
		break;
	case(4):
		return "Stone Wall";
		break;
	case(5):
		return "Stone Wall w/ Moat";
		break;
	default:
		cerr << " No valid outcome chosen " << endl;
	}
	return "";
}

/*
Returns a string that corresponds to the battleType passed based on its name
*/
 string EnumerationConversions::to_string(const battleType b){
	switch ((int)b)
	{
	case(1):
		return "Normal";
		break;
	case(2):
		return "Siege";
		break;
	case(3):
		return "Raid";
		break;
	case(4):
		return "Naval";
		break;
	case(5):
		return "Monster";
		break;
	default:
		cerr << " No valid outcome chosen " << endl;
	}
	return "";
}

/*
Returns a string that corresponds to the unitType passed based on its name
*/
 string EnumerationConversions::to_string(const unitType u){
	switch ((int)u)
	{
	case(1):
		return "Melee";
		break;
	case(2):
		return "Cavalry";
		break;
	case(3):
		return "Ranged";
		break;
	default:
		cerr << " No valid outcome chosen " << endl;
	}
	return "";
}


/*
Returns the unitType that corresponds to the int passed
*/
 unitType EnumerationConversions::intToUnitType(const int unitType){
	switch (unitType)
	{
	case 1:
		return unitType::Melee;
		break;
	case 2:
		return unitType::Cavalry;
		break;
	case 3:
		return unitType::Ranged;
		break;
	default:
		cerr << "invalid integer input." << endl;
	}
	return unitType::Melee;
}

/*
Returns an equipmentType that corresponds to the string passed
*/
 equipmentType EnumerationConversions::stringToEquipType(const string nameI){
	vector<string> names = { "Null","Armor","Weapon","Trinket","Banner","Dragon","Follower" };
	vector<equipmentType> types = { equipmentType::null,equipmentType::armor,equipmentType::weapon,
		equipmentType::trinket,equipmentType::banner,equipmentType::dragon,equipmentType::follower };

	for (int i = 0; i < names.size(); i++) //Tests the input string against a list of the equipmentTypes
	{
		if (nameI == names[i])
		{
			return types[i];
		}
	}
	cerr << "no equipmentType was discernable from " << nameI << endl;
	return equipmentType::null;

}