#ifndef MAP_H
#define MAP_H

#include <QVector>

#include "city.h"
#include "abstractmap.h"
#include "QGraphicsScene"

class map : public AbstractMap
{
public:
    map();
    ~map();
    void addCity(City*);
    bool addStreet(Street*);
    void draw(QGraphicsScene *scene);
    City* findCity(const QString cityName) const;
    QVector<Street*> getStreetList(const City* city) const;
    City* getOppositeCity(const Street* street, const City* city) const;
    double getLength(const Street* street) const;

private:
    QVector<City*> mapa;
    QVector<Street*> streets;
};

#endif // MAP_H
