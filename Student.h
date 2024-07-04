//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    void ausgabe() const;
    bool operator ==(const Student & other) const;
    bool operator ==(unsigned int num) const;
    bool operator >(const Student & other) const;
    bool operator <(const Student & other) const;
    friend std::ostream& operator<<(std::ostream& out, const Student& student);
protected:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};


#endif
