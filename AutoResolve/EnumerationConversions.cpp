#include "EnumerationConversions.h"


/*
Returns a string that corresponds to the equipmentType passed based on its name
*/
 string EnumerationConversions::to_string(const equipmentType e){
	switch (e)
	{
	case equipmentType::null:
		return "null";
		break;
	case equipmentType::armor:
		return "Armor";
		break;
	case equipmentType::weapon:
		return "Weapon";
		break;
	case equipmentType::trinket:
		return "Trinket";
		break;
	case equipmentType::banner:
		return "Banner";
		break;
	case equipmentType::dragon:
		return "Dragon";
		break;
	case equipmentType::follower:
		return "Follower";
		break;
	default:
		cerr << " No valid equipmentType chosen: "<< (int)e << endl;
	}
	return "";
}

/*
Returns a string that corresponds to the outcome passed based on its name
*/
 string EnumerationConversions::to_string(const outcome o){
	switch (o)
	{
	case outcome::Decisive_Victory:
		return "Decisive Victory";
		break;
	case outcome::Heroic_Victory:
		return "Heroic Victory";
		break;
	case outcome::Close_Victory:
		return "Close Victory";
		break;
	case outcome::Draw:
		return "Draw";
		break;
	case outcome::Close_Defeat:
		return "Close Defeat";
		break;
	case outcome::Valiant_Defeat:
		return "Valiant Defeat";
		break;
	case outcome::Crushing_Defeat:
		return "Crushing Defeat";
		break;
	default:
		cerr << " No valid outcome chosen: " << (int)o << endl;
	}
	return "";
}

/*
Returns a string that corresponds to the faction passed based on its name
*/
 string EnumerationConversions::to_string(const faction f){
	switch (f)
	{
	case faction::rebel:
		return "Rebel";
		break;
	case faction::beladimir:
		return "Beladimir";
		break;
	case faction::lerastir:
		return "Lerastir";
		break;
	case faction::menoriad:
		return "Menoriad";
		break;
	default:
		cerr << " No valid faction chosen: " << (int)f << endl;
	}
	return "";
}

/*
Returns a string that corresponds to the outcome passed based on its name
*/
 string EnumerationConversions::to_string(const monsterType m){
	switch (m)
	{
	case monsterType::Minotaur:
		return "Minotaur";
		break;
	case monsterType::Hobgoblin:
		return "Hobgoblin";
		break;
	case monsterType::Troll:
		return "Troll";
		break;
	case monsterType::Giant:
		return "Giant";
		break;
	case monsterType::Demon:
		return "Demon";
		break;
	case monsterType::Dragon:
		return "Dragon";
		break;
	case monsterType::Empty:
		return "Empty";
		break;
	default:
		cerr << " No valid monsterType chosen: "  << (int)m << endl;
	}
	return "";
}

/*
Returns a string that corresponds to the defenses passed based on its name
*/
 string EnumerationConversions::to_string(const defenses d) {
	switch (d)
	{
	case defenses::None:
		return "None";
		break;
	case defenses::Wooden_Wall:
		return "Wooden Wall";
		break;
	case defenses::Wooden_Wall_W_Moat:
		return "Wooden Wall w/ Moat";
		break;
	case defenses::Stone_Wall:
		return "Stone Wall";
		break;
	case defenses::Stone_Wall_W_Moat:
		return "Stone Wall w/ Moat";
		break;
	default:
		cerr << " No valid defenses chosen: " << (int)d << endl;
	}
	return "";
}

/*
Returns a string that corresponds to the battleType passed based on its name
*/
 string EnumerationConversions::to_string(const battleType b){
	switch (b)
	{
	case battleType::Normal:
		return "Normal";
		break;
	case battleType::Siege:
		return "Siege";
		break;
	case battleType::Raid:
		return "Raid";
		break;
	case battleType::Naval:
		return "Naval";
		break;
	case battleType::Monster:
		return "Monster";
		break;
	default:
		cerr << " No valid battleType chosen: " << (int)b << endl;
	}
	return "";
}

/*
Returns a string that corresponds to the unitType passed based on its name
*/
 string EnumerationConversions::to_string(const unitType u){
	switch (u)
	{
	case unitType::Melee:
		return "Melee";
		break;
	case unitType::Cavalry:
		return "Cavalry";
		break;
	case unitType::Ranged:
		return "Ranged";
		break;
	default:
		cerr << " No valid unitType chosen: "<< (int)u << endl;
	}
	return "";
}

 /*
 Returns a string that corresponds to the generalState passed based on its name
 */
 string EnumerationConversions::to_string(const generalState g) {
	 switch (g) {
	 case generalState::Unharmed:
		 return "Unharmed";
		 break;
	 case generalState::Wounded:
		 return "Wounded";
		 break;
	 case generalState::Slain:
		 return "Slain";
		 break;
	 default:
		 cerr << " No valid generalState chosen: "<< (int)g << endl;
	 }
	 return "";
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