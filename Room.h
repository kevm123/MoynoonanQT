#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class Room {

private:
	string description;
	map<string, Room*> exits;
	string exitString();
    vector <Item> itemsInRoom;


public:
    int numberOfItems();
	Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
    string longDescription(string facing);
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem(string facing);
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    Item takeItem(int location);
    string getItemI(int num);
    Item getItem(int location);
};

#endif
