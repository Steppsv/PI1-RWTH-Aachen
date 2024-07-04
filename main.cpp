/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch6: Dynamische Datenstrukturen , Vector
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Student.h"

int main()
{
	std::vector<Student> studentenVector;
    Student student;
    char abfrage;

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben F->B" << std::endl
				  << "(4): Datenbank ausgeben B->F" << std::endl
				  << "(5): Datenelement nach Matrukelnummer löschen" << std::endl
                  << "(6): Datenelement vorne hinzufügen" << std::endl
				  << "(7): Daten aus Datei herunterladen" << std::endl
				  << "(8): Daten hochladen" << std::endl
				  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenVector.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenVector.empty())
                    {
                        student = studentenVector[0];
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        student.ausgabe();
                        studentenVector.erase(studentenVector.begin());
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenVector.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for(long long unsigned int i = 0 ; i < studentenVector.size() ; i++)
                    {
                    	studentenVector[i].ausgabe();
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;
            // Datenbank B->F ausgebben
            case '4':
            	if(!studentenVector.empty())
				{
					std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
					for( int i = studentenVector.size()-1 ; i >= 0 ; i--)
					{
						studentenVector[i].ausgabe();
					}
				}
				else
				{
            	    std::cout << "Die Liste ist leer!\n\n";
            	}
            	break;
            //Datenelement nach Matnr löschen
            case '5':
            	if(!studentenVector.empty())
            	{
            	    unsigned int LMatNum = 0;
            	    std::cout << "Welcher Student muss entfernt werden?\n";
            	    std::cin >> LMatNum;

					for( long long unsigned int i = 0 ; i+1 < studentenVector.size()+1 ; i++)
					{
						if( studentenVector[i].getMatNr() == LMatNum)
						{
							//studentenVector.erase(studentenVector.begin());
							studentenVector.erase(studentenVector.begin()+i);
							std::cout << "Student ist entfernt" << std::endl;
							break;
						}
						if( i == studentenVector.size()-1)
						std::cout << "Dieser Student steht nicht auf der Liste" << std::endl;
					}
              	}
            	else
            	{
            	std::cout << "Die Liste ist leer!\n\n";
            	}
            	break;

            case '6':
            {
            	unsigned int matNr = 0;
            	std::string name = "";
            	std::string geburtstag = "";
            	std::string adresse = "";

            	std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
            	getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

            	std::cout << "Geburtsdatum: ";
            	getline(std::cin, geburtstag);

            	std::cout << "Adresse: ";
            	getline(std::cin, adresse);

            	std::cout << "Matrikelnummer: ";
            	std::cin >> matNr;
            	std::cin.ignore(10, '\n');

            	student = Student(matNr, name, geburtstag, adresse);
            	studentenVector.push_back(student);
            	//studentenVector.insert(studentenVector.begin(),student);
            }

            	break;

            case '7':
            {
            	studentenVector.clear();

            	unsigned int matNr = 0;
				std::string name = "";
				std::string geburtstag = "";
				std::string adresse = "";
            	std::ifstream eingabe("studenten.txt");
            	//int i = 0;
				while(eingabe.peek() != EOF){
					eingabe >> matNr;
					eingabe.ignore(1 , '\n');
					std::getline(eingabe, name);
					std::getline(eingabe, geburtstag);
					std::getline(eingabe, adresse);
					student = Student(matNr, name, geburtstag, adresse);

					studentenVector.push_back(student);
				}
				std::cout << "Die Datei ist nun heruntergeladen" << std::endl;
            }
            	break;

            case '8':
            { //| std::ios::trunc
            	std::ofstream ausgabe("studenten.txt", std::ios::out | std::ios::trunc);
            	for(long long unsigned int i = 0 ; i < studentenVector.size(); i++)
            	{
            		ausgabe << studentenVector[i].getMatNr() << std::endl;
            		ausgabe << studentenVector[i].getName() << std::endl;
            		ausgabe << studentenVector[i].getGeburtstag() << std::endl;
            		ausgabe << studentenVector[i].getAdresse() << std::endl;
            	}
            	ausgabe.close();
            	std::cout << "Die Datei ist nun hochgeladen" << std::endl;
            }
            	break;

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
