/*
 * Magazin.h
 *
 *  Created on: 26 июн. 2024 г.
 *      Author: dzhug
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_
#include "Buch.h"
#include "Medium.h"
#include "Datum.h"
class Magazin : public Medium {
public:

	virtual ~Magazin();
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
	bool ausleihen(Person person, Datum ausleihdatum);
	void ausgabe() const;
private:
	Datum datum;
	std::string sparte;
};

#endif /* MAGAZIN_H_ */
