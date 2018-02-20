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
     play();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    a = new Room("a");
        a->addItem(new Item("x", 1, 11));
        a->addItem(new Item("y", 2, 22));
    b = new Room("b");
        b->addItem(new Item("xx", 3, 33));
        b->addItem(new Item("yy", 4, 44));
    c = new Room("c");
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");
    j = new Room("j");

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, j);
    j->setExits(NULL,i,NULL,NULL);

        currentRoom = a;
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
        string RoomInfo = currentRoom->longDescription();
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
        goRoom(command);
        string RoomInfo = currentRoom->longDescription();
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
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
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

    else if (commandWord.compare("put") == 0)
    {

    }

    else if(commandWord.compare("teleport")==0)
    {
        teleport();
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

void MainWindow::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else {
        currentRoom = nextRoom;
        aMap.setMapLocation(currentRoom->shortDescription());
        cout << currentRoom->longDescription() << endl;
    }
}

void MainWindow::teleport(){

    cout << "Tried to teleport" << endl;
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
        return currentRoom->longDescription();
    }
}



void MainWindow::on_NorthButton_clicked()
{
    Command* command = parser.getCommand("go north");
    processCommand(*command);
}

void MainWindow::on_SouthButton_clicked()
{
    Command* command = parser.getCommand("go south");
    processCommand(*command);
}

void MainWindow::on_EastButton_clicked()
{
    Command* command = parser.getCommand("go east");
    processCommand(*command);
}

void MainWindow::on_West_clicked()
{
    Command* command = parser.getCommand("go west");
    processCommand(*command);
}

void MainWindow::on_TakeButton_clicked()
{
    string ItemToTake = (ui->ItemDropdown->currentText()).toStdString();
    string comm = "take "+ItemToTake;
    Command* command = parser.getCommand(comm);
    processCommand(*command);
}
void MainWindow::on_teleportButton_clicked()
{
 teleport();
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

