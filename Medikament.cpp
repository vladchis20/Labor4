#include "Medikament.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
Medikament::Medikament() //constructor
{
    Name = "";
    Konzentration = 0;
    Menge = 0;
    Preis = 0;
}

Medikament::Medikament(string Name, int Konzentration, int Menge, int Preis) //constructor
{
    this -> Name = Name;
    this -> Konzentration = Konzentration;
    this -> Menge = Menge;
    this -> Preis = Preis;
}

Medikament::~Medikament() //destructor
{

}

//getteri
string Medikament::getName()
{
    return Name;
}
int Medikament::getKonzentration()
{
    return Konzentration;
}
int Medikament::getMenge()
{
    return Menge;
}
int Medikament::getPreis() const
{
    return Preis;
}

//gettteri NEU
int Medikament::getNeuesMenge()
{
    return Menge;
}
int Medikament::getNeuesPreis()
{
    return Preis;
}

//setteri
void Medikament::setName(string Name)
{
    this->Name=Name;
}

void Medikament::setKonzentration(int Konzentration)
{
    this->Konzentration=Konzentration;
}

void Medikament::setMenge(int Menge)
{

    this->Menge=Menge;
}

void Medikament::setPreis(int Preis)
{
    this->Preis=Preis;
}

// implementare pentru operatorul de insertie in stream
ostream& operator<<(ostream& s, const Medikament &m)
{
    // left - specifica alinierea la stanga
    // setw - numarul de caractere pe care se va afisa elementul urmator din stream
    s<<left<<setw(20)<<m.Name<<"|"<<setw(5)<<m.Konzentration<<"|"<<setw(5)<<m.Menge<<"|"<<setw(5)<<m.Preis<<'\n';
    return s;
}
