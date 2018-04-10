#include "Character.h"
#include "Item.h"

Character::Character() {

    facing="north";
}


int Character::numberOfItems() {
    return itemsInCharacter.size();
}

string Character::getItemI(int num)
{
    return itemsInCharacter[num].getShortDescription();
}

Item* Character::getItemByString(string itemName){
    for(int i=0; i<numberOfItems(); i++){
        if(itemsInCharacter[i].getShortDescription()==itemName){
            return &itemsInCharacter[i];
         }
    }
    return nullptr;
}

string Character::getFacing()
{
    return facing;
}

void Character::setFacing(string direction)
{
    facing = direction;
}


