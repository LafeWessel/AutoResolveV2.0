#include "Equipment.h"

Equipment::~Equipment()
{
}

Equipment::Equipment() //void initializer
{
	name = "";
	autoBonus = 0;
	index = 0;
	range = 0;
	EquipType = equipmentType::null;
	effect = "";
	coinValue = 0;
	debug = false;
}

Equipment::Equipment(bool debugI)
{
	name = "";
	autoBonus = 0;
	index = 0;
	range = 0;
	EquipType = equipmentType::null;
	effect = "";
	coinValue = 0;
	this->setDebug(debugI);
}

Equipment::Equipment(string nameI, int autoBonusI, int numberI, int rangeI, equipmentType EquipTypeI, string effectI, int coinValueI) //initializer
{
	name = nameI;
	autoBonus = autoBonusI;
	index = numberI;
	range = rangeI;
	EquipType = EquipTypeI;
	effect = effectI;
	coinValue = coinValueI;
	debug = false;
}

const string Equipment::printData()
{
	return "Equipment printData called\nEquipment name: " + name + "\nEquipment autoresolve bonus: "+ to_string(autoBonus)+
		"\nEquipment index: " + to_string(index) + "\nEquipment range: " + to_string(range) + "\nEquipment equipType: "+ EnumerationConversions::to_string(EquipType) + "\nEquipment effect: " +
		effect + "\nEquipment coin value: "+ to_string(coinValue) + "\n";
}