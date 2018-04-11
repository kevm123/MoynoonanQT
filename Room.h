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
    string name;
	string description;
	map<string, Room*> exits;
    map<string, double> locks;
    map<string, string> facingDescriptions;
	string exitString();
    vector <Item> itemsInRoom;


public:
    int numberOfItems();
    Room(string name, string description);
    ~Room();
	void setExits(Room *north, Room *east, Room *south, Room *west);
    void setLocks(double north, double east, double south, double west);
    bool isLocked(string facing);
	string shortDescription();
    string longDescription(string facing);
	Room* nextRoom(string direction);
    //void addItem(Item *inItem);
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
    string getName();
    template<class T>
     void addItem(T *inItem){
            itemsInRoom.push_back(*inItem);

        }

};

#endif
