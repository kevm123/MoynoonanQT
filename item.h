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
	bool weaponCheck;
    string placed;
    bool obtainable;
    string InvestigateString;
    bool isKey;
    int keyNum;

public:
    Item (string description, string inplaced, bool obtainable, string inString, bool isKey, int inKeyNum);
    Item (string description, string inplaced, bool obtainable, string inString, bool isKey);
    Item (string description);
    ~Item();
	string getShortDescription();
    string getLongDescription();
    string getPlaced();
    void setPlaced(string p);
    bool getObtainable();
    string getInvestigateString();
    int getKeyNum();
    bool getIsKey();

};

#endif /*ITEM_H_*/
