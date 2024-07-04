#ifndef STREET_H
#define STREET_H
#include "city.h"
#include <QGraphicsScene>
class Street
{
public:
    Street(City* city1,City* city2);
    void draw(QGraphicsScene& scene);
    City* Get_City1() const;
    City* Get_City2() const;
    void drawRed(QGraphicsScene& scene);
private:
    int x1,y1,x2,y2;
    City* city1;
    City* city2;
};

#endif // STREET_H
