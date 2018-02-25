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
    map<string, int> locks;
    map<string, string> facingDescriptions;
	string exitString();
    vector <Item> itemsInRoom;


public:
    int numberOfItems();
	Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
    void setLocks(int north, int east, int south, int west);
    bool isLocked(string facing);
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
    bool isADoor(string facing);
    int getLockNum(string facing);
    void setLockNum(string facing);
    void setFacingDescriptions(string north, string east, string south, string west);
    string getFacingDescription(string facing);
};

#endif
