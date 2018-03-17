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

private slots:
    void on_Button_clicked();

    void on_CloseButton_clicked();

private:
    int code;
    Ui::FinalDoor *ui;
};

#endif // FINALDOOR_H
