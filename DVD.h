/*
 * DVD.h
 *
 *  Created on: 26 июн. 2024 г.
 *      Author: dzhug
 */

#ifndef DVD_H_
#define DVD_H_
#include "Buch.h"
#include "Medium.h"
#include "Person.h"
class DVD : public Medium{
public:

	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	virtual ~DVD();
	void ausgabe() const;
	bool ausleihen(Person person, Datum ausleihdatum);
private:
	Person person;
	int altersfreigabe;
	std::string genre;
};

#endif /* DVD_H_ */
