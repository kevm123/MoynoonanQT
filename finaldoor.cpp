#include "finaldoor.h"
#include "ui_finaldoor.h"

FinalDoor::FinalDoor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FinalDoor)
{
    ui->setupUi(this);
}

FinalDoor::~FinalDoor()
{
    delete ui;
}

FinalDoor::setCode(int c)
{
    code = c;
}

FinalDoor::setUpDoor(Room *c, string f)
{
    currentRoom = c;
    facing = f;
}

void FinalDoor::on_Button_clicked()
{
    QString in = ui->Input->text();
    int inInt = in.toInt();
    if(inInt == code)
    {
        ui->Output->setText("Congratulations, The door is Open!!");
        currentRoom->setLockNum(facing);
    }
    else
        ui->Output->setText("Wrong Code");

}

void FinalDoor::on_CloseButton_clicked()
{
    this->hide();
}
