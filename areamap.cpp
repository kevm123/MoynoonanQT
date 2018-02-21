#include "areamap.h"
#include "ui_areamap.h"
#include "mainwindow.h"

AreaMap::AreaMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AreaMap)
{
    mapLoc = 0;
    ui->setupUi(this);
}

AreaMap::~AreaMap()
{
    delete ui;
}

void AreaMap::setMapLocation(string currentRoom)
{
    if(currentRoom == "a"){
     ui->mapView->setPixmap(QPixmap(":/mapImgs/images/roomMapTemplatePosA.png"));
    }else if(currentRoom == "b"){
       ui-> mapView->setPixmap(QPixmap(":/mapImgs/images/roomMapTemplatePosB.png"));
    }else if(currentRoom == "c"){
        ui-> mapView->setPixmap(QPixmap(":/mapImgs/images/roomMapTemplatePosC.png"));
     }else if(currentRoom == "d"){
        ui-> mapView->setPixmap(QPixmap(":/mapImgs/images/roomMapTemplatePosD.png"));
    }else if(currentRoom == "e"){
        ui-> mapView->setPixmap(QPixmap(":/mapImgs/images/roomMapTemplatePosE.png"));
    }else if(currentRoom == "f"){
        ui-> mapView->setPixmap(QPixmap(":/mapImgs/images/roomMapTemplatePosF.png"));
    }else if(currentRoom == "g"){
        ui-> mapView->setPixmap(QPixmap(":/mapImgs/images/roomMapTemplatePosG.png"));
    }else if(currentRoom == "h"){
        ui-> mapView->setPixmap(QPixmap(":/mapImgs/images/roomMapTemplatePosH.png"));
    }else if(currentRoom == "i"){
        ui-> mapView->setPixmap(QPixmap(":/mapImgs/images/roomMapTemplatePosI.png"));
    }else if(currentRoom == "j"){
        ui-> mapView->setPixmap(QPixmap(":/mapImgs/images/roomMapTemplatePosJ.png"));
    }
}
