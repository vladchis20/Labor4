#ifndef MEDIKAMENTUI_H
#define MEDIKAMENTUI_H

#include <iostream>
#include <string>
#include <vector>


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

        void Afisare_Medikamente_anzusehen(); //functia de afisare a tuturor medicamentelor

        void Afisare_Medikamente_hinzufugen(); //aduagare medicamente

        void Afisare_Medikamente_loschen(); //stergere medicamente

        void Afisare_Medikamente_bearbeiten(); //modificare medicamente

        void Punkt1(); //meniu pentru cerintele de la punctul 1

        void verfugbare_Medikamente(); //medicamente disponibile

        void Punkt2(); //meniu pentru cerintele de la punctul 2

        void Medikamente_kanpp_als_X(); //medicamente mai putine decat X

        void Punkt3(); //meniu pentru cerintele de la punctul 3

        void Medikamente_nach_Preis(); //medicamente ordonate crescator dupa pret

        void Punkt4(); //meniu pentru cerintele de la punctul 4

        void Undo();

        void Redo();

        void Hauptmenu(); //meniu principal


    protected:

    private:
        MedikamentController* controller;
};

#endif // MEDIKAMENTUI_H
