//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

int main()
{
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);
    Vektor vector3(vector1.sub(vector2));
    double rad = 1.57;
    vector1.ausgabe();
    std::cout << std::endl;
    vector2.ausgabe();
    std::cout << std::endl;

    std::cout << "Laenge des vektor1 ist: " << vector1.laenge() << "\n\n";

    std::cout << "Substraktion v1 - v2: \n";
    vector3.ausgabe();
    std::cout << "Skalar produkt v1 und v3 ist: " << vector1.skalarProd(vector3) << " \n\n";

    std::cout << "Winkel zwischen v1 und v2 ist: " << vector1.winkel(vector2) << " \n\n";
    vector1.rotiereUmZ(rad);
    std::cout << "Vektor1 ist rotiert um " << rad << " Radian\n";
    vector1.ausgabe();


    std::cout << "\n\n\n";
    Vektor vector5(0, 6371557.4, 0);       //Mensch und die Plattform
    Vektor vector6(0, 6371000  , 0);	   //Erde niveau
    Vektor vector8(vector5.sub(vector6)); //höhe von Mensch
    int i = 0;
    double skal = 0;
    double lange = 0;
    do
    {
    	i++;
    	//vector5.ausgabe();
		vector6.rotiereUmZ(-0.00000001);
		//vector6.ausgabe();
		Vektor vector7(vector6.sub(vector5));  //Vektor der verbindet mensch mit dem Punkt, wo er nichts mehr sehen kann
		lange = vector7.laenge();
		skal = vector6.skalarProd(vector7);
		//std::cout << skal << std::endl;

    } while(!((skal > -10000)&&(skal < 10000)));

    std::cout << "Wie weit entfernt ist der Horizont? \nAnswer ist: " << lange << "\n";
	std::cout << "Sie sind " << vector8.laenge() << " Meter hoch\n";
	std::cout << "Winkel ist: " << vector5.winkel(vector6) << "\n";
	std::cout << "Anzahl Schritte: " << i << "\n\n";

    return 0;

}
