//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}
/**
 * @brief funktion laenge rechnet  die Länge des vektores
 * @return laenge
 */
double Vektor::laenge() const
{
	return sqrt(x*x+y*y+z*z);
}

/**
 * @brief nimmt zwei vektoren und substrahiert sie
 * @return gibt zurück ein neues vektor,substraktion der erste Zwei
 */
Vektor Vektor::sub(const Vektor& input) const
{
	Vektor vx(x - input.x ,y - input.y ,z - input.z );
	return (vx);
}

/**
 * @brief nimmt zwei vektoren und rechnet skalar produkt von beiden
 * @return Liefert skalar peodukt Zwei vektoren Zurück
 */
double Vektor::skalarProd(const Vektor& input) const
{
	return x*input.x + y*input.y + z*input.z;
}

/**
 * @brief nimmt zwei vektoren und rechnet winkel zwischen sie
 * @return Liefert winkel zwischen beiden vektoren
 */
double Vektor::winkel(const Vektor& input) const
{
	return (acos(this->skalarProd(input)/ (this->laenge()*input.laenge()))*57.2957795);
}

void Vektor::rotiereUmZ(const double rad)
{
	x = (cos(rad)*x)-(sin(rad)*y);
	y = (sin(rad)*x)+(cos(rad)*y);
}
/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}
