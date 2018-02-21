#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
private:
	string description;
	string longDescription;
	int weightGrams;
	float value;
	bool weaponCheck;
    string placed;
    bool obtainable;

public:
    Item (string description, int inWeight, float inValue, string inplaced, bool obtainable);
    Item (string description);
	string getShortDescription();
    string getLongDescription();
	int getWeight();
	void setWeight(int weightGrams);
	float getValue();
	void setValue(float value);
	int getWeaponCheck();
	void setWeaponCheck(int weaponCheck);
    string getPlaced();
    void setPlaced(string p);
    bool getObtainable();
};

#endif /*ITEM_H_*/
