#include "map.h"
//#include <cmath>

map::map() {}
map::~map(){}

void map::addCity(City* neu_city)
{
    mapa.push_back(neu_city);
    qDebug() << "   Adding City: " << neu_city->Get_Name() << " X: " << neu_city->Get_X() << " Y: " << neu_city->Get_Y();
}

void map::draw(QGraphicsScene *scene)
{
    for(City* city : mapa)
    {
        city->draw(*scene);
    }
    for(Street* street : streets)
    {
        street->draw(*scene);
    }
}

bool map::addStreet(Street* neues_street)
{
    if(mapa.contains(neues_street->Get_City1()) && mapa.contains(neues_street->Get_City1()))
    {
        streets.push_back(neues_street);
        return 1;
    }
    qDebug() << "Cannot add street: cities isn't on the map.";
    return 0;
}

City* map::findCity(const QString cityName) const
{
    auto it = std::find_if(mapa.begin(), mapa.end(), [&cityName](City* city)
                           {return city->Get_Name() == cityName;});
    if (it != mapa.end())
    {
        qDebug() << "City " << cityName << " was found";
        return *it; //city was found
    }
    else
    {
        return nullptr; //city wasn't found
    }
}

QVector<Street*> map::getStreetList(const City* city) const
{
    QVector<Street*> streetList;
    for (Street* street : streets)
    {
        if(city == street->Get_City1() || city == street->Get_City2())
        {
            streetList.append(street);
        }
    }

    return streetList;
}

City* map::getOppositeCity(const Street* street, const City* city) const
{
    if(street->Get_City1() == city)
    {
        return street->Get_City2();
    }
    else if(street->Get_City2() == city)
    {
        return street->Get_City1();
    }
    else
    {
        return nullptr;
    }
}

double map::getLength(const Street* street) const
{
    double xCity1 = street->Get_City1()->Get_X();
    double yCity1 = street->Get_City1()->Get_Y();
    double xCity2 = street->Get_City2()->Get_X();
    double yCity2 = street->Get_City2()->Get_Y();

    return sqrt((xCity2 - xCity1)*(xCity2 - xCity1) + (yCity2 - yCity1)*(yCity2 - yCity1));
}
