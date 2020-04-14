#ifndef MEDIKAMENT_H
#define MEDIKAMENT_H
#include <iostream>
#include <string>
#include <graphics.h>
#include <vector>
#include <algorithm>
using namespace std;

class Medikament
{
    public:
        Medikament();
        Medikament(string Name, int Konzentration, int Menge, int Preis);
        ~Medikament();

        //setteri
        void setName(string Name);
        void setKonzentration(int Konzentration);
        void setMenge(int Menge);
        void setPreis(int Preis);

        //getteri
        string getName();
        int getKonzentration();
        int getMenge();
        int getPreis();

    private:
        string Name;
        int Konzentration;
        int Menge;
        int Preis;
};

#endif // MEDIKAMENT_H
