#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "item.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:
    string description;
    vector < Item > itemsInCharacter;
    string facing;
public:
    void addItem(Item item);




public:
    Character(string description);
    string shortDescription();
    string longDescription();
    int numberOfItems();
    string getItemI(int num);
    string getFacing();
    void setFacing(string direction);

};

#endif /*CHARACTER_H_*/
