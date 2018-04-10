#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Command.h"
#include "areamap.h"
#include "finaldoor.h"


//Creates a new MainWindow
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     createRooms();
    // AreaMap aMap;
     aMap.show();
     aMap.setMapLocation(currentRoom->getName());
     play();
}

//Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

//This is a pure virtual function
class output
{
public:
    virtual string getText() =0;
};

//Abstract class
class Controls: public output {

public:
    string getText(){
        return("CONTROLS:\n- Use the arrows to face in a direction.\n- You can investigate and take items in the room only when you are facing them.\n- Use keys or other items to open doors when facing them.\n- Use 'Go' to go in the direction your facing through open doors.");
    }

};


//Creates Rooms, references room in Room.cpp
void MainWindow::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    a = new Room("a","Directly in front of you is a dentists chair.\nBut none of the other tools appear to be dental related.\nA worrying amount of red stains are scattered throughout the room.\nTo the south is a hallway.\nThere is a red door to the west and a blue door to the east.");

    b = new Room("b","You are now standing a room filled with sleepingbags and old mattress's.\nTheres bars on the windows but its too dark to see outside.\nA small dimly lit candle lights the room.\nA small trail of blood seems to go under a door to the north.");
        b->addItem(new Item("UnusualKey", "east", true, "A strange key for a strange door", true, 6));

    c = new Room("c","A large steel door with a very unique lock is to the north of the room.\nThis door has a letter box but its welded shut.\nSurely this is the way out.");
        c->addItem(new Item("ModernKey", "west", true, "A normal modern key", true, 7));

    d = new Room("d","You are now standing in a small hallway.\nA large skylight above you shows a clear dark night.\nIn front of you is a door that says --TOILETS-- and another unlocked door is to the north.");

    e = new Room("e","A light flickering overhead displays a small tiled bathroom.\nThere appears to be blood on the floor and a mop and bucket lie next to it.");
        e->addItem(new Item("RedKey", "east", true, "A Red Key", true, 4));
        e->addItem(new Item("BlueKey", "east", true, "A Blue Key", true, 5));

    f = new Room("f","Congratulations, You have escaped!!");

    g = new Room("g","This room is not like the others.\nIts brightly lit with a large sign that reads \n--Len Groseman, Your one stop shop for pain relief and a better life-- \nAbove an apparent receptionists desk.\nTo the east is a large bolted door with a keypad.");
        g->addItem(new Item("Notepad", "east", false, "Note to self:\nWhen the ship sailed the door opened.", false));

    h = new Room("h","You enter a dead end. There is nowhere to go only back");

    i = new Room("i","You are now in a small brightly lit room.\nIt looks like some kind of waiting room.\nTheres a table in the middle of the room with dusty magazines and chairs dotted around.");
         i->addItem(new Item("Oldkey", "east", true, "An old, rusty key hangs on the wall", true, 2));

         j = new Room("j","Welcome to the game.\nYou are in an old room with a red carpet and no windows.\nYou have no idea where you are but you know you must find a way out...\nUse the buttons below to look around.");
        j->addItem(new Item("painting", "north", false, "The painting is of a ship in a storm.\nIt says in the corner --Painted in 1964--", false));
        j->addItem(new Item("key", "south", true, "An old key just lying on the ground.\nYou can tell from the dust marks its been there a while.", true, 1));

//             (N, E, S, W)
    a->setExits(NULL, b, d, c);
    b->setExits(g, NULL, NULL, a);
    c->setExits(h, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, NULL, NULL);
    g->setExits(NULL, NULL, b, f);
    h->setExits(NULL, NULL, c, NULL);
    i->setExits(NULL, d, NULL, j);
    j->setExits(NULL,i,NULL,NULL);

   //            (N, E, S, W)
     a->setLocks(0, 5, 0, 4);
     b->setLocks(7, 0, 0, 0);
     c->setLocks(6, 0, 0, 0);
     d->setLocks(0, 0, 0, 0);
     e->setLocks(0, 0, 0, 0);
     f->setLocks(0, 0, 0, 0);
     g->setLocks(0, 0, 0, 1000);
     h->setLocks(0, 0, 0, 0);
     i->setLocks(0, 2, 0, 0);
     j->setLocks(0, 1, 0, 0);

     a->setFacingDescriptions("There is nothing but a large brick wall", "A large blue door stands in front of you", "An open door leading to a hall with a skylight", "A red door is in front of you");
     b->setFacingDescriptions("A large door with a trail of blood, the blood still seems wet.", "Chains line the walls and theres claw marks on the floor, an unusual looking key is on the chains", "Sleeping bags and old mattress's are scattered on the floor", "A blue door is open");
     c->setFacingDescriptions("That steel door is in front of you, You cant look out the letterbox but it seems promising", "The red door is open", "Nothing but a plain wall to the south", "A small Modern Key seems to appear from a crack in the wall");
     d->setFacingDescriptions("An open door leads to another room", "A door that says --TOILETS--, I guess we know whats in there", "A large carpet covers the wall, It looks african in style", "An open door leads to another room");
     e->setFacingDescriptions("A tile covered wall", "There is a large blood spill with an overturned bucket and mop\nA RedKey is lying in the blood and a BlueKey is tied to the handle of the mop", "A dirty sink is propped against the wall", "A door leads to a hallway");
     f->setFacingDescriptions("-", "-", "-", "-");
     g->setFacingDescriptions("Large windows cover the wall but it is too dark to see out", "The receptionist desk looks like its used often, a small notepad is on it", "A door leads to another room", "A large steel door with a numeric lock, Can we guess the code??");
     h->setFacingDescriptions("Plain white wall", "Plain white wall", "Plain white wall", "Plain white wall");
     i->setFacingDescriptions("A window looking out, it is too dark to see anything", "There is a key with a lock, there is a also an old key on the floor", "There is a couch", "There is a room with an open door");
     j->setFacingDescriptions("There is a painting on a wall", "There is a door with a lock", "There is a key hanging on a hook", "A couch lies in the corner");
        currentRoom = j;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void MainWindow::play() {

    character = new Character();
    fillItems();
    printWelcome();
}

void MainWindow::printWelcome() {

        showDescription("desc");
        string RoomInfo = currentRoom->longDescription(character->getFacing());
        ui->Label2->setText(QString::fromStdString(RoomInfo));

        //Calls the abstract class
        Controls c;
        string controlsText = c.getText();
        ui->outputLabel->setText(QString::fromStdString(controlsText));

}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool MainWindow::processCommand(Command command) {

    string commandWord = command.getCommandWord();
    if(commandWord.compare("go") == 0)
    {
        string facing = character->getFacing();
        goRoom(command, facing);

            string RoomInfo = currentRoom->longDescription(character->getFacing());
            ui->Label2->setText(QString::fromStdString(RoomInfo));
            fillItems();

    }

    else if (commandWord.compare("take") == 0)
    {
         if (command.hasSecondWord()) {
        ui->outputLabel->setText(QString::fromStdString("you're trying to take "+ command.getSecondWord()));
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if((currentRoom->getItem(location)).getObtainable() && (character->getFacing() == (currentRoom->getItem(location)).getPlaced())){

            currentRoom->getItem(location).setPlaced("");
            character->addItem(currentRoom->takeItem(location));

            //Update Obtained Items DropDown
            ui->ObtainedItems->clear();
            int numOfItems = character->numberOfItems();
            for(int i = 0; i < numOfItems; i++)
                {
                    ui->ObtainedItems->addItem(QString::fromStdString(character->getItemI(i)));
                    ui->outputLabel->setText(QString::fromStdString("You have obtained the "+ command.getSecondWord()));
                }

            //Update Items In Room DropDown
            fillItems();
        }
        else if(!(currentRoom->getItem(location)).getObtainable())
            ui->outputLabel->setText(QString::fromStdString("This Item cannot be taken.\nYou can only investigate it."));
        else
            ui->outputLabel->setText(QString::fromStdString("You are not facing in the direction of the object"));
        }
    }

    else if (commandWord.compare("Investigate") == 0)
    {
         if (command.hasSecondWord()) {
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            ui->outputLabel->setText(QString::fromStdString("Cannot find this item in the room, maybe you have already picked it up"));
        else if((character->getFacing() == (currentRoom->getItem(location)).getPlaced()))
        {
            Item ItemToInvestigate = currentRoom->getItem(location);
            string output = ItemToInvestigate.getInvestigateString();
             ui->outputLabel->setText(QString::fromStdString(output));
         }
        else
            ui->outputLabel->setText(QString::fromStdString("You are not facing in the direction of the object"));
    }
    }
    else if (commandWord.compare("use")==0)
    {
        if(command.hasSecondWord()){

            string itemName = command.getSecondWord();
            Item *itemToUse = character->getItemByString(itemName);

            bool isAKey= itemToUse->getIsKey();
            if(isAKey==true){
                int keyNum = itemToUse->getKeyNum();
                unlockDoor(keyNum);
                if(currentRoom->getName() == "g")
                    ui->outputLabel->setText(QString::fromStdString("This Door cannot be opened with a key.\nIt needs the code to be entered"));
                else
                    ui->outputLabel->setText(QString::fromStdString("You have unlocked the door"));
            }else{
                ui->outputLabel->setText(QString::fromStdString("You cannot use this item on anything you are facing"));
            }

        }
    }

    return false;
}
/** COMMANDS **/

void MainWindow::goRoom(Command command, string facing) {
    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        ui->outputLabel->setText(QString::fromStdString("There is no exit in this direction."));
    else if(1000 == currentRoom->getLockNum(facing))
    {
        fd.setCode(1964);
        fd.setUpDoor(currentRoom, facing);
        fd.show();
    }
    else if(currentRoom->isLocked(facing)==true){
        ui->outputLabel->setText(QString::fromStdString("This exit is locked.\nUnlock it with a key."));
    }
    else {
        currentRoom = nextRoom;
        showDescription("desc");
        aMap.setMapLocation(currentRoom->getName());
    }
}


string MainWindow::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        showDescription("desc");
        return currentRoom->longDescription(character->getFacing());
    }
}



void MainWindow::on_NorthButton_clicked()
{
    character->setFacing("north");
    string RoomInfo = currentRoom->longDescription(character->getFacing());
    ui->Label2->setText(QString::fromStdString(RoomInfo));
    showDescription("north");
}

void MainWindow::on_SouthButton_clicked()
{
    character->setFacing("south");
    string RoomInfo = currentRoom->longDescription(character->getFacing());
    ui->Label2->setText(QString::fromStdString(RoomInfo));
    showDescription("south");
}

void MainWindow::on_EastButton_clicked()
{
    character->setFacing("east");
    string RoomInfo = currentRoom->longDescription(character->getFacing());
    ui->Label2->setText(QString::fromStdString(RoomInfo));
    showDescription("east");
}

void MainWindow::on_West_clicked()
{
    character->setFacing("west");
    string RoomInfo = currentRoom->longDescription(character->getFacing());
    ui->Label2->setText(QString::fromStdString(RoomInfo));
    showDescription("west");
}


void MainWindow::on_GoButton_clicked()
{
    string direction = character->getFacing();
    Command* command = parser.getCommand("go "+direction);
    processCommand(*command);
}

void MainWindow::on_TakeButton_clicked()
{
    string ItemToTake = (ui->ItemDropdown->currentText()).toStdString();
    string comm = "take "+ItemToTake;
    Command* command = parser.getCommand(comm);
    processCommand(*command);
}

void MainWindow::on_InvestigateButton_clicked()
{
    string ItemToInvestigate = (ui->ItemDropdown->currentText()).toStdString();
    string comm = "Investigate "+ItemToInvestigate;
    Command* command = parser.getCommand(comm);
    processCommand(*command);
}

void MainWindow::on_UseButton_clicked()
{
    string itemName = (ui->ObtainedItems->currentText()).toStdString();
    string comm = "use "+itemName;
    Command* command = parser.getCommand(comm);
    processCommand(*command);
}


//Update Items In Room DropDown
void MainWindow::fillItems()
{
    ui->ItemDropdown->clear();
    int numOfItems = currentRoom->numberOfItems();
    for(int i = 0; i < numOfItems; i++)
        {
            ui->ItemDropdown->addItem(QString::fromStdString(currentRoom->getItemI(i)));
        }
}

void MainWindow::unlockDoor(int keyNum){

    string facing = character->getFacing();
    if(currentRoom->isADoor(facing)==true){

        if(keyNum == currentRoom->getLockNum(facing)){
            ui->Label1->setText("Key Worked, Door unlocked!");
             currentRoom->setLockNum(facing);
        }else{
            ui->Label1->setText("Wrong key for this lock");
        }
    }
}

void MainWindow::showDescription(string facing)
{
    string desc;
    if(!facing.compare("desc")){
         desc = currentRoom->shortDescription();
    }
    else{
        desc = currentRoom->getFacingDescription(facing);
    }
    ui->Label1->setText(QString::fromStdString(desc));
}
