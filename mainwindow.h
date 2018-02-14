#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Character.h"

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void play();
    string go(string direction);


private slots:
    void on_NorthButton_clicked();

    void on_SouthButton_clicked();

    void on_EastButton_clicked();

    void on_West_clicked();

    void on_TakeButton_clicked();

private:
    Ui::MainWindow *ui;

    Parser parser;
    Room *currentRoom;
    Character *character;
    void createRooms();
    void printWelcome();
    bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();
    void teleport();
    void fillItems();

};

#endif // MAINWINDOW_H
