#include "street.h"

Street::Street(City* city1,City* city2)
    :city1(city1),city2(city2)
{
    x1 = city1->Get_X();
    y1 = city1->Get_Y();
    x2 = city2->Get_X();
    y2 = city2->Get_Y();
}

void Street::draw(QGraphicsScene& scene)
{

    scene.addLine( x1+5,y1+5,x2+5,y2+5);
    qDebug() << " Drawing Streat between " << city1->Get_Name() << " and " << city2->Get_Name();
    //scene.addText(name)->setPos(x+5,y+1);
}

City* Street::Get_City1() const
{
    return city1;
}

City* Street::Get_City2() const
{
    return city2;
}

void Street::drawRed(QGraphicsScene& scene)
{
    if (city1 && city2)
    {
        QPen pen(Qt::red);
        pen.setWidth(3);
        scene.addLine(city1->Get_X()+1, city1->Get_Y()+1, city2->Get_X()+1, city2->Get_Y()+1, pen);
    }
}
