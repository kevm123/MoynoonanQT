#include "Character.h"
#include "Item.h"

Character::Character(string description) {
    this->description = description;
    facing="north";
}
/*void Character::addItem(Item *item) {
    itemsInCharacter.push_back(*item);
}*/
/*void Character::addItem(Item *item) {
    itemsInCharacter.push_back(*item);
    delete item;
}*/
string Character::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Item*>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    ret += "\t"+ (*i)->getLongDescription() + "\n";
  cout << ret << endl;
  return ret;
}

int Character::numberOfItems() {
    return itemsInCharacter.size();
}

string Character::getItemI(int num)
{
    return itemsInCharacter[num]->getShortDescription();
}

Item* Character::getItemByString(string itemName){
    for(int i=0; i<numberOfItems(); i++){
        if(itemsInCharacter[i]->getShortDescription()==itemName){
            return itemsInCharacter[i];
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


