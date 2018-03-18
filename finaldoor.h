#ifndef FINALDOOR_H
#define FINALDOOR_H

#include <QDialog>
#include "Room.h"

namespace Ui {
class FinalDoor;
}

class FinalDoor : public QDialog
{
    Q_OBJECT

public:
    explicit FinalDoor(QWidget *parent = 0);
    ~FinalDoor();
    setCode(int c);
    setUpDoor(Room *c, string f);

private slots:
    void on_Button_clicked();

    void on_CloseButton_clicked();

private:
    int code;
    Room *currentRoom;
    string facing;
    Ui::FinalDoor *ui;
};

#endif // FINALDOOR_H
