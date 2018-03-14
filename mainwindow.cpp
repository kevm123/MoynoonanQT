#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Command.h"
#include "areamap.h"

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

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    a = new Room("a","Directly in front of you is a dentists chair.\nBut none of the other tools appear to be dental related.\nA worrying amount of red stains are scattered throughout the room.\nTo the south is a hallway.\nThere is a red door to the west and a blue door to the east.");
        a->addItem(new Item("x", 1, 11, "north", true, "No info", false));
        a->addItem(new Item("y", 2, 22, "south", true, "No info", false));

    b = new Room("b","You are now standing a room filled with sleepingbags and old mattress's.\nTheres bars on the windows but its too dark to see outside.\nA small dimly lit candle lights the room.\nA small trail of blood seems to go under a door to the north.");
        b->addItem(new Item("Unusual Key", 3, 33, "east", true, "A strange key for a strange door", true, 6));

    c = new Room("c","A large steel door with a very unique lock is to the north of the room.\nThis door has a letter box but its welded shut.\nSurely this is the way out.");
        c->addItem(new Item("Modern Key", 3, 33, "west", true, "A normal modern key", true, 7));

    d = new Room("d","You are now standing in a small hallway.\nA large skylight above you shows a clear dark night.\nIn front of you is a door that says --TOILETS-- and another unlocked door is to the north.");

    e = new Room("e","A light flickering overhead displays a small tiled bathroom.\nThere appears to be blood on the floor and a mop and bucket lie next to it.");
        e->addItem(new Item("RedKey", 2, 22, "east", true, "A Red Key", true, 4));
        e->addItem(new Item("BlueKey", 2, 22, "east", true, "A Blue Key", true, 5));

    f = new Room("f","f");

    g = new Room("g","This room is not like the others.\nIts brightly lit with a large sign that reads \n--Len Groseman, Your one stp shop for pain relief and a better life-- \nabove an apparent receptionists desk.\nTo the east is a large bolted door with a keypad.");

    h = new Room("h","You enter a dead end. There is nowhere to go only back");

    i = new Room("i","You are now in a small brightly lit room.\nIt looks like some kind of waiting room.\nTheres a table in the middle of the room with dusty magazines and chairs dotted around.");
         i->addItem(new Item("Oldkey", 2, 22, "east", true, "An old, rusty key hangs on the wall", true, 2));

         j = new Room("j","Welcome to the game.\nYou are in an old room with a red carpet and no windows.\nYou have no idea where you are but you know you must find a way out...\nUse the buttons below to look around.");
        j->addItem(new Item("painting", 1, 11, "north", false, "The painting is of a ship in a storm.\nIt says in the corner --Painted in 1964--", false));
        j->addItem(new Item("key", 2, 22, "south", true, "An old key just lying on the ground.\nYou can tell from the dust marks its been there a while.", true, 1));

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
     g->setLocks(0, 0, 0, 8);
     h->setLocks(0, 0, 0, 0);
     i->setLocks(0, 2, 0, 0);
     j->setLocks(0, 1, 0, 0);

     a->setFacingDescriptions("-", "-", "-", "-");
     b->setFacingDescriptions("-", "-", "-", "-");
     c->setFacingDescriptions("-", "-", "-", "-");
     d->setFacingDescriptions("-", "-", "-", "-");
     e->setFacingDescriptions("-", "-", "-", "-");
     f->setFacingDescriptions("-", "-", "-", "-");
     g->setFacingDescriptions("-", "-", "-", "-");
     h->setFacingDescriptions("-", "-", "-", "-");
     i->setFacingDescriptions("A window looking out, it is too dark to see anything", "There is a key with a lock, there is a also an old key on the floor", "There is a couch", "There is a room with an open door");
     j->setFacingDescriptions("There is a painting on a wall", "There is a door with a lock", "There is a key hanging on a hook", "A couch lies in the corner");
        currentRoom = j;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void MainWindow::play() {

    character = new Character("This is a new Character");
    fillItems();
    printWelcome();

   /* // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;


        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;


    cout << endl;
    cout << "end" << endl;*/
}

void MainWindow::printWelcome() {

        showDescription("desc");
        string RoomInfo = currentRoom->longDescription(character->getFacing());
        ui->Label2->setText(QString::fromStdString(RoomInfo));

    /*cout << "start"<< endl;
    cout << "info for help"<< endl;
    cout << "valid inputs are; " << endl;
    parser.showCommands();
    cout << endl;
    cout << currentRoom->longDescription() << endl;*/
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool MainWindow::processCommand(Command command) {
    if (command.isUnknown()) {
        cout << "invalid input"<< endl;
        ui->outputLabel->setText(QString::fromStdString("invalid input"));
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
        {
        cout << "[h] --- [f] --- [g]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[c] --- [a] --- [b]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[i] --- [d] --- [e]" << endl;
        }

    else if (commandWord.compare("go") == 0)
    {
        string facing = character->getFacing();
        goRoom(command, facing);
        string RoomInfo = currentRoom->longDescription(character->getFacing());
        ui->Label2->setText(QString::fromStdString(RoomInfo));
        fillItems();
    }

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        ui->outputLabel->setText("incomplete input");
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        ui->outputLabel->setText(QString::fromStdString("you're trying to take "+ command.getSecondWord()));
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else if((currentRoom->getItem(location)).getObtainable() && (character->getFacing() == (currentRoom->getItem(location)).getPlaced())){
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription(character->getFacing()) << endl;

            currentRoom->getItem(location).setPlaced("");
            character->addItem(currentRoom->takeItem(location));

            //Update Obtained Items DropDown
            ui->ObtainedItems->clear();
            int numOfItems = character->numberOfItems();
            for(int i = 0; i < numOfItems; i++)
                {
                    ui->ObtainedItems->addItem(QString::fromStdString(character->getItemI(i)));
                    ui->outputLabel->setText(QString::fromStdString("have obtained the "+ command.getSecondWord()));
                }

            //Update Items In Room DropDown
            fillItems();
        }
        else
            ui->outputLabel->setText(QString::fromStdString("You are not facing in the direction of the object"));
        }
    }

    else if (commandWord.compare("Investigate") == 0)
    {
        if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
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


    /*
    {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true; /**signal to quit*/
    }
    return false;
}
/** COMMANDS **/
void MainWindow::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}

void MainWindow::goRoom(Command command, string facing) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else if(currentRoom->isLocked(facing)==true){
        cout<< "locked"<< endl;
    }
    else {
        currentRoom = nextRoom;
        showDescription("desc");
        aMap.setMapLocation(currentRoom->getName());
        cout << currentRoom->longDescription(character->getFacing()) << endl;
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


void MainWindow::on_UseButton_clicked()
{
    string itemName = (ui->ObtainedItems->currentText()).toStdString();
    Item *itemToUse = character->getItemByString(itemName);

    bool isAKey= itemToUse->getIsKey();
    if(isAKey==true){
        int keyNum = itemToUse->getKeyNum();
        unlockDoor(keyNum);
    }else{
        cout<< "trying to use "<< itemName << endl;
    }
}

void MainWindow::unlockDoor(int keyNum){

    string facing = character->getFacing();
    if(currentRoom->isADoor(facing)==true){
        cout << "attempting to head through the " << facing << " door"<< endl;
        if(keyNum == currentRoom->getLockNum(facing)){
             cout << "key worked !" << endl;
             currentRoom->setLockNum(facing);
        }else{
            cout << "wrong key for this lock" << endl;
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
