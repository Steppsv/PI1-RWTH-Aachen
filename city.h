#ifndef CITY_H
#define CITY_H

#include <QDebug>
#include <QString>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

class City
{
public:
    City(QString name, int x, int y);
    void draw(QGraphicsScene& scene);
    int Get_X();
    int Get_Y();
    QString Get_Name();

private:
    QString name;
    int x;
    int y;

};


#endif // CITY_H

