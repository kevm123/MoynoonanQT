#ifndef KEY_H
#define KEY_H

#include <map>
#include <string>
#include <iostream>
#include "item.h"

using namespace std;

class Key : public Item
{
protected:
    int keyNum;

public:
    Key(string inDescription, int inWeightGrams, float inValue, string inplaced, bool obt, string inString, bool inIsKey, int inKeyNum);
   // Key(Item* it);
    int getKeyNum();
};

#endif // KEY_H
