/*
 * Magazin.cpp
 *
 *  Created on: 26 июн. 2024 г.
 *      Author: dzhug
 */

#include "Magazin.h"
#include "Buch.h"
#include "Datum.h"


Magazin::~Magazin() {
	// TODO Auto-generated destructor stub
}
Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
    : Medium(initTitel), datum(initDatumAusgabe), sparte(initSparte) {}

bool Magazin::ausleihen(Person person, Datum ausleihdatum){
	if (((ausleihdatum.Get_monat() - datum.Get_monat()) == 0 )&&((ausleihdatum.Get_jahr() - datum.Get_jahr()) == 0 )){
		std::cout<<"Das ist die neuste Ausgabe. /nDas dürfen wir nicht ausleihen"<<std::endl;
		return false;
	}
	else {
		Medium::ausleihen(person,ausleihdatum);
		return true;
	}
}

void Magazin::ausgabe() const {
	Medium::ausgabe();
	std::cout << "Ausgabe" << datum  <<std::endl;
	std::cout << "Sparte:" << sparte <<std::endl;
}
