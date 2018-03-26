#include "item.h"

Item::Item (string inDescription, int inWeightGrams, float inValue, string inplaced, bool obt, string inString, bool inIsKey /**, int weaponCheck*/, int inKeyNum) {
    description = inDescription;
    setWeight(inWeightGrams);
    value = inValue;
    placed = inplaced;
    obtainable = obt;
    InvestigateString = inString;
     isKey = inIsKey;
    keyNum = inKeyNum;
    /**weaponCheck(isWeapon);*/
}
Item::Item (string inDescription, int inWeightGrams, float inValue, string inplaced, bool obt, string inString, bool inIsKey /**, int weaponCheck*/) {
    description = inDescription;
    setWeight(inWeightGrams);
    value = inValue;
    placed = inplaced;
    obtainable = obt;
    InvestigateString = inString;
    isKey = inIsKey;
    /**weaponCheck(isWeapon);*/
}

Item::Item(string inDescription) {
	description = inDescription;
}

void Item::setWeight(int inWeightGrams)
{
	   weightGrams = inWeightGrams;
}

void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)

	   value = inValue;
}



string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
	return " item(s), " + description + ".\n";
}

string Item::getPlaced()
{
    return placed;
}

void Item::setPlaced(string p)
{
    placed = p;
}

bool Item::getObtainable()
{

    return obtainable;
}

string Item::getInvestigateString()
{
    return InvestigateString;
}
bool Item::getIsKey(){
    return isKey;
}
int Item::getKeyNum(){
    return keyNum;
}
