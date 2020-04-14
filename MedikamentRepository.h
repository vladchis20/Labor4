#ifndef MEDIKAMENTREPOSITORY_H
#define MEDIKAMENTREPOSITORY_H
#include "Medikament.h"

#include <iostream>
#include <string>

using namespace std;

class MedikamentRepository
{
    public:
        MedikamentRepository();
        ~MedikamentRepository();

        bool add_Medikament(Medikament m);

        bool delete_Medikament(string Name, int Menge);

        int search_Medikament(string x, int y);

        bool update_Medikament(string Name, int Menge, int neue_Menge, int neues_Preis);

        void display_repo()
        {
            for(int i=0; i<sizeRepo;i++)
            {
                cout<<elem[i].getName()<<" ";
                cout<<elem[i].getKonzentration()<<" ";
                cout<<elem[i].getMenge()<<" ";
                cout<<elem[i].getPreis()<<endl;
            }
        }

    private:
        int sizeRepo;
        int capRepo;
        Medikament* elem;
};

#endif // MEDIKAMENTREPOSITORY_H
