#include "city.h"

City::City(QString name, int x, int y)
: name(name), x(x), y(y)
{

}


void City::draw(QGraphicsScene& scene)
{
    scene.addEllipse( x,y,10,10,QPen(Qt::black),QBrush(Qt::red, Qt::SolidPattern));
    qDebug() << " Drawing City: " << name << " X: " << x << " Y: " << y;
    scene.addText(name)->setPos(x+5,y+1);
}

int City::Get_X(){
    return x;
}
int City::Get_Y(){
    return y;
}

QString City::Get_Name(){
    return name;
}

