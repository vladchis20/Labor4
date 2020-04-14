#ifndef MEDIKAMENTUI_H
#define MEDIKAMENTUI_H

#include <iostream>
#include <string>
#include <vector>
#include <graphics.h>

#include "MedikamentController.h"
#include "MedikamentRepository.h"
#include "Medikament.h"

using namespace std;

class MedikamentUI
{
    public:
        MedikamentUI(MedikamentController* c);
        ~MedikamentUI();

        void Afisare_Exit();

        void Afisare_Medikamente_hinzufugen(Medikament med); //aduagare medicamente

        void Afisare_Medikamente_loschen(Medikament med); //stergere medicamente

        void Afisare_Medikamente_bearbeiten(Medikament med); //modificare medicamente

        void Punkt1(Medikament med); //meniu pentru cerintele de la punctul 1

        void verfugbare_Medikamente(Medikament med); //medicamente disponibile

        void Punkt2(Medikament med); //meniu pentru cerintele de la punctul 2

        void Medikamente_kanpp_als_X(Medikament med); //medicamente mai putine decat X

        void Punkt3(Medikament med); //meniu pentru cerintele de la punctul 3

        void Medikamente_nach_Preis(Medikament med); //medicamente ordonate crescator dupa pret

        void Punkt4(Medikament med); //meniu pentru cerintele de la punctul 4

        void Hauptmenu(Medikament med); //meniu principal

    protected:

    private:
        MedikamentController* controller;
};

#endif // MEDIKAMENTUI_H
