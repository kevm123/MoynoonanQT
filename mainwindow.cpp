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
     aMap.setMapLocation(currentRoom->shortDescription());
     play();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    a = new Room("a");
        a->addItem(new Item("x", 1, 11, "north", true, "No info", false));
        a->addItem(new Item("y", 2, 22, "south", true, "No info", false));
    b = new Room("b");
        b->addItem(new Item("xx", 3, 33, "east", true, "No info", false));
        b->addItem(new Item("yy", 4, 44, "west", true, "No info", false));
    c = new Room("c");
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");
    j = new Room("j");
        j->addItem(new Item("painting", 1, 11, "north", false, "Painted in 1964", false));
        j->addItem(new Item("key", 2, 22, "south", true, "Its a key", true, 1));

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

   //              (N, E, S, W)

     a->setLocks(0, 0, 0, 0);
     b->setLocks(0, 0, 0, 0);
     c->setLocks(0, 0, 0, 0);
     d->setLocks(0, 0, 0, 0);
     e->setLocks(0, 0, 0, 0);
     f->setLocks(0, 0, 0, 0);
     g->setLocks(0, 0, 0, 0);
     h->setLocks(0, 0, 0, 0);
     i->setLocks(0,2, 0, 0);
     j->setLocks(0, 1, 0, 0);

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

        ui->Label1->setText("Welcome to a new Game\nThe button below will guid you through\nPress Continue");
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
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else if((currentRoom->getItem(location)).getObtainable()){
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
                }

            //Update Items In Room DropDown
            fillItems();
        }
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
        else
        {
            Item ItemToInvestigate = currentRoom->getItem(location);
            string output = ItemToInvestigate.getInvestigateString();
            cout<<output<<endl;
         }
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
        aMap.setMapLocation(currentRoom->shortDescription());
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
        return currentRoom->longDescription(character->getFacing());
    }
}



void MainWindow::on_NorthButton_clicked()
{
    character->setFacing("north");
    string RoomInfo = currentRoom->longDescription(character->getFacing());
    ui->Label2->setText(QString::fromStdString(RoomInfo));
}

void MainWindow::on_SouthButton_clicked()
{
    character->setFacing("south");
    string RoomInfo = currentRoom->longDescription(character->getFacing());
    ui->Label2->setText(QString::fromStdString(RoomInfo));
}

void MainWindow::on_EastButton_clicked()
{
    character->setFacing("east");
    string RoomInfo = currentRoom->longDescription(character->getFacing());
    ui->Label2->setText(QString::fromStdString(RoomInfo));
}

void MainWindow::on_West_clicked()
{
    character->setFacing("west");
    string RoomInfo = currentRoom->longDescription(character->getFacing());
    ui->Label2->setText(QString::fromStdString(RoomInfo));
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
