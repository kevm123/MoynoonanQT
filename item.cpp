#include "item.h"

Item::Item (string inDescription, string inplaced, bool obt, string inString, bool inIsKey, int inKeyNum) {
    description = inDescription;
    placed = inplaced;
    obtainable = obt;
    InvestigateString = inString;
     isKey = inIsKey;
    keyNum = inKeyNum;
}
Item::Item (string inDescription, string inplaced, bool obt, string inString, bool inIsKey) {
    description = inDescription;
    placed = inplaced;
    obtainable = obt;
    InvestigateString = inString;
    isKey = inIsKey;
}

Item::Item(string inDescription) {
	description = inDescription;
}

Item::~Item(void){}

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
