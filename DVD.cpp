/*
 * DVD.cpp
 *
 *  Created on: 26 июн. 2024 г.
 *      Author: dzhug
 */

#include "DVD.h"


DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
    : Medium(initTitel), altersfreigabe(initAltersfreigabe),genre(initGenre){}

DVD::~DVD() {
	// TODO Auto-generated destructor stub
}
void DVD::ausgabe() const {
    Medium::ausgabe();
    std::cout << "FSK: ab " << altersfreigabe << " Jahre" << std::endl; // Добавьте вывод
    std::cout << "Genre: " << genre << std::endl; // Добавьте вывод
}

bool DVD::ausleihen(Person person, Datum ausleihdatum){
	if ( (2024 - person.getGeburtsdatum().Get_jahr() - altersfreigabe) >= 0){
		std::cout<<"Der Person ist zu Jung für solche DVD"<<std::endl;
		return false;
	}
	else {
		Medium::ausleihen(person,ausleihdatum);
		return true;
	}
}
