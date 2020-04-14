#include "Medikament.h"
#include <iostream>
#include <string>
#include <graphics.h>
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
int Medikament::getPreis()
{
    return Preis;
}

void Medikament::setName(string Name)
{
    string x;
    x=Name;
}

void Medikament::setKonzentration(int Konzentration)
{
    int x;
    x=Konzentration;
}

void Medikament::setMenge(int Menge)
{
    int x;
    x=Menge;
}

void Medikament::setPreis(int Preis)
{
    int x;
    x=Preis;
}
