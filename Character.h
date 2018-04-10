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
    //void addItem(Item item);




public:
    Character(string description);
    string shortDescription();
    string longDescription();
    int numberOfItems();
    string getItemI(int num);
    Item* getItemByString(string itemName);
    string getFacing();
    void setFacing(string direction);
    template<class T>
        void addItem(T inItem){
            itemsInCharacter.push_back(inItem);
        }

};

#endif /*CHARACTER_H_*/
