#ifndef AREAMAP_H
#define AREAMAP_H

#include <QWidget>
#include <string>
using namespace std;

namespace Ui {
class AreaMap;
}

class AreaMap : public QWidget
{
    Q_OBJECT

public:
    explicit AreaMap(QWidget *parent = 0);
    int mapLoc;
    ~AreaMap();
    void setMapLocation(string currentRoom);

private:
    Ui::AreaMap *ui;
};

#endif // AREAMAP_H
