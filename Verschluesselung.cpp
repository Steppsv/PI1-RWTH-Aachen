///////////////////////////////////////////////////////////////////////////////-
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(char schluessel[2][26], string wort)
{
	string vwort;
	for( long long unsigned int i = 0 ; i < size(wort) ; i++ ){
		int LetterNumber = wort[i]-65;
		vwort = vwort + schluessel[1][LetterNumber];
	}

	return vwort;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	string ewort;
		for( long long unsigned int i = 0 ; i < size(wort) ; i++ ){
			int LetterNumber = wort[i];
			for( int j = 0; j < 26; j++)
			{
				if(LetterNumber == schluessel[0][j])
				{
					ewort = ewort + schluessel[0][j];
					break;
				}
			}

	}
	return ewort;
}

int main()
{
	char alfabet [2][26];
	string psw = "ABRACADABRA";
	string vpsw,epsw;
	for( int i = 0; i < 26 ; i++ ){
		alfabet [0][i]= i+65;
		alfabet [1][i]= 90-i;
		cout << alfabet[0][i] << " " << alfabet [1][i] << endl;
	}

	cout << "Schreiben Sie bitte die zu verschlussendes Wort: \n";
	//cin >> psw;

	vpsw = verschluesseln( alfabet, psw );
	cout << "\nVerschlussendes Passwort ist: \n" << vpsw;
	epsw = entschluesseln( alfabet, psw );
	cout << "\nEntschlussendes Passwort ist: \n" << epsw;


	return 0;
}
