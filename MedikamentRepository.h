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

        bool delete_Medikament(string Name, int Konzentration);

        int search_Medikament(string x, int y);

        bool update_Medikament(string Name, int Konzentration, int Menge, int Preis ,int neues_Menge, int neues_Preis);

        void displaySortedByPrice();

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

        void displayMedikamentMengeNonZero();

        void displayMedikamentMengeKleinerX(int X);

    private:
        int sizeRepo;
        int capRepo;
        Medikament* elem;
};

#endif // MEDIKAMENTREPOSITORY_H
