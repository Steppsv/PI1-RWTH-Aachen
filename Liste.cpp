//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, back);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        back = neuesElement;
    }
}


/**
 * @brief Hinzufuegen eines neuen Listenelements am Anfang der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student pData)
{
	ListenElement* neuesElement = new ListenElement(pData, front, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
    	front = neuesElement;
	    back = neuesElement;
    }
	else
    {
		front->setPrev(neuesElement);
	    front = neuesElement;
	}
}
/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete front;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeBackwaerts() const
{
	ListenElement* cursor = back;

	while (cursor != nullptr)
	{
		cursor->getData().ausgabe();
		cursor = cursor->getPrev();
	}
}

/**
 * @brief Entfernen eines Listenelements mit gleichen Matrikelnummer aus der Liste.
 *
 * @return void
 */
void Liste::datenElementLoschen(int LMatNum)
{
	ListenElement* cursor = front;
	ListenElement* Temp = front;
	    while (cursor != nullptr)
	    {
	    	int MatNum = cursor->getData().getMatNr();
	    	if (MatNum == LMatNum)
	    	{
	    		if (front == back)                                       // Liste enth�lt nur ein Listenelement
	    		    {
	    		        delete front;                                        // Listenelement l�schen
	    		        front = nullptr;
	    		        back = nullptr;
	    		    }
	    		    else{
	    		    	if (cursor == front)
	    		    	{
	    		    		front = front->getNext();
	    		    		front->setPrev(nullptr);
	    		            delete cursor;
	    		    	}
	    		    	else{
	    		    		if (cursor == back)
	    		    		{
	    		    			back = back->getPrev();
	    		    			back->setNext(nullptr);
	   	    		            delete cursor;
	    		    		}else{
	    		    			Temp = cursor->getPrev();            // Temp ist prev
	    		    			Temp->setNext(cursor->getNext());     // set previous Next element als Next element von current element

	    		    			Temp = cursor->getNext();			//Temp ist next
	    		    			Temp->setPrev(cursor->getPrev());   // set next prev element als current previous

	    		    			std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
	    		    			cursor->getData().ausgabe();
	    		    			delete cursor;
	    		    	}}}
	    		break;
	    	}
	    	cursor = cursor->getNext();
	        if(cursor == nullptr)
	        std::cout << "Student mit diesem Mat.Nummer wurde nicht gefunden\n";

	    }
}


