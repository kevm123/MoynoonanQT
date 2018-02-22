#include "Room.h"
#include "Command.h"


Room::Room(string description) {
	this->description = description;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

void Room::setLocks(int north, int east, int south, int west) {

        locks["north"] = north;

        locks["east"] = east;

        locks["south"] = south;

        locks["west"] = west;
}


string Room::shortDescription() {
	return description;
}

string Room::longDescription(string facing) {
    return "You are now in room " + description + ".\n" + "You are facing "+ facing + ".\n" + displayItem(facing) + exitString();
}

string Room::exitString() {
	string returnString = "\nexits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}

Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}

string Room::displayItem(string facing) {
    string tempString = "items to the "+facing+" in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            if(itemsInRoom[x].getPlaced() == facing)
                tempString = tempString + itemsInRoom[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {

                return x;
            }
            x++;
            }
        }
    return -1;
}

Item Room::getItem(int location)
{
    Item ItemToCheck = itemsInRoom[location];
    return ItemToCheck;
}

Item Room::takeItem(int location)
{
    Item takingItem = itemsInRoom[location];
    itemsInRoom.erase(itemsInRoom.begin()+location);
    return takingItem;
}

string Room::getItemI(int num)
{
    return itemsInRoom[num].getShortDescription();
}
bool Room::isLocked(string facing){

    if(locks[facing]!=0){
        cout<< locks[facing] << facing << endl;
        return true;
    }else{
        cout<< locks[facing] << facing << endl;
        return false;
    }

}
