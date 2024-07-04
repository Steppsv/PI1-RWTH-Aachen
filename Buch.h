/*
 * Buch.h
 *
 *  Created on: 25 июн. 2024 г.
 *      Author: dzhug
 */

#ifndef BUCH_H_
#define BUCH_H_
#include "Medium.h"
#include <string>
#include <iostream>

class Buch : public Medium {
public:
	Buch();
	virtual ~Buch();
	Buch(std::string initTitel, std::string initAutor);
	void ausgabe();
private:
	std::string autor;
};

#endif /* BUCH_H_ */
