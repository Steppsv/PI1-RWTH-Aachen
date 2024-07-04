#include "Buch.h"
#include <string>
#include <iostream>

Buch::Buch() : Medium("") {}
Buch::~Buch(){

}

Buch::Buch(std::string initTitel, std::string initAutor)
:Medium(initTitel),autor(initAutor){

}

void Buch::ausgabe()  {
	Medium::ausgabe();
	std::cout << "Autor: " << autor << std::endl;
}
