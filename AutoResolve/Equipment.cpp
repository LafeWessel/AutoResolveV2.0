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

Equipment::Equipment(const bool debugI)
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

Equipment::Equipment(const string nameI, const int autoBonusI, const int numberI, const int rangeI,
	const equipmentType EquipTypeI, const string effectI, const int coinValueI) //initializer
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

 string Equipment::to_string() const
{
	return "Equipment printData called\nEquipment name: " + name + "\nEquipment autoresolve bonus: "+ std::to_string(autoBonus)+
		"\nEquipment index: " + std::to_string(index) + "\nEquipment range: " + std::to_string(range) + "\nEquipment equipType: "+ EnumerationConversions::to_string(EquipType) + "\nEquipment effect: " +
		effect + "\nEquipment coin value: "+ std::to_string(coinValue) + "\n";
}